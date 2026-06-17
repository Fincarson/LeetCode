# 1413. Minimum Value to Get Positive Step by Step Sum

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 1413 - Minimum Value to Get Positive Step by Step Sum](https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/)

## Problem

Given an array of integers nums, you start with an initial positive value startValue.

In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

Return the minimum positive value of startValue such that the step by step sum is never less than 1.

### Example 1

```text
Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
step by step sum
startValue = 4 | startValue = 5 | nums
  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
  (4 +2 ) = 6  | (5 +2 ) = 7    |   2
```

### Example 2

```text
Input: nums = [1,2]
Output: 1
Explanation: Minimum start value should be positive.
```

### Example 3

```text
Input: nums = [1,-2,-3]
Output: 5
```

## Constraints

- 1 <= nums.length <= 100
- -100 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1413. Minimum Value to Get Positive Step by Step Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, JavaScript, Python |
| Binary Search | C++, Java, JavaScript, Python |
| Prefix total | C++, Java, JavaScript, Python |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        // Start with startValue = 1. 
        int startValue = 1;

        // While we haven't found the first valid startValue
        while (true) {
            // The step-by-step total equals startValue at the beginning.
            // Use boolean parameter "isValid" to record whether the total 
            // is larger than or equal to 1.
            int total = startValue;
            bool isValid = true;

            // Iterate over the array "nums".
            for (int num : nums) {
                // In each iteration, calculate "total" 
                // plus the element "num" in the array.
                total += num;

                // If "total" is less than 1, we shall try a larger startValue,
                // we mark "isValid" as "false" and break the current iteration.
                if (total < 1) {
                    isValid = false;
                    break;
                }
            }

            // If "isVaild" is true, meaning "total" is never less than 1 in the
            // iteration, therefore we return this "startValue". Otherwise, we 
            // go ahead and try "startValue" + 1 as the new "startValue". 
            if (isValid) {
                return startValue;
            } else {
                startValue += 1;
            }
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minStartValue(int[] nums) {
        // Start with startValue = 1. 
        int startValue = 1;

        // While we haven't found the first valid startValue
        while (true) {
            // The step-by-step total equals startValue at the beginning.
            // Use boolean parameter "isValid" to record whether the total 
            // is larger than or equal to 1.
            int total = startValue;
            boolean isValid = true;

            // Iterate over the array "nums".
            for (int num : nums) {
                // In each iteration, calculate "total" 
                // plus the element "num" in the array.
                total += num;

                // If "total" is less than 1, we shall try a larger startValue,
                // we mark "isValid" as "false" and break the current iteration.
                if (total < 1) {
                    isValid = false;
                    break;
                }
            }

            // If "isVaild" is true, meaning "total" is never less than 1 in the
            // iteration, therefore we return this "startValue". Otherwise, we 
            // go ahead and try "startValue" + 1 as the new "startValue". 
            if (isValid) {
                return startValue;
            } else {
                startValue += 1;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minStartValue = function(nums) {
    // Start with startValue = 1. 
    var startValue = 1;

    // While we haven't found the first valid startValue
    while (true) {
        // The step-by-step total equals startValue at the beginning.
        // Use boolean parameter "isValid" to record whether the total 
        // is larger than or equal to 1.
        var total = startValue;
        isValid = true;

        // Iterate over the array "nums".
        for (const num of nums) {
            // In each iteration, calculate "total" 
            // plus the element "num" in the array.
            total += num;

            // If "total" is less than 1, we shall try a larger startValue,
            // we mark "isValid" as "false" and break the current iteration.
            if (total < 1) {
                isValid = false;
                break;
            }
        }

        // If "isVaild" is true, meaning "total" is never less than 1 in the
        // iteration, therefore we return this "startValue". Otherwise, we 
        // go ahead and try "startValue" + 1 as the new "startValue". 
        if (isValid) {
            return startValue;
        } else {
            startValue += 1;
        }      
    }
};
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        # Start with startValue = 1. 
        start_value = 1

        # While we haven't found the first valid startValue
        while True:
            # The step-by-step total "total" equals startValue at the beginning.
            # Use boolean parameter "isValid" to record whether the total 
            # is larger than or equal to 1.
            total = start_value
            is_valid = True

            # Iterate over the array "nums".
            for num in nums:
                # In each iteration, calculate "total" 
                # plus the element "num" in the array.
                total += num

                # If "total" is less than 1, we shall try a larger startValue,
                # we mark "isValid" as "false" and break the current iteration.
                if total < 1:
                    is_valid = False
                    break

            # If "isVaild" is true, meaning "total" is never less than 1 in the
            # iteration, therefore we return this "startValue". Otherwise, we 
            # go ahead and try "startValue" + 1 as the new "startValue". 
            if is_valid:
                return start_value
            else:
                start_value += 1
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        // Let n be the length of the array "nums", m be the absolute value 
        // of the lower boundary of the element. In this question we have m = 100.
        int n = nums.size();
        int m = 100;

        // Set left and right boundaries according to left = 1, right = m * n + 1.
        int left = 1;
        int right = m * n + 1;

        while (left < right) {
            // Get the middle index "middle" of the two boundaries, let the start value 
            // be "middle". The initial step-by-step total "total" equals to middle as well.
            // Use boolean parameter "isValid" to record whether the total 
            // is greater than or equal to 1.
            int middle = (left + right) / 2;
            int total = middle;
            bool isValid = true;

            // Iterate over the array "nums".
            for (int num : nums) {

                // In each iteration, calculate "total" plus the element "num" in the array.
                total += num;

                // If "total" is less than 1, we shall try a larger start value,
                // we mark "isValid" as "false" and break the current iteration.
                if (total < 1) {
                    isValid = false;
                    break;
                }
            }

            // Check if middle is valid, and reduce the search space by half.
            if (isValid) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        // When the left and right boundaries coincide, we have found
        // the target value, that is, the minimum valid startValue.
        return left;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minStartValue(int[] nums) {
        // Let n be the length of the array "nums", m be the absolute value 
        // of the lower boundary of the element. In this question we have m = 100.
        int n = nums.length;
        int m = 100;

        // Set left and right boundaries according to left = 1, right = m * n + 1.
        int left = 1;
        int right = m * n + 1;

        while (left < right) {
            // Get the middle index "middle" of the two boundaries, let the start value 
            // be "middle". The initial step-by-step total "total" equals to middle as well.
            // Use boolean parameter "isValid" to record whether the total 
            // is greater than or equal to 1.
            int middle = (left + right) / 2;
            int total = middle;
            boolean isValid = true;

            // Iterate over the array "nums".
            for (int num : nums) {

                // In each iteration, calculate "total" plus the element "num" in the array.
                total += num;

                // If "total" is less than 1, we shall try a larger start value,
                // we mark "isValid" as "false" and break the current iteration.
                if (total < 1) {
                    isValid = false;
                    break;
                }
            }

            // Check if middle is valid, and reduce the search space by half.
            if (isValid) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        // When the left and right boundaries coincide, we have found
        // the target value, that is, the minimum valid startValue.
        return left;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minStartValue = function(nums) {
    // Let n be the length of the array "nums", m be the absolute value 
    // of the lower boundary of the element. In this question we have m = 100.
    var n = nums.length;
    var m = 100;

    // Set left and right boundaries according to left = 1, right = m * n + 1.
    var left = 1;
    var right = m * n + 1;

    while (left < right) {
        // Get the middle index "middle" of the two boundaries, let the start value 
        // be "middle". The initial step-by-step total "total" equals to middle as well.
        // Use boolean parameter "isValid" to record whether the total 
        // is greater than or equal to 1.
        var middle = Math.floor((left + right) / 2);
        var total = middle;
        var isValid = true;

        // Iterate over the array "nums".
        for (const num of nums) {

            // In each iteration, calculate "total" plus the element "num" in the array.
            total += num;

            // If "total" is less than 1, we shall try a larger start value,
            // we mark "isValid" as "false" and break the current iteration.
            if (total < 1) {
                isValid = false;
                break;
            }
        }

        // Check if middle is valid, and reduce the search space by half.
        if (isValid) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    // When the left and right boundaries coincide, we have found
    // the target value, that is, the minimum valid startValue.
    return left;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        # Let n be the length of the array "nums", m be the absolute value 
        # of the lower boundary of the element. In this question we have m = 100.
        n = len(nums)
        m = 100

        # Set left and right boundaries according to left = 1, right = m * n + 1.
        left = 1
        right = m * n + 1

        while left < right:
            # Get the middle index "middle" of the two boundaries, let the start value 
            # be "middle". The initial step-by-step total "total" equals to middle as well.
            # Use boolean parameter "is_valid" to record whether the total 
            # is greater than or equal to 1.
            middle = (left + right) // 2
            total = middle
            is_valid = True

            # Iterate over the array "nums".
            for num in nums:

                # In each iteration, calculate "total" plus the element "num" in the array.
                total += num

                # If "total" is less than 1, we shall try a larger start value,
                # we mark "is_valid" as "false" and break the current iteration.
                if total < 1:
                    is_valid = False
                    break

            # Check if middle is valid, and reduce the search space by half.
            if is_valid: 
                right = middle
            else:
                left = middle + 1

        # When the left and right boundaries coincide, we have found
        # the target value, that is, the minimum valid startValue.
        return left
```

</details>

<br>

## Approach 3: Prefix total

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        // We use "total" for current step-by-step total, "minVal" for minimum 
        // step-by-step total among all sums. Since we always start with 
        // startValue = 0, therefore the initial current step-by-step total is 0, 
        // thus we set "total" and "minVal" be 0. 
        int minVal = 0;
        int total = 0;

        // Iterate over the array and get the minimum step-by-step total.
        for (int num : nums) {

            total += num;
            minVal = min(minVal, total);
        }
        
        // We have to let the minimum step-by-step total equals to 1, 
        // by increasing the startValue from 0 to -minVal + 1, 
        // which is just the minimum startValue we want.
        return -minVal + 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minStartValue(int[] nums) {
        // We use "total" for current step-by-step total, "minVal" for minimum 
        // step-by-step total among all sums. Since we always start with 
        // startValue = 0, therefore the initial current step-by-step total is 0, 
        // thus we set "total" and "minVal" be 0. 
        int minVal = 0;
        int total = 0;

        // Iterate over the array and get the minimum step-by-step total.
        for (int num : nums) {

            total += num;
            minVal = Math.min(minVal, total);
        }

        // We have to let the minimum step-by-step total equals to 1, 
        // by increasing the startValue from 0 to -minVal + 1, 
        // which is just the minimum startValue we want.
        return -minVal + 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minStartValue = function(nums) {
    // We use "total" for current step-by-step total, "minVal" for minimum 
    // step-by-step total among all sums. Since we always start with 
    // startValue = 0, therefore the initial current step-by-step total is 0, 
    // thus we set "total" and "minVal" be 0. 
    var minVal = 0;
    var total = 0;

    // Iterate over the array and get the minimum step-by-step total.
    for (var i = 0; i < nums.length; ++i) {
        total += nums[i];
        minVal = Math.min(minVal, total);
    }

    // We have to let the minimum step-by-step total equals to 1, 
    // by increasing the startValue from 0 to -minVal + 1, 
    // which is just the minimum startValue we want.
    return -minVal + 1;
};
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        # We use "total" for current step-by-step total, "min_val" for minimum 
        # step-by-step total among all sums. Since we always start with 
        # startValue = 0, therefore the initial current step-by-step total is 0, 
        # thus we set "total" and "min_val" be 0. 
        min_val = 0
        total = 0

        # Iterate over the array and get the minimum step-by-step total.
        for num in nums:
            total += num
            min_val = min(min_val, total)

        # We have to change the minimum step-by-step total to 1, 
        # by increasing the startValue from 0 to -min_val + 1, 
        # which is just the minimum startValue we want.
        return -min_val + 1
```

</details>
