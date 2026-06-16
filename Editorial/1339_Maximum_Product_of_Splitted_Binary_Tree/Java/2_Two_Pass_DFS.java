class Solution {

    private long maximumProduct = 0;
    private int totalTreeSum = 0;

    private int treeSum(TreeNode subroot) {
        if (subroot == null) return 0;
        int leftSum = treeSum(subroot.left);
        int rightSum = treeSum(subroot.right);
        int totalSum = leftSum + rightSum + subroot.val;
        return totalSum;
    }

    private int findMaximumProduct(TreeNode subroot) {
        if (subroot == null) return 0;
        int leftSum = findMaximumProduct(subroot.left);
        int rightSum = findMaximumProduct(subroot.right);
        int totalSum = leftSum + rightSum + subroot.val;
        long totalProduct = (long)totalSum * (totalTreeSum - totalSum);
        this.maximumProduct = Math.max(this.maximumProduct, totalProduct);
        return totalSum;
    }

    public int maxProduct(TreeNode root) {
        this.totalTreeSum = treeSum(root);
        findMaximumProduct(root);
        return (int)(maximumProduct % 1000000007);
    }
}
