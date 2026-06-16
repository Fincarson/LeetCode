char* convert(char* s, int numRows) {
    if (numRows == 1)
        return s;  // If numRows is 1, return early as there is no zig zag

    int n = strlen(s);

    // The zig zag pattern creates what can be described as a section of
    // numRows-1 (numCols) columns
    int sections = ceil((float)n / (float)(2 * numRows - 2));
    int numCols = sections * (numRows - 1);

    // Create matrix
    char matrix[numRows][numCols];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = ' ';  // Fill with spaces
        }
    }

    // Initialize indices
    int currRow = 0, currCol = 0, currStringIndex = 0;

    // Iterate in zig-zag pattern on matrix and fill it with string characters.
    while (currStringIndex < n) {
        // Move down.
        while (currRow < numRows && currStringIndex < n) {
            matrix[currRow][currCol] = s[currStringIndex];
            currRow++;
            currStringIndex++;
        }

        // Move diagonally up to the right.
        currRow -= 2;
        currCol++;
        while (currRow > 0 && currCol < numCols && currStringIndex < n) {
            matrix[currRow][currCol] = s[currStringIndex];
            currRow--;
            currCol++;
            currStringIndex++;
        }
    }

    char* answer = malloc((n + 1) * sizeof(char));
    int index = 0;
    // Traverse matrix and collect characters to answer
    for (int a = 0; a < numRows; a++) {
        for (int b = 0; b < numCols; b++) {
            if (matrix[a][b] != ' ') {
                answer[index] =
                    matrix[a][b];  // Place in same string to save memory
                index++;
            }
        }
    }

    answer[index] = '\0';  // Ensure null termination
    return answer;
}
