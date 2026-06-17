class Solution {

    public int maximumLength(String s) {
        int[][] frequency = new int[26][s.length() + 1];
        char previousCharacter = s.charAt(0);
        int substringLength = 1;

        frequency[s.charAt(0) - 'a'][1] = 1;
        int ans = -1;

        for (int charIdx = 1; charIdx < s.length(); charIdx++) {
            char currentCharacter = s.charAt(charIdx);
            // If the current character is equal to the previous character, add it to the
            // mapping and increment the substring length.
            if (currentCharacter == previousCharacter) {
                substringLength++;
                int count = 1;
                frequency[currentCharacter - 'a'][substringLength] += 1;
            } else {
                // Otherwise, reset substring length to 1.
                previousCharacter = currentCharacter;
                substringLength = 1;
                frequency[currentCharacter - 'a'][1] += 1;
            }
        }

        // Calculate the cumulative sum from the end for every character and find the
        // maximum possible answer.
        for (int charIdx = 0; charIdx < 26; charIdx++) {
            for (int len = s.length() - 1; len >= 1; len--) {
                frequency[charIdx][len] += frequency[charIdx][len + 1];
                if (frequency[charIdx][len] >= 3) {
                    ans = Math.max(ans, len);
                    break;
                }
            }
        }

        return ans;
    }
}
