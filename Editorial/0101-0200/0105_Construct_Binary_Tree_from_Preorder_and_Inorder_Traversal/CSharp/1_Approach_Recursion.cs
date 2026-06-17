public class Solution {
    private int preorderIndex;
    private Dictionary<int, int> inorderIndexMap;

    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        preorderIndex = 0;
        inorderIndexMap = new Dictionary<int, int>();
        for (int i = 0; i < inorder.Length; i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        return ArrayToTree(preorder, 0, preorder.Length - 1);
    }

    private TreeNode ArrayToTree(int[] preorder, int left, int right) {
        if (left > right)
            return null;
        int rootValue = preorder[preorderIndex++];
        TreeNode root = new TreeNode(rootValue);
        root.left = ArrayToTree(preorder, left, inorderIndexMap[rootValue] - 1);
        root.right =
            ArrayToTree(preorder, inorderIndexMap[rootValue] + 1, right);
        return root;
    }
}
