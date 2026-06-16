# 641. Design Circular Deque

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/design-circular-deque/)  
`Array` `Linked List` `Design` `Queue`

**Problem Link:** [LeetCode 641 - Design Circular Deque](https://leetcode.com/problems/design-circular-deque/)

## Problem

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

- MyCircularDeque(int k) Initializes the deque with a maximum size of k.
- boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
- boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
- boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
- boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
- int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
- int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
- boolean isEmpty() Returns true if the deque is empty, or false otherwise.
- boolean isFull() Returns true if the deque is full, or false otherwise.

### Example 1

```text
Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
```

## Constraints

- 1 <= k <= 1000
- 0 <= value <= 1000
- At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Design Circular Queue](https://leetcode.com/problems/design-circular-queue/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Design Front Middle Back Queue](https://leetcode.com/problems/design-front-middle-back-queue/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 641. Design Circular Deque

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linked List | C++, Java, Python3 |
| Fixed Array with Circular Ordering | C++, Java, Python3 |

## Approach 1: Linked List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val, Node* next = NULL, Node* prev = NULL)
        : val(val), next(next), prev(prev) {}
};

class MyCircularDeque {
private:
    Node* head;
    Node* rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        head = NULL;
        rear = NULL;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        if (head == NULL) {
            head = new Node(value);
            rear = head;
        } else {
            Node* newHead = new Node(value);
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if (head == NULL) {
            head = new Node(value);
            rear = head;
        } else {
            Node* newNode = new Node(value, NULL, rear);
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        if (size == 1) {
            head = NULL;
            rear = NULL;
        } else {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        if (size == 1) {
            head = NULL;
            rear = NULL;
        } else {
            Node* prevNode = rear->prev;
            delete rear;
            rear = prevNode;
        }
        size--;
        return true;
    }

    int getFront() { return (isEmpty()) ? -1 : head->val; }

    int getRear() { return (isEmpty()) ? -1 : rear->val; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Node {

    public int val;
    public Node next;
    public Node prev;

    public Node(int val, Node next, Node prev) {
        this.val = val;
        this.next = next;
        this.prev = prev;
    }
}

class MyCircularDeque {

    Node head;
    Node rear;
    int size;
    int capacity;

    public MyCircularDeque(int k) {
        size = 0;
        capacity = k;
    }

    public boolean insertFront(int value) {
        if (isFull()) return false;
        if (head == null) {
            // first element in list
            head = new Node(value, null, null);
            rear = head;
        } else {
            // add new head
            Node newHead = new Node(value, head, null);
            head.prev = newHead;
            head = newHead;
        }
        size++;
        return true;
    }

    public boolean insertLast(int value) {
        if (isFull()) return false;
        if (head == null) {
            // first element in list
            head = new Node(value, null, null);
            rear = head;
        } else {
            // add new element to end
            rear.next = new Node(value, null, rear);
            rear = rear.next;
        }
        size++;
        return true;
    }

    public boolean deleteFront() {
        if (isEmpty()) return false;
        if (size == 1) {
            head = null;
            rear = null;
        } else {
            head = head.next;
        }
        size--;
        return true;
    }

    public boolean deleteLast() {
        if (isEmpty()) return false;
        if (size == 1) {
            head = null;
            rear = null;
        } else {
            // update rear to the previous node
            rear = rear.prev;
        }
        size--;
        return true;
    }

    public int getFront() {
        if (isEmpty()) return -1;
        return head.val;
    }

    public int getRear() {
        if (isEmpty()) return -1;
        return rear.val;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Node:
    def __init__(self, val, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev


class MyCircularDeque:

    def __init__(self, k: int):
        self.size = 0
        self.capacity = k
        self.head = None
        self.rear = None

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        if self.head is None:
            self.head = Node(value, None, None)
            self.rear = self.head
        else:
            newHead = Node(value, self.head, None)
            self.head.prev = newHead
            self.head = newHead

        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        if self.head is None:
            self.head = Node(value, None, None)
            self.rear = self.head
        else:
            self.rear.next = Node(value, None, self.rear)
            self.rear = self.rear.next

        self.size += 1
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        if self.size == 1:
            self.head = None
            self.rear = None
        else:
            self.head = self.head.next

        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        if self.size == 1:
            self.head = None
            self.rear = None
        else:
            self.rear = self.rear.prev

        self.size -= 1
        return True

    def getFront(self) -> int:
        return -1 if self.isEmpty() else self.head.val

    def getRear(self) -> int:
        return -1 if self.isEmpty() else self.rear.val

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.capacity
```

</details>

<br>

## Approach 2: Fixed Array with Circular Ordering

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MyCircularDeque {
private:
    vector<int> queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        queue = vector<int>(k);
        size = 0;
        capacity = k;
        front = 0;
        rear = k - 1;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        queue[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return queue[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return queue[rear];
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MyCircularDeque {

    int[] array;
    int front;
    int rear;
    int size;
    int capacity;

    public MyCircularDeque(int k) {
        array = new int[k];
        size = 0;
        capacity = k;
        front = 0;
        rear = k - 1;
    }

    public boolean insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        array[front] = value;
        size++;
        return true;
    }

    public boolean insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        array[rear] = value;
        size++;
        return true;
    }

    public boolean deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    public boolean deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    public int getFront() {
        if (isEmpty()) return -1;
        return array[front];
    }

    public int getRear() {
        if (isEmpty()) return -1;
        return array[rear];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MyCircularDeque:

    def __init__(self, k):
        self.queue = [0] * k
        self.front = 0
        self.rear = k - 1
        self.size = 0
        self.capacity = k

    def insertFront(self, value):
        if self.isFull():
            return False
        self.front = (self.front - 1 + self.capacity) % self.capacity
        self.queue[self.front] = value
        self.size += 1
        return True

    def insertLast(self, value):
        if self.isFull():
            return False
        self.rear = (self.rear + 1) % self.capacity
        self.queue[self.rear] = value
        self.size += 1
        return True

    def deleteFront(self):
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return True

    def deleteLast(self):
        if self.isEmpty():
            return False
        self.rear = (self.rear - 1 + self.capacity) % self.capacity
        self.size -= 1
        return True

    def getFront(self):
        if self.isEmpty():
            return -1
        return self.queue[self.front]

    def getRear(self):
        if self.isEmpty():
            return -1
        return self.queue[self.rear]

    def isEmpty(self):
        return self.size == 0

    def isFull(self):
        return self.size == self.capacity
```

</details>
