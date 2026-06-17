# 2683. Neighboring Bitwise XOR

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/neighboring-bitwise-xor/)  
`Array` `Bit Manipulation`

**Problem Link:** [LeetCode 2683 - Neighboring Bitwise XOR](https://leetcode.com/problems/neighboring-bitwise-xor/)

## Problem

A 0-indexed array derived with length n is derived by computing the bitwise XOR (Ã¢Å â€¢) of adjacent values in a binary array original of length n.

Specifically, for each index i in the range [0, n - 1]:

- If i = n - 1, then derived[i] = original[i] Ã¢Å â€¢ original[0].
- Otherwise, derived[i] = original[i] Ã¢Å â€¢ original[i + 1].

Given an array derived, your task is to determine whether there exists a valid binary array original that could have formed derived.

Return true if such an array exists or false otherwise.

- A binary array is an array containing only 0's and 1's

### Example 1

```text
Input: derived = [1,1,0]
Output: true
Explanation: A valid original array that gives derived is [0,1,0].
derived[0] = original[0] Ã¢Å â€¢ original[1] = 0 Ã¢Å â€¢ 1 = 1
derived[1] = original[1] Ã¢Å â€¢ original[2] = 1 Ã¢Å â€¢ 0 = 1
derived[2] = original[2] Ã¢Å â€¢ original[0] = 0 Ã¢Å â€¢ 0 = 0
```

### Example 2

```text
Input: derived = [1,1]
Output: true
Explanation: A valid original array that gives derived is [0,1].
derived[0] = original[0] Ã¢Å â€¢ original[1] = 1
derived[1] = original[1] Ã¢Å â€¢ original[0] = 1
```

### Example 3

```text
Input: derived = [1,0]
Output: false
Explanation: There is no valid original array that gives derived.
```

## Constraints

- n == derived.length
- 1 <= n <= 105
- The values in derived are either 0's or 1's

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Bitwise OR of Adjacent Elements](https://leetcode.com/problems/bitwise-or-of-adjacent-elements/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2683. Neighboring Bitwise XOR

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C++, Java, Python3 |
| Optimized Simulation | C++, Java, Python3 |
| Cumulative XOR | C++, Java, Python3 |
| Sum Parity | C++, Java, Python3 |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // Create an original array initialized with 0.
        vector<int> original = {0};
        for (int i = 0; i < derived.size(); i++) {
            original.push_back((derived[i] ^ original[i]));
        }
        // Store the validation results in checkForZero and checkForOne
        // respectively.
        bool checkForZero = (original[0] == original[original.size() - 1]);
        original = {1};
        for (int i = 0; i < derived.size(); i++) {
            original.push_back((derived[i] ^ original[i]));
        }
        bool checkForOne = (original[0] == original[original.size() - 1]);

        return checkForZero | checkForOne;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean doesValidArrayExist(int[] derived) {
        // Create an original array initialized with 0.
        int[] original = new int[derived.length + 1];
        original[0] = 0;
        for (int i = 0; i < derived.length; i++) {
            original[i + 1] = derived[i] ^ original[i];
        }
        // Store the validation results in checkForZero and checkForOne respectively.
        boolean checkForZero = (original[0] == original[original.length - 1]);

        original[0] = 1;
        for (int i = 0; i < derived.length; i++) {
            original[i + 1] = derived[i] ^ original[i];
        }
        boolean checkForOne = (original[0] == original[original.length - 1]);

        return checkForZero || checkForOne;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        # Create an original array initialized with 0.
        original = [0]
        for i in range(len(derived)):
            original.append(derived[i] ^ original[i])

        # Store the validation results in checkForZero and checkForOne respectively.
        check_for_zero = original[0] == original[-1]
        original = [1]
        for i in range(len(derived)):
            original.append(derived[i] ^ original[i])
        check_for_one = original[0] == original[-1]

        return check_for_zero or check_for_one
```

</details>

<br>

## Approach 2: Optimized Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // Initialize the original array with 0 as the first element.
        vector<int> original = {0};

        // Generate the original array based on derived and original[0] = 0.
        for (int i = 0; i < derived.size(); i++) {
            original.push_back((derived[i] ^ original[i]));
        }

        // Check if the array is valid by comparing the first and last elements.
        return original[0] == original[original.size() - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean doesValidArrayExist(int[] derived) {
        // Initialize the original array with 0 as the first element.
        List<Integer> original = new ArrayList<>();
        original.add(0);

        // Generate the original array based on derived and original[0] = 0.
        for (int i = 0; i < derived.length; i++) {
            original.add(derived[i] ^ original.get(i));
        }

        // Check if the array is valid by comparing the first and last elements.
        return original.get(0).equals(original.get(original.size() - 1));
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        # Initialize the original array with 0 as the first element.
        original = [0]

        # Generate the original array based on derived and original[0] = 0
        for i in range(len(derived)):
            original.append(derived[i] ^ original[i])

        # Check if the array is valid by comparing the first and last elements.
        return original[0] == original[-1]
```

</details>

<br>

## Approach 3: Cumulative XOR

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR = 0;
        for (auto element : derived) {
            XOR = XOR ^ element;
        }
        return XOR == 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean doesValidArrayExist(int[] derived) {
        int XOR = 0;
        for (int element : derived) {
            XOR = XOR ^ element;
        }
        return XOR == 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        XOR = 0
        for element in derived:
            XOR = XOR ^ element
        return XOR == 0
```

</details>

<br>

## Approach 4: Sum Parity

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = accumulate(derived.begin(), derived.end(), 0);
        return sum % 2 == 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean doesValidArrayExist(int[] derived) {
        int sum = 0;
        for (int num : derived) {
            sum += num;
        }
        return sum % 2 == 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        return sum(derived) % 2 == 0
```

</details>
