# 256. Paint House

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/paint-house/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 256 - Paint House](https://leetcode.com/problems/paint-house/)

## Problem

There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

- For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...

Return the minimum cost to paint all houses.

### Example 1

```text
Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.
```

### Example 2

```text
Input: costs = [[7,6,2]]
Output: 2
```

## Constraints

- costs.length == n
- costs[i].length == 3
- 1 <= n <= 100
- 1 <= costs[i][j] <= 20

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [House Robber](https://leetcode.com/problems/house-robber/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [House Robber II](https://leetcode.com/problems/house-robber-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Paint House II](https://leetcode.com/problems/paint-house-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Paint Fence](https://leetcode.com/problems/paint-fence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Path Cost in a Grid](https://leetcode.com/problems/minimum-path-cost-in-a-grid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 256. Paint House

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute force |  |
| Brute force with a Recursive Tree | C++, Java, Python3 |
| Memoization | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |
| Dynamic Programming with Optimized Space Complexity | C++, Java, Python3 |

## Approach 1: Brute force

### Implementation

<br>

## Approach 2: Brute force with a Recursive Tree

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> costs;
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) {
            return 0;
        }
        this->costs = costs;
        return min(paintCost(0, 0), min(paintCost(0, 1), paintCost(0, 2)));
    }

    int paintCost(int n, int color) {
        int totalCost = costs[n][color];
        if (n == costs.size() - 1) {
        } else if (color == 0) {  // Red
            totalCost += min(paintCost(n + 1, 1), paintCost(n + 1, 2));
        } else if (color == 1) {  // Green
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 2));
        } else {  // Blue
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 1));
        }
        return totalCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int[][] costs;

    public int minCost(int[][] costs) {
        if (costs.length == 0) {
            return 0;
        }
        this.costs = costs;
        return Math.min(
            paintCost(0, 0),
            Math.min(paintCost(0, 1), paintCost(0, 2))
        );
    }

    private int paintCost(int n, int color) {
        int totalCost = costs[n][color];
        if (n == costs.length - 1) {} else if (color == 0) { // Red
            totalCost += Math.min(paintCost(n + 1, 1), paintCost(n + 1, 2));
        } else if (color == 1) { // Green
            totalCost += Math.min(paintCost(n + 1, 0), paintCost(n + 1, 2));
        } else { // Blue
            totalCost += Math.min(paintCost(n + 1, 0), paintCost(n + 1, 1));
        }
        return totalCost;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        def paint_cost(n: int, color: int) -> int:
            total_cost = costs[n][color]
            if n == len(costs) - 1:
                return total_cost
            if color == 0:  # Red
                total_cost += min(paint_cost(n + 1, 1), paint_cost(n + 1, 2))
            elif color == 1:  # Green
                total_cost += min(paint_cost(n + 1, 0), paint_cost(n + 1, 2))
            else:  # Blue
                total_cost += min(paint_cost(n + 1, 0), paint_cost(n + 1, 1))
            return total_cost

        if not costs:
            return 0
        return min(paint_cost(0, 0), paint_cost(0, 1), paint_cost(0, 2))
```

</details>

<br>

## Approach 3: Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    vector<vector<int>> costs;
    unordered_map<string, int> memo;

public:
    int minCost(vector<vector<int>>& _costs) {
        if (_costs.size() == 0) {
            return 0;
        }
        this->costs = _costs;
        return min(paintCost(0, 0), min(paintCost(0, 1), paintCost(0, 2)));
    }

private:
    int paintCost(int n, int color) {
        string key = getKey(n, color);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        int totalCost = costs[n][color];
        if (n == costs.size() - 1) {
        } else if (color == 0) {  // Red
            totalCost += min(paintCost(n + 1, 1), paintCost(n + 1, 2));
        } else if (color == 1) {  // Green
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 2));
        } else {  // Blue
            totalCost += min(paintCost(n + 1, 0), paintCost(n + 1, 1));
        }
        memo[key] = totalCost;

        return totalCost;
    }

    string getKey(int n, int color) {
        return to_string(n) + " " + to_string(color);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int[][] costs;
    private Map<String, Integer> memo;

    public int minCost(int[][] costs) {
        if (costs.length == 0) {
            return 0;
        }
        this.costs = costs;
        this.memo = new HashMap<>();
        return Math.min(
            paintCost(0, 0),
            Math.min(paintCost(0, 1), paintCost(0, 2))
        );
    }

    private int paintCost(int n, int color) {
        if (memo.containsKey(getKey(n, color))) {
            return memo.get(getKey(n, color));
        }
        int totalCost = costs[n][color];
        if (n == costs.length - 1) {} else if (color == 0) { // Red
            totalCost += Math.min(paintCost(n + 1, 1), paintCost(n + 1, 2));
        } else if (color == 1) { // Green
            totalCost += Math.min(paintCost(n + 1, 0), paintCost(n + 1, 2));
        } else { // Blue
            totalCost += Math.min(paintCost(n + 1, 0), paintCost(n + 1, 1));
        }
        memo.put(getKey(n, color), totalCost);

        return totalCost;
    }

    private String getKey(int n, int color) {
        return String.valueOf(n) + " " + String.valueOf(color);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from typing import List

class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        self.memo = {}

        def paint_cost(n: int, color: int) -> int:
            if (n, color) in self.memo:
                return self.memo[(n, color)]
            
            total_cost = costs[n][color]
            if n < len(costs) - 1:
                if color == 0:
                    total_cost += min(paint_cost(n + 1, 1), paint_cost(n + 1, 2))
                elif color == 1:
                    total_cost += min(paint_cost(n + 1, 0), paint_cost(n + 1, 2))
                else:
                    total_cost += min(paint_cost(n + 1, 0), paint_cost(n + 1, 1))

            self.memo[(n, color)] = total_cost
            return total_cost

        if not costs:
            return 0

        return min(paint_cost(0, 0), paint_cost(0, 1), paint_cost(0, 2))
```

</details>

<br>

## Approach 4: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        for (int n = costs.size() - 2; n >= 0; n--) {
            // Total cost of painting the nth house red.
            costs[n][0] += min(costs[n + 1][1], costs[n + 1][2]);
            // Total cost of painting the nth house green.
            costs[n][1] += min(costs[n + 1][0], costs[n + 1][2]);
            // Total cost of painting the nth house blue.
            costs[n][2] += min(costs[n + 1][0], costs[n + 1][1]);
        }

        return min(min(costs[0][0], costs[0][1]), costs[0][2]);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minCost(int[][] costs) {
        if (costs.length == 0) return 0;
        for (int n = costs.length - 2; n >= 0; n--) {
            // Total cost of painting the nth house red.
            costs[n][0] += Math.min(costs[n + 1][1], costs[n + 1][2]);
            // Total cost of painting the nth house green.
            costs[n][1] += Math.min(costs[n + 1][0], costs[n + 1][2]);
            // Total cost of painting the nth house blue.
            costs[n][2] += Math.min(costs[n + 1][0], costs[n + 1][1]);
        }

        return Math.min(Math.min(costs[0][0], costs[0][1]), costs[0][2]);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        if not costs:
            return 0
        for n in reversed(range(len(costs) - 1)):
            # Total cost of painting nth house red.
            costs[n][0] += min(costs[n + 1][1], costs[n + 1][2])
            # Total cost of painting nth house green.
            costs[n][1] += min(costs[n + 1][0], costs[n + 1][2])
            # Total cost of painting nth house blue.
            costs[n][2] += min(costs[n + 1][0], costs[n + 1][1])

        return min(costs[0])  # Return the minimum in the first row.
```

</details>

<br>

## Approach 5: Dynamic Programming with Optimized Space Complexity

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;

        vector<int> previousRow = costs[costs.size() - 1];

        for (int n = costs.size() - 2; n >= 0; n--) {
            vector<int> currentRow = costs[n];
            // Total cost of painting the nth house red.
            currentRow[0] += min(previousRow[1], previousRow[2]);
            // Total cost of painting the nth house green.
            currentRow[1] += min(previousRow[0], previousRow[2]);
            // Total cost of painting the nth house blue.
            currentRow[2] += min(previousRow[0], previousRow[1]);
            previousRow = currentRow;
        }

        return min({previousRow[0], previousRow[1], previousRow[2]});
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minCost(int[][] costs) {
        if (costs.length == 0) return 0;

        int[] previousRow = costs[costs.length - 1];

        for (int n = costs.length - 2; n >= 0; n--) {
            int[] currentRow = costs[n].clone();
            // Total cost of painting the nth house red.
            currentRow[0] += Math.min(previousRow[1], previousRow[2]);
            // Total cost of painting the nth house green.
            currentRow[1] += Math.min(previousRow[0], previousRow[2]);
            // Total cost of painting the nth house blue.
            currentRow[2] += Math.min(previousRow[0], previousRow[1]);
            previousRow = currentRow;
        }

        return Math.min(
            Math.min(previousRow[0], previousRow[1]),
            previousRow[2]
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import copy

class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        if not costs:
            return 0

        previous_row = costs[-1][:]
        for n in reversed(range(len(costs) - 1)):
            current_row = costs[n][:]  # Copy current row without using deepcopy
            
            # Total cost of painting nth house red
            current_row[0] += min(previous_row[1], previous_row[2])
            # Total cost of painting nth house green
            current_row[1] += min(previous_row[0], previous_row[2])
            # Total cost of painting nth house blue
            current_row[2] += min(previous_row[0], previous_row[1])
            
            previous_row = current_row  # Update previous_row for the next iteration

        return min(previous_row)
```

</details>
