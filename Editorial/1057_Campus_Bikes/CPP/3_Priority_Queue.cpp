class Solution {
public:
    // Function to return the Manhattan distance
    int distance(vector<int>& worker_loc, vector<int>& bike_loc) {
        return abs(worker_loc[0] - bike_loc[0]) + abs(worker_loc[1] - bike_loc[1]);
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // List of triplets (distance, worker, bike) for each bike corresponding to worker
        vector<vector<tuple<int, int, int>>> workerToBikeList;
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, 
                       greater<tuple<int, int, int>>> pq;
        
        for (int worker = 0; worker < workers.size(); worker++) {
            // Add all the bikes with their distances from the current worker
            vector<tuple<int, int, int>> currWorkerPairs;
            for (int bike = 0; bike < bikes.size(); bike++) {
                int dist = distance(workers[worker], bikes[bike]);
                currWorkerPairs.push_back({dist, worker, bike});
            }
            
            // Sort the workerToBikeList for the current worker in reverse order.
            sort(currWorkerPairs.begin(), currWorkerPairs.end(), greater<tuple<int, int, int>>());

            // For each worker, add their closest bike to the priority queue
            pq.push(currWorkerPairs.back());
            // Second last bike is now the closest bike for this worker
            currWorkerPairs.pop_back();
            
            // Store the remaining options for the current worker in workerToBikeList
            workerToBikeList.push_back(currWorkerPairs);
        }
        
        // Initialize all values to false, to signify no bikes have been taken
        vector<int> bikeStatus(bikes.size(), false);
        // Initialize all index to -1, to signify no worker has a bike
        vector<int> workerStatus(workers.size(), -1);
        
        while (!pq.empty()) {
            // Pop the pair with smallest distance
            auto[dist, worker, bike] = pq.top();
            pq.pop();
            bike = bike;
            worker = worker;
            
            if (!bikeStatus[bike]) {
                // If the bike is free, assign the bike to the worker
                bikeStatus[bike] = true;
                workerStatus[worker] = bike;
            } else {
                // Otherwise, add the next closest bike for the current worker
                pq.push(workerToBikeList[worker].back());
                workerToBikeList[worker].pop_back();
            }
        }
        
        return workerStatus;       
    }
};
