# 2107. Number of Unique Flavors After Sharing K Candies

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/)  
`Array` `Hash Table` `Sliding Window`

**Problem Link:** [LeetCode 2107 - Number of Unique Flavors After Sharing K Candies](https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/)

## Problem

You are given a 0-indexed integer array candies, where candies[i] represents the flavor of the ith candy. Your mom wants you to share these candies with your little sister by giving her k consecutive candies, but you want to keep as many flavors of candies as possible.

Return the maximum number of unique flavors of candy you can keep after sharing  with your sister.

### Example 1

```text
Input: candies = [1,2,2,3,4,3], k = 3
Output: 3
Explanation:
Give the candies in the range [1, 3] (inclusive) with flavors [2,2,3].
You can eat candies with flavors [1,4,3].
There are 3 unique flavors, so return 3.
```

### Example 2

```text
Input: candies = [2,2,2,2,3,3], k = 2
Output: 2
Explanation:
Give the candies in the range [3, 4] (inclusive) with flavors [2,3].
You can eat candies with flavors [2,2,2,3].
There are 2 unique flavors, so return 2.
Note that you can also share the candies with flavors [2,2] and eat the candies with flavors [2,2,3,3].
```

### Example 3

```text
Input: candies = [2,4,5], k = 0
Output: 3
Explanation:
You do not have to give any candies.
You can eat the candies with flavors [2,4,5].
There are 3 unique flavors, so return 3.
```

## Constraints

- 0 <= candies.length <= 105
- 1 <= candies[i] <= 105
- 0 <= k <= candies.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Boxes](https://leetcode.com/problems/remove-boxes/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2107. Number of Unique Flavors After Sharing K Candies

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C++, Java, Python3 |

## Approach: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int uniqueFlav = 0;

        // Store the total number of unique flavors in the array.
        unordered_map<int, int> flavFreq;
        for (int c : candies) {
            if (++flavFreq[c] == 1) {
                uniqueFlav++;
            }
        }

        // Get the flavors used completely in the window.
        // It is implied when the frequency of a flavor becomes zero.
        int usedInWindow = 0;
        for (int i = 0; i < k; i++) {
            if (--flavFreq[candies[i]] == 0) {
                usedInWindow++;
            }
        }

        // Get the flavors in the remaining array currently.
        int maxFlav = uniqueFlav - usedInWindow;
        // Keep sliding the current window by one towards right.
        // Get the updated number of flavors in the current window.
        for (int i = k; i < candies.size(); i++) {
            // Remove the candy on the left end from the window
            // And if that candy is the only instance of the flavor,
            // Decrement the used flavors count.
            if (++flavFreq[candies[i - k]] == 1) {
                usedInWindow--;
            }

            // Add the candy on the right end at the ith index.
            // And if now all instances of the flavor are within the window
            // Increment the used counter by one.
            if (--flavFreq[candies[i]] == 0) {
                usedInWindow++;
            }
            maxFlav = max(maxFlav, uniqueFlav - usedInWindow);
        }

        return maxFlav;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.HashMap;
import java.util.Map;

class Solution {

    public int shareCandies(int[] candies, int k) {
        int uniqueFlav = 0;

        // Store the total number of unique flavors in the array.
        Map<Integer, Integer> flavFreq = new HashMap<>();
        for (int c : candies) {
            flavFreq.put(c, flavFreq.getOrDefault(c, 0) + 1);
            if (flavFreq.get(c) == 1) {
                uniqueFlav++;
            }
        }

        // Get the flavors used completely in the window.
        int usedInWindow = 0;
        for (int i = 0; i < k; i++) {
            flavFreq.put(candies[i], flavFreq.get(candies[i]) - 1);
            if (flavFreq.get(candies[i]) == 0) {
                usedInWindow++;
            }
        }

        // Get the flavors in the remaining array currently.
        int maxFlav = uniqueFlav - usedInWindow;

        // Slide the window to the right.
        for (int i = k; i < candies.length; i++) {
            // Remove the candy on the left end from the window.
            flavFreq.put(candies[i - k], flavFreq.get(candies[i - k]) + 1);
            if (flavFreq.get(candies[i - k]) == 1) {
                usedInWindow--;
            }

            // Add the candy on the right end at index i.
            flavFreq.put(candies[i], flavFreq.get(candies[i]) - 1);
            if (flavFreq.get(candies[i]) == 0) {
                usedInWindow++;
            }

            maxFlav = Math.max(maxFlav, uniqueFlav - usedInWindow);
        }

        return maxFlav;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shareCandies(self, candies, k):
        # Store the total number of unique flavors in the array.
        flav_freq = defaultdict(int)
        for c in candies:
            flav_freq[c] += 1

        # Get the total number of unique flavors in the array.
        unique_flav = len(flav_freq)

        # Get the flavors used completely in the window.
        used_in_window = 0
        for i in range(k):
            flav_freq[candies[i]] -= 1
            if flav_freq[candies[i]] == 0:
                used_in_window += 1

        # Get the flavors in the remaining array currently.
        max_flav = unique_flav - used_in_window

        # Slide the window to the right.
        for i in range(k, len(candies)):
            # Remove the candy on the left end from the window.
            flav_freq[candies[i - k]] += 1
            if flav_freq[candies[i - k]] == 1:
                used_in_window -= 1

            # Add the candy on the right end at index i.
            flav_freq[candies[i]] -= 1
            if flav_freq[candies[i]] == 0:
                used_in_window += 1

            max_flav = max(max_flav, unique_flav - used_in_window)

        return max_flav
```

</details>
