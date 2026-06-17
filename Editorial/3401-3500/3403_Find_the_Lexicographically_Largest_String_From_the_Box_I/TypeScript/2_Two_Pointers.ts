function lastSubstring(s: string): string {
    let i = 0,
        j = 1,
        n = s.length;
    while (j < n) {
        let k = 0;
        while (j + k < n && s[i + k] === s[j + k]) {
            k++;
        }
        if (j + k < n && s[i + k] < s[j + k]) {
            let t = i;
            i = j;
            j = Math.max(j + 1, t + k + 1);
        } else {
            j = j + k + 1;
        }
    }
    return s.substring(i, n);
}

function answerString(word: string, numFriends: number): string {
    if (numFriends === 1) {
        return word;
    }
    let last: string = lastSubstring(word);
    let n: number = word.length;
    let m: number = last.length;
    return last.substring(0, Math.min(m, n - numFriends + 1));
}
