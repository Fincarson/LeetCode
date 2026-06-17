# 952. Largest Component Size by Common Factor

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/largest-component-size-by-common-factor/)  
`Array` `Hash Table` `Math` `Union-Find` `Number Theory`

**Problem Link:** [LeetCode 952 - Largest Component Size by Common Factor](https://leetcode.com/problems/largest-component-size-by-common-factor/)

## Problem

You are given an integer array of unique positive integers nums. Consider the following graph:

- There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
- There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.

Return the size of the largest connected component in the graph.

### Example 1

```text
Input: nums = [4,6,15,35]
Output: 4
```

### Example 2

```text
Input: nums = [20,50,9,63]
Output: 2
```

### Example 3

```text
Input: nums = [2,3,6,7,4,12,21,39]
Output: 8
```

## Constraints

- 1 <= nums.length <= 2 * 104
- 1 <= nums[i] <= 105
- All the values of nums are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Groups of Strings](https://leetcode.com/problems/groups-of-strings/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Distinct Prime Factors of Product of Array](https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 952. Largest Component Size by Common Factor

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Union-Find via Factors | Java, Python |
| Union-Find on Prime Factors | Java, Python |

## Approach 1: Union-Find via Factors

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int largestComponentSize(int[] A) {

        int maxValue = Arrays.stream(A).reduce(A[0], (x, y) -> x > y ? x : y);
        DisjointSetUnion dsu = new DisjointSetUnion(maxValue);
        // attribute each element to all the groups that lead by its factors.
        for (int num : A) {
            for (int factor=2; factor < (int)(Math.sqrt(num))+1; ++ factor)
                if (num % factor == 0) {
                    dsu.union(num, factor);
                    dsu.union(num, num / factor);
                }
        }

        // count the size of group one by one
        int maxGroupSize = 0;
        HashMap<Integer, Integer> groupCount = new HashMap<>();
        for (int num : A) {
            Integer groupId = dsu.find(num);
            Integer count = groupCount.getOrDefault(groupId, 0);
            groupCount.put(groupId, count+1);
            maxGroupSize = Math.max(maxGroupSize, count+1);
        }

        return maxGroupSize;
    }
}


class DisjointSetUnion {
    private int[] parent;
    private int[] size;

    public DisjointSetUnion(int size) {
        this.parent = new int[size + 1];
        this.size = new int[size + 1];
        for (int i = 0; i < size + 1; ++i) {
            this.parent[i] = i;
            this.size[i] = 1;
        }
    }

    /** return the component id that the element x belongs to. */
    public int find(int x) {
        if (this.parent[x] != x)
            this.parent[x] = this.find(this.parent[x]);
        return this.parent[x];
    }

    /**
     * merge the two components that x, y belongs to respectively,
     * and return the merged component id as the result.
     */
    public int union(int x, int y) {
        int px = this.find(x);
        int py = this.find(y);

        // the two nodes share the same group
        if (px == py)
            return px;

        // otherwise, connect the two sets (components)
        if (this.size[px] > this.size[py]) {
            // add the node to the union with less members.
            // keeping px as the index of the smaller component
            int temp = px;
            px = py;
            py = temp;
        }

        // add the smaller component to the larger one
        this.parent[px] = py;
        this.size[py] += this.size[px];
        return py;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def largestComponentSize(self, A: List[int]) -> int:

        dsu = DisjointSetUnion(max(A))

        # attribute each element in A
        #   to all the groups that lead by its factors.
        for a in A:
            for factor in range(2, int(sqrt(a))+1):
                if a % factor == 0:
                    dsu.union(a, factor)
                    dsu.union(a, a // factor)

        # count the size of group one by one
        max_size = 0
        group_count = defaultdict(int)
        for a in A:
            group_id = dsu.find(a)
            group_count[group_id] += 1
            max_size = max(max_size, group_count[group_id])

        return max_size


class DisjointSetUnion(object):

    def __init__(self, size):
        # initially, each node is an independent component
        self.parent = [i for i in range(size+1)]
        # keep the size of each component
        self.size = [1] * (size+1)
    
    def find(self, x):
        """ return the component id that the element x belongs to. """
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        """ merge the two components that x, y belongs to respectively,
              and return the merged component id as the result.
        """
        px, py = self.find(x), self.find(y)
        
        # the two nodes share the same set
        if px == py:
            return px
        
        # otherwise, connect the two sets (components)
        if self.size[px] > self.size[py]:
            # add the node to the union with less members.
            # keeping px as the index of the smaller component
            px, py = py, px
        # add the smaller component to the larger one
        self.parent[px] = py
        self.size[py] += self.size[px]
        # return the final (merged) group
        return py
```

</details>

<br>

## Approach 2: Union-Find on Prime Factors

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
List<Integer> primeDecompose(int num) {
    List<Integer> primeFactors = new ArrayList<Integer>();
    int factor = 2;

    while (num >= factor * factor) {
        if (num % factor == 0) {
            primeFactors.add(factor);
            num = num / factor;
        } else {
            factor += 1;
        }
    }
    primeFactors.add(num);
    return primeFactors;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def primeDecompose(num):
        """ decompose any positive number into 
                a series of prime factors.
            e.g. 12 = 2 * 2 * 3
        """
    factor = 2
    prime_factors = []
    while num >= factor * factor:
        if num % factor == 0:
            prime_factors.append(factor)
            num = num // factor
        else:
            factor += 1
    prime_factors.append(num)
    return prime_factors
```

</details>
