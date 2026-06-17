# 1688. Count of Matches in Tournament

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/count-of-matches-in-tournament/)  
`Math` `Simulation`

**Problem Link:** [LeetCode 1688 - Count of Matches in Tournament](https://leetcode.com/problems/count-of-matches-in-tournament/)

## Problem

You are given an integer n, the number of teams in a tournament that has strange rules:

- If the current number of teams is even, each team gets paired with another team. A total of n / 2 matches are played, and n / 2 teams advance to the next round.
- If the current number of teams is odd, one team randomly advances in the tournament, and the rest gets paired. A total of (n - 1) / 2 matches are played, and (n - 1) / 2 + 1 teams advance to the next round.

Return the number of matches played in the tournament until a winner is decided.

### Example 1

```text
Input: n = 7
Output: 6
Explanation: Details of the tournament:
- 1st Round: Teams = 7, Matches = 3, and 4 teams advance.
- 2nd Round: Teams = 4, Matches = 2, and 2 teams advance.
- 3rd Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
Total number of matches = 3 + 2 + 1 = 6.
```

### Example 2

```text
Input: n = 14
Output: 13
Explanation: Details of the tournament:
- 1st Round: Teams = 14, Matches = 7, and 7 teams advance.
- 2nd Round: Teams = 7, Matches = 3, and 4 teams advance.
- 3rd Round: Teams = 4, Matches = 2, and 2 teams advance.
- 4th Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
Total number of matches = 7 + 3 + 2 + 1 = 13.
```

## Constraints

- 1 <= n <= 200

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Distinct Numbers on Board](https://leetcode.com/problems/count-distinct-numbers-on-board/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1688. Count of Matches in Tournament

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulate | C++, Java, Python3 |
| Logic | C++, Java, Python3 |

## Approach 1: Simulate

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                ans += n / 2;
                n = n / 2;
            } else {
                ans += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfMatches(int n) {
        int ans = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                ans += n / 2;
                n = n / 2;
            } else {
                ans += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfMatches(self, n: int) -> int:
        ans = 0
        while n > 1:
            if n % 2 == 0:
                ans += n // 2
                n = n // 2
            else:
                ans += (n - 1) // 2
                n = ((n - 1) // 2) + 1
        
        return ans
```

</details>

<br>

## Approach 2: Logic

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfMatches(int n) {
        return n - 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfMatches(self, n: int) -> int:
        return n - 1
```

</details>
