function findSubstring(s: string, words: string[]): number[] {
    const n = s.length;
    const k = words.length;
    const wordLength = words[0].length;
    const substringSize = wordLength * k;
    const wordCount: Record<string, number> = {};
    words.forEach((word) => {
        wordCount[word] = (wordCount[word] || 0) + 1;
    });
    const check = (i: number): boolean => {
        const remaining: Record<string, number> = { ...wordCount };
        let wordsUsed = 0;
        for (let j = i; j < i + substringSize; j += wordLength) {
            const sub = s.slice(j, j + wordLength);
            if (remaining[sub]) {
                remaining[sub]--;
                wordsUsed++;
            } else {
                break;
            }
        }
        return wordsUsed === k;
    };
    const answer: number[] = [];
    for (let i = 0; i < n - substringSize + 1; i++) {
        if (check(i)) {
            answer.push(i);
        }
    }
    return answer;
}
