class Solution {
public:
    void storeAbbreviations(vector<string>& abbreviations, string& word,
                            string currWord, int index, int abbreviatedCount) {
        if (index == word.size()) {
            // If the length of the last abbreviated substring is 0, add an
            // empty string.
            currWord +=
                abbreviatedCount == 0 ? "" : to_string(abbreviatedCount);

            abbreviations.push_back(currWord);
            return;
        }

        // Abbreviated string corresponding to the last substring chosen.
        string abbreviatedString =
            abbreviatedCount == 0 ? "" : to_string(abbreviatedCount);

        storeAbbreviations(abbreviations, word,
                           currWord + abbreviatedString + word[index],
                           index + 1, 0);
        storeAbbreviations(abbreviations, word, currWord, index + 1,
                           abbreviatedCount + 1);
    }

    vector<string> generateAbbreviations(string word) {
        vector<string> abbreviations;

        storeAbbreviations(abbreviations, word, "", 0, 0);
        return abbreviations;
    }
};
