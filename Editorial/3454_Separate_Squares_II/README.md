# 3454. Separate Squares II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/separate-squares-ii/)  
`Array` `Binary Search` `Segment Tree` `Sweep Line`

**Problem Link:** [LeetCode 3454 - Separate Squares II](https://leetcode.com/problems/separate-squares-ii/)

## Problem

You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.

Answers within 10-5 of the actual answer will be accepted.

Note: Squares may overlap. Overlapping areas should be counted only once in this version.

### Example 1

### Example 2

## Constraints

- 1 <= squares.length <= 5 * 104
- squares[i] = [xi, yi, li]
- squares[i].length == 3
- 0 <= xi, yi <= 109
- 1 <= li <= 109
- The total area of all the squares will not exceed 1015.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rectangle Area II](https://leetcode.com/problems/rectangle-area-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3454. Separate Squares II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Scanning Line + Segment Tree | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Scanning Line + Segment Tree

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* count;
    int* covered;
    int* xs;
    int n;
} SegmentTree;

typedef struct {
    int y;
    int delta;
    int xl;
    int xr;
} Event;

// create a segment tree
SegmentTree* createSegmentTree(int* xs, int xsSize) {
    SegmentTree* st = (SegmentTree*)malloc(sizeof(SegmentTree));
    st->xs = (int*)malloc(sizeof(int) * xsSize);
    memcpy(st->xs, xs, sizeof(int) * xsSize);
    st->n = xsSize - 1;
    int size = 4 * st->n;
    st->count = (int*)calloc(size, sizeof(int));
    st->covered = (int*)calloc(size, sizeof(int));
    return st;
}

void freeSegmentTree(SegmentTree* st) {
    free(st->count);
    free(st->covered);
    free(st->xs);
    free(st);
}

// modify the segment tree
void modify(SegmentTree* st, int qleft, int qright, int qval, int left,
            int right, int pos) {
    if (st->xs[right + 1] <= qleft || st->xs[left] >= qright) {
        return;
    }
    if (qleft <= st->xs[left] && st->xs[right + 1] <= qright) {
        st->count[pos] += qval;
    } else {
        int mid = (left + right) / 2;
        modify(st, qleft, qright, qval, left, mid, pos * 2 + 1);
        modify(st, qleft, qright, qval, mid + 1, right, pos * 2 + 2);
    }

    if (st->count[pos] > 0) {
        st->covered[pos] = st->xs[right + 1] - st->xs[left];
    } else {
        if (left == right) {
            st->covered[pos] = 0;
        } else {
            st->covered[pos] =
                st->covered[pos * 2 + 1] + st->covered[pos * 2 + 2];
        }
    }
}

// update the segment tree
void updateSegmentTree(SegmentTree* st, int qleft, int qright, int qval) {
    modify(st, qleft, qright, qval, 0, st->n - 1, 0);
}

// query the segment tree
int querySegmentTree(SegmentTree* st) { return st->covered[0]; }

// compare function
int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    return e1->y - e2->y;
}

// compare function
int compareInts(const void* a, const void* b) { return *(int*)a - *(int*)b; }

// binary search - search in double array
int binarySearch(long long* arr, int size, long long target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left - 1;  // return the last position less than targe
}

