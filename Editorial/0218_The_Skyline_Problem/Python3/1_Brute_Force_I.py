class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        # Sort the unique positions of all the edges.
        positions = sorted(list(set([x for building in buildings for x in building[:2]])))
        
        # Hast table 'edge_index_map' to record every {position : index} pairs in edges.
        edge_index_map = {x : i for i, x in enumerate(positions)}

        # Initialize 'heights' to record maximum height at each index.
        heights = [0] * len(positions)
        
        # Iterate over all the buildings.
        for left, right, height in buildings:
            # For each building, find the indexes of its left
            # and right edges.
            left_idx = edge_index_map[left]
            right_idx = edge_index_map[right]

            # Update the maximum height within the range [left_idx, right_idx)
            for i in range(left_idx, right_idx):
                heights[i] = max(heights[i], height)

        answer = []

        # Iterate over 'heights'.
        for i in range(len(heights)):
            curr_height = heights[i]
            curr_x = positions[i]

            # Add all the positions where the height changes to 'answer'.
            if not answer or answer[-1][1] != curr_height:
                answer.append([curr_x, curr_height])
        return answer
