# 2140. Solving Questions With Brainpower

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/solving-questions-with-brainpower/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 2140 - Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower/)

## Problem

You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

- For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:

		If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
		If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.

Return the maximum points you can earn for the exam.

### Example 1

```text
Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
```

### Example 2

```text
Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
```

## Constraints

- 1 <= questions.length <= 105
- questions[i].length == 2
- 1 <= pointsi, brainpoweri <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [House Robber](https://leetcode.com/problems/house-robber/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Frog Jump](https://leetcode.com/problems/frog-jump/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2140. Solving Questions With Brainpower

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming (Iterative) | Java, Python3 |
| Dynamic Programming (Recursive) | Java, Python3 |

## Approach 1: Dynamic Programming (Iterative)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] dp = new long[n];
        dp[n - 1] = questions[n - 1][0];
        
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = questions[i][0];
            int skip = questions[i][1];
            if (i + skip + 1 < n) {
                dp[i] += dp[i + skip + 1];
            }
            
            // dp[i] = max(solve it, skip it)
            dp[i] = Math.max(dp[i], dp[i + 1]);
        }
        
        return dp[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        dp = [0] * n
        dp[-1] = questions[-1][0]
        
        for i in range(n - 2, -1, -1):
            dp[i] = questions[i][0]
            skip = questions[i][1]
            if i + skip + 1 < n:
                dp[i] += dp[i + skip + 1]

            # dp[i] = max(solve it, skip it)
            dp[i] = max(dp[i], dp[i + 1])
        
        return dp[0]
```

</details>

<br>

## Approach 2: Dynamic Programming (Recursive)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    long dp[];
    private long dfs(int[][] questions, int i) {
        if (i >= questions.length) {
            return 0;
        }
        if (dp[i] != 0) {
            return dp[i];
        }
        long points = questions[i][0];
        int skip = questions[i][1];

        // dp[i] = max(skip it, solve it)
        dp[i] = Math.max(points + dfs(questions, i + skip + 1), dfs(questions, i + 1));
        return dp[i];
    }
    
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        dp = new long[n];
        
        return dfs(questions, 0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:     
        n = len(questions)
        dp = [0] * n
        
        def dfs(i):
            if i >= n:
                return 0
            if dp[i]:
                return dp[i]
            points, skip = questions[i]

            # dp[i] = max(skip it, solve it)
            dp[i] = max(dfs(i + 1), points + dfs(i + skip + 1))
            return dp[i]
        
        return dfs(0)
```

</details>
