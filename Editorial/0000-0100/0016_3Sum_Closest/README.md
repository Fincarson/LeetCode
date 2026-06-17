# 16. 3Sum Closest

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/3sum-closest/)  
`Array` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 16 - 3Sum Closest](https://leetcode.com/problems/3sum-closest/)

## Problem

Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

### Example 1

```text
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

### Example 2

```text
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
```

## Constraints

- 3 <= nums.length <= 500
- -1000 <= nums[i] <= 1000
- -104 <= target <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [3Sum](https://leetcode.com/problems/3sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [3Sum Smaller](https://leetcode.com/problems/3sum-smaller/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 16. 3Sum Closest

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Two Pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int threeSumClosest(int* nums, int numsSize, int target) {
    int diff = INT_MAX;
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize && diff != 0; ++i) {
        int lo = i + 1;
        int hi = numsSize - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (abs(target - sum) < abs(diff)) {
                diff = target - sum;
            }
            if (sum < target) {
                ++lo;
            } else {
                --hi;
            }
        }
    }
    return target - diff;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sz = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz && diff != 0; ++i) {
            int lo = i + 1;
            int hi = sz - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(target - sum) < abs(diff)) {
                    diff = target - sum;
                }
                if (sum < target) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }
        return target - diff;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        int diff = Int32.MaxValue;
        int sz = nums.Length;
        Array.Sort(nums);
        for (int i = 0; i < sz && diff != 0; ++i) {
            int lo = i + 1;
            int hi = sz - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (Math.Abs(target - sum) < Math.Abs(diff)) {
                    diff = target - sum;
                }

                if (sum < target) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }

        return target - diff;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func threeSumClosest(nums []int, target int) int {
    diff := math.MaxInt32
    sort.Ints(nums)
    for i := 0; i < len(nums) && diff != 0; i++ {
        lo := i + 1
        hi := len(nums) - 1
        for lo < hi {
            sum := nums[i] + nums[lo] + nums[hi]
            if abs(target-sum) < abs(diff) {
                diff = target - sum
            }
            if sum < target {
                lo++
            } else {
                hi--
            }
        }
    }
    return target - diff
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
    public int threeSumClosest(int[] nums, int target) {
        int diff = Integer.MAX_VALUE;
        int sz = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < sz && diff != 0; ++i) {
            int lo = i + 1;
            int hi = sz - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (Math.abs(target - sum) < Math.abs(diff)) {
                    diff = target - sum;
                }
                if (sum < target) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }
        return target - diff;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var threeSumClosest = function (nums, target) {
    let diff = Number.MAX_SAFE_INTEGER;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < nums.length && diff != 0; ++i) {
        let lo = i + 1;
        let hi = nums.length - 1;
        while (lo < hi) {
            let sum = nums[i] + nums[lo] + nums[hi];
            if (Math.abs(target - sum) < Math.abs(diff)) {
                diff = target - sum;
            }
            if (sum < target) {
                ++lo;
            } else {
                --hi;
            }
        }
    }
    return target - diff;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        diff = float("inf")
        nums.sort()
        for i in range(len(nums)):
            lo, hi = i + 1, len(nums) - 1
            while lo < hi:
                sum = nums[i] + nums[lo] + nums[hi]
                if abs(target - sum) < abs(diff):
                    diff = target - sum
                if sum < target:
                    lo += 1
                else:
                    hi -= 1
            if diff == 0:
                break
        return target - diff
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function threeSumClosest(nums: number[], target: number): number {
    let diff = Number.MAX_SAFE_INTEGER;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < nums.length && diff != 0; ++i) {
        let lo = i + 1;
        let hi = nums.length - 1;
        while (lo < hi) {
            let sum = nums[i] + nums[lo] + nums[hi];
            if (Math.abs(target - sum) < Math.abs(diff)) {
                diff = target - sum;
            }
            if (sum < target) {
                ++lo;
            } else {
                --hi;
            }
        }
    }
    return target - diff;
}
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int threeSumClosest(int* nums, int numsSize, int target) {
    int diff = INT_MAX, sz = numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < sz && diff != 0; ++i) {
        for (int j = i + 1; j < sz - 1; ++j) {
            int complement = target - nums[i] - nums[j];
            int lo = j + 1, hi = sz;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] <= complement)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            int hi_idx = lo, lo_idx = lo - 1;
            if (hi_idx < sz && abs(complement - nums[hi_idx]) < abs(diff))
                diff = complement - nums[hi_idx];
            if (lo_idx > j && abs(complement - nums[lo_idx]) < abs(diff))
                diff = complement - nums[lo_idx];
        }
    }
    return target - diff;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sz = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz && diff != 0; ++i) {
            for (int j = i + 1; j < sz - 1; ++j) {
                int complement = target - nums[i] - nums[j];
                auto it =
                    upper_bound(begin(nums) + j + 1, end(nums), complement);
                int hi = it - begin(nums), lo = hi - 1;
                if (hi < sz && abs(complement - nums[hi]) < abs(diff)) {
                    diff = complement - nums[hi];
                }
                if (lo > j && abs(complement - nums[lo]) < abs(diff)) {
                    diff = complement - nums[lo];
                }
            }
        }
        return target - diff;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        int diff = int.MaxValue, sz = nums.Length;
        Array.Sort(nums);
        for (int i = 0; i < sz && diff != 0; ++i) {
            for (int j = i + 1; j < sz - 1; ++j) {
                int complement = target - nums[i] - nums[j];
                int lo = j + 1, hi = sz;
                while (lo < hi) {
                    int mid = lo + (hi - lo) / 2;
                    if (nums[mid] <= complement)
                        lo = mid + 1;
                    else
                        hi = mid;
                }

                int hi_idx = lo, lo_idx = lo - 1;
                if (hi_idx < sz &&
                    Math.Abs(complement - nums[hi_idx]) < Math.Abs(diff))
                    diff = complement - nums[hi_idx];
                if (lo_idx > j &&
                    Math.Abs(complement - nums[lo_idx]) < Math.Abs(diff))
                    diff = complement - nums[lo_idx];
            }
        }

        return target - diff;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func threeSumClosest(nums []int, target int) int {
    sort.Ints(nums)
    diff := math.MaxInt32
    sz := len(nums)

    for i := 0; i < sz && diff != 0; i++ {
        for j := i + 1; j < sz-1; j++ {
            complement := target - nums[i] - nums[j]
            lo := j + 1
            hi := sz
            for lo < hi {
                mid := lo + (hi-lo)/2
                if nums[mid] <= complement {
                    lo = mid + 1
                } else {
                    hi = mid
                }
            }

            hi_idx := lo
            if hi_idx != len(nums) && abs(complement-nums[hi_idx]) < abs(diff) {
                diff = complement - nums[hi_idx]
            }
            lo_idx := lo - 1
            if lo_idx != j && abs(complement-nums[lo_idx]) < abs(diff) {
                diff = complement - nums[lo_idx]
            }
        }
    }

    return target - diff
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
    public int threeSumClosest(int[] nums, int target) {
        int diff = Integer.MAX_VALUE;
        int sz = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < sz && diff != 0; ++i) {
            for (int j = i + 1; j < sz - 1; ++j) {
                int complement = target - nums[i] - nums[j];
                var idx = Arrays.binarySearch(nums, j + 1, sz - 1, complement);
                int hi = idx >= 0 ? idx : ~idx, lo = hi - 1;
                if (
                    hi < sz && Math.abs(complement - nums[hi]) < Math.abs(diff)
                ) diff = complement - nums[hi];
                if (
                    lo > j && Math.abs(complement - nums[lo]) < Math.abs(diff)
                ) diff = complement - nums[lo];
            }
        }
        return target - diff;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var threeSumClosest = function (nums, target) {
    let diff = Number.MAX_SAFE_INTEGER,
        sz = nums.length;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < sz && diff != 0; ++i) {
        for (let j = i + 1; j < sz - 1; ++j) {
            let complement = target - nums[i] - nums[j];
            let lo = j + 1,
                hi = sz;
            while (lo < hi) {
                let mid = Math.floor(lo + (hi - lo) / 2);
                if (nums[mid] <= complement) lo = mid + 1;
                else hi = mid;
            }
            let hi_idx = lo,
                lo_idx = lo - 1;
            if (
                hi_idx < sz &&
                Math.abs(complement - nums[hi_idx]) < Math.abs(diff)
            )
                diff = complement - nums[hi_idx];
            if (
                lo_idx > j &&
                Math.abs(complement - nums[lo_idx]) < Math.abs(diff)
            )
                diff = complement - nums[lo_idx];
        }
    }
    return target - diff;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        diff = float("inf")
        nums.sort()
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                complement = target - nums[i] - nums[j]
                hi = bisect_right(nums, complement, j + 1)
                lo = hi - 1
                if hi < len(nums) and abs(complement - nums[hi]) < abs(diff):
                    diff = complement - nums[hi]
                if lo > j and abs(complement - nums[lo]) < abs(diff):
                    diff = complement - nums[lo]
            if diff == 0:
                break
        return target - diff
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function threeSumClosest(nums: number[], target: number): number {
    let diff = Number.MAX_SAFE_INTEGER,
        sz = nums.length;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < sz && diff != 0; ++i) {
        for (let j = i + 1; j < sz - 1; ++j) {
            let complement = target - nums[i] - nums[j];
            let lo = j + 1,
                hi = sz;
            while (lo < hi) {
                let mid = Math.floor(lo + (hi - lo) / 2);
                if (nums[mid] <= complement) lo = mid + 1;
                else hi = mid;
            }
            let hi_idx = lo,
                lo_idx = lo - 1;
            if (
                hi_idx < sz &&
                Math.abs(complement - nums[hi_idx]) < Math.abs(diff)
            )
                diff = complement - nums[hi_idx];
            if (
                lo_idx > j &&
                Math.abs(complement - nums[lo_idx]) < Math.abs(diff)
            )
                diff = complement - nums[lo_idx];
        }
    }
    return target - diff;
}
```

</details>
