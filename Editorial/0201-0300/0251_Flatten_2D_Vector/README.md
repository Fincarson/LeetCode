# 251. Flatten 2D Vector

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/flatten-2d-vector/)  
`Array` `Two Pointers` `Design` `Iterator`

**Problem Link:** [LeetCode 251 - Flatten 2D Vector](https://leetcode.com/problems/flatten-2d-vector/)

## Problem

Design an iterator to flatten a 2D vector. It should support the next and hasNext operations.

Implement the Vector2D class:

- Vector2D(int[][] vec) initializes the object with the 2D vector vec.
- next() returns the next element from the 2D vector and moves the pointer one step forward. You may assume that all the calls to next are valid.
- hasNext() returns true if there are still some elements in the vector, and false otherwise.

### Example 1

```text
Input
["Vector2D", "next", "next", "next", "hasNext", "hasNext", "next", "hasNext"]
[[[[1, 2], [3], [4]]], [], [], [], [], [], [], []]
Output
[null, 1, 2, 3, true, true, 4, false]

Explanation
Vector2D vector2D = new Vector2D([[1, 2], [3], [4]]);
vector2D.next();    // return 1
vector2D.next();    // return 2
vector2D.next();    // return 3
vector2D.hasNext(); // return True
vector2D.hasNext(); // return True
vector2D.next();    // return 4
vector2D.hasNext(); // return False
```

## Constraints

- 0 <= vec.length <= 200
- 0 <= vec[i].length <= 500
- -500 <= vec[i][j] <= 500
- At most 105 calls will be made to next and hasNext.

Follow up: As an added challenge, try to code it using only iterators in C++ or iterators in Java.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Peeking Iterator](https://leetcode.com/problems/peeking-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 251. Flatten 2D Vector

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Flatten List in Constructor | Java, Python |
| Two Pointers | Java, Python |

## Approach 1: Flatten List in Constructor

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.NoSuchElementException;

class Vector2D {

    // Constructor will put all the nums into this list.
    private List<Integer> nums = new ArrayList<>();
    // Keep track of where the Iterator is up to.
    private int position = 0;

    public Vector2D(int[][] v) {
        // We need to iterate over the 2D vector, getting all the integers
        // out of it and putting them into nums (a field).
        for (int[] innerVector : v) {
            for (int num : innerVector) {
                nums.add(num);
            }
        }
    }

    public int next() {
        // In Java, we throw a NoSuchElementException when next() is called
        // on an exhausted Iterator.
        if (!hasNext()) throw new NoSuchElementException();
        // Store the number we need to return, as we still need to move position forward.
        int result = nums.get(position);
        // Move the position pointer forward by 1, so that it's ready for
        // the next call to next, and gives a correct hasNext result.
        position++;
        return result;
    }

    public boolean hasNext() {
        // There's nums left as long as position is a valid index of the list.
        return position < nums.size();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Vector2D:

    def __init__(self, v: List[List[int]]):
        # We need to iterate over the 2D vector, getting all the integers
        # out of it and putting them into the nums list.
        self.nums = []
        for inner_list in v:
            for num in inner_list:
                self.nums.append(num)
        # We'll keep position 1 behind the next number to return.
        self.position = -1

    def next(self) -> int:
        # Move up to the current element and return it.
        self.position += 1
        return self.nums[self.position]

    def hasNext(self) -> bool:
        # If the next position is a valid index of nums, return True.
        return self.position + 1 < len(self.nums)
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.NoSuchElementException;

class Vector2D {

    private int[][] vector;
    private int inner = 0;
    private int outer = 0;

    public Vector2D(int[][] v) {
        // We need to store a *reference* to the input vector.
        vector = v;
    }

    // If the current outer and inner point to an integer, this method does nothing.
    // Otherwise, inner and outer are advanced until they point to an integer.
    // If there are no more integers, then outer will be equal to vector.length
    // when this method terminates.
    private void advanceToNext() {
        // While outer is still within the vector, but inner is over the
        // end of the inner list pointed to by outer, we want to move
        // forward to the start of the next inner vector.
        while (outer < vector.length && inner == vector[outer].length) {
            inner = 0;
            outer++;
        }
    }

    public int next() {
        // As per Java specs, throw an exception if there's no next.
        // This will also ensure the pointers point to an integer otherwise.
        if (!hasNext()) throw new NoSuchElementException();
        // Return current element and move inner so that is after the current
        // element.
        return vector[outer][inner++];
    }

    public boolean hasNext() {
        // Ensure the position pointers are moved such they point to an integer,
        // or put outer = vector.length.
        advanceToNext();
        // If outer = vector.length then there are no integers left, otherwise
        // we've stopped at an integer and so there's an integer left.
        return outer < vector.length;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Vector2D:

    def __init__(self, v: List[List[int]]):
        self.vector = v
        self.inner = 0
        self.outer = 0

    # If the current outer and inner point to an integer, this method does nothing.
    # Otherwise, inner and outer are advanced until they point to an integer.
    # If there are no more integers, then outer will be equal to vector.length
    # when this method terminates.
    def advance_to_next(self):
        # While outer is still within the vector, but inner is over the
        # end of the inner list pointed to by outer, we want to move
        # forward to the start of the next inner vector.
        while self.outer < len(self.vector) and self.inner == len(self.vector[self.outer]):
            self.outer += 1
            self.inner = 0

    def next(self) -> int:
        # Ensure the position pointers are moved such they point to an integer,
        # or put outer = vector.length.
        self.advance_to_next()
        # Return current element and move inner so that is after the current
        # element.
        result = self.vector[self.outer][self.inner]
        self.inner += 1
        return result


    def hasNext(self) -> bool:
        # Ensure the position pointers are moved such they point to an integer,
        # or put outer = vector.length.
        self.advance_to_next()
        # If outer = vector.length then there are no integers left, otherwise
        # we've stopped at an integer and so there's an integer left.
        return self.outer < len(self.vector)
```

</details>
