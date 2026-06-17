# 3027. Find the Number of Ways to Place People II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/)  
`Array` `Math` `Geometry` `Sorting` `Enumeration`

**Problem Link:** [LeetCode 3027 - Find the Number of Ways to Place People II](https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/)

## Problem

You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

We define the right direction as positive x-axis (increasing x-coordinate) and the left direction as negative x-axis (decreasing x-coordinate). Similarly, we define the up direction as positive y-axis (increasing y-coordinate) and the down direction as negative y-axis (decreasing y-coordinate)

You have to place n people, including Alice and Bob, at these points such that there is exactly one person at every point. Alice wants to be alone with Bob, so Alice will build a rectangular fence with Alice's position as the upper left corner and Bob's position as the lower right corner of the fence (Note that the fence might not enclose any area, i.e. it can be a line). If any person other than Alice and Bob is either inside the fence or on the fence, Alice will be sad.

Return the number of pairs of points where you can place Alice and Bob, such that Alice does not become sad on building the fence.

Note that Alice can only build a fence with Alice's position as the upper left corner, and Bob's position as the lower right corner. For example, Alice cannot build either of the fences in the picture below with four corners (1, 1), (1, 3), (3, 1), and (3, 3), because:

- With Alice at (3, 3) and Bob at (1, 1), Alice's position is not the upper left corner and Bob's position is not the lower right corner of the fence.
- With Alice at (1, 3) and Bob at (1, 1) (as the rectangle shown in the image instead of a line), Bob's position is not the lower right corner of the fence.

### Example 1

```text
Input: points = [[1,1],[2,2],[3,3]]
Output: 0
Explanation: There is no way to place Alice and Bob such that Alice can build a fence with Alice's position as the upper left corner and Bob's position as the lower right corner. Hence we return 0.
```

### Example 2

```text
Input: points = [[6,2],[4,4],[2,6]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
- Place Alice at (4, 4) and Bob at (6, 2).
- Place Alice at (2, 6) and Bob at (4, 4).
You cannot place Alice at (2, 6) and Bob at (6, 2) because the person at (4, 4) will be inside the fence.
```

### Example 3

```text
Input: points = [[3,1],[1,3],[1,1]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
- Place Alice at (1, 1) and Bob at (3, 1).
- Place Alice at (1, 3) and Bob at (1, 1).
You cannot place Alice at (1, 3) and Bob at (3, 1) because the person at (1, 1) will be on the fence.
Note that it does not matter if the fence encloses any area, the first and second fences in the image are valid.
```

## Constraints

