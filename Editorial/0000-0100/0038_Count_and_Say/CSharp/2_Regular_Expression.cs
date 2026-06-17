public class Solution {
    public string CountAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; i++) {
            StringBuilder current = new StringBuilder();
            for (int j = 0; j < s.Length; j++) {
                int count = 1;
                while (j < s.Length - 1 && s[j] == s[j + 1]) {
                    j++;
                    count++;
                }

                current.Append(count);
                current.Append(s[j]);
            }

            s = current.ToString();
        }

        return s;
    }
}
