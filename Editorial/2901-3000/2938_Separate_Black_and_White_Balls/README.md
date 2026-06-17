# 2938. Separate Black and White Balls

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/separate-black-and-white-balls/)  
`Two Pointers` `String` `Greedy`

**Problem Link:** [LeetCode 2938 - Separate Black and White Balls](https://leetcode.com/problems/separate-black-and-white-balls/)

## Problem

There are n balls on a table, each ball has a color black or white.

You are given a 0-indexed binary string s of length n, where 1 and 0 represent black and white balls, respectively.

In each step, you can choose two adjacent balls and swap them.

Return the minimum number of steps to group all the black balls to the right and all the white balls to the left.

### Example 1

```text
Input: s = "101"
Output: 1
Explanation: We can group all the black balls to the right in the following way:
- Swap s[0] and s[1], s = "011".
Initially, 1s are not grouped together, requiring at least 1 step to group them to the right.
```

### Example 2

```text
Input: s = "100"
Output: 2
Explanation: We can group all the black balls to the right in the following way:
- Swap s[0] and s[1], s = "010".
- Swap s[1] and s[2], s = "001".
It can be proven that the minimum number of steps needed is 2.
```

### Example 3

```text
Input: s = "0111"
Output: 0
Explanation: All the black balls are already grouped to the right.
```

## Constraints

- 1 <= n == s.length <= 105
- s[i] is either '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2938. Separate Black and White Balls

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointer | C++, Java, Python3 |
| Counter | C++, Java, Python3 |

## Approach 1: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minimumSteps(string s) {
        int whitePosition = 0;
        long long totalSwaps = 0;

        // Iterate through each ball (character) in the string
        for (int currentPos = 0; currentPos < s.length(); currentPos++) {
            if (s[currentPos] == '0') {
                // Calculate the number of swaps needed
                // to move it to the leftmost available position
                totalSwaps += currentPos - whitePosition;

                // Move the next available position for a white ball one step to
                // the right
                whitePosition++;
            }
        }

        return totalSwaps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minimumSteps(String s) {
        int whitePosition = 0;
        long totalSwaps = 0;

        // Iterate through each ball (character) in the string
        for (int currentPos = 0; currentPos < s.length(); currentPos++) {
            if (s.charAt(currentPos) == '0') {
                // Calculate the number of swaps needed
                // to move it to leftmost available position
                totalSwaps += currentPos - whitePosition;

                // Move the next available position for a white ball one step to the right
                whitePosition++;
            }
        }

        return totalSwaps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumSteps(self, s: str) -> int:
        white_position = 0
        total_swaps = 0

        # Iterate through each ball in the string
        for current_pos, char in enumerate(s):
            if char == "0":
                # Calculate the number of swaps needed
                total_swaps += current_pos - white_position

                # Move the next available position for a white ball one step to the right
                white_position += 1

        return total_swaps
```

</details>

<br>

## Approach 2: Counter

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minimumSteps(string s) {
        long long totalSwaps = 0;
        int blackBallCount = 0;

        // Iterate through each ball (character) in the string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                // Swap with all black balls to its left
                totalSwaps += (long long)blackBallCount;
            } else {
                // Increment the count
                blackBallCount++;
            }
        }

        return totalSwaps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minimumSteps(String s) {
        long totalSwaps = 0;
        int blackBallCount = 0;

        // Iterate through each ball (character) in the string
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                // Swap with all black balls to its left
                totalSwaps += (long) blackBallCount;
            } else {
                // Increment the count
                blackBallCount++;
            }
        }

        return totalSwaps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumSteps(self, s: str) -> int:
        total_swaps = 0
        black_ball_count = 0

        # Iterate through each ball in the string
        for char in s:
            if char == "0":
                total_swaps += black_ball_count
            else:
                black_ball_count += 1

        return total_swaps
```

</details>
