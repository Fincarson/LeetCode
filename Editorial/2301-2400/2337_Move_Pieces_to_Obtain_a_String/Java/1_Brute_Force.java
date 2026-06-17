class Solution {

    public boolean canChange(String start, String target) {
        // To keep track of visited states to avoid cycles
        Set<String> visitedStates = new HashSet<>();
        // Queue for current state
        Queue<String> stateQueue = new LinkedList<>();
        // Start with the initial state
        stateQueue.add(start);

        while (!stateQueue.isEmpty()) {
            String currentState = stateQueue.poll();

            // If we reach the target state, return true
            if (currentState.equals(target)) return true;

            for (
                int position = 1;
                position < currentState.length();
                position++
            ) {
                // Try moving 'L' to the left
                if (
                    currentState.charAt(position) == 'L' &&
                    currentState.charAt(position - 1) == '_'
                ) {
                    char[] stateArray = currentState.toCharArray();
                    swap(stateArray, position, position - 1);
                    String newState = new String(stateArray);
                    if (!visitedStates.contains(newState)) {
                        // Add the new state to the queue
                        stateQueue.add(newState);
                        // Mark the new state as visited
                        visitedStates.add(newState);
                    }
                    // Restore the state
                    swap(stateArray, position, position - 1);
                }
                // Try moving 'R' to the right
                if (
                    currentState.charAt(position - 1) == 'R' &&
                    currentState.charAt(position) == '_'
                ) {
                    char[] stateArray = currentState.toCharArray();
                    swap(stateArray, position, position - 1);
                    String newState = new String(stateArray);
                    if (!visitedStates.contains(newState)) {
                        // Add the new state to the queue
                        stateQueue.add(newState);
                        // Mark the new state as visited
                        visitedStates.add(newState);
                    }
                    // Restore the state
                    swap(stateArray, position, position - 1);
                }
            }
        }

        // If no valid transformation sequence is found, return false
        return false;
    }

    private void swap(char[] array, int i, int j) {
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
