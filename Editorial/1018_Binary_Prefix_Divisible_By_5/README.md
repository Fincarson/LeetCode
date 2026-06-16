# 1018. Binary Prefix Divisible By 5

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/binary-prefix-divisible-by-5/)  
`Array` `Bit Manipulation`

**Problem Link:** [LeetCode 1018 - Binary Prefix Divisible By 5](https://leetcode.com/problems/binary-prefix-divisible-by-5/)

## Problem

You are given a binary array nums (0-indexed).

We define xi as the number whose binary representation is the subarray nums[0..i] (from most-significant-bit to least-significant-bit).

- For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.

Return an array of booleans answer where answer[i] is true if xi is divisible by 5.

### Example 1

```text
Input: nums = [0,1,1]
Output: [true,false,false]
Explanation: The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.
Only the first number is divisible by 5, so answer[0] is true.
```

### Example 2

```text
Input: nums = [1,1,1]
Output: [false,false,false]
```

## Constraints

- 1 <= nums.length <= 105
- nums[i] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Average Value of Even Numbers That Are Divisible by Three](https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the Maximum Divisibility Score](https://leetcode.com/problems/find-the-maximum-divisibility-score/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1018. Binary Prefix Divisible By 5

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traversal | C, C++, Go, Java, JavaScript, Python3 |

## Approach: Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    bool* answer = malloc(sizeof(bool) * numsSize);
    int prefix = 0;
    for (int i = 0; i < numsSize; i++) {
        prefix = ((prefix << 1) + nums[i]) % 5;
        answer[i] = prefix == 0;
    }
    return answer;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
        int prefix = 0;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            prefix = ((prefix << 1) + nums[i]) % 5;
            answer.emplace_back(prefix == 0);
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func prefixesDivBy5(nums []int) []bool {
	ans := make([]bool, len(nums))
	x := 0
	for i, v := range nums {
		x = (x<<1 | v) % 5
		ans[i] = x == 0
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> answer = new ArrayList<Boolean>();
        int prefix = 0;
        int length = nums.length;
        for (int i = 0; i < length; i++) {
            prefix = ((prefix << 1) + nums[i]) % 5;
            answer.add(prefix == 0);
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var prefixesDivBy5 = function (nums) {
    const answer = [];
    let prefix = 0;
    const length = nums.length;
    for (let i = 0; i < length; i++) {
        prefix = ((prefix << 1) + nums[i]) % 5;
        answer.push(prefix === 0);
    }
    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        answer = list()
        prefix = 0
        for num in nums:
            prefix = ((prefix << 1) + num) % 5
            answer.append(prefix == 0)
        return answer
```

</details>
