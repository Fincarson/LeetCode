public class Solution {
    public int ClosestTarget(string[] words, string target, int startIndex) {
        int ans = words.Length;
        int n = words.Length;

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int dist = Math.Abs(i - startIndex);
                ans = Math.Min(ans, Math.Min(dist, n - dist));
            }
        }

        return ans < n ? ans : -1;
    }
}
