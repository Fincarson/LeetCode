# 1718. Construct the Lexicographically Largest Valid Sequence

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/)  
`Array` `Backtracking`

**Problem Link:** [LeetCode 1718 - Construct the Lexicographically Largest Valid Sequence](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/)

## Problem

Given an integer n, find a sequence with elements in the range [1, n] that satisfies all of the following:

- The integer 1 occurs once in the sequence.
- Each integer between 2 and n occurs twice in the sequence.
- For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.

The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

### Example 1

```text
Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
```

### Example 2

```text
Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]
```

## Constraints

- 1 <= n <= 20

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Number of Beautiful Subsets](https://leetcode.com/problems/the-number-of-beautiful-subsets/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Lexicographically Largest String From the Box I](https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1718. Construct the Lexicographically Largest Valid Sequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Backtracking | C++, Java, Python3 |

## Approach: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> constructDistancedSequence(int targetNumber) {
        // Initialize the result sequence with size 2*n - 1 filled with 0s
        vector<int> resultSequence(targetNumber * 2 - 1, 0);

        // Keep track of which numbers are already placed in the sequence
        vector<bool> isNumberUsed(targetNumber + 1, false);

        // Start recursive backtracking to construct the sequence
        findLexicographicallyLargestSequence(0, resultSequence, isNumberUsed,
                                             targetNumber);

        return resultSequence;
    }

