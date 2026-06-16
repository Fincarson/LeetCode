# 2594. Minimum Time to Repair Cars

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-time-to-repair-cars/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 2594 - Minimum Time to Repair Cars](https://leetcode.com/problems/minimum-time-to-repair-cars/)

## Problem

You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.

### Example 1

```text
Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation:
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
```

### Example 2

```text
Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation:
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
```

## Constraints

- 1 <= ranks.length <= 105
- 1 <= ranks[i] <= 100
- 1 <= cars <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Transformed Array](https://leetcode.com/problems/sort-transformed-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2594. Minimum Time to Repair Cars

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search on Time | C++, Java, Python3 |
| Space Optimized Binary Search | C++, Java, Python3 |
| Using Heap | C++, Java, Python3 |

## Approach 1: Binary Search on Time

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long repairCars(vector<int>& ranks, int cars) {
        int minRank = ranks[0], maxRank = ranks[0];

        // Find min and max rank dynamically
        for (int rank : ranks) {
            minRank = min(minRank, rank);
            maxRank = max(maxRank, rank);
        }

        // Frequency array to count mechanics with each rank
        vector<int> freq(maxRank + 1);
        for (int rank : ranks) {
            minRank = min(minRank, rank);
            freq[rank]++;
        }

        // Minimum possible time, Maximum possible time
        long long low = 1, high = 1LL * minRank * cars * cars;

        // Perform binary search to find the minimum time required
        while (low < high) {
            long long mid = (low + high) / 2;
            long long carsRepaired = 0;

            // Calculate the total number of cars that can be repaired in 'mid'
            // time
            for (int rank = 1; rank <= maxRank; rank++) {
                carsRepaired +=
                    freq[rank] * (long long)sqrt(mid / (long long)rank);
            }

            // Adjust the search boundaries based on the number of cars repaired
            if (carsRepaired >= cars) {
                high = mid;  // Try to find a smaller time
            } else {
                low = mid + 1;  // Need more time
            }
        }

        return low;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long repairCars(int[] ranks, int cars) {
        int minRank = ranks[0], maxRank = ranks[0];

        // Find min and max rank dynamically
        for (int rank : ranks) {
            minRank = Math.min(minRank, rank);
            maxRank = Math.max(maxRank, rank);
        }
        // Frequency array to count mechanics with each rank
        int[] freq = new int[maxRank + 1];
        for (int rank : ranks) {
            minRank = Math.min(minRank, rank);
            freq[rank]++;
        }

        // Minimum possible time, Maximum possible time
        long low = 1, high = 1L * minRank * cars * cars;

        // Perform binary search to find the minimum time required
        while (low < high) {
            long mid = (low + high) / 2;
            long carsRepaired = 0;

            // Calculate the total number of cars that can be repaired in 'mid' time
            for (int rank = 1; rank <= maxRank; rank++) {
                carsRepaired +=
                    freq[rank] * (long) Math.sqrt(mid / (long) rank);
            }

            // Adjust the search boundaries based on the number of cars repaired
            if (carsRepaired >= cars) {
                high = mid; // Try to find a smaller time
            } else {
                low = mid + 1; // Need more time
            }
        }

        return low;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:

        min_rank, max_rank = ranks[0], ranks[0]

        # Find min and max rank dynamically
        for rank in ranks:
            min_rank = min(min_rank, rank)
            max_rank = max(max_rank, rank)

        # Frequency list to count mechanics with each rank
        freq = [0] * (max_rank + 1)
        for rank in ranks:
            min_rank = min(min_rank, rank)
            freq[rank] += 1

        # Minimum possible time, Maximum possible time
        low = 1
        high = min_rank * cars * cars

        # Perform binary search to find the minimum time required
        while low < high:
            mid = (low + high) // 2
            cars_repaired = 0

            # Calculate the total number of cars that can be repaired in 'mid' time
            for rank in range(1, max_rank + 1):
                cars_repaired += freq[rank] * int(math.sqrt(mid // rank))

            # Adjust the search boundaries based on the number of cars repaired
            if cars_repaired >= cars:
                high = mid  # Try to find a smaller time
            else:
                low = mid + 1  # Need more time

        return low
```

</details>

<br>

## Approach 2: Space Optimized Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // The minimum possible time is 1,
        // and the maximum possible time is when the slowest mechanic (highest
        // rank) repairs all cars.
        long long low = 1, high = 1LL * cars * cars * ranks[0];

        // Perform binary search to find the minimum time required.
        while (low < high) {
            long long mid = low + (high - low) / 2, carsRepaired = 0;

            // Calculate the number of cars that can be repaired in 'mid' time
            // by all mechanics.
            for (auto rank : ranks) carsRepaired += sqrt(1.0 * mid / rank);

            // If the total cars repaired is less than required, increase the
            // time.
            if (carsRepaired < cars)
                low = mid + 1;
            else
                high = mid;  // Otherwise, try a smaller time.
        }

        return low;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long repairCars(int[] ranks, int cars) {
        // The minimum possible time is 1,
        // and the maximum possible time is when the slowest mechanic (highest rank) repairs all cars.
        long low = 1, high = 1L * ranks[0] * cars * cars;

        // Perform binary search to find the minimum time required.
        while (low < high) {
            long mid = (low + high) / 2, carsRepaired = 0;

            // Calculate the number of cars that can be repaired in 'mid' time by all mechanics.
            for (int rank : ranks) carsRepaired += (long) (Math.sqrt(
                    (1.0 * mid) / rank
                ));

            // If the total cars repaired is less than required, increase the time.
            if (carsRepaired < cars) low = mid + 1;
            else high = mid; // Otherwise, try a smaller time.
        }

        return low;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        # The minimum possible time is 1,
        # and the maximum possible time is when the slowest mechanic (highest rank) repairs all cars.
        low, high = 1, cars * cars * ranks[0]

        # Perform binary search to find the minimum time required.
        while low < high:
            mid = (low + high) // 2
            cars_repaired = sum(int((mid / rank) ** 0.5) for rank in ranks)

            # If the total cars repaired is less than required, increase the time.
            if cars_repaired < cars:
                low = mid + 1
            else:
                high = mid  # Otherwise, try a smaller time.

        return low
```

</details>

<br>

## Approach 3: Using Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long repairCars(vector<int>& ranks, int cars) {
        // Count the frequency of each rank
        unordered_map<int, int> count;
        for (int rank : ranks) {
            count[rank] += 1;
        }

        // Create a Min-heap (priority_queue in C++ std library) storing [time,
        // rank, n, count]
        // - time: time for the next repair
        // - rank: mechanic's rank
        // - n: cars repaired by this mechanic
        // - count: number of mechanics with this rank
        // Initial time = rank (as rank * 1^2 = rank)
        auto comp = [](vector<long>& a, vector<long>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<long>, vector<vector<long>>, decltype(comp)>
            minHeap(comp);

        // Add initial entries to the heap
        for (auto it : count) {
            int rank = it.first;
            // Elements: [time, rank, cars_repaired, mechanic_count]
            minHeap.push({rank, rank, 1, it.second});
        }

        long time = 0;
        // Process until all cars are repaired
        while (cars > 0) {
            // Pop the mechanic with the smallest current repair time
            vector<long> current = minHeap.top();
            minHeap.pop();
            time = current[0];
            int rank = current[1];
            long n = current[2];
            int mechCount = current[3];

            // Deduct the number of cars repaired by this mechanic group
            cars -= mechCount;

            // Increment the number of cars repaired by this mechanic
            n += 1;

            // Push the updated repair time back into the heap
            // The new repair time is rank * n^2 (time increases quadratically
            // with n)
            minHeap.push({rank * n * n, rank, n, mechCount});
        }

        return time;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long repairCars(int[] ranks, int cars) {
        // Count the frequency of each rank
        Map<Integer, Integer> count = new HashMap<>();
        for (int rank : ranks) {
            count.put(rank, count.getOrDefault(rank, 0) + 1);
        }

        // Create a Min-heap storing [time, rank, n, count]
        // - time: time for the next repair
        // - rank: mechanic's rank
        // - n: cars repaired by this mechanic
        // - count: number of mechanics with this rank
        // Initial time = rank (as rank * 1^2 = rank)
        PriorityQueue<long[]> minHeap = new PriorityQueue<>((a, b) ->
            Long.compare(a[0], b[0])
        );

        // Add initial entries to the heap
        for (int rank : count.keySet()) {
            // Elements: [time, rank, cars_repaired, mechanic_count]
            minHeap.offer(new long[] { rank, rank, 1, count.get(rank) });
        }

        long time = 0;
        // Process until all cars are repaired
        while (cars > 0) {
            // Pop the mechanic with the smallest current repair time
            long[] current = minHeap.poll();
            time = current[0];
            int rank = (int) current[1];
            long n = current[2];
            int mechCount = (int) current[3];

            // Deduct the number of cars repaired by this mechanic group
            cars -= mechCount;

            // Increment the number of cars repaired by this mechanic
            n += 1;

            // Push the updated repair time back into the heap
            // The new repair time is rank * n^2 (time increases quadratically with n)
            minHeap.offer(new long[] { rank * n * n, rank, n, mechCount });
        }

        return time;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def repairCars(self, rank: List[int], cars: int) -> int:
        # Count the frequency of each rank using a Counter
        count = Counter(rank)

        # Create a Min-heap storing [time, rank, n, count]:
        # - time: time for the next repair
        # - rank: mechanic's rank
        # - n: cars repaired by this mechanic
        # - count: number of mechanics with this rank
        # Initial time = rank (as rank * 1^2 = rank)
        min_heap = [[rank, rank, 1, count[rank]] for rank in count]
        heapify(min_heap)

        # Process until all cars are repaired
        while cars > 0:
            # Pop the mechanic with the smallest current repair time
            time, rank, n, count = heappop(min_heap)

            # Deduct the number of cars repaired by this mechanic group
            cars -= count

            # Increment the number of cars repaired by this mechanic
            n += 1

            # Push the updated repair time back into the heap
            # The new repair time is rank * n^2 (since time increases quadratically with n)
            heappush(min_heap, [rank * n * n, rank, n, count])

        return time
```

</details>