- 2 <= n <= 1000
- points[i].length == 2
- -109 <= points[i][0], points[i][1] <= 109
- All points[i] are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rectangle Area](https://leetcode.com/problems/rectangle-area/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3027. Find the Number of Ways to Place People II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort + Double Loop Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| 2D Prefix Sum + Discretization | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sort + Double Loop Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) {
    int* pa = *(int**)a;
    int* pb = *(int**)b;
    if (pa[0] != pb[0]) return pa[0] - pb[0];
    return pb[1] - pa[1];
}

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    int ans = 0;
    qsort(points, pointsSize, sizeof(int*), compare);

    for (int i = 0; i < pointsSize - 1; i++) {
        int* pointA = points[i];
        int xMin = pointA[0] - 1;
        int xMax = INT_MAX;
        int yMin = INT_MIN;
        int yMax = pointA[1] + 1;

        for (int j = i + 1; j < pointsSize; j++) {
            int* pointB = points[j];
            if (pointB[0] > xMin && pointB[0] < xMax && pointB[1] > yMin &&
                pointB[1] < yMax) {
                ans++;
                xMin = pointB[0];
                yMin = pointB[1];
            }
        }
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
             });

        for (int i = 0; i < points.size() - 1; i++) {
            const auto& pointA = points[i];
            int xMin = pointA[0] - 1;
            int xMax = INT_MAX;
            int yMin = INT_MIN;
            int yMax = pointA[1] + 1;

            for (int j = i + 1; j < points.size(); j++) {
                const auto& pointB = points[j];
                if (pointB[0] > xMin && pointB[0] < xMax && pointB[1] > yMin &&
                    pointB[1] < yMax) {
                    ans++;
                    xMin = pointB[0];
                    yMin = pointB[1];
                }
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
    public int NumberOfPairs(int[][] points) {
        int ans = 0;
        Array.Sort(points, (a, b) => a[0] != b[0] ? a[0].CompareTo(b[0])
                                                  : b[1].CompareTo(a[1]));
        for (int i = 0; i < points.Length - 1; i++) {
            int[] pointA = points[i];
            int xMin = pointA[0] - 1;
            int xMax = int.MaxValue;
            int yMin = int.MinValue;
            int yMax = pointA[1] + 1;

            for (int j = i + 1; j < points.Length; j++) {
                int[] pointB = points[j];
                if (pointB[0] > xMin && pointB[0] < xMax && pointB[1] > yMin &&
                    pointB[1] < yMax) {
                    ans++;
                    xMin = pointB[0];
                    yMin = pointB[1];
                }
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
func numberOfPairs(points [][]int) int {
	ans := 0
	sort.Slice(points, func(i, j int) bool {
		if points[i][0] == points[j][0] {
			return points[i][1] > points[j][1]
		}
		return points[i][0] < points[j][0]
	})

	for i := 0; i < len(points)-1; i++ {
		pointA := points[i]
		xMin := pointA[0] - 1
		xMax := math.MaxInt32
		yMin := math.MinInt32
		yMax := pointA[1] + 1

		for j := i + 1; j < len(points); j++ {
			pointB := points[j]
			if pointB[0] > xMin && pointB[0] < xMax &&
				pointB[1] > yMin && pointB[1] < yMax {
				ans++
				xMin = pointB[0]
				yMin = pointB[1]
			}
		}
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int numberOfPairs(int[][] points) {
        int ans = 0;
        Arrays.sort(points, (a, b) -> a[0] != b[0] ? a[0] - b[0] : b[1] - a[1]);
        for (int i = 0; i < points.length - 1; i++) {
            int[] pointA = points[i];
            int xMin = pointA[0] - 1;
            int xMax = Integer.MAX_VALUE;
            int yMin = Integer.MIN_VALUE;
            int yMax = pointA[1] + 1;

            for (int j = i + 1; j < points.length; j++) {
                int[] pointB = points[j];
                if (
                    pointB[0] > xMin &&
                    pointB[0] < xMax &&
                    pointB[1] > yMin &&
                    pointB[1] < yMax
                ) {
                    ans++;
                    xMin = pointB[0];
                    yMin = pointB[1];
                }
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
var numberOfPairs = function (points) {
    let ans = 0;

    points.sort((a, b) => a[0] - b[0] || b[1] - a[1]);

    for (let i = 0; i < points.length - 1; i++) {
        const pointA = points[i];
        const xRange = [pointA[0] - 1, Infinity];
        const yRange = [-Infinity, pointA[1] + 1];

        for (let j = i + 1; j < points.length; j++) {
            const pointB = points[j];

            if (
                pointB[0] > xRange[0] &&
                pointB[0] < xRange[1] &&
                pointB[1] > yRange[0] &&
                pointB[1] < yRange[1]
            ) {
                ans++;
                xRange[0] = pointB[0];
                yRange[0] = pointB[1];
            }
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
    def numberOfPairs(self, points: List[List[int]]) -> int:
        ans = 0
        points.sort(key=lambda x: (x[0], -x[1]))

        for i in range(len(points) - 1):
            pointA = points[i]
            xMin = pointA[0] - 1
            xMax = math.inf
            yMin = -math.inf
            yMax = pointA[1] + 1

            for j in range(i + 1, len(points)):
                pointB = points[j]
                if (
                    pointB[0] > xMin
                    and pointB[0] < xMax
                    and pointB[1] > yMin
                    and pointB[1] < yMax
                ):
                    ans += 1
                    xMin = pointB[0]
                    yMin = pointB[1]

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfPairs(points: number[][]): number {
    let ans = 0;

    points.sort((a, b) => a[0] - b[0] || b[1] - a[1]);

    for (let i = 0; i < points.length - 1; i++) {
        const pointA = points[i];
        const xRange = [pointA[0] - 1, Infinity];
        const yRange = [-Infinity, pointA[1] + 1];

        for (let j = i + 1; j < points.length; j++) {
            const pointB = points[j];

            if (
                pointB[0] > xRange[0] &&
                pointB[0] < xRange[1] &&
                pointB[1] > yRange[0] &&
                pointB[1] < yRange[1]
            ) {
                ans++;
                xRange[0] = pointB[0];
                yRange[0] = pointB[1];
            }
        }
    }

    return ans;
}
```

</details>

<br>

## Approach 2: 2D Prefix Sum + Discretization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

struct PairEqual {
    bool operator()(const pair<int, int>& lhs,
                    const pair<int, int>& rhs) const {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        unordered_map<int, int> col;
        unordered_map<int, int> row;
        unordered_map<pair<int, int>, pair<int, int>, PairHash, PairEqual>
            coordinatesMap;

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            col[x] = 0;
            row[y] = 0;
        }

        vector<int> colKeys;
        for (const auto& pair : col) {
            colKeys.push_back(pair.first);
        }
        sort(colKeys.begin(), colKeys.end());
        for (int i = 0; i < colKeys.size(); i++) {
            col[colKeys[i]] = i + 1;
        }

        vector<int> rowKeys;
        for (const auto& pair : row) {
            rowKeys.push_back(pair.first);
        }
        sort(rowKeys.begin(), rowKeys.end());
        for (int i = 0; i < rowKeys.size(); i++) {
            row[rowKeys[i]] = i + 1;
        }

        int nc = col.size() + 1;
        int nr = row.size() + 1;
        vector<vector<int>> m(nc, vector<int>(nr, 0));
        vector<vector<int>> prefixSum(nc, vector<int>(nr, 0));

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int c = col[x];
            int r = row[y];
            pair<int, int> key = make_pair(x, y);
            coordinatesMap[key] = make_pair(c, r);
            m[c][r] = 1;
        }

        for (int i = 1; i < nc; i++) {
            for (int j = 1; j < nr; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] -
                                  prefixSum[i - 1][j - 1] + m[i][j];
            }
        }

        int ans = 0;
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) {
                     return a[1] > b[1];
                 }
                 return a[0] < b[0];
             });

        int n = points.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (points[i][1] >= points[j][1]) {
                    pair<int, int> key1 = make_pair(points[i][0], points[i][1]);
                    pair<int, int> key2 = make_pair(points[j][0], points[j][1]);
                    pair<int, int> coord1 = coordinatesMap[key1];
                    pair<int, int> coord2 = coordinatesMap[key2];
                    int c1 = coord1.first, r1 = coord1.second;
                    int c2 = coord2.first, r2 = coord2.second;
                    int cnt = prefixSum[c2][r1] - prefixSum[c1 - 1][r1] -
                              prefixSum[c2][r2 - 1] + prefixSum[c1 - 1][r2 - 1];
                    if (cnt == 2) {
                        ans++;
                    }
                }
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
public class Point : IEquatable<Point> {
    public int X { get; }
    public int Y { get; }

    public Point(int x, int y) {
        X = x;
        Y = y;
    }

    public override bool Equals(object obj) {
        return obj is Point other && Equals(other);
    }

    public bool Equals(Point other) {
        return X == other.X && Y == other.Y;
    }

    public override int GetHashCode() {
        return HashCode.Combine(X, Y);
    }
}

public class Solution {
    public int NumberOfPairs(int[][] points) {
        Dictionary<int, int> col = new Dictionary<int, int>();
        Dictionary<int, int> row = new Dictionary<int, int>();
        Dictionary<Point, Tuple<int, int>> coordinatesMap =
            new Dictionary<Point, Tuple<int, int>>();

        foreach (var point in points) {
            int x = point[0], y = point[1];
            if (!col.ContainsKey(x)) {
                col[x] = 0;
            }
            if (!row.ContainsKey(y)) {
                row[y] = 0;
            }
        }

        var colKeys = col.Keys.ToList();
        colKeys.Sort();
        for (int i = 0; i < colKeys.Count; i++) {
            col[colKeys[i]] = i + 1;
        }
        var rowKeys = row.Keys.ToList();
        rowKeys.Sort();
        for (int i = 0; i < rowKeys.Count; i++) {
            row[rowKeys[i]] = i + 1;
        }

        int nc = col.Count + 1;
        int nr = row.Count + 1;
        int[,] m = new int[nc, nr];
        int[,] prefixSum = new int[nc, nr];

        foreach (var point in points) {
            int x = point[0], y = point[1];
            int c = col[x], r = row[y];
            var key = new Point(x, y);
            coordinatesMap[key] = Tuple.Create(c, r);
            m[c, r] = 1;
        }

        for (int i = 1; i < nc; i++) {
            for (int j = 1; j < nr; j++) {
                prefixSum[i, j] = prefixSum[i - 1, j] + prefixSum[i, j - 1] -
                                  prefixSum[i - 1, j - 1] + m[i, j];
            }
        }

        int ans = 0;
        var sortedPoints =
            points.OrderBy(p => p[0]).ThenByDescending(p => p[1]).ToArray();

        int n = sortedPoints.Length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sortedPoints[i][1] >= sortedPoints[j][1]) {
                    var key1 =
                        new Point(sortedPoints[i][0], sortedPoints[i][1]);
                    var key2 =
                        new Point(sortedPoints[j][0], sortedPoints[j][1]);
                    var coord1 = coordinatesMap[key1];
                    var coord2 = coordinatesMap[key2];
                    int c1 = coord1.Item1, r1 = coord1.Item2;
                    int c2 = coord2.Item1, r2 = coord2.Item2;

                    int cnt = prefixSum[c2, r1] - prefixSum[c1 - 1, r1] -
                              prefixSum[c2, r2 - 1] + prefixSum[c1 - 1, r2 - 1];

                    if (cnt == 2) {
                        ans++;
                    }
                }
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
func numberOfPairs(points [][]int) int {
	col := make(map[int]int)
	row := make(map[int]int)
	coordinatesMap := make(map[[2]int][2]int)

	for _, point := range points {
		x, y := point[0], point[1]
		col[x] = 0
		row[y] = 0
	}

	colKeys := make([]int, 0, len(col))
	for k := range col {
		colKeys = append(colKeys, k)
	}
	sort.Ints(colKeys)
	for i, key := range colKeys {
		col[key] = i + 1
	}
	rowKeys := make([]int, 0, len(row))
	for k := range row {
		rowKeys = append(rowKeys, k)
	}
	sort.Ints(rowKeys)
	for i, key := range rowKeys {
		row[key] = i + 1
	}

	nc := len(col) + 1
	nr := len(row) + 1

	m := make([][]int, nc)
	prefixSum := make([][]int, nc)
	for i := range m {
		m[i] = make([]int, nr)
		prefixSum[i] = make([]int, nr)
	}

	for _, point := range points {
		x, y := point[0], point[1]
		c, r := col[x], row[y]
		key := [2]int{x, y}
		coordinatesMap[key] = [2]int{c, r}
		m[c][r] = 1
	}

	for i := 1; i < nc; i++ {
		for j := 1; j < nr; j++ {
			prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] -
				prefixSum[i-1][j-1] + m[i][j]
		}
	}

	ans := 0
	sort.Slice(points, func(i, j int) bool {
		if points[i][0] == points[j][0] {
			return points[i][1] > points[j][1]
		}
		return points[i][0] < points[j][0]
	})

	n := len(points)
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			if points[i][1] >= points[j][1] {
				key1 := [2]int{points[i][0], points[i][1]}
				key2 := [2]int{points[j][0], points[j][1]}
				coord1 := coordinatesMap[key1]
				coord2 := coordinatesMap[key2]
				c1, r1 := coord1[0], coord1[1]
				c2, r2 := coord2[0], coord2[1]

				cnt := prefixSum[c2][r1] - prefixSum[c1-1][r1] -
					prefixSum[c2][r2-1] + prefixSum[c1-1][r2-1]

				if cnt == 2 {
					ans++
				}
			}
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

    static class Point {

        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Point point = (Point) o;
            return x == point.x && y == point.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }

    public int numberOfPairs(int[][] points) {
        Map<Integer, Integer> col = new HashMap<>();
        Map<Integer, Integer> row = new HashMap<>();
        Map<Point, int[]> coordinatesMap = new HashMap<>();

        for (int[] point : points) {
            int x = point[0];
            int y = point[1];
            col.put(x, 0);
            row.put(y, 0);
        }
        List<Integer> colKeys = new ArrayList<>(col.keySet());
        Collections.sort(colKeys);
        for (int i = 0; i < colKeys.size(); i++) {
            col.put(colKeys.get(i), i + 1);
        }
        List<Integer> rowKeys = new ArrayList<>(row.keySet());
        Collections.sort(rowKeys);
        for (int i = 0; i < rowKeys.size(); i++) {
            row.put(rowKeys.get(i), i + 1);
        }

        int nc = col.size() + 1;
        int nr = row.size() + 1;
        int[][] m = new int[nc][nr];
        int[][] prefixSum = new int[nc][nr];

        for (int[] point : points) {
            int x = point[0];
            int y = point[1];
            int c = col.get(x);
            int r = row.get(y);
            Point key = new Point(x, y);
            coordinatesMap.put(key, new int[] { c, r });
            m[c][r] = 1;
        }
        for (int i = 1; i < nc; i++) {
            for (int j = 1; j < nr; j++) {
                prefixSum[i][j] =
                    prefixSum[i - 1][j] +
                    prefixSum[i][j - 1] -
                    prefixSum[i - 1][j - 1] +
                    m[i][j];
            }
        }

        int ans = 0;
        Arrays.sort(points, (a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(b[1], a[1]);
            }
            return Integer.compare(a[0], b[0]);
        });

        int n = points.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (points[i][1] >= points[j][1]) {
                    Point key1 = new Point(points[i][0], points[i][1]);
                    Point key2 = new Point(points[j][0], points[j][1]);
                    int[] coord1 = coordinatesMap.get(key1);
                    int[] coord2 = coordinatesMap.get(key2);
                    int c1 = coord1[0];
                    int r1 = coord1[1];
                    int c2 = coord2[0];
                    int r2 = coord2[1];
                    int cnt =
                        prefixSum[c2][r1] -
                        prefixSum[c1 - 1][r1] -
                        prefixSum[c2][r2 - 1] +
                        prefixSum[c1 - 1][r2 - 1];
                    if (cnt == 2) {
                        ans++;
                    }
                }
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
var numberOfPairs = function (points) {
    const col = new Map();
    const row = new Map();
    const coordinatesMap = new Map();

    for (const [x, y] of points) {
        col.set(x, 0);
        row.set(y, 0);
    }

    function mapKeysToOrder(m) {
        const sortedKeys = Array.from(m.keys()).sort((a, b) => a - b);
        sortedKeys.forEach((key, index) => {
            m.set(key, index + 1);
        });
    }

    mapKeysToOrder(col);
    mapKeysToOrder(row);

    const nc = col.size + 1;
    const nr = row.size + 1;

    const m = Array.from({ length: nc }, () => new Array(nr).fill(0));

    for (const point of points) {
        const [c, r] = [col.get(point[0]), row.get(point[1])];
        coordinatesMap.set(point, [c, r]);
        m[c][r] = 1;
    }

    const prefixSum = Array.from({ length: nc }, () => new Array(nr).fill(0));

    for (let i = 1; i < nc; i++) {
        for (let j = 1; j < nr; j++) {
            prefixSum[i][j] =
                prefixSum[i - 1][j] +
                prefixSum[i][j - 1] -
                prefixSum[i - 1][j - 1] +
                m[i][j];
        }
    }

    let ans = 0;

    points.sort((a, b) => a[0] - b[0] || b[1] - a[1]);

    for (let i = 0; i < points.length - 1; i++) {
        for (let j = i + 1; j < points.length; j++) {
            if (points[i][1] >= points[j][1]) {
                const [c1, r1] = coordinatesMap.get(points[i]);
                const [c2, r2] = coordinatesMap.get(points[j]);

                const cnt =
                    prefixSum[c2][r1] -
                    prefixSum[c1 - 1][r1] -
                    prefixSum[c2][r2 - 1] +
                    prefixSum[c1 - 1][r2 - 1];

                if (cnt === 2) ans++;
            }
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
    def numberOfPairs(self, points: List[List[int]]) -> int:
        col = {}
        row = {}
        coordinates_map = {}

        for point in points:
            x, y = point
            col[x] = 0
            row[y] = 0

        def map_keys_to_order(m):
            sorted_keys = sorted(m.keys())
            for idx, key in enumerate(sorted_keys):
                m[key] = idx + 1

        map_keys_to_order(col)
        map_keys_to_order(row)
        nc = len(col) + 1
        nr = len(row) + 1
        m = [[0] * nr for _ in range(nc)]
        prefix_sum = [[0] * nr for _ in range(nc)]

        for point in points:
            x, y = point
            c = col[x]
            r = row[y]
            coordinates_map[tuple(point)] = (c, r)
            m[c][r] = 1

        for i in range(1, nc):
            for j in range(1, nr):
                prefix_sum[i][j] = (
                    prefix_sum[i - 1][j]
                    + prefix_sum[i][j - 1]
                    - prefix_sum[i - 1][j - 1]
                    + m[i][j]
                )

        ans = 0
        points.sort(key=lambda p: (p[0], -p[1]))
        n = len(points)
        for i in range(n - 1):
            for j in range(i + 1, n):
                if points[i][1] >= points[j][1]:
                    c1, r1 = coordinates_map[tuple(points[i])]
                    c2, r2 = coordinates_map[tuple(points[j])]
                    cnt = (
                        prefix_sum[c2][r1]
                        - prefix_sum[c1 - 1][r1]
                        - prefix_sum[c2][r2 - 1]
                        + prefix_sum[c1 - 1][r2 - 1]
                    )

                    if cnt == 2:
                        ans += 1

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfPairs(points: number[][]): number {
    const col = new Map<number, number>();
    const row = new Map<number, number>();
    const coordinatesMap = new Map<[number, number], [number, number]>();

    for (const [x, y] of points) {
        col.set(x, 0);
        row.set(y, 0);
    }

    function mapKeysToOrder(m: Map<number, number>) {
        const sortedKeys = Array.from(m.keys()).sort((a, b) => a - b);
        sortedKeys.forEach((key, index) => {
            m.set(key, index + 1);
        });
    }

    mapKeysToOrder(col);
    mapKeysToOrder(row);

    const nc = col.size + 1;
    const nr = row.size + 1;

    const m: number[][] = Array.from({ length: nc }, () =>
        new Array(nr).fill(0),
    );

    for (const point of points) {
        const [c, r] = [col.get(point[0])!, row.get(point[1])!];
        coordinatesMap.set(point as [number, number], [c, r]);
        m[c][r] = 1;
    }

    const prefixSum = Array.from({ length: nc }, () => new Array(nr).fill(0));

    for (let i = 1; i < nc; i++) {
        for (let j = 1; j < nr; j++) {
            prefixSum[i][j] =
                prefixSum[i - 1][j] +
                prefixSum[i][j - 1] -
                prefixSum[i - 1][j - 1] +
                m[i][j];
        }
    }

    let ans = 0;

    points.sort((a, b) => a[0] - b[0] || b[1] - a[1]);

    for (let i = 0; i < points.length - 1; i++) {
        for (let j = i + 1; j < points.length; j++) {
            if (points[i][1] >= points[j][1]) {
                const [c1, r1] = coordinatesMap.get(
                    points[i] as [number, number],
                )!;
                const [c2, r2] = coordinatesMap.get(
                    points[j] as [number, number],
                )!;

                const cnt =
                    prefixSum[c2][r1] -
                    prefixSum[c1 - 1][r1] -
                    prefixSum[c2][r2 - 1] +
                    prefixSum[c1 - 1][r2 - 1];

                if (cnt === 2) ans++;
            }
        }
    }

    return ans;
}
```

</details>
