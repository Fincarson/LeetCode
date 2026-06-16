var findSubstring = function (s, words) {
    if (words.length === 0) return [];
    const wordCount = new Map();
    const wordLength = words[0].length;
    const substringSize = words.length * wordLength;
    const n = s.length;
    const result = [];
    for (let word of words) {
        wordCount.set(word, (wordCount.get(word) || 0) + 1);
    }
    const slidingWindow = function (left) {
        const wordsFound = new Map();
        let wordsUsed = 0;
        let excessWord = false;
        for (let right = left; right <= n - wordLength; right += wordLength) {
            const sub = s.substring(right, right + wordLength);
            if (!wordCount.has(sub)) {
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                left = right + wordLength;
            } else {
                while (right - left === substringSize || excessWord) {
                    const leftmostWord = s.substring(left, left + wordLength);
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
};
