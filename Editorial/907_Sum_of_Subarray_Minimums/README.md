# 907. Sum of Subarray Minimums

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/sum-of-subarray-minimums/)  
`Array` `Dynamic Programming` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 907 - Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/)

## Problem

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

### Example 1

```text
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
```

### Example 2

```text
Input: arr = [11,81,94,43,3]
Output: 444
```

## Constraints

- 1 <= arr.length <= 3 * 104
- 1 <= arr[i] <= 3 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sum of Total Strength of Wizards](https://leetcode.com/problems/sum-of-total-strength-of-wizards/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 907. Sum of Subarray Minimums

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Monotonic Stack - Contribution of Each Element | Java, JavaScript, Python3 |
| Monotonic Stack + Dynamic Programming | Java, JavaScript, Python3 |

## Approach 1: Monotonic Stack - Contribution of Each Element

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

class Solution {
    public int sumSubarrayMins(int[] arr) {
        int MOD = 1000000007;

        Stack<Integer> stack = new Stack<>();
        long sumOfMinimums = 0;

        // building monotonically increasing stack
        for (int i = 0; i <= arr.length; i++) {

            // when i reaches the array length, it is an indication that
            // all the elements have been processed, and the remaining
            // elements in the stack should now be popped out.

            while (!stack.empty() && (i == arr.length || arr[stack.peek()] >= arr[i])) {

                // Notice the sign ">=", This ensures that no contribution
                // is counted twice. rightBoundary takes equal or smaller 
                // elements into account while leftBoundary takes only the
                // strictly smaller elements into account

                int mid = stack.pop();
                int leftBoundary = stack.empty() ? -1 : stack.peek();
                int rightBoundary = i;

                // count of subarrays where mid is the minimum element
                long count = (mid - leftBoundary) * (rightBoundary - mid) % MOD;

                sumOfMinimums += (count * arr[mid]) % MOD;
                sumOfMinimums %= MOD;
            }
            stack.push(i);
        }

        return (int) (sumOfMinimums);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript

let sumSubarrayMins = function (arr) {
    const MOD = 1000000007;

    let stack = [];
    let sumOfMinimums = 0;

    for (let i = 0; i <= arr.length; i++) {

        // when i reaches the array length, it is an indication that
        // all the elements have been processed, and the remaining
        // elements in the stack should now be popped out.

        while (stack.length && (i == arr.length || arr[stack.at(-1)] >= arr[i])) {

            // Notice the sign ">=", This ensures that no contribution
            // is counted twice. rightBoundary takes equal or smaller 
            // elements into account while leftBoundary takes only the
            // strictly smaller elements into account

            const mid = stack.pop();
            const leftBoundary = stack.at(-1) === undefined ? -1 : stack.at(-1);
            const rightBoundary = i;

            // count of subarrays where mid is the minimum element
            const count = ((mid - leftBoundary) * (rightBoundary - mid)) % MOD;
            sumOfMinimums += (count * arr[mid]) % MOD;
            sumOfMinimums %= MOD;
        }
        stack.push(i);
    }
    
    return sumOfMinimums;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python

class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 10 ** 9 + 7
        stack = []
        sum_of_minimums = 0;

        for i in range(len(arr) + 1):
            
            # when i reaches the array length, it is an indication that
            # all the elements have been processed, and the remaining
            # elements in the stack should now be popped out.

            while stack and (i == len(arr) or arr[stack[-1]] >= arr[i]):

                # Notice the sign ">=", This ensures that no contribution
                # is counted twice. right_boundary takes equal or smaller 
                # elements into account while left_boundary takes only the
                # strictly smaller elements into account

                mid = stack.pop()
                left_boundary = -1 if not stack else stack[-1]
                right_boundary = i

                # count of subarrays where mid is the minimum element
                count = (mid - left_boundary) * (right_boundary - mid)
                sum_of_minimums += (count * arr[mid])

            stack.append(i)
        
        return sum_of_minimums % MOD
```

</details>

<br>

## Approach 2: Monotonic Stack + Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

class Solution {
    public int sumSubarrayMins(int[] arr) {
        int MOD = 1000000007;

        Stack<Integer> stack = new Stack<>();

        // make a dp array of the same size as the input array `arr`
        int[] dp = new int[arr.length];

        // making a monotonic increasing stack
        for (int i = 0; i < arr.length; i++) {
            // pop the stack until it is empty or
            // the top of the stack is greater than or equal to
            // the current element
            while (!stack.empty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }

            // either the previousSmaller element exists
            if (stack.size() > 0) {
                int previousSmaller = stack.peek();
                dp[i] = dp[previousSmaller] + (i - previousSmaller) * arr[i];
            } else {
                // or it doesn't exist, in this case the current element
                // contributes with all subarrays ending at i
                dp[i] = (i + 1) * arr[i];
            }
            // push the current index
            stack.push(i);
        }

        // Add all elements of the dp to get the answer
        long sumOfMinimums = 0;
        for (int count : dp) {
            sumOfMinimums += count;
            sumOfMinimums %= MOD;
        }

        return (int) sumOfMinimums;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript

let sumSubarrayMins = function (arr) {
    const MOD = 1000000007;
    // monotonic increasing stack
    let stack = [];
    // make a dp array of the same size as the input array `arr`
    let dp = new Array(arr.length).fill(0);

    // Making a monotonic increasing stack
    for (let i = 0; i < arr.length; i++) {
        // pop the stack until it is empty or
        // the top of the stack is greater than or equal to
        // the current element
        while (stack.length && arr[stack.at(-1)] >= arr[i]) {
            stack.pop();
        }

        // two cases, either the previousSmaller element exists
        if (stack.length) {
            const previousSmaller = stack.at(-1);
            dp[i] = dp[previousSmaller] + (i - previousSmaller) * arr[i];
        } else {
            // or it doesn't exist
            dp[i] = (i + 1) * arr[i];
        }
        stack.push(i);
    }

    // Add all elements of the dp to get the answer
    const sumOfMinimums = dp.reduce((a, b) => a + b, 0);

    return sumOfMinimums % MOD;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python

class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 10 ** 9 + 7

        # monotonic increasing stack
        stack = []

        # make a dp array of the same size as the input array
        dp = [0] * len(arr)

        # populate monotonically increasing stack
        for i in range(len(arr)):
            # before pushing an element, make sure all
            # larger and equal elements in the stack are
            # removed
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()

            # calculate the sum of minimums of all subarrays
            # ending at index i
            if stack:
                previousSmaller = stack[-1]
                dp[i] = dp[previousSmaller] + (i - previousSmaller) * arr[i]
            else:
                dp[i] = (i + 1) * arr[i]
            stack.append(i)

        # add all the elements of dp to get the answer
        return sum(dp) % MOD
```

</details>
