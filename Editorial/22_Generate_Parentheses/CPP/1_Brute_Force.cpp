class Solution {
private:
    bool isValid(std::string pString) {
        int leftCount = 0;
        for (char p : pString) {
            if (p == '(') {
                leftCount++;
            } else {
                leftCount--;
            }
            if (leftCount < 0) {
                return false;
            }
        }
        return leftCount == 0;
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> answer;
        std::queue<std::string> queue;
        queue.push("");
        while (!queue.empty()) {
            std::string curString = queue.front();
            queue.pop();
            if (curString.length() == 2 * n) {
                if (isValid(curString)) {
                    answer.push_back(curString);
                }
                continue;
            }
            queue.push(curString + ")");
            queue.push(curString + "(");
        }
        return answer;
    }
};
