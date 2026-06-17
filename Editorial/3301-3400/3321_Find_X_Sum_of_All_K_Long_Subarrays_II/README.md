# 3321. Find X-Sum of All K-Long Subarrays II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/)  
`Array` `Hash Table` `Sliding Window` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 3321 - Find X-Sum of All K-Long Subarrays II](https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/)

## Problem

You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:

- Count the occurrences of all elements in the array.
- Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
- Calculate the sum of the resulting array.

Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

### Example 1

### Example 2

## Constraints

- nums.length == n
- 1 <= n <= 105
- 1 <= nums[i] <= 109
- 1 <= x <= k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3321. Find X-Sum of All K-Long Subarrays II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Table + Ordered Set | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash Table + Ordered Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Helper {
public:
    Helper(int x) {
        this->x = x;
        this->result = 0;
    }

    void insert(int num) {
        if (occ[num]) {
            internalRemove({occ[num], num});
        }
        ++occ[num];
        internalInsert({occ[num], num});
    }

    void remove(int num) {
        internalRemove({occ[num], num});
        --occ[num];
        if (occ[num]) {
            internalInsert({occ[num], num});
        }
    }

    long long get() { return result; }

private:
    void internalInsert(const pair<int, int>& p) {
        if (large.size() < x || p > *large.begin()) {
            result += static_cast<long long>(p.first) * p.second;
            large.insert(p);
            if (large.size() > x) {
                result -= static_cast<long long>(large.begin()->first) *
                          large.begin()->second;
                auto transfer = *large.begin();
                large.erase(transfer);
                small.insert(transfer);
            }
        } else {
            small.insert(p);
        }
    }

    void internalRemove(const pair<int, int>& p) {
        if (p >= *large.begin()) {
            result -= static_cast<long long>(p.first) * p.second;
            large.erase(p);
            if (!small.empty()) {
                result += static_cast<long long>(small.rbegin()->first) *
                          small.rbegin()->second;
                auto transfer = *small.rbegin();
                small.erase(transfer);
                large.insert(transfer);
            }
        } else {
            small.erase(p);
        }
    }

private:
    int x;
    long long result;
    set<pair<int, int>> large, small;
    unordered_map<int, int> occ;
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        Helper helper(x);

        vector<long long> ans;
        for (int i = 0; i < nums.size(); ++i) {
            helper.insert(nums[i]);
            if (i >= k) {
                helper.remove(nums[i - k]);
            }
            if (i >= k - 1) {
                ans.push_back(helper.get());
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
public class Helper {
    private int x;
    private long result;

    private sealed class PairComparer : IComparer<(int cnt, int num)> {
        public int Compare((int cnt, int num)a, (int cnt, int num)b) {
            int c = a.cnt.CompareTo(b.cnt);
            if (c != 0)
                return c;
            c = a.num.CompareTo(b.num);
            return c;
        }
    }

    private SortedSet<(int cnt, int num)> large;
    private SortedSet<(int cnt, int num)> small;
    private Dictionary<int, int> occ;
    private HashSet<int> inLarge;

    public Helper(int x) {
        this.x = x;
        result = 0;
        var cmp = new PairComparer();
        large = new SortedSet<(int, int)>(cmp);
        small = new SortedSet<(int, int)>(cmp);
        occ = new Dictionary<int, int>();
        inLarge = new HashSet<int>();
    }

    public void Insert(int num) {
        if (occ.TryGetValue(num, out int oldCnt) && oldCnt > 0) {
            InternalRemove((oldCnt, num));
        }

        int newCnt = oldCnt + 1;
        occ[num] = newCnt;
        InternalInsert((newCnt, num));
    }

    public void Remove(int num) {
        int cnt = occ[num];
        InternalRemove((cnt, num));
        cnt--;
        if (cnt == 0)
            occ.Remove(num);
        else
            occ[num] = cnt;

        if (cnt > 0)
            InternalInsert((cnt, num));
    }

    public long Get() => result;

    private void InternalInsert((int cnt, int num)p) {
        if (large.Count < x) {
            large.Add(p);
            inLarge.Add(p.num);
            result += (long)p.cnt * p.num;
            return;
        }

        if (large.Count > 0 && Compare(p, GetMin(large)) > 0) {
            var minL = GetMin(large);
            large.Remove(minL);
            inLarge.Remove(minL.num);
            result -= (long)minL.cnt * minL.num;

            large.Add(p);
            inLarge.Add(p.num);
            result += (long)p.cnt * p.num;

            small.Add(minL);
        } else {
            small.Add(p);
        }
    }

    private void InternalRemove((int cnt, int num)p) {
        if (inLarge.Contains(p.num)) {
            if (large.Remove(p)) {
                inLarge.Remove(p.num);
                result -= (long)p.cnt * p.num;
            }

            if (small.Count > 0) {
                var maxS = GetMax(small);
                small.Remove(maxS);
                large.Add(maxS);
                inLarge.Add(maxS.num);
                result += (long)maxS.cnt * maxS.num;
            }
        } else {
            small.Remove(p);
        }
    }

    private static (int cnt, int num) GetMin(SortedSet<(int cnt, int num)> s) {
        foreach (var v in s) return v;
        throw new InvalidOperationException();
    }

    private static (int cnt, int num) GetMax(SortedSet<(int cnt, int num)> s) {
        var it = s.Max;
        return it;
    }

    private static int Compare((int cnt, int num)a, (int cnt, int num)b) {
        int c = a.cnt.CompareTo(b.cnt);
        if (c != 0)
            return c;
        return a.num.CompareTo(b.num);
    }
}

public class Solution {
    public long[] FindXSum(int[] nums, int k, int x) {
        var helper = new Helper(x);
        var ans = new List<long>(Math.Max(0, nums.Length - k + 1));

        for (int i = 0; i < nums.Length; i++) {
            helper.Insert(nums[i]);
            if (i >= k)
                helper.Remove(nums[i - k]);
            if (i >= k - 1)
                ans.Add(helper.Get());
        }
        return ans.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
import (
	"github.com/emirpasic/gods/v2/trees/redblacktree"
)

func findXSum(nums []int, k int, x int) []int64 {
	helper := NewHelper(x)
	ans := []int64{}

	for i := 0; i < len(nums); i++ {
		helper.Insert(nums[i])
		if i >= k {
			helper.Remove(nums[i-k])
		}
		if i >= k-1 {
			ans = append(ans, helper.Get())
		}
	}

	return ans
}

type Helper struct {
	x      int
	result int64
	large  *redblacktree.Tree[pair, struct{}]
	small  *redblacktree.Tree[pair, struct{}]
	occ    map[int]int
}

type pair struct {
	freq int
	num  int
}

func pairComparator(a, b pair) int {
	if a.freq != b.freq {
		return a.freq - b.freq
	}
	return a.num - b.num
}

func NewHelper(x int) *Helper {
	return &Helper{
		x:      x,
		result: 0,
		large:  redblacktree.NewWith[pair, struct{}](pairComparator),
		small:  redblacktree.NewWith[pair, struct{}](pairComparator),
		occ:    make(map[int]int),
	}
}

func (h *Helper) Insert(num int) {
	if h.occ[num] > 0 {
		h.internalRemove(pair{freq: h.occ[num], num: num})
	}
	h.occ[num]++
	h.internalInsert(pair{freq: h.occ[num], num: num})
}

func (h *Helper) Remove(num int) {
	h.internalRemove(pair{freq: h.occ[num], num: num})
	h.occ[num]--
	if h.occ[num] > 0 {
		h.internalInsert(pair{freq: h.occ[num], num: num})
	}
}

func (h *Helper) Get() int64 {
	return h.result
}

func (h *Helper) internalInsert(p pair) {
	if h.large.Size() < h.x {
		h.result += int64(p.freq) * int64(p.num)
		h.large.Put(p, struct{}{})
	} else {
		minLarge := h.large.Left().Key
		if pairComparator(p, minLarge) > 0 {
			h.result += int64(p.freq) * int64(p.num)
			h.large.Put(p, struct{}{})
			toRemove := h.large.Left().Key
			h.result -= int64(toRemove.freq) * int64(toRemove.num)
			h.large.Remove(toRemove)
			h.small.Put(toRemove, struct{}{})
		} else {
			h.small.Put(p, struct{}{})
		}
	}
}

func (h *Helper) internalRemove(p pair) {
	if _, found := h.large.Get(p); found {
		h.result -= int64(p.freq) * int64(p.num)
		h.large.Remove(p)

		if h.small.Size() > 0 {
			maxSmall := h.small.Right().Key
			h.result += int64(maxSmall.freq) * int64(maxSmall.num)
			h.small.Remove(maxSmall)
			h.large.Put(maxSmall, struct{}{})
		}
	} else if _, found := h.small.Get(p); found {
		h.small.Remove(p)
	}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Helper {

    private int x;
    private long result;
    private TreeSet<Pair> large, small;
    private Map<Integer, Integer> occ;

    private static class Pair implements Comparable<Pair> {

        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.first != other.first) {
                return Integer.compare(this.first, other.first);
            }
            return Integer.compare(this.second, other.second);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Pair pair = (Pair) obj;
            return first == pair.first && second == pair.second;
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    }

    public Helper(int x) {
        this.x = x;
        this.result = 0;
        this.large = new TreeSet<>();
        this.small = new TreeSet<>();
        this.occ = new HashMap<>();
    }

    public void insert(int num) {
        if (occ.containsKey(num) && occ.get(num) > 0) {
            internalRemove(new Pair(occ.get(num), num));
        }
        occ.put(num, occ.getOrDefault(num, 0) + 1);
        internalInsert(new Pair(occ.get(num), num));
    }

    public void remove(int num) {
        internalRemove(new Pair(occ.get(num), num));
        occ.put(num, occ.get(num) - 1);
        if (occ.get(num) > 0) {
            internalInsert(new Pair(occ.get(num), num));
        }
    }

    public long get() {
        return result;
    }

    private void internalInsert(Pair p) {
        if (large.size() < x || p.compareTo(large.first()) > 0) {
            result += (long) p.first * p.second;
            large.add(p);
            if (large.size() > x) {
                Pair toRemove = large.first();
                result -= (long) toRemove.first * toRemove.second;
                large.remove(toRemove);
                small.add(toRemove);
            }
        } else {
            small.add(p);
        }
    }

    private void internalRemove(Pair p) {
        if (p.compareTo(large.first()) >= 0) {
            result -= (long) p.first * p.second;
            large.remove(p);
            if (!small.isEmpty()) {
                Pair toAdd = small.last();
                result += (long) toAdd.first * toAdd.second;
                small.remove(toAdd);
                large.add(toAdd);
            }
        } else {
            small.remove(p);
        }
    }
}

class Solution {

    public long[] findXSum(int[] nums, int k, int x) {
        Helper helper = new Helper(x);
        List<Long> ans = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            helper.insert(nums[i]);
            if (i >= k) {
                helper.remove(nums[i - k]);
            }
            if (i >= k - 1) {
                ans.add(helper.get());
            }
        }

        return ans.stream().mapToLong(Long::longValue).toArray();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const { AvlTree } = require("datastructures-js");

class Helper {
    constructor(x) {
        this.x = x;
        this.result = 0n;

        const comparator = (a, b) => {
            if (a[0] !== b[0]) {
                return a[0] - b[0];
            }
            return a[1] - b[1];
        };

        this.large = new AvlTree(comparator);
        this.small = new AvlTree(comparator);
        this.occ = new Map();
    }

    insert(num) {
        const currentFreq = this.occ.get(num) || 0;
        if (currentFreq > 0) {
            this.internalRemove([currentFreq, num]);
        }

        const newFreq = currentFreq + 1;
        this.occ.set(num, newFreq);
        this.internalInsert([newFreq, num]);
    }

    remove(num) {
        const currentFreq = this.occ.get(num);
        if (currentFreq === undefined || currentFreq === 0) {
            return;
        }
        this.internalRemove([currentFreq, num]);
        const newFreq = currentFreq - 1;
        if (newFreq > 0) {
            this.occ.set(num, newFreq);
            this.internalInsert([newFreq, num]);
        } else {
            this.occ.delete(num);
        }
    }

    get() {
        return Number(this.result);
    }

    internalInsert(p) {
        const [freq, value] = p;
        const minLarge = this.large.min();
        if (
            this.large.count() < this.x ||
            (minLarge && this.comparePairs(p, minLarge.getValue()) > 0)
        ) {
            this.result += BigInt(freq) * BigInt(value);
            this.large.insert(p);
            if (this.large.count() > this.x) {
                const smallestLarge = this.large.min();
                if (smallestLarge) {
                    const value = smallestLarge.getValue();
                    this.result -= BigInt(value[0]) * BigInt(value[1]);
                    this.large.remove(value);
                    this.small.insert(value);
                }
            }
        } else {
            this.small.insert(p);
        }
    }

    internalRemove(p) {
        const [freq, value] = p;
        if (this.large.has(p)) {
            this.result -= BigInt(freq) * BigInt(value);
            this.large.remove(p);
            if (this.small.count() > 0) {
                const largestSmall = this.small.max();
                if (largestSmall) {
                    const value = largestSmall.getValue();
                    this.result += BigInt(value[0]) * BigInt(value[1]);
                    this.small.remove(value);
                    this.large.insert(value);
                }
            }
        } else {
            this.small.remove(p);
        }
    }

    comparePairs(a, b) {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }
        return a[1] - b[1];
    }
}

var findXSum = function (nums, k, x) {
    const helper = new Helper(x);
    const ans = [];
    for (let i = 0; i < nums.length; i++) {
        helper.insert(nums[i]);
        if (i >= k) {
            helper.remove(nums[i - k]);
        }
        if (i >= k - 1) {
            ans.push(helper.get());
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Helper:
    def __init__(self, x):
        self.x = x
        self.result = 0
        self.large = SortedList()
        self.small = SortedList()
        self.occ = defaultdict(int)

    def insert(self, num):
        if self.occ[num] > 0:
            self.internal_remove((self.occ[num], num))
        self.occ[num] += 1
        self.internal_insert((self.occ[num], num))

    def remove(self, num):
        self.internal_remove((self.occ[num], num))
        self.occ[num] -= 1
        if self.occ[num] > 0:
            self.internal_insert((self.occ[num], num))

    def get(self):
        return self.result

    def internal_insert(self, p):
        if len(self.large) < self.x or p > self.large[0]:
            self.result += p[0] * p[1]
            self.large.add(p)
            if len(self.large) > self.x:
                to_remove = self.large[0]
                self.result -= to_remove[0] * to_remove[1]
                self.large.remove(to_remove)
                self.small.add(to_remove)
        else:
            self.small.add(p)

    def internal_remove(self, p):
        if p >= self.large[0]:
            self.result -= p[0] * p[1]
            self.large.remove(p)
            if self.small:
                to_add = self.small[-1]
                self.result += to_add[0] * to_add[1]
                self.small.remove(to_add)
                self.large.add(to_add)
        else:
            self.small.remove(p)


class Solution:
    def findXSum(self, nums, k, x):
        helper = Helper(x)
        ans = []

        for i in range(len(nums)):
            helper.insert(nums[i])
            if i >= k:
                helper.remove(nums[i - k])
            if i >= k - 1:
                ans.append(helper.get())

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
import { AvlTree } from "@datastructures-js/binary-search-tree";

type FrequencyPair = [number, number];

class Helper {
    private x: number;
    private result: bigint;
    private large: AvlTree<FrequencyPair>;
    private small: AvlTree<FrequencyPair>;
    private occ: Map<number, number>;

    constructor(x: number) {
        this.x = x;
        this.result = 0n;

        const comparator = (a: FrequencyPair, b: FrequencyPair): number => {
            if (a[0] !== b[0]) {
                return a[0] - b[0];
            }
            return a[1] - b[1];
        };

        this.large = new AvlTree<FrequencyPair>(comparator);
        this.small = new AvlTree<FrequencyPair>(comparator);
        this.occ = new Map<number, number>();
    }

    insert(num: number): void {
        const currentFreq = this.occ.get(num) || 0;
        if (currentFreq > 0) {
            this.internalRemove([currentFreq, num]);
        }

        const newFreq = currentFreq + 1;
        this.occ.set(num, newFreq);
        this.internalInsert([newFreq, num]);
    }

    remove(num: number): void {
        const currentFreq = this.occ.get(num);
        if (currentFreq === undefined || currentFreq === 0) {
            return;
        }
        this.internalRemove([currentFreq, num]);
        const newFreq = currentFreq - 1;
        if (newFreq > 0) {
            this.occ.set(num, newFreq);
            this.internalInsert([newFreq, num]);
        } else {
            this.occ.delete(num);
        }
    }

    get(): number {
        return Number(this.result);
    }

    private internalInsert(p: FrequencyPair): void {
        const [freq, value] = p;
        const minLarge = this.large.min();
        if (
            this.large.count() < this.x ||
            (minLarge && this.comparePairs(p, minLarge.getValue()) > 0)
        ) {
            this.result += BigInt(freq) * BigInt(value);
            this.large.insert(p);
            if (this.large.count() > this.x) {
                const smallestLarge = this.large.min();
                if (smallestLarge) {
                    const value = smallestLarge.getValue();
                    this.result -= BigInt(value[0]) * BigInt(value[1]);
                    this.large.remove(value);
                    this.small.insert(value);
                }
            }
        } else {
            this.small.insert(p);
        }
    }

    private internalRemove(p: FrequencyPair): void {
        const [freq, value] = p;

        if (this.large.has(p)) {
            this.result -= BigInt(freq) * BigInt(value);
            this.large.remove(p);
            if (this.small.count() > 0) {
                const largestSmall = this.small.max();
                if (largestSmall) {
                    const value = largestSmall.getValue();
                    this.result += BigInt(value[0]) * BigInt(value[1]);
                    this.small.remove(value);
                    this.large.insert(value);
                }
            }
        } else {
            this.small.remove(p);
        }
    }

    private comparePairs(a: FrequencyPair, b: FrequencyPair): number {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }
        return a[1] - b[1];
    }
}

function findXSum(nums: number[], k: number, x: number): number[] {
    const helper = new Helper(x);
    const ans: number[] = [];

    for (let i = 0; i < nums.length; i++) {
        helper.insert(nums[i]);

        if (i >= k) {
            helper.remove(nums[i - k]);
        }

        if (i >= k - 1) {
            ans.push(helper.get());
        }
    }

    return ans;
}
```

</details>
