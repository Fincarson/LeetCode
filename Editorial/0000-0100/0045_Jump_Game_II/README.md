# 45. Jump Game II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/jump-game-ii/)  
`Array` `Dynamic Programming` `Greedy`

**Problem Link:** [LeetCode 45 - Jump Game II](https://leetcode.com/problems/jump-game-ii/)

## Problem

You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

- 0 <= j <= nums[i] and
- i + j < n

Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

### Example 1

```text
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

### Example 2

```text
Input: nums = [2,3,0,1,4]
Output: 2
```

## Constraints

- 1 <= nums.length <= 104
- 0 <= nums[i] <= 1000
- It's guaranteed that you can reach nums[n - 1].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Jump Game](https://leetcode.com/problems/jump-game/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Jump Game III](https://leetcode.com/problems/jump-game-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Jump Game VII](https://leetcode.com/problems/jump-game-vii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Jump Game VIII](https://leetcode.com/problems/jump-game-viii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Number of Visited Cells in a Grid](https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Number of Jumps to Reach the Last Index](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Visit Array Positions to Maximize Score](https://leetcode.com/problems/visit-array-positions-to-maximize-score/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 45. Jump Game II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int jump(int* nums, int numsSize) {
    // The starting range of the first jump is [0, 0]
    int answer = 0;
    int curEnd = 0, curFar = 0;
    for (int i = 0; i < numsSize - 1; ++i) {
        // Update the farthest reachable index of this jump.
        curFar = (curFar > i + nums[i]) ? curFar : i + nums[i];
        // If we finish the starting range of this jump,
        // Move on to the starting range of the next jump.
        if (i == curEnd) {
            answer++;
            curEnd = curFar;
        }
    }
    return answer;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        // The starting range of the first jump is [0, 0]
        int answer = 0, n = int(nums.size());

        int curEnd = 0, curFar = 0;

        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest reachable index of this jump.
            curFar = max(curFar, i + nums[i]);

            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump.
            if (i == curEnd) {
                answer++;
                curEnd = curFar;
            }
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int Jump(int[] nums) {
        // The starting range of the first jump is [0, 0]
        int answer = 0, n = nums.Length;
        int curEnd = 0, curFar = 0;
        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest reachable index of this jump.
            curFar = Math.Max(curFar, i + nums[i]);
            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump.
            if (i == curEnd) {
                answer++;
                curEnd = curFar;
            }
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func jump(nums []int) int {
    // The starting range of the first jump is [0, 0]
    answer, n := 0, len(nums)
    curEnd, curFar := 0, 0
    for i := 0; i < n-1; i++ {
        // Update the farthest reachable index of this jump.
        if curFar < i+nums[i] {
            curFar = i + nums[i]
        }
        // If we finish the starting range of this jump,
        // Move on to the starting range of the next jump.
        if i == curEnd {
            answer++
            curEnd = curFar
        }
    }
    return answer
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int jump(int[] nums) {
        // The starting range of the first jump is [0, 0]
        int answer = 0, n = nums.length;
        int curEnd = 0, curFar = 0;

        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest reachable index of this jump.
            curFar = Math.max(curFar, i + nums[i]);

            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump.
            if (i == curEnd) {
                answer++;
                curEnd = curFar;
            }
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var jump = function (nums) {
    // The starting range of the first jump is [0, 0]
    let answer = 0,
        n = nums.length;
    let curEnd = 0,
        curFar = 0;
    for (let i = 0; i < n - 1; ++i) {
        // Update the farthest reachable index of this jump.
        curFar = Math.max(curFar, i + nums[i]);
        // If we finish the starting range of this jump,
        // Move on to the starting range of the next jump.
        if (i === curEnd) {
            ++answer;
            curEnd = curFar;
        }
    }
    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        # The starting range of the first jump is [0, 0]
        answer, n = 0, len(nums)
        cur_end, cur_far = 0, 0

        for i in range(n - 1):
            # Update the farthest reachable index of this jump.
            cur_far = max(cur_far, i + nums[i])

            # If we finish the starting range of this jump,
            # Move on to the starting range of the next jump.
            if i == cur_end:
                answer += 1
                cur_end = cur_far

        return answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function jump(nums: number[]): number {
    // The starting range of the first jump is [0, 0]
    let answer = 0,
        n = nums.length;
    let curEnd = 0,
        curFar = 0;
    for (let i = 0; i < n - 1; ++i) {
        // Update the farthest reachable index of this jump.
        curFar = Math.max(curFar, i + nums[i]);
        // If we finish the starting range of this jump,
        // Move on to the starting range of the next jump.
        if (i === curEnd) {
            ++answer;
            curEnd = curFar;
        }
    }
    return answer;
}
```

</details>
