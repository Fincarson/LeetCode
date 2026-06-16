# 3741. Minimum Distance Between Three Equal Elements II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 3741 - Minimum Distance Between Three Equal Elements II](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/)

## Problem

You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n == nums.length <= 105
- 1 <= nums[i] <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3741. Minimum Distance Between Three Equal Elements II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traversal + Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Traversal + Hash Table

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

int minimumDistance(int* nums, int numsSize) {
    int* next = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        next[i] = -1;
    }

    HashItem* occur = NULL;
    int ans = numsSize + 1;

    for (int i = numsSize - 1; i >= 0; i--) {
        int prevPos = hashGetItem(&occur, nums[i], -1);
        if (prevPos != -1) {
            next[i] = prevPos;
        }
        hashSetItem(&occur, nums[i], i);
    }

    for (int i = 0; i < numsSize; i++) {
        int secondPos = next[i];
        if (secondPos != -1) {
            int thirdPos = next[secondPos];
            if (thirdPos != -1) {
                int distance = thirdPos - i;
                if (distance < ans) {
                    ans = distance;
                }
            }
        }
    }

    free(next);
    hashFree(&occur);

    return ans == numsSize + 1 ? -1 : ans * 2;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> next(n, -1);
        std::unordered_map<int, int> occur;
        int ans = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (occur.count(nums[i])) {
                next[i] = occur[nums[i]];
            }
            occur[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int secondPos = next[i];
            if (secondPos != -1) {
                int thirdPos = next[secondPos];
                if (thirdPos != -1) {
                    ans = std::min(ans, thirdPos - i);
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumDistance(int[] nums) {
        int n = nums.Length;
        int[] next = new int[n];
        Array.Fill(next, -1);
        Dictionary<int, int> occur = new();
        int ans = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (occur.TryGetValue(nums[i], out int val)) {
                next[i] = val;
            }
            occur[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int secondPos = next[i];
            if (secondPos != -1) {
                int thirdPos = next[secondPos];
                if (thirdPos != -1) {
                    ans = Math.Min(ans, thirdPos - i);
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumDistance(nums []int) int {
	n := len(nums)
	next := make([]int, n)
	for i := range next {
		next[i] = -1
	}
	occur := make(map[int]int)
	ans := n + 1

	for i := n - 1; i >= 0; i-- {
		if val, ok := occur[nums[i]]; ok {
			next[i] = val
		}
		occur[nums[i]] = i
	}

	for i := 0; i < n; i++ {
		secondPos := next[i]
		if secondPos != -1 {
			thirdPos := next[secondPos]
			if thirdPos != -1 {
				if dist := thirdPos - i; dist < ans {
					ans = dist
				}
			}
		}
	}

	if ans == n+1 {
		return -1
	}
	return ans * 2
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumDistance(int[] nums) {
        int n = nums.length;
        int[] next = new int[n];
        Arrays.fill(next, -1);
        Map<Integer, Integer> occur = new HashMap<>();
        int ans = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (occur.containsKey(nums[i])) {
                next[i] = occur.get(nums[i]);
            }
            occur.put(nums[i], i);
        }

        for (int i = 0; i < n; i++) {
            int secondPos = next[i];
            if (secondPos != -1) {
                int thirdPos = next[secondPos];
                if (thirdPos != -1) {
                    ans = Math.min(ans, thirdPos - i);
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumDistance = function (nums) {
    const next = Array.from({ length: nums.length }).fill(-1);
    const occur = new Map();
    let ans = nums.length + 1;

    for (let i = nums.length - 1; i >= 0; i--) {
        if (occur.has(nums[i])) {
            next[i] = occur.get(nums[i]);
        }
        occur.set(nums[i], i);
    }

    for (let i = 0; i < nums.length; i++) {
        let secondPos = next[i];
        let thirdPos = next[secondPos];
        if (secondPos !== -1 && thirdPos !== -1) {
            ans = Math.min(ans, thirdPos - i);
        }
    }

    if (ans === nums.length + 1) {
        return -1;
    } else {
        return ans * 2;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)
        nxt = [-1] * n
        occur = {}
        ans = n + 1

        for i in range(n - 1, -1, -1):
            if nums[i] in occur:
                nxt[i] = occur[nums[i]]
            occur[nums[i]] = i

        for i in range(n):
            second_pos = nxt[i]
            if second_pos != -1:
                third_pos = nxt[second_pos]
                if third_pos != -1:
                    ans = min(ans, third_pos - i)

        return -1 if ans == n + 1 else ans * 2
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumDistance(nums: number[]): number {
    const next = Array.from<number>({ length: nums.length }).fill(-1);
    const occur = new Map<number, number>();
    let ans = nums.length + 1;

    for (let i = nums.length - 1; i >= 0; i--) {
        if (occur.has(nums[i])) {
            next[i] = occur.get(nums[i])!;
        }
        occur.set(nums[i], i);
    }

    for (let i = 0; i < nums.length; i++) {
        let secondPos = next[i];
        let thirdPos = next[secondPos];
        if (secondPos !== -1 && thirdPos !== -1) {
            ans = Math.min(ans, thirdPos - i);
        }
    }

    if (ans === nums.length + 1) {
        return -1;
    } else {
        return ans * 2;
    }
}
```

</details>
