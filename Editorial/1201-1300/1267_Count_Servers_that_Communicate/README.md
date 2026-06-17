# 1267. Count Servers that Communicate

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-servers-that-communicate/)  
`Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix` `Counting`

**Problem Link:** [LeetCode 1267 - Count Servers that Communicate](https://leetcode.com/problems/count-servers-that-communicate/)

## Problem

You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

### Example 1

```text
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
```

### Example 2

```text
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.
```

### Example 3

```text
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m <= 250
- 1 <= n <= 250
- grid[i][j] == 0 or 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1267. Count Servers that Communicate

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute-Force | C++, Java, Python3 |
| Track Using Two Arrays | C++, Java, Python3 |
| Server Grouping | C++, Java, Python3 |
| Space Optimized | C++, Java, Python3 |

## Approach 1: Brute-Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();
        int communicableServersCount = 0;

        // Traverse through the grid
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (grid[row][col] == 1) {
                    bool canCommunicate = false;

                    // Check for communication in the same row
                    for (int otherCol = 0; otherCol < numCols; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    // If a server was found in the same row, increment
                    // communicableServersCount
                    if (canCommunicate) {
                        communicableServersCount++;
                    } else {
                        // Check for communication in the same column
                        for (int otherRow = 0; otherRow < numRows; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }

                        // If a server was found in the same column, increment
                        // communicableServersCount
                        if (canCommunicate) {
                            communicableServersCount++;
                        }
                    }
                }
            }
        }

        return communicableServersCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countServers(int[][] grid) {
        int numRows = grid.length;
        int numCols = numRows > 0 ? grid[0].length : 0;
        int communicableServersCount = 0;

        // Traverse through the grid
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (grid[row][col] == 1) {
                    boolean canCommunicate = false;

                    // Check for communication in the same row
                    for (int otherCol = 0; otherCol < numCols; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    // If a server was found in the same row, increment
                    // communicableServersCount
                    if (canCommunicate) {
                        communicableServersCount++;
                    } else {
                        // Check for communication in the same column
                        for (int otherRow = 0; otherRow < numRows; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }

                        // If a server was found in the same column, increment
                        // communicableServersCount
                        if (canCommunicate) {
                            communicableServersCount++;
                        }
                    }
                }
            }
        }

        return communicableServersCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        num_rows = len(grid)
        num_cols = len(grid[0]) if num_rows > 0 else 0
        communicable_servers_count = 0

        # Traverse through the grid
        for row in range(num_rows):
            for col in range(num_cols):
                if grid[row][col] == 1:
                    can_communicate = False

                    # Check for communication in the same row
                    for other_col in range(num_cols):
                        if other_col != col and grid[row][other_col] == 1:
                            can_communicate = True
                            break

                    # If a server was found in the same row, increment
                    # communicable_servers_count
                    if can_communicate:
                        communicable_servers_count += 1
                    else:
                        # Check for communication in the same column
                        for other_row in range(num_rows):
                            if other_row != row and grid[other_row][col] == 1:
                                can_communicate = True
                                break

                        # If a server was found in the same column, increment
                        # communicable_servers_count
                        if can_communicate:
                            communicable_servers_count += 1

        return communicable_servers_count
```

</details>

<br>

## Approach 2: Track Using Two Arrays

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countServers(const vector<vector<int>>& grid) {
        vector<int> rowCounts(size(grid[0]), 0), colCounts(size(grid), 0);

        // Count servers in each row and each column
        for (int row = 0; row < size(grid); ++row)
            for (int col = 0; col < size(grid[0]); ++col)
                if (grid[row][col]) {
                    rowCounts[col]++;
                    colCounts[row]++;
                }

        int communicableServersCount = 0;

        // Count servers that can communicate (in the same row or column)
        for (int row = 0; row < size(grid); ++row)
            for (int col = 0; col < size(grid[0]); ++col)
                if (grid[row][col])
                    communicableServersCount +=
                        rowCounts[col] > 1 || colCounts[row] > 1;

        return communicableServersCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countServers(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        int[] rowCounts = new int[grid[0].length];
        int[] colCounts = new int[grid.length];

        // Count servers in each row and each column
        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[0].length; col++) {
                if (grid[row][col] == 1) {
                    rowCounts[col]++;
                    colCounts[row]++;
                }
            }
        }

        int communicableServersCount = 0;

        // Count servers that can communicate (in the same row or column)
        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[0].length; col++) {
                if (grid[row][col] == 1) {
                    if (rowCounts[col] > 1 || colCounts[row] > 1) {
                        communicableServersCount++;
                    }
                }
            }
        }

        return communicableServersCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        row_counts = [0] * len(grid[0])
        col_counts = [0] * len(grid)

        # Count servers in each row and each column
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col]:
                    row_counts[col] += 1
                    col_counts[row] += 1

        communicable_servers_count = 0

        # Count servers that can communicate (in the same row or column)
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col]:
                    if row_counts[col] > 1 or col_counts[row] > 1:
                        communicable_servers_count += 1

        return communicable_servers_count
