# 2256. Minimum Average Difference

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-average-difference/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 2256 - Minimum Average Difference](https://leetcode.com/problems/minimum-average-difference/)

## Problem

You are given a 0-indexed integer array nums of length n.

The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.

Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.

Note:

- The absolute difference of two numbers is the absolute value of their difference.
- The average of n elements is the sum of the n elements divided (integer division) by n.
- The average of 0 elements is considered to be 0.

### Example 1

```text
Input: nums = [2,5,3,9,5,3]
Output: 3
Explanation:
- The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
- The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
- The average difference of index 2 is: |(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
- The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
- The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
- The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
The average difference of index 3 is the minimum average difference so return 3.
```

### Example 2

```text
Input: nums = [0]
Output: 0
Explanation:
The only index is 0 so return 0.
The average difference of index 0 is: |0 / 1 - 0| = |0 - 0| = 0.
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Split Array With Same Average](https://leetcode.com/problems/split-array-with-same-average/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Number of Ways to Split Array](https://leetcode.com/problems/number-of-ways-to-split-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2256. Minimum Average Difference

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, JavaScript, Python3 |
| Prefix Sum | C++, Java, JavaScript, Python3 |
| Prefix Sum Optimized | C++, Java, JavaScript, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = int(nums.size());
        int ans = -1;
        int minAvgDiff = numeric_limits<int>::max();
        
        for (int index = 0; index < n; ++index) {
            // Calculate average of left part of array, index 0 to i.
            long long leftPartAverage = 0;
            for (int i = 0; i <= index; ++i) {
                leftPartAverage += nums[i];
            }
            leftPartAverage /= (index + 1);
            
            // Calculate average of right part of array, index i+1 to n-1.
            long long rightPartAverage = 0;
            for (int j = index + 1; j < n; ++j) {
                rightPartAverage += nums[j];
            }
            // If right part have 0 elements, then we don't divide by 0.
            if (index != n - 1) {
                rightPartAverage /= (n - index - 1);
            }
            
            int currDifference = int(abs(leftPartAverage - rightPartAverage));
            // If current difference of averages is smaller,
            // then current index can be our answer.
            if (currDifference < minAvgDiff) {
                minAvgDiff = currDifference;
                ans = index;
            }
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumAverageDifference(int[] nums) {
        int n = nums.length;
        int ans = -1;
        int minAvgDiff = Integer.MAX_VALUE;
        
        for (int index = 0; index < n; ++index) {
            // Calculate average of left part of array, index 0 to i.
            long leftPartAverage = 0;
            for (int i = 0; i <= index; ++i) {
                leftPartAverage += nums[i];
            }
            leftPartAverage /= (index + 1);
            
            // Calculate average of right part of array, index i+1 to n-1.
            long rightPartAverage = 0;
            for (int j = index + 1; j < n; ++j) {
                rightPartAverage += nums[j];
            }
            // If right part have 0 elements, then we don't divide by 0.
            if (index != n - 1) {
                rightPartAverage /= (n - index - 1);
            }
            
            int currDifference = (int) Math.abs(leftPartAverage - rightPartAverage);
            // If current difference of averages is smaller,
            // then current index can be our answer.
            if (currDifference < minAvgDiff) {
                minAvgDiff = currDifference;
                ans = index;
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let minimumAverageDifference = function(nums) {
    let n = nums.length;
    let ans = -1;
    let minAvgDiff = Number.MAX_SAFE_INTEGER;

    for (let index = 0; index < n; ++index) {
        // Calculate average of left part of array, index 0 to i.
        let leftPartAverage = 0;
        for (let i = 0; i <= index; ++i) {
            leftPartAverage += nums[i];
        }
        leftPartAverage = Math.floor(leftPartAverage / (index + 1));

        // Calculate average of right part of array, index i+1 to n-1.
        let rightPartAverage = 0;
        for (let j = index + 1; j < n; ++j) {
            rightPartAverage += nums[j];
        }
        // If right part have 0 elements, then we don't divide by 0.
        if (index != n - 1) {
            rightPartAverage = Math.floor(rightPartAverage / (n - index - 1));
        }

        let currDifference = Math.abs(leftPartAverage - rightPartAverage);
        // If current difference of averages is smaller,
        // then current index can be our answer.
        if (currDifference < minAvgDiff) {
            minAvgDiff = currDifference;
            ans = index;
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        ans = -1
        min_avg_diff = math.inf
        
        for index in range(n):
            # Calculate average of left part of array, index 0 to i.
            left_part_average = 0
            for i in range(index + 1):
                left_part_average += nums[i]
            left_part_average //= (index + 1)
            
            # Calculate average of right part of array, index i+1 to n-1.
            right_part_average = 0
            for j in range(index + 1, n):
                right_part_average += nums[j]
        
            # If right part have 0 elements, then we don't divide by 0.
            if index != n - 1:
                right_part_average //= (n - index - 1)
            
            curr_difference = abs(left_part_average - right_part_average)
            
            # If current difference of averages is smaller,
            # then current index can be our answer.
            if curr_difference < min_avg_diff:
                min_avg_diff = curr_difference
                ans = index
                
        return ans
```

</details>

<br>

## Approach 2: Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = int(nums.size());
        int ans = -1;
        int minAvgDiff = numeric_limits<int>::max();
        
        // Generate prefix and suffix sum arrays.
        vector<long long> prefixSum(n + 1);
        vector<long long> suffixSum(n + 1);
        
        for (int index = 0; index < n; ++index) {
            prefixSum[index + 1] = prefixSum[index] + nums[index];
        }
        
        for (int index = n - 1; index >= 0; --index) {
            suffixSum[index] = suffixSum[index + 1] + nums[index];
        }
        
        for (int index = 0; index < n; ++index) {
            // Calculate average of left part of array, index 0 to i.
            long long leftPartAverage = prefixSum[index + 1];
            leftPartAverage /= (index + 1);
            
            // Calculate average of right part of array, index i+1 to n-1.
            long long rightPartAverage = suffixSum[index + 1];
            // If right part have 0 elements, then we don't divide by 0.
            if (index != n - 1) {
                rightPartAverage /= (n - index - 1);
            }
            
            int currDifference = int(abs(leftPartAverage - rightPartAverage));
            // If current difference of averages is smaller,
            // then current index can be our answer.
            if (currDifference < minAvgDiff) {
                minAvgDiff = currDifference;
                ans = index;
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumAverageDifference(int[] nums) {
        int n = nums.length;
        int ans = -1;
        int minAvgDiff = Integer.MAX_VALUE;
        
        // Generate prefix and suffix sum arrays.
        long[] prefixSum = new long[n + 1];
        long[] suffixSum = new long[n + 1];
        
        for (int index = 0; index < n; ++index) {
            prefixSum[index + 1] = prefixSum[index] + nums[index];
        }
        
        for (int index = n - 1; index >= 0; --index) {
            suffixSum[index] = suffixSum[index + 1] + nums[index];
        }
        
        for (int index = 0; index < n; ++index) {
            // Calculate average of left part of array, index 0 to i.
            long leftPartAverage = prefixSum[index + 1];
            leftPartAverage /= (index + 1);
            
            // Calculate average of right part of array, index i+1 to n-1.
            long rightPartAverage = suffixSum[index + 1];
            // If right part have 0 elements, then we don't divide by 0.
            if (index != n - 1) {
                rightPartAverage /= (n - index - 1);
            }
            
            int currDifference = (int) Math.abs(leftPartAverage - rightPartAverage);
            // If current difference of averages is smaller,
            // then current index can be our answer.
            if (currDifference < minAvgDiff) {
                minAvgDiff = currDifference;
                ans = index;
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let minimumAverageDifference = function(nums) {
    let n = nums.length;
    let ans = -1;
    let minAvgDiff = Number.MAX_SAFE_INTEGER;

    // Generate prefix and suffix sum arrays.
    let prefixSum = Array(n + 1).fill(0);
    let suffixSum = Array(n + 1).fill(0);
    
    for (let index = 0; index < n; ++index) {
        prefixSum[index + 1] = prefixSum[index] + nums[index];
    }

    for (let index = n - 1; index >= 0; --index) {
        suffixSum[index] = suffixSum[index + 1] + nums[index];
    }
    
    for (let index = 0; index < n; ++index) {
        // Calculate average of left part of array, index 0 to i.
        let leftPartAverage = prefixSum[index + 1];
        leftPartAverage = Math.floor(leftPartAverage / (index + 1));

        // Calculate average of right part of array, index i+1 to n-1.
        let rightPartAverage = suffixSum[index + 1];
        // If right part have 0 elements, then we don't divide by 0.
        if (index != n - 1) {
            rightPartAverage = Math.floor(rightPartAverage / (n - index - 1));
        }

        let currDifference = Math.abs(leftPartAverage - rightPartAverage);
        // If current difference of averages is smaller,
        // then current index can be our answer.
        if (currDifference < minAvgDiff) {
            minAvgDiff = currDifference;
            ans = index;
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        ans = -1
        min_avg_diff = math.inf
        
        # Generate prefix and suffix sum arrays.
        prefix_sum = [0] * (n + 1)
        suffix_sum = [0] * (n + 1)
        
        for index in range(n):
            prefix_sum[index + 1] = prefix_sum[index] + nums[index];
        
        for index in range(n - 1, -1, -1):
            suffix_sum[index] = suffix_sum[index + 1] + nums[index];
        
        for index in range(n):
            # Calculate average of left part of array, index 0 to i.
            left_part_average = prefix_sum[index + 1]
            left_part_average //= (index + 1)
            
            # Calculate average of right part of array, index i+1 to n-1.
            right_part_average = suffix_sum[index + 1]
            # If right part have 0 elements, then we don't divide by 0.
            if index != n - 1:
                right_part_average //= (n - index - 1)
            
            curr_difference = abs(left_part_average - right_part_average)
            
            # If current difference of averages is smaller,
            # then current index can be our answer.
            if curr_difference < min_avg_diff:
                min_avg_diff = curr_difference
                ans = index
                
        return ans
```

</details>

<br>

## Approach 3: Prefix Sum Optimized

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = int(nums.size());
        int ans = -1;
        int minAvgDiff = numeric_limits<int>::max();
        long long currPrefixSum = 0;
        
        // Get total sum of array.
        long long totalSum = 0;
        for (int index = 0; index < n; ++index) {
            totalSum += nums[index];
        }
        
        for (int index = 0; index < n; ++index) {
            currPrefixSum += nums[index];
            
            // Calculate average of left part of array, index 0 to i.
            long long leftPartAverage = currPrefixSum;
            leftPartAverage /= (index + 1);
            
            // Calculate average of right part of array, index i+1 to n-1.
            long long rightPartAverage = totalSum - currPrefixSum;
            // If right part have 0 elements, then we don't divide by 0.
            if (index != n - 1) {
                rightPartAverage /= (n - index - 1);
            }
            
            int currDifference = int(abs(leftPartAverage - rightPartAverage));
            // If current difference of averages is smaller,
            // then current index can be our answer.
            if (currDifference < minAvgDiff) {
                minAvgDiff = currDifference;
                ans = index;
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumAverageDifference(int[] nums) {
        int n = nums.length;
        int ans = -1;
        int minAvgDiff = Integer.MAX_VALUE;
        long currPrefixSum = 0;
        
        // Get total sum of array.
        long totalSum = 0;
        for (int index = 0; index < n; ++index) {
            totalSum += nums[index];
        }
        
        for (int index = 0; index < n; ++index) {
            currPrefixSum += nums[index];
            
            // Calculate average of left part of array, index 0 to i.
            long leftPartAverage = currPrefixSum;
            leftPartAverage /= (index + 1);
            
            // Calculate average of right part of array, index i+1 to n-1.
            long rightPartAverage = totalSum - currPrefixSum;
            // If right part have 0 elements, then we don't divide by 0.
            if (index != n - 1) {
                rightPartAverage /= (n - index - 1);
            }
            
            int currDifference = (int) Math.abs(leftPartAverage - rightPartAverage);
            // If current difference of averages is smaller,
            // then current index can be our answer.
            if (currDifference < minAvgDiff) {
                minAvgDiff = currDifference;
                ans = index;
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let minimumAverageDifference = function(nums) {
    let n = nums.length;
    let ans = -1;
    let minAvgDiff = Number.MAX_SAFE_INTEGER;
    let currPrefixSum = 0;
        
    // Get total sum of array.
    let totalSum = 0;
    for (let index = 0; index < n; ++index) {
        totalSum += nums[index];
    }
    
    for (let index = 0; index < n; ++index) {
        currPrefixSum += nums[index];
        
        // Calculate average of left part of array, index 0 to i.
        let leftPartAverage = currPrefixSum;
        leftPartAverage = Math.floor(leftPartAverage / (index + 1));

        // Calculate average of right part of array, index i+1 to n-1.
        let rightPartAverage = totalSum - currPrefixSum;
        // If right part have 0 elements, then we don't divide by 0.
        if (index != n - 1) {
            rightPartAverage = Math.floor(rightPartAverage / (n - index - 1));
        }

        let currDifference = Math.abs(leftPartAverage - rightPartAverage);
        // If current difference of averages is smaller,
        // then current index can be our answer.
        if (currDifference < minAvgDiff) {
            minAvgDiff = currDifference;
            ans = index;
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        ans = -1
        min_avg_diff = math.inf
        curr_prefix_sum = 0
        
        # Get total sum of array.
        total_sum = 0
        for index in range(n):
            total_sum += nums[index]
        
        for index in range(n):
            curr_prefix_sum += nums[index]
            
            # Calculate average of left part of array, index 0 to i.
            left_part_average = curr_prefix_sum
            left_part_average //= (index + 1)
            
            # Calculate average of right part of array, index i+1 to n-1.
            right_part_average = total_sum - curr_prefix_sum
            # If right part have 0 elements, then we don't divide by 0.
            if index != n - 1:
                right_part_average //= (n - index - 1)
            
            curr_difference = abs(left_part_average - right_part_average)
            
            # If current difference of averages is smaller,
            # then current index can be our answer.
            if curr_difference < min_avg_diff:
                min_avg_diff = curr_difference
                ans = index
                
        return ans
```

</details>
