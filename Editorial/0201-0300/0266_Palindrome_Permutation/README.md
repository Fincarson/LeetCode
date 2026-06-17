# 266. Palindrome Permutation

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/palindrome-permutation/)  
`Hash Table` `String` `Bit Manipulation`

**Problem Link:** [LeetCode 266 - Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation/)

## Problem

Given a string s, return true if a permutation of the string could form a palindrome and false otherwise.

### Example 1

```text
Input: s = "code"
Output: false
```

### Example 2

```text
Input: s = "aab"
Output: true
```

### Example 3

```text
Input: s = "carerac"
Output: true
```

## Constraints

- 1 <= s.length <= 5000
- s consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Palindrome Permutation II](https://leetcode.com/problems/palindrome-permutation-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 266. Palindrome Permutation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Accepted] | C++, Java, Python3 |
| Approach #2 Using HashMap [Accepted] | C++, Java, Python3 |
| Approach #3 Using Array [Accepted] | C++, Java, Python3 |
| Approach #4 Single Pass [Accepted]: | C++, Java, Python3 |
| Approach #5 Using Set [Accepted]: | C++, Java, Python3 |

## Approach #1 Brute Force [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int count[128] = {0};
        for (int j = 0; j < s.length(); j++) {
            count[s[j]]++;
        }
        int odd = 0;
        for (int i = 0; i < 128 && odd <= 1; i++) {
            odd += count[i] % 2;
        }
        return odd <= 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean canPermutePalindrome(String s) {
        int count = 0;
        for (char i = 0; i < 128 && count <= 1; i++) {
            int ct = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == i) ct++;
            }
            count += ct % 2;
        }
        return count <= 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        count = 0
        for i in range(128):  # For all ASCII characters
            if count > 1:
                break
            ct = 0
            for j in range(len(s)):
                if s[j] == chr(i):  # Comparing with ASCII character
                    ct += 1
            count += ct % 2
        return count <= 1
```

</details>

<br>

## Approach #2 Using HashMap [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            +map[s[i]]++;
        }
        int count = 0;
        for (auto& pair : map) {
            count += pair.second % 2;
        }
        return count <= 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean canPermutePalindrome(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }
        int count = 0;
        for (char key : map.keySet()) {
            count += map.get(key) % 2;
        }
        return count <= 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        from collections import Counter

        count = Counter(s)
        odds = sum(val % 2 for val in count.values())
        return odds <= 1
```

</details>

<br>

## Approach #3 Using Array [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int map[128] = {0};
        for (char c : s) {
            map[int(c)]++;
        }
        int count = 0;
        for (int i = 0; i < 128 && count <= 1; i++) {
            count += map[i] % 2;
        }
        return count <= 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean canPermutePalindrome(String s) {
        int[] map = new int[128];
        for (int i = 0; i < s.length(); i++) {
            map[s.charAt(i)]++;
        }
        int count = 0;
        for (int key = 0; key < map.length && count <= 1; key++) {
            count += map[key] % 2;
        }
        return count <= 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        map = [0] * 128
        for ch in s:
            map[ord(ch)] += 1
        count = 0
        for c in map:
            if c % 2:
                count += 1
        return count <= 1
```

</details>

<br>

## Approach #4 Single Pass [Accepted]:

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int map[128] = {0};
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            map[int(s[i])]++;
            if (map[int(s[i])] % 2 == 0)
                count--;
            else
                count++;
        }
        return count <= 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean canPermutePalindrome(String s) {
        int[] map = new int[128];
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            map[s.charAt(i)]++;
            if (map[s.charAt(i)] % 2 == 0) count--;
            else count++;
        }
        return count <= 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        map = [0] * 128
        count = 0
        for i in range(len(s)):
            map[ord(s[i])] += 1
            if map[ord(s[i])] % 2 == 0:
                count -= 1
            else:
                count += 1
        return count <= 1
```

</details>

<br>

## Approach #5 Using Set [Accepted]:

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> char_set;
        for (char c : s) {
            if (char_set.find(c) != char_set.end())
                char_set.erase(c);
            else
                char_set.insert(c);
        }
        return char_set.size() <= 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean canPermutePalindrome(String s) {
        Set<Character> set = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            if (!set.add(s.charAt(i))) set.remove(s.charAt(i));
        }
        return set.size() <= 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        chars = set()
        for c in s:
            if c in chars:
                chars.remove(c)
            else:
                chars.add(c)
        return len(chars) <= 1
```

</details>
