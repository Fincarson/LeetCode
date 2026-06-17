# 2864. Maximum Odd Binary Number

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-odd-binary-number/)  
`Math` `String` `Greedy`

**Problem Link:** [LeetCode 2864 - Maximum Odd Binary Number](https://leetcode.com/problems/maximum-odd-binary-number/)

## Problem

You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.

### Example 1

```text
Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".
```

### Example 2

```text
Input: s = "0101"
Output: "1001"
Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
```

## Constraints

- 1 <= s.length <= 100
- s consists only of '0' and '1'.
- s contains at least one '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2864. Maximum Odd Binary Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy Bit Manipulation (Sorting and Swapping) | C++, Java, Python3 |
| Greedy Bit Manipulation (Counting Ones) | C++, Java, Python3 |
| Greedy Bit Manipulation (One Pass with Two Pointers) | C++, Java, Python3 |

## Approach 1: Greedy Bit Manipulation (Sorting and Swapping)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        //create char array
        const int N = s.length(); 
        char* arr = new char[N + 1]; 
        strcpy(arr, s.c_str()); 

        sort(arr, arr+N);

        // Reverse order for the first N - 1 elements of the array
        // Because we want to keep a 1 at the last index
        // The last element of the array is index N - 1, and the second to last is at N - 2
        int secondLast = N - 2;
        for (int i = 0; i < N / 2; i++) {
            char temp = arr[i];
            arr[i] = arr[secondLast - i];
            arr[secondLast - i] = temp;
        }

        // Return result
        return arr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String maximumOddBinaryNumber(String s) {
        char[] arr = s.toCharArray();
        int N = arr.length;
        
        Arrays.sort(arr);

        // Reverse order for the first N - 1 elements of the array
        // Because we want to keep a 1 at the last index
        // The last element of the array is index N - 1, and the second to last element is at N - 2
        int secondLast = N - 2;
        for (int i = 0; i < N / 2; i++) {
            char temp = arr[i];
            arr[i] = arr[secondLast - i];
            arr[secondLast - i] = temp;
        }

        // Return result
        return new String(arr);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:

        arr = sorted(s)

        # Reverse order for the first N - 1 elements of the array
        # Because we want to keep a 1 at the last index
        # The last element of the array is index N - 1, the second the last is at N - 2
        secondLast = len(arr) - 2
        for i in range(len(arr) // 2):
            arr[i], arr[secondLast - i] = arr[secondLast - i], arr[i]

        # Return result
        return "".join(arr)
```

</details>

<br>

## Approach 2: Greedy Bit Manipulation (Counting Ones)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        const int N = s.length(); 

        // Find ones_cnt
        int ones_cnt = 0;
        for (char& c: s) {
            ones_cnt += c - '0';
        }

        string result = "";
        for (int i = 0; i < ones_cnt - 1; i++) {
            result += "1";
        }
        for (int i = 0; i < N - ones_cnt; i++) {
            result += "0";
        }
        result += "1";
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String maximumOddBinaryNumber(String s) {
        int N = s.length();
        
        // Find ones_cnt
        int ones_cnt = 0;
        for (int i = 0; i < N; i++) {
            ones_cnt += s.charAt(i) - '0';
        }

        // Use StringBuilder for fast concatenation
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < ones_cnt - 1; i++) {
            sb.append("1");
        }
        for (int i = 0; i < N - ones_cnt; i++) {
            sb.append("0");
        }
        sb.append("1");

        // Return result
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        # Get n and ones_cnt
        n = len(s)
        ones_cnt = s.count('1')

        # Construct the resulting string
        return '1' * (ones_cnt - 1) + '0' * (n - ones_cnt) + '1'
```

</details>

<br>

## Approach 3: Greedy Bit Manipulation (One Pass with Two Pointers)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // Create char array
        const int N = s.length(); 
        char* arr = new char[N + 1]; 
        strcpy(arr, s.c_str()); 

        // Initialize two pointers
        int left = 0;
        int right = N -  1;

        while(left <= right) {
            
            // Increment left if equals 1
            if (arr[left] == '1') {
                left++;
            }
            // Decrement right if equals 0
            if (arr[right] == '0') {
                right--;
            }
            // Swap if neither pointer can be iterated
            if (left <= right && arr[left] == '0' && arr[right] == '1') {
                arr[left] = '1';
                arr[right] = '0';
            }
        }

        // Swap rightmost 1 bit to the end
        arr[left - 1] = '0';
        arr[N - 1] = '1';

        return arr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String maximumOddBinaryNumber(String s) {
        // Create char array
        char[] arr = s.toCharArray();
        int N = arr.length;
        
        // Initialize two pointers
        int left = 0;
        int right = N - 1;

        while (left <= right) {
            
            // Increment left if equals 1
            if (arr[left] == '1') {
                left++;
            }
            // Decrement right if equals 0
            if (arr[right] == '0') {
                right--;
            }
            // Swap if neither pointer can be iterated
            if (left <= right && arr[left] == '0' && arr[right] == '1') {
                arr[left] = '1';
                arr[right] = '0';
            }
        }

        // Swap rightmost 1 bit to the end
        arr[left - 1] = '0';
        arr[N - 1] = '1';

        return new String(arr);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        # Get n and char array
        N = len(s)
        arr = [char for char in s]

        left = 0
        right = N - 1
        while left <= right:
            
            # Increment left if equals 1
            if arr[left] == '1':
                left += 1
            # Decrement right if equals 0
            if arr[right] == '0':
                right -= 1
            # Swap if neither pointer can be iterated
            if left <= right and arr[left] == '0' and arr[right] == '1':
                arr[left] = '1'
                arr[right] = '0'
        
        # Swap rightmost 1 bit to the end
        arr[left - 1] = '0'
        arr[N - 1] = '1'

        return "".join(arr)
```

</details>
