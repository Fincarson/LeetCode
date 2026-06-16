public class Solution {
    public int MaximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        var hEdges = GetEdges(hFences, m);
        var vEdges = GetEdges(vFences, n);

        long res = 0;
        foreach (int e in hEdges) {
            if (vEdges.Contains(e)) {
                res = Math.Max(res, e);
            }
        }

        if (res == 0) {
            return -1;
        } else {
            return (int)((res * res) % 1000000007);
        }
    }

    private HashSet<int> GetEdges(int[] fences, int border) {
        var set = new HashSet<int>();
        var list = new List<int>(fences);

        list.Add(1);
        list.Add(border);
        list.Sort();
        for (int i = 0; i < list.Count; i++) {
            for (int j = i + 1; j < list.Count; j++) {
                set.Add(list[j] - list[i]);
            }
        }

        return set;
    }
}
