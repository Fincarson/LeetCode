# 3453. Separate Squares I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/separate-squares-i/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 3453 - Separate Squares I](https://leetcode.com/problems/separate-squares-i/)

## Problem

You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.

Answers within 10-5 of the actual answer will be accepted.

Note: Squares may overlap. Overlapping areas should be counted multiple times.

### Example 1

### Example 2

## Constraints

- 1 <= squares.length <= 5 * 104
- squares[i] = [xi, yi, li]
- squares[i].length == 3
- 0 <= xi, yi <= 109
- 1 <= li <= 109
- The total area of all the squares will not exceed 1012.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3453. Separate Squares I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Scanning Line | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool check(double limit_y, int** squares, int squaresSize, double total_area) {
    double area = 0.0;

    for (int i = 0; i < squaresSize; i++) {
        int y = squares[i][1];
        int l = squares[i][2];
        if (y < limit_y) {
            area += (double)l * fmin(l, limit_y - y);
        }
    }

    return area >= total_area / 2.0;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double max_y = 0.0, total_area = 0.0;
    for (int i = 0; i < squaresSize; i++) {
        int y = squares[i][1];
        int l = squares[i][2];
        total_area += (double)l * l;
        if (y + l > max_y) {
            max_y = y + l;
        }
    }

    double lo = 0.0, hi = max_y;
    double eps = 1e-5;
    while (fabs(hi - lo) > eps) {
        double mid = (hi + lo) / 2.0;
        if (check(mid, squares, squaresSize, total_area)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double max_y = 0, total_area = 0;
        for (auto& sq : squares) {
            int y = sq[1], l = sq[2];
            total_area += (double)l * l;
            max_y = max(max_y, (double)(y + l));
        }

        auto check = [&](double limit_y) -> bool {
            double area = 0;
            for (auto& sq : squares) {
                int y = sq[1], l = sq[2];
                if (y < limit_y) {
                    area += l * min(limit_y - y, (double)l);
                }
            }
            return area >= total_area / 2;
        };

        double lo = 0, hi = max_y;
        double eps = 1e-5;
        while (abs(hi - lo) > eps) {
            double mid = (hi + lo) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public double SeparateSquares(int[][] squares) {
        double max_y = 0, total_area = 0;
        foreach (int[] sq in squares) {
            int y = sq[1], l = sq[2];
            total_area += (double)l * l;
            max_y = Math.Max(max_y, (double)(y + l));
        }

        double lo = 0, hi = max_y;
        double eps = 1e-5;
        while (Math.Abs(hi - lo) > eps) {
            double mid = (hi + lo) / 2;
            if (Check(mid, squares, total_area)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }

    private bool Check(double limit_y, int[][] squares, double total_area) {
        double area = 0;
        foreach (int[] sq in squares) {
            int y = sq[1], l = sq[2];
            if (y < limit_y) {
                area += (double)l * Math.Min(limit_y - y, (double)l);
            }
        }
        return area >= total_area / 2;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func separateSquares(squares [][]int) float64 {
	max_y, total_area := 0.0, 0.0
	for _, sq := range squares {
		y, l := sq[1], sq[2]
		total_area += float64(l * l)
		if float64(y+l) > max_y {
			max_y = float64(y + l)
		}
	}

	check := func(limit_y float64) bool {
		area := 0.0
		for _, sq := range squares {
			y, l := sq[1], sq[2]
			if float64(y) < limit_y {
				overlap := math.Min(limit_y-float64(y), float64(l))
				area += float64(l) * overlap
			}
		}

		return area >= total_area/2.0
	}

	lo, hi := 0.0, max_y
	eps := 1e-5
	for math.Abs(hi-lo) > eps {
		mid := (hi + lo) / 2.0
		if check(mid) {
			hi = mid
		} else {
			lo = mid
		}
	}
	return hi
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public double separateSquares(int[][] squares) {
        double max_y = 0;
        double total_area = 0;
        for (int[] sq : squares) {
            int y = sq[1];
            int l = sq[2];
            total_area += (double) l * l;
            max_y = Math.max(max_y, (double) (y + l));
        }

        double lo = 0;
        double hi = max_y;
        double eps = 1e-5;
        while (Math.abs(hi - lo) > eps) {
            double mid = (hi + lo) / 2;
            if (check(mid, squares, total_area)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }

    private Boolean check(double limit_y, int[][] squares, double total_area) {
        double area = 0;
        for (int[] sq : squares) {
            int y = sq[1];
            int l = sq[2];
            if (y < limit_y) {
                area += (double) l * Math.min(limit_y - y, (double) l);
            }
        }
        return area >= total_area / 2;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var separateSquares = function (squares) {
    let max_y = 0,
        total_area = 0;
    for (const [x, y, l] of squares) {
        total_area += l * l;
        max_y = Math.max(max_y, y + l);
    }

    const check = (limit_y) => {
        let area = 0;
        for (const [x, y, l] of squares) {
            if (y < limit_y) {
                area += l * Math.min(limit_y - y, l);
            }
        }
        return area >= total_area / 2;
    };

    let lo = 0,
        hi = max_y;
    const eps = 1e-5;
    while (Math.abs(hi - lo) > eps) {
        const mid = (hi + lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        max_y, total_area = 0, 0
        for x, y, l in squares:
            total_area += l**2
            max_y = max(max_y, y + l)

        def check(limit_y):
            area = 0
            for x, y, l in squares:
                if y < limit_y:
                    area += l * min(limit_y - y, l)
            return area >= total_area / 2

        lo, hi = 0, max_y
        eps = 1e-5
        while abs(hi - lo) > eps:
            mid = (hi + lo) / 2
            if check(mid):
                hi = mid
            else:
                lo = mid

        return hi
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function separateSquares(squares: number[][]): number {
    let max_y = 0,
        total_area = 0;
    for (const [x, y, l] of squares) {
        total_area += l * l;
        max_y = Math.max(max_y, y + l);
    }

    const check = (limit_y: number): boolean => {
        let area = 0;
        for (const [x, y, l] of squares) {
            if (y < limit_y) {
                area += l * Math.min(limit_y - y, l);
            }
        }
        return area >= total_area / 2;
    };

    let lo = 0,
        hi = max_y;
    const eps = 1e-5;
    while (Math.abs(hi - lo) > eps) {
        const mid = (hi + lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}
```

</details>

<br>

## Approach 2: Scanning Line

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int y;
    int l;
    int delta;
} Event;

int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    return e1->y - e2->y;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    long long totalArea = 0;
    Event* events = malloc(2 * squaresSize * sizeof(Event));
    int eventCount = 0;

    for (int i = 0; i < squaresSize; i++) {
        int y = squares[i][1];
        int l = squares[i][2];
        totalArea += (long long)l * l;
        events[eventCount++] = (Event){y, l, 1};
        events[eventCount++] = (Event){y + l, l, -1};
    }

    // sort by y-coordinate
    qsort(events, eventCount, sizeof(Event), compareEvents);

    double coveredWidth =
        0.0;  // sum of all bottom edges under the current scanning line
    double currArea = 0.0;    // current cumulative area
    double prevHeight = 0.0;  // height of the previous scanning line

    for (int i = 0; i < eventCount; i++) {
        int y = events[i].y;
        int l = events[i].l;
        int delta = events[i].delta;

        int diff = y - (int)prevHeight;
        // additional area between two scanning lines
        double area = coveredWidth * diff;
        // if this part of the area exceeds more than half of the total area
        if (2LL * (currArea + area) >= totalArea) {
            double result = prevHeight +
                            (totalArea - 2.0 * currArea) / (2.0 * coveredWidth);
            free(events);
            return result;
        }
        // update width: add width at the start event, subtract width at the end
        // event
        coveredWidth += delta * l;
        currArea += area;
        prevHeight = y;
    }

    free(events);
    return 0.0;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total_area = 0;
        vector<tuple<int, int, int>> events;
        for (const auto& sq : squares) {
            int y = sq[1], l = sq[2];
            total_area += (long long)l * l;
            events.emplace_back(y, l, 1);
            events.emplace_back(y + l, l, -1);
        }
        // sort by y-coordinate
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return get<0>(a) < get<0>(b);
        });

        double covered_width =
            0;  // sum of all bottom edges under the current scanning line
        double curr_area = 0;    // current cumulative area
        double prev_height = 0;  // height of the previous scanning line
        for (const auto& [y, l, delta] : events) {
            int diff = y - prev_height;
            // additional area between two scanning lines
            double area = covered_width * diff;
            // if this part of the area exceeds more than half of the total area
            if (2LL * (curr_area + area) >= total_area) {
                return prev_height +
                       (total_area - 2.0 * curr_area) / (2.0 * covered_width);
            }
            // update width: add width at the start event, subtract width at the
            // end event
            covered_width += delta * l;
            curr_area += area;
            prev_height = y;
        }

        return 0.0;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public double SeparateSquares(int[][] squares) {
        long totalArea = 0;
        List<int[]> events = new List<int[]>();

        foreach (var sq in squares) {
            int y = sq[1], l = sq[2];
            totalArea += (long)l * l;
            events.Add(new int[] { y, l, 1 });
            events.Add(new int[] { y + l, l, -1 });
        }

        // sort by y-coordinate
        events.Sort((a, b) => a[0].CompareTo(b[0]));

        double coveredWidth =
            0;  // sum of all bottom edges under the current scanning line
        double currArea = 0;    // current cumulative area
        double prevHeight = 0;  // height of the previous scanning line

        foreach (var eventItem in events) {
            int y = eventItem[0];
            int l = eventItem[1];
            int delta = eventItem[2];

            int diff = y - (int)prevHeight;
            // additional area between two scanning lines
            double area = coveredWidth * diff;
            // if this part of the area exceeds more than half of the total area
            if (2L * (currArea + area) >= totalArea) {
                return prevHeight +
                       (totalArea - 2.0 * currArea) / (2.0 * coveredWidth);
            }
            // update width: add width at the start event, subtract width at the
            // end event
            coveredWidth += delta * l;
            currArea += area;
            prevHeight = y;
        }

        return 0.0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func separateSquares(squares [][]int) float64 {
    var totalArea int64 = 0
    type Event struct {
        y     int
        l     int
        delta int
    }
    events := make([]Event, 0, len(squares)*2)
    
    for _, sq := range squares {
        y, l := sq[1], sq[2]
        totalArea += int64(l) * int64(l)
        events = append(events, Event{y, l, 1})
        events = append(events, Event{y + l, l, -1})
    }
    
    // sort by y-coordinate
    sort.Slice(events, func(i, j int) bool {
        return events[i].y < events[j].y
    })
    
    coveredWidth := 0.0  // sum of all bottom edges under the current scanning line
    currArea := 0.0      // current cumulative area
    prevHeight := 0.0    // height of the previous scanning line
    
    for _, event := range events {
        y, l, delta := event.y, event.l, event.delta
        diff := float64(y) - prevHeight
        // additional area between two scanning lines
        area := coveredWidth * diff
        // if this part of the area exceeds more than half of the total area
        if 2.0*(currArea+area) >= float64(totalArea) {
            return prevHeight + (float64(totalArea) - 2.0*currArea) / (2.0 * coveredWidth)
        }
        // update width: add width at the start event, subtract width at the end event
        coveredWidth += float64(delta * l)
        currArea += area
        prevHeight = float64(y)
    }
    
    return 0.0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public double separateSquares(int[][] squares) {
        long totalArea = 0;
        List<int[]> events = new ArrayList<>();

        for (int[] sq : squares) {
            int y = sq[1];
            int l = sq[2];
            totalArea += (long) l * l;
            events.add(new int[] { y, l, 1 });
            events.add(new int[] { y + l, l, -1 });
        }

        // sort by y-coordinate
        events.sort((a, b) -> Integer.compare(a[0], b[0]));
        double coveredWidth = 0; // sum of all bottom edges under the current scanning line
        double currArea = 0; // current cumulative area
        double prevHeight = 0; // height of the previous scanning line

        for (int[] event : events) {
            int y = event[0];
            int l = event[1];
            int delta = event[2];

            int diff = y - (int) prevHeight;
            // additional area between two scanning lines
            double area = coveredWidth * diff;
            // if this part of the area exceeds more than half of the total area
            if (2L * (currArea + area) >= totalArea) {
                return (
                    prevHeight +
                    (totalArea - 2.0 * currArea) / (2.0 * coveredWidth)
                );
            }
            // update width: add width at the start event, subtract width at the end event
            coveredWidth += delta * l;
            currArea += area;
            prevHeight = y;
        }

        return 0.0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var separateSquares = function (squares) {
    let totalArea = 0n;
    const events = [];

    for (const sq of squares) {
        const y = sq[1],
            l = sq[2];
        totalArea += BigInt(l) * BigInt(l);
        events.push([y, l, 1]);
        events.push([y + l, l, -1]);
    }

    // sort by y-coordinate
    events.sort((a, b) => a[0] - b[0]);

    let coveredWidth = 0; // sum of all bottom edges under the current scanning line
    let currArea = 0; // current cumulative area
    let prevHeight = 0; // height of the previous scanning line

    for (const [y, l, delta] of events) {
        const diff = y - prevHeight;
        // additional area between two scanning lines
        const area = coveredWidth * diff;
        // if this part of the area exceeds more than half of the total area
        if (2n * BigInt(Math.ceil(currArea + area)) >= totalArea) {
            return (
                prevHeight +
                (Number(totalArea) - 2.0 * currArea) / (2.0 * coveredWidth)
            );
        }
        // update width: add width at the start event, subtract width at the end event
        coveredWidth += delta * l;
        currArea += area;
        prevHeight = y;
    }

    return 0.0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        total_area = 0
        events = []

        for sq in squares:
            y, l = sq[1], sq[2]
            total_area += l * l
            events.append((y, l, 1))
            events.append((y + l, l, -1))

        # sort by y-coordinate
        events.sort(key=lambda x: x[0])

        covered_width = (
            0.0  # sum of all bottom edges under the current scanning line
        )
        curr_area = 0.0  # current cumulative area
        prev_height = 0.0  # height of the previous scanning line

        for y, l, delta in events:
            diff = y - prev_height
            # additional area between two scanning lines
            area = covered_width * diff
            # if this part of the area exceeds more than half of the total area
            if 2 * (curr_area + area) >= total_area:
                return prev_height + (total_area - 2 * curr_area) / (
                    2 * covered_width
                )
            # update width: add width at the start event, subtract width at the end event
            covered_width += delta * l
            curr_area += area
            prev_height = y

        return 0.0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function separateSquares(squares: number[][]): number {
    let totalArea: bigint = 0n;
    const events: [number, number, number][] = [];

    for (const sq of squares) {
        const y = sq[1],
            l = sq[2];
        totalArea += BigInt(l) * BigInt(l);
        events.push([y, l, 1]);
        events.push([y + l, l, -1]);
    }

    // sort by y-coordinate
    events.sort((a, b) => a[0] - b[0]);

    let coveredWidth: number = 0; // sum of all bottom edges under the current scanning line
    let currArea: number = 0; // current cumulative area
    let prevHeight: number = 0; // height of the previous scanning line

    for (const [y, l, delta] of events) {
        const diff: number = y - prevHeight;
        // additional area between two scanning lines
        const area: number = coveredWidth * diff;
        // if this part of the area exceeds more than half of the total area
        if (2n * BigInt(Math.ceil(currArea + area)) >= totalArea) {
            return (
                prevHeight +
                (Number(totalArea) - 2.0 * currArea) / (2.0 * coveredWidth)
            );
        }
        // update width: add width at the start event, subtract width at the end event
        coveredWidth += delta * l;
        currArea += area;
        prevHeight = y;
    }

    return 0.0;
}
```

</details>
