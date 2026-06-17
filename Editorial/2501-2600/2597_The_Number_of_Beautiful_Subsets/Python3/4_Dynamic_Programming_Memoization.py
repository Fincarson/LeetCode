class Solution:
    def beautifulSubsets(self, nums: List[int], k) -> int:
        total_count = 1
        freq_map = defaultdict(lambda: defaultdict(int))

        # Calculate frequencies based on remainder
        for x in nums:
            freq_map[x % k][x] += 1

        # Calculate subsets for each remainder group
        for fr in freq_map.values():
            s = sorted(fr.items())
            counts = [-1] * len(s)  # Store counts of subsets for memoization
            total_count *= self._count_beautiful_subsets(s, k, 0, counts)

        return total_count - 1  # Subtract 1 for the empty subset

    def _count_beautiful_subsets(
        self,
        subsets: List[List[int]],
        difference: int,
        i: int,
        counts: List[int],
    ) -> int:
        # Base case: Return 1 for a subset of size 1
        if i == len(subsets):
            return 1

        # If the count is already calculated, return it
        if counts[i] != -1:
            return counts[i]

        # Calculate subsets where the current subset is not taken
        skip = self._count_beautiful_subsets(subsets, difference, i + 1, counts)

        # Calculate subsets where the current subset is taken
        take = (1 << subsets[i][1]) - 1

        # If the next number has a difference of 'difference',
        # calculate subsets accordingly
        if (
            i + 1 < len(subsets)
            and subsets[i + 1][0] - subsets[i][0] == difference
        ):
            take *= self._count_beautiful_subsets(
                subsets, difference, i + 2, counts
            )
        else:
            take *= self._count_beautiful_subsets(
                subsets, difference, i + 1, counts
            )

        counts[i] = skip + take  # Store and return total count of subsets
        return counts[i]
