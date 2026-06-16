var groupAnagrams = function (strs) {
    if (strs.length == 0) return [];
    let ans = {};
    for (let s of strs) {
        let count = Array(26).fill(0);
        for (let c of s) count[c.charCodeAt(0) - "a".charCodeAt(0)]++;
        let key = "";
        for (let i = 0; i < 26; i++) {
            key += "#";
            key += count[i];
        }
        if (!ans[key]) ans[key] = [];
        ans[key].push(s);
    }
    return Object.values(ans);
};
