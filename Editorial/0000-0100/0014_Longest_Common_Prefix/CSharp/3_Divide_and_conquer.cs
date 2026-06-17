public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs == null || strs.Length == 0)
            return "";
        return LongestCommonPrefix(strs, 0, strs.Length - 1);
    }

    private string LongestCommonPrefix(string[] strs, int l, int r) {
        if (l == r) {
            return strs[l];
        } else {
            int mid = (l + r) / 2;
            var lcpLeft = LongestCommonPrefix(strs, l, mid);
            var lcpRight = LongestCommonPrefix(strs, mid + 1, r);
            return CommonPrefix(lcpLeft, lcpRight);
        }
    }

    private string CommonPrefix(string left, string right) {
        int min = Math.Min(left.Length, right.Length);
        for (int i = 0; i < min; i++) {
            if (left[i] != right[i])
                return left.Substring(0, i);
        }

        return left.Substring(0, min);
    }
}
