function minCut(s: string): number {
    let cutsDp: Array<number> = new Array<number>(s.length);
    let palindromeDp: Array<Array<boolean>> = Array.from(
        Array(s.length),
        () => new Array<boolean>(s.length),
    );
    // build the palindrome cutsDp for all susbtrings
    buildPalindromeDp(s, s.length, palindromeDp);
    for (let end = 0; end < s.length; end++) {
        let minimumCut: number = end;
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
    function buildPalindromeDp(
        s: string,
        n: number,
        palindromeDp: Array<Array<boolean>>,
    ) {
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
}
