# 3432. Count Partitions with Even Sum Difference

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/count-partitions-with-even-sum-difference/)  
`Array` `Math` `Prefix Sum`

**Problem Link:** [LeetCode 3432 - Count Partitions with Even Sum Difference](https://leetcode.com/problems/count-partitions-with-even-sum-difference/)

## Problem

You are given an integer array nums of length n.

A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:

- Left subarray contains indices [0, i].
- Right subarray contains indices [i + 1, n - 1].

Return the number of partitions where the difference between the sum of the left and right subarrays is even.

### Example 1

### Example 2

### Example 3

## Constraints

- 2 <= n == nums.length <= 100
- 1 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3432. Count Partitions with Even Sum Difference

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countPartitions(int* nums, int numsSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; ++i) {
        totalSum += nums[i];
    }
    return totalSum % 2 == 0 ? numsSize - 1 : 0;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }
        return totalSum % 2 == 0 ? nums.size() - 1 : 0;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CountPartitions(int[] nums) {
        int totalSum = 0;
        foreach (int x in nums) {
            totalSum += x;
        }
        return totalSum % 2 == 0 ? nums.Length - 1 : 0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countPartitions(nums []int) int {
	totalSum := 0
	for _, x := range nums {
		totalSum += x
	}
	if totalSum%2 == 0 {
		return len(nums) - 1
	}
	return 0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countPartitions(int[] nums) {
        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }
        return totalSum % 2 == 0 ? nums.length - 1 : 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function countPartitions(nums) {
    const totalSum = nums.reduce((a, b) => a + b, 0);
    return totalSum % 2 === 0 ? nums.length - 1 : 0;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        totalSum = sum(nums)
        return len(nums) - 1 if totalSum % 2 == 0 else 0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countPartitions(nums: number[]): number {
    const totalSum = nums.reduce((a, b) => a + b, 0);
    return totalSum % 2 === 0 ? nums.length - 1 : 0;
}
```

</details>
