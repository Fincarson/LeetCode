def canConstruct(self, ransomNote: str, magazine: str) -> bool:
    
    # Check for obvious fail case.
    if len(ransomNote) > len(magazine): return False
    
    # Reverse sort the note and magazine. In Python, we simply 
    # treat a list as a stack.
    ransomNote = sorted(ransomNote, reverse=True) 
    magazine = sorted(magazine, reverse=True)
    
    # While there are letters left on both stacks:
    while ransomNote and magazine:
        # If the tops are the same, pop both because we have found a match.
        if ransomNote[-1] == magazine[-1]:
            ransomNote.pop()
            magazine.pop()
        # If magazine's top is earlier in the alphabet, we should remove that 
        # character of magazine as we definitely won't need that letter.
        elif magazine[-1] < ransomNote[-1]:
            magazine.pop()
        # Otherwise, it's impossible for top of ransomNote to be in magazine.
        else:
            return False   
    # Return true iff the entire ransomNote was built.
    return not ransomNote
