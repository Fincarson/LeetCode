public class Solution {
    public IList<TreeNode> GenerateTrees(int n) {
        var dp = new List<List<List<TreeNode>>>(n + 1);
        for (int i = 0; i <= n; i++) {
            dp.Add(new List<List<TreeNode>>(n + 1));
            for (int j = 0; j <= n; j++) {
                dp[i].Add(new List<TreeNode>());
            }
        }

        for (int i = 1; i <= n; i++) {
            dp[i][i].Add(new TreeNode(i));
        }

        for (int numOfNodes = 2; numOfNodes <= n; numOfNodes++) {
            for (int start = 1; start <= n - numOfNodes + 1; start++) {
                int end = start + numOfNodes - 1;
                for (int i = start; i <= end; i++) {
                    List<TreeNode> leftSubtrees =
                        (i != start) ? dp[start][i - 1] : new List<TreeNode>();
                    if (leftSubtrees.Count == 0)
                        leftSubtrees.Add(null);
                    List<TreeNode> rightSubtrees =
                        (i != end) ? dp[i + 1][end] : new List<TreeNode>();
                    if (rightSubtrees.Count == 0)
                        rightSubtrees.Add(null);
                    foreach (TreeNode left in leftSubtrees) {
                        foreach (TreeNode right in rightSubtrees) {
                            dp[start][end].Add(new TreeNode(i, left, right));
                        }
                    }
                }
            }
        }

        return dp[1][n];
    }
}
