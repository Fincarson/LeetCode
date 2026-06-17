# 288. Unique Word Abbreviation

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/unique-word-abbreviation/)  
`Array` `Hash Table` `String` `Design`

**Problem Link:** [LeetCode 288 - Unique Word Abbreviation](https://leetcode.com/problems/unique-word-abbreviation/)

## Problem

The abbreviation of a word is a concatenation of its first letter, the number of characters between the first and last letter, and its last letter. If a word has only two characters, then it is an abbreviation of itself.

For example:

- dog --> d1g because there is one letter between the first letter 'd' and the last letter 'g'.
- internationalization --> i18n because there are 18 letters between the first letter 'i' and the last letter 'n'.
- it --> it because any word with only two characters is an abbreviation of itself.

Implement the ValidWordAbbr class:

- ValidWordAbbr(String[] dictionary) Initializes the object with a dictionary of words.
- boolean isUnique(string word) Returns true if either of the following conditions are met (otherwise returns false):

		There is no word in dictionary whose abbreviation is equal to word's abbreviation.
		For any word in dictionary whose abbreviation is equal to word's abbreviation, that word and word are the same.

### Example 1

```text
Input
["ValidWordAbbr", "isUnique", "isUnique", "isUnique", "isUnique", "isUnique"]
[[["deer", "door", "cake", "card"]], ["dear"], ["cart"], ["cane"], ["make"], ["cake"]]
Output
[null, false, true, false, true, true]

Explanation
ValidWordAbbr validWordAbbr = new ValidWordAbbr(["deer", "door", "cake", "card"]);
validWordAbbr.isUnique("dear"); // return false, dictionary word "deer" and word "dear" have the same abbreviation "d2r" but are not the same.
validWordAbbr.isUnique("cart"); // return true, no words in the dictionary have the abbreviation "c2t".
validWordAbbr.isUnique("cane"); // return false, dictionary word "cake" and word "cane" have the same abbreviation  "c2e" but are not the same.
validWordAbbr.isUnique("make"); // return true, no words in the dictionary have the abbreviation "m2e".
validWordAbbr.isUnique("cake"); // return true, because "cake" is already in the dictionary and no other word in the dictionary has "c2e" abbreviation.
```

## Constraints

- 1 <= dictionary.length <= 3 * 104
- 1 <= dictionary[i].length <= 20
- dictionary[i] consists of lowercase English letters.
- 1 <= word.length <= 20
- word consists of lowercase English letters.
- At most 5000 calls will be made to isUnique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Generalized Abbreviation](https://leetcode.com/problems/generalized-abbreviation/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 288. Unique Word Abbreviation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Brute Force) | Java |
| Approach #2 (Hash Table) [Accepted] | Java |
| Approach #3 (Hash Table) [Accepted] | Java |

## Approach #1 (Brute Force)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class ValidWordAbbr {
    private final String[] dict;

    public ValidWordAbbr(String[] dictionary) {
        dict = dictionary;
    }

    public boolean isUnique(String word) {
        int n = word.length();
        for (String s : dict) {
            if (word.equals(s)) {
                continue;
            }
            int m = s.length();
            if (m == n
                && s.charAt(0) == word.charAt(0)
                && s.charAt(m - 1) == word.charAt(n - 1)) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<br>

## Approach #2 (Hash Table) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class ValidWordAbbr {
    private final Map<String, Set<String>> abbrDict = new HashMap<>();

    public ValidWordAbbr(String[] dictionary) {
        for (String s : dictionary) {
            String abbr = toAbbr(s);
            Set<String> words = abbrDict.containsKey(abbr)
                ? abbrDict.get(abbr) : new HashSet<>();
            words.add(s);
            abbrDict.put(abbr, words);
        }
    }

    public boolean isUnique(String word) {
        String abbr = toAbbr(word);
        Set<String> words = abbrDict.get(abbr);
        return words == null || (words.size() == 1 && words.contains(word));
    }

    private String toAbbr(String s) {
        int n = s.length();
        if (n <= 2) {
            return s;
        }
        return s.charAt(0) + Integer.toString(n - 2) + s.charAt(n - 1);
    }
}
```

</details>

<br>

## Approach #3 (Hash Table) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class ValidWordAbbr {
    private final Map<String, Boolean> abbrDict = new HashMap<>();
    private final Set<String> dict;

    public ValidWordAbbr(String[] dictionary) {
        dict = new HashSet<>(Arrays.asList(dictionary));
        for (String s : dict) {
            String abbr = toAbbr(s);
            abbrDict.put(abbr, !abbrDict.containsKey(abbr));
        }
    }

    public boolean isUnique(String word) {
        String abbr = toAbbr(word);
        Boolean hasAbbr = abbrDict.get(abbr);
        return hasAbbr == null || (hasAbbr && dict.contains(word));
    }

    private String toAbbr(String s) {
        int n = s.length();
        if (n <= 2) {
            return s;
        }
        return s.charAt(0) + Integer.toString(n - 2) + s.charAt(n - 1);
    }
}
```

</details>
