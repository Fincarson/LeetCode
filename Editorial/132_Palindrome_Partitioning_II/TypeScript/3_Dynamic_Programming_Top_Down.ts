const minCut = (s: string): number => {
    let memoCuts: number[] = new Array(s.length).fill(null);
    let memoPalindrome: boolean[][] = new Array(s.length)
        .fill(null)
        .map((_) => new Array(s.length).fill(null));
    const findMinimumCut = (
        s: string,
        start: number,
        end: number,
        minimumCut: number,
    ): number => {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }
        // check for results in memoCuts
        if (memoCuts[start] != null) {
            return memoCuts[start];
        }
        for (
            let currentEndIndex = start;
            currentEndIndex <= end;
            currentEndIndex++
        ) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut = Math.min(
                    minimumCut,
                    1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut),
                );
            }
        }
        return (memoCuts[start] = minimumCut);
    };
    const isPalindrome = (s: string, start: number, end: number): boolean => {
        if (start >= end) {
            return true;
        }
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != null) {
            return memoPalindrome[start][end];
        }
        return (memoPalindrome[start][end] =
            s[start] == s[end] && isPalindrome(s, start + 1, end - 1));
    };
    return findMinimumCut(s, 0, s.length - 1, s.length - 1);
};
