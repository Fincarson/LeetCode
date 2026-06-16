# 3300. Minimum Element After Replacement With Digit Sum

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/)  
`Array` `Math`

**Problem Link:** [LeetCode 3300 - Minimum Element After Replacement With Digit Sum](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/)

## Problem

You are given an integer array nums.

You replace each element in nums with the sum of its digits.

Return the minimum element in nums after all replacements.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3300. Minimum Element After Replacement With Digit Sum

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
int minElement(int* nums, int numsSize) {
    int ans = 37;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int dig = 0;
        while (num > 0) {
            dig += num % 10;
            num /= 10;
        }
        if (dig < ans) {
            ans = dig;
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
    int minElement(vector<int>& nums) {
        int ans = 37;
        for (int num : nums) {
            int dig = 0;
            while (num) {
                dig += num % 10;
                num /= 10;
            }
            ans = min(ans, dig);
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
    public int MinElement(int[] nums) {
        int ans = 37;
        foreach (int num in nums) {
            int dig = 0;
            int n = num;
            while (n > 0) {
                dig += n % 10;
                n /= 10;
            }
            ans = Math.Min(ans, dig);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minElement(nums []int) int {
	ans := 37
	for _, num := range nums {
		dig := 0
		n := num
		for n > 0 {
			dig += n % 10
			n /= 10
		}
		if dig < ans {
			ans = dig
		}
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minElement(int[] nums) {
        int ans = 37;
        for (int num : nums) {
            int dig = 0;
            while (num > 0) {
                dig += num % 10;
                num /= 10;
            }
            ans = Math.min(ans, dig);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function minElement(nums) {
    let ans = 37;
    for (const num of nums) {
        let dig = 0;
        let n = num;
        while (n > 0) {
            dig += n % 10;
            n = Math.floor(n / 10);
        }
        ans = Math.min(ans, dig);
    }
    return ans;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minElement(self, nums: List[int]) -> int:
        ans = 37
        for num in nums:
            dig = 0
            while num > 0:
                dig += num % 10
                num //= 10
            ans = min(ans, dig)
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minElement(nums: number[]): number {
    let ans = 37;
    for (const num of nums) {
        let dig = 0;
        let n = num;
        while (n > 0) {
            dig += n % 10;
            n = Math.floor(n / 10);
        }
        ans = Math.min(ans, dig);
    }
    return ans;
}
```

</details>
