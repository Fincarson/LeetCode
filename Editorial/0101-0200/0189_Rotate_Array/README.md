# 189. Rotate Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/rotate-array/)  
`Array` `Math` `Two Pointers`

**Problem Link:** [LeetCode 189 - Rotate Array](https://leetcode.com/problems/rotate-array/)

## Problem

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

### Example 1

```text
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

### Example 2

```text
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

## Constraints

- 1 <= nums.length <= 105
- -231 <= nums[i] <= 231 - 1
- 0 <= k <= 105

Follow up:

- Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
- Could you do it in-place with O(1) extra space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rotate List](https://leetcode.com/problems/rotate-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Make K-Subarray Sums Equal](https://leetcode.com/problems/make-k-subarray-sums-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Matching Indices After Right Shifts](https://leetcode.com/problems/maximum-number-of-matching-indices-after-right-shifts/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 189. Rotate Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Using Extra Array | C++, Java, Python3 |
| Using Cyclic Replacements | C++, Java, Python3 |
| Using Reverse | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // speed up the rotation
        k %= nums.size();
        int temp, previous;
        for (int i = 0; i < k; i++) {
            previous = nums[nums.size() - 1];
            for (int j = 0; j < nums.size(); j++) {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void rotate(int[] nums, int k) {
        // speed up the rotation
        k %= nums.length;
        int temp, previous;
        for (int i = 0; i < k; i++) {
            previous = nums[nums.length - 1];
            for (int j = 0; j < nums.length; j++) {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
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
    def rotate(self, nums: List[int], k: int) -> None:
        # speed up the rotation
        k %= len(nums)

        for i in range(k):
            previous = nums[-1]
            for j in range(len(nums)):
                nums[j], previous = previous, nums[j]
```

</details>

<br>

## Approach 2: Using Extra Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[(i + k) % n] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = a[i];
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void rotate(int[] nums, int k) {
        int[] a = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            a[(i + k) % nums.length] = nums[i];
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = a[i];
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        a = [0] * n
        for i in range(n):
            a[(i + k) % n] = nums[i]

        nums[:] = a
```

</details>

<br>

## Approach 3: Using Cyclic Replacements

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        int start = 0, count = 0;
        while (count < size) {
            int current = start, prev = nums[start];
            do {
                int next = (current + k) % size;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
            start++;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        int count = 0;
        for (int start = 0; count < nums.length; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.length;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n

        start = count = 0
        while count < n:
            current, prev = start, nums[start]
            while True:
                next_idx = (current + k) % n
                nums[next_idx], prev = prev, nums[next_idx]
                current = next_idx
                count += 1

                if start == current:
                    break
            start += 1
```

</details>

<br>

## Approach 4: Using Reverse

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }

    public void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverse(self, nums: list, start: int, end: int) -> None:
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start, end = start + 1, end - 1

    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n

        self.reverse(nums, 0, n - 1)
        self.reverse(nums, 0, k - 1)
        self.reverse(nums, k, n - 1)
```

</details>
