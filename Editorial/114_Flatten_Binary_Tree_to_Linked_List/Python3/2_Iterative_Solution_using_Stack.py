import collections


class Solution:

    def flatten(self, root: Optional[TreeNode]) -> None:

        # Handle the null scenario
        if not root:
            return None

        START, END = 1, 2

        tailNode = None
        stack = collections.deque([(root, START)])

        while stack:

            currentNode, recursionState = stack.pop()

            # We reached a leaf node. Record this as a tail
            # node and move on.
            if not currentNode.left and not currentNode.right:
                tailNode = currentNode
                continue

            # If the node is in the START state, it means we still
            # haven't processed it's left child yet.
            if recursionState == START:

                # If the current node has a left child, we add it
                # to the stack AFTER adding the current node again
                # to the stack with the END recursion state.
                if currentNode.left:
                    stack.append((currentNode, END))
                    stack.append((currentNode.left, START))
                elif currentNode.right:

                    # In case the current node didn't have a left child
                    # we will add it's right child
                    stack.append((currentNode.right, START))
            else:
                # If the current node is in the END recursion state,
                # that means we did process one of it's children. Left
                # if it existed, else right.
                rightNode = currentNode.right

                # If there was a left child, there must have been a leaf
                # node and so, we would have set the tailNode
                if tailNode:

                    # Establish the proper connections.
                    tailNode.right = currentNode.right
                    currentNode.right = currentNode.left
                    currentNode.left = None
                    rightNode = tailNode.right

                if rightNode:
                    stack.append((rightNode, START))
