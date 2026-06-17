# 546. Remove Boxes

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/remove-boxes/)  
`Array` `Dynamic Programming` `Memoization`

**Problem Link:** [LeetCode 546 - Remove Boxes](https://leetcode.com/problems/remove-boxes/)

## Problem

You are given several boxes with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.

Return the maximum points you can get.

### Example 1

```text
Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1]
----> [1, 3, 3, 4, 3, 1] (3*3=9 points)
----> [1, 3, 3, 3, 1] (1*1=1 points)
----> [1, 1] (3*3=9 points)
----> [] (2*2=4 points)
```

### Example 2

```text
Input: boxes = [1,1,1]
Output: 9
```

### Example 3

```text
Input: boxes = [1]
Output: 1
```

## Constraints

- 1 <= boxes.length <= 100
- 1 <= boxes[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Strange Printer](https://leetcode.com/problems/strange-printer/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Number of Unique Flavors After Sharing K Candies](https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 546. Remove Boxes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force Approach [Time Limit Exceeded] | Java |
| Top-Down Dynamic Programming | Java |

## Approach 1: Brute Force Approach [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int removeBoxes(int[] boxes) {
        return remove(boxes);
    }
   
    public int remove(int[] boxes) {
        if (boxes.length == 0) {
            return 0;
        }
        
        int res = 0;
    
        for (int i = 0, j = i + 1; i < boxes.length; i++) {
            while (j < boxes.length && boxes[i] == boxes[j]) {
                j++;
            }
            
            int[] newboxes = new int[boxes.length - (j - i)];
            for (int k = 0, p = 0; k < boxes.length; k++) {
                if (k == i) {
                    k = j;
                }
                if (k < boxes.length) {
                    newboxes[p++] = boxes[k];
                }
            }
            res = Math.max(res, remove(newboxes) + (j - i) * (j - i));
        }
    
        return res;
    }
}
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int removeBoxes(int[] boxes) {
        int[][][] dp = new int[100][100][100];
        return calculatePoints(boxes, dp, 0, boxes.length - 1, 0);
    }
    
    public int calculatePoints(int[] boxes, int[][][] dp, int l, int r, int k) {
        if (l > r) {
            return 0;
        }
        
        while (r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        
        if (dp[l][r][k] != 0) {
            return dp[l][r][k];
        }
        
        dp[l][r][k] = calculatePoints(boxes, dp, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                dp[l][r][k] = Math.max(dp[l][r][k], calculatePoints(boxes, dp, l, i, k + 1) 
                              + calculatePoints(boxes, dp, i + 1, r - 1, 0));
            }
        }
                              
        return dp[l][r][k];
    }
}
```

</details>
