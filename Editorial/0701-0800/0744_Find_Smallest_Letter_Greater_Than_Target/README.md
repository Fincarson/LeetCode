# 744. Find Smallest Letter Greater Than Target

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 744 - Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)

## Problem

You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

### Example 1

```text
Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
```

### Example 2

```text
Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
```

### Example 3

```text
Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
```

## Constraints

- 2 <= letters.length <= 104
- letters[i] is a lowercase English letter.
- letters is sorted in non-decreasing order.
- letters contains at least two different characters.
- target is a lowercase English letter.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Elements With Strictly Smaller and Greater Elements ](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 744. Find Smallest Letter Greater Than Target

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char letter : letters) {
            if (letter > target) {
                return letter;
            }
        }
        return letters[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        for (char letter : letters) {
            if (letter > target) {
                return letter;
            }
        }
        return letters[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        for letter in letters:
            if letter > target:
                return letter
        return letters[0]
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
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left == letters.size() ? letters[0] : letters[left];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int left = 0, right = letters.length - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left == letters.length ? letters[0] : letters[left];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        left = 0
        right = len(letters) - 1
    
        while left <= right:
            mid = (left + right) // 2
            if letters[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        
        if left == len(letters):
            return letters[0]
        else:
            return letters[left]
```

</details>
