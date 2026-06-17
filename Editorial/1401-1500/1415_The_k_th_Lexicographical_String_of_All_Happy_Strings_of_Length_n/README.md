# 1415. The k-th Lexicographical String of All Happy Strings of Length n

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)  
`String` `Backtracking`

**Problem Link:** [LeetCode 1415 - The k-th Lexicographical String of All Happy Strings of Length n](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)

## Problem

A happy string is a string that:

- consists only of letters of the set ['a', 'b', 'c'].
- s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).

For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

### Example 1

```text
Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
```

### Example 2

```text
Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
```

### Example 3

```text
Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
```

## Constraints

- 1 <= n <= 10
- 1 <= k <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1415. The k-th Lexicographical String of All Happy Strings of Length n

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking (Optimized) | C++, Java, Python3 |
| Optimized Recursion | C++, Java, Python3 |
| Iterative Using a Stack | C++, Java, Python3 |
| Combinatorics | C++, Java, Python3 |

## Approach 1: Backtracking (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string getHappyString(int n, int k) {
        string currentString = "";
        vector<string> happyStrings;
        // Generate all happy strings of length n
        generateHappyStrings(n, currentString, happyStrings);

        // Check if there are at least k happy strings
        if (happyStrings.size() < k) return "";

        return happyStrings[k - 1];
    }

