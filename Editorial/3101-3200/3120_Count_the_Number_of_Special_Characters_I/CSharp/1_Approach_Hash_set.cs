public class Solution {
    public int NumberOfSpecialChars(string word) {
        var s = new HashSet<char>(word);
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.Contains(c) && s.Contains((char)(c - 'a' + 'A'))) {
                ans++;
            }
        }
        return ans;
    }
}
