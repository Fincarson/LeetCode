function getWords(i, words, maxWidth) {
    let currentLine = [];
    let currLength = 0;
    while (i < words.length && currLength + words[i].length <= maxWidth) {
        currentLine.push(words[i]);
        currLength += words[i].length + 1;
        i++;
    }
    return currentLine;
}
