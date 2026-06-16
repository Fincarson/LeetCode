class Solution:
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:

        i = 0
        count = 0
        boxes.sort(reverse = True)

        for room in warehouse:
            # Iterate through boxes from largest to smallest
            # Discard boxes that doesn't fit in the current warehouse
            while i < len(boxes) and boxes[i] > room:
                i += 1
            if i == len(boxes):
                return count
            count += 1
            i += 1

        return count
