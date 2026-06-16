# 155. Min Stack

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/min-stack/)  
`Stack` `Design`

**Problem Link:** [LeetCode 155 - Min Stack](https://leetcode.com/problems/min-stack/)

## Problem

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

- MinStack() initializes the stack object.
- void push(int value) pushes the element value onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

### Example 1

```text
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

## Constraints

- -231 <= val <= 231 - 1
- Methods pop, top and getMin operations will always be called on non-empty stacks.
- At most 3 * 104 calls will be made to push, pop, top, and getMin.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Max Stack](https://leetcode.com/problems/max-stack/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 155. Min Stack

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack of Value/ Minimum Pairs | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Stacks | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Improved Two Stacks | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Stack of Value/ Minimum Pairs

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* data;     // Array to store the stack values
    int* mins;     // Array to store the minimum values
    int top;       // Index of the top element in the stack
    int capacity;  // Maximum number of items the stack can hold
} MinStack;

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->capacity = 10;  // Initial capacity, can grow as needed
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    stack->mins = (int*)malloc(stack->capacity * sizeof(int));
    stack->top = -1;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    /* If the stack is full, increase the capacity */
    if (obj->top == obj->capacity - 1) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, obj->capacity * sizeof(int));
        obj->mins = (int*)realloc(obj->mins, obj->capacity * sizeof(int));
    }
    /* If the stack is empty, then the min value
     * must just be the first value we add. */
    obj->top++;
    obj->data[obj->top] = val;
    if (obj->top == 0) {
        obj->mins[obj->top] = val;
    } else {
        int currentMin = obj->mins[obj->top - 1];
        obj->mins[obj->top] = (val < currentMin) ? val : currentMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top != -1) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top != -1) {
        return obj->data[obj->top];
    }
    return -1;  // Should handle this error case appropriately in real
                // applications
}

int minStackGetMin(MinStack* obj) {
    if (obj->top != -1) {
        return obj->mins[obj->top];
    }
    return -1;  // Should handle this error case appropriately in real
                // applications
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->mins);
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class MinStack {
private:
    std::stack<std::pair<int, int>> stack;

public:
    MinStack() {}

    void push(int x) {
        /* If the stack is empty, then the min value
         * must just be the first value we add. */
        if (stack.empty()) {
            stack.push({x, x});
            return;
        }

        int currentMin = stack.top().second;
        stack.push({x, std::min(x, currentMin)});
    }

    void pop() { stack.pop(); }

    int top() { return stack.top().first; }

    int getMin() { return stack.top().second; }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class MinStack {
    private Stack<int[]> stack = new Stack<int[]>();

    public MinStack() {
    }

    public void Push(int x) {
        // If the Stack is empty then min value is the first value we add
        if (stack.Count == 0) {
            stack.Push(new int[] { x, x });
            return;
        }

        int current_min = stack.Peek()[1];
        stack.Push(new int[] { x, Math.Min(x, current_min) });
    }

    public void Pop() {
        stack.Pop();
    }

    public int Top() {
        return stack.Peek()[0];
    }

    public int GetMin() {
        return stack.Peek()[1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type MinStack struct {
    stack [][]int
}

func Constructor() MinStack {
    return MinStack{stack: make([][]int, 0)}
}

func (this *MinStack) Push(val int) {
    /* If the stack is empty, then the min value
     * must just be the first value we add. */
    if len(this.stack) == 0 {
        this.stack = append(this.stack, []int{val, val})
        return
    }

    currentMin := this.stack[len(this.stack)-1][1]
    this.stack = append(this.stack, []int{val, min(val, currentMin)})
}

func (this *MinStack) Pop() {
    this.stack = this.stack[:len(this.stack)-1]
}

func (this *MinStack) Top() int {
    return this.stack[len(this.stack)-1][0]
}

func (this *MinStack) GetMin() int {
    return this.stack[len(this.stack)-1][1]
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MinStack {
    private Stack<int[]> stack = new Stack<>();

    public MinStack() {}

    public void push(int x) {
        /* If the stack is empty, then the min value
         * must just be the first value we add. */
        if (stack.isEmpty()) {
            stack.push(new int[] { x, x });
            return;
        }

        int currentMin = stack.peek()[1];
        stack.push(new int[] { x, Math.min(x, currentMin) });
    }

    public void pop() {
        stack.pop();
    }

    public int top() {
        return stack.peek()[0];
    }

    public int getMin() {
        return stack.peek()[1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function last(arr) {
    return arr[arr.length - 1];
}

class MinStack {
    _stack = [];

    push(x) {
        // If the stack is empty, then the min value
        // must just be the first value we add
        if (this._stack.length === 0) {
            this._stack.push([x, x]);
            return;
        }

        const currentMin = last(this._stack)[1];
        this._stack.push([x, Math.min(currentMin, x)]);
    }

    pop() {
        this._stack.pop();
    }

    top() {
        return last(this._stack)[0];
    }

    getMin() {
        return last(this._stack)[1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MinStack:

    def __init__(self):
        self.stack = []

    def push(self, x: int) -> None:

        # If the stack is empty, then the min value
        # must just be the first value we add
        if not self.stack:
            self.stack.append((x, x))
            return

        current_min = self.stack[-1][1]
        self.stack.append((x, min(x, current_min)))

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class MinStack {
    private _stack: [number, number][] = [];

    push(x: number): void {
        // If the stack is empty, then the min value must just be the first value we add
        if (this._stack.length === 0) {
            this._stack.push([x, x]);
            return;
        }
        const currentMin = this._stack[this._stack.length - 1][1];
        this._stack.push([x, Math.min(x, currentMin)]);
    }

    pop(): void {
        this._stack.pop();
    }

    top(): number {
        return this._stack[this._stack.length - 1][0];
    }

    getMin(): number {
        return this._stack[this._stack.length - 1][1];
    }
}
```

</details>

<br>

## Approach 2: Two Stacks

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* data;     // Array to store the stack values
    int* mins;     // Array to store the minimum values
    int top;       // Index of the top element in the stack
    int capacity;  // Maximum number of items the stack can hold
} MinStack;

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->capacity = 10;  // Initial capacity, can grow as needed
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    stack->mins = (int*)malloc(stack->capacity * sizeof(int));
    stack->top = -1;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    /* If the stack is full, increase the capacity */
    if (obj->top == obj->capacity - 1) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, obj->capacity * sizeof(int));
        obj->mins = (int*)realloc(obj->mins, obj->capacity * sizeof(int));
    }
    obj->top++;
    obj->data[obj->top] = val;
    /* If minStack is empty or the new value is <= the top of minStack,
       push it to minStack. */
    if (obj->top == 0 || val <= obj->mins[obj->top - 1]) {
        obj->mins[obj->top] = val;
    } else {
        obj->mins[obj->top] = obj->mins[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top != -1) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top != -1) {
        return obj->data[obj->top];
    }
    return -1;  // Should handle this error case appropriately in real
                // applications
}

