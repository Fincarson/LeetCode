# 2078. Two Furthest Houses With Different Colors

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/two-furthest-houses-with-different-colors/)  
`Array` `Greedy`

**Problem Link:** [LeetCode 2078 - Two Furthest Houses With Different Colors](https://leetcode.com/problems/two-furthest-houses-with-different-colors/)

## Problem

There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

Return the maximum distance between two houses with different colors.

The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

### Example 1

```text
Input: colors = [1,1,1,6,1,1,1]
Output: 3
Explanation: In the above image, color 1 is blue, and color 6 is red.
The furthest two houses with different colors are house 0 and house 3.
House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
Note that houses 3 and 6 can also produce the optimal answer.
```

### Example 2

```text
Input: colors = [1,8,3,8,3]
Output: 4
Explanation: In the above image, color 1 is blue, color 8 is yellow, and color 3 is green.
The furthest two houses with different colors are house 0 and house 4.
House 0 has color 1, and house 4 has color 3. The distance between them is abs(0 - 4) = 4.
```

### Example 3

```text
Input: colors = [0,1]
Output: 1
Explanation: The furthest two houses with different colors are house 0 and house 1.
House 0 has color 0, and house 1 has color 1. The distance between them is abs(0 - 1) = 1.
```

## Constraints

- n == colors.length
- 2 <= n <= 100
- 0 <= colors[i] <= 100
- Test data are generated such that at least two houses have different colors.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Replace Elements with Greatest Element on Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Maximum Distance Between a Pair of Values](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Difference Between Increasing Elements](https://leetcode.com/problems/maximum-difference-between-increasing-elements/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2078. Two Furthest Houses With Different Colors

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxDistance(int* colors, int colorsSize) {
    int n = colorsSize;
    int res = 0;  // the maximum distance between two houses of different colors
    // traverse the indices of two houses and maintain the maximum distance
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (colors[i] != colors[j]) {
                if (j - i > res) {
                    res = j - i;
                }
            }
        }
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int res =
            0;  // the maximum distance between two houses of different colors
        // traverse the indices of two houses and maintain the maximum distance
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (colors[i] != colors[j]) {
                    res = max(res, j - i);
                }
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
    public int MaxDistance(int[] colors) {
        int n = colors.Length;
        int res =
            0;  // the maximum distance between two houses of different colors
        // traverse the indices of two houses and maintain the maximum distance
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (colors[i] != colors[j]) {
                    res = Math.Max(res, j - i);
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDistance(colors []int) int {
	n := len(colors)
	res := 0 // the maximum distance between two houses of different colors
	// traverse the indices of two houses and maintain the maximum distance
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if colors[i] != colors[j] {
				if j-i > res {
					res = j - i
				}
			}
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

    public int maxDistance(int[] colors) {
        int n = colors.length;
        int res = 0; // the maximum distance between two houses of different colors
        // traverse the indices of two houses and maintain the maximum distance
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (colors[i] != colors[j]) {
                    res = Math.max(res, j - i);
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDistance = function (colors) {
    const n = colors.length;
    let res = 0; // the maximum distance between two houses of different colors
    // traverse the indices of two houses and maintain the maximum distance
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (colors[i] !== colors[j]) {
                res = Math.max(res, j - i);
            }
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
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        res = 0  # the maximum distance between two houses of different colors
        # traverse the indices of two houses and maintain the maximum distance
        for i in range(n):
            for j in range(i + 1, n):
                if colors[i] != colors[j]:
                    res = max(res, j - i)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDistance(colors: number[]): number {
    const n = colors.length;
    let res = 0; // the maximum distance between two houses of different colors
    // traverse the indices of two houses and maintain the maximum distance
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (colors[i] !== colors[j]) {
                res = Math.max(res, j - i);
            }
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxDistance(int* colors, int colorsSize) {
    int n = colorsSize;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (colors[i] != colors[n - 1]) {
            int d = i > n - 1 - i ? i : n - 1 - i;
            if (d > ans) ans = d;
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
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = max(ans, max(i, n - 1 - i));
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
    public int MaxDistance(int[] colors) {
        int n = colors.Length;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = Math.Max(ans, Math.Max(i, n - 1 - i));
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
func maxDistance(colors []int) int {
	n := len(colors)
	ans := 0
	for i := 0; i < n-1; i++ {
		if colors[i] != colors[n-1] {
			d := i
			if n-1-i > d {
				d = n - 1 - i
			}
			if d > ans {
				ans = d
			}
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
    public int maxDistance(int[] colors) {
        int n = colors.length;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = Math.max(ans, Math.max(i, n - 1 - i));
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
var maxDistance = function(colors) {
    const n = colors.length;
    let ans = 0;
    for (let i = 0; i < n - 1; i++) {
        if (colors[i] !== colors[n - 1]) {
            ans = Math.max(ans, i, n - 1 - i);
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
    def maxDistance(self, colors: List[int]) -> int:
        ans = 0
        n = len(colors)
        for i in range(n - 1):
            if colors[i] != colors[n - 1]:
                ans = max(ans, i, n - 1 - i)
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDistance(colors: number[]): number {
    const n = colors.length;
    let ans = 0;
    for (let i = 0; i < n - 1; i++) {
        if (colors[i] !== colors[n - 1]) {
            ans = Math.max(ans, i, n - 1 - i);
        }
    }
    return ans;
}
```

</details>
