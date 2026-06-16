public class Solution {
    public int MinOperations(string s, int k) {
        int n = s.Length, m = 0;
        int[] dist = new int[n + 1];
        for (int i = 0; i <= n; i++) dist[i] = int.MaxValue;

        List<SortedSet<int>> nodeSets = new List<SortedSet<int>>();
        nodeSets.Add(new SortedSet<int>());
        nodeSets.Add(new SortedSet<int>());
        for (int i = 0; i <= n; i++) {
            nodeSets[i % 2].Add(i);
            if (i < n && s[i] == '0') {
                m++;
            }
        }

        Queue<int> q = new Queue<int>();
        q.Enqueue(m);
        dist[m] = 0;
        nodeSets[m % 2].Remove(m);
        while (q.Count > 0) {
            m = q.Dequeue();
            int c1 = Math.Max(k - n + m, 0);
            int c2 = Math.Min(m, k);
            int lnode = m + k - 2 * c2;
            int rnode = m + k - 2 * c1;

            var nodeSet = nodeSets[lnode % 2];
            var toRemove = new List<int>();
            var view = nodeSet.GetViewBetween(lnode, rnode);
            foreach (var val in view) {
                toRemove.Add(val);
            }
            foreach (int m2 in toRemove) {
                dist[m2] = dist[m] + 1;
                q.Enqueue(m2);
                nodeSet.Remove(m2);
            }
        }

        return dist[0] == int.MaxValue ? -1 : dist[0];
    }
}
