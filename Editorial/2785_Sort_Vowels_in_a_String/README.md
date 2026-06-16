# 2785. Sort Vowels in a String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/sort-vowels-in-a-string/)  
`String` `Sorting`

**Problem Link:** [LeetCode 2785 - Sort Vowels in a String](https://leetcode.com/problems/sort-vowels-in-a-string/)

## Problem

Given a 0-indexed string s, permute s to get a new string t such that:

- All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
- The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].

Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

### Example 1

```text
Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
```

### Example 2

```text
Input: s = "lYmpH"
Output: "lYmpH"
Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".
```

## Constraints

- 1 <= s.length <= 105
- s consists only of letters of the English alphabet in uppercase and lowercase.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2785. Sort Vowels in a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java |
| Counting Sort | C++, Java |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Returns true if the character is a vowel.
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }

    string sortVowels(string s) {
        string temp;

        // Store the vowels in the temporary string.
        for (char c : s) {
            if (isVowel(c)) {
                temp += c;
            }
        }
        
        // Sort the temporary string characters in ascending order.
        sort(temp.begin(), temp.end());

        int j = 0;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            // If the character is a vowel, replace it with the character in the string temp.
            if (isVowel(s[i])) {
                ans += temp[j];
                j++;
            } else {
                ans += s[i];
            }
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns true if the character is a vowel.
    boolean isVowel(Character c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    
    public String sortVowels(String s) {
         ArrayList<Character> temp = new ArrayList<>();

        // Store the vowels in the temporary string.
        for (char c : s.toCharArray()) {
            if (isVowel(c)) {
                temp.add(c);
            }
        }
        
        // Sort the temporary string characters in ascending order.
        Collections.sort(temp);

        StringBuilder ans = new StringBuilder();
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            // If the character is a vowel, replace it with the character in the string temp.
            if (isVowel(s.charAt(i))) {
                ans.append(temp.get(j));
                j++;
            } else {
                ans.append(s.charAt(i));
            }
        }
        
        return ans.toString();
    }
};
```

</details>

<br>

## Approach 2: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Returns true if the character is a vowel.
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    
    string sortVowels(string s) {
        unordered_map<char, int> count;

        // Store the frequencies for each character.
        for (char c : s) {
            if (isVowel(c)) {
                count[c]++;
            }
        }

        // Sorted string having all the vowels.
        string sortedVowel = "AEIOUaeiou";
        string ans;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!isVowel(s[i])) {
                ans += s[i];
            } else {
                // Skip to the character which is having remaining count.
                while (count[sortedVowel[j]] == 0) {
                    j++;
                }

                ans += sortedVowel[j];
                count[sortedVowel[j]]--;
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Returns true if the character is a vowel.
    boolean isVowel(Character c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i'
                || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }

    public String sortVowels(String s) {
        int[] count = new int[1000];

        // Store the frequencies for each character.
        for (char c : s.toCharArray()) {
            if (isVowel(c)) {
                count[c - 'A']++;
            }
        }

        // Sorted string having all the vowels.
        String sortedVowel = "AEIOUaeiou";
        StringBuilder ans = new StringBuilder();
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!isVowel(s.charAt(i))) {
                ans.append(s.charAt(i));
            } else {
                // Skip to the character which is having remaining count.
                while (count[sortedVowel.charAt(j) - 'A'] == 0) {
                    j++;
                }

                ans.append(sortedVowel.charAt(j));
                count[sortedVowel.charAt(j) - 'A']--;
            }
        }
        return ans.toString();
    }
};
```

</details>
