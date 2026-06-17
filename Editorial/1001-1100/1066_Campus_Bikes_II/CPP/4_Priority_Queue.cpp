class Solution {
public:
    // Manhattan distance
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    // Count the number of ones using Brian Kernighan’s Algorithm
    int countNumOfOnes(int mask) {
        int count = 0;
        while (mask != 0) {
            mask &= (mask - 1);
            count++;
        } 
        return count;
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) { 
        int numOfBikes = bikes.size();
        int numOfWorkers = workers.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;
        unordered_set<int> visited;

        // Initially both distance sum and mask is 0
        priorityQueue.push({0, 0});
        while (!priorityQueue.empty()) {
            int currentDistanceSum = priorityQueue.top().first;
            int currentMask = priorityQueue.top().second;
            priorityQueue.pop();
            
            // Continue if the mask is already traversed
            if (visited.find(currentMask) != visited.end())
                continue;
            
            // Marking the mask as visited
            visited.insert(currentMask);
            // Next Worker index would be equal to the number of 1's in currentMask
            int workerIndex = countNumOfOnes(currentMask);
            
            // Return the current distance sum if all workers are covered
            if (workerIndex == numOfWorkers) {
                return currentDistanceSum;
            }

            for (int bikeIndex = 0; bikeIndex < numOfBikes; bikeIndex++) {
                // Checking if the bike at bikeIndex has been assigned or not
                if ((currentMask & (1 << bikeIndex)) == 0) {
                    int nextStateDistanceSum = currentDistanceSum + 
                        findDistance(workers[workerIndex], bikes[bikeIndex]);
                    
                    // Put the next state pair into the priority queue
                    int nextStateMask = currentMask | (1 << bikeIndex);
                    priorityQueue.push({nextStateDistanceSum, nextStateMask});
                }
            }
        }
        
        // This statement will never be executed provided there is at least one bike per worker
        return -1;
	}
};
