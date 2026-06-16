class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        n = len(gifts)

        # Create a copy of the gifts array and sort it
        sorted_gifts = sorted(gifts)

        # Perform the operation k times
        for _ in range(k):
            max_element = sorted_gifts[-1]
            sorted_gifts.pop()

            # Find the index where the square root of max_element should be inserted
            sqrt_value = math.isqrt(max_element)
            spot_of_sqrt = bisect.bisect_right(sorted_gifts, sqrt_value)

            # Insert the square root value at the correct position
            sorted_gifts.insert(spot_of_sqrt, sqrt_value)

        # Calculate the sum of the remaining elements in the sorted array
        number_of_remaining_gifts = sum(sorted_gifts)

        return number_of_remaining_gifts
