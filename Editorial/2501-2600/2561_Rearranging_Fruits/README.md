# 2561. Rearranging Fruits

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/rearranging-fruits/)  
`Array` `Hash Table` `Greedy` `Sort`

**Problem Link:** [LeetCode 2561 - Rearranging Fruits](https://leetcode.com/problems/rearranging-fruits/)

## Problem

You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

- Choose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
- The cost of the swap is min(basket1[i], basket2[j]).

Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.

### Example 1

```text
Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1
Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
```

### Example 2

```text
Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
Output: -1
Explanation: It can be shown that it is impossible to make both the baskets equal.
```

## Constraints

- basket1.length == basket2.length
- 1 <= basket1.length <= 105
- 1 <= basket1[i], basket2[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Latest Time to Catch a Bus](https://leetcode.com/problems/the-latest-time-to-catch-a-bus/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Number of Operations to Make Arrays Similar](https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2561. Rearranging Fruits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} Hash;

void add(Hash **map, int key, int delta) {
    Hash *entry;
    HASH_FIND_INT(*map, &key, entry);
    if (!entry) {
        entry = (Hash *)malloc(sizeof(Hash));
        entry->key = key;
        entry->count = 0;
        HASH_ADD_INT(*map, key, entry);
    }
    entry->count += delta;
}

void free_map(Hash **map) {
    Hash *e, *tmp;
    HASH_ITER(hh, *map, e, tmp) {
        HASH_DEL(*map, e);
        free(e);
    }
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

long long minCost(int *basket1, int basket1Size, int *basket2,
                  int basket2Size) {
    int m = INT_MAX;
    Hash *frequency_map = NULL;
    for (int i = 0; i < basket1Size; i++) {
        add(&frequency_map, basket1[i], 1);
        if (basket1[i] < m) m = basket1[i];
    }
    for (int i = 0; i < basket2Size; i++) {
        add(&frequency_map, basket2[i], -1);
        if (basket2[i] < m) m = basket2[i];
    }

    int *merge = (int *)malloc(sizeof(int) * (basket1Size + basket2Size));
    int mergeSize = 0;
    Hash *e, *tmp;
    HASH_ITER(hh, frequency_map, e, tmp) {
        int c = e->count;
        if (c % 2 != 0) {
            free(merge);
            free_map(&frequency_map);
            return -1;
        }
        for (int i = 0; i < abs(c) / 2; i++) {
            merge[mergeSize++] = e->key;
        }
    }

    if (mergeSize == 0) {
        free(merge);
        free_map(&frequency_map);
        return 0;
    }

    qsort(merge, mergeSize, sizeof(int), cmp);

    long long res = 0;
    for (int i = 0; i < mergeSize / 2; i++) {
        res += fmin(merge[i], m * 2);
    }

    free(merge);
    free_map(&frequency_map);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = INT_MAX;
        unordered_map<int, int> frequency_map;
        for (int b1 : basket1) {
            frequency_map[b1]++;
            m = min(m, b1);
        }
        for (int b2 : basket2) {
            frequency_map[b2]--;
            m = min(m, b2);
        }
        vector<int> merge;
        for (auto [k, c] : frequency_map) {
            if (c % 2 != 0) {
                return -1;
            }
            for (int i = 0; i < abs(c) / 2; ++i) {
                merge.push_back(k);
            }
        }
        nth_element(merge.begin(), merge.begin() + merge.size() / 2,
                    merge.end());
        return accumulate(merge.begin(), merge.begin() + merge.size() / 2, 0ll,
                          [&](long long res, int x) -> long long {
                              return res + min(2 * m, x);
                          });
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MinCost(int[] basket1, int[] basket2) {
        var freq = new Dictionary<int, int>();
        int m = int.MaxValue;

        foreach (var b in basket1) {
            if (!freq.ContainsKey(b))
                freq[b] = 0;
            freq[b]++;
            m = Math.Min(m, b);
        }
        foreach (var b in basket2) {
            if (!freq.ContainsKey(b))
                freq[b] = 0;
            freq[b]--;
            m = Math.Min(m, b);
        }

        var merge = new List<int>();
        foreach (var kv in freq) {
            int c = kv.Value;
            if (c % 2 != 0)
                return -1;
            for (int i = 0; i < Math.Abs(c) / 2; i++) {
                merge.Add(kv.Key);
            }
        }

        merge.Sort();
        long res = 0;
        for (int i = 0; i < merge.Count / 2; i++) {
            res += Math.Min(2 * m, merge[i]);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minCost(basket1 []int, basket2 []int) int64 {
	freq := map[int]int{}
	m := math.MaxInt
	for _, b := range basket1 {
		freq[b]++
		if b < m {
			m = b
		}
	}
	for _, b := range basket2 {
		freq[b]--
		if b < m {
			m = b
		}
	}

	var merge []int
	for k, c := range freq {
		if c%2 != 0 {
			return -1
		}
		for i := 0; i < abs(c)/2; i++ {
			merge = append(merge, k)
		}
	}

	sort.Ints(merge)
	var res int64
	for i := 0; i < len(merge)/2; i++ {
		if 2*m < merge[i] {
			res += int64(2 * m)
		} else {
			res += int64(merge[i])
		}
	}
	return res
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minCost(int[] basket1, int[] basket2) {
        TreeMap<Integer, Integer> freq = new TreeMap<>();
        int m = Integer.MAX_VALUE;
        for (int b1 : basket1) {
            freq.put(b1, freq.getOrDefault(b1, 0) + 1);
            m = Math.min(m, b1);
        }
        for (int b2 : basket2) {
            freq.put(b2, freq.getOrDefault(b2, 0) - 1);
            m = Math.min(m, b2);
        }

        List<Integer> merge = new ArrayList<>();
        for (var entry : freq.entrySet()) {
            int count = entry.getValue();
            if (count % 2 != 0) return -1;
            for (int i = 0; i < Math.abs(count) / 2; i++) {
                merge.add(entry.getKey());
            }
        }

        Collections.sort(merge);
        long res = 0;
        for (int i = 0; i < merge.size() / 2; i++) {
            res += Math.min(2 * m, merge.get(i));
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minCost = function (basket1, basket2) {
    const freq = new Map();
    let m = Infinity;

    for (const b of basket1) {
        freq.set(b, (freq.get(b) || 0) + 1);
        m = Math.min(m, b);
    }
    for (const b of basket2) {
        freq.set(b, (freq.get(b) || 0) - 1);
        m = Math.min(m, b);
    }

    const merge = [];
    for (const [k, c] of freq.entries()) {
        if (c % 2 !== 0) return -1;
        for (let i = 0; i < Math.abs(c) / 2; i++) {
            merge.push(k);
        }
    }

    merge.sort((a, b) => a - b);
    let res = 0;
    for (let i = 0; i < merge.length / 2; i++) {
        res += Math.min(2 * m, merge[i]);
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        freq = Counter()
        m = float("inf")
        for b1 in basket1:
            freq[b1] += 1
            m = min(m, b1)
        for b2 in basket2:
            freq[b2] -= 1
            m = min(m, b2)

        merge = []
        for k, c in freq.items():
            if c % 2 != 0:
                return -1
            merge.extend([k] * (abs(c) // 2))

        if not merge:
            return 0
        merge.sort()
        return sum(min(2 * m, x) for x in merge[: len(merge) // 2])
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minCost(basket1: number[], basket2: number[]): number {
    const freq = new Map<number, number>();
    let m = Infinity;

    for (const b of basket1) {
        freq.set(b, (freq.get(b) || 0) + 1);
        m = Math.min(m, b);
    }
    for (const b of basket2) {
        freq.set(b, (freq.get(b) || 0) - 1);
        m = Math.min(m, b);
    }

    const merge: number[] = [];
    for (const [k, c] of freq.entries()) {
        if (c % 2 !== 0) return -1;
        for (let i = 0; i < Math.abs(c) / 2; i++) {
            merge.push(k);
        }
    }

    merge.sort((a, b) => a - b);
    let res = 0;
    for (let i = 0; i < merge.length / 2; i++) {
        res += Math.min(2 * m, merge[i]);
    }
    return res;
}
```

</details>
