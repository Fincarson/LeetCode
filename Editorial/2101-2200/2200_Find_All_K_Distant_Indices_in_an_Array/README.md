# 2200. Find All K-Distant Indices in an Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/)  
`Array` `Two Pointers`

**Problem Link:** [LeetCode 2200 - Find All K-Distant Indices in an Array](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/)

## Problem

You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.

Return a list of all k-distant indices sorted in increasing order.

### Example 1

```text
Input: nums = [3,4,9,1,3,9,5], key = 9, k = 1
Output: [1,2,3,4,5,6]
Explanation: Here, nums[2] == key and nums[5] == key.
- For index 0, |0 - 2| > k and |0 - 5| > k, so there is no j where |0 - j| <= k and nums[j] == key. Thus, 0 is not a k-distant index.
- For index 1, |1 - 2| <= k and nums[2] == key, so 1 is a k-distant index.
- For index 2, |2 - 2| <= k and nums[2] == key, so 2 is a k-distant index.
- For index 3, |3 - 2| <= k and nums[2] == key, so 3 is a k-distant index.
- For index 4, |4 - 5| <= k and nums[5] == key, so 4 is a k-distant index.
- For index 5, |5 - 5| <= k and nums[5] == key, so 5 is a k-distant index.
- For index 6, |6 - 5| <= k and nums[5] == key, so 6 is a k-distant index.
Thus, we return [1,2,3,4,5,6] which is sorted in increasing order.
```

### Example 2

```text
Input: nums = [2,2,2,2,2], key = 2, k = 2
Output: [0,1,2,3,4]
Explanation: For all indices i in nums, there exists some index j such that |i - j| <= k and nums[j] == key, so every index is a k-distant index.
Hence, we return [0,1,2,3,4].
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 1000
- key is an integer from the array nums.
- 1 <= k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum](https://leetcode.com/problems/two-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Shortest Word Distance](https://leetcode.com/problems/shortest-word-distance/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Absolute Difference Between Elements With Constraint](https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2200. Find All K-Distant Indices in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumerate | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| One-time Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumerate

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* findKDistantIndices(int* nums, int numsSize, int key, int k,
                         int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    // traverse number pairs
    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < numsSize; ++j) {
            if (nums[j] == key && abs(i - j) <= k) {
                res[count++] = i;
                break;  // early termination to prevent duplicate addition
            }
        }
    }
    *returnSize = count;
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n = nums.size();
        // traverse number pairs
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] == key && abs(i - j) <= k) {
                    res.push_back(i);
                    break;  // early termination to prevent duplicate addition
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
    public IList<int> FindKDistantIndices(int[] nums, int key, int k) {
        List<int> res = new List<int>();
        int n = nums.Length;
        // traverse number pairs
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] == key && Math.Abs(i - j) <= k) {
                    res.Add(i);
                    break;  // early termination to prevent duplicate addition
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
func findKDistantIndices(nums []int, key int, k int) []int {
	var res []int
	n := len(nums)
	// traverse number pairs
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if nums[j] == key && abs(i-j) <= k {
				res = append(res, i)
				break // early termination to prevent duplicate addition
			}
		}
	}
	return res
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> res = new ArrayList<>();
        int n = nums.length;
        // traverse number pairs
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] == key && Math.abs(i - j) <= k) {
                    res.add(i);
                    break; // early termination to prevent duplicate addition
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
var findKDistantIndices = function (nums, key, k) {
    const res = [];
    const n = nums.length;
    // traverse number pairs
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (nums[j] === key && Math.abs(i - j) <= k) {
                res.push(i);
                break; // early termination to prevent duplicate addition
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
    def findKDistantIndices(
        self, nums: List[int], key: int, k: int
    ) -> List[int]:
        res = []
        n = len(nums)
        # traverse number pairs
        for i in range(n):
            for j in range(n):
                if nums[j] == key and abs(i - j) <= k:
                    res.append(i)
                    break  # early termination to prevent duplicate addition
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findKDistantIndices(nums: number[], key: number, k: number): number[] {
    const res: number[] = [];
    const n = nums.length;
    // traverse number pairs
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (nums[j] === key && Math.abs(i - j) <= k) {
                res.push(i);
                break; // early termination to prevent duplicate addition
            }
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: One-time Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* findKDistantIndices(int* nums, int numsSize, int key, int k,
                         int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    int r = 0;  // unjudged minimum index
    for (int j = 0; j < numsSize; ++j) {
        if (nums[j] == key) {
            int l = fmax(r, j - k);
            r = fmin(numsSize - 1, j + k) + 1;
            for (int i = l; i < r; ++i) {
                res[count++] = i;
            }
        }
    }
    *returnSize = count;
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int r = 0;  // unjudged minimum index
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int l = max(r, j - k);
                r = min(n - 1, j + k) + 1;
                for (int i = l; i < r; ++i) {
                    res.push_back(i);
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
    public IList<int> FindKDistantIndices(int[] nums, int key, int k) {
        List<int> res = new List<int>();
        int r = 0;  // unjudged minimum index
        int n = nums.Length;
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int l = Math.Max(r, j - k);
                r = Math.Min(n - 1, j + k) + 1;
                for (int i = l; i < r; ++i) {
                    res.Add(i);
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
func findKDistantIndices(nums []int, key int, k int) []int {
	var res []int
	r := 0 // unjudged minimum index
	n := len(nums)
	for j := 0; j < n; j++ {
		if nums[j] == key {
			l := max(r, j-k)
			r = min(n-1, j+k) + 1
			for i := l; i < r; i++ {
				res = append(res, i)
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

    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> res = new ArrayList<>();
        int r = 0; // unjudged minimum index
        int n = nums.length;
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int l = Math.max(r, j - k);
                r = Math.min(n - 1, j + k) + 1;
                for (int i = l; i < r; ++i) {
                    res.add(i);
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
var findKDistantIndices = function (nums, key, k) {
    const res = [];
    let r = 0; // unjudged minimum index
    const n = nums.length;
    for (let j = 0; j < n; ++j) {
        if (nums[j] === key) {
            const l = Math.max(r, j - k);
            r = Math.min(n - 1, j + k) + 1;
            for (let i = l; i < r; ++i) {
                res.push(i);
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
    def findKDistantIndices(
        self, nums: List[int], key: int, k: int
    ) -> List[int]:
        res = []
        r = 0  # unjudged minimum index
        n = len(nums)
        for j in range(n):
            if nums[j] == key:
                l = max(r, j - k)
                r = min(n - 1, j + k) + 1
                for i in range(l, r):
                    res.append(i)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findKDistantIndices(nums: number[], key: number, k: number): number[] {
    const res: number[] = [];
    let r = 0; // unjudged minimum index
    const n = nums.length;
    for (let j = 0; j < n; ++j) {
        if (nums[j] === key) {
            const l = Math.max(r, j - k);
            r = Math.min(n - 1, j + k) + 1;
            for (let i = l; i < r; ++i) {
                res.push(i);
            }
        }
    }
    return res;
}
```

</details>
