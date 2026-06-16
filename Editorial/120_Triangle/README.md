# 120. Triangle

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/triangle/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 120 - Triangle](https://leetcode.com/problems/triangle/)

## Problem

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

### Example 1

```text
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
```

### Example 2

```text
Input: triangle = [[-10]]
Output: -10
```

## Constraints

- 1 <= triangle.length <= 200
- triangle[0].length == 1
- triangle[i].length == triangle[i - 1].length + 1
- -104 <= triangle[i][j] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 120. Triangle

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming (Bottom-up: In-place) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming (Bottom-up: Auxiliary Space) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming (Bottom-up: Flip Triangle Upside Down) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Memoization (Top-Down) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Dynamic Programming (Bottom-up: In-place)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for (int row = 1; row < triangleSize; ++row) {
        for (int col = 0; col <= row; ++col) {
            int smallestAbove = INT_MAX;
            if (col > 0) {
                smallestAbove = triangle[row - 1][col - 1];
            }
            if (col < row) {
                smallestAbove = fmin(smallestAbove, triangle[row - 1][col]);
            }
            triangle[row][col] += smallestAbove;
        }
    }
    int min_val = triangle[triangleSize - 1][0];
    for (int i = 0; i < triangleColSize[triangleSize - 1]; i++) {
        if (triangle[triangleSize - 1][i] < min_val) {
            min_val = triangle[triangleSize - 1][i];
        }
    }
    return min_val;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int row = 1; row < triangle.size(); row++) {
            for (int col = 0; col <= row; col++) {
                int smallestAbove = INT_MAX;
                if (col > 0) {
                    smallestAbove = triangle[row - 1][col - 1];
                }
                if (col < row) {
                    smallestAbove = min(smallestAbove, triangle[row - 1][col]);
                }
                triangle[row][col] += smallestAbove;
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumTotal(IList<IList<int>> triangle) {
        for (int row = 1; row < triangle.Count; row++) {
            for (int col = 0; col <= row; col++) {
                int smallestAbove = int.MaxValue;
                if (col > 0) {
                    smallestAbove = triangle[row - 1][col - 1];
                }

                if (col < row) {
                    smallestAbove =
                        Math.Min(smallestAbove, triangle[row - 1][col]);
                }

                int path = smallestAbove + triangle[row][col];
                triangle[row][col] = path;
            }
        }

        return triangle[triangle.Count - 1].Min();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumTotal(triangle [][]int) int {
    for row := 1; row < len(triangle); row++ {
        for col := 0; col <= row; col++ {
            smallestAbove := math.MaxInt32
            if col > 0 {
                smallestAbove = triangle[row-1][col-1]
            }
            if col < row {
                smallestAbove = min(smallestAbove, triangle[row-1][col])
            }
            triangle[row][col] += smallestAbove
        }
    }
    return minSlice(triangle[len(triangle)-1])
}

func minSlice(slice []int) int {
    minVal := slice[0]
    for _, val := range slice {
        minVal = min(minVal, val)
    }
    return minVal
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        for (int row = 1; row < triangle.size(); row++) {
            for (int col = 0; col <= row; col++) {
                int smallestAbove = Integer.MAX_VALUE;
                if (col > 0) {
                    smallestAbove = triangle.get(row - 1).get(col - 1);
                }
                if (col < row) {
                    smallestAbove = Math.min(
                        smallestAbove,
                        triangle.get(row - 1).get(col)
                    );
                }
                int path = smallestAbove + triangle.get(row).get(col);
                triangle.get(row).set(col, path);
            }
        }
        return Collections.min(triangle.get(triangle.size() - 1));
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumTotal = function (triangle) {
    for (let row = 1; row < triangle.length; row++) {
        for (let col = 0; col <= row; col++) {
            let smallestAbove = Number.MAX_VALUE;
            if (col > 0) {
                smallestAbove = triangle[row - 1][col - 1];
            }
            if (col < row) {
                smallestAbove = Math.min(smallestAbove, triangle[row - 1][col]);
            }
            triangle[row][col] += smallestAbove;
        }
    }
    return Math.min(...triangle[triangle.length - 1]);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for row in range(1, len(triangle)):
            for col in range(row + 1):
                smallest_above = math.inf
                if col > 0:
                    smallest_above = triangle[row - 1][col - 1]
                if col < row:
                    smallest_above = min(smallest_above, triangle[row - 1][col])
                triangle[row][col] += smallest_above
        return min(triangle[-1])
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumTotal(triangle: number[][]): number {
    for (let row = 1; row < triangle.length; row++) {
        for (let col = 0; col <= row; col++) {
            let smallestAbove = Number.MAX_VALUE;
            if (col > 0) {
                smallestAbove = triangle[row - 1][col - 1];
            }
            if (col < row) {
                smallestAbove = Math.min(smallestAbove, triangle[row - 1][col]);
            }
            triangle[row][col] += smallestAbove;
        }
    }
    return Math.min(...triangle[triangle.length - 1]);
}
```

</details>

<br>

## Approach 2: Dynamic Programming (Bottom-up: Auxiliary Space)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int* prevRow = malloc(triangleColSize[0] * sizeof(int));
    for (int i = 0; i < triangleColSize[0]; i++) {
        prevRow[i] = triangle[0][i];
    }
    for (int row = 1; row < triangleSize; row++) {
        int* currRow = malloc(triangleColSize[row] * sizeof(int));
        for (int col = 0; col <= row; col++) {
            int smallestAbove = INT_MAX;
            if (col > 0) {
                smallestAbove = prevRow[col - 1];
            }
            if (col < row) {
                smallestAbove = (smallestAbove < prevRow[col]) ? smallestAbove
                                                               : prevRow[col];
            }
            currRow[col] = smallestAbove + triangle[row][col];
        }
        free(prevRow);
        prevRow = currRow;
    }
    int minVal = INT_MAX;
    for (int i = 0; i < triangleSize; i++) {
        minVal = (minVal < prevRow[i]) ? minVal : prevRow[i];
    }
    free(prevRow);
    return minVal;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prevRow = triangle[0];
        for (int row = 1; row < triangle.size(); row++) {
            vector<int> currRow;
            for (int col = 0; col <= row; col++) {
                int smallestAbove = INT_MAX;
                if (col > 0) {
                    smallestAbove = prevRow[col - 1];
                }
                if (col < row) {
                    smallestAbove = min(smallestAbove, prevRow[col]);
                }
                currRow.push_back(smallestAbove + triangle[row][col]);
            }
            prevRow = currRow;
        }
        return *min_element(prevRow.begin(), prevRow.end());
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumTotal(IList<IList<int>> triangle) {
        List<int> prevRow = triangle[0].ToList();
        for (int row = 1; row < triangle.Count; row++) {
            List<int> currRow = new List<int>();
            for (int col = 0; col <= row; col++) {
                int smallestAbove = int.MaxValue;
                if (col > 0) {
                    smallestAbove = prevRow[col - 1];
                }

                if (col < row) {
                    smallestAbove = Math.Min(smallestAbove, prevRow[col]);
                }

                currRow.Add(smallestAbove + triangle[row][col]);
            }

            prevRow = currRow;
        }

        return prevRow.Min();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumTotal(triangle [][]int) int {
    prevRow := make([]int, len(triangle[0]))
    copy(prevRow, triangle[0])
    for row := 1; row < len(triangle); row++ {
        currRow := make([]int, row+1)
        for col := 0; col <= row; col++ {
            smallestAbove := int(^uint(0) >> 1)
            if col > 0 {
                smallestAbove = prevRow[col-1]
            }
            if col < row {
                smallestAbove = min(smallestAbove, prevRow[col])
            }
            currRow[col] = smallestAbove + triangle[row][col]
        }
        prevRow = currRow
    }
    min_val := prevRow[0]
    for i := 0; i < len(prevRow); i++ {
        min_val = min(min_val, prevRow[i])
    }
    return min_val
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        List<Integer> prevRow = triangle.get(0);
        for (int row = 1; row < triangle.size(); row++) {
            List<Integer> currRow = new ArrayList<>();
            for (int col = 0; col <= row; col++) {
                int smallestAbove = Integer.MAX_VALUE;
                if (col > 0) {
                    smallestAbove = prevRow.get(col - 1);
                }
                if (col < row) {
                    smallestAbove = Math.min(smallestAbove, prevRow.get(col));
                }
                currRow.add(smallestAbove + triangle.get(row).get(col));
            }
            prevRow = currRow;
        }
        return Collections.min(prevRow);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumTotal = function (triangle) {
    let prevRow = triangle[0];
    for (let row = 1; row < triangle.length; row++) {
        let currRow = [];
        for (let col = 0; col <= row; col++) {
            let smallestAbove = Number.MAX_VALUE;
            if (col > 0) {
                smallestAbove = prevRow[col - 1];
            }
            if (col < row) {
                smallestAbove = Math.min(smallestAbove, prevRow[col]);
            }
            currRow.push(smallestAbove + triangle[row][col]);
        }
        prevRow = currRow;
    }
    return Math.min(...prevRow);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        prev_row = triangle[0]
        for row in range(1, len(triangle)):
            curr_row = []
            for col in range(row + 1):
                smallest_above = math.inf
                if col > 0:
                    smallest_above = prev_row[col - 1]
                if col < row:
                    smallest_above = min(smallest_above, prev_row[col])
                curr_row.append(triangle[row][col] + smallest_above)
            prev_row = curr_row
        return min(prev_row)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumTotal(triangle: number[][]): number {
    let prevRow = triangle[0];
    for (let row = 1; row < triangle.length; row++) {
        let currRow = [];
        for (let col = 0; col <= row; col++) {
            let smallestAbove = Number.MAX_VALUE;
            if (col > 0) {
                smallestAbove = prevRow[col - 1];
            }
            if (col < row) {
                smallestAbove = Math.min(smallestAbove, prevRow[col]);
            }
            currRow.push(smallestAbove + triangle[row][col]);
        }
        prevRow = currRow;
    }
    return Math.min(...prevRow);
}
```

</details>

<br>

## Approach 3: Dynamic Programming (Bottom-up: Flip Triangle Upside Down)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for (int row = triangleSize - 2; row >= 0; --row) {
        for (int col = 0; col <= row; ++col) {
            int bestBelow =
                fmin(triangle[row + 1][col], triangle[row + 1][col + 1]);
            triangle[row][col] += bestBelow;
        }
    }
    return triangle[0][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int row = triangle.size() - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                int bestBelow = std::min(triangle[row + 1][col],
                                         triangle[row + 1][col + 1]);
                triangle[row][col] += bestBelow;
            }
        }
        return triangle[0][0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumTotal(IList<IList<int>> triangle) {
        for (int row = triangle.Count - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                int bestBelow = Math.Min(triangle[row + 1][col],
                                         triangle[row + 1][col + 1]);
                triangle[row][col] += bestBelow;
            }
        }

        return triangle[0][0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumTotal(triangle [][]int) int {
    for row := len(triangle) - 2; row >= 0; row-- {
        for col := 0; col <= row; col++ {
            bestBelow := min(triangle[row+1][col], triangle[row+1][col+1])
            triangle[row][col] += bestBelow
        }
    }
    return triangle[0][0]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        for (int row = triangle.size() - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                int bestBelow = Math.min(
                    triangle.get(row + 1).get(col),
                    triangle.get(row + 1).get(col + 1)
                );
                triangle
                    .get(row)
                    .set(col, bestBelow + triangle.get(row).get(col));
            }
        }
        return triangle.get(0).get(0);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumTotal = function (triangle) {
    for (let row = triangle.length - 2; row >= 0; row--) {
        for (let col = 0; col <= row; col++) {
            let bestBelow = Math.min(
                triangle[row + 1][col],
                triangle[row + 1][col + 1],
            );
            triangle[row][col] += bestBelow;
        }
    }
    return triangle[0][0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        below_row = triangle[-1]
        n = len(triangle)
        for row in reversed(range(n - 1)):
            curr_row = []
            for col in range(row + 1):
                smallest_below = min(below_row[col], below_row[col + 1])
                curr_row.append(triangle[row][col] + smallest_below)
            below_row = curr_row
        return below_row[0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumTotal(triangle: number[][]): number {
    for (let row = triangle.length - 2; row >= 0; row--) {
        for (let col = 0; col <= row; col++) {
            let bestBelow = Math.min(
                triangle[row + 1][col],
                triangle[row + 1][col + 1],
            );
            triangle[row][col] += bestBelow;
        }
    }
    return triangle[0][0];
}
```

</details>

<br>

## Approach 4: Memoization (Top-Down)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct key {
    int row;
    int col;
};
struct hash_table {
    struct key k;
    int val;
    UT_hash_handle hh;
};
struct hash_table* memotable = NULL;
void add(struct key k, int val) {
    struct hash_table* s;
    HASH_FIND(hh, memotable, &k, sizeof(struct key), s);
    if (s == NULL) {
        s = (struct hash_table*)malloc(sizeof *s);
        s->k = k;
        s->val = val;
        HASH_ADD(hh, memotable, k, sizeof(struct key), s);
    } else {  // add this condition when element already exists just overwrite
              // its value
        s->val = val;
    }
}
int find(struct key k) {
    struct hash_table* s;
    HASH_FIND(hh, memotable, &k, sizeof(struct key), s);
    if (s == NULL) return -1;
    return s->val;
}
int** triangle;
int triangleRowSize;
int* triangleColSize;
int minPath(int row, int col) {
    struct key k;
    k.row = row;
    k.col = col;
    int stored = find(k);
    if (stored != -1) {
        return stored;
    }
    int path = triangle[row][col];
    if (row < triangleRowSize - 1) {
        path += fmin(minPath(row + 1, col), minPath(row + 1, col + 1));
    }
    add(k, path);
    return path;
}
int minimumTotal(int** tri, int triRowSize, int* triColSize) {
    triangle = tri;
    triangleRowSize = triRowSize;
    triangleColSize = triColSize;
    memotable = NULL;  // add this to reset memo table before new query
    return minPath(0, 0);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    vector<vector<int>> triangle;
    map<pair<int, int>, int> memoTable;
    int minPath(int row, int col) {
        if (memoTable.count({row, col})) {
            return memoTable[{row, col}];
        }
        int path = triangle[row][col];
        if (row < triangle.size() - 1) {
            path += min(minPath(row + 1, col), minPath(row + 1, col + 1));
        }
        memoTable[{row, col}] = path;
        return path;
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        this->triangle = triangle;
        return minPath(0, 0);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private List<IList<int>> triangle;
    private Dictionary<string, int> memoTable = new Dictionary<string, int>();

    private int MinPath(int row, int col) {
        string paramsKey = row + ":" + col;
        if (memoTable.ContainsKey(paramsKey)) {
            return memoTable[paramsKey];
        }

        int path = triangle[row][col];
        if (row < triangle.Count - 1) {
            path += Math.Min(MinPath(row + 1, col), MinPath(row + 1, col + 1));
        }

        memoTable[paramsKey] = path;
        return path;
    }

    public int MinimumTotal(IList<IList<int>> triangle) {
        this.triangle = triangle.ToList();
        memoTable.Clear();
        return MinPath(0, 0);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
var (
    triangle  [][]int
    memoTable map[string]int
)

func minPath(row int, col int) int {
    params := fmt.Sprintf("%d:%d", row, col)
    if val, ok := memoTable[params]; ok {
        return val
    }
    path := triangle[row][col]
    if row < len(triangle)-1 {
        path += min(minPath(row+1, col), minPath(row+1, col+1))
    }
    memoTable[params] = path
    return path
}

func minimumTotal(triangleInput [][]int) int {
    triangle = triangleInput
    memoTable = make(map[string]int)
    return minPath(0, 0)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Map<String, Integer> memoTable;
    private List<List<Integer>> triangle;

    private int minPath(int row, int col) {
        String params = row + ":" + col;
        if (memoTable.containsKey(params)) {
            return memoTable.get(params);
        }
        int path = triangle.get(row).get(col);
        if (row < triangle.size() - 1) {
            path += Math.min(minPath(row + 1, col), minPath(row + 1, col + 1));
        }
        memoTable.put(params, path);
        return path;
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        this.triangle = triangle;
        memoTable = new HashMap<>();
        return minPath(0, 0);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let triangle;
let memoTable = new Map();
function minPath(row, col) {
    let params = row + ":" + col;
    if (memoTable.has(params)) {
        return memoTable.get(params);
    }
    let path = triangle[row][col];
    if (row < triangle.length - 1) {
        path += Math.min(minPath(row + 1, col), minPath(row + 1, col + 1));
    }
    memoTable.set(params, path);
    return path;
}
var minimumTotal = function (triangleInput) {
    triangle = triangleInput;
    memoTable.clear();
    return minPath(0, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        @lru_cache(maxsize=None)
        def min_path(row, col):
            path = triangle[row][col]
            if row < len(triangle) - 1:
                path += min(min_path(row + 1, col), min_path(row + 1, col + 1))
            return path

        return min_path(0, 0)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
let triangle: number[][];
let memoTable = new Map<string, number>();
function minPath(row: number, col: number): number {
    let params = row + ":" + col;
    if (memoTable.has(params)) {
        return memoTable.get(params)!;
    }
    let path = triangle[row][col];
    if (row < triangle.length - 1) {
        path += Math.min(minPath(row + 1, col), minPath(row + 1, col + 1));
    }
    memoTable.set(params, path);
    return path;
}
function minimumTotal(triangleInput: number[][]): number {
    triangle = triangleInput;
    memoTable.clear();
    return minPath(0, 0);
}
```

</details>
