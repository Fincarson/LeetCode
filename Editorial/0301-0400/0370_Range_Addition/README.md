# 370. Range Addition

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/range-addition/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 370 - Range Addition](https://leetcode.com/problems/range-addition/)

## Problem

You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

You have an array arr of length length with all zeros, and you have some operation to apply on arr. In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

Return arr after applying all the updates.

### Example 1

```text
Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]
```

### Example 2

```text
Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
Output: [0,-4,2,2,2,4,4,-4,-4,-4]
```

## Constraints

- 1 <= length <= 105
- 0 <= updates.length <= 104
- 0 <= startIdxi <= endIdxi < length
- -1000 <= inci <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Range Addition II](https://leetcode.com/problems/range-addition-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Positions on Street With Required Brightness](https://leetcode.com/problems/count-positions-on-street-with-required-brightness/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Shifting Letters II](https://leetcode.com/problems/shifting-letters-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 370. Range Addition

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| NaÃƒÂ¯ve Approach | C++ |
| Range Caching | C++ |

## Approach 1: NaÃƒÂ¯ve Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
vector<int> getModifiedArray(int length, vector<vector<int> > updates)
{
    vector<int> result(length, 0);

    for (auto& tuple : updates) {
        int start = tuple[0], end = tuple[1], val = tuple[2];

        for (int i = start; i <= end; i++) {
            result[i] += val;
        }
    }

    return result;
}
```

</details>

<br>

## Approach 2: Range Caching

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
vector<int> getModifiedArray(int length, vector<vector<int> > updates)
{
    vector<int> result(length, 0);

    for (auto& tuple : updates) {
        int start = tuple[0], end = tuple[1], val = tuple[2];

        result[start] += val;
        if (end < length - 1)
            result[end + 1] -= val;
    }

    // partial_sum applies the following operation (by default) for the parameters {x[0], x[n], y[0]}:
    // y[0] = x[0]
    // y[1] = y[0] + x[1]
    // y[2] = y[1] + x[2]
    // ...  ...  ...
    // y[n] = y[n-1] + x[n]

    partial_sum(result.begin(), result.end(), result.begin());

    return result;
}
```

</details>
