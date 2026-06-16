class Solution {

    public long numberOfSubstrings(String s) {
        long answer = 0;
        long[] frequencyCount = new long[26];

        // Count the frequency of each character in the string.
        for (char ch : s.toCharArray()) {
            frequencyCount[ch - 'a']++;
        }

        // Calculate the total number of valid substrings.
        for (long currentCount : frequencyCount) {
            // Using (currentCount + 1) choose 2 to calculate valid substrings
            // for the current letter.
            answer += ((currentCount + 1) * currentCount) / 2;
        }

        return answer;
    }
}
