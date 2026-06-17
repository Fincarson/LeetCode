class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        total_count = 1
        freq_map = defaultdict(lambda: defaultdict(int))

        # Calculate frequencies based on remainder
        for x in nums:
            freq_map[x % k][x] += 1

        # Calculate subsets for each remainder group
        for fr in freq_map.values():
            subsets = sorted(fr.items())
            total_count *= self._count_beautiful_subsets(
                subsets, len(subsets), k, 0
            )

        return total_count - 1  # Subtract 1 for the empty subset

    def _count_beautiful_subsets(self, subsets, num_subsets, difference, i):
        # Base case: Return 1 for a subset of size 1
        if i == num_subsets:
            return 1

        # Calculate subsets where the current subset is not taken
        skip = self._count_beautiful_subsets(
            subsets, num_subsets, difference, i + 1
        )

        # Calculate subsets where the current subset is taken
        take = (1 << subsets[i][1]) - 1

        # If next number has a 'difference', calculate subsets; otherwise, move to next
        if (
            i + 1 < num_subsets
            and subsets[i + 1][0] - subsets[i][0] == difference
        ):
            take *= self._count_beautiful_subsets(
                subsets, num_subsets, difference, i + 2
            )
        else:
            take *= self._count_beautiful_subsets(
                subsets, num_subsets, difference, i + 1
            )

        return skip + take  # Return total count of subsets
