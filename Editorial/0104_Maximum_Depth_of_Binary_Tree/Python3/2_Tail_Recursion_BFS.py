class Solution:
    def __init__(self):
        # The queue that contains the next nodes to visit,
        # along with the level/depth that each node is located.
        self.next_items = []
        self.max_depth = 0

    def next_maxDepth(self):
        if not self.next_items:
            return self.max_depth
        next_node, next_level = self.next_items.pop(0)
        next_level += 1
        self.max_depth = max(self.max_depth, next_level)
        # Add the nodes to visit in the following recursive calls.
        if next_node.left:
            self.next_items.append((next_node.left, next_level))
        if next_node.right:
            self.next_items.append((next_node.right, next_level))
        # The last action should be the ONLY recursive call
        # in the tail-recursion function.
        return self.next_maxDepth()

    def maxDepth(self, root):
        if not root:
            return 0
        # Clear the previous queue.
        self.next_items = []
        self.max_depth = 0
        # Push the root node into the queue to kick off the next visit.
        self.next_items.append((root, 0))
        return self.next_maxDepth()
