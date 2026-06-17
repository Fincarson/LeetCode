# 593. Valid Square

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/valid-square/)  
`Math` `Geometry`

**Problem Link:** [LeetCode 593 - Valid Square](https://leetcode.com/problems/valid-square/)

## Problem

Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).

### Example 1

```text
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true
```

### Example 2

```text
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false
```

### Example 3

```text
Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true
```

## Constraints

- p1.length == p2.length == p3.length == p4.length == 2
- -104 <= xi, yi <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 593. Valid Square

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Accepted] | C++, Java, Python3 |
| Approach #2 Using Sorting [Accepted] | C++, Java, Python3 |
| Approach #3 Checking every case [Accepted] | C++, Java, Python3 |

## Approach #1 Brute Force [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2) {
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) +
               (p2[0] - p1[0]) * (p2[0] - p1[0]);
    }

    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3,
               vector<int>& p4) {
        return dist(p1, p2) > 0 && dist(p1, p2) == dist(p2, p3) &&
               dist(p2, p3) == dist(p3, p4) && dist(p3, p4) == dist(p1, p4) &&
               dist(p1, p3) == dist(p2, p4);
    }

    void swap(vector<vector<int>>& p, int x, int y) {
        vector<int> temp = p[x];
        p[x] = p[y];
        p[y] = temp;
    }

    bool checkAllPermutations(vector<vector<int>>& p, int l) {
        if (l == 4) {
            if (p[0] == p[1] || p[1] == p[2] || p[2] == p[3] || p[3] == p[0] ||
                p[0] == p[2] || p[1] == p[3])
                return false;
            return check(p[0], p[1], p[2], p[3]);
        } else {
            bool res = false;
            for (int i = l; i < 4; i++) {
                swap(p, l, i);
                res |= checkAllPermutations(p, l + 1);
                swap(p, l, i);
                if (res) return true;
            }
            return res;
        }
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                     vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        return checkAllPermutations(p, 0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int[][] p = { p1, p2, p3, p4 };
        return checkAllPermutations(p, 0);
    }

    private double dist(int[] p1, int[] p2) {
        return (
            (p2[1] - p1[1]) * (p2[1] - p1[1]) +
            (p2[0] - p1[0]) * (p2[0] - p1[0])
        );
    }

    private boolean check(int[] p1, int[] p2, int[] p3, int[] p4) {
        double d1 = dist(p1, p2);
        double d2 = dist(p2, p3);
        double d3 = dist(p3, p4);
        double d4 = dist(p1, p4);
        double d5 = dist(p1, p3);
        double d6 = dist(p2, p4);

        return d1 > 0 && d1 == d2 && d2 == d3 && d3 == d4 && d5 == d6;
    }

    private void swap(int[][] p, int x, int y) {
        int[] temp = p[x];
        p[x] = p[y];
        p[y] = temp;
    }

    private boolean checkAllPermutations(int[][] p, int l) {
        if (l == 4) {
            if (
                Arrays.equals(p[0], p[1]) ||
                Arrays.equals(p[1], p[2]) ||
                Arrays.equals(p[2], p[3]) ||
                Arrays.equals(p[3], p[0]) ||
                Arrays.equals(p[0], p[2]) ||
                Arrays.equals(p[1], p[3])
            ) {
                return false;
            }
            return check(p[0], p[1], p[2], p[3]);
        } else {
            boolean res = false;
            for (int i = l; i < 4; i++) {
                swap(p, l, i);
                res |= checkAllPermutations(p, l + 1);
                swap(p, l, i);
                if (res) return true;
            }
            return res;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validSquare(
        self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]
    ) -> bool:
        def dist(p1, p2):
            return (p2[1] - p1[1]) ** 2 + (p2[0] - p1[0]) ** 2

        def check(p1, p2, p3, p4):
            return (
                dist(p1, p2) > 0
                and dist(p1, p2) == dist(p2, p3)
                and dist(p2, p3) == dist(p3, p4)
                and dist(p3, p4) == dist(p4, p1)
                and dist(p1, p3) == dist(p2, p4)
            )

        def checkAllPermutations(p, l):
            if l == 4:
                return check(p[0], p[1], p[2], p[3])
            else:
                res = False
                for i in range(l, 4):
                    p[l], p[i] = p[i], p[l]
                    res |= checkAllPermutations(p, l + 1)
                    p[l], p[i] = p[i], p[l]
                return res

        p = [p1, p2, p3, p4]
        dis = [dist(p[i], p[(i + 1) % 4]) for i in range(4)]
        dis += [dist(p[i], p[(i + 2) % 4]) for i in range(4)]
        return (
            len(set(dis)) == 2 and min(dis) != 0 and checkAllPermutations(p, 0)
        )
```

</details>

<br>

## Approach #2 Using Sorting [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2) {
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) +
               (p2[0] - p1[0]) * (p2[0] - p1[0]);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                     vector<int>& p4) {
        vector<vector<int> > p{p1, p2, p3, p4};
        sort(p.begin(), p.end());
        return dist(p[0], p[1]) != 0 && dist(p[0], p[1]) == dist(p[1], p[3]) &&
               dist(p[1], p[3]) == dist(p[3], p[2]) &&
               dist(p[3], p[2]) == dist(p[2], p[0]) &&
               dist(p[0], p[3]) == dist(p[1], p[2]);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public double dist(int[] p1, int[] p2) {
        return (
            (p2[1] - p1[1]) * (p2[1] - p1[1]) +
            (p2[0] - p1[0]) * (p2[0] - p1[0])
        );
    }

    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int[][] p = { p1, p2, p3, p4 };
        Arrays.sort(p, (l1, l2) ->
            l2[0] == l1[0] ? l1[1] - l2[1] : l1[0] - l2[0]
        );
        return (
            dist(p[0], p[1]) != 0 &&
            dist(p[0], p[1]) == dist(p[1], p[3]) &&
            dist(p[1], p[3]) == dist(p[3], p[2]) &&
            dist(p[3], p[2]) == dist(p[2], p[0]) &&
            dist(p[0], p[3]) == dist(p[1], p[2])
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dist(self, p1, p2):
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (
            p2[0] - p1[0]
        )

    def validSquare(self, p1, p2, p3, p4):
        p = [p1, p2, p3, p4]
        p.sort(key=lambda l: (l[0], l[1]))
        return (
            self.dist(p[0], p[1]) != 0
            and self.dist(p[0], p[1]) == self.dist(p[1], p[3])
            and self.dist(p[1], p[3]) == self.dist(p[3], p[2])
            and self.dist(p[3], p[2]) == self.dist(p[2], p[0])
            and self.dist(p[0], p[3]) == self.dist(p[1], p[2])
        )
```

</details>

<br>

## Approach #3 Checking every case [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2) {
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) +
               (p2[0] - p1[0]) * (p2[0] - p1[0]);
    }

    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3,
               vector<int>& p4) {
        return dist(p1, p2) > 0 && dist(p1, p3) > 0 &&
               dist(p1, p2) == dist(p2, p3) && dist(p2, p3) == dist(p3, p4) &&
               dist(p3, p4) == dist(p4, p1) && dist(p1, p3) == dist(p2, p4);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                     vector<int>& p4) {
        return check(p1, p2, p3, p4) || check(p1, p3, p2, p4) ||
               check(p1, p2, p4, p3);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public double dist(int[] p1, int[] p2) {
        return (
            (p2[1] - p1[1]) * (p2[1] - p1[1]) +
            (p2[0] - p1[0]) * (p2[0] - p1[0])
        );
    }

    public boolean check(int[] p1, int[] p2, int[] p3, int[] p4) {
        return (
            dist(p1, p2) > 0 &&
            dist(p1, p3) > 0 &&
            dist(p1, p2) == dist(p2, p3) &&
            dist(p2, p3) == dist(p3, p4) &&
            dist(p3, p4) == dist(p4, p1) &&
            dist(p1, p3) == dist(p2, p4)
        );
    }

    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        return (
            check(p1, p2, p3, p4) ||
            check(p1, p3, p2, p4) ||
            check(p1, p2, p4, p3)
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dist(self, p1, p2):
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (
            p2[0] - p1[0]
        )

    def check(self, p1, p2, p3, p4):
        return (
            self.dist(p1, p2) > 0
            and self.dist(p1, p3) > 0
            and self.dist(p1, p2) == self.dist(p2, p3)
            and self.dist(p2, p3) == self.dist(p3, p4)
            and self.dist(p3, p4) == self.dist(p4, p1)
            and self.dist(p1, p3) == self.dist(p2, p4)
        )

    def validSquare(self, p1, p2, p3, p4):
        return (
            self.check(p1, p2, p3, p4)
            or self.check(p1, p3, p2, p4)
            or self.check(p1, p2, p4, p3)
        )
```

</details>
