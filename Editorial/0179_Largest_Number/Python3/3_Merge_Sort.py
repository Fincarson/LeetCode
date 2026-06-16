class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Sort the numbers using Merge Sort
        sorted_nums = self._merge_sort(nums, 0, len(nums) - 1)
        # Concatenate sorted numbers to form the largest number
        largest_num = "".join(map(str, sorted_nums))
        # Handle the case where the largest number is zero
        return "0" if largest_num[0] == "0" else largest_num

    def _merge_sort(self, nums: List[int], left: int, right: int) -> List[int]:
        # Base case: a single element is already sorted
        if left >= right:
            return [nums[left]]
        mid = left + (right - left) // 2

        # Recursively sort the left and right halves
        left_half = self._merge_sort(nums, left, mid)
        right_half = self._merge_sort(nums, mid + 1, right)

        # Merge the sorted halves
        return self._merge(left_half, right_half)

    def _merge(self, left_half: List[int], right_half: List[int]) -> List[int]:
        sorted_nums = []
        left_index, right_index = 0, 0

        # Merge the two halves based on custom comparison
        while left_index < len(left_half) and right_index < len(right_half):
            if self._compare(left_half[left_index], right_half[right_index]):
                sorted_nums.append(left_half[left_index])
                left_index += 1
            else:
                sorted_nums.append(right_half[right_index])
                right_index += 1

        # Append remaining elements from left half
        sorted_nums.extend(left_half[left_index:])

        # Append remaining elements from right half
        sorted_nums.extend(right_half[right_index:])
        return sorted_nums

    def _compare(self, first_num: int, second_num: int) -> bool:
        # Compare concatenated strings to decide the order
        return str(first_num) + str(second_num) > str(second_num) + str(
            first_num
        )
