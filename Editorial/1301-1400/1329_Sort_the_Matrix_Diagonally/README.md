# 1329. Sort the Matrix Diagonally

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sort-the-matrix-diagonally/)  
`Array` `Sorting` `Matrix`

**Problem Link:** [LeetCode 1329 - Sort the Matrix Diagonally](https://leetcode.com/problems/sort-the-matrix-diagonally/)

## Problem

A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

### Example 1

```text
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
```

### Example 2

```text
Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
```

## Constraints

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 100
- 1 <= mat[i][j] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Matrix by Diagonals](https://leetcode.com/problems/sort-matrix-by-diagonals/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1329. Sort the Matrix Diagonally

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Table of Heaps | C++, Java, Python3 |
| Sort Diagonals One by One Using Heap | C++, Java, Python3 |
| Sort Diagonals One by One Using Counting Sort | C++, Java, Python3 |

## Approach 1: Hash Table of Heaps

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // Store the matrix dimensions
        size_t m = mat.size();
        size_t n = mat[0].size();

        // create a hasmap of min-heaps to store the diagonals
        map<int, priority_queue<int, vector<int>, greater<int>>> diagonals;

        // Insert the values into the Hash Map
        for (size_t row = 0; row < m; row++) {
            for (size_t col = 0; col < n; col++) {
                // Observing that on each diagonal, the differences between the row and column
                // indices of each element is the same.
                // Hence we can use row - col as the key to collect elements on the same diagonal.
                diagonals[row - col].push(mat[row][col]);
            }
        }

        // Take values back out of the Hash Map
        for (size_t row = 0; row < m; row++) {
            for (size_t col = 0; col < n; col++) {
                mat[row][col] = diagonals[row - col].top();
                diagonals[row - col].pop();
            }
        }

        return mat;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] diagonalSort(int[][] mat) {
        // Store the matrix dimensions
        int m = mat.length;
        int n = mat[0].length;
        
        // Data structure to store the diagonals.
        Map<Integer, Queue<Integer>> diagonals = new HashMap<>();
        
        // Insert values into the HashMap.
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) { 
                diagonals.putIfAbsent(row - col, new PriorityQueue<>());
                diagonals.get(row - col).add(mat[row][col]);
            }   
        }

        // Take values back out of the HashMap.
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                mat[row][col] = diagonals.get(row - col).remove();
            }
        }
        
        return mat;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        # Store the matrix dimensions
        m = len(mat)
        n = len(mat[0])

        # Hash Map to store the diagonals. We will use a list
        # for now, but then heapify each list before taking them out.
        diagonals = defaultdict(list)

        # Insert values into the Hash Map.
        for row in range(m):
            for col in range(n):
                # Observing that on each diagonal, the differences between the row and column indices
                # of each element is the same.
                # Hence we can use row - col as the key to collect elements on the same diagonal.
                diagonals[row - col].append(mat[row][col])
                
        # Heapify each list in the Hash Map.
        for diagonal in diagonals.values():
            heapq.heapify(diagonal)

        # Take values back out of the Hash Map.
        for row in range(m):
            for col in range(n):
                value = heapq.heappop(diagonals[row - col])
                mat[row][col] = value
        
        return mat
```

</details>

<br>

## Approach 2: Sort Diagonals One by One Using Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // Store the matrix dimensions.
        size_t m = mat.size();
        size_t n = mat[0].size();

        // Sort each diagonal that starts on a row.
        for (size_t row = 0; row < m; row++) {
            sortDiagonal(row, 0, mat);
        }

        // Sort each diagonal that starts on a col.
        // Note that we've already sorted the one starting
        // at col = 0; this is the same as the one starting
        // at row = 0.
        for (size_t col = 0; col < n; col++) {
            sortDiagonal(0, col, mat);
        }

        return mat;
    }

    // Helper function to sort the current diagonal at row, col
    void sortDiagonal(size_t row, size_t col, vector<vector<int>>& mat) {
        size_t m = mat.size();
        size_t n = mat[0].size();

        // create a min-heap to store the diagonal
        priority_queue<int, vector<int>, greater<int>> diagonal;

        size_t diagonal_length = min(m - row, n - col);
        // Put values on this diagonal into the heap.
        for (size_t i = 0; i < diagonal_length; i++) {
            diagonal.push(mat[row + i][col + i]);
        }

        // Put values on heap back into this diagonal
        for (size_t i = 0; i < diagonal_length; i++) {
            mat[row + i][col + i] = diagonal.top();
            diagonal.pop();
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    public int[][] diagonalSort(int[][] mat) {
        // Store the matrix dimensions.
        int m = mat.length;
        int n = mat[0].length;
        
        // Sort each diagonal that starts on a row.
        for (int row = 0; row < m; row++) {
            sortDiagonal(row, 0, mat);       
        } 

        // Sort each diagonal that starts on a col.
        // Note that we've already sorted the one starting
        // at col = 0; this is the same as the one starting
        // at row = 0.
        for (int col = 1; col < n; col++) {
            sortDiagonal(0, col, mat);  
        } 
        
        return mat;
    }

    private void sortDiagonal(int row, int col, int[][] mat) {
        int m = mat.length; 
        int n = mat[0].length;
        Queue<Integer> diagonal = new PriorityQueue<>();
        
        int diagonalLength = Math.min(m - row, n - col);
        // Put values on this diagonal into the heap.
        for (int i = 0; i < diagonalLength; i++) {
            diagonal.add(mat[row + i][col + i]);
        }
        // Put values on heap back into this diagonal
        for (int i = 0; i < diagonalLength; i++) {
            mat[row + i][col + i] = diagonal.remove();
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        
        # Store the matrix dimensions.
        m = len(mat)
        n = len(mat[0])

        # Helper function to sort a single diagonal at row, col
        def sortDiagonal(row, col):
            # Like before, we'll put all of the values into a list
            # before we heapify it.
            diagonal = []
            diagonal_length = min(m - row, n - col)
            
            # Put values in this diagonal into the list.
            for i in range(diagonal_length):
                diagonal.append(mat[row + i][col + i])

            # Heapify this diagonal.
            heapq.heapify(diagonal)

            # Put values in this diagonal back into matrix.
            for i in range(diagonal_length):
                mat[row + i][col + i] = heapq.heappop(diagonal)

        # Sort each diagonal that starts on a row.
        for row in range(m):
            sortDiagonal(row, 0)

        # Sort each diagonal that starts on a col.
        # Note that we've already sorted the one starting
        # at col = 0; this is the same as the one starting
        # at row = 0.
        for col in range(1, n):
            sortDiagonal(0, col)

        return mat
```

