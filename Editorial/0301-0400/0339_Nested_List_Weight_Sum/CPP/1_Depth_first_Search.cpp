class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }

    int dfs(vector<NestedInteger>& list, int depth) {
        int total = 0;
        for (NestedInteger nested : list) {
            if (nested.isInteger()) {
                total += nested.getInteger() * depth;
            } else {
                total += dfs(nested.getList(), depth + 1);
            }
        }
        return total;
    }
};
