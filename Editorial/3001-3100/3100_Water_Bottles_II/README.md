# 3100. Water Bottles II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/water-bottles-ii/)  
`Math` `Simulation`

**Problem Link:** [LeetCode 3100 - Water Bottles II](https://leetcode.com/problems/water-bottles-ii/)

## Problem

You are given two integers numBottles and numExchange.

numBottles represents the number of full water bottles that you initially have. In one operation, you can perform one of the following operations:

- Drink any number of full water bottles turning them into empty bottles.
- Exchange numExchange empty bottles with one full water bottle. Then, increase numExchange by one.

Note that you cannot exchange multiple batches of empty bottles for the same value of numExchange. For example, if numBottles == 3 and numExchange == 1, you cannot exchange 3 empty water bottles for 3 full bottles.

Return the maximum number of water bottles you can drink.

### Example 1

```text
Input: numBottles = 13, numExchange = 6
Output: 15
Explanation: The table above shows the number of full water bottles, empty water bottles, the value of numExchange, and the number of bottles drunk.
```

### Example 2

```text
Input: numBottles = 10, numExchange = 3
Output: 13
Explanation: The table above shows the number of full water bottles, empty water bottles, the value of numExchange, and the number of bottles drunk.
```

## Constraints

- 1 <= numBottles <= 100
- 1 <= numExchange <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Water Bottles](https://leetcode.com/problems/water-bottles/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3100. Water Bottles II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxBottlesDrunk(int numBottles, int numExchange) {
    int ans = numBottles;
    int empty = numBottles;
    while (empty >= numExchange) {
        ans++;
        empty -= numExchange - 1;
        numExchange++;
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
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        for (int empty = numBottles; empty >= numExchange; numExchange++) {
            ans++;
            empty -= numExchange - 1;
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
    public int MaxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            ans++;
            empty -= numExchange - 1;
            numExchange++;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxBottlesDrunk(numBottles int, numExchange int) int {
	ans := numBottles
	for empty := numBottles; empty >= numExchange; numExchange++ {
		ans++
		empty -= numExchange - 1
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        for (int empty = numBottles; empty >= numExchange; numExchange++) {
            ans++;
            empty -= numExchange - 1;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxBottlesDrunk = function (numBottles, numExchange) {
    let ans = numBottles;
    let empty = numBottles;
    while (empty >= numExchange) {
        ans++;
        empty -= numExchange - 1;
        numExchange++;
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles
        empty = numBottles
        while empty >= numExchange:
            ans += 1
            empty -= numExchange - 1
            numExchange += 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxBottlesDrunk(numBottles: number, numExchange: number): number {
    let ans = numBottles;
    let empty = numBottles;
    while (empty >= numExchange) {
        ans++;
        empty -= numExchange - 1;
        numExchange++;
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxBottlesDrunk(int numBottles, int numExchange) {
    int a = 1;
    int b = 2 * numExchange - 3;
    int c = -2 * numBottles;
    double delta = (double)b * b - 4.0 * a * c;
    int t = (int)ceil((-b + sqrt(delta)) / (2.0 * a));
    return numBottles + t - 1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int a = 1;
        int b = 2 * numExchange - 3;
        int c = -2 * numBottles;
        double delta = (double)b * b - 4.0 * a * c;
        int t = (int)ceil((-b + sqrt(delta)) / (2.0 * a));
        return numBottles + t - 1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxBottlesDrunk(int numBottles, int numExchange) {
        int a = 1;
        int b = 2 * numExchange - 3;
        int c = -2 * numBottles;
        double delta = (double)b * b - 4.0 * a * c;
        int t = (int)Math.Ceiling((-b + Math.Sqrt(delta)) / (2.0 * a));
        return numBottles + t - 1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxBottlesDrunk(numBottles int, numExchange int) int {
	a := 1
	b := 2*numExchange - 3
	c := -2 * numBottles
	delta := float64(b*b - 4*a*c)
	t := int(math.Ceil((-float64(b) + math.Sqrt(delta)) / (2.0 * float64(a))))
	return numBottles + t - 1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int t = 0;
        int empty = t * numExchange + (t * (t - 1)) / 2;
        int total = numBottles + t;
        int a = 1;
        int b = 2 * numExchange - 3;
        int c = -2 * numBottles;
        t = (int) Math.ceil(((-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a)));
        return numBottles + t - 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxBottlesDrunk = function (numBottles, numExchange) {
    let a = 1;
    let b = 2 * numExchange - 3;
    let c = -2 * numBottles;
    let delta = b * b - 4 * a * c;
    let t = Math.ceil((-b + Math.sqrt(delta)) / (2 * a));
    return numBottles + t - 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        a = 1
        b = 2 * numExchange - 3
        c = -2 * numBottles
        delta = b * b - 4 * a * c
        t = math.ceil((-b + math.sqrt(delta)) / (2 * a))
        return numBottles + t - 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxBottlesDrunk(numBottles: number, numExchange: number): number {
    let a = 1;
    let b = 2 * numExchange - 3;
    let c = -2 * numBottles;
    let delta = b * b - 4 * a * c;
    let t = Math.ceil((-b + Math.sqrt(delta)) / (2 * a));
    return numBottles + t - 1;
}
```

</details>
