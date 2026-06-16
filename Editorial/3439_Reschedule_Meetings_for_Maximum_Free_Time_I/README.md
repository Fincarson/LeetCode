# 3439. Reschedule Meetings for Maximum Free Time I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/)  
`Array` `Greedy` `Sliding Window`

**Problem Link:** [LeetCode 3439 - Reschedule Meetings for Maximum Free Time I](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/)

## Problem

You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.

You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.

The relative order of all the meetings should stay the same and they should remain non-overlapping.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= eventTime <= 109
- n == startTime.length == endTime.length
- 2 <= n <= 105
- 1 <= k <= n
- 0 <= startTime[i] < endTime[i] <= eventTime
- endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Meeting Scheduler](https://leetcode.com/problems/meeting-scheduler/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3439. Reschedule Meetings for Maximum Free Time I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy + Prefix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Greedy + Sliding Window | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Greedy + Prefix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxFreeTime(int eventTime, int k, int* startTime, int startSize,
                int* endTime, int endSize) {
    int n = startSize;
    int res = 0;
    int* sum = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + endTime[i] - startTime[i];
    }
    for (int i = k - 1; i < n; i++) {
        int right = (i == n - 1) ? eventTime : startTime[i + 1];
        int left = (i == k - 1) ? 0 : endTime[i - k];
        int val = right - left - (sum[i + 1] - sum[i - k + 1]);
        res = fmax(res, val);
    }
    free(sum);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size(), res = 0;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + endTime[i] - startTime[i];
        }
        for (int i = k - 1; i < n; i++) {
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            int left = i == k - 1 ? 0 : endTime[i - k];
            res = max(res, right - left - (sum[i + 1] - sum[i - k + 1]));
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
    public int MaxFreeTime(int eventTime, int k, int[] startTime,
                           int[] endTime) {
        int n = startTime.Length, res = 0;
        int[] sum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + endTime[i] - startTime[i];
        }
        for (int i = k - 1; i < n; i++) {
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            int left = i == k - 1 ? 0 : endTime[i - k];
            res = Math.Max(res, right - left - (sum[i + 1] - sum[i - k + 1]));
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxFreeTime(eventTime int, k int, startTime []int, endTime []int) int {
	n := len(startTime)
	res := 0
	sum := make([]int, n+1)
	for i := 0; i < n; i++ {
		sum[i+1] = sum[i] + endTime[i] - startTime[i]
	}
	for i := k - 1; i < n; i++ {
		var right int
		if i == n-1 {
			right = eventTime
		} else {
			right = startTime[i+1]
		}
		var left int
		if i == k-1 {
			left = 0
		} else {
			left = endTime[i-k]
		}
		res = max(res, right-left-(sum[i+1]-sum[i-k+1]))
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maxFreeTime(
        int eventTime,
        int k,
        int[] startTime,
        int[] endTime
    ) {
        int n = startTime.length;
        int res = 0;
        int[] sum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + endTime[i] - startTime[i];
        }
        for (int i = k - 1; i < n; i++) {
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            int left = i == k - 1 ? 0 : endTime[i - k];
            res = Math.max(res, right - left - (sum[i + 1] - sum[i - k + 1]));
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxFreeTime = function (eventTime, k, startTime, endTime) {
    let n = startTime.length,
        res = 0;
    let sum = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + endTime[i] - startTime[i];
    }
    for (let i = k - 1; i < n; i++) {
        let right = i === n - 1 ? eventTime : startTime[i + 1];
        let left = i === k - 1 ? 0 : endTime[i - k];
        res = Math.max(res, right - left - (sum[i + 1] - sum[i - k + 1]));
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxFreeTime(
        self, eventTime: int, k: int, startTime: List[int], endTime: List[int]
    ) -> int:
        n = len(startTime)
        res = 0
        total = [0] * (n + 1)
        for i in range(n):
            total[i + 1] = total[i] + endTime[i] - startTime[i]
        for i in range(k - 1, n):
            right = eventTime if i == n - 1 else startTime[i + 1]
            left = 0 if i == k - 1 else endTime[i - k]
            res = max(res, right - left - (total[i + 1] - total[i - k + 1]))
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxFreeTime(
    eventTime: number,
    k: number,
    startTime: number[],
    endTime: number[],
): number {
    let n = startTime.length,
        res = 0;
    let sum: number[] = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + endTime[i] - startTime[i];
    }
    for (let i = k - 1; i < n; i++) {
        let right = i === n - 1 ? eventTime : startTime[i + 1];
        let left = i === k - 1 ? 0 : endTime[i - k];
        res = Math.max(res, right - left - (sum[i + 1] - sum[i - k + 1]));
    }
    return res;
}
```

</details>

<br>

## Approach 2: Greedy + Sliding Window

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxFreeTime(int eventTime, int k, int* startTime, int startSize,
                int* endTime, int endSize) {
    int n = startSize;
    int res = 0, t = 0;
    for (int i = 0; i < n; i++) {
        t += endTime[i] - startTime[i];
        int left = (i <= k - 1) ? 0 : endTime[i - k];
        int right = (i == n - 1) ? eventTime : startTime[i + 1];
        if (right - left - t > res) res = right - left - t;
        if (i >= k - 1) {
            t -= endTime[i - k + 1] - startTime[i - k + 1];
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
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size(), res = 0, t = 0;
        for (int i = 0; i < n; i++) {
            t += endTime[i] - startTime[i];
            int left = i <= k - 1 ? 0 : endTime[i - k];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            res = max(res, right - left - t);
            if (i >= k - 1) {
                t -= endTime[i - k + 1] - startTime[i - k + 1];
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
    public int MaxFreeTime(int eventTime, int k, int[] startTime,
                           int[] endTime) {
        int n = startTime.Length, res = 0, t = 0;
        for (int i = 0; i < n; i++) {
            t += endTime[i] - startTime[i];
            int left = i <= k - 1 ? 0 : endTime[i - k];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            res = Math.Max(res, right - left - t);
            if (i >= k - 1) {
                t -= endTime[i - k + 1] - startTime[i - k + 1];
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
func maxFreeTime(eventTime int, k int, startTime []int, endTime []int) int {
	n := len(startTime)
	res := 0
	t := 0
	for i := 0; i < n; i++ {
		t += endTime[i] - startTime[i]
		var left int
		if i <= k-1 {
			left = 0
		} else {
			left = endTime[i-k]
		}
		var right int
		if i == n-1 {
			right = eventTime
		} else {
			right = startTime[i+1]
		}
		if right-left-t > res {
			res = right - left - t
		}
		if i >= k-1 {
			t -= endTime[i-k+1] - startTime[i-k+1]
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maxFreeTime(
        int eventTime,
        int k,
        int[] startTime,
        int[] endTime
    ) {
        int n = startTime.length;
        int res = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            t += endTime[i] - startTime[i];
            int left = i <= k - 1 ? 0 : endTime[i - k];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            res = Math.max(res, right - left - t);
            if (i >= k - 1) {
                t -= endTime[i - k + 1] - startTime[i - k + 1];
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
var maxFreeTime = function (eventTime, k, startTime, endTime) {
    let n = startTime.length,
        res = 0,
        t = 0;
    for (let i = 0; i < n; i++) {
        t += endTime[i] - startTime[i];
        let left = i <= k - 1 ? 0 : endTime[i - k];
        let right = i === n - 1 ? eventTime : startTime[i + 1];
        res = Math.max(res, right - left - t);
        if (i >= k - 1) {
            t -= endTime[i - k + 1] - startTime[i - k + 1];
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
    def maxFreeTime(
        self, eventTime: int, k: int, startTime: List[int], endTime: List[int]
    ) -> int:
        n = len(startTime)
        res = 0
        t = 0
        for i in range(n):
            t += endTime[i] - startTime[i]
            left = 0 if i <= k - 1 else endTime[i - k]
            right = eventTime if i == n - 1 else startTime[i + 1]
            res = max(res, right - left - t)
            if i >= k - 1:
                t -= endTime[i - k + 1] - startTime[i - k + 1]
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxFreeTime(
    eventTime: number,
    k: number,
    startTime: number[],
    endTime: number[],
): number {
    let n = startTime.length,
        res = 0,
        t = 0;
    for (let i = 0; i < n; i++) {
        t += endTime[i] - startTime[i];
        let left = i <= k - 1 ? 0 : endTime[i - k];
        let right = i === n - 1 ? eventTime : startTime[i + 1];
        res = Math.max(res, right - left - t);
        if (i >= k - 1) {
            t -= endTime[i - k + 1] - startTime[i - k + 1];
        }
    }
    return res;
}
```

</details>
