# 3296. Minimum Number of Seconds to Make Mountain Height Zero

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/)  
`Array` `Math` `Binary Search` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 3296 - Minimum Number of Seconds to Make Mountain Height Zero](https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/)

## Problem

You are given an integer mountainHeight denoting the height of a mountain.

You are also given an integer array workerTimes representing the work time of workers in seconds.

Each worker may reduce the mountain's height by any non-negative integer amount. If worker i reduces the height by x, then:

- reducing the first unit of height takes workerTimes[i] seconds,
- reducing the second unit takes workerTimes[i] * 2 seconds,
- ...
- reducing the x-th unit takes workerTimes[i] * x seconds.

The total time spent by worker i is the sum of the times required for all x units they reduce. As all workers operate simultaneously, the total time required is the maximum time spent by any worker.

Return an integer representing the minimum number of seconds required for the workers to make the height of the mountain 0.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= mountainHeight <= 105
- 1 <= workerTimes.length <= 104
- 1 <= workerTimes[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3296. Minimum Number of Seconds to Make Mountain Height Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Answer | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Binary Answer

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define EPS 1e-7

long long minNumberOfSeconds(int mountainHeight, int* workerTimes,
                             int workerTimesSize) {
    int maxWorkerTimes = 0;
    for (int i = 0; i < workerTimesSize; i++) {
        if (workerTimes[i] > maxWorkerTimes) {
            maxWorkerTimes = workerTimes[i];
        }
    }

    long long l = 1;
    long long r =
        (long long)maxWorkerTimes * mountainHeight * (mountainHeight + 1) / 2;
    long long ans = 0;

    while (l <= r) {
        long long mid = (l + r) / 2;
        long long cnt = 0;
        for (int i = 0; i < workerTimesSize; i++) {
            long long work = mid / workerTimes[i];
            // find the largest k such that 1+2+...+k <= work
            long long k = (long long)((-1.0 + sqrt(1 + work * 8)) / 2 + EPS);
            cnt += k;
        }

        if (cnt >= mountainHeight) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxWorkerTimes =
            *max_element(workerTimes.begin(), workerTimes.end());
        long long l = 1, r = static_cast<long long>(maxWorkerTimes) *
                             mountainHeight * (mountainHeight + 1) / 2;
        long long ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;
            long long cnt = 0;
            for (int t : workerTimes) {
                long long work = mid / t;
                // find the largest k such that 1+2+...+k <= work
                long long k = (-1.0 + sqrt(1 + work * 8)) / 2 + eps;
                cnt += k;
            }
            if (cnt >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

private:
    static constexpr double eps = 1e-7;
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    private const double EPS = 1e-7;

    public long MinNumberOfSeconds(int mountainHeight, int[] workerTimes) {
        int maxWorkerTimes = 0;
        foreach (int t in workerTimes) {
            maxWorkerTimes = Math.Max(maxWorkerTimes, t);
        }

        long l = 1;
        long r =
            (long)maxWorkerTimes * mountainHeight * (mountainHeight + 1) / 2;
        long ans = 0;

        while (l <= r) {
            long mid = (l + r) / 2;
            long cnt = 0;

            foreach (int t in workerTimes) {
                long work = mid / t;
                // find the largest k such that 1+2+...+k <= work
                long k = (long)((-1.0 + Math.Sqrt(1 + work * 8)) / 2 + EPS);
                cnt += k;
            }

            if (cnt >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
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
const eps = 1e-7

func minNumberOfSeconds(mountainHeight int, workerTimes []int) int64 {
    maxWorkerTimes := 0
    for _, t := range workerTimes {
        if t > maxWorkerTimes {
            maxWorkerTimes = t
        }
    }
    
    l := int64(1)
    r := int64(maxWorkerTimes) * int64(mountainHeight) * int64(mountainHeight + 1) / 2
    var ans int64 = 0
    
    for l <= r {
        mid := (l + r) / 2
        var cnt int64 = 0
        
        for _, t := range workerTimes {
            work := mid / int64(t)
            // find the largest k such that 1+2+...+k <= work
            k := int64((-1.0 + math.Sqrt(1 + float64(work) * 8)) / 2 + eps)
            cnt += k
        }
        if cnt >= int64(mountainHeight) {
            ans = mid
            r = mid - 1
        } else {
            l = mid + 1
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

    private static final double EPS = 1e-7;

    public long minNumberOfSeconds(int mountainHeight, int[] workerTimes) {
        int maxWorkerTimes = 0;
        for (int t : workerTimes) {
            maxWorkerTimes = Math.max(maxWorkerTimes, t);
        }

        long l = 1;
        long r =
            ((long) maxWorkerTimes * mountainHeight * (mountainHeight + 1)) / 2;
        long ans = 0;

        while (l <= r) {
            long mid = (l + r) / 2;
            long cnt = 0;
            for (int t : workerTimes) {
                long work = mid / t;
                // find the largest k such that 1+2+...+k <= work
                long k = (long) ((-1.0 + Math.sqrt(1 + work * 8)) / 2 + EPS);
                cnt += k;
            }

            if (cnt >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
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
const EPS = 1e-7;

var minNumberOfSeconds = function (mountainHeight, workerTimes) {
    const maxWorkerTimes = Math.max(...workerTimes);
    let l = 1;
    let r = (maxWorkerTimes * mountainHeight * (mountainHeight + 1)) / 2;
    let ans = 0;

    while (l <= r) {
        const mid = Math.floor((l + r) / 2);
        let cnt = 0;
        for (const t of workerTimes) {
            const work = Math.floor(mid / t);
            // find the largest k such that 1+2+...+k <= work
            const k = Math.floor((-1.0 + Math.sqrt(1 + work * 8)) / 2 + EPS);
            cnt += k;
        }

        if (cnt >= mountainHeight) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
    def minNumberOfSeconds(
        self, mountainHeight: int, workerTimes: List[int]
    ) -> int:
        maxWorkerTimes = max(workerTimes)
        l, r, ans = (
            1,
            maxWorkerTimes * mountainHeight * (mountainHeight + 1) // 2,
            0,
        )
        eps = 1e-7

        while l <= r:
            mid = (l + r) // 2
            cnt = 0
            for t in workerTimes:
                work = mid // t
                # find the largest k such that 1+2+...+k <= work
                k = int((-1 + ((1 + work * 8) ** 0.5)) / 2 + eps)
                cnt += k
            if cnt >= mountainHeight:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const EPS: number = 1e-7;

function minNumberOfSeconds(
    mountainHeight: number,
    workerTimes: number[],
): number {
    const maxWorkerTimes: number = Math.max(...workerTimes);
    let l: number = 1;
    let r: number =
        (maxWorkerTimes * mountainHeight * (mountainHeight + 1)) / 2;
    let ans: number = 0;

    while (l <= r) {
        const mid: number = Math.floor((l + r) / 2);
        let cnt: number = 0;
        for (const t of workerTimes) {
            const work: number = Math.floor(mid / t);
            // find the largest k such that 1+2+...+k <= work
            const k: number = Math.floor(
                (-1.0 + Math.sqrt(1 + work * 8)) / 2 + EPS,
            );
            cnt += k;
        }

        if (cnt >= mountainHeight) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}
```

</details>
