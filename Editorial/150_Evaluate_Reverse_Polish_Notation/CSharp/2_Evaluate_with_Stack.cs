public class Solution {
    private static Dictionary<string, Func<int, int, int>> OPERATIONS =
        new Dictionary<string, Func<int, int, int>>() {
            { "+", (int a, int b) => a + b },
            { "-", (int a, int b) => a - b },
            { "*", (int a, int b) => a * b },
            { "/", (int a, int b) => a / b }
        };

    public int EvalRPN(string[] tokens) {
        Stack<int> stack = new Stack<int>();
        foreach (string token in tokens) {
            if (!OPERATIONS.ContainsKey(token)) {
                stack.Push(Int32.Parse(token));
                continue;
            }

            int number2 = stack.Pop();
            int number1 = stack.Pop();
            Func<int, int, int> operation = OPERATIONS[token];
            int result = operation(number1, number2);
            stack.Push(result);
        }

        return stack.Pop();
    }
}
