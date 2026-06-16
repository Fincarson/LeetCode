# 6. Zigzag Conversion

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/zigzag-conversion/)  
`String`

**Problem Link:** [LeetCode 6 - Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)

## Problem

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```text
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

```text
string convert(string s, int numRows);
```

### Example 1

```text
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

### Example 2

```text
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

### Example 3

```text
Input: s = "A", numRows = 1
Output: "A"
```

## Constraints

- 1 <= s.length <= 1000
- s consists of English letters (lower-case and upper-case), ',' and '.'.
- 1 <= numRows <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 6. Zigzag Conversion

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulate Zig-Zag Movement | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| String Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Simulate Zig-Zag Movement

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* convert(char* s, int numRows) {
    if (numRows == 1)
        return s;  // If numRows is 1, return early as there is no zig zag

    int n = strlen(s);

    // The zig zag pattern creates what can be described as a section of
    // numRows-1 (numCols) columns
    int sections = ceil((float)n / (float)(2 * numRows - 2));
    int numCols = sections * (numRows - 1);

    // Create matrix
    char matrix[numRows][numCols];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = ' ';  // Fill with spaces
        }
    }

    // Initialize indices
    int currRow = 0, currCol = 0, currStringIndex = 0;

    // Iterate in zig-zag pattern on matrix and fill it with string characters.
    while (currStringIndex < n) {
        // Move down.
        while (currRow < numRows && currStringIndex < n) {
            matrix[currRow][currCol] = s[currStringIndex];
            currRow++;
            currStringIndex++;
        }

        // Move diagonally up to the right.
        currRow -= 2;
        currCol++;
        while (currRow > 0 && currCol < numCols && currStringIndex < n) {
            matrix[currRow][currCol] = s[currStringIndex];
            currRow--;
            currCol++;
            currStringIndex++;
        }
    }

    char* answer = malloc((n + 1) * sizeof(char));
    int index = 0;
    // Traverse matrix and collect characters to answer
    for (int a = 0; a < numRows; a++) {
        for (int b = 0; b < numCols; b++) {
            if (matrix[a][b] != ' ') {
                answer[index] =
                    matrix[a][b];  // Place in same string to save memory
                index++;
            }
        }
    }

    answer[index] = '\0';  // Ensure null termination
    return answer;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int n = int(s.size());
        int sections = ceil(n / (2 * numRows - 2.0));
        int numCols = sections * (numRows - 1);

        vector<vector<char>> matrix(numRows, vector<char>(numCols, ' '));

        int currRow = 0, currCol = 0;
        int currStringIndex = 0;

        // Iterate in zig-zag pattern on matrix and fill it with string
        // characters.
        while (currStringIndex < n) {
            // Move down.
            while (currRow < numRows && currStringIndex < n) {
                matrix[currRow][currCol] = s[currStringIndex];
                currRow++;
                currStringIndex++;
            }

            currRow -= 2;
            currCol++;

            // Move up (with moving right also).
            while (currRow > 0 && currCol < numCols && currStringIndex < n) {
                matrix[currRow][currCol] = s[currStringIndex];
                currRow--;
                currCol++;
                currStringIndex++;
            }
        }

        string answer;
        for (auto& row : matrix) {
            for (auto& character : row) {
                if (character != ' ') {
                    answer += character;
                }
            }
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string Convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int n = s.Length;
        int sections = (int)Math.Ceiling(n / (2 * numRows - 2.0));
        int numCols = sections * (numRows - 1);

        char[][] matrix = new char [numRows][];
        for (int i = 0; i < numRows; i++) {
            matrix[i] = new char[numCols];
            matrix[i] = Enumerable.Repeat(' ', numCols).ToArray();
        }

        int currRow = 0, currCol = 0;
        int currStringIndex = 0;

        // Iterate in zig-zag pattern on matrix and fill it with string
        // characters.
        while (currStringIndex < n) {
            // Move down.
            while (currRow < numRows && currStringIndex < n) {
                matrix[currRow][currCol] = s[currStringIndex];
                currRow++;
                currStringIndex++;
            }

            currRow -= 2;
            currCol++;

            // Move up (with moving right also).
            while (currRow > 0 && currCol < numCols && currStringIndex < n) {
                matrix[currRow][currCol] = s[currStringIndex];
                currRow--;
                currCol++;
                currStringIndex++;
            }
        }

        string answer = "";
        foreach (char[] row in matrix) {
            string rowStr = new string(row).Replace(" ", "");
            answer += rowStr;
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func convert(s string, numRows int) string {
    if numRows == 1 {
        return s
    }

    n := len(s)
    sections := int(math.Ceil(float64(n) / float64(2*numRows-2)))
    numCols := sections * (numRows - 1)

    matrix := make([][]rune, numRows)
    for i := range matrix {
        matrix[i] = make([]rune, numCols)
        for j := range matrix[i] {
            matrix[i][j] = ' '
        }
    }

    currRow, currCol, currStringIndex := 0, 0, 0

    // Iterate in zig-zag pattern on matrix and fill it with string characters.
    for currStringIndex < n {
        // Move down.
        for currRow < numRows && currStringIndex < n {
            matrix[currRow][currCol] = rune(s[currStringIndex])
            currRow++
            currStringIndex++
        }

        currRow -= 2
        currCol++

        // Move up (with moving right also).
        for currRow > 0 && currCol < numCols && currStringIndex < n {
            matrix[currRow][currCol] = rune(s[currStringIndex])
            currRow--
            currCol++
            currStringIndex++
        }
    }

    answer := make([]rune, 0)
    for _, row := range matrix {
        for _, character := range row {
            if character != ' ' {
                answer = append(answer, character)
            }
        }
    }

    return string(answer)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int n = s.length();
        int sections = (int) Math.ceil(n / (2 * numRows - 2.0));
        int numCols = sections * (numRows - 1);

        char[][] matrix = new char[numRows][numCols];
        for (char[] row : matrix) {
            Arrays.fill(row, ' ');
        }

        int currRow = 0, currCol = 0;
        int currStringIndex = 0;

        // Iterate in zig-zag pattern on matrix and fill it with string characters.
        while (currStringIndex < n) {
            // Move down.
            while (currRow < numRows && currStringIndex < n) {
                matrix[currRow][currCol] = s.charAt(currStringIndex);
                currRow++;
                currStringIndex++;
            }

            currRow -= 2;
            currCol++;

            // Move up (with moving right also).
            while (currRow > 0 && currCol < numCols && currStringIndex < n) {
                matrix[currRow][currCol] = s.charAt(currStringIndex);
                currRow--;
                currCol++;
                currStringIndex++;
            }
        }

        StringBuilder answer = new StringBuilder();
        for (char[] row : matrix) {
            for (char character : row) {
                if (character != ' ') {
                    answer.append(character);
                }
            }
        }

        return answer.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let convert = function (s, numRows) {
    if (numRows == 1) {
        return s;
    }

    let n = s.length;
    let sections = Math.ceil(n / (2 * numRows - 2.0));
    let numCols = sections * (numRows - 1);

    let matrix = new Array(numRows)
        .fill(0)
        .map(() => new Array(numCols).fill(" "));

    let currRow = 0,
        currCol = 0;
    let currStringIndex = 0;

    // Iterate in zig-zag pattern on matrix and fill it with string characters.
    while (currStringIndex < n) {
        // Move down.
        while (currRow < numRows && currStringIndex < n) {
            matrix[currRow][currCol] = s[currStringIndex];
            currRow++;
            currStringIndex++;
        }

        currRow -= 2;
        currCol++;

        // Move up (with moving right also).
        while (currRow > 0 && currCol < numCols && currStringIndex < n) {
            matrix[currRow][currCol] = s[currStringIndex];
            currRow--;
            currCol++;
            currStringIndex++;
        }
    }

    let answer = matrix.map((row) => row.join("")).join("");
    return answer.replaceAll(" ", "");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def convert(self, s: str, num_rows: int) -> str:
        if num_rows == 1:
            return s

        n = len(s)
        sections = ceil(n / (2 * num_rows - 2.0))
        num_cols = sections * (num_rows - 1)

        matrix = [[" "] * num_cols for _ in range(num_rows)]

        curr_row, curr_col = 0, 0
        curr_string_index = 0

        # Iterate in zig-zag pattern on matrix and fill it with string characters.
        while curr_string_index < n:
            # Move down.
            while curr_row < num_rows and curr_string_index < n:
                matrix[curr_row][curr_col] = s[curr_string_index]
                curr_row += 1
                curr_string_index += 1

            curr_row -= 2
            curr_col += 1

            # Move up (with moving right also).
            while (
                curr_row > 0 and curr_col < num_cols and curr_string_index < n
            ):
                matrix[curr_row][curr_col] = s[curr_string_index]
                curr_row -= 1
                curr_col += 1
                curr_string_index += 1

        answer = ""
        for row in matrix:
            answer += "".join(row)

        return answer.replace(" ", "")
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function convert(s: string, numRows: number): string {
    if (numRows === 1) {
        return s;
    }

    let n = s.length;
    let sections = Math.ceil(n / (2 * numRows - 2));
    let numCols = sections * (numRows - 1);

    let matrix = Array.from({ length: numRows }, () =>
        Array(numCols).fill(" "),
    );

    let currRow = 0,
        currCol = 0;
    let currStringIndex = 0;

    // Iterate in zig-zag pattern on matrix and fill it with string characters.
    while (currStringIndex < n) {
        // Move down.
        while (currRow < numRows && currStringIndex < n) {
            matrix[currRow][currCol] = s[currStringIndex];
            currRow++;
            currStringIndex++;
        }

        currRow -= 2;
        currCol++;

        // Move up (with moving right also).
        while (currRow > 0 && currCol < numCols && currStringIndex < n) {
            matrix[currRow][currCol] = s[currStringIndex];
            currRow--;
            currCol++;
            currStringIndex++;
        }
    }

    let answer = matrix.map((row) => row.join(""));
    return answer.join("").split(" ").join("");
}
```

