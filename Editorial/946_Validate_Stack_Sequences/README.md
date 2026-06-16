# 946. Validate Stack Sequences

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/validate-stack-sequences/)  
`Array` `Stack` `Simulation`

**Problem Link:** [LeetCode 946 - Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/)

## Problem

Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

### Example 1

```text
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
```

### Example 2

```text
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
```

## Constraints

- 1 <= pushed.length <= 1000
- 0 <= pushed[i] <= 1000
- All the elements of pushed are unique.
- popped.length == pushed.length
- popped is a permutation of pushed.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 946. Validate Stack Sequences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | Java, Python |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int N = pushed.length;
        Stack<Integer> stack = new Stack();

        int j = 0;
        for (int x: pushed) {
            stack.push(x);
            while (!stack.isEmpty() && j < N && stack.peek() == popped[j]) {
                stack.pop();
                j++;
            }
        }

        return j == N;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def validateStackSequences(self, pushed, popped):
        j = 0
        stack = []
        for x in pushed:
            stack.append(x)
            while stack and j < len(popped) and stack[-1] == popped[j]:
                stack.pop()
                j += 1

        return j == len(popped)
```

</details>
