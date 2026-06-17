class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        # Initialize a set to store negative numbers
        neg = set()
        
        # Loop through the numbers and insert negative numbers into the set
        for num in nums:
            if num < 0:
                neg.add(num)
        
        ans = -1
        
        for num in nums:
            # If current number is greater than ans and its negation exists in the set
            if num > ans and -num in neg:
                ans = num
        
        return ans
