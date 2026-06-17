# 2011. Final Value of Variable After Performing Operations

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/)  
`Array` `String` `Simulation`

**Problem Link:** [LeetCode 2011 - Final Value of Variable After Performing Operations](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/)

## Problem

There is a programming language with only four operations and one variable X:

- ++X and X++ increments the value of the variable X by 1.
- --X and X-- decrements the value of the variable X by 1.

Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

### Example 1

```text
Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
```

### Example 2

```text
Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
```

### Example 3

```text
Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
```

## Constraints

- 1 <= operations.length <= 100
- operations[i] will be either "++X", "X++", "--X", or "X--".

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2011. Final Value of Variable After Performing Operations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int finalValueAfterOperations(char** operations, int operationsSize) {
    int x = 0;
    for (int i = 0; i < operationsSize; i++) {
        char* op = operations[i];
        if (!strcmp(op, "X++") || !strcmp(op, "++X")) {
            x++;
        } else {
            x--;
        }
    }
    return x;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& op : operations) {
            if (op == "X++" || op == "++X") {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FinalValueAfterOperations(string[] operations) {
        int x = 0;
        foreach (string op in operations) {
            if (op == "X++" || op == "++X") {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func finalValueAfterOperations(operations []string) (x int) {
	for _, op := range operations {
		if op[1] == '+' {
			x++
		} else {
			x--
		}
	}
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int finalValueAfterOperations(String[] operations) {
        int x = 0;
        for (String op : operations) {
            if ("X++".equals(op) || "++X".equals(op)) {
                x++;
            } else {
                x--;
            }
        }
        return x;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var finalValueAfterOperations = function (operations) {
    let x = 0;
    for (const op of operations) {
        if ("X++" === op || "++X" === op) {
            x++;
        } else {
            x--;
        }
    }
    return x;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        return sum(1 if op[1] == "+" else -1 for op in operations)
```

</details>
