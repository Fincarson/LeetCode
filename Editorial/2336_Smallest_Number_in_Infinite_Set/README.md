# 2336. Smallest Number in Infinite Set

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/smallest-number-in-infinite-set/)  
`Hash Table` `Design` `Heap (Priority Queue)` `Ordered Set`

**Problem Link:** [LeetCode 2336 - Smallest Number in Infinite Set](https://leetcode.com/problems/smallest-number-in-infinite-set/)

## Problem

You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

- SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
- int popSmallest() Removes and returns the smallest integer contained in the infinite set.
- void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.

### Example 1

```text
Input
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
Output
[null, null, 1, 2, 3, null, 1, 4, 5]

Explanation
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                   // is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
```

## Constraints

- 1 <= num <= 1000
- At most 1000 calls will be made in total to popSmallest and addBack.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2336. Smallest Number in Infinite Set

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashset + Heap | C++, Java, JavaScript, Python3 |
| Sorted Set | C++, Java, Python3 |

## Approach 1: Hashset + Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class SmallestInfiniteSet {
    unordered_set<int> isPresent;
    priority_queue<int, vector<int>, greater<int>> addedIntegers;
    int currentInteger;

public:
    SmallestInfiniteSet() {
        // The positive integer set's first element will be 1.
        currentInteger = 1;
    }

    int popSmallest() {
        int answer;
        // If there are numbers in the min-heap, 
        // top element is lowest among all the available numbers.
        if (!addedIntegers.empty()) {
            answer = addedIntegers.top();
            isPresent.erase(answer);
            addedIntegers.pop();
        } 
        // Otherwise, the smallest number of large positive set 
        // denoted by 'currentInteger' is the answer.
        else {
            answer = currentInteger;
            currentInteger += 1;
        }
        return answer;
    }

    void addBack(int num) {
        if (currentInteger <= num || 
            isPresent.find(num) != isPresent.end()) {
            return;
        }
        // We push 'num' in the min-heap if it isn't already present.
        addedIntegers.push(num);
        isPresent.insert(num);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class SmallestInfiniteSet {
    private HashSet<Integer> isPresent;
    private PriorityQueue<Integer> addedIntegers;
    private Integer currentInteger;
    
    public SmallestInfiniteSet() {
        isPresent = new HashSet<>();
        addedIntegers = new PriorityQueue<>();
        currentInteger = 1;
    }
    
    public int popSmallest() {
        int answer;
        // If there are numbers in the min-heap, 
        // top element is lowest among all the available numbers.
        if (!addedIntegers.isEmpty()) {
            answer = addedIntegers.poll();
            isPresent.remove(answer);
        } 
        // Otherwise, the smallest number of large positive set 
        // denoted by 'currentInteger' is the answer.
        else {
            answer = currentInteger;
            currentInteger += 1;
        }
        return answer;
    }
    
    public void addBack(int num) {
        if (currentInteger <= num || isPresent.contains(num)) {
            return;
        }
        // We push 'num' in the min-heap if it isn't already present.
        addedIntegers.add(num);
        isPresent.add(num);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let SmallestInfiniteSet = function() {
    this.isPresent = new HashSet();
    this.addedIntegers = new MinHeapPQ();
    this.currentInteger = 1;
};

SmallestInfiniteSet.prototype.popSmallest = function() {
    // If there are numbers in the min-heap, 
    // top element is lowest among all the available numbers.
    if (!this.addedIntegers.isEmpty()) {
        answer = this.addedIntegers.popMin();
        this.isPresent.remove(answer);
    }
    // Otherwise, the smallest number of large positive set 
    // denoted by 'current_integer' is the answer.
    else {
        answer = this.currentInteger;
        this.currentInteger += 1;
    }
    return answer;
};

SmallestInfiniteSet.prototype.addBack = function(num) {
    if (this.currentInteger <= num || this.isPresent.contains(num)) {
        return;
    }
    // We push 'num' in the min-heap if it isn't already present.
    this.addedIntegers.insert(num);
    this.isPresent.add(num);
};


// === MIN HEAP PRIORITY QUEUE CLASS === //
class MinHeapPQ {
    constructor() {
        this.heap = [];
    }

    // Helper methods to get parent, left and right child indices
    getParentIndex(index) {
        return Math.floor((index - 1) / 2);
    }
    getLeftChildIndex(index) {
        return 2 * index + 1;
    }
    getRightChildIndex(index) {
        return 2 * index + 2;
    }
    
    // Helper method to swap two elements in the heap
    swap(index1, index2) {
        [this.heap[index1], this.heap[index2]] = [this.heap[index2], this.heap[index1]];
    }

    // Helper method to get the minimum element in the heap
    peek() {
        if (this.heap.length === 0) {
            throw new Error("Heap is empty");
        }
        return this.heap[0];
    }

    // Helper method to insert an element into the heap
    insert(value) {
        this.heap.push(value);
        let currentIndex = this.heap.length - 1;
        let parentIndex = this.getParentIndex(currentIndex);
        while (currentIndex > 0 && this.heap[currentIndex] < this.heap[parentIndex]) {
            this.swap(currentIndex, parentIndex);
            currentIndex = parentIndex;
            parentIndex = this.getParentIndex(currentIndex);
        }
    }

    // Helper method to remove the minimum element from the heap
    popMin() {
        if (this.heap.length === 0) {
            throw new Error("Heap is empty");
        }
        const min = this.heap[0];
        const last = this.heap.pop();
        if (this.heap.length > 0) {
            this.heap[0] = last;
            let currentIndex = 0;
            let leftChildIndex = this.getLeftChildIndex(currentIndex);
            let rightChildIndex = this.getRightChildIndex(currentIndex);
            while (
                (leftChildIndex < this.heap.length && this.heap[leftChildIndex] < this.heap[currentIndex]) || 
                (rightChildIndex < this.heap.length && this.heap[rightChildIndex] < this.heap[currentIndex])
            ) {
                const smallerChildIndex = (rightChildIndex >= this.heap.length || 
                    this.heap[leftChildIndex] < this.heap[rightChildIndex]) ? leftChildIndex : rightChildIndex;

                this.swap(currentIndex, smallerChildIndex);
                currentIndex = smallerChildIndex;
                leftChildIndex = this.getLeftChildIndex(currentIndex);
                rightChildIndex = this.getRightChildIndex(currentIndex);
            }
        }
        return min;
    }

    // Helper method to get the size of the heap
    size() {
        return this.heap.length;
    }
    // Helper method to check if the heap is empty
    isEmpty() {
        return this.heap.length === 0;
    }
}


// === HASH SET CLASS === //
class HashSet {
  constructor() {
    this.hash = {};
    this.size = 0;
  }

  add(value) {
    if (!this.contains(value)) {
      this.hash[value] = true;
      this.size++;
    }
  }

  remove(value) {
    if (this.contains(value)) {
      delete this.hash[value];
      this.size--;
    }
  }

  contains(value) {
    return this.hash.hasOwnProperty(value);
  }

  getSize() {
    return this.size;
  }

  isEmpty() {
    return this.size === 0;
  }

  clear() {
    this.hash = {};
    this.size = 0;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class SmallestInfiniteSet:
    def __init__(self):
        self.is_present: {int} = set()
        self.added_integers: [int] = []
        self.current_integer = 1

    def popSmallest(self) -> int:
        # If there are numbers in the min-heap, 
        # top element is lowest among all the available numbers.
        if len(self.added_integers):
            answer = heapq.heappop(self.added_integers)
            self.is_present.remove(answer)
        # Otherwise, the smallest number of large positive set 
        # denoted by 'current_integer' is the answer.
        else:
            answer = self.current_integer
            self.current_integer += 1
        return answer

    def addBack(self, num: int) -> None:
        if self.current_integer <= num or num in self.is_present:
            return
        # We push 'num' in the min-heap if it isn't already present.
        heapq.heappush(self.added_integers, num)
        self.is_present.add(num)
```

</details>

<br>

## Approach 2: Sorted Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class SmallestInfiniteSet {
    set<int> addedIntegers;
    int currentInteger;
public:
    SmallestInfiniteSet() {
        // The positive integer set's first element will be 1.
        currentInteger = 1;
    }
    int popSmallest() {
        int answer;
        // If there are numbers in the sorted-set, 
        // first element is lowest among all the available numbers.
        if (!addedIntegers.empty()) {
            answer = *addedIntegers.begin();
            addedIntegers.erase(addedIntegers.begin());
        } 
        // Otherwise, the smallest number of large positive set 
        // denoted by 'currentInteger' is the answer.
        else {
            answer = currentInteger;
            currentInteger += 1;
        }
        return answer;
    }
    void addBack(int num) {
        if (currentInteger <= num || 
            addedIntegers.find(num) != addedIntegers.end()) {
            return;
        }
        // We push 'num' in the sorted-set if it isn't already present.
        addedIntegers.insert(num);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class SmallestInfiniteSet {
    private SortedSet<Integer> addedIntegers;
    private Integer currentInteger;
    
    public SmallestInfiniteSet() {
        addedIntegers = new TreeSet<>();
        currentInteger = 1;
    }
    
    public int popSmallest() {
        int answer;
        // If there are numbers in the sorted-set, 
        // top element is lowest among all the available numbers.
        if (!addedIntegers.isEmpty()) {
            answer = addedIntegers.first();
            addedIntegers.remove(answer);
        } 
        // Otherwise, the smallest number of large positive set 
        // denoted by 'currentInteger' is the answer.
        else {
            answer = currentInteger;
            currentInteger += 1;
        }
        return answer;
    }
    
    public void addBack(int num) {
        if (currentInteger <= num || addedIntegers.contains(num)) {
            return;
        }
        // We push 'num' in the sorted-set if it isn't already present.
        addedIntegers.add(num);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedSet

class SmallestInfiniteSet:
    def __init__(self):
        self.added_integers = SortedSet()
        self.current_integer = 1
    def popSmallest(self) -> int:
        # If there are numbers in the sorted-set, 
        # top element is lowest among all the available numbers.
        if len(self.added_integers):
            answer = self.added_integers[0]
            self.added_integers.discard(answer)
        # Otherwise, the smallest number of large positive set 
        # denoted by 'current_integer' is the answer.
        else:
            answer = self.current_integer
            self.current_integer += 1
        return answer
    def addBack(self, num: int) -> None:
        if self.current_integer <= num or num in self.added_integers:
            return
        # We push 'num' in the sorted-set if it isn't already present.
        self.added_integers.add(num)
```

</details>
