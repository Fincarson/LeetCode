# 1337. The K Weakest Rows in a Matrix

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/)  
`Array` `Binary Search` `Sorting` `Heap (Priority Queue)` `Matrix`

**Problem Link:** [LeetCode 1337 - The K Weakest Rows in a Matrix](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/)

## Problem

You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

- The number of soldiers in row i is less than the number of soldiers in row j.
- Both rows have the same number of soldiers and i < j.

Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

### Example 1

```text
Input: mat =
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]],
k = 3
Output: [2,0,3]
Explanation:
The number of soldiers in each row is:
- Row 0: 2
- Row 1: 4
- Row 2: 1
- Row 3: 2
- Row 4: 5
The rows ordered from weakest to strongest are [2,0,3,1,4].
```

### Example 2

```text
Input: mat =
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]],
k = 2
Output: [0,2]
Explanation:
The number of soldiers in each row is:
- Row 0: 1
- Row 1: 4
- Row 2: 1
- Row 3: 1
The rows ordered from weakest to strongest are [0,2,3,1].
```

## Constraints

- m == mat.length
- n == mat[i].length
- 2 <= n, m <= 100
- 1 <= k <= m
- matrix[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1337. The K Weakest Rows in a Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Search and Sorting | Java, Python3 |
| Linear Search and Map | Java, Python3 |
| Binary Search and Sorting/ Map | Java, Python3 |
| Binary Search and Priority Queue | Java, Python3 |
| Vertical Iteration | Java, Python3 |

## Approach 1: Linear Search and Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;

        // Calculate all the strengths and put strength/ index pairs into an array.
        int[][] pairs = new int[m][2];

        for (int i = 0; i < m; i++) {
            int strength = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) break;
                strength++;
            }
            pairs[i][0] = strength;
            pairs[i][1] = i;
        }

        /* Sort the pairs, firstly on strength and secondly on index. We'll need
         * to implement a comparator to do this. */
        Arrays.sort(pairs, (a, b) -> {
            if (a[0] == b[0]) return a[1] - b[1];
            else return a[0] - b[0];
        });

        // Pull out the first k indexes of the sorted array to return.
        int[] indexes = new int[k];
        for (int i = 0; i < k; i++) {
            indexes[i] = pairs[i][1];
        }
        return indexes;

    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:

    # Note that there is a more conscise solution just below. This code
    # avoids the use of advanced language features.

    m = len(mat)
    n = len(mat[0])

    # Calculate the strength of each row.
    strengths = []
    for i, row in enumerate(mat):
        strength = 0
        for j in range(n):
            if row[j] == 0: break
            strength += 1
        strengths.append((strength, i))

    # Sort all the strengths. This will sort firstly by strength
    # and secondly by index.
    strengths.sort()

    # Pull out and return the indexes of the smallest k entries.
    indexes = []
    for i in range(k):
        indexes.append(strengths[i][1])
    return indexes
```

</details>

<br>

## Approach 2: Linear Search and Map

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {

        int m = mat.length;
        int n = mat[0].length;

        // Calculate all the strengths and put them into a HashMap.
        Map<Integer, List<Integer>> strengths = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int strength = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) break;
                strength++;
            }
            if (!strengths.containsKey(strength)) {
                strengths.put(strength, new ArrayList<>());
            }
            strengths.get(strength).add(i);
        }

        // Note that if we'd used a TreeMap instead of HashMap, the keys would
        // have already been sorted.
        List<Integer> sortedStrengths = new ArrayList<>(strengths.keySet());
        Collections.sort(sortedStrengths);

        // Pull out indexes for the k smallest strengths.
        int[] indexes = new int[k];
        int i = 0;
        for (int key : sortedStrengths) {
            for (int index : strengths.get(key)) {
                indexes[i] = index;
                i++;
                if (i == k) break;
            }
            if (i == k) break;
        }

        return indexes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:

    m = len(mat)
    n = len(mat[0])

    # Calculate the strength of each row and put them in a dictionary.
    strengths = collections.defaultdict(list)
    for i, row in enumerate(mat):
        strength = 0
        for j in range(n):
            if row[j] == 0: break
            strength += 1
        strengths[strength].append(i)

    # Sort the keys.
    sorted_strengths = sorted(list(strengths.keys()))

    # Pull out and return the indexes of the smallest k entries.
    indexes = []
    for strength in sorted_strengths:
        for index in strengths[strength]:
            indexes.append(index)
            if len(indexes) == k: break
        if len(indexes) == k: break

    return indexes
```

</details>

<br>

