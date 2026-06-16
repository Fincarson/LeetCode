# 779. K-th Symbol in Grammar

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/k-th-symbol-in-grammar/)  
`Math` `Bit Manipulation` `Recursion`

**Problem Link:** [LeetCode 779 - K-th Symbol in Grammar](https://leetcode.com/problems/k-th-symbol-in-grammar/)

## Problem

We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

- For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.

Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

### Example 1

```text
Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0
```

### Example 2

```text
Input: n = 2, k = 1
Output: 0
Explanation:
row 1: 0
row 2: 01
```

### Example 3

```text
Input: n = 2, k = 2
Output: 1
Explanation:
row 1: 0
row 2: 01
```

## Constraints

- 1 <= n <= 30
- 1 <= k <= 2n - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 779. K-th Symbol in Grammar

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Tree Traversal | C++, Java, JavaScript, Python3 |
| Normal Recursion | C++, Java, JavaScript, Python3 |
| Recursion to Iteration | C++, Java, JavaScript, Python3 |
| Math | C++, Java, JavaScript, Python3 |

## Approach 1: Binary Tree Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int depthFirstSearch(int n, int k, int rootVal) {
        if (n == 1) {
            return rootVal;
        }

        int totalNodes = pow(2, n - 1);

        // Target node will be present in the right half sub-tree of the current root node.
        if (k > (totalNodes / 2)) {
            int nextRootVal = (rootVal == 0) ? 1 : 0;
            return depthFirstSearch(n - 1, k - (totalNodes / 2), nextRootVal);
        }
        // Otherwise, the target node is in the left sub-tree of the current root node.
        else {
            int nextRootVal = (rootVal == 0) ? 0 : 1;
            return depthFirstSearch(n - 1, k, nextRootVal);
        }
    }

    int kthGrammar(int n, int k) {
        return depthFirstSearch(n, k, 0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int depthFirstSearch(int n, int k, int rootVal) {
        if (n == 1) {
            return rootVal;
        }

        int totalNodes = (int) Math.pow(2, n - 1);

        // Target node will be present in the right half sub-tree of the current root node.
        if (k > (totalNodes / 2)) {
            int nextRootVal = (rootVal == 0) ? 1 : 0;
            return depthFirstSearch(n - 1, k - (totalNodes / 2), nextRootVal);
        }
        // Otherwise, the target node is in the left sub-tree of the current root node.
        else {
            int nextRootVal = (rootVal == 0) ? 0 : 1;
            return depthFirstSearch(n - 1, k, nextRootVal);
        }
    }

    public int kthGrammar(int n, int k) {
        return depthFirstSearch(n, k, 0);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let depthFirstSearch = (n, k, rootVal) => {
    if (n === 1) {
        return rootVal;
    }

    let totalNodes = Math.pow(2, n - 1);

    // Target node will be present in the right half sub-tree of the current root node.
    if (k > totalNodes / 2) {
        let nextRootVal = (rootVal === 0) ? 1 : 0;
        return depthFirstSearch(n - 1, k - (totalNodes / 2), nextRootVal);
    }
    // Otherwise, the target node is in the left sub-tree of the current root node.
    else {
        let nextRootVal = (rootVal === 0) ? 0 : 1;
        return depthFirstSearch(n - 1, k, nextRootVal);
    }
};

let kthGrammar = function(n, k) {
    return depthFirstSearch(n, k, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def depthFirstSearch(self, n: int, k: int, rootVal: int) -> int:
        if n == 1:
            return rootVal

        totalNodes = 2 ** (n - 1)

        # Target node will be present in the right half sub-tree of the current root node.
        if k > (totalNodes / 2):
            nextRootVal = 1 if rootVal == 0 else 0
            return self.depthFirstSearch(n - 1, k - (totalNodes / 2), nextRootVal)
        # Otherwise, the target node is in the left sub-tree of the current root node.
        else:
            nextRootVal = 0 if rootVal == 0 else 1
            return self.depthFirstSearch(n - 1, k, nextRootVal)

    def kthGrammar(self, n: int, k: int) -> int:
        return self.depthFirstSearch(n, k, 0)
```

</details>

<br>

## Approach 2: Normal Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int recursion(int n, int k) {
        // First row will only have one symbol '0'.
        if (n == 1) {
            return 0;
        }

        int totalElements = pow(2, (n - 1));
        int halfElements = totalElements / 2;

        // If the target is present in the right half, we switch to the respective left half symbol.
        if (k > halfElements) {
            return 1 - kthGrammar(n, k - halfElements);
        }

        // Otherwise, we switch to the previous row.
        return recursion(n - 1, k);
    }

    int kthGrammar(int n, int k) {
        return recursion(n, k);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int recursion(int n, int k) {
        // First row will only have one symbol '0'.
        if (n == 1) {
            return 0;
        }

        int totalElements = (int) Math.pow(2, (n - 1));
        int halfElements = totalElements / 2;

        // If the target is present in the right half, we switch to the respective left half symbol.
        if (k > halfElements) {
            return 1 - recursion(n, k - halfElements);
        }

        // Otherwise, we switch to the previous row.
        return recursion(n - 1, k);
    }

    public int kthGrammar(int n, int k) {
        return recursion(n, k);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let recursion = (n, k) => {
    // First row will only have one symbol '0'.
    if (n === 1) {
        return 0;
    }

    const totalElements = Math.pow(2, n - 1);
    const halfElements = totalElements / 2;

    // If the target is present in the right half, we switch to the respective left half symbol.
    if (k > halfElements) {
        return 1 - recursion(n, k - halfElements);
    }

    // Otherwise, we switch to the previous row.
    return recursion(n - 1, k);
}

let kthGrammar = function(n, k) {
    return recursion(n, k);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def recursion(self, n: int, k: int) -> int:
        # First row will only have one symbol '0'.
        if n == 1:
            return 0

        total_elements = 2 ** (n - 1)
        half_elements = total_elements // 2

        # If the target is present in the right half, we switch to the respective left half symbol.
        if k > half_elements:
            return 1 - self.recursion(n, k - half_elements)

        # Otherwise, we switch to the previous row.
        return self.recursion(n - 1, k)

    def kthGrammar(self, n: int, k: int) -> int:
        return self.recursion(n, k)
```

</details>

<br>

## Approach 3: Recursion to Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }

        // We assume the symbol at the target position is '1'.
        int symbol = 1;

        for (int currRow = n; currRow > 1; --currRow) {
            int totalElements = pow(2, (currRow - 1));
            int halfElements = totalElements / 2;

            // If 'k' lies in the right half symbol, then we flip over to the respective left half symbol.
            if (k > halfElements) {
                // Flip the symbol.
                symbol = 1 - symbol;
                // Change the position after flipping.
                k -= halfElements;
            }
        }

        // We reached the 1st row; if the symbol is not '0', we started with the wrong symbol.
        if (symbol != 0) {
            // Thus, the start symbol was '0' not '1'.
            return 0;
        } 

        // Start symbol was indeed what we started with, a '1'.
        return 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }

        // We assume the symbol at the target position is '1'.
        int symbol = 1;

        for (int currRow = n; currRow > 1; --currRow) {
            int totalElements = (int) Math.pow(2, (currRow - 1));
            int halfElements = totalElements / 2;

            // If 'k' lies in the right half symbol, then we flip over to the respective left half symbol.
            if (k > halfElements) {
                // Flip the symbol.
                symbol = 1 - symbol;
                // Change the position after flipping.
                k -= halfElements;
            }
        }

        // We reached the 1st row; if the symbol is not '0', we started with the wrong symbol.
        if (symbol != 0) {
            // Thus, the start symbol was '0', not '1'.
            return 0;
        }

        // The start symbol was indeed what we started with, a '1'.
        return 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let kthGrammar = function(n, k) {
    if (n === 1) {
        return 0;
    }

    // We assume the symbol at the target position is '1'.
    let symbol = 1;

    for (let currRow = n; currRow > 1; --currRow) {
        const totalElements = Math.pow(2, currRow - 1);
        const halfElements = totalElements / 2;

        // If 'k' lies in the right half symbol, then we flip over to the respective left half symbol.
        if (k > halfElements) {
            // Flip the symbol.
            symbol = 1 - symbol;
            // Change the position after flipping.
            k -= halfElements;
        }
    }

    // We reached the 1st row; if the symbol is not '0', we started with the wrong symbol.
    if (symbol !== 0) {
        // Thus, the start symbol was '0', not '1'.
        return 0;
    }

    // The start symbol was indeed what we started with, a '1'.
    return 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1:
            return 0

        # We assume the symbol at the target position is '1'.
        symbol = 1

        for curr_row in range(n, 1, -1):
            total_elements = 2 ** (curr_row - 1)
            half_elements = total_elements // 2

            # If 'k' lies in the right half symbol, then we flip over to the respective left half symbol.
            if k > half_elements:
                # Flip the symbol.
                symbol = 1 - symbol
                # Change the position after flipping.
                k -= half_elements

        # We reached the 1st row; if the symbol is not '0', we started with the wrong symbol.
        if symbol != 0:
            # Thus, the start symbol was '0', not '1'.
            return 0

        # The start symbol was indeed what we started with, a '1'.
        return 1
```

</details>

<br>

## Approach 4: Math

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int kthGrammar(int n, int k) {
        int count = __builtin_popcount(k - 1);
        return count % 2 == 0 ? 0 : 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int kthGrammar(int n, int k) {
        int count = Integer.bitCount(k - 1);
        return count % 2 == 0 ? 0 : 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let kthGrammar = function(n, k) {
    const count = (k - 1).toString(2).split('1').length - 1;
    return count % 2 === 0 ? 0 : 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        count = bin(k - 1).count('1')
        return 0 if count % 2 == 0 else 1
```

</details>
