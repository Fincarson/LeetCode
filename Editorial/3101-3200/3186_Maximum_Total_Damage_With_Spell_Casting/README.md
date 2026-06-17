# 3186. Maximum Total Damage With Spell Casting

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-total-damage-with-spell-casting/)  
`Array` `Hash Table` `Two Pointers` `Binary Search` `Dynamic Programming` `Sorting` `Counting`

**Problem Link:** [LeetCode 3186 - Maximum Total Damage With Spell Casting](https://leetcode.com/problems/maximum-total-damage-with-spell-casting/)

## Problem

A magician has various spells.

You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.

It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.

Each spell can be cast only once.

Return the maximum possible total damage that a magician can cast.

### Example 1

### Example 2

## Constraints

- 1 <= power.length <= 105
- 1 <= power[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3186. Maximum Total Damage With Spell Casting

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

long long maximumTotalDamage(int* power, int powerSize) {
    int* keys = (int*)malloc(sizeof(int) * powerSize);
    int* vals = (int*)malloc(sizeof(int) * powerSize);
    int m = 0;

    qsort(power, powerSize, sizeof(int), cmp);

    for (int i = 0; i < powerSize; i++) {
        if (m == 0 || power[i] != keys[m - 1]) {
            keys[m] = power[i];
            vals[m] = 1;
            m++;
        } else {
            vals[m - 1]++;
        }
    }

    int* vk = (int*)malloc(sizeof(int) * (m + 1));
    int* vv = (int*)malloc(sizeof(int) * (m + 1));
    vk[0] = -1000000000;
    vv[0] = 0;
    for (int i = 0; i < m; i++) {
        vk[i + 1] = keys[i];
        vv[i + 1] = vals[i];
    }
    int n = m + 1;

    long long* f = (long long*)calloc(n, sizeof(long long));
    long long mx = 0, ans = 0;
    int j = 1;
    for (int i = 1; i < n; i++) {
        while (j < i && vk[j] < vk[i] - 2) {
            if (f[j] > mx) {
                mx = f[j];
            }
            j++;
        }
        f[i] = mx + 1LL * vk[i] * vv[i];
        if (f[i] > ans) {
            ans = f[i];
        }
    }

    free(keys);
    free(vals);
    free(vk);
    free(vv);
    free(f);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> count;
        for (int p : power) {
            count[p]++;
        }
        vector<pair<int, int>> vec = {{-1e9, 0}};
        for (auto& p : count) {
            vec.push_back(p);
        }
        int n = vec.size();
        vector<long long> f(n, 0);
        long long mx = 0;
        for (int i = 1, j = 1; i < n; i++) {
            while (j < i && vec[j].first < vec[i].first - 2) {
                mx = max(mx, f[j]);
                j++;
            }
            f[i] = mx + 1LL * vec[i].first * vec[i].second;
        }
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, f[i]);
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
    public long MaximumTotalDamage(int[] power) {
        var count = new SortedDictionary<int, int>();
        foreach (var p in power) {
            if (!count.ContainsKey(p)) {
                count[p] = 0;
            }
            count[p]++;
        }
        var vec = new List<(int, int)>();
        vec.Add((-1000000000, 0));
        foreach (var kv in count) {
            vec.Add((kv.Key, kv.Value));
        }
        int n = vec.Count;
        long[] f = new long[n];
        long mx = 0, ans = 0;
        int j = 1;
        for (int i = 1; i < n; i++) {
            while (j < i && vec[j].Item1 < vec[i].Item1 - 2) {
                mx = Math.Max(mx, f[j]);
                j++;
            }
            f[i] = mx + (long)vec[i].Item1 * vec[i].Item2;
            ans = Math.Max(ans, f[i]);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumTotalDamage(power []int) int64 {
	count := map[int]int{}
	for _, p := range power {
		count[p]++
	}
	keys := make([]int, 0, len(count))
	for k := range count {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	vec := [][2]int{{-1000000000, 0}}
	for _, k := range keys {
		vec = append(vec, [2]int{k, count[k]})
	}
	n := len(vec)
	f := make([]int64, n)
	var mx int64
	var ans int64
	j := 1
	for i := 1; i < n; i++ {
		for j < i && vec[j][0] < vec[i][0]-2 {
			if f[j] > mx {
				mx = f[j]
			}
			j++
		}
		f[i] = mx + int64(vec[i][0])*int64(vec[i][1])
		if f[i] > ans {
			ans = f[i]
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

    public long maximumTotalDamage(int[] power) {
        TreeMap<Integer, Integer> count = new TreeMap<>();
        for (int p : power) {
            count.put(p, count.getOrDefault(p, 0) + 1);
        }
        List<int[]> vec = new ArrayList<>();
        vec.add(new int[] { -1000000000, 0 });
        for (Map.Entry<Integer, Integer> e : count.entrySet()) {
            vec.add(new int[] { e.getKey(), e.getValue() });
        }
        int n = vec.size();
        long[] f = new long[n];
        long mx = 0;
        long ans = 0;
        int j = 1;
        for (int i = 1; i < n; i++) {
            while (j < i && vec.get(j)[0] < vec.get(i)[0] - 2) {
                mx = Math.max(mx, f[j]);
                j++;
            }
            f[i] = mx + 1L * vec.get(i)[0] * vec.get(i)[1];
            ans = Math.max(ans, f[i]);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumTotalDamage = function (power) {
    let count = new Map();
    for (let p of power) {
        count.set(p, (count.get(p) || 0) + 1);
    }
    let vec = [[-1000000000, 0]];
    let keys = Array.from(count.keys()).sort((a, b) => a - b);
    for (let k of keys) {
        vec.push([k, count.get(k)]);
    }
    let n = vec.length;
    let f = Array(n).fill(0);
    let mx = 0,
        ans = 0,
        j = 1;
    for (let i = 1; i < n; i++) {
        while (j < i && vec[j][0] < vec[i][0] - 2) {
            mx = Math.max(mx, f[j]);
            j++;
        }
        f[i] = mx + vec[i][0] * vec[i][1];
        ans = Math.max(ans, f[i]);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumTotalDamage(self, power):
        count = Counter(power)
        vec = [(-(10**9), 0)]
        for k in sorted(count.keys()):
            vec.append((k, count[k]))
        n = len(vec)
        f = [0] * n
        mx = 0
        j = 1
        for i in range(1, n):
            while j < i and vec[j][0] < vec[i][0] - 2:
                mx = max(mx, f[j])
                j += 1
            f[i] = mx + vec[i][0] * vec[i][1]
        return max(f)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumTotalDamage(power: number[]): number {
    let count = new Map<number, number>();
    for (let p of power) {
        count.set(p, (count.get(p) || 0) + 1);
    }
    let vec: [number, number][] = [[-1000000000, 0]];
    let keys = Array.from(count.keys()).sort((a, b) => a - b);
    for (let k of keys) {
        vec.push([k, count.get(k)!]);
    }
    let n = vec.length;
    let f = new Array<number>(n).fill(0);
    let mx = 0,
        ans = 0,
        j = 1;
    for (let i = 1; i < n; i++) {
        while (j < i && vec[j][0] < vec[i][0] - 2) {
            mx = Math.max(mx, f[j]);
            j++;
        }
        f[i] = mx + vec[i][0] * vec[i][1];
        ans = Math.max(ans, f[i]);
    }
    return ans;
}
```

</details>
