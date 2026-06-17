class Solution(object):
    def intersection(self, nums1, nums2):

        # Initialize seen dictionary and res array
        seen = {}
        result = []

        # mark values occurring in nums1
        for x in nums1:
          seen[x] = 1
          
        for x in nums2:
          # Check if x is in the dictionary and not in the result
          if x in seen and seen[x] == 1:
            result.append(x)
            seen[x] = 0

        # Return the result
        return result
