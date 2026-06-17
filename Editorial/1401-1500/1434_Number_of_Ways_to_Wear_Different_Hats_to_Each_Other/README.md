# 1434. Number of Ways to Wear Different Hats to Each Other

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/)  
`Array` `Dynamic Programming` `Bit Manipulation` `Bitmask`

**Problem Link:** [LeetCode 1434 - Number of Ways to Wear Different Hats to Each Other](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/)

## Problem

There are n people and 40 types of hats labeled from 1 to 40.

Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.

Return the number of ways that n people can wear different hats from each other.

Since the answer may be too large, return it modulo 109 + 7.

### Example 1

```text
Input: hats = [[3,4],[4,5],[5]]
Output: 1
Explanation: There is only one way to choose hats given the conditions.
First person chooses hat 3, Second person chooses hat 4 and last one hat 5.
```

### Example 2

```text
Input: hats = [[3,5,1],[3,5]]
Output: 4
Explanation: There are 4 ways to choose hats:
(3,5), (5,3), (1,3) and (1,5)
```

### Example 3

```text
Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
Output: 24
Explanation: Each person can choose hats labeled from 1 to 4.
Number of Permutations of (1,2,3,4) = 24.
```

## Constraints

- n == hats.length
- 1 <= n <= 10
- 1 <= hats[i].length <= 40
- 1 <= hats[i][j] <= 40
- hats[i] contains a list of unique integers.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Number of Good Subsets](https://leetcode.com/problems/the-number-of-good-subsets/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1434. Number of Ways to Wear Different Hats to Each Other

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming + Bitmasks | Java, Python3 |
| Bottom-Up Dynamic Programming | Java, Python3 |

## Approach 1: Top-Down Dynamic Programming + Bitmasks

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][] memo;
    int done;
    int n;
    int MOD = 1000000007;
    Map<Integer, ArrayList<Integer>> hatsToPeople;
    
    public int numberWays(List<List<Integer>> hats) {
        n = hats.size();
        
        hatsToPeople = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int hat: hats.get(i)) {
                if (!hatsToPeople.containsKey(hat)) {
                    hatsToPeople.put(hat, new ArrayList<>());
                }
                
                hatsToPeople.get(hat).add(i);
            }
        }
        
        done = (int) Math.pow(2, n) - 1;
        memo = new int[41][done];
        
        for (int i = 0; i < memo.length; i++) {
            for (int j = 0; j < memo[i].length; j++) {
                memo[i][j] = -1;
            }
        }
        
        return dp(1, 0);
    }
    
    private int dp(int hat, int mask) {
        if (mask == done) {
            return 1;
        }
        
        if (hat > 40) {
            return 0;
        }
        
        if (memo[hat][mask] != -1) {
            return memo[hat][mask];
        }
        
        int ans = dp(hat + 1, mask);
        
        if (hatsToPeople.containsKey(hat)) {
            for (int person: hatsToPeople.get(hat)) {
                if ((mask & (1 << person)) == 0) {
                    ans = (ans + dp(hat + 1, mask | (1 << person))) % MOD;
                }
            }
        }
        
        memo[hat][mask] = ans;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        @cache
        def dp(hat, mask):
            if mask == done:
                return 1
            
            if hat > 40:
                return 0
            
            ans = dp(hat + 1, mask)

            for person in hats_to_people[hat]:
                if mask & (1 << person) == 0:
                    ans = (ans + dp(hat + 1, mask | (1 << person))) % MOD

            return ans
        
        hats_to_people = defaultdict(list)
        for i in range(len(hats)):
            for hat in hats[i]:
                hats_to_people[hat].append(i)

        n = len(hats)
        MOD = 10 ** 9 + 7
        done = 2 ** n - 1
        return dp(1, 0)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberWays(List<List<Integer>> hats) {
        int n = hats.size();
        Map<Integer, ArrayList<Integer>> hatsToPeople = new HashMap<>();
        
        hatsToPeople = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int hat: hats.get(i)) {
                if (!hatsToPeople.containsKey(hat)) {
                    hatsToPeople.put(hat, new ArrayList<>());
                }
                
                hatsToPeople.get(hat).add(i);
            }
        }
        
        int done = (int) Math.pow(2, n) - 1;
        int MOD = 1000000007;
        
        int[][] dp = new int[42][done + 1];
        for (int i = 0; i < dp.length; i++) {
            dp[i][done] = 1;
        }
        
        for (int hat = 40; hat > 0; hat--) {
            for (int mask = done; mask >= 0; mask--) {
                int ans = dp[hat + 1][mask];
                if (hatsToPeople.containsKey(hat)) {
                    for (int person: hatsToPeople.get(hat)) {
                        if ((mask & (1 << person)) == 0) {
                            ans = (ans + dp[hat + 1][mask | (1 << person)]) % MOD;
                        }
                    }
                }
                
                dp[hat][mask] = ans;
            }
        }

        return dp[1][0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:        
        hats_to_people = defaultdict(list)
        for i in range(len(hats)):
            for hat in hats[i]:
                hats_to_people[hat].append(i)

        n = len(hats)
        MOD = 10 ** 9 + 7
        done = 2 ** n - 1
        
        dp = [[0] * (done + 1) for _ in range(42)]
        for i in range(len(dp)):
            dp[i][done] = 1
        
        for mask in range(done, -1, -1):
            for hat in range(40, 0, -1):
                ans = dp[hat + 1][mask]
                for person in hats_to_people[hat]:
                    if mask & (1 << person) == 0:
                        ans = (ans + dp[hat + 1][mask | (1 << person)]) % MOD

                dp[hat][mask] = ans
        
        return dp[1][0]
```

</details>
