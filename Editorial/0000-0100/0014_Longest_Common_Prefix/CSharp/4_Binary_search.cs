public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs == null || strs.Length == 0)
            return "";
        int minLen = Int32.MaxValue;
        foreach (string str in strs) minLen = Math.Min(minLen, str.Length);
        int low = 1;
        int high = minLen;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (IsCommonPrefix(strs, middle))
                low = middle + 1;
            else
                high = middle - 1;
        }

        return strs[0].Substring(0, (low + high) / 2);
    }

    private bool IsCommonPrefix(string[] strs, int len) {
        string str1 = strs[0].Substring(0, len);
        for (int i = 1; i < strs.Length; i++)
            if (!strs[i].StartsWith(str1))
                return false;
        return true;
    }
}
