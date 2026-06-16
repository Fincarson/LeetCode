# 2221. Find Triangular Sum of an Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-triangular-sum-of-an-array/)  
`Array` `Math` `Simulation` `Combinatorics` `Number Theory`

**Problem Link:** [LeetCode 2221 - Find Triangular Sum of an Array](https://leetcode.com/problems/find-triangular-sum-of-an-array/)

## Problem

You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).

The triangular sum of nums is the value of the only element present in nums after the following process terminates:

Return the triangular sum of nums.

### Example 1

```text
Input: nums = [1,2,3,4,5]
Output: 8
Explanation:
The above diagram depicts the process from which we obtain the triangular sum of the array.
```

### Example 2

```text
Input: nums = [5]
Output: 5
Explanation:
Since there is only one element in nums, the triangular sum is the value of that element itself.
```

## Constraints

- 1 <= nums.length <= 1000
- 0 <= nums[i] <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Calculate Digit Sum of a String](https://leetcode.com/problems/calculate-digit-sum-of-a-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Min Max Game](https://leetcode.com/problems/min-max-game/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2221. Find Triangular Sum of an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Combinatorics with Modular Arithmetic | C++, Java, Python3 |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int triangularSum(int* nums, int numsSize) {
    int* current = (int*)malloc(numsSize * sizeof(int));
    int* newNums = (int*)malloc(numsSize * sizeof(int));
    memcpy(current, nums, numsSize * sizeof(int));
    int currentSize = numsSize;
    while (currentSize > 1) {
        for (int i = 0; i < currentSize - 1; ++i) {
            newNums[i] = (current[i] + current[i + 1]) % 10;
        }
        currentSize--;
        memcpy(current, newNums, sizeof(int) * currentSize);
    }

    int result = current[0];
    free(current);
    free(newNums);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> new_nums;
            for (int i = 0; i < nums.size() - 1; ++i) {
                new_nums.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = move(new_nums);
        }
        return nums[0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int TriangularSum(int[] nums) {
        List<int> current = new List<int>(nums);
        while (current.Count > 1) {
            List<int> newNums = new List<int>();
            for (int i = 0; i < current.Count - 1; ++i) {
                newNums.Add((current[i] + current[i + 1]) % 10);
            }
            current = newNums;
        }
        return current[0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func triangularSum(nums []int) int {
	current := nums
	for len(current) > 1 {
		newNums := make([]int, 0, len(current)-1)
		for i := 0; i < len(current)-1; i++ {
			newNums = append(newNums, (current[i]+current[i+1])%10)
		}
		current = newNums
	}
	return current[0]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int triangularSum(int[] nums) {
        List<Integer> current = Arrays.stream(nums)
            .boxed()
            .collect(Collectors.toList());
        while (current.size() > 1) {
            List<Integer> newNums = new ArrayList<>();
            for (int i = 0; i < current.size() - 1; ++i) {
                newNums.add((current.get(i) + current.get(i + 1)) % 10);
            }
            current = newNums;
        }
        return current.get(0);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var triangularSum = function (nums) {
    let current = nums;
    while (current.length > 1) {
        const newNums = [];
        for (let i = 0; i < current.length - 1; i++) {
            newNums.push((current[i] + current[i + 1]) % 10);
        }
        current = newNums;
    }
    return current[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        while len(nums) > 1:
            new_nums = list()
            for i in range(len(nums) - 1):
                new_nums.append((nums[i] + nums[i + 1]) % 10)
            nums = new_nums
        return nums[0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function triangularSum(nums: number[]): number {
    let current = nums;
    while (current.length > 1) {
        const newNums: number[] = [];
        for (let i = 0; i < current.length - 1; i++) {
            newNums.push((current[i] + current[i + 1]) % 10);
        }
        current = newNums;
    }
    return current[0];
}
```

</details>

<br>

## Approach 2: Combinatorics with Modular Arithmetic

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int n1 = n - 1;

        // Precompute C(n, k) mod 5 for small digits (0 <= n, k < 5)
        int C5[5][5] = {0};
        for (int i = 0; i < 5; ++i) {
            C5[i][0] = 1;
            C5[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                C5[i][j] = (C5[i - 1][j - 1] + C5[i - 1][j]) % 5;
            }
        }

        // Helper: compute C(n, k) mod 2
        auto comb_mod2 = [](int n, int k) -> int {
            while (n > 0 || k > 0) {
                int nb = n & 1, kb = k & 1;
                if (kb > nb) return 0;
                n >>= 1; k >>= 1;
            }
            return 1;
        };

        // Helper: compute C(n, k) mod 5 using Lucas theorem
        auto comb_mod5 = [&](int n, int k) -> int {
            int res = 1;
            while (n > 0 || k > 0) {
                int nd = n % 5;
                int kd = k % 5;
                if (kd > nd) return 0;
                res = (res * C5[nd][kd]) % 5;
                n /= 5; k /= 5;
            }
            return res;
        };

        int ans = 0;

        // Combine contributions
        for (int i = 0; i <= n1; ++i) {
            int a2 = comb_mod2(n1, i);   // mod 2
            int a5 = comb_mod5(n1, i);   // mod 5
            int coeff_mod10 = (5 * a2 + 6 * a5) % 10; // Combine using CRT

            ans = (ans + coeff_mod10 * (nums[i] % 10)) % 10;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int triangularSum(int[] nums) {
        int n = nums.length;
        int n1 = n - 1;

        // Precompute C(n, k) mod 5 for digits 0..4
        int[][] C5 = new int[5][5];
        for (int i = 0; i < 5; ++i) {
            C5[i][0] = 1;
            C5[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                C5[i][j] = (C5[i - 1][j - 1] + C5[i - 1][j]) % 5;
            }
        }

        int ans = 0;

        for (int i = 0; i <= n1; ++i) {
            int a2 = combMod2(n1, i);
            int a5 = combMod5(n1, i, C5);

            // Combine via CRT
            int coeffMod10 = (5 * a2 + 6 * a5) % 10;

            ans = (ans + coeffMod10 * (nums[i] % 10)) % 10;
        }

        return ans;
    }

    private int combMod2(int n, int k) {
        while (n > 0 || k > 0) {
            int nb = n & 1, kb = k & 1;
            if (kb > nb) return 0;
            n >>= 1; k >>= 1;
        }
        return 1;
    }

    private int combMod5(int n, int k, int[][] C5) {
        int res = 1;
        while (n > 0 || k > 0) {
            int nd = n % 5;
            int kd = k % 5;
            if (kd > nd) return 0;
            res = (res * C5[nd][kd]) % 5;
            n /= 5; k /= 5;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n1 = len(nums) - 1

        # Precompute Pascal mod 5
        C5 = [[0]*5 for _ in range(5)]
        for i in range(5):
            C5[i][0] = 1
            C5[i][i] = 1
            for j in range(1, i):
                C5[i][j] = (C5[i-1][j-1] + C5[i-1][j]) % 5

        def comb_mod2(n, k):
            while n > 0 or k > 0:
                if k & 1 and not n & 1:
                    return 0
                n >>= 1
                k >>= 1
            return 1

        def comb_mod5(n, k):
            res = 1
            while n > 0 or k > 0:
                nd, kd = n % 5, k % 5
                if kd > nd:
                    return 0
                res = (res * C5[nd][kd]) % 5
                n //= 5
                k //= 5
            return res

        ans = 0
        for i, num in enumerate(nums):
            a2 = comb_mod2(n1, i)
            a5 = comb_mod5(n1, i)
            coeff_mod10 = (5 * a2 + 6 * a5) % 10
            ans = (ans + coeff_mod10 * num) % 10

        return ans
```

</details>
