# 1317. Convert Integer to the Sum of Two No-Zero Integers

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/)  
`Math`

**Problem Link:** [LeetCode 1317 - Convert Integer to the Sum of Two No-Zero Integers](https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/)

## Problem

No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

- a and b are No-Zero integers.
- a + b = n

The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

### Example 1

```text
Input: n = 2
Output: [1,1]
Explanation: Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.
```

### Example 2

```text
Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.
```

## Constraints

- 2 <= n <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1317. Convert Integer to the Sum of Two No-Zero Integers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* getNoZeroIntegers(int n, int* returnSize) {
    char aStr[8], bStr[8];
    for (int A = 1; A < n; ++A) {
        int B = n - A;
        sprintf(aStr, "%d", A);
        sprintf(bStr, "%d", B);
        if (strchr(aStr, '0') == NULL && strchr(bStr, '0') == NULL) {
            int* result = malloc(2 * sizeof(int));
            *returnSize = 2;
            result[0] = A;
            result[1] = B;
            return result;
        }
    }
    *returnSize = 0;
    return NULL;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int A = 1; A < n; ++A) {
            int B = n - A;
            if ((to_string(A) + to_string(B)).find('0') == string::npos) {
                return {A, B};
            }
        }
        return {};
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] GetNoZeroIntegers(int n) {
        for (int A = 1; A < n; ++A) {
            int B = n - A;
            if (!A.ToString().Contains("0") && !B.ToString().Contains("0")) {
                return new int[] { A, B };
            }
        }
        return new int[0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getNoZeroIntegers(n int) []int {
    for A := 1; A < n; A++ {
        B := n - A
        if !strings.Contains(strconv.Itoa(A), "0") && !strings.Contains(strconv.Itoa(B), "0") {
            return []int{A, B}
        }
    }
    return []int{}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] getNoZeroIntegers(int n) {
        for (int A = 1; A < n; ++A) {
            int B = n - A;
            if (
                !String.valueOf(A).contains("0") &&
                !String.valueOf(B).contains("0")
            ) {
                return new int[] { A, B };
            }
        }
        return new int[0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getNoZeroIntegers = function (n) {
    for (let A = 1; A < n; A++) {
        const B = n - A;
        if (!A.toString().includes("0") && !B.toString().includes("0")) {
            return [A, B];
        }
    }
    return [];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for A in range(1, n):
            B = n - A
            if "0" not in str(A) + str(B):
                return [A, B]
        return []
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getNoZeroIntegers(n: number): number[] {
    for (let A = 1; A < n; A++) {
        const B = n - A;
        if (!A.toString().includes("0") && !B.toString().includes("0")) {
            return [A, B];
        }
    }
    return [];
}
```

</details>
