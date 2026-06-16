var partition = function (s) {
    const res = [];
    dfs(s, [], res);
    return res;
    function dfs(s, path, res) {
        if (!s.length) {
            res.push(path);
            return;
        }
        for (let i = 0; i < s.length; i++) {
            const cur = s.substr(0, i + 1);
            if (isPalindrome(cur)) {
                // add current substring in the currentList
                dfs(s.substr(i + 1), path.concat(cur), res);
                // backtrack and remove the current substring from currentList
            }
        }
    }
    function isPalindrome(s) {
        let lo = 0,
            hi = s.length - 1;
        while (lo < hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
};
