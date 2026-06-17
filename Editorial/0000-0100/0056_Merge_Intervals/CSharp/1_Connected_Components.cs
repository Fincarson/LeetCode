public class Solution {
    IDictionary<int[], List<int[]>> graph =
        new Dictionary<int[], List<int[]>>();

    IDictionary<int, List<int[]>> nodesInComp =
        new Dictionary<int, List<int[]>>();

    HashSet<int[]> visited = new HashSet<int[]>();

    private bool Overlap(int[] a, int[] b) {
        return a[0] <= b[1] && b[0] <= a[1];
    }

    private void BuildGraph(int[][] intervals) {
        foreach (var interval in intervals) {
            graph[interval] = new List<int[]>();
        }

        for (int i = 0; i < intervals.Length; i++) {
            for (int j = 0; j < intervals.Length; j++) {
                if (this.Overlap(intervals[i], intervals[j])) {
                    graph.TryGetValue(intervals[i], out var val);
                    if (val != null) {
                        val.Add(intervals[j]);
                    }

                    graph.TryGetValue(intervals[j], out val);
                    if (val != null) {
                        val.Add(intervals[i]);
                    }
                }
            }
        }
    }

    private int[] MergeNodes(List<int[]> nodes) {
        int minStart = nodes[0][0];
        foreach (var node in nodes) {
            minStart = Math.Min(minStart, node[0]);
        }

        int maxEnd = nodes[0][1];
        foreach (var node in nodes) {
            maxEnd = Math.Max(maxEnd, node[1]);
        }

        return new int[] { minStart, maxEnd };
    }

    private void MarkComponentDFS(int[] start, Stack<int[]> stack,
                                  int compNumber) {
        stack.Push(start);
        while (stack.Count != 0) {
            int[] node = stack.Pop();
            if (!visited.Contains(node)) {
                visited.Add(node);
                if (!nodesInComp.ContainsKey(compNumber)) {
                    nodesInComp.Add(compNumber, new List<int[]>());
                }

                nodesInComp.TryGetValue(compNumber, out var val);
                val.Add(node);
                List<int[]> nodes = null;
                graph.TryGetValue(node, out nodes);
                foreach (var child in nodes) {
                    stack.Push(child);
                }
            }
        }
    }

    private void BuildComponents(int[][] intervals) {
        int compNumber = 0;
        Stack<int[]> stack = new Stack<int[]>();
        foreach (var interval in intervals) {
            if (!visited.Contains(interval)) {
                MarkComponentDFS(interval, stack, compNumber);
                compNumber++;
            }
        }
    }

    public int[][] Merge(int[][] intervals) {
        BuildGraph(intervals);
        BuildComponents(intervals);
        List<int[]> merged = new List<int[]>();
        for (int i = 0; i < nodesInComp.Count; i++) {
            merged.Add(MergeNodes(nodesInComp[i]));
        }

        return merged.ToArray();
    }
}
