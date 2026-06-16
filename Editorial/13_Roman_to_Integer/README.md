# 13. Roman to Integer

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/roman-to-integer/)  
`Hash Table` `Math` `String`

**Problem Link:** [LeetCode 13 - Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

## Problem

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

```text
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

- I can be placed before V (5) and X (10) to make 4 and 9.
- X can be placed before L (50) and C (100) to make 40 and 90.
- C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

### Example 1

```text
Input: s = "III"
Output: 3
Explanation: III = 3.
```

### Example 2

```text
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
```

### Example 3

```text
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

## Constraints

- 1 <= s.length <= 15
- s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
- It is guaranteed that s is a valid roman numeral in the range [1, 3999].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 13. Roman to Integer

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Left-to-Right Pass | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Left-to-Right Pass Improved | C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Right-to-Left Pass | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Left-to-Right Pass

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int romanToInt(char *s) {
    int values[256];
    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;

    int sum = 0;
    int i = 0;
    while (i < strlen(s)) {
        char currentSymbol = s[i];
        int currentValue = values[currentSymbol];
        int nextValue = 0;
        if (i + 1 < strlen(s)) {
            char nextSymbol = s[i + 1];
            nextValue = values[nextSymbol];
        }
        if (currentValue < nextValue) {
            sum += (nextValue - currentValue);
            i += 2;
        } else {
            sum += currentValue;
            i += 1;
        }
    }
    return sum;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> values{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                              {'C', 100}, {'D', 500}, {'M', 1000}};

        int sum = 0;
        int i = 0;
        while (i < s.length()) {
            char currentSymbol = s[i];
            int currentValue = values[currentSymbol];
            int nextValue = 0;
            // If a next value exists
            if (i + 1 < s.length()) {
                char nextSymbol = s[i + 1];
                nextValue = values[nextSymbol];
            }

            // If this is the subtractive case.
            if (currentValue < nextValue) {
                sum += (nextValue - currentValue);
                i += 2;
            }
            // else this is NOT the subtractive case.
            else {
                sum += currentValue;
                i += 1;
            }
        }
        return sum;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private static Dictionary<char, int> values =
        new Dictionary<char, int>() { { 'I', 1 },   { 'V', 5 },   { 'X', 10 },
                                      { 'L', 50 },  { 'C', 100 }, { 'D', 500 },
                                      { 'M', 1000 } };

    public int RomanToInt(string s) {
        int total = 0;
        int i = 0;
        while (i < s.Length) {
            // If this is the subtractive case.
            char currentSymbol = s[i];
            int currentValue = values[currentSymbol];
            int nextValue = 0;
            if (i + 1 < s.Length) {
                char nextSymbol = s[i + 1];
                nextValue = values[nextSymbol];
            }

            if (currentValue < nextValue) {
                total += (nextValue - currentValue);
                i += 2;
            }
            // else this is NOT the subtractive case.
            else {
                total += currentValue;
                i += 1;
            }
        }

        return total;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func romanToInt(s string) int {
    values := map[rune]int{
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }

    total := 0
    i := 0
    for i < len(s) {
        // If this is the subtractive case.
        if i+1 < len(s) && values[rune(s[i])] < values[rune(s[i+1])] {
            total += values[rune(s[i+1])] - values[rune(s[i])]
            i += 2
        } else {
            total += values[rune(s[i])]
            i += 1
        }
    }
    return total
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    static Map<String, Integer> values = new HashMap<>();

    static {
        values.put("M", 1000);
        values.put("D", 500);
        values.put("C", 100);
        values.put("L", 50);
        values.put("X", 10);
        values.put("V", 5);
        values.put("I", 1);
    }

    public int romanToInt(String s) {
        int sum = 0;
        int i = 0;
        while (i < s.length()) {
            String currentSymbol = s.substring(i, i + 1);
            int currentValue = values.get(currentSymbol);
            int nextValue = 0;
            if (i + 1 < s.length()) {
                String nextSymbol = s.substring(i + 1, i + 2);
                nextValue = values.get(nextSymbol);
            }

            if (currentValue < nextValue) {
                sum += (nextValue - currentValue);
                i += 2;
            } else {
                sum += currentValue;
                i += 1;
            }
        }
        return sum;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var romanToInt = function (s) {
    let values = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };

    let total = 0;
    let i = 0;
    while (i < s.length) {
        // If this is the subtractive case.
        if (i + 1 < s.length && values[s[i]] < values[s[i + 1]]) {
            total += values[s[i + 1]] - values[s[i]];
            i += 2;
        }
        // Else this is NOT the subtractive case.
        else {
            total += values[s[i]];
            i += 1;
        }
    }
    return total;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
values = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
}


class Solution:
    def romanToInt(self, s: str) -> int:
        total = 0
        i = 0
        while i < len(s):
            # If this is the subtractive case.
            if i + 1 < len(s) and values[s[i]] < values[s[i + 1]]:
                total += values[s[i + 1]] - values[s[i]]
                i += 2
            # Else this is NOT the subtractive case.
            else:
                total += values[s[i]]
                i += 1
        return total
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function romanToInt(s: string): number {
    let values: { [key: string]: number } = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };

    let total = 0;
    let i = 0;
    while (i < s.length) {
        // If this is the subtractive case.
        if (i + 1 < s.length && values[s[i]] < values[s[i + 1]]) {
            total += values[s[i + 1]] - values[s[i]];
            i += 2;
        }
        // Else this is NOT the subtractive case.
        else {
            total += values[s[i]];
            i += 1;
        }
    }
    return total;
}
```

</details>

<br>

## Approach 2: Left-to-Right Pass Improved

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    static map<string, int>
        values;  // static ensures map initialization only happens once instead
                 // of every object of the class

    Solution() {
        if (values.empty()) {
            values.insert(pair<string, int>("I", 1));
            values.insert(pair<string, int>("V", 5));
            values.insert(pair<string, int>("X", 10));
            values.insert(pair<string, int>("L", 50));
            values.insert(pair<string, int>("C", 100));
            values.insert(pair<string, int>("D", 500));
            values.insert(pair<string, int>("M", 1000));
            values.insert(pair<string, int>("IV", 4));
            values.insert(pair<string, int>("IX", 9));
            values.insert(pair<string, int>("XL", 40));
            values.insert(pair<string, int>("XC", 90));
            values.insert(pair<string, int>("CD", 400));
            values.insert(pair<string, int>("CM", 900));
        }
    }

    int romanToInt(string s) {
        int sum = 0;
        int i = 0;
        while (i < s.size()) {
            if (i < s.size() - 1) {
                string doubleSymbol = s.substr(i, 2);
                // check if this is the length-2 symbol case
                if (values.count(doubleSymbol)) {
                    sum += values[doubleSymbol];
                    i += 2;
                    continue;
                }
            }
            // otherwise, it must be the length-1 symbol case
            string singleSymbol = s.substr(i, 1);
            sum += values[singleSymbol];
            i += 1;
        }
        return sum;
    }
};

map<string, int> Solution::values;  // initalizing the map outside the class
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    static Dictionary<string, int> values = new Dictionary<string, int> {
        { "I", 1 },   { "V", 5 },    { "X", 10 },  { "L", 50 }, { "C", 100 },
        { "D", 500 }, { "M", 1000 }, { "IV", 4 },  { "IX", 9 }, { "XL", 40 },
        { "XC", 90 }, { "CD", 400 }, { "CM", 900 }
    };

    public int RomanToInt(string s) {
        int sum = 0;
        int i = 0;
        while (i < s.Length) {
            if (i < s.Length - 1) {
                string doubleSymbol = s.Substring(i, 2);
                if (values.ContainsKey(doubleSymbol)) {
                    sum += values[doubleSymbol];
                    i += 2;
                    continue;
                }
            }

            string singleSymbol = s.Substring(i, 1);
            sum += values[singleSymbol];
            i += 1;
        }

        return sum;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func romanToInt(s string) int {
    values := map[string]int{
        "I":  1,
        "V":  5,
        "X":  10,
        "L":  50,
        "C":  100,
        "D":  500,
        "M":  1000,
        "IV": 4,
        "IX": 9,
        "XL": 40,
        "XC": 90,
        "CD": 400,
        "CM": 900,
    }
    total := 0
    i := 0
    for i < len(s) {
        if i < len(s)-1 {
            substring := s[i : i+2]
            vals, ok := values[substring]
            if ok {
                total += vals
                i += 2
                continue
            }
        }
        val := values[string(s[i])]
        total += val
        i++
    }
    return total
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    static Map<String, Integer> values = new HashMap<>();

    static {
        values.put("I", 1);
        values.put("V", 5);
        values.put("X", 10);
        values.put("L", 50);
        values.put("C", 100);
        values.put("D", 500);
        values.put("M", 1000);
        values.put("IV", 4);
        values.put("IX", 9);
        values.put("XL", 40);
        values.put("XC", 90);
        values.put("CD", 400);
        values.put("CM", 900);
    }

    public int romanToInt(String s) {
        int sum = 0;
        int i = 0;
        while (i < s.length()) {
            if (i < s.length() - 1) {
                String doubleSymbol = s.substring(i, i + 2);
                // Check if this is the length-2 symbol case.
                if (values.containsKey(doubleSymbol)) {
                    sum += values.get(doubleSymbol);
                    i += 2;
                    continue;
                }
            }
            // Otherwise, it must be the length-1 symbol case.
            String singleSymbol = s.substring(i, i + 1);
            sum += values.get(singleSymbol);
            i += 1;
        }
        return sum;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let values = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
    IV: 4,
    IX: 9,
    XL: 40,
    XC: 90,
    CD: 400,
    CM: 900,
};

var romanToInt = function (s) {
    let total = 0;
    let i = 0;
    while (i < s.length) {
        if (i < s.length - 1 && s.substring(i, i + 2) in values) {
            total += values[s.substring(i, i + 2)];
            i += 2;
        } else {
            total += values[s.charAt(i)];
            i++;
        }
    }
    return total;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
values = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
    "IV": 4,
    "IX": 9,
    "XL": 40,
    "XC": 90,
    "CD": 400,
    "CM": 900,
}


class Solution:
    def romanToInt(self, s: str) -> int:
        total = 0
        i = 0
        while i < len(s):
            # This is the subtractive case.
            if i < len(s) - 1 and s[i : i + 2] in values:
                total += values[s[i : i + 2]]
                i += 2
            else:
                total += values[s[i]]
                i += 1
        return total
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
let values: { [key: string]: number } = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
    IV: 4,
    IX: 9,
    XL: 40,
    XC: 90,
    CD: 400,
    CM: 900,
};

function romanToInt(s: string): number {
    let total = 0;
    let i = 0;
    while (i < s.length) {
        if (i < s.length - 1 && s.substring(i, i + 2) in values) {
            total += values[s.substring(i, i + 2)];
            i += 2;
        } else {
            total += values[s.charAt(i)];
            i++;
        }
    }
    return total;
}
```

</details>

<br>

## Approach 3: Right-to-Left Pass

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct roman_value {
    char letter;
    int value;
};

const struct roman_value values[] = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

int find_value(char letter) {
    for (int i = 0; i < sizeof(values) / sizeof(*values); ++i) {
        if (values[i].letter == letter) {
            return values[i].value;
        }
    }
    return 0;
}

int romanToInt(char* s) {
    int total = find_value(s[strlen(s) - 1]);
    for (int i = strlen(s) - 2; i >= 0; --i) {
        if (find_value(s[i]) < find_value(s[i + 1])) {
            total -= find_value(s[i]);
        } else {
            total += find_value(s[i]);
        }
    }
    return total;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    static unordered_map<char, int> values;
    int romanToInt(string s) {
        char lastSymbol = s[s.size() - 1];
        int lastValue = values[lastSymbol];
        int total = lastValue;

        for (int i = s.size() - 2; i >= 0; i--) {
            char currentSymbol = s[i];
            int currentValue = values[currentSymbol];
            if (currentValue < lastValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }
            lastValue = currentValue;
        }
        return total;
    }
};

unordered_map<char, int> Solution::values = {
    {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
    {'X', 10},   {'V', 5},   {'I', 1}};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    static Dictionary<char, int> values = new Dictionary<char, int> {
        { 'I', 1 },   { 'V', 5 },   { 'X', 10 },   { 'L', 50 },
        { 'C', 100 }, { 'D', 500 }, { 'M', 1000 },
    };

    public int RomanToInt(string s) {
        char lastSymbol = s[s.Length - 1];
        int lastValue = values[lastSymbol];
        int total = lastValue;

        for (int i = s.Length - 2; i >= 0; i--) {
            char currentSymbol = s[i];
            int currentValue = values[currentSymbol];
            if (currentValue < lastValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }

            lastValue = currentValue;
        }

        return total;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func romanToInt(s string) int {
    values := map[rune]int{
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }
    var lastValue int = int(values[rune(s[len(s)-1])])
    var total int = lastValue

    for i := len(s) - 2; i >= 0; i-- {
        var currentValue int = int(values[rune(s[i])])
        if currentValue < lastValue {
            total -= currentValue
        } else {
            total += currentValue
        }
        lastValue = currentValue
    }
    return total
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    static Map<String, Integer> values = new HashMap<>();

    static {
        values.put("M", 1000);
        values.put("D", 500);
        values.put("C", 100);
        values.put("L", 50);
        values.put("X", 10);
        values.put("V", 5);
        values.put("I", 1);
    }

    public int romanToInt(String s) {
        String lastSymbol = s.substring(s.length() - 1);
        int lastValue = values.get(lastSymbol);
        int total = lastValue;

        for (int i = s.length() - 2; i >= 0; i--) {
            String currentSymbol = s.substring(i, i + 1);
            int currentValue = values.get(currentSymbol);
            if (currentValue < lastValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }
            lastValue = currentValue;
        }
        return total;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var romanToInt = function (s) {
    const values = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };

    let lastSymbol = s[s.length - 1];
    let lastValue = values[lastSymbol];
    let total = lastValue;

    for (let i = s.length - 2; i >= 0; i--) {
        let currentSymbol = s[i];
        let currentValue = values[currentSymbol];
        if (currentValue < lastValue) {
            total -= currentValue;
        } else {
            total += currentValue;
        }
        lastValue = currentValue;
    }
    return total;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
values = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
}


class Solution:
    def romanToInt(self, s: str) -> int:
        total = values.get(s[-1])
        for i in reversed(range(len(s) - 1)):
            if values[s[i]] < values[s[i + 1]]:
                total -= values[s[i]]
            else:
                total += values[s[i]]
        return total
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function romanToInt(s: string): number {
    const values: Record<string, number> = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };

    let lastSymbol = s[s.length - 1];
    let lastValue = values[lastSymbol];
    let total = lastValue;

    for (let i = s.length - 2; i >= 0; i--) {
        let currentSymbol = s[i];
        let currentValue = values[currentSymbol];
        if (currentValue < lastValue) {
            total -= currentValue;
        } else {
            total += currentValue;
        }
        lastValue = currentValue;
    }
    return total;
}
```

</details>
