# 1674. Minimum Moves to Make Array Complementary

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/)  
`Array` `Hash Table` `Prefix Sum`

**Problem Link:** [LeetCode 1674 - Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/)

## Problem

You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.

The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.

Return the minimum number of moves required to make nums complementary.

### Example 1

```text
Input: nums = [1,2,4,3], limit = 4
Output: 1
Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements are changed).
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
```

### Example 2

```text
Input: nums = [1,2,2,1], limit = 2
Output: 2
Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot change any number to 3 since 3 > limit.
```

### Example 3

```text
Input: nums = [1,2,1,2], limit = 2
Output: 0
Explanation: nums is already complementary.
```

## Constraints

- n == nums.length
- 2 <= n <= 105
- 1 <= nums[i] <= limit <= 105
- n is even.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Zero Array Transformation II](https://leetcode.com/problems/zero-array-transformation-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Zero Array Transformation III](https://leetcode.com/problems/zero-array-transformation-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1674. Minimum Moves to Make Array Complementary

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Difference | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Difference

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minMoves(int* nums, int numsSize, int limit) {
    int n = numsSize;
    int* diff = (int*)calloc(2 * limit + 2, sizeof(int));

    for (int i = 0; i < n / 2; i++) {
        int a = fmin(nums[i], nums[n - 1 - i]);
        int b = fmax(nums[i], nums[n - 1 - i]);

        diff[2] += 2;
        diff[a + 1] -= 1;
        diff[a + b] -= 1;
        diff[a + b + 1] += 1;
        diff[b + limit + 1] += 1;
    }

    int minOps = n;
    int currentOps = 0;

    for (int c = 2; c <= 2 * limit; c++) {
        currentOps += diff[c];
        if (currentOps < minOps) {
            minOps = currentOps;
        }
    }

    free(diff);
    return minOps;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[b + limit + 1] += 1;
        }

        int min_ops = n;
        int current_ops = 0;

        for (int c = 2; c <= 2 * limit; ++c) {
            current_ops += diff[c];
            min_ops = min(min_ops, current_ops);
        }

        return min_ops;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinMoves(int[] nums, int limit) {
        int n = nums.Length;
        int[] diff = new int[2 * limit + 2];

        for (int i = 0; i < n / 2; i++) {
            int a = Math.Min(nums[i], nums[n - 1 - i]);
            int b = Math.Max(nums[i], nums[n - 1 - i]);

            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[b + limit + 1] += 1;
        }

        int minOps = n;
        int currentOps = 0;

        for (int c = 2; c <= 2 * limit; c++) {
            currentOps += diff[c];
            minOps = Math.Min(minOps, currentOps);
        }

        return minOps;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minMoves(nums []int, limit int) int {
	n := len(nums)
	diff := make([]int, 2*limit+2)

	for i := 0; i < n/2; i++ {
		a := min(nums[i], nums[n-1-i])
		b := max(nums[i], nums[n-1-i])

		diff[2] += 2
		diff[a+1] -= 1
		diff[a+b] -= 1
		diff[a+b+1] += 1
		diff[b+limit+1] += 1
	}

	minOps := n
	currentOps := 0

	for c := 2; c <= 2*limit; c++ {
		currentOps += diff[c]
		minOps = min(minOps, currentOps)
	}

	return minOps
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minMoves(int[] nums, int limit) {
        int n = nums.length;
        int[] diff = new int[2 * limit + 2];

        for (int i = 0; i < n / 2; i++) {
            int a = Math.min(nums[i], nums[n - 1 - i]);
            int b = Math.max(nums[i], nums[n - 1 - i]);

            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[b + limit + 1] += 1;
        }

        int minOps = n;
        int currentOps = 0;

        for (int c = 2; c <= 2 * limit; c++) {
            currentOps += diff[c];
            minOps = Math.min(minOps, currentOps);
        }

        return minOps;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minMoves = function (nums, limit) {
    const n = nums.length;
    const diff = new Array(2 * limit + 2).fill(0);

    for (let i = 0; i < n / 2; i++) {
        const a = Math.min(nums[i], nums[n - 1 - i]);
        const b = Math.max(nums[i], nums[n - 1 - i]);

        diff[2] += 2;
        diff[a + 1] -= 1;
        diff[a + b] -= 1;
        diff[a + b + 1] += 1;
        diff[b + limit + 1] += 1;
    }

    let minOps = n;
    let currentOps = 0;

    for (let c = 2; c <= 2 * limit; c++) {
        currentOps += diff[c];
        minOps = Math.min(minOps, currentOps);
    }

    return minOps;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        diff = [0] * (2 * limit + 2)

        for i in range(n // 2):
            a = min(nums[i], nums[n - 1 - i])
            b = max(nums[i], nums[n - 1 - i])

            diff[2] += 2
            diff[a + 1] -= 1
            diff[a + b] -= 1
            diff[a + b + 1] += 1
            diff[b + limit + 1] += 1

        min_ops = n
        current_ops = 0

        for c in range(2, 2 * limit + 1):
            current_ops += diff[c]
            if current_ops < min_ops:
                min_ops = current_ops

        return min_ops
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minMoves(nums: number[], limit: number): number {
    const n = nums.length;
    const diff = new Array(2 * limit + 2).fill(0);

    for (let i = 0; i < n / 2; i++) {
        const a = Math.min(nums[i], nums[n - 1 - i]);
        const b = Math.max(nums[i], nums[n - 1 - i]);

        diff[2] += 2;
        diff[a + 1] -= 1;
        diff[a + b] -= 1;
        diff[a + b + 1] += 1;
        diff[b + limit + 1] += 1;
    }

    let minOps = n;
    let currentOps = 0;

    for (let c = 2; c <= 2 * limit; c++) {
        currentOps += diff[c];
        minOps = Math.min(minOps, currentOps);
    }

    return minOps;
}
```

</details>

<br>

## Approach 2: Binary Search

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

int lowerBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int minMoves(int* nums, int numsSize, int limit) {
    int n = numsSize;
    int half = n / 2;

    HashItem* sumCount = NULL;
    int* minArr = (int*)malloc(half * sizeof(int));
    int* maxArr = (int*)malloc(half * sizeof(int));

    for (int i = 0; i < half; i++) {
        int a = fmin(nums[i], nums[n - 1 - i]);
        int b = fmax(nums[i], nums[n - 1 - i]);

        int sum = a + b;
        int currentCount = hashGetItem(&sumCount, sum, 0);
        hashSetItem(&sumCount, sum, currentCount + 1);

        minArr[i] = a;
        maxArr[i] = b;
    }

    qsort(minArr, half, sizeof(int), compare);
    qsort(maxArr, half, sizeof(int), compare);

    int minOps = n;

    for (int c = 2; c <= 2 * limit; c++) {
        int addLeft = half - lowerBound(minArr, half, c);
        int addRight = lowerBound(maxArr, half, c - limit);

        int currentOps =
            half + addLeft + addRight - hashGetItem(&sumCount, c, 0);
        if (currentOps < minOps) {
            minOps = currentOps;
        }
    }

    free(minArr);
    free(maxArr);
    hashFree(&sumCount);

    return minOps;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        unordered_map<int, int> sum_count;
        vector<int> min_arr, max_arr;
        min_arr.reserve(n / 2);
        max_arr.reserve(n / 2);

        for (int i = 0; i < n / 2; ++i) {
            int a = std::min(nums[i], nums[n - 1 - i]);
            int b = std::max(nums[i], nums[n - 1 - i]);

            sum_count[a + b]++;
            min_arr.push_back(a);
            max_arr.push_back(b);
        }

        std::sort(min_arr.begin(), min_arr.end());
        std::sort(max_arr.begin(), max_arr.end());

        int min_ops = n;

        for (int c = 2; c <= 2 * limit; ++c) {
            int add_left =
                n / 2 - (lower_bound(min_arr.begin(), min_arr.end(), c) -
                         min_arr.begin());
            int add_right =
                lower_bound(max_arr.begin(), max_arr.end(), c - limit) -
                max_arr.begin();

            int current_ops = n / 2 + add_left + add_right - sum_count[c];
            min_ops = min(min_ops, current_ops);
        }

        return min_ops;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinMoves(int[] nums, int limit) {
        int n = nums.Length;
        var sumCount = new Dictionary<int, int>();
        var minArr = new int[n / 2];
        var maxArr = new int[n / 2];

        for (int i = 0; i < n / 2; i++) {
            int a = Math.Min(nums[i], nums[n - 1 - i]);
            int b = Math.Max(nums[i], nums[n - 1 - i]);

            int sum = a + b;
            sumCount[sum] = sumCount.GetValueOrDefault(sum) + 1;

            minArr[i] = a;
            maxArr[i] = b;
        }

        Array.Sort(minArr);
        Array.Sort(maxArr);

        int LowerBound(int[] arr, int target) {
            int left = 0, right = arr.Length;
            while (left < right) {
                int mid = left + ((right - left) >>> 1);
                if (arr[mid] >= target) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

        int minOps = n;

        for (int c = 2; c <= 2 * limit; c++) {
            int addLeft = n / 2 - LowerBound(minArr, c);
            int addRight = LowerBound(maxArr, c - limit);

            int currentOps =
                n / 2 + addLeft + addRight - sumCount.GetValueOrDefault(c);
            minOps = Math.Min(minOps, currentOps);
        }

        return minOps;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minMoves(nums []int, limit int) int {
	n := len(nums)
	sumCount := make(map[int]int)
	minArr := make([]int, n/2)
	maxArr := make([]int, n/2)

	for i := 0; i < n/2; i++ {
		a := min(nums[i], nums[n-1-i])
		b := max(nums[i], nums[n-1-i])

		sumCount[a+b]++
		minArr[i] = a
		maxArr[i] = b
	}

	sort.Ints(minArr)
	sort.Ints(maxArr)
	minOps := n

	for c := 2; c <= 2*limit; c++ {
		addLeft := n/2 - lowerBound(minArr, c)
		addRight := lowerBound(maxArr, c-limit)

		currentOps := n/2 + addLeft + addRight - sumCount[c]
		minOps = min(minOps, currentOps)
	}

	return minOps
}

func lowerBound(arr []int, target int) int {
	left, right := 0, len(arr)
	for left < right {
		mid := (left + right) / 2
		if arr[mid] >= target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minMoves(int[] nums, int limit) {
        int n = nums.length;
        Map<Integer, Integer> sumCount = new HashMap<>();
        int[] minArr = new int[n / 2];
        int[] maxArr = new int[n / 2];

        for (int i = 0; i < n / 2; i++) {
            int a = Math.min(nums[i], nums[n - 1 - i]);
            int b = Math.max(nums[i], nums[n - 1 - i]);

            sumCount.merge(a + b, 1, Integer::sum);
            minArr[i] = a;
            maxArr[i] = b;
        }

        Arrays.sort(minArr);
        Arrays.sort(maxArr);

        int minOps = n;

        for (int c = 2; c <= 2 * limit; c++) {
            int addLeft = n / 2 - lowerBound(minArr, c);
            int addRight = lowerBound(maxArr, c - limit);

            int currentOps =
                n / 2 + addLeft + addRight - sumCount.getOrDefault(c, 0);
            minOps = Math.min(minOps, currentOps);
        }

        return minOps;
    }

    private int lowerBound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (arr[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
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
var minMoves = function (nums, limit) {
    const n = nums.length;
    const sumCount = new Map();
    const minArr = [];
    const maxArr = [];

    for (let i = 0; i < n / 2; i++) {
        const a = Math.min(nums[i], nums[n - 1 - i]);
        const b = Math.max(nums[i], nums[n - 1 - i]);

        const sum = a + b;
        sumCount.set(sum, (sumCount.get(sum) ?? 0) + 1);

        minArr.push(a);
        maxArr.push(b);
    }

    minArr.sort((x, y) => x - y);
    maxArr.sort((x, y) => x - y);

    const lowerBound = (arr, target) => {
        let left = 0,
            right = arr.length;
        while (left < right) {
            const mid = left + ((right - left) >>> 1);
            if (arr[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };

    let minOps = n;

    for (let c = 2; c <= 2 * limit; c++) {
        const addLeft = n / 2 - lowerBound(minArr, c);
        const addRight = lowerBound(maxArr, c - limit);

        const currentOps = n / 2 + addLeft + addRight - (sumCount.get(c) ?? 0);
        minOps = Math.min(minOps, currentOps);
    }

    return minOps;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        sum_count = Counter()
        min_arr = []
        max_arr = []

        for i in range(n // 2):
            a = min(nums[i], nums[n - 1 - i])
            b = max(nums[i], nums[n - 1 - i])

            sum_count[a + b] += 1
            min_arr.append(a)
            max_arr.append(b)

        min_arr.sort()
        max_arr.sort()

        min_ops = n

        for c in range(2, 2 * limit + 1):
            add_left = n // 2 - bisect_left(min_arr, c)
            add_right = bisect_left(max_arr, c - limit)

            current_ops = n // 2 + add_left + add_right - sum_count[c]
            min_ops = min(min_ops, current_ops)

        return min_ops
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minMoves(nums: number[], limit: number): number {
    const n = nums.length;

    const sumCount = new Map<number, number>();
    const minArr: number[] = [];
    const maxArr: number[] = [];

    for (let i = 0; i < n / 2; i++) {
        const a = Math.min(nums[i], nums[n - 1 - i]);
        const b = Math.max(nums[i], nums[n - 1 - i]);

        const sum = a + b;
        sumCount.set(sum, (sumCount.get(sum) ?? 0) + 1);

        minArr.push(a);
        maxArr.push(b);
    }

    minArr.sort((x, y) => x - y);
    maxArr.sort((x, y) => x - y);

    const lowerBound = (arr: number[], target: number): number => {
        let left = 0,
            right = arr.length;
        while (left < right) {
            const mid = left + Math.floor((right - left) >>> 1);
            if (arr[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };

    let minOps = n;

    for (let c = 2; c <= 2 * limit; c++) {
        const addLeft = n / 2 - lowerBound(minArr, c);
        const addRight = lowerBound(maxArr, c - limit);

        const currentOps = n / 2 + addLeft + addRight - (sumCount.get(c) ?? 0);
        minOps = Math.min(minOps, currentOps);
    }

    return minOps;
}
```

</details>
