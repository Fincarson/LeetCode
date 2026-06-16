# 3346. Maximum Frequency of an Element After Performing Operations I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/)  
`Array` `Binary Search` `Sliding Window` `Sorting` `Prefix Sum`

**Problem Link:** [LeetCode 3346 - Maximum Frequency of an Element After Performing Operations I](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/)

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
- 1 <= nums[i] <= 105
- 0 <= k <= 105
- 0 <= numOperations <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3346. Maximum Frequency of an Element After Performing Operations I

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
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

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

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    qsort(nums, numsSize, sizeof(int), compare);
    int ans = 0;
    HashItem* numCount = NULL;
    int lastNumIndex = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != nums[lastNumIndex]) {
            hashSetItem(&numCount, nums[lastNumIndex], i - lastNumIndex);
            ans = fmax(ans, i - lastNumIndex);
            lastNumIndex = i;
        }
    }
    hashSetItem(&numCount, nums[lastNumIndex], numsSize - lastNumIndex);
    ans = fmax(ans, numsSize - lastNumIndex);
    for (int i = nums[0]; i <= nums[numsSize - 1]; i++) {
        int l = leftBound(nums, numsSize, i - k);
        int r = rightBound(nums, numsSize, i + k);
        int tempAns;
        if (hashFindItem(&numCount, i)) {
            tempAns =
                fmin(r - l + 1, hashGetItem(&numCount, i, 0) + numOperations);
        } else {
            tempAns = fmin(r - l + 1, numOperations);
        }
        ans = fmax(ans, tempAns);
    }
    hashFree(&numCount);
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

        int lastNumIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = max(ans, i - lastNumIndex);
                lastNumIndex = i;
            }
        }

        numCount[nums[lastNumIndex]] = nums.size() - lastNumIndex;
        ans = max(ans, (int)nums.size() - lastNumIndex);

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

        for (int i = nums.front(); i <= nums.back(); i++) {
            int l = leftBound(i - k);
            int r = rightBound(i + k);

            int tempAns;
            if (numCount.count(i)) {
                tempAns = min(r - l + 1, numCount[i] + numOperations);
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

        int lastNumIndex = 0;
        for (int i = 0; i < nums.Length; ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = Math.Max(ans, i - lastNumIndex);
                lastNumIndex = i;
            }
        }

        numCount[nums[lastNumIndex]] = nums.Length - lastNumIndex;
        ans = Math.Max(ans, nums.Length - lastNumIndex);

        for (int i = nums[0]; i <= nums[nums.Length - 1]; i++) {
            int l = LeftBound(nums, i - k);
            int r = RightBound(nums, i + k);

            int tempAns;
            if (numCount.ContainsKey(i)) {
                tempAns = Math.Min(r - l + 1, numCount[i] + numOperations);
            } else {
                tempAns = Math.Min(r - l + 1, numOperations);
            }
            ans = Math.Max(ans, tempAns);
        }

        return ans;
    }

    private int LeftBound(int[] nums, int value) {
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
    }

    private int RightBound(int[] nums, int value) {
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

	lastNumIndex := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != nums[lastNumIndex] {
			numCount[nums[lastNumIndex]] = i - lastNumIndex
			ans = max(ans, i-lastNumIndex)
			lastNumIndex = i
		}
	}

	numCount[nums[lastNumIndex]] = len(nums) - lastNumIndex
	ans = max(ans, len(nums)-lastNumIndex)

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

	for i := nums[0]; i <= nums[len(nums)-1]; i++ {
		l := leftBound(i - k)
		r := rightBound(i + k)

		tempAns := 0
		if count, exists := numCount[i]; exists {
			tempAns = min(r-l+1, count+numOperations)
		} else {
			tempAns = min(r-l+1, numOperations)
		}
		ans = max(ans, tempAns)
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

        int lastNumIndex = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount.put(nums[lastNumIndex], i - lastNumIndex);
                ans = Math.max(ans, i - lastNumIndex);
                lastNumIndex = i;
            }
        }

        numCount.put(nums[lastNumIndex], nums.length - lastNumIndex);
        ans = Math.max(ans, nums.length - lastNumIndex);

        for (int i = nums[0]; i <= nums[nums.length - 1]; i++) {
            int l = leftBound(nums, i - k);
            int r = rightBound(nums, i + k);
            int tempAns;
            if (numCount.containsKey(i)) {
                tempAns = Math.min(r - l + 1, numCount.get(i) + numOperations);
            } else {
                tempAns = Math.min(r - l + 1, numOperations);
            }
            ans = Math.max(ans, tempAns);
        }

        return ans;
    }

    private int leftBound(int[] nums, int value) {
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
    }

    private int rightBound(int[] nums, int value) {
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

    let lastNumIndex = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== nums[lastNumIndex]) {
            numCount.set(nums[lastNumIndex], i - lastNumIndex);
            ans = Math.max(ans, i - lastNumIndex);

            lastNumIndex = i;
        }
    }

    numCount.set(nums[lastNumIndex], nums.length - lastNumIndex);
    ans = Math.max(ans, nums.length - lastNumIndex);

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

    for (let i = nums.at(0); i <= nums.at(-1); i++) {
        const [l, r] = [leftBound(i - k), rightBound(i + k)];

        let tempAns;

        if (numCount.has(i)) {
            tempAns = Math.min(r - l + 1, numCount.get(i) + numOperations);
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
        num_count = {}
        last_num_index = 0
        for i in range(len(nums)):
            if nums[i] != nums[last_num_index]:
                num_count[nums[last_num_index]] = i - last_num_index
                ans = max(ans, i - last_num_index)
                last_num_index = i

        num_count[nums[last_num_index]] = len(nums) - last_num_index
        ans = max(ans, len(nums) - last_num_index)

        for i in range(nums[0], nums[-1] + 1):
            l = bisect.bisect_left(nums, i - k)
            r = bisect.bisect_right(nums, i + k) - 1
            if i in num_count:
                temp_ans = min(r - l + 1, num_count[i] + numOperations)
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

    let lastNumIndex = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== nums[lastNumIndex]) {
            numCount.set(nums[lastNumIndex], i - lastNumIndex);
            ans = Math.max(ans, i - lastNumIndex);
            lastNumIndex = i;
        }
    }

    numCount.set(nums[lastNumIndex], nums.length - lastNumIndex);
    ans = Math.max(ans, nums.length - lastNumIndex);

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

    for (let i = nums.at(0)!; i <= nums.at(-1)!; i++) {
        const [l, r] = [leftBound(i - k), rightBound(i + k)];

        let tempAns;

        if (numCount.has(i)) {
            tempAns = Math.min(r - l + 1, numCount.get(i)! + numOperations);
        } else {
            tempAns = Math.min(r - l + 1, numOperations);
        }

        ans = Math.max(ans, tempAns);
    }

    return ans;
}
```

</details>
