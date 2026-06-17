# 1344. Angle Between Hands of a Clock

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/angle-between-hands-of-a-clock/)  
`Math`

**Problem Link:** [LeetCode 1344 - Angle Between Hands of a Clock](https://leetcode.com/problems/angle-between-hands-of-a-clock/)

## Problem

Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.

### Example 1

```text
Input: hour = 12, minutes = 30
Output: 165
```

### Example 2

```text
Input: hour = 3, minutes = 30
Output: 75
```

### Example 3

```text
Input: hour = 3, minutes = 15
Output: 7.5
```

## Constraints

- 1 <= hour <= 12
- 0 <= minutes <= 59

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1344. Angle Between Hands of a Clock

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Math | C++, Go, Java, Python, Python3 |

## Approach 1: Math

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  double angleClock(int hour, int minutes) {
    int oneMinAngle = 6;
    int oneHourAngle = 30;

    double minutesAngle = oneMinAngle * minutes;
    double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;

    double diff = abs(hourAngle - minutesAngle);
    return min(diff, 360 - diff);
  }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func angleClock(hour int, minutes int) float64 {
    var oneMinAngle, oneHourAngle, minutesAngle, hourAngle, diff float64;
    oneMinAngle = 6;
    oneHourAngle = 30;

    minutesAngle = oneMinAngle * float64(minutes);
    hourAngle = (float64(hour % 12) + float64(minutes) / 60.0) * oneHourAngle;

    diff = math.Abs(hourAngle - minutesAngle);
    return math.Min(diff, 360 - diff);
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public double angleClock(int hour, int minutes) {
    int oneMinAngle = 6;
    int oneHourAngle = 30;

    double minutesAngle = oneMinAngle * minutes;
    double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;

    double diff = Math.abs(hourAngle - minutesAngle);
    return Math.min(diff, 360 - diff);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        one_min_angle = 6
        one_hour_angle = 30
        
        minutes_angle = one_min_angle * minutes
        hour_angle = (hour % 12 + minutes / 60) * one_hour_angle
        
        diff = abs(hour_angle - minutes_angle)
        return min(diff, 360 - diff)
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        one_min_angle = 6
        one_hour_angle = 30
        
        minutes_angle = one_min_angle * minutes
        hour_angle = (hour % 12 + minutes / 60) * one_hour_angle
        
        diff = abs(hour_angle - minutes_angle)
        return min(diff, 360 - diff)
```

</details>
