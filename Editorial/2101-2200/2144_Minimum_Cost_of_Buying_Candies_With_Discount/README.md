# 2144. Minimum Cost of Buying Candies With Discount

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 2144 - Minimum Cost of Buying Candies With Discount](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/)

## Problem

A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

- For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.

Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.

### Example 1

```text
Input: cost = [1,2,3]
Output: 5
Explanation: We buy the candies with costs 2 and 3, and take the candy with cost 1 for free.
The total cost of buying all candies is 2 + 3 = 5. This is the only way we can buy the candies.
Note that we cannot buy candies with costs 1 and 3, and then take the candy with cost 2 for free.
The cost of the free candy has to be less than or equal to the minimum cost of the purchased candies.
```

### Example 2

```text
Input: cost = [6,5,7,9,2,2]
Output: 23
Explanation: The way in which we can get the minimum cost is described below:
- Buy candies with costs 9 and 7
- Take the candy with cost 6 for free
- We buy candies with costs 5 and 2
- Take the last remaining candy with cost 2 for free
Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.
```

### Example 3

```text
Input: cost = [5,5]
Output: 10
Explanation: Since there are only 2 candies, we buy both of them. There is not a third candy we can take for free.
Hence, the minimum cost to buy all candies is 5 + 5 = 10.
```

## Constraints

- 1 <= cost.length <= 100
- 1 <= cost[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Array Partition](https://leetcode.com/problems/array-partition/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Number of Operations to Satisfy Conditions](https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Check if Grid Satisfies Conditions](https://leetcode.com/problems/check-if-grid-satisfies-conditions/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2144. Minimum Cost of Buying Candies With Discount

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compareDesc(const void* a, const void* b) { return *(int*)b - *(int*)a; }

int minimumCost(int* cost, int costSize) {
    qsort(cost, costSize, sizeof(int), compareDesc);
    int res = 0;
    for (int i = 0; i < costSize; ++i) {
        if (i % 3 != 2) {
            res += cost[i];
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
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int res = 0;
        int n = cost.size();
        for (int i = 0; i < n; ++i) {
            if (i % 3 != 2) {
                res += cost[i];
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
    public int MinimumCost(int[] cost) {
        Array.Sort(cost);
        Array.Reverse(cost);

        int res = 0;
        int n = cost.Length;
        for (int i = 0; i < n; ++i) {
            if (i % 3 != 2) {
                res += cost[i];
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
func minimumCost(cost []int) int {
	sort.Sort(sort.Reverse(sort.IntSlice(cost)))
	res := 0
	n := len(cost)
	for i := 0; i < n; i++ {
		if i%3 != 2 {
			res += cost[i]
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

    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int res = 0;
        int n = cost.length;
        for (int i = n - 1; i >= 0; --i) {
            if ((n - 1 - i) % 3 != 2) {
                res += cost[i];
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
var minimumCost = function (cost) {
    cost.sort((a, b) => b - a);
    let res = 0;
    const n = cost.length;
    for (let i = 0; i < n; ++i) {
        if (i % 3 !== 2) {
            res += cost[i];
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
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(key=lambda x: -x)
        res = 0
        n = len(cost)
        for i in range(n):
            if i % 3 != 2:
                res += cost[i]
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumCost(cost: number[]): number {
    cost.sort((a, b) => b - a);
    let res = 0;
    const n = cost.length;
    for (let i = 0; i < n; ++i) {
        if (i % 3 !== 2) {
            res += cost[i];
        }
    }
    return res;
}
```

</details>
