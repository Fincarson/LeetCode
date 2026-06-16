# 2106. Maximum Fruits Harvested After at Most K Steps

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/)  
`Array` `Binary Search` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 2106 - Maximum Fruits Harvested After at Most K Steps](https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/)

## Problem

Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. fruits is already sorted by positioni in ascending order, and each positioni is unique.

You are also given an integer startPos and an integer k. Initially, you are at the position startPos. From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and you can walk at most k steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.

Return the maximum total number of fruits you can harvest.

### Example 1

```text
Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
Output: 9
Explanation:
The optimal way is to:
- Move right to position 6 and harvest 3 fruits
- Move right to position 8 and harvest 6 fruits
You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
```

### Example 2

```text
Input: fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
Output: 14
Explanation:
You can move at most k = 4 steps, so you cannot reach position 0 nor 10.
The optimal way is to:
- Harvest the 7 fruits at the starting position 5
- Move left to position 4 and harvest 1 fruit
- Move right to position 6 and harvest 2 fruits
- Move right to position 7 and harvest 4 fruits
You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.
```

### Example 3

```text
Input: fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
Output: 0
Explanation:
You can move at most k = 2 steps and cannot reach any position with fruits.
```

## Constraints

- 1 <= fruits.length <= 105
- fruits[i].length == 2
- 0 <= startPos, positioni <= 2 * 105
- positioni-1 < positioni for any i > 0 (0-indexed)
- 1 <= amounti <= 104
- 0 <= k <= 2 * 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Performance of a Team](https://leetcode.com/problems/maximum-performance-of-a-team/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2106. Maximum Fruits Harvested After at Most K Steps

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C, C++, C#, Java, JavaScript, Python3 |
| Sliding Window | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lowerBound(const int* arr, int left, int right, int val) {
    int res = right + 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= val) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int upperBound(const int* arr, int left, int right, int val) {
    int res = right + 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > val) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int maxTotalFruits(int** fruits, int fruitsSize, int* fruitsColSize,
                   int startPos, int k) {
    int n = fruitsSize;
    int sum[n + 1];
    int indices[n];
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + fruits[i][1];
        indices[i] = fruits[i][0];
    }
    int ans = 0;
    for (int x = 0; x <= k / 2; x++) {
        /* move left x steps, then move right k - x steps. */
        int y = k - 2 * x;
        int left = startPos - x;
        int right = startPos + y;
        int start = lowerBound(indices, 0, n - 1, left);
        int end = upperBound(indices, 0, n - 1, right);
        ans = MAX(ans, sum[end] - sum[start]);
        /* move right x steps, then move left k - x steps. */
        y = k - 2 * x;
        left = startPos - y;
        right = startPos + x;
        start = lowerBound(indices, 0, n - 1, left);
        end = upperBound(indices, 0, n - 1, right);
        ans = MAX(ans, sum[end] - sum[start]);
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
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> sum(n + 1);
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }
        int ans = 0;
        for (int x = 0; x <= k / 2; x++) {
            /* move left x steps, then move right k - x steps. */
            int y = k - 2 * x;
            int left = startPos - x;
            int right = startPos + y;
            int start = lower_bound(indices.begin(), indices.end(), left) -
                        indices.begin();
            int end = upper_bound(indices.begin(), indices.end(), right) -
                      indices.begin();
            ans = max(ans, sum[end] - sum[start]);
            /* move right x steps, then move left k - x steps. */
            y = k - 2 * x;
            left = startPos - y;
            right = startPos + x;
            start = lower_bound(indices.begin(), indices.end(), left) -
                    indices.begin();
            end = upper_bound(indices.begin(), indices.end(), right) -
                  indices.begin();
            ans = max(ans, sum[end] - sum[start]);
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
    public int MaxTotalFruits(int[][] fruits, int startPos, int k) {
        int n = fruits.Length;
        int[] sum = new int[n + 1];
        int[] indices = new int[n];
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }
        int ans = 0;
        for (int x = 0; x <= k / 2; x++) {
            /* move left x steps, then move right k - x steps. */
            int y = k - 2 * x;
            int left = startPos - x;
            int right = startPos + y;
            int start = LowerBound(indices, 0, n - 1, left);
            int end = UpperBound(indices, 0, n - 1, right);
            ans = Math.Max(ans, sum[end] - sum[start]);
            /* move right x steps, then move left k - x steps. */
            y = k - 2 * x;
            left = startPos - y;
            right = startPos + x;
            start = LowerBound(indices, 0, n - 1, left);
            end = UpperBound(indices, 0, n - 1, right);
            ans = Math.Max(ans, sum[end] - sum[start]);
        }
        return ans;
    }

    public int LowerBound(int[] arr, int left, int right, int val) {
        int res = right + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= val) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }

    public int UpperBound(int[] arr, int left, int right, int val) {
        int res = right + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > val) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int n = fruits.length;
        int[] sum = new int[n + 1];
        int[] indices = new int[n];
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }
        int ans = 0;
        for (int x = 0; x <= k / 2; x++) {
            /* move left x steps, then move right k - x steps. */
            int y = k - 2 * x;
            int left = startPos - x;
            int right = startPos + y;
            int start = lowerBound(indices, 0, n - 1, left);
            int end = upperBound(indices, 0, n - 1, right);
            ans = Math.max(ans, sum[end] - sum[start]);
            /* move right x steps, then move left k - x steps. */
            y = k - 2 * x;
            left = startPos - y;
            right = startPos + x;
            start = lowerBound(indices, 0, n - 1, left);
            end = upperBound(indices, 0, n - 1, right);
            ans = Math.max(ans, sum[end] - sum[start]);
        }
        return ans;
    }

    public int lowerBound(int[] arr, int left, int right, int val) {
        int res = right + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= val) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }

    public int upperBound(int[] arr, int left, int right, int val) {
        int res = right + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > val) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
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
var maxTotalFruits = function (fruits, startPos, k) {
    const n = fruits.length;
    const sum = new Array(n + 1).fill(0);
    const indices = new Array(n).fill(0);
    sum[0] = 0;
    for (let i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + fruits[i][1];
        indices[i] = fruits[i][0];
    }
    let ans = 0;
    for (let x = 0; x <= Math.floor(k / 2); x++) {
        /* move left x steps, then move right k - x steps. */
        let y = k - 2 * x;
        let left = startPos - x;
        let right = startPos + y;
        let start = lowerBound(indices, 0, n - 1, left);
        let end = upperBound(indices, 0, n - 1, right);
        ans = Math.max(ans, sum[end] - sum[start]);
        /* move right x steps, then move left k - x steps. */
        y = k - 2 * x;
        left = startPos - y;
        right = startPos + x;
        start = lowerBound(indices, 0, n - 1, left);
        end = upperBound(indices, 0, n - 1, right);
        ans = Math.max(ans, sum[end] - sum[start]);
    }
    return ans;
};

