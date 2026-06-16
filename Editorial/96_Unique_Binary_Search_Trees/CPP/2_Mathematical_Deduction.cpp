class Solution {
public:
    int numTrees(int n) {
        // Note: we should use long long here instead of int, otherwise overflow
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};
