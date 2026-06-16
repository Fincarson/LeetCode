# 1429. First Unique Number

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/first-unique-number/)  
`Array` `Hash Table` `Design` `Queue` `Data Stream`

**Problem Link:** [LeetCode 1429 - First Unique Number](https://leetcode.com/problems/first-unique-number/)

## Problem

You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

- FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
- int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
- void add(int value) insert value to the queue.

### Example 1

```text
Input:
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output:
[null,2,null,2,null,3,null,-1]
Explanation:
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1
```

### Example 2

```text
Input:
["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
Output:
[null,-1,null,null,null,null,null,17]
Explanation:
FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
firstUnique.showFirstUnique(); // return -1
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
firstUnique.showFirstUnique(); // return 17
```

### Example 3

```text
Input:
["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]
Output:
[null,809,null,-1]
Explanation:
FirstUnique firstUnique = new FirstUnique([809]);
firstUnique.showFirstUnique(); // return 809
firstUnique.add(809);          // the queue is now [809,809]
firstUnique.showFirstUnique(); // return -1
```

## Constraints

- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^8
- 1 <= value <= 10^8
- At most 50000 calls will be made to showFirstUnique and add.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1429. First Unique Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python3 |
| Queue and HashMap of Unique-Status | Java, Python3 |
| LinkedHashSet for Queue, and HashMap of Unique-Statuses | Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class FirstUnique {

  private Queue<Integer> queue = new ArrayDeque<>();
  
  public FirstUnique(int[] nums) {
    for (int num : nums) {
      queue.add(num);
    }
  }
    
  public int showFirstUnique() {
    for (int num : queue) {
      int count = Collections.frequency(queue, num);
      if (count == 1) {
        return num;
      }
    }
    return -1;
  }
    
  public void add(int value) {
    queue.add(value);    
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque

class FirstUnique:
    def __init__(self, nums: List[int]):
        self._queue = deque(nums)

    def showFirstUnique(self):
        for item in self._queue:
            if self._queue.count(item) == 1:
                return item
        return -1

    def add(self, value):
        self._queue.append(value)
```

</details>

<br>

## Approach 2: Queue and HashMap of Unique-Status

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class FirstUnique {

  private Queue<Integer> queue = new ArrayDeque<>();
  private Map<Integer, Boolean> isUnique = new HashMap<>();

  public FirstUnique(int[] nums) {
    for (int num : nums) {
      // Notice that we're calling the "add" method of FirstUnique; not of the queue. 
      this.add(num);
    }
  }

  public int showFirstUnique() {
    // We need to start by "cleaning" the queue of any non-uniques at the start.
    // Note that we know that if a value is in the queue, then it is also in
    // isUnique, as the implementation of add() guarantees this.
    while (!queue.isEmpty() && !isUnique.get(queue.peek())) {
      queue.remove();
    }
    // Check if there is still a value left in the queue. There might be no uniques.
    if (!queue.isEmpty()) {
      return queue.peek(); // We don't want to actually *remove* the value.
    }
    return -1;
  }

  public void add(int value) {
    // Case 1: We need to add the number to the queue and mark it as unique. 
    if (!isUnique.containsKey(value)) {
      isUnique.put(value, true);
      queue.add(value);
    // Case 2 and 3: We need to mark the number as no longer unique.
    } else {
      isUnique.put(value, false);
    }
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque

class FirstUnique:

    def __init__(self, nums: List[int]):
        self._queue = deque(nums)
        self._is_unique = {}
        for num in nums:
            # Notice that we're calling the "add" method of FirstUnique; not of the queue. 
            self.add(num)
        
    def showFirstUnique(self) -> int:
        # We need to start by "cleaning" the queue of any non-uniques at the start.
        # Note that we know that if a value is in the queue, then it is also in
        # is_unique, as the implementation of add() guarantees this.
        while self._queue and not self._is_unique[self._queue[0]]:
            self._queue.popleft()
        # Check if there is still a value left in the queue. There might be no uniques.
        if self._queue:
            return self._queue[0] # We don't want to actually *remove* the value.
        return -1
        
    def add(self, value: int) -> None:
        # Case 1: We need to add the number to the queue and mark it as unique. 
        if value not in self._is_unique:
            self._is_unique[value] = True
            self._queue.append(value)
        # Case 2 and 3: We need to mark the number as no longer unique.
        else:
            self._is_unique[value] = False
```

</details>

<br>

## Approach 3: LinkedHashSet for Queue, and HashMap of Unique-Statuses

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class FirstUnique {
  
  private Set<Integer> setQueue = new LinkedHashSet<>();
  private Map<Integer, Boolean> isUnique = new HashMap<>();
  
  public FirstUnique(int[] nums) {
    for (int num : nums) {
      this.add(num);
    }
  }
    
  public int showFirstUnique() {
    // If the queue contains values, we need to get the first one from it.
    // We can do this by making an iterator, and getting its first item.
    if (!setQueue.isEmpty()) {
       return setQueue.iterator().next();
    }
    return -1;
  }
    
  public void add(int value) {
    // Case 1: This value is not yet in the data structure.
    // It should be ADDED.
    if (!isUnique.containsKey(value)) {
      isUnique.put(value, true);
      setQueue.add(value);
    // Case 2: This value has been seen once, so is now becoming
    // non-unique. It should be REMOVED.
    } else if (isUnique.get(value)) {
      isUnique.put(value, false);
      setQueue.remove(value);
    }
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# In Python, we have to make do with the OrderedDict class. We can use it as a Set by setting
# the values to None.

from collections import OrderedDict

class FirstUnique:

    def __init__(self, nums: List[int]):
        self._queue = OrderedDict()
        self._is_unique = {}
        for num in nums:
            # Notice that we're calling the "add" method of FirstUnique; not of the queue. 
            self.add(num)
        
    def showFirstUnique(self) -> int:
        # Check if there is still a value left in the queue. There might be no uniques.
        if self._queue:
            # We don't want to actually *remove* the value.
            # Seeing as OrderedDict has no "get first" method, the way that we can get
            # the first value is to create an iterator, and then get the "next" value
            # from that. Note that this is O(1).
            return next(iter(self._queue))
        return -1
        
    def add(self, value: int) -> None:
        # Case 1: We need to add the number to the queue and mark it as unique. 
        if value not in self._is_unique:
            self._is_unique[value] = True
            self._queue[value] = None
        # Case 2: We need to mark the value as no longer unique and then 
        # remove it from the queue.
        elif self._is_unique[value]:
            self._is_unique[value] = False
            self._queue.pop(value)
        # Case 3: We don't need to do anything; the number was removed from the queue
        # the second time it occurred.
```

</details>
