// Code by kamanelf (https://leetcode.com/kamanelf/)
// https://leetcode.com/problems/sum-of-left-leaves/discuss/124147/C-solution-with-Morris-Traversal
int sumOfLeftLeaves(struct TreeNode* root) {
  int sum = 0;
  while (root) {
    if (!root->left) {
      root = root->right;
    } else {
      struct TreeNode* pre = root->left;
      if (pre->left == NULL && pre->right == NULL) sum += pre->val;
      while (pre->right && pre->right != root) pre = pre->right;
      if (!pre->right) {
        pre->right = root;
        root = root->left;
      } else {
        pre->right = NULL;
        root = root->right;
      }
    }
  }
  return sum;
}
