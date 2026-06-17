# 1340. Jump Game V

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/jump-game-v/)  
`Array` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 1340 - Jump Game V](https://leetcode.com/problems/jump-game-v/)

## Problem

Given an array of integers arr and an integer d. In one step you can jump from index i to index:

- i + x where: i + x < arr.length and  0 < x <= d.
- i - x where: i - x >= 0 and  0 < x <= d.

In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.

### Example 1

```text
Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.
```

### Example 2

```text
Input: arr = [3,3,3,3,3], d = 3
Output: 1
Explanation: You can start at any index. You always cannot jump to any index.
```

### Example 3

```text
Input: arr = [7,6,5,4,3,2,1], d = 1
Output: 7
Explanation: Start at index 0. You can visit all the indicies.
```

## Constraints

- 1 <= arr.length <= 1000
- 1 <= arr[i] <= 105
- 1 <= d <= arr.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Jump Game VII](https://leetcode.com/problems/jump-game-vii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Jump Game VIII](https://leetcode.com/problems/jump-game-viii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1340. Jump Game V

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Memoization Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Memoization Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void dfs(int* arr, int id, int d, int n, int* f) {
    if (f[id] != -1) {
        return;
    }
    f[id] = 1;
    for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
        dfs(arr, i, d, n, f);
        if (f[i] + 1 > f[id]) {
            f[id] = f[i] + 1;
        }
    }
    for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
        dfs(arr, i, d, n, f);
        if (f[i] + 1 > f[id]) {
            f[id] = f[i] + 1;
        }
    }
}

int maxJumps(int* arr, int arrSize, int d) {
    int n = arrSize;
    int* f = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        f[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        dfs(arr, i, d, n, f);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (f[i] > ans) {
            ans = f[i];
        }
    }

    free(f);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    vector<int> f;

public:
    void dfs(vector<int>& arr, int id, int d, int n) {
        if (f[id] != -1) {
            return;
        }
        f[id] = 1;
        for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
            dfs(arr, i, d, n);
            f[id] = max(f[id], f[i] + 1);
        }
        for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
            dfs(arr, i, d, n);
            f[id] = max(f[id], f[i] + 1);
        }
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        f.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            dfs(arr, i, d, n);
        }
        return *max_element(f.begin(), f.end());
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int[] f;

    private void Dfs(int[] arr, int id, int d, int n) {
        if (f[id] != -1) {
            return;
        }
        f[id] = 1;
        for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
            Dfs(arr, i, d, n);
            f[id] = Math.Max(f[id], f[i] + 1);
        }
        for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
            Dfs(arr, i, d, n);
            f[id] = Math.Max(f[id], f[i] + 1);
        }
    }

    public int MaxJumps(int[] arr, int d) {
        int n = arr.Length;
        f = new int[n];
        Array.Fill(f, -1);
        for (int i = 0; i < n; ++i) {
            Dfs(arr, i, d, n);
        }
        return f.Max();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxJumps(arr []int, d int) int {
	n := len(arr)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}

	var dfs func(int)
	dfs = func(id int) {
		if f[id] != -1 {
			return
		}
		f[id] = 1
		for i := id - 1; i >= 0 && id-i <= d && arr[id] > arr[i]; i-- {
			dfs(i)
			if f[i]+1 > f[id] {
				f[id] = f[i] + 1
			}
		}
		for i := id + 1; i < n && i-id <= d && arr[id] > arr[i]; i++ {
			dfs(i)
			if f[i]+1 > f[id] {
				f[id] = f[i] + 1
			}
		}
	}

	for i := 0; i < n; i++ {
		dfs(i)
	}

	ans := 0
	for _, val := range f {
		if val > ans {
			ans = val
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

    private int[] f;

    private void dfs(int[] arr, int id, int d, int n) {
        if (f[id] != -1) {
            return;
        }
        f[id] = 1;
        for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
            dfs(arr, i, d, n);
            f[id] = Math.max(f[id], f[i] + 1);
        }
        for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
            dfs(arr, i, d, n);
            f[id] = Math.max(f[id], f[i] + 1);
        }
    }

    public int maxJumps(int[] arr, int d) {
        int n = arr.length;
        f = new int[n];
        Arrays.fill(f, -1);
        for (int i = 0; i < n; ++i) {
            dfs(arr, i, d, n);
        }
        int ans = 0;
        for (int val : f) {
            ans = Math.max(ans, val);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxJumps = function (arr, d) {
    const n = arr.length;
    const f = new Array(n).fill(-1);

    const dfs = (id) => {
        if (f[id] !== -1) {
            return;
        }
        f[id] = 1;
        for (let i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
            dfs(i);
            f[id] = Math.max(f[id], f[i] + 1);
        }
        for (let i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
            dfs(i);
            f[id] = Math.max(f[id], f[i] + 1);
        }
    };

    for (let i = 0; i < n; ++i) {
        dfs(i);
    }

    return Math.max(...f);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        seen = dict()

        def dfs(pos):
            if pos in seen:
                return
            seen[pos] = 1

            i = pos - 1
            while i >= 0 and pos - i <= d and arr[pos] > arr[i]:
                dfs(i)
                seen[pos] = max(seen[pos], seen[i] + 1)
                i -= 1
            i = pos + 1
            while i < len(arr) and i - pos <= d and arr[pos] > arr[i]:
                dfs(i)
                seen[pos] = max(seen[pos], seen[i] + 1)
                i += 1

        for i in range(len(arr)):
            dfs(i)

        return max(seen.values())
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxJumps(arr: number[], d: number): number {
    const n = arr.length;
    const f: number[] = new Array(n).fill(-1);

    const dfs = (id: number): void => {
        if (f[id] !== -1) {
            return;
        }
        f[id] = 1;
        for (let i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
            dfs(i);
            f[id] = Math.max(f[id], f[i] + 1);
        }
        for (let i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
            dfs(i);
            f[id] = Math.max(f[id], f[i] + 1);
        }
    };

    for (let i = 0; i < n; ++i) {
        dfs(i);
    }

    return Math.max(...f);
}
```

</details>
