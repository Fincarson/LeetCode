# 393. UTF-8 Validation

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/utf-8-validation/)  
`Array` `Bit Manipulation`

**Problem Link:** [LeetCode 393 - UTF-8 Validation](https://leetcode.com/problems/utf-8-validation/)

## Problem

Given an integer array data representing the data, return whether it is a valid UTF-8 encoding (i.e. it translates to a sequence of valid UTF-8 encoded characters).

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

This is how the UTF-8 encoding would work:

```text
Number of Bytes   |        UTF-8 Octet Sequence
                       |              (binary)
   --------------------+-----------------------------------------
            1          |   0xxxxxxx
            2          |   110xxxxx 10xxxxxx
            3          |   1110xxxx 10xxxxxx 10xxxxxx
            4          |   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
```

x denotes a bit in the binary form of a byte that may be either 0 or 1.

Note: The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

### Example 1

```text
Input: data = [197,130,1]
Output: true
Explanation: data represents the octet sequence: 11000101 10000010 00000001.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
```

### Example 2

```text
Input: data = [235,140,4]
Output: false
Explanation: data represented the octet sequence: 11101011 10001100 00000100.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
```

## Constraints

- 1 <= data.length <= 2 * 104
- 0 <= data[i] <= 255

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 393. UTF-8 Validation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| String Manipulation. | Java, Python |
| Bit Manipulation | Java, Python |

## Approach 1: String Manipulation.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public boolean validUtf8(int[] data) {

    // Number of bytes in the current UTF-8 character
    int numberOfBytesToProcess = 0;

    // For each integer in the data array.
    for (int i = 0; i < data.length; i++) {

      // Get the binary representation. We only need the least significant 8 bits
      // for any given number.
      String binRep = Integer.toBinaryString(data[i]);
      binRep =
          binRep.length() >= 8
              ? binRep.substring(binRep.length() - 8)
              : "00000000".substring(binRep.length() % 8) + binRep;

      // If this is the case then we are to start processing a new UTF-8 character.
      if (numberOfBytesToProcess == 0) {

        // Get the number of 1s in the beginning of the string.
        for (int j = 0; j < binRep.length(); j++) {
          if (binRep.charAt(j) == '0') {
            break;
          }

          numberOfBytesToProcess += 1;
        }

        // 1 byte characters
        if (numberOfBytesToProcess == 0) {
          continue;
        }

        // Invalid scenarios according to the rules of the problem.
        if (numberOfBytesToProcess > 4 || numberOfBytesToProcess == 1) {
          return false;
        }

      } else {

        // Else, we are processing integers which represent bytes which are a part of
        // a UTF-8 character. So, they must adhere to the pattern `10xxxxxx`.
        if (!(binRep.charAt(0) == '1' && binRep.charAt(1) == '0')) {
          return false;
        }
      }

      // We reduce the number of bytes to process by 1 after each integer.
      numberOfBytesToProcess -= 1;
    }

    // This is for the case where we might not have the complete data for
    // a particular UTF-8 character.
    return numberOfBytesToProcess == 0;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """

        # Number of bytes in the current UTF-8 character
        n_bytes = 0

        # For each integer in the data array.
        for num in data:

            # Get the binary representation. We only need the least significant 8 bits
            # for any given number.
            bin_rep = format(num, '#010b')[-8:]

            # If this is the case then we are to start processing a new UTF-8 character.
            if n_bytes == 0:

                # Get the number of 1s in the beginning of the string.
                for bit in bin_rep:
                    if bit == '0': break
                    n_bytes += 1

                # 1 byte characters
                if n_bytes == 0:
                    continue

                # Invalid scenarios according to the rules of the problem.
                if n_bytes == 1 or n_bytes > 4:
                    return False
            else:
                # Else, we are processing integers which represent bytes which are a part of
                # a UTF-8 character. So, they must adhere to the pattern `10xxxxxx`.
                if not (bin_rep[0] == '1' and bin_rep[1] == '0'):
                    return False

            # We reduce the number of bytes to process by 1 after each integer.
            n_bytes -= 1

        # This is for the case where we might not have the complete data for
        # a particular UTF-8 character.
        return n_bytes == 0
```

</details>

<br>

## Approach 2: Bit Manipulation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean validUtf8(int[] data) {

        // Number of bytes in the current UTF-8 character
        int numberOfBytesToProcess = 0;

        // Masks to check two most significant bits in a byte.
        int mask1 = 1 << 7;
        int mask2 = 1 << 6;

        // For each integer in the data array.
        for(int i = 0; i < data.length; i++) {
            // If this is the case then we are to start processing a new UTF-8 character.
            if (numberOfBytesToProcess == 0) {
                int mask = 1 << 7;
                 while ((mask & data[i]) != 0) {
                    numberOfBytesToProcess += 1;
                    mask = mask >> 1;
                 }

                // 1 byte characters
                if (numberOfBytesToProcess == 0) {
                    continue;
                }

                // Invalid scenarios according to the rules of the problem.
                if (numberOfBytesToProcess > 4 || numberOfBytesToProcess == 1) {
                    return false;
                }

            } else {

                // data[i] should have most significant bit set and
                // second most significant bit unset. So, we use the two masks
                // to make sure this is the case.
                if (!((data[i] & mask1) != 0 && (mask2 & data[i]) == 0)) {
                    return false;
                }
            }

            // We reduce the number of bytes to process by 1 after each integer.
            numberOfBytesToProcess -= 1;
        }

        // This is for the case where we might not have the complete data for
        // a particular UTF-8 character.
        return numberOfBytesToProcess == 0;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """

        # Number of bytes in the current UTF-8 character
        n_bytes = 0

        # Mask to check if the most significant bit (8th bit from the left) is set or not
        mask1 = 1 << 7

        # Mask to check if the second most significant bit is set or not
        mask2 = 1 << 6
        for num in data:

            # Get the number of set most significant bits in the byte if
            # this is the starting byte of an UTF-8 character.
            mask = 1 << 7
            if n_bytes == 0:
                while mask & num:
                    n_bytes += 1
                    mask = mask >> 1

                # 1 byte characters
                if n_bytes == 0:
                    continue

                # Invalid scenarios according to the rules of the problem.
                if n_bytes == 1 or n_bytes > 4:
                    return False
            else:

                # If this byte is a part of an existing UTF-8 character, then we
                # simply have to look at the two most significant bits and we make
                # use of the masks we defined before.
                if not (num & mask1 and not (num & mask2)):
                    return False
            n_bytes -= 1
        return n_bytes == 0
```

</details>
