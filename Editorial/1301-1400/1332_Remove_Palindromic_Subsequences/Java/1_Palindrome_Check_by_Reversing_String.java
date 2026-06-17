class Solution {
    public int removePalindromeSub(String s) {
        if (s.isEmpty()) {
            return 0;
        }
        // See below for code that compacts this into one line.
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        String reversedString = sb.toString();
        if (reversedString.equals(s)) {
            return 1;
        }
        return 2;
    }
}
