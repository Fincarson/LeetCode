function possibleStringCount(word: string, k: number): number {
    const mod: number = 1000000007;
    const n = word.length;
    let cnt = 1;
    const freq: number[] = [];

    for (let i = 1; i < n; ++i) {
        if (word[i] === word[i - 1]) {
            ++cnt;
        } else {
            freq.push(cnt);
            cnt = 1;
        }
    }
    freq.push(cnt);

    let ans = 1;
    for (const o of freq) {
        ans = (ans * o) % mod;
    }

    if (freq.length >= k) {
        return ans;
    }

    let f: number[] = new Array(k).fill(0);
    let g: number[] = new Array(k).fill(1);

    for (let i = 0; i < freq.length; ++i) {
        const f_new: number[] = new Array(k).fill(0);
        for (let j = 1; j < k; ++j) {
            f_new[j] = g[j - 1];
            if (j - freq[i] - 1 >= 0) {
                f_new[j] = (f_new[j] - g[j - freq[i] - 1] + mod) % mod;
            }
        }
        const g_new: number[] = new Array(k).fill(0);
        g_new[0] = f_new[0];
        for (let j = 1; j < k; ++j) {
            g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
        }
        f = f_new;
        g = g_new;
    }

    return (ans - g[k - 1] + mod) % mod;
}
