string removeDuplicates(string s, int k) {
    auto j = 0;
    stack<int> counts;
    for (auto i = 0; i < s.size(); ++i, ++j) {
        s[j] = s[i];
        if (j == 0 || s[j] != s[j - 1]) {
            counts.push(1);
        } else if (++counts.top() == k) {
            counts.pop();
            j -= k;
        }
    }
    return s.substr(0, j);
}
