# 1865. Finding Pairs With a Certain Sum

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/)  
`Array` `Hash Table` `Design`

**Problem Link:** [LeetCode 1865 - Finding Pairs With a Certain Sum](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/)

## Problem

You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

Implement the FindSumPairs class:

- FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
- void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
- int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

### Example 1

```text
Input
["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
[[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
Output
[null, 8, null, 2, 1, null, null, 11]

Explanation
FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]);
findSumPairs.count(7);  // return 8; pairs (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4
findSumPairs.add(3, 2); // now nums2 = [1,4,5,4,5,4]
findSumPairs.count(8);  // return 2; pairs (5,2), (5,4) make 3 + 5
findSumPairs.count(4);  // return 1; pair (5,0) makes 3 + 1
findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4]
findSumPairs.add(1, 1); // now nums2 = [2,5,5,4,5,4]
findSumPairs.count(7);  // return 11; pairs (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs (5,3), (5,5) make 3 + 4
```

## Constraints

- 1 <= nums1.length <= 1000
- 1 <= nums2.length <= 105
- 1 <= nums1[i] <= 109
- 1 <= nums2[i] <= 105
- 0 <= index < nums2.length
- 1 <= val <= 105
- 1 <= tot <= 109
- At most 1000 calls are made to add and count each.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Number of Distinct Averages](https://leetcode.com/problems/number-of-distinct-averages/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count the Number of Fair Pairs](https://leetcode.com/problems/count-the-number-of-fair-pairs/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1865. Finding Pairs With a Certain Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, int key, int val) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

typedef struct {
    int *nums1, *nums2;
    int nums1Size, nums2Size;
    HashItem *cnt;
} FindSumPairs;

FindSumPairs *findSumPairsCreate(int *nums1, int nums1Size, int *nums2,
                                 int nums2Size) {
    FindSumPairs *obj = (FindSumPairs *)malloc(sizeof(FindSumPairs));
    obj->nums1 = nums1;
    obj->nums1Size = nums1Size;
    obj->nums2 = nums2;
    obj->nums2Size = nums2Size;
    obj->cnt = NULL;
    for (int i = 0; i < nums2Size; i++) {
        hashSetItem(&obj->cnt, nums2[i],
                    hashGetItem(&obj->cnt, nums2[i], 0) + 1);
    }
    return obj;
}

void findSumPairsAdd(FindSumPairs *obj, int index, int val) {
    hashSetItem(&obj->cnt, obj->nums2[index],
                hashGetItem(&obj->cnt, obj->nums2[index], 0) - 1);
    obj->nums2[index] += val;
    hashSetItem(&obj->cnt, obj->nums2[index],
                hashGetItem(&obj->cnt, obj->nums2[index], 0) + 1);
}

int findSumPairsCount(FindSumPairs *obj, int tot) {
    int ans = 0;
    for (int i = 0; i < obj->nums1Size; i++) {
        int rest = tot - obj->nums1[i];
        if (hashFindItem(&obj->cnt, rest)) {
            ans += hashGetItem(&obj->cnt, rest, 0);
        }
    }
    return ans;
}

void findSumPairsFree(FindSumPairs *obj) {
    hashFree(&obj->cnt);
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            ++cnt[num];
        }
    }

    void add(int index, int val) {
        --cnt[nums2[index]];
        nums2[index] += val;
        ++cnt[nums2[index]];
    }

    int count(int tot) {
        int ans = 0;
        for (int num : nums1) {
            int rest = tot - num;
            if (cnt.count(rest)) {
                ans += cnt[rest];
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
public class FindSumPairs {
    private int[] nums1;
    private int[] nums2;
    private Dictionary<int, int> cnt;

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        this.cnt = new Dictionary<int, int>();
        foreach (int num in nums2) {
            if (cnt.ContainsKey(num)) {
                cnt[num]++;
            } else {
                cnt[num] = 1;
            }
        }
    }

    public void Add(int index, int val) {
        int oldVal = nums2[index];
        cnt[oldVal]--;
        nums2[index] += val;
        if (cnt.ContainsKey(nums2[index])) {
            cnt[nums2[index]]++;
        } else {
            cnt[nums2[index]] = 1;
        }
    }

    public int Count(int tot) {
        int ans = 0;
        foreach (int num in nums1) {
            int rest = tot - num;
            if (cnt.ContainsKey(rest)) {
                ans += cnt[rest];
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
type FindSumPairs struct {
	nums1 []int
	nums2 []int
	cnt   map[int]int
}

func Constructor(nums1 []int, nums2 []int) FindSumPairs {
	cnt := make(map[int]int)
	for _, num := range nums2 {
		cnt[num]++
	}
	return FindSumPairs{
		nums1: nums1,
		nums2: nums2,
		cnt:   cnt,
	}
}

func (this *FindSumPairs) Add(index int, val int) {
	oldVal := this.nums2[index]
	this.cnt[oldVal]--
	this.nums2[index] += val
	this.cnt[this.nums2[index]]++
}

func (this *FindSumPairs) Count(tot int) int {
	ans := 0
	for _, num := range this.nums1 {
		rest := tot - num
		ans += this.cnt[rest]
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class FindSumPairs {

    private int[] nums1;
    private int[] nums2;
    private Map<Integer, Integer> cnt;

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        this.cnt = new HashMap<>();
        for (int num : nums2) {
            cnt.put(num, cnt.getOrDefault(num, 0) + 1);
        }
    }

    public void add(int index, int val) {
        int oldVal = nums2[index];
        cnt.put(oldVal, cnt.get(oldVal) - 1);
        nums2[index] += val;
        cnt.put(nums2[index], cnt.getOrDefault(nums2[index], 0) + 1);
    }

    public int count(int tot) {
        int ans = 0;
        for (int num : nums1) {
            int rest = tot - num;
            ans += cnt.getOrDefault(rest, 0);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var FindSumPairs = function (nums1, nums2) {
    this.nums1 = nums1;
    this.nums2 = nums2;
    this.cnt = new Map();
    for (const num of nums2) {
        this.cnt.set(num, (this.cnt.get(num) || 0) + 1);
    }
};

FindSumPairs.prototype.add = function (index, val) {
    const oldVal = this.nums2[index];
    this.cnt.set(oldVal, (this.cnt.get(oldVal) || 0) - 1);
    this.nums2[index] += val;
    const newVal = this.nums2[index];
    this.cnt.set(newVal, (this.cnt.get(newVal) || 0) + 1);
};

FindSumPairs.prototype.count = function (tot) {
    let ans = 0;
    for (const num of this.nums1) {
        const rest = tot - num;
        ans += this.cnt.get(rest) || 0;
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = nums1
        self.nums2 = nums2
        self.cnt = Counter(nums2)

    def add(self, index: int, val: int) -> None:
        _nums2, _cnt = self.nums2, self.cnt

        _cnt[_nums2[index]] -= 1
        _nums2[index] += val
        _cnt[_nums2[index]] += 1

    def count(self, tot: int) -> int:
        _nums1, _cnt = self.nums1, self.cnt

        ans = 0
        for num in _nums1:
            if (rest := tot - num) in _cnt:
                ans += _cnt[rest]
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class FindSumPairs {
    private nums1: number[];
    private nums2: number[];
    private cnt: Map<number, number>;

    constructor(nums1: number[], nums2: number[]) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        this.cnt = new Map();
        for (const num of nums2) {
            this.cnt.set(num, (this.cnt.get(num) || 0) + 1);
        }
    }

    add(index: number, val: number): void {
        const oldVal = this.nums2[index];
        this.cnt.set(oldVal, (this.cnt.get(oldVal) || 0) - 1);
        this.nums2[index] += val;
        const newVal = this.nums2[index];
        this.cnt.set(newVal, (this.cnt.get(newVal) || 0) + 1);
    }

    count(tot: number): number {
        let ans = 0;
        for (const num of this.nums1) {
            const rest = tot - num;
            ans += this.cnt.get(rest) || 0;
        }
        return ans;
    }
}
```

</details>
