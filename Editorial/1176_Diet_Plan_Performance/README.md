# 1176. Diet Plan Performance

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/diet-plan-performance/)  
`Array` `Sliding Window`

**Problem Link:** [LeetCode 1176 - Diet Plan Performance](https://leetcode.com/problems/diet-plan-performance/)

## Problem

A dieter consumes calories[i] calories on the i-th day.

Given an integer k, for every consecutive sequence of k days (calories[i], calories[i+1], ..., calories[i+k-1] for all 0 <= i <= n-k), they look at T, the total calories consumed during that sequence of k days (calories[i] + calories[i+1] + ... + calories[i+k-1]):

- If T < lower, they performed poorly on their diet and lose 1 point;
- If T > upper, they performed well on their diet and gain 1 point;
- Otherwise, they performed normally and there is no change in points.

Initially, the dieter has zero points. Return the total number of points the dieter has after dieting for calories.length days.

Note that the total points can be negative.

### Example 1

```text
Input: calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
Output: 0
Explanation: Since k = 1, we consider each element of the array separately and compare it to lower and upper.
calories[0] and calories[1] are less than lower so 2 points are lost.
calories[3] and calories[4] are greater than upper so 2 points are gained.
```

### Example 2

```text
Input: calories = [3,2], k = 2, lower = 0, upper = 1
Output: 1
Explanation: Since k = 2, we consider subarrays of length 2.
calories[0] + calories[1] > upper so 1 point is gained.
```

### Example 3

```text
Input: calories = [6,5,0,0], k = 2, lower = 1, upper = 5
Output: 0
Explanation:
calories[0] + calories[1] > upper so 1 point is gained.
lower <= calories[1] + calories[2] <= upper so no change in points.
calories[2] + calories[3] < lower so 1 point is lost.
```

## Constraints

- 1 <= k <= calories.length <= 10^5
- 0 <= calories[i] <= 20000
- 0 <= lower <= upper

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1176. Diet Plan Performance

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C, C++, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Sliding Window

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int dietPlanPerformance(int* calories, int caloriesSize, int k, int lower,
                        int upper) {
    int index = 0;
    int score = 0;
    int sum = 0;
    for (index; index < k; index++) {
        sum += calories[index];
    }
    for (index;; index++) {
        if (sum < lower) {
            score--;
        } else if (sum > upper) {
            score++;
        }
        if (index == caloriesSize) {
            break;
        }
        sum += calories[index] - calories[index - k];
    }
    return score;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower,
                            int upper) {
        int sum = 0, score = 0;
        for (int i = 0; i < k; i++) {
            sum += calories[i];
        }
        for (int i = k; i < calories.size(); i++) {
            if (sum < lower) {
                score--;
            } else if (sum > upper) {
                score++;
            }
            sum += calories[i] - calories[i - k];
        }
        if (sum < lower) {
            score--;
        } else if (sum > upper) {
            score++;
        }
        return score;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func dietPlanPerformance(calories []int, k int, lower int, upper int) int {
	sum, score := 0, 0
	for i := 0; i < k; i++ {
		sum += calories[i]
	}
	for i := k; ; i++ {
		if sum < lower {
			score--
		} else if sum > upper {
			score++
		}
		if i == len(calories) {
			break
		}
		sum += calories[i] - calories[i-k]
	}
	return score
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int dietPlanPerformance(
        int[] calories,
        int k,
        int lower,
        int upper
    ) {
        int sum = 0;
        int score = 0;
        for (int i = 0; i < k; i++) {
            sum += calories[i];
        }
        for (int i = k; i < calories.length; i++) {
            if (sum < lower) {
                score--;
            } else if (sum > upper) {
                score++;
            }
            sum += calories[i] - calories[i - k];
        }
        if (sum < lower) {
            score--;
        } else if (sum > upper) {
            score++;
        }
        return score;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var dietPlanPerformance = function (calories, k, lower, upper) {
    let score = 0;
    let sum = 0;
    for (let i = 0; i < k; i++) {
        sum += calories[i];
    }
    for (let i = k; i < calories.length; i++) {
        if (sum < lower) {
            score--;
        } else if (sum > upper) {
            score++;
        }
        sum += calories[i] - calories[i - k];
    }
    if (sum < lower) {
        score--;
    } else if (sum > upper) {
        score++;
    }
    return score;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dietPlanPerformance(
        self, calories: List[int], k: int, lower: int, upper: int
    ) -> int:
        score = 0
        sum_calories = sum(calories[:k])
        for i in range(k, len(calories)):
            if sum_calories < lower:
                score -= 1
            elif sum_calories > upper:
                score += 1
            sum_calories += calories[i] - calories[i - k]
        if sum_calories < lower:
            score -= 1
        elif sum_calories > upper:
            score += 1
        return score
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function dietPlanPerformance(
    calories: number[],
    k: number,
    lower: number,
    upper: number,
): number {
    let score = 0;
    let sum = 0;
    for (let i = 0; i < k; i++) {
        sum += calories[i];
    }
    for (let i = k; i < calories.length; i++) {
        if (sum < lower) {
            score--;
        } else if (sum > upper) {
            score++;
        }
        sum += calories[i] - calories[i - k];
    }
    if (sum < lower) {
        score--;
    } else if (sum > upper) {
        score++;
    }
    return score;
}
```

</details>
