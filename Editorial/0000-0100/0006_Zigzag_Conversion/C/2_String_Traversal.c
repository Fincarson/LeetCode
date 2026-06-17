const char* convert(char* s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int n = strlen(s);
    char* answer = malloc((n + 1) * sizeof(char));
    int charsInSection = 2 * (numRows - 1);

    int ans_index = 0;
    for (int currRow = 0; currRow < numRows; currRow++) {
        int index = currRow;
        while (index < n) {
            answer[ans_index] = s[index];
            ans_index += 1;

            // If current row is not first or last,
            // then we have to add one more character of current section.
            if (currRow != 0 && currRow != numRows - 1) {
                int charsInBetween = charsInSection - 2 * currRow;
                int secondIndex = index + charsInBetween;

                if (secondIndex < n) {
                    answer[ans_index] = s[secondIndex];
                    ans_index += 1;
                }
            }
            // Jump to same row's first character of next section.
            index += charsInSection;
        }
    }
    answer[n] = '\0';
    return answer;
}
