from sortedcontainers import SortedList


class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        set_ = SortedList()
        for i in range(len(nums)):
            # Find the successor of current element
            idx = set_.bisect_left(nums[i])
            if idx != len(set_) and set_[idx] <= nums[i] + t:
                return True

            # Find the predecessor of current element
            if idx > 0 and nums[i] <= set_[idx - 1] + t:
                return True

            set_.add(nums[i])
            if len(set_) > k:
                set_.remove(nums[i - k])

        return False
