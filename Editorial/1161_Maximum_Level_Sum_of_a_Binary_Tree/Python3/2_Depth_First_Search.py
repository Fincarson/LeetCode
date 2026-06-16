class Solution:
    def dfs(
        self, node: Optional[TreeNode], level: int, sum_of_nodes_at_level: List[int]
    ) -> None:
        if node is None:
            return

        if len(sum_of_nodes_at_level) == level:
            sum_of_nodes_at_level.append(node.val)
        else:
            sum_of_nodes_at_level[level] += node.val

        self.dfs(node.left, level + 1, sum_of_nodes_at_level)
        self.dfs(node.right, level + 1, sum_of_nodes_at_level)

    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        sum_of_nodes_at_level = []
        self.dfs(root, 0, sum_of_nodes_at_level)

        max_sum = float("-inf")
        ans = 0

        for i in range(len(sum_of_nodes_at_level)):
            if max_sum < sum_of_nodes_at_level[i]:
                max_sum = sum_of_nodes_at_level[i]
                ans = i + 1

        return ans
