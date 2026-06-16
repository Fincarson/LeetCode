class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push('(');
            } else if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }

    int longestValidParentheses(std::string s) {
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 2; j <= s.length(); j += 2) {
                if (isValid(s.substr(i, j - i))) {
                    maxlen = std::max(maxlen, j - i);
                }
            }
        }
        return maxlen;
    }
};
