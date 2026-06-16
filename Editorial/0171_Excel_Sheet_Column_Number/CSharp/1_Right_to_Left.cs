public class Solution {
    public int TitleToNumber(string s) {
        int result = 0;

        Dictionary<Char, int> alpha_map = new Dictionary<Char, int>();
        for (int i = 0; i < 26; i++) {
            // Decimal 65 in ASCII corresponds to char 'A'
            Char c = Convert.ToChar(i + 65);
            alpha_map[c] = i + 1;
        }

        int n = s.Length;
        for (int i = 0; i < n; i++) {
            char cur_char = s[n - 1 - i];
            result += (alpha_map[cur_char] * ((int)Math.Pow(26, i)));
        }

        return result;
    }
}
