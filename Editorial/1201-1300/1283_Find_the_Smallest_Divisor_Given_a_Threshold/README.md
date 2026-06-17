# 1283. Find the Smallest Divisor Given a Threshold

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 1283 - Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)

## Problem

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

### Example 1

```text
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).
```

### Example 2

```text
Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
```

## Constraints

- 1 <= nums.length <= 5 * 104
- 1 <= nums[i] <= 106
- nums.length <= threshold <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1283. Find the Smallest Divisor Given a Threshold

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Search | C++, Java, JavaScript, Python3 |
| Binary Search | C++, Java, JavaScript, Python3 |

## Approach 1: Linear Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxElement = *max_element(nums.begin(), nums.end());
        
        // Iterate on all divisors.
        for (int divisor = 1; divisor <= maxElement; ++divisor) {
            int sumOfDivisionResults = 0;
            bool thresholdExceeded = true;
            
            // Divide all numbers of array and sum the result.
            for (int& num : nums) {
                sumOfDivisionResults += ceil((1.0 * num) / divisor);
                if (sumOfDivisionResults > threshold) {
                    thresholdExceeded = false;
                    break;
                }
            }
            
            // If threshold was not exceeded then return current divisor.
            if (thresholdExceeded) {
                return divisor;
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
    public int smallestDivisor(int[] nums, int threshold) {
        int maxElement = nums[0];
        for (int num : nums) {
            maxElement = Math.max(maxElement, num);
        }
        
        // Iterate on all divisors.
        for (int divisor = 1; divisor <= maxElement; ++divisor) {
            int sumOfDivisionResults = 0;
            boolean thresholdExceeded = true;
            
            // Divide all numbers of array and sum the result.
            for (int num : nums) {
                sumOfDivisionResults += Math.ceil((1.0 * num) / divisor);
                if (sumOfDivisionResults > threshold) {
                    thresholdExceeded = false;
                    break;
                }
            }
            
            // If threshold was not exceeded then return current divisor.
            if (thresholdExceeded) {
                return divisor;
            }
        }
        
        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let smallestDivisor = function(nums, threshold) {
    const maxElement = nums.reduce((a, b) => Math.max(a, b), nums[0]);

    // Iterate on all divisors.
    for (let divisor = 1; divisor <= maxElement; ++divisor) {
        let sumOfDivisionResults = 0;
        let thresholdExceeded = true;

        // Divide all numbers of array and sum the result.
        for (let index in nums) {
            const num = nums[index];
            sumOfDivisionResults += Math.ceil((1.0 * num) / divisor);
            
            if (sumOfDivisionResults > threshold) {
                thresholdExceeded = false;
                break;
            }
        }

        // If threshold was not exceeded then return current divisor.
        if (thresholdExceeded) {
            return divisor;
        }
    }

    return -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        max_element = max(nums)
        
        # Iterate on all divisors.
        for divisor in range(1, max_element + 1):
            sum_of_division_results = 0
            threshold_exceeded = True
            
            # Divide all numbers of array and sum the result.
            for num in nums:
                sum_of_division_results += ceil((1.0 * num) / divisor)
                if sum_of_division_results > threshold:
                    threshold_exceeded = False
                    break
            
            # If threshold was not exceeded then return current divisor.
            if threshold_exceeded:
                return divisor
                    
        return -1
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
    // Return the sum of division results with 'divisor'.
    int findDivisionSum(vector<int>& nums, int& divisor) {
        int result = 0;
        for (int& num : nums) {
            result += ceil((1.0 * num) / divisor);
        }
        return result;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        // Iterate using binary search on all divisors.
        while (low <= high) {
            int mid = (low + high) / 2;
            int result = findDivisionSum(nums, mid);
            // If current divisor does not exceed threshold, 
            // then it can be our answer, but also try smaller divisors
            // thus change search space to left half.
            if (result <= threshold) {
                ans = mid;
                high = mid - 1;
            }
            // Otherwise, we need a bigger divisor to reduce the result sum
            // thus change search space to right half.
            else {
                low = mid + 1;
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
    // Return the sum of division results with 'divisor'.
    private int findDivisionSum(int[] nums, int divisor) {
        int result = 0;
        for (int num : nums) {
            result += Math.ceil((1.0 * num) / divisor);
        }
        return result;
    }
    
    public int smallestDivisor(int[] nums, int threshold) {
        int ans = -1;
        
        int low = 1;
        int high = nums[0];
        for (int num : nums) {
            high = Math.max(high, num);
        }
        
        // Iterate using binary search on all divisors.
        while (low <= high) {
            int mid = (low + high) / 2;
            int result = findDivisionSum(nums, mid);
            // If current divisor does not exceed threshold, 
            // then it can be our answer, but also try smaller divisors
            // thus change search space to left half.
            if (result <= threshold) {
                ans = mid;
                high = mid - 1;
            }
            // Otherwise, we need a bigger divisor to reduce the result sum
            // thus change search space to right half.
            else {
                low = mid + 1;
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
// Return the sum of division results with 'divisor'.
let findDivisionSum = (nums, divisor) => {
    let result = 0;
    for (let index in nums) {
        const num = nums[index];
        result += Math.ceil((1.0 * num) / divisor);
    }
    return result;
}

let smallestDivisor = function(nums, threshold) {
    let ans = -1;
        
    let low = 1;
    let high = nums.reduce((a, b) => Math.max(a, b), nums[0]);

    // Iterate using binary search on all divisors.
    while (low <= high) {
        const mid = Math.floor((low + high) / 2);
        const result = findDivisionSum(nums, mid);
        // If current divisor does not exceed threshold, 
        // then it can be our answer, but also try smaller divisors
        // thus change search space to left half.
        if (result <= threshold) {
            ans = mid;
            high = mid - 1;
        }
        // Otherwise, we need a bigger divisor to reduce the result sum
        // thus change search space to right half.
        else {
            low = mid + 1;
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
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        
        # Return the sum of division results with 'divisor'.
        def find_division_sum(divisor: int) -> int:
            result = 0
            for num in nums:
                result += ceil((1.0 * num) / divisor)
            return result
        
        ans = -1
        low = 1
        high = max(nums)
        
        # Iterate using binary search on all divisors.
        while low <= high:
            mid = (low + high) // 2
            result = find_division_sum(mid)
            # If current divisor does not exceed threshold, 
            # then it can be our answer, but also try smaller divisors
            # thus change search space to left half.
            if result <= threshold:
                ans = mid
                high = mid - 1
            # Otherwise, we need a bigger divisor to reduce the result sum
            # thus change search space to right half.
            else:
                low = mid + 1
        
        return ans
```

</details>
