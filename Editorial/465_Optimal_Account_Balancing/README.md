# 465. Optimal Account Balancing

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/optimal-account-balancing/)  
`Array` `Dynamic Programming` `Backtracking` `Bit Manipulation` `Bitmask`

**Problem Link:** [LeetCode 465 - Optimal Account Balancing](https://leetcode.com/problems/optimal-account-balancing/)

## Problem

You are given an array of transactions transactions where transactions[i] = [fromi, toi, amounti] indicates that the person with ID = fromi gave amounti $ to the person with ID = toi.

Return the minimum number of transactions required to settle the debt.

### Example 1

```text
Input: transactions = [[0,1,10],[2,0,5]]
Output: 2
Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.
Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
```

### Example 2

```text
Input: transactions = [[0,1,10],[1,0,1],[1,2,5],[2,0,5]]
Output: 1
Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.
Therefore, person #1 only need to give person #0 $4, and all debt is settled.
```

## Constraints

- 1 <= transactions.length <= 8
- transactions[i].length == 3
- 0 <= fromi, toi < 12
- fromi != toi
- 1 <= amounti <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 465. Optimal Account Balancing

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | Java, Python3 |
| Dynamic Programming | Java, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minTransfers(int[][] transactions) {
        Map<Integer, Integer> creditMap = new HashMap<>();
        for (int[] t : transactions) {
            creditMap.put(t[0], creditMap.getOrDefault(t[0], 0) + t[2]);
            creditMap.put(t[1], creditMap.getOrDefault(t[1], 0) - t[2]);
        }
        
        creditList = new ArrayList<>();
        for (int amount : creditMap.values()) {
            if (amount != 0) {
                creditList.add(amount);
            }
        }
        
        int n = creditList.size();
        return dfs(0, n);
    }
    
    List<Integer> creditList;
    private int dfs(int cur, int n) {
        while (cur < n && creditList.get(cur) == 0) {
            cur++;
        }
    
        if (cur == n) {
            return 0;
        }
        
        int cost = Integer.MAX_VALUE;
        for (int nxt = cur + 1; nxt < n; nxt++) {
            // If nxt is a valid recipient, do the following: 
            // 1. add cur's balance to nxt.
            // 2. recursively call dfs(cur + 1).
            // 3. remove cur's balance from nxt.
            if (creditList.get(nxt) * creditList.get(cur) < 0) {
                creditList.set(nxt, creditList.get(nxt) + creditList.get(cur));
                cost = Math.min(cost, 1 + dfs(cur + 1, n));
                creditList.set(nxt, creditList.get(nxt) - creditList.get(cur));
            }
        }
        
        return cost;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        balance_map = collections.defaultdict(int)
        for a, b, amount in transactions:
            balance_map[a] += amount
            balance_map[b] -= amount
        
        balance_list = [amount for amount in balance_map.values() if amount]
        n = len(balance_list)
        
        def dfs(cur):
            while cur < n and not balance_list[cur]:
                cur += 1
            if cur == n:
                return 0
            cost = float('inf')
            for nxt in range(cur + 1, n):
                # If nxt is a valid recipient, do the following: 
                # 1. add cur's balance to nxt.
                # 2. recursively call dfs(cur + 1).
                # 3. remove cur's balance from nxt.
                if balance_list[nxt] * balance_list[cur] < 0:
                    balance_list[nxt] += balance_list[cur]
                    cost = min(cost, 1 + dfs(cur + 1))
                    balance_list[nxt] -= balance_list[cur]
            return cost
        
        return dfs(0)
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minTransfers(int[][] transactions) {
        Map<Integer, Integer> creditMap = new HashMap<>();
        for (int[] t : transactions) {
            creditMap.put(t[0], creditMap.getOrDefault(t[0], 0) + t[2]);
            creditMap.put(t[1], creditMap.getOrDefault(t[1], 0) - t[2]);
        }
        
        creditList = new ArrayList<>();
        for (int amount : creditMap.values()) {
            if (amount != 0) {
                creditList.add(amount);
            }
        }
        
        int n = creditList.size();
        int[] memo = new int[1 << n];
        Arrays.fill(memo, -1);
        memo[0] = 0;
        return n - dfs((1 << n) - 1, memo);
    }
    
    List<Integer> creditList;
    private int dfs(int totalMask, int[] memo) {
        if (memo[totalMask] != -1) {
            return memo[totalMask];
        }
        int balanceSum = 0, answer = 0;
        
        // Remove one person at a time in total_mask
        for (int i = 0; i < creditList.size(); i++) {
            int curBit = 1 << i;
            if ((totalMask & curBit) != 0) {
                balanceSum += creditList.get(i);
                answer = Math.max(answer, dfs(totalMask ^ curBit, memo));
            }
        }

        // If the total balance of total_mask is 0, increment answer by 1.
        memo[totalMask] = answer + (balanceSum == 0 ? 1 : 0);
        return memo[totalMask];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        balance_map = collections.defaultdict(int)
        for a, b, amount in transactions:
            balance_map[a] += amount
            balance_map[b] -= amount
        
        balance_list = [amount for amount in balance_map.values() if amount]
        n = len(balance_list)
        
        memo = [-1] * (1 << n)
        memo[0] = 0
        
        def dfs(total_mask):
            if memo[total_mask] != -1:
                return memo[total_mask]
            balance_sum, answer = 0, 0

            # Remove one person at a time in total_mask
            for i in range(n):
                cur_bit = 1 << i
                if total_mask & cur_bit:
                    balance_sum += balance_list[i]
                    answer = max(answer, dfs(total_mask ^ cur_bit))

            # If the total balance of total_mask is 0, increment answer by 1.
            memo[total_mask] = answer + (balance_sum == 0)
            return memo[total_mask]
        
        return n - dfs((1 << n) - 1)
```

</details>
