class Solution {
public:
    string countOfAtoms(string formula) {
        // Regular expression to extract atom, count, (, ), multiplier
        // Every element of matcher will be a quintuple
        regex reg("([A-Z][a-z]*)(\\d*)|(\\()|(\\))(\\d*)");
        sregex_iterator it(formula.begin(), formula.end(), reg);
        sregex_iterator end;

        // Stack to keep track of the atoms and their counts
        stack<unordered_map<string, int>> stack;
        stack.push(unordered_map<string, int>());

        // Parse the formula
        while (it != end) {
            smatch match = *it;
            string atom = match[1].str();
            string count = match[2].str();
            string left = match[3].str();
            string right = match[4].str();
            string multiplier = match[5].str();

            // If atom, add it to the top hashmap
            if (!atom.empty()) {
                stack.top()[atom] += count.empty() ? 1 : stoi(count);
            }

            // If left parenthesis, insert a new hashmap to the stack
            else if (!left.empty()) {
                stack.push(unordered_map<string, int>());
            }

            // If right parenthesis, pop the top element from the stack
            // Multiply the count with the attached multiplicity.
            // Add the count to the current formula
            else if (!right.empty()) {
                unordered_map<string, int> currMap = stack.top();
                stack.pop();
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                for (auto& [atom, count] : currMap) {
                    stack.top()[atom] += count;
                }
            }

            it++;
        }

        // Sort the final map
        map<string, int> finalMap(stack.top().begin(), stack.top().end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : finalMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};
