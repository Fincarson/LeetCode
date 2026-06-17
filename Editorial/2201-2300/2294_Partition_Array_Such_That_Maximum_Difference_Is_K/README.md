# 2294. Partition Array Such That Maximum Difference Is K

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 2294 - Partition Array Such That Maximum Difference Is K](https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/)

## Problem

You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.

Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

### Example 1

```text
Input: nums = [3,6,1,2,5], k = 2
Output: 2
Explanation:
We can partition nums into the two subsequences [3,1,2] and [6,5].
The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.
```

### Example 2

```text
Input: nums = [1,2,3], k = 1
Output: 2
Explanation:
We can partition nums into the two subsequences [1,2] and [3].
The difference between the maximum and minimum value in the first subsequence is 2 - 1 = 1.
The difference between the maximum and minimum value in the second subsequence is 3 - 3 = 0.
Since two subsequences were created, we return 2. Note that another optimal solution is to partition nums into the two subsequences [1] and [2,3].
```

### Example 3

```text
Input: nums = [2,2,4,5], k = 0
Output: 3
Explanation:
We can partition nums into the three subsequences [2,2], [4], and [5].
The difference between the maximum and minimum value in the first subsequences is 2 - 2 = 0.
The difference between the maximum and minimum value in the second subsequences is 4 - 4 = 0.
The difference between the maximum and minimum value in the third subsequences is 5 - 5 = 0.
Since three subsequences were created, we return 3. It can be shown that 3 is the minimum number of subsequences needed.
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 105
- 0 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Beauty of an Array After Applying Operation](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2294. Partition Array Such That Maximum Difference Is K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sort + Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Sort + Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int partitionArray(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 1;
    int rec = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] - rec > k) {
            ans++;
            rec = nums[i];
        }
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
    int partitionArray(vector<int>& nums, int k) {
        ranges::sort(nums);
        int ans = 1;
        int rec = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - rec > k) {
                ans++;
                rec = nums[i];
            }
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
    public int PartitionArray(int[] nums, int k) {
        Array.Sort(nums);
        int ans = 1;
        int rec = nums[0];
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] - rec > k) {
                ans++;
                rec = nums[i];
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func partitionArray(nums []int, k int) int {
	sort.Ints(nums)
	ans := 1
	rec := nums[0]
	for _, num := range nums {
		if num-rec > k {
			ans++
			rec = num
		}
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 1;
        int rec = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] - rec > k) {
                ans++;
                rec = nums[i];
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
var partitionArray = function (nums, k) {
    nums.sort((a, b) => a - b);
    let ans = 1;
    let rec = nums[0];
    for (let num of nums) {
        if (num - rec > k) {
            ans++;
            rec = num;
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
    def partitionArray(self, nums: list[int], k: int) -> int:
        nums.sort()
        ans = 1
        rec = nums[0]
        for num in nums:
            if num - rec > k:
                ans += 1
                rec = num
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function partitionArray(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = 1;
    let rec = nums[0];
    for (let num of nums) {
        if (num - rec > k) {
            ans++;
            rec = num;
        }
    }
    return ans;
}
```

</details>
