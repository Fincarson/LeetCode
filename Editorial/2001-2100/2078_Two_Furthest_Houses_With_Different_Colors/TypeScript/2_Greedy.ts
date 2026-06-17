function maxDistance(colors: number[]): number {
    const n = colors.length;
    let ans = 0;
    for (let i = 0; i < n - 1; i++) {
        if (colors[i] !== colors[n - 1]) {
            ans = Math.max(ans, i, n - 1 - i);
        }
    }
    return ans;
}
