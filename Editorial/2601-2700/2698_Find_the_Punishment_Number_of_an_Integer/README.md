# 2698. Find the Punishment Number of an Integer

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-punishment-number-of-an-integer/)  
`Math` `Backtracking`

**Problem Link:** [LeetCode 2698 - Find the Punishment Number of an Integer](https://leetcode.com/problems/find-the-punishment-number-of-an-integer/)

## Problem

Given a positive integer n, return the punishment number of n.

The punishment number of n is defined as the sum of the squares of all integers i such that:

- 1 <= i <= n
- The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.

### Example 1

```text
Input: n = 10
Output: 182
Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
Hence, the punishment number of 10 is 1 + 81 + 100 = 182
```

### Example 2

```text
Input: n = 37
Output: 1478
Explanation: There are exactly 4 integers i in the range [1, 37] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1.
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0.
- 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478
```

## Constraints

- 1 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Great Partitions](https://leetcode.com/problems/number-of-great-partitions/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2698. Find the Punishment Number of an Integer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Memoization | C++, Java, Python3 |
| Recursion of Strings | C++, Java, Python3 |
| Recursion of Integers | C++, Java, Python3 |

## Approach 1: Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool findPartitions(int startIndex, int sum, string stringNum, int target,
                        vector<vector<int>>& memo) {
        // Check if partition is valid
        if (startIndex == stringNum.size()) {
            return sum == target;
        }

        // Invalid partition found, so we return false
        if (sum > target) return false;

        // If the result for this state is already calculated, return it
        if (memo[startIndex][sum] != -1) return memo[startIndex][sum];

        bool partitionFound = false;

        // Iterate through all possible substrings starting with startIdx
        for (int currentIndex = startIndex; currentIndex < stringNum.size();
             currentIndex++) {
            // Create partition
            string currentString =
                stringNum.substr(startIndex, currentIndex - startIndex + 1);
            int addend = stoi(currentString);

            // Recursively check if valid partition can be found
            partitionFound =
                partitionFound || findPartitions(currentIndex + 1, sum + addend,
                                                 stringNum, target, memo);
            if (partitionFound == true) return true;
        }

        // Memoize the result for future reference and return its result
        return memo[startIndex][sum] = partitionFound;
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;
        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            string stringNum = to_string(squareNum);

            // Initialize values in memoization array
            vector<vector<int>> memoArray(stringNum.size(),
                                          vector<int>(currentNum + 1, -1));

            // Check if valid partition can be found and add squared number if
            // so
            if (findPartitions(0, 0, stringNum, currentNum, memoArray)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean findPartitions(
        int startIndex,
        int sum,
        String stringNum,
        int target,
        int[][] memo
    ) {
        // Check if partition is valid
        if (startIndex == stringNum.length()) {
            return sum == target;
        }

        // Invalid partition found, so we return false
        if (sum > target) return false;

        // If the result for this state is already calculated, return it
        if (memo[startIndex][sum] != -1) return memo[startIndex][sum] == 1;

        boolean partitionFound = false;

        // Iterate through all possible substrings starting with startIndex
        for (
            int currentIndex = startIndex;
            currentIndex < stringNum.length();
            currentIndex++
        ) {
            // Create partition
            String currentString = stringNum.substring(
                startIndex,
                currentIndex + 1
            );
            int addend = Integer.parseInt(currentString);

            // Recursively check if valid partition can be found
            partitionFound =
                partitionFound ||
                findPartitions(
                    currentIndex + 1,
                    sum + addend,
                    stringNum,
                    target,
                    memo
                );
            if (partitionFound) {
                memo[startIndex][sum] = 1;
                return true;
            }
        }

        // Memoize the result for future reference and return its result
        memo[startIndex][sum] = 0;
        return false;
    }

    public int punishmentNumber(int n) {
        int punishmentNum = 0;
        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            String stringNum = Integer.toString(squareNum);

            // Initialize values in memoization array
            int[][] memoArray = new int[stringNum.length()][currentNum + 1];
            for (int[] row : memoArray) {
                java.util.Arrays.fill(row, -1);
            }

            // Check if valid partition can be found and add squared number if so
            if (findPartitions(0, 0, stringNum, currentNum, memoArray)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def find_partitions(
        self, start_index, current_sum, string_num, target, memo
    ):
        # Check if partition is valid
        if start_index == len(string_num):
            return current_sum == target

        # Invalid partition found, so we return False
        if current_sum > target:
            return False

        # If the result for this state is already calculated, return it
        if memo[start_index][current_sum] != -1:
            return memo[start_index][current_sum] == 1

        partition_found = False

        # Iterate through all possible substrings starting with start_index
        for current_index in range(start_index, len(string_num)):
            # Create partition
            current_string = string_num[start_index : current_index + 1]
            addend = int(current_string)

            # Recursively check if valid partition can be found
            partition_found = partition_found or self.find_partitions(
                current_index + 1,
                current_sum + addend,
                string_num,
                target,
                memo,
            )
            if partition_found:
                memo[start_index][current_sum] = 1
                return True

        # Memoize the result for future reference and return its result
        memo[start_index][current_sum] = 0
        return False

    def punishmentNumber(self, n: int) -> int:
        punishment_num = 0
        # Iterate through numbers in range [1, n]
        for current_num in range(1, n + 1):
            square_num = current_num * current_num
            string_num = str(square_num)

            # Initialize values in memoization array
            memo_array = [
                [-1] * (current_num + 1) for _ in range(len(string_num))
            ]

            # Check if valid partition can be found and add squared number if so
            if self.find_partitions(0, 0, string_num, current_num, memo_array):
                punishment_num += square_num

        return punishment_num
```

</details>

<br>

## Approach 2: Recursion of Strings

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPartition(string stringNum, int target) {
        // Valid Partition Found
        if (stringNum == "" && target == 0) return true;

        // Invalid Partition Found
        if (target < 0) return false;

        // Recursively check all partitions for a valid partition
        for (int index = 0; index < stringNum.size(); index++) {
            string left = stringNum.substr(0, index + 1);
            string right = stringNum.substr(index + 1);
            int leftNum = stoi(left);

            if (canPartition(right, target - leftNum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;

        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;

            // Check if valid partition can be found and add squared number if
            // so
            if (canPartition(to_string(squareNum), currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canPartition(String stringNum, int target) {
        // Valid Partition Found
        if (stringNum.isEmpty() && target == 0) {
            return true;
        }

        // Invalid Partition Found
        if (target < 0) {
            return false;
        }

        // Recursively check all partitions for a valid partition
        for (int index = 0; index < stringNum.length(); index++) {
            String left = stringNum.substring(0, index + 1);
            String right = stringNum.substring(index + 1);
            int leftNum = Integer.parseInt(left);

            if (canPartition(right, target - leftNum)) {
                return true;
            }
        }
        return false;
    }

    public int punishmentNumber(int n) {
        int punishmentNum = 0;

        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;

            // Check if valid partition can be found and add squared number if so
            if (canPartition(Integer.toString(squareNum), currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def can_partition(self, string_num, target):
        # Valid Partition Found
        if not string_num and target == 0:
            return True

        # Invalid Partition Found
        if target < 0:
            return False

        # Recursively check all partitions for a valid partition
        for index in range(len(string_num)):
            left = string_num[: index + 1]
            right = string_num[index + 1 :]
            left_num = int(left)

            if self.can_partition(right, target - left_num):
                return True

        return False

    def punishmentNumber(self, n: int) -> int:
        punishment_num = 0

        # Iterate through numbers in range [1, n]
        for current_num in range(1, n + 1):
            square_num = current_num * current_num

            # Check if valid partition can be found and add squared number if so
            if self.can_partition(str(square_num), current_num):
                punishment_num += square_num

        return punishment_num
```

</details>

<br>

## Approach 3: Recursion of Integers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool CanPartition(int num, int target) {
        // Invalid partition found
        if (target < 0 || num < target) {
            return false;
        }

        // Valid partition found
        if (num == target) {
            return true;
        }

        // Recursively check all partitions for a valid partition
        return CanPartition(num / 10, target - num % 10) ||
               CanPartition(num / 100, target - num % 100) ||
               CanPartition(num / 1000, target - num % 1000);
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;

        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;

            // Check if valid partition can be found and add squared number if
            // so
            if (CanPartition(squareNum, currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canPartition(int num, int target) {
        // Invalid partition found
        if (target < 0 || num < target) {
            return false;
        }

        // Valid partition found
        if (num == target) {
            return true;
        }

        // Recursively check all partitions for a valid partition
        return (
            canPartition(num / 10, target - (num % 10)) ||
            canPartition(num / 100, target - (num % 100)) ||
            canPartition(num / 1000, target - (num % 1000))
        );
    }

    public int punishmentNumber(int n) {
        int punishmentNum = 0;

        // Iterate through numbers in range [1, n]
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;

            // Check if valid partition can be found and add squared number if so
            if (canPartition(squareNum, currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def can_partition(self, num, target):
        # Invalid partition found
        if target < 0 or num < target:
            return False

        # Valid partition found
        if num == target:
            return True

        # Recursively check all partitions for a valid partition
        return (
            self.can_partition(num // 10, target - num % 10)
            or self.can_partition(num // 100, target - num % 100)
            or self.can_partition(num // 1000, target - num % 1000)
        )

    def punishmentNumber(self, n: int) -> int:
        punishment_num = 0

        # Iterate through numbers in range [1, n]
        for current_num in range(1, n + 1):
            square_num = current_num * current_num

            # Check if valid partition can be found and add squared number if so
            if self.can_partition(square_num, current_num):
                punishment_num += square_num

        return punishment_num
```

</details>
