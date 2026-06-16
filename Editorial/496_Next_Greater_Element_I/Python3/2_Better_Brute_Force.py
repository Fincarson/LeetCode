class Solution:
    def nextGreaterElement(
        self, nums1: List[int], nums2: List[int]
    ) -> List[int]:
        hash_table = {num: i for i, num in enumerate(nums2)}

        res = [0] * len(nums1)
        for i, num in enumerate(nums1):
            j = hash_table[num] + 1
            while j < len(nums2):
                if num < nums2[j]:
                    res[i] = nums2[j]
                    break
                j += 1
            else:
                res[i] = -1

        return res
