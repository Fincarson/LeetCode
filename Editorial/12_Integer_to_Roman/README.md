# 12. Integer to Roman

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/integer-to-roman/)  
`Hash Table` `Math` `String`

**Problem Link:** [LeetCode 12 - Integer to Roman](https://leetcode.com/problems/integer-to-roman/)

## Problem

Seven different symbols represent Roman numerals with the following values:

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

- If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
- If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
- Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.

Given an integer, convert it to a Roman numeral.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= num <= 3999

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Roman to Integer](https://leetcode.com/problems/roman-to-integer/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Integer to English Words](https://leetcode.com/problems/integer-to-english-words/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 12. Integer to Roman

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Hardcode Digits | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char *intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                       "XL", "X",  "IX", "V",  "IV", "I"};
    char *roman = (char *)malloc(20 * sizeof(char));
    roman[0] = '\0';

    // Loop through each symbol, stopping if num becomes 0.
    for (int i = 0; i < 13 && num > 0; i++) {
        // Repeat while the current symbol still fits into num.
        while (values[i] <= num) {
            num -= values[i];
            strcat(roman, symbols[i]);
        }
    }
    return roman;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50,
                              40,   10,  9,   5,   4,   1};
        vector<string> symbols = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                  "XL", "X",  "IX", "V",  "IV", "I"};
        string roman;
        // Loop through each symbol, stopping if num becomes 0.
        for (int i = 0; i < values.size() && num > 0; i++) {
            // Repeat while the current symbol still fits into num.
            while (values[i] <= num) {
                num -= values[i];
                roman += symbols[i];
            }
        }
        return roman;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string IntToRoman(int num) {
        int[] values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string[] symbols = { "M",  "CM", "D",  "CD", "C",  "XC", "L",
                             "XL", "X",  "IX", "V",  "IV", "I" };
        StringBuilder roman = new StringBuilder();
        // Loop through each symbol, stopping if num becomes 0.
        for (int i = 0; i < values.Length && num > 0; i++) {
            // Repeat while the current symbol still fits into num.
            while (values[i] <= num) {
                num -= values[i];
                roman.Append(symbols[i]);
            }
        }

        return roman.ToString();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func intToRoman(num int) string {
    values := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
    symbols := []string{
        "M",
        "CM",
        "D",
        "CD",
        "C",
        "XC",
        "L",
        "XL",
        "X",
        "IX",
        "V",
        "IV",
        "I",
    }
    roman := ""
    // Loop through each symbol, stopping if num becomes 0.
    for i := 0; i < len(values) && num > 0; i++ {
        // Repeat while the current symbol still fits into num.
        for values[i] <= num {
            num -= values[i]
            roman += symbols[i]
        }
    }
    return roman
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static final int[] values = {
        1000,
        900,
        500,
        400,
        100,
        90,
        50,
        40,
        10,
        9,
        5,
        4,
        1,
    };
    private static final String[] symbols = {
        "M",
        "CM",
        "D",
        "CD",
        "C",
        "XC",
        "L",
        "XL",
        "X",
        "IX",
        "V",
        "IV",
        "I",
    };

    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        // Loop through each symbol, stopping if num becomes 0.
        for (int i = 0; i < values.length && num > 0; i++) {
            // Repeat while the current symbol still fits into num.
            while (values[i] <= num) {
                num -= values[i];
                sb.append(symbols[i]);
            }
        }
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var intToRoman = function (num) {
    const values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    const symbols = [
        "M",
        "CM",
        "D",
        "CD",
        "C",
        "XC",
        "L",
        "XL",
        "X",
        "IX",
        "V",
        "IV",
        "I",
    ];
    let roman = "";
    // Loop through each symbol, stopping if num becomes 0.
    for (let i = 0; i < values.length && num > 0; i++) {
        // Repeat while the current symbol still fits into num.
        while (values[i] <= num) {
            num -= values[i];
            roman += symbols[i];
        }
    }
    return roman;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def intToRoman(self, num: int) -> str:
        digits = [
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ]

        roman_digits = []
        # Loop through each symbol.
        for value, symbol in digits:
            # We don't want to continue looping if we're done.
            if num == 0:
                break
            count, num = divmod(num, value)
            # Append "count" copies of "symbol" to roman_digits.
            roman_digits.append(symbol * count)
        return "".join(roman_digits)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function intToRoman(num: number): string {
    const values: number[] = [
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1,
    ];
    const symbols: string[] = [
        "M",
        "CM",
        "D",
        "CD",
        "C",
        "XC",
        "L",
        "XL",
        "X",
        "IX",
        "V",
        "IV",
        "I",
    ];
    let roman: string = "";
    // Loop through each symbol, stopping if num becomes 0.
    for (let i = 0; i < values.length && num > 0; i++) {
        // Repeat while the current symbol still fits into num.
        while (values[i] <= num) {
            num -= values[i];
            roman += symbols[i];
        }
    }
    return roman;
}
```

</details>

<br>

## Approach 2: Hardcode Digits

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char *intToRoman(int num) {
    const char *thousands[] = {"", "M", "MM", "MMM"};
    const char *hundreds[] = {"",  "C",  "CC",  "CCC",  "CD",
                              "D", "DC", "DCC", "DCCC", "CM"};
    const char *tens[] = {"",  "X",  "XX",  "XXX",  "XL",
                          "L", "LX", "LXX", "LXXX", "XC"};
    const char *ones[] = {"",  "I",  "II",  "III",  "IV",
                          "V", "VI", "VII", "VIII", "IX"};

    char *result = (char *)malloc(16 * sizeof(char));
    strcpy(result, "");

    strcat(result, thousands[num / 1000]);
    strcat(result, hundreds[num % 1000 / 100]);
    strcat(result, tens[num % 100 / 10]);
    strcat(result, ones[num % 10]);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    std::string intToRoman(int num) {
        std::vector<std::string> thousands = {"", "M", "MM", "MMM"};
        std::vector<std::string> hundreds = {"",  "C",  "CC",  "CCC",  "CD",
                                             "D", "DC", "DCC", "DCCC", "CM"};
        std::vector<std::string> tens = {"",  "X",  "XX",  "XXX",  "XL",
                                         "L", "LX", "LXX", "LXXX", "XC"};
        std::vector<std::string> ones = {"",  "I",  "II",  "III",  "IV",
                                         "V", "VI", "VII", "VIII", "IX"};
        return thousands[num / 1000] + hundreds[num % 1000 / 100] +
               tens[num % 100 / 10] + ones[num % 10];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private static readonly string[] thousands = { "", "M", "MM", "MMM" };

    private static readonly string[] hundreds = {
        "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
    };

    private static readonly string[] tens = { "",  "X",  "XX",  "XXX",  "XL",
                                              "L", "LX", "LXX", "LXXX", "XC" };

    private static readonly string[] ones = { "",  "I",  "II",  "III",  "IV",
                                              "V", "VI", "VII", "VIII", "IX" };

    public string IntToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] +
               tens[num % 100 / 10] + ones[num % 10];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func intToRoman(num int) string {
    thousands := []string{"", "M", "MM", "MMM"}
    hundreds := []string{
        "",
        "C",
        "CC",
        "CCC",
        "CD",
        "D",
        "DC",
        "DCC",
        "DCCC",
        "CM",
    }
    tens := []string{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
    ones := []string{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}

    return thousands[num/1000] + hundreds[num%1000/100] + tens[num%100/10] + ones[num%10]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static final String[] thousands = { "", "M", "MM", "MMM" };
    private static final String[] hundreds = {
        "",
        "C",
        "CC",
        "CCC",
        "CD",
        "D",
        "DC",
        "DCC",
        "DCCC",
        "CM",
    };
    private static final String[] tens = {
        "",
        "X",
        "XX",
        "XXX",
        "XL",
        "L",
        "LX",
        "LXX",
        "LXXX",
        "XC",
    };
    private static final String[] ones = {
        "",
        "I",
        "II",
        "III",
        "IV",
        "V",
        "VI",
        "VII",
        "VIII",
        "IX",
    };

    public String intToRoman(int num) {
        return (
            thousands[num / 1000] +
            hundreds[(num % 1000) / 100] +
            tens[(num % 100) / 10] +
            ones[num % 10]
        );
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var intToRoman = function (num) {
    let thousands = ["", "M", "MM", "MMM"];
    let hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];
    let tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
    let ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];

    return (
        thousands[Math.floor(num / 1000)] +
        hundreds[Math.floor((num % 1000) / 100)] +
        tens[Math.floor((num % 100) / 10)] +
        ones[num % 10]
    );
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def intToRoman(self, num: int) -> str:
        thousands = ["", "M", "MM", "MMM"]
        hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        return (
            thousands[num // 1000]
            + hundreds[num % 1000 // 100]
            + tens[num % 100 // 10]
            + ones[num % 10]
        )
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function intToRoman(num: number): string {
    let thousands: string[] = ["", "M", "MM", "MMM"];
    let hundreds: string[] = [
        "",
        "C",
        "CC",
        "CCC",
        "CD",
        "D",
        "DC",
        "DCC",
        "DCCC",
        "CM",
    ];
    let tens: string[] = [
        "",
        "X",
        "XX",
        "XXX",
        "XL",
        "L",
        "LX",
        "LXX",
        "LXXX",
        "XC",
    ];
    let ones: string[] = [
        "",
        "I",
        "II",
        "III",
        "IV",
        "V",
        "VI",
        "VII",
        "VIII",
        "IX",
    ];

    return (
        thousands[Math.floor(num / 1000)] +
        hundreds[Math.floor((num % 1000) / 100)] +
        tens[Math.floor((num % 100) / 10)] +
        ones[num % 10]
    );
}
```

</details>
