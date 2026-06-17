# 3016. Minimum Number of Pushes to Type Word II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/)  
`Hash Table` `String` `Greedy` `Sorting` `Counting`

**Problem Link:** [LeetCode 3016 - Minimum Number of Pushes to Type Word II](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/)

## Problem

You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

### Example 1

```text
Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.
```

### Example 2

```text
Input: word = "xyzxyzxyzxyz"
Output: 12
Explanation: The remapped keypad given in the image provides the minimum cost.
"x" -> one push on key 2
"y" -> one push on key 3
"z" -> one push on key 4
Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
It can be shown that no other mapping can provide a lower cost.
Note that the key 9 is not mapped to any letter: it is not necessary to map letters to every key, but to map all the letters.
```

### Example 3

```text
Input: word = "aabbccddeeffgghhiiiiii"
Output: 24
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
"f" -> one push on key 7
"g" -> one push on key 8
"h" -> two pushes on key 9
"i" -> one push on key 9
Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
It can be shown that no other mapping can provide a lower cost.
```

## Constraints

- 1 <= word.length <= 105
- word consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3016. Minimum Number of Pushes to Type Word II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy Sorting | C++, Java, Python3 |
| Using Heap | C++, Java, Python3 |

## Approach 1: Greedy Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumPushes(string word) {
        // Frequency vector to store count of each letter
        vector<int> frequency(26, 0);

        // Count occurrences of each letter
        for (char& c : word) {
            ++frequency[c - 'a'];
        }

        // Sort frequencies in descending order
        sort(frequency.rbegin(), frequency.rend());

        int totalPushes = 0;

        // Calculate total number of presses
        for (int i = 0; i < 26; ++i) {
            if (frequency[i] == 0) break;
            totalPushes += (i / 8 + 1) * frequency[i];
        }

        return totalPushes;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int minimumPushes(String word) {
        // Frequency array to store count of each letter
        int[] frequency = new int[26];

        // Count occurrences of each letter
        for (char c : word.toCharArray()) {
            frequency[c - 'a']++;
        }

        // Sort frequencies in descending order
        Arrays.sort(frequency);
        int[] sortedFrequency = new int[26];
        for (int i = 0; i < 26; i++) {
            sortedFrequency[i] = frequency[25 - i];
        }

        /*
        // Or do like this 
        // Sort frequencies in descending order
        Integer[] sortedFrequency = Arrays.stream(frequency).boxed().toArray(Integer[]::new);
        Arrays.sort(sortedFrequency, (a, b) -> b - a);
        */

        int totalPushes = 0;

        // Calculate total number of presses
        for (int i = 0; i < 26; i++) {
            if (sortedFrequency[i] == 0) break;
            totalPushes += (i / 8 + 1) * sortedFrequency[i];
        }

        return totalPushes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumPushes(self, word: str) -> int:
        # Frequency list to store count of each letter
        frequency = [0] * 26

        # Count occurrences of each letter
        for c in word:
            frequency[ord(c) - ord("a")] += 1
        # Sort frequencies in descending order
        frequency.sort(reverse=True)

        total_pushes = 0

        # Calculate total number of presses
        for i in range(26):
            if frequency[i] == 0:
                break
            total_pushes += (i // 8 + 1) * frequency[i]

        return total_pushes
```

</details>

<br>

## Approach 2: Using Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumPushes(string word) {
        // Frequency map to store count of each letter
        unordered_map<char, int> frequencyMap;

        // Count occurrences of each letter
        for (char& c : word) {
            ++frequencyMap[c];
        }

        // Priority queue to store frequencies in descending order
        priority_queue<int> frequencyQueue;

        // Push all frequencies into the priority queue
        for (const auto& entry : frequencyMap) {
            frequencyQueue.push(entry.second);
        }

        int totalPushes = 0;
        int index = 0;

        // Calculate total number of presses
        while (!frequencyQueue.empty()) {
            totalPushes += (1 + (index / 8)) * frequencyQueue.top();
            frequencyQueue.pop();
            index++;
        }

        return totalPushes;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumPushes(String word) {
        // Frequency map to store count of each letter
        Map<Character, Integer> frequencyMap = new HashMap<>();

        // Count occurrences of each letter
        for (char c : word.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        // Priority queue to store frequencies in descending order
        PriorityQueue<Integer> frequencyQueue = new PriorityQueue<>(
            (a, b) -> b - a
        );
        frequencyQueue.addAll(frequencyMap.values());

        int totalPushes = 0;
        int index = 0;

        // Calculate total number of presses
        while (!frequencyQueue.isEmpty()) {
            totalPushes += (index / 8 + 1) * frequencyQueue.poll();
            index++;
        }

        return totalPushes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumPushes(self, word: str) -> int:
        # Frequency map to store count of each letter
        frequency_map = Counter(word)

        # Priority queue to store frequencies in descending order
        frequency_queue = [-freq for freq in frequency_map.values()]
        heapq.heapify(frequency_queue)

        total_pushes = 0
        index = 0

        # Calculate total number of presses
        while frequency_queue:
            total_pushes += (1 + (index // 8)) * (
                -heapq.heappop(frequency_queue)
            )
            index += 1
        return total_pushes
```

</details>
