class Solution {
public:
    string countAndSay(int n) {
        regex e("(.)\\1*");
        string s = "1";
        for (int i = 2; i <= n; i++) {
            string t;
            for (sregex_iterator it = sregex_iterator(s.begin(), s.end(), e);
                 it != sregex_iterator(); it++) {
                t += to_string(it->str().size()) + it->str(1);
            }
            s = t;
        }
        return s;
    }
};
