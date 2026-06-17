# 72. Edit Distance

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/edit-distance/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 72 - Edit Distance](https://leetcode.com/problems/edit-distance/)

## Problem

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character

### Example 1

```text
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

### Example 2

```text
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```

## Constraints

- 0 <= word1.length, word2.length <= 500
- word1 and word2 consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [One Edit Distance](https://leetcode.com/problems/one-edit-distance/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum White Tiles After Covering With Carpets](https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Longest Palindrome After Substring Concatenation II](https://leetcode.com/problems/longest-palindrome-after-substring-concatenation-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Steps to Convert String with Operations](https://leetcode.com/problems/minimum-steps-to-convert-string-with-operations/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 72. Edit Distance

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Memoization: Top-Down Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bottom-Up Dynamic Programming: Tabulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int min(int a, int b) { return a < b ? a : b; }
int minDistanceRecur(char *word1, char *word2, int word1Index, int word2Index) {
    if (word1Index == 0) {
        return word2Index;
    }
    if (word2Index == 0) {
        return word1Index;
    }
    if (word1[word1Index - 1] == word2[word2Index - 1]) {
        return minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
    } else {
        int insertOperation =
            minDistanceRecur(word1, word2, word1Index, word2Index - 1);
        int deleteOperation =
            minDistanceRecur(word1, word2, word1Index - 1, word2Index);
        int replaceOperation =
            minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
        return min(insertOperation, min(deleteOperation, replaceOperation)) + 1;
    }
}
int minDistance(char *word1, char *word2) {
    return minDistanceRecur(word1, word2, strlen(word1), strlen(word2));
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        return minDistanceRecur(word1, word2, word1.size(), word2.size());
    }

    int minDistanceRecur(string word1, string word2, int word1Index,
                         int word2Index) {
        if (word1Index == 0) {
            return word2Index;
        }
        if (word2Index == 0) {
            return word1Index;
        }
        if (word1[word1Index - 1] == word2[word2Index - 1]) {
            return minDistanceRecur(word1, word2, word1Index - 1,
                                    word2Index - 1);
        } else {
            int insertOperation =
                minDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            return min(insertOperation,
                       min(deleteOperation, replaceOperation)) +
                   1;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinDistance(string word1, string word2) {
        return MinDistanceRecur(word1, word2, word1.Length, word2.Length);
    }

    public int MinDistanceRecur(string word1, string word2, int word1Index,
                                int word2Index) {
        if (word1Index == 0) {
            return word2Index;
        }

        if (word2Index == 0) {
            return word1Index;
        }

        if (word1[word1Index - 1] == word2[word2Index - 1]) {
            return MinDistanceRecur(word1, word2, word1Index - 1,
                                    word2Index - 1);
        } else {
            int insertOperation =
                MinDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation =
                MinDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation =
                MinDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            return Math.Min(insertOperation,
                            Math.Min(deleteOperation, replaceOperation)) +
                   1;
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func min(a int, b int, c int) int {
    if a <= b && a <= c {
        return a
    }
    if b <= a && b <= c {
        return b
    }
    return c
}

func minDistanceRecur(
    word1 string,
    word2 string,
    word1Index int,
    word2Index int,
) int {
    if word1Index == 0 {
        return word2Index
    }
    if word2Index == 0 {
        return word1Index
    }
    if word1[word1Index-1] == word2[word2Index-1] {
        return minDistanceRecur(word1, word2, word1Index-1, word2Index-1)
    } else {
        insertOperation := minDistanceRecur(word1, word2, word1Index, word2Index-1)
        deleteOperation := minDistanceRecur(word1, word2, word1Index-1, word2Index)
        replaceOperation := minDistanceRecur(word1, word2, word1Index-1, word2Index-1)
        return min(insertOperation, deleteOperation, replaceOperation) + 1
    }
}

func minDistance(word1 string, word2 string) int {
    return minDistanceRecur(word1, word2, len(word1), len(word2))
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDistance(String word1, String word2) {
        return minDistanceRecur(word1, word2, word1.length(), word2.length());
    }

    int minDistanceRecur(
        String word1,
        String word2,
        int word1Index,
        int word2Index
    ) {
        if (word1Index == 0) {
            return word2Index;
        }
        if (word2Index == 0) {
            return word1Index;
        }
        if (word1.charAt(word1Index - 1) == word2.charAt(word2Index - 1)) {
            return minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index - 1
            );
        } else {
            int insertOperation = minDistanceRecur(
                word1,
                word2,
                word1Index,
                word2Index - 1
            );
            int deleteOperation = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index
            );
            int replaceOperation = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index - 1
            );
            return (
                Math.min(
                    insertOperation,
                    Math.min(deleteOperation, replaceOperation)
                ) +
                1
            );
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minDistance = function (word1, word2) {
    return minDistanceRecur(word1, word2, word1.length, word2.length);
};
var minDistanceRecur = function (word1, word2, word1Index, word2Index) {
    if (word1Index == 0) {
        return word2Index;
    }
    if (word2Index == 0) {
        return word1Index;
    }
    if (word1.charAt(word1Index - 1) == word2.charAt(word2Index - 1)) {
        return minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
    } else {
        var insertOperation = minDistanceRecur(
            word1,
            word2,
            word1Index,
            word2Index - 1,
        );
        var deleteOperation = minDistanceRecur(
            word1,
            word2,
            word1Index - 1,
            word2Index,
        );
        var replaceOperation = minDistanceRecur(
            word1,
            word2,
            word1Index - 1,
            word2Index - 1,
        );
        return (
            Math.min(
                insertOperation,
                Math.min(deleteOperation, replaceOperation),
            ) + 1
        );
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # calculate the distance between two words using recursion
        return self.minDistanceRecur(word1, word2, len(word1), len(word2))

    def minDistanceRecur(
        self, word1: str, word2: str, word1Index: int, word2Index: int
    ) -> int:
        # base cases
        if (
            word1Index == 0
        ):  # if word1 is empty, the minimum distance is the length of word2
            return word2Index
        if (
            word2Index == 0
        ):  # if word2 is empty, the minimum distance is the length of word1
            return word1Index
        # if the characters are same, continue with next pair of characters
        if word1[word1Index - 1] == word2[word2Index - 1]:
            return self.minDistanceRecur(
                word1, word2, word1Index - 1, word2Index - 1
            )
        else:
            # calculate the cost of insert, delete, and replace operations
            insertOperation = self.minDistanceRecur(
                word1, word2, word1Index, word2Index - 1
            )
            deleteOperation = self.minDistanceRecur(
                word1, word2, word1Index - 1, word2Index
            )
            replaceOperation = self.minDistanceRecur(
                word1, word2, word1Index - 1, word2Index - 1
            )
            # return the minimum cost
            return min(insertOperation, deleteOperation, replaceOperation) + 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minDistance(word1: string, word2: string): number {
    return minDistanceRecur(word1, word2, word1.length, word2.length);
}
function minDistanceRecur(
    word1: string,
    word2: string,
    word1Index: number,
    word2Index: number,
): number {
    if (word1Index == 0) {
        return word2Index;
    }
    if (word2Index == 0) {
        return word1Index;
    }
    if (word1.charAt(word1Index - 1) == word2.charAt(word2Index - 1)) {
        return minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
    } else {
        let insertOperation = minDistanceRecur(
            word1,
            word2,
            word1Index,
            word2Index - 1,
        );
        let deleteOperation = minDistanceRecur(
            word1,
            word2,
            word1Index - 1,
            word2Index,
        );
        let replaceOperation = minDistanceRecur(
            word1,
            word2,
            word1Index - 1,
            word2Index - 1,
        );
        return (
            Math.min(
                insertOperation,
                Math.min(deleteOperation, replaceOperation),
            ) + 1
        );
    }
}
```

</details>

<br>

## Approach 2: Memoization: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int min(int a, int b) { return a < b ? a : b; }
int minDistance(char* word1, char* word2) {
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);
    int** memo = (int**)malloc((word1_len + 1) * sizeof(int*));
    for (int i = 0; i <= word1_len; i++) {
        memo[i] = (int*)malloc((word2_len + 1) * sizeof(int));
        for (int j = 0; j <= word2_len; j++) {
            memo[i][j] = -1;
        }
    }
    int minDistanceRecur(char* word1, char* word2, int word1Index,
                         int word2Index) {
        if (word1Index == 0) {
            return word2Index;
        }
        if (word2Index == 0) {
            return word1Index;
        }
        if (memo[word1Index][word2Index] != -1) {
            return memo[word1Index][word2Index];
        }
        int minEditDistance = 0;
        if (word1[word1Index - 1] == word2[word2Index - 1]) {
            minEditDistance =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
        } else {
            int insertOperation =
                minDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            minEditDistance =
                min(insertOperation, min(deleteOperation, replaceOperation)) +
                1;
        }
        memo[word1Index][word2Index] = minEditDistance;
        return minEditDistance;
    }
    return minDistanceRecur(word1, word2, word1_len, word2_len);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        memo.resize(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return minDistanceRecur(word1, word2, word1.size(), word2.size());
    }

    int minDistanceRecur(string &word1, string &word2, int word1Index,
                         int word2Index) {
        if (word1Index == 0) {
            return word2Index;
        }
        if (word2Index == 0) {
            return word1Index;
        }
        if (memo[word1Index][word2Index] != -1) {
            return memo[word1Index][word2Index];
        }
        int minEditDistance = 0;
        if (word1[word1Index - 1] == word2[word2Index - 1]) {
            minEditDistance =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
        } else {
            int insertOperation =
                minDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation =
                minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            minEditDistance =
                min(insertOperation, min(deleteOperation, replaceOperation)) +
                1;
        }
        memo[word1Index][word2Index] = minEditDistance;
        return minEditDistance;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinDistance(string word1, string word2) {
        int?[][] memo = new int ?[word1.Length + 1][];
        for (int i = 0; i <= word1.Length; i++)
            memo[i] = new int?[word2.Length + 1];
        return MinDistanceRecur(word1, word2, word1.Length, word2.Length);

        int MinDistanceRecur(string word1, string word2, int word1Index,
                             int word2Index) {
            if (word1Index == 0)
                return word2Index;
            if (word2Index == 0)
                return word1Index;
            if (memo[word1Index][word2Index] != null)
                return memo[word1Index][word2Index].Value;
            int minEditDistance = 0;
            if (word1[word1Index - 1] == word2[word2Index - 1])
                minEditDistance = MinDistanceRecur(word1, word2, word1Index - 1,
                                                   word2Index - 1);
            else {
                int insertOperation =
                    MinDistanceRecur(word1, word2, word1Index, word2Index - 1);
                int deleteOperation =
                    MinDistanceRecur(word1, word2, word1Index - 1, word2Index);
                int replaceOperation = MinDistanceRecur(
                    word1, word2, word1Index - 1, word2Index - 1);
                minEditDistance =
                    Math.Min(insertOperation,
                             Math.Min(deleteOperation, replaceOperation)) +
                    1;
            }

            memo[word1Index][word2Index] = minEditDistance;
            return minEditDistance;
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minDistance(word1 string, word2 string) int {
    memo := make([][]int, len(word1)+1)
    for i := range memo {
        memo[i] = make([]int, len(word2)+1)
        for j := range memo[i] {
            memo[i][j] = -1
        }
    }
    min := func(a, b, c int) int {
        if a < b {
            if a < c {
                return a
            }
            return c
        }
        if b < c {
            return b
        }
        return c
    }
    var minDistanceRecur func(word1, word2 string, word1Index, word2Index int) int
    minDistanceRecur = func(word1, word2 string, word1Index, word2Index int) int {
        if word1Index == 0 {
            return word2Index
        }
        if word2Index == 0 {
            return word1Index
        }
        if memo[word1Index][word2Index] != -1 {
            return memo[word1Index][word2Index]
        }
        var minEditDistance int
        if word1[word1Index-1] == word2[word2Index-1] {
            minEditDistance = minDistanceRecur(
                word1,
                word2,
                word1Index-1,
                word2Index-1,
            )
        } else {
            insertOperation := minDistanceRecur(word1, word2, word1Index, word2Index-1)
            deleteOperation := minDistanceRecur(word1, word2, word1Index-1, word2Index)
            replaceOperation := minDistanceRecur(word1, word2, word1Index-1, word2Index-1)
            minEditDistance = min(insertOperation, deleteOperation, replaceOperation) + 1
        }
        memo[word1Index][word2Index] = minEditDistance
        return minEditDistance
    }
    return minDistanceRecur(word1, word2, len(word1), len(word2))
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Integer memo[][];

    public int minDistance(String word1, String word2) {
        memo = new Integer[word1.length() + 1][word2.length() + 1];
        return minDistanceRecur(word1, word2, word1.length(), word2.length());
    }

    int minDistanceRecur(
        String word1,
        String word2,
        int word1Index,
        int word2Index
    ) {
        if (word1Index == 0) {
            return word2Index;
        }
        if (word2Index == 0) {
            return word1Index;
        }
        if (memo[word1Index][word2Index] != null) {
            return memo[word1Index][word2Index];
        }
        int minEditDistance = 0;
        if (word1.charAt(word1Index - 1) == word2.charAt(word2Index - 1)) {
            minEditDistance = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index - 1
            );
        } else {
            int insertOperation = minDistanceRecur(
                word1,
                word2,
                word1Index,
                word2Index - 1
            );
            int deleteOperation = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index
            );
            int replaceOperation = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index - 1
            );
            minEditDistance = Math.min(
                insertOperation,
                Math.min(deleteOperation, replaceOperation)
            ) +
            1;
        }
        memo[word1Index][word2Index] = minEditDistance;
        return minEditDistance;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minDistance = function (word1, word2) {
    let memo = Array(word1.length + 1)
        .fill()
        .map(() => Array(word2.length + 1).fill(null));
    function minDistanceRecur(word1, word2, word1Index, word2Index) {
        if (word1Index === 0) {
            return word2Index;
        }
        if (word2Index === 0) {
            return word1Index;
        }
        if (memo[word1Index][word2Index] !== null) {
            return memo[word1Index][word2Index];
        }
        let minEditDistance = 0;
        if (word1[word1Index - 1] === word2[word2Index - 1]) {
            minEditDistance = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index - 1,
            );
        } else {
            let insertOperation = minDistanceRecur(
                word1,
                word2,
                word1Index,
                word2Index - 1,
            );
            let deleteOperation = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index,
            );
            let replaceOperation = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index - 1,
            );
            minEditDistance =
                Math.min(
                    insertOperation,
                    Math.min(deleteOperation, replaceOperation),
                ) + 1;
        }
        memo[word1Index][word2Index] = minEditDistance;
        return minEditDistance;
    }
    return minDistanceRecur(word1, word2, word1.length, word2.length);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        memo = [
            [None for _ in range(len(word2) + 1)] for _ in range(len(word1) + 1)
        ]

        def minDistanceRecur(word1, word2, word1Index, word2Index):
            if word1Index == 0:
                return word2Index
            if word2Index == 0:
                return word1Index
            if memo[word1Index][word2Index] is not None:
                return memo[word1Index][word2Index]
            minEditDistance = 0
            if word1[word1Index - 1] == word2[word2Index - 1]:
                minEditDistance = minDistanceRecur(
                    word1, word2, word1Index - 1, word2Index - 1
                )
            else:
                insertOperation = minDistanceRecur(
                    word1, word2, word1Index, word2Index - 1
                )
                deleteOperation = minDistanceRecur(
                    word1, word2, word1Index - 1, word2Index
                )
                replaceOperation = minDistanceRecur(
                    word1, word2, word1Index - 1, word2Index - 1
                )
                minEditDistance = (
                    min(insertOperation, deleteOperation, replaceOperation) + 1
                )
            memo[word1Index][word2Index] = minEditDistance
            return minEditDistance

        return minDistanceRecur(word1, word2, len(word1), len(word2))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minDistance(word1: string, word2: string): number {
    let memo: number[][] = Array.from({ length: word1.length + 1 }, () =>
        Array(word2.length + 1).fill(null),
    );
    function minDistanceRecur(
        word1: string,
        word2: string,
        word1Index: number,
        word2Index: number,
    ): number {
        if (word1Index === 0) {
            return word2Index;
        }
        if (word2Index === 0) {
            return word1Index;
        }
        if (memo[word1Index][word2Index] !== null) {
            return memo[word1Index][word2Index];
        }
        let minEditDistance = 0;
        if (word1[word1Index - 1] === word2[word2Index - 1]) {
            minEditDistance = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index - 1,
            );
        } else {
            let insertOperation = minDistanceRecur(
                word1,
                word2,
                word1Index,
                word2Index - 1,
            );
            let deleteOperation = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index,
            );
            let replaceOperation = minDistanceRecur(
                word1,
                word2,
                word1Index - 1,
                word2Index - 1,
            );
            minEditDistance =
                Math.min(
                    insertOperation,
                    Math.min(deleteOperation, replaceOperation),
                ) + 1;
        }
        memo[word1Index][word2Index] = minEditDistance;
        return minEditDistance;
    }
    return minDistanceRecur(word1, word2, word1.length, word2.length);
}
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming: Tabulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int min(int a, int b, int c) {
    int temp = a < b ? a : b;
    return temp < c ? temp : c;
}
int minDistance(char* word1, char* word2) {
    // The sizes of the words
    int word1Length = strlen(word1);
    int word2Length = strlen(word2);
    // If word1 is empty, the answer is the size of word2
    if (word1Length == 0) {
        return word2Length;
    }
    // If word2 is empty, the answer is the size of word1
    if (word2Length == 0) {
        return word1Length;
    }
    int dp[word1Length + 1][word2Length + 1];
    dp[0][0] = 0;
    for (int word1Index = 1; word1Index <= word1Length; word1Index++) {
        dp[word1Index][0] = word1Index;
    }
    for (int word2Index = 1; word2Index <= word2Length; word2Index++) {
        dp[0][word2Index] = word2Index;
    }
    for (int word1Index = 1; word1Index <= word1Length; word1Index++) {
        for (int word2Index = 1; word2Index <= word2Length; word2Index++) {
            if (word2[word2Index - 1] == word1[word1Index - 1]) {
                dp[word1Index][word2Index] = dp[word1Index - 1][word2Index - 1];
            } else {
                dp[word1Index][word2Index] =
                    min(dp[word1Index - 1][word2Index],
                        dp[word1Index][word2Index - 1],
                        dp[word1Index - 1][word2Index - 1]) +
                    1;
            }
        }
    }
    return dp[word1Length][word2Length];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        int word1Length = word1.size();
        int word2Length = word2.size();
        if (word1Length == 0) {
            return word2Length;
        }
        if (word2Length == 0) {
            return word1Length;
        }
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, 0));
        for (int word1Index = 1; word1Index <= word1Length; word1Index++) {
            dp[word1Index][0] = word1Index;
        }
        for (int word2Index = 1; word2Index <= word2Length; word2Index++) {
            dp[0][word2Index] = word2Index;
        }
        for (int word1Index = 1; word1Index <= word1Length; word1Index++) {
            for (int word2Index = 1; word2Index <= word2Length; word2Index++) {
                if (word2[word2Index - 1] == word1[word1Index - 1]) {
                    dp[word1Index][word2Index] =
                        dp[word1Index - 1][word2Index - 1];
                } else {
                    dp[word1Index][word2Index] =
                        min(dp[word1Index - 1][word2Index],
                            min(dp[word1Index][word2Index - 1],
                                dp[word1Index - 1][word2Index - 1])) +
                        1;
                }
            }
        }

        return dp[word1Length][word2Length];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinDistance(string word1, string word2) {
        int word1Length = word1.Length;
        int word2Length = word2.Length;
        if (word1Length == 0) {
            return word2Length;
        }

        if (word2Length == 0) {
            return word1Length;
        }

        int[,] dp = new int[word1Length + 1, word2Length + 1];
        for (int word1Index = 1; word1Index <= word1Length; word1Index++) {
            dp[word1Index, 0] = word1Index;
        }

        for (int word2Index = 1; word2Index <= word2Length; word2Index++) {
            dp[0, word2Index] = word2Index;
        }

        for (int word1Index = 1; word1Index <= word1Length; word1Index++) {
            for (int word2Index = 1; word2Index <= word2Length; word2Index++) {
                if (word2[word2Index - 1] == word1[word1Index - 1]) {
                    dp[word1Index, word2Index] =
                        dp[word1Index - 1, word2Index - 1];
                } else {
                    dp[word1Index, word2Index] =
                        Math.Min(dp[word1Index - 1, word2Index],
                                 Math.Min(dp[word1Index, word2Index - 1],
                                          dp[word1Index - 1, word2Index - 1])) +
                        1;
                }
            }
        }

        return dp[word1Length, word2Length];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func min(x, y, z int) int {
    m := x
    if y < m {
        m = y
    }
    if z < m {
        m = z
    }
    return m
}

func minDistance(word1 string, word2 string) int {
    word1Length := len(word1)
    word2Length := len(word2)
    if word1Length == 0 {
        return word2Length
    }
    if word2Length == 0 {
        return word1Length
    }
    dp := make([][]int, word1Length+1)
    for i := range dp {
        dp[i] = make([]int, word2Length+1)
    }
    for word1Index := 1; word1Index <= word1Length; word1Index++ {
        dp[word1Index][0] = word1Index
    }
    for word2Index := 1; word2Index <= word2Length; word2Index++ {
        dp[0][word2Index] = word2Index
    }
    for word1Index := 1; word1Index <= word1Length; word1Index++ {
        for word2Index := 1; word2Index <= word2Length; word2Index++ {
            if word2[word2Index-1] == word1[word1Index-1] {
                dp[word1Index][word2Index] = dp[word1Index-1][word2Index-1]
            } else {
                dp[word1Index][word2Index] = min(dp[word1Index-1][word2Index], dp[word1Index][word2Index-1], dp[word1Index-1][word2Index-1]) + 1
            }
        }
    }
    return dp[word1Length][word2Length]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int word1Length = word1.length();
        int word2Length = word2.length();

        if (word1Length == 0) {
            return word2Length;
        }
        if (word2Length == 0) {
            return word1Length;
        }

        int dp[][] = new int[word1Length + 1][word2Length + 1];

        for (int word1Index = 1; word1Index <= word1Length; word1Index++) {
            dp[word1Index][0] = word1Index;
        }

        for (int word2Index = 1; word2Index <= word2Length; word2Index++) {
            dp[0][word2Index] = word2Index;
        }

        for (int word1Index = 1; word1Index <= word1Length; word1Index++) {
            for (int word2Index = 1; word2Index <= word2Length; word2Index++) {
                if (
                    word2.charAt(word2Index - 1) == word1.charAt(word1Index - 1)
                ) {
                    dp[word1Index][word2Index] = dp[word1Index - 1][word2Index -
                        1];
                } else {
                    dp[word1Index][word2Index] = Math.min(
                        dp[word1Index - 1][word2Index],
                        Math.min(
                            dp[word1Index][word2Index - 1],
                            dp[word1Index - 1][word2Index - 1]
                        )
                    ) +
                    1;
                }
            }
        }

        return dp[word1Length][word2Length];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minDistance = function (word1, word2) {
    let word1Length = word1.length;
    let word2Length = word2.length;
    if (word1Length == 0) {
        return word2Length;
    }
    if (word2Length == 0) {
        return word1Length;
    }
    let dp = Array.from(
        Array(word1Length + 1),
        () => new Array(word2Length + 1),
    );
    for (let word1Index = 0; word1Index <= word1Length; ++word1Index) {
        dp[word1Index][0] = word1Index;
    }
    for (let word2Index = 0; word2Index <= word2Length; ++word2Index) {
        dp[0][word2Index] = word2Index;
    }
    for (let word1Index = 1; word1Index <= word1Length; ++word1Index) {
        for (let word2Index = 1; word2Index <= word2Length; ++word2Index) {
            if (word2.charAt(word2Index - 1) == word1.charAt(word1Index - 1)) {
                dp[word1Index][word2Index] = dp[word1Index - 1][word2Index - 1];
            } else {
                dp[word1Index][word2Index] =
                    Math.min(
                        dp[word1Index - 1][word2Index],
                        dp[word1Index][word2Index - 1],
                        dp[word1Index - 1][word2Index - 1],
                    ) + 1;
            }
        }
    }
    return dp[word1Length][word2Length];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        word1Length = len(word1)
        word2Length = len(word2)
        if word1Length == 0:
            return word2Length
        if word2Length == 0:
            return word1Length
        dp = [
            [0 for _ in range(word2Length + 1)] for _ in range(word1Length + 1)
        ]
        for word1Index in range(1, word1Length + 1):
            dp[word1Index][0] = word1Index
        for word2Index in range(1, word2Length + 1):
            dp[0][word2Index] = word2Index
        for word1Index in range(1, word1Length + 1):
            for word2Index in range(1, word2Length + 1):
                if word2[word2Index - 1] == word1[word1Index - 1]:
                    dp[word1Index][word2Index] = dp[word1Index - 1][
                        word2Index - 1
                    ]
                else:
                    dp[word1Index][word2Index] = (
                        min(
                            dp[word1Index - 1][word2Index],
                            dp[word1Index][word2Index - 1],
                            dp[word1Index - 1][word2Index - 1],
                        )
                        + 1
                    )
        return dp[word1Length][word2Length]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minDistance(word1: string, word2: string): number {
    let word1Length = word1.length;
    let word2Length = word2.length;
    if (word1Length == 0) {
        return word2Length;
    }
    if (word2Length == 0) {
        return word1Length;
    }
    let dp: number[][] = Array.from(Array(word1Length + 1), () =>
        Array(word2Length + 1).fill(0),
    );
    for (let word1Index = 1; word1Index <= word1Length; ++word1Index) {
        dp[word1Index][0] = word1Index;
    }
    for (let word2Index = 1; word2Index <= word2Length; ++word2Index) {
        dp[0][word2Index] = word2Index;
    }
    for (let word1Index = 1; word1Index <= word1Length; ++word1Index) {
        for (let word2Index = 1; word2Index <= word2Length; ++word2Index) {
            if (word2.charAt(word2Index - 1) == word1.charAt(word1Index - 1)) {
                dp[word1Index][word2Index] = dp[word1Index - 1][word2Index - 1];
            } else {
                dp[word1Index][word2Index] =
                    Math.min(
                        dp[word1Index - 1][word2Index],
                        dp[word1Index][word2Index - 1],
                        dp[word1Index - 1][word2Index - 1],
                    ) + 1;
            }
        }
    }
    return dp[word1Length][word2Length];
}
```

</details>
