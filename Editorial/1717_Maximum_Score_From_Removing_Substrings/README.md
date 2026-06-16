# 1717. Maximum Score From Removing Substrings

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-score-from-removing-substrings/)  
`String` `Stack` `Greedy`

**Problem Link:** [LeetCode 1717 - Maximum Score From Removing Substrings](https://leetcode.com/problems/maximum-score-from-removing-substrings/)

## Problem

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

- Remove substring "ab" and gain x points.

		For example, when removing "ab" from "cabxbae" it becomes "cxbae".
- Remove substring "ba" and gain y points.

		For example, when removing "ba" from "cabxbae" it becomes "cabxe".

Return the maximum points you can gain after applying the above operations on s.

### Example 1

```text
Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
```

### Example 2

```text
Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
```

## Constraints

- 1 <= s.length <= 105
- 1 <= x, y <= 104
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Words Obtained After Adding a Letter](https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1717. Maximum Score From Removing Substrings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy Way (Stack) | C++, Java, Python3 |
| Greedy Way (Without Stack) | C++, Java, Python3 |
| Greedy Way (Counting) | C++, Java, Python3 |

## Approach 1: Greedy Way (Stack)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string highPriorityPair = x > y ? "ab" : "ba";
        string lowPriorityPair = highPriorityPair == "ab" ? "ba" : "ab";

        // First pass: remove high priority pair
        string stringAfterFirstPass = removeSubstring(s, highPriorityPair);
        int removedPairsCount =
            (s.length() - stringAfterFirstPass.length()) / 2;

        // Calculate score from first pass
        totalScore += removedPairsCount * max(x, y);

        // Second pass: remove low priority pair
        string stringAfterSecondPass =
            removeSubstring(stringAfterFirstPass, lowPriorityPair);
        removedPairsCount =
            (stringAfterFirstPass.length() - stringAfterSecondPass.length()) /
            2;

        // Calculate score from second pass
        totalScore += removedPairsCount * min(x, y);

        return totalScore;
    }

