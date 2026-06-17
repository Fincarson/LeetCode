# 3623. Count Number of Trapezoids I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-number-of-trapezoids-i/)  
`Array` `Hash Table` `Math` `Geometry`

**Problem Link:** [LeetCode 3623 - Count Number of Trapezoids I](https://leetcode.com/problems/count-number-of-trapezoids-i/)

## Problem

You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the  number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 109 + 7.

### Example 1

### Example 2

## Constraints

- 4 <= points.length <= 105
- Ã¢â‚¬â€œ108 <= xi, yi <= 108
- All points are pairwise distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3623. Count Number of Trapezoids I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Table + Geometry Mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash Table + Geometry Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int countTrapezoids(int** points, int pointsSize, int* pointsColSize) {
    HashItem* pointNum = NULL;
    const int mod = 1e9 + 7;
    long long ans = 0, sum = 0;
    for (int i = 0; i < pointsSize; i++) {
        hashSetItem(&pointNum, points[i][1],
                    hashGetItem(&pointNum, points[i][1], 0) + 1);
    }
    for (HashItem* pEntry = pointNum; pEntry; pEntry = pEntry->hh.next) {
        int pNum = pEntry->val;
        long long edge = (long long)pNum * (pNum - 1) / 2;
        ans += edge * sum;
        sum += edge;
    }
    hashFree(&pointNum);
    return ans % mod;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> pointNum;
        const int mod = 1e9 + 7;
        long long ans = 0, sum = 0;
        for (auto& point : points) {
            pointNum[point[1]]++;
        }
        for (auto& [_, pNum] : pointNum) {
            long long edge = (long long)pNum * (pNum - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }
        return ans % mod;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CountTrapezoids(int[][] points) {
        Dictionary<int, int> pointNum = new Dictionary<int, int>();
        const int mod = 1000000007;
        long ans = 0, sum = 0;

        foreach (int[] point in points) {
            int y = point[1];
            if (pointNum.ContainsKey(y)) {
                pointNum[y]++;
            } else {
                pointNum[y] = 1;
            }
        }

        foreach (int pNum in pointNum.Values) {
            long edge = (long)pNum * (pNum - 1) / 2;
            ans = (ans + edge * sum) % mod;
            sum = (sum + edge) % mod;
        }

        return (int)ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countTrapezoids(points [][]int) int {
	pointNum := make(map[int]int)
	mod := 1000000007
	ans, sum := 0, 0

	for _, point := range points {
		y := point[1]
		pointNum[y]++
	}

	for _, pNum := range pointNum {
		edge := pNum * (pNum - 1) / 2
		ans = (ans + edge*sum) % mod
		sum = (sum + edge) % mod
	}

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countTrapezoids(int[][] points) {
        Map<Integer, Integer> pointNum = new HashMap<>();
        final int mod = 1000000007;
        long ans = 0;
        long sum = 0;
        for (int[] point : points) {
            pointNum.put(point[1], pointNum.getOrDefault(point[1], 0) + 1);
        }
        for (int pNum : pointNum.values()) {
            long edge = ((long) pNum * (pNum - 1)) / 2;
            ans = (ans + edge * sum) % mod;
            sum = (sum + edge) % mod;
        }
        return (int) ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countTrapezoids = function (points) {
    const pointNum = new Map();
    const mod = 1000000007n;
    let ans = 0n,
        sum = 0n;

    for (const point of points) {
        const y = point[1];
        pointNum.set(y, (pointNum.get(y) || 0) + 1);
    }

    for (const pNum of pointNum.values()) {
        const edge = (BigInt(pNum) * BigInt(pNum - 1)) / 2n;
        ans = (ans + edge * sum) % mod;
        sum = (sum + edge) % mod;
    }

    return Number(ans);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        point_num = defaultdict(int)
        mod = 10**9 + 7
        ans, total_sum = 0, 0
        for point in points:
            point_num[point[1]] += 1
        for p_num in point_num.values():
            edge = p_num * (p_num - 1) // 2
            ans = (ans + edge * total_sum) % mod
            total_sum = (total_sum + edge) % mod
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countTrapezoids(points: number[][]): number {
    const pointNum: Map<number, number> = new Map();
    const mod: bigint = 1000000007n;
    let ans: bigint = 0n,
        sum: bigint = 0n;

    for (const point of points) {
        const y: number = point[1];
        pointNum.set(y, (pointNum.get(y) || 0) + 1);
    }

    for (const pNum of pointNum.values()) {
        const edge: bigint = (BigInt(pNum) * BigInt(pNum - 1)) / 2n;
        ans = (ans + edge * sum) % mod;
        sum = (sum + edge) % mod;
    }

    return Number(ans);
}
```

</details>
