# 1395. Count Number of Teams

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-number-of-teams/)  
`Array` `Dynamic Programming` `Binary Indexed Tree` `Segment Tree`

**Problem Link:** [LeetCode 1395 - Count Number of Teams](https://leetcode.com/problems/count-number-of-teams/)

## Problem

There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

- Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
- A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

### Example 1

```text
Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).
```

### Example 2

```text
Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
```

### Example 3

```text
Input: rating = [1,2,3,4]
Output: 4
```

## Constraints

- n == rating.length
- 3 <= n <= 1000
- 1 <= rating[i] <= 105
- All the integers in rating are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1395. Count Number of Teams

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming (Memoization) | C++, Java, Python3 |
| Dynamic Programming (Tabulation) | C++, Java, Python3 |
| Dynamic Programming (Optimized) | C++, Java, Python3 |
| Binary Indexed Tree (Fenwick Tree) | C++, Java, Python3 |

## Approach 1: Dynamic Programming (Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;
        vector<vector<int>> increasingCache(n, vector<int>(4, -1));
        vector<vector<int>> decreasingCache(n, vector<int>(4, -1));

        // Calculate total teams by considering each soldier as a starting point
        for (int startIndex = 0; startIndex < n; startIndex++) {
            teams +=
                countIncreasingTeams(rating, startIndex, 1, increasingCache) +
                countDecreasingTeams(rating, startIndex, 1, decreasingCache);
        }

        return teams;
    }

