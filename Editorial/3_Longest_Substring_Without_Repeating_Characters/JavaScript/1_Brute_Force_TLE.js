var lengthOfLongestSubstring = function (s) {
    const n = s.length;

    let res = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            if (checkRepetition(s, i, j)) {
                res = Math.max(res, j - i + 1);
            }
        }
    }

    function checkRepetition(s, start, end) {
        const chars = new Set();

        for (let i = start; i <= end; i++) {
            const c = s[i];
            if (chars.has(c)) {
                return false;
            }
            chars.add(c);
        }

        return true;
    }

    return res;
};
