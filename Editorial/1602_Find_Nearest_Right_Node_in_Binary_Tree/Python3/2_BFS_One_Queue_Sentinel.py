class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        if root is None:
            return None

        queue = deque([root, None,])
        while queue:
            curr = queue.popleft()

            # if it's the given node
            if curr == u:
                return queue.popleft()

            if curr:
                # add child nodes in the queue
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
            else:
                # once the level is finished,
                # add a sentinel to mark end of level
                if queue:
                    queue.append(None)
