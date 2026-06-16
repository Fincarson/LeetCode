# 2168. Unique Substrings With Equal Digit Frequency

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/)  
`Hash Table` `String` `Rolling Hash` `Counting` `Hash Function`

**Problem Link:** [LeetCode 2168 - Unique Substrings With Equal Digit Frequency](https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/)

## Problem

### Example 1

```text
Input: s = "1212"
Output: 5
Explanation: The substrings that meet the requirements are "1", "2", "12", "21", "1212".
Note that although the substring "12" appears twice, it is only counted once.
```

### Example 2

```text
Input: s = "12321"
Output: 9
Explanation: The substrings that meet the requirements are "1", "2", "3", "12", "23", "32", "21", "123", "321".
```

## Constraints

- 1 <= s.length <= 1000
- s consists of digits.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Equal Count Substrings](https://leetcode.com/problems/number-of-equal-count-substrings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Substrings That Begin and End With the Same Letter](https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2168. Unique Substrings With Equal Digit Frequency

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Optimized Brute Force | C++, Java, Python3 |
| Rolling Hash | C++, Java, Python3 |
| Prefix Tree (Trie) | C++, Java, Python3 |

## Approach 1: Optimized Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int equalDigitFrequency(string s) {
        int n = s.size();
        // Set to store unique substrings with equal digit frequency
        unordered_set<string> validSubstrings;

        // Iterate over each possible starting position of a substring
        for (int start = 0; start < n; start++) {
            vector<int> digitFrequency(10, 0);

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < n; end++) {
                digitFrequency[s[end] - '0']++;

                // Variable to store the frequency all digits must match
                int commonFrequency = 0;
                bool isValid = true;

                for (int i = 0; i < digitFrequency.size(); i++) {
                    // Skip digits that are not in the substring
                    if (digitFrequency[i] == 0) continue;

                    if (commonFrequency == 0) {
                        // First digit found, set commonFrequency
                        commonFrequency = digitFrequency[i];
                    }
                    if (commonFrequency != digitFrequency[i]) {
                        // Mismatch in frequency, mark as invalid
                        isValid = false;
                        break;
                    }
                }

                // If the substring is valid, add it to the set
                if (isValid) {
                    string substring = s.substr(start, end - start + 1);
                    validSubstrings.insert(substring);
                }
            }
        }

        // Return the number of unique valid substrings
        return validSubstrings.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int equalDigitFrequency(String s) {
        int n = s.length();
        // Set to store unique substrings with equal digit frequency
        Set<String> validSubstrings = new HashSet<>();

        // Iterate over each possible starting position of a substring
        for (int start = 0; start < n; start++) {
            // Frequency array for digits 0-9
            int[] digitFrequency = new int[10];

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < n; end++) {
                digitFrequency[s.charAt(end) - '0']++;

                // Variable to store the frequency all digits must match
                int commonFrequency = 0;
                boolean isValid = true;

                for (int i = 0; i < digitFrequency.length; i++) {
                    if (digitFrequency[i] == 0) continue; // Skip digits not in the substring
                    if (commonFrequency == 0) {
                        // First digit found, set commonFrequency
                        commonFrequency = digitFrequency[i];
                    }
                    if (commonFrequency != digitFrequency[i]) {
                        // Mismatch in frequency, mark as invalid
                        isValid = false;
                        break;
                    }
                }

                // If the substring is valid, add it to the set
                if (isValid) {
                    String substring = s.substring(start, end + 1);
                    validSubstrings.add(substring);
                }
            }
        }

        // Return the number of unique valid substrings
        return validSubstrings.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def equalDigitFrequency(self, s: str) -> int:
        n = len(s)
        # Set to store unique substrings with equal digit frequency
        valid_substrings = set()

        # Iterate over each possible starting position of a substring
        for start in range(n):
            digit_frequency = [0] * 10  # Frequency array for digits 0-9

            # Extend the substring from 'start' to different end positions
            for end in range(start, n):
                digit_frequency[ord(s[end]) - ord("0")] += 1

                # Variable to store the frequency all digits must match
                common_frequency = 0
                is_valid = True

                for count in digit_frequency:
                    if count == 0:
                        continue  # Skip digits not in the substring
                    if common_frequency == 0:
                        # First digit found, set common_frequency
                        common_frequency = count
                    if common_frequency != count:
                        # Mismatch in frequency, mark as invalid
                        is_valid = False
                        break

                # If the substring is valid, add it to the set
                if is_valid:
                    substring = s[start : end + 1]
                    valid_substrings.add(substring)

        # Return the number of unique valid substrings
        return len(valid_substrings)
