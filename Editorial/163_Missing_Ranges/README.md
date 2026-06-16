# 163. Missing Ranges

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/missing-ranges/)  
`Array`

**Problem Link:** [LeetCode 163 - Missing Ranges](https://leetcode.com/problems/missing-ranges/)

## Problem

You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are within the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

Return the shortest sorted list of ranges that exactly covers all the missing numbers. That is, no element of nums is included in any of the ranges, and each missing number is covered by one of the ranges.

### Example 1

```text
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]
Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]
```

### Example 2

```text
Input: nums = [-1], lower = -1, upper = -1
Output: []
Explanation: There are no missing ranges since there are no missing numbers.
```

## Constraints

- -109 <= lower <= upper <= 109
- 0 <= nums.length <= 100
- lower <= nums[i] <= upper
- All the values of nums are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Summary Ranges](https://leetcode.com/problems/summary-ranges/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find Maximal Uncovered Ranges](https://leetcode.com/problems/find-maximal-uncovered-ranges/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 163. Missing Ranges

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Linear Scan | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Linear Scan

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Range {
    int start, end;
};

struct Range** findMissingRanges(int* nums, int numsSize, int lower, int upper,
                                 int* returnSize, int** returnColumnSizes) {
    int n = numsSize;

    struct Range** missingRanges = malloc((n + 2) * sizeof(struct Range*));
    *returnColumnSizes = malloc((n + 2) * sizeof(int));
    *returnSize = 0;

    if (n == 0) {
        missingRanges[*returnSize] = malloc(2 * sizeof(int));
        missingRanges[*returnSize]->start = lower;
        missingRanges[*returnSize]->end = upper;
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        return missingRanges;
    }

    if (lower < nums[0]) {
        missingRanges[*returnSize] = malloc(2 * sizeof(int));
        missingRanges[*returnSize]->start = lower;
        missingRanges[*returnSize]->end = nums[0] - 1;
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] <= 1) {
            continue;
        }
        missingRanges[*returnSize] = malloc(2 * sizeof(int));
        missingRanges[*returnSize]->start = nums[i] + 1;
        missingRanges[*returnSize]->end = nums[i + 1] - 1;
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    if (upper > nums[n - 1]) {
        missingRanges[*returnSize] = malloc(2 * sizeof(int));
        missingRanges[*returnSize]->start = nums[n - 1] + 1;
        missingRanges[*returnSize]->end = upper;
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    return missingRanges;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower,
                                          int upper) {
        int n = nums.size();
        vector<vector<int>> missingRanges;
        if (n == 0) {
            missingRanges.push_back(vector<int>{lower, upper});
            return missingRanges;
        }

        // Check for any missing numbers between the lower bound and nums[0].
        if (lower < nums[0]) {
            missingRanges.push_back(vector<int>{lower, nums[0] - 1});
        }

        // Check for any missing numbers between successive elements of nums.
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= 1) {
                continue;
            }
            missingRanges.push_back(vector<int>{nums[i] + 1, nums[i + 1] - 1});
        }

        // Check for any missing numbers between the last element of nums and
        // the upper bound.
        if (upper > nums[n - 1]) {
            missingRanges.push_back(vector<int>{nums[n - 1] + 1, upper});
        }

        return missingRanges;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>>
        FindMissingRanges(int[] nums, int lower, int upper) {
        int n = nums.Length;
        IList<IList<int>> missingRanges = new List<IList<int>>();

        if (n == 0) {
            missingRanges.Add(new List<int>() { lower, upper });
            return missingRanges;
        }

        // Check for any missing numbers between the lower bound and nums[0].
        if (lower < nums[0]) {
            missingRanges.Add(new List<int>() { lower, nums[0] - 1 });
        }

        // Check for any missing numbers between successive elements of nums.
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= 1) {
                continue;
            }

            missingRanges.Add(new List<int>() { nums[i] + 1, nums[i + 1] - 1 });
        }

        // Check for any missing numbers between the last element of nums and the upper bound.
        if (upper > nums[n - 1]) {
            missingRanges.Add(new List<int>() { nums[n - 1] + 1, upper });
        }

        return missingRanges;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findMissingRanges(nums []int, lower int, upper int) [][]int {
    n := len(nums)
    missingRanges := make([][]int, 0)
    if n == 0 {
        missingRanges = append(missingRanges, []int{lower, upper})
        return missingRanges
    }

    // Check for any missing numbers between the lower bound and nums[0].
    if lower < nums[0] {
        missingRanges = append(missingRanges, []int{lower, nums[0] - 1})
    }

    // Check for any missing numbers between successive elements of nums.
    for i := 0; i < n-1; i++ {
        if nums[i+1]-nums[i] <= 1 {
            continue
        }
        missingRanges = append(missingRanges, []int{nums[i] + 1, nums[i+1] - 1})
    }
    // Check for any missing numbers between the last element of nums and the upper bound.
    if upper > nums[n-1] {
        missingRanges = append(missingRanges, []int{nums[n-1] + 1, upper})
    }

    return missingRanges
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> findMissingRanges(
        int[] nums,
        int lower,
        int upper
    ) {
        int n = nums.length;
        List<List<Integer>> missingRanges = new ArrayList<>();

        if (n == 0) {
            missingRanges.add(Arrays.asList(lower, upper));
            return missingRanges;
        }
        // Check for any missing numbers between the lower bound and nums[0].
        if (lower < nums[0]) {
            missingRanges.add(Arrays.asList(lower, nums[0] - 1));
        }

        // Check for any missing numbers between successive elements of nums.
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= 1) {
                continue;
            }
            missingRanges.add(Arrays.asList(nums[i] + 1, nums[i + 1] - 1));
        }

        // Check for any missing numbers between the last element of nums and the upper bound.
        if (upper > nums[n - 1]) {
            missingRanges.add(Arrays.asList(nums[n - 1] + 1, upper));
        }

        return missingRanges;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findMissingRanges = function (nums, lower, upper) {
    let n = nums.length;
    let missingRanges = [];
    if (n === 0) {
        missingRanges.push([lower, upper]);
        return missingRanges;
    }

    // Check for any missing numbers between the lower bound and nums[0].
    if (lower < nums[0]) {
        missingRanges.push([lower, nums[0] - 1]);
    }

    // Check for any missing numbers between successive elements of nums.
    for (let i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] <= 1) {
            continue;
        }
        missingRanges.push([nums[i] + 1, nums[i + 1] - 1]);
    }

    // Check for any missing numbers between the last element of nums and the upper bound.
    if (upper > nums[n - 1]) {
        missingRanges.push([nums[n - 1] + 1, upper]);
    }

    return missingRanges;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMissingRanges(
        self, nums: List[int], lower: int, upper: int
    ) -> List[List[int]]:
        n = len(nums)
        missing_ranges = []
        if n == 0:
            missing_ranges.append([lower, upper])
            return missing_ranges

        # Check for any missing numbers between the lower bound and nums[0].
        if lower < nums[0]:
            missing_ranges.append([lower, nums[0] - 1])

        # Check for any missing numbers between successive elements of nums.
        for i in range(n - 1):
            if nums[i + 1] - nums[i] <= 1:
                continue
            missing_ranges.append([nums[i] + 1, nums[i + 1] - 1])

        # Check for any missing numbers between the last element of nums and the upper bound.
        if upper > nums[n - 1]:
            missing_ranges.append([nums[n - 1] + 1, upper])

        return missing_ranges
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findMissingRanges(
    nums: number[],
    lower: number,
    upper: number,
): number[][] {
    let n = nums.length;
    let missingRanges: number[][] = [];
    if (n === 0) {
        missingRanges.push([lower, upper]);
        return missingRanges;
    }

    // Check for any missing numbers between the lower bound and nums[0].
    if (lower < nums[0]) {
        missingRanges.push([lower, nums[0] - 1]);
    }

    // Check for any missing numbers between successive elements of nums.
    for (let i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] <= 1) {
            continue;
        }
        missingRanges.push([nums[i] + 1, nums[i + 1] - 1]);
    }

    // Check for any missing numbers between the last element of nums and the upper bound.
    if (upper > nums[n - 1]) {
        missingRanges.push([nums[n - 1] + 1, upper]);
    }

    return missingRanges;
}
```

</details>
