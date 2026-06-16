# 1404. Number of Steps to Reduce a Number in Binary Representation to One

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/)  
`String` `Bit Manipulation` `Simulation`

**Problem Link:** [LeetCode 1404 - Number of Steps to Reduce a Number in Binary Representation to One](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/)

## Problem

Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

- If the current number is even, you have to divide it by 2.
- If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.

### Example 1

```text
Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14.
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.
Step 5) 4 is even, divide by 2 and obtain 2.
Step 6) 2 is even, divide by 2 and obtain 1.
```

### Example 2

```text
Input: s = "10"
Output: 1
Explanation: "10" corresponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.
```

### Example 3

```text
Input: s = "1"
Output: 0
```

## Constraints

- 1 <= s.length <= 500
- s consists of characters '0' or '1'
- s[0] == '1'

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Moves to Reach Target Score](https://leetcode.com/problems/minimum-moves-to-reach-target-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1404. Number of Steps to Reduce a Number in Binary Representation to One

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C++, Java, Python3 |
| Greedy | C++, Java, Python3 |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void divideByTwo(string& s) { s.pop_back(); }

    void addOne(string& s) {
        int i = s.size() - 1;

        // Iterating while the character is 1 and changing to 0 to carry the 1.
        while (i >= 0 && s[i] != '0') {
            s[i] = '0';
            i--;
        }

        if (i < 0) {
            s = '1' + s;
        } else {
            s[i] = '1';
        }
    }

    int numSteps(string s) {
        int N = s.size();

        int operations = 0;
        while (s.size() > 1) {
            N = s.size();

            if (s[N - 1] == '0') {
                divideByTwo(s);
            } else {
                addOne(s);
            }

            operations++;
        }

        return operations;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private void divideByTwo(StringBuilder s) {
        s.deleteCharAt(s.length() - 1);
    }

    private void addOne(StringBuilder s) {
        int i = s.length() - 1;

        // Iterating while the character is 1 and changing to 0
        while (i >= 0 && s.charAt(i) != '0') {
            s.setCharAt(i, '0');
            i--;
        }

        if (i < 0) {
            s.insert(0, '1');
        } else {
            s.setCharAt(i, '1');
        }
    }

    public int numSteps(String s) {
        StringBuilder str = new StringBuilder(s);

        int operations = 0;
        while (str.length() > 1) {
            int N = str.length();

            if (str.charAt(N - 1) == '0') {
                divideByTwo(str);
            } else {
                addOne(str);
            }

            operations++;
        }

        return operations;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divide_by_two(self, s):
        s.pop()

    def add_one(self, s):
        i = len(s) - 1

        # Iterating while the character is 1 and changing to 0
        while i >= 0 and s[i] != "0":
            s[i] = "0"
            i -= 1

        if i < 0:
            s.insert(0, "1")
        else:
            s[i] = "1"

    def numSteps(self, s: str) -> int:
        s = list(s)
        operations = 0

        while len(s) > 1:
            N = len(s)

            if s[N - 1] == "0":
                self.divide_by_two(s)
            else:
                self.add_one(s)

            operations += 1

        return operations
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numSteps(string s) {
        int N = s.size();

        int operations = 0;
        int carry = 0;
        for (int i = N - 1; i > 0; i--) {
            if (((s[i] - '0') + carry) % 2) {
                operations += 2;
                carry = 1;
            } else {
                operations++;
            }
        }

        return operations + carry;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int numSteps(String s) {
        int N = s.length();

        int operations = 0;
        int carry = 0;
        for (int i = N - 1; i > 0; i--) {
            int digit = Character.getNumericValue(s.charAt(i)) + carry;

            if (digit % 2 == 1) {
                operations += 2;
                carry = 1;
            } else {
                operations++;
            }
        }

        return operations + carry;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numSteps(self, s: str) -> int:
        N = len(s)

        operations = 0
        carry = 0
        for i in range(N - 1, 0, -1):
            digit = int(s[i]) + carry
            if digit % 2 == 1:
                operations += 2
                carry = 1
            else:
                operations += 1

        return operations + carry
```

</details>
