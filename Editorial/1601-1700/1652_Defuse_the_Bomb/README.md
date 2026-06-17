# 1652. Defuse the Bomb

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/defuse-the-bomb/)  
`Array` `Sliding Window`

**Problem Link:** [LeetCode 1652 - Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb/)

## Problem

You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

- If k > 0, replace the ith number with the sum of the next k numbers.
- If k < 0, replace the ith number with the sum of the previous -k numbers.
- If k == 0, replace the ith number with 0.

As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

### Example 1

```text
Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
```

### Example 2

```text
Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]
Explanation: When k is zero, the numbers are replaced by 0.
```

### Example 3

```text
Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
```

## Constraints

- n == code.length
- 1 <= n <= 100
- 1 <= code[i] <= 100
- -(n - 1) <= k <= n - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Circular Sentence](https://leetcode.com/problems/circular-sentence/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Shortest Distance to Target String in a Circular Array](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Take K of Each Character From Left and Right](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1652. Defuse the Bomb

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        // If k is 0, return the result directly.
        if (k == 0) {
            return result;
        }
        for (int i = 0; i < result.size(); i++) {
            if (k > 0) {
                // If k is greater than 0, store the sum of next k numbers.
                for (int j = i + 1; j < i + k + 1; j++) {
                    result[i] += code[j % code.size()];
                }
            } else {
                // If k is less than 0, store the sum of previous -1*k numbers.
                for (int j = i - abs(k); j < i; j++) {
                    result[i] += code[(j + code.size()) % code.size()];
                }
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] decrypt(int[] code, int k) {
        int[] result = new int[code.length];
        // If k is 0, return the result directly.
        if (k == 0) {
            return result;
        }
        for (int i = 0; i < result.length; i++) {
            if (k > 0) {
                // If k is greater than 0, store the sum of next k numbers.
                for (int j = i + 1; j < i + k + 1; j++) {
                    result[i] += code[j % code.length];
                }
            } else {
                // If k is less than 0, store the sum of previous -1*k numbers.
                for (int j = i - Math.abs(k); j < i; j++) {
                    result[i] += code[(j + code.length) % code.length];
                }
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        result = [0] * len(code)
        # If k is 0, return the result directly.
        if k == 0:
            return result
        for i in range(len(result)):
            if k > 0:
                # If k is greater than 0, store the sum of next k numbers.            
                for j in range(i + 1, i + k + 1):
                    result[i] += code[j % len(code)]
            else:
                # If k is less than 0, store the sum of previous -1*k numbers.
                for j in range(i - abs(k), i):
                    result[i] += code[(j + len(code)) % len(code)]
        return result
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        if (k == 0) return result;
        // Define the initial window and initial sum
        int start = 1, end = k, sum = 0;
        // If k < 0, the starting point will be end of the array.
        if (k < 0) {
            start = code.size() - abs(k);
            end = code.size() - 1;
        }
        for (int i = start; i <= end; i++) sum += code[i];
        // Scan through the code array as i moving to the right, update the
        // window sum.
        for (int i = 0; i < code.size(); i++) {
            result[i] = sum;
            sum -= code[start % code.size()];
            sum += code[(end + 1) % code.size()];
            start++;
            end++;
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] decrypt(int[] code, int k) {
        int[] result = new int[code.length];
        if (k == 0) return result;
        // Define the initial window and initial sum
        int start = 1, end = k, sum = 0;
        // If k < 0, the starting point will be end of the array.
        if (k < 0) {
            start = code.length - Math.abs(k);
            end = code.length - 1;
        }
        for (int i = start; i <= end; i++) sum += code[i];
        // Scan through the code array as i moving to the right, update the window sum.
        for (int i = 0; i < code.length; i++) {
            result[i] = sum;
            sum -= code[(start) % code.length];
            sum += code[(end + 1) % code.length];
            start++;
            end++;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        result = [0 for _ in range(len(code))]
        if k == 0:
            return result
        # Define the initial window and initial sum
        start, end, window_sum = 1, k, 0
        # If k < 0, the starting point will be end of the array.
        if k < 0:
            start = len(code) - abs(k)
            end = len(code) - 1
        for i in range(start, end + 1):
            window_sum += code[i]
        # Scan through the code array as i moving to the right, update the window sum.
        for i in range(len(code)):
            result[i] = window_sum
            window_sum -= code[start % len(code)]
            window_sum += code[(end + 1) % len(code)]
            start += 1
            end += 1
        return result
```

</details>
