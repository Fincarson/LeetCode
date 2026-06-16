# 3443. Maximum Manhattan Distance After K Changes

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/)  
`Hash Table` `Math` `String` `Counting`

**Problem Link:** [LeetCode 3443 - Maximum Manhattan Distance After K Changes](https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/)

## Problem

You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:

- 'N' : Move north by 1 unit.
- 'S' : Move south by 1 unit.
- 'E' : Move east by 1 unit.
- 'W' : Move west by 1 unit.

Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.

Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 105
- 0 <= k <= s.length
- s consists of only 'N', 'S', 'E', and 'W'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [As Far from Land as Possible](https://leetcode.com/problems/as-far-from-land-as-possible/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3443. Maximum Manhattan Distance After K Changes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Step-by-step Solution | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Overall Solution | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Step-by-step Solution

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int count(int drt1, int drt2, int times) {
    return abs(drt1 - drt2) + times * 2;
}  // Calculate modified Manhattan distance

int maxDistance(char* s, int k) {
    int ans = 0;
    int north = 0, south = 0, east = 0, west = 0;
    for (char* p = s; *p != '\0'; p++) {
        char it = *p;
        switch (it) {
            case 'N':
                north++;
                break;
            case 'S':
                south++;
                break;
            case 'E':
                east++;
                break;
            case 'W':
                west++;
                break;
        }

        int times1 =
            fmin(fmin(north, south), k);  // modification times for N and S
        int times2 = fmin(fmin(east, west),
                          k - times1);  // modification times for E and W
        int current = count(north, south, times1) + count(east, west, times2);
        if (current > ans) {
            ans = current;
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
    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;
        for (char it : s) {
            switch (it) {
                case 'N':
                    north++;
                    break;
                case 'S':
                    south++;
                    break;
                case 'E':
                    east++;
                    break;
                case 'W':
                    west++;
                    break;
            }
            int times1 =
                min({north, south, k});  // modification times for N and S
            int times2 = min(
                {east, west, k - times1});  // modification times for E and W
            ans = max(ans,
                      count(north, south, times1) + count(east, west, times2));
        }
        return ans;
    }

    int count(int drt1, int drt2, int times) {
        return abs(drt1 - drt2) + times * 2;
    }  // Calculate modified Manhattan distance
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;
        foreach (char it in s) {
            switch (it) {
                case 'N':
                    north++;
                    break;
                case 'S':
                    south++;
                    break;
                case 'E':
                    east++;
                    break;
                case 'W':
                    west++;
                    break;
            }
            int times1 = Math.Min(Math.Min(north, south),
                                  k);  // modification times for N and S
            int times2 =
                Math.Min(Math.Min(east, west),
                         k - times1);  // modification times for E and W
            ans = Math.Max(
                ans, Count(north, south, times1) + Count(east, west, times2));
        }
        return ans;
    }

    private int Count(int drt1, int drt2, int times) {
        return Math.Abs(drt1 - drt2) +
               times * 2;  // Calculate modified Manhattan distance
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDistance(s string, k int) int {
    ans := 0
    north, south, east, west := 0, 0, 0, 0
    count := func(drt1, drt2, times int) int {
        return int(math.Abs(float64(drt1 - drt2))) + times * 2
    } // Calculate modified Manhattan distance

    for _, it := range s {
        switch it {
        case 'N':
            north++
        case 'S':
            south++
        case 'E':
            east++
        case 'W':
            west++
        }
        times1 := min(min(north, south), k)        // modification times for N and S
        times2 := min(min(east, west), k - times1)   // modification times for E and W
        current := count(north, south, times1) + count(east, west, times2)
        if current > ans {
            ans = current
        }
    }
    
    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maxDistance(String s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;
        for (char it : s.toCharArray()) {
            switch (it) {
                case 'N':
                    north++;
                    break;
                case 'S':
                    south++;
                    break;
                case 'E':
                    east++;
                    break;
                case 'W':
                    west++;
                    break;
            }
            int times1 = Math.min(Math.min(north, south), k); // modification times for N and S
            int times2 = Math.min(Math.min(east, west), k - times1); // modification times for E and W
            ans = Math.max(
                ans,
                count(north, south, times1) + count(east, west, times2)
            );
        }
        return ans;
    }

    private int count(int drt1, int drt2, int times) {
        return Math.abs(drt1 - drt2) + times * 2; // Calculate modified Manhattan distance
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDistance = function (s, k) {
    let ans = 0;
    let north = 0,
        south = 0,
        east = 0,
        west = 0;
    for (const it of s) {
        switch (it) {
            case "N":
                north++;
                break;
            case "S":
                south++;
                break;
            case "E":
                east++;
                break;
            case "W":
                west++;
                break;
        }

        const count = (drt1, drt2, times) => {
            return Math.abs(drt1 - drt2) + times * 2; // Calculate modified Manhattan distance
        };

        let times1 = Math.min(north, south, k); // modification times for N and S
        let times2 = Math.min(east, west, k - times1); // modification times for E and W
        ans = Math.max(
            ans,
            count(north, south, times1) + count(east, west, times2),
        );
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        ans = 0
        north = south = east = west = 0
        for it in s:
            if it == "N":
                north += 1
            elif it == "S":
                south += 1
            elif it == "E":
                east += 1
            elif it == "W":
                west += 1
            times1 = min(north, south, k)  # modification times for N and S
            times2 = min(
                east, west, k - times1
            )  # modification times for E and W
            ans = max(
                ans,
                self.count(north, south, times1)
                + self.count(east, west, times2),
            )
        return ans

    def count(self, drt1: int, drt2: int, times: int) -> int:
        return (
            abs(drt1 - drt2) + times * 2
        )  # Calculate modified Manhattan distance
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDistance(s: string, k: number): number {
    let ans = 0;
    let north = 0,
        south = 0,
        east = 0,
        west = 0;
    for (const it of s) {
        switch (it) {
            case "N":
                north++;
                break;
            case "S":
                south++;
                break;
            case "E":
                east++;
                break;
            case "W":
                west++;
                break;
        }
        const times1 = Math.min(north, south, k); // modification times for N and S
        const times2 = Math.min(east, west, k - times1); // modification times for E and W
        const current = count(north, south, times1) + count(east, west, times2);
        ans = Math.max(ans, current);
    }
    return ans;
}

function count(drt1: number, drt2: number, times: number): number {
    return Math.abs(drt1 - drt2) + times * 2;
} // Calculate modified Manhattan distance
```

</details>

<br>

## Approach 2: Overall Solution

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxDistance(char* s, int k) {
    int latitude = 0, longitude = 0, ans = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'N':
                latitude++;
                break;
            case 'S':
                latitude--;
                break;
            case 'E':
                longitude++;
                break;
            case 'W':
                longitude--;
                break;
        }
        ans = fmax(ans, fmin(abs(latitude) + abs(longitude) + k * 2, i + 1));
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
    int maxDistance(string s, int k) {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'N':
                    latitude++;
                    break;
                case 'S':
                    latitude--;
                    break;
                case 'E':
                    longitude++;
                    break;
                case 'W':
                    longitude--;
                    break;
            }
            ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1));
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxDistance(string s, int k) {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.Length;
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'N':
                    latitude++;
                    break;
                case 'S':
                    latitude--;
                    break;
                case 'E':
                    longitude++;
                    break;
                case 'W':
                    longitude--;
                    break;
            }
            ans = Math.Max(
                ans, Math.Min(Math.Abs(latitude) + Math.Abs(longitude) + k * 2,
                              i + 1));
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDistance(s string, k int) int {
	latitude, longitude, ans := 0, 0, 0
	n := len(s)
	for i := 0; i < n; i++ {
		switch s[i] {
		case 'N':
			latitude++
		case 'S':
			latitude--
		case 'E':
			longitude++
		case 'W':
			longitude--
		}
		ans = max(ans, min(abs(latitude)+abs(longitude)+k*2, i+1))
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maxDistance(String s, int k) {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            switch (c) {
                case 'N':
                    latitude++;
                    break;
                case 'S':
                    latitude--;
                    break;
                case 'E':
                    longitude++;
                    break;
                case 'W':
                    longitude--;
                    break;
            }
            ans = Math.max(
                ans,
                Math.min(
                    Math.abs(latitude) + Math.abs(longitude) + k * 2,
                    i + 1
                )
            );
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDistance = function (s, k) {
    let latitude = 0,
        longitude = 0,
        ans = 0;
    const n = s.length;
    for (let i = 0; i < n; i++) {
        switch (s[i]) {
            case "N":
                latitude++;
                break;
            case "S":
                latitude--;
                break;
            case "E":
                longitude++;
                break;
            case "W":
                longitude--;
                break;
        }
        ans = Math.max(
            ans,
            Math.min(Math.abs(latitude) + Math.abs(longitude) + k * 2, i + 1),
        );
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        latitude = 0
        longitude = 0
        ans = 0
        n = len(s)
        for i in range(n):
            if s[i] == "N":
                latitude += 1
            elif s[i] == "S":
                latitude -= 1
            elif s[i] == "E":
                longitude += 1
            elif s[i] == "W":
                longitude -= 1
            ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1))
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDistance(s: string, k: number): number {
    let latitude = 0,
        longitude = 0,
        ans = 0;
    const n = s.length;
    for (let i = 0; i < n; i++) {
        switch (s[i]) {
            case "N":
                latitude++;
                break;
            case "S":
                latitude--;
                break;
            case "E":
                longitude++;
                break;
            case "W":
                longitude--;
                break;
        }
        ans = Math.max(
            ans,
            Math.min(Math.abs(latitude) + Math.abs(longitude) + k * 2, i + 1),
        );
    }
    return ans;
}
```

</details>
