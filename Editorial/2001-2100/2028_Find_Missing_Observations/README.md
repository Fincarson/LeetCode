# 2028. Find Missing Observations

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-missing-observations/)  
`Array` `Math` `Simulation`

**Problem Link:** [LeetCode 2028 - Find Missing Observations](https://leetcode.com/problems/find-missing-observations/)

## Problem

You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.

You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.

### Example 1

```text
Input: rolls = [3,2,4,3], mean = 4, n = 2
Output: [6,6]
Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
```

### Example 2

```text
Input: rolls = [1,5,6], mean = 3, n = 4
Output: [2,3,2,2]
Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.
```

### Example 3

```text
Input: rolls = [1,2,3,4], mean = 6, n = 4
Output: []
Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.
```

## Constraints

- m == rolls.length
- 1 <= n, m <= 105
- 1 <= rolls[i], mean <= 6

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Dice Rolls With Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Dice Roll Simulation](https://leetcode.com/problems/dice-roll-simulation/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2028. Find Missing Observations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Math | C++, Java, Python3 |

## Approach: Math

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (int i = 0; i < rolls.size(); i++) {
            sum = sum + rolls[i];
        }
        // Find the remaining sum.
        int remainingSum = mean * (n + rolls.size()) - sum;
        // Check if sum is valid or not.
        if (remainingSum > 6 * n or remainingSum < n) {
            return {};
        }
        int distributeMean = remainingSum / n;
        int mod = remainingSum % n;
        // Distribute the remaining mod elements in nElements array.
        vector<int> nElements(n, distributeMean);
        for (int i = 0; i < mod; i++) {
            nElements[i]++;
        }
        return nElements;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[] missingRolls(int[] rolls, int mean, int n) {
        int sum = 0;
        for (int roll : rolls) {
            sum = sum + roll;
        }
        // Find the remaining sum.
        int remainingSum = mean * (n + rolls.length) - sum;
        // Check if sum is valid or not.
        if (remainingSum > 6 * n || remainingSum < n) {
            return new int[0];
        }
        int distributeMean = remainingSum / n;
        int mod = remainingSum % n;
        // Distribute the remaining mod elements in nElements array.
        int[] nElements = new int[n];
        Arrays.fill(nElements, distributeMean);
        for (int i = 0; i < mod; i++) {
            nElements[i]++;
        }
        return nElements;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        sum_rolls = sum(rolls)
        # Find the remaining sum.
        remaining_sum = mean * (n + len(rolls)) - sum_rolls
        # Check if sum is valid or not.
        if remaining_sum > 6 * n or remaining_sum < n:
            return []
        distribute_mean = remaining_sum // n
        mod = remaining_sum % n
        # Distribute the remaining mod elements in n_elements list.
        n_elements = [distribute_mean] * n
        for i in range(mod):
            n_elements[i] += 1
        return n_elements
```

</details>
