class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];
            graph[u].push_back({v, pathProb});
            graph[v].push_back({u, pathProb});
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        queue<int> queue;
        queue.push(start);
        while (!queue.empty()) {
            int curNode = queue.front();
            queue.pop();
            for (const pair<int, double>& neighbor : graph[curNode]) {
                int nxtNode = neighbor.first;
                double pathProb = neighbor.second;

                // Only update maxProb[nxtNode] if the current path increases
                // the probability of reach nxtNode.
                if (maxProb[curNode] * pathProb > maxProb[nxtNode]) {
                    maxProb[nxtNode] = maxProb[curNode] * pathProb;
                    queue.push(nxtNode);
                }
            }
        }

        return maxProb[end];
    }
};
