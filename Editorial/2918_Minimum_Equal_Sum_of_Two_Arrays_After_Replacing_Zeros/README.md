# 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/)  
`Array` `Greedy`

**Problem Link:** [LeetCode 2918 - Minimum Equal Sum of Two Arrays After Replacing Zeros](https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/)

## Problem

You are given two arrays nums1 and nums2 consisting of positive integers.

You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.

Return the minimum equal sum you can obtain, or -1 if it is impossible.

### Example 1

```text
Input: nums1 = [3,2,0,1,0], nums2 = [6,5,0]
Output: 12
Explanation: We can replace 0's in the following way:
- Replace the two 0's in nums1 with the values 2 and 4. The resulting array is nums1 = [3,2,2,1,4].
- Replace the 0 in nums2 with the value 1. The resulting array is nums2 = [6,5,1].
Both arrays have an equal sum of 12. It can be shown that it is the minimum sum we can obtain.
```

### Example 2

```text
Input: nums1 = [2,0,2,0], nums2 = [1,4]
Output: -1
Explanation: It is impossible to make the sum of both arrays equal.
```

## Constraints

- 1 <= nums1.length, nums2.length <= 105
- 0 <= nums1[i], nums2[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Minimum Sum Matching | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Minimum Sum Matching

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    long long sum1 = 0, sum2 = 0;
    int zero1 = 0, zero2 = 0;

    for (int i = 0; i < nums1Size; i++) {
        sum1 += nums1[i];
        if (nums1[i] == 0) {
            sum1 += 1;
            zero1++;
        }
    }

    for (int i = 0; i < nums2Size; i++) {
        sum2 += nums2[i];
        if (nums2[i] == 0) {
            sum2 += 1;
            zero2++;
        }
    }

    if ((zero1 == 0 && sum2 > sum1) || (zero2 == 0 && sum1 > sum2)) {
        return -1;
    }

    return sum1 > sum2 ? sum1 : sum2;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;
        for (int i : nums1) {
            sum1 += i;
            if (i == 0) {
                sum1++;
                zero1++;
            }
        }
        for (int i : nums2) {
            sum2 += i;
            if (i == 0) {
                sum2++;
                zero2++;
            }
        }
        if (!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2) {
            return -1;
        }
        return max(sum1, sum2);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MinSum(int[] nums1, int[] nums2) {
        long sum1 = 0, sum2 = 0;
        long zero1 = 0, zero2 = 0;

        foreach (int i in nums1) {
            sum1 += i;
            if (i == 0) {
                sum1++;
                zero1++;
            }
        }

        foreach (int i in nums2) {
            sum2 += i;
            if (i == 0) {
                sum2++;
                zero2++;
            }
        }

        if ((zero1 == 0 && sum2 > sum1) || (zero2 == 0 && sum1 > sum2)) {
            return -1;
        }

        return Math.Max(sum1, sum2);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minSum(nums1 []int, nums2 []int) int64 {
	var sum1, sum2 int64
	var zero1, zero2 int

	for _, num := range nums1 {
		sum1 += int64(num)
		if num == 0 {
			sum1++
			zero1++
		}
	}

	for _, num := range nums2 {
		sum2 += int64(num)
		if num == 0 {
			sum2++
			zero2++
		}
	}

	if (zero1 == 0 && sum2 > sum1) || (zero2 == 0 && sum1 > sum2) {
		return -1
	}

	if sum1 > sum2 {
		return sum1
	}
	return sum2
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minSum(int[] nums1, int[] nums2) {
        long sum1 = 0, sum2 = 0;
        long zero1 = 0, zero2 = 0;

        for (int i : nums1) {
            sum1 += i;
            if (i == 0) {
                sum1++;
                zero1++;
            }
        }

        for (int i : nums2) {
            sum2 += i;
            if (i == 0) {
                sum2++;
                zero2++;
            }
        }

        if ((zero1 == 0 && sum2 > sum1) || (zero2 == 0 && sum1 > sum2)) {
            return -1;
        }

        return Math.max(sum1, sum2);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minSum = function (nums1, nums2) {
    let sum1 = 0,
        sum2 = 0;
    let zero1 = 0,
        zero2 = 0;

    for (let i of nums1) {
        sum1 += i;
        if (i === 0) {
            sum1++;
            zero1++;
        }
    }

    for (let i of nums2) {
        sum2 += i;
        if (i === 0) {
            sum2++;
            zero2++;
        }
    }

    if ((zero1 === 0 && sum2 > sum1) || (zero2 === 0 && sum1 > sum2)) {
        return -1;
    }

    return Math.max(sum1, sum2);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        sum1 = sum2 = 0
        zero1 = zero2 = 0

        for i in nums1:
            sum1 += i
            if i == 0:
                sum1 += 1
                zero1 += 1

        for i in nums2:
            sum2 += i
            if i == 0:
                sum2 += 1
                zero2 += 1

        if (zero1 == 0 and sum2 > sum1) or (zero2 == 0 and sum1 > sum2):
            return -1

        return max(sum1, sum2)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minSum(nums1: number[], nums2: number[]): number {
    let sum1 = 0,
        sum2 = 0;
    let zero1 = 0,
        zero2 = 0;

    for (let i of nums1) {
        sum1 += i;
        if (i === 0) {
            sum1++;
            zero1++;
        }
    }

    for (let i of nums2) {
        sum2 += i;
        if (i === 0) {
            sum2++;
            zero2++;
        }
    }

    if ((zero1 === 0 && sum2 > sum1) || (zero2 === 0 && sum1 > sum2)) {
        return -1;
    }

    return Math.max(sum1, sum2);
}
```

</details>
