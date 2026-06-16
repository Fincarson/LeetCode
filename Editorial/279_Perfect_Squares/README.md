# 279. Perfect Squares

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/perfect-squares/)  
`Math` `Dynamic Programming` `Breadth-First Search`

**Problem Link:** [LeetCode 279 - Perfect Squares](https://leetcode.com/problems/perfect-squares/)

## Problem

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

### Example 1

```text
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
```

### Example 2

```text
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

## Constraints

- 1 <= n <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Primes](https://leetcode.com/problems/count-primes/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Ways to Express an Integer as Sum of Powers](https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 279. Perfect Squares

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute-force Enumeration [Time Limit Exceeded] | Python |
| Dynamic Programming | Java, Python |
| Greedy Enumeration | Java, Python |
| Greedy + BFS (Breadth-First Search) | Java, Python |
| Mathematics | Java, Python |

## Approach 1: Brute-force Enumeration [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def numSquares(self, n):
        square_nums = [i**2 for i in range(1, int(math.sqrt(n))+1)]

        def minNumSquares(k):
            """ recursive solution """
            # bottom cases: find a square number
            if k in square_nums:
                return 1
            min_num = float('inf')

            # Find the minimal value among all possible solutions
            for square in square_nums:
                if k < square:
                    break
                new_num = minNumSquares(k-square) + 1
                min_num = min(min_num, new_num)
            return min_num

        return minNumSquares(n)
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

  public int numSquares(int n) {
    int dp[] = new int[n + 1];
    Arrays.fill(dp, Integer.MAX_VALUE);
    // bottom case
    dp[0] = 0;

    // pre-calculate the square numbers.
    int max_square_index = (int) Math.sqrt(n) + 1;
    int square_nums[] = new int[max_square_index];
    for (int i = 1; i < max_square_index; ++i) {
      square_nums[i] = i * i;
    }

    for (int i = 1; i <= n; ++i) {
      for (int s = 1; s < max_square_index; ++s) {
        if (i < square_nums[s])
          break;
        dp[i] = Math.min(dp[i], dp[i - square_nums[s]] + 1);
      }
    }
    return dp[n];
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        square_nums = [i**2 for i in range(0, int(math.sqrt(n))+1)]
        
        dp = [float('inf')] * (n+1)
        # bottom case
        dp[0] = 0
        
        for i in range(1, n+1):
            for square in square_nums:
                if i < square:
                    break
                dp[i] = min(dp[i], dp[i-square] + 1)
        
        return dp[-1]
```

</details>

<br>

## Approach 3: Greedy Enumeration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  Set<Integer> square_nums = new HashSet<Integer>();

  protected boolean is_divided_by(int n, int count) {
    if (count == 1) {
      return square_nums.contains(n);
    }

    for (Integer square : square_nums) {
      if (is_divided_by(n - square, count - 1)) {
        return true;
      }
    }
    return false;
  }

  public int numSquares(int n) {
    this.square_nums.clear();

    for (int i = 1; i * i <= n; ++i) {
      this.square_nums.add(i * i);
    }

    int count = 1;
    for (; count <= n; ++count) {
      if (is_divided_by(n, count))
        return count;
    }
    return count;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def numSquares(self, n):
        
        def is_divided_by(n, count):
            """
                return: true if "n" can be decomposed into "count" number of perfect square numbers.
                e.g. n=12, count=3:  true.
                     n=12, count=2:  false
            """
            if count == 1:
                return n in square_nums
            
            for k in square_nums:
                if is_divided_by(n - k, count - 1):
                    return True
            return False

        square_nums = set([i * i for i in range(1, int(n**0.5)+1)])
    
        for count in range(1, n+1):
            if is_divided_by(n, count):
                return count
```

</details>

<br>

## Approach 4: Greedy + BFS (Breadth-First Search)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int numSquares(int n) {

    ArrayList<Integer> square_nums = new ArrayList<Integer>();
    for (int i = 1; i * i <= n; ++i) {
      square_nums.add(i * i);
    }

    Set<Integer> queue = new HashSet<Integer>();
    queue.add(n);

    int level = 0;
    while (queue.size() > 0) {
      level += 1;
      Set<Integer> next_queue = new HashSet<Integer>();

      for (Integer remainder : queue) {
        for (Integer square : square_nums) {
          if (remainder.equals(square)) {
            return level;
          } else if (remainder < square) {
            break;
          } else {
            next_queue.add(remainder - square);
          }
        }
      }
      queue = next_queue;
    }
    return level;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def numSquares(self, n):

        # list of square numbers that are less than `n`
        square_nums = [i * i for i in range(1, int(n**0.5)+1)]
    
        level = 0
        queue = {n}
        while queue:
            level += 1
            #! Important: use set() instead of list() to eliminate the redundancy,
            # which would even provide a 5-times speedup, 200ms vs. 1000ms.
            next_queue = set()
            # construct the queue for the next level
            for remainder in queue:
                for square_num in square_nums:    
                    if remainder == square_num:
                        return level  # find the node!
                    elif remainder < square_num:
                        break
                    else:
                        next_queue.add(remainder - square_num)
            queue = next_queue
        return level
```

</details>

<br>

## Approach 5: Mathematics

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

  protected boolean isSquare(int n) {
    int sq = (int) Math.sqrt(n);
    return n == sq * sq;
  }

  public int numSquares(int n) {
    // four-square and three-square theorems.
    while (n % 4 == 0)
      n /= 4;
    if (n % 8 == 7)
      return 4;

    if (this.isSquare(n))
      return 1;
    // enumeration to check if the number can be decomposed into sum of two squares.
    for (int i = 1; i * i <= n; ++i) {
      if (this.isSquare(n - i * i))
        return 2;
    }
    // bottom case of three-square theorem.
    return 3;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def isSquare(self, n: int) -> bool:
        sq = int(math.sqrt(n))
        return sq*sq == n

    def numSquares(self, n: int) -> int:
        # four-square and three-square theorems
        while (n & 3) == 0:
            n >>= 2      # reducing the 4^k factor from number
        if (n & 7) == 7: # mod 8
            return 4

        if self.isSquare(n):
            return 1
        # check if the number can be decomposed into sum of two squares
        for i in range(1, int(n**(0.5)) + 1):
            if self.isSquare(n - i*i):
                return 2
        # bottom case from the three-square theorem
        return 3
```

</details>
