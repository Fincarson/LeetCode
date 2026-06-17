# 2211. Count Collisions on a Road

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-collisions-on-a-road/)  
`String` `Stack` `Simulation`

**Problem Link:** [LeetCode 2211 - Count Collisions on a Road](https://leetcode.com/problems/count-collisions-on-a-road/)

## Problem

There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 from left to right and each car is present at a unique point.

You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' denoting whether the ith car is moving towards the left, towards the right, or staying at its current point respectively. Each moving car has the same speed.

The number of collisions can be calculated as follows:

- When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
- When a moving car collides with a stationary car, the number of collisions increases by 1.

After a collision, the cars involved can no longer move and will stay at the point where they collided. Other than that, cars cannot change their state or direction of motion.

Return the total number of collisions that will happen on the road.

### Example 1

```text
Input: directions = "RLRSLL"
Output: 5
Explanation:
The collisions that will happen on the road are:
- Cars 0 and 1 will collide with each other. Since they are moving in opposite directions, the number of collisions becomes 0 + 2 = 2.
- Cars 2 and 3 will collide with each other. Since car 3 is stationary, the number of collisions becomes 2 + 1 = 3.
- Cars 3 and 4 will collide with each other. Since car 3 is stationary, the number of collisions becomes 3 + 1 = 4.
- Cars 4 and 5 will collide with each other. After car 4 collides with car 3, it will stay at the point of collision and get hit by car 5. The number of collisions becomes 4 + 1 = 5.
Thus, the total number of collisions that will happen on the road is 5.
```

### Example 2

```text
Input: directions = "LLRR"
Output: 0
Explanation:
No cars will collide with each other. Thus, the total number of collisions that will happen on the road is 0.
```

## Constraints

- 1 <= directions.length <= 105
- directions[i] is either 'L', 'R', or 'S'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Asteroid Collision](https://leetcode.com/problems/asteroid-collision/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Car Fleet](https://leetcode.com/problems/car-fleet/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Last Moment Before All Ants Fall Out of a Plank](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Car Fleet II](https://leetcode.com/problems/car-fleet-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2211. Count Collisions on a Road

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Counting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countCollisions(char* directions) {
    int res = 0;
    int flag = -1;

    for (int i = 0; directions[i] != '\0'; i++) {
        char c = directions[i];
        if (c == 'L') {
            if (flag >= 0) {
                res += flag + 1;
                flag = 0;
            }
        } else if (c == 'S') {
            if (flag > 0) {
                res += flag;
            }
            flag = 0;
        } else {
            if (flag >= 0) {
                flag++;
            } else {
                flag = 1;
            }
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
    int countCollisions(string directions) {
        int res = 0;
        int flag = -1;
        for (auto c : directions) {
            if (c == 'L') {
                if (flag >= 0) {
                    res += flag + 1;
                    flag = 0;
                }
            } else if (c == 'S') {
                if (flag > 0) {
                    res += flag;
                }
                flag = 0;
            } else {
                if (flag >= 0) {
                    flag++;
                } else {
                    flag = 1;
                }
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
    public int CountCollisions(string directions) {
        int res = 0;
        int flag = -1;
        foreach (char c in directions) {
            if (c == 'L') {
                if (flag >= 0) {
                    res += flag + 1;
                    flag = 0;
                }
            } else if (c == 'S') {
                if (flag > 0) {
                    res += flag;
                }
                flag = 0;
            } else {
                if (flag >= 0) {
                    flag++;
                } else {
                    flag = 1;
                }
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
func countCollisions(directions string) int {
	res := 0
	flag := -1
	for _, c := range directions {
		if c == 'L' {
			if flag >= 0 {
				res += flag + 1
				flag = 0
			}
		} else if c == 'S' {
			if flag > 0 {
				res += flag
			}
			flag = 0
		} else {
			if flag >= 0 {
				flag++
			} else {
				flag = 1
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

    public int countCollisions(String directions) {
        int res = 0;
        int flag = -1;
        for (char c : directions.toCharArray()) {
            if (c == 'L') {
                if (flag >= 0) {
                    res += flag + 1;
                    flag = 0;
                }
            } else if (c == 'S') {
                if (flag > 0) {
                    res += flag;
                }
                flag = 0;
            } else {
                if (flag >= 0) {
                    flag++;
                } else {
                    flag = 1;
                }
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
var countCollisions = function (directions) {
    let res = 0;
    let flag = -1;
    for (let i = 0; i < directions.length; i++) {
        const c = directions[i];
        if (c === "L") {
            if (flag >= 0) {
                res += flag + 1;
                flag = 0;
            }
        } else if (c === "S") {
            if (flag > 0) {
                res += flag;
            }
            flag = 0;
        } else {
            if (flag >= 0) {
                flag++;
            } else {
                flag = 1;
            }
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
    def countCollisions(self, directions: str) -> int:
        res = 0
        flag = -1

        for c in directions:
            if c == "L":
                if flag >= 0:
                    res += flag + 1
                    flag = 0
            elif c == "S":
                if flag > 0:
                    res += flag
                flag = 0
            else:
                if flag >= 0:
                    flag += 1
                else:
                    flag = 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countCollisions(directions: string): number {
    let res: number = 0;
    let flag: number = -1;
    for (let i = 0; i < directions.length; i++) {
        const c: string = directions[i];
        if (c === "L") {
            if (flag >= 0) {
                res += flag + 1;
                flag = 0;
            }
        } else if (c === "S") {
            if (flag > 0) {
                res += flag;
            }
            flag = 0;
        } else {
            if (flag >= 0) {
                flag++;
            } else {
                flag = 1;
            }
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: Counting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countCollisions(char* directions) {
    int n = strlen(directions);
    int l = 0, r = n - 1;

    while (l < n && directions[l] == 'L') {
        l++;
    }

    while (r >= l && directions[r] == 'R') {
        r--;
    }

    int res = 0;
    for (int i = l; i <= r; i++) {
        if (directions[i] != 'S') {
            res++;
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
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0, r = n - 1;

        while (l < n && directions[l] == 'L') {
            l++;
        }

        while (r >= l && directions[r] == 'R') {
            r--;
        }

        int res = 0;
        for (int i = l; i <= r; i++) {
            if (directions[i] != 'S') {
                res++;
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
    public int CountCollisions(string directions) {
        int n = directions.Length;
        int l = 0, r = n - 1;

        while (l < n && directions[l] == 'L') {
            l++;
        }

        while (r >= l && directions[r] == 'R') {
            r--;
        }

        int res = 0;
        for (int i = l; i <= r; i++) {
            if (directions[i] != 'S') {
                res++;
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
func countCollisions(directions string) int {
	n := len(directions)
	l, r := 0, n-1

	for l < n && directions[l] == 'L' {
		l++
	}

	for r >= l && directions[r] == 'R' {
		r--
	}

	res := 0
	for i := l; i <= r; i++ {
		if directions[i] != 'S' {
			res++
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

    public int countCollisions(String directions) {
        int n = directions.length();
        int l = 0;
        int r = n - 1;

        while (l < n && directions.charAt(l) == 'L') {
            l++;
        }

        while (r >= l && directions.charAt(r) == 'R') {
            r--;
        }

        int res = 0;
        for (int i = l; i <= r; i++) {
            if (directions.charAt(i) != 'S') {
                res++;
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
var countCollisions = function (directions) {
    const n = directions.length;
    let l = 0,
        r = n - 1;

    while (l < n && directions[l] === "L") {
        l++;
    }

    while (r >= l && directions[r] === "R") {
        r--;
    }

    let res = 0;
    for (let i = l; i <= r; i++) {
        if (directions[i] !== "S") {
            res++;
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
    def countCollisions(self, directions: str) -> int:
        dirs = directions.lstrip("L").rstrip("R")
        return len(dirs) - dirs.count("S")
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countCollisions(directions: string): number {
    const n: number = directions.length;
    let l: number = 0,
        r: number = n - 1;

    while (l < n && directions[l] === "L") {
        l++;
    }

    while (r >= l && directions[r] === "R") {
        r--;
    }

    let res: number = 0;
    for (let i = l; i <= r; i++) {
        if (directions[i] !== "S") {
            res++;
        }
    }
    return res;
}
```

</details>
