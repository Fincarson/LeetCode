# 1198. Find Smallest Common Element in All Rows

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-smallest-common-element-in-all-rows/)  
`Array` `Hash Table` `Binary Search` `Matrix` `Counting`

**Problem Link:** [LeetCode 1198 - Find Smallest Common Element in All Rows](https://leetcode.com/problems/find-smallest-common-element-in-all-rows/)

## Problem

Given an m x n matrix mat where every row is sorted in strictly increasing order, return the smallest common element in all rows.

If there is no common element, return -1.

### Example 1

```text
Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
Output: 5
```

### Example 2

```text
Input: mat = [[1,2,3],[2,3,4],[2,3,5]]
Output: 2
```

## Constraints

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 500
- 1 <= mat[i][j] <= 104
- mat[i] is sorted in strictly increasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1198. Find Smallest Common Element in All Rows

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count Elements | C++, Java |
| Binary Search | C++, Java |
| Row Positions | C++, Java |

## Approach 1: Count Elements

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int smallestCommonElement(vector<vector<int>>& mat) {
    int count[10001] = {};
    int n = mat.size(), m = mat[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ++count[mat[i][j]];
        }
    }
    for (int k = 1; k <= 10000; ++k) {
        if (count[k] == n) {
            return k;
        }
    }
    return -1;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public int smallestCommonElement(int[][] mat) {
    int count[] = new int[10001];
    int n = mat.length, m = mat[0].length;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ++count[mat[i][j]];
        }
    }
    for (int k = 1; k <= 10000; ++k) {
        if (count[k] == n) {
            return k;
        }
    } 
    return -1;
}
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int smallestCommonElement(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    for (int j = 0; j < m; ++j) {
        bool found = true;
        for (int i = 1; i < n && found; ++i) {
            found = binary_search(begin(mat[i]), end(mat[i]), mat[0][j]);
        }
        if (found) {
            return mat[0][j];
        }
    }
    return -1;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public int smallestCommonElement(int[][] mat) {
    int n = mat.length, m = mat[0].length;
    for (int j = 0; j < m; ++j) {
        boolean found = true;
        for (int i = 1; i < n && found; ++i) {
            found = Arrays.binarySearch(mat[i], mat[0][j]) >= 0;
        }
        if (found) {
            return mat[0][j];
        }
    }
    return -1;
}
```

</details>

<br>

## Approach 3: Row Positions

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int smallestCommonElement(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int cur_max = 0, cnt = 0;
    vector<int> pos(n);
    while (true) {
        for (int i = 0; i < n; ++i) {
            while (pos[i] < m && mat[i][pos[i]] < cur_max) {
                ++pos[i];
            }
            if (pos[i] >= m) {
                return -1;
            }
            if (cur_max != mat[i][pos[i]]) {
                cnt = 1;
                cur_max = mat[i][pos[i]];
            } else if (++cnt == n) {
                return cur_max;
            }
        }
    }
    return -1;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public int smallestCommonElement(int[][] mat) {
    int n = mat.length, m = mat[0].length;
    int pos[] = new int[n], cur_max = 0, cnt = 0;
    while (true) {
        for (int i = 0; i < n; ++i) {
            while (pos[i] < m && mat[i][pos[i]] < cur_max) {
                ++pos[i];
            }
            if (pos[i] >= m) {
                return -1;
            }
            if (mat[i][pos[i]] != cur_max) {
                cnt = 1;
                cur_max = mat[i][pos[i]];
            } else if (++cnt == n) {
                return cur_max;
            }
        }
    }
}
```

</details>
