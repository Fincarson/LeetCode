# 3480. Maximize Subarrays After Removing One Conflicting Pair

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/)  
`Array` `Segment Tree` `Enumeration` `Prefix Sum`

**Problem Link:** [LeetCode 3480 - Maximize Subarrays After Removing One Conflicting Pair](https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/)

## Problem

You are given an integer n which represents an array nums containing the numbers from 1 to n in order. Additionally, you are given a 2D array conflictingPairs, where conflictingPairs[i] = [a, b] indicates that a and b form a conflicting pair.

Remove exactly one element from conflictingPairs. Afterward, count the number of non-empty subarrays of nums which do not contain both a and b for any remaining conflicting pair [a, b].

Return the maximum number of subarrays possible after removing exactly one conflicting pair.

### Example 1

### Example 2

## Constraints

- 2 <= n <= 105
- 1 <= conflictingPairs.length <= 2 * n
- conflictingPairs[i].length == 2
- 1 <= conflictingPairs[i][j] <= n
- conflictingPairs[i][0] != conflictingPairs[i][1]

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3480. Maximize Subarrays After Removing One Conflicting Pair

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long maxSubarrays(int n, int** conflictingPairs, int conflictingPairsSize,
                       int* conflictingPairsColSize) {
    int* bMin1 = (int*)malloc((n + 1) * sizeof(int));
    int* bMin2 = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) bMin1[i] = bMin2[i] = INT_MAX;
    for (int i = 0; i < conflictingPairsSize; i++) {
        int a = fmin(conflictingPairs[i][0], conflictingPairs[i][1]);
        int b = fmax(conflictingPairs[i][0], conflictingPairs[i][1]);
        if (bMin1[a] > b) {
            bMin2[a] = bMin1[a];
            bMin1[a] = b;
        } else if (bMin2[a] > b) {
            bMin2[a] = b;
        }
    }
    long long res = 0;
    int ib1 = n, b2 = INT_MAX;
    long long* delCount = (long long*)calloc(n + 1, sizeof(long long));
    for (int i = n; i >= 1; i--) {
        if (bMin1[ib1] > bMin1[i]) {
            b2 = fmin(b2, bMin1[ib1]);
            ib1 = i;
        } else {
            b2 = fmin(b2, bMin1[i]);
        }
        res += fmin(bMin1[ib1], n + 1) - i;
        delCount[ib1] +=
            fmin(fmin(b2, bMin2[ib1]), n + 1) - fmin(bMin1[ib1], n + 1);
    }
    long long max = 0;
    for (int i = 0; i <= n; i++) {
        if (delCount[i] > max) max = delCount[i];
    }
    free(bMin1);
    free(bMin2);
    free(delCount);
    return res + max;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> bMin1(n + 1, INT_MAX), bMin2(n + 1, INT_MAX);
        for (const auto& pair : conflictingPairs) {
            int a = min(pair[0], pair[1]), b = max(pair[0], pair[1]);
            if (bMin1[a] > b) {
                bMin2[a] = bMin1[a];
                bMin1[a] = b;
            } else if (bMin2[a] > b) {
                bMin2[a] = b;
            }
        }
        long long res = 0;
        int ib1 = n, b2 = INT_MAX;
        vector<long long> delCount(n + 1, 0);
        for (int i = n; i >= 1; i--) {
            if (bMin1[ib1] > bMin1[i]) {
                b2 = min(b2, bMin1[ib1]);
                ib1 = i;
            } else {
                b2 = min(b2, bMin1[i]);
            }
            res += min(bMin1[ib1], n + 1) - i;
            delCount[ib1] +=
                min(min(b2, bMin2[ib1]), n + 1) - min(bMin1[ib1], n + 1);
        }
        return res + *max_element(delCount.begin(), delCount.end());
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MaxSubarrays(int n, int[][] conflictingPairs) {
        int[] bMin1 = new int[n + 1];
        int[] bMin2 = new int[n + 1];
        Array.Fill(bMin1, int.MaxValue);
        Array.Fill(bMin2, int.MaxValue);
        foreach (var pair in conflictingPairs) {
            int a = Math.Min(pair[0], pair[1]);
            int b = Math.Max(pair[0], pair[1]);
            if (bMin1[a] > b) {
                bMin2[a] = bMin1[a];
                bMin1[a] = b;
            } else if (bMin2[a] > b) {
                bMin2[a] = b;
            }
        }
        long res = 0;
        int ib1 = n, b2 = int.MaxValue;
        long[] delCount = new long[n + 1];
        for (int i = n; i >= 1; i--) {
            if (bMin1[ib1] > bMin1[i]) {
                b2 = Math.Min(b2, bMin1[ib1]);
                ib1 = i;
            } else {
                b2 = Math.Min(b2, bMin1[i]);
            }
            res += Math.Min(bMin1[ib1], n + 1) - i;
            delCount[ib1] += Math.Min(Math.Min(b2, bMin2[ib1]), n + 1) -
                             Math.Min(bMin1[ib1], n + 1);
        }
        long max = 0;
        foreach (var val in delCount) {
            if (val > max)
                max = val;
        }
        return res + max;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxSubarrays(n int, conflictingPairs [][]int) int64 {
    bMin1 := make([]int, n+1)
    bMin2 := make([]int, n+1)
    for i := 0; i <= n; i++ {
        bMin1[i] = math.MaxInt32
        bMin2[i] = math.MaxInt32
    }
    for _, pair := range conflictingPairs {
        a := min(pair[0], pair[1])
        b := max(pair[0], pair[1])
        if bMin1[a] > b {
            bMin2[a] = bMin1[a]
            bMin1[a] = b
        } else if bMin2[a] > b {
            bMin2[a] = b
        }
    }
    res, ib1, b2 := int64(0), n, math.MaxInt32
    delCount := make([]int64, n+1)
    for i := n; i >= 1; i-- {
        if bMin1[ib1] > bMin1[i] {
            b2 = min(b2, bMin1[ib1])
            ib1 = i
        } else {
            b2 = min(b2, bMin1[i])
        }
        res += int64(min(bMin1[ib1], n+1) - i)
        delCount[ib1] += int64(min(min(b2, bMin2[ib1]), n+1) - min(bMin1[ib1], n+1))
    }
    maxVal := int64(0)
    for _, v := range delCount {
        maxVal = max(maxVal, v)
    }
    return res + maxVal
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maxSubarrays(int n, int[][] conflictingPairs) {
        int[] bMin1 = new int[n + 1];
        int[] bMin2 = new int[n + 1];
        Arrays.fill(bMin1, Integer.MAX_VALUE);
        Arrays.fill(bMin2, Integer.MAX_VALUE);
        for (int[] pair : conflictingPairs) {
            int a = Math.min(pair[0], pair[1]);
            int b = Math.max(pair[0], pair[1]);
            if (bMin1[a] > b) {
                bMin2[a] = bMin1[a];
                bMin1[a] = b;
            } else if (bMin2[a] > b) {
                bMin2[a] = b;
            }
        }
        long res = 0;
        int ib1 = n;
        int b2 = Integer.MAX_VALUE;
        long[] delCount = new long[n + 1];
        for (int i = n; i >= 1; i--) {
            if (bMin1[ib1] > bMin1[i]) {
                b2 = Math.min(b2, bMin1[ib1]);
                ib1 = i;
            } else {
                b2 = Math.min(b2, bMin1[i]);
            }
            res += Math.min(bMin1[ib1], n + 1) - i;
            delCount[ib1] +=
                Math.min(Math.min(b2, bMin2[ib1]), n + 1) -
                Math.min(bMin1[ib1], n + 1);
        }
        long max = 0;
        for (long val : delCount) {
            max = Math.max(max, val);
        }
        return res + max;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSubarrays = function (n, conflictingPairs) {
    const bMin1 = Array(n + 1).fill(Number.MAX_SAFE_INTEGER);
    const bMin2 = Array(n + 1).fill(Number.MAX_SAFE_INTEGER);
    for (const pair of conflictingPairs) {
        const a = Math.min(pair[0], pair[1]),
            b = Math.max(pair[0], pair[1]);
        if (bMin1[a] > b) {
            bMin2[a] = bMin1[a];
            bMin1[a] = b;
        } else if (bMin2[a] > b) {
            bMin2[a] = b;
        }
    }
    let res = 0,
        ib1 = n,
        b2 = Number.MAX_SAFE_INTEGER;
    const delCount = Array(n + 1).fill(0);
    for (let i = n; i >= 1; i--) {
        if (bMin1[ib1] > bMin1[i]) {
            b2 = Math.min(b2, bMin1[ib1]);
            ib1 = i;
        } else {
            b2 = Math.min(b2, bMin1[i]);
        }
        res += Math.min(bMin1[ib1], n + 1) - i;
        delCount[ib1] +=
            Math.min(Math.min(b2, bMin2[ib1]), n + 1) -
            Math.min(bMin1[ib1], n + 1);
    }
    return res + Math.max(...delCount);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSubarrays(self, n: int, conflictingPairs: List[List[int]]) -> int:
        bMin1 = [2**31 - 1] * (n + 1)
        bMin2 = [2**31 - 1] * (n + 1)
        for pair in conflictingPairs:
            a = min(pair[0], pair[1])
            b = max(pair[0], pair[1])
            if bMin1[a] > b:
                bMin2[a] = bMin1[a]
                bMin1[a] = b
            elif bMin2[a] > b:
                bMin2[a] = b
        res = 0
        ib1 = n
        b2 = 0x3FFFFFFF
        delCount = [0] * (n + 1)
        for i in range(n, 0, -1):
            if bMin1[ib1] > bMin1[i]:
                b2 = min(b2, bMin1[ib1])
                ib1 = i
            else:
                b2 = min(b2, bMin1[i])
            res += min(bMin1[ib1], n + 1) - i
            delCount[ib1] += min(min(b2, bMin2[ib1]), n + 1) - min(
                bMin1[ib1], n + 1
            )
        return res + max(delCount)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxSubarrays(n: number, conflictingPairs: number[][]): number {
    const bMin1 = Array(n + 1).fill(Number.MAX_SAFE_INTEGER);
    const bMin2 = Array(n + 1).fill(Number.MAX_SAFE_INTEGER);
    for (const pair of conflictingPairs) {
        const a = Math.min(pair[0], pair[1]),
            b = Math.max(pair[0], pair[1]);
        if (bMin1[a] > b) {
            bMin2[a] = bMin1[a];
            bMin1[a] = b;
        } else if (bMin2[a] > b) {
            bMin2[a] = b;
        }
    }
    let res = 0,
        ib1 = n,
        b2 = Number.MAX_SAFE_INTEGER;
    const delCount = Array(n + 1).fill(0);
    for (let i = n; i >= 1; i--) {
        if (bMin1[ib1] > bMin1[i]) {
            b2 = Math.min(b2, bMin1[ib1]);
            ib1 = i;
        } else {
            b2 = Math.min(b2, bMin1[i]);
        }
        res += Math.min(bMin1[ib1], n + 1) - i;
        delCount[ib1] +=
            Math.min(Math.min(b2, bMin2[ib1]), n + 1) -
            Math.min(bMin1[ib1], n + 1);
    }
    return res + Math.max(...delCount);
}
```

</details>
