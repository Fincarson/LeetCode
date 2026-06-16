# 1029. Two City Scheduling

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/two-city-scheduling/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1029 - Two City Scheduling](https://leetcode.com/problems/two-city-scheduling/)

## Problem

A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

### Example 1

```text
Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
```

### Example 2

```text
Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
Output: 1859
```

### Example 3

```text
Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
Output: 3086
```

## Constraints

- 2 * n == costs.length
- 2 <= costs.length <= 100
- costs.length is even.
- 1 <= aCosti, bCosti <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rearrange Array to Maximize Prefix Score](https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1029. Two City Scheduling

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy. | C++, Java, Python |

## Approach 1: Greedy.

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    // Sort by a gain which company has 
    // by sending a person to city A and not to city B
    sort(begin(costs), end(costs),
            [](const vector<int> &o1, const vector<int> &o2) {
      return (o1[0] - o1[1] < o2[0] - o2[1]);
    });

    int total = 0;
    int n = costs.size() / 2;
    // To optimize the company expenses,
    // send the first n persons to the city A
    // and the others to the city B
    for (int i = 0; i < n; ++i) total += costs[i][0] + costs[i + n][1];
    return total;
  }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int twoCitySchedCost(int[][] costs) {
    // Sort by a gain which company has 
    // by sending a person to city A and not to city B
    Arrays.sort(costs, new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        return o1[0] - o1[1] - (o2[0] - o2[1]);
      }
    });

    int total = 0;
    int n = costs.length / 2;
    // To optimize the company expenses,
    // send the first n persons to the city A
    // and the others to the city B
    for (int i = 0; i < n; ++i) total += costs[i][0] + costs[i + n][1];
    return total;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        # Sort by a gain which company has 
        # by sending a person to city A and not to city B
        costs.sort(key = lambda x : x[0] - x[1])
        
        total = 0
        n = len(costs) // 2
        # To optimize the company expenses,
        # send the first n persons to the city A
        # and the others to the city B
        for i in range(n):
            total += costs[i][0] + costs[i + n][1]
        return total
```

</details>
