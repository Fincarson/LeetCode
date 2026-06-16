# 2554. Maximum Number of Integers to Choose From a Range I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/)  
`Array` `Hash Table` `Binary Search` `Greedy` `Sorting`

**Problem Link:** [LeetCode 2554 - Maximum Number of Integers to Choose From a Range I](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/)

## Problem

You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

- The chosen integers have to be in the range [1, n].
- Each integer can be chosen at most once.
- The chosen integers should not be in the array banned.
- The sum of the chosen integers should not exceed maxSum.

Return the maximum number of integers you can choose following the mentioned rules.

### Example 1

```text
Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
```

### Example 2

```text
Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned conditions.
```

### Example 3

```text
Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.
```

## Constraints

- 1 <= banned.length <= 104
- 1 <= banned[i], n <= 104
- 1 <= maxSum <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Append K Integers With Minimal Sum](https://leetcode.com/problems/append-k-integers-with-minimal-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Replace Elements in an Array](https://leetcode.com/problems/replace-elements-in-an-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Integers to Choose From a Range II](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2554. Maximum Number of Integers to Choose From a Range I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Sweep | C++, Java, Python3 |
| Hash Set | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Sort banned array to enable binary search
        sort(banned.begin(), banned.end());

        int count = 0;

        // Try each number from 1 to n
        for (int num = 1; num <= n; num++) {
            // Skip if number is in banned array
            if (customBinarySearch(banned, num)) continue;

            maxSum -= num;

            // Break if sum exceeds our limit
            if (maxSum < 0) break;

            count++;
        }
        return count;
    }

private:
    // Helper method to check if value exists in sorted array
    bool customBinarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) return true;

            if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxCount(int[] banned, int n, int maxSum) {
        // Sort banned array to enable binary search
        Arrays.sort(banned);

        int count = 0;

        // Try each number from 1 to n
        for (int num = 1; num <= n; num++) {
            // Skip if number is in banned array
            if (customBinarySearch(banned, num)) continue;

            maxSum -= num;

            // Break if sum exceeds our limit
            if (maxSum < 0) break;

            count++;
        }
        return count;
    }

    // Helper method to check if value exists in sorted array
    private boolean customBinarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) return true;

            if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        # Sort banned array to enable binary search
        banned.sort()
        count = 0

        # Try each number from 1 to n
        for num in range(1, n + 1):
            # Skip if number is in banned array
            if self._custom_binary_search(banned, num):
                continue

            maxSum -= num
            # Break if sum exceeds our limit
            if maxSum < 0:
                break

            count += 1

        return count

    def _custom_binary_search(self, arr: List[int], target: int) -> bool:
        left, right = 0, len(arr) - 1

        while left <= right:
            mid = (left + right) // 2
            if arr[mid] == target:
                return True
            if arr[mid] > target:
                right = mid - 1
            else:
                left = mid + 1

        return False
```

</details>

<br>

## Approach 2: Sweep

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());

        int bannedIdx = 0, count = 0;

        // Check each number from 1 to n while sum is valid
        for (int num = 1; num <= n && maxSum >= 0; num++) {
            // Skip if current number is in banned array
            if (bannedIdx < banned.size() && banned[bannedIdx] == num) {
                // Handle duplicate banned numbers
                while (bannedIdx < banned.size() && banned[bannedIdx] == num) {
                    bannedIdx++;
                }
            } else {
                // Include current number if possible
                maxSum -= num;
                if (maxSum >= 0) {
                    count++;
                }
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxCount(int[] banned, int n, int maxSum) {
        Arrays.sort(banned);

        int bannedIdx = 0, count = 0;

        // Check each number from 1 to n while sum is valid
        for (int num = 1; num <= n && maxSum >= 0; num++) {
            // Skip if current number is in banned array
            if (bannedIdx < banned.length && banned[bannedIdx] == num) {
                // Handle duplicate banned numbers
                while (bannedIdx < banned.length && banned[bannedIdx] == num) {
                    bannedIdx++;
                }
            } else {
                // Include current number if possible
                maxSum -= num;
                if (maxSum >= 0) {
                    count++;
                }
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxCount(self, banned: list[int], n: int, maxSum: int) -> int:
        # Sort the banned list
        banned.sort()

        banned_idx = 0
        count = 0

        # Check each number from 1 to n while the sum is valid
        for num in range(1, n + 1):
            # Skip if the current number is in the banned list
            if banned_idx < len(banned) and banned[banned_idx] == num:
                # Handle duplicate banned numbers
                while banned_idx < len(banned) and banned[banned_idx] == num:
                    banned_idx += 1
            else:
                # Include the current number if possible
                maxSum -= num
                if maxSum >= 0:
                    count += 1
                else:
                    break

        return count
```

</details>

<br>

## Approach 3: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Store banned numbers in an unordered_set
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        int count = 0;

        // Try each number from 1 to n
        for (int num = 1; num <= n; num++) {
            // Skip banned numbers
            if (bannedSet.count(num)) continue;

            // Return if adding current number exceeds maxSum
            if (maxSum - num < 0) return count;

            // Include current number
            maxSum -= num;
            count++;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxCount(int[] banned, int n, int maxSum) {
        // Store banned numbers in HashSet
        Set<Integer> bannedSet = new HashSet<>();
        for (int num : banned) {
            bannedSet.add(num);
        }

        // Track count of valid numbers we can choose
        int count = 0;

        // Try each number from 1 to n
        for (int num = 1; num <= n; num++) {
            // Skip banned numbers
            if (bannedSet.contains(num)) continue;

            // Return if adding current number exceeds maxSum
            if (maxSum - num < 0) return count;

            // Include current number
            maxSum -= num;
            count++;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxCount(self, banned: list[int], n: int, maxSum: int) -> int:
        # Store banned numbers in a set for quick lookup
        banned_set = set(banned)

        count = 0

        # Try each number from 1 to n
        for num in range(1, n + 1):
            # Skip banned numbers
            if num in banned_set:
                continue

            # Return if adding the current number exceeds maxSum
            if maxSum - num < 0:
                return count

            # Include current number
            maxSum -= num
            count += 1

        return count
```

</details>
