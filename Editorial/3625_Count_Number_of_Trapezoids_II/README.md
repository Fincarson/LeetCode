# 3625. Count Number of Trapezoids II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/count-number-of-trapezoids-ii/)  
`Array` `Hash Table` `Math` `Geometry`

**Problem Link:** [LeetCode 3625 - Count Number of Trapezoids II](https://leetcode.com/problems/count-number-of-trapezoids-ii/)

## Problem

You are given a 2D integer array points where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

Return the number of unique trapezoids that can be formed by choosing any four distinct points from points.

A trapezoid is a convex quadrilateral with at least one pair of parallel sides. Two lines are parallel if and only if they have the same slope.

### Example 1

### Example 2

## Constraints

- 4 <= points.length <= 500
- –1000 <= xi, yi <= 1000
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

# Editorial - 3625. Count Number of Trapezoids II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Table + Geometry Mathematics | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash Table + Geometry Mathematics

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int inf = 1e9 + 7;
        unordered_map<float, vector<float>> slopeToIntercept;
        unordered_map<int, vector<float>> midToSlope;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x1 - x2;
                int dy = y1 - y2;
                float k, b;
                if (x2 == x1) {
                    k = inf;
                    b = x1;
                } else {
                    k = (float)(y2 - y1) / (x2 - x1);
                    b = (float)(y1 * dx - x1 * dy) / dx;
                }
                int mid = (x1 + x2) * 10000 + (y1 + y2);
                slopeToIntercept[k].push_back(b);
                midToSlope[mid].push_back(k);
            }
        }
        for (auto& [_, sti] : slopeToIntercept) {
            if (sti.size() == 1) {
                continue;
            }
            map<float, int> cnt;
            for (float b : sti) {
                cnt[b]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                ans += sum * count;
                sum += count;
            }
        }
        for (auto& [_, mts] : midToSlope) {
            if (mts.size() == 1) {
                continue;
            }
            map<float, int> cnt;
            for (float k : mts) {
                cnt[k]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                ans -= sum * count;
                sum += count;
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CountTrapezoids(int[][] points) {
        int n = points.Length;
        double inf = 1e9 + 7;
        Dictionary<double, List<double>> slopeToIntercept =
            new Dictionary<double, List<double>>();
        Dictionary<double, List<double>> midToSlope =
            new Dictionary<double, List<double>>();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x1 - x2;
                int dy = y1 - y2;

                double k, b;
                if (x2 == x1) {
                    k = inf;
                    b = x1;
                } else {
                    k = (double)(y2 - y1) / (x2 - x1);
                    b = (double)(y1 * dx - x1 * dy) / dx;
                }

                double mid = (x1 + x2) * 10000.0 + (y1 + y2);
                if (!slopeToIntercept.ContainsKey(k)) {
                    slopeToIntercept[k] = new List<double>();
                }
                if (!midToSlope.ContainsKey(mid)) {
                    midToSlope[mid] = new List<double>();
                }
                slopeToIntercept[k].Add(b);
                midToSlope[mid].Add(k);
            }
        }

        foreach (var sti in slopeToIntercept.Values) {
            if (sti.Count == 1) {
                continue;
            }
            Dictionary<double, int> cnt = new Dictionary<double, int>();
            foreach (double bVal in sti) {
                cnt[bVal] = cnt.GetValueOrDefault(bVal, 0) + 1;
            }
            int totalSum = 0;
            foreach (int count in cnt.Values) {
                ans += totalSum * count;
                totalSum += count;
            }
        }

        foreach (var mts in midToSlope.Values) {
            if (mts.Count == 1) {
                continue;
            }
            Dictionary<double, int> cnt = new Dictionary<double, int>();
            foreach (double kVal in mts) {
                cnt[kVal] = cnt.GetValueOrDefault(kVal, 0) + 1;
            }

            int totalSum = 0;
            foreach (int count in cnt.Values) {
                ans -= totalSum * count;
                totalSum += count;
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countTrapezoids(points [][]int) int {
	n := len(points)
	inf := 1e9 + 7
	slopeToIntercept := make(map[float64][]float64)
	midToSlope := make(map[float64][]float64)
	ans := 0

	for i := 0; i < n; i++ {
		x1, y1 := points[i][0], points[i][1]
		for j := i + 1; j < n; j++ {
			x2, y2 := points[j][0], points[j][1]
			dx := x1 - x2
			dy := y1 - y2

			var k, b float64
			if x2 == x1 {
				k = inf
				b = float64(x1)
			} else {
				k = float64(y2-y1) / float64(x2-x1)
				b = float64(y1*dx-x1*dy) / float64(dx)
			}

			mid := float64((x1+x2)*10000 + (y1 + y2))
			slopeToIntercept[k] = append(slopeToIntercept[k], b)
			midToSlope[mid] = append(midToSlope[mid], k)
		}
	}

	for _, sti := range slopeToIntercept {
		if len(sti) == 1 {
			continue
		}

		cnt := make(map[float64]int)
		for _, bVal := range sti {
			cnt[bVal]++
		}

		totalSum := 0
		for _, count := range cnt {
			ans += totalSum * count
			totalSum += count
		}
	}

	for _, mts := range midToSlope {
		if len(mts) == 1 {
			continue
		}

		cnt := make(map[float64]int)
		for _, kVal := range mts {
			cnt[kVal]++
		}

		totalSum := 0
		for _, count := range cnt {
			ans -= totalSum * count
			totalSum += count
		}
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
        int n = points.length;
        double inf = 1e9 + 7;
        Map<Double, List<Double>> slopeToIntercept = new HashMap<>();
        Map<Integer, List<Double>> midToSlope = new HashMap<>();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x1 - x2;
                int dy = y1 - y2;
                double k;
                double b;

                if (x2 == x1) {
                    k = inf;
                    b = x1;
                } else {
                    k = (1.0 * (y2 - y1)) / (x2 - x1);
                    b = (1.0 * (y1 * dx - x1 * dy)) / dx;
                }
                if (k == -0.0) {
                    k = 0.0;
                }
                if (b == -0.0) {
                    b = 0.0;
                }
                int mid = (x1 + x2) * 10000 + (y1 + y2);
                slopeToIntercept
                    .computeIfAbsent(k, key -> new ArrayList<>())
                    .add(b);
                midToSlope
                    .computeIfAbsent(mid, key -> new ArrayList<>())
                    .add(k);
            }
        }

        for (List<Double> sti : slopeToIntercept.values()) {
            if (sti.size() == 1) {
                continue;
            }
            Map<Double, Integer> cnt = new TreeMap<>();
            for (double b : sti) {
                cnt.put(b, cnt.getOrDefault(b, 0) + 1);
            }
            int sum = 0;
            for (int count : cnt.values()) {
                ans += sum * count;
                sum += count;
            }
        }

        for (List<Double> mts : midToSlope.values()) {
            if (mts.size() == 1) {
                continue;
            }
            Map<Double, Integer> cnt = new TreeMap<>();
            for (double k : mts) {
                cnt.put(k, cnt.getOrDefault(k, 0) + 1);
            }
            int sum = 0;
            for (int count : cnt.values()) {
                ans -= sum * count;
                sum += count;
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countTrapezoids = function (points) {
    const n = points.length;
    const inf = 1e9 + 7;
    const slopeToIntercept = new Map();
    const midToSlope = new Map();
    let ans = 0;

    for (let i = 0; i < n; i++) {
        const [x1, y1] = points[i];
        for (let j = i + 1; j < n; j++) {
            const [x2, y2] = points[j];
            const dx = x1 - x2;
            const dy = y1 - y2;

            let k, b;
            if (x2 === x1) {
                k = inf;
                b = x1;
            } else {
                k = (y2 - y1) / (x2 - x1);
                b = (y1 * dx - x1 * dy) / dx;
            }

            const mid = (x1 + x2) * 10000 + (y1 + y2);
            if (!slopeToIntercept.has(k)) {
                slopeToIntercept.set(k, []);
            }
            if (!midToSlope.has(mid)) {
                midToSlope.set(mid, []);
            }
            slopeToIntercept.get(k).push(b);
            midToSlope.get(mid).push(k);
        }
    }

    for (const sti of slopeToIntercept.values()) {
        if (sti.length === 1) {
            continue;
        }
        const cnt = new Map();
        for (const bVal of sti) {
            cnt.set(bVal, (cnt.get(bVal) || 0) + 1);
        }

        let totalSum = 0;
        for (const count of cnt.values()) {
            ans += totalSum * count;
            totalSum += count;
        }
    }

    for (const mts of midToSlope.values()) {
        if (mts.length === 1) {
            continue;
        }
        const cnt = new Map();
        for (const kVal of mts) {
            cnt.set(kVal, (cnt.get(kVal) || 0) + 1);
        }

        let totalSum = 0;
        for (const count of cnt.values()) {
            ans -= totalSum * count;
            totalSum += count;
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        n = len(points)
        inf = 10**9 + 7
        slope_to_intercept = defaultdict(list)
        mid_to_slope = defaultdict(list)
        ans = 0

        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                dx = x1 - x2
                dy = y1 - y2

                if x2 == x1:
                    k = inf
                    b = x1
                else:
                    k = (y2 - y1) / (x2 - x1)
                    b = (y1 * dx - x1 * dy) / dx

                mid = (x1 + x2) * 10000 + (y1 + y2)
                slope_to_intercept[k].append(b)
                mid_to_slope[mid].append(k)

        for sti in slope_to_intercept.values():
            if len(sti) == 1:
                continue

            cnt = defaultdict(int)
            for b_val in sti:
                cnt[b_val] += 1

            total_sum = 0
            for count in cnt.values():
                ans += total_sum * count
                total_sum += count

        for mts in mid_to_slope.values():
            if len(mts) == 1:
                continue

            cnt = defaultdict(int)
            for k_val in mts:
                cnt[k_val] += 1

            total_sum = 0
            for count in cnt.values():
                ans -= total_sum * count
                total_sum += count

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countTrapezoids(points: number[][]): number {
    const n: number = points.length;
    const inf: number = 1e9 + 7;
    const slopeToIntercept: Map<number, number[]> = new Map();
    const midToSlope: Map<number, number[]> = new Map();
    let ans: number = 0;

    for (let i = 0; i < n; i++) {
        const [x1, y1] = points[i];
        for (let j = i + 1; j < n; j++) {
            const [x2, y2] = points[j];
            const dx = x1 - x2;
            const dy = y1 - y2;

            let k: number, b: number;
            if (x2 === x1) {
                k = inf;
                b = x1;
            } else {
                k = (y2 - y1) / (x2 - x1);
                b = (y1 * dx - x1 * dy) / dx;
            }

            const mid: number = (x1 + x2) * 10000 + (y1 + y2);
            if (!slopeToIntercept.has(k)) {
                slopeToIntercept.set(k, []);
            }
            if (!midToSlope.has(mid)) {
                midToSlope.set(mid, []);
            }
            slopeToIntercept.get(k)!.push(b);
            midToSlope.get(mid)!.push(k);
        }
    }

    for (const sti of slopeToIntercept.values()) {
        if (sti.length === 1) {
            continue;
        }
        const cnt: Map<number, number> = new Map();
        for (const bVal of sti) {
            cnt.set(bVal, (cnt.get(bVal) || 0) + 1);
        }

        let totalSum: number = 0;
        for (const count of cnt.values()) {
            ans += totalSum * count;
            totalSum += count;
        }
    }

    for (const mts of midToSlope.values()) {
        if (mts.length === 1) {
            continue;
        }
        const cnt: Map<number, number> = new Map();
        for (const kVal of mts) {
            cnt.set(kVal, (cnt.get(kVal) || 0) + 1);
        }

        let totalSum: number = 0;
        for (const count of cnt.values()) {
            ans -= totalSum * count;
            totalSum += count;
        }
    }

    return ans;
}
```

</details>
