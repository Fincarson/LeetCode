# 1931. Painting a Grid With Three Different Colors

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/painting-a-grid-with-three-different-colors/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 1931 - Painting a Grid With Three Different Colors](https://leetcode.com/problems/painting-a-grid-with-three-different-colors/)

## Problem

You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

### Example 1

```text
Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.
```

### Example 2

```text
Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.
```

### Example 3

```text
Input: m = 5, n = 5
Output: 580986
```

## Constraints

- 1 <= m <= 5
- 1 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Ways to Paint N × 3 Grid](https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1931. Painting a Grid With Three Different Colors

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: State Compression Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: State Compression Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

struct ListNode *createListNode(int val) {
    struct ListNode *obj = (struct ListNode *)malloc(sizeof(struct ListNode));
    obj->val = val;
    obj->next = NULL;
    return obj;
}

void freeList(struct ListNode *list) {
    while (list) {
        struct ListNode *p = list;
        list = list->next;
        free(p);
    }
}

typedef struct {
    int key;
    struct ListNode *val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    HashItem *pEntry = hashFindItem(obj, key);
    struct ListNode *p = createListNode(val);
    if (!pEntry) {
        pEntry = (HashItem *)malloc(sizeof(HashItem));
        pEntry->key = key;
        pEntry->val = p;
        HASH_ADD_INT(*obj, key, pEntry);
    } else {
        p->next = pEntry->val;
        pEntry->val = p;
    }
    return true;
}

bool hashSetItem(HashItem **obj, int key, struct ListNode *list) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        pEntry = (HashItem *)malloc(sizeof(HashItem));
        pEntry->key = key;
        pEntry->val = list;
        HASH_ADD_INT(*obj, key, pEntry);
    } else {
        freeList(pEntry->val);
        pEntry->val = list;
    }
    return true;
}

struct ListNode *hashGetItem(HashItem **obj, int key) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return NULL;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        freeList(curr->val);
        free(curr);
    }
}

