public class Solution {
    private bool IsValid(string pString) {
        int leftCount = 0;
        foreach (char p in pString.ToCharArray()) {
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

    public IList<string> GenerateParenthesis(int n) {
        IList<string> answer = new List<string>();
        Queue<string> queue = new Queue<string>();
        queue.Enqueue("");
        while (queue.Count != 0) {
            string curString = queue.Dequeue();
            if (curString.Length == 2 * n) {
                if (IsValid(curString)) {
                    answer.Add(curString);
                }

                continue;
            }

            queue.Enqueue(curString + ")");
            queue.Enqueue(curString + "(");
        }

        return answer;
    }
}
