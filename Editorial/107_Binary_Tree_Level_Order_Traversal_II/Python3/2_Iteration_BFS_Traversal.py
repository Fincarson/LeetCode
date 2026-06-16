class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        levels = []
        next_level = deque([root])

        while root and next_level:
            curr_level = next_level
            next_level = deque()
            levels.append([])

            for node in curr_level:
                # append the current node value
                levels[-1].append(node.val)
                # process child nodes for the next level
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)

        return levels[::-1]
