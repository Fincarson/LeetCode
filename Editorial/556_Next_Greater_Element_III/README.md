# 556. Next Greater Element III

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/next-greater-element-iii/)  
`Math` `Two Pointers` `String`

**Problem Link:** [LeetCode 556 - Next Greater Element III](https://leetcode.com/problems/next-greater-element-iii/)

## Problem

Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

### Example 1

```text
Input: n = 12
Output: 21
```

### Example 2

```text
Input: n = 21
Output: -1
```

## Constraints

- 1 <= n <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Next Palindrome Using Same Digits](https://leetcode.com/problems/next-palindrome-using-same-digits/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 556. Next Greater Element III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force | Java |
| Approach #2 Linear Solution | Java |

## Approach #1 Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String swap(String s, int i0, int i1) {
        if (i0 == i1)
            return s;
        String s1 = s.substring(0, i0);
        String s2 = s.substring(i0 + 1, i1);
        String s3 = s.substring(i1 + 1);
        return s1 + s.charAt(i1) + s2 + s.charAt(i0) + s3;
    }
    ArrayList < String > list = new ArrayList < > ();
    void permute(String a, int l, int r) {
        int i;
        if (l == r)
            list.add(a);
        else {
            for (i = l; i <= r; i++) {
                a = swap(a, l, i);
                permute(a, l + 1, r);
                a = swap(a, l, i);
            }
        }
    }
    public int nextGreaterElement(int n) {
        String s = "" + n;
        permute(s, 0, s.length() - 1);
        Collections.sort(list);
        int i;
        for (i = list.size() - 1; i >= 0; i--) {
            if (list.get(i).equals("" + n))
                break;
        }
        return i == list.size() - 1 ? -1 : Integer.parseInt(list.get(i + 1));
    }
}
```

</details>

<br>

## Approach #2 Linear Solution

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public int nextGreaterElement(int n) {
        char[] a = ("" + n).toCharArray();
        int i = a.length - 2;
        while (i >= 0 && a[i + 1] <= a[i]) {
            i--;
        }
        if (i < 0)
            return -1;
        int j = a.length - 1;
        while (j >= 0 && a[j] <= a[i]) {
            j--;
        }
        swap(a, i, j);
        reverse(a, i + 1);
        try {
            return Integer.parseInt(new String(a));
        } catch (Exception e) {
            return -1;
        }
    }
    private void reverse(char[] a, int start) {
        int i = start, j = a.length - 1;
        while (i < j) {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    private void swap(char[] a, int i, int j) {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
```

</details>
