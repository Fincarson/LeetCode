# 1690. Stone Game VII

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/stone-game-vii/)  
`Array` `Math` `Dynamic Programming` `Game Theory`

**Problem Link:** [LeetCode 1690 - Stone Game VII](https://leetcode.com/problems/stone-game-vii/)

## Problem

Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.

### Example 1

```text
Input: stones = [5,3,1,4,2]
Output: 6
Explanation:
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.
```

### Example 2

```text
Input: stones = [7,90,5,1,100,10,10,2]
Output: 122
```

## Constraints

- n == stones.length
- 2 <= n <= 1000
- 1 <= stones[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Stone Game](https://leetcode.com/problems/stone-game/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Stone Game II](https://leetcode.com/problems/stone-game-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Stone Game III](https://leetcode.com/problems/stone-game-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Stone Game IV](https://leetcode.com/problems/stone-game-iv/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Stone Game V](https://leetcode.com/problems/stone-game-v/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Stone Game VI](https://leetcode.com/problems/stone-game-vi/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Score from Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Stone Game VIII](https://leetcode.com/problems/stone-game-viii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Stone Game IX](https://leetcode.com/problems/stone-game-ix/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1690. Stone Game VII

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force Using Recursion | C++, Java |

## Approach 1: Brute Force Using Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }
        return abs(findDifference(prefixSum, 0, n - 1, true));
    }

    int findDifference(vector<int>& prefixSum, int start, int end, bool alice) {
        if (start == end) {
            return 0;
        }
        int difference;
        int scoreRemoveFirst = prefixSum[end + 1] - prefixSum[start + 1];
        int scoreRemoveLast = prefixSum[end] - prefixSum[start];

        if (alice) {
            difference = max(findDifference(prefixSum, start + 1, end, !alice) +
                                 scoreRemoveFirst,
                             findDifference(prefixSum, start, end - 1, !alice) +
                                 scoreRemoveLast);
        } else {
            difference = min(findDifference(prefixSum, start + 1, end, !alice) -
                                 scoreRemoveFirst,
                             findDifference(prefixSum, start, end - 1, !alice) -
                                 scoreRemoveLast);
        }
        return difference;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[] prefixSum;

    private int findDifference(int start, int end, boolean alice) {
        if (start == end) {
            return 0;
        }
        int difference;
        int scoreRemoveFirst = prefixSum[end + 1] - prefixSum[start + 1];
        int scoreRemoveLast = prefixSum[end] - prefixSum[start];

        if (alice) {
            difference = Math.max(
                    findDifference(start + 1, end, !alice) + scoreRemoveFirst,
                    findDifference(start, end - 1, !alice) + scoreRemoveLast);
        } else {
            difference = Math.min(
                    findDifference(start + 1, end, !alice) - scoreRemoveFirst,
                    findDifference(start, end - 1, !alice) - scoreRemoveLast);
        }
        return difference;
    }

    public int stoneGameVII(int[] stones) {
        int n = stones.length;
        prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }
        return Math.abs(findDifference(0, n - 1, true));
    }
}
```

</details>
