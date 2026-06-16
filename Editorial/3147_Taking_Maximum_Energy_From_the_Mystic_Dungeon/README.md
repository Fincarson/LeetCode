# 3147. Taking Maximum Energy From the Mystic Dungeon

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/)  
`Array` `Dynamic Programming` `Prefix Sum`

**Problem Link:** [LeetCode 3147 - Taking Maximum Energy From the Mystic Dungeon](https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/)

## Problem

In a mystic dungeon, n magicians are standing in a line. Each magician has an attribute that gives you energy. Some magicians can give you negative energy, which means taking energy from you.

You have been cursed in such a way that after absorbing energy from magician i, you will be instantly transported to magician (i + k). This process will be repeated until you reach the magician where (i + k) does not exist.

In other words, you will choose a starting point and then teleport with k jumps until you reach the end of the magicians' sequence, absorbing all the energy during the journey.

You are given an array energy and an integer k. Return the maximum possible energy you can gain.

Note that when you reach a magician, you must take energy from them, whether it is negative or positive energy.

### Example 1

### Example 2

## Constraints

- 1 <= energy.length <= 105
- -1000 <= energy[i] <= 1000
- 1 <= k <= energy.length - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3147. Taking Maximum Energy From the Mystic Dungeon

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Reverse Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Reverse Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maximumEnergy(int* energy, int energySize, int k) {
    int n = energySize;
    int ans = INT_MIN;

    for (int i = n - k; i < n; i++) {
        int sum = 0;
        for (int j = i; j >= 0; j -= k) {
            sum += energy[j];
            if (sum > ans) {
                ans = sum;
            }
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
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(), ans = INT_MIN;
        for (int i = n - k; i < n; i++) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                ans = max(ans, sum);
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
    public int MaximumEnergy(int[] energy, int k) {
        int n = energy.Length;
        int ans = int.MinValue;
        for (int i = n - k; i < n; i++) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                if (sum > ans)
                    ans = sum;
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
func maximumEnergy(energy []int, k int) int {
	n := len(energy)
	ans := -1 << 31

	for i := n - k; i < n; i++ {
		sum := 0
		for j := i; j >= 0; j -= k {
			sum += energy[j]
			ans = max(ans, sum)
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

    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length;
        int ans = Integer.MIN_VALUE;
        for (int i = n - k; i < n; i++) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                ans = Math.max(ans, sum);
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
var maximumEnergy = function (energy, k) {
    const n = energy.length;
    let ans = -Number.MAX_SAFE_INTEGER;

    for (let i = n - k; i < n; i++) {
        let sum = 0;
        for (let j = i; j >= 0; j -= k) {
            sum += energy[j];
            ans = Math.max(ans, sum);
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
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        n = len(energy)
        ans = -inf

        for i in range(n - k, n):
            total = 0
            j = i
            while j >= 0:
                total += energy[j]
                ans = max(ans, total)
                j -= k

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumEnergy(energy: number[], k: number): number {
    const n = energy.length;
    let ans = -Number.MAX_SAFE_INTEGER;

    for (let i = n - k; i < n; i++) {
        let sum = 0;
        for (let j = i; j >= 0; j -= k) {
            sum += energy[j];
            ans = Math.max(ans, sum);
        }
    }
    return ans;
}
```

</details>
