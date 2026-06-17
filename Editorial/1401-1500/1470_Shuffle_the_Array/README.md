# 1470. Shuffle the Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/shuffle-the-array/)  
`Array`

**Problem Link:** [LeetCode 1470 - Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/)

## Problem

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

### Example 1

```text
Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7]
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
```

### Example 2

```text
Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
```

### Example 3

```text
Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]
```

## Constraints

- 1 <= n <= 500
- nums.length == 2n
- 1 <= nums[i] <= 10^3

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1470. Shuffle the Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simple Iteration | C++, Java, JavaScript, Python3 |
| In-place Filling | C++, Java, JavaScript, Python3 |

## Approach 1: Simple Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2 * n);
        for (int i = 0; i < n; ++i) {
            result[2 * i] = nums[i];
            result[2 * i + 1] = nums[n + i];
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
    public int[] shuffle(int[] nums, int n) {
        int[] result = new int[2 * n];
        for (int i = 0; i < n; ++i) {
            result[2 * i] = nums[i];
            result[2 * i + 1] = nums[n + i];
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var shuffle = function(nums, n) {
    let result = Array(2 * n);
    for (let i = 0; i < n; ++i) {
        result[2 * i] = nums[i];
        result[2 * i + 1] = nums[n + i];
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        result = [0] * (2 * n)
        for i in range(n):
            result[2 * i] = nums[i]
            result[2 * i + 1] = nums[n + i]
        return result
```

</details>

<br>

## Approach 2: In-place Filling

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // Store each y(i) with respective x(i).
        for (int i = n; i < 2 * n; ++i) {
            int secondNum = nums[i] << 10;
            nums[i - n] |= secondNum;
        }

        // '0000000000 1111111111' in decimal.
        int allOnes = pow(2, 10) - 1;

        // We will start putting all numbers from the end, 
        // as they are empty places.
        for (int i = n - 1; i >= 0; --i) {
            // Fetch both the numbers from the current index.
            int secondNum = nums[i] >> 10;
            int firstNum = nums[i] & allOnes;
            nums[2 * i + 1] = secondNum;
            nums[2 * i] = firstNum;
        }
        return nums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] shuffle(int[] nums, int n) {
        // Store each y(i) with respective x(i).
        for (int i = n; i < 2 * n; ++i) {
            int secondNum = nums[i] << 10;
            nums[i - n] |= secondNum;
        }

        // '0000000000 1111111111' in decimal.
        int allOnes = (int) Math.pow(2, 10) - 1;

        // We will start putting all numbers from the end, 
        // as they are empty places.
        for (int i = n - 1; i >= 0; --i) {
            // Fetch both the numbers from the current index.
            int secondNum = nums[i] >> 10;
            int firstNum = nums[i] & allOnes;
            nums[2 * i + 1] = secondNum;
            nums[2 * i] = firstNum;
        }
        return nums;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var shuffle = function(nums, n) {
    // Store each y(i) with respective x(i).
    for (let i = n; i < 2 * n; ++i) {
        let secondNum = nums[i] << 10;
        nums[i - n] |= secondNum;
    }

    // '0000000000 1111111111' in decimal.
    let allOnes = Number(Math.pow(2, 10)) - 1;

    // We will start putting all numbers from the end, 
    // as they are empty places.
    for (let i = n - 1; i >= 0; --i) {
        // Fetch both the numbers from the current index.
        let secondNum = nums[i] >> 10;
        let firstNum = nums[i] & allOnes;
        nums[2 * i + 1] = secondNum;
        nums[2 * i] = firstNum;
    }
    return nums;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        # Store each y(i) with respective x(i).
        for i in range(n, 2 * n):
            secondNum = nums[i] << 10
            nums[i - n] |= secondNum

        # '0000000000 1111111111' in decimal.
        allOnes = int(pow(2, 10)) - 1

        # We will start putting all numbers from the end, 
        # as they are empty places.
        for i in range(n - 1, -1, -1):
            # Fetch both the numbers from the current index.
            secondNum = nums[i] >> 10
            firstNum = nums[i] & allOnes
            nums[2 * i + 1] = secondNum
            nums[2 * i] = firstNum
        return nums
```

</details>
