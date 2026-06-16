# 273. Integer to English Words

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/integer-to-english-words/)  
`Math` `String` `Recursion`

**Problem Link:** [LeetCode 273 - Integer to English Words](https://leetcode.com/problems/integer-to-english-words/)

## Problem

Convert a non-negative integer num to its English words representation.

### Example 1

```text
Input: num = 123
Output: "One Hundred Twenty Three"
```

### Example 2

```text
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
```

### Example 3

```text
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
```

## Constraints

- 0 <= num <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 273. Integer to English Words

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Approach | C++, Java, Python3 |
| Iterative Approach | C++, Java, Python3 |
| Pair-Based Approach | C++, Java, Python3 |

## Approach 1: Recursive Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Arrays to store words for numbers less than 10, 20, and 100
    const vector<string> belowTen = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    const vector<string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    const vector<string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    // Main function to convert a number to English words
    string numberToWords(int num) {
        // Handle the special case where the number is zero
        if (num == 0) {
            return "Zero";
        }
        // Call the helper function to start the conversion
        return convertToWords(num);
    }

private:
    // Recursive function to convert numbers to words
    // Handles numbers based on their ranges: <10, <20, <100, <1000, <1000000, <1000000000, and >=1000000000
    string convertToWords(int num) {
        if (num < 10) {
            return belowTen[num];
        }
        if (num < 20) {
            return belowTwenty[num - 10];
        }
        if (num < 100) {
            return belowHundred[num / 10] + (num % 10 ? " " + convertToWords(num % 10) : "");
        }
        if (num < 1000) {
            return convertToWords(num / 100) + " Hundred" + (num % 100 ? " " + convertToWords(num % 100) : "");
        }
        if (num < 1000000) {
            return convertToWords(num / 1000) + " Thousand" + (num % 1000 ? " " + convertToWords(num % 1000) : "");
        }
        if (num < 1000000000) {
            return convertToWords(num / 1000000) + " Million" + (num % 1000000 ? " " + convertToWords(num % 1000000) : "");
        }
        return convertToWords(num / 1000000000) + " Billion" + (num % 1000000000 ? " " + convertToWords(num % 1000000000) : "");
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Arrays to store words for numbers less than 10, 20, and 100
    private static final String[] belowTen = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    private static final String[] belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    private static final String[] belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    // Main function to convert a number to English words
    public String numberToWords(int num) {
        // Handle the special case where the number is zero
        if (num == 0) {
            return "Zero";
        }
        // Call the helper function to start the conversion
        return convertToWords(num);
    }

    // Recursive function to convert numbers to words
    // Handles numbers based on their ranges: <10, <20, <100, <1000, <1000000, <1000000000, and >=1000000000
    private String convertToWords(int num) {
        if (num < 10) {
            return belowTen[num];
        }
        if (num < 20) {
            return belowTwenty[num - 10];
        }
        if (num < 100) {
            return belowHundred[num / 10] + (num % 10 != 0 ? " " + convertToWords(num % 10) : "");
        }
        if (num < 1000) {
            return convertToWords(num / 100) + " Hundred" + (num % 100 != 0 ? " " + convertToWords(num % 100) : "");
        }
        if (num < 1000000) {
            return convertToWords(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + convertToWords(num % 1000) : "");
        }
        if (num < 1000000000) {
            return convertToWords(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + convertToWords(num % 1000000) : "");
        }
        return convertToWords(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + convertToWords(num % 1000000000) : "");
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Arrays to store words for numbers less than 10, 20, and 100
    below_ten = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
    below_twenty = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
    below_hundred = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]

    # Main function to convert a number to English words
    def numberToWords(self, num: int) -> str:
        # Handle the special case where the number is zero
        if num == 0:
            return "Zero"
        # Call the helper function to start the conversion
        return self._convert_to_words(num)

    # Recursive function to convert numbers to words
    # Handles numbers based on their ranges: <10, <20, <100, <1000, <1000000, <1000000000, and >=1000000000
    def _convert_to_words(self, num: int) -> str:
        if num < 10:
            return self.below_ten[num]
        if num < 20:
            return self.below_twenty[num - 10]
        if num < 100:
            return self.below_hundred[num // 10] + (" " + self._convert_to_words(num % 10) if num % 10 != 0 else "")
        if num < 1000:
            return self._convert_to_words(num // 100) + " Hundred" + (" " + self._convert_to_words(num % 100) if num % 100 != 0 else "")
        if num < 1000000:
            return self._convert_to_words(num // 1000) + " Thousand" + (" " + self._convert_to_words(num % 1000) if num % 1000 != 0 else "")
        if num < 1000000000:
            return self._convert_to_words(num // 1000000) + " Million" + (" " + self._convert_to_words(num % 1000000) if num % 1000000 != 0 else "")
        return self._convert_to_words(num // 1000000000) + " Billion" + (" " + self._convert_to_words(num % 1000000000) if num % 1000000000 != 0 else "")
```

</details>

<br>

## Approach 2: Iterative Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string numberToWords(int num) {
        // Handle the special case where the number is zero
        if (num == 0) return "Zero";

        // Arrays to store words for single digits, tens, and thousands
        const vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        const vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        // StringBuilder to accumulate the result
        string result = "";
        int groupIndex = 0;

        // Process the number in chunks of 1000
        while (num > 0) {
            // Process the last three digits
            if (num % 1000 != 0) {
                string groupResult = "";
                int part = num % 1000;

                // Handle hundreds
                if (part >= 100) {
                    groupResult = ones[part / 100] + " Hundred ";
                    part %= 100;
                }

                // Handle tens and units
                if (part >= 20) {
                    groupResult += tens[part / 10] + " ";
                    part %= 10;
                }

                // Handle units
                if (part > 0) {
                    groupResult += ones[part] + " ";
                }

                // Append the scale (thousand, million, billion) for the current group
                groupResult += thousands[groupIndex] + " ";
                // Insert the group result at the beginning of the final result
                result = groupResult + result;
            }
            // Move to the next chunk of 1000
            num /= 1000;
            groupIndex++;
        }

        return result.substr(0, result.find_last_not_of(" ") + 1); // Remove trailing spaces
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String numberToWords(int num) {
        // Handle the special case where the number is zero
        if (num == 0) return "Zero";

        // Arrays to store words for single digits, tens, and thousands
        String[] ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        String[] tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        String[] thousands = {"", "Thousand", "Million", "Billion"};

        // StringBuilder to accumulate the result
        StringBuilder result = new StringBuilder();
        int groupIndex = 0;

        // Process the number in chunks of 1000
        while (num > 0) {
            // Process the last three digits
            if (num % 1000 != 0) {
                StringBuilder groupResult = new StringBuilder();
                int part = num % 1000;

                // Handle hundreds
                if (part >= 100) {
                    groupResult.append(ones[part / 100]).append(" Hundred ");
                    part %= 100;
                }

                // Handle tens and units
                if (part >= 20) {
                    groupResult.append(tens[part / 10]).append(" ");
                    part %= 10;
                }

                // Handle units
                if (part > 0) {
                    groupResult.append(ones[part]).append(" ");
                }

                // Append the scale (thousand, million, billion) for the current group
                groupResult.append(thousands[groupIndex]).append(" ");
                // Insert the group result at the beginning of the final result
                result.insert(0, groupResult);
            }
            // Move to the next chunk of 1000
            num /= 1000;
            groupIndex++;
        }

        return result.toString().trim();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberToWords(self, num: int) -> str:
        # Handle the special case where the number is zero
        if num == 0:
            return "Zero"

        # Arrays to store words for single digits, tens, and thousands
        ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        thousands = ["", "Thousand", "Million", "Billion"]

        # StringBuilder to accumulate the result
        result = ""
        group_index = 0

        # Process the number in chunks of 1000
        while num > 0:
            # Process the last three digits
            if num % 1000 != 0:
                group_result = ""
                part = num % 1000

                # Handle hundreds
                if part >= 100:
                    group_result += ones[part // 100] + " Hundred "
                    part %= 100

                # Handle tens and units
                if part >= 20:
                    group_result += tens[part // 10] + " "
                    part %= 10

                # Handle units
                if part > 0:
                    group_result += ones[part] + " "

                # Append the scale (thousand, million, billion) for the current group
                group_result += thousands[group_index] + " "
                # Insert the group result at the beginning of the final result
                result = group_result + result
            # Move to the next chunk of 1000
            num //= 1000
            group_index += 1

        return result.strip()
```

</details>

<br>

## Approach 3: Pair-Based Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Mapping of numeric values to their corresponding English words
    vector<pair<int, string>> numberToWordsMap = {
        {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"},
        {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
        {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"},
        {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"},
        {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"},
        {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"},
        {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"},
        {2, "Two"}, {1, "One"}
    };

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        for (auto& [value, word] : numberToWordsMap) {
            // Check if the number is greater than or equal to the current unit
            if (num >= value) {
                // Convert the quotient to words if the current unit is 100 or greater
                string prefix = (num >= 100) ? numberToWords(num / value) + " " : "";

                // Get the word for the current unit
                string unit = word;

                // Convert the remainder to words if it's not zero
                string suffix = (num % value == 0) ? "" : " " + numberToWords(num % value);

                return prefix + unit + suffix;
            }
        }

        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class NumberWord {
    int value;
    String word;

    NumberWord(int value, String word) {
        this.value = value;
        this.word = word;
    }
}

class Solution {
    // List to store words for numbers
    private static final List<NumberWord> numberToWordsList = Arrays.asList(
        new NumberWord(1000000000, "Billion"), new NumberWord(1000000, "Million"),
        new NumberWord(1000, "Thousand"), new NumberWord(100, "Hundred"),
        new NumberWord(90, "Ninety"), new NumberWord(80, "Eighty"),
        new NumberWord(70, "Seventy"), new NumberWord(60, "Sixty"),
        new NumberWord(50, "Fifty"), new NumberWord(40, "Forty"),
        new NumberWord(30, "Thirty"), new NumberWord(20, "Twenty"),
        new NumberWord(19, "Nineteen"), new NumberWord(18, "Eighteen"),
        new NumberWord(17, "Seventeen"), new NumberWord(16, "Sixteen"),
        new NumberWord(15, "Fifteen"), new NumberWord(14, "Fourteen"),
        new NumberWord(13, "Thirteen"), new NumberWord(12, "Twelve"),
        new NumberWord(11, "Eleven"), new NumberWord(10, "Ten"),
        new NumberWord(9, "Nine"), new NumberWord(8, "Eight"),
        new NumberWord(7, "Seven"), new NumberWord(6, "Six"),
        new NumberWord(5, "Five"), new NumberWord(4, "Four"),
        new NumberWord(3, "Three"), new NumberWord(2, "Two"),
        new NumberWord(1, "One")
    );

    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        for (NumberWord nw : numberToWordsList) {
            // Check if the number is greater than or equal to the current unit
            if (num >= nw.value) {
                // Convert the quotient to words if the current unit is 100 or greater
                String prefix = (num >= 100) ? numberToWords(num / nw.value) + " " : "";

                // Get the word for the current unit
                String unit = nw.word;

                // Convert the remainder to words if it's not zero
                String suffix = (num % nw.value == 0) ? "" : " " + numberToWords(num % nw.value);

                return prefix + unit + suffix;
            }
        }

        return "";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Dictionary to store words for numbers
    number_to_words_map = {
        1000000000: "Billion", 1000000: "Million", 1000: "Thousand",
        100: "Hundred", 90: "Ninety", 80: "Eighty", 70: "Seventy",
        60: "Sixty", 50: "Fifty", 40: "Forty", 30: "Thirty",
        20: "Twenty", 19: "Nineteen", 18: "Eighteen", 17: "Seventeen",
        16: "Sixteen", 15: "Fifteen", 14: "Fourteen", 13: "Thirteen",
        12: "Twelve", 11: "Eleven", 10: "Ten", 9: "Nine", 8: "Eight",
        7: "Seven", 6: "Six", 5: "Five", 4: "Four", 3: "Three",
        2: "Two", 1: "One"
    }

    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"

        for value, word in self.number_to_words_map.items():
            # Check if the number is greater than or equal to the current unit
            if num >= value:
                # Convert the quotient to words if the current unit is 100 or greater
                prefix = (self.numberToWords(num // value) + " ") if num >= 100 else ""

                # Get the word for the current unit
                unit = word

                # Convert the remainder to words if it's not zero
                suffix = "" if num % value == 0 else " " + self.numberToWords(num % value)

                return prefix + unit + suffix

        return ""
```

</details>
