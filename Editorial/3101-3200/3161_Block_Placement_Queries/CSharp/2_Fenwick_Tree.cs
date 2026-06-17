public class Solution {
    private int[] bt;

    private void Update(int x, int v) {
        for (; x < bt.Length; x += x & -x) {
            bt[x] = Math.Max(bt[x], v);
        }
    }

    private int Query(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) {
            res = Math.Max(res, bt[x]);
        }
        return res;
    }

    public IList<bool> GetResults(int[][] queries) {
        int mx = 50000;

        SortedSet<int> st = new SortedSet<int> { 0, mx };
        foreach (int[] q in queries) {
            if (q[0] == 1) {
                st.Add(q[1]);
            }
        }

        List<int> sortedList = new List<int>(st);
        bt = new int[mx + 1];
        int pre = 0;
        for (int i = 0; i < sortedList.Count; i++) {
            int x = sortedList[i];
            if (x == 0) {
                continue;
            }
            Update(x, x - pre);
            pre = x;
        }

        List<bool> ans = new List<bool>();
        for (int i = queries.Length - 1; i >= 0; i--) {
            int[] q = queries[i];
            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                int idx = sortedList.BinarySearch(x);
                if (idx < 0) {
                    idx = ~idx - 1;
                }

                int preVal = sortedList[idx];
                int maxSpace = Query(preVal);
                maxSpace = Math.Max(maxSpace, x - preVal);
                ans.Add(maxSpace >= sz);
            } else {
                int x = q[1];

                int idx = sortedList.BinarySearch(x);
                int preVal = idx > 0 ? sortedList[idx - 1] : 0;
                int nxt = idx < sortedList.Count - 1 ? sortedList[idx + 1] : mx;

                Update(nxt, nxt - preVal);
                sortedList.RemoveAt(idx);
            }
        }

        ans.Reverse();
        return ans;
    }
}
