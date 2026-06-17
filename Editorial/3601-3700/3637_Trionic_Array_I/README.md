# 3637. Trionic Array I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/trionic-array-i/)  
`Array`

**Problem Link:** [LeetCode 3637 - Trionic Array I](https://leetcode.com/problems/trionic-array-i/)

## Problem

You are given an integer array nums of length n.

An array is trionic if there exist indices 0 < p < q < n Ã¢Ë†â€™ 1 such that:

- nums[0...p] is strictly increasing,
- nums[p...q] is strictly decreasing,
- nums[q...n Ã¢Ë†â€™ 1] is strictly increasing.

Return true if nums is trionic, otherwise return false.

### Example 1

### Example 2

## Constraints

- 3 <= n <= 100
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

# Editorial - 3637. Trionic Array I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Evaluating the Validity of the Boundaries | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Counting the Number of Turning Points | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Evaluating the Validity of the Boundaries

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isTrionic(int* nums, int numsSize) {
    int n = numsSize, i = 1;
    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    int p = i - 1;
    while (i < n && nums[i - 1] > nums[i]) {
        i++;
    }
    int q = i - 1;
    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    int flag = i - 1;
    return (p != 0) && (q != p) && (flag == n - 1 && flag != q);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int p = i - 1;
        while (i < n && nums[i - 1] > nums[i]) {
            i++;
        }
        int q = i - 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int flag = i - 1;
        return (p != 0) && (q != p) && (flag == n - 1 && flag != q);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsTrionic(int[] nums) {
        int n = nums.Length, i = 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int p = i - 1;
        while (i < n && nums[i - 1] > nums[i]) {
            i++;
        }
        int q = i - 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int flag = i - 1;
        return (p != 0) && (q != p) && (flag == n - 1 && flag != q);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isTrionic(nums []int) bool {
	n := len(nums)
	i := 1
	for i < n && nums[i-1] < nums[i] {
		i++
	}
	p := i - 1

	for i < n && nums[i-1] > nums[i] {
		i++
	}
	q := i - 1

	for i < n && nums[i-1] < nums[i] {
		i++
	}
	flag := i - 1

	return p != 0 && q != p && flag == n-1 && flag != q
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        int i = 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int p = i - 1;
        while (i < n && nums[i - 1] > nums[i]) {
            i++;
        }
        int q = i - 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int flag = i - 1;
        return (p != 0) && (q != p) && (flag == n - 1 && flag != q);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isTrionic = function (nums) {
    const n = nums.length;
    let p = -1,
        q = -1,
        flag = -1,
        i = 1;
    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    p = i - 1;

    while (i < n && nums[i - 1] > nums[i]) {
        i++;
    }
    q = i - 1;

    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    flag = i - 1;

    return p !== 0 && q !== p && flag === n - 1 && flag !== q;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        i = 1

        while i < n and nums[i - 1] < nums[i]:
            i += 1
        p = i - 1

        while i < n and nums[i - 1] > nums[i]:
            i += 1
        q = i - 1

        while i < n and nums[i - 1] < nums[i]:
            i += 1
        flag = i - 1

        return (p != 0) and (q != p) and (flag == n - 1 and flag != q)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isTrionic(nums: number[]): boolean {
    const n = nums.length;
    let i = 1;

    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    const p = i - 1;

    while (i < n && nums[i - 1] > nums[i]) {
        i++;
    }
    const q = i - 1;

    while (i < n && nums[i - 1] < nums[i]) {
        i++;
    }
    const flag = i - 1;

    return p !== 0 && q !== p && flag === n - 1 && flag !== q;
}
```

</details>

<br>

## Approach 2: Counting the Number of Turning Points

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isTrionic(int* nums, int numsSize) {
    if (nums[0] >= nums[1]) {
        return false;
    }
    int count = 1;
    for (int i = 2; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) {
            return false;
        }
        if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
            count++;
        }
    }
    return count == 3;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] >= nums[1]) {
            return false;
        }
        int count = 1;
        for (int i = 2; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                return false;
            }
            if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
                count++;
            }
        }
        return count == 3;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsTrionic(int[] nums) {
        int n = nums.Length;
        if (nums[0] >= nums[1]) {
            return false;
        }
        int count = 1;
        for (int i = 2; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                return false;
            }
            if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
                count++;
            }
        }
        return count == 3;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isTrionic(nums []int) bool {
	n := len(nums)
	if nums[0] >= nums[1] {
		return false
	}
	count := 1
	for i := 2; i < n; i++ {
		if nums[i-1] == nums[i] {
			return false
		}
		if (nums[i-2]-nums[i-1])*(nums[i-1]-nums[i]) < 0 {
			count++
		}
	}
	return count == 3
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        if (nums[0] >= nums[1]) {
            return false;
        }
        int count = 1;
        for (int i = 2; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                return false;
            }
            if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
                count++;
            }
        }
        return count == 3;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isTrionic = function (nums) {
    const n = nums.length;
    if (nums[0] >= nums[1]) {
        return false;
    }
    let count = 1;
    for (let i = 2; i < n; i++) {
        if (nums[i - 1] === nums[i]) {
            return false;
        }
        if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
            count++;
        }
    }
    return count === 3;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        if nums[0] >= nums[1]:
            return False

        count = 1
        for i in range(2, n):
            if nums[i - 1] == nums[i]:
                return False
            if (nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0:
                count += 1

        return count == 3
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isTrionic(nums: number[]): boolean {
    const n = nums.length;
    if (nums[0] >= nums[1]) {
        return false;
    }
    let count = 1;
    for (let i = 2; i < n; i++) {
        if (nums[i - 1] === nums[i]) {
            return false;
        }
        if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
            count++;
        }
    }
    return count === 3;
}
```

</details>
