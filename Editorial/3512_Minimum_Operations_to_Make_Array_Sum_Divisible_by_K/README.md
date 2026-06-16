# 3512. Minimum Operations to Make Array Sum Divisible by K

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/)  
`Array` `Math`

**Problem Link:** [LeetCode 3512 - Minimum Operations to Make Array Sum Divisible by K](https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/)

## Problem

You are given an integer array nums and an integer k. You can perform the following operation any number of times:

- Select an index i and replace nums[i] with nums[i] - 1.

Return the minimum number of operations required to make the sum of the array divisible by k.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 1000
- 1 <= k <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3512. Minimum Operations to Make Array Sum Divisible by K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sum Modulo | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Sum Modulo

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minOperations(int* nums, int numsSize, int k) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return sum % k;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinOperations(IList<int> nums, int k) {
        int sum = 0;
        foreach (int num in nums) {
            sum += num;
        }
        return sum % k;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minOperations(nums []int, k int) int {
	sum := 0
	for _, num := range nums {
		sum += num
	}
	return sum % k
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minOperations(int[] nums, int k) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum % k;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minOperations = function (nums, k) {
    let sum = 0;
    for (let num of nums) {
        sum += num;
    }
    return sum % k;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(nums) % k
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minOperations(nums: number[], k: number): number {
    let sum = 0;
    for (let num of nums) {
        sum += num;
    }
    return sum % k;
}
```

</details>
