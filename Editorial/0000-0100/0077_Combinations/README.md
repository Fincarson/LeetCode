# 77. Combinations

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/combinations/)  
`Backtracking`

**Problem Link:** [LeetCode 77 - Combinations](https://leetcode.com/problems/combinations/)

## Problem

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

### Example 1

```text
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
```

### Example 2

```text
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
```

## Constraints

- 1 <= n <= 20
- 1 <= k <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Combination Sum](https://leetcode.com/problems/combination-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Permutations](https://leetcode.com/problems/permutations/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 77. Combinations

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
void backtrack(vector<int>& curr, int firstNum, vector<vector<int>>& ans) {
    if (curr.size() == k) {
        ans.push_back(curr);
        return;
    }

    for (int num = firstNum; num <= n; num++) {
        curr.push_back(num);
        backtrack(curr, num + 1, ans);
        curr.pop_back();
    }

    return;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public void backtrack(
    List<Integer> curr,
    int firstNum,
    List<List<Integer>> ans
) {
    if (curr.size() == k) {
        ans.add(new ArrayList<>(curr));
        return;
    }

    for (int num = firstNum; num <= n; num++) {
        curr.add(num);
        backtrack(curr, num + 1, ans);
        curr.remove(curr.size() - 1);
    }

    return;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def backtrack(curr, first_num):
    if len(curr) == k:
        ans.append(curr[:])
        return

    for num in range(first_num, n + 1):
        curr.append(num)
        backtrack(curr, num + 1)
        curr.pop()
```

</details>
