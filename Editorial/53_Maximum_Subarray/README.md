# 53. Maximum Subarray

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-subarray/)  
`Array` `Divide and Conquer` `Dynamic Programming`

**Problem Link:** [LeetCode 53 - Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

## Problem

Given an integer array nums, find the subarray with the largest sum, and return its sum.

### Example 1

```text
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

### Example 2

```text
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```

### Example 3

```text
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

## Constraints

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Degree of an Array](https://leetcode.com/problems/degree-of-an-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Longest Turbulent Subarray](https://leetcode.com/problems/longest-turbulent-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Score Of Spliced Array](https://leetcode.com/problems/maximum-score-of-spliced-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Absolute Sum of Any Subarray](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Subarray Sum After One Operation](https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Substring With Largest Variance](https://leetcode.com/problems/substring-with-largest-variance/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Subarrays With Score Less Than K](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Value of a String in an Array](https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the Substring With Maximum Cost](https://leetcode.com/problems/find-the-substring-with-maximum-cost/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [K Items With the Maximum Sum](https://leetcode.com/problems/k-items-with-the-maximum-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Good Subarray Sum](https://leetcode.com/problems/maximum-good-subarray-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximize Subarray Sum After Removing All Occurrences of One Element](https://leetcode.com/problems/maximize-subarray-sum-after-removing-all-occurrences-of-one-element/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 53. Maximum Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Optimized Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming, Kadane's Algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Divide and Conquer (Advanced) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Optimized Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxSubArray(int* nums, int numsSize) {
    int max_subarray = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        int current_subarray = 0;
        for (int j = i; j < numsSize; j++) {
            current_subarray += nums[j];
            max_subarray = current_subarray > max_subarray ? current_subarray
                                                           : max_subarray;
        }
    }
    return max_subarray;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_subarray = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int current_subarray = 0;
            for (int j = i; j < nums.size(); j++) {
                current_subarray += nums[j];
                max_subarray = max(max_subarray, current_subarray);
            }
        }
        return max_subarray;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxSubArray(int[] nums) {
        int max_subarray = int.MinValue;
        for (int i = 0; i < nums.Length; i++) {
            int current_subarray = 0;
            for (int j = i; j < nums.Length; j++) {
                current_subarray += nums[j];
                max_subarray = Math.Max(max_subarray, current_subarray);
            }
        }

        return max_subarray;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxSubArray(nums []int) int {
    max_subarray := -(int(^uint(0) >> 1)) - 1 // min int value
    for i := 0; i < len(nums); i++ {
        current_subarray := 0
        for j := i; j < len(nums); j++ {
            current_subarray += nums[j]
            if current_subarray > max_subarray {
                max_subarray = current_subarray
            }
        }
    }
    return max_subarray
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int maxSubarray = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int currentSubarray = 0;
            for (int j = i; j < nums.length; j++) {
                currentSubarray += nums[j];
                maxSubarray = Math.max(maxSubarray, currentSubarray);
            }
        }

        return maxSubarray;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSubArray = function (nums) {
    let max_subarray = Number.NEGATIVE_INFINITY;
    for (let i = 0; i < nums.length; i++) {
        let current_subarray = 0;
        for (let j = i; j < nums.length; j++) {
            current_subarray += nums[j];
            max_subarray = Math.max(max_subarray, current_subarray);
        }
    }
    return max_subarray;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_subarray = -math.inf
        for i in range(len(nums)):
            current_subarray = 0
            for j in range(i, len(nums)):
                current_subarray += nums[j]
                max_subarray = max(max_subarray, current_subarray)

        return max_subarray
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxSubArray(nums: number[]): number {
    let max_subarray = Number.NEGATIVE_INFINITY;
    for (let i = 0; i < nums.length; i++) {
        let current_subarray = 0;
        for (let j = i; j < nums.length; j++) {
            current_subarray += nums[j];
            max_subarray = Math.max(max_subarray, current_subarray);
        }
    }
    return max_subarray;
}
```

</details>

<br>

## Approach 2: Dynamic Programming, Kadane's Algorithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxSubArray(int* nums, int numsSize) {
    // Initialize our variables using the first element.
    int currentSubarray = nums[0];
    int maxSubarray = nums[0];
    // Start with the 2nd element since we already used the first one.
    for (int i = 1; i < numsSize; i++) {
        // If current_subarray is negative, throw it away. Otherwise, keep
        // adding to it.
        currentSubarray =
            currentSubarray < 0 ? nums[i] : currentSubarray + nums[i];
        maxSubarray =
            currentSubarray > maxSubarray ? currentSubarray : maxSubarray;
    }
    return maxSubarray;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize our variables using the first element.
        int currentSubarray = nums[0];
        int maxSubarray = nums[0];
        // Start with the 2nd element since we already used the first one.
        for (int i = 1; i < nums.size(); i++) {
            // If current_subarray is negative, throw it away. Otherwise, keep
            // adding to it.
            currentSubarray = max(nums[i], currentSubarray + nums[i]);
            maxSubarray = max(maxSubarray, currentSubarray);
        }
        return maxSubarray;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxSubArray(int[] nums) {
        // Initialize our variables using the first element.
        int currentSubarray = nums[0];
        int maxSubarray = nums[0];
        // Start with the 2nd element since we already used the first one.
        for (int i = 1; i < nums.Length; i++) {
            // If current_subarray is negative, throw it away. Otherwise, keep
            // adding to it.
            currentSubarray = Math.Max(nums[i], currentSubarray + nums[i]);
            maxSubarray = Math.Max(maxSubarray, currentSubarray);
        }

        return maxSubarray;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxSubArray(nums []int) int {
    // Initialize our variables using the first element.
    currentSubarray := nums[0]
    maxSubarray := nums[0]
    // Start with the 2nd element since we already used the first one.
    for i := 1; i < len(nums); i++ {
        num := nums[i]
        // If current_subarray is negative, throw it away. Otherwise, keep adding to it.
        if currentSubarray < 0 {
            currentSubarray = num
        } else {
            currentSubarray += num
        }
        if maxSubarray < currentSubarray {
            maxSubarray = currentSubarray
        }
    }
    return maxSubarray
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxSubArray(int[] nums) {
        // Initialize our variables using the first element.
        int currentSubarray = nums[0];
        int maxSubarray = nums[0];

        // Start with the 2nd element since we already used the first one.
        for (int i = 1; i < nums.length; i++) {
            int num = nums[i];
            // If current_subarray is negative, throw it away. Otherwise, keep adding to it.
            currentSubarray = Math.max(num, currentSubarray + num);
            maxSubarray = Math.max(maxSubarray, currentSubarray);
        }

        return maxSubarray;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSubArray = function (nums) {
    // Initialize our variables using the first element.
    let currentSubarray = nums[0];
    let maxSubarray = nums[0];
    // Start with the 2nd element since we already used the first one.
    for (let i = 1; i < nums.length; i++) {
        let num = nums[i];
        // If current_subarray is negative, throw it away. Otherwise, keep adding to it.
        currentSubarray = Math.max(num, currentSubarray + num);
        maxSubarray = Math.max(maxSubarray, currentSubarray);
    }
    return maxSubarray;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # Initialize our variables using the first element.
        current_subarray = max_subarray = nums[0]

        # Start with the 2nd element since we already used the first one.
        for num in nums[1:]:
            # If current_subarray is negative, throw it away. Otherwise, keep adding to it.
            current_subarray = max(num, current_subarray + num)
            max_subarray = max(max_subarray, current_subarray)

        return max_subarray
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxSubArray(nums: number[]): number {
    // Initialize our variables using the first element.
    let currentSubarray: number = nums[0];
    let maxSubarray: number = nums[0];
    // Start with the 2nd element since we already used the first one.
    for (let i = 1; i < nums.length; i++) {
        let num: number = nums[i];
        // If current_subarray is negative, throw it away. Otherwise, keep adding to it.
        currentSubarray = Math.max(num, currentSubarray + num);
        maxSubarray = Math.max(maxSubarray, currentSubarray);
    }
    return maxSubarray;
}
```

</details>

<br>

## Approach 3: Divide and Conquer (Advanced)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxSubArray(int* nums, int numsSize) {
    return findBestSubarray(nums, 0, numsSize - 1);
}
int findBestSubarray(int* nums, int left, int right) {
    // Base case - empty array.
    if (left > right) {
        return INT_MIN;
    }
    int mid = (left + right) / 2;
    int curr = 0;
    int bestLeftSum = 0;
    int bestRightSum = 0;
    // Iterate from the middle to the beginning.
    for (int i = mid - 1; i >= left; i--) {
        curr += nums[i];
        bestLeftSum = fmax(bestLeftSum, curr);
    }
    // Reset curr and iterate from the middle to the end.
    curr = 0;
    for (int i = mid + 1; i <= right; i++) {
        curr += nums[i];
        bestRightSum = fmax(bestRightSum, curr);
    }
    // The bestCombinedSum uses the middle element and the best
    // possible sum from each half.
    int bestCombinedSum = nums[mid] + bestLeftSum + bestRightSum;
    // Find the best subarray possible from both halves.
    int leftHalf = findBestSubarray(nums, left, mid - 1);
    int rightHalf = findBestSubarray(nums, mid + 1, right);
    // The largest of the 3 is the answer for any given input array.
    return fmax(bestCombinedSum, fmax(leftHalf, rightHalf));
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    vector<int> numsArray;

public:
    int maxSubArray(vector<int>& nums) {
        numsArray = nums;
        // Our helper function is designed to solve this problem for
        // any array - so just call it using the entire input!
        return findBestSubarray(0, numsArray.size() - 1);
    }
    int findBestSubarray(int left, int right) {
        // Base case - empty array.
        if (left > right) {
            return INT_MIN;
        }
        int mid = (left + right) / 2;
        int curr = 0;
        int bestLeftSum = 0;
        int bestRightSum = 0;
        // Iterate from the middle to the beginning.
        for (int i = mid - 1; i >= left; i--) {
            curr += numsArray[i];
            bestLeftSum = max(bestLeftSum, curr);
        }
        // Reset curr and iterate from the middle to the end.
        curr = 0;
        for (int i = mid + 1; i <= right; i++) {
            curr += numsArray[i];
            bestRightSum = max(bestRightSum, curr);
        }
        // The bestCombinedSum uses the middle element and the best
        // possible sum from each half.
        int bestCombinedSum = numsArray[mid] + bestLeftSum + bestRightSum;
        // Find the best subarray possible from both halves.
        int leftHalf = findBestSubarray(left, mid - 1);
        int rightHalf = findBestSubarray(mid + 1, right);
        // The largest of the 3 is the answer for any given input array.
        return max(bestCombinedSum, max(leftHalf, rightHalf));
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int[] numsArray;

    public int MaxSubArray(int[] nums) {
        numsArray = nums;
        // Our helper function is designed to solve this problem for
        // any array - so just call it using the entire input!
        return FindBestSubarray(0, numsArray.Length - 1);
    }

    private int FindBestSubarray(int left, int right) {
        // Base case - empty array.
        if (left > right) {
            return Int32.MinValue;
        }

        int mid = (left + right) / 2;
        int curr = 0;
        int bestLeftSum = 0;
        int bestRightSum = 0;
        // Iterate from the middle to the beginning.
        for (int i = mid - 1; i >= left; i--) {
            curr += numsArray[i];
            bestLeftSum = Math.Max(bestLeftSum, curr);
        }

        // Reset curr and iterate from the middle to the end.
        curr = 0;
        for (int i = mid + 1; i <= right; i++) {
            curr += numsArray[i];
            bestRightSum = Math.Max(bestRightSum, curr);
        }

        // The bestCombinedSum uses the middle element and the best possible sum
        // from each half.
        int bestCombinedSum = numsArray[mid] + bestLeftSum + bestRightSum;
        // Find the best subarray possible from both halves.
        int leftHalf = FindBestSubarray(left, mid - 1);
        int rightHalf = FindBestSubarray(mid + 1, right);
        // The largest of the 3 is the answer for any given input array.
        return Math.Max(bestCombinedSum, Math.Max(leftHalf, rightHalf));
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxSubArray(nums []int) int {
    // Our helper function is designed to solve this problem for
    // any array - so just call it using the entire input!
    return findBestSubarray(nums, 0, len(nums)-1)
}

func findBestSubarray(nums []int, left int, right int) int {
    // Base case - empty array.
    if left > right {
        return -2147483648
    }
    mid := (left + right) / 2
    curr := 0
    bestLeftSum := 0
    bestRightSum := 0
    // Iterate from the middle to the beginning.
    for i := mid - 1; i >= left; i-- {
        curr += nums[i]
        if bestLeftSum < curr {
            bestLeftSum = curr
        }
    }
    // Reset curr and iterate from the middle to the end.
    curr = 0
    for i := mid + 1; i <= right; i++ {
        curr += nums[i]
        if bestRightSum < curr {
            bestRightSum = curr
        }
    }
    // The bestCombinedSum uses the middle element and the best possible sum from each half.
    bestCombinedSum := nums[mid] + bestLeftSum + bestRightSum
    // Find the best subarray possible from both halves.
    leftHalf := findBestSubarray(nums, left, mid-1)
    rightHalf := findBestSubarray(nums, mid+1, right)
    // The largest of the 3 is the answer for any given input array.
    if bestCombinedSum < leftHalf {
        bestCombinedSum = leftHalf
    }
    if bestCombinedSum < rightHalf {
        bestCombinedSum = rightHalf
    }
    return bestCombinedSum
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int[] numsArray;

    public int maxSubArray(int[] nums) {
        numsArray = nums;

        // Our helper function is designed to solve this problem for
        // any array - so just call it using the entire input!
        return findBestSubarray(0, numsArray.length - 1);
    }

    private int findBestSubarray(int left, int right) {
        // Base case - empty array.
        if (left > right) {
            return Integer.MIN_VALUE;
        }

        int mid = Math.floorDiv(left + right, 2);
        int curr = 0;
        int bestLeftSum = 0;
        int bestRightSum = 0;

        // Iterate from the middle to the beginning.
        for (int i = mid - 1; i >= left; i--) {
            curr += numsArray[i];
            bestLeftSum = Math.max(bestLeftSum, curr);
        }

        // Reset curr and iterate from the middle to the end.
        curr = 0;
        for (int i = mid + 1; i <= right; i++) {
            curr += numsArray[i];
            bestRightSum = Math.max(bestRightSum, curr);
        }

        // The bestCombinedSum uses the middle element and the best
        // possible sum from each half.
        int bestCombinedSum = numsArray[mid] + bestLeftSum + bestRightSum;

        // Find the best subarray possible from both halves.
        int leftHalf = findBestSubarray(left, mid - 1);
        int rightHalf = findBestSubarray(mid + 1, right);

        // The largest of the 3 is the answer for any given input array.
        return Math.max(bestCombinedSum, Math.max(leftHalf, rightHalf));
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSubArray = function (nums) {
    // Our helper function is designed to solve this problem for
    // any array - so just call it using the entire input!
    return findBestSubarray(nums, 0, nums.length - 1);
};
var findBestSubarray = function (nums, left, right) {
    // Base case - empty array.
    if (left > right) {
        return -Infinity;
    }
    let mid = Math.floor((left + right) / 2);
    let curr = 0;
    let bestLeftSum = 0;
    let bestRightSum = 0;
    // Iterate from the middle to the beginning.
    for (let i = mid - 1; i >= left; i--) {
        curr += nums[i];
        bestLeftSum = Math.max(bestLeftSum, curr);
    }
    // Reset curr and iterate from the middle to the end.
    curr = 0;
    for (let i = mid + 1; i <= right; i++) {
        curr += nums[i];
        bestRightSum = Math.max(bestRightSum, curr);
    }
    // The bestCombinedSum uses the middle element and the best possible sum from each half.
    let bestCombinedSum = nums[mid] + bestLeftSum + bestRightSum;
    // Find the best subarray possible from both halves.
    let leftHalf = findBestSubarray(nums, left, mid - 1);
    let rightHalf = findBestSubarray(nums, mid + 1, right);
    // The largest of the 3 is the answer for any given input array.
    return Math.max(bestCombinedSum, Math.max(leftHalf, rightHalf));
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        def findBestSubarray(nums, left, right):
            # Base case - empty array.
            if left > right:
                return -math.inf

            mid = (left + right) // 2
            curr = best_left_sum = best_right_sum = 0

            # Iterate from the middle to the beginning.
            for i in range(mid - 1, left - 1, -1):
                curr += nums[i]
                best_left_sum = max(best_left_sum, curr)

            # Reset curr and iterate from the middle to the end.
            curr = 0
            for i in range(mid + 1, right + 1):
                curr += nums[i]
                best_right_sum = max(best_right_sum, curr)

            # The best_combined_sum uses the middle element and
            # the best possible sum from each half.
            best_combined_sum = nums[mid] + best_left_sum + best_right_sum

            # Find the best subarray possible from both halves.
            left_half = findBestSubarray(nums, left, mid - 1)
            right_half = findBestSubarray(nums, mid + 1, right)

            # The largest of the 3 is the answer for any given input array.
            return max(best_combined_sum, left_half, right_half)

        # Our helper function is designed to solve this problem for
        # any array - so just call it using the entire input!
        return findBestSubarray(nums, 0, len(nums) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxSubArray(nums: number[]): number {
    // Our helper function is designed to solve this problem for
    // any array - so just call it using the entire input!
    return findBestSubarray(nums, 0, nums.length - 1);
}
function findBestSubarray(nums: number[], left: number, right: number): number {
    // Base case - empty array.
    if (left > right) {
        return -Infinity;
    }
    let mid = Math.floor((left + right) / 2);
    let curr = 0;
    let bestLeftSum = 0;
    let bestRightSum = 0;
    // Iterate from the middle to the beginning.
    for (let i = mid - 1; i >= left; i--) {
        curr += nums[i];
        bestLeftSum = Math.max(bestLeftSum, curr);
    }
    // Reset curr and iterate from the middle to the end.
    curr = 0;
    for (let i = mid + 1; i <= right; i++) {
        curr += nums[i];
        bestRightSum = Math.max(bestRightSum, curr);
    }
    // The bestCombinedSum uses the middle element and the best possible sum from each half.
    let bestCombinedSum = nums[mid] + bestLeftSum + bestRightSum;
    // Find the best subarray possible from both halves.
    let leftHalf = findBestSubarray(nums, left, mid - 1);
    let rightHalf = findBestSubarray(nums, mid + 1, right);
    // The largest of the 3 is the answer for any given input array.
    return Math.max(bestCombinedSum, Math.max(leftHalf, rightHalf));
}
```

</details>
