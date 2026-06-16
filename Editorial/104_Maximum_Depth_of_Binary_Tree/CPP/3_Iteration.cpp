class Solution {
  public:
  int maxDepth(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }

    vector<pair<int, TreeNode*>> my_stack;
    my_stack.push_back(pair<int, TreeNode*>(1, root));
    int max_depth = 0;
    while (!my_stack.empty()) {
      pair<int, TreeNode*> my_pair = my_stack.back();
      int c_depth = get<0>(my_pair);
      TreeNode* c_node = get<1>(my_pair);
      max_depth = max(max_depth, c_depth);
      my_stack.pop_back();
      if (c_node->left != NULL) {
        my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, c_node->left));
      }
      if (c_node->right != NULL) {
        my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, c_node->right));
      }
    }
    return max_depth;
  }
};
