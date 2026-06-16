class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return vector<int>();

        deque<TreeNode*> nextLevel{root};
        deque<TreeNode*> currLevel;
        vector<int> rightside;

        TreeNode* node = nullptr;
        while (!nextLevel.empty()) {
            currLevel = nextLevel;
            nextLevel.clear();

            while (!currLevel.empty()) {
                node = currLevel.front();
                currLevel.pop_front();

                if (node->left != nullptr) nextLevel.push_back(node->left);
                if (node->right != nullptr) nextLevel.push_back(node->right);
            }

            rightside.push_back(node->val);
        }
        return rightside;
    }
};
