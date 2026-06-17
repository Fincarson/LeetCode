class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        return maxAverage(root).maxAverage;
    }

private:
    struct State {
        // count of nodes in the subtree
        int nodeCount;

        // sum of values in the subtree
        int valueSum;

        // max average found in the subtree
        double maxAverage;
    };

    State maxAverage(TreeNode* root) {
        if (!root) return {0, 0, 0};

        // postorder traversal, solve for both child nodes first.
        State left = maxAverage(root->left);
        State right = maxAverage(root->right);

        // now find nodeCount, valueSum and maxAverage for current node `root`
        int nodeCount = left.nodeCount + right.nodeCount + 1;
        int sum = left.valueSum + right.valueSum + root->val;
        double maxAverage = max(
                (1.0 * (sum)) / nodeCount, // average for current node
                max(right.maxAverage, left.maxAverage) // max average from child nodes
        );

        return {nodeCount, sum, maxAverage};
    }
};
