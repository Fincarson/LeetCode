# 368. Largest Divisible Subset

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/largest-divisible-subset/)  
`Array` `Math` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 368 - Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/)

## Problem

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

- answer[i] % answer[j] == 0, or
- answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.

### Example 1

```text
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
```

### Example 2

```text
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 2 * 109
- All the integers in nums are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 368. Largest Divisible Subset

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | Java, Python3 |
| Dynamic Programming with Less Space | Java, Python3 |
| Recursion with Memoization | Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> largestDivisibleSubset(int[] nums) {
        // Test case with empty set.
        int n = nums.length;
        if (n == 0) return new ArrayList();

        // Container to keep the largest divisible subset
        //   that ends with each of the nums.
        List<ArrayList> EDS = new ArrayList();
        for (int num : nums) EDS.add(new ArrayList());

        /* Sort the original list in ascending order. */
        Arrays.sort(nums);

        /* Calculate all the values of EDS(X_i) */
        for (int i = 0; i < n; ++i) {
            List<Integer> maxSubset = new ArrayList();

            // Find the largest divisible subset of previous elements.
            for (int k = 0; k < i; ++k) if (
                nums[i] % nums[k] == 0 && maxSubset.size() < EDS.get(k).size()
            ) maxSubset = EDS.get(k);

            // Extend the found subset with the element itself.
            EDS.get(i).addAll(maxSubset);
            EDS.get(i).add(nums[i]);
        }
        /* Find the largest of EDS values  */
        List<Integer> ret = new ArrayList();
        for (int i = 0; i < n; ++i) if (ret.size() < EDS.get(i).size()) ret =
            EDS.get(i);
        return ret;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # The container that holds all intermediate solutions.
        # key: the largest element in a valid subset.
        subsets = {-1: set()}

        for num in sorted(nums):
            subsets[num] = max(
                [subsets[k] for k in subsets if num % k == 0], key=len
            ) | {num}

        return list(max(subsets.values(), key=len))
```

</details>

<br>

## Approach 2: Dynamic Programming with Less Space

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> largestDivisibleSubset(int[] nums) {
        // Test case with empty set.
        int n = nums.length;
        if (n == 0) return new ArrayList();

        // Container to keep the size of the largest divisible subset
        //   that ends with each of the nums.
        Integer[] dp = new Integer[n];

        /* Sort the original list in ascending order. */
        Arrays.sort(nums);

        Integer maxSubsetSize = -1, maxSubsetIndex = -1;

        /* Calculate the rest of EDS(X_i) */
        for (int i = 0; i < n; ++i) {
            Integer subsetSize = 0;

            // Find the size of the largest divisible subset.
            for (int k = 0; k < i; ++k) if (
                nums[i] % nums[k] == 0 && subsetSize < dp[k]
            ) subsetSize = dp[k];

            // Extend the found subset with the element itself.
            dp[i] = subsetSize + 1;

            // We reuse this loop to obtain the largest subset size
            //   in order to prepare for the reconstruction of subset.
            if (maxSubsetSize < dp[i]) {
                maxSubsetSize = dp[i];
                maxSubsetIndex = i;
            }
        }

        /* Reconstruct the largest divisible subset  */
        LinkedList<Integer> subset = new LinkedList();
        Integer currSize = maxSubsetSize;
        Integer currTail = nums[maxSubsetIndex];
        for (int i = maxSubsetIndex; i >= 0; --i) {
            if (currSize == 0) break;

            if (currTail % nums[i] == 0 && currSize == dp[i]) {
                subset.addFirst(nums[i]);
                currTail = nums[i];
                currSize -= 1;
            }
        }

        return subset;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) == 0:
            return []

        # important step !
        nums.sort()

        # The container that keep the size of the largest divisible subset that ends with X_i
        # dp[i] corresponds to len(EDS(X_i))
        dp = [0] * (len(nums))

        """ Build the dynamic programming matrix/vector """
        for i, num in enumerate(nums):
            maxSubsetSize = 0
            for k in range(0, i):
                if nums[i] % nums[k] == 0:
                    maxSubsetSize = max(maxSubsetSize, dp[k])

            maxSubsetSize += 1
            dp[i] = maxSubsetSize

        """ Find both the size of largest divisible set and its index """
        maxSize, maxSizeIndex = max([(v, i) for i, v in enumerate(dp)])
        ret = []

        """ Reconstruct the largest divisible subset """
        # currSize: the size of the current subset
        # currTail: the last element in the current subset
        currSize, currTail = maxSize, nums[maxSizeIndex]
        for i in range(maxSizeIndex, -1, -1):
            if currSize == dp[i] and currTail % nums[i] == 0:
                ret.append(nums[i])
                currSize -= 1
                currTail = nums[i]

        return reversed(ret)
```

</details>

<br>

## Approach 3: Recursion with Memoization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    HashMap<Integer, List<Integer>> _eds = new HashMap<
        Integer,
        List<Integer>
    >();
    int[] _nums = {};

    private List<Integer> EDS(Integer i) {
        // memoization
        if (this._eds.containsKey(i)) return this._eds.get(i);

        List<Integer> maxSubset = new ArrayList();
        // Find the largest divisible subset of previous elements.
        for (int k = 0; k < i; ++k) {
            if (this._nums[i] % this._nums[k] == 0) {
                List<Integer> subset = EDS(k);
                if (maxSubset.size() < subset.size()) maxSubset = subset;
            }
        }
        // Extend the found subset with the element itself.
        List<Integer> newEntry = new ArrayList();
        newEntry.addAll(maxSubset);
        newEntry.add(this._nums[i]);

        // update the cached values
        this._eds.put(i, newEntry);
        return newEntry;
    }

    public List<Integer> largestDivisibleSubset(int[] nums) {
        // Test case with empty set.
        int n = nums.length;
        if (n == 0) return new ArrayList();

        // Container to keep the largest divisible subset
        //   that ends with each of the nums
        // key: the index of the element
        this._eds = new HashMap<Integer, List<Integer>>();

        /* Sort the original list in ascending order. */
        Arrays.sort(nums);
        this._nums = nums;

        List<Integer> maxSubset = new ArrayList();
        /* Calculate the values of all EDS(X_i), 
       while keeping track of the largest one as the result value. */
        for (int i = 0; i < n; ++i) {
            List<Integer> subset = EDS(i);
            if (maxSubset.size() < subset.size()) maxSubset = subset;
        }

        // return the largest one
        return maxSubset;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:

        def EDS(i):
            """recursion with memoization"""
            if i in memo:
                return memo[i]

            tail = nums[i]
            maxSubset = []
            # The value of EDS(i) depends on it previous elements
            for p in range(0, i):
                if tail % nums[p] == 0:
                    subset = EDS(p)
                    if len(maxSubset) < len(subset):
                        maxSubset = subset

            # extend the found max subset with the current tail.
            maxSubset = maxSubset.copy()
            maxSubset.append(tail)

            # memorize the intermediate solutions for reuse.
            memo[i] = maxSubset
            return maxSubset

        # test case with empty set
        if len(nums) == 0:
            return []

        nums.sort()
        memo = {}

        # Find the largest divisible subset
        return max([EDS(i) for i in range(len(nums))], key=len)
```

</details>
