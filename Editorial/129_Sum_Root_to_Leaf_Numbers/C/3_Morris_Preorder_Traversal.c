int sumNumbers(struct TreeNode* root) {
    int root_to_leaf = 0, curr_number = 0;
    int steps;
    struct TreeNode* predecessor;
    while (root != NULL) {
        if (root->left != NULL) {
            predecessor = root->left;
            steps = 1;
            while (predecessor->right != NULL && predecessor->right != root) {
                predecessor = predecessor->right;
                ++steps;
            }
            if (predecessor->right == NULL) {
                curr_number = curr_number * 10 + root->val;
                predecessor->right = root;
                root = root->left;
            } else {
                if (predecessor->left == NULL) {
                    root_to_leaf += curr_number;
                }
                for (int i = 0; i < steps; ++i) {
                    curr_number /= 10;
                }
                predecessor->right = NULL;
                root = root->right;
            }
        } else {
            curr_number = curr_number * 10 + root->val;
            if (root->right == NULL) {
                root_to_leaf += curr_number;
            }
            root = root->right;
        }
    }
    return root_to_leaf;
}
