function minCut(s: string): number {
    let cutsDp: number[] = new Array(s.length).fill(0);
    for (let i = 1; i < s.length; i++) {
        cutsDp[i] = i;
    }
    for (let mid = 0; mid < s.length; mid++) {
        findMinimumCuts(mid, mid, cutsDp, s);
        findMinimumCuts(mid - 1, mid, cutsDp, s);
    }
    return cutsDp[s.length - 1];
}
function findMinimumCuts(
    startIndex: number,
    endIndex: number,
    cutsDp: number[],
    s: string,
): void {
    for (
        let start = startIndex, end = endIndex;
        start >= 0 && end < s.length && s.charAt(start) == s.charAt(end);
        start--, end++
    ) {
        let newCut: number = start == 0 ? 0 : cutsDp[start - 1] + 1;
        cutsDp[end] = Math.min(cutsDp[end], newCut);
    }
}
