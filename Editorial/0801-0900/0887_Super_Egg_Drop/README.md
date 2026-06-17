# 887. Super Egg Drop

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/super-egg-drop/)  
`Math` `Binary Search` `Dynamic Programming`

**Problem Link:** [LeetCode 887 - Super Egg Drop](https://leetcode.com/problems/super-egg-drop/)

## Problem

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

### Example 1

```text
Input: k = 1, n = 2
Output: 2
Explanation:
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
```

### Example 2

```text
Input: k = 2, n = 6
Output: 3
```

### Example 3

```text
Input: k = 3, n = 14
Output: 4
```

## Constraints

- 1 <= k <= 100
- 1 <= n <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Egg Drop With 2 Eggs and N Floors](https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 887. Super Egg Drop

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming with Binary Search | Java, Python3 |
| Dynamic Programming with Optimality Criterion | Java, Python3 |
| Mathematical | Java, Python3 |

## Approach 1: Dynamic Programming with Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int superEggDrop(int K, int N) {
        return dp(K, N);
    }

    Map<Integer, Integer> memo = new HashMap();
    public int dp(int K, int N) {
        if (!memo.containsKey(N * 100 + K)) {
            int ans;
            if (N == 0)
                ans = 0;
            else if (K == 1)
                ans = N;
            else {
                int lo = 1, hi = N;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(K-1, x-1);
                    int t2 = dp(K, N-x);

                    if (t1 < t2)
                        lo = x;
                    else if (t1 > t2)
                        hi = x;
                    else
                        lo = hi = x;
                }

                ans = 1 + Math.min(Math.max(dp(K-1, lo-1), dp(K, N-lo)),
                                   Math.max(dp(K-1, hi-1), dp(K, N-hi)));
            }

            memo.put(N * 100 + K, ans);
        }

        return memo.get(N * 100 + K);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        @lru_cache(None)
        def dp(k, n):
            if n == 0:
                return 0
            if k == 1:
                return n
            lo, hi = 1, n
            # keep a gap of 2 X values to manually check later
            while lo + 1 < hi:
                x = (lo + hi) // 2
                t1 = dp(k-1, x-1)
                t2 = dp(k, n-x)

                if t1 < t2:
                    lo = x
                elif t1 > t2:
                    hi = x
                else:
                    lo = hi = x
            return 1 + min(max(dp(k-1, x-1), dp(k, n-x))for x in (lo, hi))

        return dp(K, N)
```

</details>

<br>

## Approach 2: Dynamic Programming with Optimality Criterion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int superEggDrop(int K, int N) {
        // Right now, dp[i] represents dp(1, i)
        int[] dp = new int[N+1];
        for (int i = 0; i <= N; ++i)
            dp[i] = i;

        for (int k = 2; k <= K; ++k) {
            // Now, we will develop dp2[i] = dp(k, i)
            int[] dp2 = new int[N+1];
            int x = 1;
            for (int n = 1; n <= N; ++n) {
                // Let's find dp2[n] = dp(k, n)
                // Increase our optimal x while we can make our answer better.
                // Notice max(dp[x-1], dp2[n-x]) > max(dp[x], dp2[n-x-1])
                // is simply max(T1(x-1), T2(x-1)) > max(T1(x), T2(x)).
                while (x < n && Math.max(dp[x-1], dp2[n-x]) > Math.max(dp[x], dp2[n-x-1]))
                    x++;

                // The final answer happens at this x.
                dp2[n] = 1 + Math.max(dp[x-1], dp2[n-x]);
            }

            dp = dp2;
        }

        return dp[N];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def superEggDrop(self, K: int, N: int) -> int:

        # Right now, dp[i] represents dp(1, i)
        dp = range(N+1)

        for k in range(2, K+1):
            # Now, we will develop dp2[i] = dp(k, i)
            dp2 = [0]
            x = 1
            for n in range(1, N+1):
                # Let's find dp2[n] = dp(k, n)
                # Increase our optimal x while we can make our answer better.
                # Notice max(dp[x-1], dp2[n-x]) > max(dp[x], dp2[n-x-1])
                # is simply max(T1(x-1), T2(x-1)) > max(T1(x), T2(x)).
                while x < n and max(dp[x-1], dp2[n-x]) > \
                                max(dp[x], dp2[n-x-1]):
                    x += 1

                # The final answer happens at this x.
                dp2.append(1 + max(dp[x-1], dp2[n-x]))

            dp = dp2
        return dp[-1]
```

</details>

<br>

## Approach 3: Mathematical

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int superEggDrop(int K, int N) {
        int lo = 1, hi = N;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (f(mi, K, N) < N)
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;
    }

    public int f(int x, int K, int N) {
        int ans = 0, r = 1;
        for (int i = 1; i <= K; ++i) {
            r *= x-i+1;
            r /= i;
            ans += r;
            if (ans >= N) break;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        def f(x):
            ans = 0
            r = 1
            for i in range(1, K+1):
                r *= x-i+1
                r //= i
                ans += r
                if ans >= N: break
            return ans

        lo, hi = 1, N
        while lo < hi:
            mi = (lo + hi) // 2
            if f(mi) < N:
                lo = mi + 1
            else:
                hi = mi
        return lo
```

</details>
