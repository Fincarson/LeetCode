# 3464. Maximize the Distance Between Points on a Square

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/)  
`Array` `Math` `Binary Search` `Geometry` `Sorting`

**Problem Link:** [LeetCode 3464 - Maximize the Distance Between Points on a Square](https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/)

## Problem

You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.

You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.

You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.

Return the maximum possible minimum Manhattan distance between the selected k points.

The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= side <= 109
- 4 <= points.length <= min(4 * side, 15 * 103)
- points[i] == [xi, yi]
- The input is generated such that:

		points[i] lies on the boundary of the square.
		All points[i] are unique.
- 4 <= k <= min(25, points.length)

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Number of Integers to Choose From a Range II](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Points Inside the Square](https://leetcode.com/problems/maximum-points-inside-the-square/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3464. Maximize the Distance Between Points on a Square

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int lower_bound(long long* arr, int size, long long target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int compare(const void* a, const void* b) {
    long long la = *(const long long*)a;
    long long lb = *(const long long*)b;
    return (la > lb) - (la < lb);
}

int check(long long* arr, int size, int side, int k, long long limit) {
    long long perimeter = side * 4LL;

    for (int i = 0; i < size; i++) {
        long long start = arr[i];
        long long end = start + perimeter - limit;
        long long cur = start;

        for (int j = 0; j < k - 1; j++) {
            int idx = lower_bound(arr, size, cur + limit);
            if (idx == size || arr[idx] > end) {
                cur = -1;
                break;
            }
            cur = arr[idx];
        }

        if (cur >= 0) {
            return 1;
        }
    }
    return 0;
}

int maxDistance(int side, int** points, int pointsSize, int* pointsColSize,
                int k) {
    long long* arr = (long long*)malloc(pointsSize * sizeof(long long));

    for (int i = 0; i < pointsSize; i++) {
        int x = points[i][0], y = points[i][1];
        if (x == 0) {
            arr[i] = y;
        } else if (y == side) {
            arr[i] = side + (long long)x;
        } else if (x == side) {
            arr[i] = side * 3LL - y;
        } else {
            arr[i] = side * 4LL - x;
        }
    }

    qsort(arr, pointsSize, sizeof(long long), compare);

    long long lo = 1, hi = side;
    int ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (check(arr, pointsSize, side, k, mid)) {
            lo = mid + 1;
            ans = (int)mid;
        } else {
            hi = mid - 1;
        }
    }

    free(arr);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) {
                arr.push_back(y);
            } else if (y == side) {
                arr.push_back(side + x);
            } else if (x == side) {
                arr.push_back(side * 3LL - y);
            } else {
                arr.push_back(side * 4LL - x);
            }
        }
        sort(arr.begin(), arr.end());

        auto check = [&](long long limit) -> bool {
            for (long long start : arr) {
                long long end = start + side * 4LL - limit;
                long long cur = start;
                for (int i = 0; i < k - 1; i++) {
                    auto it = ranges::lower_bound(arr, cur + limit);
                    if (it == arr.end() || *it > end) {
                        cur = -1;
                        break;
                    }
                    cur = *it;
                }
                if (cur >= 0) {
                    return true;
                }
            }
            return false;
        };

        long long lo = 1, hi = side;
        int ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (check(mid)) {
                lo = mid + 1;
                ans = mid;
            } else {
                hi = mid - 1;
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
    public int MaxDistance(int side, int[][] points, int k) {
        List<long> arr = new List<long>();

        foreach (var p in points) {
            int x = p[0], y = p[1];
            if (x == 0) {
                arr.Add(y);
            } else if (y == side) {
                arr.Add(side + (long)x);
            } else if (x == side) {
                arr.Add(side * 3L - y);
            } else {
                arr.Add(side * 4L - x);
            }
        }
        arr.Sort();

        long lo = 1, hi = side;
        int ans = 0;

        while (lo <= hi) {
            long mid = (lo + hi) / 2;
            if (Check(arr, side, k, mid)) {
                lo = mid + 1;
                ans = (int)mid;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    private bool Check(List<long> arr, int side, int k, long limit) {
        long perimeter = side * 4L;

        foreach (long start in arr) {
            long end = start + perimeter - limit;
            long cur = start;

            for (int i = 0; i < k - 1; i++) {
                int idx = LowerBound(arr, cur + limit);
                if (idx == arr.Count || arr[idx] > end) {
                    cur = -1;
                    break;
                }
                cur = arr[idx];
            }

            if (cur >= 0) {
                return true;
            }
        }
        return false;
    }

    private int LowerBound(List<long> arr, long target) {
        int left = 0, right = arr.Count;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDistance(side int, points [][]int, k int) int {
	arr := make([]int64, 0, len(points))

	for _, p := range points {
		x, y := p[0], p[1]
		if x == 0 {
			arr = append(arr, int64(y))
		} else if y == side {
			arr = append(arr, int64(side+x))
		} else if x == side {
			arr = append(arr, int64(side*3-y))
		} else {
			arr = append(arr, int64(side*4-x))
		}
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i] < arr[j] })

	lo, hi := int64(1), int64(side)
	ans := 0
	for lo <= hi {
		mid := (lo + hi) / 2
		if check(arr, int64(side), k, mid) {
			lo = mid + 1
			ans = int(mid)
		} else {
			hi = mid - 1
		}
	}
	return ans
}

func check(arr []int64, side int64, k int, limit int64) bool {
	perimeter := side * 4

	for _, start := range arr {
		end := start + perimeter - limit
		cur := start

		for i := 0; i < k-1; i++ {
			idx := lowerBound(arr, cur+limit)
			if idx == len(arr) || arr[idx] > end {
				cur = -1
				break
			}
			cur = arr[idx]
		}

		if cur >= 0 {
			return true
		}
	}
	return false
}

func lowerBound(arr []int64, target int64) int {
	left, right := 0, len(arr)
	for left < right {
		mid := left + (right-left)/2
		if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxDistance(int side, int[][] points, int k) {
        List<Long> arr = new ArrayList<>();

        for (int[] p : points) {
            int x = p[0];
            int y = p[1];
            if (x == 0) {
                arr.add((long) y);
            } else if (y == side) {
                arr.add((long) side + x);
            } else if (x == side) {
                arr.add(side * 3L - y);
            } else {
                arr.add(side * 4L - x);
            }
        }
        Collections.sort(arr);

        long lo = 1;
        long hi = side;
        int ans = 0;

        while (lo <= hi) {
            long mid = (lo + hi) / 2;
            if (check(arr, side, k, mid)) {
                lo = mid + 1;
                ans = (int) mid;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    private boolean check(List<Long> arr, int side, int k, long limit) {
        long perimeter = side * 4L;

        for (long start : arr) {
            long end = start + perimeter - limit;
            long cur = start;

            for (int i = 0; i < k - 1; i++) {
                int idx = lowerBound(arr, cur + limit);
                if (idx == arr.size() || arr.get(idx) > end) {
                    cur = -1;
                    break;
                }
                cur = arr.get(idx);
            }

            if (cur >= 0) {
                return true;
            }
        }
        return false;
    }

    private int lowerBound(List<Long> arr, long target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDistance = function (side, points, k) {
    const arr = [];

    for (const [x, y] of points) {
        if (x === 0) {
            arr.push(y);
        } else if (y === side) {
            arr.push(side + x);
        } else if (x === side) {
            arr.push(side * 3 - y);
        } else {
            arr.push(side * 4 - x);
        }
    }

    arr.sort((a, b) => a - b);

    const lowerBound = (target) => {
        let left = 0,
            right = arr.length;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    };

    const check = (limit) => {
        const perimeter = side * 4;
        for (const start of arr) {
            const end = start + perimeter - limit;
            let cur = start;
            for (let i = 0; i < k - 1; i++) {
                const idx = lowerBound(cur + limit);
                if (idx === arr.length || arr[idx] > end) {
                    cur = -1;
                    break;
                }
                cur = arr[idx];
            }
            if (cur >= 0) return true;
        }
        return false;
    };

    let lo = 1,
        hi = side;
    let ans = 0;

    while (lo <= hi) {
        const mid = Math.floor((lo + hi) / 2);
        if (check(mid)) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
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
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        arr = []
        
        for x, y in points:
            if x == 0:
                arr.append(y)
            elif y == side:
                arr.append(side + x)
            elif x == side:
                arr.append(side * 3 - y)
            else:
                arr.append(side * 4 - x)
        
        arr.sort()
        
        def check(limit: int) -> bool:
            perimeter = side * 4
            for start in arr:
                end = start + perimeter - limit
                cur = start
                for _ in range(k - 1):
                    idx = bisect_left(arr, cur + limit)
                    if idx == len(arr) or arr[idx] > end:
                        cur = -1
                        break
                    cur = arr[idx]
                if cur >= 0:
                    return True
            return False
        
        lo, hi = 1, side
        ans = 0
        
        while lo <= hi:
            mid = (lo + hi) // 2
            if check(mid):
                lo = mid + 1
                ans = mid
            else:
                hi = mid - 1
                
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDistance(side: number, points: number[][], k: number): number {
    const arr: number[] = [];

    for (const [x, y] of points) {
        if (x === 0) {
            arr.push(y);
        } else if (y === side) {
            arr.push(side + x);
        } else if (x === side) {
            arr.push(side * 3 - y);
        } else {
            arr.push(side * 4 - x);
        }
    }

    arr.sort((a, b) => a - b);

    const lowerBound = (target: number): number => {
        let left = 0,
            right = arr.length;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    };

    const check = (limit: number): boolean => {
        const perimeter = side * 4;
        for (const start of arr) {
            const end = start + perimeter - limit;
            let cur = start;
            for (let i = 0; i < k - 1; i++) {
                const idx = lowerBound(cur + limit);
                if (idx === arr.length || arr[idx] > end) {
                    cur = -1;
                    break;
                }
                cur = arr[idx];
            }
            if (cur >= 0) return true;
        }
        return false;
    };

    let lo = 1,
        hi = side;
    let ans = 0;

    while (lo <= hi) {
        const mid = Math.floor((lo + hi) / 2);
        if (check(mid)) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
        }
    }

    return ans;
}
```

</details>
