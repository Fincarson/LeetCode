# 1381. Design a Stack With Increment Operation

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/design-a-stack-with-increment-operation/)  
`Array` `Stack` `Design`

**Problem Link:** [LeetCode 1381 - Design a Stack With Increment Operation](https://leetcode.com/problems/design-a-stack-with-increment-operation/)

## Problem

Design a stack that supports increment operations on its elements.

Implement the CustomStack class:

- CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
- void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
- int pop() Pops and returns the top of the stack or -1 if the stack is empty.
- void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.

### Example 1

```text
Input
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
Output
[null,null,null,2,null,null,null,null,null,103,202,201,-1]
Explanation
CustomStack stk = new CustomStack(3); // Stack is Empty []
stk.push(1);                          // stack becomes [1]
stk.push(2);                          // stack becomes [1, 2]
stk.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]
stk.push(2);                          // stack becomes [1, 2]
stk.push(3);                          // stack becomes [1, 2, 3]
stk.push(4);                          // stack still [1, 2, 3], Do not add another elements as size is 4
stk.increment(5, 100);                // stack becomes [101, 102, 103]
stk.increment(2, 100);                // stack becomes [201, 202, 103]
stk.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
stk.pop();                            // return 202 --> Return top of the stack 202, stack becomes [201]
stk.pop();                            // return 201 --> Return top of the stack 201, stack becomes []
stk.pop();                            // return -1 --> Stack is empty return -1.
```

## Constraints

- 1 <= maxSize, x, k <= 1000
- 0 <= val <= 100
- At most 1000 calls will be made to each method of increment, push and pop each separately.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1381. Design a Stack With Increment Operation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Array | C++, Java, Python3 |
| Linked List | C++, Java, Python3 |
| Array using Lazy Propagation | C++, Java, Python3 |

## Approach 1: Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class CustomStack {
private:
    // Vector to store stack elements
    vector<int> stackVector;

    // Index of the top element in the stack
    int topIndex;

public:
    CustomStack(int maxSize) {
        stackVector.resize(maxSize);
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex < (int)(stackVector.size()) - 1) {
            stackVector[++topIndex] = x;
        }
    }

    int pop() {
        if (topIndex >= 0) {
            return stackVector[topIndex--];
        }
        return -1;  // Return -1 if the stack is empty
    }

    void increment(int k, int val) {
        int limit = min(k, topIndex + 1);
        for (int i = 0; i < limit; i++) {
            stackVector[i] += val;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class CustomStack {

    // Array to store stack elements
    private int[] stackArray;
    // Index of the top element in the stack
    private int topIndex;

    public CustomStack(int maxSize) {
        stackArray = new int[maxSize];
        topIndex = -1;
    }

    public void push(int x) {
        if (topIndex < stackArray.length - 1) {
            stackArray[++topIndex] = x;
        }
    }

    public int pop() {
        if (topIndex >= 0) {
            return stackArray[topIndex--];
        }
        return -1; // Return -1 if the stack is empty
    }

    public void increment(int k, int val) {
        int limit = Math.min(k, topIndex + 1);
        for (int i = 0; i < limit; i++) {
            stackArray[i] += val;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class CustomStack:
    def __init__(self, max_size: int):
        # Array to store stack elements
        self._stack = []
        # Index of the top element in the stack
        self._max_size = max_size

    def push(self, x: int) -> None:
        if len(self._stack) < self._max_size:
            self._stack.append(x)

    def pop(self) -> int:
        return self._stack.pop() if self._stack else -1

    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, len(self._stack))):
            self._stack[i] += val
```

</details>

<br>

## Approach 2: Linked List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class CustomStack {
private:
    list<int> stack;
    int maxSize;

public:
    CustomStack(int maxSize) { this->maxSize = maxSize; }

    void push(int x) {
        // Add the element to the top of the stack if it hasn't reached maxSize
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    int pop() {
        // Return -1 if the stack is empty, otherwise remove and return the top
        // element
        if (stack.empty()) return -1;
        int topElement = stack.back();
        stack.pop_back();
        return topElement;
    }

    void increment(int k, int val) {
        // Increment the bottom k elements (or all elements if k > stack size)
        auto it = stack.begin();
        for (int i = 0; i < k && it != stack.end(); i++, it++) {
            *it += val;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class CustomStack {

    private List<Integer> stack;
    private int maxSize;

    public CustomStack(int maxSize) {
        // Initialize the stack as a LinkedList for efficient add/remove operations
        stack = new LinkedList<>();
        this.maxSize = maxSize;
    }

    public void push(int x) {
        // Add the element to the top of the stack if it hasn't reached maxSize
        if (stack.size() < maxSize) {
            stack.addLast(x);
        }
    }

    public int pop() {
        // Return -1 if the stack is empty, otherwise remove and return the top element
        if (stack.isEmpty()) return -1;
        return stack.removeLast();
    }

    public void increment(int k, int val) {
        // Create an iterator to traverse the stack from bottom to top
        ListIterator<Integer> iterator = stack.listIterator();

        // Increment the bottom k elements (or all elements if k > stack size)
        while (iterator.hasNext() && k > 0) {
            int current = iterator.next();
            iterator.set(current + val);
            k--;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class CustomStack:
    def __init__(self, maxSize: int):
        # Initialize the stack as a deque for efficient add/remove operations
        self.stack = deque()
        self.max_size = maxSize

    def push(self, x: int) -> None:
        # Add the element to the top of the stack if it hasn't reached max_size
        if len(self.stack) < self.max_size:
            self.stack.append(x)

    def pop(self) -> int:
        # Return -1 if the stack is empty, otherwise remove and return the top element
        return self.stack.pop() if self.stack else -1

    def increment(self, k: int, val: int) -> None:
        # Increment the bottom k elements (or all elements if k > stack size)
        for i, _ in zip(range(k), self.stack):
            self.stack[i] += val
```

</details>

<br>

## Approach 3: Array using Lazy Propagation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class CustomStack {
private:
    // Vector to store stack elements
    vector<int> stackArray;

    // Vector to store increments for lazy propagation
    vector<int> incrementArray;

    // Current top index of the stack
    int topIndex;

public:
    CustomStack(int maxSize) {
        stackArray.resize(maxSize);
        incrementArray.resize(maxSize);
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex < (int)(stackArray.size()) - 1) {
            stackArray[++topIndex] = x;
        }
    }

    int pop() {
        if (topIndex < 0) {
            return -1;
        }

        // Calculate the actual value with increment
        int result = stackArray[topIndex] + incrementArray[topIndex];

        // Propagate the increment to the element below
        if (topIndex > 0) {
            incrementArray[topIndex - 1] += incrementArray[topIndex];
        }

        // Reset the increment for this position
        incrementArray[topIndex] = 0;

        topIndex--;
        return result;
    }

    void increment(int k, int val) {
        if (topIndex >= 0) {
            // Apply increment to the topmost element of the range
            int incrementIndex = min(topIndex, k - 1);
            incrementArray[incrementIndex] += val;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class CustomStack {

    // Array to store stack elements
    private int[] stackArray;

    // Array to store increments for lazy propagation
    private int[] incrementArray;

    // Current top index of the stack
    private int topIndex;

    public CustomStack(int maxSize) {
        stackArray = new int[maxSize];
        incrementArray = new int[maxSize];
        topIndex = -1;
    }

    public void push(int x) {
        if (topIndex < stackArray.length - 1) {
            stackArray[++topIndex] = x;
        }
    }

    public int pop() {
        if (topIndex < 0) {
            return -1;
        }

        // Calculate the actual value with increment
        int result = stackArray[topIndex] + incrementArray[topIndex];

        // Propagate the increment to the element below
        if (topIndex > 0) {
            incrementArray[topIndex - 1] += incrementArray[topIndex];
        }

        // Reset the increment for this position
        incrementArray[topIndex] = 0;

        topIndex--;
        return result;
    }

    public void increment(int k, int val) {
        if (topIndex >= 0) {
            // Apply increment to the topmost element of the range
            int incrementIndex = Math.min(topIndex, k - 1);
            incrementArray[incrementIndex] += val;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class CustomStack:
    def __init__(self, max_size: int):
        # List to store stack elements
        self._stack = [0] * max_size
        # List to store increments for lazy propagation
        self._inc = [0] * max_size
        # Current top index of the stack
        self._top = -1

    def push(self, x: int) -> None:
        if self._top < len(self._stack) - 1:
            self._top += 1
            self._stack[self._top] = x

    def pop(self) -> int:
        if self._top < 0:
            return -1

        # Calculate the actual value with increment
        result = self._stack[self._top] + self._inc[self._top]

        # Propagate the increment to the element below
        if self._top > 0:
            self._inc[self._top - 1] += self._inc[self._top]

        # Reset the increment for this position
        self._inc[self._top] = 0
        self._top -= 1
        return result

    def increment(self, k: int, val: int) -> None:
        if self._top >= 0:
            # Apply increment to the topmost element of the range
            index = min(self._top, k - 1)
            self._inc[index] += val
```

</details>
