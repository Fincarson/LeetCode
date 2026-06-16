class Solution {
    public int countLetters(String S) {
        int substrings[] = new int[S.length()];
        int total = 1;
        substrings[0] = 1;
        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i) == S.charAt(i - 1)) {
                substrings[i] = substrings[i - 1] + 1;
            } else {
                substrings[i] = 1;
            }
            total += substrings[i];
        }
        return total;
    }
}