// Main function
int colorTheGrid(int m, int n) {
    // Hash mapping stores all valid coloration schemes for a single row that
    // meet the requirements The key represents mask, and the value represents
    // the ternary string of mask (stored as a list)
    HashItem *valid = NULL;
    // Enumerate masks that meet the requirements within the range [0, 3^m)
    int mask_end = pow(3, m);
    for (int mask = 0; mask < mask_end; ++mask) {
        int mm = mask;
        int color[m];
        for (int i = 0; i < m; ++i) {
            color[i] = mm % 3;
            mm /= 3;
        }
        bool check = true;
        for (int i = 0; i < m - 1; ++i) {
            if (color[i] == color[i + 1]) {
                check = false;
                break;
            }
        }
        if (check) {
            for (int i = 0; i < m; i++) {
                hashAddItem(&valid, mask, color[i]);
            }
        }
    }

    // Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and mask2
    // When adjacent rows, the colors of the two cells in the same column are
    // different
    HashItem *adjacent = NULL;
    for (HashItem *pEntry1 = valid; pEntry1; pEntry1 = pEntry1->hh.next) {
        int mask1 = pEntry1->key;
        for (HashItem *pEntry2 = valid; pEntry2; pEntry2 = pEntry2->hh.next) {
            int mask2 = pEntry2->key;
            bool check = true;
            for (struct ListNode *p1 = pEntry1->val, *p2 = pEntry2->val;
                 p1 && p2; p1 = p1->next, p2 = p2->next) {
                if (p1->val == p2->val) {
                    check = false;
                    break;
                }
            }
            if (check) {
                hashAddItem(&adjacent, mask1, mask2);
            }
        }
    }

    int f[mask_end];
    memset(f, 0, sizeof(f));
    for (HashItem *pEntry = valid; pEntry; pEntry = pEntry->hh.next) {
        int mask = pEntry->key;
        f[mask] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int g[mask_end];
        memset(g, 0, sizeof(g));
        for (HashItem *pEntry1 = valid; pEntry1; pEntry1 = pEntry1->hh.next) {
            int mask2 = pEntry1->key;
            for (struct ListNode *p = hashGetItem(&adjacent, mask2); p != NULL;
                 p = p->next) {
                int mask1 = p->val;
                g[mask2] += f[mask1];
                if (g[mask2] >= MOD) {
                    g[mask2] -= MOD;
                }
            }
        }
        memcpy(f, g, sizeof(f));
    }

    int ans = 0;
    for (int i = 0; i < mask_end; i++) {
        ans += f[i];
        if (ans >= MOD) {
            ans -= MOD;
        }
    }
    hashFree(&valid);
    hashFree(&adjacent);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int colorTheGrid(int m, int n) {
        // Hash mapping stores all valid coloration schemes for a single row
        // that meet the requirements The key represents mask, and the value
        // represents the ternary string of mask (stored as a list)
        unordered_map<int, vector<int>> valid;

        // Enumerate masks that meet the requirements within the range [0, 3^m)
        int mask_end = pow(3, m);
        for (int mask = 0; mask < mask_end; ++mask) {
            vector<int> color;
            int mm = mask;
            for (int i = 0; i < m; ++i) {
                color.push_back(mm % 3);
                mm /= 3;
            }
            bool check = true;
            for (int i = 0; i < m - 1; ++i) {
                if (color[i] == color[i + 1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                valid[mask] = move(color);
            }
        }

        // Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and
        // mask2 When adjacent rows, the colors of the two cells in the same
        // column are different
        unordered_map<int, vector<int>> adjacent;
        for (const auto& [mask1, color1] : valid) {
            for (const auto& [mask2, color2] : valid) {
                bool check = true;
                for (int i = 0; i < m; ++i) {
                    if (color1[i] == color2[i]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    adjacent[mask1].push_back(mask2);
                }
            }
        }

        vector<int> f(mask_end);
        for (const auto& [mask, _] : valid) {
            f[mask] = 1;
        }
        for (int i = 1; i < n; ++i) {
            vector<int> g(mask_end);
            for (const auto& [mask2, _] : valid) {
                for (int mask1 : adjacent[mask2]) {
                    g[mask2] += f[mask1];
                    if (g[mask2] >= mod) {
                        g[mask2] -= mod;
                    }
                }
            }
            f = move(g);
        }

        int ans = 0;
        for (int num : f) {
            ans += num;
            if (ans >= mod) {
                ans -= mod;
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
    private const int mod = 1000000007;

    public int ColorTheGrid(int m, int n) {
        // Hash mapping stores all valid coloration schemes for a single row
        // that meet the requirements
        var valid = new Dictionary<int, List<int>>();
        // Enumerate masks that meet the requirements within the range [0, 3^m)
        int maskEnd = (int)Math.Pow(3, m);
        for (int mask = 0; mask < maskEnd; ++mask) {
            var color = new List<int>();
            int mm = mask;
            for (int i = 0; i < m; ++i) {
                color.Add(mm % 3);
                mm /= 3;
            }
            bool check = true;
            for (int i = 0; i < m - 1; ++i) {
                if (color[i] == color[i + 1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                valid[mask] = color;
            }
        }

        // Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and
        // mask2 When adjacent rows, the colors of the two cells in the same
        // column are different
        var adjacent = new Dictionary<int, List<int>>();
        foreach (var mask1 in valid.Keys) {
            foreach (var mask2 in valid.Keys) {
                bool check = true;
                for (int i = 0; i < m; ++i) {
                    if (valid[mask1][i] == valid[mask2][i]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    if (!adjacent.ContainsKey(mask1)) {
                        adjacent[mask1] = new List<int>();
                    }
                    adjacent[mask1].Add(mask2);
                }
            }
        }

        var f = new Dictionary<int, int>();
        foreach (var mask in valid.Keys) {
            f[mask] = 1;
        }
        for (int i = 1; i < n; ++i) {
            var g = new Dictionary<int, int>();
            foreach (var mask2 in valid.Keys) {
                if (adjacent.ContainsKey(mask2)) {
                    foreach (var mask1 in adjacent[mask2]) {
                        if (!g.ContainsKey(mask2)) {
                            g[mask2] = 0;
                        }
                        g[mask2] = (g[mask2] + f[mask1]) % mod;
                    }
                }
            }
            f = g;
        }

        int ans = 0;
        foreach (var num in f.Values) {
            ans = (ans + num) % mod;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const mod = 1000000007

func colorTheGrid(m int, n int) int {
	// Hash mapping stores all valid coloration schemes for a single row that
	// meet the requirements
	valid := make(map[int][]int)

	// Enumerate masks that meet the requirements within the range [0, 3^m)
	maskEnd := int(math.Pow(3, float64(m)))
	for mask := 0; mask < maskEnd; mask++ {
		color := make([]int, m)
		mm := mask
		for i := 0; i < m; i++ {
			color[i] = mm % 3
			mm /= 3
		}
		check := true
		for i := 0; i < m-1; i++ {
			if color[i] == color[i+1] {
				check = false
				break
			}
		}
		if check {
			valid[mask] = color
		}
	}

	// Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and mask2
	// When adjacent rows, the colors of the two cells in the same column are
	// different
	adjacent := make(map[int][]int)
	for mask1 := range valid {
		for mask2 := range valid {
			check := true
			for i := 0; i < m; i++ {
				if valid[mask1][i] == valid[mask2][i] {
					check = false
					break
				}
			}
			if check {
				adjacent[mask1] = append(adjacent[mask1], mask2)
			}
		}
	}

	f := make(map[int]int)
	for mask := range valid {
		f[mask] = 1
	}
	for i := 1; i < n; i++ {
		g := make(map[int]int)
		for mask2 := range valid {
			for _, mask1 := range adjacent[mask2] {
				g[mask2] = (g[mask2] + f[mask1]) % mod
			}
		}
		f = g
	}

	ans := 0
	for _, num := range f {
		ans = (ans + num) % mod
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    static final int mod = 1000000007;

    public int colorTheGrid(int m, int n) {
        // Hash mapping stores all valid coloration schemes for a single row that meet the requirements
        Map<Integer, List<Integer>> valid = new HashMap<>();
        // Enumerate masks that meet the requirements within the range [0, 3^m)
        int maskEnd = (int) Math.pow(3, m);
        for (int mask = 0; mask < maskEnd; ++mask) {
            List<Integer> color = new ArrayList<>();
            int mm = mask;
            for (int i = 0; i < m; ++i) {
                color.add(mm % 3);
                mm /= 3;
            }
            boolean check = true;
            for (int i = 0; i < m - 1; ++i) {
                if (color.get(i).equals(color.get(i + 1))) {
                    check = false;
                    break;
                }
            }
            if (check) {
                valid.put(mask, color);
            }
        }

        // Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and mask2 When adjacent rows, the colors of the two cells in the same column are different
        Map<Integer, List<Integer>> adjacent = new HashMap<>();
        for (int mask1 : valid.keySet()) {
            for (int mask2 : valid.keySet()) {
                boolean check = true;
                for (int i = 0; i < m; ++i) {
                    if (
                        valid.get(mask1).get(i).equals(valid.get(mask2).get(i))
                    ) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    adjacent
                        .computeIfAbsent(mask1, k -> new ArrayList<>())
                        .add(mask2);
                }
            }
        }

        Map<Integer, Integer> f = new HashMap<>();
        for (int mask : valid.keySet()) {
            f.put(mask, 1);
        }
        for (int i = 1; i < n; ++i) {
            Map<Integer, Integer> g = new HashMap<>();
            for (int mask2 : valid.keySet()) {
                for (int mask1 : adjacent.getOrDefault(
                    mask2,
                    new ArrayList<>()
                )) {
                    g.put(
                        mask2,
                        (g.getOrDefault(mask2, 0) + f.getOrDefault(mask1, 0)) %
                        mod
                    );
                }
            }
            f = g;
        }

        int ans = 0;
        for (int num : f.values()) {
            ans = (ans + num) % mod;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var colorTheGrid = function (m, n) {
    const mod = 1000000007;
    // Hash mapping stores all valid coloration schemes for a single row that meet the requirements
    const valid = new Map();
    // Enumerate masks that meet the requirements within the range [0, 3^m)
    const maskEnd = Math.pow(3, m);
    for (let mask = 0; mask < maskEnd; ++mask) {
        const color = [];
        let mm = mask;
        for (let i = 0; i < m; ++i) {
            color.push(mm % 3);
            mm = Math.floor(mm / 3);
        }
        let check = true;
        for (let i = 0; i < m - 1; ++i) {
            if (color[i] === color[i + 1]) {
                check = false;
                break;
            }
        }
        if (check) {
            valid.set(mask, color);
        }
    }

    // Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and mask2 When adjacent rows, the colors of the two cells in the same column are different
    const adjacent = new Map();
    for (const [mask1, color1] of valid.entries()) {
        for (const [mask2, color2] of valid.entries()) {
            let check = true;
            for (let i = 0; i < m; ++i) {
                if (color1[i] === color2[i]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                if (!adjacent.has(mask1)) {
                    adjacent.set(mask1, []);
                }
                adjacent.get(mask1).push(mask2);
            }
        }
    }

    let f = new Map();
    for (const [mask, _] of valid.entries()) {
        f.set(mask, 1);
    }
    for (let i = 1; i < n; ++i) {
        const g = new Map();
        for (const [mask2, _] of valid.entries()) {
            for (const mask1 of adjacent.get(mask2) || []) {
                g.set(mask2, ((g.get(mask2) || 0) + f.get(mask1)) % mod);
            }
        }
        f = g;
    }

    let ans = 0;
    for (const num of f.values()) {
        ans = (ans + num) % mod;
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        mod = 10**9 + 7
        # Hash mapping stores all valid coloration schemes for a single row that meet the requirements
        # The key represents mask, and the value represents the ternary string of mask (stored as a list)
        valid = dict()

        # Enumerate masks that meet the requirements within the range [0, 3^m)
        for mask in range(3**m):
            color = list()
            mm = mask
            for i in range(m):
                color.append(mm % 3)
                mm //= 3
            if any(color[i] == color[i + 1] for i in range(m - 1)):
                continue
            valid[mask] = color

        # Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and mask2 When adjacent rows, the colors of the two cells in the same column are different
        adjacent = defaultdict(list)
        for mask1, color1 in valid.items():
            for mask2, color2 in valid.items():
                if not any(x == y for x, y in zip(color1, color2)):
                    adjacent[mask1].append(mask2)

        f = [int(mask in valid) for mask in range(3**m)]
        for i in range(1, n):
            g = [0] * (3**m)
            for mask2 in valid.keys():
                for mask1 in adjacent[mask2]:
                    g[mask2] += f[mask1]
                    if g[mask2] >= mod:
                        g[mask2] -= mod
            f = g

        return sum(f) % mod
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function colorTheGrid(m: number, n: number): number {
    const mod = 1000000007;
    // Hash mapping stores all valid coloration schemes for a single row that meet the requirements
    const valid = new Map<number, number[]>();

    // Enumerate masks that meet the requirements within the range [0, 3^m)
    const maskEnd = Math.pow(3, m);
    for (let mask = 0; mask < maskEnd; ++mask) {
        const color: number[] = [];
        let mm = mask;
        for (let i = 0; i < m; ++i) {
            color.push(mm % 3);
            mm = Math.floor(mm / 3);
        }
        let check = true;
        for (let i = 0; i < m - 1; ++i) {
            if (color[i] === color[i + 1]) {
                check = false;
                break;
            }
        }
        if (check) {
            valid.set(mask, color);
        }
    }

    // Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and mask2 When adjacent rows, the colors of the two cells in the same column are different
    const adjacent = new Map<number, number[]>();
    for (const [mask1, color1] of valid.entries()) {
        for (const [mask2, color2] of valid.entries()) {
            let check = true;
            for (let i = 0; i < m; ++i) {
                if (color1[i] === color2[i]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                if (!adjacent.has(mask1)) {
                    adjacent.set(mask1, []);
                }
                adjacent.get(mask1)!.push(mask2);
            }
        }
    }

    let f = new Map<number, number>();
    for (const [mask, _] of valid.entries()) {
        f.set(mask, 1);
    }
    for (let i = 1; i < n; ++i) {
        const g = new Map<number, number>();
        for (const [mask2, _] of valid.entries()) {
            for (const mask1 of adjacent.get(mask2) || []) {
                g.set(mask2, ((g.get(mask2) || 0) + f.get(mask1)!) % mod);
            }
        }
        f = g;
    }

    let ans = 0;
    for (const num of f.values()) {
        ans = (ans + num) % mod;
    }
    return ans;
}
```

</details>
