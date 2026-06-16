public class Solution {
    public bool IsNumber(string s) {
        // This is the DFA we have designed above
        var dfa = new Dictionary<string, int>[] {
            new Dictionary<string, int> {
                { "digit", 1 }, { "sign", 2 }, { "dot", 3 }
            },
            new Dictionary<string, int> {
                { "digit", 1 }, { "dot", 4 }, { "exponent", 5 }
            },
            new Dictionary<string, int> { { "digit", 1 }, { "dot", 3 } },
            new Dictionary<string, int> { { "digit", 4 } },
            new Dictionary<string, int> { { "digit", 4 }, { "exponent", 5 } },
            new Dictionary<string, int> { { "sign", 6 }, { "digit", 7 } },
            new Dictionary<string, int> { { "digit", 7 } },
            new Dictionary<string, int> { { "digit", 7 } }
        };
        int currentState = 0;
        string group;
        foreach (char curr in s) {
            if (Char.IsDigit(curr)) {
                group = "digit";
            } else if (curr == '+' || curr == '-') {
                group = "sign";
            } else if (curr == 'e' || curr == 'E') {
                group = "exponent";
            } else if (curr == '.') {
                group = "dot";
            } else {
                return false;
            }

            if (!dfa[currentState].ContainsKey(group)) {
                return false;
            }

            currentState = dfa[currentState][group];
        }

        return currentState == 1 || currentState == 4 || currentState == 7;
    }
}
