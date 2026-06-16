# 3355. Zero Array Transformation I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/zero-array-transformation-i/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 3355 - Zero Array Transformation I](https://leetcode.com/problems/zero-array-transformation-i/)

## Problem

You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

- Select a subset of indices within the range [li, ri] in nums.
- Decrement the values at the selected indices by 1.

A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 105
- 1 <= queries.length <= 105
- queries[i].length == 2
- 0 <= li <= ri < nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Zero Array Transformation IV](https://leetcode.com/problems/zero-array-transformation-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3355. Zero Array Transformation I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Difference Array | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Difference Array

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize,
                 int* queriesColSize) {
    int* deltaArray = (int*)calloc(numsSize + 1, sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        deltaArray[left] += 1;
        deltaArray[right + 1] -= 1;
    }
    int* operationCounts = (int*)malloc((numsSize + 1) * sizeof(int));
    int currentOperations = 0;
    for (int i = 0; i < numsSize + 1; i++) {
        currentOperations += deltaArray[i];
        operationCounts[i] = currentOperations;
    }
    for (int i = 0; i < numsSize; i++) {
        if (operationCounts[i] < nums[i]) {
            free(deltaArray);
            free(operationCounts);
            return false;
        }
    }
    free(deltaArray);
    free(operationCounts);
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> deltaArray(nums.size() + 1, 0);
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            deltaArray[left] += 1;
            deltaArray[right + 1] -= 1;
        }
        vector<int> operationCounts;
        int currentOperations = 0;
        for (int delta : deltaArray) {
            currentOperations += delta;
            operationCounts.push_back(currentOperations);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (operationCounts[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsZeroArray(int[] nums, int[][] queries) {
        int[] deltaArray = new int[nums.Length + 1];
        foreach (int[] query in queries) {
            int left = query[0];
            int right = query[1];
            deltaArray[left] += 1;
            deltaArray[right + 1] -= 1;
        }
        int[] operationCounts = new int[deltaArray.Length];
        int currentOperations = 0;
        for (int i = 0; i < deltaArray.Length; i++) {
            currentOperations += deltaArray[i];
            operationCounts[i] = currentOperations;
        }
        for (int i = 0; i < nums.Length; i++) {
            if (operationCounts[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isZeroArray(nums []int, queries [][]int) bool {
	deltaArray := make([]int, len(nums)+1)
	for _, query := range queries {
		left := query[0]
		right := query[1]
		deltaArray[left] += 1
		deltaArray[right+1] -= 1
	}
	operationCounts := make([]int, len(deltaArray))
	currentOperations := 0
	for i, delta := range deltaArray {
		currentOperations += delta
		operationCounts[i] = currentOperations
	}
	for i := 0; i < len(nums); i++ {
		if operationCounts[i] < nums[i] {
			return false
		}
	}
	return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isZeroArray(int[] nums, int[][] queries) {
        int[] deltaArray = new int[nums.length + 1];
        for (int[] query : queries) {
            int left = query[0];
            int right = query[1];
            deltaArray[left] += 1;
            deltaArray[right + 1] -= 1;
        }
        int[] operationCounts = new int[deltaArray.length];
        int currentOperations = 0;
        for (int i = 0; i < deltaArray.length; i++) {
            currentOperations += deltaArray[i];
            operationCounts[i] = currentOperations;
        }
        for (int i = 0; i < nums.length; i++) {
            if (operationCounts[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isZeroArray = function (nums, queries) {
    const deltaArray = new Array(nums.length + 1).fill(0);
    for (const [left, right] of queries) {
        deltaArray[left] += 1;
        deltaArray[right + 1] -= 1;
    }
    const operationCounts = [];
    let currentOperations = 0;
    for (const delta of deltaArray) {
        currentOperations += delta;
        operationCounts.push(currentOperations);
    }
    for (let i = 0; i < nums.length; i++) {
        if (operationCounts[i] < nums[i]) {
            return false;
        }
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        deltaArray = [0] * (len(nums) + 1)
        for left, right in queries:
            deltaArray[left] += 1
            deltaArray[right + 1] -= 1
        operationCounts = []
        currentOperations = 0
        for delta in deltaArray:
            currentOperations += delta
            operationCounts.append(currentOperations)
        for operations, target in zip(operationCounts, nums):
            if operations < target:
                return False
        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isZeroArray(nums: number[], queries: number[][]): boolean {
    const deltaArray: number[] = new Array(nums.length + 1).fill(0);
    for (const [left, right] of queries) {
        deltaArray[left] += 1;
        deltaArray[right + 1] -= 1;
    }
    const operationCounts: number[] = [];
    let currentOperations = 0;
    for (const delta of deltaArray) {
        currentOperations += delta;
        operationCounts.push(currentOperations);
    }
    for (let i = 0; i < nums.length; i++) {
        if (operationCounts[i] < nums[i]) {
            return false;
        }
    }
    return true;
}
```

</details>
