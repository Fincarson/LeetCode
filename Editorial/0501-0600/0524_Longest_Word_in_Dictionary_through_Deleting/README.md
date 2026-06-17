# 524. Longest Word in Dictionary through Deleting

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)  
`Array` `Two Pointers` `String` `Sorting`

**Problem Link:** [LeetCode 524 - Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)

## Problem

Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

### Example 1

```text
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
```

### Example 2

```text
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
```

## Constraints

- 1 <= s.length <= 1000
- 1 <= dictionary.length <= 1000
- 1 <= dictionary[i].length <= 1000
- s and dictionary[i] consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 524. Longest Word in Dictionary through Deleting

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Iterative Brute Force | Java |
| Sorting and Checking Subsequence | Java |
| Without Sorting | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String findLongestWord(String s, List < String > d) {
        HashSet < String > set = new HashSet < > (d);
        List < String > l = new ArrayList < > ();
        generate(s, "", 0, l);
        String max_str = "";
        for (String str: l) {
            if (set.contains(str))
                if (str.length() > max_str.length() || (str.length() == max_str.length() && str.compareTo(max_str) < 0))
                    max_str = str;
        }
        return max_str;
    }
    public void generate(String s, String str, int i, List < String > l) {
        if (i == s.length())
            l.add(str);
        else {
            generate(s, str + s.charAt(i), i + 1, l);
            generate(s, str, i + 1, l);
        }
    }
}
```

</details>

<br>

## Approach 2: Iterative Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String findLongestWord(String s, List < String > d) {
        HashSet < String > set = new HashSet < > (d);
        List < String > l = new ArrayList < > ();
        for (int i = 0; i < (1 << s.length()); i++) {
            String t = "";
            for (int j = 0; j < s.length(); j++) {
                if (((i >> j) & 1) != 0)
                    t += s.charAt(j);
            }
            l.add(t);
        }
        String max_str = "";
        for (String str: l) {
            if (set.contains(str))
                if (str.length() > max_str.length() || (str.length() == max_str.length() && str.compareTo(max_str) < 0))
                    max_str = str;
        }
        return max_str;
    }
}
```

</details>

<br>

## Approach 3: Sorting and Checking Subsequence

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean isSubsequence(String x, String y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x.charAt(j) == y.charAt(i))
                j++;
        return j == x.length();
    }
    public String findLongestWord(String s, List < String > d) {
        Collections.sort(d, new Comparator < String > () {
            public int compare(String s1, String s2) {
                return s2.length() != s1.length() ? s2.length() - s1.length() : s1.compareTo(s2);
            }
        });
        for (String str: d) {
            if (isSubsequence(str, s))
                return str;
        }
        return "";
    }
}
```

</details>

<br>

## Approach 4: Without Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean isSubsequence(String x, String y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x.charAt(j) == y.charAt(i))
                j++;
        return j == x.length();
    }
    public String findLongestWord(String s, List < String > d) {
        String max_str = "";
        for (String str: d) {
            if (isSubsequence(str, s)) {
                if (str.length() > max_str.length() || (str.length() == max_str.length() && str.compareTo(max_str) < 0))
                    max_str = str;
            }
        }
        return max_str;
    }
}
```

</details>
