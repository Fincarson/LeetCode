public class Solution {
    public int[][] Merge(int[][] intervals) {
        Array.Sort(intervals, (a, b) => a[0] - b[0]);
        LinkedList<int[]> merged = new LinkedList<int[]>();
        foreach (int[] interval in intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, append it
            if (merged.Count == 0 || merged.Last.Value[1] < interval[0]) {
                merged.AddLast(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals
            else {
                merged.Last.Value[1] =
                    Math.Max(merged.Last.Value[1], interval[1]);
            }
        }

        return merged.ToArray();
    }
}
