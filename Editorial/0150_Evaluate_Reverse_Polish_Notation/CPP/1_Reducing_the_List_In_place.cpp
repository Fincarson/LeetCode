class Solution {
private:
    map<string, function<int(int, int)>> OPERATIONS = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }}};

public:
    int evalRPN(vector<string>& tokens) {
        int currentPosition = 0;
        while (tokens.size() > 1) {
            while (OPERATIONS.find(tokens[currentPosition]) ==
                   OPERATIONS.end()) {
                currentPosition++;
            }
            string operation = tokens[currentPosition];
            int number1 = stoi(tokens[currentPosition - 2]);
            int number2 = stoi(tokens[currentPosition - 1]);
            auto it = OPERATIONS.find(operation);
            int value = (it->second)(number1, number2);
            tokens[currentPosition] = to_string(value);
            tokens.erase(tokens.begin() + currentPosition - 2,
                         tokens.begin() + currentPosition);
            currentPosition--;
        }
        return stoi(tokens[0]);
    }
};
