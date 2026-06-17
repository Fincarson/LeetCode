# 2355. Maximum Number of Books You Can Take

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-number-of-books-you-can-take/)  
`Array` `Dynamic Programming` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 2355 - Maximum Number of Books You Can Take](https://leetcode.com/problems/maximum-number-of-books-you-can-take/)

## Problem

You are given a 0-indexed integer array books of length n where books[i] denotes the number of books on the ith shelf of a bookshelf.

You are going to take books from a contiguous section of the bookshelf spanning from l to r where 0 <= l <= r < n. For each index i in the range l <= i < r, you must take strictly fewer books from shelf i than shelf i + 1.

Return the maximum number of books you can take from the bookshelf.

### Example 1

```text
Input: books = [8,5,2,7,9]
Output: 19
Explanation:
- Take 1 book from shelf 1.
- Take 2 books from shelf 2.
- Take 7 books from shelf 3.
- Take 9 books from shelf 4.
You have taken 19 books, so return 19.
It can be proven that 19 is the maximum number of books you can take.
```

### Example 2

```text
Input: books = [7,0,3,4,5]
Output: 12
Explanation:
- Take 3 books from shelf 2.
- Take 4 books from shelf 3.
- Take 5 books from shelf 4.
You have taken 12 books so return 12.
It can be proven that 12 is the maximum number of books you can take.
```

### Example 3

```text
Input: books = [8,2,3,7,3,4,0,1,4,3]
Output: 13
Explanation:
- Take 1 book from shelf 0.
- Take 2 books from shelf 1.
- Take 3 books from shelf 2.
- Take 7 books from shelf 3.
You have taken 13 books so return 13.
It can be proven that 13 is the maximum number of books you can take.
```

## Constraints

- 1 <= books.length <= 105
- 0 <= books[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Beautiful Towers II](https://leetcode.com/problems/beautiful-towers-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Beautiful Towers I](https://leetcode.com/problems/beautiful-towers-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2355. Maximum Number of Books You Can Take

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();

        // Helper function to calculate the sum of books in a given range [l, r]
        auto calculateSum = [&](int l, int r) {
            long long cnt = min(books[r], r - l + 1);
            return (2 * books[r] - (cnt - 1)) * cnt / 2;
        };

        stack<int> s;
        vector<long long> dp(n);

        for (int i = 0; i < n; i++) {
            // While we cannot push i, we pop from the stack
            while (!s.empty() && books[s.top()] - s.top() >= books[i] - i) {
                s.pop();
            }

            // Compute dp[i]
            if (s.empty()) {
                dp[i] = calculateSum(0, i);
            }
            else {
                int j = s.top();
                dp[i] = dp[j] + calculateSum(j + 1, i);
            }

            // Push the current index onto the stack
            s.push(i);
        }

        // Return the maximum element in dp array
        return *max_element(dp.begin(), dp.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long maximumBooks(int[] books) {
        int n = books.length;

        Stack<Integer> s = new Stack<>();
        long[] dp = new long[n];

        for (int i = 0; i < n; i++) {
            // While we cannot push i, we pop from the stack
            while (!s.isEmpty() && books[s.peek()] - s.peek() >= books[i] - i) {
                s.pop();
            }

            // Compute dp[i]
            if (s.isEmpty()) {
                dp[i] = calculateSum(books, 0, i);
            } else {
                int j = s.peek();
                dp[i] = dp[j] + calculateSum(books, j + 1, i);
            }

            // Push the current index onto the stack
            s.push(i);
        }


        // Return the maximum element in dp array
        return Arrays.stream(dp).max().getAsLong();
    }

    // Helper function to calculate the sum of books in a given range [l, r]
    private long calculateSum(int[] books, int l, int r) {
        long cnt = Math.min(books[r], r - l + 1);
        return (2 * books[r] - (cnt - 1)) * cnt / 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumBooks(self, books: List[int]) -> int:
        n = len(books)

        # Helper function to calculate the sum of books in a given range [l, r]
        def calculateSum(l, r):
            cnt = min(books[r], r - l + 1)
            return (2 * books[r] - (cnt - 1)) * cnt // 2

        stack = []
        dp = [0] * n

        for i in range(n):
            # While we cannot push i, we pop from the stack
            while stack and books[stack[-1]] - stack[-1] >= books[i] - i:
                stack.pop()

            # Compute dp[i]
            if not stack:
                dp[i] = calculateSum(0, i)
            else:
                j = stack[-1]
                dp[i] = dp[j] + calculateSum(j + 1, i)

            # Push the current index onto the stack
            stack.append(i)

        # Return the maximum element in the dp array
        return max(dp)
```

</details>
