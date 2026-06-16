class Solution {
    public char findTheDifference(String s, String t) {

        // Sort both the strings
        char[] sortedS = s.toCharArray();
        char[] sortedT = t.toCharArray();
        Arrays.sort(sortedS);
        Arrays.sort(sortedT);

        // Character by character comparison
        int i = 0;
        while (i < s.length()) {
            if (sortedS[i] != sortedT[i]) {
                return sortedT[i];
            }
            i += 1;
        }

        return sortedT[i];
    }
}
