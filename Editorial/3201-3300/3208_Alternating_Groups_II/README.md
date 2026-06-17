# 3208. Alternating Groups II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/alternating-groups-ii/)  
`Array` `Sliding Window`

**Problem Link:** [LeetCode 3208 - Alternating Groups II](https://leetcode.com/problems/alternating-groups-ii/)

## Problem

There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

- colors[i] == 0 means that tile i is red.
- colors[i] == 1 means that tile i is blue.

An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

### Example 1

### Example 2

### Example 3

## Constraints

- 3 <= colors.length <= 105
- 0 <= colors[i] <= 1
- 3 <= k <= colors.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3208. Alternating Groups II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Expanding the Array & Sliding Window | C++, Java, Python3 |
| Two Passes | C++, Java, Python3 |
| One Pass | C++, Java, Python3 |

## Approach 1: Expanding the Array & Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // Extend the array to handle circular sequences
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int length = colors.size();
        int result = 0;
        // Initialize the bounds of the sliding window
        int left = 0;
        int right = 1;

        while (right < length) {
            // Check if the current color is the same as the last one
            if (colors[right] == colors[right - 1]) {
                // Pattern breaks, reset window from the current position
                left = right;
                right++;
                continue;
            }

            // Expand the window to the right
            right++;

            // Skip counting sequence if its length is less than k
            if (right - left < k) continue;

            // Record a valid sequence and shrink window from the left to search
            // for more
            result++;
            left++;
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

    public int numberOfAlternatingGroups(int[] colors, int k) {
        int[] extendedColors = new int[colors.length + k - 1];
        // Extend the array to handle circular sequences
        for (int i = 0; i < colors.length; i++) {
            extendedColors[i] = colors[i];
        }
        for (int i = 0; i < k - 1; i++) {
            extendedColors[colors.length + i] = colors[i];
        }

        int length = extendedColors.length;
        int result = 0;
        // Initialize the bounds of the sliding window
        int left = 0;
        int right = 1;

        while (right < length) {
            // Check if the current color is the same as the last one
            if (extendedColors[right] == extendedColors[right - 1]) {
                // Pattern breaks, reset window from the current position
                left = right;
                right++;
                continue;
            }

            // Expand the window to the right
            right++;

            // Skip counting sequence if its length is less than k
            if (right - left < k) continue;

            // Record a valid sequence and shrink window from the left to search for more
            result++;
            left++;
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
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        # Extend the array to handle circular sequences
        for i in range(k - 1):
            colors.append(colors[i])

        length = len(colors)
        result = 0
        # Initialize the bounds of the sliding window
        left = 0
        right = 1

        while right < length:
            # Check if the current color is the same as the last one
            if colors[right] == colors[right - 1]:

                # Pattern breaks, reset window from the current position
                left = right
                right += 1
                continue

            # Extend window
            right += 1

            # Skip counting sequence if its length is less than k
            if right - left < k:
                continue

            # Record a valid sequence and shrink window from the left to search for more
            result += 1
            left += 1

        return result
```

</details>

<br>

## Approach 2: Two Passes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int length = colors.size();
        int result = 0;
        // Tracks the length of the current alternating sequence
        int alternatingElementsCount = 1;
        int lastColor = colors[0];

        for (int index = 1; index < length; index++) {
            // Check if the current color is the same as the last one
            if (colors[index] == lastColor) {
                // Pattern breaks, reset sequence length
                alternatingElementsCount = 1;
                lastColor = colors[index];
                continue;
            }

            // Sequence can be extended
            alternatingElementsCount++;

            // Record a new alternating sequence
            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
        }

        // Wrap around to the first k - 1 elements
        for (int index = 0; index < k - 1; index++) {
            // Pattern breaks. Since there are less than k elements remaining,
            // no more sequences can be formed
            if (colors[index] == lastColor) break;

            // Extend the pattern
            alternatingElementsCount++;

            // Record a new alternating sequence
            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
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

    public int numberOfAlternatingGroups(int[] colors, int k) {
        int length = colors.length;
        int result = 0;
        // Tracks the length of the current alternating sequence
        int alternatingElementsCount = 1;
        int lastColor = colors[0];

        for (int index = 1; index < length; index++) {
            // Check if the current color is the same as the last one
            if (colors[index] == lastColor) {
                // Pattern breaks, reset sequence length
                alternatingElementsCount = 1;
                lastColor = colors[index];
                continue;
            }
            // Sequence can be extended
            alternatingElementsCount++;

            // Record a new alternating sequence
            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
        }

        // Wrap around to the first k - 1 elements
        for (int index = 0; index < k - 1; index++) {
            // Pattern breaks. Since there are less than k elements remaining,
            // no more sequences can be formed
            if (colors[index] == lastColor) break;

            // Extend the pattern
            alternatingElementsCount++;

            // Record a new alternating sequence
            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
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
    def numberOfAlternatingGroups(self, colors, k):
        length = len(colors)
        result = 0
        # Tracks the length of the current alternating sequence
        alternating_elements_count = 1
        last_color = colors[0]

        # First pass through the array
        for index in range(1, length):
            # Check if the current color is the same as the last one
            if colors[index] == last_color:
                # Pattern breaks, reset sequence length
                alternating_elements_count = 1
                last_color = colors[index]
                continue

            # Sequence can be extended
            alternating_elements_count += 1

            # If sequence length reaches at least k, count it
            if alternating_elements_count >= k:
                result += 1

            last_color = colors[index]

        # Wrap around to the first k - 1 elements
        for index in range(k - 1):

            # Pattern breaks. Since there are less than k elements remaining,
            # no more sequences can be formed
            if colors[index] == last_color:
                break

            # Extend the pattern
            alternating_elements_count += 1

            # Record a new alternating sequence
            if alternating_elements_count >= k:
                result += 1

            last_color = colors[index]

        return result
```

</details>

<br>

## Approach 3: One Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int length = colors.size();
        int result = 0;
        // Tracks the length of the current alternating sequence
        int alternatingElementsCount = 1;
        int lastColor = colors[0];

        // Loop through the array, including the wrap-around (circular check)
        for (int i = 1; i < length + k - 1; i++) {
            // Use modulo to handle circular traversal
            int index = i % length;

            // Check if current color is the same as last color
            if (colors[index] == lastColor) {
                // Pattern breaks, reset sequence length
                alternatingElementsCount = 1;
                lastColor = colors[index];
                continue;
            }

            // Extend alternating sequence
            alternatingElementsCount += 1;

            // If sequence length reaches at least k, count it
            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
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

    public int numberOfAlternatingGroups(int[] colors, int k) {
        int length = colors.length;
        int result = 0;
        // Length of current alternating sequence
        int alternatingElementsCount = 1;
        int lastColor = colors[0];

        // Loop through array with circular traversal
        for (int i = 1; i < length + k - 1; i++) {
            int index = i % length; // Wrap around using modulo

            // Check if current color is the same as last color
            if (colors[index] == lastColor) {
                // Pattern breaks, reset sequence length
                alternatingElementsCount = 1;
                lastColor = colors[index];
                continue;
            }

            // Extend alternating sequence
            alternatingElementsCount += 1;

            // If sequence length reaches at least k, count it
            if (alternatingElementsCount >= k) {
                result++;
            }

            lastColor = colors[index];
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
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        length = len(colors)
        result = 0
        alternating_elements_count = 1  # Length of current alternating sequence
        last_color = colors[0]  # Previous color

        # Loop through array with circular traversal
        for i in range(1, length + k - 1):
            index = i % length  # Wrap around using modulo

            # Check if current color is the same as the last color
            if colors[index] == last_color:
                # Pattern breaks, reset sequence length
                alternating_elements_count = 1
                last_color = colors[index]
                continue

            # Extend sequence
            alternating_elements_count += 1

            # If sequence length reaches at least k, count it
            if alternating_elements_count >= k:
                result += 1

            last_color = colors[index]

        return result
```

</details>
