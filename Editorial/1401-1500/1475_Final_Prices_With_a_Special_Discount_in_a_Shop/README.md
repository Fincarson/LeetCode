# 1475. Final Prices With a Special Discount in a Shop

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/)  
`Array` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 1475 - Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/)

## Problem

You are given an integer array prices where prices[i] is the price of the ith item in a shop.

There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.

### Example 1

```text
Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation:
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
```

### Example 2

```text
Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.
```

### Example 3

```text
Input: prices = [10,1,1,6]
Output: [9,0,1,6]
```

## Constraints

- 1 <= prices.length <= 500
- 1 <= prices[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1475. Final Prices With a Special Discount in a Shop

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute-Force | C++, Java, Python3 |
| Monotonic Stack | C++, Java, Python3 |

## Approach 1: Brute-Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        // Create a copy of original prices array to store discounted prices
        vector<int> result = prices;

        for (int i = 0; i < n; i++) {
            // Look for first smaller or equal price that comes after current
            // item
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    // Apply discount by subtracting prices[j] from current
                    // price
                    result[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        // Create a copy of original prices array to store discounted prices
        int[] result = prices.clone();

        for (int i = 0; i < n; i++) {
            // Look for first smaller or equal price that comes after current item
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    // Apply discount by subtracting prices[j] from current price
                    result[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        # Create a copy of original prices array to store discounted prices
        result = prices.copy()

        for i in range(len(prices)):
            # Look for first smaller or equal price that comes after current item
            for j in range(i + 1, len(prices)):
                if prices[j] <= prices[i]:
                    # Apply discount by subtracting prices[j] from current price
                    result[i] = prices[i] - prices[j]
                    break

        return result
```

</details>

<br>

## Approach 2: Monotonic Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Create a copy of prices array to store discounted prices
        vector<int> result = prices;

        stack<int> stack;

        for (int i = 0; i < prices.size(); i++) {
            // Process items that can be discounted by current price
            while (!stack.empty() && prices[stack.top()] >= prices[i]) {
                // Apply discount to previous item using current price
                result[stack.top()] -= prices[i];
                stack.pop();
            }
            // Add current index to stack
            stack.push(i);
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] finalPrices(int[] prices) {
        // Create a copy of prices array to store discounted prices
        int[] result = prices.clone();

        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < prices.length; i++) {
            // Process items that can be discounted by current price
            while (!stack.isEmpty() && prices[stack.peek()] >= prices[i]) {
                // Apply discount to previous item using current price
                result[stack.pop()] -= prices[i];
            }
            // Add current index to stack
            stack.add(i);
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        # Create a copy of prices array to store discounted prices
        result = prices.copy()

        stack = deque()

        for i in range(len(prices)):
            # Process items that can be discounted by current price
            while stack and prices[stack[-1]] >= prices[i]:
                # Apply discount to previous item using current price
                result[stack.pop()] -= prices[i]
            # Add current index to stack
            stack.append(i)

        return result
```

</details>
