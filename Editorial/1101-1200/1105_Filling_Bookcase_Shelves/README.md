# 1105. Filling Bookcase Shelves

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/filling-bookcase-shelves/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1105 - Filling Bookcase Shelves](https://leetcode.com/problems/filling-bookcase-shelves/)

## Problem

You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

- For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

### Example 1

```text
Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.
```

### Example 2

```text
Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
Output: 4
```

## Constraints

- 1 <= books.length <= 1000
- 1 <= thicknessi <= shelfWidth <= 1000
- 1 <= heighti <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1105. Filling Bookcase Shelves

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> memo(books.size(), vector<int>(shelfWidth + 1, 0));
        return dpHelper(books, shelfWidth, memo, 0, shelfWidth, 0);
    }

private:
    int dpHelper(vector<vector<int>>& books, int shelfWidth,
                 vector<vector<int>>& memo, int i, int remainingShelfWidth,
                 int maxHeight) {
        // Return height of current shelf
        if (i == books.size()) return maxHeight;
        // Return answer if already computed
        if (memo[i][remainingShelfWidth] != 0) {
            return memo[i][remainingShelfWidth];
        } else {
            vector<int> currentBook = books[i];
            // Calculate the height of the bookcase if we put the
            // current book on the new shelf
            int option1Height =
                maxHeight + dpHelper(books, shelfWidth, memo, i + 1,
                                     shelfWidth - currentBook[0],
                                     currentBook[1]);
            int option2Height = INT_MAX;
            if (remainingShelfWidth >= currentBook[0]) {
                int maxHeightUpdated = max(maxHeight, currentBook[1]);
                option2Height = dpHelper(books, shelfWidth, memo, i + 1,
                                         remainingShelfWidth - currentBook[0],
                                         maxHeightUpdated);
            }
            // Store the smaller result in cache
            memo[i][remainingShelfWidth] = min(option1Height, option2Height);
            return memo[i][remainingShelfWidth];
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minHeightShelves(int[][] books, int shelfWidth) {
        // Cache to store previous computations
        int[][] memo = new int[books.length][shelfWidth + 1];
        return dpHelper(books, shelfWidth, memo, 0, shelfWidth, 0);
    }

    private int dpHelper(
        int[][] books,
        int shelfWidth,
        int[][] memo,
        int i,
        int remainingShelfWidth,
        int maxHeight
    ) {
        // Return height of current shelf
        if (i == books.length) return maxHeight;
        // Return answer if already computed
        if (memo[i][remainingShelfWidth] != 0) {
            return memo[i][remainingShelfWidth];
        } else {
            int[] currentBook = books[i];
            // Calculate the height of the bookcase if we put the current book on the new shelf
            int option1Height =
                maxHeight +
                dpHelper(
                    books,
                    shelfWidth,
                    memo,
                    i + 1,
                    shelfWidth - currentBook[0],
                    currentBook[1]
                );
            int option2Height = Integer.MAX_VALUE;
            if (remainingShelfWidth >= currentBook[0]) {
                int maxHeightUpdated = Math.max(maxHeight, currentBook[1]);
                // Calculate height of the bookcase if we put the current book on the current shelf
                option2Height = dpHelper(
                    books,
                    shelfWidth,
                    memo,
                    i + 1,
                    remainingShelfWidth - currentBook[0],
                    maxHeightUpdated
                );
            }
            // Store the smaller result in cache
            memo[i][remainingShelfWidth] = Math.min(
                option1Height,
                option2Height
            );
            return memo[i][remainingShelfWidth];
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        # Cache to store previous computations
        memo = [[0 for _ in range(shelfWidth + 1)] for _ in range(len(books))]
        return self._dpHelper(books, shelfWidth, memo, 0, shelfWidth, 0)

    def _dpHelper(
        self, books, shelf_width, memo, i, remaining_shelf_width, max_height
    ):
        if i == len(books):
            return max_height
        if memo[i][remaining_shelf_width] != 0:
            return memo[i][remaining_shelf_width]
        else:
            current_book = books[i]
            # Calculate height of the bookcase if we put the current book on the new shelf
            option_1_height = max_height + self._dpHelper(
                books,
                shelf_width,
                memo,
                i + 1,
                shelf_width - current_book[0],
                current_book[1],
            )
            option_2_height = float("inf")
            if remaining_shelf_width >= current_book[0]:
                # Calculate height of the bookcase if we put the current book on the current shelf
                max_height_updated = max(max_height, current_book[1])
                option_2_height = self._dpHelper(
                    books,
                    shelf_width,
                    memo,
                    i + 1,
                    remaining_shelf_width - current_book[0],
                    max_height_updated,
                )

            # Store the smaller result in cache
            memo[i][remaining_shelf_width] = min(
                option_1_height, option_2_height
            )
            return memo[i][remaining_shelf_width]
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // dp[i] will store the minimum height of the bookcase containing all
        // books up to and excluding i
        vector<int> dp(books.size() + 1, 0);

        // Base cases
        dp[0] = 0;
        dp[1] = books[0][1];

        for (int i = 1; i <= books.size(); ++i) {
            // new shelf built to hold current book
            int remainingShelfWidth = shelfWidth - books[i - 1][0];
            int maxHeight = books[i - 1][1];
            dp[i] = dp[i - 1] + maxHeight;

            int j = i - 1;
            // calculate the height when previous books are added onto a new
            // shelf
            while (j > 0 && remainingShelfWidth - books[j - 1][0] >= 0) {
                remainingShelfWidth -= books[j - 1][0];
                maxHeight = max(maxHeight, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxHeight);
                j--;
            }
        }

        return dp[books.size()];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minHeightShelves(int[][] books, int shelfWidth) {
        // dp[i] = minimum height of bookcase containing all books up to and
        // excluding book i
        int[] dp = new int[books.length + 1];

        // base cases
        dp[0] = 0;
        dp[1] = books[0][1];

        for (int i = 2; i <= books.length; i++) {
            // new shelf built to hold current book
            int remainingShelfWidth = shelfWidth - books[i - 1][0];
            int maxHeight = books[i - 1][1];
            dp[i] = books[i - 1][1] + dp[i - 1];

            int j = i - 1;
            // calculate the height when previous books are added onto a new shelf
            while (j > 0 && remainingShelfWidth - books[j - 1][0] >= 0) {
                maxHeight = Math.max(maxHeight, books[j - 1][1]);
                remainingShelfWidth -= books[j - 1][0];
                dp[i] = Math.min(dp[i], maxHeight + dp[j - 1]);
                j--;
            }
        }

        return dp[books.length];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        # dp[i] will store the minimum height of the bookcase containing all
        # books up to and excluding i
        dp = [0] * (n + 1)

        # Base cases
        dp[0] = 0
        dp[1] = books[0][1]

        for i in range(2, n + 1):
            # new shelf built to hold current book
            remaining_shelf_width = shelfWidth - books[i - 1][0]
            max_height = books[i - 1][1]
            dp[i] = books[i - 1][1] + dp[i - 1]

            j = i - 1
            # calculate the height when previous books are added to new shelf
            while j > 0 and remaining_shelf_width - books[j - 1][0] >= 0:
                max_height = max(max_height, books[j - 1][1])
                remaining_shelf_width -= books[j - 1][0]
                dp[i] = min(dp[i], max_height + dp[j - 1])
                j -= 1

        return dp[n]
```

</details>
