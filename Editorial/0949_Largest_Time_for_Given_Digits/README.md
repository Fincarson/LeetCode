# 949. Largest Time for Given Digits

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/largest-time-for-given-digits/)  
`Array` `String` `Backtracking` `Enumeration`

**Problem Link:** [LeetCode 949 - Largest Time for Given Digits](https://leetcode.com/problems/largest-time-for-given-digits/)

## Problem

Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.

24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.

Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.

### Example 1

```text
Input: arr = [1,2,3,4]
Output: "23:41"
Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.
```

### Example 2

```text
Input: arr = [5,5,5,5]
Output: ""
Explanation: There are no valid 24-hour times as "55:55" is not valid.
```

## Constraints

- arr.length == 4
- 0 <= arr[i] <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Valid Clock Times](https://leetcode.com/problems/number-of-valid-clock-times/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 949. Largest Time for Given Digits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumerate the Permutations | C++, Python3 |
| Permutation via Enumeration | Java, Python3 |
| Permutation via Backtracking | Java, Python3 |

## Approach 1: Enumerate the Permutations

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {

        int max_time = -1;
        // prepare for the generation of permutations next.
        std::sort(A.begin(), A.end());

        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];

            if (hour < 24 && minute < 60) {
                int new_time = hour * 60 + minute;
                max_time = new_time > max_time ? new_time : max_time;
            }
        } while(next_permutation(A.begin(), A.end()));

        if (max_time == -1) {
            return "";
        } else {
            std::ostringstream strstream;
            strstream << std::setw(2) << std::setfill('0') << max_time / 60
               << ":" << std::setw(2) << std::setfill('0') << max_time % 60;
            return strstream.str();
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        
        max_time = -1
        # enumerate all possibilities, with the permutation() func
        for h, i, j, k in itertools.permutations(A):
            hour = h*10 + i
            minute = j*10 + k
            if hour < 24 and minute < 60:
                max_time = max(max_time, hour * 60 + minute)
        
        if max_time == -1:
            return ""
        else:
            return "{:02d}:{:02d}".format(max_time // 60, max_time % 60)
```

</details>

<br>

## Approach 2: Permutation via Enumeration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int max_time = -1;

    public String largestTimeFromDigits(int[] A) {
        this.max_time = -1;

        for (int i1 = 0; i1 < A.length; ++i1)
            for (int i2 = 0; i2 < A.length; ++i2)
                for (int i3 = 0; i3 < A.length; ++i3) {
                    // skip duplicate elements
                    if (i1 == i2 || i2 == i3 || i1 == i3)
                        continue;
                    // the total sum of indices is 0 + 1 + 2 + 3 = 6.
                    int i4 = 6 - i1 - i2 - i3;
                    int [] perm = {A[i1], A[i2], A[i3], A[i4]};
                    // check if the permutation can form a time
                    validateTime(perm);
                }
        if (this.max_time == -1)
            return "";
        else
            return String.format("%02d:%02d", max_time / 60, max_time % 60);
    }

    protected void validateTime(int[] perm) {
        int hour = perm[0] * 10 + perm[1];
        int minute = perm[2] * 10 + perm[3];
        if (hour < 24 && minute < 60)
            this.max_time = Math.max(this.max_time, hour*60 + minute);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:

        max_time = -1
        for i1, D1 in enumerate(A):
            for i2, D2 in enumerate(A):
                for i3, D3 in enumerate(A):
                    if i1 == i2 or i2 == i3 or i1 == i3:
                        # skip duplicate elements
                        continue
                    # the total sum of indices is 0 + 1 + 2 + 3 = 6.
                    i4 = 6 - i1 - i2 - i3
                    D4 = A[i4]

                    # check if the permutation can form a time
                    hour = D1*10 + D2
                    minute = D3*10 + D4
                    if hour < 24 and minute < 60:
                        max_time = max(max_time, hour * 60 + minute)

        if max_time == -1:
            return ""
        else:
            return "{:02d}:{:02d}".format(max_time // 60, max_time % 60)
```

</details>

<br>

## Approach 3: Permutation via Backtracking

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int max_time = -1;

    public String largestTimeFromDigits(int[] A) {
        this.max_time = -1;
        permutate(A, 0);
        if (this.max_time == -1)
            return "";
        else
            return String.format("%02d:%02d", max_time / 60, max_time % 60);
    }

    protected void permutate(int[] array, int start) {
        if (start == array.length) {
            this.build_time(array);
            return;
        }
        for (int i = start; i < array.length; ++i) {
            this.swap(array, i, start);
            this.permutate(array, start + 1);
            this.swap(array, i, start);
        }
    }

    protected void build_time(int[] perm) {
        int hour = perm[0] * 10 + perm[1];
        int minute = perm[2] * 10 + perm[3];
        if (hour < 24 && minute < 60)
            this.max_time = Math.max(this.max_time, hour * 60 + minute);
    }

    protected void swap(int[] array, int i, int j) {
        if (i != j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:

        max_time = -1

        def build_time(permutation):
            nonlocal max_time

            h, i, j, k = permutation
            hour = h*10 + i
            minute = j*10 + k
            if hour < 24 and minute < 60:
                max_time = max(max_time, hour * 60 + minute)

        def swap(array, i, j):
            if i != j:
                array[i], array[j] = array[j], array[i]

        def permutate(array, start):
            if start == len(array):
                build_time(array)
                return

            for index in range(start, len(array)):
                swap(array, index, start)
                # repeat the permutation with the original array mutated
                permutate(array, start+1)
                swap(array, index, start)

        permutate(A, 0)
        if max_time == -1:
            return ""
        else:
            return "{:02d}:{:02d}".format(max_time // 60, max_time % 60)
```

</details>
