class Solution {
    String source, target;
    Integer leftBound, rightBound;

    private boolean rec_isSubsequence(int leftIndex, int rightIndex) {
        // base cases
        if (leftIndex == leftBound)
            return true;
        if (rightIndex == rightBound)
            return false;

        // consume both strings or just the target string
        if (source.charAt(leftIndex) == target.charAt(rightIndex))
            ++leftIndex;
        ++rightIndex;

        return rec_isSubsequence(leftIndex, rightIndex);
    }

    public boolean isSubsequence(String s, String t) {
        this.source = s;
        this.target = t;
        this.leftBound = s.length();
        this.rightBound = t.length();

        return rec_isSubsequence(0, 0);
    }
}
