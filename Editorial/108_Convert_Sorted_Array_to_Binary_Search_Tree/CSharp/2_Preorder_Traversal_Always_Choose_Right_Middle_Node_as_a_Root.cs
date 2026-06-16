public class Solution {
    private int[] nums;

    private TreeNode Helper(int left, int right) {
        if (left > right)
            return null;
        // always choose right middle node as a root
        int p = (left + right) / 2;
        if ((left + right) % 2 == 1)
            ++p;
        // preorder traversal: node -> left -> right
        TreeNode root = new TreeNode(nums[p]);
        root.left = Helper(left, p - 1);
        root.right = Helper(p + 1, right);
        return root;
    }

    public TreeNode SortedArrayToBST(int[] nums) {
        this.nums = nums;
        return Helper(0, nums.Length - 1);
    }
}
