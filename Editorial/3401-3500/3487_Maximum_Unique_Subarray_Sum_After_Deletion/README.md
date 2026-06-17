# 3487. Maximum Unique Subarray Sum After Deletion

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/)  
`Array` `Hash Table` `Greedy`

**Problem Link:** [LeetCode 3487 - Maximum Unique Subarray Sum After Deletion](https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/)

## Problem

You are given an integer array nums.

You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:

Return the maximum sum of such a subarray.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 100
- -100 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Subarray Sum with One Deletion](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3487. Maximum Unique Subarray Sum After Deletion

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Duplicate Removal for Positive Numbers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Duplicate Removal for Positive Numbers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int maxSum(int *nums, int numsSize) {
    HashItem *positiveNumsSet = NULL;
    int maxNum = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            hashAddItem(&positiveNumsSet, nums[i]);
        }
        maxNum = fmax(maxNum, nums[i]);
    }
    if (HASH_COUNT(positiveNumsSet) == 0) {
        hashFree(&positiveNumsSet);
        return maxNum;
    }
    int sum = 0;
    for (HashItem *pEntry = positiveNumsSet; pEntry; pEntry = pEntry->hh.next) {
        sum += pEntry->key;
    }
    hashFree(&positiveNumsSet);
    return sum;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> positiveNumsSet;
        for (int num : nums) {
            if (num > 0) {
                positiveNumsSet.emplace(num);
            }
        }
        if (positiveNumsSet.empty()) {
            return *max_element(nums.begin(), nums.end());
        }
        return accumulate(positiveNumsSet.begin(), positiveNumsSet.end(), 0);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxSum(int[] nums) {
        HashSet<int> positiveNumsSet = new HashSet<int>();
        foreach (int num in nums) {
            if (num > 0) {
                positiveNumsSet.Add(num);
            }
        }
        if (positiveNumsSet.Count == 0) {
            return nums.Max();
        }
        return positiveNumsSet.Sum();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxSum(nums []int) int {
	positiveNumsSet := make(map[int]bool)
	maxNum := nums[0]
	for _, num := range nums {
		if num > 0 {
			positiveNumsSet[num] = true
		}
		maxNum = max(maxNum, num)
	}

	if len(positiveNumsSet) == 0 {
		return maxNum
	}
	sum := 0
	for num := range positiveNumsSet {
		sum += num
	}
	return sum
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxSum(int[] nums) {
        Set<Integer> positiveNumsSet = new HashSet<>();
        for (int num : nums) {
            if (num > 0) {
                positiveNumsSet.add(num);
            }
        }
        if (positiveNumsSet.isEmpty()) {
            return Arrays.stream(nums).max().getAsInt();
        }
        return positiveNumsSet.stream().mapToInt(Integer::intValue).sum();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSum = function (nums) {
    const positiveNumsSet = new Set(nums.filter((num) => num > 0));
    return positiveNumsSet.size === 0
        ? Math.max(...nums)
        : [...positiveNumsSet].reduce((a, b) => a + b, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSum(self, nums: List[int]) -> int:
        positiveNumsSet = set([num for num in nums if num > 0])
        return max(nums) if len(positiveNumsSet) == 0 else sum(positiveNumsSet)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxSum(nums: number[]): number {
    const positiveNumsSet = new Set(nums.filter((num) => num > 0));
    return positiveNumsSet.size === 0
        ? Math.max(...nums)
        : [...positiveNumsSet].reduce((a, b) => a + b, 0);
}
```

</details>
