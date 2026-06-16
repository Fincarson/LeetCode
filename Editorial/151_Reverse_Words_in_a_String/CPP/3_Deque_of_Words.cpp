class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') ++left;
        while (left <= right && s[right] == ' ') --right;

        deque<string> d;
        string word;

        while (left <= right) {
            if (s[left] == ' ' && !word.empty()) {
                d.push_front(word);
                word.clear();
            } else if (s[left] != ' ') {
                word += s[left];
            }
            ++left;
        }
        d.push_front(word);

        string result = "";
        while (!d.empty()) {
            result += d.front();
            d.pop_front();
            if (!d.empty()) {
                result += " ";
            }
        }
        return result;
    }
};
