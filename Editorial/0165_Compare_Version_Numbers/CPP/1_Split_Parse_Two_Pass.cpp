class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> tokens1, tokens2;
        istringstream iss1(version1), iss2(version2);
        string token;

        while (getline(iss1, token, '.')) tokens1.push_back(token);
        while (getline(iss2, token, '.')) tokens2.push_back(token);

        int i1, i2;
        for (int i = 0; i < max(tokens1.size(), tokens2.size()); ++i) {
            i1 = i < tokens1.size() ? stoi(tokens1[i]) : 0;
            i2 = i < tokens2.size() ? stoi(tokens2[i]) : 0;

            if (i1 != i2) return i1 > i2 ? 1 : -1;
        }
        // The versions are equal
        return 0;
    }
};
