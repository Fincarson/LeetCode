class Solution {
    public List<String> generatePossibleNextMoves(String currentState) {
        // List to store all possible next states after making one move.
        List<String> nextPossibleStates = new ArrayList<>();

        // Iterate through the 'currentState' string characters from left to right.
        for (int index = 0; index < currentState.length() - 1; ++index) {
            // If two adjacent characters of the 'currentState' string are '+', 
            // replace them with '-' and store the new state string.
            if (currentState.charAt(index) == '+' && currentState.charAt(index + 1) == '+') {
                String nextState = (
                    currentState.substring(0, index) + 
                    "--" + 
                    currentState.substring(index + 2)
                );
                nextPossibleStates.add(nextState);
            }
        }

        // Return 'nextPossibleStates' list.
        return nextPossibleStates;
    }
}
