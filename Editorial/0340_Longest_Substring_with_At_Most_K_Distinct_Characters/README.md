# 340. Longest Substring with At Most K Distinct Characters

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)  
`Hash Table` `String` `Sliding Window`

**Problem Link:** [LeetCode 340 - Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)

## Problem

Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

### Example 1

```text
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
```

### Example 2

```text
Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
```

## Constraints

- 1 <= s.length <= 5 * 104
- 0 <= k <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 340. Longest Substring with At Most K Distinct Characters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search + Fixed Size Sliding Window | Java, Python3 |
| Sliding Window | Java, Python3 |
| Sliding Window II | Java, Python3 |

## Approach 1: Binary Search + Fixed Size Sliding Window

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int n = s.length();
        if (k >= n) {
            return n;
        }
        
        int left = k, right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            
            if (isValid(s, mid, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
    
    private boolean isValid(String s, int size, int k) {
        int n = s.length();
        Map<Character, Integer> counter = new HashMap<>();
        
        for (int i = 0; i < size; i++) {
            char c = s.charAt(i);
            counter.put(c, counter.getOrDefault(c, 0) + 1);
        }
        
        if (counter.size() <= k) {
            return true;
        }
        
        for (int i = size; i < n; i++) {
            char c1 = s.charAt(i);
            counter.put(c1, counter.getOrDefault(c1, 0) + 1);
            char c2 = s.charAt(i - size);
            counter.put(c2, counter.getOrDefault(c2, 0) - 1);
            if (counter.get(c2) == 0) {
                counter.remove(c2);
            }
            if (counter.size() <= k) {
                return true;
            }
        }
        
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        n = len(s)
        if k >= n:
            return n
        left, right = k, n
        
        def isValid(size):
            counter = collections.Counter(s[:size])
            if len(counter) <= k:
                return True
            for i in range(size, n):
                counter[s[i]] += 1
                counter[s[i - size]] -= 1
                if counter[s[i - size]] == 0:
                    del counter[s[i - size]]
                if len(counter) <= k:
                    return True
            return False
        
        while left < right:
            mid = (left + right + 1) // 2
            
            if isValid(mid):
                left = mid
            else:
                right = mid - 1
        
        return left
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int n = s.length();
        int maxSize = 0;
        Map<Character, Integer> counter = new HashMap<>();
        
        int left = 0;
        for (int right = 0; right < n; right++) {
            counter.put(s.charAt(right), counter.getOrDefault(s.charAt(right), 0) + 1);
            
            while (counter.size() > k) {
                counter.put(s.charAt(left), counter.get(s.charAt(left)) - 1);
                if (counter.get(s.charAt(left)) == 0) {
                    counter.remove(s.charAt(left));
                }
                left++;
            }
            
            maxSize = Math.max(maxSize, right - left + 1);
        }
                    
        return maxSize;  
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        n = len(s)
        max_size = 0
        counter = collections.Counter()
        
        left = 0
        for right in range(n):
            counter[s[right]] += 1
            
            while len(counter) > k: 
                counter[s[left]] -= 1
                if counter[s[left]] == 0:
                    del counter[s[left]]
                left += 1
            
            max_size = max(max_size, right - left + 1)
                    
        return max_size
```

</details>

<br>

## Approach 3: Sliding Window II

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int n = s.length();
        int maxSize = 0;
        Map<Character, Integer> counter = new HashMap<>();
        
        for (int right = 0; right < n; right++) {
            counter.put(s.charAt(right), counter.getOrDefault(s.charAt(right), 0) + 1);
            
            if (counter.size() <= k) {
                maxSize++;
            } else {
                counter.put(s.charAt(right - maxSize), counter.get(s.charAt(right - maxSize)) - 1);
                if (counter.get(s.charAt(right - maxSize)) == 0) {
                    counter.remove(s.charAt(right - maxSize));
                }
            }
        }

        return maxSize; 
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        max_size = 0
        counter = collections.Counter()
        
        for right in range(len(s)):
            counter[s[right]] += 1
            
            if len(counter) <= k:
                max_size += 1
            else:
                counter[s[right - max_size]] -= 1
                if counter[s[right - max_size]] == 0:
                    del counter[s[right - max_size]]

        return max_size
```

</details>
