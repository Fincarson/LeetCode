public class Solution {
    public int LengthOfLastWord(string s) {
        s = s.Trim();  // trim the trailing spaces in the string
        return s.Length - s.LastIndexOf(" ") - 1;
    }
}
