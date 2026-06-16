# 3024. Type of Triangle

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/type-of-triangle/)  
`Array` `Math` `Sorting`

**Problem Link:** [LeetCode 3024 - Type of Triangle](https://leetcode.com/problems/type-of-triangle/)

## Problem

You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

- A triangle is called equilateral if it has all sides of equal length.
- A triangle is called isosceles if it has exactly two sides of equal length.
- A triangle is called scalene if all its sides are of different lengths.

Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.

### Example 1

```text
Input: nums = [3,3,3]
Output: "equilateral"
Explanation: Since all the sides are of equal length, therefore, it will form an equilateral triangle.
```

### Example 2

```text
Input: nums = [3,4,5]
Output: "scalene"
Explanation:
nums[0] + nums[1] = 3 + 4 = 7, which is greater than nums[2] = 5.
nums[0] + nums[2] = 3 + 5 = 8, which is greater than nums[1] = 4.
nums[1] + nums[2] = 4 + 5 = 9, which is greater than nums[0] = 3.
Since the sum of the two sides is greater than the third side for all three cases, therefore, it can form a triangle.
As all the sides are of different lengths, it will form a scalene triangle.
```

## Constraints

- nums.length == 3
- 1 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3024. Type of Triangle

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

char* triangleType(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[0] + nums[1] <= nums[2]) {
        return "none";
    } else if (nums[0] == nums[2]) {
        return "equilateral";
    } else if (nums[0] == nums[1] || nums[1] == nums[2]) {
        return "isosceles";
    } else {
        return "scalene";
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        } else if (nums[0] == nums[2]) {
            return "equilateral";
        } else if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string TriangleType(int[] nums) {
        Array.Sort(nums);
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        } else if (nums[0] == nums[2]) {
            return "equilateral";
        } else if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func triangleType(nums []int) string {
	sort.Ints(nums)
	if nums[0]+nums[1] <= nums[2] {
		return "none"
	} else if nums[0] == nums[2] {
		return "equilateral"
	} else if nums[0] == nums[1] || nums[1] == nums[2] {
		return "isosceles"
	} else {
		return "scalene"
	}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String triangleType(int[] nums) {
        Arrays.sort(nums);
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        } else if (nums[0] == nums[2]) {
            return "equilateral";
        } else if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var triangleType = function (nums) {
    nums.sort((a, b) => a - b);
    if (nums[0] + nums[1] <= nums[2]) {
        return "none";
    } else if (nums[0] === nums[2]) {
        return "equilateral";
    } else if (nums[0] === nums[1] || nums[1] === nums[2]) {
        return "isosceles";
    } else {
        return "scalene";
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def triangleType(self, nums: List[int]) -> str:
        nums.sort()
        if nums[0] + nums[1] <= nums[2]:
            return "none"
        elif nums[0] == nums[2]:
            return "equilateral"
        elif nums[0] == nums[1] or nums[1] == nums[2]:
            return "isosceles"
        else:
            return "scalene"
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function triangleType(nums: number[]): string {
    nums.sort((a, b) => a - b);
    if (nums[0] + nums[1] <= nums[2]) {
        return "none";
    } else if (nums[0] === nums[2]) {
        return "equilateral";
    } else if (nums[0] === nums[1] || nums[1] === nums[2]) {
        return "isosceles";
    } else {
        return "scalene";
    }
}
```

</details>