</details>

<br>

## Approach 3: Sort Diagonals One by One Using Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        size_t m = mat.size();
        size_t n = mat[0].size();

        for (size_t row = 0; row < m; row++) {
            sortDiagonal(row, 0, mat);
        }

        for (size_t col = 0; col < n; col++) {
            sortDiagonal(0, col, mat);
        }

        return mat;
    }

    vector<int> countingSort(vector<int> nums) {
        // The problem constraints allow us to assume that
        // 1 <= mat[i][j] <= 100.
        // You should, however, confirm with the interviewer
        // that it is OK to hardcode values like this.
        int min = 1;    // You could also use: *min_element(nums.begin(), nums.end());
        int max = 100;  // You could also use: *max_element(nums.begin(), nums.end());

        // Calculate the range of values, and then create an array
        // of the size of the range.
        int len = max - min + 1;
        int count[len];
        // Tally up the values in nums.
        for (int num : nums) {
            count[num - min]++;
        }

        // Flatten the list of counts into a sorted vector.
        vector<int> sortedNums;
        for (int i = 0; i < len; i++) {
            for (int times = count[i]; times > 0; times--) {
                sortedNums.push_back(i + min);
            }
        }

        return sortedNums;
    }

    // sort the current diagonal
    void sortDiagonal(size_t row, size_t col, vector<vector<int>>& mat) {
        size_t m = mat.size();
        size_t n = mat[0].size();

        // store the current diagonal values into a vector
        vector<int> diagonal;

        size_t diagonal_length = min(m - row, n - col);
        for (size_t i = 0; i < diagonal_length; i++) {
            diagonal.push_back(mat[row + i][col + i]);
        }

        // sort the vector of diagonal values
        sort(diagonal.begin(), diagonal.end());

        // build the output for the current diagonal
        for (size_t i = 0; i < diagonal_length; i++) {
            mat[row + i][col + i] = diagonal[i];
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        for (int row = 0; row < m; row++) {
            sortDiagonal(row, 0, mat);
        }

        for (int col = 1; col < n; col++) {
            sortDiagonal(0, col, mat);
        }

        return mat;
    }

    private List<Integer> countingSort(List<Integer> nums) {
        // The problem constraints allow us to assume that
        // 1 <= mat[i][j] <= 100.
        // You should, however, confirm with the interviewer
        // that it is OK to hardcode values like this.
        int min = 1; // You could also use: Collections.min(nums); 
        int max = 100; // You could also use: Collections.max(nums);
        
        // Calculate the range of values, and then create a list
        // of the size of the range.
        int len = max - min + 1;
        int[] count = new int[len];
        // Tally up the values in nums.
        for (int num : nums) {
            count[num - min]++;
        }

        // Flatten the list of counts into a sorted list.
        List<Integer> sortedNums = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            for (int times = count[i]; times > 0; times--) {
                sortedNums.add(i + min);
            }
        }

        return sortedNums;
    }

    private void sortDiagonal(int row, int col, int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        List<Integer> diagonal = new ArrayList<>();

        int diagonalLength = Math.min(m - row, n - col);
        for (int i = 0; i < diagonalLength; i++) {
            diagonal.add(mat[row + i][col + i]);
        }

        // Sort the diagonal using our counting sort method.
        diagonal = countingSort(diagonal);

        for (int i = 0; i < diagonalLength; i++) {
            mat[row + i][col + i] = diagonal.remove(0);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        # Helper function to sort a single diagonal at row, col
        def sortDiagonal(row, col):
            diagonal = []
            diagonal_length = min(m - row, n - col)
            
            # Put values in this diagonal into the list.
            for i in range(diagonal_length):
                diagonal.append(mat[row + i][col + i])

            # Sort the diagonal using our counting sort function.
            diagonal = countingSort(diagonal)

            # Put values in this diagonal back into matrix.
            for i in range(diagonal_length):
                mat[row + i][col + i] = heapq.heappop(diagonal)

        # Helper function to peform a counting sort on a single 
        # list of nums.
        def countingSort(nums):
            # The problem constraints allow us to assume that
            # 1 <= mat[i][j] <= 100.
            # You should, however, confirm with the interviewer
            # that it is OK to hardcode values like this.
            minimum = 1 # You could also use: min(nums)
            maximum = 100 # You could also use: max(nums)

            # We can use a counter to do the counting for us.
            counts = Counter(nums)
            
            # And now we need to flatten the list of counts into
            # a sorted list.
            sorted_nums = []
            for i in range(minimum, maximum + 1):
                sorted_nums.extend([i] * counts[i])
            return sorted_nums

        # Same as previous approach, we're iterating through
        # each diagonal.
        for row in range(m):
            sortDiagonal(row, 0)

        for col in range(1, n):
            sortDiagonal(0, col)

        return mat
```

</details>
