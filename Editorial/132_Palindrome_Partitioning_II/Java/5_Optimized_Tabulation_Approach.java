class Solution {
    public int minCut(String s) {
        Integer cutsDp[];
        boolean palindromeDp[][];
        cutsDp = new Integer[s.length()];
        palindromeDp = new boolean[s.length()][s.length()];
        for (int end = 0; end < s.length(); end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                // check if substring (start, end) is palidrome
                if (
                    s.charAt(start) == s.charAt(end) &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])
                ) {
                    palindromeDp[start][end] = true;
                    minimumCut = start == 0
                        ? 0
                        : Math.min(minimumCut, cutsDp[start - 1] + 1);
                }
            }
            cutsDp[end] = minimumCut;
        }
        return cutsDp[s.length() - 1];
    }
}
