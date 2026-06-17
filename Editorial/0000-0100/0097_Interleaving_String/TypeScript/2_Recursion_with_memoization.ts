function isInterleave(s1: string, s2: string, s3: string): boolean {
    if (s1.length + s2.length !== s3.length) {
        return false;
    }
    let memo: number[][] = Array(s1.length)
        .fill(0)
        .map((x) => Array(s2.length).fill(-1));
    return is_Interleave(s1, 0, s2, 0, s3, 0, memo);
}
function is_Interleave(
    s1: string,
    i: number,
    s2: string,
    j: number,
    s3: string,
    k: number,
    memo: number[][],
): boolean {
    if (i === s1.length) {
        return s2.substring(j) === s3.substring(k);
    }
    if (j === s2.length) {
        return s1.substring(i) === s3.substring(k);
    }
    if (memo[i][j] >= 0) {
        return memo[i][j] === 1;
    }
    let ans = false;
    if (
        (s3.charAt(k) === s1.charAt(i) &&
            is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)) ||
        (s3.charAt(k) === s2.charAt(j) &&
            is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo))
    ) {
        ans = true;
    }
    memo[i][j] = ans ? 1 : 0;
    return ans;
}
