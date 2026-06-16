class Solution:
    def replaceValueInTree(self, root):
        if root is None:
            return root
        node_queue = deque()
        node_queue.append(root)
        current_level_sum = root.val

        while node_queue:
            level_size = len(node_queue)
            next_level_sum = 0

            for _ in range(level_size):
                current_node = node_queue.popleft()
                # Update node value to cousin sum
                current_node.val = current_level_sum - current_node.val

                # Calculate sibling sum
                sibling_sum = (
                    0 if current_node.left is None else current_node.left.val
                ) + (
                    0 if current_node.right is None else current_node.right.val
                )

                if current_node.left is not None:
                    next_level_sum += (
                        current_node.left.val
                    )  # Accumulate next level sum
                    current_node.left.val = (
                        sibling_sum  # Update left child's value
                    )
                    node_queue.append(
                        current_node.left
                    )  # Add to queue for next level
                if current_node.right is not None:
                    next_level_sum += (
                        current_node.right.val
                    )  # Accumulate next level sum
                    current_node.right.val = (
                        sibling_sum  # Update right child's value
                    )
                    node_queue.append(
                        current_node.right
                    )  # Add to queue for next level

            # Update current level sum for next iteration
            current_level_sum = next_level_sum
        return root
