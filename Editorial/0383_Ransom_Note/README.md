# 383. Ransom Note

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/ransom-note/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 383 - Ransom Note](https://leetcode.com/problems/ransom-note/)

## Problem

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

### Example 1

```text
Input: ransomNote = "a", magazine = "b"
Output: false
```

### Example 2

```text
Input: ransomNote = "aa", magazine = "ab"
Output: false
```

### Example 3

```text
Input: ransomNote = "aa", magazine = "aab"
Output: true
```

## Constraints

- 1 <= ransomNote.length, magazine.length <= 105
- ransomNote and magazine consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find Words That Can Be Formed by Characters](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 383. Ransom Note

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | Java, Python |
| Two HashMaps | Java, Python |
| One HashMap | Java, Python |
| Sorting and Stacks | Java, Python |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
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
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def canConstruct(self, ransomNote: str, magazine: str) -> bool:
    # For each character, c,  in the ransom note.
    for c in ransomNote:
        # If there are none of c left in the String, return False.
        if c not in magazine:
            return False
        # Find the index of the first occurrence of c in the magazine.
        location = magazine.index(c)
        # Use splicing to make a new string with the characters 
        # before "location" (but not including), and the characters 
        #after "location". 
        magazine = magazine[:location] + magazine[location + 1:]
    # If we got this far, we can successfully build the note.
    return True
```

</details>

<br>

## Approach 2: Two HashMaps

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    // Takes a String, and returns a HashMap with counts of
    // each character.
    private Map<Character, Integer> makeCountsMap(String s) {
        Map<Character, Integer> counts = new HashMap<>();
        for (char c : s.toCharArray()) {
            int currentCount = counts.getOrDefault(c, 0);
            counts.put(c, currentCount + 1);
        }
        return counts;
    }
    
    
    public boolean canConstruct(String ransomNote, String magazine) {
        
        // Check for obvious fail case.
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        // Make the count maps.
        Map<Character, Integer> ransomNoteCounts = makeCountsMap(ransomNote);
        Map<Character, Integer> magazineCounts = makeCountsMap(magazine);
        
        // For each unique character, c, in the ransom note:
        for (char c : ransomNoteCounts.keySet()) {
            // Check that the count of char in the magazine is equal
            // or higher than the count in the ransom note.
            int countInMagazine = magazineCounts.getOrDefault(c, 0);
            int countInRansomNote = ransomNoteCounts.get(c);
            if (countInMagazine < countInRansomNote) {
                return false;
            }
        }
        
        // If we got this far, we can successfully build the note.
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def canConstruct(self, ransomNote: str, magazine: str) -> bool:

    # Check for obvious fail case.
    if len(ransomNote) > len(magazine): return False

    # In Python, we can use the Counter class. It does all the work that the
    # makeCountsMap(...) function in our pseudocode did!
    magazine_counts = collections.Counter(magazine)
    ransom_note_counts = collections.Counter(ransomNote)
    
    # For each *unique* character in the ransom note:
    for char, count in ransom_note_counts.items():
        # Check that the count of char in the magazine is equal
        # or higher than the count in the ransom note.
        magazine_count = magazine_counts[char]
        if magazine_count < count:
            return False
            
    # If we got this far, we can successfully build the note.
    return True
```

</details>

<br>

## Approach 3: One HashMap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    // Takes a String, and returns a HashMap with counts of
    // each character.
    private Map<Character, Integer> makeCountsMap(String s) {
        Map<Character, Integer> counts = new HashMap<>();
        for (char c : s.toCharArray()) {
            int currentCount = counts.getOrDefault(c, 0);
            counts.put(c, currentCount + 1);
        }
        return counts;
    }
    
    
    public boolean canConstruct(String ransomNote, String magazine) {
        
        // Check for obvious fail case.
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        // Make a counts map for the magazine.
        Map<Character, Integer> magazineCounts = makeCountsMap(magazine);
        
        // For each character in the ransom note:
        for (char c : ransomNote.toCharArray()) {
            // Get the current count for c in the magazine.
            int countInMagazine = magazineCounts.getOrDefault(c, 0);
            // If there are none of c left, return false.
            if (countInMagazine == 0) {
                return false;
            }
            // Put the updated count for c back into magazineCounts.
            magazineCounts.put(c, countInMagazine - 1);
        }
        
        // If we got this far, we can successfully build the note.
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def canConstruct(self, ransomNote: str, magazine: str) -> bool:
    
    # Check for obvious fail case.
    if len(ransomNote) > len(magazine): return False

    # In Python, we can use the Counter class. It does all the work that the
    # makeCountsMap(...) function in our pseudocode did!
    letters = collections.Counter(magazine)
    
    # For each character, c, in the ransom note:
    for c in ransomNote:
        # If there are none of c left, return False.
        if letters[c] <= 0:
            return False
        # Remove one of c from the Counter.
        letters[c] -= 1
    # If we got this far, we can successfully build the note.
    return True
```

</details>

<br>

## Approach 4: Sorting and Stacks

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
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
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
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
```

</details>
