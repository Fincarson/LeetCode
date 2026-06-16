var findSubstring = function (s, words) {
    const n = s.length;
    const k = words.length;
    const wordLength = words[0].length;
    const substringSize = wordLength * k;
    const wordCount = {};
    words.forEach((word) => {
        wordCount[word] = (wordCount[word] || 0) + 1;
    });
    const check = (i) => {
        const remaining = Object.assign({}, wordCount);
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
    const answer = [];
    for (let i = 0; i < n - substringSize + 1; i++) {
        if (check(i)) {
            answer.push(i);
        }
    }
    return answer;
};
