func generatePossibleNextMoves(currentState string) []string {
    // Slice to store all possible next states after making one move.
	var nextPossibleStates []string

	// Iterate through the 'currentState' string characters from left to right.
	for index := 0; index < len(currentState)-1; index++ {
		// If two adjacent characters of the 'currentState' string are '+', 
		// replace them with '-' and store the new state string.
		if currentState[index] == '+' && currentState[index+1] == '+' {
			nextState := currentState[:index] + "--" + currentState[index+2:]
			nextPossibleStates = append(nextPossibleStates, nextState)
		}
	}

	// Return 'nextPossibleStates' slice.
	return nextPossibleStates
}
