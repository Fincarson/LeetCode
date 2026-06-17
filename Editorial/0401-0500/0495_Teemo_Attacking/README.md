# 495. Teemo Attacking

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/teemo-attacking/)  
`Array` `Simulation`

**Problem Link:** [LeetCode 495 - Teemo Attacking](https://leetcode.com/problems/teemo-attacking/)

## Problem

Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly duration seconds. More formally, an attack at second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration - 1]. If Teemo attacks again before the poison effect ends, the timer for it is reset, and the poison effect will end duration seconds after the new attack.

You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks Ashe at second timeSeries[i], and an integer duration.

Return the total number of seconds that Ashe is poisoned.

### Example 1

```text
Input: timeSeries = [1,4], duration = 2
Output: 4
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 4, Teemo attacks, and Ashe is poisoned for seconds 4 and 5.
Ashe is poisoned for seconds 1, 2, 4, and 5, which is 4 seconds in total.
```

### Example 2

```text
Input: timeSeries = [1,2], duration = 2
Output: 3
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 2 however, Teemo attacks again and resets the poison timer. Ashe is poisoned for seconds 2 and 3.
Ashe is poisoned for seconds 1, 2, and 3, which is 3 seconds in total.
```

## Constraints

- 1 <= timeSeries.length <= 104
- 0 <= timeSeries[i], duration <= 107
- timeSeries is sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Can Place Flowers](https://leetcode.com/problems/can-place-flowers/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Dota2 Senate](https://leetcode.com/problems/dota2-senate/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 495. Teemo Attacking

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| One pass | Java, Python |

## Approach 1: One pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int findPoisonedDuration(int[] timeSeries, int duration) {
    int n = timeSeries.length;
    if (n == 0) return 0;

    int total = 0;
    for(int i = 0; i < n - 1; ++i)
      total += Math.min(timeSeries[i + 1] - timeSeries[i], duration);
    return total + duration;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        n = len(timeSeries)
        if n == 0:
            return 0
        
        total = 0
        for i in range(n - 1):
            total += min(timeSeries[i + 1] - timeSeries[i], duration)
        return total + duration
```

</details>
