# 1578. Minimum Time to Make Rope Colorful

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/)  
`Array` `String` `Dynamic Programming` `Greedy`

**Problem Link:** [LeetCode 1578 - Minimum Time to Make Rope Colorful](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/)

## Problem

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

### Example 1

```text
Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
```

### Example 2

```text
Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
```

### Example 3

```text
Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the balloons at indices 0 and 4. Each balloons takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
```

## Constraints

- n == colors.length == neededTime.length
- 1 <= n <= 105
- 1 <= neededTime[i] <= 104
- colors contains only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1578. Minimum Time to Make Rope Colorful

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two pointers | C++, Java, JavaScript, Python3 |
| Advanced 1-Pass | C++, Java, JavaScript, Python3 |

## Approach 1: Two pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // Initalize two pointers i, j.
        int totalTime = 0;
        int i = 0, j = 0;
        
        while (i < neededTime.size() && j < neededTime.size()) {
            int currTotal = 0, currMax = 0;
            
            // Find all the balloons having the same color as the 
            // balloon indexed at i, record the total removal time 
            // and the maximum removal time.
            while (j < neededTime.size() && colors[i] == colors[j]) {
                currTotal += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                j++;
            }
            
            // Once we reach the end of the current group, add the cost of 
            // this group to total_time, and reset two pointers.
            totalTime += currTotal - currMax;
            i = j;
        }
        return totalTime;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCost(String colors, int[] neededTime) {
        // Initalize two pointers i, j.
        int totalTime = 0;
        int i = 0, j = 0;
        
        while (i < neededTime.length && j < neededTime.length) {
            int currTotal = 0, currMax = 0;
            
            // Find all the balloons having the same color as the 
            // balloon indexed at i, record the total removal time 
            // and the maximum removal time.
            while (j < neededTime.length && colors.charAt(i) == colors.charAt(j)) {
                currTotal += neededTime[j];
                currMax = Math.max(currMax, neededTime[j]);
                j++;
            }
            
            // Once we reach the end of the current group, add the cost of 
            // this group to total_time, and reset two pointers.
            totalTime += currTotal - currMax;
            i = j;
        }
        return totalTime;    
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minCost = function(s, cost) {
    // Initalize two pointers i, j.
    let totalTime = 0;
    let i = 0, j = 0;

    while (i < cost.length && j < cost.length) {
        let currTotal = 0, currMax = 0;

        // Find all the balloons having the same color as the 
        // balloon indexed at i, record the total removal time 
        // and the maximum removal time.
        while (j < cost.length && s[i] == s[j]) {
            currTotal += cost[j];
            currMax = Math.max(currMax, cost[j]);
            j++;
        }

        // Once we reach the end of the current group, add the cost of 
        // this group to total_time, and reset two pointers.
        totalTime += currTotal - currMax;
        i = j;
    }
    return totalTime; 
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        # Initalize two pointers i, j.
        total_time = 0
        i, j = 0, 0
        
        while i < len(neededTime) and j < len(neededTime):
            curr_total = 0
            curr_max = 0
            
            # Find all the balloons having the same color as the 
            # balloon indexed at i, record the total removal time 
            # and the maximum removal time.
            while j < len(neededTime) and colors[i] == colors[j]:
                curr_total += neededTime[j]
                curr_max = max(curr_max, neededTime[j])
                j += 1
            
            # Once we reach the end of the current group, add the cost of 
            # this group to total_time, and reset two pointers.
            total_time += curr_total - curr_max
            i = j
        
        return total_time
```

</details>

<br>

## Approach 2: Advanced 1-Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // totalTime: total time needed to make rope colorful;
        // currMaxTime: maximum time of a balloon needed in this group.
        int totalTime = 0, currMaxTime = 0;
        
        // For each balloon in the array:
        for (int i = 0; i < colors.size(); ++i) {
            // If this balloon is the first balloon of a new group
            // set the currMaxTime as 0.
            if (i > 0 && colors[i] != colors[i - 1]) {
                currMaxTime = 0;
            }
            
            // Increment totalTime by the smaller one.
            // Update currMaxTime as the larger one.
            totalTime += min(currMaxTime, neededTime[i]);
            currMaxTime = max(currMaxTime, neededTime[i]);
        }
        
        // Return totalTime as the minimum removal time.
        return totalTime;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCost(String colors, int[] neededTime) {
        // totalTime: total time needed to make rope colorful;
        // currMaxTime: maximum time of a balloon needed.
        int totalTime = 0, currMaxTime = 0;
        
        // For each balloon in the array:
        for (int i = 0; i < colors.length(); ++i) {
            // If this balloon is the first balloon of a new group
            // set the currMaxTime as 0.
            if (i > 0 && colors.charAt(i) != colors.charAt(i - 1)) {
                currMaxTime = 0;
            }
            
            // Increment totalTime by the smaller one.
            // Update currMaxTime as the larger one.
            totalTime += Math.min(currMaxTime, neededTime[i]);
            currMaxTime = Math.max(currMaxTime, neededTime[i]);
        }
        
        // Return totalTime as the minimum removal time.
        return totalTime;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minCost = function(s, cost) {
    // totalTime: total time needed to make rope colorful;
        // currMaxTime: maximum time of a balloon needed.
        let totalTime = 0, currMaxTime = 0;

        // For each balloon in the array:
        for (let i = 0; i < s.length; ++i) {
            // If this balloon is the first balloon of a new group
            // set the currMaxTime as 0.
            if (i > 0 && s[i] != s[i - 1]) {
                currMaxTime = 0;
            }

            // Increment totalTime by the smaller one.
            // Update currMaxTime as the larger one.
            totalTime += Math.min(currMaxTime, cost[i]);
            currMaxTime = Math.max(currMaxTime, cost[i]);
        }

        // Return totalTime as the minimum removal time.
        return totalTime;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        # totalTime: total time needed to make rope colorful;
        # currMaxTime: maximum time of a balloon needed in this group.
        total_time = 0
        curr_max_time = 0
        
        # For each balloon in the array:
        for i in range(len(colors)):
            # If this balloon is the first balloon of a new group
            # set the curr_max_time as 0.
            if i > 0 and colors[i] != colors[i - 1]:
                curr_max_time = 0
            
            # Increment total_time by the smaller one.
            # Update curr_max_time as the larger one.
            total_time += min(curr_max_time, neededTime[i])
            curr_max_time = max(curr_max_time, neededTime[i])
                
        # Return total_time as the minimum removal time.
        return total_time
```

</details>