private:
    string removeSubstring(const string& input, const string& targetPair) {
        stack<char> charStack;

        // Iterate through each character in the input string
        for (char currentChar : input) {
            // Check if current character forms the target pair with the top of
            // the stack
            if (currentChar == targetPair[1] && !charStack.empty() &&
                charStack.top() == targetPair[0]) {
                charStack
                    .pop();  // Remove the matching character from the stack
            } else {
                charStack.push(currentChar);
            }
        }

        // Reconstruct the remaining string after removing target pairs
        string remainingChars;
        while (!charStack.empty()) {
            remainingChars += charStack.top();
            charStack.pop();
        }
        reverse(remainingChars.begin(), remainingChars.end());
        return remainingChars;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumGain(String s, int x, int y) {
        int totalScore = 0;
        String highPriorityPair = x > y ? "ab" : "ba";
        String lowPriorityPair = highPriorityPair.equals("ab") ? "ba" : "ab";

        // First pass: remove high priority pair
        String stringAfterFirstPass = removeSubstring(s, highPriorityPair);
        int removedPairsCount =
            (s.length() - stringAfterFirstPass.length()) / 2;

        // Calculate score from first pass
        totalScore += removedPairsCount * Math.max(x, y);

        // Second pass: remove low priority pair
        String stringAfterSecondPass = removeSubstring(
            stringAfterFirstPass,
            lowPriorityPair
        );
        removedPairsCount = (stringAfterFirstPass.length() -
            stringAfterSecondPass.length()) /
        2;

        // Calculate score from second pass
        totalScore += removedPairsCount * Math.min(x, y);

        return totalScore;
    }

    private String removeSubstring(String input, String targetPair) {
        Stack<Character> charStack = new Stack<>();

        // Iterate through each character in the input string
        for (int i = 0; i < input.length(); i++) {
            char currentChar = input.charAt(i);

            // Check if current character forms the target pair with the top of the stack
            if (
                currentChar == targetPair.charAt(1) &&
                !charStack.isEmpty() &&
                charStack.peek() == targetPair.charAt(0)
            ) {
                charStack.pop(); // Remove the matching character from the stack
            } else {
                charStack.push(currentChar);
            }
        }

        // Reconstruct the remaining string after removing target pairs
        StringBuilder remainingChars = new StringBuilder();
        while (!charStack.isEmpty()) {
            remainingChars.append(charStack.pop());
        }
        return remainingChars.reverse().toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        total_score = 0
        high_priority_pair = "ab" if x > y else "ba"
        low_priority_pair = "ba" if high_priority_pair == "ab" else "ab"

        # First pass: remove high priority pair
        string_after_first_pass = self.remove_substring(s, high_priority_pair)
        removed_pairs_count = (len(s) - len(string_after_first_pass)) // 2

        # Calculate score from first pass
        total_score += removed_pairs_count * max(x, y)

        # Second pass: remove low priority pair
        string_after_second_pass = self.remove_substring(
            string_after_first_pass, low_priority_pair
        )
        removed_pairs_count = (
            len(string_after_first_pass) - len(string_after_second_pass)
        ) // 2

        # Calculate score from second pass
        total_score += removed_pairs_count * min(x, y)

        return total_score

    def remove_substring(self, input: str, target_pair: str) -> str:
        char_stack = []

        # Iterate through each character in the input string
        for current_char in input:
            # Check if current character forms the target pair with the top of the stack
            if (
                current_char == target_pair[1]
                and char_stack
                and char_stack[-1] == target_pair[0]
            ):
                char_stack.pop()  # Remove the matching character from the stack
            else:
                char_stack.append(current_char)

        # Reconstruct the remaining string after removing target pairs
        return "".join(char_stack)
```

</details>

<br>

## Approach 2: Greedy Way (Without Stack)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalPoints = 0;

        if (x > y) {
            // Remove "ab" first (higher points), then "ba"
            totalPoints += removeSubstring(s, "ab", x);
            totalPoints += removeSubstring(s, "ba", y);
        } else {
            // Remove "ba" first (higher or equal points), then "ab"
            totalPoints += removeSubstring(s, "ba", y);
            totalPoints += removeSubstring(s, "ab", x);
        }

        return totalPoints;
    }

    int removeSubstring(string& inputString, string targetSubstring,
                        int pointsPerRemoval) {
        int totalPoints = 0;
        int writeIndex = 0;

        // Iterate through the string
        for (int readIndex = 0; readIndex < inputString.size(); readIndex++) {
            // Add the current character
            inputString[writeIndex++] = inputString[readIndex];

            // Check if we've written at least two characters and
            // they match the target substring
            if (writeIndex > 1 &&
                inputString[writeIndex - 2] == targetSubstring[0] &&
                inputString[writeIndex - 1] == targetSubstring[1]) {
                writeIndex -= 2;  // Move write index back to remove the match
                totalPoints += pointsPerRemoval;
            }
        }

        // Trim the string to remove any leftover characters
        inputString.erase(inputString.begin() + writeIndex, inputString.end());

        return totalPoints;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumGain(String s, int x, int y) {
        StringBuilder text = new StringBuilder(s);
        int totalPoints = 0;

        if (x > y) {
            // Remove "ab" first (higher points), then "ba"
            totalPoints += removeSubstring(text, "ab", x);
            totalPoints += removeSubstring(text, "ba", y);
        } else {
            // Remove "ba" first (higher or equal points), then "ab"
            totalPoints += removeSubstring(text, "ba", y);
            totalPoints += removeSubstring(text, "ab", x);
        }

        return totalPoints;
    }

    private int removeSubstring(
        StringBuilder inputString,
        String targetSubstring,
        int pointsPerRemoval
    ) {
        int totalPoints = 0;
        int writeIndex = 0;

        // Iterate through the string
        for (int readIndex = 0; readIndex < inputString.length(); readIndex++) {
            // Add the current character
            inputString.setCharAt(writeIndex++, inputString.charAt(readIndex));

            // Check if we've written at least two characters and
            // they match the target substring
            if (
                writeIndex > 1 &&
                inputString.charAt(writeIndex - 2) ==
                targetSubstring.charAt(0) &&
                inputString.charAt(writeIndex - 1) == targetSubstring.charAt(1)
            ) {
                writeIndex -= 2; // Move write index back to remove the match
                totalPoints += pointsPerRemoval;
            }
        }

        // Trim the StringBuilder to remove any leftover characters
        inputString.setLength(writeIndex);

        return totalPoints;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def maximumGain(self, s: str, x: int, y: int) -> int:
        total_points = 0
        s = list(s)

        if x > y:
            # Remove "ab" first (higher points), then "ba"
            total_points += self.remove_substring(s, "ab", x)
            total_points += self.remove_substring(s, "ba", y)
        else:
            # Remove "ba" first (higher or equal points), then "ab"
            total_points += self.remove_substring(s, "ba", y)
            total_points += self.remove_substring(s, "ab", x)

        return total_points

    def remove_substring(
        self, input_string, target_substring, points_per_removal
    ):
        total_points = 0
        write_index = 0

        # Iterate through the string
        for read_index in range(0, len(input_string)):
            # Add the current character
            input_string[write_index] = input_string[read_index]
            write_index += 1

            # Check if we've written at least two characters and
            # they match the target substring
            if (
                write_index > 1
                and input_string[write_index - 2] == target_substring[0]
                and input_string[write_index - 1] == target_substring[1]
            ):
                write_index -= 2
                total_points += points_per_removal

        # Trim the list to remove any leftover characters
        del input_string[write_index:]

        return total_points
```

</details>

<br>

## Approach 3: Greedy Way (Counting)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Ensure "ab" always has more points than "ba"
        if (x < y) {
            // Swap points
            int temp = x;
            x = y;
            y = temp;
            // Reverse the string to maintain logic
            reverse(s.begin(), s.end());
        }

        int aCount = 0, bCount = 0, totalPoints = 0;

        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];

            if (currentChar == 'a') {
                ++aCount;
            } else if (currentChar == 'b') {
                if (aCount > 0) {
                    // Can form "ab", remove it and add points
                    --aCount;
                    totalPoints += x;
                } else {
                    // Can't form "ab", keep 'b' for potential future "ba"
                    ++bCount;
                }
            } else {
                // Non 'a' or 'b' character encountered
                // Calculate points for any remaining "ba" pairs
                totalPoints += min(bCount, aCount) * y;
                // Reset counters for next segment
                aCount = bCount = 0;
            }
        }
        // Calculate points for any remaining "ba" pairs at the end
        totalPoints += min(bCount, aCount) * y;

        return totalPoints;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumGain(String s, int x, int y) {
        // Ensure "ab" always has higher points than "ba"
        if (x < y) {
            // Swap points
            int temp = x;
            x = y;
            y = temp;
            // Reverse the string to maintain logic
            s = new StringBuilder(s).reverse().toString();
        }

        int aCount = 0, bCount = 0, totalPoints = 0;

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);

            if (currentChar == 'a') {
                aCount++;
            } else if (currentChar == 'b') {
                if (aCount > 0) {
                    // Can form "ab", remove it and add points
                    aCount--;
                    totalPoints += x;
                } else {
                    // Can't form "ab", keep 'b' for potential future "ba"
                    bCount++;
                }
            } else {
                // Non 'a' or 'b' character encountered
                // Calculate points for any remaining "ba" pairs
                totalPoints += Math.min(bCount, aCount) * y;
                // Reset counters for next segment
                aCount = bCount = 0;
            }
        }

        // Calculate points for any remaining "ba" pairs at the end
        totalPoints += Math.min(bCount, aCount) * y;

        return totalPoints;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        # Ensure "ab" always has higher points than "ba"
        if x < y:
            # Reverse the string to maintain logic
            s = s[::-1]
            # Swap points
            x, y = y, x

        a_count, b_count, total_points = 0, 0, 0

        for i in range(len(s)):
            if s[i] == "a":
                a_count += 1
            elif s[i] == "b":
                if a_count > 0:
                    # Can form "ab", remove it and add points
                    a_count -= 1
                    total_points += x
                else:
                    # Can't form "ab", keep 'b' for potential future "ba"
                    b_count += 1
            else:
                # Non 'a' or 'b' character encountered
                # Calculate points for any remaining "ba" pairs
                total_points += min(b_count, a_count) * y
                # Reset counters for next segment
                a_count = b_count = 0

        # Calculate points for any remaining "ba" pairs at the end
        total_points += min(b_count, a_count) * y

        return total_points
```

</details>
