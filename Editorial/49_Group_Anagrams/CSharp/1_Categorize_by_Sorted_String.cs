public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        var dict = new Dictionary<string, List<string>>();
        foreach (var s in strs) {
            var ca = s.ToCharArray();
            Array.Sort(ca);
            var key = new String(ca);
            if (!dict.ContainsKey(key))
                dict[key] = new List<string>();
            dict[key].Add(s);
        }

        return new List<IList<string>>(dict.Values);
    }
}
