# 1769. Minimum Number of Operations to Move All Balls to Each Box

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)  
`Array` `String` `Prefix Sum`

**Problem Link:** [LeetCode 1769 - Minimum Number of Operations to Move All Balls to Each Box](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)

## Problem

You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

### Example 1

```text
Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
```

### Example 2

```text
Input: boxes = "001011"
Output: [11,8,5,4,3,4]
```

## Constraints

- n == boxes.length
- 1 <= n <= 2000
- boxes[i] is either '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost to Move Chips to The Same Position](https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Moves to Spread Stones Over Grid](https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1769. Minimum Number of Operations to Move All Balls to Each Box

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Sum of Left and Right Moves | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.length());
        for (int currentBox = 0; currentBox < boxes.length(); currentBox++) {
            // If the current box contains a ball, calculate the number of moves
            // for every box.
            if (boxes[currentBox] == '1') {
                for (int newPosition = 0; newPosition < boxes.length();
                     newPosition++) {
                    answer[newPosition] += abs(newPosition - currentBox);
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

    public int[] minOperations(String boxes) {
        int[] answer = new int[boxes.length()];
        for (int currentBox = 0; currentBox < boxes.length(); currentBox++) {
            // If the current box contains a ball, calculate the number of moves for every box.
            if (boxes.charAt(currentBox) == '1') {
                for (
                    int newPosition = 0;
                    newPosition < boxes.length();
                    newPosition++
                ) {
                    answer[newPosition] += Math.abs(newPosition - currentBox);
                }
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        answer = [0] * len(boxes)
        for current_box in range(len(boxes)):
            # If the current box contains a ball, calculate the number of moves for every box.
            if boxes[current_box] == "1":
                for new_position in range(len(boxes)):
                    answer[new_position] += abs(new_position - current_box)
        return answer
```

</details>

<br>

## Approach 2: Sum of Left and Right Moves

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        // Single pass: calculate moves from both left and right
        for (int i = 0; i < n; i++) {
            // Left pass
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            // Right pass
            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
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

    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] answer = new int[n];

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        // Single pass: calculate moves from both left and right
        for (int i = 0; i < n; i++) {
            // Left pass
            answer[i] += movesToLeft;
            ballsToLeft += Character.getNumericValue(boxes.charAt(i));
            movesToLeft += ballsToLeft;

            // Right pass
            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += Character.getNumericValue(boxes.charAt(j));
            movesToRight += ballsToRight;
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        answer = [0] * n

        balls_to_left = 0
        moves_to_left = 0
        balls_to_right = 0
        moves_to_right = 0

        # Single pass: calculate moves from both left and right
        for i in range(n):
            # Left pass
            answer[i] += moves_to_left
            balls_to_left += int(boxes[i])
            moves_to_left += balls_to_left

            # Right pass
            j = n - 1 - i
            answer[j] += moves_to_right
            balls_to_right += int(boxes[j])
            moves_to_right += balls_to_right

        return answer
```

</details>
