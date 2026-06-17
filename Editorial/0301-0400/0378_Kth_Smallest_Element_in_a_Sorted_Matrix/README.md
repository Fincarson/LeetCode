# 378. Kth Smallest Element in a Sorted Matrix

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)  
`Array` `Binary Search` `Sorting` `Heap (Priority Queue)` `Matrix`

**Problem Link:** [LeetCode 378 - Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

## Problem

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

### Example 1

```text
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
```

### Example 2

```text
Input: matrix = [[-5]], k = 1
Output: -5
```

## Constraints

- n == matrix.length == matrix[i].length
- 1 <= n <= 300
- -109 <= matrix[i][j] <= 109
- All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
- 1 <= k <= n2

Follow up:

- Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
- Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 378. Kth Smallest Element in a Sorted Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Min-Heap approach | Java, Python3 |
| Binary Search | Java, Python3 |

## Approach 1: Min-Heap approach

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class MyHeapNode {

  int row;
  int column;
  int value;

  public MyHeapNode(int v, int r, int c) {
    this.value = v;
    this.row = r;
    this.column = c;
  }

  public int getValue() {
    return this.value;
  }

  public int getRow() {
    return this.row;
  }

  public int getColumn() {
    return this.column;
  }
}

class MyHeapComparator implements Comparator<MyHeapNode> {
  public int compare(MyHeapNode x, MyHeapNode y) {
    return x.value - y.value;
  }
}

class Solution {

  public int kthSmallest(int[][] matrix, int k) {

    int N = matrix.length;

    PriorityQueue<MyHeapNode> minHeap =
        new PriorityQueue<MyHeapNode>(Math.min(N, k), new MyHeapComparator());

    // Preparing our min-heap
    for (int r = 0; r < Math.min(N, k); r++) {

      // We add triplets of information for each cell
      minHeap.offer(new MyHeapNode(matrix[r][0], r, 0));
    }

    MyHeapNode element = minHeap.peek();
    while (k-- > 0) {

      // Extract-Min
      element = minHeap.poll();
      int r = element.getRow(), c = element.getColumn();

      // If we have any new elements in the current row, add them
      if (c < N - 1) {

        minHeap.offer(new MyHeapNode(matrix[r][c + 1], r, c + 1));
      }
    }

    return element.getValue();
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import heapq

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        
        # The size of the matrix
        N = len(matrix)
        
        # Preparing our min-heap
        minHeap = []
        for r in range(min(k, N)):
            
            # We add triplets of information for each cell
            minHeap.append((matrix[r][0], r, 0))
        
        # Heapify our list
        heapq.heapify(minHeap)    
        
        # Until we find k elements
        while k:
            
            # Extract-Min
            element, r, c = heapq.heappop(minHeap)
            
            # If we have any new elements in the current row, add them
            if c < N - 1:
                heapq.heappush(minHeap, (matrix[r][c+1], r, c+1))
            
            # Decrement k
            k -= 1
        
        return element
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

  public int kthSmallest(int[][] matrix, int k) {

    int n = matrix.length;
    int start = matrix[0][0], end = matrix[n - 1][n - 1];
    while (start < end) {

      int mid = start + (end - start) / 2;
      // first number is the smallest and the second number is the largest
      int[] smallLargePair = {matrix[0][0], matrix[n - 1][n - 1]};

      int count = this.countLessEqual(matrix, mid, smallLargePair);

      if (count == k) return smallLargePair[0];

      if (count < k) start = smallLargePair[1]; // search higher
      else end = smallLargePair[0]; // search lower
    }
    return start;
  }

  private int countLessEqual(int[][] matrix, int mid, int[] smallLargePair) {

    int count = 0;
    int n = matrix.length, row = n - 1, col = 0;

    while (row >= 0 && col < n) {

      if (matrix[row][col] > mid) {

        // as matrix[row][col] is bigger than the mid, let's keep track of the
        // smallest number greater than the mid
        smallLargePair[1] = Math.min(smallLargePair[1], matrix[row][col]);
        row--;

      } else {

        // as matrix[row][col] is less than or equal to the mid, let's keep track of the
        // biggest number less than or equal to the mid
        smallLargePair[0] = Math.max(smallLargePair[0], matrix[row][col]);
        count += row + 1;
        col++;
      }
    }

    return count;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    
    def countLessEqual(self, matrix, mid, smaller, larger):
        
        count, n = 0, len(matrix)
        row, col = n - 1, 0
        
        while row >= 0 and col < n:
            if matrix[row][col] > mid:
               
                # As matrix[row][col] is bigger than the mid, let's keep track of the
                # smallest number greater than the mid
                larger = min(larger, matrix[row][col])
                row -= 1
                
            else:
                
                # As matrix[row][col] is less than or equal to the mid, let's keep track of the
                # biggest number less than or equal to the mid
                
                smaller = max(smaller, matrix[row][col])
                count += row + 1
                col += 1

        return count, smaller, larger
    
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        
        n = len(matrix)
        start, end = matrix[0][0], matrix[n - 1][n - 1]
        while start < end:
            mid = start + (end - start) / 2
            smaller, larger = (matrix[0][0], matrix[n - 1][n - 1])

            count, smaller, larger = self.countLessEqual(matrix, mid, smaller, larger)

            if count == k:
                return smaller
            if count < k:
                start = larger  # search higher
            else:
                end = smaller  # search lower

        return start
```

</details>
