var longestPalindrome = function (s) {
    function expand(i, j) {
        let left = i;
        let right = j;

        while (left >= 0 && right < s.length && s[left] === s[right]) {
            left--;
            right++;
        }

        return s.slice(left + 1, right);
    }

    let ans = "";

    for (let i = 0; i < s.length; i++) {
        let odd = expand(i, i);
        if (odd.length > ans.length) {
            ans = odd;
        }

        let even = expand(i, i + 1);
        if (even.length > ans.length) {
            ans = even;
        }
    }

    return ans;
};
