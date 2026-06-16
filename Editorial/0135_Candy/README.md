# 135. Candy

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/candy/)  
`Array` `Greedy`

**Problem Link:** [LeetCode 135 - Candy](https://leetcode.com/problems/candy/)

## Problem

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies to the children.

### Example 1

```text
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
```

### Example 2

```text
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
```

## Constraints

- n == ratings.length
- 1 <= n <= 2 * 104
- 0 <= ratings[i] <= 2 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimize Maximum Value in a Grid](https://leetcode.com/problems/minimize-maximum-value-in-a-grid/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Number of Operations to Satisfy Conditions](https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Check if Grid Satisfies Conditions](https://leetcode.com/problems/check-if-grid-satisfies-conditions/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 135. Candy

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using two arrays | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using one array | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Single Pass Approach with Constant Space | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int candy(int* ratings, int ratingsSize) {
    int* candies = (int*)malloc(ratingsSize * sizeof(int));
    for (int i = 0; i < ratingsSize; i++) {
        candies[i] = 1;  // Initialize all elements to 1 as in Arrays.fill
    }

    bool hasChanged = true;
    while (hasChanged) {
        hasChanged = false;
        for (int i = 0; i < ratingsSize; i++) {
            if (i != ratingsSize - 1 && ratings[i] > ratings[i + 1] &&
                candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
                hasChanged = true;
            }
            if (i > 0 && ratings[i] > ratings[i - 1] &&
                candies[i] <= candies[i - 1]) {
                candies[i] = candies[i - 1] + 1;
                hasChanged = true;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < ratingsSize; i++) {
        sum += candies[i];
    }

    free(candies);  // Free the allocated memory
    return sum;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        bool hasChanged = true;
        while (hasChanged) {
            hasChanged = false;
            for (int i = 0; i < ratings.size(); i++) {
                if (i != ratings.size() - 1 && ratings[i] > ratings[i + 1] &&
                    candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    hasChanged = true;
                }
                if (i > 0 && ratings[i] > ratings[i - 1] &&
                    candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    hasChanged = true;
                }
            }
        }
        int sum = 0;
        for (int candy : candies) {
            sum += candy;
        }
        return sum;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int Candy(int[] ratings) {
        int[] candies = new int[ratings.Length];
        for (int i = 0; i < candies.Length; i++) candies[i] = 1;
        bool hasChanged = true;
        while (hasChanged) {
            hasChanged = false;
            for (int i = 0; i < ratings.Length; i++) {
                if (i != ratings.Length - 1 && ratings[i] > ratings[i + 1] &&
                    candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    hasChanged = true;
                }

                if (i > 0 && ratings[i] > ratings[i - 1] &&
                    candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    hasChanged = true;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < candies.Length; i++) {
            sum += candies[i];
        }

        return sum;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func candy(ratings []int) int {
    candies := make([]int, len(ratings))
    for i := range candies {
        candies[i] = 1
    }
    hasChanged := true
    for hasChanged {
        hasChanged = false
        for i := 0; i < len(ratings); i++ {
            if i != len(ratings)-1 && ratings[i] > ratings[i+1] &&
                candies[i] <= candies[i+1] {
                candies[i] = candies[i+1] + 1
                hasChanged = true
            }
            if i > 0 && ratings[i] > ratings[i-1] &&
                candies[i] <= candies[i-1] {
                candies[i] = candies[i-1] + 1
                hasChanged = true
            }
        }
    }
    sum := 0
    for _, candy := range candies {
        sum += candy
    }
    return sum
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        Arrays.fill(candies, 1);
        boolean hasChanged = true;
        while (hasChanged) {
            hasChanged = false;
            for (int i = 0; i < ratings.length; i++) {
                if (
                    i != ratings.length - 1 &&
                    ratings[i] > ratings[i + 1] &&
                    candies[i] <= candies[i + 1]
                ) {
                    candies[i] = candies[i + 1] + 1;
                    hasChanged = true;
                }
                if (
                    i > 0 &&
                    ratings[i] > ratings[i - 1] &&
                    candies[i] <= candies[i - 1]
                ) {
                    candies[i] = candies[i - 1] + 1;
                    hasChanged = true;
                }
            }
        }
        int sum = 0;
        for (int candy : candies) {
            sum += candy;
        }
        return sum;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var candy = function (ratings) {
    let candies = new Array(ratings.length).fill(1);
    let hasChanged = true;
    while (hasChanged) {
        hasChanged = false;
        for (let i = 0; i < ratings.length; i++) {
            if (
                i !== ratings.length - 1 &&
                ratings[i] > ratings[i + 1] &&
                candies[i] <= candies[i + 1]
            ) {
                candies[i] = candies[i + 1] + 1;
                hasChanged = true;
            }
            if (
                i > 0 &&
                ratings[i] > ratings[i - 1] &&
                candies[i] <= candies[i - 1]
            ) {
                candies[i] = candies[i - 1] + 1;
                hasChanged = true;
            }
        }
    }
    return candies.reduce((a, b) => a + b, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        candies = [1] * len(ratings)
        hasChanged = True
        while hasChanged:
            hasChanged = False
            for i in range(len(ratings)):
                if (
                    i != len(ratings) - 1
                    and ratings[i] > ratings[i + 1]
                    and candies[i] <= candies[i + 1]
                ):
                    candies[i] = candies[i + 1] + 1
                    hasChanged = True
                if (
                    i > 0
                    and ratings[i] > ratings[i - 1]
                    and candies[i] <= candies[i - 1]
                ):
                    candies[i] = candies[i - 1] + 1
                    hasChanged = True
        return sum(candies)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function candy(ratings: number[]): number {
    let candies = new Array(ratings.length).fill(1);
    let hasChanged = true;
    while (hasChanged) {
        hasChanged = false;
        for (let i = 0; i < ratings.length; i++) {
            if (
                i !== ratings.length - 1 &&
                ratings[i] > ratings[i + 1] &&
                candies[i] <= candies[i + 1]
            ) {
                candies[i] = candies[i + 1] + 1;
                hasChanged = true;
            }
            if (
                i > 0 &&
                ratings[i] > ratings[i - 1] &&
                candies[i] <= candies[i - 1]
            ) {
                candies[i] = candies[i - 1] + 1;
                hasChanged = true;
            }
        }
    }
    return candies.reduce((a, b) => a + b, 0);
}
```

</details>

<br>

## Approach 2: Using two arrays

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int candy(int* ratings, int ratingsSize) {
    int sum = 0;
    int* left2right = (int*)malloc(ratingsSize * sizeof(int));
    int* right2left = (int*)malloc(ratingsSize * sizeof(int));

    // Initialize arrays with 1s
    for (int i = 0; i < ratingsSize; i++) {
        left2right[i] = 1;
        right2left[i] = 1;
    }

    // Calculate candies from left to right
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left2right[i] = left2right[i - 1] + 1;
        }
    }

    // Calculate candies from right to left
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            right2left[i] = right2left[i + 1] + 1;
        }
    }

    // Calculate the total candies to distribute
    for (int i = 0; i < ratingsSize; i++) {
        sum += (left2right[i] > right2left[i]) ? left2right[i] : right2left[i];
    }

    // Free the allocated memory
    free(left2right);
    free(right2left);

    return sum;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        vector<int> left2right(ratings.size(), 1);
        vector<int> right2left(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i + 1] + 1;
            }
        }
        for (int i = 0; i < ratings.size(); i++) {
            sum += max(left2right[i], right2left[i]);
        }
        return sum;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int Candy(int[] ratings) {
        int sum = 0;
        int length = ratings.Length;
        int[] left2right = Enumerable.Repeat(1, length).ToArray();
        int[] right2left = Enumerable.Repeat(1, length).ToArray();
        for (int i = 1; i < length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }

        for (int i = length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i + 1] + 1;
            }
        }

        for (int i = 0; i < length; i++) {
            sum += Math.Max(left2right[i], right2left[i]);
        }

        return sum;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func candy(ratings []int) int {
    sum := 0
    n := len(ratings)
    left2right := make([]int, n)
    right2left := make([]int, n)
    for i := range left2right {
        left2right[i] = 1
    }
    for i := range right2left {
        right2left[i] = 1
    }
    for i := 1; i < n; i++ {
        if ratings[i] > ratings[i-1] {
            left2right[i] = left2right[i-1] + 1
        }
    }
    for i := n - 2; i >= 0; i-- {
        if ratings[i] > ratings[i+1] {
            right2left[i] = right2left[i+1] + 1
        }
    }
    for i := 0; i < n; i++ {
        sum += max(left2right[i], right2left[i])
    }
    return sum
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int candy(int[] ratings) {
        int sum = 0;
        int[] left2right = new int[ratings.length];
        int[] right2left = new int[ratings.length];
        Arrays.fill(left2right, 1);
        Arrays.fill(right2left, 1);
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i + 1] + 1;
            }
        }
        for (int i = 0; i < ratings.length; i++) {
            sum += Math.max(left2right[i], right2left[i]);
        }
        return sum;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var candy = function (ratings) {
    var sum = 0;
    var len = ratings.length;
    var left2right = new Array(len).fill(1);
    var right2left = new Array(len).fill(1);
    for (var i = 1; i < len; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left2right[i] = left2right[i - 1] + 1;
        }
    }
    for (var i = len - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            right2left[i] = right2left[i + 1] + 1;
        }
    }
    for (var i = 0; i < len; i++) {
        sum += Math.max(left2right[i], right2left[i]);
    }
    return sum;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        sum = 0
        n = len(ratings)
        left2right = [1] * n
        right2left = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                left2right[i] = left2right[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right2left[i] = right2left[i + 1] + 1
        for i in range(n):
            sum += max(left2right[i], right2left[i])
        return sum
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function candy(ratings: number[]): number {
    let sum = 0;
    const len = ratings.length;
    const left2right = new Array(len).fill(1);
    const right2left = new Array(len).fill(1);
    for (let i = 1; i < len; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left2right[i] = left2right[i - 1] + 1;
        }
    }
    for (let i = len - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            right2left[i] = right2left[i + 1] + 1;
        }
    }
    for (let i = 0; i < len; i++) {
        sum += Math.max(left2right[i], right2left[i]);
    }
    return sum;
}
```

</details>

<br>

## Approach 3: Using one array

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int candy(int* ratings, int ratingsSize) {
    int* candies = (int*)malloc(ratingsSize * sizeof(int));
    for (int i = 0; i < ratingsSize; i++) {
        candies[i] = 1;
    }
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    int sum = candies[ratingsSize - 1];
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
            candies[i] = candies[i + 1] + 1;
        }
        sum += candies[i];
    }
    free(candies);
    return sum;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int sum = candies.back();
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }
        return sum;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int Candy(int[] ratings) {
        int[] candies = new int[ratings.Length];
        for (int i = 0; i < candies.Length; i++) candies[i] = 1;
        for (int i = 1; i < ratings.Length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        int sum = candies[candies.Length - 1];
        for (int i = ratings.Length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.Max(candies[i], candies[i + 1] + 1);
            }

            sum += candies[i];
        }

        return sum;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func candy(ratings []int) int {
    candies := make([]int, len(ratings))
    for i := range candies {
        candies[i] = 1
    }
    for i := 1; i < len(ratings); i++ {
        if ratings[i] > ratings[i-1] {
            candies[i] = candies[i-1] + 1
        }
    }
    sum := candies[len(candies)-1]
    for i := len(ratings) - 2; i >= 0; i-- {
        if ratings[i] > ratings[i+1] {
            candies[i] = max(candies[i], candies[i+1]+1)
        }
        sum += candies[i]
    }
    return sum
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        Arrays.fill(candies, 1);
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int sum = candies[ratings.length - 1];
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }
        return sum;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var candy = function (ratings) {
    let candies = Array(ratings.length).fill(1);
    for (let i = 1; i < ratings.length; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    let sum = candies[candies.length - 1];
    for (let i = ratings.length - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = Math.max(candies[i], candies[i + 1] + 1);
        }
        sum += candies[i];
    }
    return sum;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def candy(self, ratings):
        candies = [1] * len(ratings)
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
        sum = candies[-1]
        for i in range(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)
            sum += candies[i]
        return sum
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function candy(ratings: number[]): number {
    let candies: number[] = Array(ratings.length).fill(1);
    for (let i = 1; i < ratings.length; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    let sum: number = candies[candies.length - 1];
    for (let i = ratings.length - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = Math.max(candies[i], candies[i + 1] + 1);
        }
        sum += candies[i];
    }
    return sum;
}
```

</details>

<br>

## Approach 4: Single Pass Approach with Constant Space

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Function to calculate sum of first n natural numbers
int count(int n) { return (n * (n + 1)) / 2; }
int max(int a, int b) { return ((a) > (b) ? (a) : (b)); }
int candy(int* ratings, int ratingsSize) {
    if (ratingsSize <= 1) {
        return ratingsSize;
    }
    int candies = 0;
    int up = 0;
    int down = 0;
    int oldSlope = 0;
    for (int i = 1; i < ratingsSize; i++) {
        int newSlope = (ratings[i] > ratings[i - 1])
                           ? 1
                           : ((ratings[i] < ratings[i - 1]) ? -1 : 0);
        // slope is changing from uphill to flat or downhill
        // or from downhill to flat or uphill
        if ((oldSlope > 0 && newSlope == 0) ||
            (oldSlope < 0 && newSlope >= 0)) {
            candies += count(up) + count(down) + max(up, down);
            up = 0;
            down = 0;
        }
        // slope is uphill
        if (newSlope > 0) {
            up++;
        }
        // slope is downhill
        else if (newSlope < 0) {
            down++;
        }
        // slope is flat
        else {
            candies++;
        }
        oldSlope = newSlope;
    }
    candies += count(up) + count(down) + max(up, down) + 1;
    return candies;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Function to calculate sum of first n natural numbers
    int count(int n) { return (n * (n + 1)) / 2; }
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1) {
            return ratings.size();
        }
        int candies = 0;
        int up = 0;
        int down = 0;
        int oldSlope = 0;
        for (int i = 1; i < ratings.size(); i++) {
            int newSlope = (ratings[i] > ratings[i - 1])
                               ? 1
                               : (ratings[i] < ratings[i - 1] ? -1 : 0);
            // slope is changing from uphill to flat or downhill
            // or from downhill to flat or uphill
            if ((oldSlope > 0 && newSlope == 0) ||
                (oldSlope < 0 && newSlope >= 0)) {
                candies += count(up) + count(down) + max(up, down);
                up = 0;
                down = 0;
            }
            // slope is uphill
            if (newSlope > 0) {
                up++;
            }
            // slope is downhill
            else if (newSlope < 0) {
                down++;
            }
            // slope is flat
            else {
                candies++;
            }
            oldSlope = newSlope;
        }
        candies += count(up) + count(down) + max(up, down) + 1;
        return candies;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    // Function to calculate sum of first n natural numbers
    public int count(int n) {
        return (n * (n + 1)) / 2;
    }

    public int Candy(int[] ratings) {
        if (ratings.Length <= 1) {
            return ratings.Length;
        }

        int candies = 0;
        int up = 0;
        int down = 0;
        int oldSlope = 0;
        for (int i = 1; i < ratings.Length; i++) {
            int newSlope = (ratings[i] > ratings[i - 1])
                               ? 1
                               : (ratings[i] < ratings[i - 1] ? -1 : 0);
            if ((oldSlope > 0 && newSlope == 0) ||
                (oldSlope < 0 && newSlope >= 0)) {
                candies += count(up) + count(down) + Math.Max(up, down);
                up = 0;
                down = 0;
            }

            if (newSlope > 0)
                up++;
            if (newSlope < 0)
                down++;
            if (newSlope == 0)
                candies++;
            oldSlope = newSlope;
        }

        candies += count(up) + count(down) + Math.Max(up, down) + 1;
        return candies;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func count(n int) int {
    // Function to calculate sum of first n natural numbers
    return (n * (n + 1)) / 2
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func candy(ratings []int) int {
    if len(ratings) <= 1 {
        return len(ratings)
    }
    candies := 0
    up := 0
    down := 0
    oldSlope := 0
    for i := 1; i < len(ratings); i++ {
        newSlope := 0
        if ratings[i] > ratings[i-1] {
            newSlope = 1
        } else if ratings[i] < ratings[i-1] {
            newSlope = -1
        }
        if (oldSlope > 0 && newSlope == 0) || (oldSlope < 0 && newSlope >= 0) {
            candies += count(up) + count(down) + max(up, down)
            up = 0
            down = 0
        }
        if newSlope > 0 {
            up++
        }
        if newSlope < 0 {
            down++
        }
        if newSlope == 0 {
            candies++
        }
        oldSlope = newSlope
    }
    candies += count(up) + count(down) + max(up, down) + 1
    return candies
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int count(int n) {
        return (n * (n + 1)) / 2;
    }

    public int candy(int[] ratings) {
        if (ratings.length <= 1) {
            return ratings.length;
        }
        int candies = 0;
        int up = 0;
        int down = 0;
        int oldSlope = 0;
        for (int i = 1; i < ratings.length; i++) {
            int newSlope = (ratings[i] > ratings[i - 1])
                ? 1
                : (ratings[i] < ratings[i - 1] ? -1 : 0);

            if (
                (oldSlope > 0 && newSlope == 0) ||
                (oldSlope < 0 && newSlope >= 0)
            ) {
                candies += count(up) + count(down) + Math.max(up, down);
                up = 0;
                down = 0;
            }
            if (newSlope > 0) {
                up++;
            } else if (newSlope < 0) {
                down++;
            } else {
                candies++;
            }

            oldSlope = newSlope;
        }
        candies += count(up) + count(down) + Math.max(up, down) + 1;
        return candies;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var count = function (n) {
    // Function to calculate sum of first n natural numbers
    return (n * (n + 1)) / 2;
};
var candy = function (ratings) {
    if (ratings.length <= 1) {
        return ratings.length;
    }
    var candies = 0;
    var up = 0;
    var down = 0;
    var oldSlope = 0;
    for (var i = 1; i < ratings.length; i++) {
        var newSlope =
            ratings[i] > ratings[i - 1]
                ? 1
                : ratings[i] < ratings[i - 1]
                  ? -1
                  : 0;
        // slope is changing from uphill to flat or downhill
        // or from downhill to flat or uphill
        if (
            (oldSlope > 0 && newSlope == 0) ||
            (oldSlope < 0 && newSlope >= 0)
        ) {
            candies += count(up) + count(down) + Math.max(up, down);
            up = 0;
            down = 0;
        }
        // slope is uphill
        if (newSlope > 0) {
            up++;
        }
        // slope is downhill
        else if (newSlope < 0) {
            down++;
        }
        // slope is flat
        else {
            candies++;
        }
        oldSlope = newSlope;
    }
    candies += count(up) + count(down) + Math.max(up, down) + 1;
    return candies;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Function to calculate sum of first n natural numbers
    def count(self, n):
        return (n * (n + 1)) // 2

    def candy(self, ratings):
        if len(ratings) <= 1:
            return len(ratings)
        candies = 0
        up = 0
        down = 0
        oldSlope = 0
        for i in range(1, len(ratings)):
            newSlope = (
                1
                if ratings[i] > ratings[i - 1]
                else (-1 if ratings[i] < ratings[i - 1] else 0)
            )
            # slope is changing from uphill to flat or downhill
            # or from downhill to flat or uphill
            if (oldSlope > 0 and newSlope == 0) or (
                oldSlope < 0 and newSlope >= 0
            ):
                candies += self.count(up) + self.count(down) + max(up, down)
                up = 0
                down = 0
            # slope is uphill
            if newSlope > 0:
                up += 1
            # slope is downhill
            elif newSlope < 0:
                down += 1
            # slope is flat
            else:
                candies += 1
            oldSlope = newSlope
        candies += self.count(up) + self.count(down) + max(up, down) + 1
        return candies
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function count(n: number): number {
    // Function to calculate sum of first n natural numbers
    return (n * (n + 1)) / 2;
}
function candy(ratings: number[]): number {
    if (ratings.length <= 1) {
        return ratings.length;
    }
    let candies = 0;
    let up = 0;
    let down = 0;
    let oldSlope = 0;
    for (let i = 1; i < ratings.length; i++) {
        let newSlope =
            ratings[i] > ratings[i - 1]
                ? 1
                : ratings[i] < ratings[i - 1]
                  ? -1
                  : 0;
        // slope is changing from uphill to flat or downhill
        // or from downhill to flat or uphill
        if (
            (oldSlope > 0 && newSlope == 0) ||
            (oldSlope < 0 && newSlope >= 0)
        ) {
            candies += count(up) + count(down) + Math.max(up, down);
            up = 0;
            down = 0;
        }
        // slope is uphill
        if (newSlope > 0) {
            up++;
        }
        // slope is downhill
        else if (newSlope < 0) {
            down++;
        }
        // slope is flat
        else {
            candies++;
        }
        oldSlope = newSlope;
    }
    candies += count(up) + count(down) + Math.max(up, down) + 1;
    return candies;
}
```

</details>
