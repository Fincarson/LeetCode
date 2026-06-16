public class Solution {
    Random rand = new Random();

    public TreeNode SortedArrayToBST(int[] nums) {
        return Helper(nums, 0, nums.Length - 1);
    }

    private TreeNode Helper(int[] nums, int left, int right) {
        if (left > right)
            return null;
        int p = (left + right) / 2;
        if ((left + right) % 2 == 1)
            p += rand.Next(2);
        TreeNode root = new TreeNode(nums[p]);
        root.left = Helper(nums, left, p - 1);
        root.right = Helper(nums, p + 1, right);
        return root;
    }
}
