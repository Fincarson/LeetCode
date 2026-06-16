# 47. Permutations II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/permutations-ii/)  
`Array` `Backtracking` `Sorting`

**Problem Link:** [LeetCode 47 - Permutations II](https://leetcode.com/problems/permutations-ii/)

## Problem

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

### Example 1

```text
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

### Example 2

```text
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

## Constraints

- 1 <= nums.length <= 8
- -10 <= nums[i] <= 10

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Permutation](https://leetcode.com/problems/next-permutation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Permutations](https://leetcode.com/problems/permutations/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Palindrome Permutation II](https://leetcode.com/problems/palindrome-permutation-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of Squareful Arrays](https://leetcode.com/problems/number-of-squareful-arrays/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 47. Permutations II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking with Groups of Numbers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Backtracking with Groups of Numbers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ht_item {
    int key;
    int count;
    UT_hash_handle hh;
};
void backtrack(int* nums, int numsSize, int* comb, int combSize, int** res,
               int* returnSize, int** returnColumnSizes,
               struct ht_item* counter) {
    if (combSize == numsSize) {
        res[*returnSize] = malloc(numsSize * sizeof(int));
        memcpy(res[*returnSize], comb, numsSize * sizeof(int));
        returnColumnSizes[0][*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    struct ht_item *item, *tmp;
    HASH_ITER(hh, counter, item, tmp) {
        if (item->count > 0) {
            comb[combSize] = item->key;
            item->count--;
            backtrack(nums, numsSize, comb, combSize + 1, res, returnSize,
                      returnColumnSizes, counter);
            item->count++;
        }
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize,
                    int** returnColumnSizes) {
    struct ht_item *counter = NULL, *item;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(counter, &nums[i], item);
        if (item == NULL) {
            item = malloc(sizeof(struct ht_item));
            item->key = nums[i];
            item->count = 1;
            HASH_ADD_INT(counter, key, item);
        } else {
            item->count++;
        }
    }
    int** res = malloc(10000 * sizeof(int*));
    *returnColumnSizes = malloc(10000 * sizeof(int));
    *returnSize = 0;
    int* comb = malloc(numsSize * sizeof(int));
    backtrack(nums, numsSize, comb, 0, res, returnSize, returnColumnSizes,
              counter);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++ Solution
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_map<int, int> counter;
        for (int num : nums) counter[num]++;
        vector<int> comb;
        backtrack(counter, comb, nums.size(), results);
        return results;
    }
    void backtrack(unordered_map<int, int>& counter, vector<int>& comb, int N,
                   vector<vector<int>>& results) {
        if (comb.size() == N) {
            results.push_back(comb);
            return;
        }
        for (auto& item : counter) {
            int num = item.first;
            int count = item.second;
            if (count == 0) continue;
            comb.push_back(num);
            counter[num]--;
            backtrack(counter, comb, N, results);
            comb.pop_back();
            counter[num]++;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C# Solution

public class Solution {
    public IList<IList<int>> PermuteUnique(int[] nums) {
        List<IList<int>> results = new List<IList<int>>();
        Dictionary<int, int> counter = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (!counter.ContainsKey(num))
                counter.Add(num, 0);
            counter[num]++;
        }

        List<int> comb = new List<int>();
        this.Backtrack(comb, nums.Length, counter, results);
        return results;
    }

    private void Backtrack(List<int> comb, int N, Dictionary<int, int> counter,
                           List<IList<int>> results) {
        if (comb.Count == N) {
            results.Add(new List<int>(comb));
            return;
        }

        foreach (var entry in counter.ToList()) {
            int num = entry.Key;
            int count = entry.Value;
            if (count == 0)
                continue;
            comb.Add(num);
            counter[num]--;
            this.Backtrack(comb, N, counter, results);
            comb.RemoveAt(comb.Count - 1);
            counter[num]++;
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang Solution
func permuteUnique(nums []int) [][]int {
    results := [][]int{}
    counter := make(map[int]int)
    for _, num := range nums {
        counter[num]++
    }
    var backtrack func(comb []int, N int)
    backtrack = func(comb []int, N int) {
        if len(comb) == N {
            tmp := make([]int, len(comb))
            copy(tmp, comb)
            results = append(results, tmp)
            return
        }
        for num, count := range counter {
            if count == 0 {
                continue
            }
            comb = append(comb, num)
            counter[num]--
            backtrack(comb, N)
            counter[num]++
            comb = comb[:len(comb)-1]
        }
    }
    backtrack([]int{}, len(nums))
    return results
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();

        // count the occurrence of each number
        HashMap<Integer, Integer> counter = new HashMap<>();
        for (int num : nums) {
            if (!counter.containsKey(num)) counter.put(num, 0);
            counter.put(num, counter.get(num) + 1);
        }

        LinkedList<Integer> comb = new LinkedList<>();
        this.backtrack(comb, nums.length, counter, results);
        return results;
    }

    protected void backtrack(
        LinkedList<Integer> comb,
        Integer N,
        HashMap<Integer, Integer> counter,
        List<List<Integer>> results
    ) {
        if (comb.size() == N) {
            // make a deep copy of the resulting permutation,
            // since the permutation would be backtracked later.
            results.add(new ArrayList<Integer>(comb));
            return;
        }

        for (Map.Entry<Integer, Integer> entry : counter.entrySet()) {
            Integer num = entry.getKey();
            Integer count = entry.getValue();
            if (count == 0) continue;
            // add this number into the current combination
            comb.addLast(num);
            counter.put(num, count - 1);

            // continue the exploration
            backtrack(comb, N, counter, results);

            // revert the choice for the next exploration
            comb.removeLast();
            counter.put(num, count);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript Solution
var permuteUnique = function (nums) {
    let results = [];
    let counter = {};
    for (let num of nums) {
        if (!(num in counter)) counter[num] = 0;
        counter[num]++;
    }
    function backtrack(comb, N) {
        if (comb.length === N) {
            results.push([...comb]);
            return;
        }
        for (let num in counter) {
            if (counter[num] === 0) continue;
            comb.push(parseInt(num));
            counter[num]--;
            backtrack(comb, N);
            counter[num]++;
            comb.pop();
        }
    }
    backtrack([], nums.length);
    return results;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        results = []

        def backtrack(comb, counter):
            if len(comb) == len(nums):
                # make a deep copy of the resulting permutation,
                # since the permutation would be backtracked later.
                results.append(list(comb))
                return

            for num in counter:
                if counter[num] > 0:
                    # add this number into the current combination
                    comb.append(num)
                    counter[num] -= 1
                    # continue the exploration
                    backtrack(comb, counter)
                    # revert the choice for the next exploration
                    comb.pop()
                    counter[num] += 1

        backtrack([], Counter(nums))

        return results
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript Solution
function permuteUnique(nums: number[]): number[][] {
    let results: number[][] = [];
    let counter: { [key: number]: number } = {};
    for (let num of nums) {
        if (!(num in counter)) counter[num] = 0;
        counter[num]++;
    }
    const backtrack = (comb: number[], N: number) => {
        if (comb.length == N) {
            results.push([...comb]);
            return;
        }
        for (let num in counter) {
            if (counter[num] == 0) continue;
            comb.push(parseInt(num));
            counter[num]--;
            backtrack(comb, N);
            comb.pop();
            counter[num]++;
        }
    };
    backtrack([], nums.length);
    return results;
}
```

</details>
