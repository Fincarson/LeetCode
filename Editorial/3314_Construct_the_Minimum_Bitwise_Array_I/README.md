# 3314. Construct the Minimum Bitwise Array I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/)  
`Array` `Bit Manipulation`

**Problem Link:** [LeetCode 3314 - Construct the Minimum Bitwise Array I](https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/)

## Problem

You are given an array nums consisting of n prime integers.

You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

Additionally, you must minimize each value of ans[i] in the resulting array.

If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 100
- 2 <= nums[i] <= 1000
- nums[i] is a prime number.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3314. Construct the Minimum Bitwise Array I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bitwise Operation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        int original = nums[i];
        int candidate = -1;

        for (int j = 1; j < original; j++) {
            if ((j | (j + 1)) == original) {
                candidate = j;
                break;
            }
        }

        result[i] = candidate;
    }

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            for (int j = 1; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    nums[i] = j;
                    break;
                }
            }
            if (nums[i] == tmp) {
                nums[i] = -1;
            }
        }
        return nums;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] MinBitwiseArray(IList<int> nums) {
        int[] result = new int[nums.Count];

        for (int i = 0; i < nums.Count; i++) {
            int original = nums[i];
            int candidate = -1;
            for (int j = 1; j < original; j++) {
                if ((j | (j + 1)) == original) {
                    candidate = j;
                    break;
                }
            }

            result[i] = candidate;
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minBitwiseArray(nums []int) []int {
	result := make([]int, len(nums))

	for i, original := range nums {
		candidate := -1

		for j := 1; j < original; j++ {
			if (j | (j + 1)) == original {
				candidate = j
				break
			}
		}

		result[i] = candidate
	}

	return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] minBitwiseArray(List<Integer> nums) {
        int[] result = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            int original = nums.get(i);
            int candidate = -1;
            for (int j = 1; j < original; j++) {
                if ((j | (j + 1)) == original) {
                    candidate = j;
                    break;
                }
            }
            result[i] = candidate;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minBitwiseArray = function (nums) {
    const result = new Array(nums.length);

    for (let i = 0; i < nums.length; i++) {
        const original = nums[i];
        let candidate = -1;

        for (let j = 1; j < original; j++) {
            if ((j | (j + 1)) === original) {
                candidate = j;
                break;
            }
        }

        result[i] = candidate;
    }

    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        result = []
        for num in nums:
            original = num
            candidate = -1
            for j in range(1, original):
                if (j | (j + 1)) == original:
                    candidate = j
                    break
            result.append(candidate)
        return result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minBitwiseArray(nums: number[]): number[] {
    const result: number[] = new Array(nums.length);

    for (let i = 0; i < nums.length; i++) {
        const original = nums[i];
        let candidate: number = -1;

        for (let j = 1; j < original; j++) {
            if ((j | (j + 1)) === original) {
                candidate = j;
                break;
            }
        }

        result[i] = candidate;
    }

    return result;
}
```

</details>

<br>

## Approach 2: Bitwise Operation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int res = -1;
        int d = 1;
        while ((x & d) != 0) {
            res = x - d;
            d <<= 1;
        }
        nums[i] = res;
    }
    return nums;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x : nums) {
            int res = -1;
            int d = 1;
            while ((x & d) != 0) {
                res = x - d;
                d <<= 1;
            }
            x = res;
        }
        return nums;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] MinBitwiseArray(IList<int> nums) {
        for (int i = 0; i < nums.Count; i++) {
            int x = nums[i];
            int res = -1;
            int d = 1;
            while ((x & d) != 0) {
                res = x - d;
                d <<= 1;
            }
            nums[i] = res;
        }
        return nums.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minBitwiseArray(nums []int) []int {
	for i, x := range nums {
		res := -1
		d := 1
		for (x & d) != 0 {
			res = x - d
			d <<= 1
		}
		nums[i] = res
	}
	return nums
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            int x = nums.get(i);
            int res = -1;
            int d = 1;
            while ((x & d) != 0) {
                res = x - d;
                d <<= 1;
            }
            result[i] = res;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minBitwiseArray = function (nums) {
    for (let i = 0; i < nums.length; i++) {
        let x = nums[i];
        let res = -1;
        let d = 1;
        while ((x & d) !== 0) {
            res = x - d;
            d <<= 1;
        }
        nums[i] = res;
    }
    return nums;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            res = -1
            d = 1
            while (nums[i] & d) != 0:
                res = nums[i] - d
                d <<= 1
            nums[i] = res
        return nums
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minBitwiseArray(nums: number[]): number[] {
    for (let i = 0; i < nums.length; i++) {
        let x = nums[i];
        let res = -1;
        let d = 1;
        while ((x & d) !== 0) {
            res = x - d;
            d <<= 1;
        }
        nums[i] = res;
    }
    return nums;
}
```

</details>
