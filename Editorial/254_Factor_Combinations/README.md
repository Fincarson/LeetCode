# 254. Factor Combinations

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/factor-combinations/)  
`Backtracking`

**Problem Link:** [LeetCode 254 - Factor Combinations](https://leetcode.com/problems/factor-combinations/)

## Problem

Numbers can be regarded as the product of their factors.

- For example, 8 = 2 x 2 x 2 = 2 x 4.

Given an integer n, return all possible combinations of its factors. You may return the answer in any order.

Note that the factors should be in the range [2, n - 1].

### Example 1

```text
Input: n = 1
Output: []
```

### Example 2

```text
Input: n = 12
Output: [[2,6],[3,4],[2,2,3]]
```

### Example 3

```text
Input: n = 37
Output: []
```

## Constraints

- 1 <= n <= 107

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Combination Sum](https://leetcode.com/problems/combination-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 254. Factor Combinations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C++, Java |
| Iterative DFS | C++, Java |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    void backtracking(vector<int>& factors, vector<vector<int>>& ans) {
        // Got a solution,
        if (factors.size() > 1) {
            ans.push_back(factors);
        }
        const int lastFactor = factors.back();
        factors.pop_back();
        for (int i = factors.empty() ? 2 : factors.back(); i <= lastFactor / i; ++i) {
            if (lastFactor % i == 0) {
                // Add i and lastFactor / i.
                factors.push_back(i);
                factors.push_back(lastFactor / i);
                backtracking(factors, ans);
                // Remove the last 2 elements in factors to restore it after the recursion returns
                factors.pop_back();
                factors.pop_back();
            }
        }
        // Add lastFactor back to factors to restore it.
        factors.push_back(lastFactor);
    }

public:
    vector<vector<int>> getFactors(int n) {
        vector<int> factors = {n};
        vector<vector<int>> ans;
        backtracking(factors, ans);
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private void backtracking(final LinkedList<Integer> factors, final List<List<Integer>> ans) {
        // Got a solution.
        if (factors.size() > 1) {
            ans.add(new ArrayList(factors));
        }
        final int lastFactor = factors.removeLast();
        for (int i = factors.isEmpty() ? 2 : factors.peekLast(); i <=  lastFactor / i; ++i) {
            if (lastFactor % i == 0) {
                // Add i and lastFactor / i.
                factors.add(i);
                factors.add(lastFactor / i);
                backtracking(factors, ans);
                // Remove the last 2 elements in factors to restore it after the recursion returns.
                factors.removeLast();
                factors.removeLast();
            }
        }
        // Add lastFactor back to factors to restore it.
        factors.add(lastFactor);
    }

    public List<List<Integer>> getFactors(int n) {
        final List<List<Integer>> ans = new LinkedList<>();
        backtracking(new LinkedList<>(Arrays.asList(n)), ans);
        return ans;
    }
}
```

</details>

<br>

## Approach 2: Iterative DFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        stack<vector<int>> stack;
        stack.push({n});
        while (!stack.empty()) {
            auto factors = stack.top();
            stack.pop();
            const int lastFactor = factors.back();
            factors.pop_back();
            for (int i = factors.empty() ? 2 : factors.back(); i <= lastFactor / i; ++i) {
                if (lastFactor % i == 0) {
                    vector<int> newFactors = factors;
                    newFactors.push_back(i);
                    newFactors.push_back(lastFactor / i);
                    stack.push(newFactors);
                    ans.push_back(newFactors);
                }
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> getFactors(int n) {
        final List<List<Integer>> ans = new LinkedList<>();
        final Stack<LinkedList<Integer>> stack = new Stack<>();
        stack.push(new LinkedList<>(new LinkedList<>(Arrays.asList(n))));
        while (!stack.isEmpty()) {
            final LinkedList<Integer> factors = stack.pop();
            final int lastFactor = factors.removeLast();
            for (int i = factors.isEmpty() ? 2 : factors.peekLast(); i <=  lastFactor / i; ++i) {
                if (lastFactor % i == 0) {
                    // Add i and lastFactor / i.
                    LinkedList<Integer> newFactors = new LinkedList<>(factors);
                    newFactors.add(i);
                    newFactors.add(lastFactor / i);
                    stack.push(newFactors);
                    ans.add(new LinkedList<>(newFactors));
                }
            }
        }
        return ans;
    }
}
```

</details>
