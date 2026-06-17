# 3633. Earliest Finish Time for Land and Water Rides I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/)  
`Array` `Two Pointers` `Binary Search` `Greedy` `Sorting`

**Problem Link:** [LeetCode 3633 - Earliest Finish Time for Land and Water Rides I](https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/)

## Problem

You are given two categories of theme park attractions: land rides and water rides.

- Land rides

		landStartTime[i] Ã¢â‚¬â€œ the earliest time the ith land ride can be boarded.
		landDuration[i] Ã¢â‚¬â€œ how long the ith land ride lasts.
- Water rides

		waterStartTime[j] Ã¢â‚¬â€œ the earliest time the jth water ride can be boarded.
		waterDuration[j] Ã¢â‚¬â€œ how long the jth water ride lasts.

A tourist must experience exactly one ride from each category, in either order.

- A ride may be started at its opening time or any later moment.
- If a ride is started at time t, it finishes at time t + duration.
- Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.

Return the earliest possible time at which the tourist can finish both rides.

### Example 1

### Example 2

## Constraints

- 1 <= n, m <= 100
- landStartTime.length == landDuration.length == n
- waterStartTime.length == waterDuration.length == m
- 1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3633. Earliest Finish Time for Land and Water Rides I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force Enumeration + Classification Discussion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Linear Enumeration + Classification Discussion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force Enumeration + Classification Discussion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int earliestFinishTime(int* landStartTime, int landStartTimeSize,
                       int* landDuration, int landDurationSize,
                       int* waterStartTime, int waterStartTimeSize,
                       int* waterDuration, int waterDurationSize) {
    int n = landStartTimeSize;
    int m = waterStartTimeSize;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int land = landStartTime[i] + landDuration[i];
            int land_water = MAX(land, waterStartTime[j]) + waterDuration[j];
            res = MIN(res, land_water);

            int water = waterStartTime[j] + waterDuration[j];
            int water_land = MAX(water, landStartTime[i]) + landDuration[i];
            res = MIN(res, water_land);
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
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int land = landStartTime[i] + landDuration[i];
                int land_water =
                    max(land, waterStartTime[j]) + waterDuration[j];
                res = min(res, land_water);

                int water = waterStartTime[j] + waterDuration[j];
                int water_land = max(water, landStartTime[i]) + landDuration[i];
                res = min(res, water_land);
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
    public int EarliestFinishTime(int[] landStartTime, int[] landDuration,
                                  int[] waterStartTime, int[] waterDuration) {
        int n = landStartTime.Length;
        int m = waterStartTime.Length;
        int res = int.MaxValue;
        ;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int land = landStartTime[i] + landDuration[i];
                int land_water =
                    Math.Max(land, waterStartTime[j]) + waterDuration[j];
                res = Math.Min(res, land_water);

                int water = waterStartTime[j] + waterDuration[j];
                int water_land =
                    Math.Max(water, landStartTime[i]) + landDuration[i];
                res = Math.Min(res, water_land);
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
func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {
    n := len(landStartTime)
    m := len(waterStartTime)
    res := 1000000
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            land := landStartTime[i] + landDuration[i]
            land_water := land
            if waterStartTime[j] > land_water {
                land_water = waterStartTime[j]
            }
            land_water += waterDuration[j]
            if land_water < res {
                res = land_water
            }

            water := waterStartTime[j] + waterDuration[j]
            water_land := water
            if landStartTime[i] > water_land {
                water_land = landStartTime[i]
            }
            water_land += landDuration[i]
            if water_land < res {
                res = water_land
            }
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

    public int earliestFinishTime(
        int[] landStartTime,
        int[] landDuration,
        int[] waterStartTime,
        int[] waterDuration
    ) {
        int n = landStartTime.length;
        int m = waterStartTime.length;
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int land = landStartTime[i] + landDuration[i];
                int land_water =
                    Math.max(land, waterStartTime[j]) + waterDuration[j];
                res = Math.min(res, land_water);

                int water = waterStartTime[j] + waterDuration[j];
                int water_land =
                    Math.max(water, landStartTime[i]) + landDuration[i];
                res = Math.min(res, water_land);
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
var earliestFinishTime = function (
    landStartTime,
    landDuration,
    waterStartTime,
    waterDuration,
) {
    let n = landStartTime.length;
    let m = waterStartTime.length;
    let res = Infinity;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            let land = landStartTime[i] + landDuration[i];
            let land_water =
                Math.max(land, waterStartTime[j]) + waterDuration[j];
            res = Math.min(res, land_water);

            let water = waterStartTime[j] + waterDuration[j];
            let water_land =
                Math.max(water, landStartTime[i]) + landDuration[i];
            res = Math.min(res, water_land);
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
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int],
    ) -> int:
        n = len(landStartTime)
        m = len(waterStartTime)
        res = inf
        for i in range(n):
            for j in range(m):
                land = landStartTime[i] + landDuration[i]
                land_water = max(land, waterStartTime[j]) + waterDuration[j]
                res = min(res, land_water)

                water = waterStartTime[j] + waterDuration[j]
                water_land = max(water, landStartTime[i]) + landDuration[i]
                res = min(res, water_land)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function earliestFinishTime(
    landStartTime: number[],
    landDuration: number[],
    waterStartTime: number[],
    waterDuration: number[],
): number {
    let n = landStartTime.length;
    let m = waterStartTime.length;
    let res = Infinity;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            let land = landStartTime[i] + landDuration[i];
            let land_water =
                Math.max(land, waterStartTime[j]) + waterDuration[j];
            res = Math.min(res, land_water);

            let water = waterStartTime[j] + waterDuration[j];
            let water_land =
                Math.max(water, landStartTime[i]) + landDuration[i];
            res = Math.min(res, water_land);
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: Linear Enumeration + Classification Discussion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int solve(int* start1, int start1Size, int* duration1, int* start2,
          int start2Size, int* duration2) {
    int finish1 = INT_MAX;
    for (int i = 0; i < start1Size; i++) {
        finish1 = min(finish1, start1[i] + duration1[i]);
    }
    int finish2 = INT_MAX;
    for (int i = 0; i < start2Size; i++) {
        finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
    }
    return finish2;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize,
                       int* landDuration, int landDurationSize,
                       int* waterStartTime, int waterStartTimeSize,
                       int* waterDuration, int waterDurationSize) {
    int land_water = solve(landStartTime, landStartTimeSize, landDuration,
                           waterStartTime, waterStartTimeSize, waterDuration);
    int water_land = solve(waterStartTime, waterStartTimeSize, waterDuration,
                           landStartTime, landStartTimeSize, landDuration);
    return min(land_water, water_land);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2,
              vector<int>& duration2) {
        int finish1 = INT_MAX;
        for (int i = 0; i < start1.size(); i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for (int i = 0; i < start2.size(); i++) {
            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int solve(int[] start1, int[] duration1, int[] start2,
                      int[] duration2) {
        int finish1 = int.MaxValue;
        for (int i = 0; i < start1.Length; i++) {
            finish1 = Math.Min(finish1, start1[i] + duration1[i]);
        }
        int finish2 = int.MaxValue;
        for (int i = 0; i < start2.Length; i++) {
            finish2 =
                Math.Min(finish2, Math.Max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }

    public int EarliestFinishTime(int[] landStartTime, int[] landDuration,
                                  int[] waterStartTime, int[] waterDuration) {
        int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return Math.Min(land_water, water_land);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {
    solve := func(start1, duration1, start2, duration2 []int) int {
        finish1 := 2147483647
        for i := 0; i < len(start1); i++ {
            if val := start1[i] + duration1[i]; val < finish1 {
                finish1 = val
            }
        }
        finish2 := 2147483647
        for i := 0; i < len(start2); i++ {
            curStart := start2[i]
            if finish1 > curStart {
                curStart = finish1
            }
            if val := curStart + duration2[i]; val < finish2 {
                finish2 = val
            }
        }
        return finish2
    }

    land_water := solve(landStartTime, landDuration, waterStartTime, waterDuration)
    water_land := solve(waterStartTime, waterDuration, landStartTime, landDuration)
    if land_water < water_land {
        return land_water
    }
    return water_land
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int solve(
        int[] start1,
        int[] duration1,
        int[] start2,
        int[] duration2
    ) {
        int finish1 = Integer.MAX_VALUE;
        for (int i = 0; i < start1.length; i++) {
            finish1 = Math.min(finish1, start1[i] + duration1[i]);
        }
        int finish2 = Integer.MAX_VALUE;
        for (int i = 0; i < start2.length; i++) {
            finish2 = Math.min(
                finish2,
                Math.max(start2[i], finish1) + duration2[i]
            );
        }
        return finish2;
    }

    public int earliestFinishTime(
        int[] landStartTime,
        int[] landDuration,
        int[] waterStartTime,
        int[] waterDuration
    ) {
        int land_water = solve(
            landStartTime,
            landDuration,
            waterStartTime,
            waterDuration
        );
        int water_land = solve(
            waterStartTime,
            waterDuration,
            landStartTime,
            landDuration
        );
        return Math.min(land_water, water_land);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var earliestFinishTime = function (
    landStartTime,
    landDuration,
    waterStartTime,
    waterDuration,
) {
    function solve(start1, duration1, start2, duration2) {
        let finish1 = Infinity;
        for (let i = 0; i < start1.length; i++) {
            finish1 = Math.min(finish1, start1[i] + duration1[i]);
        }
        let finish2 = Infinity;
        for (let i = 0; i < start2.length; i++) {
            finish2 = Math.min(
                finish2,
                Math.max(start2[i], finish1) + duration2[i],
            );
        }
        return finish2;
    }

    let land_water = solve(
        landStartTime,
        landDuration,
        waterStartTime,
        waterDuration,
    );
    let water_land = solve(
        waterStartTime,
        waterDuration,
        landStartTime,
        landDuration,
    );
    return Math.min(land_water, water_land);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int],
    ) -> int:
        def solve(start1, duration1, start2, duration2):
            finish1 = inf
            for i in range(len(start1)):
                finish1 = min(finish1, start1[i] + duration1[i])
            finish2 = inf
            for i in range(len(start2)):
                finish2 = min(finish2, max(start2[i], finish1) + duration2[i])
            return finish2

        land_water = solve(
            landStartTime, landDuration, waterStartTime, waterDuration
        )
        water_land = solve(
            waterStartTime, waterDuration, landStartTime, landDuration
        )
        return min(land_water, water_land)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function solve(start1, duration1, start2, duration2) {
    let finish1 = Infinity;
    for (let i = 0; i < start1.length; i++) {
        finish1 = Math.min(finish1, start1[i] + duration1[i]);
    }
    let finish2 = Infinity;
    for (let i = 0; i < start2.length; i++) {
        finish2 = Math.min(
            finish2,
            Math.max(start2[i], finish1) + duration2[i],
        );
    }
    return finish2;
}

function earliestFinishTime(
    landStartTime: number[],
    landDuration: number[],
    waterStartTime: number[],
    waterDuration: number[],
): number {
    let land_water = solve(
        landStartTime,
        landDuration,
        waterStartTime,
        waterDuration,
    );
    let water_land = solve(
        waterStartTime,
        waterDuration,
        landStartTime,
        landDuration,
    );
    return Math.min(land_water, water_land);
}
```

</details>
