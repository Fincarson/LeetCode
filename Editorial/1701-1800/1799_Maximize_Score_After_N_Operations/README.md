# 1799. Maximize Score After N Operations

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximize-score-after-n-operations/)  
`Array` `Math` `Dynamic Programming` `Backtracking` `Bit Manipulation` `Number Theory` `Bitmask`

**Problem Link:** [LeetCode 1799 - Maximize Score After N Operations](https://leetcode.com/problems/maximize-score-after-n-operations/)

## Problem

You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

- Choose two elements, x and y.
- Receive a score of i * gcd(x, y).
- Remove x and y from nums.

Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.

### Example 1

```text
Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1
```

### Example 2

```text
Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
```

### Example 3

```text
Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
```

## Constraints

- 1 <= n <= 7
- nums.length == 2 * n
- 1 <= nums[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1799. Maximize Score After N Operations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DP with Bitmasking (Recursive) | C++, Java, JavaScript, Python3 |
| DP with Bitmasking (Iterative) | C++, Java, JavaScript, Python3 |

## Approach 1: DP with Bitmasking (Recursive)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int backtrack(vector<int>& nums, int mask, int pairsPicked, vector<int>& memo) {
        // If we have picked all the numbers from 'nums' array, we can't get more score.
        if (2 * pairsPicked == nums.size()) {
            return 0;
        }

        // If we already solved this sub-problem then return the stored result.
        if (memo[mask] != -1) {
            return memo[mask];
        }

        int maxScore = 0;

        // Iterate on 'nums' array to pick the first and second number of the pair.
        for (int firstIndex = 0; firstIndex < nums.size(); ++firstIndex) {
            for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); ++secondIndex) {
    
                // If the numbers are same, or already picked, then we move to next number.
                if (((mask >> firstIndex) & 1) == 1 or ((mask >> secondIndex) & 1) == 1) {
                    continue;
                }

                // Both numbers are marked as picked in this new mask.
                int newMask = mask | (1 << firstIndex) | ((1 << secondIndex));

                // Calculate score of current pair of numbers, and the remaining array.
                int currScore = (pairsPicked + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                int remainingScore = backtrack(nums, newMask, pairsPicked + 1, memo);

                // Store the maximum score.
                maxScore = max(maxScore, currScore + remainingScore);
                // We will use old mask in loop's next interation, 
                // means we discarded the picked number and backtracked.
            }
        }

        // Store the result of the current sub-problem.
        memo[mask] = maxScore;
        return maxScore;
    }

    int maxScore(vector<int>& nums) {
        int memoSize = 1 << nums.size(); // 2^(nums array size)
        vector<int> memo(memoSize, -1);
        return backtrack(nums, 0, 0, memo);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int backtrack(int[] nums, int mask, int pairsPicked, int[] memo) {
        // If we have picked all the numbers from 'nums' array, we can't get more score.
        if (2 * pairsPicked == nums.length) {
            return 0;
        }

        // If we already solved this sub-problem then return the stored result.
        if (memo[mask] != -1) {
            return memo[mask];
        }

        int maxScore = 0;

        // Iterate on 'nums' array to pick the first and second number of the pair.
        for (int firstIndex = 0; firstIndex < nums.length; ++firstIndex) {
            for (int secondIndex = firstIndex + 1; secondIndex < nums.length; ++secondIndex) {
    
                // If the numbers are same, or already picked, then we move to next number.
                if (((mask >> firstIndex) & 1) == 1 || ((mask >> secondIndex) & 1) == 1) {
                    continue;
                }

                // Both numbers are marked as picked in this new mask.
                int newMask = mask | (1 << firstIndex) | (1 << secondIndex);

                // Calculate score of current pair of numbers, and the remaining array.
                int currScore = (pairsPicked + 1) * gcd(nums[firstIndex], nums[secondIndex]);
                int remainingScore = backtrack(nums, newMask, pairsPicked + 1, memo);

                // Store the maximum score.
                maxScore = Math.max(maxScore, currScore + remainingScore);
                // We will use old mask in loop's next interation, 
                // means we discarded the picked number and backtracked.
            }
        }

        // Store the result of the current sub-problem.
        memo[mask] = maxScore;
        return maxScore;
    }

    public int maxScore(int[] nums) {
        int memoSize = 1 << nums.length; // 2^(nums array size)
        int[] memo = new int[memoSize];
        Arrays.fill(memo, -1);
        return backtrack(nums, 0, 0, memo);
    }

    // Utility function to calculate the gcd of two numbers.
    public int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let backtrack = (nums, mask, pairsPicked, memo) => {
    // If we have picked all the numbers from 'nums' array, we can't get more score.
    if (2 * pairsPicked == nums.length) {
        return 0;
    }

    // If we already solved this sub-problem then return the stored result.
    if (memo[mask] != -1) {
        return memo[mask];
    }

    let maxScore = 0;

    // Iterate on 'nums' array to pick the first and second number of the pair.
    for (let firstIndex = 0; firstIndex < nums.length; ++firstIndex) {
        for (let secondIndex = firstIndex + 1; secondIndex < nums.length; ++secondIndex) {

            // If the numbers are same, or already picked, then we move to next number.
            if (((mask >> firstIndex) & 1) === 1 || ((mask >> secondIndex) & 1) === 1) {
                continue;
            }

            // Both numbers are marked as picked in this new mask.
            const newMask = mask | (1 << firstIndex) | (1 << secondIndex);

            // Calculate score of current pair of numbers, and the remaining array.
            const currScore = (pairsPicked + 1) * gcd(nums[firstIndex], nums[secondIndex]);
            const remainingScore = backtrack(nums, newMask, pairsPicked + 1, memo);

            // Store the maximum score.
            maxScore = Math.max(maxScore, currScore + remainingScore);
            // We will use old mask in loop's next interation, 
            // means we discarded the picked number and backtracked.
        }
    }

    // Store the result of the current sub-problem.
    memo[mask] = maxScore;
    return maxScore;
}

let maxScore = function(nums) {
    const memoSize = 1 << nums.length; // 2^(nums array size)
    const memo = new Array(memoSize).fill(-1);
    return backtrack(nums, 0, 0, memo);
};

// Utility function to calculate the gcd of two numbers.
let gcd = (a, b) => {
  return b === 0 ? a : gcd(b, a % b);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def backtrack(self, nums: List[int], mask: int, pairsPicked: int, memo: List[int]) -> int:
        # If we have picked all the numbers from 'nums' array, we can't get more score.
        if 2 * pairsPicked == len(nums):
            return 0

        # If we already solved this sub-problem then return the stored result.
        if memo[mask] != -1:
            return memo[mask]

        maxScore = 0

        # Iterate on 'nums' array to pick the first and second number of the pair.
        for firstIndex in range(len(nums)):
            for secondIndex in range(firstIndex + 1, len(nums)):

                # If the numbers are same, or already picked, then we move to next number.
                if (mask >> firstIndex) & 1 == 1 or (mask >> secondIndex) & 1 == 1:
                    continue

                # Both numbers are marked as picked in this new mask.
                newMask = mask | (1 << firstIndex) | (1 << secondIndex)

                # Calculate score of current pair of numbers, and the remaining array.
                currScore = (pairsPicked + 1) * math.gcd(nums[firstIndex], nums[secondIndex])
                remainingScore = self.backtrack(nums, newMask, pairsPicked + 1, memo)

                # Store the maximum score.
                maxScore = max(maxScore, currScore + remainingScore)
                # We will use old mask in loop's next interation,
                # means we discarded the picked number and backtracked.

        # Store the result of the current sub-problem.
        memo[mask] = maxScore
        return maxScore
    
    def maxScore(self, nums: List[int]) -> int:
        memoSize = 1 << len(nums)  # 2^(nums array size)
        memo = [-1] * memoSize
        return self.backtrack(nums, 0, 0, memo)
```

</details>

<br>

## Approach 2: DP with Bitmasking (Iterative)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int maxStates = 1 << nums.size(); // 2^(nums array size)
        int finalMask = maxStates - 1;

        // 'dp[i]' stores max score we can get after picking remaining numbers represented by 'i'.
        vector<int> dp(maxStates);

        // Iterate on all possible states one-by-one.
        for (int state = finalMask; state >= 0; state -= 1) {
            // If we have picked all numbers, we know we can't get more score as no number is remaining.
            if (state == finalMask) {
                dp[state] = 0;
                continue;
            }

            int numbersTaken = __builtin_popcount(state);
            int pairsFormed = numbersTaken / 2;
            // States representing even numbers are taken are only valid.
            if (numbersTaken % 2) {
                continue;
            }

            // We have picked 'pairsFormed' pairs, we try all combinations of one more pair now.
            // We itearte on two numbers using two nested for loops.
            for (int firstIndex = 0; firstIndex < nums.size(); firstIndex += 1) {
                for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); secondIndex += 1) {
                    // We only choose those numbers which were not already picked.
                    if (((state >> firstIndex) & 1) == 1 || ((state >> secondIndex) & 1) == 1) {
                        continue;
                    }
                    int currentScore = (pairsFormed + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                    int stateAfterPickingCurrPair = state | (1 << firstIndex) | (1 << secondIndex);
                    int remainingScore = dp[stateAfterPickingCurrPair];
                    dp[state] = max(dp[state], currentScore + remainingScore);
                }
            }
        }

        // Returning score we get from 'n' remaining numbers of array.
        return dp[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxScore(int[] nums) {
        int maxStates = 1 << nums.length; // 2^(nums array size)
        int finalMask = maxStates - 1;

        // 'dp[i]' stores max score we can get after picking remaining numbers represented by 'i'.
        int[] dp = new int[maxStates];

        // Iterate on all possible states one-by-one.
        for (int state = finalMask; state >= 0; state--) {
            // If we have picked all numbers, we know we can't get more score as no number is remaining.
            if (state == finalMask) {
                dp[state] = 0;
                continue;
            }

            int numbersTaken = Integer.bitCount(state);
            int pairsFormed = numbersTaken / 2;
            // States representing even numbers are taken are only valid.
            if (numbersTaken % 2 != 0) {
                continue;
            }

            // We have picked 'pairsFormed' pairs, we try all combinations of one more pair now.
            // We iterate on two numbers using two nested for loops.
            for (int firstIndex = 0; firstIndex < nums.length; firstIndex++) {
                for (int secondIndex = firstIndex + 1; secondIndex < nums.length; secondIndex++) {
                    // We only choose those numbers which were not already picked.
                    if (((state >> firstIndex) & 1) == 1 || ((state >> secondIndex) & 1) == 1) {
                        continue;
                    }
                    int currentScore = (pairsFormed + 1) * gcd(nums[firstIndex], nums[secondIndex]);
                    int stateAfterPickingCurrPair = state | (1 << firstIndex) | (1 << secondIndex);
                    int remainingScore = dp[stateAfterPickingCurrPair];
                    dp[state] = Math.max(dp[state], currentScore + remainingScore);
                }
            }
        }

        // Returning score we get from 'n' remaining numbers of array.
        return dp[0];
    }

    // Helper method to calculate GCD using Euclidean algorithm.
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxScore = function(nums) {
    const maxStates = 1 << nums.length; // 2^(nums array size)
    const finalMask = maxStates - 1;

    // 'dp[i]' stores max score we can get after picking remaining numbers represented by 'i'.
    const dp = new Array(maxStates).fill(0);

    // Iterate on all possible states one-by-one.
    for (let state = finalMask; state >= 0; state -= 1) {
        // If we have picked all numbers, we know we can't get more score as no number is remaining.
        if (state == finalMask) {
            dp[state] = 0;
            continue;
        }

        const numbersTaken = state.toString(2).split('1').length - 1;
        const pairsFormed = numbersTaken / 2;
        // States representing even numbers are taken are only valid.
        if (numbersTaken % 2) {
            continue;
        }

        // We have picked 'pairsFormed' pairs, we try all combinations of one more pair now.
        // We itearte on two numbers using two nested for loops.
        for (let firstIndex = 0; firstIndex < nums.length; firstIndex += 1) {
            for (let secondIndex = firstIndex + 1; secondIndex < nums.length; secondIndex += 1) {
                // We only choose those numbers which were not already picked.
                if (((state >> firstIndex) & 1) == 1 || ((state >> secondIndex) & 1) == 1) {
                    continue;
                }
                const currentScore = (pairsFormed + 1) * gcd(nums[firstIndex], nums[secondIndex]);
                const stateAfterPickingCurrPair = state | (1 << firstIndex) | (1 << secondIndex);
                const remainingScore = dp[stateAfterPickingCurrPair];
                dp[state] = Math.max(dp[state], currentScore + remainingScore);
            }
        }
    }

    // Returning score we get from 'n' remaining numbers of array.
    return dp[0];
}

// Helper function to find the gcd of two numbers.
function gcd(a, b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        maxStates = 1 << len(nums) # 2^(nums array size)
        finalMask = maxStates - 1

        # 'dp[i]' stores max score we can get after picking remaining numbers represented by 'i'.
        dp = [0] * maxStates

        # Iterate on all possible states one-by-one.
        for state in range(finalMask, -1, -1):
            # If we have picked all numbers, we know we can't get more score as no number is remaining.
            if state == finalMask:
                dp[state] = 0
                continue

            numbersTaken = bin(state).count('1')
            pairsFormed = numbersTaken // 2
            # States representing even numbers are taken are only valid.
            if numbersTaken % 2:
                continue

            # We have picked 'pairsFormed' pairs, we try all combinations of one more pair now.
            # We iterate on two numbers using two nested for loops.
            for firstIndex in range(len(nums)):
                for secondIndex in range(firstIndex + 1, len(nums)):
                    # We only choose those numbers which were not already picked.
                    if (state >> firstIndex & 1) == 1 or (state >> secondIndex & 1) == 1:
                        continue
                    currentScore = (pairsFormed + 1) * math.gcd(nums[firstIndex], nums[secondIndex])
                    stateAfterPickingCurrPair = state | (1 << firstIndex) | (1 << secondIndex)
                    remainingScore = dp[stateAfterPickingCurrPair]
                    dp[state] = max(dp[state], currentScore + remainingScore)

        # Returning score we get from 'n' remaining numbers of array.
        return dp[0]
```

</details>
