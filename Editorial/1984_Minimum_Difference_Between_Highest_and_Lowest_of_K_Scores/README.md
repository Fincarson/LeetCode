# 1984. Minimum Difference Between Highest and Lowest of K Scores

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/)  
`Array` `Sliding Window` `Sorting`

**Problem Link:** [LeetCode 1984 - Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/)

## Problem

You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.

Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.

Return the minimum possible difference.

### Example 1

```text
Input: nums = [90], k = 1
Output: 0
Explanation: There is one way to pick score(s) of one student:
- [90]. The difference between the highest and lowest score is 90 - 90 = 0.
The minimum possible difference is 0.
```

### Example 2

```text
Input: nums = [9,4,1,7], k = 2
Output: 2
Explanation: There are six ways to pick score(s) of two students:
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
- [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
The minimum possible difference is 2.
```

## Constraints

- 1 <= k <= nums.length <= 1000
- 0 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Array Partition](https://leetcode.com/problems/array-partition/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1984. Minimum Difference Between Highest and Lowest of K Scores

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmp(const void* pa, const void* pb) { return *(int*)pa - *(int*)pb; }

int minimumDifference(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = INT_MAX;
    for (int i = 0; i + k - 1 < numsSize; ++i) {
        ans = MIN(ans, nums[i + k - 1] - nums[i]);
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
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i + k - 1 < n; ++i) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
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
    public int MinimumDifference(int[] nums, int k) {
        int n = nums.Length;
        Array.Sort(nums);
        int ans = int.MaxValue;
        for (int i = 0; i + k - 1 < n; ++i) {
            ans = Math.Min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumDifference(nums []int, k int) int {
	sort.Ints(nums)
	ans := math.MaxInt32
	for i, num := range nums[:len(nums)-k+1] {
		ans = min(ans, nums[i+k-1]-num)
	}
	return ans
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDifference(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i + k - 1 < n; ++i) {
            ans = Math.min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumDifference = function (nums, k) {
    const n = nums.length;
    nums.sort((a, b) => a - b);
    let ans = Number.MAX_SAFE_INTEGER;
    for (let i = 0; i < n - k + 1; i++) {
        ans = Math.min(ans, nums[i + k - 1] - nums[i]);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min(nums[i + k - 1] - nums[i] for i in range(len(nums) - k + 1))
```

</details>
