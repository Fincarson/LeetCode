# 119. Pascal's Triangle II

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/pascals-triangle-ii/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 119 - Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)

## Problem

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

### Example 1

```text
Input: rowIndex = 3
Output: [1,3,3,1]
```

### Example 2

```text
Input: rowIndex = 0
Output: [1]
```

### Example 3

```text
Input: rowIndex = 1
Output: [1,1]
```

## Constraints

- 0 <= rowIndex <= 33

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find Triangular Sum of an Array](https://leetcode.com/problems/find-triangular-sum-of-an-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 119. Pascal's Triangle II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Memory-efficient Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Math! (specifically, Combinatorics) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int getNum(int row, int col) {
    if (row == 0 || col == 0 || row == col) {
        return 1;
    }
    return getNum(row - 1, col - 1) + getNum(row - 1, col);
}
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* ans = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i <= rowIndex; i++) {
        ans[i] = getNum(rowIndex, i);
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getNum(int row, int col) {
        if (row == 0 || col == 0 || row == col) return 1;

        return getNum(row - 1, col - 1) + getNum(row - 1, col);
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;

        for (int i = 0; i <= rowIndex; i++) ans.push_back(getNum(rowIndex, i));

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int getNum(int row, int col) {
        if (row == 0 || col == 0 || row == col) {
            return 1;
        }

        return getNum(row - 1, col - 1) + getNum(row - 1, col);
    }

    public IList<int> GetRow(int rowIndex) {
        IList<int> ans = new List<int>();
        for (int i = 0; i <= rowIndex; i++) {
            ans.Add(getNum(rowIndex, i));
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getNum(row int, col int) int {
    if row == 0 || col == 0 || row == col {
        return 1
    }
    return getNum(row-1, col-1) + getNum(row-1, col)
}

func getRow(rowIndex int) []int {
    ans := make([]int, rowIndex+1)
    for i := 0; i <= rowIndex; i++ {
        ans[i] = getNum(rowIndex, i)
    }
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int getNum(int row, int col) {
        if (row == 0 || col == 0 || row == col) {
            return 1;
        }

        return getNum(row - 1, col - 1) + getNum(row - 1, col);
    }

    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i <= rowIndex; i++) {
            ans.add(getNum(rowIndex, i));
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getNum = function (row, col) {
    if (row === 0 || col === 0 || row === col) {
        return 1;
    }
    return getNum(row - 1, col - 1) + getNum(row - 1, col);
};
var getRow = function (rowIndex) {
    let ans = [];
    for (let i = 0; i <= rowIndex; i++) {
        ans.push(getNum(rowIndex, i));
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getNum(self, row, col):
        if row == 0 or col == 0 or row == col:
            return 1
        return self.getNum(row - 1, col - 1) + self.getNum(row - 1, col)

    def getRow(self, rowIndex):
        ans = []
        for i in range(rowIndex + 1):
            ans.append(self.getNum(rowIndex, i))
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getNum(row: number, col: number): number {
    if (row === 0 || col === 0 || row === col) {
        return 1;
    }
    return getNum(row - 1, col - 1) + getNum(row - 1, col);
}
function getRow(rowIndex: number): number[] {
    let ans: number[] = [];
    for (let i = 0; i <= rowIndex; i++) {
        ans.push(getNum(rowIndex, i));
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Cache {
    int key;
    int val;
    UT_hash_handle hh;
};
struct Cache *cache, *tmp;
void add_cache(int key, int val) {
    tmp = malloc(sizeof(struct Cache));
    tmp->key = key;
    tmp->val = val;
    HASH_ADD_INT(cache, key, tmp);
}
struct Cache* find_cache(int key) {
    HASH_FIND_INT(cache, &key, tmp);
    return tmp;
}
int getNum(int row, int col) {
    int key = ((row + 1) << 16) | (col + 1);
    tmp = find_cache(key);
    if (tmp) return tmp->val;
    if (row == 0 || col == 0 || row == col) {
        add_cache(key, 1);
        return 1;
    }
    int val = getNum(row - 1, col - 1) + getNum(row - 1, col);
    add_cache(key, val);
    return val;
}
int* getRow(int rowIndex, int* returnSize) {
    cache = NULL;
    *returnSize = rowIndex + 1;
    int* ans = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        ans[i] = getNum(rowIndex, i);
    }
    HASH_CLEAR(hh, cache);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    unordered_map<size_t, int> cache;

    // use a better hashing function like `boost::hash_combine` in the real
    // world.
    int key(int i, int j) const {
        size_t hash_i = hash<int>{}(i), hash_j = hash<int>{}(j);
        int hashed = (int)(hash_i ^ (hash_i >> 32));
        return (hashed << 5) - 1 + (int)(hash_j ^ (hash_j >> 32));
    }

public:
    int getNum(int row, int col) {
        auto rowCol = key(row, col);

        if (cache.count(rowCol) > 0) return cache[rowCol];

        if (row == 0 || col == 0 || row == col) return (cache[rowCol] = 1);

        return (cache[rowCol] =
                    getNum(row - 1, col - 1) + getNum(row - 1, col));
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;

        for (int i = 0; i <= rowIndex; i++) ans.push_back(getNum(rowIndex, i));

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private Dictionary<(int, int), int> cache =
        new Dictionary<(int, int), int>();

    private int GetNum(int row, int col) {
        if (cache.ContainsKey((row, col))) {
            return cache[(row, col)];
        }

        int computedVal = (row == 0 || col == 0 || row == col)
                              ? 1
                              : GetNum(row - 1, col - 1) + GetNum(row - 1, col);
        cache[(row, col)] = computedVal;
        return computedVal;
    }

    public IList<int> GetRow(int rowIndex) {
        List<int> ans = new List<int>();
        for (int i = 0; i <= rowIndex; i++) {
            ans.Add(GetNum(rowIndex, i));
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type key struct {
    row int
    col int
}

var cache = make(map[key]int)

func getNum(row int, col int) int {
    rowCol := key{row, col}
    if val, ok := cache[rowCol]; ok {
        return val
    }
    if row == 0 || col == 0 || row == col {
        cache[rowCol] = 1
        return 1
    }
    cache[rowCol] = getNum(row-1, col-1) + getNum(row-1, col)
    return cache[rowCol]
}

func getRow(rowIndex int) []int {
    ans := make([]int, rowIndex+1)
    for i := range ans {
        ans[i] = getNum(rowIndex, i)
    }
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private final class RowCol {
        private int row, col;

        public RowCol(int row, int col) {
            this.row = row;
            this.col = col;
        }

        @Override
        public int hashCode() {
            int result = (int) (row ^ (row >>> 32));
            return (result << 5) - result + (int) (col ^ (col >>> 32)); // 31 * result == (result << 5) - result
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null) return false;
            if (this.getClass() != o.getClass()) return false;

            RowCol rowCol = (RowCol) o;
            return row == rowCol.row && col == rowCol.col;
        }
    }

    private Map<RowCol, Integer> cache = new HashMap<>();

    private int getNum(int row, int col) {
        RowCol rowCol = new RowCol(row, col);

        if (cache.containsKey(rowCol)) {
            return cache.get(rowCol);
        }

        int computedVal = (row == 0 || col == 0 || row == col)
            ? 1
            : getNum(row - 1, col - 1) + getNum(row - 1, col);

        cache.put(rowCol, computedVal);

        return computedVal;
    }

    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i <= rowIndex; i++) {
            ans.add(getNum(rowIndex, i));
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// initially, the cache is empty
let cache = {};
// Internal helper function to calculate the number of ways
function getNum(row, col) {
    // store the position as a tuple, which will be used as a key in the cache
    let rowCol = [row, col].toString();
    // if the key is already in the cache, then return the cached value
    if (cache[rowCol]) {
        return cache[rowCol];
    }
    // if the row or column is 0, or if the row and column are the same, then there is only one way
    if (row == 0 || col == 0 || row == col) {
        cache[rowCol] = 1;
        return 1;
    }
    // otherwise, the number of ways is the sum of the number of ways from the cell above and the cell to the left
    cache[rowCol] = getNum(row - 1, col - 1) + getNum(row - 1, col);
    return cache[rowCol];
}
// Function to return the row of Pascal's Triangle
function getRow(rowIndex) {
    let ans = [];
    for (let i = 0; i <= rowIndex; i++) {
        ans.push(getNum(rowIndex, i));
    }
    return ans;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # initially, the cache is empty
    cache = {}

    # Internal helper function to calculate the number of ways
    def getNum(self, row, col):
        # store the position as a tuple, which will be used as a key in the cache
        rowCol = (row, col)
        # if the key is already in the cache, then return the cached value
        if rowCol in self.cache:
            return self.cache[rowCol]
        # if the row or column is 0, or if the row and column are the same, then there is only one way
        if row == 0 or col == 0 or row == col:
            self.cache[rowCol] = 1
            return 1
        # otherwise, the number of ways is the sum of the number of ways from the cell above and the cell to the left
        self.cache[rowCol] = self.getNum(row - 1, col - 1) + self.getNum(
            row - 1, col
        )
        return self.cache[rowCol]

    # Function to return the row of Pascal's Triangle
    def getRow(self, rowIndex):
        ans = []
        for i in range(rowIndex + 1):
            ans.append(self.getNum(rowIndex, i))
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
let cache: { [key: string]: number } = {};
function getNum(row: number, col: number): number {
    let rowCol = [row, col].toString();
    if (cache[rowCol]) {
        return cache[rowCol];
    }
    if (row == 0 || col == 0 || row == col) {
        cache[rowCol] = 1;
        return 1;
    }
    cache[rowCol] = getNum(row - 1, col - 1) + getNum(row - 1, col);
    return cache[rowCol];
}
function getRow(rowIndex: number): number[] {
    let ans: number[] = [];
    for (let i = 0; i <= rowIndex; i++) {
        ans.push(getNum(rowIndex, i));
    }
    return ans;
}
```

</details>

<br>

## Approach 3: Memory-efficient Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* getRow(int rowIndex, int* returnSize) {
    // set return size
    *returnSize = rowIndex + 1;
    // initialize row with all elements as 1
    int* row = (int*)calloc(*returnSize, sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        row[i] = 1;
    }
    // populate each row element
    for (int i = 1; i < rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            // current element is sum of current and previous element in above
            // row
            row[j] += row[j - 1];
        }
    }
    return row;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = vector<int>(rowIndex + 1, 1);

        for (int i = 1; i < rowIndex; i++)
            for (int j = i; j > 0; j--)
                ans[j] += ans[j - 1];  // ans[j] = ans[j-1] + ans[j]

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<int> GetRow(int rowIndex) {
        IList<int> row = new int[rowIndex + 1];
        for (int i = 0; i <= rowIndex; i++) {
            row[i] = 1;
        }

        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                row[j] += row[j - 1];
            }
        }

        return row;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getRow(rowIndex int) []int {
    row := make([]int, rowIndex+1)
    for i := 0; i < rowIndex+1; i++ {
        row[i] = 1
    }
    for i := 1; i < rowIndex; i++ {
        for j := i; j > 0; j-- {
            row[j] += row[j-1]
        }
    }
    return row
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<>(rowIndex + 1) {
            {
                add(1);
            }
        };

        for (int i = 0; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                row.set(j, row.get(j) + row.get(j - 1));
            }
            row.add(1);
        }

        return row;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getRow = function (rowIndex) {
    let row = Array(rowIndex + 1).fill(1);
    for (let i = 1; i < rowIndex; i++) {
        for (let j = i; j > 0; j--) {
            row[j] += row[j - 1];
        }
    }
    return row;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        # initialize row with all elements as 1
        row = [1] * (rowIndex + 1)
        # populate each row element
        for i in range(1, rowIndex):
            for j in range(i, 0, -1):
                # current element is sum of current and previous element in above row
                row[j] += row[j - 1]
        return row
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getRow(rowIndex: number): number[] {
    let row: number[] = Array(rowIndex + 1).fill(1);
    for (let i = 1; i < rowIndex; i++) {
        for (let j = i; j > 0; j--) {
            row[j] += row[j - 1];
        }
    }
    return row;
}
```

</details>

<br>

## Approach 4: Math! (specifically, Combinatorics)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* getRow(int n, int* returnSize) {
    *returnSize = n + 1;
    int* ans = malloc((n + 1) * sizeof(int));
    ans[0] = 1;
    for (int k = 1; k <= n; k++)
        ans[k] = (int)((ans[k - 1] * (long long)(n - k + 1)) / k);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> ans = {1};

        for (int k = 1; k <= n; k++)
            ans.push_back((int)((ans.back() * (long long)(n - k + 1)) / k));

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<int> GetRow(int rowIndex) {
        List<int> row = new List<int>() { 1 };
        for (int k = 1; k <= rowIndex; k++) {
            row.Add((int)((row[row.Count - 1] * (long)(rowIndex - k + 1)) / k));
        }

        return row;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getRow(n int) []int {
    row := []int{1}
    for k := 1; k <= n; k++ {
        row = append(row, int(float64(row[len(row)-1]*(n-k+1))/float64(k)))
    }
    return row
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> getRow(int n) {
        List<Integer> row = new ArrayList<>() {
            {
                add(1);
            }
        };

        for (int k = 1; k <= n; k++) {
            row.add((int) ((row.get(row.size() - 1) * (long) (n - k + 1)) / k));
        }

        return row;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getRow = function (n) {
    let row = [1];
    for (let k = 1; k <= n; k++) {
        row.push(Math.floor((row[row.length - 1] * (n - k + 1)) / k));
    }
    return row;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getRow(self, n):
        row = [1]
        for k in range(1, n + 1):
            row.append(int((row[-1] * (n - k + 1)) / k))
        return row
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getRow(n: number): number[] {
    let row = [1];
    for (let k = 1; k <= n; k++) {
        row.push(Math.floor((row[row.length - 1] * (n - k + 1)) / k));
    }
    return row;
}
```

</details>
