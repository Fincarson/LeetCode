# 2197. Replace Non-Coprime Numbers in Array

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/replace-non-coprime-numbers-in-array/)  
`Array` `Math` `Stack` `Number Theory`

**Problem Link:** [LeetCode 2197 - Replace Non-Coprime Numbers in Array](https://leetcode.com/problems/replace-non-coprime-numbers-in-array/)

## Problem

You are given an array of integers nums. Perform the following steps:

Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in any arbitrary order will lead to the same result.

The test cases are generated such that the values in the final array are less than or equal to 108.

Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.

### Example 1

```text
Input: nums = [6,4,3,2,7,6,2]
Output: [12,7,6]
Explanation:
- (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
- (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
- (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
- (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [12,7,6].
Note that there are other ways to obtain the same resultant array.
```

### Example 2

```text
Input: nums = [2,2,1,1,3,3,3]
Output: [2,1,1,3]
Explanation:
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3,3].
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3].
- (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [2,1,1,3].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [2,1,1,3].
Note that there are other ways to obtain the same resultant array.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105
- The test cases are generated such that the values in the final array are less than or equal to 108.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Pairs of Interchangeable Rectangles](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Split the Array to Make Coprime Products](https://leetcode.com/problems/split-the-array-to-make-coprime-products/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2197. Replace Non-Coprime Numbers in Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int* replaceNonCoprimes(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int pos = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        while (pos > 0) {
            int last = ans[pos - 1];
            int g = gcd(last, num);
            if (g > 1) {
                num = last / g * num;
                pos--;
            } else {
                break;
            }
        }
        ans[pos++] = num;
    }
    *returnSize = pos;
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            while (!ans.empty()) {
                int g = gcd(ans.back(), num);
                if (g > 1) {
                    num = ans.back() / g * num;
                    ans.pop_back();
                } else {
                    break;
                }
            }
            ans.push_back(num);
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
    public IList<int> ReplaceNonCoprimes(int[] nums) {
        List<int> ans = new List<int>();
        for (int i = 0; i < nums.Length; i++) {
            int num = nums[i];
            while (ans.Count > 0) {
                int last = ans[ans.Count - 1];
                int g = GCD(last, num);
                if (g > 1) {
                    num = last / g * num;
                    ans.RemoveAt(ans.Count - 1);
                } else {
                    break;
                }
            }
            ans.Add(num);
        }
        return ans;
    }

    private int GCD(int a, int b) {
        return b == 0 ? a : GCD(b, a % b);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func replaceNonCoprimes(nums []int) []int {
	ans := []int{}
	for _, num := range nums {
		for len(ans) > 0 {
			last := ans[len(ans)-1]
			g := gcd(last, num)
			if g > 1 {
				num = last / g * num
				ans = ans[:len(ans)-1]
			} else {
				break
			}
		}
		ans = append(ans, num)
	}
	return ans
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

    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        for (int num : nums) {
            while (!ans.isEmpty()) {
                int last = ans.get(ans.size() - 1);
                int g = gcd(last, num);
                if (g > 1) {
                    num = (last / g) * num;
                    ans.remove(ans.size() - 1);
                } else {
                    break;
                }
            }
            ans.add(num);
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var replaceNonCoprimes = function (nums) {
    const ans = [];
    for (let num of nums) {
        while (ans.length > 0) {
            const last = ans[ans.length - 1];
            const g = gcd(last, num);
            if (g > 1) {
                num = Math.floor(last / g) * num;
                ans.pop();
            } else {
                break;
            }
        }
        ans.push(num);
    }
    return ans;
};

const gcd = (a, b) => {
    return b === 0 ? a : gcd(b, a % b);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        ans = list()
        for num in nums:
            while ans:
                g = math.gcd(ans[-1], num)
                if g > 1:
                    num = ans[-1] // g * num
                    ans.pop()
                else:
                    break
            ans.append(num)

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function replaceNonCoprimes(nums: number[]): number[] {
    const ans: number[] = [];
    for (let num of nums) {
        while (ans.length > 0) {
            const last = ans[ans.length - 1];
            const g = gcd(last, num);
            if (g > 1) {
                num = Math.floor(last / g) * num;
                ans.pop();
            } else {
                break;
            }
        }
        ans.push(num);
    }
    return ans;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```

</details>