## Approach 3: Binary Search and Sorting/ Map

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int binarySearch(int[] row) {
        int low = 0;
        int high = row.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == 1) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    public int[] kWeakestRows(int[][] mat, int k) {

        // Calculate all the strengths using Binary Search and
        // put them into a TreeMap.
        Map<Integer, List<Integer>> strengths = new HashMap<>();
        for (int i = 0; i < mat.length; i++) {
            int strength = binarySearch(mat[i]);
            if (!strengths.containsKey(strength)) {
                strengths.put(strength, new ArrayList<>());
            }
            strengths.get(strength).add(i);
        }

        // Note that if we'd used a TreeMap instead of HashMap, the keys would
        // have already been sorted.
        List<Integer> sortedStrengths = new ArrayList<>(strengths.keySet());
        Collections.sort(sortedStrengths);

        int[] indexes = new int[k];
        int i = 0;
        for (int key : sortedStrengths) {
            for (int index : strengths.get(key)) {
                indexes[i] = index;
                i++;
                if (i == k) break;
            }
            if (i == k) break;
        }

        return indexes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:

    n = len(mat[0])

    def binary_search(row):
        low = 0
        high = n
        while low < high:
            mid = low + (high - low) // 2
            if row[mid] == 1:
                low = mid + 1
            else:
                high = mid
        return low

    # Calculate the strength of each row using binary search.
    row_strengths = []
    for i, row in enumerate(mat):
        row_strengths.append((binary_search(row), i))

    # Sort all the strengths. This will sort firstly by strength
    # and secondly by index.
    row_strengths.sort()

    # Pull out and return the indexes of the smallest k entries.
    indexes = []
    for i in range(k):
        indexes.append(row_strengths[i][1])
    return indexes
```

</details>

<br>

## Approach 4: Binary Search and Priority Queue

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int binarySearch(int[] row) {
        int low = 0;
        int high = row.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == 1) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    public int[] kWeakestRows(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;

        // Create a Priority Queue that measures firstly on strength and then indexes.
        PriorityQueue<int[]> pq = new  PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) return b[1] - a[1];
            else return b[0] - a[0];
        });

        // Add strength/index pairs to the pq. Whenever length > k, remove the largest.
        for (int i = 0; i < m; i++) {
            int strength = binarySearch(mat[i]);
            int[] entry = new int[]{strength, i};
            pq.add(entry);
            if (pq.size() > k) {
                pq.poll();
            }
        }

        // Pull the indexes out of the priority queue.
        int[] indexes = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            int[] pair = pq.poll();
            indexes[i] = pair[1];
        }

        return indexes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import heapq

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:

        m = len(mat)
        n = len(mat[0])

        def binary_search(row):
            low = 0
            high = n
            while low < high:
                mid = low + (high - low) // 2
                if row[mid] == 1:
                    low = mid + 1
                else:
                    high = mid
            return low

        # Calculate the strength of each row using binary search.
        # Put the strength/index pairs into a priority queue.
        pq = []
        for i, row in enumerate(mat):
            strength = binary_search(row)
            entry = (-strength, -i)
            if len(pq) < k or entry > pq[0]:
                heapq.heappush(pq, entry)
            if len(pq) > k:
                heapq.heappop(pq)

        # Pull out and return the indexes of the smallest k entries.
        # Don't forget to convert them back to positive numbers!
        indexes = []
        while pq:
            strength, i = heapq.heappop(pq)
            indexes.append(-i)

        # Reverse, as the indexes are around the wrong way.
        indexes = indexes[::-1]

        return indexes
```

</details>

<br>

## Approach 5: Vertical Iteration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {

        int m = mat.length;
        int n = mat[0].length;

        int [] indexes = new int[k];
        int nextInsertIndex = 0;

        // This code does the same as the animation above.
        for (int c = 0; c < n && nextInsertIndex < k; c++) {
            for (int r = 0; r < m && nextInsertIndex < k; r++) {
                // If this is the first 0 in the current row.
                if (mat[r][c] == 0 && (c == 0 || mat[r][c - 1] == 1)) {
                    indexes[nextInsertIndex] = r;
                    nextInsertIndex++;
                }
            }
        }

        /* If there aren't enough, it's because some of the first k weakest rows
         * are entirely 1's. We need to include the ones with the lowest indexes
         * until we have at least k. */
        for (int r = 0; nextInsertIndex < k ; r++) {
            /* If index i in the last column is 1, this was a full row and therefore
             * couldn't have been included in the output yet. */
            if (mat[r][n - 1] == 1) {
                indexes[nextInsertIndex] = r;
                nextInsertIndex++;
            }
        }

        return indexes;

    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
    m = len(mat)
    n = len(mat[0])

    # This code does the same as the animation above.
    indexes = []
    # For each cell, accessed in the order shown in the animation.
    for c, r in itertools.product(range(n), range(m)):
        if len(indexes) == k: break
        # If this is the first 0 in the current row.
        if mat[r][c] == 0 and (c == 0 or mat[r][c - 1] == 1):
            indexes.append(r)

    # If there aren't enough, it's because some of the first k weakest rows
    # are entirely 1's. We need to include the ones with the lowest indexes
    # until we have at least k.
    i = 0
    while len(indexes) < k:
        # If index i in the last column is 1, this was a full row and therefore
        # couldn't have been included in the output yet.
        if mat[i][-1] == 1:
            indexes.append(i)
        i += 1

    return indexes
```

</details>
