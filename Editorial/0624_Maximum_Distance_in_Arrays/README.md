# 624. Maximum Distance in Arrays

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-distance-in-arrays/)  
`Array` `Greedy`

**Problem Link:** [LeetCode 624 - Maximum Distance in Arrays](https://leetcode.com/problems/maximum-distance-in-arrays/)

## Problem

You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

### Example 1

```text
Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
```

### Example 2

```text
Input: arrays = [[1],[1]]
Output: 0
```

## Constraints

- m == arrays.length
- 2 <= m <= 105
- 1 <= arrays[i].length <= 500
- -104 <= arrays[i][j] <= 104
- arrays[i] is sorted in ascending order.
- There will be at most 105 integers in all the arrays.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 624. Maximum Distance in Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Better Brute Force [Time Limit Exceeded] | Java |
| Approach #3 Single Scan [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int res = 0;
        int n = arrays.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < arrays.get(i).size(); j++) {
                for (int k = i + 1; k < n; k++) {
                    for (int l = 0; l < arrays.get(k).size(); l++) {
                        res = Math.max(res, Math.abs(arrays.get(i).get(j) - arrays.get(k).get(l)));
                    }
                }
            }
        }
        return res;
    }
}
```

</details>

<br>

## Approach #2 Better Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        List<Integer> array1, array2;
        int res = 0;
        int n = arrays.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                array1 = arrays.get(i);
                array2 = arrays.get(j);
                res = Math.max(res, Math.abs(array1.get(0) - array2.get(array2.size() - 1)));
                res = Math.max(res, Math.abs(array2.get(0) - array1.get(array1.size() - 1)));
            }
        }
        return res;
    }
}
```

</details>

<br>

## Approach #3 Single Scan [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int res = 0;
        int n = arrays.get(0).size();
        int min_val = arrays.get(0).get(0);
        int max_val = arrays.get(0).get(arrays.get(0).size() - 1);
        for (int i = 1; i < arrays.size(); i++) {
            n = arrays.get(i).size();
            res = Math.max(res, Math.max(Math.abs(arrays.get(i).get(n - 1) - min_val), 
                                         Math.abs(max_val - arrays.get(i).get(0))));
            min_val = Math.min(min_val, arrays.get(i).get(0));
            max_val = Math.max(max_val, arrays.get(i).get(n - 1));
        }
        return res;
    }
}
```

</details>
