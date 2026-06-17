# 1518. Water Bottles

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/water-bottles/)  
`Math` `Simulation`

**Problem Link:** [LeetCode 1518 - Water Bottles](https://leetcode.com/problems/water-bottles/)

## Problem

There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

### Example 1

```text
Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.
```

### Example 2

```text
Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 15 + 3 + 1 = 19.
```

## Constraints

- 1 <= numBottles <= 100
- 2 <= numExchange <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Water Bottles II](https://leetcode.com/problems/water-bottles-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1518. Water Bottles

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C++, Java, Python3 |
| Optimized Simulation | C++, Java, Python3 |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = 0;

        while (numBottles >= numExchange) {
            // Consume numExchange full bottles.
            consumedBottles += numExchange;
            numBottles -= numExchange;

            // Exchange them for one full bottle.
            numBottles++;
        }

        // Consume the remaining numBottles (<numExchange).
        return consumedBottles + numBottles;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = 0;

        while (numBottles >= numExchange) {
            // Consume numExchange full bottles.
            consumedBottles += numExchange;
            numBottles -= numExchange;

            // Exchange them for one full bottle.
            numBottles++;
        }

        // Consume the remaining numBottles (<numExchange).
        return consumedBottles + numBottles;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        consumed_bottles = 0

        while numBottles >= numExchange:
            # Consume numExchange full bottles.
            consumed_bottles += numExchange
            numBottles -= numExchange

            # Exchange them for one full bottle.
            numBottles += 1

        # Consume the remaining numBottles (less than numExchange).
        return consumed_bottles + numBottles
```

</details>

<br>

## Approach 2: Optimized Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = 0;

        while (numBottles >= numExchange) {
            // Maximum number of times we can consume numExchange
            // number of bottles using numBottles.
            int K = numBottles / numExchange;

            consumedBottles += numExchange * K;
            numBottles -= numExchange * K;

            numBottles += K;
        }

        return consumedBottles + numBottles;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = 0;

        while (numBottles >= numExchange) {
            // Maximum number of times we can consume numExchange
            // number of bottles using numBottles.
            int K = numBottles / numExchange;

            consumedBottles += numExchange * K;
            numBottles -= numExchange * K;

            numBottles += K;
        }

        return consumedBottles + numBottles;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        consumed_bottles = 0

        while numBottles >= numExchange:
            # Maximum number of times we can consume numExchange
            # number of bottles using numBottles.
            K = numBottles // numExchange

            consumed_bottles += numExchange * K
            numBottles -= numExchange * K

            numBottles += K

        return consumed_bottles + numBottles
```

</details>
