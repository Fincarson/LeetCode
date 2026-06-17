# 3477. Fruits Into Baskets II

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/fruits-into-baskets-ii/)  
`Array` `Binary Search` `Segment Tree` `Simulation` `Ordered Set`

**Problem Link:** [LeetCode 3477 - Fruits Into Baskets II](https://leetcode.com/problems/fruits-into-baskets-ii/)

## Problem

You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.

From left to right, place the fruits according to these rules:

- Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
- Each basket can hold only one type of fruit.
- If a fruit type cannot be placed in any basket, it remains unplaced.

Return the number of fruit types that remain unplaced after all possible allocations are made.

### Example 1

### Example 2

## Constraints

- n == fruits.length == baskets.length
- 1 <= n <= 100
- 1 <= fruits[i], baskets[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3477. Fruits Into Baskets II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets,
                        int basketsSize) {
    int count = 0;
    for (int j = 0; j < fruitsSize; j++) {
        int unset = 1;
        for (int i = 0; i < basketsSize; i++) {
            if (fruits[j] <= baskets[i]) {
                baskets[i] = 0;
                unset = 0;
                break;
            }
        }
        count += unset;
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
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = baskets.size();
        for (auto fruit : fruits) {
            int unset = 1;
            for (int i = 0; i < n; i++) {
                if (fruit <= baskets[i]) {
                    baskets[i] = 0;
                    unset = 0;
                    break;
                }
            }
            count += unset;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumOfUnplacedFruits(int[] fruits, int[] baskets) {
        int count = 0;
        int n = baskets.Length;
        foreach (int fruit in fruits) {
            int unset = 1;
            for (int i = 0; i < n; i++) {
                if (fruit <= baskets[i]) {
                    baskets[i] = 0;
                    unset = 0;
                    break;
                }
            }
            count += unset;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numOfUnplacedFruits(fruits []int, baskets []int) int {
	count := 0
	n := len(baskets)
	for _, fruit := range fruits {
		unset := 1
		for i := 0; i < n; i++ {
			if fruit <= baskets[i] {
				baskets[i] = 0
				unset = 0
				break
			}
		}
		count += unset
	}
	return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int count = 0;
        int n = baskets.length;
        for (int fruit : fruits) {
            int unset = 1;
            for (int i = 0; i < n; i++) {
                if (fruit <= baskets[i]) {
                    baskets[i] = 0;
                    unset = 0;
                    break;
                }
            }
            count += unset;
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numOfUnplacedFruits = function (fruits, baskets) {
    let count = 0;
    const n = baskets.length;
    for (const fruit of fruits) {
        let unset = 1;
        for (let i = 0; i < n; i++) {
            if (fruit <= baskets[i]) {
                baskets[i] = 0;
                unset = 0;
                break;
            }
        }
        count += unset;
    }
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        count = 0
        n = len(baskets)
        for fruit in fruits:
            unset = 1
            for i in range(n):
                if fruit <= baskets[i]:
                    baskets[i] = 0
                    unset = 0
                    break
            count += unset
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numOfUnplacedFruits(fruits: number[], baskets: number[]): number {
    let count = 0;
    const n = baskets.length;
    for (const fruit of fruits) {
        let unset = 1;
        for (let i = 0; i < n; i++) {
            if (fruit <= baskets[i]) {
                baskets[i] = 0;
                unset = 0;
                break;
            }
        }
        count += unset;
    }
    return count;
}
```

</details>
