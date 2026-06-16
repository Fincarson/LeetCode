# 544. Output Contest Matches

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/output-contest-matches/)  
`String` `Recursion` `Simulation`

**Problem Link:** [LeetCode 544 - Output Contest Matches](https://leetcode.com/problems/output-contest-matches/)

## Problem

During the NBA playoffs, we always set the rather strong team to play with the rather weak team, like making the rank 1 team play with the rank nth team, which is a good strategy to make the contest more interesting.

Given n teams, return their final contest matches in the form of a string.

The n teams are labeled from 1 to n, which represents their initial rank (i.e., Rank 1 is the strongest team and Rank n is the weakest team).

We will use parentheses '(', and ')' and commas ',' to represent the contest team pairing. We use the parentheses for pairing and the commas for partition. During the pairing process in each round, you always need to follow the strategy of making the rather strong one pair with the rather weak one.

### Example 1

```text
Input: n = 4
Output: "((1,4),(2,3))"
Explanation:
In the first round, we pair the team 1 and 4, the teams 2 and 3 together, as we need to make the strong team and weak team together.
And we got (1, 4),(2, 3).
In the second round, the winners of (1, 4) and (2, 3) need to play again to generate the final winner, so you need to add the paratheses outside them.
And we got the final answer ((1,4),(2,3)).
```

### Example 2

```text
Input: n = 8
Output: "(((1,8),(4,5)),((2,7),(3,6)))"
Explanation:
First round: (1, 8),(2, 7),(3, 6),(4, 5)
Second round: ((1, 8),(4, 5)),((2, 7),(3, 6))
Third round: (((1, 8),(4, 5)),((2, 7),(3, 6)))
Since the third round will generate the final winner, you need to output the answer (((1,8),(4,5)),((2,7),(3,6))).
```

## Constraints

- n == 2x where x in in the range [1, 12].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 544. Output Contest Matches

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Simulation [Accepted] | Java, Python |
| Approach #2: Linear Write [Accepted] | Java, Python |

## Approach #1: Simulation [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String findContestMatch(int n) {
        String[] team = new String[n];
        for (int i = 1; i <= n; ++i)
            team[i-1] = "" + i;

        for (; n > 1; n /= 2)
            for (int i = 0; i < n / 2; ++i)
                team[i] = "(" + team[i] + "," + team[n-1-i] + ")";

        return team[0];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findContestMatch(self, n):
        team = map(str, range(1, n+1))

        while n > 1:
            for i in xrange(n / 2):
                team[i] = "({},{})".format(team[i], team.pop())
            n /= 2

        return team[0]
```

</details>

<br>

## Approach #2: Linear Write [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[] team;
    int t;
    StringBuilder ans;
    public String findContestMatch(int n) {
        team = new int[n];
        t = 0;
        ans = new StringBuilder();
        write(n, Integer.numberOfTrailingZeros(n));
        return ans.toString();
    }

    public void write(int n, int round) {
        if (round == 0) {
            int w = Integer.lowestOneBit(t);
            team[t] = w > 0 ? n / w + 1 - team[t - w] : 1;
            ans.append("" + team[t++]);
        } else {
            ans.append("(");
            write(n, round - 1);
            ans.append(",");
            write(n, round - 1);
            ans.append(")");
        }
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findContestMatch(self, n):
        team = []
        ans = []
        def write(r):
            if r == 0:
                i = len(team)
                w = i & -i
                team.append(n/w+1 - team[i-w] if w else 1)
                ans.append(str(team[-1]))
            else:
                ans.append("(")
                write(r-1)
                ans.append(",")
                write(r-1)
                ans.append(")")

        write(int(math.log(n, 2)))
        return "".join(ans)
```

</details>
