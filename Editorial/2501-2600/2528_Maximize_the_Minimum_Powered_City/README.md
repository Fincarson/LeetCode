# 2528. Maximize the Minimum Powered City

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximize-the-minimum-powered-city/)  
`Array` `Binary Search` `Greedy` `Queue` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 2528 - Maximize the Minimum Powered City](https://leetcode.com/problems/maximize-the-minimum-powered-city/)

## Problem

You are given a 0-indexed integer array stations of length n, where stations[i] represents the number of power stations in the ith city.

Each power station can provide power to every city in a fixed range. In other words, if the range is denoted by r, then a power station at city i can provide power to all cities j such that |i - j| <= r and 0 <= i, j <= n - 1.

- Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 - 10| = 7.

The power of a city is the total number of power stations it is being provided power from.

The government has sanctioned building k more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.

Given the two integers r and k, return the maximum possible minimum power of a city, if the additional power stations are built optimally.

Note that you can build the k power stations in multiple cities.

### Example 1

```text
Input: stations = [1,2,4,5,0], r = 1, k = 2
Output: 5
Explanation:
One of the optimal ways is to install both the power stations at city 1.
So stations will become [1,4,4,5,0].
- City 0 is provided by 1 + 4 = 5 power stations.
- City 1 is provided by 1 + 4 + 4 = 9 power stations.
- City 2 is provided by 4 + 4 + 5 = 13 power stations.
- City 3 is provided by 5 + 4 = 9 power stations.
- City 4 is provided by 5 + 0 = 5 power stations.
So the minimum power of a city is 5.
Since it is not possible to obtain a larger power, we return 5.
```

### Example 2

```text
Input: stations = [4,4,4,4], r = 0, k = 3
Output: 4
Explanation:
It can be proved that we cannot make the minimum power of a city greater than 4.
```

## Constraints

- n == stations.length
- 1 <= n <= 105
- 0 <= stations[i] <= 105
- 0 <= r <= n - 1
- 0 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2528. Maximize the Minimum Powered City

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search + Difference Array | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Binary Search + Difference Array

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool check(long long* cnt, int r, long long k, long long val, int n) {
    long long* diff = (long long*)malloc((n + 1) * sizeof(long long));
    memcpy(diff, cnt, (n + 1) * sizeof(long long));

    long long sum = 0;
    long long remaining = k;

    for (int i = 0; i < n; i++) {
        sum += diff[i];
        if (sum < val) {
            long long add = val - sum;
            if (remaining < add) {
                free(diff);
                return false;
            }
            remaining -= add;
            int end = fmin(n, i + 2 * r + 1);
            diff[end] -= add;
            sum += add;
        }
    }
    free(diff);
    return true;
}

long long maxPower(int* stations, int stationsSize, int r, int k) {
    int n = stationsSize;
    long long* cnt = (long long*)calloc(n + 1, sizeof(long long));

    for (int i = 0; i < n; i++) {
        int left = fmax(0, i - r);
        int right = fmin(n, i + r + 1);
        cnt[left] += stations[i];
        cnt[right] -= stations[i];
    }

    long long minStation = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (stations[i] < minStation) {
            minStation = stations[i];
        }
    }

    long long minVal = LLONG_MAX;
    long long sumTotal = 0;
    for (int i = 0; i < n; i++) {
        if (stations[i] < minVal) {
            minVal = stations[i];
        }
        sumTotal += stations[i];
    }
    long long hi = sumTotal + k;
    long long lo = minVal;
    long long res = 0;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (check(cnt, r, k, mid, n)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    free(cnt);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            cnt[left] += stations[i];
            cnt[right] -= stations[i];
        }

        auto check = [&](long long val) -> bool {
            vector<long long> diff = cnt;
            long long sum = 0;
            long long remaining = k;

            for (int i = 0; i < n; i++) {
                sum += diff[i];
                if (sum < val) {
                    long long add = val - sum;
                    if (remaining < add) {
                        return false;
                    }
                    remaining -= add;
                    int end = min(n, i + 2 * r + 1);
                    diff[end] -= add;
                    sum += add;
                }
            }
            return true;
        };

        long long lo = ranges::min(stations);
        long long hi = accumulate(stations.begin(), stations.end(), 0LL) + k;
        long long res = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
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
    public long MaxPower(int[] stations, int r, int k) {
        int n = stations.Length;
        long[] cnt = new long[n + 1];

        for (int i = 0; i < n; i++) {
            int left = Math.Max(0, i - r);
            int right = Math.Min(n, i + r + 1);
            cnt[left] += stations[i];
            cnt[right] -= stations[i];
        }

        long lo = stations.Min();
        long hi = stations.Sum(x => (long)x) + k;
        long res = 0;

        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            if (Check(cnt, mid, r, k)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }

    private bool Check(long[] cnt, long val, int r, int k) {
        int n = cnt.Length - 1;
        long[] diff = (long[])cnt.Clone();
        long sum = 0;
        long remaining = k;

        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (sum < val) {
                long add = val - sum;
                if (remaining < add) {
                    return false;
                }
                remaining -= add;
                int end = Math.Min(n, i + 2 * r + 1);
                diff[end] -= add;
                sum += add;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxPower(stations []int, r int, k int) int64 {
	n := len(stations)
	cnt := make([]int64, n+1)
	for i := 0; i < n; i++ {
		left := max(0, i-r)
		right := min(n, i+r+1)
		cnt[left] += int64(stations[i])
		cnt[right] -= int64(stations[i])
	}

	minVal := int64(stations[0])
	sumTotal := int64(0)
	for _, s := range stations {
		if int64(s) < minVal {
			minVal = int64(s)
		}
		sumTotal += int64(s)
	}

	lo, hi := minVal, sumTotal+int64(k)
	var res int64 = 0

	for lo <= hi {
		mid := lo + (hi-lo)/2
		if check(cnt, mid, r, k) {
			res = mid
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}
	return res
}

func check(cnt []int64, val int64, r int, k int) bool {
	n := len(cnt) - 1
	diff := make([]int64, len(cnt))
	copy(diff, cnt)
	var sum int64 = 0
	remaining := int64(k)

	for i := 0; i < n; i++ {
		sum += diff[i]
		if sum < val {
			add := val - sum
			if remaining < add {
				return false
			}
			remaining -= add
			end := min(n, i+2*r+1)
			diff[end] -= add
			sum += add
		}
	}

	return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maxPower(int[] stations, int r, int k) {
        int n = stations.length;
        long[] cnt = new long[n + 1];

        for (int i = 0; i < n; i++) {
            int left = Math.max(0, i - r);
            int right = Math.min(n, i + r + 1);
            cnt[left] += stations[i];
            cnt[right] -= stations[i];
        }

        long lo = Arrays.stream(stations).min().getAsInt();
        long hi = Arrays.stream(stations).asLongStream().sum() + k;
        long res = 0;

        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            if (check(cnt, mid, r, k)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }

    private boolean check(long[] cnt, long val, int r, int k) {
        int n = cnt.length - 1;
        long[] diff = cnt.clone();
        long sum = 0;
        long remaining = k;

        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (sum < val) {
                long add = val - sum;
                if (remaining < add) {
                    return false;
                }
                remaining -= add;
                int end = Math.min(n, i + 2 * r + 1);
                diff[end] -= add;
                sum += add;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxPower = function (stations, r, k) {
    const n = stations.length;
    const cnt = new Array(n + 1).fill(0);

    for (let i = 0; i < n; i++) {
        const left = Math.max(0, i - r);
        const right = Math.min(n, i + r + 1);
        cnt[left] += stations[i];
        cnt[right] -= stations[i];
    }

    const check = (val) => {
        const diff = [...cnt];
        let sum = 0;
        let remaining = k;

        for (let i = 0; i < n; i++) {
            sum += diff[i];
            if (sum < val) {
                const add = val - sum;
                if (remaining < add) {
                    return false;
                }
                remaining -= add;
                const end = Math.min(n, i + 2 * r + 1);
                diff[end] -= add;
                sum += add;
            }
        }
        return true;
    };

    let lo = Math.min(...stations);
    let hi = stations.reduce((a, b) => a + b, 0) + k;
    let res = 0;

    while (lo <= hi) {
        const mid = Math.floor(lo + (hi - lo) / 2);
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        n = len(stations)
        cnt = [0] * (n + 1)

        for i in range(n):
            left = max(0, i - r)
            right = min(n, i + r + 1)
            cnt[left] += stations[i]
            cnt[right] -= stations[i]

        def check(val: int) -> bool:
            diff = cnt.copy()
            total = 0
            remaining = k

            for i in range(n):
                total += diff[i]
                if total < val:
                    add = val - total
                    if remaining < add:
                        return False
                    remaining -= add
                    end = min(n, i + 2 * r + 1)
                    diff[end] -= add
                    total += add
            return True

        lo, hi = min(stations), sum(stations) + k
        res = 0
        while lo <= hi:
            mid = (lo + hi) // 2
            if check(mid):
                res = mid
                lo = mid + 1
            else:
                hi = mid - 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxPower(stations: number[], r: number, k: number): number {
    const n: number = stations.length;
    const cnt: number[] = new Array(n + 1).fill(0);

    for (let i = 0; i < n; i++) {
        const left: number = Math.max(0, i - r);
        const right: number = Math.min(n, i + r + 1);
        cnt[left] += stations[i];
        cnt[right] -= stations[i];
    }

    const check = (val: number): boolean => {
        const diff: number[] = [...cnt];
        let sum: number = 0;
        let remaining: number = k;

        for (let i = 0; i < n; i++) {
            sum += diff[i];
            if (sum < val) {
                const add: number = val - sum;
                if (remaining < add) {
                    return false;
                }
                remaining -= add;
                const end: number = Math.min(n, i + 2 * r + 1);
                diff[end] -= add;
                sum += add;
            }
        }
        return true;
    };

    let lo: number = Math.min(...stations);
    let hi: number = stations.reduce((a, b) => a + b, 0) + k;
    let res: number = 0;

    while (lo <= hi) {
        const mid: number = Math.floor(lo + (hi - lo) / 2);
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return res;
}
```

</details>
