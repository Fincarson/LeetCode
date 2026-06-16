public class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int maxlen = 0;
        for (int i = 0; i < (1 << strs.length); i++) {
            int zeroes = 0, ones = 0, len = 0;
            for (int j = 0; j < strs.length; j++) {
                if ((i & (1 << j)) != 0) {
                    int[] count = countzeroesones(strs[j]);
                    zeroes += count[0];
                    ones += count[1];
                    len++;
                }
            }
            if (zeroes <= m && ones <= n)
                maxlen = Math.max(maxlen, len);
        }
        return maxlen;

    }
    public int[] countzeroesones(String s) {
        int[] c = new int[2];
        for (int i = 0; i < s.length(); i++) {
            c[s.charAt(i)-'0']++;
        }
        return c;
    }
}
