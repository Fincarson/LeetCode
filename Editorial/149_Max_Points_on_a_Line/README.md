# 149. Max Points on a Line

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/max-points-on-a-line/)  
`Array` `Hash Table` `Math` `Geometry`

**Problem Link:** [LeetCode 149 - Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)

## Problem

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

### Example 1

```text
Input: points = [[1,1],[2,2],[3,3]]
Output: 3
```

### Example 2

```text
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
```

## Constraints

- 1 <= points.length <= 300
- points[i].length == 2
- -104 <= xi, yi <= 104
- All the points are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Line Reflection](https://leetcode.com/problems/line-reflection/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Number of Lines to Cover Points](https://leetcode.com/problems/minimum-number-of-lines-to-cover-points/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Lines to Represent a Line Chart](https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Special Subsequences](https://leetcode.com/problems/count-special-subsequences/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 149. Max Points on a Line

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Solution

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct hash_map {
    double key;
    int val;
    UT_hash_handle hh;
};
int maxPoints(int **points, int pointsSize, int *pointsColSize) {
    if (pointsSize == 1) {
        return 1;
    }
    int result = 2;
    for (int i = 0; i < pointsSize; i++) {
        struct hash_map *cnt = NULL, *tmp;
        for (int j = 0; j < pointsSize; j++) {
            if (j != i) {
                double key = atan2((double)(points[j][1] - points[i][1]),
                                   (double)(points[j][0] - points[i][0]));
                HASH_FIND(hh, cnt, &key, sizeof(double), tmp);
                if (tmp == NULL) {
                    tmp = (struct hash_map *)malloc(sizeof(struct hash_map));
                    tmp->key = key;
                    tmp->val = 1;
                    HASH_ADD(hh, cnt, key, sizeof(double), tmp);
                } else {
                    tmp->val++;
                }
            }
        }
        struct hash_map *s;
        int maxCnt = 0;
        for (s = cnt; s != NULL; s = s->hh.next) {
            if (s->val > maxCnt) {
                maxCnt = s->val;
            }
        }
        result = result > maxCnt + 1 ? result : maxCnt + 1;
        HASH_CLEAR(hh, cnt);
    }
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) {
            return 1;
        }
        int result = 2;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> cnt;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    cnt[atan2(points[j][1] - points[i][1],
                              points[j][0] - points[i][0])]++;
                }
            }
            for (auto [h, count] : cnt) {
                result = max(result, count + 1);
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxPoints(int[][] points) {
        int n = points.Length;
        if (n == 1) {
            return 1;
        }

        int result = 2;
        for (int i = 0; i < n; i++) {
            Dictionary<double, int> cnt = new Dictionary<double, int>();
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    double key = Math.Atan2(points[j][1] - points[i][1],
                                            points[j][0] - points[i][0]);
                    if (cnt.ContainsKey(key)) {
                        cnt[key]++;
                    } else {
                        cnt[key] = 1;
                    }
                }
            }

            result = Math.Max(result, cnt.Values.Max() + 1);
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxPoints(points [][]int) int {
    n := len(points)
    if n == 1 {
        return 1
    }
    result := 2
    for i := 0; i < n; i++ {
        cnt := make(map[float64]int)
        for j := 0; j < n; j++ {
            if j != i {
                key := math.Atan2(
                    float64(points[j][1]-points[i][1]),
                    float64(points[j][0]-points[i][0]),
                )
                cnt[key]++
            }
        }
        maxCnt := 0
        for _, v := range cnt {
            if v > maxCnt {
                maxCnt = v
            }
        }
        result = max(result, maxCnt+1)
    }
    return result
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n == 1) {
            return 1;
        }
        int result = 2;
        for (int i = 0; i < n; i++) {
            Map<Double, Integer> cnt = new HashMap<>();
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    cnt.merge(
                        Math.atan2(
                            points[j][1] - points[i][1],
                            points[j][0] - points[i][0]
                        ),
                        1,
                        Integer::sum
                    );
                }
            }
            result = Math.max(result, Collections.max(cnt.values()) + 1);
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxPoints = function (points) {
    let n = points.length;
    if (n == 1) {
        return 1;
    }
    let result = 2;
    for (let i = 0; i < n; i++) {
        let cnt = {};
        for (let j = 0; j < n; j++) {
            if (j != i) {
                let key = Math.atan2(
                    points[j][1] - points[i][1],
                    points[j][0] - points[i][0],
                );
                cnt[key] = cnt[key] ? cnt[key] + 1 : 1;
            }
        }
        result = Math.max(result, Math.max(...Object.values(cnt)) + 1);
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n == 1:
            return 1
        result = 2
        for i in range(n):
            cnt = collections.defaultdict(int)
            for j in range(n):
                if j != i:
                    cnt[
                        math.atan2(
                            points[j][1] - points[i][1],
                            points[j][0] - points[i][0],
                        )
                    ] += 1
            result = max(result, max(cnt.values()) + 1)
        return result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxPoints(points: number[][]): number {
    let n = points.length;
    if (n == 1) {
        return 1;
    }
    let result = 2;
    for (let i = 0; i < n; i++) {
        let cnt: { [key: number]: number } = {};
        for (let j = 0; j < n; j++) {
            if (j != i) {
                let key = Math.atan2(
                    points[j][1] - points[i][1],
                    points[j][0] - points[i][0],
                );
                cnt[key] = cnt[key] ? cnt[key] + 1 : 1;
            }
        }
        result = Math.max(result, Math.max(...Object.values<number>(cnt)) + 1);
    }
    return result;
}
```

</details>
