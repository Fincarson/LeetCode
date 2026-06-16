# 232. Implement Queue using Stacks

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/implement-queue-using-stacks/)  
`Stack` `Design` `Queue`

**Problem Link:** [LeetCode 232 - Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)

## Problem

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

- void push(int x) Pushes element x to the back of the queue.
- int pop() Removes the element from the front of the queue and returns it.
- int peek() Returns the element at the front of the queue.
- boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

- You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
- Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

### Example 1

```text
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

## Constraints

- 1 <= x <= 9
- At most 100 calls will be made to push, pop, peek, and empty.
- All the calls to pop and peek are valid.

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 232. Implement Queue using Stacks

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Two Stacks) Push - $O(n)$ per operation, Pop - $O(1)$ per operation. | Java |
| Approach #2 (Two Stacks) Push - $O(1)$ per operation, Pop - Amortized $O(1)$ per operation. | Java |

## Approach #1 (Two Stacks) Push - $O(n)$ per operation, Pop - $O(1)$ per operation.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
private int front;

public void push(int x) {
    if (s1.empty())
        front = x;
    while (!s1.isEmpty())
        s2.push(s1.pop());
    s2.push(x);
    while (!s2.isEmpty())
        s1.push(s2.pop());
}
```

</details>

<br>

## Approach #2 (Two Stacks) Push - $O(1)$ per operation, Pop - Amortized $O(1)$ per operation.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

private Stack<Integer> s1 = new Stack<>();
private Stack<Integer> s2 = new Stack<>();

// Push element x to the back of queue.
public void push(int x) {
    if (s1.empty())
        front = x;
    s1.push(x);
}
```

</details>
