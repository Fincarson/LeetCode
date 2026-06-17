# 567. Permutation in String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/permutation-in-string/)  
`Hash Table` `Two Pointers` `String` `Sliding Window`

**Problem Link:** [LeetCode 567 - Permutation in String](https://leetcode.com/problems/permutation-in-string/)

## Problem

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

### Example 1

```text
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
```

### Example 2

```text
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
```

## Constraints

- 1 <= s1.length, s2.length <= 104
- s1 and s2 consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 567. Permutation in String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Using sorting: | Java |
| Using Hashmap | Java |
| Using Array [Accepted] | Java |
| Sliding Window  [Accepted]: | Java, Python3 |
| Optimized Sliding Window [Accepted]: | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    boolean flag = false;

    public boolean checkInclusion(String s1, String s2) {
        permute(s1, s2, 0);
        return flag;
    }

    public String swap(String s, int i0, int i1) {
        if (i0 == i1)
            return s;
        String s1 = s.substring(0, i0);
        String s2 = s.substring(i0 + 1, i1);
        String s3 = s.substring(i1 + 1);
        return s1 + s.charAt(i1) + s2 + s.charAt(i0) + s3;
    }

    void permute(String s1, String s2, int l) {
        if (l == s1.length()) {
            if (s2.indexOf(s1) >= 0)
                flag = true;
        } else {
            for (int i = l; i < s1.length(); i++) {
                s1 = swap(s1, l, i);
                permute(s1, s2, l + 1);
                s1 = swap(s1, l, i);
            }
        }
    }
}
```

</details>

<br>

## Approach 2: Using sorting:

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        s1 = sort(s1);
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            if (s1.equals(sort(s2.substring(i, i + s1.length()))))
                return true;
        }
        return false;
    }

    public String sort(String s) {
        char[] t = s.toCharArray();
        Arrays.sort(t);
        return new String(t);
    }
}
```

</details>

<br>

## Approach 3: Using Hashmap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        HashMap<Character, Integer> s1map = new HashMap<>();

        for (int i = 0; i < s1.length(); i++)
            s1map.put(s1.charAt(i), s1map.getOrDefault(s1.charAt(i), 0) + 1);

        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            HashMap<Character, Integer> s2map = new HashMap<>();
            for (int j = 0; j < s1.length(); j++) {
                s2map.put(s2.charAt(i + j), s2map.getOrDefault(s2.charAt(i + j), 0) + 1);
            }
            if (matches(s1map, s2map))
                return true;
        }
        return false;
    }

    public boolean matches(HashMap<Character, Integer> s1map, HashMap<Character, Integer> s2map) {
        for (char key : s1map.keySet()) {
            if (s1map.get(key) - s2map.getOrDefault(key, -1) != 0)
                return false;
        }
        return true;
    }
}
```

</details>

<br>

## Approach 4: Using Array [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        int[] s1arr = new int[26];
        for (int i = 0; i < s1.length(); i++)
            s1arr[s1.charAt(i) - 'a']++;
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            int[] s2arr = new int[26];
            for (int j = 0; j < s1.length(); j++) {
                s2arr[s2.charAt(i + j) - 'a']++;
            }
            if (matches(s1arr, s2arr))
                return true;
        }
        return false;
    }

    public boolean matches(int[] s1arr, int[] s2arr) {
        for (int i = 0; i < 26; i++) {
            if (s1arr[i] != s2arr[i])
                return false;
        }
        return true;
    }
}
```

</details>

<br>

## Approach 5: Sliding Window  [Accepted]:

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        int[] s1arr = new int[26];
        int[] s2arr = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            s1arr[s1.charAt(i) - 'a']++;
            s2arr[s2.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (matches(s1arr, s2arr))
                return true;
            s2arr[s2.charAt(i + s1.length()) - 'a']++;
            s2arr[s2.charAt(i) - 'a']--;
        }
        return matches(s1arr, s2arr);
    }

    public boolean matches(int[] s1arr, int[] s2arr) {
        for (int i = 0; i < 26; i++) {
            if (s1arr[i] != s2arr[i])
                return false;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s2_len, s1_len = len(s2), len(s1)

        if s1_len > s2_len:
            return False

        s1_char_freq_arr = [0] * 26
        s2_window_char_freq_arr = [0] * 26

        for index in range(s1_len):
            s1_char_freq_arr[ord(s1[index]) - ord('a')] += 1
            s2_window_char_freq_arr[ord(s2[index]) - ord('a')] += 1

        if s1_char_freq_arr == s2_window_char_freq_arr:
            return True

        for index in range(s2_len - s1_len):
            s2_window_char_freq_arr[ord(s2[index]) - ord('a')] -= 1
            s2_window_char_freq_arr[ord(s2[index + s1_len]) - ord('a')] += 1

            if s1_char_freq_arr == s2_window_char_freq_arr:
                return True

        return False
```

</details>

<br>

## Approach 6: Optimized Sliding Window [Accepted]:

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        int[] s1arr = new int[26];
        int[] s2arr = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            s1arr[s1.charAt(i) - 'a']++;
            s2arr[s2.charAt(i) - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (s1arr[i] == s2arr[i])
                count++;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            int r = s2.charAt(i + s1.length()) - 'a', l = s2.charAt(i) - 'a';
            if (count == 26)
                return true;
            s2arr[r]++;
            if (s2arr[r] == s1arr[r]) {
                count++;
            } else if (s2arr[r] == s1arr[r] + 1) {
                count--;
            }
            s2arr[l]--;
            if (s2arr[l] == s1arr[l]) {
                count++;
            } else if (s2arr[l] == s1arr[l] - 1) {
                count--;
            }
        }
        return count == 26;
    }
}
```

</details>
