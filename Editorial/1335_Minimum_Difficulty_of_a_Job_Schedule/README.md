# 1335. Minimum Difficulty of a Job Schedule

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1335 - Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/)

## Problem

You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

### Example 1

```text
Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7
```

### Example 2

```text
Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
```

### Example 3

```text
Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.
```

## Constraints

- 1 <= jobDifficulty.length <= 300
- 0 <= jobDifficulty[i] <= 1000
- 1 <= d <= 10

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1335. Minimum Difficulty of a Job Schedule

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-down DP | Java, Python3 |
| Bottom-up 2D DP | Java, Python3 |
| Bottom-up 1D DP | Java, Python3 |
| Monotonic Stack - Better Time Complexity | Java, Python3 |

## Approach 1: Top-down DP

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {

        int n = jobDifficulty.length;
        // Edge case: make sure there is at least one job per day
        if (n < d) {
            return -1;
        }

        int[][] mem = new int[n][d + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= d; j++) {
                mem[i][j] = -1;
            }
        }

        return minDiff(0, d, jobDifficulty, mem);
    }

    private int minDiff(int i, int daysRemaining, int[] jobDifficulty, int[][] mem) {
        // Use memoization to avoid repeated computation of states
        if (mem[i][daysRemaining] != -1) {
            return mem[i][daysRemaining];
        }

        // Base case: finish all remaining jobs in the last day
        if (daysRemaining == 1) {
            int res = 0;
            for (int j = i; j < jobDifficulty.length; j++) {
                res = Math.max(res, jobDifficulty[j]);
            }
            return res;
        }

        int res = Integer.MAX_VALUE;
        int dailyMaxJobDiff = 0;
        // Iterate through possible starting index for the next day
        // and ensure we have at least one job for each remaining day.
        for (int j = i; j < jobDifficulty.length - daysRemaining + 1; j++) {
            dailyMaxJobDiff = Math.max(dailyMaxJobDiff, jobDifficulty[j]);
            res = Math.min(res, dailyMaxJobDiff + minDiff(j + 1, daysRemaining - 1, jobDifficulty, mem));
        }
        mem[i][daysRemaining] = res;
        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        # Edge case: make sure there is at least one job per day
        if n < d:
            return -1

        # Precompute the maximum job difficulty for remaining jobs
        max_job_remaining = jobDifficulty[:]
        for i in range(n - 2, -1, -1):
            max_job_remaining[i] = max(max_job_remaining[i], max_job_remaining[i + 1])

        # Use memoization to avoid repeated computation of min_diff states
        @cache
        def min_diff(i, days_remaining):
            # Base case: finish all remaining jobs in the last day
            if days_remaining == 1:
                return max_job_remaining[i]

            res = float('inf')
            daily_max_job_diff = 0 # keep track of the maximum difficulty for today

            # Iterate through possible starting index for the next day
            # and ensure we have at least one job for each remaining day.
            for j in range(i, n - days_remaining + 1):
                daily_max_job_diff = max(daily_max_job_diff, jobDifficulty[j])
                res = min(res, daily_max_job_diff + min_diff(j + 1, days_remaining - 1))

            return res

        return min_diff(0, d)
```

</details>

<br>

## Approach 2: Bottom-up 2D DP

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;
        // Initialize the minDiff matrix to record the minimum difficulty
        // of the job schedule
        int[][] minDiff = new int[d + 1][n + 1];
        for (int daysRemaining = 0; daysRemaining <= d; daysRemaining++) {
            for (int i = 0; i < n; i++) {
                minDiff[daysRemaining][i] = Integer.MAX_VALUE;
            }
        }
        for (int daysRemaining = 1; daysRemaining <= d; daysRemaining++) {
            for (int i = 0; i < n - daysRemaining + 1; i++) {
                int dailyMaxJobDiff = 0;
                for (int j = i + 1; j < n - daysRemaining + 2; j++) {
                    // Use dailyMaxJobDiff to record maximum job difficulty
                    dailyMaxJobDiff = Math.max(dailyMaxJobDiff, jobDifficulty[j - 1]);
                    if (minDiff[daysRemaining - 1][j] != Integer.MAX_VALUE) {
                        minDiff[daysRemaining][i] = Math.min(minDiff[daysRemaining][i],
                                                             dailyMaxJobDiff + minDiff[daysRemaining - 1][j]);
                    }
                }
            }
        }
        return minDiff[d][0] < Integer.MAX_VALUE ? minDiff[d][0] : -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        # Initialize the min_diff matrix to record the minimum difficulty
        # of the job schedule        
        min_diff = [[float('inf')] * n + [0] for i in range(d + 1)]
        for days_remaining in range(1, d + 1):
            for i in range(n - days_remaining + 1):
                daily_max_job_diff = 0
                for j in range(i + 1, n - days_remaining + 2):
                    # Use daily_max_job_diff to record maximum job difficulty
                    daily_max_job_diff = max(daily_max_job_diff, jobDifficulty[j - 1])
                    min_diff[days_remaining][i] = min(min_diff[days_remaining][i],
                                                      daily_max_job_diff + min_diff[days_remaining - 1][j])
        if min_diff[d][0] == float('inf'):
            return -1
        return min_diff[d][0]
```

</details>

<br>

## Approach 3: Bottom-up 1D DP

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;
        // Initialize the minDiff matrix to record the minimum difficulty
        // of the job schedule    
        int[] minDiffNextDay = new int[n + 1];
        for (int i = 0; i < n; i++) {
            minDiffNextDay[i] = Integer.MAX_VALUE;
        }
        for (int daysRemaining = 1; daysRemaining <= d; daysRemaining++) {
            int[] minDiffCurrDay = new int[n + 1];
            for (int i = 0; i < n; i++) {
                minDiffCurrDay[i] = Integer.MAX_VALUE;
            }
            for (int i = 0; i < n - daysRemaining + 1; i++) {
                int dailyMaxJobDiff = 0;
                for (int j = i + 1; j < n - daysRemaining + 2; j++) {
                    // Use dailyMaxJobDiff to record maximum job difficulty
                    dailyMaxJobDiff = Math.max(dailyMaxJobDiff, jobDifficulty[j - 1]);
                    if (minDiffNextDay[j] != Integer.MAX_VALUE) {
                        minDiffCurrDay[i] = Math.min(minDiffCurrDay[i],
                                                     dailyMaxJobDiff + minDiffNextDay[j]);
                    }
                }
            }
            minDiffNextDay = minDiffCurrDay;
        }
        return minDiffNextDay[0] < Integer.MAX_VALUE ? minDiffNextDay[0] : -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        # Initialize the min_diff matrix to record the minimum difficulty
        # of the job schedule
        min_diff_next_day = [float('inf')] * n + [0]

        for days_remaining in range(1, d + 1):
            min_diff_curr_day = [float('inf')] * n + [0]
            for i in range(n - days_remaining + 1):
                daily_max_job_diff = 0
                for j in range(i + 1, n - days_remaining + 2):
                    # Use daily_max_job_diff to record maximum job difficulty
                    daily_max_job_diff = max(daily_max_job_diff, jobDifficulty[j - 1])
                    min_diff_curr_day[i] = min(min_diff_curr_day[i],
                                               daily_max_job_diff + min_diff_next_day[j])
            min_diff_next_day = min_diff_curr_day

        return min_diff_next_day[0] if min_diff_next_day[0] < float('inf') else -1
```

</details>

<br>

## Approach 4: Monotonic Stack - Better Time Complexity

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;
        if (n < d) {
            return -1;
        }

        // min_diff_curr_day and min_diff_prev_day record the minimum total job difficulty
        // for the current day and previous day, respectively
        int[] minDiffPrevDay = new int[n];
        int[] minDiffCurrDay = new int[n];
        int[] tmp;

        Arrays.fill(minDiffPrevDay, 1000);
        Deque<Integer> stack = new ArrayDeque<>();

        for (int day = 0; day < d; ++day) {
            // Use a monotonically decreasing stack to record job difficulties
            stack.clear();
            // The number of jobs needs to be no less than number of days passed.
            for (int i = day; i < n; i++) {
                // We initialize min_diff_curr_day[i] as only performing 1 job at the i-th index.
                // At day 0, the minimum total job difficulty is to complete the 0th job only.
                // Otherwise, we increment min_diff_prev_day[i - 1] by the i-th job difficulty
                minDiffCurrDay[i] = i > 0 ? minDiffPrevDay[i - 1] + jobDifficulty[i] : jobDifficulty[i];

                // When we find the last element in the stack is smaller than or equal to current job,
                // we need to pop out the element to maintain a monotonic decreasing stack.
                while (!stack.isEmpty() && jobDifficulty[stack.peek()] <= jobDifficulty[i]) {
                    // If we include all jobs with index j+1 to i to the current d,
                    // total job difficulty of the current d will be increased
                    // by the amount of jobDifficulty[i] - jobDifficulty[j]
                    int j = stack.pop();
                    int diffIncr = jobDifficulty[i] - jobDifficulty[j];
                    minDiffCurrDay[i] = Math.min(minDiffCurrDay[i], minDiffCurrDay[j] + diffIncr);
                }

                // When the last element in the stack is larger than current element,
                // if we include all jobs with index j+1 to i to the current d
                // the overall job difficulty will not change
                if (!stack.isEmpty()) {
                    minDiffCurrDay[i] = Math.min(minDiffCurrDay[i], minDiffCurrDay[stack.peek()]);
                }

                // Update the monotonic stack by adding in the current index
                stack.push(i);
            }
            tmp = minDiffPrevDay;
            minDiffPrevDay = minDiffCurrDay;
            minDiffCurrDay = tmp;
        }
        return minDiffPrevDay[n - 1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDifficulty(self, jobDifficulty, d):
        n = len(jobDifficulty)
        if n < d:
            return -1

        # min_diff_curr_day and min_diff_prev_day record the minimum total job difficulty
        # for the current day and previous day, respectively
        min_diff_prev_day, min_diff_curr_day = [float('inf')] * n, [float('inf')] * n

        for day in range(d):
            # Use a monotonically decreasing stack to record job difficulties
            stack = []

            # The number of jobs needs to be no less than number of days passed.
            for i in range(day, n):

                # We initialize min_diff_curr_day[i] as only performing 1 job at the i-th index.
                # At day 0, the minimum total job difficulty is to complete the 0th job only.
                if i == 0:
                    min_diff_curr_day[i] = jobDifficulty[0]
                # Otherwise, we increment min_diff_prev_day[i - 1] by the i-th job difficulty
                else:
                    min_diff_curr_day[i] = min_diff_prev_day[i - 1] + jobDifficulty[i]

                # When we find the last element in the stack is smaller than or equal to current job,
                # we need to pop out the element to maintain a monotonic decreasing stack.
                while stack and jobDifficulty[stack[-1]] <= jobDifficulty[i]:

                    # If we include all jobs with index j+1 to i to the current day,
                    # total job difficulty of the current day will be increased.
                    # by the amount of jobDifficulty[i] - jobDifficulty[j]
                    j = stack.pop()
                    diff_incr = jobDifficulty[i] - jobDifficulty[j]
                    min_diff_curr_day[i] = min(min_diff_curr_day[i], min_diff_curr_day[j] + diff_incr)

                # When the last element in the stack is larger than current element,
                # If we include all jobs with index j+1 to i to the current day,
                # the overall job difficulty will not change.
                if stack:
                    min_diff_curr_day[i] = min(min_diff_curr_day[i], min_diff_curr_day[stack[-1]])

                # Update the monotonic stack by adding in the current index
                stack.append(i)

            min_diff_prev_day, min_diff_curr_day = min_diff_curr_day, min_diff_prev_day

        return min_diff_prev_day[-1]
```

</details>
