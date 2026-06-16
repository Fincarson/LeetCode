class Solution {

    public int isPrefixOfWord(String sentence, String searchWord) {
        // Split the sentence into words
        String[] words = sentence.split(" ");
        // Iterate over the words with their positions
        for (int i = 0; i < words.length; i++) {
            // Check if the current word is long enough to contain the searchWord as a prefix
            // and if the prefix matches the searchWord
            if (
                words[i].length() >= searchWord.length() &&
                words[i].substring(0, searchWord.length()).equals(searchWord)
            ) {
                // If a match is found, return the current word position (adjusted to 1-based index)
                return i + 1;
            }
        }
        // If no match is found, return -1
        return -1;
    }
}
