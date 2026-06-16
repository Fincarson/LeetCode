# 3152. Special Array II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/special-array-ii/)  
`Array` `Binary Search` `Prefix Sum`

**Problem Link:** [LeetCode 3152 - Special Array II](https://leetcode.com/problems/special-array-ii/)

## Problem

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that subarray nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105
- 1 <= queries.length <= 105
- queries[i].length == 2
- 0 <= queries[i][0] <= queries[i][1] <= nums.length - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3152. Special Array II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Prefix Sum | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        vector<int> violatingIndices;

        for (int i = 1; i < nums.size(); i++) {
            // same parity, found violating index
            if (nums[i] % 2 == nums[i - 1] % 2) {
                violatingIndices.push_back(i);
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int start = query[0];
            int end = query[1];

            bool foundViolatingIndex =
                binarySearch(start + 1, end, violatingIndices);

            if (foundViolatingIndex) {
                ans[i] = false;
            } else {
                ans[i] = true;
            }
        }

        return ans;
    }

private:
    bool binarySearch(int start, int end, vector<int>& violatingIndices) {
        int left = 0;
        int right = violatingIndices.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int violatingIndex = violatingIndices[mid];

            if (violatingIndex < start) {
                // check right half
                left = mid + 1;
            } else if (violatingIndex > end) {
                // check left half
                right = mid - 1;
            } else {
                // violatingIndex falls in between start and end
                return true;
            }
        }

        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        boolean[] ans = new boolean[queries.length];
        ArrayList<Integer> violatingIndices = new ArrayList<>();

        for (int i = 1; i < nums.length; i++) {
            // same parity, found violating index
            if (nums[i] % 2 == nums[i - 1] % 2) {
                violatingIndices.add(i);
            }
        }

        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            int start = query[0];
            int end = query[1];

            boolean foundViolatingIndex = binarySearch(
                start + 1,
                end,
                violatingIndices
            );

            if (foundViolatingIndex) {
                ans[i] = false;
            } else {
                ans[i] = true;
            }
        }

        return ans;
    }

    private boolean binarySearch(
        int start,
        int end,
        ArrayList<Integer> violatingIndices
    ) {
        int left = 0;
        int right = violatingIndices.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int violatingIndex = violatingIndices.get(mid);

            if (violatingIndex < start) {
                // check right half
                left = mid + 1;
            } else if (violatingIndex > end) {
                // check left half
                right = mid - 1;
            } else {
                // violatingIndex falls in between start and end
                return true;
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isArraySpecial(
        self, nums: List[int], queries: List[Tuple[int, int]]
    ) -> List[bool]:
        ans = [False] * len(queries)
        violating_indices = []

        for i in range(1, len(nums)):
            # same parity, found violating index
            if nums[i] % 2 == nums[i - 1] % 2:
                violating_indices.append(i)

        for i in range(len(queries)):
            query = queries[i]
            start = query[0]
            end = query[1]

            found_violating_index = self.binarySearch(
                start + 1, end, violating_indices
            )

            if found_violating_index:
                ans[i] = False
            else:
                ans[i] = True

        return ans

    def binarySearch(
        self, start: int, end: int, violating_indices: List[int]
    ) -> bool:
        left = 0
        right = len(violating_indices) - 1
        while left <= right:
            mid = left + (right - left) // 2
            violating_index = violating_indices[mid]

            if violating_index < start:
                # check right half
                left = mid + 1
            elif violating_index > end:
                # check left half
                right = mid - 1
            else:
                # violatingIndex falls in between start and end
                return True

        return False
```

</details>

<br>

## Approach 2: Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        vector<int> prefix(nums.size(), 0);
        prefix[0] = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                // new violative index found
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int start = query[0];
            int end = query[1];

            ans[i] = prefix[end] - prefix[start] == 0;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        boolean[] ans = new boolean[queries.length];
        int[] prefix = new int[nums.length];
        prefix[0] = 0;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                // new violative index found
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }

        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            int start = query[0];
            int end = query[1];

            ans[i] = prefix[end] - prefix[start] == 0;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isArraySpecial(
        self, nums: List[int], queries: List[List[int]]
    ) -> List[bool]:
        ans = [False] * len(queries)
        prefix = [0] * len(nums)
        prefix[0] = 0

        for i in range(1, len(nums)):
            if nums[i] % 2 == nums[i - 1] % 2:
                # new violative index found
                prefix[i] = prefix[i - 1] + 1
            else:
                prefix[i] = prefix[i - 1]

        for i in range(len(queries)):
            query = queries[i]
            start = query[0]
            end = query[1]

            ans[i] = prefix[end] - prefix[start] == 0

        return ans
```

</details>

<br>

## Approach 3: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> maxReach(n);

        // Step 1: Compute the maximum reachable index for each starting index
        // from last to first
        maxReach[n - 1] = n - 1; // The last index can only reach itself
        for (int i = n - 2; i >= 0; i--) {
            // Check if adjacent elements have different parity
            if ((nums[i] % 2) != (nums[i + 1] % 2)) {
                maxReach[i] = maxReach[i + 1]; // Extend the reach
            } else {
                maxReach[i] = i; // Can only reach itself
            }
        }

        vector<bool> ans(queries.size());

        // Step 2: Answer each query based on precomputed 'maxReach'
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            // Check if the query range [start, end] lies within the max
            // reachable range
            ans[i] = end <= maxReach[start];
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] maxReach = new int[n];

        // Step 1: Compute the maximum reachable index for each starting index from last to first
        maxReach[n - 1] = n - 1; // The last index can only reach itself
        for (int i = n - 2; i >= 0; i--) {
            // Check if adjacent elements have different parity
            if ((nums[i] % 2) != (nums[i + 1] % 2)) {
                maxReach[i] = maxReach[i + 1]; // Extend the reach
            } else {
                maxReach[i] = i; // Can only reach itself
            }
        }

        boolean[] ans = new boolean[queries.length];

        // Step 2: Answer each query based on precomputed 'maxReach'
        for (int i = 0; i < queries.length; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            // Check if the query range [start, end] lies within the max reachable range
            ans[i] = end <= maxReach[start];
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isArraySpecial(
        self, nums: List[int], queries: List[List[int]]
    ) -> List[bool]:
        n = len(nums)
        max_reach = [0] * n

        # Step 1: Compute the maximum reachable index for each starting index from last to first
        max_reach[-1] = n - 1  # The last index can only reach itself
        for i in range(n - 2, -1, -1):
            # Check if adjacent elements have different parity
            if nums[i] % 2 != nums[i + 1] % 2:
                max_reach[i] = max_reach[i + 1]  # Extend the reach
            else:
                max_reach[i] = i  # Can only reach itself

        ans = [False] * len(queries)

        # Step 2: Answer each query based on precomputed 'max_reach'
        for i, query in enumerate(queries):
            start, end = query
            # Check if the query range [start, end] lies within the max reachable range
            ans[i] = end <= max_reach[start]

        return ans
```

</details>
