class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        deepest_sum = depth = 0
        queue = deque([(root, 0),])

        while queue:
            node, curr_depth = queue.popleft()
            if node.left is None and node.right is None:
                # if this leaf is the deepest one seen so far
                if depth < curr_depth:
                    deepest_sum = node.val      # start new sum
                    depth = curr_depth          # note new depth
                # if there were already leaves at this depth
                elif depth == curr_depth:
                    deepest_sum += node.val     # update existing sum    
            else:
                if node.left:
                    queue.append((node.left, curr_depth + 1))
                if node.right:
                    queue.append((node.right, curr_depth + 1))
                        
        return deepest_sum