</details>

<br>

## Approach 2: String Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
const char* convert(char* s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int n = strlen(s);
    char* answer = malloc((n + 1) * sizeof(char));
    int charsInSection = 2 * (numRows - 1);

    int ans_index = 0;
    for (int currRow = 0; currRow < numRows; currRow++) {
        int index = currRow;
        while (index < n) {
            answer[ans_index] = s[index];
            ans_index += 1;

            // If current row is not first or last,
            // then we have to add one more character of current section.
            if (currRow != 0 && currRow != numRows - 1) {
                int charsInBetween = charsInSection - 2 * currRow;
                int secondIndex = index + charsInBetween;

                if (secondIndex < n) {
                    answer[ans_index] = s[secondIndex];
                    ans_index += 1;
                }
            }
            // Jump to same row's first character of next section.
            index += charsInSection;
        }
    }
    answer[n] = '\0';
    return answer;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string answer;
        int n = s.size();
        int charsInSection = 2 * (numRows - 1);

        for (int currRow = 0; currRow < numRows; ++currRow) {
            int index = currRow;

            while (index < n) {
                answer += s[index];

                // If currRow is not the first or last row
                // then we have to add one more character of current section.
                if (currRow != 0 && currRow != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * currRow;
                    int secondIndex = index + charsInBetween;

                    if (secondIndex < n) {
                        answer += s[secondIndex];
                    }
                }
                // Jump to same row's first character of next section.
                index += charsInSection;
            }
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string Convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        StringBuilder answer = new StringBuilder();
        int n = s.Length;
        int charsInSection = 2 * (numRows - 1);

        for (int currRow = 0; currRow < numRows; ++currRow) {
            int index = currRow;

            while (index < n) {
                answer.Append(s[index]);

                // If currRow is not the first or last row
                // then we have to add one more character of current section.
                if (currRow != 0 && currRow != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * currRow;
                    int secondIndex = index + charsInBetween;

                    if (secondIndex < n) {
                        answer.Append(s[secondIndex]);
                    }
                }

                // Jump to same row's first character of next section.
                index += charsInSection;
            }
        }

        return answer.ToString();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func convert(s string, numRows int) string {
    if numRows == 1 {
        return s
    }

    var answer strings.Builder
    n := len(s)
    charsInSection := 2 * (numRows - 1)

    for currRow := 0; currRow < numRows; currRow++ {
        index := currRow
        for index < n {
            answer.WriteByte(s[index])

            // If current row is not first or last,
            // then we have to add one more character of current section.
            if currRow != 0 && currRow != numRows-1 {
                charsInBetween := charsInSection - 2*currRow
                secondIndex := index + charsInBetween
                if secondIndex < n {
                    answer.WriteByte(s[secondIndex])
                }
            }
            // Jump to same row's first character of next section.
            index += charsInSection
        }
    }
    return answer.String()
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        StringBuilder answer = new StringBuilder();
        int n = s.length();
        int charsInSection = 2 * (numRows - 1);

        for (int currRow = 0; currRow < numRows; ++currRow) {
            int index = currRow;

            while (index < n) {
                answer.append(s.charAt(index));

                // If currRow is not the first or last row
                // then we have to add one more character of current section.
                if (currRow != 0 && currRow != numRows - 1) {
                    int charsInBetween = charsInSection - 2 * currRow;
                    int secondIndex = index + charsInBetween;

                    if (secondIndex < n) {
                        answer.append(s.charAt(secondIndex));
                    }
                }
                // Jump to same row's first character of next section.
                index += charsInSection;
            }
        }

        return answer.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let convert = function (s, numRows) {
    if (numRows == 1) {
        return s;
    }

    let answer = "";
    let n = s.length;
    let charsInSection = 2 * (numRows - 1);

    for (let currRow = 0; currRow < numRows; ++currRow) {
        let index = currRow;

        while (index < n) {
            answer += s[index];

            // If current row is not first or last,
            // then we have to add one more character of current section.
            if (currRow != 0 && currRow != numRows - 1) {
                let charsInBetween = charsInSection - 2 * currRow;
                let secondIndex = index + charsInBetween;

                if (secondIndex < n) {
                    answer += s[secondIndex];
                }
            }
            // Jump to same row's first character of next section.
            index += charsInSection;
        }
    }

    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        answer = []
        n = len(s)
        chars_in_section = 2 * (numRows - 1)

        for curr_row in range(numRows):
            index = curr_row
            while index < n:
                answer.append(s[index])

                # If curr_row is not the first or last row,
                # then we have to add one more character of current section.
                if curr_row != 0 and curr_row != numRows - 1:
                    chars_in_between = chars_in_section - 2 * curr_row
                    second_index = index + chars_in_between

                    if second_index < n:
                        answer.append(s[second_index])
                # Jump to same row's first character of next section.
                index += chars_in_section

        return "".join(answer)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function convert(s: string, numRows: number): string {
    if (numRows === 1) {
        return s;
    }

    let answer: string = "";
    let n: number = s.length;
    let charsInSection: number = 2 * (numRows - 1);

    for (let currRow: number = 0; currRow < numRows; ++currRow) {
        let index: number = currRow;
        while (index < n) {
            answer += s[index];

            // If current row is not first or last,
            // then we have to add one more character of current section.
            if (currRow != 0 && currRow != numRows - 1) {
                let charsInBetween: number = charsInSection - 2 * currRow;
                let secondIndex: number = index + charsInBetween;
                if (secondIndex < n) {
                    answer += s[secondIndex];
                }
            }
            // Jump to same row's first character of next section.
            index += charsInSection;
        }
    }
    return answer;
}
```

</details>
