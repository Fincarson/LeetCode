public class Solution {
    public string GenerateString(string str1, string str2) {
        int n = str1.Length, m = str2.Length;
        char[] s = new char[n + m - 1];
        int[] fixed_ = new int[n + m - 1];

        for (int i = 0; i < s.Length; i++) {
            s[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = i; j < i + m; j++) {
                    if (fixed_[j] == 1 && s[j] != str2[j - i]) {
                        return "";
                    } else {
                        s[j] = str2[j - i];
                        fixed_[j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool flag = false;
                int idx = -1;
                for (int j = i + m - 1; j >= i; j--) {
                    if (str2[j - i] != s[j]) {
                        flag = true;
                    }
                    if (idx == -1 && fixed_[j] == 0) {
                        idx = j;
                    }
                }
                if (flag) {
                    continue;
                } else if (idx != -1) {
                    s[idx] = 'b';
                } else {
                    return "";
                }
            }
        }
        return new string(s);
    }
}
