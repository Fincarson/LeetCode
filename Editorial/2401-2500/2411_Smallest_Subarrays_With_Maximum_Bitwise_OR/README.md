# 2411. Smallest Subarrays With Maximum Bitwise OR

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/)  
`Array` `Binary Search` `Bit Manipulation` `Sliding Window`

**Problem Link:** [LeetCode 2411 - Smallest Subarrays With Maximum Bitwise OR](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/)

## Problem

You are given a 0-indexed array nums of length n, consisting of non-negative integers. For each index i from 0 to n - 1, you must determine the size of the minimum sized non-empty subarray of nums starting at i (inclusive) that has the maximum possible bitwise OR.

- In other words, let Bij be the bitwise OR of the subarray nums[i...j]. You need to find the smallest subarray starting at i, such that bitwise OR of this subarray is equal to max(Bik) where i <= k <= n - 1.

The bitwise OR of an array is the bitwise OR of all the numbers in it.

Return an integer array answer of size n where answer[i] is the length of the minimum sized subarray starting at i with maximum bitwise OR.

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

```text
Input: nums = [1,0,2,1,3]
Output: [3,3,2,2,1]
Explanation:
The maximum possible bitwise OR starting at any index is 3.
- Starting at index 0, the shortest subarray that yields it is [1,0,2].
- Starting at index 1, the shortest subarray that yields the maximum bitwise OR is [0,2,1].
- Starting at index 2, the shortest subarray that yields the maximum bitwise OR is [2,1].
- Starting at index 3, the shortest subarray that yields the maximum bitwise OR is [1,3].
- Starting at index 4, the shortest subarray that yields the maximum bitwise OR is [3].
Therefore, we return [3,3,2,2,1].
```

### Example 2

```text
Input: nums = [1,2]
Output: [2,1]
Explanation:
Starting at index 0, the shortest subarray that yields the maximum bitwise OR is of length 2.
Starting at index 1, the shortest subarray that yields the maximum bitwise OR is of length 1.
Therefore, we return [2,1].
```

## Constraints

- n == nums.length
- 1 <= n <= 105
- 0 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Bitwise ORs of Subarrays](https://leetcode.com/problems/bitwise-ors-of-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Subarray With Maximum Bitwise AND](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2411. Smallest Subarrays With Maximum Bitwise OR

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* smallestSubarrays(int* nums, int numsSize, int* returnSize) {
    int* pos = (int*)malloc(31 * sizeof(int));
    memset(pos, -1, 31 * sizeof(int));
    int* ans = (int*)malloc(numsSize * sizeof(int));
    for (int i = numsSize - 1; i >= 0; --i) {
        int j = i;
        for (int bit = 0; bit < 31; ++bit) {
            if (!(nums[i] & (1 << bit))) {
                if (pos[bit] != -1) {
                    j = fmax(j, pos[bit]);
                }
            } else {
                pos[bit] = i;
            }
        }
        ans[i] = j - i + 1;
    }
    free(pos);
    *returnSize = numsSize;
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(31, -1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            int j = i;
            for (int bit = 0; bit < 31; ++bit) {
                if (!(nums[i] & (1 << bit))) {
                    if (pos[bit] != -1) {
                        j = max(j, pos[bit]);
                    }
                } else {
                    pos[bit] = i;
                }
            }
            ans[i] = j - i + 1;
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
    public int[] SmallestSubarrays(int[] nums) {
        int n = nums.Length;
        int[] pos = new int[31];
        Array.Fill(pos, -1);
        int[] ans = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            int j = i;
            for (int bit = 0; bit < 31; ++bit) {
                if ((nums[i] & (1 << bit)) == 0) {
                    if (pos[bit] != -1) {
                        j = Math.Max(j, pos[bit]);
                    }
                } else {
                    pos[bit] = i;
                }
            }
            ans[i] = j - i + 1;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func smallestSubarrays(nums []int) []int {
	n := len(nums)
	pos := make([]int, 31)
	for i := range pos {
		pos[i] = -1
	}
	ans := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		j := i
		for bit := 0; bit < 31; bit++ {
			if (nums[i] & (1 << bit)) == 0 {
				if pos[bit] != -1 {
					j = max(j, pos[bit])
				}
			} else {
				pos[bit] = i
			}
		}
		ans[i] = j - i + 1
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;
        int[] pos = new int[31];
        Arrays.fill(pos, -1);
        int[] ans = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            int j = i;
            for (int bit = 0; bit < 31; ++bit) {
                if ((nums[i] & (1 << bit)) == 0) {
                    if (pos[bit] != -1) {
                        j = Math.max(j, pos[bit]);
                    }
                } else {
                    pos[bit] = i;
                }
            }
            ans[i] = j - i + 1;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var smallestSubarrays = function (nums) {
    const n = nums.length;
    const pos = new Array(31).fill(-1);
    const ans = new Array(n);
    for (let i = n - 1; i >= 0; --i) {
        let j = i;
        for (let bit = 0; bit < 31; ++bit) {
            if (!(nums[i] & (1 << bit))) {
                if (pos[bit] !== -1) {
                    j = Math.max(j, pos[bit]);
                }
            } else {
                pos[bit] = i;
            }
        }
        ans[i] = j - i + 1;
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pos = [-1] * 31
        ans = [0] * n
        for i in range(n - 1, -1, -1):
            j = i
            for bit in range(31):
                if (nums[i] & (1 << bit)) == 0:
                    if pos[bit] != -1:
                        j = max(j, pos[bit])
                else:
                    pos[bit] = i
            ans[i] = j - i + 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function smallestSubarrays(nums: number[]): number[] {
    const n = nums.length;
    const pos: number[] = new Array(31).fill(-1);
    const ans: number[] = new Array(n);
    for (let i = n - 1; i >= 0; --i) {
        let j = i;
        for (let bit = 0; bit < 31; ++bit) {
            if (!(nums[i] & (1 << bit))) {
                if (pos[bit] !== -1) {
                    j = Math.max(j, pos[bit]);
                }
            } else {
                pos[bit] = i;
            }
        }
        ans[i] = j - i + 1;
    }
    return ans;
}
```

</details>
