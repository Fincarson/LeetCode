# 2176. Count Equal and Divisible Pairs in an Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/)  
`Array`

**Problem Link:** [LeetCode 2176 - Count Equal and Divisible Pairs in an Array](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/)

## Problem

### Example 1

```text
Input: nums = [3,1,2,2,2,1,3], k = 2
Output: 4
Explanation:
There are 4 pairs that meet all the requirements:
- nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
- nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
- nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
- nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
```

### Example 2

```text
Input: nums = [1,2,3,4], k = 1
Output: 0
Explanation: Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.
```

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i], k <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count Number of Bad Pairs](https://leetcode.com/problems/count-number-of-bad-pairs/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2176. Count Equal and Divisible Pairs in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Traverse number pairs | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Traverse number pairs

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countPairs(int* nums, int numsSize, int k) {
    int res = 0;  // number of pairs meeting the requirements
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if ((i * j) % k == 0 && nums[i] == nums[j]) {
                ++res;
            }
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
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;  // number of pairs meeting the requirements
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((i * j) % k == 0 && nums[i] == nums[j]) {
                    ++res;
                }
            }
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
    public int CountPairs(int[] nums, int k) {
        int n = nums.Length;
        int res = 0;  // number of pairs meeting the requirements
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((i * j) % k == 0 && nums[i] == nums[j]) {
                    ++res;
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countPairs(nums []int, k int) int {
	n := len(nums)
	res := 0 // number of pairs meeting the requirements
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			if (i*j)%k == 0 && nums[i] == nums[j] {
				res++
			}
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countPairs(int[] nums, int k) {
        int n = nums.length;
        int res = 0; // number of pairs meeting the requirements
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((i * j) % k == 0 && nums[i] == nums[j]) {
                    ++res;
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countPairs = function (nums, k) {
    let n = nums.length;
    let res = 0; // number of pairs meeting the requirements
    for (let i = 0; i < n - 1; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if ((i * j) % k === 0 && nums[i] === nums[j]) {
                ++res;
            }
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = 0  # number of pairs meeting the requirements
        for i in range(n - 1):
            for j in range(i + 1, n):
                if (i * j) % k == 0 and nums[i] == nums[j]:
                    res += 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countPairs(nums: number[], k: number): number {
    let n = nums.length;
    let res = 0; // number of pairs meeting the requirements
    for (let i = 0; i < n - 1; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if ((i * j) % k === 0 && nums[i] === nums[j]) {
                ++res;
            }
        }
    }
    return res;
}
```

</details>
