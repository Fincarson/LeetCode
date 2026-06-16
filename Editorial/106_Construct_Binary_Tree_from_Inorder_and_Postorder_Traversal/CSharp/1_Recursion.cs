public class Solution {
    int post_idx;
    int[] postorder;
    int[] inorder;
    Dictionary<int, int> idx_map = new Dictionary<int, int>();

    public TreeNode Helper(int in_left, int in_right) {
        if (in_left > in_right)
            return null;
        int root_val = postorder[post_idx];
        TreeNode root = new TreeNode(root_val);
        int index = idx_map[root_val];
        post_idx--;
        root.right = Helper(index + 1, in_right);
        root.left = Helper(in_left, index - 1);
        return root;
    }

    public TreeNode BuildTree(int[] inorder, int[] postorder) {
        this.postorder = postorder;
        this.inorder = inorder;
        post_idx = postorder.Length - 1;
        for (int idx = 0; idx < inorder.Length; idx++)
            idx_map[inorder[idx]] = idx;
        return Helper(0, inorder.Length - 1);
    }
}
