# 826. Most Profit Assigning Work

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/most-profit-assigning-work/)  
`Array` `Two Pointers` `Binary Search` `Greedy` `Sorting`

**Problem Link:** [LeetCode 826 - Most Profit Assigning Work](https://leetcode.com/problems/most-profit-assigning-work/)

## Problem

You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

- difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
- worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).

Every worker can be assigned at most one job, but one job can be completed multiple times.

- For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.

Return the maximum profit we can achieve after assigning the workers to the jobs.

### Example 1

```text
Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
```

### Example 2

```text
Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
Output: 0
```

## Constraints

- n == difficulty.length
- n == profit.length
- m == worker.length
- 1 <= n, m <= 104
- 1 <= difficulty[i], profit[i], worker[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Successful Pairs of Spells and Potions](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Matching of Players With Trainers](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 826. Most Profit Assigning Work

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search and Greedy (Sort by Job Difficulty) | C++, Java, Python3 |
| Binary Search and Greedy (Sort by profit) | C++, Java, Python3 |
| Greedy and Two-Pointers | C++, Java, Python3 |
| Memoization | C++, Java, Python3 |

## Approach 1: Binary Search and Greedy (Sort by Job Difficulty)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> jobProfile;
        jobProfile.push_back({0, 0});
        for (int i = 0; i < difficulty.size(); i++) {
            jobProfile.push_back({difficulty[i], profit[i]});
        }

        // Sort by difficulty values in increasing order.
        sort(jobProfile.begin(), jobProfile.end());
        for (int i = 0; i < jobProfile.size() - 1; i++) {
            jobProfile[i + 1].second =
                max(jobProfile[i].second, jobProfile[i + 1].second);
        }

        int netProfit = 0;
        for (int i = 0; i < worker.size(); i++) {
            int ability = worker[i];

            // Find the job with just smaller or equal difficulty than ability.
            int l = 0, r = jobProfile.size() - 1, jobProfit = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobProfile[mid].first <= ability) {
                    jobProfit = max(jobProfit, jobProfile[mid].second);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            // Increment profit of current worker to total profit.
            netProfit += jobProfit;
        }
        return netProfit;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxProfitAssignment(
        int[] difficulty,
        int[] profit,
        int[] worker
    ) {
        List<int[]> jobProfile = new ArrayList<>();
        jobProfile.add(new int[] { 0, 0 });
        for (int i = 0; i < difficulty.length; i++) {
            jobProfile.add(new int[] { difficulty[i], profit[i] });
        }

        // Sort by difficulty values in increasing order.
        Collections.sort(jobProfile, (a, b) -> Integer.compare(a[0], b[0]));
        for (int i = 0; i < jobProfile.size() - 1; i++) {
            jobProfile.get(i + 1)[1] = Math.max(
                jobProfile.get(i)[1],
                jobProfile.get(i + 1)[1]
            );
        }

        int netProfit = 0;
        for (int i = 0; i < worker.length; i++) {
            int ability = worker[i];

            // Find the job with just smaller or equal difficulty than ability.
            int l = 0, r = jobProfile.size() - 1, jobProfit = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobProfile.get(mid)[0] <= ability) {
                    jobProfit = Math.max(jobProfit, jobProfile.get(mid)[1]);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            // Increment profit of current worker to total profit.
            netProfit += jobProfit;
        }
        return netProfit;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfitAssignment(
        self, difficulty: List[int], profit: List[int], worker: List[int]
    ) -> int:
        job_profile = [(0, 0)]
        for i in range(len(difficulty)):
            job_profile.append((difficulty[i], profit[i]))
        # Sort by difficulty values in increasing order.

        job_profile.sort()
        for i in range(len(job_profile) - 1):
            job_profile[i + 1] = (
                job_profile[i + 1][0],
                max(job_profile[i][1], job_profile[i + 1][1]),
            )
        net_profit = 0
        for i in range(len(worker)):
            ability = worker[i]

            # Find the job with just smaller or equal difficulty than ability.

            l, r = 0, len(job_profile) - 1
            job_profit = 0
            while l <= r:
                mid = (l + r) // 2
                if job_profile[mid][0] <= ability:
                    job_profit = max(job_profit, job_profile[mid][1])
                    l = mid + 1
                else:
                    r = mid - 1
            # Increment profit of current worker to total profit.

            net_profit += job_profit
        return net_profit
```

</details>

<br>

## Approach 2: Binary Search and Greedy (Sort by profit)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> jobProfile;
        jobProfile.push_back({0, 0});
        for (int i = 0; i < difficulty.size(); i++) {
            jobProfile.push_back({profit[i], difficulty[i]});
        }

        // Sort in decreasing order of profit.
        sort(jobProfile.begin(), jobProfile.end());
        reverse(jobProfile.begin(), jobProfile.end());
        for (int i = 0; i < jobProfile.size() - 1; i++) {
            jobProfile[i + 1].second =
                min(jobProfile[i].second, jobProfile[i + 1].second);
        }

        int netProfit = 0;
        for (int i = 0; i < worker.size(); i++) {
            int ability = worker[i];
            // Maximize profit using binary search.
            int l = 0, r = jobProfile.size() - 1, jobProfit = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobProfile[mid].second <= ability) {
                    jobProfit = max(jobProfit, jobProfile[mid].first);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // Add profit of each worker to total profit.
            netProfit += jobProfit;
        }
        return netProfit;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxProfitAssignment(
        int[] difficulty,
        int[] profit,
        int[] worker
    ) {
        List<int[]> jobProfile = new ArrayList<>();
        jobProfile.add(new int[] { 0, 0 });
        for (int i = 0; i < difficulty.length; i++) {
            jobProfile.add(new int[] { profit[i], difficulty[i] });
        }

        // Sort in decreasing order of profit.
        jobProfile.sort((a, b) -> Integer.compare(b[0], a[0]));
        for (int i = 0; i < jobProfile.size() - 1; i++) {
            jobProfile.get(i + 1)[1] = Math.min(
                jobProfile.get(i)[1],
                jobProfile.get(i + 1)[1]
            );
        }

        int netProfit = 0;
        for (int i = 0; i < worker.length; i++) {
            int ability = worker[i];
            // Maximize profit using binary search.
            int l = 0, r = jobProfile.size() - 1, jobProfit = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobProfile.get(mid)[1] <= ability) {
                    jobProfit = Math.max(jobProfit, jobProfile.get(mid)[0]);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // Add profit of each worker to total profit.
            netProfit += jobProfit;
        }
        return netProfit;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfitAssignment(
        self, difficulty: List[int], profit: List[int], worker: List[int]
    ) -> int:
        job_profile = [(0, 0)]
        for i in range(len(difficulty)):
            job_profile.append((profit[i], difficulty[i]))

        # Sort in decreasing order of profit.
        job_profile.sort(reverse=True)
        for i in range(len(job_profile) - 1):
            job_profile[i + 1] = (
                job_profile[i + 1][0],
                min(job_profile[i][1], job_profile[i + 1][1]),
            )

        net_profit = 0
        for ability in worker:
            # Maximize profit using binary search.
            l, r = 0, len(job_profile) - 1
            job_profit = 0
            while l <= r:
                mid = (l + r) // 2
                if job_profile[mid][1] <= ability:
                    job_profit = max(job_profit, job_profile[mid][0])
                    r = mid - 1
                else:
                    l = mid + 1
            # Add profit of each worker to total profit.
            net_profit += job_profit

        return net_profit
```

</details>

<br>

## Approach 3: Greedy and Two-Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> jobProfile;
        for (int i = 0; i < difficulty.size(); i++) {
            jobProfile.push_back({difficulty[i], profit[i]});
        }

        // Sort both worker and jobProfile arrays
        sort(worker.begin(), worker.end());
        sort(jobProfile.begin(), jobProfile.end());

        int netProfit = 0, maxProfit = 0, index = 0;
        for (int i = 0; i < worker.size(); i++) {
            // While the index has not reached the end and worker can pick a job
            // with greater difficulty move ahead.
            while (index < difficulty.size() and
                   worker[i] >= jobProfile[index].first) {
                maxProfit = max(maxProfit, jobProfile[index].second);
                index++;
            }
            netProfit += maxProfit;
        }
        return netProfit;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxProfitAssignment(
        int[] difficulty,
        int[] profit,
        int[] worker
    ) {
        List<int[]> jobProfile = new ArrayList<>();
        for (int i = 0; i < difficulty.length; i++) {
            jobProfile.add(new int[] { difficulty[i], profit[i] });
        }

        // Sort both worker and jobProfile arrays
        Arrays.sort(worker);
        jobProfile.sort((a, b) -> Integer.compare(a[0], b[0]));

        int netProfit = 0, maxProfit = 0, index = 0;
        for (int i = 0; i < worker.length; i++) {
            // While the index has not reached the end and worker can pick a job
            // with greater difficulty move ahead.
            while (
                index < difficulty.length &&
                worker[i] >= jobProfile.get(index)[0]
            ) {
                maxProfit = Math.max(maxProfit, jobProfile.get(index)[1]);
                index++;
            }
            netProfit += maxProfit;
        }
        return netProfit;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfitAssignment(
        self, difficulty: List[int], profit: List[int], worker: List[int]
    ) -> int:
        job_profile = [
            (difficulty[i], profit[i]) for i in range(len(difficulty))
        ]

        # Sort both worker and job_profile arrays

        worker.sort()
        job_profile.sort()

        net_profit, max_profit, index = 0, 0, 0
        for ability in worker:
            # While the index has not reached the end and worker can pick a job
            # with greater difficulty move ahead.

            while index < len(difficulty) and ability >= job_profile[index][0]:
                max_profit = max(max_profit, job_profile[index][1])
                index += 1
            net_profit += max_profit
        return net_profit
```

</details>

<br>

## Approach 4: Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        // Find maximum ability in the worker array.
        int maxAbility = *max_element(begin(worker), end(worker));
        vector<int> jobs(maxAbility + 1, 0);
        for (int i = 0; i < difficulty.size(); i++) {
            if (difficulty[i] <= maxAbility)
                jobs[difficulty[i]] = max(jobs[difficulty[i]], profit[i]);
        }
        // Take maxima of prefixes.
        for (int i = 1; i <= maxAbility; i++)
            jobs[i] = max(jobs[i], jobs[i - 1]);

        int netProfit = 0;
        for (auto ability : worker) {
            int maxProfit = jobs[ability];
            netProfit += maxProfit;
        }
        return netProfit;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxProfitAssignment(
        int[] difficulty,
        int[] profit,
        int[] worker
    ) {
        // Find maximum ability in the worker array.
        int maxAbility = Arrays.stream(worker).max().getAsInt();
        int[] jobs = new int[maxAbility + 1];

        for (int i = 0; i < difficulty.length; i++) {
            if (difficulty[i] <= maxAbility) {
                jobs[difficulty[i]] = Math.max(jobs[difficulty[i]], profit[i]);
            }
        }

        // Take maxima of prefixes.
        for (int i = 1; i <= maxAbility; i++) {
            jobs[i] = Math.max(jobs[i], jobs[i - 1]);
        }

        int netProfit = 0;
        for (int ability : worker) {
            netProfit += jobs[ability];
        }
        return netProfit;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfitAssignment(
        self, difficulty: List[int], profit: List[int], worker: List[int]
    ) -> int:
        # Find maximum ability in the worker array.

        maxAbility = max(worker)
        jobs = [0] * (maxAbility + 1)

        for i in range(len(difficulty)):
            if difficulty[i] <= maxAbility:
                jobs[difficulty[i]] = max(jobs[difficulty[i]], profit[i])
        # Take maxima of prefixes.

        for i in range(1, maxAbility + 1):
            jobs[i] = max(jobs[i], jobs[i - 1])
        netProfit = 0
        for ability in worker:
            netProfit += jobs[ability]
        return netProfit
```

</details>
