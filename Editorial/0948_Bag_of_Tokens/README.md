# 948. Bag of Tokens

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/bag-of-tokens/)  
`Array` `Two Pointers` `Greedy` `Sorting`

**Problem Link:** [LeetCode 948 - Bag of Tokens](https://leetcode.com/problems/bag-of-tokens/)

## Problem

You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] denotes the value of tokeni.

Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

- Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
- Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.

Return the maximum possible score you can achieve after playing any number of tokens.

### Example 1

### Example 2

### Example 3

## Constraints

- 0 <= tokens.length <= 1000
- 0 <= tokens[i], power < 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 948. Bag of Tokens

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sort and Greedy | C++, Java, Python3 |

## Approach: Sort and Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int low = 0;
        int high = tokens.size() - 1;
        int score = 0;
        sort(tokens.begin(), tokens.end());

        while (low <= high) {
            // When we have enough power, play lowest token face-up
            if (power >= tokens[low]) {
                score += 1;
                power -= tokens[low];
                low += 1;
            // We don't have enough power to play a token face-up
            // If there is at least one token remaining,
            // and we have enough score, play highest token face-down
            } else if (low < high && score > 0) {
                score -= 1;
                power += tokens[high];
                high -= 1;
            // We don't have enough score, power, or tokens 
            // to play face-up or down and increase our score
            } else {
                return score;
            }
        }
        return score;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        int low = 0;
        int high = tokens.length - 1;
        int score = 0;
        Arrays.sort(tokens);

        while (low <= high) {
            // When we have enough power, play lowest token face-up
            if (power >= tokens[low]) {
                score += 1;
                power -= tokens[low];
                low += 1;
            // We don't have enough power to play a token face-up
            // If there is at least one token remaining,
            // and we have enough score, play highest token face-down
            } else if (low < high && score > 0) {
                score -= 1;
                power += tokens[high];
                high -= 1;
            // We don't have enough score, power, or tokens 
            // to play face-up or down and increase our score
            } else {
                return score;
            }
        }
        return score;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        low = 0
        high = len(tokens) - 1
        score = 0
        tokens.sort()

        while low <= high:
            # When we have enough power, play lowest token face-up
            if power >= tokens[low]:
                score += 1
                power -= tokens[low]
                low += 1

            # We don't have enough power to play a token face-up
            # If there is at least one token remaining,
            # and we have enough score, play highest token face-down
            elif low < high and score > 0:
                score -= 1
                power += tokens[high]
                high -= 1

            # We don't have enough score, power, or tokens 
            # to play face-up or down and increase our score
            else:
                return score

        return score
```

</details>
