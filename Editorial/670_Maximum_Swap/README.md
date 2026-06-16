# 670. Maximum Swap

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-swap/)  
`Math` `Greedy`

**Problem Link:** [LeetCode 670 - Maximum Swap](https://leetcode.com/problems/maximum-swap/)

## Problem

You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

### Example 1

```text
Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
```

### Example 2

```text
Input: num = 9973
Output: 9973
Explanation: No swap.
```

## Constraints

- 0 <= num <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Create Maximum Number](https://leetcode.com/problems/create-maximum-number/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 670. Maximum Swap

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Greedy Two-Pass | C++, Java, Python3 |
| Suboptimal Greedy | C++, Java, Python3 |
| Space Optimized Greedy | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string numStr =
            to_string(num);  // Convert num to string for easy manipulation
        int n = numStr.size();
        int maxNum = num;  // Track the maximum number found

        // Try all possible swaps
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(numStr[i], numStr[j]);  // Swap digits at index i and j
                maxNum = max(
                    maxNum,
                    stoi(numStr));  // Update maxNum if the new number is larger
                swap(numStr[i],
                     numStr[j]);  // Swap back to restore the original string
            }
        }

        return maxNum;  // Return the largest number after all possible swaps
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumSwap(int num) {
        String numStr = Integer.toString(num); // Convert num to string for easy manipulation
        int n = numStr.length();
        int maxNum = num; // Track the maximum number found

        // Try all possible swaps
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                char[] numeral = numStr.toCharArray(); // Convert string to char array for swapping

                // Swap digits at index i and j
                char temp = numeral[i];
                numeral[i] = numeral[j];
                numeral[j] = temp;

                int tempNum = Integer.parseInt(new String(numeral)); // Convert the char array back to integer

                maxNum = Math.max(maxNum, tempNum); // Update maxNum if the new number is larger
            }
        }

        return maxNum; // Return the largest number after all possible swaps
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumSwap(self, num: int) -> int:
        num_str = str(num)  # Convert num to string for easy manipulation
        n = len(num_str)
        max_num = num  # Track the maximum number found

        # Try all possible swaps
        for i in range(n):
            for j in range(i + 1, n):
                num_list = list(
                    num_str
                )  # Convert the string to list for swapping

                num_list[i], num_list[j] = (
                    num_list[j],
                    num_list[i],
                )  # Swap digits at index i and j
                temp = int(
                    "".join(num_list)
                )  # Convert the list back to string and then to integer

                max_num = max(
                    max_num, temp
                )  # Update max_num if the new number is larger

        return max_num  # Return the largest number after all possible swaps
```

</details>

<br>

## Approach 2: Greedy Two-Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> maxRightIndex(n);  // Stores the index of the max digit from
                                       // current position to the end

        // First pass: Populate maxRightIndex with the index of the largest
        // digit to the right of each position
        maxRightIndex[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            maxRightIndex[i] = (numStr[i] > numStr[maxRightIndex[i + 1]])
                                   ? i
                                   : maxRightIndex[i + 1];
        }

        // Second pass: Find the first place where we can swap to maximize the
        // number
        for (int i = 0; i < n; ++i) {
            if (numStr[i] < numStr[maxRightIndex[i]]) {
                swap(numStr[i],
                     numStr[maxRightIndex[i]]);  // Swap to maximize the number
                return stoi(numStr);  // Return the new number immediately after
                                      // the swap
            }
        }

        return num;  // Return the original number if no swap can maximize it
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumSwap(int num) {
        char[] numArr = Integer.toString(num).toCharArray();
        int n = numArr.length;
        int[] maxRightIndex = new int[n];

        maxRightIndex[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            maxRightIndex[i] = (numArr[i] > numArr[maxRightIndex[i + 1]])
                ? i
                : maxRightIndex[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            if (numArr[i] < numArr[maxRightIndex[i]]) {
                char temp = numArr[i];
                numArr[i] = numArr[maxRightIndex[i]];
                numArr[maxRightIndex[i]] = temp;
                return Integer.parseInt(new String(numArr));
            }
        }

        return num;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumSwap(self, num: int) -> int:
        num_str = list(str(num))
        n = len(num_str)
        max_right_index = [0] * n

        max_right_index[n - 1] = n - 1
        for i in range(n - 2, -1, -1):
            max_right_index[i] = (
                i
                if num_str[i] > num_str[max_right_index[i + 1]]
                else max_right_index[i + 1]
            )

        for i in range(n):
            if num_str[i] < num_str[max_right_index[i]]:
                num_str[i], num_str[max_right_index[i]] = (
                    num_str[max_right_index[i]],
                    num_str[i],
                )
                return int("".join(num_str))

        return num
```

</details>

<br>

