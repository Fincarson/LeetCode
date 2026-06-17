# 774. Minimize Max Distance to Gas Station

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimize-max-distance-to-gas-station/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 774 - Minimize Max Distance to Gas Station](https://leetcode.com/problems/minimize-max-distance-to-gas-station/)

## Problem

You are given an integer array stations that represents the positions of the gas stations on the x-axis. You are also given an integer k.

You should add k new gas stations. You can add the stations anywhere on the x-axis, and not necessarily on an integer position.

Let penalty() be the maximum distance between adjacent gas stations after adding the k new stations.

Return the smallest possible value of penalty(). Answers within 10-6 of the actual answer will be accepted.

### Example 1

```text
Input: stations = [1,2,3,4,5,6,7,8,9,10], k = 9
Output: 0.50000
```

### Example 2

```text
Input: stations = [23,24,36,39,46,56,57,65,84,98], k = 1
Output: 14.00000
```

## Constraints

- 10 <= stations.length <= 2000
- 0 <= stations[i] <= 108
- stations is sorted in a strictly increasing order.
- 1 <= k <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 774. Minimize Max Distance to Gas Station

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Dynamic Programming [Memory Limit Exceeded] | Java, Python |
| Approach #2: Brute Force [Time Limit Exceeded] | Java, Python |
| Approach #3: Heap [Time Limit Exceeded] | Java, Python |
| Approach #4: Approach #3.5: Preprocessing + Heap + Greedy [Accepted] | C++, Java, Python3 |
| Approach #5: Binary Search [Accepted] | Java, Python |

## Approach #1: Dynamic Programming [Memory Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        int N = stations.length;
        double[] deltas = new double[N-1];
        for (int i = 0; i < N-1; ++i)
            deltas[i] = stations[i+1] - stations[i];

        double[][] dp = new double[N-1][K+1];
        //dp[i][j] = answer for deltas[:i+1] when adding j gas stations
        for (int i = 0; i <= K; ++i)
            dp[0][i] = deltas[0] / (i+1);

        for (int p = 1; p < N-1; ++p)
            for (int k = 0; k <= K; ++k) {
                double bns = 999999999;
                for (int x = 0; x <= k; ++x)
                    bns = Math.min(bns, Math.max(deltas[p] / (x+1), dp[p-1][k-x]));
                dp[p][k] = bns;
            }

        return dp[N-2][K];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minmaxGasDist(self, stations, K):
        N = len(stations)
        deltas = [stations[i+1] - stations[i] for i in xrange(N-1)]
        dp = [[0.0] * (K+1) for _ in xrange(N-1)]
        #dp[i][j] = answer for deltas[:i+1] when adding j gas stations
        for i in xrange(K+1):
            dp[0][i] = deltas[0] / float(i + 1)

        for p in xrange(1, N-1):
            for k in xrange(K+1):
                dp[p][k] = min(max(deltas[p] / float(x+1), dp[p-1][k-x])
                               for x in xrange(k+1))

        return dp[-1][K]
```

</details>

<br>

## Approach #2: Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        int N = stations.length;
        double[] deltas = new double[N-1];
        for (int i = 0; i < N-1; ++i)
            deltas[i] = stations[i+1] - stations[i];

        int[] count = new int[N-1];
        Arrays.fill(count, 1);

        for (int k = 0; k < K; ++k) {
            // Find interval with largest part
            int best = 0;
            for (int i = 0; i < N-1; ++i)
                if (deltas[i] / count[i] > deltas[best] / count[best])
                    best = i;

            // Add gas station to best interval
            count[best]++;
        }

        double ans = 0;
        for (int i = 0; i < N-1; ++i)
            ans = Math.max(ans, deltas[i] / count[i]);

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minmaxGasDist(self, stations, K):
        N = len(stations)
        deltas = [float(stations[i+1] - stations[i]) for i in xrange(N-1)]
        count = [1] * (N - 1)

        for _ in xrange(K):
            #Find interval with largest part
            best = 0
            for i, x in enumerate(deltas):
                if x / count[i] > deltas[best] / count[best]:
                    best = i

            #Add gas station to best interval
            count[best] += 1

        return max(x / count[i] for i, x in enumerate(deltas))
```

</details>

<br>

## Approach #3: Heap [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        int N = stations.length;
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) ->
            (double)b[0]/b[1] < (double)a[0]/a[1] ? -1 : 1);
        for (int i = 0; i < N-1; ++i)
            pq.add(new int[]{stations[i+1] - stations[i], 1});

        for (int k = 0; k < K; ++k) {
            int[] node = pq.poll();
            node[1]++;
            pq.add(node);
        }

        int[] node = pq.poll();
        return (double)node[0] / node[1];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minmaxGasDist(self, stations, K):
        pq = [] #(-part_length, original_length, num_parts)
        for i in xrange(len(stations) - 1):
            x, y = stations[i], stations[i+1]
            pq.append((x-y, y-x, 1))
        heapq.heapify(pq)

        for _ in xrange(K):
            negnext, orig, parts = heapq.heappop(pq)
            parts += 1
            heapq.heappush(pq, (-(orig / float(parts)), orig, parts))

        return -pq[0][0]
