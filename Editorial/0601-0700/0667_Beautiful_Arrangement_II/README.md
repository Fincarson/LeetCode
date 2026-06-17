# 667. Beautiful Arrangement II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/beautiful-arrangement-ii/)  
`Array` `Math`

**Problem Link:** [LeetCode 667 - Beautiful Arrangement II](https://leetcode.com/problems/beautiful-arrangement-ii/)

## Problem

Given two integers n and k, construct a list answer that contains n different positive integers ranging from 1 to n and obeys the following requirement:

- Suppose this list is answer = [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

Return the list answer. If there multiple valid answers, return any of them.

### Example 1

```text
Input: n = 3, k = 1
Output: [1,2,3]
Explanation: The [1,2,3] has three different positive integers ranging from 1 to 3, and the [1,1] has exactly 1 distinct integer: 1
```

### Example 2

```text
Input: n = 3, k = 2
Output: [1,3,2]
Explanation: The [1,3,2] has three different positive integers ranging from 1 to 3, and the [2,1] has exactly 2 distinct integers: 1 and 2.
```

## Constraints

- 1 <= k < n <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Beautiful Arrangement](https://leetcode.com/problems/beautiful-arrangement/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 667. Beautiful Arrangement II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force [Time Limit Exceeded] | C++, Java, Python3 |
| Approach #2: Construction [Accepted] | C++, Java, Python3 |

## Approach #1: Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> permutations(vector<int> nums) {
        vector<vector<int>> ans;
        permute(ans, nums, 0);
        return ans;
    }

    void permute(vector<vector<int>>& ans, vector<int>& nums, int start) {
        if (start >= nums.size()) {
            ans.push_back(nums);
        } else {
            for (int i = start; i < nums.size(); i++) {
                swap(nums[start], nums[i]);
                permute(ans, nums, start + 1);
                swap(nums[start], nums[i]);
            }
        }
    }

    int numUniqueDiffs(vector<int> arr) {
        vector<bool> seen(arr.size());
        int ans = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            int delta = abs(arr[i] - arr[i + 1]);
            if (!seen[delta]) {
                ans++;
                seen[delta] = true;
            }
        }
        return ans;
    }

    vector<int> constructArray(int n, int k) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        for (auto& cand : permutations(nums)) {
            if (numUniqueDiffs(cand) == k) {
                return cand;
            }
        }
        return vector<int>();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private ArrayList<ArrayList<Integer>> permutations(int[] nums) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        permute(ans, nums, 0);
        return ans;
    }

    private void permute(
        ArrayList<ArrayList<Integer>> ans,
        int[] nums,
        int start
    ) {
        if (start >= nums.length) {
            ArrayList<Integer> cur = new ArrayList<Integer>();
            for (int x : nums) cur.add(x);
            ans.add(cur);
        } else {
            for (int i = start; i < nums.length; i++) {
                swap(nums, start, i);
                permute(ans, nums, start + 1);
                swap(nums, start, i);
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private int numUniqueDiffs(ArrayList<Integer> arr) {
        boolean[] seen = new boolean[arr.size()];
        int ans = 0;

        for (int i = 0; i < arr.size() - 1; i++) {
            int delta = Math.abs(arr.get(i) - arr.get(i + 1));
            if (!seen[delta]) {
                ans++;
                seen[delta] = true;
            }
        }
        return ans;
    }

    public int[] constructArray(int n, int k) {
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        for (ArrayList<Integer> cand : permutations(nums)) {
            if (numUniqueDiffs(cand) == k) {
                int[] ans = new int[n];
                int i = 0;
                for (int x : cand) ans[i++] = x;
                return ans;
            }
        }
        return null;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def permutations(self, nums):
        ans = []
        self.permute(ans, nums, 0)
        return ans

    def permute(self, ans, nums, start):
        if start >= len(nums):
            ans.append(nums[:])
        else:
            for i in range(start, len(nums)):
                nums[start], nums[i] = nums[i], nums[start]
                self.permute(ans, nums, start + 1)
                nums[start], nums[i] = nums[i], nums[start]

    def numUniqueDiffs(self, arr):
        seen = [False] * len(arr)
        ans = 0
        for i in range(len(arr) - 1):
            delta = abs(arr[i] - arr[i + 1])
            if not seen[delta]:
                ans += 1
                seen[delta] = True
        return ans

    def constructArray(self, n, k):
        nums = [i + 1 for i in range(n)]
        for cand in self.permutations(nums):
            if self.numUniqueDiffs(cand) == k:
                return cand
        return []
```

</details>

<br>

## Approach #2: Construction [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n, 0);
        int c = 0;
        for (int v = 1; v < n - k; v++) {
            ans[c++] = v;
        }
        for (int i = 0; i <= k; i++) {
            ans[c++] = (i % 2 == 0) ? (n - k + i / 2) : (n - i / 2);
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

    public int[] constructArray(int n, int k) {
        int[] ans = new int[n];
        int c = 0;
        for (int v = 1; v < n - k; v++) {
            ans[c++] = v;
        }
        for (int i = 0; i <= k; i++) {
            ans[c++] = (i % 2 == 0) ? (n - k + i / 2) : (n - i / 2);
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
    def constructArray(self, n: int, k: int) -> List[int]:
        ans = [0] * n
        c = 0
        for v in range(1, n - k):
            ans[c] = v
            c += 1
        for i in range(k + 1):
            ans[c] = n - k + i // 2 if i % 2 == 0 else n - i // 2
            c += 1
        return ans
```

</details>
