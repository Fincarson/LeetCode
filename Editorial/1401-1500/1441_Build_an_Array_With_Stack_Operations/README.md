# 1441. Build an Array With Stack Operations

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/build-an-array-with-stack-operations/)  
`Array` `Stack` `Simulation`

**Problem Link:** [LeetCode 1441 - Build an Array With Stack Operations](https://leetcode.com/problems/build-an-array-with-stack-operations/)

## Problem

You are given an integer array target and an integer n.

You have an empty stack with the two following operations:

- "Push": pushes an integer to the top of the stack.
- "Pop": removes the integer on the top of the stack.

You also have a stream of the integers in the range [1, n].

Use the two stack operations to make the numbers in the stack (from the bottom to the top) equal to target. You should follow the following rules:

- If the stream of the integers is not empty, pick the next integer from the stream and push it to the top of the stack.
- If the stack is not empty, pop the integer at the top of the stack.
- If, at any moment, the elements in the stack (from the bottom to the top) are equal to target, do not read new integers from the stream and do not do more operations on the stack.

Return the stack operations needed to build target following the mentioned rules. If there are multiple valid answers, return any of them.

### Example 1

```text
Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Pop the integer on the top of the stack. s = [1].
Read 3 from the stream and push it to the stack. s = [1,3].
```

### Example 2

```text
Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Read 3 from the stream and push it to the stack. s = [1,2,3].
```

### Example 3

```text
Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Since the stack (from the bottom to the top) is equal to target, we stop the stack operations.
The answers that read integer 3 from the stream are not accepted.
```

## Constraints

- 1 <= target.length <= 100
- 1 <= n <= 100
- 1 <= target[i] <= n
- target is strictly increasing.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Operations to Collect Elements](https://leetcode.com/problems/minimum-operations-to-collect-elements/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1441. Build an Array With Stack Operations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulate | C++, Java, Python3 |

## Approach: Simulate

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0;
        
        for (int num : target) {
            while (i < num - 1) {
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
            
            ans.push_back("Push");
            i++;
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
    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList();
        int i = 0;
        
        for (int num : target) {
            while (i < num - 1) {
                ans.add("Push");
                ans.add("Pop");
                i++;
            }
            
            ans.add("Push");
            i++;
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        i = 0
        
        for num in target:
            while i < num - 1:
                ans.append("Push")
                ans.append("Pop")
                i += 1

            ans.append("Push")
            i += 1

        return ans
```

</details>
