# 528. Random Pick with Weight

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/random-pick-with-weight/)  
`Array` `Math` `Binary Search` `Prefix Sum` `Randomized`

**Problem Link:** [LeetCode 528 - Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)

## Problem

You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

- For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).

### Example 1

```text
Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
```

### Example 2

```text
Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output
[null,1,1,1,1,0]

Explanation
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // return 1. It is returning the second element (index = 1) that has a probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0. It is returning the first element (index = 0) that has a probability of 1/4.

Since this is a randomization problem, multiple answers are allowed.
All of the following outputs can be considered correct:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
and so on.
```

## Constraints

- 1 <= w.length <= 104
- 1 <= w[i] <= 105
- pickIndex will be called at most 104 times.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Random Pick Index](https://leetcode.com/problems/random-pick-index/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Random Pick with Blacklist](https://leetcode.com/problems/random-pick-with-blacklist/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Random Point in Non-overlapping Rectangles](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 528. Random Pick with Weight

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sums with Linear Search | C++, Java, Python3 |
| Prefix Sums with Binary Search | C++, Java, Python3 |

## Approach 1: Prefix Sums with Linear Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    vector<int> prefixSums;
public:
    Solution(vector<int> &w) {
        for (auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }

    int pickIndex() {
        // generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums.back();
        // run a linear search to find the target zone
        for (int i = 0; i < prefixSums.size(); ++i)
            if (target < prefixSums[i])
                return i;
        return prefixSums.size() - 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int[] prefixSums;
    private int totalSum;

    public Solution(int[] w) {
        this.prefixSums = new int[w.length];

        int prefixSum = 0;
        for (int i = 0; i < w.length; ++i) {
            prefixSum += w[i];
            this.prefixSums[i] = prefixSum;
        }
        this.totalSum = prefixSum;
    }

    public int pickIndex() {
        double target = this.totalSum * Math.random();
        int i = 0;
        // run a linear search to find the target zone
        for (; i < this.prefixSums.length; ++i) {
            if (target < this.prefixSums[i])
                return i;
        }
        // to have a return statement, though this should never happen.
        return i - 1;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def __init__(self, w: List[int]):
        """
        :type w: List[int]
        """
        self.prefix_sums = []
        prefix_sum = 0
        for weight in w:
            prefix_sum += weight
            self.prefix_sums.append(prefix_sum)
        self.total_sum = prefix_sum

    def pickIndex(self) -> int:
        """
        :rtype: int
        """
        target = self.total_sum * random.random()
        # run a linear search to find the target zone
        for i, prefix_sum in enumerate(self.prefix_sums):
            if target < prefix_sum:
                return i
```

</details>

<br>

## Approach 2: Prefix Sums with Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    vector<int> prefixSums;

public:
    Solution(vector<int> &w) {
        for (auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }
    int pickIndex() {
        // generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums.back();
        return lower_bound(begin(prefixSums), end(prefixSums), target) - begin(prefixSums);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int[] prefixSums;
    private int totalSum;

    public Solution(int[] w) {
        this.prefixSums = new int[w.length];

        int prefixSum = 0;
        for (int i = 0; i < w.length; ++i) {
            prefixSum += w[i];
            this.prefixSums[i] = prefixSum;
        }
        this.totalSum = prefixSum;
    }

    public int pickIndex() {
        double target = this.totalSum * Math.random();

        // run a binary search to find the target zone
        int low = 0, high = this.prefixSums.length;
        while (low < high) {
            // better to avoid the overflow
            int mid = low + (high - low) / 2;
            if (target > this.prefixSums[mid])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self, w: List[int]):
        """
        :type w: List[int]
        """
        self.prefix_sums = []
        prefix_sum = 0
        for weight in w:
            prefix_sum += weight
            self.prefix_sums.append(prefix_sum)
        self.total_sum = prefix_sum

    def pickIndex(self) -> int:
        """
        :rtype: int
        """
        target = self.total_sum * random.random()
        # run a binary search to find the target zone
        low, high = 0, len(self.prefix_sums)
        while low < high:
            mid = low + (high - low) // 2
            if target > self.prefix_sums[mid]:
                low = mid + 1
            else:
                high = mid
        return low
```

</details>
