# 1526. Minimum Number of Increments on Subarrays to Form a Target Array

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/)  
`Array` `Dynamic Programming` `Stack` `Greedy` `Monotonic Stack`

**Problem Link:** [LeetCode 1526 - Minimum Number of Increments on Subarrays to Form a Target Array](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/)

## Problem

You are given an integer array target. You have an integer array initial of the same size as target with all elements initially zeros.

In one operation you can choose any subarray from initial and increment each value by one.

Return the minimum number of operations to form a target array from initial.

The test cases are generated so that the answer fits in a 32-bit integer.

### Example 1

```text
Input: target = [1,2,3,2,1]
Output: 3
Explanation: We need at least 3 operations to form the target array from the initial array.
[0,0,0,0,0] increment 1 from index 0 to 4 (inclusive).
[1,1,1,1,1] increment 1 from index 1 to 3 (inclusive).
[1,2,2,2,1] increment 1 at index 2.
[1,2,3,2,1] target array is formed.
```

### Example 2

```text
Input: target = [3,1,1,2]
Output: 4
Explanation: [0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> [2,1,1,2] -> [3,1,1,2]
```

### Example 3

```text
Input: target = [3,1,5,4,2]
Output: 7
Explanation: [0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] -> [3,1,1,1,1] -> [3,1,2,2,2] -> [3,1,3,3,2] -> [3,1,4,4,2] -> [3,1,5,4,2].
```

## Constraints

- 1 <= target.length <= 105
- 1 <= target[i] <= 105
- Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹The input is generated such that the answer fits inside a 32 bit integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1526. Minimum Number of Increments on Subarrays to Form a Target Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Difference Array | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Difference Array

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minNumberOperations(int* target, int targetSize) {
    int ans = target[0];
    for (int i = 1; i < targetSize; ++i) {
        ans += fmax(target[i] - target[i - 1], 0);
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
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];
        for (int i = 1; i < n; ++i) {
            ans += max(target[i] - target[i - 1], 0);
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
    public int MinNumberOperations(int[] target) {
        int n = target.Length;
        int ans = target[0];
        for (int i = 1; i < n; ++i) {
            ans += Math.Max(target[i] - target[i - 1], 0);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minNumberOperations(target []int) int {
	n := len(target)
	ans := target[0]
	for i := 1; i < n; i++ {
		ans += max(target[i]-target[i-1], 0)
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minNumberOperations(int[] target) {
        int n = target.length;
        int ans = target[0];
        for (int i = 1; i < n; ++i) {
            ans += Math.max(target[i] - target[i - 1], 0);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minNumberOperations = function (target) {
    const n = target.length;
    let ans = target[0];
    for (let i = 1; i < n; ++i) {
        ans += Math.max(target[i] - target[i - 1], 0);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        n = len(target)
        ans = target[0]
        for i in range(1, n):
            ans += max(target[i] - target[i - 1], 0)
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minNumberOperations(target: number[]): number {
    const n = target.length;
    let ans = target[0];
    for (let i = 1; i < n; ++i) {
        ans += Math.max(target[i] - target[i - 1], 0);
    }
    return ans;
}
```

</details>
