class Solution:
    def nextGreaterElement(self, nums1, nums2):
        stack = []
        hashmap = {}

        for num in nums2:
            while stack and num > stack[-1]:
                hashmap[stack.pop()] = num
            stack.append(num)

        return [hashmap.get(i, -1) for i in nums1]
