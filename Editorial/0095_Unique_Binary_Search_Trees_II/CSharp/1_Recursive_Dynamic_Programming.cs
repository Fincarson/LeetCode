public class Solution {
    public IList<TreeNode> AllPossibleBST(
        int start, int end, Dictionary<(int, int), IList<TreeNode>> memo) {
        List<TreeNode> res = new List<TreeNode>();
        if (start > end) {
            res.Add(null);
            return res;
        }

        var key = (start, end);
        if (memo.ContainsKey(key)) {
            return memo[key];
        }

        // Iterate through all values from start to end to construct left and
        // right subtree recursively.
        for (int i = start; i <= end; ++i) {
            IList<TreeNode> leftSubTrees = AllPossibleBST(start, i - 1, memo);
            IList<TreeNode> rightSubTrees = AllPossibleBST(i + 1, end, memo);
            // Loop through all left and right subtrees and connect them to ith
            // root.
            foreach (TreeNode left in leftSubTrees) {
                foreach (TreeNode right in rightSubTrees) {
                    TreeNode root = new TreeNode(i, left, right);
                    res.Add(root);
                }
            }
        }

        memo[key] = res;
        return res;
    }

    public IList<TreeNode> GenerateTrees(int n) {
        var memo = new Dictionary<(int, int), IList<TreeNode>>();
        return AllPossibleBST(1, n, memo);
    }
}
