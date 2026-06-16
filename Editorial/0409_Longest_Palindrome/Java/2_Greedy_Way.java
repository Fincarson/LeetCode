class Solution {

    public int longestPalindrome(String s) {
        int oddFreqCharsCount = 0;
        Map<Character, Integer> frequencyMap = new HashMap<>();

        // Loop over the string
        for (char c : s.toCharArray()) {
            // Update count of current character
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);

            // If the current freq of the character is odd,
            // increment oddCount
            if ((frequencyMap.get(c) % 2) == 1) {
                oddFreqCharsCount++;
            } else {
                oddFreqCharsCount--;
            }
        }

        // If there are characters with odd frequencies, we are
        // guaranteed to have at least one letter left unmatched,
        // which can make the center of an odd length palindrome.
        if (oddFreqCharsCount > 0) {
            return s.length() - oddFreqCharsCount + 1;
        } else {
            return s.length();
        }
    }
}
