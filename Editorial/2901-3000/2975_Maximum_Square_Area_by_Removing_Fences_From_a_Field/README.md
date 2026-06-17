# 2975. Maximum Square Area by Removing Fences From a Field

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/)  
`Array` `Hash Table` `Enumeration`

**Problem Link:** [LeetCode 2975 - Maximum Square Area by Removing Fences From a Field](https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/)

## Problem

There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.

Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).

Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.

Since the answer may be large, return it modulo 109 + 7.

Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.

### Example 1

```text
Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
Output: 4
Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
```

### Example 2

```text
Input: m = 6, n = 7, hFences = [2], vFences = [4]
Output: -1
Explanation: It can be proved that there is no way to create a square field by removing fences.
```

## Constraints

- 3 <= m, n <= 109
- 1 <= hFences.length, vFences.length <= 600
- 1 < hFences[i] < m
- 1 < vFences[i] < n
- hFences and vFences are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximize Area of Square Hole in Grid](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2975. Maximum Square Area by Removing Fences From a Field

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
static int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

static int* getEdges(int* fences, int fencesSize, int border, int* outSize) {
    int arrSize = fencesSize + 2;
    int* arr = (int*)malloc(sizeof(int) * arrSize);
    memcpy(arr, fences, sizeof(int) * fencesSize);
    arr[fencesSize] = 1;
    arr[fencesSize + 1] = border;
    qsort(arr, arrSize, sizeof(int), compare);

    int maxEdges = arrSize * (arrSize - 1) / 2;
    int* edges = (int*)malloc(sizeof(int) * maxEdges);
    int idx = 0;
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            edges[idx++] = arr[j] - arr[i];
        }
    }
    free(arr);
    qsort(edges, idx, sizeof(int), compare);

    int k = 0;
    for (int i = 0; i < idx; i++) {
        if (i == 0 || edges[i] != edges[i - 1]) {
            edges[k++] = edges[i];
        }
    }
    *outSize = k;
    return edges;
}

