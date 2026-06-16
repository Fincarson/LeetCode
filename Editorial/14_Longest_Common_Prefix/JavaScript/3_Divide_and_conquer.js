var longestCommonPrefix = function (strs) {
    if (!strs || strs.length < 1) return "";

    let LCP = (str1, str2) => {
        let minLen = Math.min(str1.length, str2.length);
        for (let i = 0; i < minLen; i++) {
            if (str1[i] !== str2[i]) {
                return str1.slice(0, i);
            }
        }
        return str1.slice(0, minLen);
    };

    let divideAndConquer = (strs, l, r) => {
        if (l == r) {
            return strs[l];
        } else {
            let mid = Math.floor((l + r) / 2);
            let lcpLeft = divideAndConquer(strs, l, mid);
            let lcpRight = divideAndConquer(strs, mid + 1, r);
            return LCP(lcpLeft, lcpRight);
        }
    };

    return divideAndConquer(strs, 0, strs.length - 1);
};
