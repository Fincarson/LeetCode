class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size();
        tree.resize(n);
        visited.assign(n, false);

        // Form tree with edges
        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Find the path taken by Bob to reach node 0 and the times it takes to
        // get there
        findBobPath(bob, 0);

        // Find Alice's optimal path
        visited.assign(n, false);
        findAlicePath(0, 0, 0, amount);

        return maxIncome;
    }

private:
    unordered_map<int, int> bobPath;
    vector<bool> visited;
    vector<vector<int>> tree;
    int maxIncome = INT_MIN;

    // Depth First Search to find Bob's path
    bool findBobPath(int sourceNode, int time) {
        // Mark and set time node is reached
        bobPath[sourceNode] = time;
        visited[sourceNode] = true;

        // Destination for Bob is found
        if (sourceNode == 0) {
            return true;
        }

        // Traverse through unvisited nodes
        for (int adjacentNode : tree[sourceNode]) {
            if (!visited[adjacentNode] && findBobPath(adjacentNode, time + 1)) {
                return true;
            }
        }

        // If node 0 isn't reached, remove current node from path
        bobPath.erase(sourceNode);
        return false;
    }

    // Depth First Search to find Alice's optimal path
    void findAlicePath(int sourceNode, int time, int income,
                       vector<int>& amount) {
        // Mark node as explored
        visited[sourceNode] = true;

        // Alice reaches the node first
        if (bobPath.find(sourceNode) == bobPath.end() ||
            time < bobPath[sourceNode]) {
            income += amount[sourceNode];
        }

        // Alice and Bob reach the node at the same time
        else if (time == bobPath[sourceNode]) {
            income += (amount[sourceNode] / 2);
        }

        // Update max value if current node is a new leaf
        if (tree[sourceNode].size() == 1 && sourceNode != 0) {
            maxIncome = max(maxIncome, income);
        }

        // Traverse through unvisited nodes
        for (int adjacentNode : tree[sourceNode]) {
            if (!visited[adjacentNode]) {
                findAlicePath(adjacentNode, time + 1, income, amount);
            }
        }
    }
};
