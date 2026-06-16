class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        count = {}

        # Count occurrences of each number
        for num in arr:
            count[num] = count.get(num, 0) + 1

        for num in arr:
            # Check for double
            if num != 0 and 2 * num in count:
                return True
            # Handle zero case (ensure there are at least two zeros)
            if num == 0 and count[num] > 1:
                return True

        return False
