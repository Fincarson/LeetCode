public class Solution {
    public IList<IList<string>> Partition(string s) {
        var ans = new List<IList<string>>();
        Dfs(0, new List<string>(), s, ans);
        return ans;
    }

    private void Dfs(int start, List<string> currentList, string s,
                     List<IList<string>> result) {
        if (start >= s.Length)
            result.Add(new List<string>(currentList));
        else {
            for (int end = start; end < s.Length; end++) {
                if (IsPalindrome(s, start, end)) {
                    currentList.Add(s.Substring(start, end - start + 1));
                    Dfs(end + 1, currentList, s, result);
                    currentList.RemoveAt(currentList.Count - 1);
                }
            }
        }
    }

    bool IsPalindrome(string s, int low, int high) {
        while (low < high)
            if (s[low++] != s[high--])
                return false;
        return true;
    }
}
