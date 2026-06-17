class Solution {

    private void storeAbbreviations(
        List<String> abbreviations,
        String word,
        StringBuilder currWord,
        int index,
        int abbreviatedCount
    ) {
        if (index == word.length()) {
            // If the length of the last abbreviated substring is 0, add an empty string.
            if (abbreviatedCount > 0) {
                currWord.append(abbreviatedCount);
            }
            abbreviations.add(currWord.toString());
            return;
        }
        int currWordLength = currWord.length();
        // Option 1: Keep the current character.
        if (abbreviatedCount > 0) {
            currWord.append(abbreviatedCount);
        }
        currWord.append(word.charAt(index));
        storeAbbreviations(abbreviations, word, currWord, index + 1, 0);
        currWord.setLength(currWordLength); // Backtrack
        // Option 2: Abbreviate the current character.
        storeAbbreviations(
            abbreviations,
            word,
            currWord,
            index + 1,
            abbreviatedCount + 1
        );
    }

    public List<String> generateAbbreviations(String word) {
        List<String> abbreviations = new ArrayList<>();
        storeAbbreviations(abbreviations, word, new StringBuilder(), 0, 0);
        return abbreviations;
    }
}
