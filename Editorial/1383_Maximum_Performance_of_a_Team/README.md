# 1383. Maximum Performance of a Team

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximum-performance-of-a-team/)  
`Array` `Greedy` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1383 - Maximum Performance of a Team](https://leetcode.com/problems/maximum-performance-of-a-team/)

## Problem

You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

The performance of a team is the sum of its engineers' speeds multiplied by the minimum efficiency among its engineers.

Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

### Example 1

```text
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation:
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
```

### Example 2

```text
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
```

### Example 3

```text
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72
```

## Constraints

- 1 <= k <= n <= 105
- speed.length == n
- efficiency.length == n
- 1 <= speed[i] <= 105
- 1 <= efficiency[i] <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Fruits Harvested After at Most K Steps](https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1383. Maximum Performance of a Team

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy with Priority Queue | Java, Python3 |

## Approach: Greedy with Priority Queue

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int modulo = (int) Math.pow(10, 9) + 7;
        // build tuples of (efficiency, speed)
        List<Pair<Integer, Integer>> candidates = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            candidates.add(new Pair(efficiency[i], speed[i]));
        }
        // sort the members by their efficiencies
        Collections.sort(candidates, Comparator.comparing(o -> -o.getKey()));

        // create a heap to keep the top (k-1) speeds
        PriorityQueue<Integer> speedHeap = new PriorityQueue<>((o1, o2) -> o1 - o2);

        long speedSum = 0, perf = 0;
        for (Pair<Integer, Integer> p : candidates) {
            Integer currEfficiency = p.getKey();
            Integer currSpeed = p.getValue();
            // maintain a heap for the fastest (k-1) speeds
            if (speedHeap.size() > k - 1) {
                speedSum -= speedHeap.remove();
            }
            speedHeap.add(currSpeed);

            // calculate the maximum performance with
            // the current member as the least efficient one in the team
            speedSum += currSpeed;
            perf = Math.max(perf, speedSum * currEfficiency);
        }
        return (int) (perf % modulo);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        modulo = 10 ** 9 + 7

        # build tuples of (efficiency, speed)
        candidates = zip(efficiency, speed)
        # sort the candidates by their efficiencies
        candidates = sorted(candidates, key=lambda t:t[0], reverse=True)

        speed_heap = []
        speed_sum, perf = 0, 0
        for curr_efficiency, curr_speed in candidates:
            # maintain a heap for the fastest (k-1) speeds
            if len(speed_heap) > k-1:
                speed_sum -= heapq.heappop(speed_heap)
            heapq.heappush(speed_heap, curr_speed)

            # calculate the maximum performance with the current member as the least efficient one in the team
            speed_sum += curr_speed
            perf = max(perf, speed_sum * curr_efficiency)

        return perf % modulo
```

</details>