```

</details>

<br>

## Approach 2: Rolling Hash

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int equalDigitFrequency(string s) {
        int n = s.size();
        int prime = 31;            // Prime base for the rolling hash
        long long int mod = 10e9;  // Large prime modulus to avoid overflow
        unordered_set<long long int> validSubstringHashes;

        for (int start = 0; start < n; start++) {
            vector<int> digitFrequency(10, 0);
            // Track number of unique digits in the substring
            int uniqueDigitsCount = 0;
            // Rolling hash for the current substring
            long long int substringHash = 0;
            // Maximum frequency of any digit in the substring
            int maxDigitFrequency = 0;

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < n; end++) {
                int currentDigit = s[end] - '0';

                // If this digit appears for the first time, increment
                // uniqueDigits
                if (digitFrequency[currentDigit] == 0) {
                    uniqueDigitsCount++;
                }

                digitFrequency[currentDigit]++;
                maxDigitFrequency =
                    max(maxDigitFrequency, digitFrequency[currentDigit]);

                // Update rolling hash
                substringHash =
                    (prime * substringHash + currentDigit + 1) % mod;

                // Check if all digits in the substring have the same frequency
                if (maxDigitFrequency * uniqueDigitsCount == end - start + 1) {
                    // Insert unique hash
                    validSubstringHashes.insert(substringHash);
                }
            }
        }

        return validSubstringHashes.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int equalDigitFrequency(String s) {
        int n = s.length();
        int prime = 31; // Prime base for the rolling hash
        long mod = 1000000000L;
        Set<Long> validSubstringHashes = new HashSet<>();

        for (int start = 0; start < n; start++) {
            int[] digitFrequency = new int[10]; // Frequency array for digits 0-9
            int uniqueDigitsCount = 0; // Track number of unique digits in the substring
            long substringHash = 0; // Rolling hash for the current substring
            int maxDigitFrequency = 0; // Maximum frequency of any digit in the substring

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < n; end++) {
                int currentDigit = s.charAt(end) - '0';

                // This digit appears for the first time
                if (digitFrequency[currentDigit] == 0) {
                    uniqueDigitsCount++;
                }

                digitFrequency[currentDigit]++;
                maxDigitFrequency = Math.max(
                    maxDigitFrequency,
                    digitFrequency[currentDigit]
                );

                // Update rolling hash
                substringHash =
                    (prime * substringHash + currentDigit + 1) % mod;

                // Check if all digits in the substring have the same frequency
                if (maxDigitFrequency * uniqueDigitsCount == end - start + 1) {
                    validSubstringHashes.add(substringHash); // Insert unique hash
                }
            }
        }

        return validSubstringHashes.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def equalDigitFrequency(self, s: str) -> int:
        n = len(s)  # Size of the string
        prime = 31  # Prime base for the rolling hash
        mod = 10**9  # Large prime modulus to avoid overflow
        valid_substring_hashes = set()

        for start in range(n):
            digit_frequency = [0] * 10  # Frequency array for digits 0-9
            # Track number of unique digits in the substring
            unique_digits_count = 0
            substring_hash = 0  # Rolling hash for the current substring
            # Maximum frequency of any digit in the substring
            max_digit_frequency = 0

            for end in range(start, n):
                current_digit = int(s[end]) - 0  # Convert char to digit (0-9)

                # If this digit appears for the first time, increment unique_digits
                if digit_frequency[current_digit] == 0:
                    unique_digits_count += 1

                digit_frequency[current_digit] += 1
                max_digit_frequency = max(
                    max_digit_frequency, digit_frequency[current_digit]
                )

                # Update rolling hash
                substring_hash = (
                    prime * substring_hash + current_digit + 1
                ) % mod

                # Check if all digits in the substring have the same frequency
                if max_digit_frequency * unique_digits_count == end - start + 1:
                    # Insert unique hash
                    valid_substring_hashes.add(substring_hash)

        return len(valid_substring_hashes)
```

</details>

<br>

