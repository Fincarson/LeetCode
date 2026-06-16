# 1010. Pairs of Songs With Total Durations Divisible by 60

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)  
`Array` `Hash Table` `Counting`

**Problem Link:** [LeetCode 1010 - Pairs of Songs With Total Durations Divisible by 60](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)

## Problem

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

### Example 1

```text
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
```

### Example 2

```text
Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
```

## Constraints

- 1 <= time.length <= 6 * 104
- 1 <= time[i] <= 500

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Destroy Sequential Targets](https://leetcode.com/problems/destroy-sequential-targets/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Pairs That Form a Complete Day II](https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1010. Pairs of Songs With Total Durations Divisible by 60

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python3 |
| Use an Array to Store Frequencies | Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int count = 0, n = time.length;
        for (int i = 0; i < n; i++) {
            // j starts with i+1 so that i is always to the left of j
            // to avoid repetitive counting
            for (int j = i + 1; j < n; j++) {
                if ((time[i] + time[j]) % 60 == 0) {
                    count++;
                }
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        ret, n = 0, len(time)
        for i in range(n):
            # j starts with i+1 so that i is always to the left of j
            # to avoid repetitive counting
            for j in range(i + 1, n):
                ret += (time[i] + time[j]) % 60==0
        return ret
```

</details>

<br>

## Approach 2: Use an Array to Store Frequencies

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int remainders[] = new int[60];
        int count = 0;
        for (int t: time) {
            if (t % 60 == 0) { // check if a%60==0 && b%60==0
                count += remainders[0];
            } else { // check if a%60+b%60==60
                count += remainders[60 - t % 60];
            }
            remainders[t % 60]++; // remember to update the remainders
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        remainders = collections.defaultdict(int)
        ret = 0
        for t in time:
            if t % 60 == 0: # check if a%60==0 && b%60==0
                ret += remainders[0]
            else: # check if a%60+b%60==60
                ret += remainders[60-t%60]
            remainders[t % 60] += 1 # remember to update the remainders
        return ret
```

</details>
