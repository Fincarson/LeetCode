# 2182. Construct String With Repeat Limit

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/construct-string-with-repeat-limit/)  
`Hash Table` `String` `Greedy` `Heap (Priority Queue)` `Counting`

**Problem Link:** [LeetCode 2182 - Construct String With Repeat Limit](https://leetcode.com/problems/construct-string-with-repeat-limit/)

## Problem

You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.

### Example 1

```text
Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
```

### Example 2

```text
Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa".
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
```

## Constraints

- 1 <= repeatLimit <= s.length <= 105
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2182. Construct String With Repeat Limit

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy Character Frequency Distribution | C++, Java, Python3 |
| Heap-Optimized Greedy Character Frequency Distribution | C++, Java, Python3 |

## Approach 1: Greedy Character Frequency Distribution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;
        int currentCharIndex = 25;  // Start from the largest character
        while (currentCharIndex >= 0) {
            if (freq[currentCharIndex] == 0) {
                currentCharIndex--;
                continue;
            }

            int use = min(freq[currentCharIndex], repeatLimit);
            result.append(use, 'a' + currentCharIndex);
            freq[currentCharIndex] -= use;

            if (freq[currentCharIndex] >
                0) {  // Need to add a smaller character
                int smallerCharIndex = currentCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }
                if (smallerCharIndex < 0) {
                    break;
                }
                result.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String repeatLimitedString(String s, int repeatLimit) {
        int[] freq = new int[26];
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        StringBuilder result = new StringBuilder();
        int currentCharIndex = 25; // Start from the largest character
        while (currentCharIndex >= 0) {
            if (freq[currentCharIndex] == 0) {
                currentCharIndex--;
                continue;
            }

            int use = Math.min(freq[currentCharIndex], repeatLimit);
            for (int k = 0; k < use; k++) {
                result.append((char) ('a' + currentCharIndex));
            }
            freq[currentCharIndex] -= use;

            if (freq[currentCharIndex] > 0) { // Need to add a smaller character
                int smallerCharIndex = currentCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }
                if (smallerCharIndex < 0) {
                    break;
                }
                result.append((char) ('a' + smallerCharIndex));
                freq[smallerCharIndex]--;
            }
        }

        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq = [0] * 26
        for char in s:
            freq[ord(char) - ord("a")] += 1

        result = []
        current_char_index = 25  # Start from the largest character
        while current_char_index >= 0:
            if freq[current_char_index] == 0:
                current_char_index -= 1
                continue

            use = min(freq[current_char_index], repeatLimit)
            result.append(chr(current_char_index + ord("a")) * use)
            freq[current_char_index] -= use

            if freq[current_char_index] > 0:  # Need to add a smaller character
                smaller_char_index = current_char_index - 1
                while smaller_char_index >= 0 and freq[smaller_char_index] == 0:
                    smaller_char_index -= 1
                if smaller_char_index < 0:
                    break
                result.append(chr(smaller_char_index + ord("a")))
                freq[smaller_char_index] -= 1

        return "".join(result)
```

</details>

<br>

## Approach 2: Heap-Optimized Greedy Character Frequency Distribution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<char> maxHeap;
        for (auto& [ch, count] : freq) {
            maxHeap.push(ch);
        }

        string result;

        while (!maxHeap.empty()) {
            char ch = maxHeap.top();
            maxHeap.pop();
            int count = freq[ch];

            int use = min(count, repeatLimit);
            result.append(use, ch);

            freq[ch] -= use;

            if (freq[ch] > 0 && !maxHeap.empty()) {
                char nextCh = maxHeap.top();
                maxHeap.pop();

                result.push_back(nextCh);
                freq[nextCh]--;

                if (freq[nextCh] > 0) {
                    maxHeap.push(nextCh);
                }

                maxHeap.push(ch);
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String repeatLimitedString(String s, int repeatLimit) {
        Map<Character, Integer> freq = new HashMap<>();
        for (char ch : s.toCharArray()) {
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);
        }

        PriorityQueue<Character> maxHeap = new PriorityQueue<>((a, b) ->
            Character.compare(b, a)
        );

        for (char ch : freq.keySet()) {
            maxHeap.offer(ch);
        }

        StringBuilder result = new StringBuilder();

        while (!maxHeap.isEmpty()) {
            char ch = maxHeap.poll();
            int count = freq.get(ch);

            int use = Math.min(count, repeatLimit);
            for (int i = 0; i < use; i++) {
                result.append(ch);
            }

            freq.put(ch, count - use);

            if (freq.get(ch) > 0 && !maxHeap.isEmpty()) {
                char nextCh = maxHeap.poll();
                result.append(nextCh);
                freq.put(nextCh, freq.get(nextCh) - 1);
                if (freq.get(nextCh) > 0) {
                    maxHeap.offer(nextCh);
                }
                maxHeap.offer(ch);
            }
        }

        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        max_heap = [(-ord(c), cnt) for c, cnt in Counter(s).items()]
        heapify(max_heap)
        result = []

        while max_heap:
            char_neg, count = heappop(max_heap)
            char = chr(-char_neg)
            use = min(count, repeatLimit)
            result.append(char * use)

            if count > use and max_heap:
                next_char_neg, next_count = heappop(max_heap)
                result.append(chr(-next_char_neg))
                if next_count > 1:
                    heappush(max_heap, (next_char_neg, next_count - 1))
                heappush(max_heap, (char_neg, count - use))

        return "".join(result)
```

</details>
