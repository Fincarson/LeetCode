# 2244. Minimum Rounds to Complete All Tasks

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/)  
`Array` `Hash Table` `Greedy` `Counting`

**Problem Link:** [LeetCode 2244 - Minimum Rounds to Complete All Tasks](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/)

## Problem

You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

### Example 1

```text
Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2.
- In the second round, you complete 2 tasks of difficulty level 3.
- In the third round, you complete 3 tasks of difficulty level 4.
- In the fourth round, you complete 2 tasks of difficulty level 4.
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
```

### Example 2

```text
Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.
```

## Constraints

- 1 <= tasks.length <= 105
- 1 <= tasks[i] <= 109

Note: This question is the same as 2870: Minimum Number of Operations to Make Array Empty.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Odd String Difference](https://leetcode.com/problems/odd-string-difference/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Levels to Gain More Points](https://leetcode.com/problems/minimum-levels-to-gain-more-points/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2244. Minimum Rounds to Complete All Tasks

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Counting | C++, Java |

## Approach 1: Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        // Store the frequencies in the map.
        for (int task : tasks) {
            freq[task]++;
        }
        
        int minimumRounds = 0;
        // Iterate over the task's frequencies.
        for (auto [task, count] : freq) {
            // If the frequency is 1, it's not possible to complete tasks.
            if (count == 1) {
                return - 1;
            }

            if (count % 3 == 0) {
                // Group all the task in triplets.
                minimumRounds += count / 3;
            } else {
                // If count % 3 = 1; (count / 3 - 1) groups of triplets and 2 pairs.
                // If count % 3 = 2; (count / 3) groups of triplets and 1 pair.
                minimumRounds += count / 3 + 1;
            }
        }
        
        return minimumRounds;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> freq = new HashMap();
        // Store the frequencies in the map.
        for (int task : tasks) {
            freq.put(task, freq.getOrDefault(task, 0) + 1);
        }

        int minimumRounds = 0;
        // Iterate over the task's frequencies.
        for (int count : freq.values()) {
            // If the frequency is 1, it's not possible to complete tasks.
            if (count == 1) {
                return - 1;
            }

            if (count % 3 == 0) {
                // Group all the task in triplets.
                minimumRounds += count / 3;
            } else {
                // If count % 3 = 1; (count / 3 - 1) groups of triplets and 2 pairs.
                // If count % 3 = 2; (count / 3) groups of triplets and 1 pair.
                minimumRounds += count / 3 + 1;
            }
        }

        return minimumRounds;
    }
}
```

</details>
