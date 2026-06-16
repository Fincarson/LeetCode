# 40. Combination Sum II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/combination-sum-ii/)  
`Array` `Backtracking`

**Problem Link:** [LeetCode 40 - Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

## Problem

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

### Example 1

```text
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

### Example 2

```text
Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]
```

## Constraints

- 1 <= candidates.length <= 100
- 1 <= candidates[i] <= 50
- 1 <= target <= 30

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Combination Sum](https://leetcode.com/problems/combination-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 40. Combination Sum II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Backtracking | C++, Java, Python3 |

## Approach: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> tempList;
        sort(candidates.begin(), candidates.end());
        backtrack(result, tempList, candidates, target, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& answer, vector<int>& tempList,
                   vector<int>& candidates, int totalLeft, int index) {
        if (totalLeft < 0)
            return;
        else if (totalLeft == 0) {
            answer.push_back(tempList);
        } else {
            for (int i = index;
                 i < candidates.size() && totalLeft >= candidates[i]; i++) {
                if (i > index && candidates[i] == candidates[i - 1]) continue;
                tempList.push_back(candidates[i]);
                backtrack(answer, tempList, candidates,
                          totalLeft - candidates[i], i + 1);
                tempList.pop_back();
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> list = new LinkedList<List<Integer>>();
        Arrays.sort(candidates);
        backtrack(list, new ArrayList<Integer>(), candidates, target, 0);
        return list;
    }

    private void backtrack(
        List<List<Integer>> answer,
        List<Integer> tempList,
        int[] candidates,
        int totalLeft,
        int index
    ) {
        if (totalLeft < 0) return;
        else if (totalLeft == 0) { // Add to the answer array, if the sum is equal to target.
            answer.add(new ArrayList<>(tempList));
        } else {
            for (
                int i = index;
                i < candidates.length && totalLeft >= candidates[i];
                i++
            ) {
                if (i > index && candidates[i] == candidates[i - 1]) continue;
                // Add it to tempList.
                tempList.add(candidates[i]);
                // Check for all possible scenarios.
                backtrack(
                    answer,
                    tempList,
                    candidates,
                    totalLeft - candidates[i],
                    i + 1
                );
                // Backtrack the tempList.
                tempList.remove(tempList.size() - 1);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def combinationSum2(
        self, candidates: List[int], target: int
    ) -> List[List[int]]:
        def backtrack(answer, temp_list, candidates, total_left, index):
            if total_left < 0:
                return
            elif total_left == 0:
                answer.append(temp_list.copy())
            else:
                for i in range(index, len(candidates)):
                    if i > index and candidates[i] == candidates[i - 1]:
                        continue
                    if total_left < candidates[i]:
                        break
                    temp_list.append(candidates[i])
                    backtrack(
                        answer,
                        temp_list,
                        candidates,
                        total_left - candidates[i],
                        i + 1,
                    )
                    temp_list.pop()

        result = []
        candidates.sort()
        backtrack(result, [], candidates, target, 0)
        return result
```

</details>
