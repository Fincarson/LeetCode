class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        if not root:
            return None

        # Step 1: Create the backbone (vine)
        # Temporary dummy node
        vine_head = TreeNode(0)
        vine_head.right = root
        current = vine_head
        while current.right:
            if current.right.left:
                self.right_rotate(current, current.right)
            else:
                current = current.right

        # Step 2: Count the nodes
        node_count = 0
        current = vine_head.right
        while current:
            node_count += 1
            current = current.right

        # Step 3: Create a balanced BST
        m = 2 ** math.floor(math.log2(node_count + 1)) - 1
        self.make_rotations(vine_head, node_count - m)
        while m > 1:
            m //= 2
            self.make_rotations(vine_head, m)

        balanced_root = vine_head.right
        # Delete the temporary dummy node
        vine_head = None
        return balanced_root

    # Function to perform a right rotation
    def right_rotate(self, parent: TreeNode, node: TreeNode):
        tmp = node.left
        node.left = tmp.right
        tmp.right = node
        parent.right = tmp

    # Function to perform a left rotation
    def left_rotate(self, parent: TreeNode, node: TreeNode):
        tmp = node.right
        node.right = tmp.left
        tmp.left = node
        parent.right = tmp

    # Function to perform a series of left rotations to balance the vine
    def make_rotations(self, vine_head: TreeNode, count: int):
        current = vine_head
        for _ in range(count):
            tmp = current.right
            self.left_rotate(current, tmp)
            current = current.right
