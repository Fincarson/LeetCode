class Solution {
public:
    // Function to return the Manhattan distance
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int minDis = INT_MAX;
        // Stores the list of (worker, bike) pairs corresponding to its distance
        vector<pair<int, int>> disToPairs[1999];
        
        // Add the (worker, bike) pairs corresponding to their distance list
        for (int worker = 0; worker < workers.size(); worker++) {
            for (int bike = 0; bike < bikes.size(); bike++) {
                int distance = findDistance(workers[worker], bikes[bike]);
                disToPairs[distance].push_back({worker, bike});
                minDis = min(minDis, distance);
            }
        }
        
        int currDis = minDis;
        // Initialize all values to false, to signify no bikes have been taken
        vector<int> bikeStatus(bikes.size(), false);
        // Initialize all index to -1, to signify no worker has a bike
        vector<int> workerStatus(workers.size(), -1);
        // Keep track of how many worker-bike pairs have been made
        int pairCount = 0;
        
        // Until all workers have not been assigned a bike
        while (pairCount != workers.size()) {
            for (auto[worker, bike] : disToPairs[currDis]) {
                if (workerStatus[worker] == -1 && !bikeStatus[bike]) {
                    // If both worker and bike are free, assign them to each other
                    bikeStatus[bike] = true;
                    workerStatus[worker] = bike;
                    pairCount++;
                }
            }
            currDis++;
        }
        
        return workerStatus;
    }
};
