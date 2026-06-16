# 502. IPO

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/ipo/)  
`Array` `Greedy` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 502 - IPO](https://leetcode.com/problems/ipo/)

## Problem

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

### Example 1

```text
Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
```

### Example 2

```text
Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6
```

## Constraints

- 1 <= k <= 105
- 0 <= w <= 109
- n == profits.length
- n == capital.length
- 1 <= n <= 105
- 0 <= profits[i] <= 104
- 0 <= capital[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Subsequence Score](https://leetcode.com/problems/maximum-subsequence-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Elegance of a K-Length Subsequence](https://leetcode.com/problems/maximum-elegance-of-a-k-length-subsequence/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 502. IPO

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | C++, Java, Python3 |

## Solution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> q;
        int ptr = 0;
        for (int i = 0; i < k; i++) {
            while (ptr < n && projects[ptr].first <= w) {
                q.push(projects[ptr++].second);
            }
            if (q.empty()) {
                break;
            }
            w += q.top();
            q.pop();
        }
        return w;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    class Project implements Comparable<Project> {
        int capital, profit;

        public Project(int capital, int profit) {
            this.capital = capital;
            this.profit = profit;
        }

        public int compareTo(Project project) {
            return capital - project.capital;
        }
    }

    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        Project[] projects = new Project[n];
        for (int i = 0; i < n; i++) {
            projects[i] = new Project(capital[i], profits[i]);
        }
        Arrays.sort(projects);
        // PriorityQueue is a min heap, but we need a max heap, so we use
        // Collections.reverseOrder()
        PriorityQueue<Integer> q = new PriorityQueue<Integer>(n, Collections.reverseOrder());
        int ptr = 0;
        for (int i = 0; i < k; i++) {
            while (ptr < n && projects[ptr].capital <= w) {
                q.add(projects[ptr++].profit);
            }
            if (q.isEmpty()) {
                break;
            }
            w += q.poll();
        }
        return w;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int],
                             capital: List[int]) -> int:
        n = len(profits)
        projects = list(zip(capital, profits))
        projects.sort()
        # heapq is a min heap, but we need a max heap
        # so we will store negated elements
        q = []
        ptr = 0
        for i in range(k):
            while ptr < n and projects[ptr][0] <= w:
                # push a negated element
                heappush(q, -projects[ptr][1])
                ptr += 1
            if not q:
                break
            # pop a negated element
            w += -heappop(q)
        return w
```

</details>
