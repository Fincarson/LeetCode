class Solution {
    
    // Please, if there's a nicer way of doing this, without getting tangled in
    // primitives vs Java's generics let me know in the article comments :-)
    private Stack<Character> sortedCharacterStack(String s) {
        char[] charArray = s.toCharArray();
        Arrays.sort(charArray);
        Stack<Character> stack = new Stack<>();
        for (int i = s.length() - 1; i >= 0; i--) {
            stack.push(charArray[i]);
        }
        return stack;
    }
    
    
    public boolean canConstruct(String ransomNote, String magazine) {
        
        // Check for obvious fail case.
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        
        // Reverse sort the characters of the note and magazine, and then
        // put them into stacks.
        Stack<Character> magazineStack = sortedCharacterStack(magazine);
        Stack<Character> ransomNoteStack = sortedCharacterStack(ransomNote);
        
        // And now process the stacks, while both have letters remaining.
        while (!magazineStack.isEmpty() && !ransomNoteStack.isEmpty()) {
            // If the tops are the same, pop both because we have found a match.
            if (magazineStack.peek().equals(ransomNoteStack.peek())) {
                ransomNoteStack.pop();
                magazineStack.pop();
            } 
            // If magazine's top is earlier in the alphabet, we should remove that 
            // character of magazine as we definitely won't need that letter.
            else if (magazineStack.peek() < ransomNoteStack.peek()) {
                magazineStack.pop();
            }
            // Otherwise, it's impossible for top of ransomNote to be in magazine.
            else {
                return false;
            }
        }
                
        // Return true iff the entire ransomNote was built.
        return ransomNoteStack.isEmpty();
        
    }
}
