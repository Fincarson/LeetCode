# 1534. Count Good Triplets

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/count-good-triplets/)  
`Array` `Enumeration`

**Problem Link:** [LeetCode 1534 - Count Good Triplets](https://leetcode.com/problems/count-good-triplets/)

## Problem

Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

- 0 <= i < j < k < arr.length
- |arr[i] - arr[j]| <= a
- |arr[j] - arr[k]| <= b
- |arr[i] - arr[k]| <= c

Where |x| denotes the absolute value of x.

Return the number of good triplets.

### Example 1

```text
Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
```

### Example 2

```text
Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
Output: 0
Explanation: No triplet satisfies all conditions.
```

## Constraints

- 3 <= arr.length <= 100
- 0 <= arr[i] <= 1000
- 0 <= a, b, c <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Special Quadruplets](https://leetcode.com/problems/count-special-quadruplets/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Number of Unequal Triplets in Array](https://leetcode.com/problems/number-of-unequal-triplets-in-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1534. Count Good Triplets

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Optimized enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int cnt = 0;
    for (int i = 0; i < arrSize; ++i) {
        for (int j = i + 1; j < arrSize; ++j) {
            for (int k = j + 1; k < arrSize; ++k) {
                if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b &&
                    abs(arr[i] - arr[k]) <= c) {
                    ++cnt;
                }
            }
        }
    }
    return cnt;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c) {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CountGoodTriplets(int[] arr, int a, int b, int c) {
        int n = arr.Length, cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (Math.Abs(arr[i] - arr[j]) <= a &&
                        Math.Abs(arr[j] - arr[k]) <= b &&
                        Math.Abs(arr[i] - arr[k]) <= c) {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countGoodTriplets(arr []int, a int, b int, c int) int {
    n := len(arr)
	cnt := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				if abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i]-arr[k]) <= c {
					cnt++
				}
			}
		}
	}
	return cnt
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int n = arr.length, cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (
                        Math.abs(arr[i] - arr[j]) <= a &&
                        Math.abs(arr[j] - arr[k]) <= b &&
                        Math.abs(arr[i] - arr[k]) <= c
                    ) {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countGoodTriplets = function (arr, a, b, c) {
    const n = arr.length;
    let cnt = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            for (let k = j + 1; k < n; ++k) {
                if (
                    Math.abs(arr[i] - arr[j]) <= a &&
                    Math.abs(arr[j] - arr[k]) <= b &&
                    Math.abs(arr[i] - arr[k]) <= c
                ) {
                    ++cnt;
                }
            }
        }
    }
    return cnt;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        n = len(arr)
        cnt = 0
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if (
                        abs(arr[i] - arr[j]) <= a
                        and abs(arr[j] - arr[k]) <= b
                        and abs(arr[i] - arr[k]) <= c
                    ):
                        cnt += 1
        return cnt
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countGoodTriplets(
    arr: number[],
    a: number,
    b: number,
    c: number,
): number {
    let n = arr.length,
        cnt = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            for (let k = j + 1; k < n; ++k) {
                if (
                    Math.abs(arr[i] - arr[j]) <= a &&
                    Math.abs(arr[j] - arr[k]) <= b &&
                    Math.abs(arr[i] - arr[k]) <= c
                ) {
                    ++cnt;
                }
            }
        }
    }
    return cnt;
}
```

</details>

<br>

## Approach 2: Optimized enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int ans = 0;
    int sum[1001] = {0};
    for (int j = 0; j < arrSize; ++j) {
        for (int k = j + 1; k < arrSize; ++k) {
            if (abs(arr[j] - arr[k]) <= b) {
                int lj = arr[j] - a, rj = arr[j] + a;
                int lk = arr[k] - c, rk = arr[k] + c;
                int l = fmax(0, fmax(lj, lk)), r = fmin(1000, fmin(rj, rk));
                if (l <= r) {
                    if (l == 0) {
                        ans += sum[r];
                    } else {
                        ans += sum[r] - sum[l - 1];
                    }
                }
            }
        }
        for (int k = arr[j]; k <= 1000; ++k) {
            ++sum[k];
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
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0, n = arr.size();
        vector<int> sum(1001, 0);
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (abs(arr[j] - arr[k]) <= b) {
                    int lj = arr[j] - a, rj = arr[j] + a;
                    int lk = arr[k] - c, rk = arr[k] + c;
                    int l = max(0, max(lj, lk)), r = min(1000, min(rj, rk));
                    if (l <= r) {
                        if (l == 0) {
                            ans += sum[r];
                        } else {
                            ans += sum[r] - sum[l - 1];
                        }
                    }
                }
            }
            for (int k = arr[j]; k <= 1000; ++k) {
                ++sum[k];
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
    public int CountGoodTriplets(int[] arr, int a, int b, int c) {
        int ans = 0, n = arr.Length;
        int[] sum = new int[1001];
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (Math.Abs(arr[j] - arr[k]) <= b) {
                    int lj = arr[j] - a, rj = arr[j] + a;
                    int lk = arr[k] - c, rk = arr[k] + c;
                    int l = Math.Max(0, Math.Max(lj, lk)),
                        r = Math.Min(1000, Math.Min(rj, rk));
                    if (l <= r) {
                        if (l == 0) {
                            ans += sum[r];
                        } else {
                            ans += sum[r] - sum[l - 1];
                        }
                    }
                }
            }
            for (int k = arr[j]; k <= 1000; ++k) {
                ++sum[k];
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
func countGoodTriplets(arr []int, a int, b int, c int) int {
	ans := 0
	n := len(arr)
	sum := make([]int, 1001)
	for j := 0; j < n; j++ {
		for k := j + 1; k < n; k++ {
			if abs(arr[j]-arr[k]) <= b {
				lj, rj := arr[j]-a, arr[j]+a
				lk, rk := arr[k]-c, arr[k]+c
				l := max(0, max(lj, lk))
				r := min(1000, min(rj, rk))
				if l <= r {
					if l == 0 {
						ans += sum[r]
					} else {
						ans += sum[r] - sum[l-1]
					}
				}
			}
		}
		for k := arr[j]; k <= 1000; k++ {
			sum[k]++
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int ans = 0, n = arr.length;
        int[] sum = new int[1001];
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (Math.abs(arr[j] - arr[k]) <= b) {
                    int lj = arr[j] - a, rj = arr[j] + a;
                    int lk = arr[k] - c, rk = arr[k] + c;
                    int l = Math.max(0, Math.max(lj, lk)), r = Math.min(
                        1000,
                        Math.min(rj, rk)
                    );
                    if (l <= r) {
                        if (l == 0) {
                            ans += sum[r];
                        } else {
                            ans += sum[r] - sum[l - 1];
                        }
                    }
                }
            }
            for (int k = arr[j]; k <= 1000; ++k) {
                ++sum[k];
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
var countGoodTriplets = function (arr, a, b, c) {
    const n = arr.length,
        sum = new Array(1001).fill(0);
    let ans = 0;
    for (let j = 0; j < n; ++j) {
        for (let k = j + 1; k < n; ++k) {
            if (Math.abs(arr[j] - arr[k]) <= b) {
                const lj = arr[j] - a,
                    rj = arr[j] + a;
                const lk = arr[k] - c,
                    rk = arr[k] + c;
                const l = Math.max(0, Math.max(lj, lk)),
                    r = Math.min(1000, Math.min(rj, rk));
                if (l <= r) {
                    if (l === 0) {
                        ans += sum[r];
                    } else {
                        ans += sum[r] - sum[l - 1];
                    }
                }
            }
        }
        for (let k = arr[j]; k <= 1000; ++k) {
            sum[k] += 1;
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
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        ans = 0
        n = len(arr)
        total = [0] * 1001
        for j in range(n):
            for k in range(j + 1, n):
                if abs(arr[j] - arr[k]) <= b:
                    lj, rj = arr[j] - a, arr[j] + a
                    lk, rk = arr[k] - c, arr[k] + c
                    l = max(0, lj, lk)
                    r = min(1000, rj, rk)
                    if l <= r:
                        ans += total[r] if l == 0 else total[r] - total[l - 1]
            for k in range(arr[j], 1001):
                total[k] += 1

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countGoodTriplets(
    arr: number[],
    a: number,
    b: number,
    c: number,
): number {
    let ans = 0;
    const n = arr.length;
    const sum = new Array(1001).fill(0);
    for (let j = 0; j < n; ++j) {
        for (let k = j + 1; k < n; ++k) {
            if (Math.abs(arr[j] - arr[k]) <= b) {
                const lj = arr[j] - a,
                    rj = arr[j] + a;
                const lk = arr[k] - c,
                    rk = arr[k] + c;
                const l = Math.max(0, Math.max(lj, lk)),
                    r = Math.min(1000, Math.min(rj, rk));
                if (l <= r) {
                    if (l === 0) {
                        ans += sum[r];
                    } else {
                        ans += sum[r] - sum[l - 1];
                    }
                }
            }
        }
        for (let k = arr[j]; k <= 1000; ++k) {
            sum[k]++;
        }
    }
    return ans;
}
```

</details>
