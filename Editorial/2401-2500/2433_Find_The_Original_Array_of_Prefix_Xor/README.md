# 2433. Find The Original Array of Prefix Xor

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/)  
`Array` `Bit Manipulation`

**Problem Link:** [LeetCode 2433 - Find The Original Array of Prefix Xor](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/)

## Problem

You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:

- pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].

Note that ^ denotes the bitwise-xor operation.

It can be proven that the answer is unique.

### Example 1

```text
Input: pref = [5,2,0,3,1]
Output: [5,7,2,3,2]
Explanation: From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.
```

### Example 2

```text
Input: pref = [13]
Output: [13]
Explanation: We have pref[0] = arr[0] = 13.
```

## Constraints

- 1 <= pref.length <= 105
- 0 <= pref[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Single Number III](https://leetcode.com/problems/single-number-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Triplets That Can Form Two Arrays of Equal XOR](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Decode XORed Array](https://leetcode.com/problems/decode-xored-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2433. Find The Original Array of Prefix Xor

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using XOR Properties | C++, Java |
| Using XOR Properties, Space Optimized | C++, Java |

## Approach 1: Using XOR Properties

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        
        vector<int> arr;
        arr.push_back(pref[0]);
        for (int i = 1; i < n; i++) {
            arr.push_back(pref[i] ^ pref[i - 1]);
        }
        
        return arr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findArray(int[] pref) {
        int n = pref.length;
        
        int[] arr = new int[n];
        arr[0] = pref[0];
        for (int i = 1; i < n; i++) {
            arr[i] = pref[i] ^ pref[i - 1];
        }
        
        return arr;
    }
}
```

</details>

<br>

## Approach 2: Using XOR Properties, Space Optimized

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        
        for (int i = n - 1; i > 0; i--) {
            pref[i] = pref[i] ^ pref[i - 1];
        }
        
        return pref;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findArray(int[] pref) {
        int n = pref.length;

        for (int i = n - 1; i > 0; i--) {
            pref[i] = pref[i] ^ pref[i - 1];
        }

        return pref;
    }
}
```

</details>
