# 284. Peeking Iterator

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/peeking-iterator/)  
`Array` `Design` `Iterator`

**Problem Link:** [LeetCode 284 - Peeking Iterator](https://leetcode.com/problems/peeking-iterator/)

## Problem

Design an iterator that supports the peek operation on an existing iterator in addition to the hasNext and the next operations.

Implement the PeekingIterator class:

- PeekingIterator(Iterator<int> nums) Initializes the object with the given integer iterator iterator.
- int next() Returns the next element in the array and moves the pointer to the next element.
- boolean hasNext() Returns true if there are still elements in the array.
- int peek() Returns the next element in the array without moving the pointer.

Note: Each language may have a different implementation of the constructor and Iterator, but they all support the int next() and boolean hasNext() functions.

### Example 1

```text
Input
["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 2, 2, 3, false]

Explanation
PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
peekingIterator.next();    // return 1, the pointer moves to the next element [1,2,3].
peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,3]
peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]
peekingIterator.hasNext(); // return False
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 1000
- All the calls to next and peek are valid.
- At most 1000 calls will be made to next, hasNext, and peek.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Flatten 2D Vector](https://leetcode.com/problems/flatten-2d-vector/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 284. Peeking Iterator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Saving Peeked Value | Java, Python |
| Saving the Next Value | Java, Python |

## Approach 1: Saving Peeked Value

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

import java.util.NoSuchElementException;

class PeekingIterator implements Iterator<Integer> {

    private Iterator<Integer> iter;
    private Integer peekedValue = null;

    public PeekingIterator(Iterator<Integer> iterator) {
        iter = iterator;
    }

    public Integer peek() {
        /* If there's not already a peeked value, get one out and store
         * it in the peekedValue variable. We aren't told what to do if
         * the iterator is actually empty -- here I have thrown an exception
         * but in an interview you should definitely ask! This is the kind of
         * thing they expect you to ask about. */
        if (peekedValue == null) {
            if (!iter.hasNext()) {
                throw new NoSuchElementException();
            }
            peekedValue = iter.next();
        }
        return peekedValue;
    }

    @Override
    public Integer next() {
        /* Firstly, we need to check if we have a value already
         * stored in the peekedValue variable. If we do, we need to
         * return it and also set peekedValue to null so that the value
         * isn't returned again. */
        if (peekedValue != null) {
            Integer toReturn = peekedValue;
            peekedValue = null;
            return toReturn;
        }
        /* As per the Java Iterator specs, we should throw a NoSuchElementException
         * if the next element doesn't exist. */
        if (!iter.hasNext()) {
            throw new NoSuchElementException();
        }
        /* Otherwise, we need to return a new value. */
        return iter.next();
    }

    @Override
    public boolean hasNext() {
        /* If there's a value waiting in peekedValue, or if there are values
         * remaining in the iterator, we should return true. */
        return peekedValue != null || iter.hasNext();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class PeekingIterator:
    def __init__(self, iterator):
        self._iterator = iterator
        self._peeked_value = None

    def peek(self):
        # If there's not already a peeked value, get one out and store
        # it in the _peeked_value variable. We aren't told what to do if
        # the iterator is actually empty -- here I have thrown an exception
        # but in an interview you should definitely ask! This is the kind of
        # thing they expect you to ask about.
        if self._peeked_value is None:
            if not self._iterator.hasNext():
                raise StopIteration()
            self._peeked_value = self._iterator.next()

        return self._peeked_value

    def next(self):
        # Firstly, we need to check if we have a value already
        # stored in the _peeked_value variable. If we do, we need to
        # return it and also set _peeked_value to null so that the value
        # isn't returned again.
        if self._peeked_value is not None:
            to_return = self._peeked_value
            self._peeked_value = None
            return to_return

        if not self._iterator.hasNext():
            raise StopIteration()

        # Otherwise, we need to return a new value.
        return self._iterator.next()

    def hasNext(self):
        # If there's a value waiting in _peeked_value, or if there are values
        # remaining in the iterator, we should return true.
        return self._peeked_value is not None or self._iterator.hasNext()
```

</details>

<br>

## Approach 2: Saving the Next Value

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

import java.util.NoSuchElementException;

class PeekingIterator implements Iterator<Integer> {

    private Iterator<Integer> iter;
    private Integer next = null;

    public PeekingIterator(Iterator<Integer> iterator) {
        // Avoid an exception being thrown in the constructor.
        if (iterator.hasNext()) {
            next = iterator.next();
        }
        iter = iterator;
    }

    public Integer peek() {
        return next;
    }

    @Override
    public Integer next() {
        /* As per the Java Iterator specs, we should throw a NoSuchElementException
         * if the next element doesn't exist. */
        if (next == null) {
            throw new NoSuchElementException();
        }
        Integer toReturn = next;
        next = null;
        if (iter.hasNext()) {
            next = iter.next();
        }
        return toReturn;
    }

    @Override
    public boolean hasNext() {
        return next != null;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class PeekingIterator:
    def __init__(self, iterator):
        self._next = iterator.next()
        self._iterator = iterator

    def peek(self):
        return self._next

    def next(self):
        if self._next is None:
            raise StopIteration()
        to_return = self._next
        self._next = None
        if self._iterator.hasNext():
            self._next = self._iterator.next()
        return to_return

    def hasNext(self):
        return self._next is not None
```

</details>
