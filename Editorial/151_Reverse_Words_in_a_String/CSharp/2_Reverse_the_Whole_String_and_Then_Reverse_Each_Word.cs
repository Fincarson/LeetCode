// Translated C# solution

public class Solution {
    public string ReverseWords(string s) {
        StringBuilder sb = TrimSpaces(s);
        // reverse the whole string
        Reverse(sb, 0, sb.Length - 1);
        // reverse each word
        ReverseEachWord(sb);
        return sb.ToString();
    }

    private StringBuilder TrimSpaces(string s) {
        int left = 0, right = s.Length - 1;
        // remove leading spaces
        while (left <= right && s[left] == ' ') ++left;
        // remove trailing spaces
        while (left <= right && s[right] == ' ') --right;
        // reduce multiple spaces to single one
        StringBuilder sb = new StringBuilder();
        while (left <= right) {
            if (s[left] != ' ') sb.Append(s[left]);
            else if (sb[sb.Length - 1] != ' ') sb.Append(s[left]);
            ++left;
        }

        return sb;
    }

    private void ReverseEachWord(StringBuilder sb) {
        int n = sb.Length;
        int start = 0, end = 0;
        while (start < n) {
            // go to the end of the word
            while (end < n && sb[end] != ' ') ++end;
            // reverse the word
            Reverse(sb, start, end - 1);
            // move to the next word
            start = end + 1;
            ++end;
        }
    }

    private void Reverse(StringBuilder sb, int left, int right) {
        while (left < right) {
            char tmp = sb[left];
            sb[left++] = sb[right];
            sb[right--] = tmp;
        }
    }
}
