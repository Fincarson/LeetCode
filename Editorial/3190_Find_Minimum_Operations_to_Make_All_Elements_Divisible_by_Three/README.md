# 3190. Find Minimum Operations to Make All Elements Divisible by Three

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/)  
`Array` `Math`

**Problem Link:** [LeetCode 3190 - Find Minimum Operations to Make All Elements Divisible by Three](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/)

## Problem

You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 50
- 1 <= nums[i] <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3190. Find Minimum Operations to Make All Elements Divisible by Three

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumOperations(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        int remainder = nums[i] % 3;
        sum += (remainder < 3 - remainder) ? remainder : (3 - remainder);
    }
    return sum;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, [](int acc, int v) {
            return acc + std::min(v % 3, 3 - v % 3);
        });
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumOperations(int[] nums) {
        return nums.Select(x => { return Math.Min(x % 3, 3 - x % 3); }).Sum();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumOperations(nums []int) int {
	sum := 0
	for _, x := range nums {
		remainder := x % 3
		sum += min(remainder, 3-remainder)
	}
	return sum
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumOperations(int[] nums) {
        int sum = 0;
        for (int x : nums) {
            int rem = x % 3;
            sum += Math.min(rem, 3 - rem);
        }
        return sum;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumOperations = function (nums) {
    return nums.reduce((pre, v) => (pre += Math.min(3 - (v % 3), v % 3)), 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        return sum(min(x % 3, 3 - x % 3) for x in nums)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumOperations(nums: number[]): number {
    return nums.reduce((pre, v) => (pre += Math.min(3 - (v % 3), v % 3)), 0);
}
```

</details>
