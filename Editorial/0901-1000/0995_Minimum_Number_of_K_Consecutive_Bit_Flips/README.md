# 995. Minimum Number of K Consecutive Bit Flips

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/)  
`Array` `Bit Manipulation` `Queue` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 995 - Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/)

## Problem

You are given a binary array nums and an integer k.

A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

A subarray is a contiguous part of an array.

### Example 1

```text
Input: nums = [0,1,0], k = 1
Output: 2
Explanation: Flip nums[0], then flip nums[2].
```

### Example 2

```text
Input: nums = [1,1,0], k = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].
```

### Example 3

```text
Input: nums = [0,0,0,1,0,1,1,0], k = 3
Output: 3
Explanation:
Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Bulb Switcher](https://leetcode.com/problems/bulb-switcher/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Time to Remove All Cars Containing Illegal Goods](https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Number of Distinct Binary Strings After Applying Operations](https://leetcode.com/problems/number-of-distinct-binary-strings-after-applying-operations/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Operations to Make Binary Array Elements Equal to One I](https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Smallest Number With All Set Bits](https://leetcode.com/problems/smallest-number-with-all-set-bits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 995. Minimum Number of K Consecutive Bit Flips

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using an Auxiliary Array | C++, Java, Python3 |
| Using a Deque | C++, Java, Python3 |
| In Constant Space | C++, Java, Python3 |

## Approach 1: Using an Auxiliary Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // Keeps track of flipped states
        vector<bool> flipped(nums.size(), false);
        // Tracks valid flips within the past window
        int validFlipsFromPastWindow = 0;
        // Counts total flips needed
        int flipCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                // Decrease count of valid flips from the past window if needed
                if (flipped[i - k]) {
                    validFlipsFromPastWindow--;
                }
            }

            // Check if current bit needs to be flipped
            if (validFlipsFromPastWindow % 2 == nums[i]) {
                // If flipping the window extends beyond the array length,
                // return -1
                if (i + k > nums.size()) {
                    return -1;
                }
                // Increment the count of valid flips and mark current as
                // flipped
                validFlipsFromPastWindow++;
                flipped[i] = true;
                flipCount++;
            }
        }

        return flipCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minKBitFlips(int[] nums, int k) {
        // Keeps track of flipped states
        boolean[] flipped = new boolean[nums.length];
        // Tracks valid flips within the past window
        int validFlipsFromPastWindow = 0;
        // Counts total flips needed
        int flipCount = 0;

        for (int i = 0; i < nums.length; i++) {
            if (i >= k) {
                // Decrease count of valid flips from the past window if needed
                if (flipped[i - k]) {
                    validFlipsFromPastWindow--;
                }
            }

            // Check if current bit needs to be flipped
            if (validFlipsFromPastWindow % 2 == nums[i]) {
                // If flipping the window extends beyond the array length, return -1
                if (i + k > nums.length) {
                    return -1;
                }
                // Increment the count of valid flips and mark current as flipped
                validFlipsFromPastWindow++;
                flipped[i] = true;
                flipCount++;
            }
        }

        return flipCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        # Keeps track of flipped states
        flipped = [False] * len(nums)

        # Tracks valid flips within the past window
        validFlipsFromPastWindow = 0

        # Counts total flips needed
        flipCount = 0

        for i in range(len(nums)):
            if i >= k:
                # Decrease count of valid flips from the past window if needed
                if flipped[i - k]:
                    validFlipsFromPastWindow -= 1

            # Check if current bit needs to be flipped
            if validFlipsFromPastWindow % 2 == nums[i]:
                # If flipping the window extends beyond the array length,
                # return -1
                if i + k > len(nums):
                    return -1

                # Increment the count of valid flips and
                # mark current as flipped
                validFlipsFromPastWindow += 1
                flipped[i] = True
                flipCount += 1

        return flipCount
```

</details>

<br>