private:
    int countIncreasingTeams(const vector<int>& rating, int currentIndex,
                             int teamSize,
                             vector<vector<int>>& increasingCache) {
        int n = rating.size();

        // Base case: reached end of array
        if (currentIndex == n) return 0;

        // Base case: found a valid team of size 3
        if (teamSize == 3) return 1;

        // Return cached result if available
        if (increasingCache[currentIndex][teamSize] != -1) {
            return increasingCache[currentIndex][teamSize];
        }

        int validTeams = 0;

        // Recursively count teams with increasing ratings
        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++) {
            if (rating[nextIndex] > rating[currentIndex]) {
                validTeams += countIncreasingTeams(
                    rating, nextIndex, teamSize + 1, increasingCache);
            }
        }

        // Cache and return the result
        return increasingCache[currentIndex][teamSize] = validTeams;
    }

    int countDecreasingTeams(const vector<int>& rating, int currentIndex,
                             int teamSize,
                             vector<vector<int>>& decreasingCache) {
        int n = rating.size();

        // Base case: reached end of array
        if (currentIndex == n) return 0;

        // Base case: found a valid team of size 3
        if (teamSize == 3) return 1;

        // Return cached result if available
        if (decreasingCache[currentIndex][teamSize] != -1) {
            return decreasingCache[currentIndex][teamSize];
        }

        int validTeams = 0;

        // Recursively count teams with decreasing ratings
        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++) {
            if (rating[nextIndex] < rating[currentIndex]) {
                validTeams += countDecreasingTeams(
                    rating, nextIndex, teamSize + 1, decreasingCache);
            }
        }

        // Cache and return the result
        return decreasingCache[currentIndex][teamSize] = validTeams;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numTeams(int[] rating) {
        int n = rating.length;
        int teams = 0;
        Integer[][] increasingCache = new Integer[n][4];
        Integer[][] decreasingCache = new Integer[n][4];

        // Calculate total teams by considering each soldier as a starting point
        for (int startIndex = 0; startIndex < n; startIndex++) {
            teams +=
            countIncreasingTeams(rating, startIndex, 1, increasingCache) +
            countDecreasingTeams(rating, startIndex, 1, decreasingCache);
        }

        return teams;
    }

    private int countIncreasingTeams(
        int[] rating,
        int currentIndex,
        int teamSize,
        Integer[][] increasingCache
    ) {
        int n = rating.length;

        // Base case: reached end of array
        if (currentIndex == n) return 0;

        // Base case: found a valid team of size 3
        if (teamSize == 3) return 1;

        // Return cached result if available
        if (increasingCache[currentIndex][teamSize] != null) {
            return increasingCache[currentIndex][teamSize];
        }

        int validTeams = 0;

        // Recursively count teams with increasing ratings
        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++) {
            if (rating[nextIndex] > rating[currentIndex]) {
                validTeams +=
                countIncreasingTeams(
                    rating,
                    nextIndex,
                    teamSize + 1,
                    increasingCache
                );
            }
        }

        // Cache and return the result
        return increasingCache[currentIndex][teamSize] = validTeams;
    }

    private int countDecreasingTeams(
        int[] rating,
        int currentIndex,
        int teamSize,
        Integer[][] decreasingCache
    ) {
        int n = rating.length;

        // Base case: reached end of array
        if (currentIndex == n) return 0;

        // Base case: found a valid team of size 3
        if (teamSize == 3) return 1;

        // Return cached result if available
        if (decreasingCache[currentIndex][teamSize] != null) {
            return decreasingCache[currentIndex][teamSize];
        }

        int validTeams = 0;

        // Recursively count teams with decreasing ratings
        for (int nextIndex = currentIndex + 1; nextIndex < n; nextIndex++) {
            if (rating[nextIndex] < rating[currentIndex]) {
                validTeams +=
                countDecreasingTeams(
                    rating,
                    nextIndex,
                    teamSize + 1,
                    decreasingCache
                );
            }
        }

        // Cache and return the result
        return decreasingCache[currentIndex][teamSize] = validTeams;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        teams = 0
        increasing_cache = [[-1] * 4 for _ in range(n)]
        decreasing_cache = [[-1] * 4 for _ in range(n)]

        # Calculate total teams by considering each soldier as a starting point
        for start_index in range(n):
            teams += self._count_increasing_teams(
                rating, start_index, 1, increasing_cache
            ) + self._count_decreasing_teams(
                rating, start_index, 1, decreasing_cache
            )

        return teams

    def _count_increasing_teams(
        self,
        rating: List[int],
        current_index: int,
        team_size: int,
        increasing_cache: List[List[int]],
    ) -> int:
        n = len(rating)

        # Base case: reached end of array
        if current_index == n:
            return 0

        # Base case: found a valid team of size 3
        if team_size == 3:
            return 1

        # Return cached result if available
        if increasing_cache[current_index][team_size] != -1:
            return increasing_cache[current_index][team_size]

        valid_teams = 0

        # Recursively count teams with increasing ratings
        for next_index in range(current_index + 1, n):
            if rating[next_index] > rating[current_index]:
                valid_teams += self._count_increasing_teams(
                    rating, next_index, team_size + 1, increasing_cache
                )

        # Cache and return the result
        increasing_cache[current_index][team_size] = valid_teams
        return valid_teams

    def _count_decreasing_teams(
        self,
        rating: List[int],
        current_index: int,
        team_size: int,
        decreasing_cache: List[List[int]],
    ) -> int:
        n = len(rating)

        # Base case: reached end of array
        if current_index == n:
            return 0

        # Base case: found a valid team of size 3
        if team_size == 3:
            return 1

        # Return cached result if available
        if decreasing_cache[current_index][team_size] != -1:
            return decreasing_cache[current_index][team_size]

        valid_teams = 0

        # Recursively count teams with decreasing ratings
        for next_index in range(current_index + 1, n):
            if rating[next_index] < rating[current_index]:
                valid_teams += self._count_decreasing_teams(
                    rating, next_index, team_size + 1, decreasing_cache
                )

        # Cache and return the result
        decreasing_cache[current_index][team_size] = valid_teams
        return valid_teams
```

</details>

<br>

## Approach 2: Dynamic Programming (Tabulation)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;

        // Tables for increasing and decreasing sequences
        vector<vector<int>> increasingTeams(n, vector<int>(4, 0));
        vector<vector<int>> decreasingTeams(n, vector<int>(4, 0));

        // Fill the base cases. (Each soldier is a sequence of length 1)
        for (int i = 0; i < n; i++) {
            increasingTeams[i][1] = 1;
            decreasingTeams[i][1] = 1;
        }

        // Fill the tables
        for (int count = 2; count <= 3; count++) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (rating[j] > rating[i]) {
                        increasingTeams[j][count] +=
                            increasingTeams[i][count - 1];
                    }
                    if (rating[j] < rating[i]) {
                        decreasingTeams[j][count] +=
                            decreasingTeams[i][count - 1];
                    }
                }
            }
        }

        // Sum up the results (All sequences of length 3)
        for (int i = 0; i < n; i++) {
            teams += increasingTeams[i][3] + decreasingTeams[i][3];
        }

        return teams;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numTeams(int[] rating) {
        int n = rating.length;
        int teams = 0;

        // Tables for increasing and decreasing sequences
        int[][] increasingTeams = new int[n][4];
        int[][] decreasingTeams = new int[n][4];

        // Fill the base cases. (Each soldier is a sequence of length 1)
        for (int i = 0; i < n; i++) {
            increasingTeams[i][1] = 1;
            decreasingTeams[i][1] = 1;
        }

        // Fill the tables
        for (int count = 2; count <= 3; count++) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (rating[j] > rating[i]) {
                        increasingTeams[j][count] +=
                        increasingTeams[i][count - 1];
                    }
                    if (rating[j] < rating[i]) {
                        decreasingTeams[j][count] +=
                        decreasingTeams[i][count - 1];
                    }
                }
            }
        }

        // Sum up the results (All sequences of length 3)
        for (int i = 0; i < n; i++) {
            teams += increasingTeams[i][3] + decreasingTeams[i][3];
        }

        return teams;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        teams = 0

        # Tables for increasing and decreasing sequences
        increasing_teams = [[0] * 4 for _ in range(n)]
        decreasing_teams = [[0] * 4 for _ in range(n)]

        # Fill the base cases. (Each soldier is a sequence of length 1)
        for i in range(n):
            increasing_teams[i][1] = 1
            decreasing_teams[i][1] = 1

        # Fill the tables
        for count in range(2, 4):
            for i in range(n):
                for j in range(i + 1, n):
                    if rating[j] > rating[i]:
                        increasing_teams[j][count] += increasing_teams[i][
                            count - 1
                        ]
                    if rating[j] < rating[i]:
                        decreasing_teams[j][count] += decreasing_teams[i][
                            count - 1
                        ]

        # Sum up the results (All sequences of length 3)
        for i in range(n):
            teams += increasing_teams[i][3] + decreasing_teams[i][3]

        return teams
```

</details>

<br>

## Approach 3: Dynamic Programming (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;

        // Iterate through each soldier as the middle soldier
        for (int mid = 0; mid < n; mid++) {
            int leftSmaller = 0;
            int rightLarger = 0;

            // Count soldiers with smaller ratings on the left side of the
            // current soldier
            for (int left = mid - 1; left >= 0; left--) {
                if (rating[left] < rating[mid]) {
                    leftSmaller++;
                }
            }

            // Count soldiers with larger ratings on the right side of the
            // current soldier
            for (int right = mid + 1; right < n; right++) {
                if (rating[right] > rating[mid]) {
                    rightLarger++;
                }
            }

            // Calculate and add the number of ascending rating teams
            // (small-mid-large)
            teams += leftSmaller * rightLarger;

            // Calculate soldiers with larger ratings on the left and smaller
            // ratings on the right
            int leftLarger = mid - leftSmaller;
            int rightSmaller = n - mid - 1 - rightLarger;

            // Calculate and add the number of descending rating teams
            // (large-mid-small)
            teams += leftLarger * rightSmaller;
        }

        // Return the total number of valid teams
        return teams;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numTeams(int[] rating) {
        int n = rating.length;
        int teams = 0;

        // Iterate through each soldier as the middle soldier
        for (int mid = 0; mid < n; mid++) {
            int leftSmaller = 0;
            int rightLarger = 0;

            // Count soldiers with smaller rating on the left side of the current soldier
            for (int left = mid - 1; left >= 0; left--) {
                if (rating[left] < rating[mid]) {
                    leftSmaller++;
                }
            }

            // Count soldiers with larger ratings on the right side of the current soldier
            for (int right = mid + 1; right < n; right++) {
                if (rating[right] > rating[mid]) {
                    rightLarger++;
                }
            }

            // Calculate and add the number of ascending rating teams (small-mid-large)
            teams += leftSmaller * rightLarger;

            // Calculate soldiers with larger ratings on the left and smaller ratings on the right
            int leftLarger = mid - leftSmaller;
            int rightSmaller = n - mid - 1 - rightLarger;

            // Calculate and add the number of descending rating teams (large-mid-small)
            teams += leftLarger * rightSmaller;
        }

        // Return the total number of valid teams
        return teams;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        teams = 0

        # Iterate through each soldier as the middle soldier
        for mid in range(n):
            left_smaller = 0
            right_larger = 0

            # Count soldiers with smaller ratings on the left side of the current soldier
            for left in range(mid - 1, -1, -1):
                if rating[left] < rating[mid]:
                    left_smaller += 1

            # Count soldiers with larger ratings on the right side of the current soldier
            for right in range(mid + 1, n):
                if rating[right] > rating[mid]:
                    right_larger += 1

            # Calculate and add the number of ascending rating teams (small-mid-large)
            teams += left_smaller * right_larger

            # Calculate soldiers with larger ratings on the left and smaller ratings on the right
            left_larger = mid - left_smaller
            right_smaller = n - mid - 1 - right_larger

            # Calculate and add the number of descending rating teams (large-mid-small)
            teams += left_larger * right_smaller

        # Return the total number of valid teams
        return teams
```

</details>

<br>

## Approach 4: Binary Indexed Tree (Fenwick Tree)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        // Find the maximum rating
        int maxRating = 0;
        for (int r : rating) {
            maxRating = max(maxRating, r);
        }

        // Initialize Binary Indexed Trees for left and right sides
        vector<int> leftBIT(maxRating + 1, 0);
        vector<int> rightBIT(maxRating + 1, 0);

        // Populate the right BIT with all ratings initially
        for (int r : rating) {
            updateBIT(rightBIT, r, 1);
        }

        int teams = 0;
        for (int currentRating : rating) {
            // Remove current rating from right BIT
            updateBIT(rightBIT, currentRating, -1);

            // Count soldiers with smaller and larger ratings on both sides
            int smallerRatingsLeft = getPrefixSum(leftBIT, currentRating - 1);
            int smallerRatingsRight = getPrefixSum(rightBIT, currentRating - 1);
            int largerRatingsLeft = getPrefixSum(leftBIT, maxRating) -
                                    getPrefixSum(leftBIT, currentRating);
            int largerRatingsRight = getPrefixSum(rightBIT, maxRating) -
                                     getPrefixSum(rightBIT, currentRating);

            // Count increasing and decreasing sequences
            teams += (smallerRatingsLeft * largerRatingsRight);
            teams += (largerRatingsLeft * smallerRatingsRight);

            // Add current rating to left BIT
            updateBIT(leftBIT, currentRating, 1);
        }

        return teams;
    }

private:
    // Update the Binary Indexed Tree
    void updateBIT(vector<int>& BIT, int index, int value) {
        while (index < BIT.size()) {
            BIT[index] += value;
            index +=
                index & (-index);  // Move to the next relevant index in BIT
        }
    }

    // Get the sum of all elements up to the given index in the BIT
    int getPrefixSum(vector<int>& BIT, int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & (-index);  // Move to the parent node in BIT
        }
        return sum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numTeams(int[] rating) {
        // Find the maximum rating
        int maxRating = 0;
        for (int r : rating) {
            maxRating = Math.max(maxRating, r);
        }

        // Initialize Binary Indexed Trees for left and right sides
        int[] leftBIT = new int[maxRating + 1];
        int[] rightBIT = new int[maxRating + 1];

        // Populate the right BIT with all ratings initially
        for (int r : rating) {
            updateBIT(rightBIT, r, 1);
        }

        int teams = 0;
        for (int currentRating : rating) {
            // Remove current rating from right BIT
            updateBIT(rightBIT, currentRating, -1);

            // Count soldiers with smaller and larger ratings on both sides
            int smallerRatingsLeft = getPrefixSum(leftBIT, currentRating - 1);
            int smallerRatingsRight = getPrefixSum(rightBIT, currentRating - 1);
            int largerRatingsLeft =
                getPrefixSum(leftBIT, maxRating) -
                getPrefixSum(leftBIT, currentRating);
            int largerRatingsRight =
                getPrefixSum(rightBIT, maxRating) -
                getPrefixSum(rightBIT, currentRating);

            // Count increasing and decreasing sequences
            teams += (smallerRatingsLeft * largerRatingsRight);
            teams += (largerRatingsLeft * smallerRatingsRight);

            // Add current rating to left BIT
            updateBIT(leftBIT, currentRating, 1);
        }

        return teams;
    }

    // Update the Binary Indexed Tree
    private void updateBIT(int[] BIT, int index, int value) {
        while (index < BIT.length) {
            BIT[index] += value;
            index += index & (-index); // Move to the next relevant index in BIT
        }
    }

    // Get the sum of all elements up to the given index in the BIT
    private int getPrefixSum(int[] BIT, int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & (-index); // Move to the parent node in BIT
        }
        return sum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        # Find the maximum rating
        max_rating = 0
        for r in rating:
            max_rating = max(max_rating, r)

        # Initialize Binary Indexed Trees for left and right sides
        left_BIT = [0] * (max_rating + 1)
        right_BIT = [0] * (max_rating + 1)

        # Populate the right BIT with all ratings initially
        for r in rating:
            self._update_BIT(right_BIT, r, 1)

        teams = 0
        for current_rating in rating:
            # Remove current rating from right BIT
            self._update_BIT(right_BIT, current_rating, -1)

            # Count soldiers with smaller and larger ratings on both sides
            smaller_ratings_left = self._get_prefix_sum(
                left_BIT, current_rating - 1
            )
            smaller_ratings_right = self._get_prefix_sum(
                right_BIT, current_rating - 1
            )
            larger_ratings_left = self._get_prefix_sum(
                left_BIT, max_rating
            ) - self._get_prefix_sum(left_BIT, current_rating)
            larger_ratings_right = self._get_prefix_sum(
                right_BIT, max_rating
            ) - self._get_prefix_sum(right_BIT, current_rating)

            # Count increasing and decreasing sequences
            teams += smaller_ratings_left * larger_ratings_right
            teams += larger_ratings_left * smaller_ratings_right

            # Add current rating to left BIT
            self._update_BIT(left_BIT, current_rating, 1)

        return teams

    # Update the Binary Indexed Tree
    def _update_BIT(self, BIT: List[int], index: int, value: int) -> None:
        while index < len(BIT):
            BIT[index] += value
            index += index & (-index)  # Move to the next relevant index in BIT

    # Get the sum of all elements up to the given index in the BIT
    def _get_prefix_sum(self, BIT: List[int], index: int) -> int:
        sum = 0
        while index > 0:
            sum += BIT[index]
            index -= index & (-index)  # Move to the parent node in BIT
        return sum
```

</details>
