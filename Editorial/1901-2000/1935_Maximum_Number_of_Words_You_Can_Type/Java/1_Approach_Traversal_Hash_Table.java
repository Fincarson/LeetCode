class Solution {

    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> broken = new HashSet<>(); // set of broken letter keys
        for (char ch : brokenLetters.toCharArray()) {
            broken.add(ch);
        }
        int res = 0; // the number of words that can be fully inputted
        boolean flag = true; // is the current character in the word completely inputtable
        for (char ch : text.toCharArray()) {
            if (ch == ' ') {
                // the current character is a space, check the status of the previous word, update the count and initialize the flag
                if (flag) {
                    ++res;
                }
                flag = true;
            } else if (broken.contains(ch)) {
                // the current character cannot be entered, the word it is in cannot be fully entered, update flag
                flag = false;
            }
        }
        // judge the status of the last word and update the count
        if (flag) {
            ++res;
        }
        return res;
    }
}
