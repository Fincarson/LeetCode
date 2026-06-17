# 3761. Minimum Absolute Distance Between Mirror Pairs

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/)  
`Array` `Hash Table` `Math`

**Problem Link:** [LeetCode 3761 - Minimum Absolute Distance Between Mirror Pairs](https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/)

## Problem

You are given an integer array nums.

A mirror pair is a pair of indices (i, j) such that:

- 0 <= i < j < nums.length, and
- reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.

Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

If no mirror pair exists, return -1.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3761. Minimum Absolute Distance Between Mirror Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: One-time Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: One-time Traversal

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

void hashEraseItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if (pEntry) {
        HASH_DEL(*obj, pEntry);
        free(pEntry);
    }
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int minMirrorPairDistance(int* nums, int numsSize) {
    int reverseNum(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }

    HashItem* prev = NULL;
    int ans = numsSize + 1;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int prevIndex = hashGetItem(&prev, x, -1);
        if (prevIndex != -1) {
            int distance = i - prevIndex;
            if (distance < ans) {
                ans = distance;
            }
        }

        hashSetItem(&prev, reverseNum(x), i);
    }

    hashFree(&prev);

    return ans == numsSize + 1 ? -1 : ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        auto reverseNum = [](int x) {
            int y = 0;
            while (x > 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            return y;
        };

        int n = nums.size();
        unordered_map<int, int> prev;
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (prev.count(x)) {
                ans = min(ans, i - prev[x]);
            }
            prev[reverseNum(x)] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinMirrorPairDistance(int[] nums) {
        Dictionary<int, int> prev = new Dictionary<int, int>();
        int n = nums.Length;
        int ans = n + 1;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (prev.ContainsKey(x)) {
                ans = Math.Min(ans, i - prev[x]);
            }
            prev[ReverseNum(x)] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }

    private int ReverseNum(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minMirrorPairDistance(nums []int) int {
	reverseNum := func(x int) int {
		y := 0
		for x > 0 {
			y = y*10 + x%10
			x /= 10
		}
		return y
	}

	prev := make(map[int]int)
	n := len(nums)
	ans := n + 1

	for i, x := range nums {
		if idx, exists := prev[x]; exists {
			if i-idx < ans {
				ans = i - idx
			}
		}
		prev[reverseNum(x)] = i
	}

	if ans == n+1 {
		return -1
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minMirrorPairDistance(int[] nums) {
        Map<Integer, Integer> prev = new HashMap<>();
        int n = nums.length;
        int ans = n + 1;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (prev.containsKey(x)) {
                ans = Math.min(ans, i - prev.get(x));
            }
            prev.put(reverseNum(x), i);
        }

        return ans == n + 1 ? -1 : ans;
    }

    private int reverseNum(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + (x % 10);
            x /= 10;
        }
        return y;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minMirrorPairDistance = function (nums) {
    const reverseNum = (x) => {
        let y = 0;
        while (x > 0) {
            y = y * 10 + (x % 10);
            x = Math.floor(x / 10);
        }
        return y;
    };

    const prev = new Map();
    const n = nums.length;
    let ans = n + 1;

    for (let i = 0; i < n; i++) {
        const x = nums[i];
        if (prev.has(x)) {
            ans = Math.min(ans, i - prev.get(x));
        }
        prev.set(reverseNum(x), i);
    }

    return ans === n + 1 ? -1 : ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        prev = dict()
        ans = inf
        for i, num in enumerate(nums):
            if num in prev:
                ans = min(ans, i - prev[num])
            prev[int(str(num)[::-1])] = i
        return -1 if ans == inf else ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minMirrorPairDistance(nums: number[]): number {
    const reverseNum = (x: number): number => {
        let y = 0;
        while (x > 0) {
            y = y * 10 + (x % 10);
            x = Math.floor(x / 10);
        }
        return y;
    };

    const prev = new Map<number, number>();
    const n = nums.length;
    let ans = n + 1;

    for (let i = 0; i < n; i++) {
        const x = nums[i];
        if (prev.has(x)) {
            ans = Math.min(ans, i - prev.get(x)!);
        }
        prev.set(reverseNum(x), i);
    }

    return ans === n + 1 ? -1 : ans;
}
```

</details>
