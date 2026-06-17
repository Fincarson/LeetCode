# 2709. Greatest Common Divisor Traversal

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/greatest-common-divisor-traversal/)  
`Array` `Math` `Union-Find` `Number Theory`

**Problem Link:** [LeetCode 2709 - Greatest Common Divisor Traversal](https://leetcode.com/problems/greatest-common-divisor-traversal/)

## Problem

You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.

Your task is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.

Return true if it is possible to traverse between all such pairs of indices, or false otherwise.

### Example 1

```text
Input: nums = [2,3,6]
Output: true
Explanation: In this example, there are 3 possible pairs of indices: (0, 1), (0, 2), and (1, 2).
To go from index 0 to index 1, we can use the sequence of traversals 0 -> 2 -> 1, where we move from index 0 to index 2 because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1, and then move from index 2 to index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 > 1.
To go from index 0 to index 2, we can just go directly because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1. Likewise, to go from index 1 to index 2, we can just go directly because gcd(nums[1], nums[2]) = gcd(3, 6) = 3 > 1.
```

### Example 2

```text
Input: nums = [3,9,5]
Output: false
Explanation: No sequence of traversals can take us from index 0 to index 2 in this example. So, we return false.
```

### Example 3

```text
Input: nums = [4,3,12,8]
Output: true
Explanation: There are 6 possible pairs of indices to traverse between: (0, 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A valid sequence of traversals exists for each pair, so we return true.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Graph Connectivity With Threshold](https://leetcode.com/problems/graph-connectivity-with-threshold/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2709. Greatest Common Divisor Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Creating a graph with dummy nodes and edges | C++, Java, Python3 |

## Approach 1: Creating a graph with dummy nodes and edges

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int N) {
        for (int i = 0; i <= N; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;
        if (size[fx] > size[fy]) swap(fx, fy);
        parent[fx] = fy;
        size[fy] += size[fx];
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int MAX = 100000;
        int N = nums.size();
        vector<bool> has(MAX + 1, false);
        for (int x : nums) {
            has[x] = true;
        }

        if (N == 1) return true;
        if (has[1]) return false;

        vector<int> sieve(MAX + 1, 0);
        for (int d = 2; d <= MAX; d++) {
            if (sieve[d] == 0) {
                for (int v = d; v <= MAX; v += d) {
                    sieve[v] = d;
                }
            }
        }

        DSU unionfind(2 * MAX + 1);
        for (int x : nums) {
            int val = x;
            while (val > 1) {
                int prime = sieve[val];
                int root = prime + MAX;
                if (unionfind.find(root) != unionfind.find(x)) {
                    unionfind.merge(root, x);
                }
                while (val % prime == 0) {
                    val /= prime;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i <= MAX; i++) {
            if (has[i] && unionfind.find(i) == i) {
                cnt++;
            }
        }
        return cnt == 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canTraverseAllPairs(int[] nums) {
        int MAX = 100000;
        int N = nums.length;
        boolean[] has = new boolean[MAX + 1];
        for (int x : nums) {
            has[x] = true;
        }

        // edge cases
        if (N == 1) {
            return true;
        }
        if (has[1]) {
            return false;
        }

        // the general solution
        int[] sieve = new int[MAX + 1];
        for (int d = 2; d <= MAX; d++) {
            if (sieve[d] == 0) {
                for (int v = d; v <= MAX; v += d) {
                    sieve[v] = d;
                }
            }
        }

        DSU union = new DSU(2 * MAX + 1);
        for (int x : nums) {
            int val = x;
            while (val > 1) {
                int prime = sieve[val];
                int root = prime + MAX;
                if (union.find(root) != union.find(x)) {
                    union.merge(root, x);
                }
                while (val % prime == 0) {
                    val /= prime;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i <= MAX; i++) {
            if (has[i] && union.find(i) == i) {
                cnt++;
            }
        }
        return cnt == 1;
    }
}

class DSU {

    public int[] dsu;
    public int[] size;

    public DSU(int N) {
        dsu = new int[N + 1];
        size = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            dsu[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        return dsu[x] == x ? x : (dsu[x] = find(dsu[x]));
    }

    public void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) {
            return;
        }
        if (size[fx] > size[fy]) {
            int temp = fx;
            fx = fy;
            fy = temp;
        }
        dsu[fx] = fy;
        size[fy] += size[fx];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def canTraverseAllPairs(self, nums):
        MAX = max(nums)
        N = len(nums)
        has = [False] * (MAX + 1)
        for x in nums:
            has[x] = True

        # edge cases
        if N == 1:
            return True
        if has[1]:
            return False

        # the general solution
        sieve = [0] * (MAX + 1)
        for d in range(2, MAX + 1):
            if sieve[d] == 0:
                for v in range(d, MAX + 1, d):
                    sieve[v] = d

        union = DSU(2 * MAX + 1)
        for x in nums:
            val = x
            while val > 1:
                prime = sieve[val]
                root = prime + MAX
                if union.find(root) != union.find(x):
                    union.merge(root, x)
                while val % prime == 0:
                    val //= prime

        cnt = 0
        for i in range(2, MAX + 1):
            if has[i] and union.find(i) == i:
                cnt += 1
        return cnt == 1


class DSU:

    def __init__(self, N):
        self.dsu = list(range(N + 1))
        self.size = [1] * (N + 1)

    def find(self, x):
        return x if self.dsu[x] == x else self.find(self.dsu[x])

    def merge(self, x, y):
        fx = self.find(x)
        fy = self.find(y)
        if fx == fy:
            return
        if self.size[fx] > self.size[fy]:
            fx, fy = fy, fx
        self.dsu[fx] = fy
        self.size[fy] += self.size[fx]
```

</details>
