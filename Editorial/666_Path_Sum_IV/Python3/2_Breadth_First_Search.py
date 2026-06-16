class Solution:
    def pathSum(self, nums: List[int]) -> int:
        map = (
            {}
        )  # Store the node values in a hashmap, using coordinates as the key.

        # Iterate over given nums
        for element in nums:
            coordinates = element // 10
            value = element % 10
            map[coordinates] = value

        total_sum = 0  # Initialize the total sum
        q = [
            (nums[0] // 10, map[nums[0] // 10])
        ]  # Initialize the BFS queue and start with the root node.

        # Continue till queue is not empty
        while q:
            coordinates, current_sum = q.pop(0)  # Dequeue
            level = coordinates // 10
            position = coordinates % 10

            left = (level + 1) * 10 + position * 2 - 1
            right = (level + 1) * 10 + position * 2

            # If it's a leaf node (no left and right children), add currentSum to totalSum.
            if not (left in map or right in map):
                total_sum += current_sum

            # Add the left child to the queue if it exists.
            if left in map:
                q.append((left, current_sum + map[left]))

            # Add the right child to the queue if it exists.
            if right in map:
                q.append((right, current_sum + map[right]))

        return total_sum
