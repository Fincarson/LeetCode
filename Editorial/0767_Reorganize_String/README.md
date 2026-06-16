# 767. Reorganize String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/reorganize-string/)  
`Hash Table` `String` `Greedy` `Sorting` `Heap (Priority Queue)` `Counting`

**Problem Link:** [LeetCode 767 - Reorganize String](https://leetcode.com/problems/reorganize-string/)

## Problem

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

### Example 1

```text
Input: s = "aab"
Output: "aba"
```

### Example 2

```text
Input: s = "aaab"
Output: ""
```

## Constraints

- 1 <= s.length <= 500
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Task Scheduler](https://leetcode.com/problems/task-scheduler/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Happy String](https://leetcode.com/problems/longest-happy-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 767. Reorganize String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Counting and Priority Queue | C++, Java, Python3 |
| Counting and Odd/Even | C++, Java, Python3 |

## Approach 1: Counting and Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charCounts(26, 0);
        for (char c : s) {
            charCounts[c - 'a']++;
        }

        // Max heap ordered by character counts
        priority_queue<vector<int>> pq;
        for (int i = 0; i < 26; i++) {
            if (charCounts[i] > 0) {
                pq.push(vector<int>{charCounts[i], i + 'a'});
            }
        }
        
        string result;
        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();
            if (result.empty() || first[1] != result.back()) {
                result += char(first[1]);
                if (--first[0] > 0) {
                    pq.push(first);
                }
            } else {
                if (pq.empty()) {
                    return "";
                }
                auto second = pq.top();
                pq.pop();
                result += char(second[1]);
                if (--second[0] > 0) {
                    pq.push(second);
                }
                pq.push(first);
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
    public String reorganizeString(String s) {
        var charCounts = new int[26];
        for (char c : s.toCharArray()) {
            charCounts[c - 'a']++;
        }

        // Max heap ordered by character counts
        var pq = new PriorityQueue<int[]>((a, b) -> Integer.compare(b[1], a[1]));
        for (int i = 0; i < 26; i++) {
            if (charCounts[i] > 0) {
                pq.offer(new int[] {i + 'a', charCounts[i]});
            }
        }
            
        var sb = new StringBuilder();
        while (!pq.isEmpty()) {
            var first = pq.poll();
            if (sb.length() == 0 || first[0] != sb.charAt(sb.length() - 1)) {
                sb.append((char) first[0]);
                if (--first[1] > 0) {
                    pq.offer(first);
                }
            } else {
                if (pq.isEmpty()) {
                    return "";
                }
                
                var second = pq.poll();
                sb.append((char) second[0]);
                if (--second[1] > 0) {
                    pq.offer(second);
                }
                
                pq.offer(first);
            }
        }
        
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reorganizeString(self, s: str) -> str:
        ans = []
        # Min heap ordered by character counts, so we will use
        # negative values for count
        pq = [(-count, char) for char, count in Counter(s).items()]
        heapify(pq)

        while pq:
            count_first, char_first = heappop(pq)
            if not ans or char_first != ans[-1]:
                ans.append(char_first)
                if count_first + 1 != 0: 
                    heappush(pq, (count_first + 1, char_first))
            else:
                if not pq: return ''
                count_second, char_second = heappop(pq)
                ans.append(char_second)
                if count_second + 1 != 0:
                    heappush(pq, (count_second + 1, char_second))
                heappush(pq, (count_first, char_first))

        return ''.join(ans)
```

</details>

<br>

## Approach 2: Counting and Odd/Even

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> charCounts(26, 0);
        for (char c : s) {
            charCounts[c - 'a']++;
        }
        int maxCount = 0, letter = 0;
        for (int i = 0; i < charCounts.size(); i++) {
            if (charCounts[i] > maxCount) {
                maxCount = charCounts[i];
                letter = i;
            }
        }
        if (maxCount > (s.length() + 1) / 2) {
            return "";
        }
        string ans = s;
        int index = 0;

        // Place the most frequent letter
        while (charCounts[letter] != 0) {
            ans[index] = char(letter + 'a');
            index += 2;
            charCounts[letter]--;
        }

        // Place rest of the letters in any order
        for (int i = 0; i < charCounts.size(); i++) {
            while (charCounts[i] > 0) {
                if (index >= s.length()) {
                    index = 1;
                }
                ans[index] = char(i + 'a');
                index += 2;
                charCounts[i]--;
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
    public String reorganizeString(String s) {
        var charCounts = new int[26];
        for (char c : s.toCharArray()) {
            charCounts[c - 'a']++;
        }
        int maxCount = 0, letter = 0;
        for (int i = 0; i < charCounts.length; i++) {
            if (charCounts[i] > maxCount) {
                maxCount = charCounts[i];
                letter = i;
            }
        }
        if (maxCount > (s.length() + 1) / 2) {
            return "";
        }
        var ans = new char[s.length()];
        int index = 0;

        // Place the most frequent letter
        while (charCounts[letter] != 0) {
            ans[index] = (char) (letter + 'a');
            index += 2;
            charCounts[letter]--;
        }

        // Place rest of the letters in any order
        for (int i = 0; i < charCounts.length; i++) {
            while (charCounts[i] > 0) {
                if (index >= s.length()) {
                    index = 1;
                }
                ans[index] = (char) (i + 'a');
                index += 2;
                charCounts[i]--;
            }
        }

        return String.valueOf(ans);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reorganizeString(self, s: str) -> str:
        char_counts = Counter(s)
        max_count, letter = 0, ''
        for char, count in char_counts.items():
            if count > max_count:
                max_count = count
                letter = char
        if max_count > (len(s) + 1) // 2:
            return ""
        ans = [''] * len(s)
        index = 0

        # Place the most frequent letter
        while char_counts[letter] != 0:
            ans[index] = letter
            index += 2
            char_counts[letter] -= 1

        # Place rest of the letters in any order
        for char, count in char_counts.items():
            while count > 0:
                if index >= len(s):
                    index = 1
                ans[index] = char
                index += 2
                count -= 1

        return ''.join(ans)
```

</details>
