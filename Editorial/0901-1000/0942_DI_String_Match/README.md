# 942. DI String Match

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/di-string-match/)  
`Array` `Two Pointers` `String` `Greedy`

**Problem Link:** [LeetCode 942 - DI String Match](https://leetcode.com/problems/di-string-match/)

## Problem

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

- s[i] == 'I' if perm[i] < perm[i + 1], and
- s[i] == 'D' if perm[i] > perm[i + 1].

Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.

### Example 1

```text
Input: s = "IDID"
Output: [0,4,1,3,2]
```

### Example 2

```text
Input: s = "III"
Output: [0,1,2,3]
```

### Example 3

```text
Input: s = "DDI"
Output: [3,2,0,1]
```

## Constraints

- 1 <= s.length <= 105
- s[i] is either 'I' or 'D'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Construct Smallest Number From DI String](https://leetcode.com/problems/construct-smallest-number-from-di-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 942. DI String Match

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Ad-Hoc | C++, Java, Python3 |

## Approach 1: Ad-Hoc

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int N = s.length();
        int lo = 0, hi = N;
        vector<int> ans(N + 1);

        for (int i = 0; i < N; ++i) {
            if (s[i] == 'I') {
                ans[i] = lo++;
            } else {
                ans[i] = hi--;
            }
        }

        ans[N] = lo;
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] diStringMatch(String S) {
        int N = S.length();
        int lo = 0, hi = N;
        int[] ans = new int[N + 1];
        for (int i = 0; i < N; ++i) {
            if (S.charAt(i) == 'I') ans[i] = lo++;
            else ans[i] = hi--;
        }

        ans[N] = lo;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        lo, hi = 0, len(s)
        ans = []
        for x in s:
            if x == "I":
                ans.append(lo)
                lo += 1
            else:
                ans.append(hi)
                hi -= 1

        return ans + [lo]
```

</details>
