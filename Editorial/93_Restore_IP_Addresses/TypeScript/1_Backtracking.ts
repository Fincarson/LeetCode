function restoreIpAddresses(s: string): string[] {
    let ans: string[] = [];
    function valid(s: string, start: number, length: number): boolean {
        return (
            length == 1 ||
            (s.charAt(start) != "0" &&
                (length < 3 || s.substring(start, start + length) <= "255"))
        );
    }
    function helper(
        s: string,
        startIndex: number,
        dots: number[],
        ans: string[],
    ): void {
        const remainingLength = s.length - startIndex;
        const remainingNumberOfIntegers = 4 - dots.length;
        if (
            remainingLength > remainingNumberOfIntegers * 3 ||
            remainingLength < remainingNumberOfIntegers
        ) {
            return;
        }
        if (dots.length == 3) {
            if (valid(s, startIndex, remainingLength)) {
                let temp = "";
                let last = 0;
                for (let dot of dots) {
                    temp += s.substring(last, last + dot) + ".";
                    last += dot;
                }
                temp += s.substring(startIndex);
                ans.push(temp);
            }
            return;
        }
        for (
            let curPos = 1;
            curPos <= 3 && curPos <= remainingLength;
            ++curPos
        ) {
            dots.push(curPos);
            if (valid(s, startIndex, curPos)) {
                helper(s, startIndex + curPos, dots, ans);
            }
            dots.pop();
        }
    }
    helper(s, 0, [], ans);
    return ans;
}