// remove duplicates
int unique(int* arr, int arrSize) {
    if (arrSize <= 1) {
        return arrSize;
    }
    int j = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    Event* events = (Event*)malloc(sizeof(Event) * squaresSize * 2);
    int* xs = (int*)malloc(sizeof(int) * squaresSize * 4);
    int eventsSize = 0, xsSize = 0;

    // collect all events and x coordinates
    for (int i = 0; i < squaresSize; i++) {
        int x = squares[i][0];
        int y = squares[i][1];
        int l = squares[i][2];
        int xr = x + l;

        xs[xsSize++] = x;
        xs[xsSize++] = xr;
        events[eventsSize++] = (Event){y, 1, x, xr};
        events[eventsSize++] = (Event){y + l, -1, x, xr};
    }

    // sort events by y-coordinate
    qsort(events, eventsSize, sizeof(Event), compareEvents);
    // sort and remove duplicates x-coordinate
    qsort(xs, xsSize, sizeof(int), compareInts);
    xsSize = unique(xs, xsSize);

    // create a segment tree
    SegmentTree* segTree = createSegmentTree(xs, xsSize);

    // save prefix sums and widths
    long long* psum = (long long*)malloc(sizeof(long long) * eventsSize);
    int* widths = (int*)malloc(sizeof(int) * eventsSize);
    long long totalArea = 0LL;
    int prev = events[0].y;
    int pos = 0;

    // scan: calculate total area and record intermediate states
    for (int i = 0; i < eventsSize; i++) {
        int y = events[i].y;
        int delta = events[i].delta;
        int xl = events[i].xl;
        int xr = events[i].xr;

        totalArea += (double)querySegmentTree(segTree) * (y - prev);
        updateSegmentTree(segTree, xl, xr, delta);
        // record prefix sums and widths
        psum[i] = totalArea;
        widths[i] = querySegmentTree(segTree);
        prev = y;
    }

    // calculate the target area (half rounded up)
    long long target = (long long)(totalArea + 1) / 2;
    // find the first position greater than or equal to target using binary
    // search
    int idx = binarySearch(psum, eventsSize, (double)target);
    // get the corresponding area, width, and height
    double area = psum[idx];
    int width = widths[idx];
    int height = events[idx].y;

    double result = height + (totalArea - area * 2) / (width * 2.0);

    // release memory
    free(events);
    free(xs);
    free(psum);
    free(widths);
    freeSegmentTree(segTree);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class SegmentTree {
private:
    vector<int> count;
    vector<int> covered;
    vector<int> xs;
    int n;

    void modify(int qleft, int qright, int qval, int left, int right, int pos) {
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }
        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            if (left == right) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

public:
    SegmentTree(vector<int>& xs_) : xs(xs_) {
        n = xs.size() - 1;
        count.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }

    void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }

    int query() { return covered[0]; }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xsSet;

        for (auto& sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.emplace_back(y, 1, x, xr);
            events.emplace_back(y + l, -1, x, xr);
            xsSet.insert(x);
            xsSet.insert(xr);
        }

        // sort events by y-coordinate
        sort(events.begin(), events.end());
        // discrete coordinates
        vector<int> xs(xsSet.begin(), xsSet.end());
        // initialize the segment tree
        SegmentTree segTree(xs);

        vector<double> psum;
        vector<int> widths;
        double total_area = 0.0;
        int prev = get<0>(events[0]);

        // scan: calculate total area and record intermediate states
        for (auto& [y, delta, xl, xr] : events) {
            int len = segTree.query();
            total_area += 1LL * len * (y - prev);
            segTree.update(xl, xr, delta);
            // record prefix sums and widths
            psum.push_back(total_area);
            widths.push_back(segTree.query());
            prev = y;
        }

        // calculate the target area (half rounded up)
        long long target = (long long)(total_area + 1) / 2;
        // find the first position greater than or equal to target using binary
        // search
        int i =
            lower_bound(psum.begin(), psum.end(), target) - psum.begin() - 1;
        // get the corresponding area, width, and height
        double area = psum[i];
        int width = widths[i], height = get<0>(events[i]);

        return height + (total_area - area * 2) / (width * 2.0);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class SegmentTree {
    private int[] count;
    private int[] covered;
    private int[] xs;
    private int n;

    public SegmentTree(int[] xs_) {
        xs = xs_;
        n = xs.Length - 1;
        count = new int[4 * n];
        covered = new int[4 * n];
    }

    private void Modify(int qleft, int qright, int qval, int left, int right,
                        int pos) {
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }
        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            int mid = (left + right) / 2;
            Modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            Modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            if (left == right) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

    public void Update(int qleft, int qright, int qval) {
        Modify(qleft, qright, qval, 0, n - 1, 0);
    }

    public int Query() {
        return covered[0];
    }
}

public class Solution {
    public double SeparateSquares(int[][] squares) {
        // save events: (y-coordinate, type, left boundary, right boundary)
        List<int[]> events = new List<int[]>();
        SortedSet<int> xsSet = new SortedSet<int>();

        foreach (var sq in squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.Add(new int[] { y, 1, x, xr });
            events.Add(new int[] { y + l, -1, x, xr });
            xsSet.Add(x);
            xsSet.Add(xr);
        }

        // sort events by y-coordinate
        events.Sort((a, b) => a[0].CompareTo(b[0]));
        // discrete coordinates
        int[] xs = xsSet.ToArray();
        // initialize the segment tree
        SegmentTree segTree = new SegmentTree(xs);

        List<long> psum = new List<long>();
        List<int> widths = new List<int>();
        long totalArea = 0;
        int prev = events[0][0];

        // scan: calculate total area and record intermediate states
        foreach (var eventItem in events) {
            int y = eventItem[0], delta = eventItem[1], xl = eventItem[2],
                xr = eventItem[3];
            int len = segTree.Query();
            totalArea += (long)len * (y - prev);
            segTree.Update(xl, xr, delta);
            // record prefix sums and widths
            psum.Add(totalArea);
            widths.Add(segTree.Query());
            prev = y;
        }

        // calculate the target area (half rounded up)
        long target = (totalArea + 1) / 2;
        // find the first position greater than or equal to target using binary
        // search
        int idx = BinarySearch(psum, target);
        // get the corresponding area, width, and height
        double area = psum[idx];
        int width = widths[idx], height = events[idx][0];

        return height + (totalArea - area * 2) / (width * 2.0);
    }

    private int BinarySearch(List<long> list, long target) {
        int left = 0;
        int right = list.Count - 1;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid] < target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type SegmentTree struct {
	count   []int
	covered []int
	xs      []int
	n       int
}

func NewSegmentTree(xs []int) *SegmentTree {
	n := len(xs) - 1
	return &SegmentTree{
		count:   make([]int, 4*n),
		covered: make([]int, 4*n),
		xs:      xs,
		n:       n,
	}
}

func (st *SegmentTree) modify(qleft, qright, qval, left, right, pos int) {
	if st.xs[right+1] <= qleft || st.xs[left] >= qright {
		return
	}
	if qleft <= st.xs[left] && st.xs[right+1] <= qright {
		st.count[pos] += qval
	} else {
		mid := (left + right) / 2
		st.modify(qleft, qright, qval, left, mid, pos*2+1)
		st.modify(qleft, qright, qval, mid+1, right, pos*2+2)
	}

	if st.count[pos] > 0 {
		st.covered[pos] = st.xs[right+1] - st.xs[left]
	} else {
		if left == right {
			st.covered[pos] = 0
		} else {
			st.covered[pos] = st.covered[pos*2+1] + st.covered[pos*2+2]
		}
	}
}

func (st *SegmentTree) Update(qleft, qright, qval int) {
	st.modify(qleft, qright, qval, 0, st.n-1, 0)
}

func (st *SegmentTree) Query() int {
	return st.covered[0]
}

func separateSquares(squares [][]int) float64 {
	// save events: (y-coordinate, type, left boundary, right boundary)
	type Event struct {
		y, delta, xl, xr int
	}
	events := []Event{}
	xsSet := make(map[int]bool)

	for _, sq := range squares {
		x, y, l := sq[0], sq[1], sq[2]
		xr := x + l
		events = append(events, Event{y, 1, x, xr})
		events = append(events, Event{y + l, -1, x, xr})
		xsSet[x] = true
		xsSet[xr] = true
	}

	// sort events by y-coordinate
	sort.Slice(events, func(i, j int) bool {
		return events[i].y < events[j].y
	})

	// discrete coordinates
	xs := make([]int, 0, len(xsSet))
	for x := range xsSet {
		xs = append(xs, x)
	}
	sort.Ints(xs)

	// initialize the segment tree
	segTree := NewSegmentTree(xs)

	psum := []float64{}
	widths := []int{}
	totalArea := 0.0
	prev := events[0].y

	// scan: calculate total area and record intermediate states
	for _, event := range events {
		y, delta, xl, xr := event.y, event.delta, event.xl, event.xr
		length := segTree.Query()
		totalArea += float64(length) * float64(y-prev)
		segTree.Update(xl, xr, delta)
		// record prefix sums and widths
		psum = append(psum, totalArea)
		widths = append(widths, segTree.Query())
		prev = y
	}

	// calculate the target area (half rounded up)
	target := int64(totalArea+1) / 2
	// find the first position greater than or equal to target using binary
	// search
	i := sort.Search(len(psum), func(i int) bool {
		return psum[i] >= float64(target)
	})
	i--

	// get the corresponding area, width, and height
	area := psum[i]
	width := widths[i]
	height := events[i].y

	return float64(height) + (totalArea-area*2)/(float64(width)*2.0)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class SegmentTree {

    private int[] count;
    private int[] covered;
    private int[] xs;
    private int n;

    public SegmentTree(int[] xs_) {
        xs = xs_;
        n = xs.length - 1;
        count = new int[4 * n];
        covered = new int[4 * n];
    }

    private void modify(
        int qleft,
        int qright,
        int qval,
        int left,
        int right,
        int pos
    ) {
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }
        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            if (left == right) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

    public void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }

    public int query() {
        return covered[0];
    }
}

class Solution {

    public double separateSquares(int[][] squares) {
        // save events: (y-coordinate, type, left boundary, right boundary)
        List<int[]> events = new ArrayList<>();
        Set<Integer> xsSet = new TreeSet<>();

        for (int[] sq : squares) {
            int x = sq[0];
            int y = sq[1];
            int l = sq[2];
            int xr = x + l;
            events.add(new int[] { y, 1, x, xr });
            events.add(new int[] { y + l, -1, x, xr });
            xsSet.add(x);
            xsSet.add(xr);
        }

        // sort events by y-coordinate
        events.sort((a, b) -> Integer.compare(a[0], b[0]));
        // discrete coordinates
        int[] xs = xsSet.stream().mapToInt(i -> i).toArray();
        // initialize the segment tree
        SegmentTree segTree = new SegmentTree(xs);

        List<Long> psum = new ArrayList<>();
        List<Integer> widths = new ArrayList<>();
        Long totalArea = 0L;
        int prev = events.get(0)[0];

        // scan: calculate total area and record intermediate states
        for (int[] event : events) {
            int y = event[0];
            int delta = event[1];
            int xl = event[2];
            int xr = event[3];
            int len = segTree.query();
            totalArea += (long) len * (y - prev);
            segTree.update(xl, xr, delta);
            // record prefix sums and widths
            psum.add(totalArea);
            widths.add(segTree.query());
            prev = y;
        }

        // calculate the target area (half rounded up)
        long target = (long) (totalArea + 1) / 2;
        // binary search
        int i = binarySearch(psum, target);
        double area = psum.get(i);
        // get the corresponding area, width, and height
        int width = widths.get(i);
        int height = events.get(i)[0];

        return height + (totalArea - area * 2) / (width * 2.0);
    }

    private int binarySearch(List<Long> list, long target) {
        int left = 0;
        int right = list.size() - 1;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) < target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class SegmentTree {
    constructor(xs) {
        this.xs = xs; // sorted x coordinates
        this.n = xs.length - 1;
        this.count = new Array(4 * this.n).fill(0);
        this.covered = new Array(4 * this.n).fill(0);
    }

    update(qleft, qright, qval, left, right, pos) {
        if (this.xs[right + 1] <= qleft || this.xs[left] >= qright) {
            return; // no overlap
        }
        if (qleft <= this.xs[left] && this.xs[right + 1] <= qright) {
            this.count[pos] += qval;
        } else {
            const mid = Math.floor((left + right) / 2);
            this.update(qleft, qright, qval, left, mid, pos * 2 + 1);
            this.update(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (this.count[pos] > 0) {
            this.covered[pos] = this.xs[right + 1] - this.xs[left];
        } else {
            if (left === right) {
                this.covered[pos] = 0;
            } else {
                this.covered[pos] =
                    this.covered[pos * 2 + 1] + this.covered[pos * 2 + 2];
            }
        }
    }

    query() {
        return this.covered[0];
    }
}

var separateSquares = function (squares) {
    // save events: [y-coordinate, type, left boundary, right boundary]
    const events = [];
    const xsSet = new Set();

    for (const sq of squares) {
        const [x, y, l] = sq;
        const xr = x + l;
        events.push([y, 1, x, xr]);
        events.push([y + l, -1, x, xr]);
        xsSet.add(x);
        xsSet.add(xr);
    }

    // sort events by y-coordinate
    events.sort((a, b) => a[0] - b[0]);
    // discrete coordinates
    const xs = Array.from(xsSet).sort((a, b) => a - b);
    // initialize the segment tree
    const segTree = new SegmentTree(xs);

    const psum = [];
    const widths = [];
    let total_area = 0;
    let prev = events[0][0];

    // scan: calculate total area and record intermediate states
    for (const event of events) {
        const [y, delta, xl, xr] = event;
        const length = segTree.query();
        total_area += length * (y - prev);
        segTree.update(xl, xr, delta, 0, segTree.n - 1, 0);
        // record prefix sums and widths
        psum.push(total_area);
        widths.push(segTree.query());
        prev = y;
    }

    // calculate the target area (half rounded up)
    const target = Math.floor((total_area + 1) / 2);
    // find the first position greater than or equal to target using binary search
    let left = 0,
        right = psum.length - 1;
    let i = 0;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (psum[mid] < target) {
            i = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // get the corresponding area, width, and height
    const area = psum[i];
    const width = widths[i];
    const height = events[i][0];

    return height + (total_area - area * 2) / (width * 2.0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from typing import List
import bisect


class SegmentTree:
    def __init__(self, xs: List[int]):
        self.xs = xs
        self.n = len(xs) - 1
        self.count = [0] * (4 * self.n)
        self.covered = [0] * (4 * self.n)

    def update(self, qleft, qright, qval, left, right, pos):
        if self.xs[right + 1] <= qleft or self.xs[left] >= qright:
            return
        if qleft <= self.xs[left] and self.xs[right + 1] <= qright:
            self.count[pos] += qval
        else:
            mid = (left + right) // 2
            self.update(qleft, qright, qval, left, mid, pos * 2 + 1)
            self.update(qleft, qright, qval, mid + 1, right, pos * 2 + 2)

        if self.count[pos] > 0:
            self.covered[pos] = self.xs[right + 1] - self.xs[left]
        else:
            if left == right:
                self.covered[pos] = 0
            else:
                self.covered[pos] = (
                    self.covered[pos * 2 + 1] + self.covered[pos * 2 + 2]
                )

    def query(self):
        return self.covered[0]


class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        events = []
        xs_set = set()
        for x, y, l in squares:
            events.append((y, 1, x, x + l))
            events.append((y + l, -1, x, x + l))
            xs_set.update([x, x + l])
        xs = sorted(xs_set)

        seg_tree = SegmentTree(xs)
        events.sort()

        psum = []
        widths = []
        total_area = 0.0
        prev_y = events[0][0]

        # scan: calculate total area and record intermediate states
        for y, delta, xl, xr in events:
            length = seg_tree.query()
            total_area += length * (y - prev_y)
            seg_tree.update(xl, xr, delta, 0, seg_tree.n - 1, 0)
            # record prefix sums and widths
            psum.append(total_area)
            widths.append(seg_tree.query())
            prev_y = y

        # calculate the target area (half rounded up)
        target = (total_area + 1) // 2
        # find the first position greater than or equal to target using binary search
        i = bisect.bisect_left(psum, target) - 1
        # get the corresponding area, width, and height
        area = psum[i]
        width = widths[i]
        height = events[i][0]

        return height + (total_area - area * 2) / (width * 2.0)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class SegmentTree {
    private count: number[];
    private covered: number[];
    private xs: number[];
    private n: number;

    constructor(xs: number[]) {
        this.xs = xs; // sorted x coordinates
        this.n = xs.length - 1;
        this.count = new Array(4 * this.n).fill(0);
        this.covered = new Array(4 * this.n).fill(0);
    }

    private modify(
        qleft: number,
        qright: number,
        qval: number,
        left: number,
        right: number,
        pos: number,
    ): void {
        if (this.xs[right + 1] <= qleft || this.xs[left] >= qright) {
            return; // no overlap
        }
        if (qleft <= this.xs[left] && this.xs[right + 1] <= qright) {
            this.count[pos] += qval;
        } else {
            const mid = Math.floor((left + right) / 2);
            this.modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            this.modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (this.count[pos] > 0) {
            this.covered[pos] = this.xs[right + 1] - this.xs[left];
        } else {
            if (left === right) {
                this.covered[pos] = 0;
            } else {
                this.covered[pos] =
                    this.covered[pos * 2 + 1] + this.covered[pos * 2 + 2];
            }
        }
    }

    public update(qleft: number, qright: number, qval: number): void {
        this.modify(qleft, qright, qval, 0, this.n - 1, 0);
    }

    public query(): number {
        return this.covered[0];
    }
}

function separateSquares(squares: number[][]): number {
    // save events: [y-coordinate, type, left boundary, right boundary]
    const events: [number, number, number, number][] = [];
    const xsSet = new Set<number>();

    for (const sq of squares) {
        const [x, y, l] = sq;
        const xr = x + l;
        events.push([y, 1, x, xr]);
        events.push([y + l, -1, x, xr]);
        xsSet.add(x);
        xsSet.add(xr);
    }

    // sort events by y-coordinate
    events.sort((a, b) => a[0] - b[0]);
    // discrete coordinates
    const xs = Array.from(xsSet).sort((a, b) => a - b);
    // initialize the segment tree
    const segTree = new SegmentTree(xs);

    const psum: number[] = [];
    const widths: number[] = [];
    let total_area = 0.0;
    let prev = events[0][0];

    // scan: calculate total area and record intermediate states
    for (const event of events) {
        const [y, delta, xl, xr] = event;
        const length = segTree.query();
        total_area += length * (y - prev);
        segTree.update(xl, xr, delta);
        // record prefix sums and widths
        psum.push(total_area);
        widths.push(segTree.query());
        prev = y;
    }

    // calculate the target area (half rounded up)
    const target = Math.floor((total_area + 1) / 2);
    // find the first position greater than or equal to target using binary search
    let left = 0,
        right = psum.length - 1;
    let i = 0;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (psum[mid] < target) {
            i = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // get the corresponding area, width, and height
    const area = psum[i];
    const width = widths[i];
    const height = events[i][0];

    return height + (total_area - area * 2) / (width * 2.0);
}
```

</details>
