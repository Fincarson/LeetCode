# 3660. Jump Game IX

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/jump-game-ix/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 3660 - Jump Game IX](https://leetcode.com/problems/jump-game-ix/)

## Problem

You are given an integer array nums.

From any index i, you can jump to another index j under the following rules:

- Jump to index j where j > i is allowed only if nums[j] < nums[i].
- Jump to index j where j < i is allowed only if nums[j] > nums[i].

For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.

Return an array ans where ans[i] is the maximum value reachable starting from index i.

### Example 1

### Example 2

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

# Editorial - 3660. Jump Game IX

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Interval Divide and Conquer | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Monotonic Stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Interval Divide and Conquer

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int value;
    int index;
} Item;

void process(int* nums, int* ans, Item* prevMax, int r, int rightMin,
             int rightMax) {
    int pMax = prevMax[r].value;
    int pivotIndex = prevMax[r].index;

    int currMax = (pMax <= rightMin) ? pMax : rightMax;

    int nextRightMin = (pMax < rightMin) ? pMax : rightMin;
    for (int i = pivotIndex; i <= r; i++) {
        ans[i] = currMax;
        if (nums[i] < nextRightMin) {
            nextRightMin = nums[i];
        }
    }

    if (pivotIndex == 0) {
        return;
    }

    process(nums, ans, prevMax, pivotIndex - 1, nextRightMin, currMax);
}

