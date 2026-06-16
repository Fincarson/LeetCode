class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        backtracking(answer, "", 0, 0, n);
        return answer;
    }

private:
    void backtracking(vector<string>& answer, string curString, int leftCount,
                      int rightCount, int n) {
        if (curString.size() == 2 * n) {
            answer.push_back(curString);
            return;
        }
        if (leftCount < n) {
            curString += '(';
            backtracking(answer, curString, leftCount + 1, rightCount, n);
            curString.pop_back();
        }
        if (leftCount > rightCount) {
            curString += ')';
            backtracking(answer, curString, leftCount, rightCount + 1, n);
            curString.pop_back();
        }
    }
};
