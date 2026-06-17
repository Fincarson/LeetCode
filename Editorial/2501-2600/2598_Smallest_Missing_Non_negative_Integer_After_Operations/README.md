# 2598. Smallest Missing Non-negative Integer After Operations

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/)  
`Array` `Hash Table` `Math` `Greedy`

**Problem Link:** [LeetCode 2598 - Smallest Missing Non-negative Integer After Operations](https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/)

## Problem

You are given a 0-indexed integer array nums and an integer value.

In one operation, you can add or subtract value from any element of nums.

- For example, if nums = [1,2,3] and value = 2, you can choose to subtract value from nums[0] to make nums = [-1,2,3].

The MEX (minimum excluded) of an array is the smallest missing non-negative integer in it.

- For example, the MEX of [-1,2,3] is 0 while the MEX of [1,0,3] is 2.

Return the maximum MEX of nums after applying the mentioned operation any number of times.

### Example 1

```text
Input: nums = [1,-10,7,13,6,8], value = 5
Output: 4
Explanation: One can achieve this result by applying the following operations:
- Add value to nums[1] twice to make nums = [1,0,7,13,6,8]
- Subtract value from nums[2] once to make nums = [1,0,2,13,6,8]
- Subtract value from nums[3] twice to make nums = [1,0,2,3,6,8]
The MEX of nums is 4. It can be shown that 4 is the maximum MEX we can achieve.
```

### Example 2

```text
Input: nums = [1,-10,7,13,6,8], value = 7
Output: 2
Explanation: One can achieve this result by applying the following operation:
- subtract value from nums[2] once to make nums = [1,-10,0,13,6,8]
The MEX of nums is 2. It can be shown that 2 is the maximum MEX we can achieve.
```

## Constraints

- 1 <= nums.length, value <= 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2598. Smallest Missing Non-negative Integer After Operations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int findSmallestInteger(int* nums, int numsSize, int value) {
    int mp[value];
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int v = (x % value + value) % value;
        mp[v]++;
    }
    int mex = 0;
    while (mp[mex % value] > 0) {
        mp[mex % value]--;
        mex++;
    }
    return mex;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mp(value);
        for (auto& x : nums) {
            int v = (x % value + value) % value;
            mp[v]++;
        }
        int mex = 0;
        while (mp[mex % value] > 0) {
            mp[mex % value]--;
            mex++;
        }
        return mex;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FindSmallestInteger(int[] nums, int value) {
        int[] mp = new int[value];
        foreach (int x in nums) {
            int v = ((x % value) + value) % value;
            mp[v]++;
        }
        int mex = 0;
        while (mp[mex % value] > 0) {
            mp[mex % value]--;
            mex++;
        }
        return mex;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findSmallestInteger(nums []int, value int) int {
	mp := make([]int, value)
	for _, x := range nums {
		v := ((x % value) + value) % value
		mp[v]++
	}
	mex := 0
	for mp[mex%value] > 0 {
		mp[mex%value]--
		mex++
	}
	return mex
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findSmallestInteger(int[] nums, int value) {
        int[] mp = new int[value];
        for (int x : nums) {
            int v = ((x % value) + value) % value;
            mp[v]++;
        }
        int mex = 0;
        while (mp[mex % value] > 0) {
            mp[mex % value]--;
            mex++;
        }
        return mex;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findSmallestInteger = function (nums, value) {
    const mp = new Array(value).fill(0);
    for (let x of nums) {
        const v = ((x % value) + value) % value;
        mp[v]++;
    }
    let mex = 0;
    while (mp[mex % value] > 0) {
        mp[mex % value]--;
        mex++;
    }
    return mex;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        mp = Counter(x % value for x in nums)
        mex = 0
        while mp[mex % value] > 0:
            mp[mex % value] -= 1
            mex += 1
        return mex
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findSmallestInteger(nums: number[], value: number): number {
    const mp: number[] = new Array(value).fill(0);

    for (const x of nums) {
        const v = ((x % value) + value) % value;
        mp[v]++;
    }

    let mex = 0;
    while (mp[mex % value] > 0) {
        mp[mex % value]--;
        mex++;
    }

    return mex;
}
```

</details>
