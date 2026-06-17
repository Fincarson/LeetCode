# 454. 4Sum II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/4sum-ii/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 454 - 4Sum II](https://leetcode.com/problems/4sum-ii/)

## Problem

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

- 0 <= i, j, k, l < n
- nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

### Example 1

```text
Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
```

### Example 2

```text
Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
```

## Constraints

- n == nums1.length
- n == nums2.length
- n == nums3.length
- n == nums4.length
- 1 <= n <= 200
- -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [4Sum](https://leetcode.com/problems/4sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 454. 4Sum II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashmap | C++, Java, Python3 |
| kSum II | C++, Java, Python3 |

## Approach 1: Hashmap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int cnt = 0;
        unordered_map<int, int> m;
        for (int a : A) {
            for (int b : B) {
                ++m[a + b];
            }
        }
        
        for (int c : C) {
            for (int d : D) {
                auto it = m.find(-(c + d));
                if (it != end(m)) {
                    cnt += it->second;
                }
            }    
        }
        return cnt;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int cnt = 0;
        Map<Integer, Integer> m = new HashMap<>();
        for (int a : A) {
            for (int b : B) {
                m.put(a + b, m.getOrDefault(a + b, 0) + 1);
            }
        }
        for (int c : C) {
            for (int d : D) {
                cnt += m.getOrDefault(-(c + d), 0);
            }
        }
        return cnt;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        cnt = 0
        m = collections.defaultdict(int)
        for a in A:
            for b in B:
                m[a + b] += 1
                
        for c in C:
            for d in D:
                cnt += m[-(c + d)]
                
        return cnt
```

</details>

<br>

## Approach 2: kSum II

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<vector<int>> lsts = {A, B, C, D};
        int k = int(lsts.size());

        auto countSum = [&](int start, int end) {
            map<int, int> cnt({{0, 1}});
            for (int i = start; i < end; i++) {
                map<int, int> temp;
                for (int total : lsts[i]) {
                    for (auto k = cnt.begin(); k != cnt.end(); k++) {
                        temp[total + k->first] += k->second;
                    }
                }
                cnt = temp;
            }
            return cnt;
        };

        map<int, int> left = countSum(0, k / 2);
        map<int, int> right = countSum(k / 2, k);
        int res = 0;
        for (auto k = left.begin(); k != left.end(); k++) {
            res += k->second * right[-k->first];
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.Map;

class Solution {
    private int[][] lsts;

    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        lsts = new int[][] { A, B, C, D };
        int k = lsts.length;
        Map<Integer, Integer> left = sumCount(0, k / 2);
        Map<Integer, Integer> right = sumCount(k / 2, k);
        int res = 0;
        for (int s : left.keySet())
            res += left.get(s) * right.getOrDefault(-s, 0);
        return res;
    }

    private Map<Integer, Integer> sumCount(int start, int end) {
        Map<Integer, Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        for (int i = start; i < end; i++) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int a : lsts[i]) {
                for (int total : cnt.keySet()) {
                    map.put(total + a, map.getOrDefault(total + a, 0) + cnt.get(total));
                }
            }
            cnt = map;
        }
        return cnt;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter


class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        def sum_count(lsts: List[List[int]]) -> Counter:
            res = Counter({0: 1})
            for lst in lsts:
                temp = Counter()
                for a in lst:
                    for total in res:
                        temp[total + a] += res[total]
                res = temp
            return res

        lsts = [A, B, C, D]
        k = len(lsts)
        left, right = sum_count(lsts[:k//2]), sum_count(lsts[k//2:])
        return sum(left[s]*right[-s] for s in left)
```

</details>
