"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""
class Solution:
    def diameter(self, root: 'Node') -> int:
        diameter = 0

        def height(node):
            """ return the height of the node """
            nonlocal diameter

            if len(node.children) == 0:
                return 0

            # select the top two heights
            max_height_1, max_height_2 = 0, 0
            for child in node.children:
                parent_height = height(child) + 1
                if parent_height > max_height_1:
                    max_height_1, max_height_2 = parent_height, max_height_1
                elif parent_height > max_height_2:
                    max_height_2 = parent_height

            # calculate the distance between the two farthest leaves nodes.
            distance = max_height_1 + max_height_2
            diameter = max(diameter, distance)

            return max_height_1

        height(root)
        return diameter
