# 989. Add to Array-Form of Integer

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/add-to-array-form-of-integer/)  
`Array` `Math`

**Problem Link:** [LeetCode 989 - Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/)

## Problem

The array-form of an integer num is an array representing its digits in left to right order.

- For example, for num = 1321, the array form is [1,3,2,1].

Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

### Example 1

```text
Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
```

### Example 2

```text
Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
```

### Example 3

```text
Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
```

## Constraints

- 1 <= num.length <= 104
- 0 <= num[i] <= 9
- num does not contain any leading zeros except for the zero itself.
- 1 <= k <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Plus One](https://leetcode.com/problems/plus-one/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Add Binary](https://leetcode.com/problems/add-binary/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Add Strings](https://leetcode.com/problems/add-strings/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 989. Add to Array-Form of Integer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Schoolbook Addition | Java, Python |

## Approach 1: Schoolbook Addition

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        int N = A.length;
        int cur = K;
        List<Integer> ans = new ArrayList();

        int i = N;
        while (--i >= 0 || cur > 0) {
            if (i >= 0)
                cur += A[i];
            ans.add(cur % 10);
            cur /= 10;
        }

        Collections.reverse(ans);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def addToArrayForm(self, A, K):
        A[-1] += K
        for i in xrange(len(A) - 1, -1, -1):
            carry, A[i] = divmod(A[i], 10)
            if i: A[i-1] += carry
        if carry:
            A = map(int, str(carry)) + A
        return A
```

</details>
