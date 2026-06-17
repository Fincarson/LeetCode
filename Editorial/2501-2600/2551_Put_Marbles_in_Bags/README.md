# 2551. Put Marbles in Bags

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/put-marbles-in-bags/)  
`Array` `Greedy` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 2551 - Put Marbles in Bags](https://leetcode.com/problems/put-marbles-in-bags/)

## Problem

You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.

Divide the marbles into the k bags according to the following rules:

- No bag is empty.
- If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
- If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].

The score after distributing the marbles is the sum of the costs of all the k bags.

Return the difference between the maximum and minimum scores among marble distributions.

### Example 1

```text
Input: weights = [1,3,5,1], k = 2
Output: 4
Explanation:
The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6.
The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10.
Thus, we return their difference 10 - 6 = 4.
```

### Example 2

```text
Input: weights = [1, 3], k = 2
Output: 0
Explanation: The only distribution possible is [1],[3].
Since both the maximal and minimal score are the same, we return 0.
```

## Constraints

- 1 <= k <= weights.length <= 105
- 1 <= weights[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2551. Put Marbles in Bags

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting | C++, Java, Python3 |

## Approach: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // We collect and sort the value of all n - 1 pairs.
        int n = weights.size();
        vector<int> pairWeights(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            pairWeights[i] += weights[i] + weights[i + 1];
        }

        sort(pairWeights.begin(), pairWeights.end());

        // Get the difference between the largest k - 1 values and the
        // smallest k - 1 values.
        long long answer = 0;
        for (int i = 0; i < k - 1; ++i) {
            answer += pairWeights[n - 2 - i] - pairWeights[i];
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

    public long putMarbles(int[] weights, int k) {
        // We collect and sort the value of all n - 1 pairs.
        int n = weights.length;
        int[] pairWeights = new int[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            pairWeights[i] = weights[i] + weights[i + 1];
        }
        // We will sort only the first (n - 1) elements of the array.
        Arrays.sort(pairWeights, 0, n - 1);

        // Get the difference between the largest k - 1 values and the
        // smallest k - 1 values.
        long answer = 0l;
        for (int i = 0; i < k - 1; ++i) {
            answer += pairWeights[n - 2 - i] - pairWeights[i];
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        # We collect and sort the value of all n - 1 pairs.
        n = len(weights)
        pairWeights = [weights[i] + weights[i + 1] for i in range(n - 1)]

        # Since python's sort function sorts the whole list, we don't limit it to the first n-1 elements here.
        pairWeights.sort()

        # Get the difference between the largest k - 1 values and the smallest k - 1 values.
        answer = 0
        for i in range(k - 1):
            answer += pairWeights[n - 2 - i] - pairWeights[i]

        return answer
```

</details>
