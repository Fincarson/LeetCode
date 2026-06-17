class Solution {

    public long numberOfSubstrings(String s) {
        int n = s.length();
        // Number of substrings can exceed the integer range
        long answer = 0;
        long[] prefixCount = new long[26];

        for (int i = 0; i < s.length(); i++) {
            // Increment the number of times we encountered the current letter
            // so far.
            prefixCount[s.charAt(i) - 'a']++;

            // Current letter can be paired with all the occurrences of it that
            // comes before, including itself, to form a valid substring.
            answer += prefixCount[s.charAt(i) - 'a'];
        }

        return answer;
    }
}
