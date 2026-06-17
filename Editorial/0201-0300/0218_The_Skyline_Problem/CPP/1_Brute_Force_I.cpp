class Solution {
public: 
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Sort the unique positions of all the edges.
        set<int> edgeSet;
        for (auto building : buildings) {
            int left = building[0], right = building[1];
            edgeSet.insert(left);
            edgeSet.insert(right);
        }
        vector<int> edges(edgeSet.begin(), edgeSet.end());
        // Use hash table 'edgeIndexMap' to record every {position : index} pairs in edges.
        map<int, int> edgeIndexMap;
        for (int i = 0; i < edges.size(); ++i) {
            edgeIndexMap[edges[i]] = i;
        }
        
        // Use 'heights' to record maximum height at each index.
        vector<int> heights(edges.size());
        
        // Iterate over all the buildings.
        for (auto building : buildings) {
            // Find the indexes of the left and right edges
            // and update the max height within the range [left_idx, right_idx)
            int left = building[0], right = building[1], height = building[2];
            int leftIndex = edgeIndexMap[left], rightIndex = edgeIndexMap[right];
            for (int idx = leftIndex; idx < rightIndex; ++idx) {
                heights[idx] = max(heights[idx], height);
            }
        }
        
        vector<vector<int>> answer;

        // Iterate over 'heights'.
        for (int i = 0; i < heights.size(); ++i) {
            // Add all the positions where the height changes to 'answer'.
            int currHeight = heights[i], currPos = edges[i];
            if (i == 0 || currHeight != heights[i - 1]) {
                answer.push_back({currPos, currHeight});
            }
        }
        return answer;
    }
};
