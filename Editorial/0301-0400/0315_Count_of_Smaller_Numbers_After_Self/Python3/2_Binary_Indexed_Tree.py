class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # implement Binary Index Tree
        def update(index, value, tree, size):
            index += 1  # index in BIT is 1 more than the original index
            while index < size:
                tree[index] += value
                index += index & -index

        def query(index, tree):
            # return sum of [0, index)
            result = 0
            while index >= 1:
                result += tree[index]
                index -= index & -index
            return result

        offset = 10**4  # offset negative to non-negative
        size = 2 * 10**4 + 2  # total possible values in nums plus one dummy
        tree = [0] * size
        result = []
        for num in reversed(nums):
            smaller_count = query(num + offset, tree)
            result.append(smaller_count)
            update(num + offset, 1, tree, size)
        return reversed(result)
