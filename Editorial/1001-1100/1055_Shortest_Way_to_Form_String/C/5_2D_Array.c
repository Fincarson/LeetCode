int shortestWay(char * source, char * target){

    // Length of source
    int sourceLength = strlen(source);

    // Next Occurrence of Character after Index
    int nextOccurrence[sourceLength][26];

    // Base Case
    for (int c = 0; c < 26; c++) {
        nextOccurrence[sourceLength - 1][c] = -1;
    }
    nextOccurrence[sourceLength - 1][source[sourceLength - 1] - 'a'] = sourceLength - 1;

    // Fill using recurrence relation
    for (int idx = sourceLength - 2; idx >= 0; idx--) {
        for (int c = 0; c < 26; c++) {
            nextOccurrence[idx][c] = nextOccurrence[idx + 1][c];
        }
        nextOccurrence[idx][source[idx] - 'a'] = idx;
    }

    // Pointer to the current index in source
    int sourceIterator = 0;

    // Number of times we need to iterate through source
    int count = 1;

    // Find all characters of target in source
    for (int idx = 0; target[idx] != '\0'; idx++) {

        // If the character is not present in source
        if (nextOccurrence[0][target[idx] - 'a'] == -1) {
            return -1;
        }

        // If we have reached the end of source, or the character is not in
        // source after source_iterator, loop back to beginning
        if (sourceIterator == sourceLength || nextOccurrence[sourceIterator][target[idx] - 'a'] == -1) {
            count++;
            sourceIterator = 0;
        }

        // Next occurrence of character in source after source_iterator
        sourceIterator = nextOccurrence[sourceIterator][target[idx] - 'a'] + 1;
    }

    // Return the number of times we need to iterate through source
    return count;
}
