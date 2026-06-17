string removeDuplicates(string s, int k) {
    int length = -1;
    while (length != s.size()) {
        length = s.size();
        for (int i = 0, count = 1; i < s.size(); ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                count = 1;
            } else if (++count == k) {
                s.erase(i - k + 1, k);
                break;
            }
        }
    }
    return s;
}