## Approach 2: Using a Deque

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        // Queue to keep track of flips
        deque<int> flipQueue;
        // Current flip state
        int flipped = 0;
        // Total number of flips
        int result = 0;

        for (int i = 0; i < n; ++i) {
            // Remove the effect of the oldest flip if it's out of the current
            // window
            if (i >= k) {
                flipped ^= flipQueue.front();
                flipQueue.pop_front();
            }

            // If the current bit is 0 it needs to be flipped
            if (flipped == nums[i]) {
                // If we cannot flip a subarray starting at index i
                if (i + k > n) {
                    return -1;
                }
                // Add a flip at this position
                flipQueue.push_back(1);
                // Toggle the flipped state
                flipped ^= 1;
                // Increment the flip count
                result += 1;
            } else {
                flipQueue.push_back(0);
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length; // Length of the input array
        Deque<Integer> flipQueue = new LinkedList<>(); // Queue to keep track of flips
        int flipped = 0; // Current flip state
        int result = 0; // Total number of flips

        for (int i = 0; i < n; i++) {
            // Remove the effect of the oldest flip if it's out of the current window
            if (i >= k) {
                flipped ^= flipQueue.poll();
            }

            // If the current bit is 0 (i.e., it needs to be flipped)
            if (flipped == nums[i]) {
                // If we cannot flip a subarray starting at index i
                if (i + k > n) {
                    return -1;
                }
                // Add a flip at this position
                flipQueue.offer(1);
                flipped ^= 1; // Toggle the flipped state
                result += 1; // Increment the flip count
            } else {
                flipQueue.offer(0);
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)  # Length of the input list
        flip_queue = collections.deque()  # Queue to keep track of flips
        flipped = 0  # Current flip state
        result = 0  # Total number of flips

        for i, num in enumerate(nums):

            # Remove the effect of the oldest flip if it's out of the current window
            if i >= k:
                flipped ^= flip_queue[0]

            # If the current bit is 0 (i.e., it needs to be flipped)
            if flipped == nums[i]:

                # If we cannot flip a subarray starting at index i
                if i + k > n:
                    return -1

                # Add a flip at this position
                flip_queue.append(1)
                flipped ^= 1  # Toggle the flipped state
                result += 1  # Increment the flip count
            else:
                flip_queue.append(0)
            # Remove the oldest flip effect if the queue is longer than k

            if len(flip_queue) > k:
                flip_queue.popleft()
        return result
```

</details>

<br>

## Approach 3: In Constant Space

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // Tracks the current number of flips
        int currentFlips = 0;
        // Tracks the total number of flips
        int totalFlips = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // If the window slides out of the range and the leftmost element
            // is marked as flipped (2), decrement currentFlips
            if (i >= k && nums[i - k] == 2) {
                currentFlips--;
            }

            // Check if the current bit needs to be flipped
            if ((currentFlips % 2) == nums[i]) {
                // If flipping would exceed array bounds, return -1
                if (i + k > nums.size()) {
                    return -1;
                }
                // Mark the current bit as flipped
                nums[i] = 2;
                currentFlips++;
                totalFlips++;
            }
        }

        return totalFlips;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minKBitFlips(int[] nums, int k) {
        int currentFlips = 0; // Tracks the current number of flips
        int totalFlips = 0; // Tracks the total number of flips

        for (int i = 0; i < nums.length; ++i) {
            // If the window slides out of the range and the leftmost element is
            // marked as flipped (2), decrement currentFlips
            if (i >= k && nums[i - k] == 2) {
                currentFlips--;
            }

            // Check if the current bit needs to be flipped
            if ((currentFlips % 2) == nums[i]) {
                // If flipping would exceed array bounds, return -1
                if (i + k > nums.length) {
                    return -1;
                }
                // Mark the current bit as flipped
                nums[i] = 2;
                currentFlips++;
                totalFlips++;
            }
        }

        return totalFlips;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        current_flips = 0  # Tracks the current number of flips
        total_flips = 0  # Tracks the total number of flips

        for i in range(len(nums)):
            # If the window slides out of the range and the leftmost element is
            #  marked as flipped (2), decrement current_flips
            if i >= k and nums[i - k] == 2:
                current_flips -= 1

            # Check if the current bit needs to be flipped
            if (current_flips % 2) == nums[i]:
                # If flipping would exceed array bounds, return -1
                if i + k > len(nums):
                    return -1
                # Mark the current bit as flipped
                nums[i] = 2
                current_flips += 1
                total_flips += 1

        return total_flips
```

</details>
