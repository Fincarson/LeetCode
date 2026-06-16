# 2943. Maximize Area of Square Hole in Grid

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 2943 - Maximize Area of Square Hole in Grid](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/)

## Problem

You are given the two integers, n and m and two integer arrays, hBars and vBars. The grid has n + 2 horizontal and m + 2 vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.

You can remove some of the bars in hBars from horizontal bars and some of the bars in vBars from vertical bars. Note that other bars are fixed and cannot be removed.

Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n <= 109
- 1 <= m <= 109
- 1 <= hBars.length <= 100
- 2 <= hBars[i] <= n + 1
- 1 <= vBars.length <= 100
- 2 <= vBars[i] <= m + 1
- All values in hBars are distinct.
- All values in vBars are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximal Square](https://leetcode.com/problems/maximal-square/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Square Area by Removing Fences From a Field](https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2943. Maximize Area of Square Hole in Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars,
                           int vBarsSize) {
    qsort(hBars, hBarsSize, sizeof(int), compare);
    qsort(vBars, vBarsSize, sizeof(int), compare);
    int hmax = 1, vmax = 1;
    int hcur = 1, vcur = 1;
    for (int i = 1; i < hBarsSize; i++) {
        if (hBars[i] == hBars[i - 1] + 1) {
            hcur++;
        } else {
            hcur = 1;
        }
        hmax = fmax(hmax, hcur);
    }
    for (int i = 1; i < vBarsSize; i++) {
        if (vBars[i] == vBars[i - 1] + 1) {
            vcur++;
        } else {
            vcur = 1;
        }
        vmax = fmax(vmax, vcur);
    }
    int side = fmin(hmax, vmax) + 1;
    return side * side;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hmax = 1, vmax = 1;
        int hcur = 1, vcur = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hcur++;
            } else {
                hcur = 1;
            }
            hmax = max(hmax, hcur);
        }
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                vcur++;
            } else {
                vcur = 1;
            }
            vmax = max(vmax, vcur);
        }
        int side = min(hmax, vmax) + 1;
        return side * side;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Array.Sort(hBars);
        Array.Sort(vBars);
        int hmax = 1, vmax = 1;
        int hcur = 1, vcur = 1;
        for (int i = 1; i < hBars.Length; i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hcur++;
            } else {
                hcur = 1;
            }
            hmax = Math.Max(hmax, hcur);
        }
        for (int i = 1; i < vBars.Length; i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                vcur++;
            } else {
                vcur = 1;
            }
            vmax = Math.Max(vmax, vcur);
        }
        int side = Math.Min(hmax, vmax) + 1;
        return side * side;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximizeSquareHoleArea(n int, m int, hBars []int, vBars []int) int {
	sort.Ints(hBars)
	sort.Ints(vBars)
	hmax, vmax := 1, 1
	hcur, vcur := 1, 1
	for i := 1; i < len(hBars); i++ {
		if hBars[i] == hBars[i-1]+1 {
			hcur++
		} else {
			hcur = 1
		}
		hmax = max(hmax, hcur)
	}
	for i := 1; i < len(vBars); i++ {
		if vBars[i] == vBars[i-1]+1 {
			vcur++
		} else {
			vcur = 1
		}
		vmax = max(vmax, vcur)
	}
	side := min(hmax, vmax) + 1
	return side * side
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Arrays.sort(hBars);
        Arrays.sort(vBars);
        int hmax = 1;
        int vmax = 1;
        int hcur = 1;
        int vcur = 1;
        for (int i = 1; i < hBars.length; i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hcur++;
            } else {
                hcur = 1;
            }
            hmax = Math.max(hmax, hcur);
        }
        for (int i = 1; i < vBars.length; i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                vcur++;
            } else {
                vcur = 1;
            }
            vmax = Math.max(vmax, vcur);
        }
        int side = Math.min(hmax, vmax) + 1;
        return side * side;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function maximizeSquareHoleArea(n, m, hBars, vBars) {
    hBars.sort((a, b) => a - b);
    vBars.sort((a, b) => a - b);
    let hmax = 1,
        vmax = 1;
    let hcur = 1,
        vcur = 1;
    for (let i = 1; i < hBars.length; i++) {
        if (hBars[i] === hBars[i - 1] + 1) {
            hcur++;
        } else {
            hcur = 1;
        }
        hmax = Math.max(hmax, hcur);
    }
    for (let i = 1; i < vBars.length; i++) {
        if (vBars[i] === vBars[i - 1] + 1) {
            vcur++;
        } else {
            vcur = 1;
        }
        vmax = Math.max(vmax, vcur);
    }
    const side = Math.min(hmax, vmax) + 1;
    return side * side;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximizeSquareHoleArea(
        self, n: int, m: int, hBars: List[int], vBars: List[int]
    ) -> int:
        hBars.sort()
        vBars.sort()
        hmax, vmax = 1, 1
        hcur, vcur = 1, 1
        for i in range(1, len(hBars)):
            if hBars[i] == hBars[i - 1] + 1:
                hcur += 1
            else:
                hcur = 1
            hmax = max(hmax, hcur)
        for i in range(1, len(vBars)):
            if vBars[i] == vBars[i - 1] + 1:
                vcur += 1
            else:
                vcur = 1
            vmax = max(vmax, vcur)
        side = min(hmax, vmax) + 1
        return side * side
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximizeSquareHoleArea(
    n: number,
    m: number,
    hBars: number[],
    vBars: number[],
): number {
    hBars.sort((a, b) => a - b);
    vBars.sort((a, b) => a - b);
    let hmax = 1,
        vmax = 1;
    let hcur = 1,
        vcur = 1;
    for (let i = 1; i < hBars.length; i++) {
        if (hBars[i] === hBars[i - 1] + 1) {
            hcur++;
        } else {
            hcur = 1;
        }
        hmax = Math.max(hmax, hcur);
    }
    for (let i = 1; i < vBars.length; i++) {
        if (vBars[i] === vBars[i - 1] + 1) {
            vcur++;
        } else {
            vcur = 1;
        }
        vmax = Math.max(vmax, vcur);
    }
    const side = Math.min(hmax, vmax) + 1;
    return side * side;
}
```

</details>
