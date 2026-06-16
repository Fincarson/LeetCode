# 3354. Make Array Elements Equal to Zero

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/make-array-elements-equal-to-zero/)  
`Array` `Simulation` `Prefix Sum`

**Problem Link:** [LeetCode 3354 - Make Array Elements Equal to Zero](https://leetcode.com/problems/make-array-elements-equal-to-zero/)

## Problem

You are given an integer array nums.

Start by selecting a starting position curr such that nums[curr] == 0, and choose a movement direction of either left or right.

After that, you repeat the following process:

- If curr is out of the range [0, n - 1], this process ends.
- If nums[curr] == 0, move in the current direction by incrementing curr if you are moving right, or decrementing curr if you are moving left.
- Else if nums[curr] > 0:

		Decrement nums[curr] by 1.
		Reverse your movement direction (left becomes right and vice versa).
		Take a step in your new direction.

A selection of the initial position curr and movement direction is considered valid if every element in nums becomes 0 by the end of the process.

Return the number of possible valid selections.

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 100
- 0 <= nums[i] <= 100
- There is at least one element i where nums[i] == 0.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3354. Make Array Elements Equal to Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Prefix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int isValid(int* nums, int n, int nonZeros, int start, int direction) {
    int temp[1000];
    memcpy(temp, nums, n * sizeof(int));
    int curr = start;
    while (nonZeros > 0 && curr >= 0 && curr < n) {
        if (temp[curr] > 0) {
            temp[curr]--;
            direction *= -1;
            if (temp[curr] == 0) nonZeros--;
        }
        curr += direction;
    }
    return nonZeros == 0;
}

int countValidSelections(int* nums, int n) {
    int count = 0, nonZeros = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] > 0) nonZeros++;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (isValid(nums, n, nonZeros, i, -1)) count++;
            if (isValid(nums, n, nonZeros, i, 1)) count++;
        }
    }
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int count = 0;
        int nonZeros = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                nonZeros++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, nonZeros, i, -1)) {
                    count++;
                }
                if (isValid(nums, nonZeros, i, 1)) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    bool isValid(const vector<int>& nums, int nonZeros, int start,
                 int direction) {
        int n = nums.size();
        vector<int> temp(nums);
        int curr = start;

        while (nonZeros > 0 && curr >= 0 && curr < n) {
            if (temp[curr] > 0) {
                temp[curr]--;
                direction *= -1;
                if (temp[curr] == 0) {
                    nonZeros--;
                }
            }
            curr += direction;
        }

        return nonZeros == 0;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    public int CountValidSelections(int[] nums) {
        int count = 0, nonZeros = nums.Count(x => x > 0), n = nums.Length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (IsValid(nums, nonZeros, i, -1))
                    count++;
                if (IsValid(nums, nonZeros, i, 1))
                    count++;
            }
        }
        return count;
    }

    bool IsValid(int[] nums, int nonZeros, int start, int direction) {
        int n = nums.Length;
        int[] temp = (int[])nums.Clone();
        int curr = start;
        while (nonZeros > 0 && curr >= 0 && curr < n) {
            if (temp[curr] > 0) {
                temp[curr]--;
                direction *= -1;
                if (temp[curr] == 0)
                    nonZeros--;
            }
            curr += direction;
        }
        return nonZeros == 0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countValidSelections(nums []int) int {
	count, nonZeros, n := 0, 0, len(nums)
	for _, x := range nums {
		if x > 0 {
			nonZeros++
		}
	}
	for i := 0; i < n; i++ {
		if nums[i] == 0 {
			if isValid(nums, nonZeros, i, -1) {
				count++
			}
			if isValid(nums, nonZeros, i, 1) {
				count++
			}
		}
	}
	return count
}

func isValid(nums []int, nonZeros, start, direction int) bool {
	temp := make([]int, len(nums))
	copy(temp, nums)
	curr := start
	for nonZeros > 0 && curr >= 0 && curr < len(nums) {
		if temp[curr] > 0 {
			temp[curr]--
			direction *= -1
			if temp[curr] == 0 {
				nonZeros--
			}
		}
		curr += direction
	}
	return nonZeros == 0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countValidSelections(int[] nums) {
        int count = 0;
        int nonZeros = 0;
        int n = nums.length;
        for (int x : nums) if (x > 0) nonZeros++;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, nonZeros, i, -1)) count++;
                if (isValid(nums, nonZeros, i, 1)) count++;
            }
        }
        return count;
    }

    private boolean isValid(
        int[] nums,
        int nonZeros,
        int start,
        int direction
    ) {
        int n = nums.length;
        int curr = start;
        int[] temp = nums.clone();
        while (nonZeros > 0 && curr >= 0 && curr < n) {
            if (temp[curr] > 0) {
                temp[curr]--;
                direction *= -1;
                if (temp[curr] == 0) nonZeros--;
            }
            curr += direction;
        }
        return nonZeros == 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countValidSelections = function (nums) {
    let count = 0,
        nonZeros = nums.filter((x) => x > 0).length,
        n = nums.length;
    for (let i = 0; i < n; i++) {
        if (nums[i] === 0) {
            if (isValid([...nums], nonZeros, i, -1)) count++;
            if (isValid([...nums], nonZeros, i, 1)) count++;
        }
    }
    return count;
};

function isValid(nums, nonZeros, start, direction) {
    let curr = start;
    while (nonZeros > 0 && curr >= 0 && curr < nums.length) {
        if (nums[curr] > 0) {
            nums[curr]--;
            direction *= -1;
            if (nums[curr] === 0) nonZeros--;
        }
        curr += direction;
    }
    return nonZeros === 0;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countValidSelections(self, nums):
        count = 0
        nonZeros = sum(1 for x in nums if x > 0)
        n = len(nums)
        for i in range(n):
            if nums[i] == 0:
                if self.isValid(nums, nonZeros, i, -1):
                    count += 1
                if self.isValid(nums, nonZeros, i, 1):
                    count += 1
        return count

    def isValid(self, nums, nonZeros, start, direction):
        temp = nums[:]
        curr = start
        while nonZeros > 0 and 0 <= curr < len(nums):
            if temp[curr] > 0:
                temp[curr] -= 1
                direction *= -1
                if temp[curr] == 0:
                    nonZeros -= 1
            curr += direction
        return nonZeros == 0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countValidSelections(nums: number[]): number {
    let count = 0,
        nonZeros = nums.filter((x) => x > 0).length,
        n = nums.length;
    for (let i = 0; i < n; i++) {
        if (nums[i] === 0) {
            if (isValid([...nums], nonZeros, i, -1)) count++;
            if (isValid([...nums], nonZeros, i, 1)) count++;
        }
    }
    return count;
}

function isValid(nums, nonZeros, start, direction) {
    let curr = start;
    while (nonZeros > 0 && curr >= 0 && curr < nums.length) {
        if (nums[curr] > 0) {
            nums[curr]--;
            direction *= -1;
            if (nums[curr] === 0) nonZeros--;
        }
        curr += direction;
    }
    return nonZeros === 0;
}
```

</details>

<br>

## Approach 2: Prefix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countValidSelections(int* nums, int n) {
    int ans = 0, sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];
    int left = 0, right = sum;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (left - right >= 0 && left - right <= 1) ans++;
            if (right - left >= 0 && right - left <= 1) ans++;
        } else {
            left += nums[i];
            right -= nums[i];
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
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int rightSum = sum;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (leftSum - rightSum >= 0 && leftSum - rightSum <= 1) {
                    ans++;
                }
                if (rightSum - leftSum >= 0 && rightSum - leftSum <= 1) {
                    ans++;
                }
            } else {
                leftSum += nums[i];
                rightSum -= nums[i];
            }
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
    public int CountValidSelections(int[] nums) {
        int n = nums.Length, ans = 0;
        int sum = nums.Sum();
        int left = 0, right = sum;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (left - right >= 0 && left - right <= 1)
                    ans++;
                if (right - left >= 0 && right - left <= 1)
                    ans++;
            } else {
                left += nums[i];
                right -= nums[i];
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countValidSelections(nums []int) int {
	n := len(nums)
	sum := 0
	for _, x := range nums {
		sum += x
	}
	ans, leftSum, rightSum := 0, 0, sum
	for i := 0; i < n; i++ {
		if nums[i] == 0 {
			if leftSum-rightSum >= 0 && leftSum-rightSum <= 1 {
				ans++
			}
			if rightSum-leftSum >= 0 && rightSum-leftSum <= 1 {
				ans++
			}
		} else {
			leftSum += nums[i]
			rightSum -= nums[i]
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

    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int ans = 0;
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        int leftSum = 0;
        int rightSum = sum;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (leftSum - rightSum >= 0 && leftSum - rightSum <= 1) {
                    ans++;
                }
                if (rightSum - leftSum >= 0 && rightSum - leftSum <= 1) {
                    ans++;
                }
            } else {
                leftSum += nums[i];
                rightSum -= nums[i];
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countValidSelections = function (nums) {
    let n = nums.length,
        ans = 0;
    let sum = nums.reduce((a, b) => a + b, 0);
    let left = 0,
        right = sum;
    for (let i = 0; i < n; i++) {
        if (nums[i] === 0) {
            if (left - right >= 0 && left - right <= 1) ans++;
            if (right - left >= 0 && right - left <= 1) ans++;
        } else {
            left += nums[i];
            right -= nums[i];
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countValidSelections(self, nums):
        n = len(nums)
        ans = 0
        s = sum(nums)
        left, right = 0, s
        for i in range(n):
            if nums[i] == 0:
                if 0 <= left - right <= 1:
                    ans += 1
                if 0 <= right - left <= 1:
                    ans += 1
            else:
                left += nums[i]
                right -= nums[i]
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countValidSelections(nums: number[]): number {
    let n = nums.length,
        ans = 0;
    let sum = nums.reduce((a, b) => a + b, 0);
    let left = 0,
        right = sum;
    for (let i = 0; i < n; i++) {
        if (nums[i] === 0) {
            if (left - right >= 0 && left - right <= 1) ans++;
            if (right - left >= 0 && right - left <= 1) ans++;
        } else {
            left += nums[i];
            right -= nums[i];
        }
    }
    return ans;
}
```

</details>
