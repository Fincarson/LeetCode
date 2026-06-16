# 46. Permutations

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/permutations/)  
`Array` `Backtracking`

**Problem Link:** [LeetCode 46 - Permutations](https://leetcode.com/problems/permutations/)

## Problem

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

### Example 1

```text
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

### Example 2

```text
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```

### Example 3

```text
Input: nums = [1]
Output: [[1]]
```

## Constraints

- 1 <= nums.length <= 6
- -10 <= nums[i] <= 10
- All the integers of nums are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Permutation](https://leetcode.com/problems/next-permutation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Permutations II](https://leetcode.com/problems/permutations-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Combinations](https://leetcode.com/problems/combinations/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 46. Permutations

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void backtrack(int* nums, int numsSize, int* cur, int curSize, int** ret,
               int* returnSize) {
    if (curSize == numsSize) {
        ret[*returnSize] = malloc(sizeof(int) * numsSize);
        memcpy(ret[*returnSize], cur, numsSize * sizeof(int));
        *returnSize += 1;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        bool exists = false;
        for (int j = 0; j < curSize; j++) {
            if (cur[j] == nums[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            cur[curSize] = nums[i];
            backtrack(nums, numsSize, cur, curSize + 1, ret, returnSize);
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize,
              int** returnColumnSizes) {
    int** ret = (int**)malloc(sizeof(int*) * 10000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
    for (int i = 0; i < 10000; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    *returnSize = 0;
    int* cur = (int*)malloc(numsSize * sizeof(int));
    memset(cur, -1, numsSize * sizeof(int));
    backtrack(nums, numsSize, cur, 0, ret, returnSize);
    free(cur);
    return ret;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(curr, ans, nums);
        return ans;
    }

    void backtrack(vector<int>& curr, vector<vector<int>>& ans,
                   vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int num : nums) {
            if (find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
                backtrack(curr, ans, nums);
                curr.pop_back();
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
    public IList<IList<int>> Permute(int[] nums) {
        List<IList<int>> ans = new List<IList<int>>();
        Backtrack(new List<int>(), ans, nums);
        return ans;
    }

    void Backtrack(List<int> curr, List<IList<int>> ans, int[] nums) {
        if (curr.Count == nums.Length) {
            ans.Add(new List<int>(curr));
            return;
        }

        foreach (int num in nums) {
            if (!curr.Contains(num)) {
                curr.Add(num);
                Backtrack(curr, ans, nums);
                curr.RemoveAt(curr.Count - 1);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func backtrack(nums []int, cur []int, ans *[][]int) {
    if len(cur) == len(nums) {
        copied := make([]int, len(cur))
        copy(copied, cur)
        *ans = append(*ans, copied)
        return
    }
    for _, num := range nums {
        exists := false
        for _, val := range cur {
            if val == num {
                exists = true
                break
            }
        }
        if !exists {
            cur = append(cur, num)
            backtrack(nums, cur, ans)
            cur = cur[:len(cur)-1]
        }
    }
}

func permute(nums []int) [][]int {
    ans := make([][]int, 0)
    backtrack(nums, []int{}, &ans)
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(new ArrayList<>(), ans, nums);
        return ans;
    }

    public void backtrack(
        List<Integer> curr,
        List<List<Integer>> ans,
        int[] nums
    ) {
        if (curr.size() == nums.length) {
            ans.add(new ArrayList<>(curr));
            return;
        }

        for (int num : nums) {
            if (!curr.contains(num)) {
                curr.add(num);
                backtrack(curr, ans, nums);
                curr.remove(curr.size() - 1);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var permute = function (nums) {
    var ans = [];
    var backtrack = function (curr) {
        if (curr.length === nums.length) {
            ans.push([...curr]);
            return;
        }
        for (var num of nums) {
            if (!curr.includes(num)) {
                curr.push(num);
                backtrack(curr);
                curr.pop();
            }
        }
    };
    backtrack([]);
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def backtrack(curr):
            if len(curr) == len(nums):
                ans.append(curr[:])
                return

            for num in nums:
                if num not in curr:
                    curr.append(num)
                    backtrack(curr)
                    curr.pop()

        ans = []
        backtrack([])
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function permute(nums: number[]): number[][] {
    let ans: number[][] = [];
    function backtrack(curr: number[]) {
        if (curr.length === nums.length) {
            ans.push([...curr]);
            return;
        }
        for (let num of nums) {
            if (!curr.includes(num)) {
                curr.push(num);
                backtrack(curr);
                curr.pop();
            }
        }
    }
    backtrack([]);
    return ans;
}
```

</details>
