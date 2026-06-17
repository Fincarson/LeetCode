# 2553. Separate the Digits in an Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/separate-the-digits-in-an-array/)  
`Array` `Simulation`

**Problem Link:** [LeetCode 2553 - Separate the Digits in an Array](https://leetcode.com/problems/separate-the-digits-in-an-array/)

## Problem

Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.

To separate the digits of an integer is to get all the digits it has in the same order.

- For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].

### Example 1

```text
Input: nums = [13,25,83,77]
Output: [1,3,2,5,8,3,7,7]
Explanation:
- The separation of 13 is [1,3].
- The separation of 25 is [2,5].
- The separation of 83 is [8,3].
- The separation of 77 is [7,7].
answer = [1,3,2,5,8,3,7,7]. Note that answer contains the separations in the same order.
```

### Example 2

```text
Input: nums = [7,1,3,9]
Output: [7,1,3,9]
Explanation: The separation of each integer in nums is itself.
answer = [7,1,3,9].
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Integers With Even Digit Sum](https://leetcode.com/problems/count-integers-with-even-digit-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Alternating Digit Sum](https://leetcode.com/problems/alternating-digit-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2553. Separate the Digits in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Reverse Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int totalDigits = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        if (x == 0) {
            totalDigits++;
        } else {
            while (x > 0) {
                totalDigits++;
                x /= 10;
            }
        }
    }

    int* res = (int*)malloc(totalDigits * sizeof(int));
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int* tmp = (int*)malloc(10 * sizeof(int));
        int tmpSize = 0;
        if (x == 0) {
            res[index++] = 0;
            continue;
        }
        while (x > 0) {
            tmp[tmpSize++] = x % 10;
            x /= 10;
        }
        for (int j = tmpSize - 1; j >= 0; j--) {
            res[index++] = tmp[j];
        }
        free(tmp);
    }

    *returnSize = totalDigits;
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (auto x : nums) {
            vector<int> tmp;
            while (x > 0) {
                tmp.push_back(x % 10);
                x /= 10;
            }
            for (int i = tmp.size() - 1; i >= 0; i--) {
                res.push_back(tmp[i]);
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] SeparateDigits(int[] nums) {
        List<int> res = new List<int>();
        foreach (int num in nums) {
            int x = num;
            List<int> tmp = new List<int>();
            while (x > 0) {
                tmp.Add(x % 10);
                x /= 10;
            }
            for (int i = tmp.Count - 1; i >= 0; i--) {
                res.Add(tmp[i]);
            }
        }
        return res.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func separateDigits(nums []int) []int {
	res := []int{}
	for _, num := range nums {
		x := num
		tmp := []int{}
		for x > 0 {
			tmp = append(tmp, x%10)
			x /= 10
		}
		for i := len(tmp) - 1; i >= 0; i-- {
			res = append(res, tmp[i])
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] separateDigits(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int x : nums) {
            List<Integer> tmp = new ArrayList<>();
            while (x > 0) {
                tmp.add(x % 10);
                x /= 10;
            }
            for (int i = tmp.size() - 1; i >= 0; i--) {
                res.add(tmp.get(i));
            }
        }

        int[] result = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            result[i] = res.get(i);
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var separateDigits = function (nums) {
    const res = [];
    for (let num of nums) {
        let x = num;
        const tmp = [];
        while (x > 0) {
            tmp.push(x % 10);
            x = Math.floor(x / 10);
        }
        for (let i = tmp.length - 1; i >= 0; i--) {
            res.push(tmp[i]);
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []
        for x in nums:
            tmp = []
            while x > 0:
                tmp.append(x % 10)
                x //= 10
            res.extend(tmp[::-1])
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function separateDigits(nums: number[]): number[] {
    const res: number[] = [];
    for (const num of nums) {
        let x = num;
        const tmp: number[] = [];
        while (x > 0) {
            tmp.push(x % 10);
            x = Math.floor(x / 10);
        }
        for (let i = tmp.length - 1; i >= 0; i--) {
            res.push(tmp[i]);
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: Reverse Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int totalDigits = 0;
    for (int i = numsSize - 1; i >= 0; i--) {
        int x = nums[i];
        while (x > 0) {
            totalDigits++;
            x /= 10;
        }
    }

    int* temp = (int*)malloc(totalDigits * sizeof(int));
    int index = 0;
    for (int i = numsSize - 1; i >= 0; i--) {
        int x = nums[i];
        while (x > 0) {
            temp[index++] = x % 10;
            x /= 10;
        }
    }

    int* res = (int*)malloc(totalDigits * sizeof(int));
    for (int i = 0; i < totalDigits; i++) {
        res[i] = temp[totalDigits - 1 - i];
    }

    free(temp);
    *returnSize = totalDigits;
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int x = nums[i];
            while (x > 0) {
                res.push_back(x % 10);
                x /= 10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    public int[] SeparateDigits(int[] nums) {
        List<int> res = new List<int>();
        for (int i = nums.Length - 1; i >= 0; i--) {
            int x = nums[i];
            while (x > 0) {
                res.Add(x % 10);
                x /= 10;
            }
        }
        res.Reverse();
        return res.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func separateDigits(nums []int) []int {
	res := []int{}
	for i := len(nums) - 1; i >= 0; i-- {
		x := nums[i]
		for x > 0 {
			res = append(res, x%10)
			x /= 10
		}
	}

	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i]
	}

	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] separateDigits(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            int x = nums[i];
            while (x > 0) {
                res.add(x % 10);
                x /= 10;
            }
        }

        Collections.reverse(res);
        int[] result = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            result[i] = res.get(i);
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var separateDigits = function (nums) {
    const res = [];
    for (let i = nums.length - 1; i >= 0; i--) {
        let x = nums[i];
        while (x > 0) {
            res.push(x % 10);
            x = Math.floor(x / 10);
        }
    }
    res.reverse();
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums) - 1, -1, -1):
            x = nums[i]
            while x > 0:
                res.append(x % 10)
                x //= 10
        res.reverse()
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function separateDigits(nums: number[]): number[] {
    const res: number[] = [];
    for (let i = nums.length - 1; i >= 0; i--) {
        let x = nums[i];
        while (x > 0) {
            res.push(x % 10);
            x = Math.floor(x / 10);
        }
    }
    res.reverse();
    return res;
}
```

</details>
