public class Solution {
    public string[] DivideString(string s, int k, char fill) {
        List<string> res = new List<string>();  // grouped string
        int n = s.Length;
        int curr = 0;  // starting index of each group
        // split string
        while (curr < n) {
            int end = Math.Min(curr + k, n);
            res.Add(s.Substring(curr, end - curr));
            curr += k;
        }
        // try to fill in the last group
        string last = res[res.Count - 1];
        if (last.Length < k) {
            last += new string(fill, k - last.Length);
            res[res.Count - 1] = last;
        }
        return res.ToArray();
    }
}
