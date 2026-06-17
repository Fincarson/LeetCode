class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        stack = [root]
        evaluated = {}
        
        while stack:
            top_node = stack[-1]
            
            # If the node is a leaf node, store its value in the evaluated dictionary
            # and continue
            if not top_node.left and not top_node.right:
                stack.pop()
                evaluated[top_node] = top_node.val == 1
                continue
            
            # If both the children have already been evaluated, use their
            # values to evaluate the current node.
            if top_node.left in evaluated and top_node.right in evaluated:
                stack.pop()
                if top_node.val == 2:
                    evaluated[top_node] = evaluated[top_node.left] or evaluated[top_node.right]
                else:
                    evaluated[top_node] = evaluated[top_node.left] and evaluated[top_node.right]
            else:
                # If both the children are not leaf nodes, push the current
                # node along with its left and right child back into the stack.
                if top_node.left:
                    stack.append(top_node.left)
                if top_node.right:
                    stack.append(top_node.right)
        
        return evaluated[root]
