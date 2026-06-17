function findSubstring(s: string, words: string[]): number[] {
    let wordCount = new Map<string, number>(),
        wordLength = words[0].length,
        substringSize = words.length * wordLength,
        n = s.length,
        result: number[] = [];
    words.forEach((word) => {
        wordCount.set(word, (wordCount.get(word) || 0) + 1);
    });
    const slidingWindow = (left: number) => {
        let wordsFound = new Map<string, number>(),
            wordsUsed = 0,
            excessWord = false;
        for (let right = left; right <= n - wordLength; right += wordLength) {
            let sub = s.substring(right, right + wordLength);
            if (!wordCount.has(sub)) {
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                left = right + wordLength;
            } else {
                while (right - left === substringSize || excessWord) {
                    let leftmostWord = s.substring(left, left + wordLength);
                    left += wordLength;
                    wordsFound.set(
                        leftmostWord,
                        wordsFound.get(leftmostWord) - 1,
                    );
                    if (
                        wordsFound.get(leftmostWord) >=
                        wordCount.get(leftmostWord)
                    ) {
                        excessWord = false;
                    } else {
                        wordsUsed--;
                    }
                }
                wordsFound.set(sub, (wordsFound.get(sub) || 0) + 1);
                if (wordsFound.get(sub) <= wordCount.get(sub)) {
                    wordsUsed++;
                } else {
                    excessWord = true;
                }
                if (wordsUsed === words.length && !excessWord) {
                    result.push(left);
                }
            }
        }
    };
    for (let i = 0; i < wordLength; i++) {
        slidingWindow(i);
    }
    return result;
}