## Approach 3: Suboptimal Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> lastSeen(10,
                             -1);  // Store the last occurrence of each digit

        // Record the last occurrence of each digit
        for (int i = 0; i < n; ++i) {
            lastSeen[numStr[i] - '0'] = i;
        }

        // Traverse the string to find the first digit that can be swapped with
        // a larger one
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (lastSeen[d] > i) {
                    swap(numStr[i], numStr[lastSeen[d]]);  // Perform the swap
                    return stoi(numStr);  // Return the new number immediately
                                          // after the swap
                }
            }
        }

        return num;  // Return the original number if no swap can maximize it
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maximumSwap(int num) {
        String numStr = Integer.toString(num);
        int n = numStr.length();
        int[] lastSeen = new int[10]; // Store the last occurrence of each digit

        // Record the last occurrence of each digit
        for (int i = 0; i < n; ++i) {
            lastSeen[numStr.charAt(i) - '0'] = i;
        }

        // Traverse the string to find the first digit that can be swapped with a larger one
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > numStr.charAt(i) - '0'; --d) {
                if (lastSeen[d] > i) {
                    //Perform the swap
                    char[] arr = numStr.toCharArray();
                    char temp = arr[i];
                    arr[i] = arr[lastSeen[d]];
                    arr[lastSeen[d]] = temp;
                    numStr = new String(arr);

                    return Integer.parseInt(numStr); // Return the new number immediately after the swap
                }
            }
        }

        return num; // Return the original number if no swap can maximize it
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumSwap(self, num: int) -> int:
        num_str = str(num)
        n = len(num_str)
        last_seen = [-1] * 10  # Store the last occurrence of each digit

        # Record the last occurrence of each digit
        for i in range(n):
            last_seen[int(num_str[i])] = i

        # Traverse the string to find the first digit that can be swapped with a larger one
        for i in range(n):
            for d in range(9, int(num_str[i]), -1):
                if last_seen[d] > i:
                    # Perform the swap
                    num_str = list(num_str)
                    num_str[i], num_str[last_seen[d]] = (
                        num_str[last_seen[d]],
                        num_str[i],
                    )
                    num_str = "".join(num_str)

                    return int(
                        num_str
                    )  # Return the new number immediately after the swap

        return num  # Return the original number if no swap can maximize it
```

</details>

<br>

## Approach 4: Space Optimized Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        int maxDigitIndex = -1, swapIdx1 = -1, swapIdx2 = -1;

        // Traverse the string from right to left, tracking the max digit and
        // potential swap
        for (int i = n - 1; i >= 0; --i) {
            if (maxDigitIndex == -1 || numStr[i] > numStr[maxDigitIndex]) {
                maxDigitIndex = i;  // Update the index of the max digit
            } else if (numStr[i] < numStr[maxDigitIndex]) {
                swapIdx1 = i;  // Mark the smaller digit for swapping
                swapIdx2 = maxDigitIndex;  // Mark the larger digit for swapping
            }
        }

        // Perform the swap if a valid swap is found
        if (swapIdx1 != -1 && swapIdx2 != -1) {
            swap(numStr[swapIdx1], numStr[swapIdx2]);
        }

        return stoi(numStr);  // Return the new number or the original if no
                              // swap occurred
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumSwap(int num) {
        char[] numStr = Integer.toString(num).toCharArray();
        int n = numStr.length;
        int maxDigitIndex = -1, swapIdx1 = -1, swapIdx2 = -1;

        // Traverse the string from right to left, tracking the max digit and
        // potential swap
        for (int i = n - 1; i >= 0; --i) {
            if (maxDigitIndex == -1 || numStr[i] > numStr[maxDigitIndex]) {
                maxDigitIndex = i; // Update the index of the max digit
            } else if (numStr[i] < numStr[maxDigitIndex]) {
                swapIdx1 = i; // Mark the smaller digit for swapping
                swapIdx2 = maxDigitIndex; // Mark the larger digit for swapping
            }
        }

        // Perform the swap if a valid swap is found
        if (swapIdx1 != -1 && swapIdx2 != -1) {
            char temp = numStr[swapIdx1];
            numStr[swapIdx1] = numStr[swapIdx2];
            numStr[swapIdx2] = temp;
        }

        return Integer.parseInt(new String(numStr)); // Return the new number or the original if no
        // swap occurred
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumSwap(self, num: int) -> int:
        num_str = list(str(num))
        n = len(num_str)
        max_digit_index = -1
        swap_idx_1 = -1
        swap_idx_2 = -1

        # Traverse the string from right to left, tracking the max digit and
        # potential swap
        for i in range(n - 1, -1, -1):
            if max_digit_index == -1 or num_str[i] > num_str[max_digit_index]:
                max_digit_index = i  # Update the index of the max digit
            elif num_str[i] < num_str[max_digit_index]:
                swap_idx_1 = i  # Mark the smaller digit for swapping
                swap_idx_2 = (
                    max_digit_index  # Mark the larger digit for swapping
                )

        # Perform the swap if a valid swap is found
        if swap_idx_1 != -1 and swap_idx_2 != -1:
            num_str[swap_idx_1], num_str[swap_idx_2] = (
                num_str[swap_idx_2],
                num_str[swap_idx_1],
            )

        return int(
            "".join(num_str)
        )  # Return the new number or the original if no
        # swap occurred
```

</details>
