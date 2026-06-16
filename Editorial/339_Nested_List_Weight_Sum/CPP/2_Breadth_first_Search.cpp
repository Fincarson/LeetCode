class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        for (NestedInteger nested : nestedList) {
            q.push(nested);
        }

        int depth = 1;
        int total = 0;

        while (!q.empty()) {
            size_t size = q.size();
            for (size_t i = 0; i < size; i++) {
                NestedInteger nested = q.front();
                q.pop();
                if (nested.isInteger()) {
                    total += nested.getInteger() * depth;
                } else {
                    for (NestedInteger nested_deeper : nested.getList()) {
                        q.push(nested_deeper);
                    }
                }
            }
            depth++;
        }
        return total;
    }
};
