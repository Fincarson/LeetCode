public boolean canConstruct(String ransomNote, String magazine) {
    // For each character, c,  in the ransom note.
    for (char c : ransomNote.toCharArray()) {
        // Find the index of the first occurrence of c in the magazine.
        int index = magazine.indexOf(c);
        // If there are none of c left in the String, return False.
        if (index == -1) {
            return false;
        }
        // Use substring to make a new string with the characters 
        // before "index" (but not including), and the characters 
        // after "index". 
        magazine = magazine.substring(0, index) + magazine.substring(index + 1);
    }
    // If we got this far, we can successfully build the note.
    return true;
}
