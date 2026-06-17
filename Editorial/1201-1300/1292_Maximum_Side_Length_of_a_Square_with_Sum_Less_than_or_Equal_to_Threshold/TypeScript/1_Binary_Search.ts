function maxSideLength(mat: number[][], threshold: number): number {
    const m = mat.length,
        n = mat[0].length;
    const P: number[][] = Array.from({ length: m + 1 }, () =>
        new Array(n + 1).fill(0),
    );

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            P[i][j] =
                P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    let l = 1,
        r = Math.min(m, n),
        ans = 0;
    while (l <= r) {
        const mid = Math.floor((l + r) / 2);
        let find = false;
        for (let i = 1; i <= m - mid + 1; i++) {
            for (let j = 1; j <= n - mid + 1; j++) {
                const sum =
                    P[i + mid - 1][j + mid - 1] -
                    P[i - 1][j + mid - 1] -
                    P[i + mid - 1][j - 1] +
                    P[i - 1][j - 1];
                if (sum <= threshold) {
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        if (find) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
