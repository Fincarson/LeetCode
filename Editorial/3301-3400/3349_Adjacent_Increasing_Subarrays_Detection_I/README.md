# 3349. Adjacent Increasing Subarrays Detection I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/)  
`Array`

**Problem Link:** [LeetCode 3349 - Adjacent Increasing Subarrays Detection I](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/)

## Problem

Given an array nums of n integers and an integer k, determine whether there exist two adjacent subarrays of length k such that both subarrays are strictly increasing. Specifically, check if there are two subarrays starting at indices a and b (a < b), where:

- Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
- The subarrays must be adjacent, meaning b = a + k.

Return true if it is possible to find two such subarrays, and false otherwise.

### Example 1

### Example 2

## Constraints

- 2 <= nums.length <= 100
- 1 < 2 * k <= nums.length
- -1000 <= nums[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3349. Adjacent Increasing Subarrays Detection I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: One-time Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: One-time Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    int cnt = 1, precnt = 0, ans = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > nums[i - 1]) {
            ++cnt;
        } else {
            precnt = cnt;
            cnt = 1;
        }
        ans = fmax(ans, fmin(precnt, cnt));
        ans = fmax(ans, cnt / 2);
    }
    return ans >= k;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1, precnt = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = max(ans, min(precnt, cnt));
            ans = max(ans, cnt / 2);
        }
        return ans >= k;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool HasIncreasingSubarrays(IList<int> nums, int k) {
        int n = nums.Count;
        int cnt = 1, precnt = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = Math.Max(ans, Math.Min(precnt, cnt));
            ans = Math.Max(ans, cnt / 2);
        }
        return ans >= k;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func hasIncreasingSubarrays(nums []int, k int) bool {
	n := len(nums)
	cnt, precnt, ans := 1, 0, 0
	for i := 1; i < n; i++ {
		if nums[i] > nums[i-1] {
			cnt++
		} else {
			precnt = cnt
			cnt = 1
		}
		ans = max(ans, min(precnt, cnt))
		ans = max(ans, cnt/2)
	}
	return ans >= k
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();
        int cnt = 1;
        int precnt = 0;
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            if (nums.get(i) > nums.get(i - 1)) {
                ++cnt;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = Math.max(ans, Math.min(precnt, cnt));
            ans = Math.max(ans, cnt / 2);
        }

        return ans >= k;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var hasIncreasingSubarrays = function (nums, k) {
    const n = nums.length;
    let cnt = 1,
        precnt = 0,
        ans = 0;
    for (let i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            ++cnt;
        } else {
            precnt = cnt;
            cnt = 1;
        }
        ans = Math.max(ans, Math.min(precnt, cnt));
        ans = Math.max(ans, Math.floor(cnt / 2));
    }
    return ans >= k;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        cnt, precnt, ans = 1, 0, 0
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                cnt += 1
            else:
                precnt, cnt = cnt, 1
            ans = max(ans, min(precnt, cnt))
            ans = max(ans, cnt // 2)
        return ans >= k
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function hasIncreasingSubarrays(nums: number[], k: number): boolean {
    const n = nums.length;
    let cnt = 1,
        precnt = 0,
        ans = 0;
    for (let i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            ++cnt;
        } else {
            precnt = cnt;
            cnt = 1;
        }
        ans = Math.max(ans, Math.min(precnt, cnt));
        ans = Math.max(ans, Math.floor(cnt / 2));
    }
    return ans >= k;
}
```

</details>
