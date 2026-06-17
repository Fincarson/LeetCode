# 39. Combination Sum

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/combination-sum/)  
`Array` `Backtracking`

**Problem Link:** [LeetCode 39 - Combination Sum](https://leetcode.com/problems/combination-sum/)

## Problem

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

### Example 1

```text
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

### Example 2

```text
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

### Example 3

```text
Input: candidates = [2], target = 1
Output: []
```

## Constraints

- 1 <= candidates.length <= 30
- 2 <= candidates[i] <= 40
- All elements of candidates are distinct.
- 1 <= target <= 40

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Combinations](https://leetcode.com/problems/combinations/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Factor Combinations](https://leetcode.com/problems/factor-combinations/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [The Number of Ways to Make the Sum](https://leetcode.com/problems/the-number-of-ways-to-make-the-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 39. Combination Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void backtrack(int remain, int *comb, int combSize, int start, int *candidates,
               int candidatesSize, int ***results, int *returnSize,
               int **returnColumnSizes) {
    if (remain == 0) {
        // Make a deep copy of the current combination to add to results
        int *newComb = (int *)malloc(combSize * sizeof(int));
        for (int i = 0; i < combSize; i++) {
            newComb[i] = comb[i];
        }
        (*returnColumnSizes)[*returnSize] = combSize;
        (*results)[*returnSize] = newComb;
        (*returnSize)++;
        return;
    } else if (remain < 0) {
        // Exceed the scope, stop exploration.
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        // Add the number into the combination
        comb[combSize] = candidates[i];
        backtrack(remain - candidates[i], comb, combSize + 1, i, candidates,
                  candidatesSize, results, returnSize, returnColumnSizes);
    }
}

int **combinationSum(int *candidates, int candidatesSize, int target,
                     int *returnSize, int **returnColumnSizes) {
    int maxResults = 1000;  // Maximum number of combinations
    int **results = (int **)malloc(maxResults * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxResults * sizeof(int));
    *returnSize = 0;

    int *comb = (int *)malloc(
        target * sizeof(int));  // Large enough to hold any combination

    backtrack(target, comb, 0, 0, candidates, candidatesSize, &results,
              returnSize, returnColumnSizes);

    free(comb);
    return results;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void backtrack(int remain, vector<int>& comb, int start,
                   const vector<int>& candidates,
                   vector<vector<int>>& results) {
        if (remain == 0) {
            // make a deep copy of the current combination
            results.push_back(comb);
            return;
        } else if (remain < 0) {
            // exceed the scope, stop exploration.
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // add the number into the combination
            comb.push_back(candidates[i]);
            backtrack(remain - candidates[i], comb,
                      i,  // not i + 1 because we can reuse same elements
                      candidates, results);
            // backtrack, remove the number from the combination
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> comb;

        backtrack(target, comb, 0, candidates, results);
        return results;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        List<IList<int>> results = new List<IList<int>>();
        this.backtrack(target, new List<int>(), candidates, 0, results);
        return results;
    }

    private void backtrack(int remain, List<int> comb, int[] candidates,
                           int start, List<IList<int>> results) {
        if (remain == 0) {
            results.Add(new List<int>(comb));
            return;
        } else if (remain < 0) {
            return;
        }

        for (int i = start; i < candidates.Length; ++i) {
            comb.Add(candidates[i]);
            this.backtrack(remain - candidates[i], comb, candidates, i,
                           results);
            comb.RemoveAt(comb.Count - 1);
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func combinationSum(candidates []int, target int) [][]int {
    var results [][]int
    var comb []int
    backtrack(target, comb, 0, candidates, &results)
    return results
}

func backtrack(
    remain int,
    comb []int,
    start int,
    candidates []int,
    results *[][]int,
) {
    if remain == 0 {
        // Make a deep copy of the current combination to add to results
        newComb := make([]int, len(comb))
        copy(newComb, comb)
        *results = append(*results, newComb)
        return
    } else if remain < 0 {
        // Exceed the scope, stop exploration.
        return
    }

    for i := start; i < len(candidates); i++ {
        // Add the number into the combination
        comb = append(comb, candidates[i])
        // Continue to explore with the updated combination
        backtrack(remain-candidates[i], comb, i, candidates, results)
        // Backtrack, remove the number from the combination
        comb = comb[:len(comb)-1]
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    protected void backtrack(
        int remain,
        LinkedList<Integer> comb,
        int start,
        int[] candidates,
        List<List<Integer>> results
    ) {
        if (remain == 0) {
            // make a deep copy of the current combination
            results.add(new ArrayList<Integer>(comb));
            return;
        } else if (remain < 0) {
            // exceed the scope, stop exploration.
            return;
        }

        for (int i = start; i < candidates.length; ++i) {
            // add the number into the combination
            comb.add(candidates[i]);
            this.backtrack(
                    remain - candidates[i],
                    comb,
                    i,
                    candidates,
                    results
                );
            // backtrack, remove the number from the combination
            comb.removeLast();
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> results = new ArrayList<List<Integer>>();
        LinkedList<Integer> comb = new LinkedList<Integer>();

        this.backtrack(target, comb, 0, candidates, results);
        return results;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var combinationSum = function (candidates, target) {
    function backtrack(remain, start, path) {
        if (remain < 0) {
            return;
        }
        if (remain === 0) {
            combinations.push([...path]);
            return;
        }
        for (let i = start; i < candidates.length; i++) {
            path.push(candidates[i]);
            backtrack(remain - candidates[i], i, path);
            path.pop();
        }
    }
    const combinations = [];
    backtrack(target, 0, []);
    return combinations;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def combinationSum(
        self, candidates: List[int], target: int
    ) -> List[List[int]]:

        results = []

        def backtrack(remain, comb, start):
            if remain == 0:
                # make a deep copy of the current combination
                results.append(list(comb))
                return
            elif remain < 0:
                # exceed the scope, stop exploration.
                return

            for i in range(start, len(candidates)):
                # add the number into the combination
                comb.append(candidates[i])
                # give the current number another chance, rather than moving on
                backtrack(remain - candidates[i], comb, i)
                # backtrack, remove the number from the combination
                comb.pop()

        backtrack(target, [], 0)

        return results
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function combinationSum(candidates: number[], target: number): number[][] {
    function backtrack(remain: number, start: number, path: number[]): void {
        if (remain < 0) {
            return;
        }
        if (remain === 0) {
            combinations.push([...path]);
            return;
        }
        for (let i = start; i < candidates.length; i++) {
            path.push(candidates[i]);
            backtrack(remain - candidates[i], i, path);
            path.pop();
        }
    }
    const combinations: number[][] = [];
    backtrack(target, 0, []);
    return combinations;
}
```

</details>
