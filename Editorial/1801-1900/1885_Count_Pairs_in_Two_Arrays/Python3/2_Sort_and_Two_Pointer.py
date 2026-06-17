class Solution:
    def countPairs(self, nums1, nums2):
        N = len(nums1)  # nums2 is the same length

        # Difference[i] stores nums1[i] - nums2[i]
        difference = [nums1[i] - nums2[i] for i in range(N)]
        difference.sort()

        # Count the number of valid pairs
        result = 0
        left = 0
        right = N - 1
        while left < right:
            # Left makes a valid pair with right
            # Right also makes a valid pair with the indices between the pointers
            if difference[left] + difference[right] > 0:
                result += right - left
                right -= 1
            # Left and right are not a valid pair
            else:
                left += 1
        return result
