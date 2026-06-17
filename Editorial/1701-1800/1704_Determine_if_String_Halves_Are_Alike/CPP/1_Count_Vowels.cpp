class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();

        string vowels = "aeiouAEIOU";
        string a = s.substr(0, n / 2);
        string b = s.substr(n / 2);

        int aVowelCount = 0;
        for (auto c : a) {
            if (vowels.find(c) != string::npos) {
                aVowelCount++;
            }
        }

        int bVowelCount = 0;
        for (auto c : b) {
            if (vowels.find(c) != string::npos) {
                bVowelCount++;
            }
        }

        return aVowelCount == bVowelCount;
    }
};
