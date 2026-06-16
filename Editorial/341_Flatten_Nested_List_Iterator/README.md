# 341. Flatten Nested List Iterator

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/flatten-nested-list-iterator/)  
`Stack` `Tree` `Depth-First Search` `Design` `Queue` `Iterator`

**Problem Link:** [LeetCode 341 - Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/)

## Problem

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the NestedIterator class:

- NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
- int next() Returns the next integer in the nested list.
- boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.

Your code will be tested with the following pseudocode:

```text
initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
```

If res matches the expected flattened list, then your code will be judged as correct.

### Example 1

```text
Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
```

### Example 2

```text
Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
```

## Constraints

- 1 <= nestedList.length <= 500
- The values of the integers in the nested list is in the range [-106, 106].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Flatten 2D Vector](https://leetcode.com/problems/flatten-2d-vector/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Mini Parser](https://leetcode.com/problems/mini-parser/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Array Nesting](https://leetcode.com/problems/array-nesting/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 341. Flatten Nested List Iterator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Make a Flat List with Recursion | Java, JavaScript, Python |
| Stack | Java, JavaScript, Python |
| Two Stacks | Java, JavaScript, Python |
| Stack of Iterators | Java |
| Using a Generator | JavaScript, Python |

## Approach 1: Make a Flat List with Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.NoSuchElementException;

public class NestedIterator implements Iterator<Integer> {
    
    private List<Integer> integers = new ArrayList<Integer>();
    private int position = 0; // Pointer to next integer to return.
    
    public NestedIterator(List<NestedInteger> nestedList) {
        flattenList(nestedList);
    }

    // Recursively unpacks a nested list in DFS order.
    private void flattenList(List<NestedInteger> nestedList) {
        for (NestedInteger nestedInteger : nestedList) {
            if (nestedInteger.isInteger()) {
                integers.add(nestedInteger.getInteger());
            } else {
                flattenList(nestedInteger.getList());
            }
        }
    }
    
    @Override
    public Integer next() {
        // As per Java specs, we should throw an exception if no more ints.
        if (!hasNext()) throw new NoSuchElementException();
        // Return int at current position, and then *after*, increment position.
        return integers.get(position++);
    }

    @Override
    public boolean hasNext() {
        return position < integers.size();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class NestedIterator {
    _integers_ = [];
    _position = 0;

    constructor(nestedList) {
        this._flattenList(nestedList)
    }

    _flattenList(nestedList) {
        for (const nestedInteger of nestedList) {
            if (nestedInteger.isInteger()) {
                this._integers.push(nestedInteger.getInteger());
            } else {
                this._flattenList(nestedInteger.getList());
            }
        }
    }

    hasNext() {
        return this._position < this._integers.length;
    }

    next() {
        if (!this.hasNext()) return undefined;
        
        return this._integers[this._position++];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class NestedIterator:
    
    def __init__(self, nestedList: [NestedInteger]):
        def flatten_list(nested_list):
            for nested_integer in nested_list:
                if nested_integer.isInteger():
                    self._integers.append(nested_integer.getInteger())
                else:
                    flatten_list(nested_integer.getList()) 
        self._integers = []
        self._position = -1 # Pointer to previous returned.
        flatten_list(nestedList)
    
    def next(self) -> int:
        self._position += 1
        return self._integers[self._position]
        
    def hasNext(self) -> bool:
        return self._position + 1 < len(self._integers)
```

</details>

<br>

## Approach 2: Stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.NoSuchElementException;

public class NestedIterator implements Iterator<Integer> {

    // In Java, the Stack class is considered deprecated. Best practice is to use
    // a Deque instead. We'll use addFirst() for push, and removeFirst() for pop.
    private Deque<NestedInteger> stack;
    
    public NestedIterator(List<NestedInteger> nestedList) {
        // The constructor puts them on in the order we require. No need to reverse.
        stack = new ArrayDeque(nestedList);
    }
        
    
    @Override
    public Integer next() {
        // As per java specs, throw an exception if there's no elements left.
        if (!hasNext()) throw new NoSuchElementException();
        // hasNext ensures the stack top is now an integer. Pop and return
        // this integer.
        return stack.removeFirst().getInteger();
    }

    
    @Override
    public boolean hasNext() {
        // Check if there are integers left by getting one onto the top of stack.
        makeStackTopAnInteger();
        // If there are any integers remaining, one will be on the top of the stack,
        // and therefore the stack can't possibly be empty.
        return !stack.isEmpty();
    }


    private void makeStackTopAnInteger() {
        // While there are items remaining on the stack and the front of 
        // stack is a list (i.e. not integer), keep unpacking.
        while (!stack.isEmpty() && !stack.peekFirst().isInteger()) {
            // Put the NestedIntegers onto the stack in reverse order.
            List<NestedInteger> nestedList = stack.removeFirst().getList();
            for (int i = nestedList.size() - 1; i >= 0; i--) {
                stack.addFirst(nestedList.get(i));
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function pushReverse(array, items) {
    for (let i = items.length - 1; i >= 0; i--) {
        array.push(items[i]);
    }
}

function last(array) {
    return array[array.length - 1];
}

class NestedIterator {
    constructor(nestedList) {
        this._stack = [];
        pushReverse(this._stack, nestedList);
    }
    
    next() {
        this._makeStackTopAnInteger();
        const integer = this._stack.pop();
        if (integer === undefined) {
            return undefined;
        }
        return integer.getInteger();
    }
    
    hasNext() {
        this._makeStackTopAnInteger();
        return this._stack.length > 0;
    }
    
    _makeStackTopAnInteger() {
        // While the stack contains a nested list at the top...
        while (this._stack.length > 0 && !last(this._stack).isInteger()) {
            // Unpack the list at the top by putting its items onto
            // the stack in reverse order.
            const list = this._stack.pop().getList();
            pushReverse(this._stack, list);
        }
    }       
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class NestedIterator:
    
    def __init__(self, nestedList: [NestedInteger]):
        self.stack = list(reversed(nestedList))
        
        
    def next(self) -> int:
        self.make_stack_top_an_integer()
        return self.stack.pop().getInteger()
    
        
    def hasNext(self) -> bool:
        self.make_stack_top_an_integer()
        return len(self.stack) > 0
        
        
    def make_stack_top_an_integer(self):
        # While the stack contains a nested list at the top...
        while self.stack and not self.stack[-1].isInteger():
            # Unpack the list at the top by putting its items onto
            # the stack in reverse order.
            self.stack.extend(reversed(self.stack.pop().getList()))
```

</details>

<br>

## Approach 3: Two Stacks

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.NoSuchElementException;

public class NestedIterator implements Iterator<Integer> {

    private Deque<List<NestedInteger>> listStack = new ArrayDeque<>();
    private Deque<Integer> indexStack = new ArrayDeque<>();
    
    public NestedIterator(List<NestedInteger> nestedList) {
        listStack.addFirst(nestedList);
        indexStack.addFirst(0);
    }
        
    @Override
    public Integer next() {
        if (!hasNext()) throw new NoSuchElementException();
        int currentPosition = indexStack.removeFirst();
        indexStack.addFirst(currentPosition + 1);
        return listStack.peekFirst().get(currentPosition).getInteger();
    }

    
    @Override
    public boolean hasNext() {
        makeStackTopAnInteger();
        return !indexStack.isEmpty();
    }


    private void makeStackTopAnInteger() {
    
        while (!indexStack.isEmpty()) {
                        
            // If the top list is used up, pop it and its index.
            if (indexStack.peekFirst() >= listStack.peekFirst().size()) {
                indexStack.removeFirst();
                listStack.removeFirst();
                continue;
            }

            // Otherwise, if it's already an integer, we don't need to do anything.
            if (listStack.peekFirst().get(indexStack.peekFirst()).isInteger()) {
                break;
            }

            // Otherwise, it must be a list. We need to update the previous index
            // and then add the new list with an index of 0.
            listStack.addFirst(listStack.peekFirst().get(indexStack.peekFirst()).getList());
            indexStack.addFirst(indexStack.removeFirst() + 1);
            indexStack.addFirst(0);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function last(array) {
    return array[array.length - 1];
}

class NestedIterator {
    constructor(nestedList) {
        this._stack = [[nestedList, 0]];
    }

    _makeStackTopAnInteger() {
        while (this._stack.length > 0) {
            const [currentList, currentIndex] = last(this._stack);
            
            // If the top list is used up, pop it and its index.
            if (currentList.length === currentIndex) {
                this._stack.pop();
                continue;
            }
            
            // Otherwise, if it's already an integer, we don't need 
            // to do anything.
            if (currentList[currentIndex].isInteger()) {
                break;
            }
            
            // Otherwise, it must be a list. We need to increment the index
            // on the previous list, and add the new list.
            const newList = currentList[currentIndex].getList();
            last(this._stack)[1] += 1; // Increment old
            this._stack.push([newList, 0]);
        }
    }

    next() {
        this._makeStackTopAnInteger();
        const [currentList, currentIndex] = last(this._stack);
        last(this._stack)[1] += 1;
        return currentList[currentIndex].getInteger();
    }

    hasNext() {
        this._makeStackTopAnInteger();
        return this._stack.length > 0;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class NestedIterator:
    
    def __init__(self, nestedList: [NestedInteger]):
        self.stack = [[nestedList, 0]]
        
    def make_stack_top_an_integer(self):
        
        while self.stack:
            
            # Essential for readability :)
            current_list = self.stack[-1][0]
            current_index = self.stack[-1][1]
            
            # If the top list is used up, pop it and its index.
            if len(current_list) == current_index:
                self.stack.pop()
                continue
            
            # Otherwise, if it's already an integer, we don't need 
            # to do anything.
            if current_list[current_index].isInteger():
                break
            
            # Otherwise, it must be a list. We need to increment the index
            # on the previous list, and add the new list.
            new_list = current_list[current_index].getList()
            self.stack[-1][1] += 1 # Increment old.
            self.stack.append([new_list, 0])
            
    
    def next(self) -> int:
        self.make_stack_top_an_integer()
        current_list = self.stack[-1][0]
        current_index = self.stack[-1][1]
        self.stack[-1][1] += 1
        return current_list[current_index].getInteger()
        
    
    def hasNext(self) -> bool:
        self.make_stack_top_an_integer()
        return len(self.stack) > 0
```

</details>

<br>

## Approach 4: Stack of Iterators

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.NoSuchElementException;

public class NestedIterator implements Iterator<Integer> {
    
    // This time, our stack will hold list iterators instead of just lists.
    private Deque<ListIterator<NestedInteger>> stackOfIterators = new ArrayDeque();
    private Integer peeked = null;

    public NestedIterator(List<NestedInteger> nestedList) {
        // Make an iterator with the input and put it on the stack. 
        // Note that creating a list iterator is an O(1) operation.
        stackOfIterators.addFirst(nestedList.listIterator());
    }

    private void setPeeked() {
        
        // If peeked is already set, there's nothing to do.
        if (peeked != null) return;
        
        while (!stackOfIterators.isEmpty()) {
            
            // If the iterator at the top of the stack doesn't have a next,
            // remove that iterator and continue on.
            if (!stackOfIterators.peekFirst().hasNext()) {
                stackOfIterators.removeFirst();
                continue;
            }
            
            // Otherwise, we need to check whether that next is a list or 
            // an integer.
            NestedInteger next = stackOfIterators.peekFirst().next();
            
            // If it's an integer, set peeked to it and return as we're done.
            if (next.isInteger()) {
                peeked = next.getInteger();
                return;
            }
            
            // Otherwise, it's a list. Create a new iterator with it, and put
            // the new iterator on the top of the stack.
            stackOfIterators.addFirst(next.getList().listIterator());
        }        
    }
    

    @Override
    public Integer next() {
        
        // As per Java specs, throw an exception if there are no further elements.
        if (!hasNext()) throw new NoSuchElementException();
        
        // hasNext() called setPeeked(), which ensures peeked has the next integer 
        // in it. We need to clear the peeked field so that the element is returned
        // again.
        Integer result = peeked;
        peeked = null;
        return result;
    }

    @Override
    public boolean hasNext() {

        // Try to set the peeked field. If any integers are remaining, it will
        // contain the next one to be returned after this call.
        setPeeked();
        
        // There are elements remaining iff peeked contains a value.
        return peeked != null;
    }
}
```

</details>

<br>

## Approach 5: Using a Generator

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class NestedIterator {
    _generator;
    _peeked = null;

    constructor(nestedList) {
        // This is the generator function. It can be used to create generator
        // objects. In JavaScript, the * means generator function.
        function* intGenerator(nestedList) {
            // This code is the same as Approach 1. It's a recursive DFS.
            for (const nestedInteger of nestedList) {
                if (nestedInteger.isInteger()) {
                    yield nestedInteger.getInteger();
                } else {
                    yield* intGenerator(nestedInteger.getList());
                }
            }
        }
        
        // Get a generator object from the generator function, passing in
        // nestedList as the parameter.
        this._generator = intGenerator(nestedList);
    }

    hasNext() {
        if (this._peeked !== null) return true;

        const { value, done } = this._generator.next();
        if (done) return false;
        this._peeked = value;
        return true;
    }

    next() {
        if (!this.hasNext()) return undefined;

        const nextValue = this._peeked;
        this._peeked = null;
        return nextValue;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class NestedIterator:

    def __init__(self, nestedList: [NestedInteger]):
        # Get a generator object from the generator function, passing in
        # nestedList as the parameter.
        self._generator = self._int_generator(nestedList)
        # All values are placed here before being returned.
        self._peeked = None

    # This is the generator function. It can be used to create generator
    # objects.
    def _int_generator(self, nested_list) -> "Generator[int]":
        # This code is the same as Approach 1. It's a recursive DFS.
        for nested in nested_list:
            if nested.isInteger():
                yield nested.getInteger()
            else:
                # We always use "yield from" on recursive generator calls.
                yield from self._int_generator(nested.getList())
        # Will automatically raise a StopIteration.
    
    def next(self) -> int:
        # Check there are integers left, and if so, then this will
        # also put one into self._peeked.
        if not self.hasNext(): return None
        # Return the value of self._peeked, also clearing it.
        next_integer, self._peeked = self._peeked, None
        return next_integer
        
    def hasNext(self) -> bool:
        if self._peeked is not None: return True
        try: # Get another integer out of the generator.
            self._peeked = next(self._generator)
            return True
        except: # The generator is finished so raised StopIteration.
            return False
```

</details>
