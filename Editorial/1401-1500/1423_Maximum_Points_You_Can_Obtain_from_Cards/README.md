# 1423. Maximum Points You Can Obtain from Cards

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)  
`Array` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 1423 - Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)

## Problem

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

### Example 1

```text
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
```

### Example 2

```text
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
```

### Example 3

```text
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
```

## Constraints

- 1 <= cardPoints.length <= 105
- 1 <= cardPoints[i] <= 104
- 1 <= k <= cardPoints.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Score from Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Removing Minimum and Maximum From Array](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Recolors to Get K Consecutive Black Blocks](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Maximum Spending After Buying Items](https://leetcode.com/problems/maximum-spending-after-buying-items/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1423. Maximum Points You Can Obtain from Cards

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java |
| Dynamic Programming - Space Optimized | C++, Java |
| Sliding Window | C++, Java |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size();

        int frontSetOfCards[k + 1];
        int rearSetOfCards[k + 1];

        //Intialize 0th index in both the arrays
        frontSetOfCards[0] = rearSetOfCards[0] = 0;

        for (int i = 0; i < k; i++) {
            frontSetOfCards[i + 1] = cardPoints[i] + frontSetOfCards[i];
            rearSetOfCards[i + 1] = cardPoints[n - i - 1] + rearSetOfCards[i];
        }

        int maxScore = 0;
        // Each i represents the number of cards we take from the front.
        for (int i = 0; i <= k; i++) {
            int currentScore = frontSetOfCards[i] + rearSetOfCards[k - i];
            maxScore = max(maxScore, currentScore);
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
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;

        int[] frontSetOfCards = new int[k + 1];
        int[] rearSetOfCards = new int[k + 1];

        for (int i = 0; i < k; i++) {
            frontSetOfCards[i + 1] = cardPoints[i] + frontSetOfCards[i];
            rearSetOfCards[i + 1] = cardPoints[n - i - 1] + rearSetOfCards[i];
        }

        int maxScore = 0;
        // Each i represents the number of cards we take from the front.
        for (int i = 0; i <= k; i++) {
            int currentScore = frontSetOfCards[i] + rearSetOfCards[k - i];
            maxScore = Math.max(maxScore, currentScore);
        }
        
        return maxScore;
    }
}
```

</details>

<br>

## Approach 2: Dynamic Programming - Space Optimized

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int frontScore = 0;
        int rearScore = 0;
        int n = cardPoints.size();

        for (int i = 0; i < k; i++) {
            frontScore += cardPoints[i];
        }

        // take all k cards from the beginning
        int maxScore = frontScore;

        // take i from the beginning and k - i from the end
        for (int i = k - 1; i >= 0; i--) {
            rearScore += cardPoints[n - (k - i)];
            frontScore -= cardPoints[i];
            int currentScore = rearScore + frontScore;
            maxScore = max(maxScore, currentScore);
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
    public int maxScore(int[] cardPoints, int k) {
        int frontScore = 0;
        int rearScore = 0;
        int n = cardPoints.length;

        for (int i = 0; i < k; i++) {
            frontScore += cardPoints[i];
        }

        // take all k cards from the beginning
        int maxScore = frontScore;

        // take i from the beginning and k - i from the end
        for (int i = k - 1; i >= 0; i--) {
            rearScore += cardPoints[n - (k - i)];
            frontScore -= cardPoints[i];
            int currentScore = rearScore + frontScore;
            maxScore = Math.max(maxScore, currentScore);
        }

        return maxScore;
    }
}
```

</details>

<br>

## Approach 3: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int startingIndex = 0;
        int presentSubarrayScore = 0;
        int n = cardPoints.size();
        int requiredSubarrayLength = n - k;
        int minSubarrayScore;
        int totalScore = 0;

        // Total score obtained on selecting all the cards.
        for (int i : cardPoints) {
            totalScore += i;
        }
        
        minSubarrayScore = totalScore;

        if (k == n) {
            return totalScore;
        }

        for (int i = 0; i < n; i++) {
            presentSubarrayScore += cardPoints[i];
            int presentSubarrayLength = i - startingIndex + 1;
            // If a valid subarray (having size cardsPoints.size() - k) is possible.
            if (presentSubarrayLength == requiredSubarrayLength) {
                minSubarrayScore = min(minSubarrayScore, presentSubarrayScore);
                presentSubarrayScore -= cardPoints[startingIndex++];
            }
        }
        return totalScore - minSubarrayScore;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int startingIndex = 0;
        int presentSubarrayScore = 0;
        int n = cardPoints.length;
        int requiredSubarrayLength = n - k;
        int minSubarrayScore;
        int totalScore = 0;

        // Total score obtained on selecting all the cards.
        for (int i : cardPoints) {
            totalScore += i;
        }

        minSubarrayScore = totalScore;

        if (k == n) {
             return totalScore;
        }

        for (int i = 0; i < n; i++) {
            presentSubarrayScore += cardPoints[i];
            int presentSubarrayLength = i - startingIndex + 1;
            // If a valid subarray (having size cardsPoints.length - k) is possible.
            if (presentSubarrayLength == requiredSubarrayLength) {
                minSubarrayScore = Math.min(minSubarrayScore, presentSubarrayScore);
                presentSubarrayScore -= cardPoints[startingIndex++];
            }
        }
        return totalScore - minSubarrayScore;
    }
}
```

</details>
