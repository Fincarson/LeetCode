# 446. Arithmetic Slices II - Subsequence

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 446 - Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/)

## Problem

Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

- For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
- For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.

A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

- For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].

The test cases are generated so that the answer fits in 32-bit integer.

### Example 1

```text
Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
```

### Example 2

```text
Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.
```

## Constraints

- 1  <= nums.length <= 1000
- -231 <= nums[i] <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Destroy Sequential Targets](https://leetcode.com/problems/destroy-sequential-targets/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Palindromic Subsequences](https://leetcode.com/problems/count-palindromic-subsequences/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 446. Arithmetic Slices II - Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | C++, Java |
| Approach #2 Dynamic Programming [Accepted] | C++, Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
#define LL long long
class Solution {
public:
    int n;
    int ans;
    void dfs(int dep, vector<int>& A, vector<LL> cur) {
        if (dep == n) {
            if (cur.size() < 3) {
                return;
            }
            for (int i = 1; i < cur.size(); i++) {
                if (cur[i] - cur[i - 1] != cur[1] - cur[0]) {
                    return;
                }
            }
            ans ++;
            return;
        }
        dfs(dep + 1, A, cur);
        cur.push_back(A[dep]);
        dfs(dep + 1, A, cur);
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        n = A.size();
        ans = 0;
        vector<LL> cur;
        dfs(0, A, cur);
        return (int)ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java

class Solution {
    private int n;
    private int ans;
    private void dfs(int dep, int[] A, List<Long> cur) {
        if (dep == n) {
            if (cur.size() < 3) {
                return;
            }
            long diff = cur.get(1) - cur.get(0);
            for (int i = 1; i < cur.size(); i++) {                
                if (cur.get(i) - cur.get(i - 1) != diff) {
                    return;
                }
            }
            ans ++;
            return;
        }
        dfs(dep + 1, A, cur);
        cur.add((long)A[dep]);
        dfs(dep + 1, A, cur);
        cur.remove((long)A[dep]);
    }
    public int numberOfArithmeticSlices(int[] A) {
        n = A.length;
        ans = 0;
        List<Long> cur = new ArrayList<Long>();
        dfs(0, A, cur);
        return (int)ans;        
    }
}
```

</details>

<br>

## Approach #2 Dynamic Programming [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp

#define LL long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        LL ans = 0;
        vector<map<LL, int>> cnt(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                LL delta = (LL)A[i] - (LL)A[j];
                int sum = 0;
                if (cnt[j].find(delta) != cnt[j].end()) {
                    sum = cnt[j][delta];
                }
                cnt[i][delta] += sum + 1;
                ans += sum;
            }
        }

        return (int)ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java

class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int n = A.length;
        long ans = 0;
        Map<Integer, Integer>[] cnt = new Map[n];
        for (int i = 0; i < n; i++) {
            cnt[i] = new HashMap<>(i);
            for (int j = 0; j < i; j++) {
                long delta = (long)A[i] - (long)A[j];
                if (delta < Integer.MIN_VALUE || delta > Integer.MAX_VALUE) {
                    continue;
                }
                int diff = (int)delta;
                int sum = cnt[j].getOrDefault(diff, 0);
                int origin = cnt[i].getOrDefault(diff, 0);
                cnt[i].put(diff, origin + sum + 1);
                ans += sum;
            }
        }
        return (int)ans;        
    }
}
```

</details>
