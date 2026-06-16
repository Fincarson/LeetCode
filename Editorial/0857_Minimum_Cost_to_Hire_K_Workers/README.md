# 857. Minimum Cost to Hire K Workers

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/)  
`Array` `Greedy` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 857 - Minimum Cost to Hire K Workers](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/)

## Problem

There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.

### Example 1

```text
Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
```

### Example 2

```text
Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
```

## Constraints

- n == quality.length == wage.length
- 1 <= k <= n <= 104
- 1 <= quality[i], wage[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Subsequence Score](https://leetcode.com/problems/maximum-subsequence-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 857. Minimum Cost to Hire K Workers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Priority Queue | C++, Java, Python3 |

## Approach: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        double totalCost = numeric_limits<double>::max();
        double currentTotalQuality = 0;
        // Store wage-to-quality ratio along with quality
        vector<pair<double, int>> wageToQualityRatio;

        // Calculate wage-to-quality ratio for each worker
        for (int i = 0; i < n; i++) {
            wageToQualityRatio.push_back(
                {static_cast<double>(wage[i]) / quality[i], quality[i]});
        }

        // Sort workers based on their wage-to-quality ratio
        sort(wageToQualityRatio.begin(), wageToQualityRatio.end());

        // Use a priority queue to keep track of the highest quality workers
        priority_queue<int> workers;

        // Iterate through workers
        for (int i = 0; i < n; i++) {
            workers.push(wageToQualityRatio[i].second);
            currentTotalQuality += wageToQualityRatio[i].second;

            // If we have more than k workers,
            // remove the one with the highest quality
            if (workers.size() > k) {
                currentTotalQuality -= workers.top();
                workers.pop();
            }

            // If we have exactly k workers,
            // calculate the total cost and update if it's the minimum
            if (workers.size() == k) {
                totalCost = min(totalCost, currentTotalQuality *
                                               wageToQualityRatio[i].first);
            }
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

    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double totalCost = Double.MAX_VALUE;
        double currentTotalQuality = 0;
        List<Pair<Double, Integer>> wageToQualityRatio = new ArrayList<>();

        // Calculate wage-to-quality ratio for each worker
        for (int i = 0; i < n; i++) {
            wageToQualityRatio.add(
                new Pair<>((double) wage[i] / quality[i], quality[i])
            );
        }

        // Sort workers based on their wage-to-quality ratio
        Collections.sort(
            wageToQualityRatio,
            Comparator.comparingDouble(Pair::getKey)
        );

        // Use a priority queue to keep track of the highest quality workers
        PriorityQueue<Integer> workers = new PriorityQueue<>(
            Collections.reverseOrder()
        );

        // Iterate through workers
        for (int i = 0; i < n; i++) {
            workers.add(wageToQualityRatio.get(i).getValue());
            currentTotalQuality += wageToQualityRatio.get(i).getValue();

            // If we have more than k workers,
            // remove the one with the highest quality
            if (workers.size() > k) {
                currentTotalQuality -= workers.poll();
            }

            // If we have exactly k workers,
            // calculate the total cost and update if it's the minimum
            if (workers.size() == k) {
                totalCost = Math.min(
                    totalCost,
                    currentTotalQuality * wageToQualityRatio.get(i).getKey()
                );
            }
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
    def mincostToHireWorkers(
        self, quality: List[int], wage: List[int], k: int
    ) -> float:
        n = len(quality)
        total_cost = float("inf")
        current_total_quality = 0
        wage_to_quality_ratio = []

        # Calculate wage-to-quality ratio for each worker
        for i in range(n):
            wage_to_quality_ratio.append((wage[i] / quality[i], quality[i]))

        # Sort workers based on their wage-to-quality ratio
        wage_to_quality_ratio.sort(key=lambda x: x[0])

        # Use a heap to keep track of the highest quality workers
        workers = []

        # Iterate through workers
        for i in range(n):
            heapq.heappush(workers, -wage_to_quality_ratio[i][1])
            current_total_quality += wage_to_quality_ratio[i][1]

            # If we have more than k workers,
            # remove the one with the highest quality
            if len(workers) > k:
                current_total_quality += heapq.heappop(workers)

            # If we have exactly k workers,
            # calculate the total cost and update if it's the minimum
            if len(workers) == k:
                total_cost = min(
                    total_cost,
                    current_total_quality * wage_to_quality_ratio[i][0],
                )

        return total_cost
```

</details>
