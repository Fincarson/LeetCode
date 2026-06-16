# 3740. Minimum Distance Between Three Equal Elements I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 3740 - Minimum Distance Between Three Equal Elements I](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/)

## Problem

You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n == nums.length <= 100
- 1 <= nums[i] <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3740. Minimum Distance Between Three Equal Elements I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumDistance(int* nums, int numsSize) {
    int ans = numsSize + 1;

    for (int i = 0; i < numsSize - 2; i++) {
        for (int j = i + 1; j < numsSize - 1; j++) {
            if (nums[i] != nums[j]) {
                continue;
            }
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[j] == nums[k]) {
                    if (k - i < ans) {
                        ans = k - i;
                    }
                    break;
                }
            }
        }
    }

    return ans == numsSize + 1 ? -1 : ans * 2;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[i] != nums[j]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[j] == nums[k]) {
                        ans = std::min(ans, k - i);
                        break;
                    }
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumDistance(int[] nums) {
        int n = nums.Length;
        int ans = n + 1;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[i] != nums[j]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[j] == nums[k]) {
                        ans = Math.Min(ans, k - i);
                        break;
                    }
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumDistance(nums []int) int {
	n := len(nums)
	ans := n + 1

	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			if nums[i] != nums[j] {
				continue
			}
			for k := j + 1; k < n; k++ {
				if nums[j] == nums[k] {
					if dist := k - i; dist < ans {
						ans = dist
					}
					break
				}
			}
		}
	}

	if ans == n+1 {
		return -1
	}
	return ans * 2
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDistance(int[] nums) {
        int n = nums.length;
        int ans = n + 1;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[i] != nums[j]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[j] == nums[k]) {
                        ans = Math.min(ans, k - i);
                        break;
                    }
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumDistance = function (nums) {
    let ans = nums.length + 1;

    for (let i = 0; i < nums.length - 2; i++) {
        for (let j = i + 1; j < nums.length - 1; j++) {
            if (nums[i] !== nums[j]) {
                continue;
            }
            for (let k = j + 1; k < nums.length; k++) {
                if (nums[j] === nums[k]) {
                    ans = Math.min(ans, k - i);
                    break;
                }
            }
        }
    }

    if (ans === nums.length + 1) {
        return -1;
    } else {
        return ans * 2;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)
        ans = n + 1

        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                if nums[i] != nums[j]:
                    continue
                for k in range(j + 1, n):
                    if nums[j] == nums[k]:
                        ans = min(ans, k - i)
                        break

        return -1 if ans == n + 1 else ans * 2
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumDistance(nums: number[]): number {
    let ans = nums.length + 1;
    for (let i = 0; i < nums.length - 2; i++) {
        for (let j = i + 1; j < nums.length - 1; j++) {
            if (nums[i] !== nums[j]) {
                continue;
            }
            for (let k = j + 1; k < nums.length; k++) {
                if (nums[j] === nums[k]) {
                    ans = Math.min(ans, k - i);
                    break;
                }
            }
        }
    }

    if (ans === nums.length + 1) {
        return -1;
    } else {
        return ans * 2;
    }
}
```

</details>
