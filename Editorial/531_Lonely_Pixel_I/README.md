# 531. Lonely Pixel I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/lonely-pixel-i/)  
`Array` `Hash Table` `Matrix`

**Problem Link:** [LeetCode 531 - Lonely Pixel I](https://leetcode.com/problems/lonely-pixel-i/)

## Problem

Given an m x n picture consisting of black 'B' and white 'W' pixels, return the number of black lonely pixels.

A black lonely pixel is a character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

### Example 1

```text
Input: picture = [["W","W","B"],["W","B","W"],["B","W","W"]]
Output: 3
Explanation: All the three 'B's are black lonely pixels.
```

### Example 2

```text
Input: picture = [["B","B","B"],["B","B","W"],["B","B","B"]]
Output: 0
```

## Constraints

- m == picture.length
- n == picture[i].length
- 1 <= m, n <= 500
- picture[i][j] is 'W' or 'B'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Lonely Pixel II](https://leetcode.com/problems/lonely-pixel-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 531. Lonely Pixel I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Counting with Arrays | C++, Java |
| Space Optimized Counting | C++, Java |

## Approach 1: Counting with Arrays

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = int(picture.size());
        int m = int(picture[0].size());
        
        // Arrays to store the count of black cells in rows and columns.
        vector<int> rowCount(n, 0);
        vector<int> columnCount(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == 'B') {
                    rowCount[i]++;
                    columnCount[j]++;
                }
            }
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Its a lonely cell, if the current cell is black and,
                // the count of black cells in its row and column is 1.
                if (picture[i][j] == 'B' && rowCount[i] == 1 && columnCount[j] == 1) {
                    answer++;
                }
            }
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findLonelyPixel(char[][] picture) {
        int n = picture.length;
        int m = picture[0].length;
        
        // Arrays to store the count of black cells in rows and columns.
        int rowCount[] = new int[n];
        int columnCount[] = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == 'B') {
                    rowCount[i]++;
                    columnCount[j]++;
                }
            }
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Its a lonely cell, if the current cell is black and,
                // the count of black cells in its row and column is 1.
                if (picture[i][j] == 'B' && rowCount[i] == 1 && columnCount[j] == 1) {
                    answer++;
                }
            }
        }
        
        return answer;
    }
}
```

</details>

<br>

## Approach 2: Space Optimized Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp

class Solution {
public:
    // Returns true if the cell at (x, y) is lonely.
    // There should not be any other black cell 
    // In the first row and column except (x, y) itself.
    bool check(vector<vector<char>>& picture, int x, int y) {
        int n = int(picture.size());
        int m = int(picture[0].size());
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (picture[i][y] == 'B');
        }
        
        for (int j = 0; j < m; j++) {
            // avoid double count (x, y)
            if (j != y) cnt += (picture[x][j] == 'B');
        }
        return picture[x][y] == 'B' && cnt == 1;
    }
    
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = int(picture.size());
        int m = int(picture[0].size());
        
        int answer = 0;
        // Lonely cells in the first row
        for (int j = 0; j < m; j++) {
            answer += check(picture, 0, j);
        }
        //Lonely cells in the first column
        for (int i = 1; i < n; i++) {
            answer += check(picture, i, 0);
        }

        // Convert cell 'B' to '1' and 'W' to '0'
        for (int j = 0; j < m; j++) {
            picture[0][j] = (picture[0][j] == 'B' ? '1' : '0');
        }
        
        for (int i = 0; i < n; i++) {
            picture[i][0] = (picture[i][0] == 'B' ? '1' : '0');
        }
        
        // If the cell is black increment the count of corresponding row and column by 1
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (picture[i][j] == 'B') {
                    picture[i][0]++;
                    picture[0][j]++;
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (picture[i][j] == 'B') {
                    if (picture[0][j] == '1' && picture[i][0] == '1') {
                        answer++;
                    }
                }
            }
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns true if the cell at (x, y) is lonely.
    // There should not be any other black cell 
    // In the first row and column except (x, y) itself.
    boolean check(char[][] picture, int x, int y) {
        int n = picture.length;
        int m = picture[0].length;
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (picture[i][y] == 'B' ? 1 : 0);
        }
        
        for (int j = 0; j < m; j++) {
            // avoid double count (x, y)
            if (j != y) cnt += (picture[x][j] == 'B' ? 1 : 0);
        }
        return picture[x][y] == 'B' && cnt == 1;
    }
    
    public int findLonelyPixel(char[][] picture) {
        int n = picture.length;
        int m = picture[0].length;
        
        int answer = 0;
        for (int j = 0; j < m; j++) {
            answer += check(picture, 0, j) ? 1 : 0;
        }
        for (int i = 1; i < n; i++) {
            answer += check(picture, i, 0) ? 1 : 0;
        }

        // Convert cell 'B' to '1' and 'W' to '0'
        for (int j = 0; j < m; j++) {
            picture[0][j] = (picture[0][j] == 'B' ? '1' : '0');
        }
        
        for (int i = 0; i < n; i++) {
            picture[i][0] = (picture[i][0] == 'B' ? '1' : '0');
        }
        
        // If the cell is black increment the count of corresponding row and column by 1
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (picture[i][j] == 'B') {
                    picture[i][0]++;
                    picture[0][j]++;
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (picture[i][j] == 'B') {
                    if (picture[0][j] == '1' && picture[i][0] == '1') {
                        answer++;
                    }
                }
            }
        }
        
        return answer;
    }
}
```

</details>
