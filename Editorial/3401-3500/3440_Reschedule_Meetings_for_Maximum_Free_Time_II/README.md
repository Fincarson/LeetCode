# 3440. Reschedule Meetings for Maximum Free Time II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/)  
`Array` `Greedy` `Enumeration`

**Problem Link:** [LeetCode 3440 - Reschedule Meetings for Maximum Free Time II](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/)

## Problem

You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays startTime and endTime, each of length n.

These represent the start and end times of n non-overlapping meetings that occur during the event between time t = 0 and time t = eventTime, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most one meeting by moving its start time while maintaining the same duration, such that the meetings remain non-overlapping, to maximize the longest continuous period of free time during the event.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event and they should remain non-overlapping.

Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting.

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- 1 <= eventTime <= 109
- n == startTime.length == endTime.length
- 2 <= n <= 105
- 0 <= startTime[i] < endTime[i] <= eventTime
- endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3440. Reschedule Meetings for Maximum Free Time II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Greedy + Optimization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxFreeTime(int eventTime, int* startTime, int startTimeSize, int* endTime,
                int endTimeSize) {
    int n = startTimeSize;
    bool* q = (bool*)calloc(n, sizeof(bool));
    int t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++) {
        if (endTime[i] - startTime[i] <= t1) {
            q[i] = true;
        }
        t1 = fmax(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

        if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
            q[n - i - 1] = true;
        }
        t2 = fmax(t2,
                  (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int left = i == 0 ? 0 : endTime[i - 1];
        int right = i == n - 1 ? eventTime : startTime[i + 1];
        if (q[i]) {
            res = fmax(res, right - left);
        } else {
            res = fmax(res, right - left - (endTime[i] - startTime[i]));
        }
    }
    free(q);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<bool> q(n);
        for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
            if (endTime[i] - startTime[i] <= t1) {
                q[i] = true;
            }
            t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
                q[n - i - 1] = true;
            }
            t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) -
                             endTime[n - i - 1]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = i == 0 ? 0 : endTime[i - 1];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            if (q[i]) {
                res = max(res, right - left);
            } else {
                res = max(res, right - left - (endTime[i] - startTime[i]));
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
    public int MaxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.Length;
        bool[] q = new bool[n];
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++) {
            if (endTime[i] - startTime[i] <= t1) {
                q[i] = true;
            }
            t1 = Math.Max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
                q[n - i - 1] = true;
            }
            t2 = Math.Max(t2, (i == 0 ? eventTime : startTime[n - i]) -
                                  endTime[n - i - 1]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = i == 0 ? 0 : endTime[i - 1];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            if (q[i]) {
                res = Math.Max(res, right - left);
            } else {
                res = Math.Max(res, right - left - (endTime[i] - startTime[i]));
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
func maxFreeTime(eventTime int, startTime []int, endTime []int) int {
	n := len(startTime)
	q := make([]bool, n)
	t1, t2 := 0, 0
	for i := 0; i < n; i++ {
		if endTime[i]-startTime[i] <= t1 {
			q[i] = true
		}
		if i == 0 {
			t1 = max(t1, startTime[i])
		} else {
			t1 = max(t1, startTime[i]-endTime[i-1])
		}

		if endTime[n-i-1]-startTime[n-i-1] <= t2 {
			q[n-i-1] = true
		}
		if i == 0 {
			t2 = max(t2, eventTime-endTime[n-1])
		} else {
			t2 = max(t2, startTime[n-i]-endTime[n-i-1])
		}
	}

	res := 0
	for i := 0; i < n; i++ {
		left := 0
		if i != 0 {
			left = endTime[i-1]
		}
		right := eventTime
		if i != n-1 {
			right = startTime[i+1]
		}
		if q[i] {
			res = max(res, right-left)
		} else {
			res = max(res, right-left-(endTime[i]-startTime[i]))
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

    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;
        boolean[] q = new boolean[n];
        for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
            if (endTime[i] - startTime[i] <= t1) {
                q[i] = true;
            }
            t1 = Math.max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
                q[n - i - 1] = true;
            }
            t2 = Math.max(
                t2,
                (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]
            );
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = i == 0 ? 0 : endTime[i - 1];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            if (q[i]) {
                res = Math.max(res, right - left);
            } else {
                res = Math.max(res, right - left - (endTime[i] - startTime[i]));
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
var maxFreeTime = function (eventTime, startTime, endTime) {
    const n = startTime.length;
    const q = new Array(n).fill(false);
    let t1 = 0,
        t2 = 0;
    for (let i = 0; i < n; i++) {
        if (endTime[i] - startTime[i] <= t1) {
            q[i] = true;
        }
        t1 = Math.max(t1, startTime[i] - (i === 0 ? 0 : endTime[i - 1]));

        if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
            q[n - i - 1] = true;
        }
        t2 = Math.max(
            t2,
            (i === 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1],
        );
    }

    let res = 0;
    for (let i = 0; i < n; i++) {
        const left = i === 0 ? 0 : endTime[i - 1];
        const right = i === n - 1 ? eventTime : startTime[i + 1];
        if (q[i]) {
            res = Math.max(res, right - left);
        } else {
            res = Math.max(res, right - left - (endTime[i] - startTime[i]));
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
        self, eventTime: int, startTime: list[int], endTime: list[int]
    ) -> int:
        n = len(startTime)
        q = [False] * n
        t1 = 0
        t2 = 0
        for i in range(n):
            if endTime[i] - startTime[i] <= t1:
                q[i] = True
            t1 = max(t1, startTime[i] - (0 if i == 0 else endTime[i - 1]))

            if endTime[n - i - 1] - startTime[n - i - 1] <= t2:
                q[n - i - 1] = True
            t2 = max(
                t2,
                (eventTime if i == 0 else startTime[n - i])
                - endTime[n - i - 1],
            )

        res = 0
        for i in range(n):
            left = 0 if i == 0 else endTime[i - 1]
            right = eventTime if i == n - 1 else startTime[i + 1]
            if q[i]:
                res = max(res, right - left)
            else:
                res = max(res, right - left - (endTime[i] - startTime[i]))
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxFreeTime(
    eventTime: number,
    startTime: number[],
    endTime: number[],
): number {
    const n = startTime.length;
    const q: boolean[] = new Array(n).fill(false);
    let t1 = 0,
        t2 = 0;
    for (let i = 0; i < n; i++) {
        if (endTime[i] - startTime[i] <= t1) {
            q[i] = true;
        }
        t1 = Math.max(t1, startTime[i] - (i === 0 ? 0 : endTime[i - 1]));

        if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
            q[n - i - 1] = true;
        }
        t2 = Math.max(
            t2,
            (i === 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1],
        );
    }

    let res = 0;
    for (let i = 0; i < n; i++) {
        const left = i === 0 ? 0 : endTime[i - 1];
        const right = i === n - 1 ? eventTime : startTime[i + 1];
        if (q[i]) {
            res = Math.max(res, right - left);
        } else {
            res = Math.max(res, right - left - (endTime[i] - startTime[i]));
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: Greedy + Optimization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxFreeTime(int eventTime, int* startTime, int startTimeSize, int* endTime,
                int endTimeSize) {
    int n = startTimeSize;
    bool* q = (bool*)calloc(n, sizeof(bool));
    int t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++) {
        if (endTime[i] - startTime[i] <= t1) {
            q[i] = true;
        }
        t1 = fmax(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

        if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
            q[n - i - 1] = true;
        }
        t2 = fmax(t2,
                  (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int left = i == 0 ? 0 : endTime[i - 1];
        int right = i == n - 1 ? eventTime : startTime[i + 1];
        if (q[i]) {
            res = fmax(res, right - left);
        } else {
            res = fmax(res, right - left - (endTime[i] - startTime[i]));
        }
    }
    free(q);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size(), res = 0;
        for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
            int left1 = i == 0 ? 0 : endTime[i - 1];
            int right1 = i == n - 1 ? eventTime : startTime[i + 1];
            if (endTime[i] - startTime[i] <= t1) {
                res = max(res, right1 - left1);
            }
            t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            res = max(res, right1 - left1 - (endTime[i] - startTime[i]));

            int left2 = i == n - 1 ? 0 : endTime[n - i - 2];
            int right2 = i == 0 ? eventTime : startTime[n - i];
            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
                res = max(res, right2 - left2);
            }
            t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) -
                             endTime[n - i - 1]);
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
    public int MaxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.Length;
        bool[] q = new bool[n];
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++) {
            if (endTime[i] - startTime[i] <= t1) {
                q[i] = true;
            }
            t1 = Math.Max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
                q[n - i - 1] = true;
            }
            t2 = Math.Max(t2, (i == 0 ? eventTime : startTime[n - i]) -
                                  endTime[n - i - 1]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = i == 0 ? 0 : endTime[i - 1];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            if (q[i]) {
                res = Math.Max(res, right - left);
            } else {
                res = Math.Max(res, right - left - (endTime[i] - startTime[i]));
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
func maxFreeTime(eventTime int, startTime []int, endTime []int) int {
	n := len(startTime)
	q := make([]bool, n)
	t1, t2 := 0, 0
	for i := 0; i < n; i++ {
		if endTime[i]-startTime[i] <= t1 {
			q[i] = true
		}
		if i == 0 {
			t1 = max(t1, startTime[i])
		} else {
			t1 = max(t1, startTime[i]-endTime[i-1])
		}

		if endTime[n-i-1]-startTime[n-i-1] <= t2 {
			q[n-i-1] = true
		}
		if i == 0 {
			t2 = max(t2, eventTime-endTime[n-1])
		} else {
			t2 = max(t2, startTime[n-i]-endTime[n-i-1])
		}
	}

	res := 0
	for i := 0; i < n; i++ {
		left := 0
		if i != 0 {
			left = endTime[i-1]
		}
		right := eventTime
		if i != n-1 {
			right = startTime[i+1]
		}
		if q[i] {
			res = max(res, right-left)
		} else {
			res = max(res, right-left-(endTime[i]-startTime[i]))
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

    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;
        boolean[] q = new boolean[n];
        for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
            if (endTime[i] - startTime[i] <= t1) {
                q[i] = true;
            }
            t1 = Math.max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
                q[n - i - 1] = true;
            }
            t2 = Math.max(
                t2,
                (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]
            );
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = i == 0 ? 0 : endTime[i - 1];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            if (q[i]) {
                res = Math.max(res, right - left);
            } else {
                res = Math.max(res, right - left - (endTime[i] - startTime[i]));
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
var maxFreeTime = function (eventTime, startTime, endTime) {
    const n = startTime.length;
    const q = new Array(n).fill(false);
    let t1 = 0,
        t2 = 0;
    for (let i = 0; i < n; i++) {
        if (endTime[i] - startTime[i] <= t1) {
            q[i] = true;
        }
        t1 = Math.max(t1, startTime[i] - (i === 0 ? 0 : endTime[i - 1]));

        if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
            q[n - i - 1] = true;
        }
        t2 = Math.max(
            t2,
            (i === 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1],
        );
    }

    let res = 0;
    for (let i = 0; i < n; i++) {
        const left = i === 0 ? 0 : endTime[i - 1];
        const right = i === n - 1 ? eventTime : startTime[i + 1];
        if (q[i]) {
            res = Math.max(res, right - left);
        } else {
            res = Math.max(res, right - left - (endTime[i] - startTime[i]));
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
        self, eventTime: int, startTime: list[int], endTime: list[int]
    ) -> int:
        n = len(startTime)
        q = [False] * n
        t1 = 0
        t2 = 0
        for i in range(n):
            if endTime[i] - startTime[i] <= t1:
                q[i] = True
            t1 = max(t1, startTime[i] - (0 if i == 0 else endTime[i - 1]))

            if endTime[n - i - 1] - startTime[n - i - 1] <= t2:
                q[n - i - 1] = True
            t2 = max(
                t2,
                (eventTime if i == 0 else startTime[n - i])
                - endTime[n - i - 1],
            )

        res = 0
        for i in range(n):
            left = 0 if i == 0 else endTime[i - 1]
            right = eventTime if i == n - 1 else startTime[i + 1]
            if q[i]:
                res = max(res, right - left)
            else:
                res = max(res, right - left - (endTime[i] - startTime[i]))
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxFreeTime(
    eventTime: number,
    startTime: number[],
    endTime: number[],
): number {
    const n = startTime.length;
    const q: boolean[] = new Array(n).fill(false);
    let t1 = 0,
        t2 = 0;
    for (let i = 0; i < n; i++) {
        if (endTime[i] - startTime[i] <= t1) {
            q[i] = true;
        }
        t1 = Math.max(t1, startTime[i] - (i === 0 ? 0 : endTime[i - 1]));

        if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
            q[n - i - 1] = true;
        }
        t2 = Math.max(
            t2,
            (i === 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1],
        );
    }

    let res = 0;
    for (let i = 0; i < n; i++) {
        const left = i === 0 ? 0 : endTime[i - 1];
        const right = i === n - 1 ? eventTime : startTime[i + 1];
        if (q[i]) {
            res = Math.max(res, right - left);
        } else {
            res = Math.max(res, right - left - (endTime[i] - startTime[i]));
        }
    }
    return res;
}
```

</details>
