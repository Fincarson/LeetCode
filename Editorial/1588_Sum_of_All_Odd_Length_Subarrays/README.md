# 1588. Sum of All Odd Length Subarrays

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)  
`Array` `Math` `Prefix Sum`

**Problem Link:** [LeetCode 1588 - Sum of All Odd Length Subarrays](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)

## Problem

Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

A subarray is a contiguous subsequence of the array.

### Example 1

```text
Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
```

### Example 2

```text
Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
```

### Example 3

```text
Input: arr = [10,11,12]
Output: 66
```

## Constraints

- 1 <= arr.length <= 100
- 1 <= arr[i] <= 1000

Follow up:

Could you solve this problem in O(n) time complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sum of Squares of Special Elements ](https://leetcode.com/problems/sum-of-squares-of-special-elements/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1588. Sum of All Odd Length Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Two Loops | C++, Java, Python3 |
| Check the occurrence of each index | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = int(arr.size()), answer = 0;
        
        for (int left = 0; left < n; ++left) {
            for (int right = left; right < n; ++right) {
                if ((right - left + 1) % 2 == 1) {
                    int currentSum = 0;
                    for (int index = left; index < right + 1; ++index) {
                        currentSum += arr[index];    
                    }
                    answer += currentSum;
                }
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int n = arr.length, answer = 0;

        for (int left = 0; left < n; ++left) {
            for (int right = left; right < n; ++right) {
                if ((right - left + 1) % 2 == 1) {
                    int currentSum = 0;
                    for (int index = left; index < right + 1; ++index) {
                        currentSum += arr[index];
                    }
                    answer += currentSum;
                }
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        answer = 0
        
        for left in range(n):
            for right in range(left, n):
                if (right - left + 1) % 2 == 1:
                    current_sum = 0
                    for index in range(left, right + 1):
                        current_sum += arr[index]
                    answer += current_sum

        return answer
```

</details>

<br>

## Approach 2: Two Loops

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = int(arr.size()), answer = 0;

        
        for (int left = 0; left < n; ++left) {
            int currentSum = 0; 
            for (int right = left; right < n; ++right) {
                currentSum += arr[right];
                answer += (right - left + 1) % 2 == 1 ? currentSum : 0;
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int n = arr.length, answer = 0;

        for (int left = 0; left < n; ++left) {
            int currentSum = 0;  
            for (int right = left; right < n; ++right) {
                currentSum += arr[right];
                answer += (right - left + 1) % 2 == 1 ? currentSum : 0;
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        answer = 0
        
        for left in range(n):
            current_sum = 0
            for right in range(left, n):
                current_sum += arr[right]
                answer += current_sum if (right - left + 1) % 2 == 1 else 0
        return answer
```

</details>

<br>

## Approach 3: Check the occurrence of each index

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = int(arr.size()), answer = 0;
        
        for (int i = 0; i < n; ++i) {
            int left = i, right = n - i - 1;
            answer += arr[i] * (left / 2 + 1) * (right / 2 + 1);
            answer += arr[i] * ((left + 1) / 2) * ((right + 1) / 2);
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int n = arr.length, answer = 0;
        
        for (int i = 0; i < n; ++i) {
            int left = i, right = n - i - 1;
            answer += arr[i] * (left / 2 + 1) * (right / 2 + 1);
            answer += arr[i] * ((left + 1) / 2) * ((right + 1) / 2);
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        answer = 0
        
        for i, a in enumerate(arr):
            left, right = i, n - i - 1
            answer += a * (left // 2 + 1) * (right // 2 + 1)
            answer += a * ((left + 1) // 2) * ((right + 1) // 2)
        return answer
```

</details>
