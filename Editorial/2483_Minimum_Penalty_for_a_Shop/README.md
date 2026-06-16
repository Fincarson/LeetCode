# 2483. Minimum Penalty for a Shop

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-penalty-for-a-shop/)  
`String` `Prefix Sum`

**Problem Link:** [LeetCode 2483 - Minimum Penalty for a Shop](https://leetcode.com/problems/minimum-penalty-for-a-shop/)

## Problem

You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':

- if the ith character is 'Y', it means that customers come at the ith hour
- whereas 'N' indicates that no customers come at the ith hour.

If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

- For every hour when the shop is open and no customers come, the penalty increases by 1.
- For every hour when the shop is closed and customers come, the penalty increases by 1.

Return the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.

### Example 1

```text
Input: customers = "YYNY"
Output: 2
Explanation:
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
```

### Example 2

```text
Input: customers = "NNNNN"
Output: 0
Explanation: It is best to close the shop at the 0th hour as no customers arrive.
```

### Example 3

```text
Input: customers = "YYYY"
Output: 4
Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.
```

## Constraints

- 1 <= customers.length <= 105
- customers consists only of characters 'Y' and 'N'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Grid Game](https://leetcode.com/problems/grid-game/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Amount of Damage Dealt to Bob](https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2483. Minimum Penalty for a Shop

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Passes | C++, Java, Python3 |
| One Pass | C++, Java, Python3 |

## Approach 1: Two Passes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int bestClosingTime(string customers) {
        int curPenalty = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (customers[i] == 'Y') {
                curPenalty++;
            }
        }

        // Start with closing at hour 0, the penalty equals all 'Y' in closed
        // hours.
        int minPenalty = curPenalty;
        int earliestHour = 0;

        for (int i = 0; i < customers.size(); ++i) {
            char ch = customers[i];

            // If status in hour i is 'Y', moving it to open hours decrement
            // penalty by 1. Otherwise, moving 'N' to open hours increment
            // penalty by 1.
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }

            // Update earliestHour if a smaller penalty is encountered.
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int bestClosingTime(String customers) {
        int curPenalty = 0;
        for (int i = 0; i < customers.length(); i++) {
            if (customers.charAt(i) == 'Y') {
                curPenalty++;
            }
        }

        // Start with closing at hour 0, the penalty equals all 'Y' in closed hours.
        int minPenalty = curPenalty;
        int earliestHour = 0;

        for (int i = 0; i < customers.length(); i++) {
            char ch = customers.charAt(i);

            // If status in hour i is 'Y', moving it to open hours decrement
            // penalty by 1. Otherwise, moving 'N' to open hours increment
            // penatly by 1.
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }

            // Update earliestHour if a smaller penatly is encountered.
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bestClosingTime(self, customers: str) -> int:
        curPenalty = sum(c == "Y" for c in customers)

        # Start with closing at hour 0, the penalty equals all 'Y' in closed hours.
        minPenalty = curPenalty
        earliestHour = 0

        for i, ch in enumerate(customers):
            # If status in hour i is 'Y', moving it to open hours decrement
            # penalty by 1. Otherwise, moving 'N' to open hours increment
            # penalty by 1.
            if ch == "Y":
                curPenalty -= 1
            else:
                curPenalty += 1

            # Update earliestHour if a smaller penalty is encountered.
            if curPenalty < minPenalty:
                earliestHour = i + 1
                minPenalty = curPenalty

        return earliestHour
```

</details>

<br>

## Approach 2: One Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int bestClosingTime(string customers) {
        // Start with closing at hour 0 and assume the current penalty is 0.
        int minPenalty = 0, curPenalty = 0;
        int earliestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            char ch = customers[i];

            // If status in hour i is 'Y', moving it to open hours decrement
            // penalty by 1. Otherwise, moving 'N' to open hours increment
            // penatly by 1.
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }

            // Update earliestHour if a smaller penatly is encountered.
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int bestClosingTime(String customers) {
        // Start with closing at hour 0 and assume the current penalty is 0.
        int minPenalty = 0, curPenalty = 0;
        int earliestHour = 0;

        for (int i = 0; i < customers.length(); i++) {
            char ch = customers.charAt(i);

            // If status in hour i is 'Y', moving it to open hours decrement
            // penalty by 1. Otherwise, moving 'N' to open hours increment
            // penatly by 1.
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }

            // Update earliestHour if a smaller penatly is encountered.
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bestClosingTime(self, customers: str) -> int:
        # Start with closing at hour 0 and assume the current penalty is 0.
        minPenalty = 0
        curPenalty = 0
        earliestHour = 0

        for i in range(len(customers)):
            ch = customers[i]

            # If status in hour i is 'Y', moving it to open hours decrement
            # penalty by 1. Otherwise, moving 'N' to open hours increment
            # penatly by 1.
            if ch == "Y":
                curPenalty -= 1
            else:
                curPenalty += 1

            # Update earliestHour if a smaller penatly is encountered.
            if curPenalty < minPenalty:
                earliestHour = i + 1
                minPenalty = curPenalty

        return earliestHour
```

</details>
