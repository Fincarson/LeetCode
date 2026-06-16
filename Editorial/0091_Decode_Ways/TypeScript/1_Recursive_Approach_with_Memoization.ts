function recursiveWithMemo(
    index: number,
    str: string,
    memo: Map<number, number>,
): number {
    if (memo.has(index)) {
        return memo.get(index);
    }
    if (index == str.length) {
        return 1;
    }
    if (str.charAt(index) == "0") {
        return 0;
    }
    if (index == str.length - 1) {
        return 1;
    }
    let ans = recursiveWithMemo(index + 1, str, memo);
    if (parseInt(str.substring(index, index + 2)) <= 26) {
        ans += recursiveWithMemo(index + 2, str, memo);
    }
    memo.set(index, ans);
    return ans;
}
function numDecodings(s: string): number {
    let memo = new Map();
    return recursiveWithMemo(0, s, memo);
}
