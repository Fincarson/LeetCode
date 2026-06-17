# 1833. Maximum Ice Cream Bars

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-ice-cream-bars/)  
`Array` `Greedy` `Sorting` `Counting Sort`

**Problem Link:** [LeetCode 1833 - Maximum Ice Cream Bars](https://leetcode.com/problems/maximum-ice-cream-bars/)

## Problem

It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible.

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.

### Example 1

```text
Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
```

### Example 2

```text
Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
```

### Example 3

```text
Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
```

## Constraints

- costs.length == n
- 1 <= n <= 105
- 1 <= costs[i] <= 105
- 1 <= coins <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1833. Maximum Ice Cream Bars

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting (Greedy) | C++, Java, JavaScript, Python3 |
| Counting Sort (Greedy) | C++, Java, JavaScript, Python3 |

## Approach 1: Sorting (Greedy)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Store ice cream costs in ascending order.
        sort(costs.begin(), costs.end());

        int n = costs.size();
        int icecream = 0;

        // Pick ice creams till we can.
        while (icecream < n && costs[icecream] <= coins) {
            // We can buy this icecream, reduce the cost from the coins. 
            coins -= costs[icecream];
            icecream += 1;
        }

        return icecream;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxIceCream(int[] costs, int coins) {
        // Store ice cream costs in increasing order.
        Arrays.sort(costs);

        int n = costs.length;
        int icecream = 0;

        // Pick ice creams till we can.
        while (icecream < n && costs[icecream] <= coins) {
            // We can buy this icecream, reduce the cost from the coins. 
            coins -= costs[icecream];
            icecream += 1;
        }

        return icecream;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxIceCream = function(costs, coins) {
    // Store ice cream costs in increasing order.
    costs.sort((num1, num2) => num1 - num2);

    let n = costs.length;
    let icecream = 0;

    // Pick ice creams till we can.
    while (icecream < n && costs[icecream] <= coins) {
        // We can buy this icecream, reduce the cost from the coins. 
        coins -= costs[icecream];
        icecream += 1;
    }

    return icecream;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        # Store ice cream costs in increasing order.
        costs.sort()
        n, icecream = len(costs), 0

        # Pick ice creams till we can.
        while icecream < n and costs[icecream] <= coins:
            # We can buy this icecream, reduce the cost from the coins. 
            coins -= costs[icecream]
            icecream += 1

        return icecream
```

</details>

<br>

## Approach 2: Counting Sort (Greedy)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int m = *max_element(costs.begin(), costs.end());
        int icecreams = 0;

        vector<int> costsFrequency(m + 1);
        for (auto& cost : costs) {
            costsFrequency[cost]++;
        }

        for (int cost = 1; cost <= m; ++cost) {
            // No ice cream is present costing 'cost'.
            if (costsFrequency[cost] == 0) {
                continue;
            }
            // We don't have enough 'coins' to even pick one ice cream.
            if (coins < cost) {
                break;
            }
            
            // Count how many icecreams of 'cost' we can pick with our 'coins'.
            // Either we can pick all ice creams of 'cost' or we will be limited by remaining 'coins'.
            int count = min(costsFrequency[cost], coins / cost);
            // We reduce price of picked ice creams from our coins.
            coins -= cost * count;
            icecreams += count;
        }

        return icecreams;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int n = costs.length;
        int icecreams = 0;

        int m = costs[0];
        for (int cost : costs) {
            m = Math.max(m, cost);
        }

        int[] costsFrequency = new int[m + 1];
        for (int cost : costs) {
            costsFrequency[cost]++;
        }

        for (int cost = 1; cost <= m; ++cost) {
            // No ice cream is present costing 'cost'.
            if (costsFrequency[cost] == 0) {
                continue;
            }
            // We don't have enough 'coins' to even pick one ice cream.
            if (coins < cost) {
                break;
            }
            
            // Count how many icecreams of 'cost' we can pick with our 'coins'.
            // Either we can pick all ice creams of 'cost' or we will be limited by remaining 'coins'.
            int count = Math.min(costsFrequency[cost], coins / cost);
            // We reduce price of picked ice creams from our coins.
            coins -= cost * count;
            icecreams += count;
        }

        return icecreams;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxIceCream = function(costs, coins) {
    let n = costs.length;
    let icecreams = 0;
    let m = Math.max(...costs);

    let costsFrequency = Array(m + 1).fill(0);
    for (let cost of costs) {
        costsFrequency[cost] += 1;
    }

    for (let cost = 1; cost <= m; ++cost) {
        // No ice cream is present costing 'cost'.
        if (!costsFrequency[cost]) {
            continue;
        }
        // We don't have enough 'coins' to even pick one ice cream.
        if (coins < cost) {
            break;
        }
        
        // Count how many icecreams of 'cost' we can pick with our 'coins'.
        // Either we can pick all ice creams of 'cost' or we will be limited by remaining 'coins'.
        let count = Math.min(costsFrequency[cost], Math.floor(coins / cost));
        // We reduce price of picked ice creams from our coins.
        coins -= cost * count;
        icecreams += count;
    }

    return icecreams;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        n, icecreams = len(costs), 0
        m = max(costs)

        costsFrequency = [0] * (m + 1)
        for cost in costs:
            costsFrequency[cost] += 1

        for cost in range(1, m + 1):
            # No ice cream is present costing 'cost'.
            if not costsFrequency[cost]:
                continue
            # We don't have enough 'coins' to even pick one ice cream.
            if coins < cost:
                break
            
            # Count how many icecreams of 'cost' we can pick with our 'coins'.
            # Either we can pick all ice creams of 'cost' or we will be limited by remaining 'coins'.
            count = min(costsFrequency[cost], coins // cost)
            # We reduce price of picked ice creams from our coins.
            coins -= cost * count
            icecreams += count
            
        return icecreams
```

</details>
