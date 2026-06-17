# 2516. Take K of Each Character From Left and Right

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/)  
`Hash Table` `String` `Sliding Window`

**Problem Link:** [LeetCode 2516 - Take K of Each Character From Left and Right](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/)

## Problem

You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

### Example 1

```text
Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation:
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.
```

### Example 2

```text
Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.
```

## Constraints

- 1 <= s.length <= 105
- s consists of only the letters 'a', 'b', and 'c'.
- 0 <= k <= s.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Reorder List](https://leetcode.com/problems/reorder-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2516. Take K of Each Character From Left and Right

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion (Time Limit Exceeded) | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |

## Approach 1: Recursion (Time Limit Exceeded)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    int minMinutes = INT_MAX;

public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        vector<int> count(3, 0);
        solve(s, k, 0, s.length() - 1, count, 0);
        return minMinutes == INT_MAX ? -1 : minMinutes;
    }

private:
    void solve(string& s, int k, int left, int right, vector<int> count,
               int minutes) {
        // Base case: check if we have k of each character
        if (count[0] >= k && count[1] >= k && count[2] >= k) {
            minMinutes = min(minMinutes, minutes);
            return;
        }
        // If we can't take more characters
        if (left > right) return;

        // Take from left
        vector<int> leftCount = count;
        leftCount[s[left] - 'a']++;
        solve(s, k, left + 1, right, leftCount, minutes + 1);

        // Take from right
        vector<int> rightCount = count;
        rightCount[s[right] - 'a']++;
        solve(s, k, left, right - 1, rightCount, minutes + 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    int minMinutes = Integer.MAX_VALUE;

    public int takeCharacters(String s, int k) {
        if (k == 0) return 0;
        int[] count = new int[3];
        solve(s, k, 0, s.length() - 1, count, 0);
        return minMinutes == Integer.MAX_VALUE ? -1 : minMinutes;
    }

    private void solve(
        String s,
        int k,
        int left,
        int right,
        int[] count,
        int minutes
    ) {
        // Base case: check if we have k of each character
        if (count[0] >= k && count[1] >= k && count[2] >= k) {
            minMinutes = Math.min(minMinutes, minutes);
            return;
        }

        // If we can't take more characters
        if (left > right) return;

        // Take from left
        int[] leftCount = count.clone();
        leftCount[s.charAt(left) - 'a']++;
        solve(s, k, left + 1, right, leftCount, minutes + 1);

        // Take from right
        int[] rightCount = count.clone();
        rightCount[s.charAt(right) - 'a']++;
        solve(s, k, left, right - 1, rightCount, minutes + 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.min_minutes = float("inf")

    def takeCharacters(self, s: str, k: int) -> int:
        if k == 0:
            return 0
        count = [0, 0, 0]
        self._solve(s, k, 0, len(s) - 1, count, 0)
        return -1 if self.min_minutes == float("inf") else self.min_minutes

    def _solve(self, s, k, left, right, count, minutes):
        # Base case: check if we have k of each character
        if count[0] >= k and count[1] >= k and count[2] >= k:
            self.min_minutes = min(self.min_minutes, minutes)
            return
        # If we can't take more characters
        if left > right:
            return

        # Take from left
        left_count = count.copy()
        left_count[ord(s[left]) - ord("a")] += 1
        self._solve(s, k, left + 1, right, left_count, minutes + 1)

        # Take from right
        right_count = count.copy()
        right_count[ord(s[right]) - ord("a")] += 1
        self._solve(s, k, left, right - 1, right_count, minutes + 1)
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3, 0);
        int n = s.length();

        // Count total occurrences
        for (char c : s) {
            count[c - 'a']++;
        }

        // Check if we have enough characters
        for (int i = 0; i < 3; i++) {
            if (count[i] < k) return -1;
        }

        vector<int> window(3, 0);
        int left = 0, maxWindow = 0;

        // Find the longest window that leaves k of each character outside
        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;

            // Shrink window if we take too many characters
            while (left <= right &&
                   (count[0] - window[0] < k || count[1] - window[1] < k ||
                    count[2] - window[2] < k)) {
                window[s[left] - 'a']--;
                left++;
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return n - maxWindow;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int takeCharacters(String s, int k) {
        int[] count = new int[3];
        int n = s.length();

        // Count total occurrences
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        // Check if we have enough characters
        for (int i = 0; i < 3; i++) {
            if (count[i] < k) return -1;
        }

        int[] window = new int[3];
        int left = 0, maxWindow = 0;

        // Find the longest window that leaves k of each character outside
        for (int right = 0; right < n; right++) {
            window[s.charAt(right) - 'a']++;

            // Shrink window if we take too many characters
            while (
                left <= right &&
                (count[0] - window[0] < k ||
                    count[1] - window[1] < k ||
                    count[2] - window[2] < k)
            ) {
                window[s.charAt(left) - 'a']--;
                left++;
            }

            maxWindow = Math.max(maxWindow, right - left + 1);
        }

        return n - maxWindow;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        count = [0] * 3
        n = len(s)

        # Count total occurrences
        for c in s:
            count[ord(c) - ord("a")] += 1

        # Check if we have enough characters
        for i in range(3):
            if count[i] < k:
                return -1

        window = [0] * 3
        left, max_window = 0, 0

        # Find the longest window that leaves k of each character outside
        for right in range(n):
            window[ord(s[right]) - ord("a")] += 1

            # Shrink window if we take too many characters
            while left <= right and (
                count[0] - window[0] < k
                or count[1] - window[1] < k
                or count[2] - window[2] < k
            ):
                window[ord(s[left]) - ord("a")] -= 1
                left += 1

            max_window = max(max_window, right - left + 1)

        return n - max_window
```

</details>
