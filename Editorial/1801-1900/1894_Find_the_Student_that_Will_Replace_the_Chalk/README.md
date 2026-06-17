# 1894. Find the Student that Will Replace the Chalk

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/)  
`Array` `Binary Search` `Simulation` `Prefix Sum`

**Problem Link:** [LeetCode 1894 - Find the Student that Will Replace the Chalk](https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/)

## Problem

There are n students in a class numbered from 0 to n - 1. The teacher will give each student a problem starting with the student number 0, then the student number 1, and so on until the teacher reaches the student number n - 1. After that, the teacher will restart the process, starting with the student number 0 again.

You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.

Return the index of the student that will replace the chalk pieces.

### Example 1

```text
Input: chalk = [5,1,5], k = 22
Output: 0
Explanation: The students go in turns as follows:
- Student number 0 uses 5 chalk, so k = 17.
- Student number 1 uses 1 chalk, so k = 16.
- Student number 2 uses 5 chalk, so k = 11.
- Student number 0 uses 5 chalk, so k = 6.
- Student number 1 uses 1 chalk, so k = 5.
- Student number 2 uses 5 chalk, so k = 0.
Student number 0 does not have enough chalk, so they will have to replace it.
```

### Example 2

```text
Input: chalk = [3,4,1,2], k = 25
Output: 1
Explanation: The students go in turns as follows:
- Student number 0 uses 3 chalk so k = 22.
- Student number 1 uses 4 chalk so k = 18.
- Student number 2 uses 1 chalk so k = 17.
- Student number 3 uses 2 chalk so k = 15.
- Student number 0 uses 3 chalk so k = 12.
- Student number 1 uses 4 chalk so k = 8.
- Student number 2 uses 1 chalk so k = 7.
- Student number 3 uses 2 chalk so k = 5.
- Student number 0 uses 3 chalk so k = 2.
Student number 1 does not have enough chalk, so they will have to replace it.
```

## Constraints

- chalk.length == n
- 1 <= n <= 105
- 1 <= chalk[i] <= 105
- 1 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Pass the Pillow](https://leetcode.com/problems/pass-the-pillow/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1894. Find the Student that Will Replace the Chalk

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sum | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Find the sum of all elements.
        int sum = 0;
        for (int i = 0; i < chalk.size(); i++) {
            sum += chalk[i];
            if (sum > k) {
                break;
            }
        }
        // Find modulo of k with sum.
        k = k % sum;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k = k - chalk[i];
        }
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int chalkReplacer(int[] chalk, int k) {
        // Find the sum of all elements.
        long sum = 0;
        for (int i = 0; i < chalk.length; i++) {
            sum += chalk[i];
            if (sum > k) {
                break;
            }
        }
        // Find modulo of k with sum.
        k = k % (int) sum;
        for (int i = 0; i < chalk.length; i++) {
            if (k < chalk[i]) {
                return i;
            }
            k = k - chalk[i];
        }
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        # Find the sum of all elements.
        sum_chalk = 0
        for i in range(len(chalk)):
            sum_chalk += chalk[i]
            if sum_chalk > k:
                break
        # Find modulo of k with sum.
        k = k % sum_chalk
        for i in range(len(chalk)):
            if k < chalk[i]:
                return i
            k -= chalk[i]
        return 0
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        vector<long> prefixSum(n);
        prefixSum[0] = chalk[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + chalk[i];
        }

        long sum = prefixSum[n - 1];
        long remainingChalk = (k % sum);

        return binarySearch(prefixSum, remainingChalk);
    }

private:
    int binarySearch(vector<long>& arr, long tar) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= tar) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return high;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int chalkReplacer(int[] chalk, int k) {
        int n = chalk.length;

        long[] prefixSum = new long[n];
        prefixSum[0] = chalk[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + chalk[i];
        }

        long sum = prefixSum[n - 1];
        long remainingChalk = (k % sum);

        return binarySearch(prefixSum, remainingChalk);
    }

    private int binarySearch(long[] arr, long tar) {
        int low = 0, high = arr.length - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= tar) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return high;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        n = len(chalk)

        prefix_sum = [0] * n
        prefix_sum[0] = chalk[0]
        for i in range(1, n):
            prefix_sum[i] = prefix_sum[i - 1] + chalk[i]

        sum_chalk = prefix_sum[n - 1]
        remaining_chalk = k % sum_chalk

        return self.__binary_search(prefix_sum, remaining_chalk)

    def __binary_search(self, arr, tar):
        low = 0
        high = len(arr) - 1

        while low < high:
            mid = low + (high - low) // 2

            if arr[mid] <= tar:
                low = mid + 1
            else:
                high = mid

        return high
```

</details>
