public class Solution {
    public IList<string> TwoEditWords(string[] queries, string[] dictionary) {
        var ans = new List<string>();
        foreach (var query in queries) {
            foreach (var s in dictionary) {
                int dis = 0;
                for (int i = 0; i < query.Length; i++) {
                    if (query[i] != s[i]) {
                        dis++;
                    }
                }
                if (dis <= 2) {
                    ans.Add(query);
                    break;
                }
            }
        }
        return ans;
    }
}
