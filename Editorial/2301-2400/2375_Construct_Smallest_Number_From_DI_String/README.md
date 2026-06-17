# 2375. Construct Smallest Number From DI String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/construct-smallest-number-from-di-string/)  
`String` `Backtracking` `Stack` `Greedy`

**Problem Link:** [LeetCode 2375 - Construct Smallest Number From DI String](https://leetcode.com/problems/construct-smallest-number-from-di-string/)

## Problem

You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

- num consists of the digits '1' to '9', where each digit is used at most once.
- If pattern[i] == 'I', then num[i] < num[i + 1].
- If pattern[i] == 'D', then num[i] > num[i + 1].

Return the lexicographically smallest possible string num that meets the conditions.

### Example 1

```text
Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
```

### Example 2

```text
Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.
```

## Constraints

- 1 <= pattern.length <= 8
- pattern consists of only the letters 'I' and 'D'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [DI String Match](https://leetcode.com/problems/di-string-match/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2375. Construct Smallest Number From DI String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Optimization with Bit Masking | C++, Java, Python3 |
| Regulated Brute Force via Recursion | C++, Java, Python3 |
| Using Stack | C++, Java, Python3 |
| Greedy Approach with Sliding Window Reversal | C++, Java, Python3 |
| Optimized Greedy Approach with Precomputed 'D' Segments | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Check if the current sequence matches the pattern of 'I' and 'D'
    bool check(string &sequence, string &pattern) {
        for (int patternIndex = 0; patternIndex < pattern.size();
             patternIndex++) {
            if (pattern[patternIndex] == 'I') {
                // Ensure the sequence is in increasing order at 'I' positions
                if (sequence[patternIndex] > sequence[patternIndex + 1])
                    return false;
            } else {
                // Ensure the sequence is in decreasing order at 'D' positions
                if (sequence[patternIndex] < sequence[patternIndex + 1])
                    return false;
            }
        }
        return true;
    }

    string smallestNumber(string pattern) {
        int patternLength = pattern.size();
        string sequence = "";

        // Create a sequence of numbers from 1 to n+1
        for (int number = 1; number <= 1 + patternLength; number++) {
            sequence.push_back(number + '0');
        }

        string permutation = sequence;

        // Keep finding the next permutation until it matches the pattern
        while (!check(permutation, pattern)) {
            next_permutation(permutation.begin(), permutation.end());
        }

        return permutation;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Check if the current sequence matches the pattern of 'I' and 'D'
    private boolean check(String sequence, String pattern) {
        for (int index = 0; index < pattern.length(); index++) {
            if (pattern.charAt(index) == 'I') {
                // Ensure the sequence is in increasing order at 'I' positions
                if (sequence.charAt(index) > sequence.charAt(index + 1)) {
                    return false;
                }
            } else {
                // Ensure the sequence is in decreasing order at 'D' positions
                if (sequence.charAt(index) < sequence.charAt(index + 1)) {
                    return false;
                }
            }
        }
        return true;
    }

    public String smallestNumber(String pattern) {
        int patternLength = pattern.length();
        char[] numberSequence = new char[patternLength + 1];

        // Create a sequence of numbers from '1' to 'n+1'
        for (int position = 0; position <= patternLength; position++) {
            numberSequence[position] = (char) ('1' + position);
        }

        // Generate permutations and check for the correct pattern
        while (!check(new String(numberSequence), pattern)) {
            if (!findNextPermutation(numberSequence)) {
                break;
            }
        }

        return new String(numberSequence);
    }

    // Custom implementation of the next permutation function
    private boolean findNextPermutation(char[] numberSequence) {
        int lastIncreasingIndex = numberSequence.length - 2;

        // Find the rightmost character smaller than its next character
        while (
            lastIncreasingIndex >= 0 &&
            numberSequence[lastIncreasingIndex] >=
            numberSequence[lastIncreasingIndex + 1]
        ) {
            lastIncreasingIndex--;
        }
        if (lastIncreasingIndex == -1) return false;

        // Find the rightmost character greater than numberSequence[lastIncreasingIndex]
        // and swap
        int swapIndex = numberSequence.length - 1;
        while (
            numberSequence[swapIndex] <= numberSequence[lastIncreasingIndex]
        ) {
            swapIndex--;
        }
        swapCharacters(numberSequence, lastIncreasingIndex, swapIndex);

        // Reverse the suffix to get the next lexicographically smallest permutation
        reverseSuffix(
            numberSequence,
            lastIncreasingIndex + 1,
            numberSequence.length - 1
        );
        return true;
    }

    private void swapCharacters(char[] array, int firstIdx, int secondIdx) {
        char temp = array[firstIdx];
        array[firstIdx] = array[secondIdx];
        array[secondIdx] = temp;
    }

    private void reverseSuffix(char[] array, int startIdx, int endIdx) {
        while (startIdx < endIdx) {
            swapCharacters(array, startIdx, endIdx);
            startIdx++;
            endIdx--;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Check if the current sequence matches the pattern of 'I' and 'D'
    def check(self, number_sequence: str, pattern: str) -> bool:
        for index in range(len(pattern)):
            # Ensure the sequence is in increasing order at 'I' positions
            if (
                pattern[index] == "I"
                and number_sequence[index] > number_sequence[index + 1]
            ):
                return False
            # Ensure the sequence is in decreasing order at 'D' positions
            elif (
                pattern[index] == "D"
                and number_sequence[index] < number_sequence[index + 1]
            ):
                return False
        return True

    def smallestNumber(self, pattern: str) -> str:
        pattern_length = len(pattern)

        # Generate sequence "123...n+1"
        number_sequence = "".join(
            str(num) for num in range(1, pattern_length + 2)
        )

        # Use permutations generator
        for permutation in permutations(number_sequence):
            permutation_str = "".join(permutation)
            if self.check(permutation_str, pattern):
                return permutation_str
        return ""
```

</details>

<br>

## Approach 2: Optimization with Bit Masking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string smallestNumber(string pattern) {
        return to_string(findSmallestNumber(pattern, 0, 0, 0));
    }

private:
    // Recursively find the smallest number that satisfies the pattern
    int findSmallestNumber(string pattern, int currentPosition,
                           int usedDigitsMask, int currentNum) {
        // Base case: return the current number when the whole pattern is
        // processed
        if (currentPosition > pattern.size()) return currentNum;

        int result = INT_MAX;
        int lastDigit = currentNum % 10;
        bool shouldIncrement =
            currentPosition == 0 || pattern[currentPosition - 1] == 'I';

        // Try all possible digits (1 to 9) that are not yet used and follow the
        // pattern
        for (int currentDigit = 1; currentDigit <= 9; ++currentDigit) {
            if ((usedDigitsMask & 1 << currentDigit) == 0 &&
                currentDigit > lastDigit == shouldIncrement)
                result = min(result, findSmallestNumber(
                                         pattern, currentPosition + 1,
                                         usedDigitsMask | 1 << currentDigit,
                                         currentNum * 10 + currentDigit));
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String smallestNumber(String pattern) {
        return String.valueOf(findSmallestNumber(pattern, 0, 0, 0));
    }

    // Recursively find the smallest number that satisfies the pattern
    private int findSmallestNumber(
        String pattern,
        int currentPosition,
        int usedDigitsMask,
        int currentNum
    ) {
        // Base case: return the current number when the whole pattern is processed
        if (currentPosition > pattern.length()) return currentNum;

        int result = Integer.MAX_VALUE;
        int lastDigit = currentNum % 10;
        boolean shouldIncrement =
            currentPosition == 0 || pattern.charAt(currentPosition - 1) == 'I';

        // Try all possible digits (1 to 9) that are not yet used and follow the pattern
        for (int currentDigit = 1; currentDigit <= 9; ++currentDigit) {
            if (
                (usedDigitsMask & (1 << currentDigit)) == 0 &&
                currentDigit > lastDigit == shouldIncrement
            ) result = Math.min(
                result,
                findSmallestNumber(
                    pattern,
                    currentPosition + 1,
                    usedDigitsMask | (1 << currentDigit),
                    currentNum * 10 + currentDigit
                )
            );
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestNumber(self, pattern: str) -> str:
        return str(self.find_smallest_number(pattern, 0, 0, 0))

    # Recursively find the smallest number that satisfies the pattern
    def find_smallest_number(
        self,
        pattern: str,
        current_position: int,
        used_digits_mask: int,
        current_num: int,
    ) -> int:
        # Base case: return the current number when the whole pattern is processed
        if current_position > len(pattern):
            return current_num

        result = float("inf")
        last_digit = current_num % 10
        should_increment = (
            current_position == 0 or pattern[current_position - 1] == "I"
        )

        # Try all possible digits (1 to 9) that are not yet used and follow the pattern
        for current_digit in range(1, 10):
            if (used_digits_mask & (1 << current_digit)) == 0 and (
                current_digit > last_digit
            ) == should_increment:
                result = min(
                    result,
                    self.find_smallest_number(
                        pattern,
                        current_position + 1,
                        used_digits_mask | (1 << current_digit),
                        current_num * 10 + current_digit,
                    ),
                )

        return result
```

</details>

<br>

## Approach 3: Regulated Brute Force via Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";

        // Start building the sequence by calling the helper function
        buildSequence(0, 0, pattern, result);
        // Reverse the final result
        reverse(result.begin(), result.end());
        return result;
    }

    // Recursively build the sequence
    int buildSequence(int currentIndex, int currentCount, string pattern,
                      string& result) {
        if (currentIndex != pattern.size()) {
            if (pattern[currentIndex] == 'I')
                // If 'I', increment the count and move to the next index
                buildSequence(currentIndex + 1, currentIndex + 1, pattern,
                              result);
            else
                // If 'D', keep the count and move to the next index
                currentCount = buildSequence(currentIndex + 1, currentCount,
                                             pattern, result);
        }

        result += to_string(currentCount + 1);
        // Return the next count for the sequence
        return currentCount + 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String smallestNumber(String pattern) {
        StringBuilder result = new StringBuilder();

        // Start building the sequence by calling the helper function
        buildSequence(0, 0, pattern.toCharArray(), result);
        // Reverse the final result
        return result.reverse().toString();
    }

    // Recursively build the sequence
    int buildSequence(
        int currentIndex,
        int currentCount,
        char[] patternArray,
        StringBuilder result
    ) {
        if (currentIndex != patternArray.length) {
            if (patternArray[currentIndex] == 'I') buildSequence(
                // If 'I', increment the count and move to the next index
                currentIndex + 1,
                currentIndex + 1,
                patternArray,
                result
            );
            else currentCount = buildSequence(
                // If 'D', keep the count and move to the next index
                currentIndex + 1,
                currentCount,
                patternArray,
                result
            );
        }

        result.append(currentCount + 1);
        // Return the next count for the sequence
        return currentCount + 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestNumber(self, pattern: str) -> str:
        self.result = []

        # Start building the sequence by calling the helper function
        self.build_sequence(0, 0, pattern)
        # Reverse the final result
        return "".join(self.result[::-1])

    # Recursively build the sequence
    def build_sequence(
        self, current_index: int, current_count: int, pattern: str
    ) -> int:
        if current_index != len(pattern):
            if pattern[current_index] == "I":
                # If 'I', increment the count and move to the next index
                self.build_sequence(
                    current_index + 1, current_index + 1, pattern
                )
            else:
                # If 'D', keep the count and move to the next index
                current_count = self.build_sequence(
                    current_index + 1, current_count, pattern
                )

        self.result.append(str(current_count + 1))

        # Return the next count for the sequence
        return current_count + 1
```

</details>

<br>

## Approach 4: Using Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string smallestNumber(string pattern) {
        string result;
        stack<int> numStack;

        // Iterate through the pattern
        for (int index = 0; index <= pattern.size(); index++) {
            // Push the next number onto the stack
            numStack.push(index + 1);

            // If 'I' is encountered or we reach the end, pop all stack elements
            if (index == pattern.size() || pattern[index] == 'I') {
                while (!numStack.empty()) {
                    result += to_string(numStack.top());
                    numStack.pop();
                }
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
class Solution {

    public String smallestNumber(String pattern) {
        StringBuilder result = new StringBuilder();
        Stack<Integer> numStack = new Stack<>();

        // Iterate through the pattern
        for (int index = 0; index <= pattern.length(); index++) {
            // Push the next number onto the stack
            numStack.push(index + 1);

            // If 'I' is encountered or we reach the end, pop all stack elements
            if (index == pattern.length() || pattern.charAt(index) == 'I') {
                while (!numStack.isEmpty()) {
                    result.append(numStack.pop());
                }
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
    def smallestNumber(self, pattern: str) -> str:
        result = []
        num_stack = []

        # Iterate through the pattern
        for index in range(len(pattern) + 1):
            # Push the next number onto the stack
            num_stack.append(index + 1)

            # If 'I' is encountered or we reach the end, pop all stack elements
            if index == len(pattern) or pattern[index] == "I":
                while num_stack:
                    result.append(str(num_stack.pop()))

        return "".join(result)
```

</details>

<br>

## Approach 5: Greedy Approach with Sliding Window Reversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string smallestNumber(string pattern) {
        string result;

        // Iterate through the pattern and build the result
        for (int currentIndex = 0, previousIndex = 0;
             currentIndex <= pattern.length(); ++currentIndex) {
            result += to_string(1 + currentIndex);

            // Reverse the substring starting from previousIndex when necessary
            if (currentIndex == pattern.length() ||
                pattern[currentIndex] == 'I') {
                reverse(result.begin() + previousIndex, result.end());
                previousIndex = currentIndex + 1;
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
class Solution {

    public String smallestNumber(String pattern) {
        StringBuilder result = new StringBuilder();

        // Iterate through the pattern and build the result
        for (
            int currentIndex = 0, previousIndex = 0;
            currentIndex <= pattern.length();
            ++currentIndex
        ) {
            result.append(1 + currentIndex);

            // Reverse the substring starting from previousIndex when necessary
            if (
                currentIndex == pattern.length() ||
                pattern.charAt(currentIndex) == 'I'
            ) {
                StringBuilder temp = new StringBuilder();
                temp
                    .append(result.substring(0, previousIndex))
                    .append(
                        new StringBuilder(
                            result.substring(previousIndex)
                        ).reverse()
                    );
                result = temp;
                previousIndex = currentIndex + 1;
            }
        }

        // Return the final result as a string
        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestNumber(self, pattern: str) -> str:
        result = []

        # Iterate through the pattern and build the result
        previous_index = 0
        for current_index in range(len(pattern) + 1):
            result.append(str(1 + current_index))

            # Reverse the substring starting from previous_index when necessary
            if current_index == len(pattern) or pattern[current_index] == "I":
                result[previous_index:] = reversed(result[previous_index:])
                previous_index = current_index + 1

        return "".join(result)
```

</details>

<br>

## Approach 6: Optimized Greedy Approach with Precomputed 'D' Segments

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string smallestNumber(string pattern) {
        int patternLength = pattern.length();
        int maxSoFar = 0, currMax = 0, temp;

        // Array to store lengths of decreasing subsequences in the pattern
        vector<int> arrD(patternLength + 1, 0);

        // Compute the lengths of decreasing subsequences in the pattern
        for (int patternIndex = patternLength - 1; patternIndex >= 0;
             patternIndex--) {
            if (pattern[patternIndex] == 'D')
                // If 'D', increment the length of the decreasing sequence
                arrD[patternIndex] = arrD[patternIndex + 1] + 1;
        }

        string result = "";

        // Build the result string based on the pattern
        for (int position = 0; position <= patternLength; position++) {
            if (pattern[position] == 'I') {
                // If 'I', assign the next maximum digit and append it to the
                // result
                maxSoFar++;
                result += '0' + maxSoFar;

                // Update the max digit encountered so far
                maxSoFar = max(maxSoFar, currMax);

                // Reset current max for the next iteration
                currMax = 0;
            } else {
                // If 'D', calculate the appropriate digit and append it to the
                // result
                temp = 1 + maxSoFar + arrD[position];
                result += '0' + temp;

                // Update the current max value
                currMax = max(currMax, temp);
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
class Solution {

    public String smallestNumber(String pattern) {
        int patternLength = pattern.length();
        int maxSoFar = 0, currMax = 0, temp;

        // Array to store lengths of decreasing subsequences in the pattern
        int[] arrD = new int[patternLength + 2];

        // Compute the lengths of decreasing subsequences in the pattern
        for (
            int patternIndex = patternLength;
            patternIndex >= 0;
            patternIndex--
        ) {
            // If 'D', increment the length of the decreasing sequence
            if (
                patternIndex < patternLength &&
                pattern.charAt(patternIndex) == 'D'
            ) arrD[patternIndex] = arrD[patternIndex + 1] + 1;
        }

        StringBuilder result = new StringBuilder();

        // Build the result string based on the pattern
        for (int position = 0; position <= patternLength; position++) {
            if (position < patternLength && pattern.charAt(position) == 'I') {
                // If 'I', assign the next maximum digit and append it to the
                // result
                maxSoFar++;
                result.append(maxSoFar);

                // Update the max digit encountered so far
                maxSoFar = Math.max(maxSoFar, currMax);

                // Reset current max for the next iteration
                currMax = 0;
            } else {
                // If 'D', calculate the appropriate digit and append it to the
                // result
                temp = 1 + maxSoFar + arrD[position];
                result.append(temp);

                // Update the current max value
                currMax = Math.max(currMax, temp);
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
    def smallestNumber(self, pattern: str) -> str:
        pattern_length = len(pattern)
        max_so_far = curr_max = temp = 0

        # List to store lengths of decreasing subsequences in the pattern
        arr_D = [0 for _ in range(pattern_length + 2)]

        # Compute the lengths of decreasing subsequences in the pattern
        for pattern_index in range(pattern_length, -1, -1):
            if pattern_index < pattern_length and pattern[pattern_index] == "D":
                # If 'D', increment the length of the decreasing sequence
                arr_D[pattern_index] = arr_D[pattern_index + 1] + 1
        result = ""

        # Build the result string based on the pattern
        for position in range(pattern_length + 1):
            if position < pattern_length and pattern[position] == "I":
                # If 'I', assign the next maximum digit and append it to the
                # result
                max_so_far += 1
                result += str(max_so_far)

                # Update the max digit encountered so far
                max_so_far = max(max_so_far, curr_max)
                # Reset current max for the next iteration
                curr_max = 0

            else:
                # If 'D', calculate the appropriate digit and append it to the
                # result
                temp = 1 + max_so_far + arr_D[position]
                result += str(temp)

                # Update the current max value
                curr_max = max(curr_max, temp)

        return result
```

</details>
