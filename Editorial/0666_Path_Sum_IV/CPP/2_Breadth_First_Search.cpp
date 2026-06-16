class Solution {
public:
    int pathSum(vector<int>& nums) {
        // Store the node values in a hashmap, using coordinates as the key.
        unordered_map<int, int> map;
        for (int element : nums) {
            int coordinates = element / 10;
            int value = element % 10;
            map[coordinates] = value;
        }

        // Initialize the BFS queue and start with the root node.
        queue<pair<int, int>> q;
        int totalSum = 0;

        int rootCoordinates = nums[0] / 10;
        q.push({rootCoordinates, map[rootCoordinates]});

        while (!q.empty()) {
            auto [coordinates, currentSum] = q.front();
            q.pop();

            int level = coordinates / 10;
            int position = coordinates % 10;

            // Find the left and right child coordinates.
            int left = (level + 1) * 10 + position * 2 - 1;
            int right = (level + 1) * 10 + position * 2;

            // If it's a leaf node (no left and right children), add currentSum
            // to totalSum.
            if (!map.count(left) && !map.count(right)) {
                totalSum += currentSum;
            }

            // Add the left child to the queue if it exists.
            if (map.count(left)) {
                q.push({left, currentSum + map[left]});
            }

            // Add the right child to the queue if it exists.
            if (map.count(right)) {
                q.push({right, currentSum + map[right]});
            }
        }

        return totalSum;
    }
};