int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize,
                       int* vFences, int vFencesSize) {
    int hSize = 0, vSize = 0;
    int* hEdges = getEdges(hFences, hFencesSize, m, &hSize);
    int* vEdges = getEdges(vFences, vFencesSize, n, &vSize);

    int i = 0, j = 0;
    int res = 0;
    while (i < hSize && j < vSize) {
        if (hEdges[i] == vEdges[j]) {
            if (hEdges[i] > res) res = hEdges[i];
            i++;
            j++;
        } else if (hEdges[i] < vEdges[j]) {
            i++;
        } else {
            j++;
        }
    }

    free(hEdges);
    free(vEdges);

    if (res == 0) return -1;
    long long ans = (long long)res * res % 1000000007;
    return (int)ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    unordered_set<int> getEdges(vector<int>& fences, int border) {
        unordered_set<int> st;
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(), fences.end());
        for (int i = 0; i < fences.size(); i++) {
            for (int j = i + 1; j < fences.size(); j++) {
                st.insert(fences[j] - fences[i]);
            }
        }
        return st;
    }

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        auto hEdges = getEdges(hFences, m);
        auto vEdges = getEdges(vFences, n);
        int res = 0;
        for (auto e : hEdges) {
            if (vEdges.contains(e)) {
                res = max(res, e);
            }
        }
        if (res == 0) {
            res = -1;
        } else {
            res = 1ll * res * res % 1000000007;
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        var hEdges = GetEdges(hFences, m);
        var vEdges = GetEdges(vFences, n);

        long res = 0;
        foreach (int e in hEdges) {
            if (vEdges.Contains(e)) {
                res = Math.Max(res, e);
            }
        }

        if (res == 0) {
            return -1;
        } else {
            return (int)((res * res) % 1000000007);
        }
    }

    private HashSet<int> GetEdges(int[] fences, int border) {
        var set = new HashSet<int>();
        var list = new List<int>(fences);

        list.Add(1);
        list.Add(border);
        list.Sort();
        for (int i = 0; i < list.Count; i++) {
            for (int j = i + 1; j < list.Count; j++) {
                set.Add(list[j] - list[i]);
            }
        }

        return set;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximizeSquareArea(m int, n int, hFences []int, vFences []int) int {
	hEdges := getEdges(hFences, m)
	vEdges := getEdges(vFences, n)

	var res int64 = 0
	for e := range hEdges {
		if _, exists := vEdges[e]; exists {
			if int64(e) > res {
				res = int64(e)
			}
		}
	}

	if res == 0 {
		return -1
	}
	return int((res * res) % 1000000007)
}

func getEdges(fences []int, border int) map[int]bool {
	set := make(map[int]bool)
	list := make([]int, len(fences))

	copy(list, fences)
	list = append(list, 1, border)
	sort.Ints(list)

	for i := 0; i < len(list); i++ {
		for j := i + 1; j < len(list); j++ {
			set[list[j]-list[i]] = true
		}
	}

	return set
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        Set<Integer> hEdges = getEdges(hFences, m);
        Set<Integer> vEdges = getEdges(vFences, n);

        long res = 0;
        for (int e : hEdges) {
            if (vEdges.contains(e)) {
                res = Math.max(res, e);
            }
        }

        if (res == 0) {
            return -1;
        } else {
            return (int) ((res * res) % 1000000007);
        }
    }

    private Set<Integer> getEdges(int[] fences, int border) {
        Set<Integer> set = new HashSet<>();
        List<Integer> list = new ArrayList<>();

        for (int fence : fences) {
            list.add(fence);
        }

        list.add(1);
        list.add(border);
        Collections.sort(list);

        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                set.add(list.get(j) - list.get(i));
            }
        }

        return set;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximizeSquareArea = function (m, n, hFences, vFences) {
    const MOD = 1000000007;

    const getEdges = (fences, border) => {
        const set = new Set();
        const list = [...fences];
        list.push(1);
        list.push(border);
        list.sort((a, b) => a - b);

        for (let i = 0; i < list.length; i++) {
            for (let j = i + 1; j < list.length; j++) {
                set.add(list[j] - list[i]);
            }
        }

        return set;
    };

    const hEdges = getEdges(hFences, m);
    const vEdges = getEdges(vFences, n);

    let res = 0;
    for (const e of hEdges) {
        if (vEdges.has(e)) {
            res = Math.max(res, e);
        }
    }

    if (res === 0) {
        return -1;
    }

    return Number((BigInt(res) * BigInt(res)) % BigInt(MOD));
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def get_edges(self, fences: List[int], border: int) -> set:
        points = sorted([1] + fences + [border])
        return {
            points[j] - points[i]
            for i in range(len(points))
            for j in range(i + 1, len(points))
        }

    def maximizeSquareArea(
        self, m: int, n: int, hFences: List[int], vFences: List[int]
    ) -> int:
        MOD = 10**9 + 7
        h_edges = self.get_edges(hFences, m)
        v_edges = self.get_edges(vFences, n)

        max_edge = max(h_edges & v_edges, default=0)
        return (max_edge * max_edge) % MOD if max_edge else -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximizeSquareArea(
    m: number,
    n: number,
    hFences: number[],
    vFences: number[],
): number {
    const MOD = 1000000007;

    const getEdges = (fences: number[], border: number): Set<number> => {
        const set = new Set<number>();
        const list = [...fences];

        list.push(1);
        list.push(border);
        list.sort((a, b) => a - b);

        for (let i = 0; i < list.length; i++) {
            for (let j = i + 1; j < list.length; j++) {
                set.add(list[j] - list[i]);
            }
        }

        return set;
    };

    const hEdges = getEdges(hFences, m);
    const vEdges = getEdges(vFences, n);

    let res = 0;
    for (const e of hEdges) {
        if (vEdges.has(e)) {
            res = Math.max(res, e);
        }
    }

    if (res === 0) {
        return -1;
    }

    return Number((BigInt(res) * BigInt(res)) % BigInt(MOD));
}
```

</details>
