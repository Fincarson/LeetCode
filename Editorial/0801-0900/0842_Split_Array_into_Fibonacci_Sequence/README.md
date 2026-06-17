# 842. Split Array into Fibonacci Sequence

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/split-array-into-fibonacci-sequence/)  
`String` `Backtracking`

**Problem Link:** [LeetCode 842 - Split Array into Fibonacci Sequence](https://leetcode.com/problems/split-array-into-fibonacci-sequence/)

## Problem

You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:

- 0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
- f.length >= 3, and
- f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.

Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.

### Example 1

```text
Input: num = "1101111"
Output: [11,0,11,11]
Explanation: The output [110, 1, 111] would also be accepted.
```

### Example 2

```text
Input: num = "112358130"
Output: []
Explanation: The task is impossible.
```

### Example 3

```text
Input: num = "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
```

## Constraints

- 1 <= num.length <= 200
- num contains only digits.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Additive Number](https://leetcode.com/problems/additive-number/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Fibonacci Number](https://leetcode.com/problems/fibonacci-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 842. Split Array into Fibonacci Sequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force [Accepted] | Java, Python |

## Approach #1: Brute Force [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        int N = S.length();
        for (int i = 0; i < Math.min(10, N); ++i) {
            if (S.charAt(0) == '0' && i > 0) break;
            long a = Long.valueOf(S.substring(0, i+1));
            if (a >= Integer.MAX_VALUE) break;

            search: for (int j = i+1; j < Math.min(i+10, N); ++j) {
                if (S.charAt(i+1) == '0' && j > i+1) break;
                long b = Long.valueOf(S.substring(i+1, j+1));
                if (b >= Integer.MAX_VALUE) break;

                List<Integer> fib = new ArrayList();
                fib.add((int) a);
                fib.add((int) b);

                int k = j + 1;
                while (k < N) {
                    long nxt = fib.get(fib.size() - 2) + fib.get(fib.size() - 1);
                    String nxtS = String.valueOf(nxt);

                    if (nxt <= Integer.MAX_VALUE && S.substring(k).startsWith(nxtS)) {
                        k += nxtS.length();
                        fib.add((int) nxt);
                    }
                    else continue search;
                }
                if (fib.size() >= 3) return fib;
            }
        }

        return new ArrayList<Integer>();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def splitIntoFibonacci(self, S):
        for i in xrange(min(10, len(S))):
            x = S[:i+1]
            if x != '0' and x.startswith('0'): break
            a = int(x)
            for j in xrange(i+1, min(i+10, len(S))):
                y = S[i+1: j+1]
                if y != '0' and y.startswith('0'): break
                b = int(y)
                fib = [a, b]
                k = j + 1
                while k < len(S):
                    nxt = fib[-1] + fib[-2]
                    nxtS = str(nxt)
                    if nxt <= 2**31 - 1 and S[k:].startswith(nxtS):
                        k += len(nxtS)
                        fib.append(nxt)
                    else:
                        break
                else:
                    if len(fib) >= 3:
                        return fib
        return []
```

</details>
