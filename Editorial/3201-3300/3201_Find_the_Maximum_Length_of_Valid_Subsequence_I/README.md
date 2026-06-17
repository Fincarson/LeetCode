# 3201. Find the Maximum Length of Valid Subsequence I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 3201 - Find the Maximum Length of Valid Subsequence I](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/)

## Problem

A subsequence sub of nums with length x is called valid if it satisfies:

- (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.

Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

### Example 1

### Example 2

### Example 3

## Constraints

- 2 <= nums.length <= 2 * 105
- 1 <= nums[i] <= 107

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Length of the Longest Subsequence That Sums to Target](https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3201. Find the Maximum Length of Valid Subsequence I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Parity of Enumeration Elements | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Parity of Enumeration Elements

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maximumLength(int* nums, int numsSize) {
    int res = 0;
    int patterns[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] % 2 == patterns[i][cnt % 2]) {
                cnt++;
            }
        }
        if (cnt > res) {
            res = cnt;
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
    int maximumLength(vector<int>& nums) {
        int res = 0;
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for (auto& pattern : patterns) {
            int cnt = 0;
            for (int num : nums) {
                if (num % 2 == pattern[cnt % 2]) {
                    cnt++;
                }
            }
            res = max(res, cnt);
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
    public int MaximumLength(int[] nums) {
        int res = 0;
        int[,] patterns =
            new int[4, 2] { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };
        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            foreach (int num in nums) {
                if (num % 2 == patterns[i, cnt % 2]) {
                    cnt++;
                }
            }
            res = Math.Max(res, cnt);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumLength(nums []int) int {
	res := 0
	patterns := [][]int{{0, 0}, {0, 1}, {1, 0}, {1, 1}}
	for _, pattern := range patterns {
		cnt := 0
		for _, num := range nums {
			if num%2 == pattern[cnt%2] {
				cnt++
			}
		}
		res = max(res, cnt)
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumLength(int[] nums) {
        int res = 0;
        int[][] patterns = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };
        for (int[] pattern : patterns) {
            int cnt = 0;
            for (int num : nums) {
                if (num % 2 == pattern[cnt % 2]) {
                    cnt++;
                }
            }
            res = Math.max(res, cnt);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumLength = function (nums) {
    let res = 0;
    const patterns = [
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1],
    ];
    for (const pattern of patterns) {
        let cnt = 0;
        for (const num of nums) {
            if (num % 2 === pattern[cnt % 2]) {
                cnt++;
            }
        }
        res = Math.max(res, cnt);
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        res = 0
        for pattern in [[0, 0], [0, 1], [1, 0], [1, 1]]:
            cnt = 0
            for num in nums:
                if num % 2 == pattern[cnt % 2]:
                    cnt += 1
            res = max(res, cnt)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumLength(nums: number[]): number {
    let res = 0;
    const patterns = [
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1],
    ] as const;
    for (const pattern of patterns) {
        let cnt = 0;
        for (const num of nums) {
            if (num % 2 === pattern[cnt % 2]) {
                cnt++;
            }
        }
        res = Math.max(res, cnt);
    }
    return res;
}
```

</details>
