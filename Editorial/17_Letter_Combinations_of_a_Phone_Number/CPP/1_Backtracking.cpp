class Solution {
private:
    vector<string> combinations;
    unordered_map<char, string> letters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string phoneDigits;

public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return combinations;
        }
        phoneDigits = digits;
        backtrack(0, "");
        return combinations;
    }

private:
    void backtrack(int index, string path) {
        if (path.length() == phoneDigits.length()) {
            combinations.push_back(path);
            return;
        }
        string possibleLetters = letters[phoneDigits[index]];
        for (char letter : possibleLetters) {
            path.push_back(letter);
            backtrack(index + 1, path);
            path.pop_back();
        }
    }
};
