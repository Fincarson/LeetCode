# 3010. Divide an Array Into Subarrays With Minimum Cost I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/)  
`Array` `Sorting` `Enumeration`

**Problem Link:** [LeetCode 3010 - Divide an Array Into Subarrays With Minimum Cost I](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/)

## Problem

You are given an array of integers nums of length n.

The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

You need to divide nums into 3 disjoint contiguous subarrays.

Return the minimum possible sum of the cost of these subarrays.

### Example 1

```text
Input: nums = [1,2,3,12]
Output: 6
Explanation: The best possible way to form 3 subarrays is: [1], [2], and [3,12] at a total cost of 1 + 2 + 3 = 6.
The other possible ways to form 3 subarrays are:
- [1], [2,3], and [12] at a total cost of 1 + 2 + 12 = 15.
- [1,2], [3], and [12] at a total cost of 1 + 3 + 12 = 16.
```

### Example 2

```text
Input: nums = [5,4,3]
Output: 12
Explanation: The best possible way to form 3 subarrays is: [5], [4], and [3] at a total cost of 5 + 4 + 3 = 12.
It can be shown that 12 is the minimum cost achievable.
```

### Example 3

```text
Input: nums = [10,3,1,1]
Output: 12
Explanation: The best possible way to form 3 subarrays is: [10,3], [1], and [1] at a total cost of 10 + 1 + 1 = 12.
It can be shown that 12 is the minimum cost achievable.
```

## Constraints

- 3 <= n <= 50
- 1 <= nums[i] <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3010. Divide an Array Into Subarrays With Minimum Cost I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Maintaining The Minimum And Second Minimum Values | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) { return (*(int*)a) - (*(int*)b); }

int minimumCost(int* nums, int numsSize) {
    qsort(nums + 1, numsSize - 1, sizeof(int), cmp);
    return nums[0] + nums[1] + nums[2];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());
        return reduce(nums.begin(), nums.begin() + 3, 0);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumCost(int[] nums) {
        Array.Sort(nums, 1, nums.Length - 1);
        return nums.Take(3).Sum();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumCost(nums []int) int {
	sort.Ints(nums[1:])
	return nums[0] + nums[1] + nums[2]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumCost(int[] nums) {
        Arrays.sort(nums, 1, nums.length);
        return nums[0] + nums[1] + nums[2];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumCost = function (nums) {
    nums = [nums[0], ...nums.slice(1).sort((a, b) => a - b)];
    return nums.slice(0, 3).reduce((sum, num) => sum + num, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        nums[1:] = sorted(nums[1:])
        return sum(nums[:3])
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumCost(nums: number[]): number {
    nums = [nums[0], ...nums.slice(1).sort((a, b) => a - b)];
    return nums.slice(0, 3).reduce((sum, num) => sum + num, 0);
}
```

</details>

<br>

## Approach 2: Maintaining The Minimum And Second Minimum Values

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumCost(int* nums, int numsSize) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 1; i < numsSize; i++) {
        int x = nums[i];
        if (x < first) {
            second = first;
            first = x;
        } else if (x < second) {
            second = x;
        }
    }
    return nums[0] + first + second;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            if (x < first) {
                second = first;
                first = x;
            } else if (x < second) {
                second = x;
            }
        }
        return nums[0] + first + second;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumCost(int[] nums) {
        int first = int.MaxValue;
        int second = int.MaxValue;

        for (int i = 1; i < nums.Length; i++) {
            int x = nums[i];
            if (x < first) {
                second = first;
                first = x;
            } else if (x < second) {
                second = x;
            }
        }
        return nums[0] + first + second;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumCost(nums []int) int {
	first := int(^uint(0) >> 1)
	second := int(^uint(0) >> 1)

	for i := 1; i < len(nums); i++ {
		x := nums[i]
		if x < first {
			second = first
			first = x
		} else if x < second {
			second = x
		}
	}
	return nums[0] + first + second
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumCost(int[] nums) {
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;

        for (int i = 1; i < nums.length; i++) {
            int x = nums[i];
            if (x < first) {
                second = first;
                first = x;
            } else if (x < second) {
                second = x;
            }
        }
        return nums[0] + first + second;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumCost = function (nums) {
    let first = Number.MAX_SAFE_INTEGER;
    let second = Number.MAX_SAFE_INTEGER;

    for (let i = 1; i < nums.length; i++) {
        const x = nums[i];
        if (x < first) {
            second = first;
            first = x;
        } else if (x < second) {
            second = x;
        }
    }
    return nums[0] + first + second;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        return nums[0] + sum(nsmallest(2, nums[1:]))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumCost(nums: number[]): number {
    let first: number = Number.MAX_SAFE_INTEGER;
    let second: number = Number.MAX_SAFE_INTEGER;

    for (let i = 1; i < nums.length; i++) {
        const x: number = nums[i];
        if (x < first) {
            second = first;
            first = x;
        } else if (x < second) {
            second = x;
        }
    }
    return nums[0] + first + second;
}
```

</details>
