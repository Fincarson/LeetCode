# 1456. Maximum Number of Vowels in a Substring of Given Length

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)  
`String` `Sliding Window`

**Problem Link:** [LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)

## Problem

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

### Example 1

```text
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
```

### Example 2

```text
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
```

### Example 3

```text
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
```

## Constraints

- 1 <= s.length <= 105
- s consists of lowercase English letters.
- 1 <= k <= s.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum White Tiles Covered by a Carpet](https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Recolors to Get K Consecutive Black Blocks](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Length of the Longest Alphabetical Continuous Substring](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1456. Maximum Number of Vowels in a Substring of Given Length

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C++, Java, Python3 |

## Approach: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        
        // Build the window of size k, count the number of vowels it contains.
        int count = 0;
        for (int i = 0; i < k; i++) {
            count += vowels.count(s[i]);
        } 
        int answer = count;
        
        // Slide the window to the right, focus on the added character and the
        // removed character and update "count". Record the largest "count".
        for (int i = k; i < s.length(); i++) {
            count += vowels.count(s[i]) - vowels.count(s[i - k]);
            answer = max(answer, count);
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
    public int maxVowels(String s, int k) {
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');
        
        // Build the window of size k, count the number of vowels it contains.
        int count = 0;
        for (int i = 0; i < k; i++) {
            count += vowels.contains(s.charAt(i)) ? 1 : 0;
        }
        int answer = count;
        
        // Slide the window to the right, focus on the added character and the
        // removed character and update "count". Record the largest "count".
        for (int i = k; i < s.length(); i++) {
            count += vowels.contains(s.charAt(i)) ? 1 : 0;
            count -= vowels.contains(s.charAt(i - k)) ? 1 : 0;
            answer = Math.max(answer, count);
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
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        
        # Build the window of size k, count the number of vowels it contains.
        count = 0
        for i in range(k):
            count += int(s[i] in vowels)
        answer = count
        
        # Slide the window to the right, focus on the added character and the
        # removed character and update "count". Record the largest "count".
        for i in range(k, len(s)):
            count += int(s[i] in vowels)
            count -= int(s[i - k] in vowels)
            answer = max(answer, count)
        
        return answer
```

</details>
