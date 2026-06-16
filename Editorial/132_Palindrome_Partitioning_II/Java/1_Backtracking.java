class Solution {
    public int minCut(String s) {
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    private int findMinimumCut(String s, int start, int end, int minimumCut) {
        // base condition, no cut needed for an empty substring or palindrome substring.
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }

        for (
            int currentEndIndex = start;
            currentEndIndex <= end;
            currentEndIndex++
        ) {
            // find result for substring (start, currentEndIndex) if it is palindrome
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut = Math.min(
                    minimumCut,
                    1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut)
                );
            }
        }
        return minimumCut;
    }

    private boolean isPalindrome(String s, int start, int end) {
        while (start < end) {
            if (s.charAt(start++) != s.charAt(end--)) {
                return false;
            }
        }
        return true;
    }
}
