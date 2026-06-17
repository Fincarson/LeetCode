# 395. Longest Substring with At Least K Repeating Characters

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)  
`Hash Table` `String` `Divide and Conquer` `Sliding Window`

**Problem Link:** [LeetCode 395 - Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)

## Problem

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

if no such substring exists, return 0.

### Example 1

```text
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
```

### Example 2

```text
Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
```

## Constraints

- 1 <= s.length <= 104
- s consists of only lowercase English letters.
- 1 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Subsequence Repeated k Times](https://leetcode.com/problems/longest-subsequence-repeated-k-times/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Number of Equal Count Substrings](https://leetcode.com/problems/number-of-equal-count-substrings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Length of Longest Subarray With at Most K Frequency](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Longest Special Substring That Occurs Thrice II](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Longest Special Substring That Occurs Thrice I](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 395. Longest Substring with At Least K Repeating Characters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java |
| Divide And Conquer | C++, Java |
| Sliding Window | C++, Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() == 0 || k > s.length()) {
            return 0;
        }
        int countMap[26] = {0};
        int n = s.length();
        int result = 0;
        for (int start = 0; start < n; start++) {
            // reset the count map
            memset(countMap, 0, sizeof(countMap));
            for (int end = start; end < n; end++) {
                countMap[s[end] - 'a']++;
                if (isValid(s, start, end, k, countMap)) {
                    result = max(result, end - start + 1);
                }
            }
        }
        return result;
    }

    bool isValid(string s, int start, int end, int k, int countMap[26]) {
        int countLetters = 0, countAtLeastK = 0;
        for (int i = 0; i < 26; i++) {
            if (countMap[i] > 0) countLetters++;
            if (countMap[i] >= k) countAtLeastK++;
        }
        return countAtLeastK == countLetters;
    }

};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestSubstring(String s, int k) {
        if (s == null || s.isEmpty() || k > s.length()) {
            return 0;
        }
        int[] countMap = new int[26];
        int n = s.length();
        int result = 0;
        for (int start = 0; start < n; start++) {
            // reset the count map
            Arrays.fill(countMap, 0);
            for (int end = start; end < n; end++) {
                countMap[s.charAt(end) - 'a']++;
                if (isValid(s, start, end, k, countMap)) {
                    result = Math.max(result, end - start + 1);
                }
            }
        }
        return result;
    }

    private boolean isValid(String s, int start, int end, int k, int[] countMap) {
        int countLetters = 0, countAtLeastK = 0;
        for (int freq : countMap) {
            if (freq > 0) countLetters++;
            if (freq >= k) countAtLeastK++;
        }
        return countAtLeastK == countLetters;
    }
}
```

</details>

<br>

## Approach 2: Divide And Conquer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        return longestSubstringUtil(s, 0, n, k);
    }
    int longestSubstringUtil(string &s, int start, int end, int k) {
        if (end < k) return 0;
        int countMap[26] = {0};
        // update the countMap with the count of each character
        for (int i = start; i < end; i++)
            countMap[s[i] - 'a']++;
        for (int mid = start; mid < end; mid++) {
            if (countMap[s[mid] - 'a'] >= k) continue;
            int midNext = mid + 1;
            while (midNext < end && countMap[s[midNext] - 'a'] < k) midNext++;
            return max(longestSubstringUtil(s, start, mid, k),
                    longestSubstringUtil(s, midNext, end, k));
        }
        return (end - start);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestSubstring(String s, int k) {
        return longestSubstringUtil(s, 0, s.length(), k);
    }

    int longestSubstringUtil(String s, int start, int end, int k) {
        if (end < k) return 0;
        int[] countMap = new int[26];
        // update the countMap with the count of each character
        for (int i = start; i < end; i++)
            countMap[s.charAt(i) - 'a']++;
        for (int mid = start; mid < end; mid++) {
            if (countMap[s.charAt(mid) - 'a'] >= k) continue;
            int midNext = mid + 1;
            while (midNext < end && countMap[s.charAt(midNext) - 'a'] < k) midNext++;
            return Math.max(longestSubstringUtil(s, start, mid, k),
                    longestSubstringUtil(s, midNext, end, k));
        }
        return (end - start);
    }
}
```

</details>

<br>

## Approach 3: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSubstring(string s, int k) {
        int countMap[26];
        int maxUnique = getMaxUniqueLetters(s);
        int result = 0;
        for (int currUnique = 1; currUnique <= maxUnique; currUnique++) {
            // reset countMap
            memset(countMap, 0, sizeof(countMap));
            int windowStart = 0, windowEnd = 0, idx = 0, unique = 0, countAtLeastK = 0;
            while (windowEnd < s.size()) {
                // expand the sliding window
                if (unique <= currUnique) {
                    idx = s[windowEnd] - 'a';
                    if (countMap[idx] == 0) unique++;
                    countMap[idx]++;
                    if (countMap[idx] == k) countAtLeastK++;
                    windowEnd++;
                }
                // shrink the sliding window
                else {
                    idx = s[windowStart] - 'a';
                    if (countMap[idx] == k) countAtLeastK--;
                    countMap[idx]--;
                    if (countMap[idx] == 0) unique--;
                    windowStart++;
                }
                if (unique == currUnique && unique == countAtLeastK)
                    result = max(windowEnd - windowStart, result);
            }
        }

        return result;
    }

    // get the maximum number of unique letters in the string s
    int getMaxUniqueLetters(string s) {
        bool map[26] = {0};
        int maxUnique = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!map[s[i] - 'a']) {
                maxUnique++;
                map[s[i] - 'a'] = true;
            }
        }
        return maxUnique;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int longestSubstring(String s, int k) {
        char[] str = s.toCharArray();
        int[] countMap = new int[26];
        int maxUnique = getMaxUniqueLetters(s);
        int result = 0;
        for (int currUnique = 1; currUnique <= maxUnique; currUnique++) {
            // reset countMap
            Arrays.fill(countMap, 0);
            int windowStart = 0, windowEnd = 0, idx = 0, unique = 0, countAtLeastK = 0;
            while (windowEnd < str.length) {
                // expand the sliding window
                if (unique <= currUnique) {
                    idx = str[windowEnd] - 'a';
                    if (countMap[idx] == 0) unique++;
                    countMap[idx]++;
                    if (countMap[idx] == k) countAtLeastK++;
                    windowEnd++;
                }
                // shrink the sliding window
                else {
                    idx = str[windowStart] - 'a';
                    if (countMap[idx] == k) countAtLeastK--;
                    countMap[idx]--;
                    if (countMap[idx] == 0) unique--;
                    windowStart++;
                }
                if (unique == currUnique && unique == countAtLeastK)
                    result = Math.max(windowEnd - windowStart, result);
            }
        }

        return result;
    }

    // get the maximum number of unique letters in the string s
    int getMaxUniqueLetters(String s) {
        boolean map[] = new boolean[26];
        int maxUnique = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!map[s.charAt(i) - 'a']) {
                maxUnique++;
                map[s.charAt(i) - 'a'] = true;
            }
        }
        return maxUnique;
    }
}
```

</details>
