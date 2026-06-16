# 575. Distribute Candies

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/distribute-candies/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 575 - Distribute Candies](https://leetcode.com/problems/distribute-candies/)

## Problem

Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

### Example 1

```text
Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.
```

### Example 2

```text
Input: candyType = [1,1,2,3]
Output: 2
Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.
```

### Example 3

```text
Input: candyType = [6,6,6,6]
Output: 1
Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.
```

## Constraints

- n == candyType.length
- 2 <= n <= 104
- n is even.
- -105 <= candyType[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Operations to Satisfy Conditions](https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Check if Grid Satisfies Conditions](https://leetcode.com/problems/check-if-grid-satisfies-conditions/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 575. Distribute Candies

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python3 |
| Sorting | Java, Python3 |
| Using a Hash Set | Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int distributeCandies(int[] candyType) {
        // Initiate a variable to count how many unique candies are in the array.
        int uniqueCandies = 0;
        // For each candy, we're going to check whether or not we've already
        // seen a candy identical to it.
        for (int i = 0; i < candyType.length; i++) {
            // Start by assuming that the candy IS unique.
            boolean isUnique = true;
            // Check each candy BEFORE this candy.
            for (int j = 0; j < i; j++) {
                // If this candy is the same as a previous one, it isn't unique.
                if (candyType[i] == candyType[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                uniqueCandies++;
            }
        }
        // The answer is the minimum out of the number of unique candies, and 
        // half the length of the candyType array.
        return Math.min(uniqueCandies, candyType.length / 2);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        # We need to count how many unique candies are in the array.
        unique_candies = 0
        # For each candy, we're going to check whether or not we've already
        # seen a candy identical to it.
        for i in range(len(candyType)):
            # Check if we've already seen a candy the same as candyType[i].
            for j in range(0, i):
                # If this candy is the same as previous one, we don't need to 
                # check further.
                if candyType[i] == candyType[j]:
                    break
            # Confused? An "else" after a "for" is an awesome Python feature.
            # The code in the "else" only runs if the "for" loop runs without a break.
            # In this case, we know that if we didn't "break" out of the loop, then 
            # candyType[i] is unique.
            # https://docs.python.org/3/tutorial/controlflow.html#break-and-continue-statements-and-else-clauses-on-loops
            else:
                unique_candies += 1
        # The answer is the minimum out of the number of unique candies, and 
        # half the length of the candyType array.
        return min(unique_candies, len(candyType) // 2)
```

</details>

<br>

## Approach 2: Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int distributeCandies(int[] candyType) {
        // We start by sorting candyType.
        Arrays.sort(candyType);
        // The first candy is always unique.
        int uniqueCandies = 1;
        // For each candy, starting from the second candy...
        for (int i = 1; i < candyType.length && uniqueCandies < candyType.length / 2; i++) {
            // This candy is unique if it is different to the one
            // immediately before it.
            if (candyType[i] != candyType[i - 1]) {
                uniqueCandies++;
            }
        }
        // Like before, the answer is the minimum out of the number of unique 
        // candies, and half the length of the candyType array.
        return Math.min(uniqueCandies, candyType.length / 2);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        # We start by sorting candyType.
        candyType.sort()
        # The first candy is always unique.
        unique_candies = 1
        # For each candy, starting from the *second* candy...
        for i in range(1, len(candyType)):
            # This candy is unique if it is different to the one
            # immediately before it.
            if candyType[i] != candyType[i - 1]:
                unique_candies += 1
            # Optimization: We should terminate the loop if unique_candies
            # is now at the maxium she can eat.
            if unique_candies == len(candyType) // 2:
                break
        # Like before, the answer is the minimum out of the number of unique candies, and 
        # half the length of the candyType array.
        return min(unique_candies, len(candyType) // 2)
```

</details>

<br>

## Approach 3: Using a Hash Set

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int distributeCandies(int[] candyType) {
        // Create an empty Hash Set, and add each candy into it.
        Set<Integer> uniqueCandiesSet = new HashSet<>();
        for (int candy: candyType) {
            uniqueCandiesSet.add(candy);
        }
        // Then, find the answer in the same way as before.
        return Math.min(uniqueCandiesSet.size(), candyType.length / 2);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        # Count the number of unique candies by creating a set with
        # candyType, and then taking its length.
        unique_candies = len(set(candyType))
        # And find the answer in the same way as before.
        return min(unique_candies, len(candyType) // 2)
```

</details>
