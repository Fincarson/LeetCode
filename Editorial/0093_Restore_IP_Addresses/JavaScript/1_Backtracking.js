var restoreIpAddresses = function (s) {
    var ans = [];
    function valid(s, start, length) {
        return (
            length == 1 ||
            (s.charAt(start) != "0" &&
                (length < 3 || s.substring(start, start + length) <= 255))
        );
    }
    function helper(s, startIndex, dots, ans) {
        var remainingLength = s.length - startIndex;
        var remainingNumberOfIntegers = 4 - dots.length;
        if (
            remainingLength > remainingNumberOfIntegers * 3 ||
            remainingLength < remainingNumberOfIntegers
        ) {
            return;
        }
        if (dots.length == 3) {
            if (valid(s, startIndex, remainingLength)) {
                var temp = "";
                var last = 0;
                for (var dot of dots) {
                    temp += s.substring(last, last + dot) + ".";
                    last += dot;
                }
                temp += s.substring(startIndex);
                ans.push(temp);
            }
            return;
        }
        for (
            var curPos = 1;
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
};