private:
    // Recursive function to generate the desired sequence
    bool findLexicographicallyLargestSequence(int currentIndex,
                                              vector<int>& resultSequence,
                                              vector<bool>& isNumberUsed,
                                              int targetNumber) {
        // If we have filled all positions, return true indicating success
        if (currentIndex == resultSequence.size()) {
            return true;
        }

        // If the current position is already filled, move to the next index
        if (resultSequence[currentIndex] != 0) {
            return findLexicographicallyLargestSequence(
                currentIndex + 1, resultSequence, isNumberUsed, targetNumber);
        }

        // Attempt to place numbers from targetNumber to 1 for a
        // lexicographically largest result
        for (int numberToPlace = targetNumber; numberToPlace >= 1;
             numberToPlace--) {
            if (isNumberUsed[numberToPlace]) continue;

            isNumberUsed[numberToPlace] = true;
            resultSequence[currentIndex] = numberToPlace;

            // If placing number 1, move to the next index directly
            if (numberToPlace == 1) {
                if (findLexicographicallyLargestSequence(
                        currentIndex + 1, resultSequence, isNumberUsed,
                        targetNumber)) {
                    return true;
                }
            }
            // Place larger numbers at two positions if valid
            else if (currentIndex + numberToPlace < resultSequence.size() &&
                     resultSequence[currentIndex + numberToPlace] == 0) {
                resultSequence[currentIndex + numberToPlace] = numberToPlace;

                if (findLexicographicallyLargestSequence(
                        currentIndex + 1, resultSequence, isNumberUsed,
                        targetNumber)) {
                    return true;
                }

                // Undo the placement for backtracking
                resultSequence[currentIndex + numberToPlace] = 0;
            }

            // Undo current placement and mark the number as unused
            resultSequence[currentIndex] = 0;
            isNumberUsed[numberToPlace] = false;
        }

        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[] constructDistancedSequence(int targetNumber) {
        // Initialize the result sequence with size 2*n - 1 filled with 0s
        int[] resultSequence = new int[targetNumber * 2 - 1];

        // Keep track of which numbers are already placed in the sequence
        boolean[] isNumberUsed = new boolean[targetNumber + 1];

        // Start recursive backtracking to construct the sequence
        findLexicographicallyLargestSequence(
            0,
            resultSequence,
            isNumberUsed,
            targetNumber
        );

        return resultSequence;
    }

    // Recursive function to generate the desired sequence
    private boolean findLexicographicallyLargestSequence(
        int currentIndex,
        int[] resultSequence,
        boolean[] isNumberUsed,
        int targetNumber
    ) {
        // If we have filled all positions, return true indicating success
        if (currentIndex == resultSequence.length) {
            return true;
        }

        // If the current position is already filled, move to the next index
        if (resultSequence[currentIndex] != 0) {
            return findLexicographicallyLargestSequence(
                currentIndex + 1,
                resultSequence,
                isNumberUsed,
                targetNumber
            );
        }

        // Attempt to place numbers from targetNumber to 1 for a
        // lexicographically largest result
        for (
            int numberToPlace = targetNumber;
            numberToPlace >= 1;
            numberToPlace--
        ) {
            if (isNumberUsed[numberToPlace]) continue;

            isNumberUsed[numberToPlace] = true;
            resultSequence[currentIndex] = numberToPlace;

            // If placing number 1, move to the next index directly
            if (numberToPlace == 1) {
                if (
                    findLexicographicallyLargestSequence(
                        currentIndex + 1,
                        resultSequence,
                        isNumberUsed,
                        targetNumber
                    )
                ) {
                    return true;
                }
            }
            // Place larger numbers at two positions if valid
            else if (
                currentIndex + numberToPlace < resultSequence.length &&
                resultSequence[currentIndex + numberToPlace] == 0
            ) {
                resultSequence[currentIndex + numberToPlace] = numberToPlace;

                if (
                    findLexicographicallyLargestSequence(
                        currentIndex + 1,
                        resultSequence,
                        isNumberUsed,
                        targetNumber
                    )
                ) {
                    return true;
                }

                // Undo the placement for backtracking
                resultSequence[currentIndex + numberToPlace] = 0;
            }

            // Undo current placement and mark the number as unused
            resultSequence[currentIndex] = 0;
            isNumberUsed[numberToPlace] = false;
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def constructDistancedSequence(self, target_number: int) -> List[int]:
        # Initialize the result sequence with size 2*n - 1 filled with 0s
        result_sequence = [0] * (target_number * 2 - 1)

        # Keep track of which numbers are already placed in the sequence
        is_number_used = [False] * (target_number + 1)

        # Start recursive backtracking to construct the sequence
        self.find_lexicographically_largest_sequence(
            0, result_sequence, is_number_used, target_number
        )

        return result_sequence

    # Recursive function to generate the desired sequence
    def find_lexicographically_largest_sequence(
        self, current_index, result_sequence, is_number_used, target_number
    ):
        # If we have filled all positions, return true indicating success
        if current_index == len(result_sequence):
            return True

        # If the current position is already filled, move to the next index
        if result_sequence[current_index] != 0:
            return self.find_lexicographically_largest_sequence(
                current_index + 1,
                result_sequence,
                is_number_used,
                target_number,
            )

        # Attempt to place numbers from targetNumber to 1 for a
        # lexicographically largest result
        for number_to_place in range(target_number, 0, -1):
            if is_number_used[number_to_place]:
                continue

            is_number_used[number_to_place] = True
            result_sequence[current_index] = number_to_place

            # If placing number 1, move to the next index directly
            if number_to_place == 1:
                if self.find_lexicographically_largest_sequence(
                    current_index + 1,
                    result_sequence,
                    is_number_used,
                    target_number,
                ):
                    return True
            # Place larger numbers at two positions if valid
            elif (
                current_index + number_to_place < len(result_sequence)
                and result_sequence[current_index + number_to_place] == 0
            ):
                result_sequence[current_index + number_to_place] = (
                    number_to_place
                )

                if self.find_lexicographically_largest_sequence(
                    current_index + 1,
                    result_sequence,
                    is_number_used,
                    target_number,
                ):
                    return True

                # Undo the placement for backtracking
                result_sequence[current_index + number_to_place] = 0

            # Undo current placement and mark the number as unused
            result_sequence[current_index] = 0
            is_number_used[number_to_place] = False

        return False
```

</details>
