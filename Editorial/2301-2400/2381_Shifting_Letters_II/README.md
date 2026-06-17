# 2381. Shifting Letters II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/shifting-letters-ii/)  
`Array` `String` `Prefix Sum`

**Problem Link:** [LeetCode 2381 - Shifting Letters II](https://leetcode.com/problems/shifting-letters-ii/)

## Problem

You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

### Example 1

```text
Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
```

### Example 2

```text
Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
```

## Constraints

- 1 <= s.length, shifts.length <= 5 * 104
- shifts[i].length == 3
- 0 <= starti <= endi < s.length
- 0 <= directioni <= 1
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Range Addition](https://leetcode.com/problems/range-addition/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Shifting Letters](https://leetcode.com/problems/shifting-letters/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Population Year](https://leetcode.com/problems/maximum-population-year/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Describe the Painting](https://leetcode.com/problems/describe-the-painting/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Shift Distance Between Two Strings](https://leetcode.com/problems/shift-distance-between-two-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2381. Shifting Letters II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Difference Array | C++, Java, Python3 |

## Approach: Difference Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArray(
            n, 0);  // Initialize a difference array with all elements set to 0.

        for (auto shift : shifts) {
            if (shift[2] == 1) {        // If direction is forward (1):
                diffArray[shift[0]]++;  // Increment at the start index to
                                        // indicate a forward shift.
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] +
                              1]--;  // Decrement at the end+1 index to stop the
                                     // effect of the shift.
                }
            } else {                    // If direction is backward (0):
                diffArray[shift[0]]--;  // Decrement at the start index to
                                        // indicate a backward shift.
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] +
                              1]++;  // Increment at the end+1 index to stop the
                                     // effect of the shift.
                }
            }
        }

        string result(n, ' ');
        int numberOfShifts = 0;

        for (int i = 0; i < s.size(); i++) {
            numberOfShifts = (numberOfShifts + diffArray[i]) %
                             26;  // Update cumulative shifts, keeping within
                                  // the alphabet range.
            if (numberOfShifts < 0)
                numberOfShifts +=
                    26;  // Ensure `numberOfShifts` is non-negative.

            // Calculate the new character by shifting `s[i]`
            result[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
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

    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] diffArray = new int[n]; // Initialize a difference array with all elements set to 0.

        // Process each shift operation
        for (int[] shift : shifts) {
            if (shift[2] == 1) { // If direction is forward (1)
                diffArray[shift[0]]++; // Increment at the start index
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] + 1]--; // Decrement at the end+1 index
                }
            } else { // If direction is backward (0)
                diffArray[shift[0]]--; // Decrement at the start index
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] + 1]++; // Increment at the end+1 index
                }
            }
        }

        StringBuilder result = new StringBuilder(s);
        int numberOfShifts = 0;

        // Apply the shifts to the string
        for (int i = 0; i < n; i++) {
            numberOfShifts = (numberOfShifts + diffArray[i]) % 26; // Update cumulative shifts, keeping within the alphabet range
            if (numberOfShifts < 0) numberOfShifts += 26; // Ensure non-negative shifts

            // Calculate the new character by shifting `s[i]`
            char shiftedChar = (char) ('a' +
                ((s.charAt(i) - 'a' + numberOfShifts) % 26));
            result.setCharAt(i, shiftedChar);
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
    def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
        n = len(s)
        diff_array = [
            0
        ] * n  # Initialize a difference array with all elements set to 0

        # Process each shift operation
        for shift in shifts:
            if shift[2] == 1:  # If direction is forward (1)
                diff_array[shift[0]] += 1  # Increment at the start index
                if shift[1] + 1 < n:
                    diff_array[
                        shift[1] + 1
                    ] -= 1  # Decrement at the end+1 index
            else:  # If direction is backward (0)
                diff_array[shift[0]] -= 1  # Decrement at the start index
                if shift[1] + 1 < n:
                    diff_array[
                        shift[1] + 1
                    ] += 1  # Increment at the end+1 index

        result = list(s)
        number_of_shifts = 0

        # Apply the shifts to the string
        for i in range(n):
            number_of_shifts = (
                number_of_shifts + diff_array[i]
            ) % 26  # Update cumulative shifts, keeping within the alphabet range
            if number_of_shifts < 0:
                number_of_shifts += 26  # Ensure non-negative shifts

            # Calculate the new character by shifting `s[i]`
            shifted_char = chr(
                (ord(s[i]) - ord("a") + number_of_shifts) % 26 + ord("a")
            )
            result[i] = shifted_char

        return "".join(result)
```

</details>
