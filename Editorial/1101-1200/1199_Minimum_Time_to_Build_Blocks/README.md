# 1199. Minimum Time to Build Blocks

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-time-to-build-blocks/)  
`Array` `Math` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1199 - Minimum Time to Build Blocks](https://leetcode.com/problems/minimum-time-to-build-blocks/)

## Problem

You are given a list of blocks, where blocks[i] = t means that the i-th block needs t units of time to be built. A block can only be built by exactly one worker.

A worker can either split into two workers (number of workers increases by one) or build a block then go home. Both decisions cost some time.

The time cost of spliting one worker into two workers is given as an integer split. Note that if two workers split at the same time, they split in parallel so the cost would be split.

Output the minimum time needed to build all blocks.

Initially, there is only one worker.

### Example 1

```text
Input: blocks = [1], split = 1
Output: 1
Explanation: We use 1 worker to build 1 block in 1 time unit.
```

### Example 2

```text
Input: blocks = [1,2], split = 5
Output: 7
Explanation: We split the worker into 2 workers in 5 time units then assign each of them to a block so the cost is 5 + max(1, 2) = 7.
```

### Example 3

```text
Input: blocks = [1,2,3], split = 1
Output: 4
Explanation: Split 1 worker into 2, then assign the first worker to the last block and split the second worker into 2.
Then, use the two unassigned workers to build the first two blocks.
The cost is 1 + max(3, 1 + max(1, 2)) = 4.
```

## Constraints

- 1 <= blocks.length <= 1000
- 1 <= blocks[i] <= 10^5
- 1 <= split <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Time Required to Eliminate Bacterial Strains](https://leetcode.com/problems/find-time-required-to-eliminate-bacterial-strains/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1199. Minimum Time to Build Blocks

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-down Dynamic Programming | C++, Java, Python3 |
| Bottom-up Dynamic Programming | C++, Java, Python3 |
| Space-Optimized Bottom-up Dynamic Programming | C++, Java, Python3 |
| Optimal Merge Pattern | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Top-down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {        
        // Sort the blocks in descending order
        sort(blocks.begin(), blocks.end(), greater<int>());
        
        // dp[i][j] represents the minimum time taken to build blocks[i~n-1] block using j workers
        vector<vector<int>> dp(blocks.size(), vector<int>(blocks.size() + 1, -1));
        
        // Call for the block from index 0 with 1 worker
        return solve(blocks, split, 0, 1, dp);
    }
    
    int solve(vector<int>& blocks, int split, int b, int w, vector<vector<int>>& dp) {        
        // Base cases
        if (b == blocks.size()) {
            return 0;
        }
        if (w == 0) {
            return INT_MAX;
        }
        if (w >= blocks.size() - b) {
            return blocks[b];
        }
        
        // If the sub-problem is already solved, return the result
        if (dp[b][w] != -1) {
            return dp[b][w];
        }
        
        // Two Choices
        int workHere = max(blocks[b], solve(blocks, split, b + 1, w - 1, dp));
        int splitHere = split + solve(blocks, split, b, min(2 * w, (int)blocks.size() - b), dp);
        
        // Store the result in the dp array
        dp[b][w] = min(workHere, splitHere);
        return dp[b][w];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minBuildTime(int[] blocks, int split) {       
        // Sort the blocks in descending order
        Arrays.sort(blocks);
        for (int i = 0; i < blocks.length / 2; i++) {
            int temp = blocks[i];
            blocks[i] = blocks[blocks.length - i - 1];
            blocks[blocks.length - i - 1] = temp;
        }
        
        // dp[i][j] represents the minimum time taken to build blocks[i~n-1] block using j workers
        int[][] dp = new int[blocks.length][blocks.length + 1];

        // Initialize the dp array with -1
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        // Call for the block from index 0 with 1 worker
        return solve(blocks, split, 0, 1, dp);
    }

    private int solve(int[] blocks, int split, int b, int w, int[][] dp) {
        // Base cases
        if (b == blocks.length) {
            return 0;
        }
        if (w == 0) {
            return Integer.MAX_VALUE;
        }
        if (w >= blocks.length - b) {
            return blocks[b];
        }

        // If the sub-problem is already solved, return the result
        if (dp[b][w] != -1) {
            return dp[b][w];
        }

        // Two Choices
        int workHere = Math.max(blocks[b], solve(blocks, split, b + 1, w - 1, dp));
        int splitHere = split + solve(blocks, split, b, Math.min(2 * w, blocks.length - b), dp);

        // Store the result in the dp array
        dp[b][w] = Math.min(workHere, splitHere);
        return dp[b][w];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBuildTime(self, blocks, split):
        n = len(blocks)

        # Sort the blocks in descending order
        blocks.sort(reverse=True)   

        # dp[i][j] represents the minimum time taken to 
        # build blocks[i~n-1] block using j workers
        dp = [[-1] * (n + 1) for _ in range(n)]

        def solve(b, w):
            # Base cases
            if b == n:
                return 0
            if w == 0:
                return float('inf')
            if w >= n - b:
                return blocks[b]

            # If the sub-problem is already solved, return the result
            if dp[b][w] != -1:
                return dp[b][w]

            # Two Choices
            work_here = max(blocks[b], solve(b + 1, w - 1))
            split_here = split + solve(b, min(2 * w, n - b))

            # Store the result in the dp array
            dp[b][w] = min(work_here, split_here)
            return dp[b][w]

        # For block from index 0, with 1 worker
        return solve(0, 1)
```

</details>

<br>

## Approach 2: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {        
        // Sort the blocks in descending order.
        int N = blocks.size();
        sort(blocks.begin(), blocks.end(), greater<int>());
        
        // Initialize the dp array.
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
        
        // Base case 1: If there are no workers, then we can't build any block.
        for (int b = 0; b < N; b++) {
            dp[b][0] = INT_MAX;
        }
        
        // Base case 2: If there are no blocks, then we don't need any time.
        for (int w = 0; w <= N; w++) {
            dp[N][w] = 0;
        }
        
        // Fill the dp array in a bottom-up fashion.
        for (int b = N - 1; b >= 0; b--) {
            for (int w = N; w >= 1; w--) {                
                // Base case 3: If we have more workers than blocks, 
                // Then we can build all the blocks.
                if (w >= N - b) {
                    dp[b][w] = blocks[b];
                    continue;
                }

                // Recurrence relation.
                int workHere = max(blocks[b], dp[b + 1][w - 1]);
                int splitHere = split + dp[b][min(2 * w, N - b)];
                
                // Store the result in the dp array
                dp[b][w] = min(workHere, splitHere);
            }
        }
        
        // For building all the blocks, with 
        // initially 1 worker.
        return dp[0][1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minBuildTime(int[] blocks, int split) {
        // Sort the blocks in descending order.
        int N = blocks.length;
        Arrays.sort(blocks);
        for (int i = 0; i < N / 2; i++) {
            int tmp = blocks[i];
            blocks[i] = blocks[N - i - 1];
            blocks[N - i - 1] = tmp;
        }
        
        // Initialize the dp array.
        int[][] dp = new int[N + 1][N + 1];
        
        // Base case 1: If there are no workers, then we can't build any block.
        for (int b = 0; b < N; b++) {
            dp[b][0] = Integer.MAX_VALUE;
        }
        
        // Base case 2: If there are no blocks, then we don't need any time.
        for (int w = 0; w <= N; w++) {
            dp[N][w] = 0;
        }
        
        // Fill the dp array in a bottom-up fashion.
        for (int b = N - 1; b >= 0; b--) {
            for (int w = N; w >= 1; w--) {                
                // Base case 3: If we have more workers than blocks, 
                //Then we can build all the blocks.
                if (w >= N - b) {
                    dp[b][w] = blocks[b];
                    continue;
                }

                // Recurrence relation.
                int workHere = Math.max(blocks[b], dp[b + 1][w - 1]);
                int splitHere = split + dp[b][Math.min(2 * w, N - b)];
                
                // Store the result in the dp array
                dp[b][w] = Math.min(workHere, splitHere);
            }
        }
        
        // For building all the blocks, with 
        // initially 1 worker.
        return dp[0][1];
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:        
        # Sort the blocks in descending order.
        N = len(blocks)
        blocks.sort(reverse=True)
        
        # Initialize the dp array.
        dp = [[0] * (N + 1) for _ in range(N + 1)]
        
        # Base case 1: If there are no workers, then we can't build any block.
        for b in range(N):
            dp[b][0] = float('inf')
        
        # Base case 2: If there are no blocks, then we don't need any time.
        for w in range(N + 1):
            dp[N][w] = 0
        
        # Fill the dp array in a bottom-up fashion.
        for b in range(N - 1, -1, -1):
            for w in range(N, 0, -1):                
                # Base case 3: If we have more workers than blocks, 
                # Then we can build all the blocks.
                if w >= N - b:
                    dp[b][w] = blocks[b]
                    continue

                # Recurrence relation.
                workHere = max(blocks[b], dp[b + 1][w - 1])
                split_here = split + dp[b][min(2 * w, N - b)]
                
                # Store the result in the dp array
                dp[b][w] = min(workHere, split_here)
        
        # For building all the blocks, with 
        # initially 1 worker.
        return dp[0][1]
```

</details>

<br>

## Approach 3: Space-Optimized Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {        
        // Sort the blocks in descending order.
        int N = blocks.size();
        sort(blocks.begin(), blocks.end(), greater<int>());
        
        // Initialize the dp array. When all N blocks
        // done, we need 0 time.
        vector<int> dp(N + 1, 0);

        // The case when we have no workers.
        dp[0] = INT_MAX;
        
        // Fill the dp array in a bottom-up fashion.
        for (int b = N - 1; b >= 0; b--) {
            for (int w = N; w > 0; w--) {                
                // If we have more workers than blocks, 
                // Then we can build all the blocks.
                if (w >= N - b) {
                    dp[w] = blocks[b];
                    continue;
                }

                // Recurrence relation.
                int workHere = max(blocks[b], dp[w - 1]);
                int splitHere = split + dp[min(2 * w, N - b)];
                
                // Store the result in the dp array
                dp[w] = min(workHere, splitHere);
            }
        }
        
        // For building all the blocks, with initially 1 worker.
        return dp[1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minBuildTime(int[] blocks, int split) {        
        // Sort the blocks in descending order.
        int N = blocks.length;
        Arrays.sort(blocks);
        for (int i = 0; i < N / 2; i++) {
            int temp = blocks[i];
            blocks[i] = blocks[N - i - 1];
            blocks[N - i - 1] = temp;
        }
        
        // Initialize the dp array. When all N blocks
        // done, we need 0 time.
        int[] dp = new int[N + 1];
        for (int w = 0; w <= N; w++) {
            dp[w] = 0;
        }

        // The case when we have no workers.
        dp[0] = Integer.MAX_VALUE;
        
        // Fill the dp array in a bottom-up fashion.
        for (int b = N - 1; b >= 0; b--) {
            for (int w = N; w > 0; w--) {                
                // If we have more workers than blocks, 
                // Then we can build all the blocks.
                if (w >= N - b) {
                    dp[w] = blocks[b];
                    continue;
                }

                // Recurrence relation.
                int workHere = Math.max(blocks[b], dp[w - 1]);
                int splitHere = split + dp[Math.min(2 * w, N - b)];
                
                // Store the result in the dp array
                dp[w] = Math.min(workHere, splitHere);
            }
        }
        
        // For building all the blocks, with initially 1 worker.
        return dp[1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:        
        # Sort the blocks in descending order.
        N = len(blocks)
        blocks.sort(reverse=True)
        
        # Initialize the dp array. When all N blocks
        # done, we need 0 time.
        dp = [0] * (N + 1)

        # The case when we have no workers.
        dp[0] = float('inf')
        
        # Fill the dp array in a bottom-up fashion.
        for b in range(N - 1, -1, -1):
            for w in range(N, 0, -1):                
                # If we have more workers than blocks, 
                # Then we can build all the blocks.
                if w >= N - b:
                    dp[w] = blocks[b]
                    continue

                # Recurrence relation.
                work_here = max(blocks[b], dp[w - 1])
                split_here = split + dp[min(2 * w, N - b)]
                
                # Store the result in the dp array
                dp[w] = min(work_here, split_here)
        
        # For building all the blocks, with 
        # initially 1 worker.
        return dp[1]
```

</details>

<br>

## Approach 4: Optimal Merge Pattern

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        // Prepare Heap of Building Time
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int block : blocks) {
            pq.push(block);
        }

        // Make sibling blocks until we are left with only one root node
        while (pq.size() > 1) {
            // Pop two minimum. The time of the abstracted sub-root will be 
            // split + max(x, y) which is split + y
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(split + y);
        }

        // Time of final root node
        return pq.top();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minBuildTime(int[] blocks, int split) {
        // Prepare Heap of Building Time
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int block : blocks) {
            pq.offer(block);
        }

        // Make sibling blocks until we are left with only one root node
        while (pq.size() > 1) {
            // Pop two minimum. The time of the abstracted sub-root will be 
            // split + max(x, y) which is split + y
            int x = pq.poll();
            int y = pq.poll();
            pq.offer(split + y);
        }

        // Time of final root node
        return pq.poll();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:        
        # Prepare Heap of Building Time
        heapq.heapify(blocks)
        
        # Make sibling blocks until we are left with only one root node
        while len(blocks) > 1:            
            # Pop two minimum. The time of the abstracted sub-root will be 
            # split + max(x, y) which is split + y
            x = heapq.heappop(blocks)
            y = heapq.heappop(blocks)
            heapq.heappush(blocks, split + y)
        
        # Time of final root node
        return heapq.heappop(blocks)
```

</details>

<br>

## Approach 5: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {        
        // Sort Array in Descending Order of the required time
        sort(blocks.begin(), blocks.end(), greater<int>());
        
        // If can be built in "limit" 
        auto possible = [&](int limit) {           
            // Build all blocks starting with one worker
            int worker = 1;
            
            for (int i = 0; i < blocks.size(); i++) {
                int time = blocks[i];                
                // If no worker or no sufficient time
                if (worker <= 0 || time > limit) {
                    return false;
                }
                
                // Keep splitting and producing workers as long as 
                // we are within the limit for this block
                while (time + split <= limit) {
                    limit -= split;
                    worker <<= 1;
                    
                    // Sufficient worker for remaining block
                    if (worker >= blocks.size() - i) {
                        return true;
                    }
                }
                
                // Build Block
                worker --;
            }
            
            // All blocks build
            return true;
        };
        
        // Binary Search Algorithm
        int left = blocks[0];
        int right = split * (ceil(log2(blocks.size()))) + blocks[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (possible(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return right;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minBuildTime(int[] blocks, int split) {        
        // Sort Array in Descending Order of the required time
        Arrays.sort(blocks);
        for (int i = 0; i < blocks.length / 2; i++) {
            int temp = blocks[i];
            blocks[i] = blocks[blocks.length - i - 1];
            blocks[blocks.length - i - 1] = temp;
        }
        
        // If can be built in "limit" 
        Predicate<Integer> possible = (limit) -> {           
            // Build all blocks starting with one worker
            int worker = 1;
            
            for (int i = 0; i < blocks.length; i++) {
                int time = blocks[i];                
                // If no worker or no sufficient time
                if (worker <= 0 || time > limit) {
                    return false;
                }
                
                // Keep splitting and producing workers as long as 
                // we are within the limit for this block
                while (time + split <= limit) {
                    limit -= split;
                    worker <<= 1;
                    
                    // Sufficient worker for remaining block
                    if (worker >= blocks.length - i) {
                        return true;
                    }
                }
                
                // Build Block
                worker --;
            }
            
            // All blocks build
            return true;
        };
        
        // Binary Search Algorithm
        int left = blocks[0];
        int right = split * (int) (Math.ceil(Math.log(blocks.length) / Math.log(2))) + blocks[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (possible.test(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return right;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:        
        # Sort Array in Descending Order of the required time
        blocks.sort(reverse = True)

        # If can be built in "limit"
        def possible(limit):           
            # Build all blocks starting with one worker
            worker = 1

            for index, time in enumerate(blocks):
                # If no worker or no sufficient time
                if worker <= 0 or time > limit:
                    return False
                
                # Keep splitting and producing workers as long as 
                # we are within the limit for this block
                while time + split <= limit:
                    limit -= split
                    worker *= 2

                    # Sufficient workers for the remaining block
                    if worker >= len(blocks) - index:
                        return True
                
                # Build Block
                worker -= 1

            # All blocks build
            return True

        # Binary Search Algorithm
        left = blocks[0]
        right = math.ceil(log2(len(blocks))) * split  + blocks[0]
        while left < right:
            mid = (left + right) // 2
            if possible(mid):
                right = mid
            else:
                left = mid + 1
        
        # Right is the minimum time when the task is possible
        return int(right)
```

</details>
