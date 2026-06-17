# 1262. Greatest Sum Divisible by Three

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/greatest-sum-divisible-by-three/)  
`Array` `Dynamic Programming` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1262 - Greatest Sum Divisible by Three](https://leetcode.com/problems/greatest-sum-divisible-by-three/)

## Problem

Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

### Example 1

```text
Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
```

### Example 2

```text
Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.
```

### Example 3

```text
Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
```

## Constraints

- 1 <= nums.length <= 4 * 104
- 1 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1262. Greatest Sum Divisible by Three

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy + Forward Thinking | C, C++, C#, Go, Java, JavaScript, Python3 |
| Greedy + Backward Thinking | C, C++, C#, Go, Java, JavaScript, Python3 |
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach 1: Greedy + Forward Thinking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
static int cmp(const void* a, const void* b) { return *(int*)b - *(int*)a; }

int maxSumDivThree(int* nums, int numsSize) {
    // Use v[0], v[1], v[2] to represent a, b, c respectively.
    int n = numsSize;
    int v[3][n];
    int vColSize[3];
    memset(vColSize, 0, sizeof(vColSize));
    for (int i = 0; i < numsSize; i++) {
        v[nums[i] % 3][vColSize[nums[i] % 3]++] = nums[i];
    }
    qsort(v[1], vColSize[1], sizeof(int), cmp);
    qsort(v[2], vColSize[2], sizeof(int), cmp);

    int ans = 0;
    int lb = vColSize[1], lc = vColSize[2];
    for (int cntb = lb - 2; cntb <= lb; ++cntb) {
        if (cntb >= 0) {
            for (int cntc = lc - 2; cntc <= lc; ++cntc) {
                if (cntc >= 0 && (cntb - cntc) % 3 == 0) {
                    int sum1 = 0, sum2 = 0;
                    for (int i = 0; i < cntb; i++) {
                        sum1 += v[1][i];
                    }
                    for (int i = 0; i < cntc; i++) {
                        sum2 += v[2][i];
                    }
                    ans = fmax(ans, sum1 + sum2);
                }
            }
        }
    }
    for (int i = 0; i < vColSize[0]; i++) {
        ans += v[0][i];
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
    int maxSumDivThree(vector<int>& nums) {
        // Use v[0], v[1], v[2] to represent a, b, c respectively.
        vector<int> v[3];
        for (int num : nums) {
            v[num % 3].push_back(num);
        }
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());

        int ans = 0;
        int lb = v[1].size(), lc = v[2].size();
        for (int cntb = lb - 2; cntb <= lb; ++cntb) {
            if (cntb >= 0) {
                for (int cntc = lc - 2; cntc <= lc; ++cntc) {
                    if (cntc >= 0 && (cntb - cntc) % 3 == 0) {
                        ans = max(ans, accumulate(v[1].begin(),
                                                  v[1].begin() + cntb, 0) +
                                           accumulate(v[2].begin(),
                                                      v[2].begin() + cntc, 0));
                    }
                }
            }
        }
        return ans + accumulate(v[0].begin(), v[0].end(), 0);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxSumDivThree(int[] nums) {
        // Use v[0], v[1], v[2] to represent a, b, c respectively.
        IList<int>[] v = new IList<int>[3];
        for (int i = 0; i < 3; ++i) {
            v[i] = new List<int>();
        }
        foreach (int num in nums) {
            v[num % 3].Add(num);
        }
        ((List<int>)v[1]).Sort((a, b) => b - a);
        ((List<int>)v[2]).Sort((a, b) => b - a);

        int ans = 0;
        int lb = v[1].Count, lc = v[2].Count;
        for (int cntb = lb - 2; cntb <= lb; ++cntb) {
            if (cntb >= 0) {
                for (int cntc = lc - 2; cntc <= lc; ++cntc) {
                    if (cntc >= 0 && (cntb - cntc) % 3 == 0) {
                        ans = Math.Max(
                            ans, GetSum(v[1], 0, cntb) + GetSum(v[2], 0, cntc));
                    }
                }
            }
        }
        return ans + GetSum(v[0], 0, v[0].Count);
    }

    public int GetSum(IList<int> list, int start, int end) {
        int sum = 0;
        for (int i = start; i < end; ++i) {
            sum += list[i];
        }
        return sum;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func accumulate(v []int) int {
	ans := 0
	for _, x := range v {
		ans += x
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxSumDivThree(nums []int) int {
	// Use v[0], v[1], v[2] to represent a, b, c respectively.
	v := make([][]int, 3)
	for _, num := range nums {
		v[num%3] = append(v[num%3], num)
	}
	sort.Slice(v[1], func(i, j int) bool {
		return v[1][i] > v[1][j]
	})
	sort.Slice(v[2], func(i, j int) bool {
		return v[2][i] > v[2][j]
	})
	ans, lb, lc := 0, len(v[1]), len(v[2])
	for cntb := max(lb-2, 0); cntb <= lb; cntb++ {
		for cntc := max(lc-2, 0); cntc <= lc; cntc++ {
			if (cntb-cntc)%3 == 0 {
				ans = max(ans, accumulate(v[1][:cntb])+accumulate(v[2][:cntc]))
			}
		}
	}
	return ans + accumulate(v[0])
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxSumDivThree(int[] nums) {
        // Use v[0], v[1], v[2] to represent a, b, c respectively.
        List<Integer>[] v = new List[3];
        for (int i = 0; i < 3; ++i) {
            v[i] = new ArrayList<Integer>();
        }
        for (int num : nums) {
            v[num % 3].add(num);
        }
        Collections.sort(v[1], (a, b) -> b - a);
        Collections.sort(v[2], (a, b) -> b - a);

        int ans = 0;
        int lb = v[1].size();
        int lc = v[2].size();
        for (int cntb = lb - 2; cntb <= lb; ++cntb) {
            if (cntb >= 0) {
                for (int cntc = lc - 2; cntc <= lc; ++cntc) {
                    if (cntc >= 0 && (cntb - cntc) % 3 == 0) {
                        ans = Math.max(
                            ans,
                            getSum(v[1], 0, cntb) + getSum(v[2], 0, cntc)
                        );
                    }
                }
            }
        }
        return ans + getSum(v[0], 0, v[0].size());
    }

    public int getSum(List<Integer> list, int start, int end) {
        int sum = 0;
        for (int i = start; i < end; ++i) {
            sum += list.get(i);
        }
        return sum;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSumDivThree = function (nums) {
    const v = [[], [], []];
    for (const num of nums) {
        v[num % 3].push(num);
    }
    v[1].sort((a, b) => b - a);
    v[2].sort((a, b) => b - a);

    let ans = 0;
    const lb = v[1].length;
    const lc = v[2].length;
    for (let cntb = lb - 2; cntb <= lb; ++cntb) {
        if (cntb >= 0) {
            for (let cntc = lc - 2; cntc <= lc; ++cntc) {
                if (cntc >= 0 && (cntb - cntc) % 3 === 0) {
                    ans = Math.max(
                        ans,
                        getSum(v[1], 0, cntb) + getSum(v[2], 0, cntc),
                    );
                }
            }
        }
    }
    return ans + getSum(v[0], 0, v[0].length);
};

const getSum = (list, start, end) => {
    let sum = 0;
    for (let i = start; i < end; ++i) {
        sum += list[i];
    }
    return sum;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        a = [x for x in nums if x % 3 == 0]
        b = sorted([x for x in nums if x % 3 == 1], reverse=True)
        c = sorted([x for x in nums if x % 3 == 2], reverse=True)

        ans = 0
        lb, lc = len(b), len(c)
        for cntb in [lb - 2, lb - 1, lb]:
            if cntb >= 0:
                for cntc in [lc - 2, lc - 1, lc]:
                    if cntc >= 0 and (cntb - cntc) % 3 == 0:
                        ans = max(ans, sum(b[:cntb]) + sum(c[:cntc]))
        return ans + sum(a)
```

</details>

<br>

## Approach 2: Greedy + Backward Thinking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
static int cmp(const void* a, const void* b) { return *(int*)b - *(int*)a; }

int maxSumDivThree(int* nums, int numsSize) {
    // Use v[0], v[1], v[2] to represent a, b, c respectively.
    int n = numsSize;
    int v[3][n];
    int vColSize[3];
    memset(vColSize, 0, sizeof(vColSize));
    for (int i = 0; i < numsSize; i++) {
        v[nums[i] % 3][vColSize[nums[i] % 3]++] = nums[i];
    }
    qsort(v[1], vColSize[1], sizeof(int), cmp);
    qsort(v[2], vColSize[2], sizeof(int), cmp);
    int tot = 0, remove = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        tot += nums[i];
    }

    if (tot % 3 == 0) {
        remove = 0;
    } else if (tot % 3 == 1) {
        if (vColSize[1] >= 1) {
            remove = fmin(remove, v[1][vColSize[1] - 1]);
        }
        if (vColSize[2] >= 2) {
            remove =
                fmin(remove, v[2][vColSize[2] - 2] + v[2][vColSize[2] - 1]);
        }
    } else {
        if (vColSize[1] >= 2) {
            remove =
                fmin(remove, v[1][vColSize[1] - 2] + v[1][vColSize[1] - 1]);
        }
        if (vColSize[2] >= 1) {
            remove = fmin(remove, v[2][vColSize[2] - 1]);
        }
    }

    return tot - remove;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // Use v[0], v[1], v[2] to represent a, b, c respectively.
        vector<int> v[3];
        for (int num : nums) {
            v[num % 3].push_back(num);
        }
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int remove = INT_MAX;

        if (tot % 3 == 0) {
            remove = 0;
        } else if (tot % 3 == 1) {
            if (v[1].size() >= 1) {
                remove = min(remove, v[1].end()[-1]);
            }
            if (v[2].size() >= 2) {
                remove = min(remove, v[2].end()[-2] + v[2].end()[-1]);
            }
        } else {
            if (v[1].size() >= 2) {
                remove = min(remove, v[1].end()[-2] + v[1].end()[-1]);
            }
            if (v[2].size() >= 1) {
                remove = min(remove, v[2].end()[-1]);
            }
        }

        return tot - remove;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxSumDivThree(int[] nums) {
        // Use v[0], v[1], v[2] to represent a, b, c respectively.
        IList<int>[] v = new IList<int>[3];
        for (int i = 0; i < 3; ++i) {
            v[i] = new List<int>();
        }
        foreach (int num in nums) {
            v[num % 3].Add(num);
        }
        ((List<int>)v[1]).Sort((a, b) => b - a);
        ((List<int>)v[2]).Sort((a, b) => b - a);

        int tot = nums.Sum();
        int remove = int.MaxValue;

        if (tot % 3 == 0) {
            remove = 0;
        } else if (tot % 3 == 1) {
            if (v[1].Count >= 1) {
                remove = Math.Min(remove, v[1][v[1].Count - 1]);
            }
            if (v[2].Count >= 2) {
                remove = Math.Min(remove,
                                  v[2][v[2].Count - 2] + v[2][v[2].Count - 1]);
            }
        } else {
            if (v[1].Count >= 2) {
                remove = Math.Min(remove,
                                  v[1][v[1].Count - 2] + v[1][v[1].Count - 1]);
            }
            if (v[2].Count >= 1) {
                remove = Math.Min(remove, v[2][v[2].Count - 1]);
            }
        }

        return tot - remove;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func accumulate(v []int) int {
	ans := 0
	for _, x := range v {
		ans += x
	}
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxSumDivThree(nums []int) int {
	// Use v[0], v[1], v[2] to represent a, b, c respectively.
	v := make([][]int, 3)
	for _, num := range nums {
		v[num%3] = append(v[num%3], num)
	}
	sort.Slice(v[1], func(i, j int) bool {
		return v[1][i] > v[1][j]
	})
	sort.Slice(v[2], func(i, j int) bool {
		return v[2][i] > v[2][j]
	})
	tot, remove := accumulate(nums), 0x3f3f3f3f
	if tot%3 == 0 {
		remove = 0
	} else if tot%3 == 1 {
		if len(v[1]) >= 1 {
			remove = min(remove, v[1][len(v[1])-1])
		}
		if len(v[2]) >= 2 {
			remove = min(remove, v[2][len(v[2])-2]+v[2][len(v[2])-1])
		}
	} else {
		if len(v[1]) >= 2 {
			remove = min(remove, v[1][len(v[1])-2]+v[1][len(v[1])-1])
		}
		if len(v[2]) >= 1 {
			remove = min(remove, v[2][len(v[2])-1])
		}
	}
	return tot - remove
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxSumDivThree(int[] nums) {
        // Use v[0], v[1], v[2] to represent a, b, c respectively.
        List<Integer>[] v = new List[3];
        for (int i = 0; i < 3; ++i) {
            v[i] = new ArrayList<Integer>();
        }
        for (int num : nums) {
            v[num % 3].add(num);
        }
        Collections.sort(v[1], (a, b) -> b - a);
        Collections.sort(v[2], (a, b) -> b - a);

        int tot = Arrays.stream(nums).sum();
        int remove = Integer.MAX_VALUE;

        if (tot % 3 == 0) {
            remove = 0;
        } else if (tot % 3 == 1) {
            if (v[1].size() >= 1) {
                remove = Math.min(remove, v[1].get(v[1].size() - 1));
            }
            if (v[2].size() >= 2) {
                remove = Math.min(
                    remove,
                    v[2].get(v[2].size() - 2) + v[2].get(v[2].size() - 1)
                );
            }
        } else {
            if (v[1].size() >= 2) {
                remove = Math.min(
                    remove,
                    v[1].get(v[1].size() - 2) + v[1].get(v[1].size() - 1)
                );
            }
            if (v[2].size() >= 1) {
                remove = Math.min(remove, v[2].get(v[2].size() - 1));
            }
        }

        return tot - remove;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSumDivThree = function (nums) {
    const v = [[], [], []];
    for (const num of nums) {
        v[num % 3].push(num);
    }
    v[1].sort((a, b) => b - a);
    v[2].sort((a, b) => b - a);

    const tot = nums.reduce((sum, num) => sum + num, 0);
    let remove = Infinity;

    if (tot % 3 === 0) {
        remove = 0;
    } else if (tot % 3 === 1) {
        if (v[1].length >= 1) {
            remove = Math.min(remove, v[1][v[1].length - 1]);
        }
        if (v[2].length >= 2) {
            remove = Math.min(
                remove,
                v[2][v[2].length - 2] + v[2][v[2].length - 1],
            );
        }
    } else {
        if (v[1].length >= 2) {
            remove = Math.min(
                remove,
                v[1][v[1].length - 2] + v[1][v[1].length - 1],
            );
        }
        if (v[2].length >= 1) {
            remove = Math.min(remove, v[2][v[2].length - 1]);
        }
    }

    return tot - remove;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        a = [x for x in nums if x % 3 == 0]
        b = sorted([x for x in nums if x % 3 == 1], reverse=True)
        c = sorted([x for x in nums if x % 3 == 2], reverse=True)
        tot, remove = sum(nums), float("inf")

        if tot % 3 == 0:
            remove = 0
        elif tot % 3 == 1:
            if len(b) >= 1:
                remove = min(remove, b[-1])
            if len(c) >= 2:
                remove = min(remove, c[-2] + c[-1])
        else:
            if len(b) >= 2:
                remove = min(remove, b[-2] + b[-1])
            if len(c) >= 1:
                remove = min(remove, c[-1])

        return tot - remove
```

</details>

<br>

## Approach 3: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxSumDivThree(int* nums, int numsSize) {
    int f[3] = {0, INT_MIN, INT_MIN};
    int g[3] = {0};
    for (int j = 0; j < numsSize; j++) {
        memcpy(g, f, sizeof(f));
        for (int i = 0; i < 3; i++) {
            g[(i + nums[j] % 3) % 3] =
                fmax(g[(i + nums[j] % 3) % 3], f[i] + nums[j]);
        }
        memcpy(f, g, sizeof(f));
    }
    return f[0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> f = {0, INT_MIN, INT_MIN};
        for (int num : nums) {
            vector<int> g = f;
            for (int i = 0; i < 3; ++i) {
                g[(i + num % 3) % 3] = max(g[(i + num % 3) % 3], f[i] + num);
            }
            f = move(g);
        }
        return f[0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxSumDivThree(int[] nums) {
        int[] f = { 0, int.MinValue, int.MinValue };
        foreach (int num in nums) {
            int[] g = new int[3];
            Array.Copy(f, 0, g, 0, 3);
            for (int i = 0; i < 3; ++i) {
                g[(i + num % 3) % 3] =
                    Math.Max(g[(i + num % 3) % 3], f[i] + num);
            }
            f = g;
        }
        return f[0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxSumDivThree(nums []int) int {
	f := []int{0, -0x3f3f3f3f, -0x3f3f3f3f}
	for _, num := range nums {
		g := make([]int, 3)
		for i := 0; i < 3; i++ {
			g[(i+num)%3] = max(f[(i+num)%3], f[i]+num)
		}
		f = g
	}
	return f[0]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxSumDivThree(int[] nums) {
        int[] f = { 0, Integer.MIN_VALUE, Integer.MIN_VALUE };
        for (int num : nums) {
            int[] g = new int[3];
            System.arraycopy(f, 0, g, 0, 3);
            for (int i = 0; i < 3; ++i) {
                g[(i + (num % 3)) % 3] = Math.max(
                    g[(i + (num % 3)) % 3],
                    f[i] + num
                );
            }
            f = g;
        }
        return f[0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSumDivThree = function (nums) {
    let f = [0, Number.MIN_SAFE_INTEGER, Number.MIN_SAFE_INTEGER];
    for (const num of nums) {
        const g = [...f];
        for (let i = 0; i < 3; ++i) {
            g[(i + (num % 3)) % 3] = Math.max(
                g[(i + (num % 3)) % 3],
                f[i] + num,
            );
        }
        f = g;
    }
    return f[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        f = [0, -float("inf"), -float("inf")]
        for num in nums:
            g = f[:]
            for i in range(3):
                g[(i + num % 3) % 3] = max(g[(i + num % 3) % 3], f[i] + num)
            f = g
        return f[0]
```

</details>
