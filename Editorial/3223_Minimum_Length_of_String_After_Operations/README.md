# 3223. Minimum Length of String After Operations

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-length-of-string-after-operations/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 3223 - Minimum Length of String After Operations](https://leetcode.com/problems/minimum-length-of-string-after-operations/)

## Problem

You are given a string s.

You can perform the following process on s any number of times:

- Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
- Delete the closest occurrence of s[i] located to the left of i.
- Delete the closest occurrence of s[i] located to the right of i.

Return the minimum length of the final string s that you can achieve.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 2 * 105
- s consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3223. Minimum Length of String After Operations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Hash Map | C++, Java, Python3 |
| Using Frequency Array | C++, Java, Python3 |
| Using Bitwise | C++, Java, Python3 |

## Approach 1: Using Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumLength(string s) {
        // Step 1: Count the frequency of each character in the string
        unordered_map<char, int> charFrequencyMap;
        for (char currentChar : s) {
            charFrequencyMap[currentChar]++;
        }

        // Step 2: Calculate the number of characters to delete
        int deleteCount = 0;
        for (auto& pair : charFrequencyMap) {
            int frequency = pair.second;
            if (frequency % 2 == 1) {
                // If frequency is odd, delete all except one
                deleteCount += frequency - 1;
            } else {
                // If frequency is even, delete all except two
                deleteCount += frequency - 2;
            }
        }

        // Step 3: Return the minimum length after deletions
        return s.length() - deleteCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumLength(String s) {
        // Step 1: Count the frequency of each character in the string
        HashMap<Character, Integer> charFrequencyMap = new HashMap<>();
        for (char currentChar : s.toCharArray()) {
            charFrequencyMap.put(
                currentChar,
                charFrequencyMap.getOrDefault(currentChar, 0) + 1
            );
        }

        // Step 2: Calculate the number of characters to delete
        int deleteCount = 0;
        for (int frequency : charFrequencyMap.values()) {
            if (frequency % 2 == 1) {
                // If frequency is odd, delete all except one
                deleteCount += frequency - 1;
            } else {
                // If frequency is even, delete all except two
                deleteCount += frequency - 2;
            }
        }

        // Step 3: Return the minimum length after deletions
        return s.length() - deleteCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumLength(self, s: str) -> int:
        # Step 1: Count the frequency of each character in the string
        char_frequency_map = Counter(s)

        # Step 2: Calculate the number of characters to delete
        delete_count = 0
        for frequency in char_frequency_map.values():
            if frequency % 2 == 1:
                # If frequency is odd, delete all except one
                delete_count += frequency - 1
            else:
                # If frequency is even, delete all except two
                delete_count += frequency - 2

        # Step 3: Return the minimum length after deletions
        return len(s) - delete_count
```

</details>

<br>

## Approach 2: Using Frequency Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumLength(string s) {
        // Step 1: Initialize a frequency array to count occurrences of each
        // character
        vector<int> charFrequency(26, 0);
        int totalLength = 0;

        // Step 2: Count the frequency of each character in the string
        for (char currentChar : s) {
            charFrequency[currentChar - 'a']++;
        }

        // Step 3: Calculate the total length after deletions count
        for (int frequency : charFrequency) {
            if (frequency == 0) continue;  // Skip characters that don't appear
            if (frequency % 2 == 0) {
                totalLength += 2;  // If frequency is even, add 2
            } else {
                totalLength += 1;  // If frequency is odd, add 1
            }
        }

        // Step 4: Return the minimum length after deletions count
        return totalLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumLength(String s) {
        // Step 1: Initialize a frequency array to count occurrences of each character
        int[] charFrequency = new int[26];
        int totalLength = 0;

        // Step 2: Count the frequency of each character in the string
        for (char currentChar : s.toCharArray()) {
            charFrequency[currentChar - 'a']++;
        }

        // Step 3: Calculate the total length after deletions count
        for (int frequency : charFrequency) {
            if (frequency == 0) continue; // Skip characters that don't appear
            if (frequency % 2 == 0) {
                totalLength += 2; // If frequency is even, add 2 characters
            } else {
                totalLength += 1; // If frequency is odd, add 1 character
            }
        }

        // Step 4: Return the minimum length after deletions count
        return totalLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumLength(self, s: str) -> int:
        # Step 1: Initialize a frequency array to count occurrences of each character
        char_frequency = [0] * 26
        total_length = 0

        # Step 2: Count the frequency of each character in the string
        for current_char in s:
            char_frequency[ord(current_char) - ord("a")] += 1

        # Step 3: Calculate the total length after deletions count
        for frequency in char_frequency:
            if frequency == 0:
                continue  # Skip characters that don't appear
            if frequency % 2 == 0:
                total_length += 2  # If frequency is even, add 2 characters
            else:
                total_length += 1  # If frequency is odd, add 1 character

        # Step 4: Return the minimum length after deletions count
        return total_length
```

</details>

<br>

## Approach 3: Using Bitwise

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumLength(string s) {
        int present = 0;
        int parity = 0;
        int placevalue;

        // Iterate through the string and update the present and parity bitmasks
        for (int k = 0; k < s.size(); k++) {
            // Calculate the bit position for the character
            placevalue = 1 << (s[k] - 'a');
            // Set the corresponding bit in the present bitmask
            present |= placevalue;
            // Toggle the corresponding bit in the parity bitmask
            parity ^= placevalue;
        }

        int totalLength = 0;

        // Process the present bitmask and check the parity bitmask to calculate
        // the minimum length
        while (present) {
            // Clear the least significant bit in present
            placevalue = present & (present - 1);
            // If the corresponding parity bit is set, it indicates an odd
            // occurrence, so add 1
            totalLength += 2 - ((parity & (present - placevalue)) != 0);
            present = placevalue;
        }

        return totalLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumLength(String s) {
        int present = 0;
        int parity = 0;
        int placeValue;

        // Iterate through the string and update the present and parity bitmasks
        for (int k = 0; k < s.length(); k++) {
            // Calculate the bit position for the character
            placeValue = 1 << (s.charAt(k) - 'a');
            // Set the corresponding bit in the present bitmask
            present |= placeValue;
            // Toggle the corresponding bit in the parity bitmask
            parity ^= placeValue;
        }

        int totalLength = 0;

        // Process the present bitmask and check the parity bitmask to calculate
        // the minimum length
        while (present > 0) {
            // Clear the least significant bit in present
            placeValue = present & (present - 1);
            // If the corresponding parity bit is set, it indicates an odd
            // occurrence, so add 1
            totalLength += 2 - ((parity & (present - placeValue)) != 0 ? 1 : 0);
            present = placeValue;
        }

        return totalLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumLength(self, s: str) -> int:
        present = 0
        parity = 0
        place_value = 0

        # Iterate through the string and update the present and parity bitmasks
        for char in s:
            # Calculate the bit position for the character
            place_value = 1 << (ord(char) - ord("a"))

            # Set the corresponding bit in the present bitmask
            present |= place_value

            # Toggle the corresponding bit in the parity bitmask
            parity ^= place_value

        total_length = 0

        # Process the present bitmask and check the parity bitmask to calculate
        # the minimum length
        while present > 0:
            # Clear the least significant bit in present
            place_value = present & (present - 1)
            # If the corresponding parity bit is set, it indicates an odd
            # occurrence, so add 1
            total_length += 2 - ((parity & (present - place_value)) != 0)
            present = place_value

        return total_length
```

</details>
