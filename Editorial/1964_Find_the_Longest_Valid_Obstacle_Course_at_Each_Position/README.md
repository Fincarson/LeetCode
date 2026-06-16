# 1964. Find the Longest Valid Obstacle Course at Each Position

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/)  
`Array` `Binary Search` `Binary Indexed Tree`

**Problem Link:** [LeetCode 1964 - Find the Longest Valid Obstacle Course at Each Position](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/)

## Problem

You want to build some obstacle courses. You are given a 0-indexed integer array obstacles of length n, where obstacles[i] describes the height of the ith obstacle.

For every index i between 0 and n - 1 (inclusive), find the length of the longest obstacle course in obstacles such that:

- You choose any number of obstacles between 0 and i inclusive.
- You must include the ith obstacle in the course.
- You must put the chosen obstacles in the same order as they appear in obstacles.
- Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.

Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.

### Example 1

```text
Input: obstacles = [1,2,3,2]
Output: [1,2,3,3]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [1], [1] has length 1.
- i = 1: [1,2], [1,2] has length 2.
- i = 2: [1,2,3], [1,2,3] has length 3.
- i = 3: [1,2,3,2], [1,2,2] has length 3.
```

### Example 2

```text
Input: obstacles = [2,2,1]
Output: [1,2,1]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [2], [2] has length 1.
- i = 1: [2,2], [2,2] has length 2.
- i = 2: [2,2,1], [1] has length 1.
```

### Example 3

```text
Input: obstacles = [3,1,5,6,4,2]
Output: [1,1,2,3,2,2]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [3], [3] has length 1.
- i = 1: [3,1], [1] has length 1.
- i = 2: [3,1,5], [3,5] has length 2. [1,5] is also valid.
- i = 3: [3,1,5,6], [3,5,6] has length 3. [1,5,6] is also valid.
- i = 4: [3,1,5,6,4], [3,4] has length 2. [1,4] is also valid.
- i = 5: [3,1,5,6,4,2], [1,2] has length 2.
```

## Constraints

- n == obstacles.length
- 1 <= n <= 105
- 1 <= obstacles[i] <= 107

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1964. Find the Longest Valid Obstacle Course at Each Position

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy + Binary Search. | C++, Java, Python3 |

## Approach: Greedy + Binary Search.

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        
        // lis[i] records the lowest increasing sequence of length i + 1.
        vector<int> answer(n, 1), lis;
        
        for (int i = 0; i < n; ++i) {
            // Find the rightmost insertion position idx.
            int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
            if (idx == lis.size())
                lis.push_back(obstacles[i]);
            else
                lis[idx] = obstacles[i];
            answer[i] = idx + 1;
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    List<Integer> answer;
    // Find the rightmost insertion position. We use a fixed-length array and a changeable right boundary 
    // to represent an arraylist of dynamic size.
    private int bisectRight(int[] A, int target, int right) {
        if (right == 0)
            return 0;
        int left = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    
    public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
        int n = obstacles.length, lisLength = 0;
        
        // lis[i] records the lowest increasing sequence of length i + 1.
        int[] answer = new int[n], lis = new int[n];

        for (int i = 0; i < n; ++i) {
            int height = obstacles[i];
            
            // Find the rightmost insertion position idx.
            int idx = bisectRight(lis, height, lisLength);
            if (idx == lisLength)
                lisLength++;

            lis[idx] = height;
            answer[i] = idx + 1;
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        n = len(obstacles)
        answer = [1] * n
        
        # lis[i] records the lowest increasing sequence of length i + 1.
        lis = []
    
        for i, height in enumerate(obstacles):
            # Find the rightmost insertion position idx.
            idx = bisect.bisect_right(lis, height)
            
            if idx == len(lis):
                lis.append(height)
            else:
                lis[idx] = height
            answer[i] = idx + 1
            
        return answer
```

</details>
