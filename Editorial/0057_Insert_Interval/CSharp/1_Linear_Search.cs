public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        int n = intervals.Length, i = 0;
        List<int[]> res = new List<int[]>();

        // Case 1: No overlapping before merging intervals
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.Add(intervals[i]);
            i++;
        }

        // Case 2: Overlapping and merging intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = Math.Min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.Max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.Add(newInterval);

        // Case 3: No overlapping after merging newInterval
        while (i < n) {
            res.Add(intervals[i]);
            i++;
        }

        return res.ToArray();
    }
}
