class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        left, right = 0, n - 1

        # We need to find the rightmost 'index' such that: (citations[index] <= n - index)
        while left <= right:
            mid = left + (right - left) // 2

            # There are (n - mid) papers with an equal or higher citation count than citations[mid]
            # If (citations[mid] == n - mid) it's the optimal result and can be returned right away
            if citations[mid] == n - mid:
                return n - mid

            # If citations[mid] are less than (n - mid), narrow down on the right half to look for a paper
            # at a future index that meets the h-index criteria. Otherwise, narrow down on the left half
            if citations[mid] < n - mid:
                left = mid + 1
            else:
                right = mid - 1

        # We didn't find an exact match, so there are exactly (n - left) papers that have citations
        # greater than or equal to citations[left] and that is our answer
        return n - left
