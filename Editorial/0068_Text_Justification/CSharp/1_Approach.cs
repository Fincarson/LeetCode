private List<string> GetWords(int i, string[] words, int maxWidth) {
    var currentLine = new List<string>();
    int currLength = 0;
    while (i < words.Length && currLength + words[i].Length <= maxWidth) {
        currentLine.Add(words[i]);
        currLength += words[i].Length + 1;
        i++;
    }

    return currentLine;
}
