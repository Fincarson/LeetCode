# 3379. Transformed Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/transformed-array/)  
`Array` `Simulation`

**Problem Link:** [LeetCode 3379 - Transformed Array](https://leetcode.com/problems/transformed-array/)

## Problem

You are given an integer array nums that represents a circular array. Your task is to create a new array result of the same size, following these rules:

- If nums[i] > 0: Start at index i and move nums[i] steps to the right in the circular array. Set result[i] to the value at the index where you land.
- If nums[i] < 0: Start at index i and move abs(nums[i]) steps to the left in the circular array. Set result[i] to the value at the index where you land.
- If nums[i] == 0: Set result[i] to nums[i].

Return the new array result.

Note: Since nums is circular, moving past the last element wraps around to the beginning, and moving before the first element wraps back to the end.

### Example 1

### Example 2

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

# Editorial - 3379. Transformed Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        res[i] = nums[((i + nums[i]) % numsSize + numsSize) % numsSize];
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
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nums[((i + nums[i]) % n + n) % n];
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
    public int[] ConstructTransformedArray(int[] nums) {
        int n = nums.Length;
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nums[((i + nums[i]) % n + n) % n];
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func constructTransformedArray(nums []int) []int {
	n := len(nums)
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = nums[((i+nums[i])%n+n)%n]
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nums[(((i + nums[i]) % n) + n) % n];
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var constructTransformedArray = function (nums) {
    const n = nums.length;
    const res = new Array(n);
    for (let i = 0; i < n; i++) {
        res[i] = nums[(((i + nums[i]) % n) + n) % n];
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def constructTransformedArray(self, nums):
        n = len(nums)
        return [nums[((i + nums[i]) % n + n) % n] for i in range(n)]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function constructTransformedArray(nums: number[]): number[] {
    const n = nums.length;
    const res: number[] = new Array(n);
    for (let i = 0; i < n; i++) {
        res[i] = nums[(((i + nums[i]) % n) + n) % n];
    }
    return res;
}
```

</details>
