# 443. String Compression

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/string-compression/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 443 - String Compression](https://leetcode.com/problems/string-compression/)

## Problem

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

- If the group's length is 1, append the character to s.
- Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Note: The characters in the array beyond the returned length do not matter and should be ignored.

### Example 1

```text
Input: chars = ["a","a","b","b","c","c","c"]
Output: 6
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
After modifying the input array in-place, the first 6 characters of chars should be ["a","2","b","2","c","3"].
```

### Example 2

```text
Input: chars = ["a"]
Output: 1
Explanation: The only group is "a", which remains uncompressed since it is a single character.
After modifying the input array in-place, the first character of chars should be ["a"].
```

### Example 3

```text
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: 4
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
After modifying the input array in-place, the first 4 characters of chars should be ["a","b","1","2"].
```

## Constraints

- 1 <= chars.length <= 2000
- chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count and Say](https://leetcode.com/problems/count-and-say/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Design Compressed String Iterator](https://leetcode.com/problems/design-compressed-string-iterator/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Decompress Run-Length Encoded List](https://leetcode.com/problems/decompress-run-length-encoded-list/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [String Compression III](https://leetcode.com/problems/string-compression-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Better Compression of String](https://leetcode.com/problems/better-compression-of-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 443. String Compression

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | C++, Java, Python3 |

## Solution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, res = 0;
        while (i < chars.size()) {
            int groupLength = 1;
            while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i]) {
                groupLength++;
            }
            chars[res++] = chars[i];
            if (groupLength > 1) {
                for (char c : to_string(groupLength)) {
                    chars[res++] = c;
                }
            }
            i += groupLength;
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int compress(char[] chars) {
        int i = 0, res = 0;
        while (i < chars.length) {
            int groupLength = 1;
            while (i + groupLength < chars.length && chars[i + groupLength] == chars[i]) {
                groupLength++;
            }
            chars[res++] = chars[i];
            if (groupLength > 1) {
                for (char c : Integer.toString(groupLength).toCharArray()) {
                    chars[res++] = c;
                }
            }
            i += groupLength;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        res = 0
        while i < len(chars):
            group_length = 1
            while (i + group_length < len(chars)
                   and chars[i + group_length] == chars[i]):
                group_length += 1
            chars[res] = chars[i]
            res += 1
            if group_length > 1:
                str_repr = str(group_length)
                chars[res:res+len(str_repr)] = list(str_repr)
                res += len(str_repr)
            i += group_length
        return res
```

</details>
