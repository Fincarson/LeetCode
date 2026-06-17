# 281. Zigzag Iterator

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/zigzag-iterator/)  
`Array` `Design` `Queue` `Iterator`

**Problem Link:** [LeetCode 281 - Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator/)

## Problem

Given two vectors of integers v1 and v2, implement an iterator to return their elements alternately.

Implement the ZigzagIterator class:

- ZigzagIterator(List<int> v1, List<int> v2) initializes the object with the two vectors v1 and v2.
- boolean hasNext() returns true if the iterator still has elements, and false otherwise.
- int next() returns the current element of the iterator and moves the iterator to the next element.

### Example 1

```text
Input: v1 = [1,2], v2 = [3,4,5,6]
Output: [1,3,2,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,3,2,4,5,6].
```

### Example 2

```text
Input: v1 = [1], v2 = []
Output: [1]
```

### Example 3

```text
Input: v1 = [], v2 = [1]
Output: [1]
```

## Constraints

- 0 <= v1.length, v2.length <= 1000
- 1 <= v1.length + v2.length <= 2000
- -231 <= v1[i], v2[i] <= 231 - 1

Follow up: What if you are given k vectors? How well can your code be extended to such cases?

Clarification for the follow-up question:

The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic".

Follow-up Example:

```text
Input: v1 = [1,2,3], v2 = [4,5,6,7], v3 = [8,9]
Output: [1,4,8,2,5,9,3,6,7]
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Flatten 2D Vector](https://leetcode.com/problems/flatten-2d-vector/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Peeking Iterator](https://leetcode.com/problems/peeking-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 281. Zigzag Iterator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two-Pointers | Java, Python3 |
| Queue of Pointers | Java, Python3 |

## Approach 1: Two-Pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class ZigzagIterator {
    private List<List<Integer>> vectors = new ArrayList<>();
    // pointer to vector, and pointer to element
    private Integer pVec = 0, pElem = 0;
    private Integer totalNum = 0, outputCount = 0;

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        this.vectors.add(v1);
        this.vectors.add(v2);
        for (List<Integer> vec : this.vectors) {
            this.totalNum += vec.size();
        }
    }

    public int next() {
        Integer iterNum = 0, ret = null;
        while (iterNum < this.vectors.size()) {
            List<Integer> currVec = this.vectors.get(this.pVec);
            if (this.pElem < currVec.size()) {
                ret = currVec.get(this.pElem);
                this.outputCount += 1;
            }

            iterNum += 1;
            this.pVec = (this.pVec + 1) % this.vectors.size();
            // increment the element pointer once iterating all vectors
            if (this.pVec == 0)
                this.pElem += 1;

            if (ret != null)
                return ret;
        }
        // one should raise an exception here.
        return 0;
    }

    public boolean hasNext() {
        return this.outputCount < this.totalNum;
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such: ZigzagIterator i = new
 * ZigzagIterator(v1, v2); while (i.hasNext()) v[f()] = i.next();
 */
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.vectors = [v1, v2]
        self.p_elem = 0   # pointer to the index of element
        self.p_vec = 0    # pointer to the vector
        # variables for hasNext() function
        self.total_num = len(v1) + len(v2)
        self.output_count = 0

    def next(self) -> int:
        iter_num = 0
        ret = None

        # Iterate over the vectors
        while iter_num < len(self.vectors):
            curr_vec = self.vectors[self.p_vec]
            if self.p_elem < len(curr_vec):
                ret = curr_vec[self.p_elem]

            iter_num += 1
            self.p_vec = (self.p_vec + 1) % len(self.vectors)
            # increment the element pointer once iterating all vectors
            if self.p_vec == 0:
                self.p_elem += 1

            if ret is not None:
                self.output_count += 1
                return ret

        # no more element to output
        raise Exception


    def hasNext(self) -> bool:
        return self.output_count < self.total_num

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
```

</details>

<br>

## Approach 2: Queue of Pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class ZigzagIterator {
    private List<List<Integer>> vectors = new ArrayList<>();
    private LinkedList<Pair<Integer, Integer>> queue = new LinkedList<>();

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        this.vectors.add(v1);
        this.vectors.add(v2);
        int index = 0;
        for (List<Integer> vec : this.vectors) {
            if (vec.size() > 0)
                // <index_to_vec, index_to_element_within_vec>
                this.queue.add(new Pair<Integer, Integer>(index, 0));
            index++;
        }
    }

    public int next() {
        // if (this.queue.size() == 0)
        // throw new Exception("Out of elements!");

        // <index_to_vec, index_to_element_within_vec>
        Pair<Integer, Integer> pointer = this.queue.removeFirst();
        Integer vecIndex = pointer.getKey();
        Integer elemIndex = pointer.getValue();
        Integer nextElemIndex = elemIndex + 1;
        // append the pointer for the next round
        // if there are some elements left.
        if (nextElemIndex < this.vectors.get(vecIndex).size())
            this.queue.addLast(new Pair<>(vecIndex, nextElemIndex));

        return this.vectors.get(vecIndex).get(elemIndex);
    }

    public boolean hasNext() {
        return this.queue.size() > 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.vectors = [v1, v2]
        self.queue = deque()
        for index, vector in enumerate(self.vectors):
            # <index_of_vector, index_of_element_to_output>
            if len(vector) > 0:
                self.queue.append((index, 0))

    def next(self) -> int:

        if self.queue:
            vec_index, elem_index = self.queue.popleft()
            next_elem_index = elem_index + 1
            if next_elem_index < len(self.vectors[vec_index]):
                # append the pointer for the next round
                # if there are some elements left
                self.queue.append((vec_index, next_elem_index))

            return self.vectors[vec_index][elem_index]

        # no more element to output
        raise Exception

    def hasNext(self) -> bool:
        return len(self.queue) > 0
```

</details>
