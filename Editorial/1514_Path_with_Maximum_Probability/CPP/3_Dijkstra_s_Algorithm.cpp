class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<double, int>>> graph;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];
            graph[u].push_back({pathProb, v});
            graph[v].push_back({pathProb, u});
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        // please note that the priority queue in c++ is a max heap by default
        // and the sorting is decided by the first element of the pair.
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        while (!pq.empty()) {
            double curProb = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
            if (curNode == end) {
                return curProb;
            }
            if (!graph[curNode]
                     .empty()) {  // Check if the node has been processed
                for (auto& nxt : graph[curNode]) {
                    int nxtNode = nxt.second;
                    double pathProb = nxt.first;
                    if (curProb * pathProb > maxProb[nxtNode]) {
                        maxProb[nxtNode] = curProb * pathProb;
                        pq.push({maxProb[nxtNode], nxtNode});
                    }
                }
                graph[curNode]
                    .clear();  // Clear the adjacency list by removing the entry
            }
        }

        return 0.0;
    }
};
