# 2873. Maximum Value of an Ordered Triplet I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/)  
`Array`

**Problem Link:** [LeetCode 2873 - Maximum Value of an Ordered Triplet I](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/)

## Problem

You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

### Example 1

```text
Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77.
```

### Example 2

```text
Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
```

### Example 3

```text
Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
```

## Constraints

- 3 <= nums.length <= 100
- 1 <= nums[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Arithmetic Triplets](https://leetcode.com/problems/number-of-arithmetic-triplets/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Sum of Mountain Triplets I](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2873. Maximum Value of an Ordered Triplet I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute-force enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Greedy + Prefix Suffix Array | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute-force enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long maximumTripletValue(int* nums, int numsSize) {
    long long res = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                long long value = (long long)(nums[i] - nums[j]) * nums[k];
                if (value > res) {
                    res = value;
                }
            }
        }
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    res = max(res, (long long)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MaximumTripletValue(int[] nums) {
        int n = nums.Length;
        long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    res = Math.Max(res, (long)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumTripletValue(nums []int) int64 {
	n := len(nums)
	var res int64 = 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				res = max(res, int64(nums[i]-nums[j])*int64(nums[k]))
			}
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    res = Math.max(res, (long) (nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumTripletValue = function (nums) {
    let n = nums.length;
    let res = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            for (let k = j + 1; k < n; k++) {
                res = Math.max(res, (nums[i] - nums[j]) * nums[k]);
            }
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    res = max(res, (nums[i] - nums[j]) * nums[k])
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumTripletValue(nums: number[]): number {
    const n = nums.length;
    let res = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            for (let k = j + 1; k < n; k++) {
                res = Math.max(res, (nums[i] - nums[j]) * nums[k]);
            }
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long maximumTripletValue(int* nums, int numsSize) {
    long long res = 0;
    for (int k = 2; k < numsSize; k++) {
        int maxPrefix = nums[0];
        for (int j = 1; j < k; j++) {
            long long value = (long long)(maxPrefix - nums[j]) * nums[k];
            if (value > res) {
                res = value;
            }
            if (nums[j] > maxPrefix) {
                maxPrefix = nums[j];
            }
        }
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for (int k = 2; k < n; k++) {
            int maxPrefix = nums[0];
            for (int j = 1; j < k; j++) {
                res = max(res, (long long)(maxPrefix - nums[j]) * nums[k]);
                maxPrefix = max(maxPrefix, nums[j]);
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MaximumTripletValue(int[] nums) {
        int n = nums.Length;
        long res = 0;
        for (int k = 2; k < n; k++) {
            int maxPrefix = nums[0];
            for (int j = 1; j < k; j++) {
                res = Math.Max(res, (long)(maxPrefix - nums[j]) * nums[k]);
                maxPrefix = Math.Max(maxPrefix, nums[j]);
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumTripletValue(nums []int) int64 {
	n := len(nums)
	var res int64 = 0
	for k := 2; k < n; k++ {
		maxPrefix := nums[0]
		for j := 1; j < k; j++ {
			res = max(res, int64(maxPrefix-nums[j])*int64(nums[k]))
			maxPrefix = max(maxPrefix, nums[j])
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long res = 0;
        for (int k = 2; k < n; k++) {
            int maxPrefix = nums[0];
            for (int j = 1; j < k; j++) {
                res = Math.max(res, (long) (maxPrefix - nums[j]) * nums[k]);
                maxPrefix = Math.max(maxPrefix, nums[j]);
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumTripletValue = function (nums) {
    let n = nums.length;
    let res = 0;
    for (let k = 2; k < n; k++) {
        let maxPrefix = nums[0];
        for (let j = 1; j < k; j++) {
            res = Math.max(res, (maxPrefix - nums[j]) * nums[k]);
            maxPrefix = Math.max(maxPrefix, nums[j]);
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for k in range(2, n):
            maxPrefix = nums[0]
            for j in range(1, k):
                res = max(res, (maxPrefix - nums[j]) * nums[k])
                maxPrefix = max(maxPrefix, nums[j])
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumTripletValue(nums: number[]): number {
    const n = nums.length;
    let res = 0;
    for (let k = 2; k < n; k++) {
        let maxPrefix = nums[0];
        for (let j = 1; j < k; j++) {
            res = Math.max(res, (maxPrefix - nums[j]) * nums[k]);
            maxPrefix = Math.max(maxPrefix, nums[j]);
        }
    }
    return res;
}
```

</details>

<br>

## Approach 3: Greedy + Prefix Suffix Array

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long maximumTripletValue(int *nums, int numsSize) {
    int leftMax[numsSize], rightMax[numsSize];
    leftMax[0] = 0;
    rightMax[numsSize - 1] = 0;
    for (int i = 1; i < numsSize; i++) {
        leftMax[i] = fmax(leftMax[i - 1], nums[i - 1]);
        rightMax[numsSize - 1 - i] =
            fmax(rightMax[numsSize - i], nums[numsSize - i]);
    }
    long long res = 0;
    for (int j = 1; j < numsSize - 1; j++) {
        long long temp = (long long)(leftMax[j] - nums[j]) * rightMax[j];
        res = fmax(res, temp);
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
        }
        long long res = 0;
        for (int j = 1; j < n - 1; j++) {
            res = max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MaximumTripletValue(int[] nums) {
        int n = nums.Length;
        int[] leftMax = new int[n];
        int[] rightMax = new int[n];
        for (int i = 1; i < n; i++) {
            leftMax[i] = Math.Max(leftMax[i - 1], nums[i - 1]);
            rightMax[n - 1 - i] = Math.Max(rightMax[n - i], nums[n - i]);
        }
        long res = 0;
        for (int j = 1; j < n - 1; j++) {
            res = Math.Max(res, (long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumTripletValue(nums []int) int64 {
	n := len(nums)
	leftMax := make([]int, n)
	rightMax := make([]int, n)
	for i := 1; i < n; i++ {
		leftMax[i] = max(leftMax[i-1], nums[i-1])
		rightMax[n-1-i] = max(rightMax[n-i], nums[n-i])
	}
	var res int64 = 0
	for j := 1; j < n-1; j++ {
		res = max(res, int64((leftMax[j]-nums[j])*rightMax[j]))
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        int[] leftMax = new int[n];
        int[] rightMax = new int[n];
        for (int i = 1; i < n; i++) {
            leftMax[i] = Math.max(leftMax[i - 1], nums[i - 1]);
            rightMax[n - 1 - i] = Math.max(rightMax[n - i], nums[n - i]);
        }
        long res = 0;
        for (int j = 1; j < n - 1; j++) {
            res = Math.max(res, (long) (leftMax[j] - nums[j]) * rightMax[j]);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumTripletValue = function (nums) {
    const n = nums.length;
    const leftMax = new Array(n).fill(0);
    const rightMax = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        leftMax[i] = Math.max(leftMax[i - 1], nums[i - 1]);
        rightMax[n - 1 - i] = Math.max(rightMax[n - i], nums[n - i]);
    }
    let res = 0;
    for (let j = 1; j < n - 1; j++) {
        res = Math.max(res, (leftMax[j] - nums[j]) * rightMax[j]);
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        leftMax = [0] * n
        rightMax = [0] * n
        for i in range(1, n):
            leftMax[i] = max(leftMax[i - 1], nums[i - 1])
            rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i])
        res = 0
        for j in range(1, n - 1):
            res = max(res, (leftMax[j] - nums[j]) * rightMax[j])
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumTripletValue(nums: number[]): number {
    const n = nums.length;
    const leftMax: number[] = new Array(n).fill(0);
    const rightMax: number[] = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        leftMax[i] = Math.max(leftMax[i - 1], nums[i - 1]);
        rightMax[n - 1 - i] = Math.max(rightMax[n - i], nums[n - i]);
    }
    let res = 0;
    for (let j = 1; j < n - 1; j++) {
        res = Math.max(res, (leftMax[j] - nums[j]) * rightMax[j]);
    }
    return res;
}
```

</details>

<br>

## Approach 4: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long maximumTripletValue(int* nums, int numsSize) {
    long long res = 0, imax = 0, dmax = 0;
    for (int k = 0; k < numsSize; k++) {
        res = fmax(res, dmax * nums[k]);
        dmax = fmax(dmax, imax - nums[k]);
        imax = fmax(imax, nums[k]);
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++) {
            res = max(res, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, static_cast<long long>(nums[k]));
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MaximumTripletValue(int[] nums) {
        int n = nums.Length;
        long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++) {
            res = Math.Max(res, dmax * nums[k]);
            dmax = Math.Max(dmax, imax - nums[k]);
            imax = Math.Max(imax, nums[k]);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumTripletValue(nums []int) int64 {
	n := len(nums)
	var res, imax, dmax int64 = 0, 0, 0
	for k := 0; k < n; k++ {
		res = max(res, dmax*int64(nums[k]))
		dmax = max(dmax, imax-int64(nums[k]))
		imax = max(imax, int64(nums[k]))
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++) {
            res = Math.max(res, dmax * nums[k]);
            dmax = Math.max(dmax, imax - nums[k]);
            imax = Math.max(imax, nums[k]);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumTripletValue = function (nums) {
    const n = nums.length;
    let res = 0,
        imax = 0,
        dmax = 0;
    for (let k = 0; k < n; k++) {
        res = Math.max(res, dmax * nums[k]);
        dmax = Math.max(dmax, imax - nums[k]);
        imax = Math.max(imax, nums[k]);
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        res, imax, dmax = 0, 0, 0
        for k in range(n):
            res = max(res, dmax * nums[k])
            dmax = max(dmax, imax - nums[k])
            imax = max(imax, nums[k])
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumTripletValue(nums: number[]): number {
    const n: number = nums.length;
    let res: number = 0,
        imax: number = 0,
        dmax: number = 0;
    for (let k = 0; k < n; k++) {
        res = Math.max(res, dmax * nums[k]);
        dmax = Math.max(dmax, imax - nums[k]);
        imax = Math.max(imax, nums[k]);
    }
    return res;
}
```

</details>
