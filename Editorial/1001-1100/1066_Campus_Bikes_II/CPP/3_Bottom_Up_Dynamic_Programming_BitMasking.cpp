class Solution {
public:
    // Maximum value of mask will be 2^(Number of bikes)
    // And number of bikes can be 10 at max
    int memo [1024];
    
    // Count the number of ones using Brian Kernighan’s Algorithm
    int countNumOfOnes(int mask) {
        int count = 0;
        while (mask != 0) {
            mask &= (mask - 1);
            count++;
        } 
        return count;
    }
    
    // Manhattan distance
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    int minimumDistanceSum(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int numOfBikes = bikes.size();
        int numOfWorkers = workers.size();
        int smallestDistanceSum = INT_MAX;

        // 0 signifies that no bike has been assigned and
        // Distance sum for not assigning any bike is equal to 0
        memo[0] = 0;
        // Traverse over all the possible values of mask
        for (int mask = 0; mask < (1 << numOfBikes); mask++) {
            int nextWorkerIndex = countNumOfOnes(mask);
            
            // If mask has more number of 1's than the number of workers
            // Then we can update our answer accordingly
            if (nextWorkerIndex >= numOfWorkers) {
                smallestDistanceSum = min(smallestDistanceSum, memo[mask]);
                continue;
            }
            
            for (int bikeIndex = 0; bikeIndex < numOfBikes; bikeIndex++) {
                // Checking if the bike at bikeIndex has already been assigned
                if ((mask & (1 << bikeIndex)) == 0) {
                    int newMask = (1 << bikeIndex) | mask;
                    
                    // Updating the distance sum for newMask
                    memo[newMask] = min(memo[newMask], memo[mask] + 
                                        findDistance(workers[nextWorkerIndex], bikes[bikeIndex]));
                }
            }
        }
        
        return smallestDistanceSum;
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) { 
        // Initializing the answers for all masks to be INT_MAX
        for (int i = 0; i < 1024; i++) {
            memo[i] = INT_MAX;
        }
        return minimumDistanceSum(workers, bikes);
	}
};
