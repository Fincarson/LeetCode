# 967. Numbers With Same Consecutive Differences

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/numbers-with-same-consecutive-differences/)  
`Backtracking` `Breadth-First Search`

**Problem Link:** [LeetCode 967 - Numbers With Same Consecutive Differences](https://leetcode.com/problems/numbers-with-same-consecutive-differences/)

## Problem

Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.

Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.

### Example 1

```text
Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
```

### Example 2

```text
Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
```

## Constraints

- 2 <= n <= 9
- 0 <= k <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 967. Numbers With Same Consecutive Differences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DFS (Depth-First Search) | Java, Python3 |
| BFS (Breadth-First Search) | Java, Python3 |

## Approach 1: DFS (Depth-First Search)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

class Solution {

    public int[] numsSameConsecDiff(int N, int K) {
        if (N == 1)
            return new int[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        List<Integer> results = new ArrayList<Integer>();
        for (int num = 1; num < 10; ++num)
            this.DFS(N - 1, num, K, results);

        // convert the ArrayList to int[]
        return results.stream().mapToInt(i->i).toArray();
    }

    protected void DFS(int N, int num, int K, List<Integer> results) {
        if (N == 0) {
            results.add(num);
            return;
        }
        List<Integer> nextDigits = new ArrayList<>();

        Integer tailDigit = num % 10;
        nextDigits.add(tailDigit + K);
        if (K != 0)
            nextDigits.add(tailDigit - K);
        for (Integer nextDigit : nextDigits) {
            if (0 <= nextDigit && nextDigit < 10) {
                Integer newNum = num * 10 + nextDigit;
                this.DFS(N - 1, newNum, K, results);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numsSameConsecDiff(self, N: int, K: int) -> List[int]:

        if N == 1:
            return [i for i in range(10)]

        ans = []
        def DFS(N, num):
            # base case
            if N == 0:
                return ans.append(num)

            tail_digit = num % 10
            # using set() to avoid duplicates when K == 0
            next_digits = set([tail_digit + K, tail_digit - K])

            for next_digit in next_digits:
                if 0 <= next_digit < 10:
                    new_num = num * 10 + next_digit
                    DFS(N-1, new_num)

        for num in range(1, 10):
            DFS(N-1, num)

        return list(ans)
```

</details>

<br>

## Approach 2: BFS (Breadth-First Search)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] numsSameConsecDiff(int N, int K) {

        if (N == 1)
            return new int[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        List<Integer> queue = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9);
        for(int level = 1; level < N; ++ level) {
            ArrayList<Integer> nextQueue = new ArrayList<>();
            // iterate through each number within the level
            for (Integer num : queue) {
                Integer tailDigit = num % 10;

                ArrayList<Integer> nextDigits = new ArrayList<>();
                nextDigits.add(tailDigit + K);
                if (K != 0)
                    nextDigits.add(tailDigit - K);
                for (Integer nextDigit : nextDigits) {
                    if (0 <= nextDigit && nextDigit < 10) {
                        Integer newNum = num * 10 + nextDigit;
                        nextQueue.add(newNum);
                    }
                }
            }
            // prepare for the next level
            queue = nextQueue;
        }

        return queue.stream().mapToInt(i->i).toArray();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numsSameConsecDiff(self, N: int, K: int) -> List[int]:

        if N == 1:
            return [i for i in range(10)]

        # initialize the queue with candidates for the first level
        queue = [digit for digit in range(1, 10)]

        for level in range(N-1):
            next_queue = []
            for num in queue:
                tail_digit = num % 10
                # using set() to avoid duplicates when K == 0
                next_digits = set([tail_digit + K, tail_digit - K])

                for next_digit in next_digits:
                    if 0 <= next_digit < 10:
                        new_num = num * 10 + next_digit
                        next_queue.append(new_num)
            # start the next level
            queue = next_queue

        return queue
```

</details>
