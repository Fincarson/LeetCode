function ladderLength(
    beginWord: string,
    endWord: string,
    wordList: string[],
): number {
    let L: number = beginWord.length;
    let allComboDict: { [key: string]: string[] } = {};
    for (let word of wordList) {
        for (let i = 0; i < L; i++) {
            let newWord = word.substring(0, i) + "*" + word.substring(i + 1, L);
            if (!allComboDict[newWord]) allComboDict[newWord] = [];
            allComboDict[newWord].push(word);
        }
    }
    let Q: [string, number][] = [[beginWord, 1]];
    let visited: { [key: string]: boolean } = { [beginWord]: true };
    while (Q.length > 0) {
        let node = Q.shift() as [string, number];
        let word: string = node[0];
        let level: number = node[1];
        for (let i = 0; i < L; i++) {
            let newWord = word.substring(0, i) + "*" + word.substring(i + 1, L);
            for (let adjacentWord of allComboDict[newWord] || []) {
                if (adjacentWord === endWord) return level + 1;
                if (!visited[adjacentWord]) {
                    visited[adjacentWord] = true;
                    Q.push([adjacentWord, level + 1]);
                }
            }
        }
    }
    return 0;
}
