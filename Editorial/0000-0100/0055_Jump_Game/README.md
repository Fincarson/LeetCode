# 55. Jump Game

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/jump-game/)  
`Array` `Dynamic Programming` `Greedy`

**Problem Link:** [LeetCode 55 - Jump Game](https://leetcode.com/problems/jump-game/)

## Problem

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

### Example 1

```text
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

### Example 2

```text
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```

## Constraints

- 1 <= nums.length <= 104
- 0 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Jump Game II](https://leetcode.com/problems/jump-game-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Jump Game III](https://leetcode.com/problems/jump-game-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Jump Game VII](https://leetcode.com/problems/jump-game-vii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Jump Game VIII](https://leetcode.com/problems/jump-game-viii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Number of Visited Cells in a Grid](https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Largest Element in an Array after Merge Operations](https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 55. Jump Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking (Not Accepted: TLE) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming Top-down | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming Bottom-up | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Backtracking (Not Accepted: TLE)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool canJumpFromPosition(int position, int* nums, int numsSize) {
    if (position == numsSize - 1) {
        return true;
    }
    int furthestJump = position + nums[position] < numsSize - 1
                           ? position + nums[position]
                           : numsSize - 1;
    for (int nextPosition = position + 1; nextPosition <= furthestJump;
         ++nextPosition) {
        if (canJumpFromPosition(nextPosition, nums, numsSize)) {
            return true;
        }
    }
    return false;
}
bool canJump(int* nums, int numsSize) {
    return canJumpFromPosition(0, nums, numsSize);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (position == nums.size() - 1) {
            return true;
        }
        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump;
             nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) { return canJumpFromPosition(0, nums); }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool CanJumpFromPosition(int position, int[] nums) {
        if (position == nums.Length - 1) {
            return true;
        }

        int furthestJump = Math.Min(position + nums[position], nums.Length - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump;
             nextPosition++) {
            if (CanJumpFromPosition(nextPosition, nums)) {
                return true;
            }
        }

        return false;
    }

    public bool CanJump(int[] nums) {
        return CanJumpFromPosition(0, nums);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func canJumpFromPosition(position int, nums []int) bool {
    if position == len(nums)-1 {
        return true
    }
    furthestJump := min(position+nums[position], len(nums)-1)
    for nextPosition := position + 1; nextPosition <= furthestJump; nextPosition++ {
        if canJumpFromPosition(nextPosition, nums) {
            return true
        }
    }
    return false
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func canJump(nums []int) bool {
    return canJumpFromPosition(0, nums)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean canJumpFromPosition(int position, int[] nums) {
        if (position == nums.length - 1) {
            return true;
        }

        int furthestJump = Math.min(position + nums[position], nums.length - 1);
        for (
            int nextPosition = position + 1;
            nextPosition <= furthestJump;
            nextPosition++
        ) {
            if (canJumpFromPosition(nextPosition, nums)) {
                return true;
            }
        }

        return false;
    }

    public boolean canJump(int[] nums) {
        return canJumpFromPosition(0, nums);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var canJumpFromPosition = function (position, nums) {
    if (position == nums.length - 1) {
        return true;
    }
    let furthestJump = Math.min(position + nums[position], nums.length - 1);
    for (
        let nextPosition = position + 1;
        nextPosition <= furthestJump;
        nextPosition++
    ) {
        if (canJumpFromPosition(nextPosition, nums)) {
            return true;
        }
    }
    return false;
};
var canJump = function (nums) {
    return canJumpFromPosition(0, nums);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canJumpFromPosition(self, position, nums):
        if position == len(nums) - 1:
            return True
        furthestJump = min(position + nums[position], len(nums) - 1)
        for nextPosition in range(position + 1, furthestJump + 1):
            if self.canJumpFromPosition(nextPosition, nums):
                return True
        return False

    def canJump(self, nums):
        return self.canJumpFromPosition(0, nums)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function canJumpFromPosition(position: number, nums: number[]): boolean {
    if (position == nums.length - 1) {
        return true;
    }
    const furthestJump = Math.min(position + nums[position], nums.length - 1);
    for (
        let nextPosition = position + 1;
        nextPosition <= furthestJump;
        nextPosition++
    ) {
        if (canJumpFromPosition(nextPosition, nums)) {
            return true;
        }
    }
    return false;
}
function canJump(nums: number[]): boolean {
    return canJumpFromPosition(0, nums);
}
```

</details>

<br>

## Approach 2: Dynamic Programming Top-down

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
enum Index { GOOD, BAD, UNKNOWN };
int canJumpFromPosition(int position, int* nums, int numsSize,
                        enum Index* memo) {
    if (memo[position] != UNKNOWN) {
        return memo[position] == GOOD ? 1 : 0;
    }
    int furthestJump = (position + nums[position] < numsSize - 1)
                           ? position + nums[position]
                           : numsSize - 1;
    for (int nextPosition = position + 1; nextPosition <= furthestJump;
         nextPosition++) {
        if (canJumpFromPosition(nextPosition, nums, numsSize, memo)) {
            memo[position] = GOOD;
            return 1;
        }
    }
    memo[position] = BAD;
    return 0;
}
int canJump(int* nums, int numsSize) {
    enum Index* memo = (enum Index*)malloc(numsSize * sizeof(enum Index));
    for (int i = 0; i < numsSize; i++) memo[i] = UNKNOWN;
    memo[numsSize - 1] = GOOD;
    return canJumpFromPosition(0, nums, numsSize, memo);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
enum Index { GOOD, BAD, UNKNOWN };
class Solution {
public:
    vector<Index> memo;
    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (memo[position] != UNKNOWN) {
            return memo[position] == GOOD ? true : false;
        }
        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump;
             nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                memo[position] = GOOD;
                return true;
            }
        }
        memo[position] = BAD;
        return false;
    }
    bool canJump(vector<int>& nums) {
        memo = vector<Index>(nums.size());
        for (int i = 0; i < memo.size(); i++) {
            memo[i] = UNKNOWN;
        }
        memo[memo.size() - 1] = GOOD;
        return canJumpFromPosition(0, nums);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public enum Index { GOOD, BAD, UNKNOWN }

public class Solution {
    Index[] memo;

    public bool CanJumpFromPosition(int position, int[] nums) {
        if (memo[position] != Index.UNKNOWN) {
            return memo[position] == Index.GOOD ? true : false;
        }

        int furthestJump = Math.Min(position + nums[position], nums.Length - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump;
             nextPosition++) {
            if (CanJumpFromPosition(nextPosition, nums)) {
                memo[position] = Index.GOOD;
                return true;
            }
        }

        memo[position] = Index.BAD;
        return false;
    }

    public bool CanJump(int[] nums) {
        memo = new Index[nums.Length];
        for (int i = 0; i < memo.Length; i++) {
            memo[i] = Index.UNKNOWN;
        }

        memo[memo.Length - 1] = Index.GOOD;
        return CanJumpFromPosition(0, nums);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Index int

const (
    GOOD    Index = 1
    BAD     Index = 2
    UNKNOWN Index = 0
)

var memo []Index

func canJumpFromPosition(position int, nums []int) bool {
    if memo[position] != UNKNOWN {
        return memo[position] == GOOD
    }
    furthestJump := position + nums[position]
    if furthestJump > len(nums)-1 {
        furthestJump = len(nums) - 1
    }
    for nextPosition := position + 1; nextPosition <= furthestJump; nextPosition++ {
        if canJumpFromPosition(nextPosition, nums) {
            memo[position] = GOOD
            return true
        }
    }
    memo[position] = BAD
    return false
}

func canJump(nums []int) bool {
    memo = make([]Index, len(nums))
    for i := range memo {
        memo[i] = UNKNOWN
    }
    memo[len(nums)-1] = GOOD
    return canJumpFromPosition(0, nums)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
enum Index {
    GOOD,
    BAD,
    UNKNOWN,
}

public class Solution {
    Index[] memo;

    public boolean canJumpFromPosition(int position, int[] nums) {
        if (memo[position] != Index.UNKNOWN) {
            return memo[position] == Index.GOOD ? true : false;
        }

        int furthestJump = Math.min(position + nums[position], nums.length - 1);
        for (
            int nextPosition = position + 1;
            nextPosition <= furthestJump;
            nextPosition++
        ) {
            if (canJumpFromPosition(nextPosition, nums)) {
                memo[position] = Index.GOOD;
                return true;
            }
        }

        memo[position] = Index.BAD;
        return false;
    }

    public boolean canJump(int[] nums) {
        memo = new Index[nums.length];
        for (int i = 0; i < memo.length; i++) {
            memo[i] = Index.UNKNOWN;
        }
        memo[memo.length - 1] = Index.GOOD;
        return canJumpFromPosition(0, nums);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let memo;
const canJumpFromPosition = (position, nums) => {
    if (memo[position] != "UNKNOWN") {
        return memo[position] == "GOOD";
    }
    let furthestJump = Math.min(position + nums[position], nums.length - 1);
    for (
        let nextPosition = position + 1;
        nextPosition <= furthestJump;
        nextPosition++
    ) {
        if (canJumpFromPosition(nextPosition, nums)) {
            memo[position] = "GOOD";
            return true;
        }
    }
    memo[position] = "BAD";
    return false;
};
var canJump = function (nums) {
    memo = new Array(nums.length).fill("UNKNOWN");
    memo[memo.length - 1] = "GOOD";
    return canJumpFromPosition(0, nums);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.memo = []
        self.nums = []

    def canJumpFromPosition(self, position):
        if self.memo[position] != -1:
            return self.memo[position] == 1
        furthestJump = min(position + self.nums[position], len(self.nums) - 1)
        for nextPosition in range(position + 1, furthestJump + 1):
            if self.canJumpFromPosition(nextPosition):
                self.memo[position] = 1
                return True
        self.memo[position] = 0
        return False

    def canJump(self, nums):
        self.nums = nums
        self.memo = [-1] * len(nums)  # -1 for unknown, 0 for bad, 1 for good
        self.memo[-1] = 1  # The last position is always "good"
        return self.canJumpFromPosition(0)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
let memo: string[];
const canJumpFromPosition = (position: number, nums: number[]): boolean => {
    if (memo[position] != "UNKNOWN") {
        return memo[position] == "GOOD";
    }
    let furthestJump = Math.min(position + nums[position], nums.length - 1);
    for (
        let nextPosition = position + 1;
        nextPosition <= furthestJump;
        nextPosition++
    ) {
        if (canJumpFromPosition(nextPosition, nums)) {
            memo[position] = "GOOD";
            return true;
        }
    }
    memo[position] = "BAD";
    return false;
};
function canJump(nums: number[]): boolean {
    memo = new Array(nums.length).fill("UNKNOWN");
    memo[memo.length - 1] = "GOOD";
    return canJumpFromPosition(0, nums);
}
```

</details>

<br>

## Approach 3: Dynamic Programming Bottom-up

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef enum Index { GOOD, BAD, UNKNOWN } Index;
bool canJump(int* nums, int numsSize) {
    Index* memo = (Index*)malloc(numsSize * sizeof(Index));
    for (int i = 0; i < numsSize; i++) {
        memo[i] = UNKNOWN;
    }
    memo[numsSize - 1] = GOOD;
    for (int i = numsSize - 2; i >= 0; i--) {
        int furthestJump =
            (i + nums[i] < numsSize - 1) ? i + nums[i] : numsSize - 1;
        for (int j = i + 1; j <= furthestJump; j++) {
            if (memo[j] == GOOD) {
                memo[i] = GOOD;
                break;
            }
        }
    }
    return memo[0] == GOOD;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
enum Index { GOOD, BAD, UNKNOWN };
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<Index> memo(nums.size(), UNKNOWN);
        memo[memo.size() - 1] = GOOD;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int furthestJump = min(i + nums[i], (int)nums.size() - 1);
            for (int j = i + 1; j <= furthestJump; j++) {
                if (memo[j] == GOOD) {
                    memo[i] = GOOD;
                    break;
                }
            }
        }
        return memo[0] == GOOD;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public enum Index { GOOD, BAD, UNKNOWN }

public class Solution {
    public bool CanJump(int[] nums) {
        Index[] memo = new Index[nums.Length];
        for (int i = 0; i < memo.Length; i++) {
            memo[i] = Index.UNKNOWN;
        }

        memo[memo.Length - 1] = Index.GOOD;
        for (int i = nums.Length - 2; i >= 0; i--) {
            int furthestJump = Math.Min(i + nums[i], nums.Length - 1);
            for (int j = i + 1; j <= furthestJump; j++) {
                if (memo[j] == Index.GOOD) {
                    memo[i] = Index.GOOD;
                    break;
                }
            }
        }

        return memo[0] == Index.GOOD;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func canJump(nums []int) bool {
    type Index int
    const (
        GOOD Index = iota
        BAD
        UNKNOWN
    )
    memo := make([]Index, len(nums))
    for i := range memo {
        memo[i] = UNKNOWN
    }
    memo[len(memo)-1] = GOOD
    for i := len(nums) - 2; i >= 0; i-- {
        furthestJump := min(i+nums[i], len(nums)-1)
        for j := i + 1; j <= furthestJump; j++ {
            if memo[j] == GOOD {
                memo[i] = GOOD
                break
            }
        }
    }
    return memo[0] == GOOD
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
enum Index {
    GOOD,
    BAD,
    UNKNOWN,
}

public class Solution {
    public boolean canJump(int[] nums) {
        Index[] memo = new Index[nums.length];
        for (int i = 0; i < memo.length; i++) {
            memo[i] = Index.UNKNOWN;
        }
        memo[memo.length - 1] = Index.GOOD;

        for (int i = nums.length - 2; i >= 0; i--) {
            int furthestJump = Math.min(i + nums[i], nums.length - 1);
            for (int j = i + 1; j <= furthestJump; j++) {
                if (memo[j] == Index.GOOD) {
                    memo[i] = Index.GOOD;
                    break;
                }
            }
        }

        return memo[0] == Index.GOOD;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var canJump = function (nums) {
    // using Number object to simulate enum
    let Index = { GOOD: 1, BAD: 0, UNKNOWN: -1 };
    let memo = new Array(nums.length).fill(Index.UNKNOWN);
    memo[memo.length - 1] = Index.GOOD;
    for (let i = nums.length - 2; i >= 0; i--) {
        let furthestJump = Math.min(i + nums[i], nums.length - 1);
        for (let j = i + 1; j <= furthestJump; j++) {
            if (memo[j] == Index.GOOD) {
                memo[i] = Index.GOOD;
                break;
            }
        }
    }
    return memo[0] == Index.GOOD;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def canJump(self, nums):
        GOOD, BAD, UNKNOWN = 1, 0, -1
        memo = [UNKNOWN] * len(nums)
        memo[-1] = GOOD
        for i in range(len(nums) - 2, -1, -1):
            furthest_jump = min(i + nums[i], len(nums) - 1)
            for j in range(i + 1, furthest_jump + 1):
                if memo[j] == GOOD:
                    memo[i] = GOOD
                    break
        return memo[0] == GOOD
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
enum Index {
    GOOD,
    BAD,
    UNKNOWN,
}
function canJump(nums: number[]): boolean {
    let memo: Index[] = Array(nums.length).fill(Index.UNKNOWN);
    memo[memo.length - 1] = Index.GOOD;
    for (let i = nums.length - 2; i >= 0; i--) {
        let furthestJump: number = Math.min(i + nums[i], nums.length - 1);
        for (let j = i + 1; j <= furthestJump; j++) {
            if (memo[j] == Index.GOOD) {
                memo[i] = Index.GOOD;
                break;
            }
        }
    }
    return memo[0] == Index.GOOD;
}
```

</details>

<br>

## Approach 4: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool canJump(int* nums, int numsSize) {
    int lastPos = numsSize - 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        if (i + nums[i] >= lastPos) {
            lastPos = i;
        }
    }
    return lastPos == 0;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool CanJump(int[] nums) {
        int lastPos = nums.Length - 1;
        for (int i = nums.Length - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }

        return lastPos == 0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func canJump(nums []int) bool {
    lastPos := len(nums) - 1
    for i := len(nums) - 1; i >= 0; i-- {
        if i+nums[i] >= lastPos {
            lastPos = i
        }
    }
    return lastPos == 0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean canJump(int[] nums) {
        int lastPos = nums.length - 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var canJump = function (nums) {
    let lastPos = nums.length - 1;
    for (let i = nums.length - 1; i >= 0; i--) {
        if (i + nums[i] >= lastPos) {
            lastPos = i;
        }
    }
    return lastPos === 0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lastPos = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[i] >= lastPos:
                lastPos = i
        return lastPos == 0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function canJump(nums: number[]): boolean {
    let lastPos = nums.length - 1;
    for (let i = nums.length - 1; i >= 0; i--) {
        if (i + nums[i] >= lastPos) {
            lastPos = i;
        }
    }
    return lastPos === 0;
}
```

</details>
