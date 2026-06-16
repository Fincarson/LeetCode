# 2110. Number of Smooth Descent Periods of a Stock

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/)  
`Array` `Math` `Two Pointers` `Dynamic Programming` `Sliding Window`

**Problem Link:** [LeetCode 2110 - Number of Smooth Descent Periods of a Stock](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/)

## Problem

You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.

### Example 1

```text
Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.
```

### Example 2

```text
Input: prices = [8,6,7,7]
Output: 4
Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.
```

### Example 3

```text
Input: prices = [1]
Output: 1
Explanation: There is 1 smooth descent period: [1]
```

## Constraints

- 1 <= prices.length <= 105
- 1 <= prices[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of Valid Subarrays](https://leetcode.com/problems/number-of-valid-subarrays/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Number of Zero-Filled Subarrays](https://leetcode.com/problems/number-of-zero-filled-subarrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2110. Number of Smooth Descent Periods of a Stock

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
long long getDescentPeriods(int* prices, int pricesSize) {
    int n = pricesSize;
    long long res =
        1;  // total number of smooth descending periods, initial value is dp[0]
    int prev = 1;  // total number of smooth descending periods ending with the
                   // previous element, initial value is dp[0]
    // traverse the array starting from 1, and update prev and the total res
    // according to the recurrence relation
    for (int i = 1; i < n; ++i) {
        if (prices[i] == prices[i - 1] - 1) {
            ++prev;
        } else {
            prev = 1;
        }
        res += prev;
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
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = 1;  // total number of smooth descending periods,
                            // initial value is dp[0]
        int prev = 1;  // total number of smooth descending periods ending with
                       // the previous element, initial value is dp[0]
        // traverse the array starting from 1, and update prev and the total res
        // according to the recurrence relation
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                ++prev;
            } else {
                prev = 1;
            }
            res += prev;
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
    public long GetDescentPeriods(int[] prices) {
        int n = prices.Length;
        long res = 1;  // total number of smooth descending periods, initial
                       // value is dp[0]
        int prev = 1;  // total number of smooth descending periods ending with
                       // the previous element, initial value is dp[0]
        // traverse the array starting from 1, and update prev and the total res
        // according to the recurrence relation
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                ++prev;
            } else {
                prev = 1;
            }
            res += prev;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getDescentPeriods(prices []int) int64 {
    n := len(prices)
    res := int64(1)   // total number of smooth descending periods, initial value is dp[0]
    prev := 1   // total number of smooth descending periods ending with the previous element, initial value is dp[0]
    // traverse the array starting from 1, and update prev and the total res according to the recurrence relation
    for i := 1; i < n; i++ {
        if prices[i] == prices[i - 1] - 1 {
            prev++    
        } else {
            prev = 1
        }
        res += int64(prev)
    }
    return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long getDescentPeriods(int[] prices) {
        int n = prices.length;
        long res = 1; // total number of smooth descending periods, initial value is dp[0]
        int prev = 1; // total number of smooth descending periods ending with the previous element, initial value is dp[0]
        // traverse the array starting from 1, and update prev and the total res according to the recurrence relation
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                ++prev;
            } else {
                prev = 1;
            }
            res += prev;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getDescentPeriods = function (prices) {
    const n = prices.length;
    let res = 1; // total number of smooth descending periods, initial value is dp[0]
    let prev = 1; // total number of smooth descending periods ending with the previous element, initial value is dp[0]
    // traverse the array starting from 1, and update prev and the total res according to the recurrence relation
    for (let i = 1; i < n; ++i) {
        if (prices[i] === prices[i - 1] - 1) {
            ++prev;
        } else {
            prev = 1;
        }
        res += prev;
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        n = len(prices)
        res = 1  # total number of smooth descending periods, initial value is dp[0]
        prev = 1  # total number of smooth descending periods ending with the previous element, initial value is dp[0]
        # traverse the array starting from 1, and update prev and the total res according to the recurrence relation
        for i in range(1, n):
            if prices[i] == prices[i - 1] - 1:
                prev += 1
            else:
                prev = 1
            res += prev
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getDescentPeriods(prices: number[]): number {
    const n = prices.length;
    let res: number = 1; // total number of smooth descending periods, initial value is dp[0]
    let prev: number = 1; // total number of smooth descending periods ending with the previous element, initial value is dp[0]
    // traverse the array starting from 1, and update prev and the total res according to the recurrence relation
    for (let i = 1; i < n; ++i) {
        if (prices[i] === prices[i - 1] - 1) {
            ++prev;
        } else {
            prev = 1;
        }
        res += prev;
    }
    return res;
}
```

</details>
