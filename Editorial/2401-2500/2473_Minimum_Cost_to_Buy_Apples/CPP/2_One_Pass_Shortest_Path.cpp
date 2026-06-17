class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        // Store the graph as a list of lists
        // The rows represent the cities (vertices)
        // The columns store an adjacency list of road, cost pairs (edge, weight)
        vector<vector<pair<int, int>>> graph(n);
        
        // Add each road to the graph using adjacency lists
        // Store each city at `graph[city - 1]`
        for (auto& road : roads) {
            int city_a = road[0] - 1, city_b = road[1] - 1, cost = road[2];
            graph[city_a].push_back({city_b, cost});
            graph[city_b].push_back({city_a, cost});
        }

        // Store the cost to buy an apple in each city 
        // without traveling in the result
        vector<long long> result(appleCost.begin(), appleCost.end());
        
        // Initialize the heap (priority queue) with each starting city
        // Each element of the heap is a pair with the cost and city
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (int start_city = 0; start_city < appleCost.size(); start_city++) {
            heap.push({appleCost[start_city], start_city});
        }
        
        // Find the minimum cost to buy an apple starting in each city
        while (!heap.empty()) {
            auto [total_cost, curr_city] = heap.top();
            heap.pop();
            
            // If we have already found a path to buy an apple
            // for cheaper than the local apple cost, skip this city
            if (result[curr_city] < total_cost)
                continue;
            
            // Add each neighboring city to the heap if it is cheaper to
            // start there, travel to the current city and buy an apple 
            // than buy in the neighboring city
            for (auto [neighbor, cost] : graph[curr_city]) {
                if (result[neighbor] > result[curr_city] + (k + 1) * cost) {
                    result[neighbor] = result[curr_city] + (k + 1) * cost;
                    heap.push({result[neighbor], neighbor});
                }
            }
        }
        return result;
    }
};
