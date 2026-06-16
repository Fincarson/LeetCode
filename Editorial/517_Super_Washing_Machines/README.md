# 517. Super Washing Machines

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/super-washing-machines/)  
`Array` `Greedy`

**Problem Link:** [LeetCode 517 - Super Washing Machines](https://leetcode.com/problems/super-washing-machines/)

## Problem

You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

For each move, you could choose any m (1 <= m <= n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time.

Given an integer array machines representing the number of dresses in each washing machine from left to right on the line, return the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.

### Example 1

```text
Input: machines = [1,0,5]
Output: 3
Explanation:
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3
3rd move:    2     1 <-- 3    =>    2     2     2
```

### Example 2

```text
Input: machines = [0,3,0]
Output: 2
Explanation:
1st move:    0 <-- 3     0    =>    1     2     0
2nd move:    1     2 --> 0    =>    1     1     1
```

### Example 3

```text
Input: machines = [0,2,0]
Output: -1
Explanation:
It's impossible to make all three washing machines have the same number of dresses.
```

## Constraints

- n == machines.length
- 1 <= n <= 104
- 0 <= machines[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 517. Super Washing Machines

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy. | Java, Python |

## Approach 1: Greedy.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int findMinMoves(int[] machines) {
    int n = machines.length, dressTotal = 0;
    for (int m : machines) dressTotal += m;
    if (dressTotal % n != 0) return -1;

    int dressPerMachine = dressTotal / n;
    // Change the number of dresses in the machines to
    // the number of dresses to be removed from this machine
    // (could be negative)
    for (int i = 0; i < n; i++) machines[i] -= dressPerMachine;

    // currSum is a number of dresses to move at this point, 
    // maxSum is the max number of dresses to move at this point or before,
    // m is the number of dresses to move out from the current machine.
    int currSum = 0, maxSum = 0, tmpRes = 0, res = 0;
    for (int m : machines) {
      currSum += m;
      maxSum = Math.max(maxSum, Math.abs(currSum));
      tmpRes = Math.max(maxSum, m);
      res = Math.max(res, tmpRes);
    }
    return res;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        n = len(machines)
        dress_total = sum(machines)
        if dress_total % n != 0:
            return -1
        
        dress_per_machine = dress_total // n
        for i in range(n):
            # Change the number of dresses in the machines to
            # the number of dresses to be removed from this machine
            # (could be negative)
            machines[i] -= dress_per_machine
            
        # curr_sum is the number of dresses to move at this point, 
        # max_sum is the max number of dresses to move at this point or before,
        # m is the number of dresses to move out from the current machine.
        curr_sum = max_sum = res = 0
        for m in machines:
            curr_sum += m
            max_sum = max(max_sum, abs(curr_sum))
            res = max(res, max_sum, m)
        return res
```

</details>
