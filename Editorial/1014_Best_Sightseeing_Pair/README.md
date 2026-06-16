# 1014. Best Sightseeing Pair

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/best-sightseeing-pair/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1014 - Best Sightseeing Pair](https://leetcode.com/problems/best-sightseeing-pair/)

## Problem

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

### Example 1

```text
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
```

### Example 2

```text
Input: values = [1,2]
Output: 2
```

## Constraints

- 2 <= values.length <= 5 * 104
- 1 <= values[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1014. Best Sightseeing Pair

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, Python3 |
| Space-Optimized DP | C++, Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        // Initialize an array to store the maximum left scores up to each
        // index.
        vector<int> maxLeftScore(n);
        // The left score at the first index is just the value of the first
        // element.
        maxLeftScore[0] = values[0];

        int maxScore = 0;

        for (int i = 1; i < n; i++) {
            int currentRightScore = values[i] - i;
            // Update the maximum score by combining the best left score so far
            // with the current right score.
            maxScore = max(maxScore, maxLeftScore[i - 1] + currentRightScore);

            int currentLeftScore = values[i] + i;
            // Update the maximum left score up to the current index.
            maxLeftScore[i] = max(maxLeftScore[i - 1], currentLeftScore);
        }

        return maxScore;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length;
        // Initialize an array to store the maximum left scores up to each index.
        int[] maxLeftScore = new int[n];
        // The left score at the first index is just the value of the first element.
        maxLeftScore[0] = values[0];

        int maxScore = 0;

        for (int i = 1; i < n; i++) {
            int currentRightScore = values[i] - i;
            // Update the maximum score by combining the best left score so far with the current right score.
            maxScore = Math.max(
                maxScore,
                maxLeftScore[i - 1] + currentRightScore
            );

            int currentLeftScore = values[i] + i;
            // Update the maximum left score up to the current index.
            maxLeftScore[i] = Math.max(maxLeftScore[i - 1], currentLeftScore);
        }

        return maxScore;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxScoreSightseeingPair(self, values):
        n = len(values)
        # Initialize a list to store the maximum left scores up to each index.
        max_left_score = [0] * n
        # The left score at the first index is just the value of the first element.
        max_left_score[0] = values[0]

        max_score = 0

        for i in range(1, n):
            current_right_score = values[i] - i
            # Update the maximum score by combining the best left score so far with the current right score.
            max_score = max(
                max_score, max_left_score[i - 1] + current_right_score
            )

            current_left_score = values[i] + i
            # Update the maximum left score up to the current index.
            max_left_score[i] = max(max_left_score[i - 1], current_left_score)

        return max_score
```

</details>

<br>

## Approach 2: Space-Optimized DP

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        // The left score is initially just the value of the first element.
        int maxLeftScore = values[0];

        int maxScore = 0;

        for (int i = 1; i < n; i++) {
            int currentRightScore = values[i] - i;
            // Update the maximum score by combining the best left score so far
            // with the current right score.
            maxScore = max(maxScore, maxLeftScore + currentRightScore);

            int currentLeftScore = values[i] + i;
            // Update the maximum left score up to the current index.
            maxLeftScore = max(maxLeftScore, currentLeftScore);
        }

        return maxScore;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length;

        // The left score is initially just the value of the first element.
        int maxLeftScore = values[0];

        int maxScore = 0;

        for (int i = 1; i < n; i++) {
            int currentRightScore = values[i] - i;
            // Update the maximum score by combining the best left score so far with the current right score.
            maxScore = Math.max(maxScore, maxLeftScore + currentRightScore);

            int currentLeftScore = values[i] + i;
            // Update the maximum left score up to the current index.
            maxLeftScore = Math.max(maxLeftScore, currentLeftScore);
        }

        return maxScore;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxScoreSightseeingPair(self, values):
        n = len(values)

        # The left score is initially just the value of the first element.
        max_left_score = values[0]

        max_score = 0

        for i in range(1, n):
            current_right_score = values[i] - i
            # Update the maximum score by combining the best left score so far with the current right score.
            max_score = max(max_score, max_left_score + current_right_score)

            current_left_score = values[i] + i
            # Update the maximum left score up to the current index.
            max_left_score = max(max_left_score, current_left_score)

        return max_score
```

</details>