```

</details>

<br>

## Approach 3: Server Grouping

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countServers(const vector<vector<int>>& grid) {
        int communicableServersCount = 0;
        vector<int> colCount(size(grid[0]), 0),
            lastServerInRow(size(grid), -1);

        // First pass to count servers in each row and column
        for (int row = 0; row < size(grid); ++row) {
            int serverCountInRow = 0;
            for (int col = 0; col < size(grid[0]); ++col)
                if (grid[row][col]) {
                    serverCountInRow++;
                    colCount[col]++;
                    lastServerInRow[row] = col;
                }
            // If there is more than one server in the row, increase the count
            if (serverCountInRow != 1)
                communicableServersCount += serverCountInRow,
                    lastServerInRow[row] = -1;
        }

        // Second pass to check if servers can communicate
        for (int row = 0; row < size(grid); ++row)
            communicableServersCount += lastServerInRow[row] != -1 &&
                                        colCount[lastServerInRow[row]] > 1;

        return communicableServersCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countServers(int[][] grid) {
        int communicableServersCount = 0;
        int[] colCount = new int[grid[0].length];
        int[] lastServerInRow = new int[grid.length];
        for (int i = 0; i < lastServerInRow.length; i++) {
            lastServerInRow[i] = -1;
        }

        // First pass to count servers in each row and column
        for (int row = 0; row < grid.length; row++) {
            int serverCountInRow = 0;
            for (int col = 0; col < grid[0].length; col++) {
                if (grid[row][col] == 1) {
                    serverCountInRow++;
                    colCount[col]++;
                    lastServerInRow[row] = col;
                }
            }
            // If there is more than one server in the row, increase the count
            if (serverCountInRow != 1) {
                communicableServersCount += serverCountInRow;
                lastServerInRow[row] = -1;
            }
        }

        // Second pass to check if servers can communicate
        for (int row = 0; row < grid.length; row++) {
            if (
                lastServerInRow[row] != -1 &&
                colCount[lastServerInRow[row]] > 1
            ) {
                communicableServersCount++;
            }
        }

        return communicableServersCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        communicable_servers_count = 0
        col_count = [0] * len(grid[0])
        last_server_in_row = [-1] * len(grid)

        # First pass to count servers in each row and column
        for row in range(len(grid)):
            server_count_in_row = 0
            for col in range(len(grid[0])):
                if grid[row][col]:
                    server_count_in_row += 1
                    col_count[col] += 1
                    last_server_in_row[row] = col

            # If there is more than one server in the row, increase the count
            if server_count_in_row != 1:
                communicable_servers_count += server_count_in_row
                last_server_in_row[row] = -1

        # Second pass to check if servers can communicate
        for row in range(len(grid)):
            if (
                last_server_in_row[row] != -1
                and col_count[last_server_in_row[row]] > 1
            ):
                communicable_servers_count += 1
        return communicable_servers_count
```

</details>

<br>

## Approach 4: Space Optimized

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int communicableServersCount = 0;

        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            int rowCounts = 0;
            int serverColumnIndex = -1;

            // Count the number of servers in the current row and record the
            // first server's column index.
            for (int colIndex = 0; colIndex < cols; ++colIndex) {
                if (grid[rowIndex][colIndex]) {
                    if (rowCounts == 0) {
                        serverColumnIndex = colIndex;
                    }
                    rowCounts += 1;
                }
            }

            // If more than one server in the row, it can communicate
            bool canCommunicate = (rowCounts !=1);

            // If there's only one server in the row, check if there's a server
            // in the same column in another row.
            if (!canCommunicate) {
                for (int i = 0; i < rows; ++i) {
                    if (i != rowIndex && grid[i][serverColumnIndex]) {
                        canCommunicate = true;
                        break;
                    }
                }
            }

            // If the server can communicate, add rowCounts to the result.
            if (canCommunicate) {
                communicableServersCount += rowCounts;
            }
        }

        return communicableServersCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countServers(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int communicableServersCount = 0;

        for (int rowIndex = 0; rowIndex < rows; ++rowIndex) {
            int rowCounts = 0;
            int serverColumnIndex = -1;

            // Count the number of servers in the current row and record the
            // first server's column index.
            for (int colIndex = 0; colIndex < cols; ++colIndex) {
                if (grid[rowIndex][colIndex] == 1) {
                    if (rowCounts == 0) {
                        serverColumnIndex = colIndex;
                    }
                    rowCounts++;
                }
            }

            // If more than one server in the row, it can communicate
            boolean canCommunicate = (rowCounts != 1);

            // If there's only one server in the row, check if there's a server
            // in the same column in another row.
            if (!canCommunicate) {
                for (int i = 0; i < rows; ++i) {
                    if (i != rowIndex && grid[i][serverColumnIndex] == 1) {
                        canCommunicate = true;
                        break;
                    }
                }
            }

            // If the server can communicate, add rowCounts to the result.
            if (canCommunicate) {
                communicableServersCount += rowCounts;
            }
        }

        return communicableServersCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        communicable_servers_count = 0

        for row_index in range(rows):
            row_counts = 0
            server_column_index = -1

            # Count the number of servers in the current row and record the
            # first server's column index.
            for col_index in range(cols):
                if grid[row_index][col_index] == 1:
                    if row_counts == 0:
                        server_column_index = col_index
                    row_counts += 1

            # If more than one server in the row, it can communicate
            can_communicate = (row_counts != 1)

            # If there's only one server in the row, check if there's a server
            # in the same column in another row.
            if not can_communicate:
                for i in range(rows):
                    if i != row_index and grid[i][server_column_index] == 1:
                        can_communicate = True
                        break

            # If the server can communicate, add row_counts to the result.
            if can_communicate:
                communicable_servers_count += row_counts

        return communicable_servers_count
```

</details>
