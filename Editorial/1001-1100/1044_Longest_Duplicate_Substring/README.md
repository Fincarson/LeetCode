# 1044. Longest Duplicate Substring

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/longest-duplicate-substring/)  
`String` `Binary Search` `Sliding Window` `Rolling Hash` `Suffix Array` `Hash Function`

**Problem Link:** [LeetCode 1044 - Longest Duplicate Substring](https://leetcode.com/problems/longest-duplicate-substring/)

## Problem

Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

### Example 1

```text
Input: s = "banana"
Output: "ana"
```

### Example 2

```text
Input: s = "abcd"
Output: ""
```

## Constraints

- 2 <= s.length <= 3 * 104
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1044. Longest Duplicate Substring

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search + Rabin-Karp | Java, Python |

## Approach 1: Binary Search + Rabin-Karp

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
h = (h * a - nums[start - 1] * aL % modulus + modulus) % modulus;
h = (h + nums[start + L - 1]) % modulus;
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
h = (h * a - nums[start - 1] * aL + nums[start + L - 1]) % modulus
```

</details>
