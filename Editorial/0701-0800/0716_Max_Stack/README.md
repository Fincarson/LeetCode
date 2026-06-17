# 716. Max Stack

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/max-stack/)  
`Linked List` `Stack` `Design` `Doubly-Linked List` `Ordered Set`

**Problem Link:** [LeetCode 716 - Max Stack](https://leetcode.com/problems/max-stack/)

## Problem

Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

- MaxStack() Initializes the stack object.
- void push(int x) Pushes element x onto the stack.
- int pop() Removes the element on top of the stack and returns it.
- int top() Gets the element on the top of the stack without removing it.
- int peekMax() Retrieves the maximum element in the stack without removing it.
- int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.

You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.

### Example 1

```text
Input
["MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"]
[[], [5], [1], [5], [], [], [], [], [], []]
Output
[null, null, null, null, 5, 5, 1, 5, 1, 5]

Explanation
MaxStack stk = new MaxStack();
stk.push(5);   // [5] the top of the stack and the maximum number is 5.
stk.push(1);   // [5, 1] the top of the stack is 1, but the maximum is 5.
stk.push(5);   // [5, 1, 5] the top of the stack is 5, which is also the maximum, because it is the top most one.
stk.top();     // return 5, [5, 1, 5] the stack did not change.
stk.popMax();  // return 5, [5, 1] the stack is changed now, and the top is different from the max.
stk.top();     // return 1, [5, 1] the stack did not change.
stk.peekMax(); // return 5, [5, 1] the stack did not change.
stk.pop();     // return 1, [5] the top of the stack and the max element is now 5.
stk.top();     // return 5, [5] the stack did not change.
```

## Constraints

- -107 <= x <= 107
- At most 105 calls will be made to push, pop, top, peekMax, and popMax.
- There will be at least one element in the stack when pop, top, peekMax, or popMax is called.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Min Stack](https://leetcode.com/problems/min-stack/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 716. Max Stack

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Balanced Trees | C++, Java, Python3 |
| Heap + Lazy Update | C++, Java, Python3 |

## Approach 1: Two Balanced Trees

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MaxStack {
private:
    set<pair<int, int>> stack;
    set<pair<int, int>> values;
    int cnt;

public:
    MaxStack() { cnt = 0; }

    void push(int x) {
        stack.insert({cnt, x});
        values.insert({x, cnt});
        cnt++;
    }

    int pop() {
        pair<int, int> p = *stack.rbegin();
        stack.erase(p);
        values.erase({p.second, p.first});
        return p.second;
    }

    int top() { return stack.rbegin()->second; }

    int peekMax() { return values.rbegin()->first; }

    int popMax() {
        pair<int, int> p = *values.rbegin();
        values.erase(p);
        stack.erase({p.second, p.first});
        return p.first;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MaxStack {

    private TreeSet<int[]> stack;
    private TreeSet<int[]> values;
    private int cnt;

    public MaxStack() {
        Comparator<int[]> comp = (a, b) -> {
            return a[0] == b[0] ? a[1] - b[1] : a[0] - b[0];
        };
        stack = new TreeSet<>(comp);
        values = new TreeSet<>(comp);
        cnt = 0;
    }

    public void push(int x) {
        stack.add(new int[] { cnt, x });
        values.add(new int[] { x, cnt });
        cnt++;
    }

    public int pop() {
        int[] pair = stack.pollLast();
        values.remove(new int[] { pair[1], pair[0] });
        return pair[1];
    }

    public int top() {
        return stack.last()[1];
    }

    public int peekMax() {
        return values.last()[0];
    }

    public int popMax() {
        int[] pair = values.pollLast();
        stack.remove(new int[] { pair[1], pair[0] });
        return pair[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedList

class MaxStack:

    def __init__(self):
        self.stack = SortedList()
        self.values = SortedList()
        self.cnt = 0

    def push(self, x: int) -> None:
        self.stack.add((self.cnt, x))
        self.values.add((x, self.cnt))
        self.cnt += 1

    def pop(self) -> int:
        idx, val = self.stack.pop()
        self.values.remove((val, idx))
        return val

    def top(self) -> int:
        return self.stack[-1][1]

    def peekMax(self) -> int:
        return self.values[-1][0]

    def popMax(self) -> int:
        val, idx = self.values.pop()
        self.stack.remove((idx, val))
        return val
```

</details>

<br>

## Approach 2: Heap + Lazy Update

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MaxStack {
private:
    stack<pair<int, int>> stk;
    priority_queue<pair<int, int>> heap;
    unordered_set<int> removed;
    int cnt;

public:
    MaxStack() { cnt = 0; }

    void push(int x) {
        stk.push({x, cnt});
        heap.push({x, cnt});
        cnt++;
    }

    int pop() {
        while (removed.count(stk.top().second)) {
            stk.pop();
        }
        const pair<int, int> p = stk.top();
        stk.pop();
        removed.insert(p.second);
        return p.first;
    }

    int top() {
        while (removed.count(stk.top().second)) {
            stk.pop();
        }
        return stk.top().first;
    }

    int peekMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        return heap.top().first;
    }

    int popMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        const pair<int, int> p = heap.top();
        heap.pop();
        removed.insert(p.second);
        return p.first;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MaxStack {
    private Stack<int[]> stack;
    private Queue<int[]> heap;
    private Set<Integer> removed;
    private int cnt;

    public MaxStack() {
        stack = new Stack<>();
        heap = new PriorityQueue<>((a, b) -> b[0] - a[0] == 0 ? b[1] - a[1] : b[0] - a[0]);
        removed = new HashSet<>();
    }

    public void push(int x) {
        stack.add(new int[] { x, cnt });
        heap.add(new int[] { x, cnt });
        cnt++;
    }

    public int pop() {
        while (removed.contains(stack.peek()[1])) {
            stack.pop();
        }
        int[] top = stack.pop();
        removed.add(top[1]);
        return top[0];
    }

    public int top() {
        while (removed.contains(stack.peek()[1])) {
            stack.pop();
        }
        return stack.peek()[0];
    }

    public int peekMax() {
        while (removed.contains(heap.peek()[1])) {
            heap.poll();
        }
        return heap.peek()[0];

    }

    public int popMax() {
        while (removed.contains(heap.peek()[1])) {
            heap.poll();
        }
        int[] top = heap.poll();
        removed.add(top[1]);
        return top[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import heapq


class MaxStack:

    def __init__(self):
        self.heap = []
        self.cnt = 0
        self.stack = []
        self.removed = set()

    def push(self, x: int) -> None:
        heapq.heappush(self.heap, (-x, -self.cnt))
        self.stack.append((x, self.cnt))
        self.cnt += 1

    def pop(self) -> int:
        while self.stack and self.stack[-1][1] in self.removed:
            self.stack.pop()
        num, idx = self.stack.pop()
        self.removed.add(idx)
        return num

    def top(self) -> int:
        while self.stack and self.stack[-1][1] in self.removed:
            self.stack.pop()
        return self.stack[-1][0]

    def peekMax(self) -> int:
        while self.heap and -self.heap[0][1] in self.removed:
            heapq.heappop(self.heap)
        return -self.heap[0][0]

    def popMax(self) -> int:
        while self.heap and -self.heap[0][1] in self.removed:
            heapq.heappop(self.heap)
        num, idx = heapq.heappop(self.heap)
        self.removed.add(-idx)
        return -num
```

</details>
