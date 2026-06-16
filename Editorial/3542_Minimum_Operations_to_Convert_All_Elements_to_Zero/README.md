# 3542. Minimum Operations to Convert All Elements to Zero

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/)  
`Array` `Hash Table` `Stack` `Greedy` `Monotonic Stack`

**Problem Link:** [LeetCode 3542 - Minimum Operations to Convert All Elements to Zero](https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/)

## Problem

You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become 0.

In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) and set all occurrences of the minimum non-negative integer in that subarray to 0.

Return the minimum number of operations required to make all elements in the array 0.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n == nums.length <= 105
- 0 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3542. Minimum Operations to Convert All Elements to Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Monotonic stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Monotonic stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minOperations(int* nums, int numsSize) {
    int* s = (int*)malloc(sizeof(int) * numsSize);
    if (!s) return 0;  // allocation failure -> safe fallback
    int top = 0, res = 0;
    for (int i = 0; i < numsSize; ++i) {
        int a = nums[i];
        while (top > 0 && s[top - 1] > a) {
            --top;
        }
        if (a == 0) continue;
        if (top == 0 || s[top - 1] < a) {
            res++;
            s[top++] = a;
        }
    }
    free(s);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;
        int res = 0;
        for (int a : nums) {
            while (!s.empty() && s.back() > a) {
                s.pop_back();
            }
            if (a == 0) continue;
            if (s.empty() || s.back() < a) {
                ++res;
                s.push_back(a);
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
    public int MinOperations(int[] nums) {
        var s = new List<int>();
        int res = 0;
        foreach (int a in nums) {
            while (s.Count > 0 && s[s.Count - 1] > a) s.RemoveAt(s.Count - 1);
            if (a == 0)
                continue;
            if (s.Count == 0 || s[s.Count - 1] < a) {
                res++;
                s.Add(a);
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minOperations(nums []int) int {
	s := []int{}
	res := 0
	for _, a := range nums {
		for len(s) > 0 && s[len(s)-1] > a {
			s = s[:len(s)-1]
		}
		if a == 0 {
			continue
		}
		if len(s) == 0 || s[len(s)-1] < a {
			res++
			s = append(s, a)
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

    public int minOperations(int[] nums) {
        List<Integer> s = new ArrayList<>();
        int res = 0;
        for (int a : nums) {
            while (!s.isEmpty() && s.get(s.size() - 1) > a) {
                s.remove(s.size() - 1);
            }
            if (a == 0) continue;
            if (s.isEmpty() || s.get(s.size() - 1) < a) {
                res++;
                s.add(a);
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minOperations = function (nums) {
    const s = [];
    let res = 0;
    for (const a of nums) {
        while (s.length && s[s.length - 1] > a) {
            s.pop();
        }
        if (a === 0) continue;
        if (!s.length || s[s.length - 1] < a) {
            res++;
            s.push(a);
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
    def minOperations(self, nums: List[int]) -> int:
        s = []
        res = 0
        for a in nums:
            while s and s[-1] > a:
                s.pop()
            if a == 0:
                continue
            if not s or s[-1] < a:
                res += 1
                s.append(a)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minOperations(nums: number[]): number {
    const s = [];
    let res = 0;
    for (const a of nums) {
        while (s.length && s[s.length - 1] > a) {
            s.pop();
        }
        if (a === 0) continue;
        if (!s.length || s[s.length - 1] < a) {
            res++;
            s.push(a);
        }
    }
    return res;
}
```

</details>
