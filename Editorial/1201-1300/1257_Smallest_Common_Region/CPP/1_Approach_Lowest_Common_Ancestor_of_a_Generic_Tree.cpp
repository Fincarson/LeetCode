class Solution {
    // Function to return an array representing the path from the root node
    // to the current node.
    vector<string> fetchPathForRegion(
        string currNode, unordered_map<string, string>& childParentMap) {
        vector<string> path;
        // Start by adding the current node to the path.
        path.push_back(currNode);

        // Traverse upwards through the tree by finding the parent of the
        // current node. Continue until the root node is reached.
        while (childParentMap.find(currNode) != childParentMap.end()) {
            string parentNode = childParentMap[currNode];
            path.push_back(parentNode);
            currNode = parentNode;
        }
        // Reverse the path so that it starts from the root and
        // ends at the given current node.
        reverse(path.begin(), path.end());
        return path;
    }

public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1,
                              string region2) {
        // Hash map to store (child -> parent) relationships
        // for each region.
        unordered_map<string, string> childParentMap;
        // Populate the 'childParentMap' using the provided 'regions' list.
        for (auto& regionArray : regions) {
            string parentNode = regionArray[0];
            for (int i = 1; i < regionArray.size(); ++i) {
                childParentMap[regionArray[i]] = parentNode;
            }
        }

        // Store the paths from the root node to 'region1' and 'region2'
        // nodes in their respective arrays.
        auto path1 = fetchPathForRegion(region1, childParentMap);
        auto path2 = fetchPathForRegion(region2, childParentMap);

        int i = 0, j = 0;
        string lowestCommonAncestor;
        // Traverse both paths simultaneously until the paths diverge.
        // The last common node is the lowest common ancestor.
        while (i < path1.size() && j < path2.size() && path1[i] == path2[j]) {
            lowestCommonAncestor = path1[i];
            i++;
            j++;
        }

        // Return the lowest common ancestor of 'region1' and 'region2'.
        return lowestCommonAncestor;
    }
};