```

</details>

<br>

## Approach #4: Approach #3.5: Preprocessing + Heap + Greedy [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int N = stations.size();

        // Step 1: Compute an upper bound for distance
        double distUpper =
            (stations.back() - stations.front()) / (double)(K + 1);

        // Step 2: Conservative allocation of stations per interval
        priority_queue<tuple<double, double, int>>
            pq; // (distance, interval_length, ki)
        for (int i = 0; i < N - 1; ++i) {
            double interval = stations[i + 1] - stations[i];
            int ki = floor(interval / distUpper);
            double actualDist = interval / (ki + 1);
            K -= ki;
            pq.push({actualDist, interval, ki});
        }

        // Step 3: Greedy allocation of remaining stations
        while (K-- > 0) {
            auto [dist, interval, ki] = pq.top();
            pq.pop();
            ki += 1;
            double newDist = interval / (ki + 1);
            pq.push({newDist, interval, ki});
        }

        // Step 4: Return the largest remaining distance
        return get<0>(pq.top());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.*;
import static java.lang.Math.*;

class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        int N = stations.length;
        double distUpper = (stations[N - 1] - stations[0]) / (double)(K + 1);
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));

        for (int i = 0; i < N - 1; i++) {
            double interval = stations[i + 1] - stations[i];
            int ki = (int) Math.floor(interval / distUpper);
            double actualDist = interval / (ki + 1);
            K -= ki;
            pq.add(new double[]{actualDist, interval, ki});
        }

        while (K-- > 0) {
            double[] top = pq.poll();
            double dist = top[0];
            double interval = top[1];
            int ki = (int) top[2] + 1;
            pq.add(new double[]{interval / (ki + 1), interval, ki});
        }

        return pq.peek()[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from heapq import heappush, heappop
from math import floor

class Solution:
    def minmaxGasDist(self, stations, k):
        n = len(stations)

        # Step 1: Compute an upper bound for distance
        dist_upper = (stations[-1] - stations[0]) / (k + 1)

        # Step 2: Conservative allocation
        heap = []  # (-distance, interval_length, current_station_count)
        for i in range(n - 1):
            interval = stations[i + 1] - stations[i]
            ki = floor(interval / dist_upper)
            actual_dist = interval / (ki + 1)
            k -= ki
            heappush(heap, (-actual_dist, interval, ki))

        # Step 3: Allocate remaining stations greedily
        for _ in range(k):
            neg_dist, interval, ki = heappop(heap)
            ki += 1
            new_dist = interval / (ki + 1)
            heappush(heap, (-new_dist, interval, ki))

        # Step 4: The largest remaining interval
        return -heap[0][0]
```

</details>

<br>

## Approach #5: Binary Search [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        double lo = 0, hi = 1e8;
        while (hi - lo > 1e-6) {
            double mi = (lo + hi) / 2.0;
            if (possible(mi, stations, K))
                hi = mi;
            else
                lo = mi;
        }
        return lo;
    }

    public boolean possible(double D, int[] stations, int K) {
        int used = 0;
        for (int i = 0; i < stations.length - 1; ++i)
            used += (int) ((stations[i+1] - stations[i]) / D);
        return used <= K;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minmaxGasDist(self, stations, K):
        def possible(D):
            return sum(int((stations[i+1] - stations[i]) / D)
                       for i in xrange(len(stations) - 1)) <= K

        lo, hi = 0, 10**8
        while hi - lo > 1e-6:
            mi = (lo + hi) / 2.0
            if possible(mi):
                hi = mi
            else:
                lo = mi
        return lo
```

</details>
