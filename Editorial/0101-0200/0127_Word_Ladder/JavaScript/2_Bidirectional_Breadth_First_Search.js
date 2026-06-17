function ladderLength(beginWord, endWord, wordList) {
    if (wordList.indexOf(endWord) === -1) {
        return 0;
    }
    const len = beginWord.length;
    const allComboDict = new Map();
    wordList.forEach((word) => {
        for (let i = 0; i < len; i++) {
            const newWord =
                word.substring(0, i) + "*" + word.substring(i + 1, len);
            const transformations = allComboDict.get(newWord) || [];
            transformations.push(word);
            allComboDict.set(newWord, transformations);
        }
    });
    const queue = [{ word: beginWord, level: 1 }];
    const visited = { beginWord: true };
    while (queue.length) {
        const current = queue.shift();
        for (let i = 0; i < len; i++) {
            const newWord =
                current.word.substring(0, i) +
                "*" +
                current.word.substring(i + 1, len);
            if (allComboDict.has(newWord)) {
                for (const adjacentWord of allComboDict.get(newWord) || []) {
                    if (adjacentWord === endWord) {
                        return current.level + 1;
                    }
                    if (!visited[adjacentWord]) {
                        visited[adjacentWord] = true;
                        queue.push({
                            word: adjacentWord,
                            level: current.level + 1,
                        });
                    }
                }
            }
        }
    }
    return 0;
}
