# 3347. Maximum Frequency of an Element After Performing Operations II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/)  
`Array` `Binary Search` `Sliding Window` `Sorting` `Prefix Sum`

**Problem Link:** [LeetCode 3347 - Maximum Frequency of an Element After Performing Operations II](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/)

## Problem

You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each operation you:

- Select an index i that was not selected in any previous operations.
- Add an integer in the range [-k, k] to nums[i].

Return the maximum possible frequency of any element in nums after performing the operations.

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 0 <= k <= 109
- 0 <= numOperations <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3347. Maximum Frequency of an Element After Performing Operations II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sort + Enumerate + Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Sort + Enumerate + Binary Search

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

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

void addMode(int* nums, int numsSize, int k, HashItem** modes, int value) {
    hashAddItem(modes, value, 1);
    if (value - k >= nums[0]) {
        hashAddItem(modes, value - k, 1);
    }
    if (value + k <= nums[numsSize - 1]) {
        hashAddItem(modes, value + k, 1);
    }
}

int leftBound(int* nums, int numsSize, int value) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int rightBound(int* nums, int numsSize, int value) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (nums[mid] > value) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    return left;
}

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    qsort(nums, numsSize, sizeof(int), compare);
    int ans = 0;
    HashItem* numCount = NULL;
    HashItem* modes = NULL;

    int lastNumIndex = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != nums[lastNumIndex]) {
            hashSetItem(&numCount, nums[lastNumIndex], i - lastNumIndex);
            if (i - lastNumIndex > ans) {
                ans = i - lastNumIndex;
            }
            addMode(nums, numsSize, k, &modes, nums[lastNumIndex]);
            lastNumIndex = i;
        }
    }

    hashSetItem(&numCount, nums[lastNumIndex], numsSize - lastNumIndex);
    if (numsSize - lastNumIndex > ans) {
        ans = numsSize - lastNumIndex;
    }
    addMode(nums, numsSize, k, &modes, nums[lastNumIndex]);

    int modesSize = HASH_COUNT(modes);
    int* sortModes = (int*)malloc(sizeof(int) * modesSize);
    int pos = 0;
    for (HashItem* pEntry = modes; pEntry; pEntry = pEntry->hh.next) {
        sortModes[pos++] = pEntry->key;
    }
    qsort(sortModes, modesSize, sizeof(int), compare);

    for (int i = 0; i < modesSize; i++) {
        int mode = sortModes[i];
        int l = leftBound(nums, numsSize, mode - k);
        int r = rightBound(nums, numsSize, mode + k);
        int tempAns;
        if (hashFindItem(&numCount, mode)) {
            int count = hashGetItem(&numCount, mode, 0);
            tempAns = fmin(r - l + 1, count + numOperations);
        } else {
            tempAns = fmin(r - l + 1, numOperations);
        }
        if (tempAns > ans) {
            ans = tempAns;
        }
    }

    hashFree(&numCount);
    hashFree(&modes);
    free(sortModes);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> numCount;
        set<int> modes;

        auto addMode = [&](int value) {
            modes.insert(value);
            if (value - k >= nums.front()) {
                modes.insert(value - k);
            }
            if (value + k <= nums.back()) {
                modes.insert(value + k);
            }
        };

        int lastNumIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = max(ans, i - lastNumIndex);
                addMode(nums[lastNumIndex]);
                lastNumIndex = i;
            }
        }

        numCount[nums[lastNumIndex]] = nums.size() - lastNumIndex;
        ans = max(ans, (int)nums.size() - lastNumIndex);
        addMode(nums[lastNumIndex]);

        auto leftBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return left;
        };

        auto rightBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            return left;
        };

        for (int mode : modes) {
            int l = leftBound(mode - k);
            int r = rightBound(mode + k);

            int tempAns;
            if (numCount.count(mode)) {
                tempAns = min(r - l + 1, numCount[mode] + numOperations);
            } else {
                tempAns = min(r - l + 1, numOperations);
            }
            ans = max(ans, tempAns);
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
    public int MaxFrequency(int[] nums, int k, int numOperations) {
        Array.Sort(nums);

        int ans = 0;
        Dictionary<int, int> numCount = new Dictionary<int, int>();
        SortedSet<int> modes = new SortedSet<int>();

        Action<int> addMode = (value) => {
            modes.Add(value);
            if (value - k >= nums[0]) {
                modes.Add(value - k);
            }
            if (value + k <= nums[nums.Length - 1]) {
                modes.Add(value + k);
            }
        };

        int lastNumIndex = 0;
        for (int i = 0; i < nums.Length; ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = Math.Max(ans, i - lastNumIndex);
                addMode(nums[lastNumIndex]);
                lastNumIndex = i;
            }
        }

        numCount[nums[lastNumIndex]] = nums.Length - lastNumIndex;
        ans = Math.Max(ans, nums.Length - lastNumIndex);
        addMode(nums[lastNumIndex]);

        Func<int, int> leftBound = (value) => {
            int left = 0, right = nums.Length - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return left;
        };

        Func<int, int> rightBound = (value) => {
            int left = 0, right = nums.Length - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            return left;
        };

        foreach (int mode in modes) {
            int l = leftBound(mode - k);
            int r = rightBound(mode + k);
            int tempAns;
            if (numCount.ContainsKey(mode)) {
                tempAns = Math.Min(r - l + 1, numCount[mode] + numOperations);
            } else {
                tempAns = Math.Min(r - l + 1, numOperations);
            }
            ans = Math.Max(ans, tempAns);
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxFrequency(nums []int, k int, numOperations int) int {
	sort.Ints(nums)
	ans := 0
	numCount := make(map[int]int)
	modes := make(map[int]bool)

	addMode := func(value int) {
		modes[value] = true
		if value-k >= nums[0] {
			modes[value-k] = true
		}
		if value+k <= nums[len(nums)-1] {
			modes[value+k] = true
		}
	}

	lastNumIndex := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != nums[lastNumIndex] {
			numCount[nums[lastNumIndex]] = i - lastNumIndex
			if i-lastNumIndex > ans {
				ans = i - lastNumIndex
			}
			addMode(nums[lastNumIndex])
			lastNumIndex = i
		}
	}

	numCount[nums[lastNumIndex]] = len(nums) - lastNumIndex
	if len(nums)-lastNumIndex > ans {
		ans = len(nums) - lastNumIndex
	}
	addMode(nums[lastNumIndex])

	leftBound := func(value int) int {
		left, right := 0, len(nums)-1
		for left < right {
			mid := (left + right) / 2
			if nums[mid] < value {
				left = mid + 1
			} else {
				right = mid
			}
		}
		return left
	}

	rightBound := func(value int) int {
		left, right := 0, len(nums)-1
		for left < right {
			mid := (left + right + 1) / 2
			if nums[mid] > value {
				right = mid - 1
			} else {
				left = mid
			}
		}
		return left
	}

	uniqueModes := make([]int, 0, len(modes))
	for mode := range modes {
		uniqueModes = append(uniqueModes, mode)
	}
	sort.Ints(uniqueModes)

	for _, mode := range uniqueModes {
		l := leftBound(mode - k)
		r := rightBound(mode + k)
		var tempAns int
		if count, exists := numCount[mode]; exists {
			tempAns = min(r-l+1, count+numOperations)
		} else {
			tempAns = min(r-l+1, numOperations)
		}
		if tempAns > ans {
			ans = tempAns
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

    public int maxFrequency(int[] nums, int k, int numOperations) {
        Arrays.sort(nums);
        int ans = 0;
        Map<Integer, Integer> numCount = new HashMap<>();
        Set<Integer> modes = new TreeSet<>();

        Consumer<Integer> addMode = value -> {
            modes.add(value);
            if (value - k >= nums[0]) {
                modes.add(value - k);
            }
            if (value + k <= nums[nums.length - 1]) {
                modes.add(value + k);
            }
        };

        int lastNumIndex = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount.put(nums[lastNumIndex], i - lastNumIndex);
                ans = Math.max(ans, i - lastNumIndex);
                addMode.accept(nums[lastNumIndex]);
                lastNumIndex = i;
            }
        }

        numCount.put(nums[lastNumIndex], nums.length - lastNumIndex);
        ans = Math.max(ans, nums.length - lastNumIndex);
        addMode.accept(nums[lastNumIndex]);

        IntUnaryOperator leftBound = value -> {
            int left = 0;
            int right = nums.length - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return left;
        };

        IntUnaryOperator rightBound = value -> {
            int left = 0;
            int right = nums.length - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            return left;
        };

        for (int mode : modes) {
            int l = leftBound.applyAsInt(mode - k);
            int r = rightBound.applyAsInt(mode + k);
            int tempAns;
            if (numCount.containsKey(mode)) {
                tempAns = Math.min(
                    r - l + 1,
                    numCount.get(mode) + numOperations
                );
            } else {
                tempAns = Math.min(r - l + 1, numOperations);
            }
            ans = Math.max(ans, tempAns);
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxFrequency = function (nums, k, numOperations) {
    nums.sort((a, b) => a - b);

    let ans = 0;
    const numCount = new Map();
    const modes = new Set();

    const addMode = (value) => {
        modes.add(value);
        if (value - k >= nums.at(0)) {
            modes.add(value - k);
        }

        if (value + k <= nums.at(-1)) {
            modes.add(value + k);
        }
    };

    let lastNumIndex = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== nums[lastNumIndex]) {
            numCount.set(nums[lastNumIndex], i - lastNumIndex);
            ans = Math.max(ans, i - lastNumIndex);
            addMode(nums[lastNumIndex]);

            lastNumIndex = i;
        }
    }

    numCount.set(nums[lastNumIndex], nums.length - lastNumIndex);
    ans = Math.max(ans, nums.length - lastNumIndex);
    addMode(nums[lastNumIndex]);

    const leftBound = (value) => {
        let left = 0;
        let right = nums.length - 1;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (nums[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    };

    const rightBound = (value) => {
        let left = 0;
        let right = nums.length - 1;
        while (left < right) {
            const mid = Math.floor((left + right + 1) / 2);
            if (nums[mid] > value) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    };

    for (const mode of modes) {
        const [l, r] = [leftBound(mode - k), rightBound(mode + k)];

        let tempAns;

        if (numCount.has(mode)) {
            tempAns = Math.min(r - l + 1, numCount.get(mode) + numOperations);
        } else {
            tempAns = Math.min(r - l + 1, numOperations);
        }

        ans = Math.max(ans, tempAns);
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()
        ans = 0
        num_count = defaultdict(int)
        modes = set()

        def add_mode(value):
            modes.add(value)
            if value - k >= nums[0]:
                modes.add(value - k)
            if value + k <= nums[-1]:
                modes.add(value + k)

        last_num_index = 0
        for i in range(len(nums)):
            if nums[i] != nums[last_num_index]:
                num_count[nums[last_num_index]] = i - last_num_index
                ans = max(ans, i - last_num_index)
                add_mode(nums[last_num_index])
                last_num_index = i

        num_count[nums[last_num_index]] = len(nums) - last_num_index
        ans = max(ans, len(nums) - last_num_index)
        add_mode(nums[last_num_index])

        for mode in sorted(modes):
            l = bisect.bisect_left(nums, mode - k)
            r = bisect.bisect_right(nums, mode + k) - 1
            if mode in num_count:
                temp_ans = min(r - l + 1, num_count[mode] + numOperations)
            else:
                temp_ans = min(r - l + 1, numOperations)
            ans = max(ans, temp_ans)

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxFrequency(
    nums: number[],
    k: number,
    numOperations: number,
): number {
    nums.sort((a, b) => a - b);

    let ans = 0;
    const numCount: Map<number, number> = new Map();
    const modes: Set<number> = new Set();

    const addMode = (value: number) => {
        modes.add(value);
        if (value - k >= nums.at(0)!) {
            modes.add(value - k);
        }

        if (value + k <= nums.at(-1)!) {
            modes.add(value + k);
        }
    };

    let lastNumIndex = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== nums[lastNumIndex]) {
            numCount.set(nums[lastNumIndex], i - lastNumIndex);
            ans = Math.max(ans, i - lastNumIndex);
            addMode(nums[lastNumIndex]);

            lastNumIndex = i;
        }
    }

    numCount.set(nums[lastNumIndex], nums.length - lastNumIndex);
    ans = Math.max(ans, nums.length - lastNumIndex);
    addMode(nums[lastNumIndex]);

    const leftBound = (value: number) => {
        let left = 0;
        let right = nums.length - 1;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (nums[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    };

    const rightBound = (value: number) => {
        let left = 0;
        let right = nums.length - 1;
        while (left < right) {
            const mid = Math.floor((left + right + 1) / 2);
            if (nums[mid] > value) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    };

    for (const mode of modes) {
        const [l, r] = [leftBound(mode - k), rightBound(mode + k)];

        let tempAns: number;

        if (numCount.has(mode)) {
            tempAns = Math.min(r - l + 1, numCount.get(mode)! + numOperations);
        } else {
            tempAns = Math.min(r - l + 1, numOperations);
        }

        ans = Math.max(ans, tempAns);
    }

    return ans;
}
```

</details>
