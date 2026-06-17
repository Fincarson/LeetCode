# 1672. Richest Customer Wealth

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/richest-customer-wealth/)  
`Array` `Matrix`

**Problem Link:** [LeetCode 1672 - Richest Customer Wealth](https://leetcode.com/problems/richest-customer-wealth/)

## Problem

You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the iÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹thÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ customer has in the jÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹thÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

### Example 1

```text
Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
```

### Example 2

```text
Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
Explanation:
1st customer has wealth = 6
2nd customer has wealth = 10
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.
```

### Example 3

```text
Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
Output: 17
```

## Constraints

- m == accounts.length
- n == accounts[i].length
- 1 <= m, n <= 50
- 1 <= accounts[i][j] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1672. Richest Customer Wealth

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Row Sum Maximum | C++, Java, Python3 |

## Approach 1: Row Sum Maximum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // Initialize the maximum wealth seen so far to 0 (the minimum wealth possible)
        int maxWealthSoFar = 0;
        
        // Iterate over accounts
        for (vector<int>& account : accounts) {
            // For each account, initialize the sum to 0
            int currCustomerWealth = 0;
            // Add the money in each bank
            for (int money : account) {
                currCustomerWealth += money;
            }
            // Update the maximum wealth seen so far if the current wealth is greater
            // If it is less than the current sum
            maxWealthSoFar = max(maxWealthSoFar, currCustomerWealth);
        }
        
        // Return the maximum wealth
        return maxWealthSoFar;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximumWealth(int[][] accounts) {
        // Initialize the maximum wealth seen so far to 0 (the minimum wealth possible)
        int maxWealthSoFar = 0;
        
        // Iterate over accounts
        for (int[] account : accounts) {
            // For each account, initialize the sum to 0
            int currCustomerWealth = 0;
            // Add the money in each bank
            for (int money : account) {
                currCustomerWealth += money;
            }
            // Update the maximum wealth seen so far if the current wealth is greater
            // If it is less than the current sum
            maxWealthSoFar = Math.max(maxWealthSoFar, currCustomerWealth);
        }
        
        // Return the maximum wealth
        return maxWealthSoFar;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        # Initialize the maximum wealth seen so far to 0 (the minimum wealth possible)
        max_wealth_so_far = 0
        
        # Iterate over accounts
        for account in accounts:
            # Add the money in each bank
            curr_customer_wealth = sum(account)
            # Update the maximum wealth seen so far if the current wealth is greater
            # If it is less than the current sum
            max_wealth_so_far = max(max_wealth_so_far, curr_customer_wealth)
            
        # Return the maximum wealth
        return max_wealth_so_far
```

</details>
