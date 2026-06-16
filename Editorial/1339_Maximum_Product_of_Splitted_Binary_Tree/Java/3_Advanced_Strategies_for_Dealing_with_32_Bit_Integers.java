/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

    private static final int MOD = 1000000007;

    private List<Integer> allSums = new ArrayList<>();

    public int maxProduct(TreeNode root) {
        int totalSum = treeSum(root);
        int nearestToHalf = 0;
        int smallestDistanceBetween = Integer.MAX_VALUE;
        for (int sum : allSums) {
            // We want to do this in a way that doesn't require floats.
            // One way is to minimise the *distance* between the 2 halves.
            int distanceBetween = Math.abs(totalSum - sum * 2);
            if (distanceBetween < smallestDistanceBetween) {
                smallestDistanceBetween = distanceBetween;
                nearestToHalf = sum;
            }
        }
        return modularMultiplication(nearestToHalf, totalSum - nearestToHalf, MOD);
    }


    private int modularMultiplication(int a, int b, int m) {
        int product = 0;
        int currentSum = a;
        while (b > 0) {
            int bit = b % 2;
            b >>= 1;
            if (bit == 1) {
                product += currentSum;
                product %= m;
            }
            currentSum <<= 1;
            currentSum %= m;
        }
        return product;
    }    

    private int treeSum(TreeNode subroot) {
        if (subroot == null) return 0;
        int leftSum = treeSum(subroot.left);
        int rightSum = treeSum(subroot.right);
        int totalSum = leftSum + rightSum + subroot.val;
        allSums.add(totalSum);
        return totalSum;
    }
}
