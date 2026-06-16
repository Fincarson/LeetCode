class Solution {
private:
    int u_depth;
    TreeNode* next_node;
    TreeNode* target_node;

public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        this->u_depth = -1;
        this->target_node = u;
        this->next_node = nullptr;
        dfs(root, 0);
        return this->next_node;
    }

    void dfs(TreeNode* curr_node, int depth) {
        // the depth to look for next node is identified
        if (curr_node == this->target_node) {
            this->u_depth = depth;
            return;
        }

        // we're on the level to look for the next node
        if (depth == this->u_depth) {
            if (this->next_node == nullptr) {
                this->next_node = curr_node;
            }
            return;
        }

        // continue to traverse the tree
        if (curr_node->left != nullptr) {
            dfs(curr_node->left, depth + 1);
        }
        if (curr_node->right != nullptr) {
            dfs(curr_node->right, depth + 1);
        }
    }
};
