# 3507. Minimum Pair Removal to Sort Array I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/)  
`Array` `Hash Table` `Linked List` `Heap (Priority Queue)` `Simulation` `Doubly-Linked List` `Ordered Set`

**Problem Link:** [LeetCode 3507 - Minimum Pair Removal to Sort Array I](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/)

## Problem

Given an array nums, you can perform the following operation any number of times:

- Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
- Replace the pair with their sum.

Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 50
- -1000 <= nums[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3507. Minimum Pair Removal to Sort Array I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Simulation + Array Simulation of Linked List | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumPairRemoval(int* nums, int numsSize) {
    int count = 0;
    int size = numsSize;

    while (size > 1) {
        int isAscending = 1;
        int minSum = INT_MAX;
        int targetIndex = -1;
        for (int i = 0; i < size - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (nums[i] > nums[i + 1]) {
                isAscending = 0;
            }
            if (sum < minSum) {
                minSum = sum;
                targetIndex = i;
            }
        }

        if (isAscending) {
            break;
        }
        count++;
        nums[targetIndex] = minSum;
        for (int i = targetIndex + 1; i < size - 1; i++) {
            nums[i] = nums[i + 1];
        }
        size--;
    }

    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int count = 0;

        while (nums.size() > 1) {
            bool isAscending = true;
            int minSum = std::numeric_limits<int>::max();
            int targetIndex = -1;

            for (size_t i = 0; i < nums.size() - 1; ++i) {
                int sum = nums[i] + nums[i + 1];

                if (nums[i] > nums[i + 1]) {
                    isAscending = false;
                }

                if (sum < minSum) {
                    minSum = sum;
                    targetIndex = static_cast<int>(i);
                }
            }

            if (isAscending) {
                break;
            }

            count++;
            nums[targetIndex] = minSum;
            nums.erase(nums.begin() + targetIndex + 1);
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumPairRemoval(int[] nums) {
        var count = 0;
        var list = nums.ToList();

        while (list.Count > 1) {
            var isAscending = true;
            var minSum = int.MaxValue;
            var targetIndex = -1;

            for (var i = 0; i < list.Count - 1; i++) {
                var sum = list[i] + list[i + 1];

                if (list[i] > list[i + 1]) {
                    isAscending = false;
                }

                if (sum < minSum) {
                    minSum = sum;
                    targetIndex = i;
                }
            }

            if (isAscending) {
                break;
            }

            count++;
            list[targetIndex] = minSum;
            list.RemoveAt(targetIndex + 1);
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumPairRemoval(nums []int) int {
	count := 0

	for len(nums) > 1 {
		isAscending := true
		minSum := 1<<31 - 1
		targetIndex := -1

		for i := 0; i < len(nums)-1; i++ {
			sum := nums[i] + nums[i+1]
			if nums[i] > nums[i+1] {
				isAscending = false
			}
			if sum < minSum {
				minSum = sum
				targetIndex = i
			}
		}

		if isAscending {
			break
		}
		count++
		nums[targetIndex] = minSum
		nums = append(nums[:targetIndex+1], nums[targetIndex+2:]...)
	}

	return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumPairRemoval(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }
        var count = 0;

        while (list.size() > 1) {
            var isAscending = true;
            var minSum = Integer.MAX_VALUE;
            var targetIndex = -1;

            for (var i = 0; i < list.size() - 1; i++) {
                var sum = list.get(i) + list.get(i + 1);

                if (list.get(i) > list.get(i + 1)) {
                    isAscending = false;
                }

                if (sum < minSum) {
                    minSum = sum;
                    targetIndex = i;
                }
            }

            if (isAscending) {
                break;
            }

            count++;
            list.set(targetIndex, minSum);
            list.remove(targetIndex + 1);
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumPairRemoval = function (nums) {
    let count = 0;

    while (nums.length > 1) {
        let isAscending = true;
        let minSum = Infinity;
        let targetIndex = -1;

        for (let i = 0; i < nums.length - 1; i++) {
            const sum = nums[i] + nums[i + 1];

            if (nums[i] > nums[i + 1]) {
                isAscending = false;
            }

            if (sum < minSum) {
                minSum = sum;
                targetIndex = i;
            }
        }

        if (isAscending) {
            break;
        }

        count++;
        nums[targetIndex] = minSum;
        nums.splice(targetIndex + 1, 1);
    }

    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        count = 0

        while len(nums) > 1:
            isAscending = True
            minSum = float("inf")
            targetIndex = -1

            for i in range(len(nums) - 1):
                pair_sum = nums[i] + nums[i + 1]

                if nums[i] > nums[i + 1]:
                    isAscending = False

                if pair_sum < minSum:
                    minSum = pair_sum
                    targetIndex = i

            if isAscending:
                break

            count += 1
            nums[targetIndex] = minSum
            nums.pop(targetIndex + 1)

        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumPairRemoval(nums: number[]): number {
    let count = 0;

    while (nums.length > 1) {
        let isAscending = true;
        let minSum = Infinity;
        let targetIndex = -1;

        for (let i = 0; i < nums.length - 1; i++) {
            const sum = nums[i] + nums[i + 1];

            if (nums[i] > nums[i + 1]) {
                isAscending = false;
            }

            if (sum < minSum) {
                minSum = sum;
                targetIndex = i;
            }
        }

        if (isAscending) {
            break;
        }

        count++;
        nums[targetIndex] = minSum;
        nums.splice(targetIndex + 1, 1);
    }

    return count;
}
```

</details>

<br>

## Approach 2: Simulation + Array Simulation of Linked List

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumPairRemoval(int* nums, int n) {
    int* next = (int*)malloc(n * sizeof(int));
    if (next == NULL) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        next[i] = i + 1;
    }
    next[n - 1] = -1;

    int count = 0;
    while (n - count > 1) {
        int curr = 0;
        int target = 0;
        int targetAdjSum = nums[target] + nums[next[target]];
        int isAscending = 1;

        while (curr != -1 && next[curr] != -1) {
            if (nums[curr] > nums[next[curr]]) {
                isAscending = 0;
            }

            int currAdjSum = nums[curr] + nums[next[curr]];
            if (currAdjSum < targetAdjSum) {
                target = curr;
                targetAdjSum = currAdjSum;
            }
            curr = next[curr];
        }
        if (isAscending) {
            break;
        }
        count++;
        next[target] = next[next[target]];
        nums[target] = targetAdjSum;
    }

    free(next);
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> next(n);
        std::iota(next.begin(), next.end(), 1);
        next[n - 1] = -1;
        int count = 0;

        while (n - count > 1) {
            int curr = 0;
            int target = 0;
            int targetAdjSum = nums[target] + nums[next[target]];
            bool isAscending = true;

            while (curr != -1 && next[curr] != -1) {
                if (nums[curr] > nums[next[curr]]) {
                    isAscending = false;
                }

                int currAdjSum = nums[curr] + nums[next[curr]];
                if (currAdjSum < targetAdjSum) {
                    target = curr;
                    targetAdjSum = currAdjSum;
                }
                curr = next[curr];
            }

            if (isAscending) {
                break;
            }

            count++;
            next[target] = next[next[target]];
            nums[target] = targetAdjSum;
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumPairRemoval(int[] nums) {
        var next = new int?[nums.Length];
        for (var i = 0; i < nums.Length - 1; i++) next[i] = i + 1;

        var count = 0;

        while (nums.Length - count > 1) {
            int? curr = 0;
            var target = 0;
            var targetAdjSum = nums[target] + nums[next[target]!.Value];
            var isAscending = true;

            while (curr is not null && next[curr.Value] is not null) {
                var nextVal = next[curr.Value]!.Value;

                if (nums[curr.Value] > nums[nextVal]) {
                    isAscending = false;
                }

                var currAdjSum = nums[curr.Value] + nums[nextVal];
                if (currAdjSum < targetAdjSum) {
                    target = curr.Value;
                    targetAdjSum = currAdjSum;
                }

                curr = next[curr.Value];
            }

            if (isAscending) {
                break;
            }

            count++;
            next[target] = next[next[target]!.Value];
            nums[target] = targetAdjSum;
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumPairRemoval(nums []int) int {
	n := len(nums)
	next := make([]int, n)

	for i := 0; i < n; i++ {
		next[i] = i + 1
	}
	next[n-1] = -1
	count := 0
	for n-count > 1 {
		curr := 0
		target := 0
		targetAdjSum := nums[target] + nums[next[target]]
		isAscending := true

		for curr != -1 && next[curr] != -1 {
			if nums[curr] > nums[next[curr]] {
				isAscending = false
			}

			currAdjSum := nums[curr] + nums[next[curr]]
			if currAdjSum < targetAdjSum {
				target = curr
				targetAdjSum = currAdjSum
			}
			curr = next[curr]
		}

		if isAscending {
			break
		}

		count++
		next[target] = next[next[target]]
		nums[target] = targetAdjSum
	}

	return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumPairRemoval(int[] nums) {
        var n = nums.length;
        var next = new int[n];
        Arrays.setAll(next, i -> i + 1);
        next[n - 1] = -1;
        var count = 0;

        while (n - count > 1) {
            var curr = 0;
            var target = 0;
            var targetAdjSum = nums[target] + nums[next[target]];
            var isAscending = true;

            while (curr != -1 && next[curr] != -1) {
                if (nums[curr] > nums[next[curr]]) {
                    isAscending = false;
                }

                var currAdjSum = nums[curr] + nums[next[curr]];
                if (currAdjSum < targetAdjSum) {
                    target = curr;
                    targetAdjSum = currAdjSum;
                }
                curr = next[curr];
            }

            if (isAscending) {
                break;
            }

            count++;
            next[target] = next[next[target]];
            nums[target] = targetAdjSum;
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumPairRemoval = function (nums) {
    const next = nums.map((_, i) => i + 1);
    next[nums.length - 1] = null;
    let count = 0;

    while (nums.length - count > 1) {
        let curr = 0;
        let target = 0;
        let targetAdjSum = nums[target] + nums[next[target]];
        let isAscending = true;

        while (curr !== null && next[curr] !== null) {
            if (nums[curr] > nums[next[curr]]) {
                isAscending = false;
            }

            let currAdjSum = nums[curr] + nums[next[curr]];
            if (currAdjSum < targetAdjSum) {
                target = curr;
                targetAdjSum = currAdjSum;
            }
            curr = next[curr];
        }

        if (isAscending) {
            break;
        }

        count++;
        next[target] = next[next[target]];
        nums[target] = targetAdjSum;
    }

    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        next_node = list(range(1, len(nums) + 1))
        next_node[-1] = None
        count = 0

        while len(nums) - count > 1:
            curr = 0
            target = 0
            target_adj_sum = nums[target] + nums[next_node[target]]
            is_ascending = True

            while curr is not None and next_node[curr] is not None:
                if nums[curr] > nums[next_node[curr]]:
                    is_ascending = False

                curr_adj_sum = nums[curr] + nums[next_node[curr]]
                if curr_adj_sum < target_adj_sum:
                    target = curr
                    target_adj_sum = curr_adj_sum

                curr = next_node[curr]

            if is_ascending:
                break

            count += 1
            next_node[target] = next_node[next_node[target]]
            nums[target] = target_adj_sum

        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumPairRemoval(nums: number[]): number {
    const next = nums.map<number | null>((_, i) => i + 1);
    next[nums.length - 1] = null;
    let count = 0;

    while (nums.length - count > 1) {
        let curr: number | null = 0;
        let target = 0;
        let targetAdjSum = nums[target] + nums[next[target]!];
        let isAscending = true;

        while (curr !== null && next[curr] !== null) {
            if (nums[curr] > nums[next[curr]!]) {
                isAscending = false;
            }

            let currAdjSum = nums[curr] + nums[next[curr]!];
            if (currAdjSum < targetAdjSum) {
                target = curr;
                targetAdjSum = currAdjSum;
            }
            curr = next[curr];
        }

        if (isAscending) {
            break;
        }

        count++;
        next[target] = next[next[target]!];
        nums[target] = targetAdjSum;
    }

    return count;
}
```

</details>
