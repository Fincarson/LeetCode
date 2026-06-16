// Definition for a binary tree node.
// struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class BSTIterator {
private:
    vector<int> nodesSorted;
    int index;

    void _inorder(TreeNode* root) {
        if (root == nullptr) return;

        this->_inorder(root->left);
        this->nodesSorted.push_back(root->val);
        this->_inorder(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        this->nodesSorted = vector<int>();
        this->index = -1;
        this->_inorder(root);
    }

    /** @return the next smallest number */
    int next() { return this->nodesSorted[++this->index]; }

    /** @return whether we have a next smallest number */
    bool hasNext() { return this->index + 1 < this->nodesSorted.size(); }
};
