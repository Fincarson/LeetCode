# 1732. Find the Highest Altitude

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-the-highest-altitude/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 1732 - Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)

## Problem

There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points iÃ¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

### Example 1

```text
Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
```

### Example 2

```text
Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
```

## Constraints

- n == gain.length
- 1 <= n <= 100
- -100 <= gain[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1732. Find the Highest Altitude

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Sum | C++, Java, Python3 |

## Approach: Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        // Highest altitude currently is 0.
        int highestPoint = currentAltitude;
        
        for (int altitudeGain : gain) {
            // Adding the gain in altitude to the current altitude.
            currentAltitude += altitudeGain;
            // Update the highest altitude.
            highestPoint = max(highestPoint, currentAltitude);
        }
        
        return highestPoint;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int largestAltitude(int[] gain) {
    int currentAltitude = 0;
    // Highest altitude currently is 0.
    int highestPoint = currentAltitude;

    for (int altitudeGain : gain) {
      // Adding the gain in altitude to the current altitude.
      currentAltitude += altitudeGain;
      // Update the highest altitude.
      highestPoint = Math.max(highestPoint, currentAltitude);
    }

    return highestPoint;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        current_altitude = 0
        # Highest altitude currently is 0.
        highest_point = current_altitude
        
        for altitude_gain in gain:
            # Adding the gain in altitude to the current altitude.
            current_altitude += altitude_gain
            # Update the highest altitude.
            highest_point = max(highest_point, current_altitude)
        
        return highest_point
```

</details>
