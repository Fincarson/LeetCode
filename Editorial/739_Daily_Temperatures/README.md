# 739. Daily Temperatures

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/daily-temperatures/)  
`Array` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 739 - Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)

## Problem

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

### Example 1

```text
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

### Example 2

```text
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
```

### Example 3

```text
Input: temperatures = [30,60,90]
Output: [1,1,0]
```

## Constraints

- 1 <= temperatures.length <= 105
- 30 <= temperatures[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Online Stock Span](https://leetcode.com/problems/online-stock-span/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 739. Daily Temperatures

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Monotonic Stack | Java, Python3 |
| Array, Optimized Space | Java, Python3 |

## Approach 1: Monotonic Stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] answer = new int[n];
        Deque<Integer> stack = new ArrayDeque<>();
        
        for (int currDay = 0; currDay < n; currDay++) {
            int currentTemp = temperatures[currDay];
            // Pop until the current day's temperature is not
            // warmer than the temperature at the top of the stack
            while (!stack.isEmpty() && temperatures[stack.peek()] < currentTemp) {
                int prevDay = stack.pop();
                answer[prevDay] = currDay - prevDay;
            }
            stack.push(currDay);
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        answer = [0] * n
        stack = []
        
        for curr_day, curr_temp in enumerate(temperatures):
            # Pop until the current day's temperature is not
            # warmer than the temperature at the top of the stack
            while stack and temperatures[stack[-1]] < curr_temp:
                prev_day = stack.pop()
                answer[prev_day] = curr_day - prev_day
            stack.append(curr_day)
        
        return answer
```

</details>

<br>

## Approach 2: Array, Optimized Space

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int hottest = 0;
        int answer[] = new int[n];
        
        for (int currDay = n - 1; currDay >= 0; currDay--) {
            int currentTemp = temperatures[currDay];
            if (currentTemp >= hottest) {
                hottest = currentTemp;
                continue;
            }
            
            int days = 1;
            while (temperatures[currDay + days] <= currentTemp) {
                // Use information from answer to search for the next warmer day
                days += answer[currDay + days];
            }
            answer[currDay] = days;
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        hottest = 0
        answer = [0] * n
        
        for curr_day in range(n - 1, -1, -1):
            current_temp = temperatures[curr_day]
            if current_temp >= hottest:
                hottest = current_temp
                continue
            
            days = 1
            while temperatures[curr_day + days] <= current_temp:
                # Use information from answer to search for the next warmer day
                days += answer[curr_day + days]
            answer[curr_day] = days

        return answer
```

</details>
