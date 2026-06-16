# 1187. Make Array Strictly Increasing

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/make-array-strictly-increasing/)  
`Array` `Binary Search` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 1187 - Make Array Strictly Increasing](https://leetcode.com/problems/make-array-strictly-increasing/)

## Problem

Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.

### Example 1

```text
Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
```

### Example 2

```text
Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
```

### Example 3

```text
Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.
```

## Constraints

- 1 <= arr1.length, arr2.length <= 2000
- 0 <= arr1[i], arr2[i] <= 10^9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Make Array Non-decreasing or Non-increasing](https://leetcode.com/problems/make-array-non-decreasing-or-non-increasing/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1187. Make Array Strictly Increasing

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-down Dynamic Programming | Java, Python3 |
| Bottom-up Dynamic Programming | Java, Python3 |

## Approach 1: Top-down Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution { 
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        Arrays.sort(arr2);
        
        int answer = dfs(0, -1, arr1, arr2);
        
        return answer < 2_001 ? answer : -1;
    }
    
    Map<Pair<Integer, Integer>, Integer> dp = new HashMap<>();
    private int dfs(int i, int prev, int[] arr1, int[] arr2) {
        if (i == arr1.length) {
            return 0;
        }
        if (dp.containsKey(new Pair<>(i, prev))) {
            return dp.get(new Pair<>(i, prev));
        }

        int cost = 2_001;

        // If arr1[i] is already greater than prev, we can leave it be.
        if (arr1[i] > prev) {
            cost = dfs(i + 1, arr1[i], arr1, arr2);
        }

        // Find a replacement with the smallest value in arr2.
        int idx = bisectRight(arr2, prev);

        // Replace arr1[i], with a cost of 1 operation.
        if (idx < arr2.length) {
            cost = Math.min(cost, 1 + dfs(i + 1, arr2[idx], arr1, arr2));
        }

        dp.put(new Pair<>(i, prev), cost);
        return cost;
    }
    
    private static int bisectRight(int[] arr, int value) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] <= value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    } 
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        dp = {}
        arr2.sort()
        
        def dfs(i, prev):
            if i == len(arr1):
                return 0
            if (i, prev) in dp:
                return dp[(i, prev)]

            cost = float('inf')
            
            # If arr1[i] is already greater than prev, we can leave it be.
            if arr1[i] > prev:
                cost = dfs(i + 1, arr1[i])
            
            # Find a replacement with the smallest value in arr2.
            idx = bisect.bisect_right(arr2, prev)
            
            # Replace arr1[i], with a cost of 1 operation.
            if idx < len(arr2):
                cost = min(cost, 1 + dfs(i + 1, arr2[idx]))

            dp[(i, prev)] = cost
            return cost
        
        res = dfs(0, -1)
        
        return res if res < float('inf') else -1
```

</details>

<br>

## Approach 2: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        Map<Integer, Integer> dp = new HashMap<>();
        Arrays.sort(arr2);
        int n = arr2.length;
        dp.put(-1, 0);

        for (int i = 0; i < arr1.length; i++) {
            Map<Integer, Integer> newDp = new HashMap<>();
            for (int prev : dp.keySet()) {
                if (arr1[i] > prev) {
                    newDp.put(arr1[i], Math.min(newDp.getOrDefault(arr1[i], Integer.MAX_VALUE), dp.get(prev)));
                }
                int idx = bisectRight(arr2, prev);
                if (idx < n) {
                    newDp.put(arr2[idx], Math.min(newDp.getOrDefault(arr2[idx], Integer.MAX_VALUE), 1 + dp.get(prev)));
                }
            }
            dp = newDp;
        }
        
        int answer = Integer.MAX_VALUE;
        for (int value : dp.values()) {
            answer = Math.min(answer, value);
        }
        
        return answer == Integer.MAX_VALUE ? -1 : answer;
    }
    
    private static int bisectRight(int[] arr, int value) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] <= value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        dp = {-1: 0}
        arr2.sort()
        n = len(arr2)
        
        for i in range(len(arr1)):
            new_dp = collections.defaultdict(lambda: float('inf'))
            for prev in dp:
                if arr1[i] > prev:
                    new_dp[arr1[i]] = min(new_dp[arr1[i]], dp[prev])
                idx = bisect.bisect_right(arr2, prev)
                if idx < n:
                    new_dp[arr2[idx]] = min(new_dp[arr2[idx]], 1 + dp[prev])
            dp = new_dp

        return min(dp.values()) if dp else -1
```

</details>
