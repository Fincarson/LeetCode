# 2654. Minimum Number of Operations to Make All Array Elements Equal to 1

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/)  
`Array` `Math` `Number Theory`

**Problem Link:** [LeetCode 2654 - Minimum Number of Operations to Make All Array Elements Equal to 1](https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/)

## Problem

You are given a 0-indexed array nums consisting of positive integers. You can do the following operation on the array any number of times:

- Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.

Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.

The gcd of two integers is the greatest common divisor of the two integers.

### Example 1

```text
Input: nums = [2,6,3,4]
Output: 4
Explanation: We can do the following operations:
- Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
- Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
- Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
- Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
```

### Example 2

```text
Input: nums = [2,10,6,14]
Output: -1
Explanation: It can be shown that it is impossible to make all the elements equal to 1.
```

## Constraints

- 2 <= nums.length <= 50
- 1 <= nums[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2654. Minimum Number of Operations to Make All Array Elements Equal to 1

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
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int minOperations(int* nums, int numsSize) {
    int n = numsSize;
    int num1 = 0;
    int g = 0;
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        if (x == 1) {
            num1++;
        }
        g = gcd(g, x);
    }
    if (num1 > 0) {
        return n - num1;
    }
    if (g > 1) {
        return -1;
    }

    int min_len = n;
    for (int i = 0; i < n; i++) {
        int current_gcd = 0;
        for (int j = i; j < n; j++) {
            current_gcd = gcd(current_gcd, nums[j]);
            if (current_gcd == 1) {
                if (j - i + 1 < min_len) {
                    min_len = j - i + 1;
                }
                break;
            }
        }
    }
    return min_len + n - 2;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0;
        int g = 0;
        for (int x : nums) {
            if (x == 1) {
                num1++;
            }
            g = gcd(g, x);
        }
        if (num1 > 0) {
            return n - num1;
        }
        if (g > 1) {
            return -1;
        }

        int min_len = n;
        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }
        return min_len + n - 2;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinOperations(int[] nums) {
        int n = nums.Length;
        int num1 = 0;
        int g = 0;
        foreach (int x in nums) {
            if (x == 1) {
                num1++;
            }
            g = GCD(g, x);
        }
        if (num1 > 0) {
            return n - num1;
        }
        if (g > 1) {
            return -1;
        }

        int minLen = n;
        for (int i = 0; i < n; i++) {
            int currentGcd = 0;
            for (int j = i; j < n; j++) {
                currentGcd = GCD(currentGcd, nums[j]);
                if (currentGcd == 1) {
                    minLen = Math.Min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen + n - 2;
    }

    private int GCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minOperations(nums []int) int {
	n := len(nums)
	num1 := 0
	g := 0
	for _, x := range nums {
		if x == 1 {
			num1++
		}
		g = gcd(g, x)
	}
	if num1 > 0 {
		return n - num1
	}
	if g > 1 {
		return -1
	}

	minLen := n
	for i := 0; i < n; i++ {
		currentGcd := 0
		for j := i; j < n; j++ {
			currentGcd = gcd(currentGcd, nums[j])
			if currentGcd == 1 {
				if j-i+1 < minLen {
					minLen = j - i + 1
				}
				break
			}
		}
	}
	return minLen + n - 2
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minOperations(int[] nums) {
        int n = nums.length;
        int num1 = 0;
        int g = 0;
        for (int x : nums) {
            if (x == 1) {
                num1++;
            }
            g = gcd(g, x);
        }
        if (num1 > 0) {
            return n - num1;
        }
        if (g > 1) {
            return -1;
        }

        int minLen = n;
        for (int i = 0; i < n; i++) {
            int currentGcd = 0;
            for (int j = i; j < n; j++) {
                currentGcd = gcd(currentGcd, nums[j]);
                if (currentGcd == 1) {
                    minLen = Math.min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen + n - 2;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minOperations = function (nums) {
    const n = nums.length;
    let num1 = 0;
    let g = 0;

    const gcd = (a, b) => {
        while (b !== 0) {
            const temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    };

    for (const x of nums) {
        if (x === 1) {
            num1++;
        }
        g = gcd(g, x);
    }

    if (num1 > 0) {
        return n - num1;
    }
    if (g > 1) {
        return -1;
    }

    let minLen = n;
    for (let i = 0; i < n; i++) {
        let currentGcd = 0;
        for (let j = i; j < n; j++) {
            currentGcd = gcd(currentGcd, nums[j]);
            if (currentGcd === 1) {
                minLen = Math.min(minLen, j - i + 1);
                break;
            }
        }
    }
    return minLen + n - 2;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        num1 = 0
        g = 0

        for x in nums:
            if x == 1:
                num1 += 1
            g = gcd(g, x)

        if num1 > 0:
            return n - num1
        if g > 1:
            return -1

        min_len = n
        for i in range(n):
            g = 0
            for j in range(i, n):
                g = gcd(g, nums[j])
                if g == 1:
                    min_len = min(min_len, j - i + 1)
                    break

        return min_len + n - 2
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minOperations(nums: number[]): number {
    const n: number = nums.length;
    let num1: number = 0;
    let g: number = 0;

    const gcd = (a: number, b: number): number => {
        while (b !== 0) {
            const temp: number = b;
            b = a % b;
            a = temp;
        }
        return a;
    };

    for (const x of nums) {
        if (x === 1) {
            num1++;
        }
        g = gcd(g, x);
    }

    if (num1 > 0) {
        return n - num1;
    }
    if (g > 1) {
        return -1;
    }

    let minLen: number = n;
    for (let i = 0; i < n; i++) {
        let currentGcd: number = 0;
        for (let j = i; j < n; j++) {
            currentGcd = gcd(currentGcd, nums[j]);
            if (currentGcd === 1) {
                minLen = Math.min(minLen, j - i + 1);
                break;
            }
        }
    }
    return minLen + n - 2;
}
```

</details>
