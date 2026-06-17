function minimumDistance(word: string): number {
    const n = word.length;
    const getDistance = (p: number, q: number): number => {
        const x1 = Math.floor(p / 6),
            y1 = p % 6;
        const x2 = Math.floor(q / 6),
            y2 = q % 6;
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    };

    const dp: number[][] = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(26).fill(Math.floor(Number.MAX_SAFE_INTEGER / 2));
    }
    for (let j = 0; j < 26; j++) {
        dp[0][j] = 0;
    }

    for (let i = 1; i < n; i++) {
        const cur = word.charCodeAt(i) - 65;
        const prev = word.charCodeAt(i - 1) - 65;
        const d = getDistance(prev, cur);

        for (let j = 0; j < 26; j++) {
            dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + d);

            if (prev === j) {
                for (let k = 0; k < 26; k++) {
                    const d0 = getDistance(k, cur);
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + d0);
                }
            }
        }
    }

    let ans = Math.floor(Number.MAX_SAFE_INTEGER / 2);
    for (let j = 0; j < 26; j++) {
        ans = Math.min(ans, dp[n - 1][j]);
    }
    return ans;
}
