public class Solution {
    private static Dictionary<string, Func<int, int, int>> OPERATIONS =
        new Dictionary<string, Func<int, int, int>>() {
            { "+", (int a, int b) => a + b },
            { "-", (int a, int b) => a - b },
            { "*", (int a, int b) => a * b },
            { "/", (int a, int b) => a / b }
        };

    public int EvalRPN(string[] tokens) {
        int currentPosition = 0;
        while (tokens.Length > 1) {
            while (!OPERATIONS.ContainsKey(tokens[currentPosition])) {
                currentPosition++;
            }

            string operation = tokens[currentPosition];
            int number1 = Int32.Parse(tokens[currentPosition - 2]);
            int number2 = Int32.Parse(tokens[currentPosition - 1]);
            Func<int, int, int> func = OPERATIONS[operation];
            int value = func(number1, number2);
            tokens[currentPosition] = value.ToString();
            List<string> tokenslist = tokens.ToList();
            tokenslist.RemoveRange(currentPosition - 2, 2);
            tokens = tokenslist.ToArray();
            currentPosition--;
        }

        return Int32.Parse(tokens[0]);
    }
}
