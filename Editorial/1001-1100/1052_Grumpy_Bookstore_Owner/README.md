# 1052. Grumpy Bookstore Owner

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/grumpy-bookstore-owner/)  
`Array` `Sliding Window`

**Problem Link:** [LeetCode 1052 - Grumpy Bookstore Owner](https://leetcode.com/problems/grumpy-bookstore-owner/)

## Problem

There is a bookstore owner that has a store open for n minutes. You are given an integer array customers of length n where customers[i] is the number of the customers that enter the store at the start of the ith minute and all those customers leave after the end of that minute.

During certain minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers entering during that minute are not satisfied. Otherwise, they are satisfied.

The bookstore owner knows a secret technique to remain not grumpy for minutes consecutive minutes, but this technique can only be used once.

Return the maximum number of customers that can be satisfied throughout the day.

### Example 1

### Example 2

## Constraints

- n == customers.length == grumpy.length
- 1 <= minutes <= n <= 2 * 104
- 0 <= customers[i] <= 1000
- grumpy[i] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1052. Grumpy Bookstore Owner

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window | C++, Java, Python3 |

## Approach 1: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unrealizedCustomers = 0;

        // Calculate initial number of unrealized customers in first 'minutes'
        // window
        for (int i = 0; i < minutes; i++) {
            unrealizedCustomers += customers[i] * grumpy[i];
        }

        int maxUnrealizedCustomers = unrealizedCustomers;

        // Slide the 'minutes' window across the rest of the customers array
        for (int i = minutes; i < n; i++) {
            // Add the current minute's unsatisfied customers if the owner is
            // grumpy and remove the customers that are out of the current
            // window
            unrealizedCustomers += customers[i] * grumpy[i];
            unrealizedCustomers -= customers[i - minutes] * grumpy[i - minutes];

            // Update the maximum unrealized customers
            maxUnrealizedCustomers =
                max(maxUnrealizedCustomers, unrealizedCustomers);
        }

        // Start with maximum possible satisfied customers due to secret
        // technique
        int totalCustomers = maxUnrealizedCustomers;

        // Add the satisfied customers during non-grumpy minutes
        for (int i = 0; i < n; i++) {
            totalCustomers += customers[i] * (1 - grumpy[i]);
        }

        // Return the maximum number of satisfied customers
        return totalCustomers;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n = customers.length;
        int unrealizedCustomers = 0;

        // Calculate initial number of unrealized customers in first 'minutes' window
        for (int i = 0; i < minutes; i++) {
            unrealizedCustomers += customers[i] * grumpy[i];
        }

        int maxUnrealizedCustomers = unrealizedCustomers;

        // Slide the 'minutes' window across the rest of the customers array
        for (int i = minutes; i < n; i++) {
            // Add the current minute's unsatisfied customers if the owner is grumpy
            // and remove the customers that are out of the current window
            unrealizedCustomers += customers[i] * grumpy[i];
            unrealizedCustomers -= customers[i - minutes] * grumpy[i - minutes];

            // Update the maximum unrealized customers
            maxUnrealizedCustomers = Math.max(
                maxUnrealizedCustomers,
                unrealizedCustomers
            );
        }

        // Start with maximum possible satisfied customers due to secret technique
        int totalCustomers = maxUnrealizedCustomers;

        // Add the satisfied customers during non-grumpy minutes
        for (int i = 0; i < customers.length; i++) {
            totalCustomers += customers[i] * (1 - grumpy[i]);
        }

        // Return the maximum number of satisfied customers
        return totalCustomers;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSatisfied(
        self, customers: List[int], grumpy: List[int], minutes: int
    ) -> int:
        n = len(customers)
        unrealized_customers = 0

        # Calculate initial number of unrealized customers in first 'minutes' window
        for i in range(minutes):
            unrealized_customers += customers[i] * grumpy[i]

        max_unrealized_customers = unrealized_customers

        # Slide the 'minutes' window across the rest of the customers array
        for i in range(minutes, n):
            # Add current minute's unsatisfied customers if the owner is grumpy
            # and remove the customers that are out of the current window
            unrealized_customers += customers[i] * grumpy[i]
            unrealized_customers -= customers[i - minutes] * grumpy[i - minutes]

            # Update the maximum unrealized customers
            max_unrealized_customers = max(
                max_unrealized_customers, unrealized_customers
            )

        # Start with maximum possible satisfied customers due to secret technique
        total_customers = max_unrealized_customers

        # Add the satisfied customers during non-grumpy minutes
        for i in range(n):
            total_customers += customers[i] * (1 - grumpy[i])

        # Return the maximum number of satisfied customers
        return total_customers
```

</details>
