class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> operations = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"/", [](int a, int b) { return a / b; }},
            {"*", [](int a, int b) { return a * b; }}};
        stack<int> stk;
        for (string& token : tokens) {
            if (!operations.count(token)) {
                stk.push(stoi(token));
            } else {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                function<int(int, int)> operation = operations[token];
                int result = operation(op1, op2);
                stk.push(result);
            }
        }
        return stk.top();
    }
};
