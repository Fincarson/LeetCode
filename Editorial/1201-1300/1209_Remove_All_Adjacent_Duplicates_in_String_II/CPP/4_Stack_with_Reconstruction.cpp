string removeDuplicates(string s, int k) {
    vector<pair<int, char>> counts;
    for (int i = 0; i < s.size(); ++i) {
        if (counts.empty() || s[i] != counts.back().second) {
            counts.push_back({ 1, s[i] });
        } else if (++counts.back().first == k) {
            counts.pop_back();
        }
    }
    s = "";
    for (auto &p : counts) {
        s += string(p.first, p.second);
    }
    return s;
}
