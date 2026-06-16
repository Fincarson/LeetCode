# 2678. Number of Senior Citizens

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/number-of-senior-citizens/)  
`Array` `String`

**Problem Link:** [LeetCode 2678 - Number of Senior Citizens](https://leetcode.com/problems/number-of-senior-citizens/)

## Problem

You are given a 0-indexed array of strings details. Each element of details provides information about a given passenger compressed into a string of length 15. The system is such that:

- The first ten characters consist of the phone number of passengers.
- The next character denotes the gender of the person.
- The following two characters are used to indicate the age of the person.
- The last two characters determine the seat allotted to that person.

Return the number of passengers who are strictly more than 60 years old.

### Example 1

```text
Input: details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
Output: 2
Explanation: The passengers at indices 0, 1, and 2 have ages 75, 92, and 40. Thus, there are 2 people who are over 60 years old.
```

### Example 2

```text
Input: details = ["1313579440F2036","2921522980M5644"]
Output: 0
Explanation: None of the passengers are older than 60.
```

## Constraints

- 1 <= details.length <= 100
- details[i].length == 15
- details[i] consists of digits from '0' to '9'.
- details[i][10] is either 'M' or 'F' or 'O'.
- The phone numbers and seat numbers of the passengers are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2678. Number of Senior Citizens

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| String Parsing | C++, Java, Python3 |
| Character-Based Extraction | C++, Java, Python3 |

## Approach 1: String Parsing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;

        // Iterate through each passenger's details
        for (string& passengerInfo : details) {
            // Extract the age from the passengerInfo string
            // Age is located at index 11 and 12 (2 characters)
            int age = stoi(passengerInfo.substr(11, 2));

            // Check if the passenger is a senior (strictly over 60 years old)
            if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countSeniors(String[] details) {
        int seniorCount = 0;

        // Iterate through each passenger's details
        for (String passengerInfo : details) {
            // Extract the age from the passengerInfo string
            // Age is located at index 11 and 12 (2 characters)
            int age = Integer.parseInt(passengerInfo.substring(11, 13));

            // Check if the passenger is a senior (strictly over 60 years old)
            if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countSeniors(self, details: List[str]) -> int:
        senior_count = 0

        # Iterate through each passenger's details
        for passenger_info in details:
            # Extract the age from the passenger_info string
            # Age is located at index 11 and 12 (2 characters)
            age = int(passenger_info[11:13])

            # Check if the passenger is a senior (strictly over 60 years old)
            if age > 60:
                senior_count += 1

        return senior_count
```

</details>

<br>

## Approach 2: Character-Based Extraction

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;

        // Iterate through each passenger's details
        for (string& passengerInfo : details) {
            // Extract the digits of age
            int ageTens = passengerInfo[11] - '0';
            int ageOnes = passengerInfo[12] - '0';

            // Calculate the full age
            int age = ageTens * 10 + ageOnes;

            // Check if the passenger is a senior (strictly over 60 years old)
            if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countSeniors(String[] details) {
        int seniorCount = 0;

        // Iterate through each passenger's details
        for (String passengerInfo : details) {
            // Extract the digits of age
            int ageTens = passengerInfo.charAt(11) - '0';
            int ageOnes = passengerInfo.charAt(12) - '0';

            // Calculate the full age
            int age = ageTens * 10 + ageOnes;

            // Check if the passenger is a senior (strictly over 60 years old)
            if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countSeniors(self, details: List[str]) -> int:
        senior_count = 0

        # Iterate through each passenger's details
        for passenger_info in details:
            # Extract the digits of age
            age_tens = ord(passenger_info[11]) - ord("0")
            age_ones = ord(passenger_info[12]) - ord("0")

            # Calculate the full age
            age = age_tens * 10 + age_ones

            # Check if the passenger is a senior (strictly over 60 years old)
            if age > 60:
                senior_count += 1

        return senior_count
```

</details>
