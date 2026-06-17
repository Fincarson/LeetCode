vector<string> getWords(int i, vector<string>& words, int maxWidth) {
    vector<string> currentLine;
    int currLength = 0;
    while (i < words.size() && currLength + words[i].size() <= maxWidth) {
        currentLine.push_back(words[i]);
        currLength += words[i].size() + 1;
        i++;
    }
    return currentLine;
}
