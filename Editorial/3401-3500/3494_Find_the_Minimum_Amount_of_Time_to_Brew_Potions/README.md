# 3494. Find the Minimum Amount of Time to Brew Potions

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/)  
`Array` `Simulation` `Prefix Sum`

**Problem Link:** [LeetCode 3494 - Find the Minimum Amount of Time to Brew Potions](https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/)

## Problem

You are given two integer arrays, skill and mana, of length n and m, respectively.

In a laboratory, n wizards must brew m potions in order. Each potion has a mana capacity mana[j] and must pass through all the wizards sequentially to be brewed properly. The time taken by the ith wizard on the jth potion is timeij = skill[i] * mana[j].

Since the brewing process is delicate, a potion must be passed to the next wizard immediately after the current wizard completes their work. This means the timing must be synchronized so that each wizard begins working on a potion exactly when it arrives. Ã¢â‚¬â€¹

Return the minimum amount of time required for the potions to be brewed properly.

### Example 1

### Example 2

### Example 3

## Constraints

- n == skill.length
- m == mana.length
- 1 <= n, m <= 5000
- 1 <= mana[i], skill[i] <= 5000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3494. Find the Minimum Amount of Time to Brew Potions

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long minTime(int* skill, int skillSize, int* mana, int manaSize) {
    long long* times = (long long*)malloc(skillSize * sizeof(long long));
    for (int i = 0; i < skillSize; i++) {
        times[i] = 0;
    }

    for (int j = 0; j < manaSize; j++) {
        long long cur_time = 0;
        for (int i = 0; i < skillSize; i++) {
            cur_time = (cur_time > times[i] ? cur_time : times[i]) +
                       (long long)skill[i] * mana[j];
        }
        times[skillSize - 1] = cur_time;
        for (int i = skillSize - 2; i >= 0; i--) {
            times[i] = times[i + 1] - (long long)skill[i + 1] * mana[j];
        }
    }

    long long result = times[skillSize - 1];
    free(times);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<ll> times(n);
        for (int j = 0; j < m; j++) {
            ll cur_time = 0;
            for (int i = 0; i < n; i++) {
                cur_time = max(cur_time, times[i]) + skill[i] * mana[j];
            }
            times[n - 1] = cur_time;
            for (int i = n - 2; i >= 0; i--) {
                times[i] = times[i + 1] - skill[i + 1] * mana[j];
            }
        }
        return times[n - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MinTime(int[] skill, int[] mana) {
        int n = skill.Length, m = mana.Length;
        long[] times = new long[n];

        for (int j = 0; j < m; j++) {
            long curTime = 0;
            for (int i = 0; i < n; i++) {
                curTime =
                    Math.Max(curTime, times[i]) + (long)skill[i] * mana[j];
            }
            times[n - 1] = curTime;
            for (int i = n - 2; i >= 0; i--) {
                times[i] = times[i + 1] - (long)skill[i + 1] * mana[j];
            }
        }
        return times[n - 1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minTime(skill []int, mana []int) int64 {
	n, m := len(skill), len(mana)
	times := make([]int64, n)

	for j := 0; j < m; j++ {
		var curTime int64 = 0
		for i := 0; i < n; i++ {
			if curTime < times[i] {
				curTime = times[i]
			}
			curTime += int64(skill[i]) * int64(mana[j])
		}
		times[n-1] = curTime
		for i := n - 2; i >= 0; i-- {
			times[i] = times[i+1] - int64(skill[i+1])*int64(mana[j])
		}
	}
	return times[n-1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minTime(int[] skill, int[] mana) {
        int n = skill.length;
        int m = mana.length;
        long[] times = new long[n];

        for (int j = 0; j < m; j++) {
            long curTime = 0;
            for (int i = 0; i < n; i++) {
                curTime =
                    Math.max(curTime, times[i]) + (long) skill[i] * mana[j];
            }
            times[n - 1] = curTime;
            for (int i = n - 2; i >= 0; i--) {
                times[i] = times[i + 1] - (long) skill[i + 1] * mana[j];
            }
        }
        return times[n - 1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minTime = function (skill, mana) {
    const n = skill.length,
        m = mana.length;
    const times = new Array(n).fill(0);

    for (let j = 0; j < m; j++) {
        let curTime = 0;
        for (let i = 0; i < n; i++) {
            curTime = Math.max(curTime, times[i]) + skill[i] * mana[j];
        }
        times[n - 1] = curTime;
        for (let i = n - 2; i >= 0; i--) {
            times[i] = times[i + 1] - skill[i + 1] * mana[j];
        }
    }
    return times[n - 1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n, m = len(skill), len(mana)
        times = [0] * n
        for j in range(m):
            cur_time = 0
            for i in range(n):
                cur_time = max(cur_time, times[i]) + skill[i] * mana[j]
            times[n - 1] = cur_time
            for i in range(n - 2, -1, -1):
                times[i] = times[i + 1] - skill[i + 1] * mana[j]
        return times[n - 1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minTime(skill: number[], mana: number[]): number {
    const n = skill.length,
        m = mana.length;
    const times: number[] = new Array(n).fill(0);

    for (let j = 0; j < m; j++) {
        let curTime = 0;
        for (let i = 0; i < n; i++) {
            curTime = Math.max(curTime, times[i]) + skill[i] * mana[j];
        }
        times[n - 1] = curTime;
        for (let i = n - 2; i >= 0; i--) {
            times[i] = times[i + 1] - skill[i + 1] * mana[j];
        }
    }
    return times[n - 1];
}
```

</details>
