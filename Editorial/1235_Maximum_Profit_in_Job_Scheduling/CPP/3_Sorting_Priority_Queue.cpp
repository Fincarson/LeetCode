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
