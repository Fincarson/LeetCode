class Solution {
public:
    string reverseWords(string s) {
        // remove leading and trailing spaces
        s.erase(0, s.find_first_not_of(' '));  // prefixing spaces
        s.erase(s.find_last_not_of(' ') + 1);  // suffixing spaces

        // split by spaces
        istringstream iss(s);
        vector<string> words;
        copy(istream_iterator<string>(iss), istream_iterator<string>(),
             back_inserter(words));

        // reverse and join
        reverse(words.begin(), words.end());
        ostringstream oss;
        copy(words.begin(), words.end() - 1,
             ostream_iterator<string>(oss, " "));
        oss << words[words.size() - 1];
        return oss.str();
    }
};
