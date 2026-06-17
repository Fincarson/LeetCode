# 1235. Maximum Profit in Job Scheduling

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)  
`Array` `Binary Search` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 1235 - Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)

## Problem

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

### Example 1

```text
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
```

### Example 2

```text
Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.
```

### Example 3

```text
Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
```

## Constraints

- 1 <= startTime.length == endTime.length == profit.length <= 5 * 104
- 1 <= startTime[i] < endTime[i] <= 109
- 1 <= profit[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Earnings From Taxi](https://leetcode.com/problems/maximum-earnings-from-taxi/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Two Best Non-Overlapping Events](https://leetcode.com/problems/two-best-non-overlapping-events/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1235. Maximum Profit in Job Scheduling

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming + Binary Search | C++, Java |
| Bottom-Up Dynamic Programming + Binary Search | C++, Java |
| Sorting + Priority Queue | C++, Java |

## Approach 1: Top-Down Dynamic Programming + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // maximum number of jobs are 50000
    int memo[50001];
    
    int findMaxProfit(vector<vector<int>>& jobs, vector<int>& start, int n, int position) {
        // 0 profit if we have already iterated over all the jobs
        if (position == n) {
            return 0;
        }
        // we have already calculated the answer so no need to go into recursion
        if (memo[position] != -1) {
            return memo[position];
        }
        // nextIndex is the index of next non-conflicting job
        // this step is similar to the binary search as in the java solution
        // lower_bound will return the iterator to the first element which is 
        // equal to or greater than the element at `jobs[position][1]`
        int nextIndex = lower_bound(start.begin(), start.end(), jobs[position][1]) - start.begin();
        
        // find the maximum profit of our two options: skipping or scheduling the current job
        int maxProfit = max(findMaxProfit(jobs, start, n, position + 1), 
                        jobs[position][2] + findMaxProfit(jobs, start, n, nextIndex));
        
        // returning maximum profit and also storing it for future reference (memoization)
        return memo[position] = maxProfit;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        // marking all values to -1 so that we can differentiate 
        // if we have already calculated the answer or not
        memset(memo, -1, sizeof(memo));
        
        // storing job's details into one list 
        // this will help in sorting the jobs while maintaining the other parameters
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());

        // binary search will be used in startTime so store it as separate list
        for (int i = 0; i < profit.size(); i++) {
            startTime[i] = jobs[i][0];
        }
        
        return findMaxProfit(jobs, startTime, profit.size(), 0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // maximum number of jobs are 50000
    int[] memo = new int[50001];
    
    private int findNextJob(int[] startTime, int lastEndingTime) {
        int start = 0, end = startTime.length - 1, nextIndex = startTime.length;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            if (startTime[mid] >= lastEndingTime) {
                nextIndex = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return nextIndex;
    }
    
    private int findMaxProfit(List<List<Integer>> jobs, int[] startTime, int n, int position) {
        // 0 profit if we have already iterated over all the jobs
        if (position == n) {
            return 0;
        }
        
        // return result directly if it's calculated 
        if (memo[position] != -1) {
            return memo[position];
        }
        
        // nextIndex is the index of next non-conflicting job
        int nextIndex = findNextJob(startTime, jobs.get(position).get(1));
        
        // find the maximum profit of our two options: skipping or scheduling the current job
        int maxProfit = Math.max(findMaxProfit(jobs, startTime, n, position + 1), 
                        jobs.get(position).get(2) + findMaxProfit(jobs, startTime, n, nextIndex));
        
        // return maximum profit and also store it for future reference (memoization)
        return memo[position] = maxProfit;
    }
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        List<List<Integer>> jobs = new ArrayList<>();
        
        // marking all values to -1 so that we can differentiate 
        // if we have already calculated the answer or not
        Arrays.fill(memo, -1);
        
        // storing job's details into one list 
        // this will help in sorting the jobs while maintaining the other parameters
        int length = profit.length;
        for (int i = 0; i < length; i++) {
            ArrayList<Integer> currJob = new ArrayList<>();
            currJob.add(startTime[i]);
            currJob.add(endTime[i]);
            currJob.add(profit[i]);
            jobs.add(currJob);
        }
        jobs.sort(Comparator.comparingInt(a -> a.get(0)));
        
        // binary search will be used in startTime so store it as separate list
        for (int i = 0; i < length; i++) {
            startTime[i] = jobs.get(i).get(0);
        }
        
        return findMaxProfit(jobs, startTime, length, 0);
    }
}
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // maximum number of jobs are 50000
    int memo[50001];
    
    int findMaxProfit(vector<int>& startTime, vector<vector<int>>& jobs) {
        int length = startTime.size();
        
        for (int position = length - 1; position >= 0; position--) {
            // it is the profit made by scheduling the current job 
            int currProfit = 0;
            
            // nextIndex is the index of next non-conflicting job
            // this step is similar to the binary search as in the java solution
            // lower_bound will return the iterator to the first element which is 
            // equal to or greater than the element at `jobs[position][1]`
            int nextIndex = lower_bound(startTime.begin(), startTime.end(), jobs[position][1]) - startTime.begin();
            
            // if there is a non-conflicting job possible add it's profit
            // else just consider the curent job profit
            if (nextIndex != length) {
                currProfit = jobs[position][2] + memo[nextIndex];
            } else {
                currProfit = jobs[position][2];
            }
            
            // storing the maximum profit we can achieve by scheduling 
            // non - conflicting jobs from index i to the end of array
            if (position == length - 1) {
                memo[position] = currProfit;
            } else {
                memo[position] = max(currProfit, memo[position + 1]);
            }
        }
        
        return memo[0];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        // storing job's details into one list 
        // this will help in sorting the jobs while maintaining the other parameters
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());

        // binary search will be used in startTime so store it as separate list
        for (int i = 0; i < profit.size(); i++) {
            startTime[i] = jobs[i][0];
        }
        
        return findMaxProfit(startTime, jobs);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // maximum number of jobs are 50000
    int memo[] = new int[50001];
    
    private int findNextJob(int[] startTime, int lastEndingTime) {
        int start = 0, end = startTime.length - 1, nextIndex = startTime.length;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (startTime[mid] >= lastEndingTime) {
                nextIndex = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return nextIndex;
    }
    
    private int findMaxProfit(List<List<Integer>> jobs, int[] startTime) {
        int length = startTime.length;
        
        for (int position = length - 1; position >= 0; position--) {
            // it is the profit made by scheduling the current job 
            int currProfit = 0;
            
            // nextIndex is the index of next non-conflicting job
            int nextIndex = findNextJob(startTime, jobs.get(position).get(1));
            
            // if there is a non-conflicting job possible add it's profit
            // else just consider the curent job profit
            if (nextIndex != length) {
                currProfit = jobs.get(position).get(2) + memo[nextIndex];
            } else {
                currProfit = jobs.get(position).get(2);
            }
            
            // storing the maximum profit we can achieve by scheduling 
            // non - conflicting jobs from index position to the end of array
            if (position == length - 1) {
                memo[position] = currProfit;
            } else {
                memo[position] = Math.max(currProfit, memo[position + 1]);
            }
        }
        
        return memo[0];
    }
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        List<List<Integer>> jobs = new ArrayList<>();
        
        // storing job's details into one list 
        // this will help in sorting the jobs while maintaining the other parameters
        int length = profit.length;
        for (int i = 0; i < length; i++) {
            ArrayList<Integer> currJob = new ArrayList<>();
            currJob.add(startTime[i]);
            currJob.add(endTime[i]);
            currJob.add(profit[i]);
            
            jobs.add(currJob);
        }
        
        jobs.sort(Comparator.comparingInt(a -> a.get(0)));

        // binary search will be used in startTime so store it as separate list
        for (int i = 0; i < length; i++) {
            startTime[i] = jobs.get(i).get(0);
        }
        
        return findMaxProfit(jobs, startTime);
    }
}
```

</details>

<br>

## Approach 3: Sorting + Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMaxProfit(vector<vector<int>>& jobs) {
        int n = jobs.size(), maxProfit = 0;
        // min heap having {endTime, profit}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for (int i = 0; i < n; i++) {
            int start = jobs[i][0], end = jobs[i][1], profit = jobs[i][2];
            
            // keep popping while the heap is not empty and
            // jobs are not conflicting
            // update the value of maxProfit
            while (pq.empty() == 0 && start >= pq.top()[0]) {
                maxProfit = max(maxProfit, pq.top()[1]);
                pq.pop();
            }
            
            // push the job with combined profit
            // if no non-conflicting job is present maxProfit will be 0
            pq.push({end, profit + maxProfit});
        }
        
        // update the value of maxProfit by comparing with
        // profit of jobs that exits in the heap
        while (pq.empty() == 0) {
            maxProfit = max(maxProfit, pq.top()[1]);
            pq.pop();
        }
        
        return maxProfit;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        // storing job's details into one list 
        // this will help in sorting the jobs while maintaining the other parameters
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        return findMaxProfit(jobs);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    class The_Comparator implements Comparator<ArrayList<Integer>> {
        public int compare(ArrayList<Integer> list1, ArrayList<Integer> list2) {
            return list1.get(0) - list2.get(0);
        }
    }
    
    private int findMaxProfit(List<List<Integer>> jobs) {
        int n = jobs.size(), maxProfit = 0;
        // min heap having {endTime, profit}
        PriorityQueue<ArrayList<Integer>> pq = new PriorityQueue<>(new The_Comparator());
        
        for (int i = 0; i < n; i++) {
            int start = jobs.get(i).get(0), end = jobs.get(i).get(1), profit = jobs.get(i).get(2);
            
            // keep popping while the heap is not empty and
            // jobs are not conflicting
            // update the value of maxProfit
            while (pq.isEmpty() == false && start >= pq.peek().get(0)) {
                maxProfit = Math.max(maxProfit, pq.peek().get(1));
                pq.remove();
            }
            
            ArrayList<Integer> combinedJob = new ArrayList<>();
            combinedJob.add(end);
            combinedJob.add(profit + maxProfit);
            
            // push the job with combined profit
            // if no non-conflicting job is present maxProfit will be 0
            pq.add(combinedJob);
        }
        
        // update the value of maxProfit by comparing with
        // profit of jobs that exits in the heap
        while (pq.isEmpty() == false) {
            maxProfit = Math.max(maxProfit, pq.peek().get(1));
            pq.remove();
        }
        
        return maxProfit;
    }
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        List<List<Integer>> jobs = new ArrayList<>();
        
        // storing job's details into one list 
        // this will help in sorting the jobs while maintaining the other parameters
        int length = profit.length;
        for (int i = 0; i < length; i++) {
            ArrayList<Integer> currJob = new ArrayList<>();
            currJob.add(startTime[i]);
            currJob.add(endTime[i]);
            currJob.add(profit[i]);
            
            jobs.add(currJob);
        }
        
        jobs.sort(Comparator.comparingInt(a -> a.get(0)));
        return findMaxProfit(jobs);
    }
}
```

</details>
