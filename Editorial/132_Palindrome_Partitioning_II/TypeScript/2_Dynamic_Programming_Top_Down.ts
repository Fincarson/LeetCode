function minCut(s: string): number {
    const n = s.length;
    const memoCuts: number[][] = Array.from({ length: n }, () =>
        Array(n).fill(-1),
    );
    const memoPalindrome: (boolean | null)[][] = Array.from({ length: n }, () =>
        Array(n).fill(null),
    );

    // Function to check if the substring is a palindrome
    const isPalindrome = (start: number, end: number): boolean => {
        if (start >= end) return true;
        if (memoPalindrome[start][end] !== null)
            return memoPalindrome[start][end];
        memoPalindrome[start][end] =
            s[start] === s[end] && isPalindrome(start + 1, end - 1);
        return memoPalindrome[start][end];
    };

    // Function to find the minimum cut for palindrome partitioning
    const findMinimumCut = (
        start: number,
        end: number,
        minimumCut: number,
    ): number => {
        // base case
        if (start === end || isPalindrome(start, end)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start][end] !== -1) {
            return memoCuts[start][end];
        }

        for (
            let currentEndIndex = start;
            currentEndIndex <= end;
            currentEndIndex++
        ) {
            if (isPalindrome(start, currentEndIndex)) {
                minimumCut = Math.min(
                    minimumCut,
                    1 + findMinimumCut(currentEndIndex + 1, end, minimumCut),
                );
            }
        }
        memoCuts[start][end] = minimumCut;
        return minimumCut;
    };

    return findMinimumCut(0, n - 1, n - 1);
}
