public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        // If the intervals vector is empty, return a vector containing the
        // newInterval
        if (intervals.Length == 0) {
            return new int[][] { newInterval };
        }

        int n = intervals.Length;
        int target = newInterval[0];
        int left = 0, right = n - 1;

        // Binary search to find the position to insert newInterval
        while (left <= right) {
            int mid = (left + right) / 2;
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Insert newInterval at the found position
        List<int[]> result = new List<int[]>();
        for (int i = 0; i < left; i++) {
            result.Add(intervals[i]);
        }

        result.Add(newInterval);
        for (int i = left; i < n; i++) {
            result.Add(intervals[i]);
        }

        // Merge overlapping intervals
        List<int[]> merged = new List<int[]>();
        foreach (int[] interval in result) {
            // If res is empty or there is no overlap, add the interval to the
            // result
            if (merged.Count == 0 ||
                merged[merged.Count - 1][1] < interval[0]) {
                merged.Add(interval);
                // If there is an overlap, merge the intervals by updating the
                // end of the last interval in res
            } else {
                merged[merged.Count - 1][1] =
                    Math.Max(merged[merged.Count - 1][1], interval[1]);
            }
        }

        return merged.ToArray();
    }
}
