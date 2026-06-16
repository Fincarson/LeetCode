# 3396. Minimum Number of Operations to Make Elements in Array Distinct

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 3396 - Minimum Number of Operations to Make Elements in Array Distinct](https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/)

## Problem

You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:

- Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.

Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Increment to Make Array Unique](https://leetcode.com/problems/minimum-increment-to-make-array-unique/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3396. Minimum Number of Operations to Make Elements in Array Distinct

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool checkUnique(int* nums, int numsSize, int start) {
    int seen[128] = {0};
    for (int i = start; i < numsSize; i++) {
        if (seen[nums[i]]) {
            return false;
        }
        seen[nums[i]] = true;
    }
    return true;
}

int minimumOperations(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < numsSize; i += 3, ans++) {
        if (checkUnique(nums, numsSize, i)) {
            return ans;
        }
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        auto checkUnique = [&](int start) {
            unordered_set<int> seen;
            for (int i = start; i < nums.size(); i++) {
                if (seen.count(nums[i])) {
                    return false;
                }
                seen.emplace(nums[i]);
            }
            return true;
        };

        int ans = 0;
        for (int i = 0; i < nums.size(); i += 3, ans++) {
            if (checkUnique(i)) {
                return ans;
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
    public int MinimumOperations(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.Length; i += 3, ans++) {
            if (CheckUnique(nums, i)) {
                return ans;
            }
        }
        return ans;
    }

    private bool CheckUnique(int[] nums, int start) {
        HashSet<int> seen = new HashSet<int>();
        for (int i = start; i < nums.Length; i++) {
            if (seen.Contains(nums[i])) {
                return false;
            }
            seen.Add(nums[i]);
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumOperations(nums []int) int {
	ans := 0
	for i := 0; i < len(nums); i += 3 {
		if checkUnique(nums, i) {
			return ans
		}
		ans++
	}
	return ans
}

func checkUnique(nums []int, start int) bool {
	seen := make(map[int]struct{})
	for i := start; i < len(nums); i++ {
		if _, exists := seen[nums[i]]; exists {
			return false
		}
		seen[nums[i]] = struct{}{}
	}
	return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumOperations(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i += 3, ans++) {
            if (checkUnique(nums, i)) {
                return ans;
            }
        }
        return ans;
    }

    private boolean checkUnique(int[] nums, int start) {
        HashSet<Integer> cnt = new HashSet<>();
        for (int i = start; i < nums.length; i++) {
            if (cnt.contains(nums[i])) {
                return false;
            }
            cnt.add(nums[i]);
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumOperations = function (nums) {
    let ans = 0;
    for (let i = 0; i < nums.length; i += 3, ans++) {
        if (checkUnique(nums, i)) {
            return ans;
        }
    }
    return ans;
};

const checkUnique = (nums, start) => {
    let seen = new Set();
    for (let i = start; i < nums.length; i++) {
        if (seen.has(nums[i])) {
            return false;
        }
        seen.add(nums[i]);
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        def check_unique(start):
            seen = set()
            for num in nums[start:]:
                if num in seen:
                    return False
                seen.add(num)
            return True

        ans = 0
        for i in range(0, len(nums), 3):
            if check_unique(i):
                return ans
            ans += 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumOperations(nums: number[]): number {
    let ans = 0;
    for (let i = 0; i < nums.length; i += 3, ans++) {
        if (checkUnique(nums, i)) {
            return ans;
        }
    }
    return ans;
}

function checkUnique(nums: number[], start: number): boolean {
    let seen = new Set<number>();
    for (let i = start; i < nums.length; i++) {
        if (seen.has(nums[i])) {
            return false;
        }
        seen.add(nums[i]);
    }
    return true;
}
```

</details>
