class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []

        queue = deque(
            [
                root,
                None,
            ]
        )
        rightside = []

        curr = root
        while queue:
            prev, curr = curr, queue.popleft()

            while curr:
                # add child nodes in the queue
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)

                prev, curr = curr, queue.popleft()

            # the current level is finished
            # and prev is its rightmost element
            rightside.append(prev.val)

            # add a sentinel to mark the end
            # of the next level
            if queue:
                queue.append(None)

        return rightside
