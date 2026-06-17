class Solution {

    // Method to return the minimum of three values
    public int min(int a, int b, int c) {
        return a < Math.min(b, c) ? a : Math.min(b, c);
    }

    public int maximumLength(String s) {
        int substringLength = 0, ans = -1;
        char previousCharacter = '\0';
        int[][] substringLengths = new int[26][3];

        // Initialize the substringLengths array to -1
        for (int charIdx = 0; charIdx < 26; charIdx++) {
            for (int lenIdx = 0; lenIdx < 3; lenIdx++) {
                substringLengths[charIdx][lenIdx] = -1;
            }
        }

        for (char character : s.toCharArray()) {
            if (character == previousCharacter) {
                substringLength++;
            } else {
                substringLength = 1;
                previousCharacter = character;
            }

            // Replace the minimum frequency with the current length if it is greater
            int index = character - 'a';
            int minLength = min(
                substringLengths[index][0],
                substringLengths[index][1],
                substringLengths[index][2]
            );
            if (substringLength > minLength) {
                if (substringLengths[index][0] == minLength) {
                    substringLengths[index][0] = substringLength;
                } else if (substringLengths[index][1] == minLength) {
                    substringLengths[index][1] = substringLength;
                } else {
                    substringLengths[index][2] = substringLength;
                }
            }
        }

        // Find the character with the maximum value of its minimum frequency
        for (int charIdx = 0; charIdx < 26; charIdx++) {
            ans = Math.max(
                ans,
                min(
                    substringLengths[charIdx][0],
                    substringLengths[charIdx][1],
                    substringLengths[charIdx][2]
                )
            );
        }

        return ans;
    }
}
