# 339. Nested List Weight Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/nested-list-weight-sum/)  
`Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 339 - Nested List Weight Sum](https://leetcode.com/problems/nested-list-weight-sum/)

## Problem

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.

Return the sum of each integer in nestedList multiplied by its depth.

### Example 1

```text
Input: nestedList = [[1,1],2,[1,1]]
Output: 10
Explanation: Four 1's at depth 2, one 2 at depth 1. 1*2 + 1*2 + 2*1 + 1*2 + 1*2 = 10.
```

### Example 2

```text
Input: nestedList = [1,[4,[6]]]
Output: 27
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3. 1*1 + 4*2 + 6*3 = 27.
```

### Example 3

```text
Input: nestedList = [0]
Output: 0
```

## Constraints

- 1 <= nestedList.length <= 50
- The values of the integers in the nested list is in the range [-100, 100].
- The maximum depth of any integer is less than or equal to 50.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Nested List Weight Sum II](https://leetcode.com/problems/nested-list-weight-sum-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Array Nesting](https://leetcode.com/problems/array-nesting/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Employee Importance](https://leetcode.com/problems/employee-importance/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 339. Nested List Weight Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-first Search | C++, Java, Python3 |
| Breadth-first Search | C++, Java, Python3 |

## Approach 1: Depth-first Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }

    int dfs(vector<NestedInteger>& list, int depth) {
        int total = 0;
        for (NestedInteger nested : list) {
            if (nested.isInteger()) {
                total += nested.getInteger() * depth;
            } else {
                total += dfs(nested.getList(), depth + 1);
            }
        }
        return total;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int depthSum(List<NestedInteger> nestedList) {
        return dfs(nestedList, 1);
    }

    private int dfs(List<NestedInteger> list, int depth) {
        int total = 0;
        for (NestedInteger nested : list) {
            if (nested.isInteger()) {
                total += nested.getInteger() * depth;
            } else {
                total += dfs(nested.getList(), depth + 1);
            }
        }
        return total;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def depthSum(self, nestedList: List[NestedInteger]) -> int:

        def dfs(nested_list, depth):
            total = 0
            for nested in nested_list:
                if nested.isInteger():
                    total += nested.getInteger() * depth
                else:
                    total += dfs(nested.getList(), depth + 1)
            return total

        return dfs(nestedList, 1)
```

</details>

<br>

## Approach 2: Breadth-first Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        for (NestedInteger nested : nestedList) {
            q.push(nested);
        }

        int depth = 1;
        int total = 0;

        while (!q.empty()) {
            size_t size = q.size();
            for (size_t i = 0; i < size; i++) {
                NestedInteger nested = q.front();
                q.pop();
                if (nested.isInteger()) {
                    total += nested.getInteger() * depth;
                } else {
                    for (NestedInteger nested_deeper : nested.getList()) {
                        q.push(nested_deeper);
                    }
                }
            }
            depth++;
        }
        return total;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int depthSum(List<NestedInteger> nestedList) {
        Queue<NestedInteger> queue = new LinkedList<>();
        queue.addAll(nestedList);

        int depth = 1;
        int total = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                NestedInteger nested = queue.poll();
                if (nested.isInteger()) {
                    total += nested.getInteger() * depth;
                } else {
                    queue.addAll(nested.getList());
                }
            }
            depth++;
        }
        return total;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def depthSum(self, nestedList: List[NestedInteger]) -> int:
        queue = deque(nestedList)

        depth = 1
        total = 0

        while len(queue) > 0:
            for i in range(len(queue)):
                nested = queue.pop()
                if nested.isInteger():
                    total += nested.getInteger() * depth
                else:
                    queue.extendleft(nested.getList())
            depth += 1

        return total
```

</details>
