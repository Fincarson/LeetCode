class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = findMaxDepth(nestedList);
        return weightedSum(nestedList, 1, maxDepth);
    }
    
    int findMaxDepth(vector<NestedInteger>& list) {
        int maxDepth = 1;
        for (NestedInteger nested : list) {
            if (!nested.isInteger() && nested.getList().size() > 0) {
                maxDepth = max(maxDepth, 1 + findMaxDepth(nested.getList()));
            }
        }
        return maxDepth;
    }
    
    int weightedSum(vector<NestedInteger>& list, int depth, int maxDepth) {
        int answer = 0;
        for (NestedInteger nested : list) {
            if (nested.isInteger()) {
                answer += nested.getInteger() * (maxDepth - depth + 1);
            } else {
                answer += weightedSum(nested.getList(), depth + 1, maxDepth);
            }
        }
        return answer;
    }
};
