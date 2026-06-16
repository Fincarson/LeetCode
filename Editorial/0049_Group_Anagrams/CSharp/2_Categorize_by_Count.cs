public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        if (strs.Length == 0)
            return new List<IList<string>>();  // an empty string
        Dictionary<string, List<string>> ans =
            new Dictionary<string, List<string>>();
        int[] count = new int[26];
        foreach (string s in strs) {
            for (int i = 0; i < 26; ++i) {
                count[i] = 0;
            }

            // Increase the count as per char
            foreach (char c in s) count[c - 'a']++;
            StringBuilder sb = new StringBuilder("");
            for (int i = 0; i < 26; i++) {
                sb.Append('#');
                sb.Append(count[i]);
            }

            string key = sb.ToString();
            if (!ans.ContainsKey(key))
                ans[key] = new List<string>();
            ans[key].Add(s);
        }

        return new List<IList<string>>(ans.Values);
    }
}
