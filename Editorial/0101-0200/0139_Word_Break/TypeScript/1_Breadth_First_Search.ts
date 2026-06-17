function wordBreak(s: string, wordDict: string[]): boolean {
    let words = new Set(wordDict);
    let queue = [0];
    let seen = new Set();
    while (queue.length !== 0) {
        let start = queue.shift();
        if (start == s.length) return true;
        for (let end = start + 1; end <= s.length; end++) {
            if (seen.has(end)) continue;
            if (words.has(s.substring(start, end))) {
                queue.push(end);
                seen.add(end);
            }
        }
    }
    return false;
}
