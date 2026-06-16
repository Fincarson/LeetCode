function wordBreak(s: string, wordDict: string[]): boolean {
    let memo: number[] = new Array(s.length).fill(-1);
    function isValid(i: number): boolean {
        if (i < 0) {
            return true;
        }
        if (memo[i] != -1) {
            return memo[i] === 1;
        }
        for (let word of wordDict) {
            let wordLen: number = word.length;
            if (i - wordLen + 1 < 0) {
                continue;
            }
            if (
                s.substring(i - wordLen + 1, i + 1) === word &&
                isValid(i - wordLen)
            ) {
                memo[i] = 1;
                return true;
            }
        }
        memo[i] = 0;
        return false;
    }
    return isValid(s.length - 1);
}
