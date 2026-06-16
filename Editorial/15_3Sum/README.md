# 15. 3Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/3sum/)  
`Array` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 15 - 3Sum](https://leetcode.com/problems/3sum/)

## Problem

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

### Example 1

```text
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
```

### Example 2

```text
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
```

### Example 3

```text
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
```

## Constraints

- 3 <= nums.length <= 3000
- -105 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum](https://leetcode.com/problems/two-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [3Sum Closest](https://leetcode.com/problems/3sum-closest/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [4Sum](https://leetcode.com/problems/4sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [3Sum Smaller](https://leetcode.com/problems/3sum-smaller/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of Arithmetic Triplets](https://leetcode.com/problems/number-of-arithmetic-triplets/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Sum of Mountain Triplets I](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Sum of Mountain Triplets II](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 15. 3Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers <a name="approach1"></a> | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Hashset | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| "Hash with Triplet Sorting for Duplicate Elimination" <a name="approach3"></a> | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Two Pointers <a name="approach1"></a>

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
void twoSum(int* nums, int numsSize, int i, int** res, int* returnSize,
            int* returnColumnSizes) {
    int lo = i + 1, hi = numsSize - 1;
    while (lo < hi) {
        int sum = nums[i] + nums[lo] + nums[hi];
        if (sum < 0) {
            ++lo;
        } else if (sum > 0) {
            --hi;
        } else {
            res[*returnSize] = (int*)malloc(sizeof(int) * 3);
            res[*returnSize][0] = nums[i];
            res[*returnSize][1] = nums[lo++];
            res[*returnSize][2] = nums[hi--];
            returnColumnSizes[*returnSize] = 3;
            (*returnSize)++;
            while (lo < hi && nums[lo] == nums[lo - 1]) {
                ++lo;
            }
        }
    }
}
int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * (numsSize * numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize * numsSize));
    for (int i = 0; i < numsSize && nums[i] <= 0; i++) {
        if (i == 0 || nums[i - 1] != nums[i]) {
            twoSum(nums, numsSize, i, res, returnSize, *returnColumnSizes);
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSumII(nums, i, res);
            }
        return res;
    }
    void twoSumII(vector<int>& nums, int i, vector<vector<int>>& res) {
        int lo = i + 1, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0) {
                ++lo;
            } else if (sum > 0) {
                --hi;
            } else {
                res.push_back({nums[i], nums[lo++], nums[hi--]});
                while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;
            }
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        Array.Sort(nums);
        List<IList<int>> res = new List<IList<int>>();
        for (int i = 0; i < nums.Length && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {
                TwoSumII(nums, i, res);
            }

        return res;
    }

    void TwoSumII(int[] nums, int i, List<IList<int>> res) {
        int lo = i + 1, hi = nums.Length - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0) {
                ++lo;
            } else if (sum > 0) {
                --hi;
            } else {
                res.Add(new List<int> { nums[i], nums[lo++], nums[hi--] });
                while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    res := [][]int{}
    for i := 0; i < len(nums) && nums[i] <= 0; i++ {
        if i == 0 || nums[i-1] != nums[i] {
            twoSumII(nums, i, &res)
        }
    }
    return res
}

