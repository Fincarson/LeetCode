public class Solution {
    public int SumNumbers(TreeNode root) {
        int rootToLeaf = 0, currNumber = 0;
        int steps;
        TreeNode predecessor;
        while (root != null) {
            if (root.left != null) {
                predecessor = root.left;
                steps = 1;
                while (predecessor.right != null && predecessor.right != root) {
                    predecessor = predecessor.right;
                    ++steps;
                }

                if (predecessor.right == null) {
                    currNumber = currNumber * 10 + root.val;
                    predecessor.right = root;
                    root = root.left;
                } else {
                    if (predecessor.left == null) {
                        rootToLeaf += currNumber;
                    }

                    for (int i = 0; i < steps; ++i) {
                        currNumber /= 10;
                    }

                    predecessor.right = null;
                    root = root.right;
                }
            } else {
                currNumber = currNumber * 10 + root.val;
                if (root.right == null) {
                    rootToLeaf += currNumber;
                }

                root = root.right;
            }
        }

        return rootToLeaf;
    }
}
