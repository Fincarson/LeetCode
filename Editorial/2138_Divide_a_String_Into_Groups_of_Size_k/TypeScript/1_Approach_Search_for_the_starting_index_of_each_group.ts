function divideString(s: string, k: number, fill: string): string[] {
    const res: string[] = []; // grouped string
    const n = s.length;
    let curr = 0; // starting index of each group
    // split string
    while (curr < n) {
        const end = Math.min(curr + k, n);
        res.push(s.slice(curr, end));
        curr += k;
    }
    // try to fill in the last group
    const last = res[res.length - 1];
    if (last.length < k) {
        res[res.length - 1] = last + fill.repeat(k - last.length);
    }
    return res;
}
