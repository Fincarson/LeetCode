# 1019. Next Greater Node In Linked List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/next-greater-node-in-linked-list/)  
`Array` `Linked List` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 1019 - Next Greater Node In Linked List](https://leetcode.com/problems/next-greater-node-in-linked-list/)

## Problem

You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

### Example 1

```text
Input: head = [2,1,5]
Output: [5,5,0]
```

### Example 2

```text
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
```

## Constraints

- The number of nodes in the list is n.
- 1 <= n <= 104
- 1 <= Node.val <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1019. Next Greater Node In Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Monotonic Stack | C++, Java, Python |
| Monotonic Stack, 1 Pass | C++, Java, Python3 |

## Approach 1: Monotonic Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }
        
        int n = int(values.size());
        stack<int> iStack;
        vector<int> answer(n);
        
        for (int i = 0; i < n; ++i) {
            while (!iStack.empty() && values[iStack.top()] < values[i]) {
                int smaller = iStack.top();
                iStack.pop();
                answer[smaller] = values[i];
            }
            iStack.push(i);
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> values = new ArrayList<>();
        while (head != null) {
            values.add(head.val);
            head = head.next;
        }
        
        int n = values.size();
        int[] answer = new int[n];
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < n; ++i) {
            while (!stack.isEmpty() && values.get(stack.peek()) < values.get(i)) {
                answer[stack.peek()] = values.get(i);
                stack.pop();
            }
            stack.add(i);
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        values = []
        while head:
            values.append(head.val)
            head = head.next
        
        answer = [0] * len(values)
        stack = []
        
        for i, value in enumerate(values):
            while stack and values[stack[-1]] < value:
                smaller = stack.pop()
                answer[smaller] = value
            stack.append(i)
        
        return answer
```

</details>

<br>

## Approach 2: Monotonic Stack, 1 Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> answer;
        vector<pair<int, int>> stk;
        // We use an integer 'cnt' to represent the index.
        int cnt = 0;

        while(head != nullptr){
            // Set the next greater value of the current value 'head.val' as 0 by default.
            answer.push_back(0);
            while(stk.size() && head->val > stk.back().second){
                auto [id, val] = stk.back();
                stk.pop_back();
                answer[id] = head->val;
            }
            // Add both the index and the value to stack.
            stk.push_back({cnt++, head->val});
            head = head->next;
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> answer = new ArrayList<>();
        Stack<int[]> stack = new Stack<>();
        // We use an integer 'cnt' to represent the index.
        int cnt = 0;

        while (head != null) {
            // Set the next greater value of the current value 'head.val' as 0 by default.
            answer.add(0);
            while (!stack.isEmpty() && head.val > stack.peek()[1]) {
                int[] curr = stack.peek();
                int id = curr[0], val = curr[1];
                stack.pop();
                answer.set(id, head.val);
            }
             // Add both the index and the value to stack.
            stack.add(new int[]{cnt++, head.val});
            head = head.next;
        }
    
        return answer.stream().mapToInt(i -> i).toArray();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        answer, stack = [], []
        # We use an integer 'cnt' to represent the index.
        cnt = 0
        
        while head:
        # Set the next greater value of the current value 'head.val' as 0 by default.
            answer.append(0)
            while stack and head.val > stack[-1][1]:
                curr_id, val = stack.pop()
                answer[curr_id] = head.val

            # Add both the index and the value to stack.
            stack.append([cnt, head.val])
            cnt += 1
            head = head.next
        
        return answer
```

</details>
