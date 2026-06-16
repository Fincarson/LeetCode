char** generatePossibleNextMoves(char* currentState, int* returnSize) {
    // Initialize the return size.
    *returnSize = 0;
    // Allocate memory for the array of strings.
    char** nextPossibleStates = NULL;

    // Iterate through the 'currentState' string characters from left to right.
    for (size_t index = 0; index < strlen(currentState) - 1; ++index) {
        // If two adjacent characters of the 'currentState' string are '+', 
        // replace them with '-' and store the new state string.
        if (currentState[index] == '+' && currentState[index + 1] == '+') {
            // Allocate memory for the next state string.
            char* nextState = malloc((strlen(currentState) + 1) * sizeof(char));
            strcpy(nextState, currentState);
            nextState[index] = '-';
            nextState[index + 1] = '-';

            // Resize the array to store the new state.
            nextPossibleStates = realloc(nextPossibleStates, (*returnSize + 1) * sizeof(char*));
            nextPossibleStates[*returnSize] = nextState;
            ++(*returnSize);
        }
    }

    return nextPossibleStates;
}
