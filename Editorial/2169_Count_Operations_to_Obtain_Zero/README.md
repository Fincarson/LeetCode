# 2169. Count Operations to Obtain Zero

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/count-operations-to-obtain-zero/)  
`Math` `Simulation`

**Problem Link:** [LeetCode 2169 - Count Operations to Obtain Zero](https://leetcode.com/problems/count-operations-to-obtain-zero/)

## Problem

You are given two non-negative integers num1 and num2.

In one operation, if num1 >= num2, you must subtract num2 from num1, otherwise subtract num1 from num2.

- For example, if num1 = 5 and num2 = 4, subtract num2 from num1, thus obtaining num1 = 1 and num2 = 4. However, if num1 = 4 and num2 = 5, after one operation, num1 = 4 and num2 = 1.

Return the number of operations required to make either num1 = 0 or num2 = 0.

### Example 1

```text
Input: num1 = 2, num2 = 3
Output: 3
Explanation:
- Operation 1: num1 = 2, num2 = 3. Since num1 < num2, we subtract num1 from num2 and get num1 = 2, num2 = 3 - 2 = 1.
- Operation 2: num1 = 2, num2 = 1. Since num1 > num2, we subtract num2 from num1.
- Operation 3: num1 = 1, num2 = 1. Since num1 == num2, we subtract num2 from num1.
Now num1 = 0 and num2 = 1. Since num1 == 0, we do not need to perform any further operations.
So the total number of operations required is 3.
```

### Example 2

```text
Input: num1 = 10, num2 = 10
Output: 1
Explanation:
- Operation 1: num1 = 10, num2 = 10. Since num1 == num2, we subtract num2 from num1 and get num1 = 10 - 10 = 0.
Now num1 = 0 and num2 = 10. Since num1 == 0, we are done.
So the total number of operations required is 1.
```

## Constraints

- 0 <= num1, num2 <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2169. Count Operations to Obtain Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Euclidean Algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Euclidean Algorithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countOperations(int num1, int num2) {
    int res = 0;  // total number of subtraction operations
    while (num1 && num2) {
        // each step of the Euclidean algorithm
        res += num1 / num2;
        num1 %= num2;
        // swap two numbers
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;  // total number of subtraction operations
        while (num1 && num2) {
            // each step of the Euclidean algorithm
            res += num1 / num2;
            num1 %= num2;
            swap(num1, num2);
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CountOperations(int num1, int num2) {
        int res = 0;  // total number of subtraction operations
        while (num1 != 0 && num2 != 0) {
            // each step of the Euclidean algorithm
            res += num1 / num2;
            num1 %= num2;
            // swap two numbers
            (num1, num2) = (num2, num1);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countOperations(num1 int, num2 int) int {
	res := 0 // total number of subtraction operations
	for num1 != 0 && num2 != 0 {
		// each step of the Euclidean algorithm
		res += num1 / num2
		num1 %= num2
		// swap two numbers
		num1, num2 = num2, num1
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countOperations(int num1, int num2) {
        int res = 0; // total number of subtraction operations
        while (num1 != 0 && num2 != 0) {
            // each step of the Euclidean algorithm
            res += num1 / num2;
            num1 %= num2;
            // swap two numbers
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countOperations = function (num1, num2) {
    let res = 0; // total number of subtraction operations
    while (num1 && num2) {
        // each step of the Euclidean algorithm
        res += Math.floor(num1 / num2);
        num1 %= num2;
        // swap two numbers
        [num1, num2] = [num2, num1];
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        res = 0  # total number of subtraction operations
        while num1 and num2:
            # each step of the Euclidean algorithm
            res += num1 // num2
            num1 %= num2
            num1, num2 = num2, num1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countOperations(num1: number, num2: number): number {
    let res = 0; // total number of subtraction operations
    while (num1 && num2) {
        // each step of the Euclidean algorithm
        res += Math.floor(num1 / num2);
        num1 %= num2;
        // swap two numbers
        [num1, num2] = [num2, num1];
    }
    return res;
}
```

</details>
