# 956. Tallest Billboard

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/tallest-billboard/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 956 - Tallest Billboard](https://leetcode.com/problems/tallest-billboard/)

## Problem

You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.

### Example 1

```text
Input: rods = [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
```

### Example 2

```text
Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
```

### Example 3

```text
Input: rods = [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.
```

## Constraints

- 1 <= rods.length <= 20
- 1 <= rods[i] <= 1000
- sum(rods[i]) <= 5000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 956. Tallest Billboard

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Meet in the Middle | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |

## Approach 1: Meet in the Middle

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    map<int, int> helper(vector<int>& rods, int leftIndex, int rightIndex) {
        set<pair<int, int>> states;
        states.insert({0, 0});
        for (int i = leftIndex; i < rightIndex; ++i) {
            int r = rods[i];
            set<pair<int, int>> newStates;
            for (auto p : states) {
                newStates.insert({p.first + r, p.second});
                newStates.insert({p.first, p.second + r});
            }
            states.insert(newStates.begin(), newStates.end());
        }

        map<int, int> dp;
        for (auto p : states) {
            int left = p.first, right = p.second;
            if (dp.find(left - right) == dp.end())
                dp[left - right] = left;
            else
                dp[left - right] = max(dp[left - right], left);
        }
        return dp;
    }

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        map<int, int> firstHalf = helper(rods, 0, n / 2);
        map<int, int> secondHalf = helper(rods, n / 2, n);

        int answer = 0;
        for (pair<int, int> it : firstHalf) {
            if (secondHalf.count(-it.first) != 0) {
                answer = max(answer, it.second + secondHalf[-it.first]);
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Helper function to collect every combination `(left, right)`
    Map<Integer, Integer> helper(int[] rods, int leftIndex, int rightIndex) {
        Set<Pair<Integer, Integer>> states = new HashSet<>();
        states.add(new Pair(0, 0));
        for (int i = leftIndex; i < rightIndex; ++i) {
            int r = rods[i];
            Set<Pair<Integer, Integer>> newStates = new HashSet<>();
            for (Pair<Integer, Integer> p : states) {
                newStates.add(new Pair(p.getKey() + r, p.getValue()));
                newStates.add(new Pair(p.getKey(), p.getValue() + r));
            }
            states.addAll(newStates);
        }

        Map<Integer, Integer> dp = new HashMap<>();
        for (Pair<Integer, Integer> p : states) {
            int left = p.getKey(), right = p.getValue();
            dp.put(
                left - right,
                Math.max(dp.getOrDefault(left - right, 0), left)
            );
        }
        return dp;
    }

    public int tallestBillboard(int[] rods) {
        int n = rods.length;
        Map<Integer, Integer> firstHalf = helper(rods, 0, n / 2);
        Map<Integer, Integer> secondHalf = helper(rods, n / 2, n);

        int answer = 0;
        for (int diff : firstHalf.keySet()) {
            if (secondHalf.containsKey(-diff)) {
                answer = Math.max(
                    answer,
                    firstHalf.get(diff) + secondHalf.get(-diff)
                );
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def tallestBillboard(self, rods):
        # Helper function to collect every combination `(left, right)`
        def helper(half_rods):
            states = set()
            states.add((0, 0))
            for r in half_rods:
                new_states = set()
                for left, right in states:
                    new_states.add((left + r, right))
                    new_states.add((left, right + r))
                states |= new_states

            dp = {}
            for left, right in states:
                dp[left - right] = max(dp.get(left - right, 0), left)
            return dp

        n = len(rods)
        first_half = helper(rods[: n // 2])
        second_half = helper(rods[n // 2 :])

        answer = 0
        for diff in first_half:
            if -diff in second_half:
                answer = max(answer, first_half[diff] + second_half[-diff])
        return answer
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        // dp[taller - shorter] = taller
        map<int, int> dp;
        dp[0] = 0;

        for (int r : rods) {
            // Creating a copy of dp (new_dp) means we don't add r to these
            // stands.
            map<int, int> new_dp(dp);

            for (auto entry : dp) {
                int diff = entry.first;
                int taller = entry.second;
                int shorter = taller - diff;

                // Add r to the taller stand, thus the height difference is
                // increased to diff + r.
                int new_taller =
                    new_dp.count(diff + r) > 0 ? new_dp[diff + r] : 0;
                new_dp[diff + r] = max(new_taller, taller + r);

                // Add r to the shorter stand, the height difference is
                // expressed as abs(shorter + r - taller).
                int new_diff = abs(shorter + r - taller);
                int new_taller2 = max(shorter + r, taller);
                new_dp[new_diff] =
                    max(new_taller2,
                        new_dp.count(new_diff) > 0 ? new_dp[new_diff] : 0);
            }

            dp = new_dp;
        }

        // Return the maximum height with 0 difference.
        return dp.count(0) > 0 ? dp[0] : 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int tallestBillboard(int[] rods) {
        // dp[taller - shorter] = taller
        Map<Integer, Integer> dp = new HashMap<>();
        dp.put(0, 0);

        for (int r : rods) {
            // newDp means we don't add r to these stands.
            Map<Integer, Integer> newDp = new HashMap<>(dp);

            for (Map.Entry<Integer, Integer> entry : dp.entrySet()) {
                int diff = entry.getKey();
                int taller = entry.getValue();
                int shorter = taller - diff;

                // Add r to the taller stand, thus the height difference is increased to diff + r.
                int newTaller = newDp.getOrDefault(diff + r, 0);
                newDp.put(diff + r, Math.max(newTaller, taller + r));

                // Add r to the shorter stand, the height difference is expressed as abs(shorter + r - taller).
                int newDiff = Math.abs(shorter + r - taller);
                int newTaller2 = Math.max(shorter + r, taller);
                newDp.put(
                    newDiff,
                    Math.max(newTaller2, newDp.getOrDefault(newDiff, 0))
                );
            }

            dp = newDp;
        }

        // Return the maximum height with 0 difference.
        return dp.getOrDefault(0, 0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        # dp[taller - shorter] = taller
        dp = {0: 0}

        for r in rods:
            # dp.copy() means we don't add r to these stands.
            new_dp = dp.copy()
            for diff, taller in dp.items():
                shorter = taller - diff

                # Add r to the taller stand, thus the height difference is increased to diff + r.
                new_dp[diff + r] = max(new_dp.get(diff + r, 0), taller + r)

                # Add r to the shorter stand, the height difference is expressed as abs(shorter + r - taller).
                new_diff = abs(shorter + r - taller)
                new_taller = max(shorter + r, taller)
                new_dp[new_diff] = max(new_dp.get(new_diff, 0), new_taller)

            dp = new_dp

        # Return the maximum height with 0 difference.
        return dp.get(0, 0)
```

</details>
