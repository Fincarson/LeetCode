struct answer {
    char** arr;
    int size;
};
struct answer getWords(int i, char** words, int wordsSize, int maxWidth) {
    struct answer currentLine;
    currentLine.arr = (char**)malloc(wordsSize * sizeof(char*));
    currentLine.size = 0;
    int currLength = 0;
    while (i < wordsSize && currLength + strlen(words[i]) <= maxWidth) {
        currentLine.arr[currentLine.size++] = words[i];
        currLength += strlen(words[i]) + 1;
        i++;
    }
    return currentLine;
}
