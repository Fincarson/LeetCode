class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        list_size = len(nums)

        # Find the maximum element in the list
        max_element = max(nums)

        # Initialize a bucket list to store counts of each distance
        distance_bucket = [0] * (max_element + 1)

        # Populate the bucket list with counts of each distance
        for i in range(list_size):
            for j in range(i + 1, list_size):
                # Compute the distance between nums[i] and nums[j]
                distance = abs(nums[i] - nums[j])

                # Increment the count for this distance in the bucket
                distance_bucket[distance] += 1

        # Find the k-th smallest distance
        for dist in range(max_element + 1):
            # Reduce k by the number of pairs with the current distance
            k -= distance_bucket[dist]

            # If k is less than or equal to 0, return the current distance
            if k <= 0:
                return dist

        return -1  # Return -1 if no distance found, should not reach here
