# 3318. Find X-Sum of All K-Long Subarrays I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/)  
`Array` `Hash Table` `Sliding Window` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 3318 - Find X-Sum of All K-Long Subarrays I](https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/)

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

- 1 <= n == nums.length <= 50
- 1 <= nums[i] <= 50
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

# Editorial - 3318. Find X-Sum of All K-Long Subarrays I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Table + Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash Table + Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

typedef struct {
    int freq;
    int num;
} FreqPair;

int compareFreq(const void* a, const void* b) {
    FreqPair* pa = (FreqPair*)a;
    FreqPair* pb = (FreqPair*)b;
    if (pa->freq != pb->freq) {
        return pb->freq - pa->freq;
    }
    return pb->num - pa->num;
}

int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* ans = (int*)malloc(*returnSize * sizeof(int));

    for (int i = 0; i <= numsSize - k; ++i) {
        HashItem* cnt = NULL;
        for (int j = i; j < i + k; ++j) {
            hashSetItem(&cnt, nums[j], hashGetItem(&cnt, nums[j], 0) + 1);
        }

        int len = HASH_COUNT(cnt);
        FreqPair* freq = (FreqPair*)malloc(len * sizeof(FreqPair));
        int pos = 0;
        for (HashItem* pEntry = cnt; pEntry; pEntry = pEntry->hh.next) {
            freq[pos].freq = pEntry->val;
            freq[pos].num = pEntry->key;
            pos++;
        }
        qsort(freq, len, sizeof(FreqPair), compareFreq);
        int xsum = 0;
        for (int j = 0; j < x && j < len; ++j) {
            xsum += freq[j].freq * freq[j].num;
        }
        ans[i] = xsum;
        hashFree(&cnt);
        free(freq);
    }

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; ++i) {
            unordered_map<int, int> cnt;
            for (int j = i; j < i + k; ++j) {
                ++cnt[nums[j]];
            }

            vector<pair<int, int>> freq;
            for (const auto& [key, value] : cnt) {
                freq.emplace_back(value, key);
            }
            sort(freq.begin(), freq.end(), greater<pair<int, int>>());

            int xsum = 0;
            for (int j = 0; j < x && j < freq.size(); ++j) {
                xsum += freq[j].first * freq[j].second;
            }
            ans.push_back(xsum);
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
    public int[] FindXSum(int[] nums, int k, int x) {
        int n = nums.Length;
        int[] ans = new int[n - k + 1];

        for (int i = 0; i <= n - k; ++i) {
            Dictionary<int, int> cnt = new Dictionary<int, int>();
            for (int j = i; j < i + k; ++j) {
                if (cnt.ContainsKey(nums[j])) {
                    cnt[nums[j]]++;
                } else {
                    cnt[nums[j]] = 1;
                }
            }

            List<int[]> freq = new List<int[]>();
            foreach (var entry in cnt) {
                freq.Add(new int[] { entry.Value, entry.Key });
            }
            freq.Sort((a, b) => b[0] != a[0] ? b[0] - a[0] : b[1] - a[1]);
            int xsum = 0;
            for (int j = 0; j < x && j < freq.Count; ++j) {
                xsum += freq[j][0] * freq[j][1];
            }
            ans[i] = xsum;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findXSum(nums []int, k int, x int) []int {
	n := len(nums)
	ans := make([]int, 0, n-k+1)

	for i := 0; i <= n-k; i++ {
		cnt := make(map[int]int)
		for j := i; j < i+k; j++ {
			cnt[nums[j]]++
		}

		type Pair struct {
			freq int
			num  int
		}
		freq := make([]Pair, 0, len(cnt))
		for num, count := range cnt {
			freq = append(freq, Pair{count, num})
		}
		sort.Slice(freq, func(i, j int) bool {
			if freq[i].freq != freq[j].freq {
				return freq[i].freq > freq[j].freq
			}
			return freq[i].num > freq[j].num
		})

		xsum := 0
		for j := 0; j < x && j < len(freq); j++ {
			xsum += freq[j].freq * freq[j].num
		}
		ans = append(ans, xsum)
	}

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];

        for (int i = 0; i <= n - k; ++i) {
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int j = i; j < i + k; ++j) {
                cnt.put(nums[j], cnt.getOrDefault(nums[j], 0) + 1);
            }

            List<int[]> freq = new ArrayList<>();
            for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
                freq.add(new int[] { entry.getValue(), entry.getKey() });
            }

            freq.sort((a, b) -> b[0] != a[0] ? b[0] - a[0] : b[1] - a[1]);
            int xsum = 0;
            for (int j = 0; j < x && j < freq.size(); ++j) {
                xsum += freq.get(j)[0] * freq.get(j)[1];
            }
            ans[i] = xsum;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findXSum = function (nums, k, x) {
    const n = nums.length;
    const ans = [];

    for (let i = 0; i <= n - k; i++) {
        const cnt = new Map();
        for (let j = i; j < i + k; j++) {
            cnt.set(nums[j], (cnt.get(nums[j]) || 0) + 1);
        }
        const freq = Array.from(cnt.entries()).map(([num, count]) => [
            count,
            num,
        ]);
        freq.sort((a, b) => (b[0] !== a[0] ? b[0] - a[0] : b[1] - a[1]));
        let xsum = 0;
        for (let j = 0; j < x && j < freq.length; j++) {
            xsum += freq[j][0] * freq[j][1];
        }
        ans.push(xsum);
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)
        ans = list()
        for i in range(n - k + 1):
            cnt = Counter(nums[i : i + k])
            freq = sorted(cnt.items(), key=lambda item: (-item[1], -item[0]))
            xsum = sum(key * value for key, value in freq[:x])
            ans.append(xsum)
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findXSum(nums: number[], k: number, x: number): number[] {
    const n: number = nums.length;
    const ans: number[] = [];

    for (let i = 0; i <= n - k; i++) {
        const cnt: Map<number, number> = new Map();
        for (let j = i; j < i + k; j++) {
            cnt.set(nums[j], (cnt.get(nums[j]) || 0) + 1);
        }

        const freq: [number, number][] = Array.from(cnt.entries()).map(
            ([num, count]) => [count, num],
        );
        freq.sort((a, b) => (b[0] !== a[0] ? b[0] - a[0] : b[1] - a[1]));
        let xsum: number = 0;
        for (let j = 0; j < x && j < freq.length; j++) {
            xsum += freq[j][0] * freq[j][1];
        }
        ans.push(xsum);
    }

    return ans;
}
```

</details>
