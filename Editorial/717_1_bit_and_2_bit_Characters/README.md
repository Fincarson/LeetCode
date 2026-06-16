# 717. 1-bit and 2-bit Characters

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/1-bit-and-2-bit-characters/)  
`Array`

**Problem Link:** [LeetCode 717 - 1-bit and 2-bit Characters](https://leetcode.com/problems/1-bit-and-2-bit-characters/)

## Problem

We have two special characters:

- The first character can be represented by one bit 0.
- The second character can be represented by two bits (10 or 11).

Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

### Example 1

```text
Input: bits = [1,0,0]
Output: true
Explanation: The only way to decode it is two-bit character and one-bit character.
So the last character is one-bit character.
```

### Example 2

```text
Input: bits = [1,1,1,0]
Output: false
Explanation: The only way to decode it is two-bit character and two-bit character.
So the last character is not one-bit character.
```

## Constraints

- 1 <= bits.length <= 1000
- bits[i] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Gray Code](https://leetcode.com/problems/gray-code/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 717. 1-bit and 2-bit Characters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Increment Pointer | C++, Java, Python |
| Greedy | C++, Java, Python |

## Approach 1: Increment Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size() - 1) {
            i += bits[i] + 1;
        }
        return i == bits.size() - 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isOneBitCharacter(int[] bits) {
        int i = 0;
        while (i < bits.length - 1) {
            i += bits[i] + 1;
        }
        return i == bits.length - 1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isOneBitCharacter(self, bits):
        i = 0
        while i < len(bits) - 1:
            i += bits[i] + 1
        return i == len(bits) - 1
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = bits.size() - 2;
        while (i >= 0 && bits[i] > 0) {
            i--;
        }
        return (bits.size() - i) % 2 == 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isOneBitCharacter(int[] bits) {
        int i = bits.length - 2;
        while (i >= 0 && bits[i] > 0) {
            i--;
        }
        return (bits.length - i) % 2 == 0;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isOneBitCharacter(self, bits):
        parity = bits.pop()
        while bits and bits.pop(): parity ^= 1
        return parity == 0
```

</details>
