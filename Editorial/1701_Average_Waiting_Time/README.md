# 1701. Average Waiting Time

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/average-waiting-time/)  
`Array` `Simulation`

**Problem Link:** [LeetCode 1701 - Average Waiting Time](https://leetcode.com/problems/average-waiting-time/)

## Problem

There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:

- arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
- timei is the time needed to prepare the order of the ith customer.

When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.

Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.

### Example 1

```text
Input: customers = [[1,2],[2,5],[4,3]]
Output: 5.00000
Explanation:
1) The first customer arrives at time 1, the chef takes his order and starts preparing it immediately at time 1, and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
2) The second customer arrives at time 2, the chef takes his order and starts preparing it at time 3, and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
3) The third customer arrives at time 4, the chef takes his order and starts preparing it at time 8, and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
So the average waiting time = (2 + 6 + 7) / 3 = 5.
```

### Example 2

```text
Input: customers = [[5,2],[5,4],[10,3],[20,1]]
Output: 3.25000
Explanation:
1) The first customer arrives at time 5, the chef takes his order and starts preparing it immediately at time 5, and finishes at time 7, so the waiting time of the first customer is 7 - 5 = 2.
2) The second customer arrives at time 5, the chef takes his order and starts preparing it at time 7, and finishes at time 11, so the waiting time of the second customer is 11 - 5 = 6.
3) The third customer arrives at time 10, the chef takes his order and starts preparing it at time 11, and finishes at time 14, so the waiting time of the third customer is 14 - 10 = 4.
4) The fourth customer arrives at time 20, the chef takes his order and starts preparing it immediately at time 20, and finishes at time 21, so the waiting time of the fourth customer is 21 - 20 = 1.
So the average waiting time = (2 + 6 + 4 + 1) / 4 = 3.25.
```

## Constraints

- 1 <= customers.length <= 105
- 1 <= arrivali, timei <= 104
- arrivali <= arrivali+1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Average Height of Buildings in Each Segment](https://leetcode.com/problems/average-height-of-buildings-in-each-segment/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1701. Average Waiting Time

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C++, Java, Python3 |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int nextIdleTime = 0;
        long long netWaitTime = 0;

        for (int i = 0; i < customers.size(); i++) {
            // The next idle time for the chef is given by the time of delivery
            // of current customer's order.
            nextIdleTime = max(customers[i][0], nextIdleTime) + customers[i][1];

            // The wait time for the current customer is the difference between
            // his delivery time and arrival time.
            netWaitTime += nextIdleTime - customers[i][0];
        }

        // Divide by total customers to get average.
        double averageWaitTime =
            static_cast<double>(netWaitTime) / customers.size();
        return averageWaitTime;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public double averageWaitingTime(int[][] customers) {
        int nextIdleTime = 0;
        long netWaitTime = 0;

        for (int i = 0; i < customers.length; i++) {
            // The next idle time for the chef is given by the time of delivery
            // of current customer's order.
            nextIdleTime = Math.max(customers[i][0], nextIdleTime) +
            customers[i][1];

            // The wait time for the current customer is the difference between
            // his delivery time and arrival time.
            netWaitTime += nextIdleTime - customers[i][0];
        }

        // Divide by total customers to get average.
        double averageWaitTime = (double) netWaitTime / customers.length;
        return averageWaitTime;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        next_idle_time = 0
        net_wait_time = 0

        for customer in customers:
            # The next idle time for the chef is given by the time of delivery
            # of current customer's order.
            next_idle_time = max(customer[0], next_idle_time) + customer[1]

            # The wait time for the current customer is the difference between
            # his delivery time and arrival time.
            net_wait_time += next_idle_time - customer[0]

        # Divide by total customers to get average.
        average_wait_time = net_wait_time / len(customers)
        return average_wait_time
```

</details>
