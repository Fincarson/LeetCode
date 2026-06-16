function minCut(s: string): number {
    return findMinimumCut(s, 0, s.length - 1, s.length - 1);
}
function findMinimumCut(
    s: string,
    start: number,
    end: number,
    minimumCut: number,
): number {
    // base condition, no cut needed for an empty substring or palindrome substring
    if (start === end || isPalindrome(s, start, end)) {
        return 0;
    }
    for (
        let currentEndIndex = start;
        currentEndIndex <= end;
        currentEndIndex++
    ) {
        // find result for substring (start, currentEndIndex) is it is palindrome
        if (isPalindrome(s, start, currentEndIndex)) {
            minimumCut = Math.min(
                minimumCut,
                1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut),
            );
        }
    }
    return minimumCut;
}
function isPalindrome(s: string, start: number, end: number): boolean {
    while (start < end) {
        if (s[start++] !== s[end--]) {
            return false;
        }
    }
    return true;
}
