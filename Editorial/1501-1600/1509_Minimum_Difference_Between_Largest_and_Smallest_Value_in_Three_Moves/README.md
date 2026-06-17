# 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1509 - Minimum Difference Between Largest and Smallest Value in Three Moves](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/)

## Problem

You are given an integer array nums.

In one move, you can choose one element of nums and change it to any value.

Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

### Example 1

```text
Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
```

### Example 2

```text
Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.
```

### Example 3

```text
Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.
```

## Constraints

- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimize the Maximum Difference of Pairs](https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort + Greedy Deletion | C++, Java, Python3 |
| Partial Sort + Greedy Deletion | C++, Java, Python3 |

## Approach 1: Sort + Greedy Deletion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int numsSize = nums.size();

        // If the array has 4 or fewer elements, return 0
        if (numsSize <= 4) return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        // Four scenarios to compute the minimum difference
        for (int left = 0, right = numsSize - 4; left < 4; left++, right++) {
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minDifference(int[] nums) {
        int numsSize = nums.length;

        // If the array has 4 or fewer elements, return 0
        if (numsSize <= 4) return 0;

        Arrays.sort(nums);

        int minDiff = Integer.MAX_VALUE;

        // Four scenarios to compute the minimum difference
        for (int left = 0, right = numsSize - 4; left < 4; left++, right++) {
            minDiff = Math.min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        nums_size = len(nums)

        # If the array has 4 or fewer elements, return 0
        if nums_size <= 4:
            return 0

        nums.sort()

        min_diff = float("inf")

        # Four scenarios to compute the minimum difference
        for left in range(4):
            right = nums_size - 4 + left
            min_diff = min(min_diff, nums[right] - nums[left])

        return min_diff
```

</details>

<br>

## Approach 2: Partial Sort + Greedy Deletion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int numsSize = nums.size(), minDiff = INT_MAX;
        if (numsSize <= 4) return 0;

        // Partially sort the first four elements
        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        // Find the 4th largest element
        nth_element(nums.begin() + 4, nums.begin() + (numsSize - 4),
                    nums.end());
        // Sort the last four elements
        sort(nums.begin() + (numsSize - 4), nums.end());

        // Four scenarios to compute the minimum difference
        for (int left = 0, right = numsSize - 4; left < 4; left++, right++) {
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int minDifference(int[] nums) {
        int numsSize = nums.length;
        if (numsSize <= 4) {
            return 0;
        }

        // Find the four smallest elements using a fixed-size max heap
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(
            Collections.reverseOrder()
        );
        for (int num : nums) {
            maxHeap.offer(num);
            if (maxHeap.size() > 4) {
                maxHeap.poll();
            }
        }
        List<Integer> smallestFour = new ArrayList<>(maxHeap);
        Collections.sort(smallestFour);

        // Find the four largest elements using a fixed-size min heap
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int num : nums) {
            minHeap.offer(num);
            if (minHeap.size() > 4) {
                minHeap.poll();
            }
        }
        List<Integer> largestFour = new ArrayList<>(minHeap);
        Collections.sort(largestFour);

        int minDiff = Integer.MAX_VALUE;
        // Four scenarios to compute the minimum difference
        for (int i = 0; i < 4; i++) {
            minDiff = Math.min(
                minDiff,
                largestFour.get(i) - smallestFour.get(i)
            );
        }

        return minDiff;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        nums_size = len(nums)
        if nums_size <= 4:
            return 0

        # Find the four smallest elements
        smallest_four = sorted(heapq.nsmallest(4, nums))

        # Find the four largest elements
        largest_four = sorted(heapq.nlargest(4, nums))

        min_diff = float("inf")
        # Four scenarios to compute the minimum difference
        for i in range(4):
            min_diff = min(min_diff, largest_four[i] - smallest_four[i])

        return min_diff
```

</details>