## Approach 3: Prefix Tree (Trie)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int equalDigitFrequency(const std::string& s) {
        TrieNode* root = new TrieNode();  // Initialize the Trie root
        int totalValidSubstrings = 0;

        // Iterate through all starting indices of substrings
        for (int start = 0; start < s.size(); start++) {
            TrieNode* currentNode = root;
            // Frequency table for digits 0-9
            vector<int> digitFrequency(10, 0);
            int uniqueDigitsCount = 0;
            int maxDigitFrequency = 0;

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < s.size(); end++) {
                int currentDigit = s[end] - '0';  // Current digit

                // Update digit frequency and unique digits count
                if (digitFrequency[currentDigit]++ == 0) {
                    uniqueDigitsCount++;
                }

                maxDigitFrequency =
                    max(maxDigitFrequency, digitFrequency[currentDigit]);

                // Traverse or create a new node in the Trie
                if (currentNode->children[currentDigit] == nullptr) {
                    currentNode->children[currentDigit] =
                        new TrieNode();  // Add new node for the digit
                }

                // Move to the child node
                currentNode = currentNode->children[currentDigit];

                // Check if the substring is valid
                if (uniqueDigitsCount * maxDigitFrequency == end - start + 1 &&
                    !currentNode->isVisited) {
                    // Increment valid substrings count
                    totalValidSubstrings++;
                    // Mark this substring as seen
                    currentNode->isVisited = true;
                }
            }
        }

        delete root;  // Cleanup allocated memory
        return totalValidSubstrings;
    }

private:
    class TrieNode {
    public:
        TrieNode* children[10];  // Pointers to children nodes (0-9)
        bool isVisited;

        TrieNode() : isVisited(false) {
            fill(begin(children), end(children), nullptr);
        }
    };
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int equalDigitFrequency(String s) {
        TrieNode root = new TrieNode(); // Initialize the Trie root
        int totalValidSubstrings = 0;

        // Iterate through all starting indices of substrings
        for (int start = 0; start < s.length(); start++) {
            TrieNode currentNode = root;
            int[] digitFrequency = new int[10];
            int uniqueDigitsCount = 0;
            int maxDigitFrequency = 0;

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < s.length(); end++) {
                int currentDigit = s.charAt(end) - '0';

                // Update digit frequency and unique digits count
                if (digitFrequency[currentDigit]++ == 0) {
                    uniqueDigitsCount++;
                }
                maxDigitFrequency = Math.max(
                    maxDigitFrequency,
                    digitFrequency[currentDigit]
                );

                // Traverse or create a new node in the Trie
                if (currentNode.children[currentDigit] == null) {
                    currentNode.children[currentDigit] = new TrieNode(); // Add new node for the digit
                }
                currentNode = currentNode.children[currentDigit]; // Move to the child node

                // Check if the substring is valid
                if (
                    uniqueDigitsCount * maxDigitFrequency == end - start + 1 &&
                    !currentNode.isVisited
                ) {
                    totalValidSubstrings++; // Increment count of valid substrings
                    currentNode.isVisited = true; // Mark this substring as seen
                }
            }
        }
        return totalValidSubstrings;
    }

    class TrieNode {

        TrieNode[] children = new TrieNode[10]; // For digits 0-9
        boolean isVisited; // Checks if this substring has been counted
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def equalDigitFrequency(self, s: str) -> int:
        root = self.TrieNode()  # Initialize the Trie root
        total_valid_substrings = 0

        # Iterate through all starting indices of substrings
        for start in range(len(s)):
            current_node = root
            digit_frequency = [0] * 10  # Frequency table for digits 0-9
            unique_digits_count = 0
            max_digit_frequency = 0

            # Extend the substring from 'start' to different end positions
            for end in range(start, len(s)):
                current_digit = int(s[end])  # Current digit

                # Update digit frequency and unique digits count
                if digit_frequency[current_digit] == 0:
                    unique_digits_count += 1
                digit_frequency[current_digit] += 1
                max_digit_frequency = max(
                    max_digit_frequency, digit_frequency[current_digit]
                )

                # Traverse or create a new node in the Trie
                if not current_node.children[current_digit]:
                    # Add new node for the digit
                    current_node.children[current_digit] = self.TrieNode()
                # Move to the child node
                current_node = current_node.children[current_digit]

                # Check if the substring is valid
                if (
                    unique_digits_count * max_digit_frequency == end - start + 1
                    and not current_node.is_visited
                ):
                    # Increment count of valid substrings
                    total_valid_substrings += 1
                    # Mark this substring as seen
                    current_node.is_visited = True

        return total_valid_substrings

    class TrieNode:
        def __init__(self):
            self.children = [None] * 10  # List of children nodes (0-9)
            self.is_visited = False  # Mark if the substring has been seen
```

</details>
