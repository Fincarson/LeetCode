# 118. Pascal's Triangle

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/pascals-triangle/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 118 - Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)

## Problem

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

### Example 1

```text
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

### Example 2

```text
Input: numRows = 1
Output: [[1]]
```

## Constraints

- 1 <= numRows <= 30

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Check If Digits Are Equal in String After Operations II](https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 118. Pascal's Triangle

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// The C language requires a convoluted way to
// allocate a multi-dimensional array on the heap.
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    int** triangle = (int**)malloc(sizeof(int*) * numRows);
    if (numRows == 0) {
        return NULL;
    }
    // Base case; first row is always [1].
    (*returnColumnSizes)[0] = 1;
    triangle[0] = (int*)malloc(sizeof(int) * 1);
    triangle[0][0] = 1;
    for (int rowNum = 1; rowNum < numRows; rowNum++) {
        int* row = (int*)malloc(sizeof(int) * (rowNum + 1));
        int* prevRow = triangle[rowNum - 1];
        row[0] = 1;
        // Each triangle element (other than the first and last of each row)
        // is equal to the sum of the elements above-and-to-the-left and
        // above-and-to-the-right.
        for (int j = 1; j < rowNum; j++) {
            row[j] = prevRow[j - 1] + prevRow[j];
        }
        row[rowNum] = 1;
        triangle[rowNum] = row;
        (*returnColumnSizes)[rowNum] = rowNum + 1;
    }
    return triangle;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Return type is vector<vector<int>>.
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        // Base case; first row is always [1].
        triangle.push_back(vector<int>());
        triangle[0].push_back(1);
        for (int rowNum = 1; rowNum < numRows; rowNum++) {
            vector<int> row;
            vector<int> prevRow = triangle[rowNum - 1];
            // The first row element is always 1.
            row.push_back(1);
            // Each triangle element (other than the first and last of each row)
            // is equal to the sum of the elements above-and-to-the-left and
            // above-and-to-the-right.
            for (int j = 1; j < rowNum; j++) {
                row.push_back(prevRow[j - 1] + prevRow[j]);
            }
            // The last row element is always 1.
            row.push_back(1);
            triangle.push_back(row);
        }
        return triangle;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        List<IList<int>> triangle = new List<IList<int>>();
        // Base case; first row is always [1].
        triangle.Add(new List<int>());
        triangle[0].Add(1);
        for (int rowNum = 1; rowNum < numRows; rowNum++) {
            List<int> row = new List<int>();
            List<int> prevRow = (List<int>)triangle[rowNum - 1];
            // The first row element is always 1.
            row.Add(1);
            // Each triangle element (other than the first and last of each row)
            // is equal to the sum of the elements above-and-to-the-left and
            // above-and-to-the-right.
            for (int j = 1; j < rowNum; j++) {
                row.Add(prevRow[j - 1] + prevRow[j]);
            }

            // The last row element is always 1.
            row.Add(1);
            triangle.Add(row);
        }

        return triangle;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func generate(numRows int) [][]int {
    triangle := make([][]int, numRows)
    // Base case; first row is always [1].
    triangle[0] = append(triangle[0], 1)
    for rowNum := 1; rowNum < numRows; rowNum++ {
        row := make([]int, 0)
        prevRow := triangle[rowNum-1]
        // The first row element is always 1.
        row = append(row, 1)
        // Each triangle element (other than the first and last of each row)
        // is equal to the sum of the elements above-and-to-the-left and
        // above-and-to-the-right.
        for j := 1; j < rowNum; j++ {
            row = append(row, prevRow[j-1]+prevRow[j])
        }
        // The last row element is always 1.
        row = append(row, 1)
        triangle[rowNum] = row
    }
    return triangle
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<List<Integer>>();

        // Base case; first row is always [1].
        triangle.add(new ArrayList<>());
        triangle.get(0).add(1);

        for (int rowNum = 1; rowNum < numRows; rowNum++) {
            List<Integer> row = new ArrayList<>();
            List<Integer> prevRow = triangle.get(rowNum - 1);

            // The first row element is always 1.
            row.add(1);

            // Each triangle element (other than the first and last of each row)
            // is equal to the sum of the elements above-and-to-the-left and
            // above-and-to-the-right.
            for (int j = 1; j < rowNum; j++) {
                row.add(prevRow.get(j - 1) + prevRow.get(j));
            }

            // The last row element is always 1.
            row.add(1);

            triangle.add(row);
        }

        return triangle;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var generate = function (numRows) {
    // Return type is an array of arrays.
    const triangle = [];
    // Base case; first row is always [1].
    triangle.push([]);
    triangle[0].push(1);
    for (let rowNum = 1; rowNum < numRows; rowNum++) {
        const row = [];
        const prevRow = triangle[rowNum - 1];
        // The first row element is always 1.
        row.push(1);
        // Each triangle element (other than the first and last of each row)
        // is equal to the sum of the elements above-and-to-the-left and
        // above-and-to-the-right.
        for (let j = 1; j < rowNum; j++) {
            row.push(prevRow[j - 1] + prevRow[j]);
        }
        // The last row element is always 1.
        row.push(1);
        triangle.push(row);
    }
    return triangle;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def generate(self, num_rows: int) -> List[List[int]]:
        triangle = []

        for row_num in range(num_rows):
            # The first and last row elements are always 1.
            row = [None for _ in range(row_num + 1)]
            row[0], row[-1] = 1, 1

            # Each triangle element is equal to the sum of the elements
            # above-and-to-the-left and above-and-to-the-right.
            for j in range(1, len(row) - 1):
                row[j] = triangle[row_num - 1][j - 1] + triangle[row_num - 1][j]

            triangle.append(row)

        return triangle
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function generate(numRows: number): number[][] {
    // Return type is an array of arrays.
    const triangle: number[][] = [];
    // Base case; first row is always [1].
    triangle.push([]);
    triangle[0].push(1);
    for (let rowNum = 1; rowNum < numRows; rowNum++) {
        const row: number[] = [];
        const prevRow: number[] = triangle[rowNum - 1];
        // The first row element is always 1.
        row.push(1);
        // Each triangle element (other than the first and last of each row)
        // is equal to the sum of the elements above-and-to-the-left and
        // above-and-to-the-right.
        for (let j = 1; j < rowNum; j++) {
            row.push(prevRow[j - 1] + prevRow[j]);
        }
        // The last row element is always 1.
        row.push(1);
        triangle.push(row);
    }
    return triangle;
}
```

</details>
