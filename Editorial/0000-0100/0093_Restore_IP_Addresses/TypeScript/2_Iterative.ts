function valid(s: string, start: number, length: number) {
    return (
        length === 1 ||
        (s[start] !== "0" && (length < 3 || s.substr(start, length) <= "255"))
    );
}
function restoreIpAddresses(s: string) {
    let ans = [];
    let length = s.length;
    for (
        let len1 = Math.max(1, length - 9);
        len1 <= 3 && len1 <= length - 3;
        ++len1
    ) {
        if (!valid(s, 0, len1)) {
            continue;
        }
        for (
            let len2 = Math.max(1, length - len1 - 6);
            len2 <= 3 && len2 <= length - len1 - 2;
            ++len2
        ) {
            if (!valid(s, len1, len2)) {
                continue;
            }
            for (
                let len3 = Math.max(1, length - len1 - len2 - 3);
                len3 <= 3 && len3 <= length - len1 - len2 - 1;
                ++len3
            ) {
                if (
                    valid(s, len1 + len2, len3) &&
                    valid(s, len1 + len2 + len3, length - len1 - len2 - len3)
                ) {
                    ans.push(
                        s.substr(0, len1) +
                            "." +
                            s.substr(len1, len2) +
                            "." +
                            s.substr(len1 + len2, len3) +
                            "." +
                            s.substr(len1 + len2 + len3),
                    );
                }
            }
        }
    }
    return ans;
}
