# 1503. Last Moment Before All Ants Fall Out of a Plank

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/)  
`Array` `Brainteaser` `Simulation`

**Problem Link:** [LeetCode 1503 - Last Moment Before All Ants Fall Out of a Plank](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/)

## Problem

We have a wooden plank of the length n units. Some ants are walking on the plank, each ant moves with a speed of 1 unit per second. Some of the ants move to the left, the other move to the right.

When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time.

When an ant reaches one end of the plank at a time t, it falls out of the plank immediately.

Given an integer n and two integer arrays left and right, the positions of the ants moving to the left and the right, return the moment when the last ant(s) fall out of the plank.

### Example 1

```text
Input: n = 4, left = [4,3], right = [0,1]
Output: 4
Explanation: In the image above:
-The ant at index 0 is named A and going to the right.
-The ant at index 1 is named B and going to the right.
-The ant at index 3 is named C and going to the left.
-The ant at index 4 is named D and going to the left.
The last moment when an ant was on the plank is t = 4 seconds. After that, it falls immediately out of the plank. (i.e., We can say that at t = 4.0000000001, there are no ants on the plank).
```

### Example 2

```text
Input: n = 7, left = [], right = [0,1,2,3,4,5,6,7]
Output: 7
Explanation: All ants are going to the right, the ant at index 0 needs 7 seconds to fall.
```

### Example 3

```text
Input: n = 7, left = [0,1,2,3,4,5,6,7], right = []
Output: 7
Explanation: All ants are going to the left, the ant at index 7 needs 7 seconds to fall.
```

## Constraints

- 1 <= n <= 104
- 0 <= left.length <= n + 1
- 0 <= left[i] <= n
- 0 <= right.length <= n + 1
- 0 <= right[i] <= n
- 1 <= left.length + right.length <= n + 1
- All values of left and right are unique, and each value can appear only in one of the two arrays.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Collisions on a Road](https://leetcode.com/problems/count-collisions-on-a-road/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Movement of Robots](https://leetcode.com/problems/movement-of-robots/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1503. Last Moment Before All Ants Fall Out of a Plank

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Ants Pass Each Other! | C++, Java, Python3 |

## Approach: Ants Pass Each Other!

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int num : left) {
            ans = max(ans, num);
        }
        
        for (int num : right) {
            ans = max(ans, n - num);
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int ans = 0;
        for (int num : left) {
            ans = Math.max(ans, num);
        }
        
        for (int num : right) {
            ans = Math.max(ans, n - num);
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        ans = 0
        for num in left:
            ans = max(ans, num)
        
        for num in right:
            ans = max(ans, n - num)
        
        return ans
```

</details>
