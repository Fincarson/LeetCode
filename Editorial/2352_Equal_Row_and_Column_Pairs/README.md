# 2352. Equal Row and Column Pairs

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/equal-row-and-column-pairs/)  
`Array` `Hash Table` `Matrix` `Simulation`

**Problem Link:** [LeetCode 2352 - Equal Row and Column Pairs](https://leetcode.com/problems/equal-row-and-column-pairs/)

## Problem

Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

### Example 1

```text
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
```

### Example 2

```text
Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
```

## Constraints

- n == grid.length == grid[i].length
- 1 <= n <= 200
- 1 <= grid[i][j] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Delete Greatest Value in Each Row](https://leetcode.com/problems/delete-greatest-value-in-each-row/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2352. Equal Row and Column Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python3 |
| Hash Map | Java, Python |
| Trie | Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int equalPairs(int[][] grid) {
        int count = 0, n = grid.length;
        
        // Check each row r against each column c.
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                boolean match = true;

                // Iterate over row r and column c.
                for (int i = 0; i < n; ++i) {
                    if (grid[r][i] != grid[i][c]) {
                        match = false;
                        break;
                    }
                }

                // If row r equals column c, increment count by 1.
                count += match ? 1 : 0;
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
    def equalPairs(self, grid: List[List[int]]) -> int:
        count = 0
        n = len(grid)
        
        # Check each row r against each column c.
        for r in range(n):
            for c in range(n):
                match = True
                
                # Iterate over row r and column c.
                for i in range(n):
                    if grid[r][i] != grid[i][c]:
                        match = False
                        break
                        
                # If row r equals column c, increment count by 1.
                count += int(match)
                    
        return count
```

</details>

<br>

## Approach 2: Hash Map

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int equalPairs(int[][] grid) {
        int count = 0;
        int n = grid.length;

        // Keep track of the frequency of each row.
        Map<String, Integer> rowCounter = new HashMap<>();
        for (int[] row : grid) {
            String rowString = Arrays.toString(row);
            rowCounter.put(rowString, 1 + rowCounter.getOrDefault(rowString, 0));
        }

        // Add up the frequency of each column in map.
        for (int c = 0; c < n; c++) {
            int[] colArray = new int[n];
            for (int r = 0; r < n; ++r) {
                colArray[r] = grid[r][c];
            }
            count += rowCounter.getOrDefault(Arrays.toString(colArray), 0);
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        count = 0
        n = len(grid)
        
        # Keep track of the frequency of each row.
        row_counter = collections.Counter(tuple(row) for row in grid)

        # Add up the frequency of each column in map.
        for c in range(n):
            col = [grid[i][c] for i in range(n)]
            count += row_counter[tuple(col)]

            
        return count
```

</details>

<br>

## Approach 3: Trie

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {
    int count;
    Map<Integer, TrieNode> children;

    public TrieNode() {
        this.count = 0;
        this.children = new HashMap<>();
    }
}

class Trie {
    TrieNode trie;

    public Trie() {
        this.trie = new TrieNode();
    }

    public void insert(int[] array) {
        TrieNode myTrie = this.trie;
        for (int a : array) {
            if (!myTrie.children.containsKey(a)) {
                myTrie.children.put(a, new TrieNode());
            }
            myTrie = myTrie.children.get(a);
        }
        myTrie.count += 1;
    }

    public int search(int[] array) {
        TrieNode myTrie = this.trie;
        for (int a : array) {
            if (myTrie.children.containsKey(a)) {
                myTrie = myTrie.children.get(a);
            } else {
                return 0;
            }
        }
        return myTrie.count;
    }
}

class Solution {
    public int equalPairs(int[][] grid) {
        Trie myTrie = new Trie();
        int count = 0, n = grid.length;
        
        for (int[] row : grid) {
            myTrie.insert(row);
        }
        
        for (int c = 0; c < n; ++c) {
            int[] colArray = new int[n];
            for (int r = 0; r < n; ++r) {
                colArray[r] = grid[r][c];
            }
            count += myTrie.search(colArray);
        }
    
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TrieNode:
    def __init__(self):
        self.count = 0
        self.children = {}

class Trie:
    def __init__(self):
        self.trie = TrieNode()

    def insert(self, array):
        my_trie = self.trie
        for a in array:
            if a not in my_trie.children:
                my_trie.children[a] = TrieNode()
            my_trie = my_trie.children[a] 
        my_trie.count += 1

    def search(self, array):
        my_trie = self.trie
        for a in array:
            if a in my_trie.children:
                my_trie = my_trie.children[a]
            else:
                return 0
        return my_trie.count

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        my_trie = Trie()
        count = 0
        n = len(grid)
        
        for row in grid:
            my_trie.insert(row)
        
        for c in range(n):
            col_array = [grid[i][c] for i in range(n)]
            count += my_trie.search(col_array)
    
        return count
```

</details>
