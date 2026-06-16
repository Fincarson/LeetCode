class Solution:
    def levelOrder(self, root: Optional['Node']) -> List[List[int]]:
        if root is None:
            return []        

        result = []
        previous_layer = [root]

        while previous_layer:
            current_layer = []
            result.append([])
            for node in previous_layer:
                result[-1].append(node.val)
                current_layer.extend(node.children)
            previous_layer = current_layer
        return result
