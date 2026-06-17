class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        # Use a dictionary to store the points and their counts
        point_to_count = defaultdict(int)

        # Mark the starting and ending points in the dictionary
        for interval in intervals:
            point_to_count[interval[0]] += 1  # Start of an interval
            point_to_count[
                interval[1] + 1
            ] -= 1  # End of an interval (interval[1] + 1)

        concurrent_intervals = 0
        max_concurrent_intervals = 0

        # Iterate over the sorted keys of the dictionary
        for point in sorted(point_to_count.keys()):
            concurrent_intervals += point_to_count[
                point
            ]  # Update currently active intervals
            max_concurrent_intervals = max(
                max_concurrent_intervals, concurrent_intervals
            )  # Update max intervals

        return max_concurrent_intervals