int* maxValue(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    memset(ans, 0, numsSize * sizeof(int));
    Item* prevMax = (Item*)malloc(numsSize * sizeof(Item));

    Item prev = {INT_MIN, -1};
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > prev.value) {
            prev.value = nums[i];
            prev.index = i;
        }
        prevMax[i] = prev;
    }

    process(nums, ans, prevMax, numsSize - 1, INT_MAX, 0);

    free(prevMax);
    *returnSize = numsSize;
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        // [value, index]
        using Item = pair<int, int>;
        vector<Item> prevMax(n);

        Item prev = {INT_MIN, -1};
        for (int i = 0; i < n; ++i) {
            if (nums[i] > prev.first) {
                prev = {nums[i], i};
            }
            prevMax[i] = prev;
        }

        auto process = [&](auto& self, int r, int rightMin,
                           int rightMax) -> void {
            auto [pMax, pivotIndex] = prevMax[r];
            int currMax = pMax <= rightMin ? pMax : rightMax;

            int nextRightMin = min(pMax, rightMin);
            for (int i = pivotIndex; i <= r; ++i) {
                ans[i] = currMax;
                nextRightMin = min(nextRightMin, nums[i]);
            }

            if (pivotIndex == 0) {
                return;
            }

            self(self, pivotIndex - 1, nextRightMin, currMax);
        };

        process(process, n - 1, INT_MAX, 0);

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] MaxValue(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];
        // [value, index]
        (int Value, int Index)[] prevMax = new(int, int)[n];

        (int Value, int Index) prev = (int.MinValue, -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] > prev.Value) {
                prev = (nums[i], i);
            }
            prevMax[i] = prev;
        }

        void Process(int r, int rightMin, int rightMax) {
            var (pMax, pivotIndex) = prevMax[r];
            int currMax = pMax <= rightMin ? pMax : rightMax;

            int nextRightMin = Math.Min(pMax, rightMin);
            for (int i = pivotIndex; i <= r; i++) {
                ans[i] = currMax;
                nextRightMin = Math.Min(nextRightMin, nums[i]);
            }

            if (pivotIndex == 0) {
                return;
            }

            Process(pivotIndex - 1, nextRightMin, currMax);
        }

        Process(n - 1, int.MaxValue, 0);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxValue(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)

	// [value, index] Ã¥Â¯Â¹
	type Item struct {
		value int
		index int
	}
	prevMax := make([]Item, n)

	prev := Item{math.MinInt32, -1}
	for i := 0; i < n; i++ {
		if nums[i] > prev.value {
			prev = Item{nums[i], i}
		}
		prevMax[i] = prev
	}

	var process func(r int, rightMin int, rightMax int)
	process = func(r int, rightMin int, rightMax int) {
		pMax := prevMax[r].value
		pivotIndex := prevMax[r].index

		currMax := pMax
		if pMax <= rightMin {
			currMax = pMax
		} else {
			currMax = rightMax
		}

		nextRightMin := rightMin
		if pMax < nextRightMin {
			nextRightMin = pMax
		}
		for i := pivotIndex; i <= r; i++ {
			ans[i] = currMax
			if nums[i] < nextRightMin {
				nextRightMin = nums[i]
			}
		}

		if pivotIndex == 0 {
			return
		}

		process(pivotIndex-1, nextRightMin, currMax)
	}

	process(n-1, math.MaxInt32, 0)

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // [value, index]
    record Item(int value, int index) {}

    public int[] maxValue(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Item[] prevMax = new Item[n];

        Item prev = new Item(Integer.MIN_VALUE, -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] > prev.value()) {
                prev = new Item(nums[i], i);
            }
            prevMax[i] = prev;
        }

        process(n - 1, Integer.MAX_VALUE, 0, prevMax, ans, nums);
        return ans;
    }

    private void process(
        int r,
        int rightMin,
        int rightMax,
        Item[] prevMax,
        int[] ans,
        int[] nums
    ) {
        int pMax = prevMax[r].value();
        int pivotIndex = prevMax[r].index();

        int currMax = pMax <= rightMin ? pMax : rightMax;

        int nextRightMin = Math.min(pMax, rightMin);
        for (int i = pivotIndex; i <= r; i++) {
            ans[i] = currMax;
            nextRightMin = Math.min(nextRightMin, nums[i]);
        }

        if (pivotIndex == 0) {
            return;
        }

        process(pivotIndex - 1, nextRightMin, currMax, prevMax, ans, nums);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxValue = function (nums) {
    const n = nums.length;
    const ans = new Array(n).fill(0);

    const prevMax = new Array(n);

    nums.reduce(
        (prev, value, index) => {
            if (value > prev[0]) {
                prev = [value, index];
            }
            return (prevMax[index] = [...prev]);
        },
        [-Infinity, -1],
    );

    const process = (r, rightMin, rightMax) => {
        const [pMax, pivotIndex] = prevMax[r];
        const currMax = pMax <= rightMin ? pMax : rightMax;

        let nextRightMin = Math.min(pMax, rightMin);
        for (let i = pivotIndex; i <= r; i++) {
            ans[i] = currMax;
            nextRightMin = Math.min(nextRightMin, nums[i]);
        }

        if (pivotIndex === 0) {
            return;
        }

        process(pivotIndex - 1, nextRightMin, currMax);
    };

    process(n - 1, Infinity, 0);

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)

        ans = [0] * n
        # [value, index]
        prev_max = [(0, 0)] * n

        prev = (-math.inf, -1)
        for i, value in enumerate(nums):
            if value > prev[0]:
                prev = (value, i)
            prev_max[i] = prev

        def process(r: int, right_min: float, right_max: float) -> None:
            p_max, pivot_index = prev_max[r]
            curr_max = p_max if p_max <= right_min else right_max

            next_right_min = min(p_max, right_min)
            for i in range(pivot_index, r + 1):
                ans[i] = curr_max
                next_right_min = min(next_right_min, nums[i])

            if pivot_index == 0:
                return

            process(pivot_index - 1, next_right_min, curr_max)

        process(n - 1, math.inf, 0)

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Item = [number, number]; // [value, index]

function maxValue(nums: number[]): number[] {
    const n = nums.length;
    const ans = new Array<number>(n).fill(0);

    const prevMax: Item[] = new Array(n);

    nums.reduce(
        (prev, value, index) => {
            if (value > prev[0]) {
                prev = [value, index];
            }
            return (prevMax[index] = [...prev]);
        },
        [-Infinity, -1] as Item,
    );

    const process = (r: number, rightMin: number, rightMax: number) => {
        const [pMax, pivotIndex] = prevMax[r];
        const currMax = pMax <= rightMin ? pMax : rightMax;

        let nextRightMin = Math.min(pMax, rightMin);
        for (let i = pivotIndex; i <= r; i++) {
            ans[i] = currMax;
            nextRightMin = Math.min(nextRightMin, nums[i]);
        }

        if (pivotIndex === 0) {
            return;
        }

        process(pivotIndex - 1, nextRightMin, currMax);
    };

    process(n - 1, Infinity, 0);

    return ans;
}
```

</details>

<br>

## Approach 2: Monotonic Stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int value;
    int left;
    int right;
} Item;

int* maxValue(const int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    memset(ans, 0, numsSize * sizeof(int));

    Item* stack = (Item*)malloc(numsSize * sizeof(Item));
    int stackSize = 0;
    for (int i = 0; i < numsSize; i++) {
        Item curr = {nums[i], i, i};
        while (stackSize > 0 && stack[stackSize - 1].value > nums[i]) {
            Item top = stack[stackSize - 1];
            stackSize--;
            curr.value = (top.value > curr.value) ? top.value : curr.value;
            curr.left = top.left;
        }

        stack[stackSize++] = curr;
    }

    for (int i = 0; i < stackSize; i++) {
        for (int j = stack[i].left; j <= stack[i].right; j++) {
            ans[j] = stack[i].value;
        }
    }

    free(stack);
    *returnSize = numsSize;
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    struct Item {
        int value;
        int left;
        int right;
    };

    vector<int> maxValue(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        vector<Item> stack;

        for (int i = 0; i < n; ++i) {
            Item curr = {nums[i], i, i};

            while (!stack.empty() && stack.back().value > nums[i]) {
                Item top = stack.back();
                stack.pop_back();
                curr.value = max(curr.value, top.value);
                curr.left = top.left;
            }

            stack.push_back(curr);
        }

        for (size_t i = 0; i < stack.size(); ++i) {
            for (int j = stack[i].left; j <= stack[i].right; ++j) {
                ans[j] = stack[i].value;
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
public class Solution {
    public int[] MaxValue(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];

        List<(int Value, int Left, int Right)> stack = new();

        for (int i = 0; i < n; i++) {
            var curr = (Value: nums[i], Left: i, Right: i);

            while (stack.Count > 0 && stack[^1].Value > nums[i]) {
                var top = stack[^1];
                stack.RemoveAt(stack.Count - 1);
                curr = (Math.Max(curr.Value, top.Value), top.Left, curr.Right);
            }

            stack.Add(curr);
        }

        for (int i = 0; i < stack.Count; i++) {
            for (int j = stack[i].Left; j <= stack[i].Right; j++) {
                ans[j] = stack[i].Value;
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
func maxValue(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)

	type Item struct {
		value int
		left  int
		right int
	}

	stack := make([]Item, 0)
	for i := 0; i < n; i++ {
		curr := Item{nums[i], i, i}

		for len(stack) > 0 && stack[len(stack)-1].value > nums[i] {
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if top.value > curr.value {
				curr.value = top.value
			}
			curr.left = top.left
		}

		stack = append(stack, curr)
	}

	for i := 0; i < len(stack); i++ {
		for j := stack[i].left; j <= stack[i].right; j++ {
			ans[j] = stack[i].value
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

    record Item(int value, int left, int right) {}

    public int[] maxValue(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];

        List<Item> stack = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            Item curr = new Item(nums[i], i, i);

            while (!stack.isEmpty() && stack.getLast().value() > nums[i]) {
                Item top = stack.removeLast();
                curr = new Item(
                    Math.max(curr.value(), top.value()),
                    top.left(),
                    curr.right()
                );
            }

            stack.add(curr);
        }

        for (int i = 0; i < stack.size(); i++) {
            for (int j = stack.get(i).left(); j <= stack.get(i).right(); j++) {
                ans[j] = stack.get(i).value();
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxValue = function (nums) {
    const n = nums.length;
    const ans = new Array(n);

    const stack = [];

    for (let i = 0; i < n; i++) {
        let curr = {
            value: nums[i],
            left: i,
            right: i,
        };

        while (stack.length > 0 && stack.at(-1).value > nums[i]) {
            const top = stack.pop();
            curr = {
                value: Math.max(curr.value, top.value),
                left: top.left,
                right: curr.right,
            };
        }

        stack.push(curr);
    }

    for (let i = 0; i < stack.length; i++) {
        for (let j = stack[i].left; j <= stack[i].right; j++) {
            ans[j] = stack[i].value;
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        # [value, left, right]
        stack = []

        for i in range(n):
            curr_val = nums[i]
            curr_left = i
            curr_right = i

            while stack and stack[-1][0] > nums[i]:
                top_val, top_left, top_right = stack.pop()
                curr_val = max(curr_val, top_val)
                curr_left = top_left

            stack.append((curr_val, curr_left, curr_right))

        for i in range(len(stack)):
            for j in range(stack[i][1], stack[i][2] + 1):
                ans[j] = stack[i][0]

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
interface Item {
    value: number;
    left: number;
    right: number;
}

function maxValue(nums: number[]): number[] {
    const n = nums.length;
    const ans = new Array<number>(n);

    const stack: Item[] = [];

    for (let i = 0; i < n; i++) {
        let curr: Item = {
            value: nums[i],
            left: i,
            right: i,
        };

        while (stack.length > 0 && stack.at(-1)!.value > nums[i]) {
            const top = stack.pop()!;
            curr = {
                value: Math.max(curr.value, top.value),
                left: top.left,
                right: curr.right,
            };
        }

        stack.push(curr);
    }

    for (let i = 0; i < stack.length; i++) {
        for (let j = stack[i].left; j <= stack[i].right; j++) {
            ans[j] = stack[i].value;
        }
    }

    return ans;
}
```

</details>
