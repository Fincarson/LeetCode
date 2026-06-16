class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        // Array to store all possible next states after making one move.
        vector<string> nextPossibleStates;

        // Iterate through the 'currentState' string characters from left to right.
        for (int index = 0; index < currentState.size() - 1; ++index) {
            // If two adjacent characters of the 'currentState' string are '+', 
            // replace them with '-' and store the new state string.
            if (currentState[index] == '+' and currentState[index + 1] == '+') {
                string nextState = (
                    currentState.substr(0, index) + 
                    "--" + 
                    currentState.substr(index + 2)
                );
                nextPossibleStates.push_back(nextState);
            }
        }
        // Return the 'nextPossibleStates' array.
        return nextPossibleStates;
    }
};
