class Solution:
    def maxBoxesInWarehouse(
        self, boxes: List[int], warehouse: List[int]
    ) -> int:
        # Sort the boxes by height

        boxes.sort()

        warehouse_size = len(warehouse)
        left_index = 0
        right_index = warehouse_size - 1
        box_count = 0
        box_index = len(boxes) - 1

        # Iterate through the boxes from largest to smallest

        while left_index <= right_index and box_index >= 0:
            # Check if the current box can fit in the
            # leftmost available room

            if boxes[box_index] <= warehouse[left_index]:
                box_count += 1
                left_index += 1
            # Check if the current box can fit in the
            # rightmost available room

            elif boxes[box_index] <= warehouse[right_index]:
                box_count += 1
                right_index -= 1
            box_index -= 1
        return box_count
