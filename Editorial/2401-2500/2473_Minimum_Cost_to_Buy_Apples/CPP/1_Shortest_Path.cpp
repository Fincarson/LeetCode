class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        // Store the graph as a list of lists
        // The rows represent the cities (vertices)
        // The columns store an adjacency list of road, cost pairs (edge, weight)
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());

        // Add each road to the graph using adjacency lists
        // Store each city at graph[city - 1]
        for (auto& road : roads) {
            int city_a = road[0] - 1, city_b = road[1] - 1, cost = road[2];
            graph[city_a].push_back({city_b, cost});
            graph[city_b].push_back({city_a, cost});
        }

        // Find the minimum cost to buy an apple starting in each city
        vector<long long> result(n);
        for (int startCity = 0; startCity < n; startCity++) {
            result[startCity] = shortestPath(startCity, graph, appleCost, k, n);
        }

        return result;
    }

private:
    // Finds the minimum cost to buy an apple from the start city
    long long shortestPath(int startCity, vector<vector<pair<int, int>>> graph,
                           vector<int>& appleCost, int k, int n) {
        // Stores the travel cost reach each city from the start city
        vector<int> travelCosts(n, INT_MAX);
        travelCosts[startCity] = 0;

        // Initialize the heap (priority queue) with the starting city
        // Each element of the heap is an array with the cost and city
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        heap.push({0, startCity});
        long long minCost = INT_MAX;

        while (!heap.empty()) {
            // Remove the city with the minimum cost from the top of the heap
            auto current = heap.top();
            heap.pop();
            int travelCost = current[0];
            int currCity = current[1];

            // Update the min cost if the curr city has a smaller total cost
            minCost = min(minCost, 
                    static_cast<long long>(appleCost[currCity]) + (k + 1) * travelCost);

            // Add each neighboring city to the heap if an apple is cheaper
            for (auto& [neighbor, cost] : graph[currCity]) {
                int nextCost = travelCost + cost;
                if (nextCost < travelCosts[neighbor]) {
                    travelCosts[neighbor] = nextCost;
                    heap.push({nextCost, neighbor});
                }
            }
        }
        return minCost;
    }
};
