# 374. Guess Number Higher or Lower

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/guess-number-higher-or-lower/)  
`Binary Search` `Interactive`

**Problem Link:** [LeetCode 374 - Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/)

## Problem

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked (the number I picked stays the same throughout the game).

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

- -1: Your guess is higher than the number I picked (i.e. num > pick).
- 1: Your guess is lower than the number I picked (i.e. num < pick).
- 0: your guess is equal to the number I picked (i.e. num == pick).

Return the number that I picked.

### Example 1

```text
Input: n = 10, pick = 6
Output: 6
```

### Example 2

```text
Input: n = 1, pick = 1
Output: 1
```

### Example 3

```text
Input: n = 2, pick = 1
Output: 1
```

## Constraints

- 1 <= n <= 231 - 1
- 1 <= pick <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [First Bad Version](https://leetcode.com/problems/first-bad-version/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 374. Guess Number Higher or Lower

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Using Binary Search | Java |
| Ternary Search | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        for (int i = 1; i < n; i++)
            if (guess(i) == 0)
                return i;
        return n;
    }
}
```

</details>

<br>

## Approach 2: Using Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);
            if (res == 0)
                return mid;
            else if (res < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
}
```

</details>

<br>

## Approach 3: Ternary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;
            int res1 = guess(mid1);
            int res2 = guess(mid2);
            if (res1 == 0)
                return mid1;
            if (res2 == 0)
                return mid2;
            else if (res1 < 0)
                high = mid1 - 1;
            else if (res2 > 0)
                low = mid2 + 1;
            else {
                low = mid1 + 1;
                high = mid2 - 1;
            }
        }
        return -1;
    }
}
```

</details>
