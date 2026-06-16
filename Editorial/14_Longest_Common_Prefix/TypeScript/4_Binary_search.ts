function longestCommonPrefix(strs: string[]): string {
    if (strs === null || strs.length === 0) return "";
    let minLen = Number.MAX_SAFE_INTEGER;
    for (let str of strs) minLen = Math.min(minLen, str.length);
    let low = 1;
    let high = minLen;
    while (low <= high) {
        let middle = Math.floor((low + high) / 2);
        if (isCommonPrefix(strs, middle)) low = middle + 1;
        else high = middle - 1;
    }
    return strs[0].substring(0, Math.floor((low + high) / 2));

    function isCommonPrefix(strs: string[], len: number) {
        let str1 = strs[0].substring(0, len);
        for (let i = 1; i < strs.length; i++)
            if (!strs[i].startsWith(str1)) return false;
        return true;
    }
}
