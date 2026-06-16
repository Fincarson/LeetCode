# 216. Combination Sum III

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/combination-sum-iii/)  
`Array` `Backtracking`

**Problem Link:** [LeetCode 216 - Combination Sum III](https://leetcode.com/problems/combination-sum-iii/)

## Problem

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

- Only numbers 1 through 9 are used.
- Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

### Example 1

```text
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
```

### Example 2

```text
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
```

### Example 3

```text
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
```

## Constraints

- 2 <= k <= 9
- 1 <= n <= 60

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Combination Sum](https://leetcode.com/problems/combination-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 216. Combination Sum III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

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
    void backtrack(int remain, int k, vector<int>& comb, int next_start,
                   vector<vector<int>>& results) {
        if (remain == 0 && comb.size() == k) {
            // Note: it's important to make a deep copy here by using push_back,
            // which copies 'comb' to 'results'. This prevents modifications to
            // 'comb' in other branches of backtracking from affecting the
            // stored combinations.
            results.push_back(comb);
            return;
        } else if (remain < 0 || comb.size() == k) {
            // Exceed the scope, no need to explore further.
            return;
        }

        // Iterate through the reduced list of candidates.
        for (int i = next_start; i < 9; ++i) {
            comb.push_back(i + 1);
            this->backtrack(remain - i - 1, k, comb, i + 1, results);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> comb;

        this->backtrack(n, k, comb, 0, results);
        return results;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    protected void backtrack(
        int remain,
        int k,
        LinkedList<Integer> comb,
        int next_start,
        List<List<Integer>> results
    ) {
        if (remain == 0 && comb.size() == k) {
            // Note: it's important to make a deep copy here,
            // Otherwise the combination would be reverted in other branch of backtracking.
            results.add(new ArrayList<Integer>(comb));
            return;
        } else if (remain < 0 || comb.size() == k) {
            // Exceed the scope, no need to explore further.
            return;
        }

        // Iterate through the reduced list of candidates.
        for (int i = next_start; i < 9; ++i) {
            comb.add(i + 1);
            this.backtrack(remain - i - 1, k, comb, i + 1, results);
            comb.removeLast();
        }
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> results = new ArrayList<List<Integer>>();
        LinkedList<Integer> comb = new LinkedList<Integer>();

        this.backtrack(n, k, comb, 0, results);
        return results;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        results = []

        def backtrack(remain, comb, next_start):
            if remain == 0 and len(comb) == k:
                # make a copy of current combination
                # Otherwise the combination would be reverted in other branch of backtracking.
                results.append(list(comb))
                return
            elif remain < 0 or len(comb) == k:
                # exceed the scope, no need to explore further.
                return

            # Iterate through the reduced list of candidates.
            for i in range(next_start, 9):
                comb.append(i + 1)
                backtrack(remain - i - 1, comb, i + 1)
                # backtrack the current choice
                comb.pop()

        backtrack(n, [], 0)

        return results
```

</details>
