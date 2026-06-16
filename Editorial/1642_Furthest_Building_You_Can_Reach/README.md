# 1642. Furthest Building You Can Reach

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/furthest-building-you-can-reach/)  
`Array` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1642 - Furthest Building You Can Reach](https://leetcode.com/problems/furthest-building-you-can-reach/)

## Problem

You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

- If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
- If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.

Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

### Example 1

```text
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
```

### Example 2

```text
Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7
```

### Example 3

```text
Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3
```

## Constraints

- 1 <= heights.length <= 105
- 1 <= heights[i] <= 106
- 0 <= bricks <= 109
- 0 <= ladders <= heights.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Make the Prefix Sum Non-negative](https://leetcode.com/problems/make-the-prefix-sum-non-negative/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Building Where Alice and Bob Can Meet](https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1642. Furthest Building You Can Reach

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Min-Heap | Java, Python3 |
| Max-Heap | Java |
| Binary Search for Final Reachable Building | Java, Python3 |
| Improved Binary Search for Final Reachable Building | Java |
| Binary Search on Threshold (Advanced) | Java, Python3 |

## Approach 1: Min-Heap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        // Create a priority queue with a comparator that makes it behave as a min-heap.
        Queue<Integer> ladderAllocations = new PriorityQueue<>((a, b) -> a - b);
        for (int i = 0; i < heights.length - 1; i++) {
            int climb = heights[i + 1] - heights[i];
            // If this is actually a "jump down", skip it.
            if (climb <= 0) {
                continue;
            }
            // Otherwise, allocate a ladder for this climb.
            ladderAllocations.add(climb);
            // If we haven't gone over the number of ladders, nothing else to do.
            if (ladderAllocations.size() <= ladders) {
                continue;
            }
            // Otherwise, we will need to take a climb out of ladder_allocations
            bricks -= ladderAllocations.remove();
            // If this caused bricks to go negative, we can't get to i + 1
            if (bricks < 0) {
                return i;
            }
        }
        // If we got to here, this means we had enough materials to cover every climb.
        return heights.length - 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        ladder_allocations = [] # We'll use heapq to treat this as a min-heap.
        for i in range(len(heights) - 1):
            climb = heights[i + 1] - heights[i]
            # If this is actually a "jump down", skip it.
            if climb <= 0:
                continue
            # Otherwise, allocate a ladder for this climb.
            heapq.heappush(ladder_allocations, climb)
            # If we haven't gone over the number of ladders, nothing else to do.
            if len(ladder_allocations) <= ladders:
                continue
            # Otherwise, we will need to take a climb out of ladder_allocations
            bricks -= heapq.heappop(ladder_allocations)
            # If this caused bricks to go negative, we can't get to i + 1
            if bricks < 0:
                return i
        # If we got to here, this means we had enough to cover every climb.
        return len(heights) - 1
```

</details>

<br>

## Approach 2: Max-Heap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        // Create a priority queue with a comparator that makes it behave as a max-heap.
        Queue<Integer> brickAllocations = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < heights.length - 1; i++) {
            int climb = heights[i + 1] - heights[i];
            // If this is actually a "jump down", skip it.
            if (climb <= 0) {
                continue;
            }            
            // Otherwise, allocate a ladder for this climb.
            brickAllocations.add(climb);
            bricks -= climb;
            // If we've used all the bricks, and have no ladders remaining, then 
            // we can't go any further.
            if (bricks < 0 && ladders == 0) {
                return i;
            }
            // Otherwise, if we've run out of bricks, we should replace the largest
            // brick allocation with a ladder.
            if (bricks < 0) {
                bricks += brickAllocations.remove();
                ladders--;
            }
        }
        // If we got to here, this means we had enough materials to cover every climb.
        return heights.length - 1;
    }
}
```

</details>

<br>

## Approach 3: Binary Search for Final Reachable Building

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        // Do a binary search on the heights array to find the final reachable building.
        int lo = 0;
        int hi = heights.length - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (isReachable(mid, heights, bricks, ladders)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return hi; // Note that return lo would be equivalent.
    }
    
    private boolean isReachable(int buildingIndex, int[] heights, int bricks, int ladders) {
        // Make a list of all the climbs we need to do to reach buildingIndex.
        List<Integer> climbs = new ArrayList<>();
        for (int i = 0; i < buildingIndex; i++) {
            int h1 = heights[i];
            int h2 = heights[i + 1];
            if (h2 <= h1) {
                continue;
            }
            climbs.add(h2 - h1);
        }
        Collections.sort(climbs);
        
        // And now determine whether or not all of these climbs can be covered with the
        // given bricks and ladders.
        for (int climb : climbs) {
            // If there are bricks left, use those.
            if (climb <= bricks) {
                bricks -= climb;
            // Otherwise, you'll have to use a ladder.
            } else if (ladders >= 1) {
                ladders -= 1;
            // And if there are no ladders either, we can't reach buildingIndex.
            } else {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        
        # Helper function to check whether or not the specified building is reachable
        # from the first building with the bricks and ladders we have.
        def is_reachable(building_index):
            # Make a sorted list of all the climbs needed to get to the given building.
            climbs = []
            for h1, h2 in zip(heights[:building_index], heights[1:building_index + 1]):
                if h2 - h1 > 0:
                    climbs.append(h2 - h1)
            climbs.sort()
            # Check whether or not we have enough bricks and ladders to cover all
            # of these climbs. Bricks will be used before ladders.
            bricks_remaining = bricks
            ladders_remaining = ladders
            for climb in climbs:
                # If there are enough bricks left, use those.
                if climb <= bricks_remaining:
                    bricks_remaining -= climb
                # Otherwise, you'll have to use a ladder.
                elif ladders_remaining >= 1:
                    ladders_remaining -= 1
                # And if there are no ladders either, we can't reach buildingIndex.
                else:
                    return False
            return True
         
        # Do the binary search to find the final reachable building.
        lo = 0
        hi = len(heights) - 1
        while lo < hi:
            mid = lo + (hi - lo + 1) // 2
            if is_reachable(mid):
                lo = mid
            else:
                hi = mid - 1
        return hi # Note that return lo would be equivalent.
```

</details>

<br>

## Approach 4: Improved Binary Search for Final Reachable Building

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        // Make a sorted list of all the climbs.
        List<int[]> sortedClimbs = new ArrayList<>();
        for (int i = 0; i < heights.length - 1; i++) {
            int climb = heights[i + 1] - heights[i];
            if (climb <= 0) {
                continue;
            }
            sortedClimbs.add(new int[]{climb, i + 1});
        }
        Collections.sort(sortedClimbs, (a,b) -> a[0] - b[0]);
        
        // Now do the binary search, same as before.
        int lo = 0;
        int hi = heights.length - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (isReachable(mid, sortedClimbs, bricks, ladders)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return hi; // Note that return lo would be equivalent.
    }
    
    private boolean isReachable(int buildingIndex, List<int[]> climbs, int bricks, int ladders) {
        for (int[] climbEntry : climbs) {
            // Extract the information for this climb
            int climb = climbEntry[0];
            int index = climbEntry[1];
            // Check if this climb is within the range.
            if (index > buildingIndex) {
                continue;
            }
            // Allocate bricks if enough remain; otherwise, allocate a ladder if
            // at least one remains.
            if (climb <= bricks) {
                bricks -= climb;
            } else if (ladders >= 1) {
                ladders -= 1;
            } else {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<br>

## Approach 5: Binary Search on Threshold (Advanced)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        int lo = Integer.MAX_VALUE;
        int hi = Integer.MIN_VALUE;
        for (int i = 0; i < heights.length - 1; i++) {
            int climb = heights[i + 1] - heights[i];
            if (climb <= 0) {
                continue;
            }
            lo = Math.min(lo, climb);
            hi = Math.max(hi, climb);   
        }
        if (lo == Integer.MAX_VALUE) {
            return heights.length - 1;
        }
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int[] result = solveWithGivenThreshold(heights, bricks, ladders, mid);
            int indexReached = result[0];
            int laddersRemaining = result[1];
            int bricksRemaining = result[2];
            if (indexReached == heights.length - 1) {
                return heights.length - 1;
            }
            if (laddersRemaining > 0) {
                hi = mid - 1;
                continue;
            }
            // Otherwise, check whether this is the "too low" or "just right" case.
            int nextClimb = heights[indexReached + 1] - heights[indexReached];
            if (nextClimb > bricksRemaining && mid > bricksRemaining) {
                return indexReached;
            } else {
                lo = mid + 1;
            }
        }
        return -1; // It always returns before here. But gotta keep Java happy.
    }
    
    public int[] solveWithGivenThreshold(int[] heights, int bricks, int ladders, int K) {
        int laddersUsedOnThreshold = 0;
        for (int i = 0; i < heights.length - 1; i++) {
            int climb = heights[i + 1] - heights[i];
            if (climb <= 0) {
                continue;
            }
            // Make resource allocations
            if (climb == K) {
                laddersUsedOnThreshold++;
                ladders--;
            } else if (climb > K) {
                ladders--;
            } else {
                bricks -= climb;
            }
            // Handle negative resources
            if (ladders < 0) {
                if (laddersUsedOnThreshold >= 1) {
                    laddersUsedOnThreshold--;
                    ladders++;
                    bricks -= K;
                } else {
                    return new int[]{i, ladders, bricks};
                }
            }
            if (bricks < 0) {
                return new int[]{i, ladders, bricks};
            }
        }
        return new int[]{heights.length - 1, ladders, bricks};
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        
        def solveWithGivenThreshold(K):
            
            ladders_remaining = ladders
            bricks_remaining = bricks
            ladders_used_on_threshold = 0
            
            for i in range(len(heights) - 1):
                climb = heights[i + 1] - heights[i]
                if climb <= 0:
                    continue
                    
                # Make resource allocations
                if climb == K:
                    ladders_used_on_threshold += 1
                    ladders_remaining -= 1
                elif climb > K:
                    ladders_remaining -= 1
                else:
                    bricks_remaining -= climb
                    
                # Handle negative resources.
                if ladders_remaining < 0:
                    if ladders_used_on_threshold:
                        ladders_used_on_threshold -= 1
                        ladders_remaining += 1
                        bricks_remaining -= K
                    else:
                        return [i, ladders_remaining, bricks_remaining]
                
                if bricks_remaining < 0:
                    return [i, ladders_remaining, bricks_remaining]
            
            return [len(heights) - 1, ladders_remaining, bricks_remaining]
                
        
        # Find the minimum climb and maximum climbs
        lo = math.inf
        hi = -math.inf
        for i in range(len(heights) - 1):
            climb = heights[i + 1] - heights[i]
            if climb <= 0:
                continue
            lo = min(lo, climb)
            hi = max(hi, climb)
        
        if lo == math.inf: # Was there no climbs?
            return len(heights) - 1
        
        # Carry out the binary search.
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            index_reached, ladders_remaining, bricks_remaining = solveWithGivenThreshold(mid)
            # Did we get all the way?
            if index_reached == len(heights) - 1:
                return len(heights) - 1
            # Otherwise, if we have a ladder remaining, it has to be too high.
            if ladders_remaining > 0:
                hi = mid - 1
                continue
                
            # Otherwise, check for the other optimal conditions.
            next_climb = heights[index_reached + 1] - heights[index_reached]
            if bricks_remaining < next_climb and bricks_remaining < mid:
                return index_reached
            
            # Otherwise, it must have been too low.
            lo = mid + 1
```

</details>
