# 3191. Minimum Operations to Make Binary Array Elements Equal to One I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/)  
`Array` `Bit Manipulation` `Queue` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 3191 - Minimum Operations to Make Binary Array Elements Equal to One I](https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/)

## Problem

You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

- Choose any 3 consecutive elements from the array and flip all of them.

Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

### Example 1

### Example 2

## Constraints

- 3 <= nums.length <= 105
- 0 <= nums[i] <= 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3191. Minimum Operations to Make Binary Array Elements Equal to One I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Deque | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |
| Sliding Window Using Bit Manipulation | C++, Java, Python3 |

## Approach 1: Using Deque

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        deque<int> flipQueue;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (!flipQueue.empty() && i > flipQueue.front() + 2) {
                flipQueue.pop_front();
            }

            if ((nums[i] + flipQueue.size()) % 2 == 0) {
                if (i + 2 >= nums.size()) {
                    return -1;
                }
                count++;
                flipQueue.push_back(i);
            }
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minOperations(int[] nums) {
        Deque<Integer> flipQueue = new ArrayDeque<>();
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
            while (!flipQueue.isEmpty() && i > flipQueue.peekFirst() + 2) {
                flipQueue.pollFirst();
            }

            if ((nums[i] + flipQueue.size()) % 2 == 0) {
                if (i + 2 >= nums.length) {
                    return -1;
                }
                count++;
                flipQueue.offerLast(i);
            }
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        flip_queue = deque()  # Stores indices of flip operations
        count = 0  # Number of operations performed

        for i in range(len(nums)):
            # Remove expired flips (older than 3 indices)
            while flip_queue and i > flip_queue[0] + 2:
                flip_queue.popleft()

            # If the current element needs flipping
            if (nums[i] + len(flip_queue)) % 2 == 0:
                # Cannot flip a full triplet
                if i + 2 >= len(nums):
                    return -1
                count += 1
                flip_queue.append(i)

        return count
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 2; i < nums.size(); i++) {
            // only looking forward to the last element
            if (nums[i - 2] == 0) {
                count++;
                // flip i-2 and i-1 and i
                nums[i - 2] ^= 1;
                nums[i - 1] ^= 1;
                nums[i] ^= 1;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == nums.size()) return count;
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minOperations(int[] nums) {
        int count = 0;
        for (int i = 2; i < nums.length; i++) {
            if (nums[i - 2] == 0) {
                count++;
                nums[i - 2] = nums[i - 2] ^ 1;
                nums[i - 1] = nums[i - 1] ^ 1;
                nums[i] = nums[i] ^ 1;
            }
        }
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum == nums.length) return count;
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = 0
        for i in range(2, len(nums)):

            # only looking forward to the last element
            if nums[i - 2] == 0:
                count += 1
                # flip i-2 and i-1 and i
                nums[i - 2] = nums[i - 2] ^ 1
                nums[i - 1] = nums[i - 1] ^ 1
                nums[i] = nums[i] ^ 1

        if sum(nums) == len(nums):
            return count
        return -1
```

</details>

<br>

## Approach 3: Sliding Window Using Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] = nums[i + 1] == 0 ? 1 : 0;
                nums[i + 2] = nums[i + 2] == 0 ? 1 : 0;
                count++;
            }
        }

        if (nums[n - 2] == 0 || nums[n - 1] == 0) return -1;
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minOperations(int[] nums) {
        int n = nums.length;
        int count = 0;
        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] = nums[i + 1] == 0 ? 1 : 0;
                nums[i + 2] = nums[i + 2] == 0 ? 1 : 0;
                count++;
            }
        }

        if (nums[n - 2] == 0 || nums[n - 1] == 0) return -1;
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, nums):
        n = len(nums)
        count = 0
        for i in range(n - 2):
            if nums[i] == 0:
                nums[i] = 1
                nums[i + 1] = 1 if nums[i + 1] == 0 else 0
                nums[i + 2] = 1 if nums[i + 2] == 0 else 0
                count += 1

        if nums[n - 2] == 0 or nums[n - 1] == 0:
            return -1
        return count
```

</details>
