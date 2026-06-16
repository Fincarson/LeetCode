# 526. Beautiful Arrangement

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/beautiful-arrangement/)  
`Array` `Dynamic Programming` `Backtracking` `Bit Manipulation` `Bitmask`

**Problem Link:** [LeetCode 526 - Beautiful Arrangement](https://leetcode.com/problems/beautiful-arrangement/)

## Problem

Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

- perm[i] is divisible by i.
- i is divisible by perm[i].

Given an integer n, return the number of the beautiful arrangements that you can construct.

### Example 1

```text
Input: n = 2
Output: 2
Explanation:
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
```

### Example 2

```text
Input: n = 1
Output: 1
```

## Constraints

- 1 <= n <= 15

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Beautiful Arrangement II](https://leetcode.com/problems/beautiful-arrangement-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 526. Beautiful Arrangement

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | C++, Java, Python3 |
| Approach #2 Better Brute Force [Accepted] | C++, Java, Python3 |
| Approach #3 Backtracking [Accepted] | C++, Java, Python3 |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countArrangement(int N) {
        count = 0;
        vector<int> nums(N);
        for (int i = 1; i <= N; i++) nums[i - 1] = i;
        permute(nums, 0);
        return count;
    }

private:
    int count;

    void permute(vector<int>& nums, int l) {
        if (l == nums.size() - 1) {
            int i;
            for (i = 1; i <= nums.size(); i++) {
                if (nums[i - 1] % i != 0 && i % nums[i - 1] != 0) break;
            }
            if (i == nums.size() + 1) {
                count++;
            }
        }
        for (int i = l; i < nums.size(); i++) {
            swap(nums[i], nums[l]);
            permute(nums, l + 1);
            swap(nums[i], nums[l]);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    int count = 0;

    public int countArrangement(int N) {
        int[] nums = new int[N];
        for (int i = 1; i <= N; i++) nums[i - 1] = i;
        permute(nums, 0);
        return count;
    }

    public void permute(int[] nums, int l) {
        if (l == nums.length - 1) {
            int i;
            for (i = 1; i <= nums.length; i++) {
                if (nums[i - 1] % i != 0 && i % nums[i - 1] != 0) break;
            }
            if (i == nums.length + 1) {
                count++;
            }
        }
        for (int i = l; i < nums.length; i++) {
            swap(nums, i, l);
            permute(nums, l + 1);
            swap(nums, i, l);
        }
    }

    public void swap(int[] nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.count = 0

    def countArrangement(self, N: int) -> int:
        nums = [i for i in range(1, N + 1)]
        self.permute(nums, 0)
        return self.count

    def permute(self, nums, l):
        if l == len(nums) - 1:
            for i in range(1, len(nums) + 1):
                if nums[i - 1] % i != 0 and i % nums[i - 1] != 0:
                    break
            else:
                self.count += 1
        for i in range(l, len(nums)):
            nums[i], nums[l] = nums[l], nums[i]
            self.permute(nums, l + 1)
            nums[i], nums[l] = nums[l], nums[i]
```

</details>

<br>

## Approach #2 Better Brute Force [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int count = 0;

public:
    int countArrangement(int N) {
        vector<int> nums(N);
        for (int i = 1; i <= N; i++) nums[i - 1] = i;
        permute(nums, 0);
        return count;
    }
    void permute(vector<int>& nums, int l) {
        if (l == nums.size()) {
            count++;
        }
        for (int i = l; i < nums.size(); i++) {
            swap(nums, i, l);
            if (nums[l] % (l + 1) == 0 || (l + 1) % nums[l] == 0)
                permute(nums, l + 1);
            swap(nums, i, l);
        }
    }
    void swap(vector<int>& nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    int count = 0;

    public int countArrangement(int N) {
        int[] nums = new int[N];
        for (int i = 1; i <= N; i++) nums[i - 1] = i;
        permute(nums, 0);
        return count;
    }

    public void permute(int[] nums, int l) {
        if (l == nums.length) {
            count++;
        }
        for (int i = l; i < nums.length; i++) {
            swap(nums, i, l);
            if (nums[l] % (l + 1) == 0 || (l + 1) % nums[l] == 0) permute(
                nums,
                l + 1
            );
            swap(nums, i, l);
        }
    }

    public void swap(int[] nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        self.count = 0
        nums = [i + 1 for i in range(N)]
        self.permute(nums, 0)
        return self.count

    def permute(self, nums, l):
        if l == len(nums):
            self.count += 1
        for i in range(l, len(nums)):
            nums[i], nums[l] = nums[l], nums[i]
            if nums[l] % (l + 1) == 0 or (l + 1) % nums[l] == 0:
                self.permute(nums, l + 1)
            nums[i], nums[l] = nums[l], nums[i]
```

</details>

<br>

## Approach #3 Backtracking [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countArrangement(int N) {
        vector<bool> visited(N + 1, false);
        calculate(N, 1, visited);
        return count;
    }

private:
    int count = 0;
    void calculate(int N, int pos, vector<bool>& visited) {
        if (pos > N)
            count++;
        else
            for (int i = 1; i <= N; ++i)
                if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                    visited[i] = true;
                    calculate(N, pos + 1, visited);
                    visited[i] = false;
                }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    int count = 0;

    public int countArrangement(int N) {
        boolean[] visited = new boolean[N + 1];
        calculate(N, 1, visited);
        return count;
    }

    public void calculate(int N, int pos, boolean[] visited) {
        if (pos > N) {
            count++;
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
                calculate(N, pos + 1, visited);
                visited[i] = false;
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
    def __init__(self):
        self.count = 0

    def countArrangement(self, N):
        visited = [False] * (N + 1)
        self.calculate(N, 1, visited)
        return self.count

    def calculate(self, N, pos, visited):
        if pos > N:
            self.count += 1
            return
        for i in range(1, N + 1):
            if not visited[i] and (pos % i == 0 or i % pos == 0):
                visited[i] = True
                self.calculate(N, pos + 1, visited)
                visited[i] = False
```

</details>
