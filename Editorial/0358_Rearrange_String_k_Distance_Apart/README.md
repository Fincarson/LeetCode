# 358. Rearrange String k Distance Apart

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/rearrange-string-k-distance-apart/)  
`Hash Table` `String` `Greedy` `Sorting` `Heap (Priority Queue)` `Counting`

**Problem Link:** [LeetCode 358 - Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/)

## Problem

Given a string s and an integer k, rearrange s such that the same characters are at least distance k from each other. If it is not possible to rearrange the string, return an empty string "".

### Example 1

```text
Input: s = "aabbcc", k = 3
Output: "abcabc"
Explanation: The same letters are at least a distance of 3 from each other.
```

### Example 2

```text
Input: s = "aaabc", k = 3
Output: ""
Explanation: It is not possible to rearrange the string.
```

### Example 3

```text
Input: s = "aaadbbcc", k = 2
Output: "abacabcd"
Explanation: The same letters are at least a distance of 2 from each other.
```

## Constraints

- 1 <= s.length <= 3 * 105
- s consists of only lowercase English letters.
- 0 <= k <= s.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Task Scheduler](https://leetcode.com/problems/task-scheduler/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Reorganize String](https://leetcode.com/problems/reorganize-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Construct String With Repeat Limit](https://leetcode.com/problems/construct-string-with-repeat-limit/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 358. Rearrange String k Distance Apart

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Priority Queue | C++, Java |
| Greedy | C++, Java |

## Approach 1: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string rearrangeString(string s, int k) {
        int freq[26] = {0};
        // Store the frequency for each character.
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        
        priority_queue<pair<int, int>> free;
        // Insert the characters with their frequencies in the max heap.
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                free.push({freq[i], i});
            }
        }
        
        string ans;
        // This queue stores the characters that cannot be used now.
        queue<pair<int, int>>  busy;
        while (ans.size() != s.size()) {
            int index = ans.size();
            
            // Insert the character that could be used now into the free heap.
            if (!busy.empty() && (index - busy.front().first) >= k) {
                auto q = busy.front(); busy.pop();
                free.push({freq[q.second], q.second});
            }
            
            // If the free heap is empty, it implies no character can be used at this index.
            if (free.empty()) {
                return "";
            }
            
            int currChar = free.top().second; free.pop();
            ans += currChar + 'a';
            
            // Insert the used character into busy queue with the current index.
            freq[currChar]--;
            if (freq[currChar] > 0) {
                busy.push({index, currChar});
            }
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String rearrangeString(String s, int k) {
        Map<Character, Integer> freq = new HashMap<>();
        // Store the frequency for each character.
        for (char c : s.toCharArray()){
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        
        PriorityQueue<Pair<Integer, Character>> free=
                    new PriorityQueue<Pair<Integer, Character>>((a, b) -> b.getKey() - a.getKey());

        // Insert the characters with their frequencies in the max heap.
        for (char c : freq.keySet()){
            free.offer(new Pair<>(freq.get(c), c));
        }
        
        StringBuffer ans = new StringBuffer();
        // This queue stores the characters that cannot be used now.
        Queue<Pair<Integer, Character>> busy = new LinkedList<>();
        while (ans.length() != s.length()) {
            int index = ans.length();
            
            // Insert the character that could be used now into the free heap.
            if (!busy.isEmpty() && (index - busy.peek().getKey()) >= k) {
                Pair<Integer, Character> q = busy.remove();
                free.offer(new Pair<>(freq.get(q.getValue()), q.getValue()));
            }
            
            // If the free heap is empty, it implies no character can be used at this index.
            if (free.isEmpty()) {
                return "";
            }
            
            Character currChar = free.peek().getValue();
            free.remove();
            ans.append(currChar);
            
            // Insert the used character into busy queue with the current index.
            freq.put(currChar, freq.get(currChar) - 1);
            if (freq.get(currChar) > 0) {
                busy.add(new Pair<>(index, currChar));
            }
        }
        
        return ans.toString();
    }
}
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string rearrangeString(string s, int k) {
        unordered_map<char, int> freqs;
        int maxFreq = 0;
        // Store the frequency, and find the highest frequency.
        for (char c : s) {
            freqs[c]++;
            maxFreq = max(maxFreq, freqs[c]);
        }
        
        unordered_set<char> mostChars;
        unordered_set<char> secondChars;
        // Store all the characters with the highest and second highest frequency - 1.
        for (pair<char, int> charPair: freqs) {
            if (charPair.second == maxFreq) {
                mostChars.insert(charPair.first);
            } else if (charPair.second == maxFreq - 1) {
                secondChars.insert(charPair.first);
            }
        }

        // Create maxFreq number of different strings.
        string segments[maxFreq];
        // Insert one instance of characters with frequency maxFreq & maxFreq - 1 in each segment.
        for (int i = 0; i < maxFreq; i++) {
            for (char c: mostChars) {
                segments[i] += c;
            }
            
            // Skip the last segment as the frequency is only maxFreq - 1.
            if (i < maxFreq - 1) {
                for (char c: secondChars) {
                    segments[i] += c;
                }
            }
        }

        int segmentId = 0;
        // Iterate over the remaining characters, and for each, distribute the instances over the segments.
        for (pair<char, int> charPair: freqs) {
            char currChar = charPair.first;
            
            // Skip characters with maxFreq or maxFreq - 1 
            // frequency as they have already been inserted.
            if (mostChars.find(currChar)  != mostChars.end() 
                || secondChars.find(currChar) != secondChars.end()) {
                continue;
            }
            
            // Distribute the instances of these characters over the segments in a round-robin manner.
            for (int freq = freqs[currChar]; freq > 0; freq--) {
                segments[segmentId] += charPair.first;
                segmentId = (segmentId + 1) % (maxFreq - 1);
            }
        }

        // Each segment except the last should have exactly K elements; else, return "".
        for (int i = 0; i < maxFreq - 1; i++) {
            if (segments[i].size() < k) {
                return "";
            }
        }
        
        string ans;
        // Join all the segments and return them.
        for (string s : segments) {
            ans += s;
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String rearrangeString(String s, int k) {
        Map<Character, Integer> freqs = new HashMap<>();
        int maxFreq = 0;
        // Store the frequency, and find the highest frequency.
        for (char c : s.toCharArray()) {
            freqs.put(c, freqs.getOrDefault(c, 0) + 1);
            maxFreq = Math.max(maxFreq, freqs.get(c));
        }

        Set<Character> mostChars = new HashSet<>();
        Set<Character> secondChars = new HashSet<>();
        // Store all the characters with the highest and second-highest frequency - 1.
        for (char c: freqs.keySet()) {
            if (freqs.get(c) == maxFreq) {
                mostChars.add(c);
            } else if (freqs.get(c) == maxFreq - 1) {
                secondChars.add(c);
            }
        }

        // Create maxFreq number of different strings.
        StringBuilder[] segments = new StringBuilder[maxFreq];
        // Insert one instance of characters with frequency maxFreq & maxFreq - 1 in each segment.
        for (int i = 0; i < maxFreq; i++) {
            segments[i] = new StringBuilder();

            for (char c: mostChars) {
                segments[i].append(c);
            }

            // Skip the last segment as the frequency is only maxFreq - 1.
            if (i < maxFreq - 1) {
                for (char c: secondChars) {
                    segments[i].append(c);
                }
            }
        }

        int segmentId = 0;
        // Iterate over the remaining characters, and for each, distribute the instances over the segments.
        for (char c: freqs.keySet()) {
            // Skip characters with maxFreq or maxFreq - 1 
            // frequency as they have already been inserted.
            if (mostChars.contains(c) || secondChars.contains(c)) {
                continue;
            }

            // Distribute the instances of these characters over the segments in a round-robin manner.
            for (int freq = freqs.get(c); freq > 0; freq--) {
                segments[segmentId].append(c);
                segmentId = (segmentId + 1) % (maxFreq - 1);
            }
        }

        // Each segment except the last should have exactly K elements; else, return "".
        for (int i = 0; i < maxFreq - 1; i++) {
            if (segments[i].length() < k) {
                return "";
            }
        }

        // Join all the segments and return them.
        return String.join("", segments);
    }
}
```

</details>
