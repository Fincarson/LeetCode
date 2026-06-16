var generatePossibleNextMoves = function(currentState) {
    // Array to store all possible next states after making one move.
    const nextPossibleStates = [];

    // Iterate through the 'currentState' string characters from left to right.
    for (let index = 0; index < currentState.length - 1; ++index) {
        // If two adjacent characters of the 'currentState' string are '+', 
        // replace them with '-' and store the new state string.
        if (currentState[index] === '+' && currentState[index + 1] === '+') {
            const nextState = (
                  currentState.substring(0, index) + 
                  "--" + 
                  currentState.substring(index + 2)
            );
            nextPossibleStates.push(nextState);
        }
    }

    // Return 'nextPossibleStates' array.
    return nextPossibleStates;
};