func twoSumII(nums []int, i int, res *[][]int) {
    lo, hi := i+1, len(nums)-1
    for lo < hi {
        sum := nums[i] + nums[lo] + nums[hi]
        if sum < 0 {
            lo++
        } else if sum > 0 {
            hi--
        } else {
            *res = append(*res, []int{nums[i], nums[lo], nums[hi]})
            lo++
            hi--
            for lo < hi && nums[lo] == nums[lo-1] {
                lo++
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length && nums[i] <= 0; ++i) if (
            i == 0 || nums[i - 1] != nums[i]
        ) {
            twoSumII(nums, i, res);
        }
        return res;
    }

    void twoSumII(int[] nums, int i, List<List<Integer>> res) {
        int lo = i + 1, hi = nums.length - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum < 0) {
                ++lo;
            } else if (sum > 0) {
                --hi;
            } else {
                res.add(Arrays.asList(nums[i], nums[lo++], nums[hi--]));
                while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var threeSum = function (nums) {
    nums.sort((a, b) => a - b);
    let res = [];
    for (let i = 0; i < nums.length && nums[i] <= 0; ++i)
        if (i === 0 || nums[i - 1] !== nums[i]) {
            twoSumII(nums, i, res);
        }
    return res;
};

let twoSumII = function (nums, i, res) {
    let lo = i + 1,
        hi = nums.length - 1;
    while (lo < hi) {
        let sum = nums[i] + nums[lo] + nums[hi];
        if (sum < 0) {
            ++lo;
        } else if (sum > 0) {
            --hi;
        } else {
            res.push([nums[i], nums[lo++], nums[hi--]]);
            while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums)):
            if nums[i] > 0:
                break
            if i == 0 or nums[i - 1] != nums[i]:
                self.twoSumII(nums, i, res)
        return res

    def twoSumII(self, nums: List[int], i: int, res: List[List[int]]):
        lo, hi = i + 1, len(nums) - 1
        while lo < hi:
            sum = nums[i] + nums[lo] + nums[hi]
            if sum < 0:
                lo += 1
            elif sum > 0:
                hi -= 1
            else:
                res.append([nums[i], nums[lo], nums[hi]])
                lo += 1
                hi -= 1
                while lo < hi and nums[lo] == nums[lo - 1]:
                    lo += 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function threeSum(nums: number[]): number[][] {
    nums.sort((a, b) => a - b);
    let res = [];
    for (let i = 0; i < nums.length && nums[i] <= 0; ++i)
        if (i === 0 || nums[i - 1] !== nums[i]) {
            twoSumII(nums, i, res);
        }
    return res;
}

function twoSumII(nums: number[], i: number, res: number[][]) {
    let lo = i + 1,
        hi = nums.length - 1;
    while (lo < hi) {
        let sum = nums[i] + nums[lo] + nums[hi];
        if (sum < 0) {
            ++lo;
        } else if (sum > 0) {
            --hi;
        } else {
            res.push([nums[i], nums[lo++], nums[hi--]]);
            while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;
        }
    }
}
```

</details>

<br>

## Approach 2: Hashset

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#include <stdio.h>
#include <stdlib.h>

// To sort array
void sort(int *nums, int numsSize) {
    int i, key, j;
    for (i = 1; i < numsSize; i++) {
        key = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}

// This function adds a record to the result set for each unique triple
int **threeSum(int *nums, int size, int *returnSize, int **returnColumnSizes) {
    sort(nums, size);
    int **results = (int **)malloc(size * size * sizeof(int *));
    *returnSize = 0;
    for (int i = 0; i < size - 2; ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = size - 1;
        while (j < k) {
            if (j != i + 1 && nums[j] == nums[j - 1]) {
                ++j;
                continue;
            }
            if (nums[i] + nums[j] + nums[k] > 0)
                --k;
            else if (nums[i] + nums[j] + nums[k] < 0)
                ++j;
            else {
                int *triplet = (int *)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[j];
                triplet[2] = nums[k];
                results[*returnSize] = triplet;
                ++*returnSize;
                ++j;
            }
        }
    }
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i] = 3;
    return results;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(nums, i, res);
            }
        return res;
    }
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& res) {
        unordered_set<int> seen;
        for (int j = i + 1; j < nums.size(); ++j) {
            int complement = -nums[i] - nums[j];
            if (seen.count(complement)) {
                res.push_back({nums[i], complement, nums[j]});
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                    ++j;
                }
            }
            seen.insert(nums[j]);
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        Array.Sort(nums);
        List<IList<int>> res = new List<IList<int>>();
        for (int i = 0; i < nums.Length && nums[i] <= 0; ++i)
            if (i == 0 || nums[i - 1] != nums[i]) {
                TwoSum(nums, i, res);
            }

        return res;
    }

    void TwoSum(int[] nums, int i, List<IList<int>> res) {
        HashSet<int> seen = new HashSet<int>();
        for (int j = i + 1; j < nums.Length; ++j) {
            int complement = -nums[i] - nums[j];
            if (seen.Contains(complement)) {
                res.Add(new List<int> { nums[i], nums[j], complement });
                while (j + 1 < nums.Length && nums[j] == nums[j + 1]) ++j;
            }

            seen.Add(nums[j]);
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
import "sort"

func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    res := [][]int{}
    for i := 0; i < len(nums) && nums[i] <= 0; i++ {
        if i == 0 || nums[i-1] != nums[i] {
            twoSum(nums, i, &res)
        }
    }
    return res
}

func twoSum(nums []int, i int, res *[][]int) {
    seen := map[int]bool{}
    for j := i + 1; j < len(nums); j++ {
        complement := -nums[i] - nums[j]
        if seen[complement] {
            *res = append(*res, []int{nums[i], nums[j], complement})
            for j+1 < len(nums) && nums[j] == nums[j+1] {
                j++
            }
        }
        seen[nums[j]] = true
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length && nums[i] <= 0; ++i) if (
            i == 0 || nums[i - 1] != nums[i]
        ) {
            twoSum(nums, i, res);
        }
        return res;
    }

    void twoSum(int[] nums, int i, List<List<Integer>> res) {
        var seen = new HashSet<Integer>();
        for (int j = i + 1; j < nums.length; ++j) {
            int complement = -nums[i] - nums[j];
            if (seen.contains(complement)) {
                res.add(Arrays.asList(nums[i], nums[j], complement));
                while (j + 1 < nums.length && nums[j] == nums[j + 1]) ++j;
            }
            seen.add(nums[j]);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var threeSum = function (nums) {
    nums.sort((a, b) => a - b);
    let res = [];
    for (let i = 0; i < nums.length && nums[i] <= 0; ++i)
        if (i == 0 || nums[i - 1] != nums[i]) {
            twoSum(nums, i, res);
        }
    return res;

    function twoSum(nums, i, res) {
        let seen = new Set();
        for (let j = i + 1; j < nums.length; ++j) {
            let complement = -nums[i] - nums[j];
            if (seen.has(complement)) {
                res.push([nums[i], nums[j], complement]);
                while (j + 1 < nums.length && nums[j] == nums[j + 1]) ++j;
            }
            seen.add(nums[j]);
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums)):
            if nums[i] > 0:
                break
            if i == 0 or nums[i - 1] != nums[i]:
                self.twoSum(nums, i, res)
        return res

    def twoSum(self, nums: List[int], i: int, res: List[List[int]]):
        seen = set()
        j = i + 1
        while j < len(nums):
            complement = -nums[i] - nums[j]
            if complement in seen:
                res.append([nums[i], nums[j], complement])
                while j + 1 < len(nums) and nums[j] == nums[j + 1]:
                    j += 1
            seen.add(nums[j])
            j += 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function threeSum(nums: number[]): number[][] {
    nums.sort((a, b) => a - b);
    let res = [];
    for (let i = 0; i < nums.length && nums[i] <= 0; ++i)
        if (i == 0 || nums[i - 1] != nums[i]) {
            twoSum(nums, i, res);
        }
    return res;

    function twoSum(nums: number[], i: number, res: number[][]) {
        let seen = new Set<number>();
        for (let j = i + 1; j < nums.length; ++j) {
            let complement = -nums[i] - nums[j];
            if (seen.has(complement)) {
                res.push([nums[i], nums[j], complement]);
                while (j + 1 < nums.length && nums[j] == nums[j + 1]) ++j;
            }
            seen.add(nums[j]);
        }
    }
}
```

</details>

<br>

## Approach 3: "Hash with Triplet Sorting for Duplicate Elimination" <a name="approach3"></a>

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} HashMapItem;
int compare(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {
    HashMapItem* map = NULL;
    qsort(nums, numsSize, sizeof(int), compare);
    int** result = (int**)malloc(numsSize * numsSize * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(numsSize * numsSize * sizeof(int));
    for (int i = 0; i < numsSize - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int start = i + 1, end = numsSize - 1;
        HashMapItem* s;
        while (start < end) {
            int sum = nums[i] + nums[start] + nums[end];
            if (sum < 0) {
                ++start;
            } else if (sum > 0) {
                --end;
            } else {
                int* triplet = (int*)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[start];
                triplet[2] = nums[end];
                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                ++(*returnSize);
                while (start < end && nums[start] == nums[start + 1]) ++start;
                while (start < end && nums[end] == nums[end - 1]) --end;
                ++start;
                --end;
            }
        }
    }
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        unordered_set<int> dups;
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i)
            if (dups.insert(nums[i]).second) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    int complement = -nums[i] - nums[j];
                    auto it = seen.find(complement);
                    if (it != end(seen) && it->second == i) {
                        vector<int> triplet = {nums[i], nums[j], complement};
                        sort(begin(triplet), end(triplet));
                        res.insert(triplet);
                    }
                    seen[nums[j]] = i;
                }
            }
        return vector<vector<int>>(begin(res), end(res));
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        var res = new HashSet<(int, int, int)>();
        var dups = new HashSet<int>();
        var seen = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++) {
            int val1 = nums[i];
            if (!dups.Contains(val1)) {
                dups.Add(val1);
                seen.Clear();  // Reset seen for each unique val1
                for (int j = i + 1; j < nums.Length; j++) {
                    int val2 = nums[j];
                    int complement = -val1 - val2;
                    if (seen.ContainsKey(complement) && seen[complement] == i) {
                        // Sort the triplet before adding to the set
                        var triplet = new List<int> { val1, val2, complement };
                        triplet.Sort();
                        res.Add((triplet[0], triplet[1], triplet[2]));
                    }
                    seen[val2] = i;
                }
            }
        }

        var result = new List<IList<int>>();
        foreach (var (a, b, c) in res) {
            result.Add(new List<int> { a, b, c });
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func threeSum(nums []int) [][]int {
    res := make(map[[3]int]int)
    dups := make(map[int]bool)
    seen := make(map[int]int)

    for i := 0; i < len(nums); i++ {
        if _, ok := dups[nums[i]]; !ok {
            dups[nums[i]] = true
            for j := i + 1; j < len(nums); j++ {
                complement := -nums[i] - nums[j]
                if v, ok := seen[complement]; ok && v == i {
                    triplet := []int{nums[i], nums[j], complement}
                    sort.Ints(triplet)
                    res[[3]int{triplet[0], triplet[1], triplet[2]}] = 1
                }
                seen[nums[j]] = i
            }
        }
    }

    keys := make([][]int, 0)
    for k := range res {
        keys = append(keys, []int{k[0], k[1], k[2]})
    }

    return keys
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> res = new HashSet<>();
        Set<Integer> dups = new HashSet<>();
        Map<Integer, Integer> seen = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) if (dups.add(nums[i])) {
            for (int j = i + 1; j < nums.length; ++j) {
                int complement = -nums[i] - nums[j];
                if (seen.containsKey(complement) && seen.get(complement) == i) {
                    List<Integer> triplet = Arrays.asList(
                        nums[i],
                        nums[j],
                        complement
                    );
                    Collections.sort(triplet);
                    res.add(triplet);
                }
                seen.put(nums[j], i);
            }
        }
        return new ArrayList(res);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var threeSum = function (nums) {
    const res = new Set();
    const dups = new Set();
    const seen = new Map();
    for (let i = 0; i < nums.length; ++i)
        if (!dups.has(nums[i])) {
            dups.add(nums[i]);
            for (let j = i + 1; j < nums.length; ++j) {
                let complement = -nums[i] - nums[j];
                if (seen.has(complement) && seen.get(complement) === i) {
                    let triplet = [nums[i], nums[j], complement].sort(
                        (a, b) => a - b,
                    );
                    res.add(JSON.stringify(triplet));
                }
                seen.set(nums[j], i);
            }
        }
    return Array.from(res, JSON.parse);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res, dups = set(), set()
        seen = {}
        for i, val1 in enumerate(nums):
            if val1 not in dups:
                dups.add(val1)
                for j, val2 in enumerate(nums[i + 1 :]):
                    complement = -val1 - val2
                    if complement in seen and seen[complement] == i:
                        res.add(tuple(sorted((val1, val2, complement))))
                    seen[val2] = i
        return [list(x) for x in res]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const threeSum = (nums: number[]): number[][] => {
    const res = new Set<string>();
    const dups = new Set<number>();
    const seen = new Map<number, number>();
    for (let i = 0; i < nums.length; ++i)
        if (!dups.has(nums[i])) {
            dups.add(nums[i]);
            for (let j = i + 1; j < nums.length; ++j) {
                const complement = -nums[i] - nums[j];
                if (seen.has(complement) && seen.get(complement) === i) {
                    const triplet = [nums[i], nums[j], complement].sort(
                        (a, b) => a - b,
                    );
                    res.add(JSON.stringify(triplet));
                }
                seen.set(nums[j], i);
            }
        }
    return Array.from(res).map((text) => JSON.parse(text));
};
```

</details>