int minStackGetMin(MinStack* obj) {
    if (obj->top != -1) {
        return obj->mins[obj->top];
    }
    return -1;  // Should handle this error case appropriately in real
                // applications
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->mins);
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class MinStack {
private:
    stack<int> stack, minStack;  // declaring the two stacks

public:
    MinStack() {}  // constructor

    void push(int x) {
        stack.push(x);  // pushing element to stack
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);  // pushing the minimum element so far to minStack
    }

    void pop() {
        if (stack.top() == minStack.top())
            minStack.pop();  // removing the top element of minStack if it's
                             // equal to the top of stack
        stack.pop();         // removing the top element of stack
    }

    int top() {
        return stack.top();  // returns the top element of stack
    }

    int getMin() {
        return minStack.top();  // returns the top element of minStack i.e.,
                                // minimum element up to now
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class MinStack {
    Stack<int> stack;
    Stack<int> minStack;

    public MinStack() {
        stack = new Stack<int>();
        minStack = new Stack<int>();
    }

    public void Push(int x) {
        stack.Push(x);
        if (minStack.Count == 0 || x <= minStack.Peek()) minStack.Push(x);
    }

    public void Pop() {
        if (stack.Peek() == minStack.Peek()) minStack.Pop();
        stack.Pop();
    }

    public int Top() {
        return stack.Peek();
    }

    public int GetMin() {
        return minStack.Peek();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type MinStack struct {
    stack    []int
    minStack []int
}

func Constructor() MinStack {
    return MinStack{}
}

func (this *MinStack) Push(x int) {
    this.stack = append(this.stack, x)
    if len(this.minStack) == 0 || x <= this.minStack[len(this.minStack)-1] {
        this.minStack = append(this.minStack, x)
    }
}

func (this *MinStack) Pop() {
    if this.stack[len(this.stack)-1] == this.minStack[len(this.minStack)-1] {
        this.minStack = this.minStack[:len(this.minStack)-1]
    }
    this.stack = this.stack[:len(this.stack)-1]
}

func (this *MinStack) Top() int {
    return this.stack[len(this.stack)-1]
}

func (this *MinStack) GetMin() int {
    return this.minStack[len(this.minStack)-1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MinStack {
    private Stack<Integer> stack = new Stack<>();
    private Stack<Integer> minStack = new Stack<>();

    public MinStack() {}

    public void push(int x) {
        stack.push(x);
        if (minStack.isEmpty() || x <= minStack.peek()) {
            minStack.push(x);
        }
    }

    public void pop() {
        if (stack.peek().equals(minStack.peek())) {
            minStack.pop();
        }
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minStack.peek();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function last(arr) {
    return arr[arr.length - 1];
}

class MinStack {
    _stack = [];
    _minStack = [];

    push(x) {
        this._stack.push(x);
        if (this._minStack.length === 0 || x <= last(this._minStack)) {
            this._minStack.push(x);
        }
    }

    pop() {
        if (last(this._minStack) === last(this._stack)) {
            this._minStack.pop();
        }
        this._stack.pop();
    }

    top() {
        return last(this._stack);
    }

    getMin() {
        return last(this._minStack);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MinStack:

    def __init__(self) -> None:
        self.stack = []
        self.min_stack = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)

    def pop(self) -> None:
        if self.min_stack[-1] == self.stack[-1]:
            self.min_stack.pop()
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class MinStack {
    _stack: number[];
    _minStack: number[];

    constructor() {
        this._stack = [];
        this._minStack = [];
    }

    push(x: number): void {
        this._stack.push(x);
        if (
            this._minStack.length === 0 ||
            x <= this._minStack[this._minStack.length - 1]
        ) {
            this._minStack.push(x);
        }
    }

    pop(): void {
        if (
            this._minStack[this._minStack.length - 1] ===
            this._stack[this._stack.length - 1]
        ) {
            this._minStack.pop();
        }
        this._stack.pop();
    }

    top(): number {
        return this._stack[this._stack.length - 1];
    }

    getMin(): number {
        return this._minStack[this._minStack.length - 1];
    }
}
```

</details>

<br>

## Approach 3: Improved Two Stacks

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* data;     // Stack for the actual data
    int* minData;  // Stack for the minimum values
    int* count;    // Stack for counting occurrences of minimum values
    int top;       // Top index for the data stack
    int minTop;    // Top index for the minimum stack
    int capacity;  // Capacity for all stacks
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 10;  // Initial capacity, can be grown as needed
    obj->data = (int*)malloc(obj->capacity * sizeof(int));
    obj->minData = (int*)malloc(obj->capacity * sizeof(int));
    obj->count = (int*)malloc(obj->capacity * sizeof(int));
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

void resizeStacks(MinStack* obj) {
    if (obj->top + 1 >= obj->capacity) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, obj->capacity * sizeof(int));
        obj->minData = (int*)realloc(obj->minData, obj->capacity * sizeof(int));
        obj->count = (int*)realloc(obj->count, obj->capacity * sizeof(int));
    }
}

void minStackPush(MinStack* obj, int val) {
    resizeStacks(obj);
    obj->data[++obj->top] = val;
    if (obj->minTop == -1 || val < obj->minData[obj->minTop]) {
        obj->minData[++obj->minTop] = val;
        obj->count[obj->minTop] = 1;
    } else if (val == obj->minData[obj->minTop]) {
        obj->count[obj->minTop]++;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->data[obj->top] == obj->minData[obj->minTop]) {
        obj->count[obj->minTop]--;
        if (obj->count[obj->minTop] == 0) {
            obj->minTop--;
        }
    }
    obj->top--;
}

int minStackTop(MinStack* obj) { return obj->data[obj->top]; }

int minStackGetMin(MinStack* obj) { return obj->minData[obj->minTop]; }

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->minData);
    free(obj->count);
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class MinStack {
private:
    std::stack<int> stack;
    std::stack<std::pair<int, int>> minStack;

public:
    MinStack() {}

    void push(int x) {
        // We always put the number onto the main stack.
        stack.push(x);

        // If the min stack is empty, or this number is smaller than
        // the top of the min stack, put it on with a count of 1.
        if (minStack.empty() || x < minStack.top().first) {
            minStack.push({x, 1});
        }
        // Else if this number is equal to what's currently at the top
        // of the min stack, then increment the count at the top by 1.
        else if (x == minStack.top().first) {
            minStack.top().second++;
        }
    }

    void pop() {
        // If the top of min stack is the same as the top of stack
        // then we need to decrement the count at the top by 1.
        if (stack.top() == minStack.top().first) {
            minStack.top().second--;
        }

        // If the count at the top of min stack is now 0, then remove
        // that value as we're done with it.
        if (minStack.top().second == 0) {
            minStack.pop();
        }

        // And like before, pop the top of the main stack.
        stack.pop();
    }

    int top() { return stack.top(); }

    int getMin() { return minStack.top().first; }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class MinStack {
    private Stack<int> stack = new Stack<int>();
    private Stack<int[]> minStack = new Stack<int[]>();

    public MinStack() {
    }

    public void Push(int x) {
        // We always put the number onto the main stack.
        stack.Push(x);

        // If the min stack is empty, or this number is smaller than
        // the top of the min stack, put it on with a count of 1.
        if (minStack.Count == 0 || x < minStack.Peek()[0]) {
            minStack.Push(new int[] { x, 1 });
        }
        // Else if this number is equal to what's currently at the top
        // of the min stack, then increment the count at the top by 1.
        else if (x == minStack.Peek()[0]) {
            minStack.Peek()[1]++;
        }
    }

    public void Pop() {
        // If the top of min stack is the same as the top of stack
        // then we need to decrement the count at the top by 1.
        if (stack.Peek() == minStack.Peek()[0]) {
            minStack.Peek()[1]--;
        }

        // If the count at the top of min stack is now 0, then remove
        // that value as we're done with it.
        if (minStack.Peek()[1] == 0) {
            minStack.Pop();
        }

        // And like before, pop the top of the main stack.
        stack.Pop();
    }

    public int Top() {
        return stack.Peek();
    }

    public int GetMin() {
        return minStack.Peek()[0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// minCount struct holds the minimum value and its count.
type minCount struct {
    min, count int
}

type MinStack struct {
    stackVal []int      // Main stack to store values
    stackMin []minCount // Stack to store min values with counts
}

// Constructor initializes a new MinStack with empty stacks.
func Constructor() MinStack {
    return MinStack{
        stackMin: make([]minCount, 0),
        stackVal: make([]int, 0),
    }
}

// Push adds a new element onto the stack.
func (this *MinStack) Push(val int)  {
    // If the min stack is empty or the new value is smaller than the current minimum,
    // push it onto the min stack with a count of 1.
    if len(this.stackMin) == 0 || val < this.stackMin[len(this.stackMin)-1].min {
        this.stackMin = append(this.stackMin, minCount{
            count: 1,
            min: val,
        })
    } else if val == this.stackMin[len(this.stackMin)-1].min {
        // If the new value equals the current minimum, increment its count.
        this.stackMin[len(this.stackMin)-1].count++
    }

    // Push the new value onto the main stack.
    this.stackVal = append(this.stackVal, val)
}

// Pop removes the top element from the stack.
func (this *MinStack) Pop()  {
    // If the top of the main stack equals the top of the min stack,
    // decrement the count of the minimum element.
    if this.stackVal[len(this.stackVal)-1] == this.stackMin[len(this.stackMin)-1].min {
        this.stackMin[len(this.stackMin)-1].count--

        // If the count of the minimum element reaches zero, remove it from the min stack.
        if this.stackMin[len(this.stackMin)-1].count == 0 {
            this.stackMin = this.stackMin[:len(this.stackMin)-1]
        }
    }

    // Remove the top element from the main stack.
    this.stackVal = this.stackVal[:len(this.stackVal)-1]
}

// Top returns the top element of the stack.
func (this *MinStack) Top() int {
    return this.stackVal[len(this.stackVal)-1]
}

// GetMin returns the minimum element from the min stack.
func (this *MinStack) GetMin() int {
    return this.stackMin[len(this.stackMin)-1].min
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MinStack {
    private Stack<Integer> stack = new Stack<>();
    private Stack<int[]> minStack = new Stack<>();

    public MinStack() {}

    public void push(int x) {
        // We always put the number onto the main stack.
        stack.push(x);

        // If the min stack is empty, or this number is smaller than
        // the top of the min stack, put it on with a count of 1.
        if (minStack.isEmpty() || x < minStack.peek()[0]) {
            minStack.push(new int[] { x, 1 });
        }
        // Else if this number is equal to what's currently at the top
        // of the min stack, then increment the count at the top by 1.
        else if (x == minStack.peek()[0]) {
            minStack.peek()[1]++;
        }
    }

    public void pop() {
        // If the top of min stack is the same as the top of stack
        // then we need to decrement the count at the top by 1.
        if (stack.peek().equals(minStack.peek()[0])) {
            minStack.peek()[1]--;
        }

        // If the count at the top of min stack is now 0, then remove
        // that value as we're done with it.
        if (minStack.peek()[1] == 0) {
            minStack.pop();
        }

        // And like before, pop the top of the main stack.
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minStack.peek()[0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function last(arr) {
    return arr[arr.length - 1];
}

class MinStack {
    _stack = [];
    _minStack = [];

    push(x) {
        // We always put the number onto the main stack.
        this._stack.push(x);

        // If the min stack is empty, or this number is smaller
        // than the top of the min stack, put it on with a count of 1.
        if (this._minStack.length === 0 || x < last(this._minStack)[0]) {
            this._minStack.push([x, 1]);
        }
        // Else if this number is equal to what's currently at the top
        // of the min stack, then increment the count at the top by 1.
        else if (x === last(this._minStack)[0]) {
            last(this._minStack)[1]++;
        }
    }

    pop() {
        // If the top of min stack is the same as the top of stack
        // then we need to decrement the count at the top by 1.
        if (last(this._minStack)[0] === last(this._stack)) {
            last(this._minStack)[1]--;
        }

        // If the count at the top of min stack is now 0, then remove
        // that value as we're done with it.
        if (last(this._minStack)[1] === 0) {
            this._minStack.pop();
        }

        // And like before, pop the top of the main stack.
        this._stack.pop();
    }

    top() {
        return last(this._stack);
    }

    getMin() {
        return last(this._minStack)[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, x: int) -> None:

        # We always put the number onto the main stack.
        self.stack.append(x)

        # If the min stack is empty, or this number is smaller than
        # the top of the min stack, put it on with a count of 1.
        if not self.min_stack or x < self.min_stack[-1][0]:
            self.min_stack.append([x, 1])

        # Else if this number is equal to what's currently at the top
        # of the min stack, then increment the count at the top by 1.
        elif x == self.min_stack[-1][0]:
            self.min_stack[-1][1] += 1

    def pop(self) -> None:

        # If the top of min stack is the same as the top of stack
        # then we need to decrement the count at the top by 1.
        if self.min_stack[-1][0] == self.stack[-1]:
            self.min_stack[-1][1] -= 1

        # If the count at the top of min stack is now 0, then remove
        # that value as we're done with it.
        if self.min_stack[-1][1] == 0:
            self.min_stack.pop()

        # And like before, pop the top of the main stack.
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1][0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const last = (arr: any[]) => arr[arr.length - 1];

class MinStack {
    private _stack: number[];
    private _minStack: Array<[number, number]>;

    constructor() {
        this._stack = [];
        this._minStack = [];
    }

    push(x: number): void {
        // We always put the number onto the main stack.
        this._stack.push(x);

        // If the min stack is empty, or this number is smaller than
        // the top of the min stack, put it on with a count of 1.
        if (!this._minStack.length || x < last(this._minStack)[0]) {
            this._minStack.push([x, 1]);
        }
        // Else if this number is equal to what's currently at the top
        // of the min stack, then increment the count at the top by 1.
        else if (x === last(this._minStack)[0]) {
            last(this._minStack)[1]++;
        }
    }

    pop(): void {
        // If the top of min stack is the same as the top of stack
        // then we need to decrement the count at the top by 1.
        if (last(this._minStack)[0] === last(this._stack)) {
            last(this._minStack)[1]--;
        }
        // If the count at the top of min stack is now 0, then remove
        // that value as we're done with it.
        if (last(this._minStack)[1] === 0) {
            this._minStack.pop();
        }
        // And like before, pop the top of the main stack.
        this._stack.pop();
    }

    top(): number {
        return last(this._stack);
    }

    getMin(): number {
        return last(this._minStack)[0];
    }
}
```

</details>