private:
    void generateHappyStrings(int n, string currentString,
                              vector<string> &happyStrings) {
        // If the current string has reached the desired length, add it to the
        // list
        if (currentString.size() == n) {
            happyStrings.push_back(currentString);
            return;
        }

        // Try adding each character ('a', 'b', 'c') to the current string
        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            // Skip if the current character is the same as the last character
            if (currentString.size() > 0 && currentString.back() == currentChar)
                continue;

            // Recursively generate the next character
            generateHappyStrings(n, currentString + currentChar, happyStrings);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    List<String> happyStrings = new ArrayList<>();

    public String getHappyString(int n, int k) {
        String currentString = "";
        // Generate all happy strings of length n
        generateHappyStrings(n, currentString);

        // Check if there are at least k happy strings
        if (happyStrings.size() < k) return "";

        return happyStrings.get(k - 1);
    }

    protected void generateHappyStrings(int n, String currentString) {
        // If the current string has reached the desired length, add it to the
        // list
        if (currentString.length() == n) {
            happyStrings.add(currentString);
            return;
        }

        // Try adding each character ('a', 'b', 'c') to the current string
        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            // Skip if the current character is the same as the last character
            if (
                currentString.length() > 0 &&
                currentString.charAt(currentString.length() - 1) == currentChar
            ) continue;

            // Recursively generate the next character
            generateHappyStrings(n, currentString + currentChar);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        current_string = ""
        happy_strings = []
        # Generate all happy strings of length n
        self.generate_happy_strings(n, current_string, happy_strings)

        # Check if there are at least k happy strings
        if len(happy_strings) < k:
            return ""

        return happy_strings[k - 1]

    def generate_happy_strings(
        self, n: int, current_string: str, happy_strings: list
    ):
        # If the current string has reached the desired length, add it to the list
        if len(current_string) == n:
            happy_strings.append(current_string)
            return

        # Try adding each character ('a', 'b', 'c') to the current string
        for current_char in ["a", "b", "c"]:
            # Skip if the current character is the same as the last character
            if len(current_string) > 0 and current_string[-1] == current_char:
                continue

            # Recursively generate the next character
            self.generate_happy_strings(
                n, current_string + current_char, happy_strings
            )
```

</details>

<br>

## Approach 2: Optimized Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string getHappyString(int n, int k) {
        string currentString = "";
        string result = "";
        int indexInSortedList = 0;

        // Generate happy strings and track the k-th string
        generateHappyStrings(n, k, currentString, indexInSortedList, result);
        return result;
    }

private:
    void generateHappyStrings(int n, int k, string &currentString,
                              int &indexInSortedList, string &result) {
        // If the current string has reached the desired length
        if (currentString.size() == n) {
            indexInSortedList++;  // Increment the count of generated strings

            // If this is the k-th string, store it in the result
            if (indexInSortedList == k) result = currentString;
            return;
        }

        // Try adding each character ('a', 'b', 'c') to the current string
        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            // Skip if the current character is the same as the last one
            if (currentString.size() > 0 && currentString.back() == currentChar)
                continue;

            currentString += currentChar;

            // Recursively generate the next character
            generateHappyStrings(n, k, currentString, indexInSortedList,
                                 result);

            // If the result is found, stop further processing
            if (result != "") return;

            // Backtrack by removing the last character
            currentString.pop_back();
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private void generateHappyStrings(
        int n,
        int k,
        StringBuilder currentString,
        int[] indexInSortedList,
        String[] result
    ) {
        // If the current string has reached the desired length
        if (currentString.length() == n) {
            indexInSortedList[0]++; // Increment the count of generated strings

            // If this is the k-th string, store it in the result
            if (indexInSortedList[0] == k) result[0] = currentString.toString();
            return;
        }

        // Try adding each character ('a', 'b', 'c') to the current string
        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            // Skip if the current character is the same as the last one
            if (
                currentString.length() > 0 &&
                currentString.charAt(currentString.length() - 1) == currentChar
            ) continue;

            currentString.append(currentChar);

            // Recursively generate the next character
            generateHappyStrings(
                n,
                k,
                currentString,
                indexInSortedList,
                result
            );

            // If the result is found, stop further processing
            if (result[0] != null) return;

            // Backtrack by removing the last character
            currentString.deleteCharAt(currentString.length() - 1);
        }
    }

    public String getHappyString(int n, int k) {
        StringBuilder currentString = new StringBuilder();
        String[] result = new String[1];
        int[] indexInSortedList = new int[1];

        // Generate happy strings and track the k-th string
        generateHappyStrings(n, k, currentString, indexInSortedList, result);
        return result[0] == null ? "" : result[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        self.current_string = ""
        self.result = ""
        self.index_in_sorted_list = 0

        # Generate happy strings and track the k-th string
        self.generate_happy_strings(n, k)
        return self.result

    def generate_happy_strings(self, n, k):
        # If the current string has reached the desired length
        if len(self.current_string) == n:
            # Increment the count of generated strings
            self.index_in_sorted_list += 1

            # If this is the k-th string, store it in the result
            if self.index_in_sorted_list == k:
                self.result = self.current_string
            return

        # Try adding each character ('a', 'b', 'c') to the current string
        for current_char in ["a", "b", "c"]:
            # Skip if the current character is the same as the last one
            if (
                len(self.current_string) > 0
                and self.current_string[-1] == current_char
            ):
                continue

            self.current_string += current_char

            # Recursively generate the next character
            self.generate_happy_strings(n, k)

            # If the result is found, stop further processing
            if self.result != "":
                return

            # Backtrack by removing the last character
            self.current_string = self.current_string[:-1]
```

</details>

<br>

## Approach 3: Iterative Using a Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string getHappyString(int n, int k) {
        stack<string> stringsStack;
        int indexInSortedList = 0;
        stringsStack.push("");  // Start with an empty string

        while (stringsStack.size() > 0) {
            string currentString = stringsStack.top();
            stringsStack.pop();

            // If we have built a string of length n, count it
            if (currentString.size() == n) {
                indexInSortedList++;
                // If we reach the k-th happy string, return it
                if (indexInSortedList == k) {
                    return currentString;
                }
                continue;
            }

            // Expand the current string by adding 'a', 'b', or 'c'
            // Ensuring lexicographic order by pushing in reverse
            for (char currentChar = 'c'; currentChar >= 'a'; currentChar--) {
                // Avoid consecutive identical characters
                if (currentString.size() > 0 &&
                    currentString.back() == currentChar)
                    continue;
                stringsStack.push(currentString + currentChar);
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
class Solution {

    public String getHappyString(int n, int k) {
        Stack<String> stringsStack = new Stack<>();
        int indexInSortedList = 0;
        stringsStack.push(""); // Start with an empty string

        while (stringsStack.size() > 0) {
            String currentString = stringsStack.pop();

            // If we have built a string of length n, count it
            if (currentString.length() == n) {
                indexInSortedList++;
                // If we reach the k-th happy string, return it
                if (indexInSortedList == k) {
                    return currentString;
                }
                continue;
            }

            // Expand the current string by adding 'a', 'b', or 'c'
            // Ensuring lexicographic order by pushing in reverse
            for (char currentChar = 'c'; currentChar >= 'a'; currentChar--) {
                // Avoid consecutive identical characters
                if (
                    currentString.length() == 0 ||
                    currentString.charAt(currentString.length() - 1) !=
                    currentChar
                ) {
                    stringsStack.push(currentString + currentChar);
                }
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
    def getHappyString(self, n: int, k: int) -> str:
        strings_stack = []
        index_in_sorted_list = 0
        strings_stack.append("")  # Start with an empty string

        while strings_stack:
            current_string = strings_stack.pop()

            # If we have built a string of length n, count it
            if len(current_string) == n:
                index_in_sorted_list += 1
                # If we reach the k-th happy string, return it
                if index_in_sorted_list == k:
                    return current_string
                continue

            # Expand the current string by adding 'a', 'b', or 'c'
            # Ensuring lexicographic order by pushing in reverse
            for current_char in reversed(["a", "b", "c"]):
                # Avoid consecutive identical characters
                if (
                    len(current_string) == 0
                    or current_string[-1] != current_char
                ):
                    strings_stack.append(current_string + current_char)
        return ""
```

</details>

<br>

## Approach 4: Combinatorics

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string getHappyString(int n, int k) {
        // Calculate the total number of happy strings of length n
        int total = 3 * (1 << (n - 1));

        // If k is greater than the total number of happy strings, return an
        // empty string
        if (k > total) return "";

        string result(n, 'a');

        // Define mappings for the next smallest and greatest valid characters
        unordered_map<char, char> nextSmallest = {
            {'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        unordered_map<char, char> nextGreatest = {
            {'a', 'c'}, {'b', 'c'}, {'c', 'b'}};

        // Calculate the starting indices for strings beginning with 'a', 'b',
        // and 'c'
        int startA = 1;
        int startB = startA + (1 << (n - 1));
        int startC = startB + (1 << (n - 1));

        // Determine the first character based on the value of k
        if (k < startB) {
            result[0] = 'a';
            k -= startA;
        } else if (k < startC) {
            result[0] = 'b';
            k -= startB;
        } else {
            result[0] = 'c';
            k -= startC;
        }

        // Iterate through the remaining positions in the result string
        for (int charIndex = 1; charIndex < n; charIndex++) {
            // Calculate the midpoint of the group for the current character
            // position
            int midpoint = (1 << (n - charIndex - 1));

            // Determine the next character based on the value of k
            if (k < midpoint) {
                result[charIndex] = nextSmallest[result[charIndex - 1]];
            } else {
                result[charIndex] = nextGreatest[result[charIndex - 1]];
                k -= midpoint;
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public String getHappyString(int n, int k) {
        // Calculate the total number of happy strings of length n
        int total = 3 * (1 << (n - 1));

        // If k is greater than the total number of happy strings, return an empty string
        if (k > total) return "";

        StringBuilder result = new StringBuilder(n);
        // Initialize result with 'a' characters
        for (int i = 0; i < n; i++) {
            result.append('a');
        }

        // Define mappings for the next smallest and greatest valid characters
        Map<Character, Character> nextSmallest = new HashMap<>();
        nextSmallest.put('a', 'b');
        nextSmallest.put('b', 'a');
        nextSmallest.put('c', 'a');

        Map<Character, Character> nextGreatest = new HashMap<>();
        nextGreatest.put('a', 'c');
        nextGreatest.put('b', 'c');
        nextGreatest.put('c', 'b');

        // Calculate the starting indices for strings beginning with 'a', 'b', and 'c'
        int startA = 1;
        int startB = startA + (1 << (n - 1));
        int startC = startB + (1 << (n - 1));

        // Determine the first character based on the value of k
        if (k < startB) {
            result.setCharAt(0, 'a');
            k -= startA;
        } else if (k < startC) {
            result.setCharAt(0, 'b');
            k -= startB;
        } else {
            result.setCharAt(0, 'c');
            k -= startC;
        }

        // Iterate through the remaining positions in the result string
        for (int charIndex = 1; charIndex < n; charIndex++) {
            // Calculate the midpoint of the group for the current character position
            int midpoint = (1 << (n - charIndex - 1));

            // Determine the next character based on the value of k
            if (k < midpoint) {
                result.setCharAt(
                    charIndex,
                    nextSmallest.get(result.charAt(charIndex - 1))
                );
            } else {
                result.setCharAt(
                    charIndex,
                    nextGreatest.get(result.charAt(charIndex - 1))
                );
                k -= midpoint;
            }
        }

        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        # Calculate the total number of happy strings of length n
        total = 3 * (1 << (n - 1))

        # If k is greater than the total number of happy strings, return an empty string
        if k > total:
            return ""

        result = ["a"] * n  # Initialize result with 'a' characters

        # Define mappings for the next smallest and greatest valid characters
        next_smallest = {"a": "b", "b": "a", "c": "a"}
        next_greatest = {"a": "c", "b": "c", "c": "b"}

        # Calculate the starting indices for strings beginning with 'a', 'b', and 'c'
        start_a = 1
        start_b = start_a + (1 << (n - 1))
        start_c = start_b + (1 << (n - 1))

        # Determine the first character based on the value of k
        if k < start_b:
            result[0] = "a"
            k -= start_a
        elif k < start_c:
            result[0] = "b"
            k -= start_b
        else:
            result[0] = "c"
            k -= start_c

        # Iterate through the remaining positions in the result string
        for char_index in range(1, n):
            # Calculate the midpoint of the group for the current character position
            midpoint = 1 << (n - char_index - 1)

            # Determine the next character based on the value of k
            if k < midpoint:
                result[char_index] = next_smallest[result[char_index - 1]]
            else:
                result[char_index] = next_greatest[result[char_index - 1]]
                k -= midpoint

        return "".join(result)
```

</details>
