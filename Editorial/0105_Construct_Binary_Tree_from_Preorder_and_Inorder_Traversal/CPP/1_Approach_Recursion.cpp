class Solution {
public:
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndexMap;
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        // if there are no elements to construct the tree
        if (left > right) return nullptr;
        // select the preorder_index element as the root and increment it
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        // build left and right subtree
        // excluding inorderIndexMap[rootValue] element because it's the root
        root->left =
            arrayToTree(preorder, left, inorderIndexMap[rootValue] - 1);
        root->right =
            arrayToTree(preorder, inorderIndexMap[rootValue] + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        // build a hashmap to store value -> its index relations
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }
};
