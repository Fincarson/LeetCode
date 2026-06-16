# 3397. Maximum Number of Distinct Elements After Operations

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 3397 - Maximum Number of Distinct Elements After Operations](https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/)

## Problem

You are given an integer array nums and an integer k.

You are allowed to perform the following operation on each element of the array at most once:

- Add an integer in the range [-k, k] to the element.

Return the maximum possible number of distinct elements in nums after performing the operations.

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 0 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Least Number of Unique Integers after K Removals](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3397. Maximum Number of Distinct Elements After Operations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int maxDistinctElements(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int cnt = 0;
    int prev = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int curr = fmin(fmax(num - k, prev + 1), num + k);
        if (curr > prev) {
            cnt++;
            prev = curr;
        }
    }
    return cnt;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0, prev = INT_MIN;
        for (int num : nums) {
            int curr = min(max(num - k, prev + 1), num + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxDistinctElements(int[] nums, int k) {
        Array.Sort(nums);
        int cnt = 0;
        int prev = int.MinValue;
        foreach (int num in nums) {
            int curr = Math.Min(Math.Max(num - k, prev + 1), num + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDistinctElements(nums []int, k int) int {
	sort.Ints(nums)
	cnt := 0
	prev := math.MinInt32

	for _, num := range nums {
		curr := min(max(num-k, prev+1), num+k)
		if curr > prev {
			cnt++
			prev = curr
		}
	}
	return cnt
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxDistinctElements(int[] nums, int k) {
        Arrays.sort(nums);
        int cnt = 0;
        int prev = Integer.MIN_VALUE;
        for (int num : nums) {
            int curr = Math.min(Math.max(num - k, prev + 1), num + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDistinctElements = function (nums, k) {
    nums.sort((a, b) => a - b);
    let cnt = 0;
    let prev = -Number.MAX_SAFE_INTEGER;

    for (const num of nums) {
        const curr = Math.min(Math.max(num - k, prev + 1), num + k);
        if (curr > prev) {
            cnt++;
            prev = curr;
        }
    }
    return cnt;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()

        cnt = 0
        prev = -math.inf

        for num in nums:
            curr = min(max(num - k, prev + 1), num + k)
            if curr > prev:
                cnt += 1
                prev = curr

        return cnt
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDistinctElements(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let cnt = 0;
    let prev = -Number.MAX_SAFE_INTEGER;

    for (const num of nums) {
        const curr = Math.min(Math.max(num - k, prev + 1), num + k);
        if (curr > prev) {
            cnt++;
            prev = curr;
        }
    }
    return cnt;
}
```

</details>
