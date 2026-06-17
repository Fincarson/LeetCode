# 276. Paint Fence

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/paint-fence/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 276 - Paint Fence](https://leetcode.com/problems/paint-fence/)

## Problem

You are painting a fence of n posts with k different colors. You must paint the posts following these rules:

- Every post must be painted exactly one color.
- There cannot be three or more consecutive posts with the same color.

Given the two integers n and k, return the number of ways you can paint the fence.

### Example 1

```text
Input: n = 3, k = 2
Output: 6
Explanation: All the possibilities are shown.
Note that painting all the posts red or all the posts green is invalid because there cannot be three posts in a row with the same color.
```

### Example 2

```text
Input: n = 1, k = 1
Output: 1
```

### Example 3

```text
Input: n = 7, k = 2
Output: 42
```

## Constraints

- 1 <= n <= 50
- 1 <= k <= 105
- The testcases are generated such that the answer is in the range [0, 231 - 1] for the given n and k.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [House Robber](https://leetcode.com/problems/house-robber/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [House Robber II](https://leetcode.com/problems/house-robber-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Paint House](https://leetcode.com/problems/paint-house/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Paint House II](https://leetcode.com/problems/paint-house-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 276. Paint Fence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming (Recursion + Memoization) | Java, Python3 |
| Bottom-Up Dynamic Programming (Tabulation) | Java, Python3 |
| Bottom-Up, Constant Space | Java, Python3 |

## Approach 1: Top-Down Dynamic Programming (Recursion + Memoization)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private HashMap<Integer, Integer> memo = new HashMap<Integer, Integer>();
    
    private int totalWays(int i, int k) {
        if (i == 1) return k;
        if (i == 2) return k * k;
        
        // Check if we have already calculated totalWays(i)
        if (memo.containsKey(i)) {
            return memo.get(i);
        }
        
        // Use the recurrence relation to calculate totalWays(i)
        memo.put(i, (k - 1) * (totalWays(i - 1, k) + totalWays(i - 2, k)));
        return memo.get(i);
    }
    
    public int numWays(int n, int k) {
        return totalWays(n, k);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWays(self, n: int, k: int) -> int:
        def total_ways(i):
            if i == 1:
                return k
            if i == 2:
                return k * k
            
            # Check if we have already calculated totalWays(i)
            if i in memo:
                return memo[i]
            
            # Use the recurrence relation to calculate total_ways(i)
            memo[i] = (k - 1) * (total_ways(i - 1) + total_ways(i - 2))
            return memo[i]

        memo = {}
        return total_ways(n)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming (Tabulation)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numWays(int n, int k) {
        // Base cases for the problem to avoid index out of bound issues
        if (n == 1) return k;
        if (n == 2) return k * k;
        
        int totalWays[] = new int[n + 1];
        totalWays[1] = k;
        totalWays[2] = k * k;
        
        for (int i = 3; i <= n; i++) {
            totalWays[i] = (k - 1) * (totalWays[i - 1] + totalWays[i - 2]);
        }
        
        return totalWays[n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWays(self, n: int, k: int) -> int:
        # Base cases for the problem to avoid index out of bound issues
        if n == 1:
            return k
        if n == 2:
            return k * k

        total_ways = [0] * (n + 1)
        total_ways[1] = k
        total_ways[2] = k * k
        
        for i in range(3, n + 1):
            total_ways[i] = (k - 1) * (total_ways[i - 1] + total_ways[i - 2])
        
        return total_ways[n]
```

</details>

<br>

## Approach 3: Bottom-Up, Constant Space

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numWays(int n, int k) {
        if (n == 1) return k;
        
        int twoPostsBack = k;
        int onePostBack = k * k;
        
        for (int i = 3; i <= n; i++) {
            int curr = (k - 1) * (onePostBack + twoPostsBack);
            twoPostsBack = onePostBack;
            onePostBack = curr;
        }
        
        return onePostBack;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n == 1:
            return k
        
        two_posts_back = k
        one_post_back = k * k
        
        for i in range(3, n + 1):
            curr = (k - 1) * (one_post_back + two_posts_back)
            two_posts_back = one_post_back
            one_post_back = curr

        return one_post_back
```

</details>
