var minCut = function (s) {
    let cutsDp = new Array(s.length).fill(0);
    let palindromeDp = Array.from(Array(s.length), () =>
        new Array(s.length).fill(false),
    );
    // build the palindrome cutsDp for all susbtrings
    buildPalindromeDp(s, s.length);
    for (let end = 0; end < s.length; end++) {
        let minimumCut = end;
        for (let start = 0; start <= end; start++) {
            if (palindromeDp[start][end]) {
                minimumCut =
                    start === 0
                        ? 0
                        : Math.min(minimumCut, cutsDp[start - 1] + 1);
            }
        }
        cutsDp[end] = minimumCut;
    }
    return cutsDp[s.length - 1];
    function buildPalindromeDp(s, n) {
        for (let end = 0; end < s.length; end++) {
            for (let start = 0; start <= end; start++) {
                if (
                    s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])
                ) {
                    palindromeDp[start][end] = true;
                }
            }
        }
    }
};
