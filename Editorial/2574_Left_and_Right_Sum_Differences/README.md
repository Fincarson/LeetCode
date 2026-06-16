# 2574. Left and Right Sum Differences

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/left-and-right-sum-differences/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 2574 - Left and Right Sum Differences](https://leetcode.com/problems/left-and-right-sum-differences/)

## Problem

You are given a 0-indexed integer array nums of size n.

Define two arrays leftSum and rightSum where:

- leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
- rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.

Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.

### Example 1

```text
Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
```

### Example 2

```text
Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the Distinct Difference Array](https://leetcode.com/problems/find-the-distinct-difference-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the N-th Value After K Seconds](https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2574. Left and Right Sum Differences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Prefix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ans = (int*)malloc(numsSize * sizeof(int));

    int leftSum = 0;
    for (int i = 0; i < numsSize; ++i) {
        ans[i] = leftSum;
        leftSum += nums[i];
    }

    int rightSum = 0;
    for (int i = numsSize - 1; i >= 0; --i) {
        ans[i] = abs(ans[i] - rightSum);
        rightSum += nums[i];
    }

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }

        int rightSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = abs(ans[i] - rightSum);
            rightSum += nums[i];
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] LeftRightDifference(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];

        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }

        int rightSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = Math.Abs(ans[i] - rightSum);
            rightSum += nums[i];
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func leftRightDifference(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)

	leftSum := 0
	for i := 0; i < n; i++ {
		ans[i] = leftSum
		leftSum += nums[i]
	}

	rightSum := 0
	for i := n - 1; i >= 0; i-- {
		ans[i] = abs(ans[i] - rightSum)
		rightSum += nums[i]
	}

	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] leftRightDifference(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];

        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }

        int rightSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = Math.abs(ans[i] - rightSum);
            rightSum += nums[i];
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var leftRightDifference = function (nums) {
    const n = nums.length;
    const ans = new Array(n);

    let leftSum = 0;
    for (let i = 0; i < n; ++i) {
        ans[i] = leftSum;
        leftSum += nums[i];
    }

    let rightSum = 0;
    for (let i = n - 1; i >= 0; --i) {
        ans[i] = Math.abs(ans[i] - rightSum);
        rightSum += nums[i];
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n

        left_sum = 0
        for i in range(n):
            ans[i] = left_sum
            left_sum += nums[i]

        right_sum = 0
        for i in range(n - 1, -1, -1):
            ans[i] = abs(ans[i] - right_sum)
            right_sum += nums[i]

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function leftRightDifference(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = new Array(n);

    let leftSum = 0;
    for (let i = 0; i < n; ++i) {
        ans[i] = leftSum;
        leftSum += nums[i];
    }

    let rightSum = 0;
    for (let i = n - 1; i >= 0; --i) {
        ans[i] = Math.abs(ans[i] - rightSum);
        rightSum += nums[i];
    }

    return ans;
}
```

</details>
