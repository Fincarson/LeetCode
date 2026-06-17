class Solution:
    def isArraySpecial(
        self, nums: List[int], queries: List[List[int]]
    ) -> List[bool]:
        n = len(nums)
        max_reach = [0] * n

        # Step 1: Compute the maximum reachable index for each starting index from last to first
        max_reach[-1] = n - 1  # The last index can only reach itself
        for i in range(n - 2, -1, -1):
            # Check if adjacent elements have different parity
            if nums[i] % 2 != nums[i + 1] % 2:
                max_reach[i] = max_reach[i + 1]  # Extend the reach
            else:
                max_reach[i] = i  # Can only reach itself

        ans = [False] * len(queries)

        # Step 2: Answer each query based on precomputed 'max_reach'
        for i, query in enumerate(queries):
            start, end = query
            # Check if the query range [start, end] lies within the max reachable range
            ans[i] = end <= max_reach[start]

        return ans
