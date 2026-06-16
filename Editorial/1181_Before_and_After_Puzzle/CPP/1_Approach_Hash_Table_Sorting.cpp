class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        int n = phrases.size();
        vector<pair<string, string>> sp;
        for (const string& phrase : phrases) {
            size_t lastSpace = phrase.rfind(' ');
            string first = phrase.substr(0, phrase.find(' '));
            string last = (lastSpace == string::npos)
                              ? phrase
                              : phrase.substr(lastSpace + 1);
            sp.push_back({first, last});
        }

        set<string> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (sp[i].first == sp[j].second) {
                    string combined =
                        phrases[j] + phrases[i].substr(sp[i].first.length());
                    m.emplace(combined);
                }
            }
        }

        vector<string> ret;
        for (const auto& entry : m) {
            ret.push_back(entry);
        }
        return ret;
    }
};
