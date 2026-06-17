# 2141. Maximum Running Time of N Computers

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-running-time-of-n-computers/)  
`Array` `Binary Search` `Greedy` `Sorting`

**Problem Link:** [LeetCode 2141 - Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers/)

## Problem

You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.

Return the maximum number of minutes you can run all the n computers simultaneously.

### Example 1

```text
Input: n = 2, batteries = [3,3,3]
Output: 4
Explanation:
Initially, insert battery 0 into the first computer and battery 1 into the second computer.
After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
We can run the two computers simultaneously for at most 4 minutes, so we return 4.
```

### Example 2

```text
Input: n = 2, batteries = [1,1,1,1]
Output: 2
Explanation:
Initially, insert battery 0 into the first computer and battery 2 into the second computer.
After one minute, battery 0 and battery 2 are drained so you need to remove them and insert battery 1 into the first computer and battery 3 into the second computer.
After another minute, battery 1 and battery 3 are also drained so the first and second computers are no longer running.
We can run the two computers simultaneously for at most 2 minutes, so we return 2.
```

## Constraints

- 1 <= n <= batteries.length <= 105
- 1 <= batteries[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sell Diminishing-Valued Colored Balls](https://leetcode.com/problems/sell-diminishing-valued-colored-balls/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Amount of Time to Fill Cups](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2141. Maximum Running Time of N Computers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting and Prefix Sum | Java, Python |
| Binary Search | Java, Python3 |

## Approach 1: Sorting and Prefix Sum

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long maxRunTime(int n, int[] batteries) {
        // Get the sum of all extra batteries.
        Arrays.sort(batteries);
        long extra = 0;
        for (int i = 0; i < batteries.length - n; i++) {
            extra += batteries[i];
        }

        // live stands for the n largest batteries we chose for n computers.

        int[] live = Arrays.copyOfRange(batteries, batteries.length - n, batteries.length);

        // We increase the total running time using 'extra' by increasing 
        // the running time of the computer with the smallest battery.
        for (int i = 0; i < n - 1; i++) {
            // If the target running time is between live[i] and live[i + 1].
            if (extra < (long)(i + 1) * (live[i + 1] - live[i])) {
                return live[i] + extra / (long)(i + 1);
            }

            // Reduce 'extra' by the total power used.
            extra -= (long)(i + 1) * (live[i + 1] - live[i]);
        }

        // If there is power left, we can increase the running time 
        // of all computers.
        return live[n - 1] + extra / n;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        # Get the sum of all extra batteries.
        batteries.sort()   
        extra = sum(batteries[:-n])
        
        # live stands for the n largest batteries we chose for n computers.

        live = batteries[-n:]
        
        # We increase the total running time using 'extra' by increasing 
        # the running time of the computer with the smallest battery.
        for i in range(n - 1):
            # If the target running time is between live[i] and live[i + 1].
            if extra // (i + 1) < live[i + 1] - live[i]:
                return live[i] + extra // (i + 1)
            
            # Reduce 'extra' by the total power used.
            extra -= (i + 1) * (live[i + 1] - live[i])
        
        # If there is power left, we can increase the running time 
        # of all computers.
        return live[-1] + extra // n
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long sumPower = 0;
        for (int power : batteries)
            sumPower += power;
        long left = 1, right = sumPower / n;
        
        while (left < right){
            long target = right - (right - left) / 2;
            long extra = 0;
            
            for (int power : batteries)
                extra += Math.min(power, target);

            if (extra >= (long)(n * target))
                left = target;
            else
                right = target - 1;
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        left, right = 1, sum(batteries) // n
        
        while left < right:
            target = right - (right - left) // 2
            
            extra = 0
            for power in batteries:
                extra += min(power, target)
            
            if extra // n >= target:
                left = target
            else:
                right = target - 1
        
        return left
```

</details>
