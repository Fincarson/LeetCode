class Solution {
    public IList<string> GenerateParenthesis(int n) {
        List<string> answer = new List<string>();
        Backtracking(answer, new StringBuilder(), 0, 0, n);
        return answer;
    }

    private void Backtracking(List<string> answer, StringBuilder curString,
                              int leftCount, int rightCount, int n) {
        if (curString.Length == 2 * n) {
            answer.Add(curString.ToString());
            return;
        }

        if (leftCount < n) {
            curString.Append("(");
            Backtracking(answer, curString, leftCount + 1, rightCount, n);
            curString.Remove(curString.Length - 1, 1);
        }

        if (leftCount > rightCount) {
            curString.Append(")");
            Backtracking(answer, curString, leftCount, rightCount + 1, n);
            curString.Remove(curString.Length - 1, 1);
        }
    }
}
