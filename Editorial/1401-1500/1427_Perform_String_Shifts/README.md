# 1427. Perform String Shifts

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/perform-string-shifts/)  
`Array` `Math` `String`

**Problem Link:** [LeetCode 1427 - Perform String Shifts](https://leetcode.com/problems/perform-string-shifts/)

## Problem

You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [directioni, amounti]:

- directioni can be 0 (for left shift) or 1 (for right shift).
- amounti is the amount by which string s is to be shifted.
- A left shift by 1 means remove the first character of s and append it to the end.
- Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.

Return the final string after all operations.

### Example 1

```text
Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation:
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"
```

### Example 2

```text
Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
```

## Constraints

- 1 <= s.length <= 100
- s only contains lower case English letters.
- 1 <= shift.length <= 100
- shift[i].length == 2
- directioni is either 0 or 1.
- 0 <= amounti <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1427. Perform String Shifts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C++, Java, Python3 |
| Compute Net Shift | C++, Java, Python3 |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string stringShift(string string, vector<vector<int>>& shift) {
        int len = string.length();
        for (auto move : shift) {
            int direction = move[0];
            int amount = move[1] % len;
            if (direction == 0) {
                // Move necessary amount of characters from start to end
                string = string.substr(amount) + string.substr(0, amount);
            } else {
                // Move necessary amount of characters from end to start
                string = string.substr(len - amount) +
                         string.substr(0, len - amount);
            }
        }
        return string;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String stringShift(String string, int[][] shift) {
        int len = string.length();
        for (int[] move : shift) {
            int direction = move[0];
            int amount = move[1] % len;
            if (direction == 0) {
                // Move necessary amount of characters from front to end
                string = string.substring(amount) + string.substring(0, amount);
            } else {
                // Move necessary amount of characters from end to front
                string =
                    string.substring(len - amount) +
                    string.substring(0, len - amount);
            }
        }
        return string;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def stringShift(self, string: str, shift: List[List[int]]) -> str:
        for direction, amount in shift:
            amount %= len(string)
            if direction == 0:
                # Move necessary amount of characters from start to end
                string = string[amount:] + string[:amount]
            else:
                # Move necessary amount of characters from end to start
                string = string[-amount:] + string[:-amount]
        return string
```

</details>

<br>

## Approach 2: Compute Net Shift

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string stringShift(string string, vector<vector<int>>& shift) {
        // Add up the left shifts and right shifts.
        vector<int> overallShifts(2, 0);
        for (auto& move : shift) {
            overallShifts[move[0]] += move[1];
        }
        int leftShifts = overallShifts[0];
        int rightShifts = overallShifts[1];

        // Determine which shift (if any) to perform.
        int len = string.length();
        if (leftShifts > rightShifts) {
            leftShifts = (leftShifts - rightShifts) % len;
            string = string.substr(leftShifts) + string.substr(0, leftShifts);
        } else if (rightShifts > leftShifts) {
            rightShifts = (rightShifts - leftShifts) % len;
            string = string.substr(len - rightShifts) +
                     string.substr(0, len - rightShifts);
        }

        return string;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String stringShift(String string, int[][] shift) {
        // Add up the left shifts and right shifts.
        int[] overallShifts = new int[2];
        for (int[] move : shift) {
            overallShifts[move[0]] += move[1];
        }
        int leftShifts = overallShifts[0];
        int rightShifts = overallShifts[1];

        // Determine which shift (if any) to perform.
        int len = string.length();
        if (leftShifts > rightShifts) {
            leftShifts = (leftShifts - rightShifts) % len;
            string =
                string.substring(leftShifts) + string.substring(0, leftShifts);
        } else if (rightShifts > leftShifts) {
            rightShifts = (rightShifts - leftShifts) % len;
            string =
                string.substring(len - rightShifts) +
                string.substring(0, len - rightShifts);
        }

        return string;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def stringShift(self, string: str, shift: List[List[int]]) -> str:

        # Add up the left shifts and right shifts.
        overall_shifts = [0, 0]
        for direction, amount in shift:
            overall_shifts[direction] += amount
        left_shifts, right_shifts = overall_shifts

        # Determine which shift (if any) to perform.
        if left_shifts > right_shifts:
            left_shifts = (left_shifts - right_shifts) % len(string)
            string = string[left_shifts:] + string[:left_shifts]
        else:
            right_shifts = (right_shifts - left_shifts) % len(string)
            string = string[-right_shifts:] + string[:-right_shifts]

        return string
```

</details>
