# 1640. Check Array Formation Through Concatenation

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/check-array-formation-through-concatenation/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 1640 - Check Array Formation Through Concatenation](https://leetcode.com/problems/check-array-formation-through-concatenation/)

## Problem

You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.

### Example 1

```text
Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]
```

### Example 2

```text
Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].
```

### Example 3

```text
Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]
```

## Constraints

- 1 <= pieces.length <= arr.length <= 100
- sum(pieces[i].length) == arr.length
- 1 <= pieces[i].length <= arr.length
- 1 <= arr[i], pieces[i][j] <= 100
- The integers in arr are distinct.
- The integers in pieces are distinct (i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1640. Check Array Formation Through Concatenation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| One by One | C++, Java, Python3 |

## Approach 1: One by One

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        int i = 0;
        while (i < n) {
            // find target piece
            int found = -1;
            for (int j = 0; j < pieces.size(); j++) {
                if (pieces[j][0] == arr[i]) {
                    found = j;
                    break;
                }
            }
            if (found == -1) {
                return false;
            }
            // find target piece
            auto targetPiece = pieces[found];
            for (int x : targetPiece) {
                if (x != arr[i]) {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        int n = arr.length;
        int i = 0;
        while (i < n) {
            // find target piece
            int found = -1;
            for (int j = 0; j < pieces.length; j++) {
                if (pieces[j][0] == arr[i]) {
                    found = j;
                    break;
                }
            }
            if (found == -1) {
                return false;
            }
            // check target piece
            int[] targetPiece = pieces[found];
            for (int x : targetPiece) {
                if (x != arr[i]) {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        n = len(arr)
        i = 0
        while i < n:
            # find target piece
            for p in pieces:
                if p[0] == arr[i]:
                    break
            else:
                return False
            # check target piece
            # python saves the last iterated `p`
            for x in p:
                if x != arr[i]:
                    return False
                i += 1
        return True
```

</details>
