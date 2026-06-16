public class Solution {
    public int LengthOfLastWord(string s) {
        // trim the trailing spaces
        int p = s.Length - 1;
        while (p >= 0 && s[p] == ' ') {
            p--;
        }

        // compute the length of last word
        int length = 0;
        while (p >= 0 && s[p] != ' ') {
            p--;
            length++;
        }

        return length;
    }
}
