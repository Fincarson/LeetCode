# 800. Similar RGB Color

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/similar-rgb-color/)  
`Math` `String` `Enumeration`

**Problem Link:** [LeetCode 800 - Similar RGB Color](https://leetcode.com/problems/similar-rgb-color/)

## Problem

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.

- For example, "#15c" is shorthand for the color "#1155cc".

The similarity between the two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)2 - (CD - WX)2 - (EF - YZ)2.

Given a string color that follows the format "#ABCDEF", return a string represents the color that is most similar to the given color and has a shorthand (i.e., it can be represented as some "#XYZ").

Any answer which has the same highest similarity as the best answer will be accepted.

### Example 1

```text
Input: color = "#09f166"
Output: "#11ee66"
Explanation:
The similarity is -(0x09 - 0x11)2 -(0xf1 - 0xee)2 - (0x66 - 0x66)2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.
```

### Example 2

```text
Input: color = "#4e3fe1"
Output: "#5544dd"
```

## Constraints

- color.length == 7
- color[0] == '#'
- color[i] is either digit or character in the range ['a', 'f'] for i > 0.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 800. Similar RGB Color

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Rounding | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Given string 'colorSection' representing a two-digit base 16 number 
    // "AB", find out the number "XX" that has the highest similarity to "AB". 
    string findTarget(string colorSection) {
        int num = stoi(colorSection, nullptr, 16);

        // We need to find the smallest absolute value of similarity, thus
        // we start with a big value 'minDiff' for comparsion.
        int ans = -1, minDiff = 1000;
        
        // We try the value of every possible "XX" pair.
        for (int i = 0; i < 16; ++i) {
            int curDiff = (i * 17 - num) * (i * 17 - num);
            if (curDiff < minDiff) {
                minDiff = curDiff;
                ans = i;
            }
        }
        
        // Return "XX", the pair of the highest similarity.
        string ansHex{char(ans > 9 ? 'a' + ans - 10 : '0' + ans)};
        return ansHex + ansHex;
    }
    
    string similarRGB(string color) {
        string targetColor = "#";
        
        // Split input color into three sections, find out the best
        // fit for each section and attach it to 'targetColor'.
        for (int i = 1; i < 6; i += 2) {
            targetColor += findTarget(color.substr(i, 2));
        }
        
        return targetColor;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Given string 'colorSection' representing a two-digit 
    // base 16 number "AB", find out the number "XX" that 
    // has the highest similarity to "AB".  
    public String findTarget(String colorSection) {
        int num = Integer.parseInt(colorSection, 16);

        // We need to find the smallest absolute value of similarity, thus
        // we start with a big value 'minDiff' for comparsion.
        int ans = -1, minDiff = 1000;

        // We try the value of every possible "XX" pair.
        for (int i = 0; i < 16; ++i) {
            int curDiff = (int)Math.pow(i * 17 - num, 2);
            if (curDiff < minDiff) {
                minDiff = curDiff;
                ans = i;
            }
        }
        
        // Return "XX", the pair of the highest similarity.
        return Integer.toHexString(ans).repeat(2);
    }
    
    public String similarRGB(String color) {
        StringBuilder targetColor = new StringBuilder();
        targetColor.append("#");
        
        // Split input color into three sections, find out the best
        // fit for each section and attach it to 'targetColor'.
        for (int i = 1; i < 6; i += 2) {
            targetColor.append(findTarget(color.substring(i, i + 2)));
        }
        
        return targetColor.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def similarRGB(self, color: str) -> str:
        # Given string 'color_section' representing a two-digit 
        # base 16 number "AB", find out the number "XX" that 
        # has the highest similarity to "AB".
        def findTarget(color_section):
            # We need to find the smallest absolute value of similarity, thus
            # we start with a big value 'min_diff' for comparsion.
            min_diff = 1000
            ans = -1
            
            # We try the value of every possible "XX" pair.
            for i in range(16):
                cur_diff = (int(color_section, 16) - i * 17) ** 2
                if cur_diff < min_diff:
                    min_diff = cur_diff
                    ans = i
            
            # Return "XX", the pair of the highest similarity.
            return hex(ans)[-1] * 2
        
        # Split input color into three sections, find out the best
        # fit for each section and attach it to 'target_color'.
        target_color = "#"
        for i in range(1, 6, 2):
            target_color += findTarget(color[i:i + 2])
            
        return target_color
```

</details>

<br>

## Approach 2: Rounding

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Given string 'colorSection' representing a two-digit 
    // base 16 number "AB", find out the number "XX" that 
    // has the highest similarity to "AB". 
    string findTarget(string colorSection) {
        int num = stoi(colorSection, nullptr, 16);
        
        // Get the rounded value of num to 17.
        int x = round(num * 1.0 / 17);
        
        // Return "XX", the pattern of the highest similarity.
        string ans;
        ans = x > 9 ? 'a' + x - 10 : '0' + x;
        return ans + ans;
    }
    
    string similarRGB(string color) {
        string targetColor = "#";

        // Split input color into three sections, find out the best
        // fit for each section and attach it to 'targetColor'.
        for (int i = 1; i < 6; i += 2) {
            targetColor += findTarget(color.substr(i, 2));
        }
        
        return targetColor;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Given string 'colorSection' representing a two-digit 
    // base 16 number "AB", find out the number "XX" that 
    // has the highest similarity to "AB".  
    public String findTarget(String colorSection) {
        int num = Integer.parseInt(colorSection, 16);
        
        // Get the rounded value of num to 17.
        int x = Math.round((float)num / 17);
        
        // Return "XX", the pattern of the highest similarity.
        return Integer.toHexString(x).repeat(2);
    }
    
    public String similarRGB(String color) {
        StringBuilder targetColor = new StringBuilder();
        targetColor.append("#");
        
        // Split input color into three sections, find out the best
        // fit for each section and attach it to 'targetColor'.
        for (int i = 1; i < 6; i += 2) {
            targetColor.append(findTarget(color.substring(i, i + 2)));
        }
        
        return targetColor.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def similarRGB(self, color: str) -> str:
        # Given string 'color_section' representing a two-digit 
        # base 16 number "AB", find out the number "XX" that 
        # has the highest similarity to "AB".
        def findTarget(color_section):
            num = int(color_section, 16)
            
            # Get the rounded value of num to 17.
            x = round(num / 17)

            # Return "XX", the pattern of the highest similarity.
            return hex(x)[-1] * 2
        
        # Split input color into three sections, find out the best
        # fit for each section and attach it to 'target_color'.
        target_color = "#"
        for i in range(1, 6, 2):
            target_color += findTarget(color[i:i + 2])
            
        return target_color
```

</details>