const lowerBound = (arr, left, right, val) => {
    let res = right + 1;
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        if (arr[mid] >= val) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
};

const upperBound = (arr, left, right, val) => {
    let res = right + 1;
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        if (arr[mid] > val) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
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
    def maxTotalFruits(
        self, fruits: List[List[int]], startPos: int, k: int
    ) -> int:
        n = len(fruits)
        sum_ = [0] * (n + 1)
        indices = [0] * n

        for i in range(n):
            sum_[i + 1] = sum_[i] + fruits[i][1]
            indices[i] = fruits[i][0]

        ans = 0
        for x in range(k // 2 + 1):
            # move left x steps, then right (k - 2x) steps
            y = k - 2 * x
            left = startPos - x
            right = startPos + y
            start = bisect_left(indices, left)
            end = bisect_right(indices, right)
            ans = max(ans, sum_[end] - sum_[start])

            # move right x steps, then left (k - 2x) steps
            y = k - 2 * x
            left = startPos - y
            right = startPos + x
            start = bisect_left(indices, left)
            end = bisect_right(indices, right)
            ans = max(ans, sum_[end] - sum_[start])

        return ans
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int step(int** fruits, int left, int right, int startPos) {
    if (fruits[right][0] <= startPos) {
        return startPos - fruits[left][0];
    } else if (fruits[left][0] >= startPos) {
        return fruits[right][0] - startPos;
    } else {
        return MIN(abs(startPos - fruits[right][0]),
                   abs(startPos - fruits[left][0])) +
               fruits[right][0] - fruits[left][0];
    }
}

int maxTotalFruits(int** fruits, int fruitsSize, int* fruitsColSize,
                   int startPos, int k) {
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;

    /* fix the right boundary of the window */
    while (right < fruitsSize) {
        sum += fruits[right][1];
        /* move left boundary */
        while (left <= right && step(fruits, left, right, startPos) > k) {
            sum -= fruits[left][1];
            left++;
        }
        ans = MAX(ans, sum);
        right++;
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
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0;
        int right = 0;
        int n = fruits.size();
        int sum = 0;
        int ans = 0;

        auto step = [&](int left, int right) -> int {
            if (fruits[right][0] <= startPos) {
                return startPos - fruits[left][0];
            } else if (fruits[left][0] >= startPos) {
                return fruits[right][0] - startPos;
            } else {
                return min(abs(startPos - fruits[right][0]),
                           abs(startPos - fruits[left][0])) +
                       fruits[right][0] - fruits[left][0];
            }
        };
        // each time fix the right boundary of the window
        while (right < n) {
            sum += fruits[right][1];
            // move left boundary
            while (left <= right && step(left, right) > k) {
                sum -= fruits[left][1];
                left++;
            }
            ans = max(ans, sum);
            right++;
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
    public int MaxTotalFruits(int[][] fruits, int startPos, int k) {
        int left = 0;
        int right = 0;
        int n = fruits.Length;
        int sum = 0;
        int ans = 0;
        // each time fix the right boundary of the window
        while (right < n) {
            sum += fruits[right][1];
            // move left boundary
            while (left <= right && Step(fruits, startPos, left, right) > k) {
                sum -= fruits[left][1];
                left++;
            }
            ans = Math.Max(ans, sum);
            right++;
        }
        return ans;
    }

    public int Step(int[][] fruits, int startPos, int left, int right) {
        if (fruits[right][0] <= startPos) {
            return startPos - fruits[left][0];
        } else if (fruits[left][0] >= startPos) {
            return fruits[right][0] - startPos;
        } else {
            return Math.Min(Math.Abs(startPos - fruits[right][0]),
                            Math.Abs(startPos - fruits[left][0])) +
                   fruits[right][0] - fruits[left][0];
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxTotalFruits(fruits [][]int, startPos int, k int) int {
    left := 0
    right := 0
    n := len(fruits)
    sum := 0
    ans := 0

    step := func(left int, right int) int {
        if fruits[right][0] <= startPos {
            return startPos - fruits[left][0]
        } else if fruits[left][0] >= startPos {
            return fruits[right][0] - startPos
        } else {
            return min(abs(startPos-fruits[right][0]), abs(startPos-fruits[left][0])) + fruits[right][0] - fruits[left][0]
        }
    }
    // each time fix the right boundary of the window
    for right < n {
        sum += fruits[right][1]
        // move left boundary
        for left <= right && step(left, right) > k {
            sum -= fruits[left][1]
            left++
        }
        ans = max(ans, sum)
        right++
    }
    return ans
}

func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}

func max(a, b int) int {
    if b > a {
        return b
    }
    return a
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
class Solution {

    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int left = 0;
        int right = 0;
        int n = fruits.length;
        int sum = 0;
        int ans = 0;
        // each time fix the right boundary of the window
        while (right < n) {
            sum += fruits[right][1];
            // move left boundary
            while (left <= right && step(fruits, startPos, left, right) > k) {
                sum -= fruits[left][1];
                left++;
            }
            ans = Math.max(ans, sum);
            right++;
        }
        return ans;
    }

    public int step(int[][] fruits, int startPos, int left, int right) {
        return (
            Math.min(
                Math.abs(startPos - fruits[right][0]),
                Math.abs(startPos - fruits[left][0])
            ) +
            fruits[right][0] -
            fruits[left][0]
        );
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxTotalFruits = function (fruits, startPos, k) {
    let left = 0;
    let right = 0;
    const n = fruits.length;
    let sum = 0;
    let ans = 0;
    // each time fix the right boundary of the window
    while (right < n) {
        sum += fruits[right][1];
        // move left boundary
        while (left <= right && step(fruits, startPos, left, right) > k) {
            sum -= fruits[left][1];
            left++;
        }
        ans = Math.max(ans, sum);
        right++;
    }
    return ans;
};

const step = (fruits, startPos, left, right) => {
    return (
        Math.min(
            Math.abs(startPos - fruits[right][0]),
            Math.abs(startPos - fruits[left][0]),
        ) +
        fruits[right][0] -
        fruits[left][0]
    );
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxTotalFruits(
        self, fruits: List[List[int]], startPos: int, k: int
    ) -> int:
        left = 0
        right = 0
        n = len(fruits)
        sum = 0
        ans = 0

        def step(left: int, right: int) -> int:
            if fruits[right][0] <= startPos:
                return startPos - fruits[left][0]
            elif fruits[left][0] >= startPos:
                return fruits[right][0] - startPos
            else:
                return (
                    min(
                        abs(startPos - fruits[right][0]),
                        abs(startPos - fruits[left][0]),
                    )
                    + fruits[right][0]
                    - fruits[left][0]
                )

        # each time fix the right boundary of the window
        while right < n:
            sum += fruits[right][1]
            # move left boundary
            while left <= right and step(left, right) > k:
                sum -= fruits[left][1]
                left += 1

            ans = max(ans, sum)
            right += 1

        return ans
```

</details>
