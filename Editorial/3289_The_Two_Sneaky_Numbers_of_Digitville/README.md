# 3289. The Two Sneaky Numbers of Digitville

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/)  
`Array` `Hash Table` `Math`

**Problem Link:** [LeetCode 3289 - The Two Sneaky Numbers of Digitville](https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/)

## Problem

In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in an additional time, making the list longer than usual.

As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.

### Example 1

### Example 2

### Example 3

## Constraints

- 2 <= n <= 100
- nums.length == n + 2
- 0 <= nums[i] < n
- The input is generated such that nums contains exactly two repeated elements.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3289. The Two Sneaky Numbers of Digitville

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bitwise Operations | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int));
    int* count = (int*)calloc(101, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        count[x]++;
        if (count[x] == 2) {
            res[(*returnSize)++] = x;
        }
    }
    free(count);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> count;
        for (int x : nums) {
            count[x]++;
            if (count[x] == 2) {
                res.push_back(x);
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] GetSneakyNumbers(int[] nums) {
        List<int> res = new List<int>();
        Dictionary<int, int> count = new Dictionary<int, int>();
        foreach (int x in nums) {
            if (!count.ContainsKey(x))
                count[x] = 0;
            count[x]++;
            if (count[x] == 2) {
                res.Add(x);
            }
        }
        return res.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getSneakyNumbers(nums []int) []int {
	res := []int{}
	count := make(map[int]int)
	for _, x := range nums {
		count[x]++
		if count[x] == 2 {
			res = append(res, x)
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] getSneakyNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();
        Map<Integer, Integer> count = new HashMap<>();
        for (int x : nums) {
            int c = count.getOrDefault(x, 0) + 1;
            count.put(x, c);
            if (c == 2) {
                res.add(x);
            }
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getSneakyNumbers = function (nums) {
    const res = [];
    const count = new Map();
    for (const x of nums) {
        count.set(x, (count.get(x) || 0) + 1);
        if (count.get(x) === 2) {
            res.push(x);
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        res = []
        count = {}
        for x in nums:
            count[x] = count.get(x, 0) + 1
            if count[x] == 2:
                res.append(x)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getSneakyNumbers(nums: number[]): number[] {
    const res: number[] = [];
    const count = new Map<number, number>();
    for (const x of nums) {
        count.set(x, (count.get(x) || 0) + 1);
        if (count.get(x) === 2) {
            res.push(x);
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: Bitwise Operations

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int n = numsSize - 2;
    int y = 0;
    for (int i = 0; i < numsSize; i++) {
        y ^= nums[i];
    }
    for (int i = 0; i < n; i++) {
        y ^= i;
    }
    int lowBit = y & -y;
    int x1 = 0, x2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & lowBit) {
            x1 ^= nums[i];
        } else {
            x2 ^= nums[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i & lowBit) {
            x1 ^= i;
        } else {
            x2 ^= i;
        }
    }
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = x1;
    res[1] = x2;
    *returnSize = 2;
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = (int)nums.size() - 2;
        int y = 0;
        for (int x : nums) {
            y ^= x;
        }
        for (int i = 0; i < n; i++) {
            y ^= i;
        }
        int lowBit = y & (-y);
        int x1 = 0, x2 = 0;
        for (int x : nums) {
            if (x & lowBit) {
                x1 ^= x;
            } else {
                x2 ^= x;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i & lowBit) {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }
        return {x1, x2};
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] GetSneakyNumbers(int[] nums) {
        int n = nums.Length - 2;
        int y = 0;
        foreach (int x in nums) {
            y ^= x;
        }
        for (int i = 0; i < n; i++) {
            y ^= i;
        }
        int lowBit = y & -y;
        int x1 = 0, x2 = 0;
        foreach (int x in nums) {
            if ((x & lowBit) != 0) {
                x1 ^= x;
            } else {
                x2 ^= x;
            }
        }
        for (int i = 0; i < n; i++) {
            if ((i & lowBit) != 0) {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }
        return new int[] { x1, x2 };
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getSneakyNumbers(nums []int) []int {
	n := len(nums) - 2
	y := 0
	for _, x := range nums {
		y ^= x
	}
	for i := 0; i < n; i++ {
		y ^= i
	}
	lowBit := y & -y
	x1, x2 := 0, 0
	for _, x := range nums {
		if x&lowBit != 0 {
			x1 ^= x
		} else {
			x2 ^= x
		}
	}
	for i := 0; i < n; i++ {
		if i&lowBit != 0 {
			x1 ^= i
		} else {
			x2 ^= i
		}
	}
	return []int{x1, x2}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] getSneakyNumbers(int[] nums) {
        int n = nums.length - 2;
        int y = 0;
        for (int x : nums) {
            y ^= x;
        }
        for (int i = 0; i < n; i++) {
            y ^= i;
        }
        int lowBit = y & -y;
        int x1 = 0;
        int x2 = 0;
        for (int x : nums) {
            if ((x & lowBit) != 0) {
                x1 ^= x;
            } else {
                x2 ^= x;
            }
        }
        for (int i = 0; i < n; i++) {
            if ((i & lowBit) != 0) {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }
        return new int[] { x1, x2 };
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function getSneakyNumbers(nums) {
    const n = nums.length - 2;
    let y = 0;
    for (const x of nums) {
        y ^= x;
    }
    for (let i = 0; i < n; i++) {
        y ^= i;
    }
    const lowBit = y & -y;
    let x1 = 0,
        x2 = 0;
    for (const x of nums) {
        if (x & lowBit) {
            x1 ^= x;
        } else {
            x2 ^= x;
        }
    }
    for (let i = 0; i < n; i++) {
        if (i & lowBit) {
            x1 ^= i;
        } else {
            x2 ^= i;
        }
    }
    return [x1, x2];
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums) - 2
        y = 0
        for x in nums:
            y ^= x
        for i in range(n):
            y ^= i
        lowBit = y & -y
        x1 = x2 = 0
        for x in nums:
            if x & lowBit:
                x1 ^= x
            else:
                x2 ^= x
        for i in range(n):
            if i & lowBit:
                x1 ^= i
            else:
                x2 ^= i
        return [x1, x2]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getSneakyNumbers(nums: number[]): number[] {
    const n = nums.length - 2;
    let y = 0;
    for (const x of nums) {
        y ^= x;
    }
    for (let i = 0; i < n; i++) {
        y ^= i;
    }
    const lowBit = y & -y;
    let x1 = 0,
        x2 = 0;
    for (const x of nums) {
        if (x & lowBit) {
            x1 ^= x;
        } else {
            x2 ^= x;
        }
    }
    for (let i = 0; i < n; i++) {
        if (i & lowBit) {
            x1 ^= i;
        } else {
            x2 ^= i;
        }
    }
    return [x1, x2];
}
```

</details>

<br>

## Approach 3: Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int n = numsSize - 2;
    double sum = 0, squaredSum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        squaredSum += nums[i] * nums[i];
    }
    double sum2 = sum - n * (n - 1) / 2.0;
    double squaredSum2 = squaredSum - n * (n - 1) * (2 * n - 1) / 6.0;
    int x1 = (int)((sum2 - sqrt(2 * squaredSum2 - sum2 * sum2)) / 2);
    int x2 = (int)((sum2 + sqrt(2 * squaredSum2 - sum2 * sum2)) / 2);
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = x1;
    res[1] = x2;
    *returnSize = 2;
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = (int)nums.size() - 2;
        int sum = 0, squaredSum = 0;
        for (int x : nums) {
            sum += x;
            squaredSum += x * x;
        }
        int sum2 = sum - n * (n - 1) / 2;
        int squaredSum2 = squaredSum - n * (n - 1) * (2 * n - 1) / 6;
        int x1 = (sum2 - sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
        int x2 = (sum2 + sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
        return {x1, x2};
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] GetSneakyNumbers(int[] nums) {
        int n = nums.Length - 2;
        double sum = 0, squaredSum = 0;
        foreach (int x in nums) {
            sum += x;
            squaredSum += x * x;
        }
        double sum2 = sum - n * (n - 1) / 2.0;
        double squaredSum2 = squaredSum - n * (n - 1) * (2 * n - 1) / 6.0;
        int x1 = (int)((sum2 - Math.Sqrt(2 * squaredSum2 - sum2 * sum2)) / 2);
        int x2 = (int)((sum2 + Math.Sqrt(2 * squaredSum2 - sum2 * sum2)) / 2);
        return new int[] { x1, x2 };
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getSneakyNumbers(nums []int) []int {
	n := len(nums) - 2
	sum, squaredSum := 0.0, 0.0
	for _, x := range nums {
		sum += float64(x)
		squaredSum += float64(x * x)
	}
	sum2 := sum - float64(n*(n-1)/2)
	squaredSum2 := squaredSum - float64(n*(n-1)*(2*n-1)/6)
	x1 := (sum2 - math.Sqrt(2*squaredSum2-sum2*sum2)) / 2
	x2 := (sum2 + math.Sqrt(2*squaredSum2-sum2*sum2)) / 2
	return []int{int(x1), int(x2)}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] getSneakyNumbers(int[] nums) {
        int n = nums.length - 2;
        double sum = 0;
        double squaredSum = 0;
        for (int x : nums) {
            sum += x;
            squaredSum += x * x;
        }
        double sum2 = sum - (n * (n - 1)) / 2.0;
        double squaredSum2 = squaredSum - (n * (n - 1) * (2 * n - 1)) / 6.0;
        int x1 = (int) ((sum2 - Math.sqrt(2 * squaredSum2 - sum2 * sum2)) / 2);
        int x2 = (int) ((sum2 + Math.sqrt(2 * squaredSum2 - sum2 * sum2)) / 2);
        return new int[] { x1, x2 };
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function getSneakyNumbers(nums) {
    const n = nums.length - 2;
    let sum = 0,
        squaredSum = 0;
    for (const x of nums) {
        sum += x;
        squaredSum += x * x;
    }
    const sum2 = sum - (n * (n - 1)) / 2;
    const squaredSum2 = squaredSum - (n * (n - 1) * (2 * n - 1)) / 6;
    const x1 = (sum2 - Math.sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
    const x2 = (sum2 + Math.sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
    return [Math.floor(x1), Math.floor(x2)];
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums) - 2
        sum_ = sum(nums)
        squared_sum = sum(x * x for x in nums)
        sum2 = sum_ - n * (n - 1) // 2
        squared_sum2 = squared_sum - n * (n - 1) * (2 * n - 1) // 6
        x1 = (sum2 - math.sqrt(2 * squared_sum2 - sum2 * sum2)) / 2
        x2 = (sum2 + math.sqrt(2 * squared_sum2 - sum2 * sum2)) / 2
        return [int(x1), int(x2)]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getSneakyNumbers(nums: number[]): number[] {
    const n = nums.length - 2;
    let sum = 0,
        squaredSum = 0;
    for (const x of nums) {
        sum += x;
        squaredSum += x * x;
    }
    const sum2 = sum - (n * (n - 1)) / 2;
    const squaredSum2 = squaredSum - (n * (n - 1) * (2 * n - 1)) / 6;
    const x1 = (sum2 - Math.sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
    const x2 = (sum2 + Math.sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
    return [Math.floor(x1), Math.floor(x2)];
}
```

</details>
