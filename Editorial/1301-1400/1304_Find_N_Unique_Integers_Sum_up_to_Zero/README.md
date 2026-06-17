# 1304. Find N Unique Integers Sum up to Zero

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/)  
`Array` `Math`

**Problem Link:** [LeetCode 1304 - Find N Unique Integers Sum up to Zero](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/)

## Problem

Given an integer n, return any array containing n unique integers such that they add up to 0.

### Example 1

```text
Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
```

### Example 2

```text
Input: n = 3
Output: [-1,0,1]
```

### Example 3

```text
Input: n = 1
Output: [0]
```

## Constraints

- 1 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1304. Find N Unique Integers Sum up to Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Construction | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Construction

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* sumZero(int n, int* returnSize) {
    *returnSize = n;
    int* ans = malloc(n * sizeof(int));
    int index = 0;
    for (int i = 1; i <= n / 2; ++i) {
        ans[index++] = i;
        ans[index++] = -i;
    }
    if (n % 2 == 1) {
        ans[index] = 0;
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
    vector<int> sumZero(int n) {
        vector<int> ans;
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 == 1) {
            ans.push_back(0);
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
    public int[] SumZero(int n) {
        int[] ans = new int[n];
        int index = 0;
        for (int i = 1; i <= n / 2; ++i) {
            ans[index++] = i;
            ans[index++] = -i;
        }
        if (n % 2 == 1) {
            ans[index] = 0;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sumZero(n int) []int {
	ans := make([]int, 0, n)
	for i := 1; i <= n/2; i++ {
		ans = append(ans, i, -i)
	}
	if n%2 == 1 {
		ans = append(ans, 0)
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] sumZero(int n) {
        int[] ans = new int[n];
        int index = 0;
        for (int i = 1; i <= n / 2; ++i) {
            ans[index++] = i;
            ans[index++] = -i;
        }
        if (n % 2 == 1) {
            ans[index] = 0;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sumZero = function (n) {
    let ans = [];
    for (let i = 1; i <= Math.floor(n / 2); i++) {
        ans.push(i, -i);
    }
    if (n % 2 === 1) {
        ans.push(0);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = []
        for i in range(1, n // 2 + 1):
            ans.append(i)
            ans.append(-i)
        if n % 2 == 1:
            ans.append(0)
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sumZero(n: number): number[] {
    let ans: number[] = [];
    for (let i = 1; i <= Math.floor(n / 2); i++) {
        ans.push(i, -i);
    }
    if (n % 2 === 1) {
        ans.push(0);
    }
    return ans;
}
```

</details>
