# 451. Sort Characters By Frequency

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/sort-characters-by-frequency/)  
`Hash Table` `String` `Sorting` `Heap (Priority Queue)` `Bucket Sort` `Counting`

**Problem Link:** [LeetCode 451 - Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)

## Problem

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

### Example 1

```text
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```

### Example 2

```text
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
```

### Example 3

```text
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
```

## Constraints

- 1 <= s.length <= 5 * 105
- s consists of uppercase and lowercase English letters and digits.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Percentage of Letter in String](https://leetcode.com/problems/percentage-of-letter-in-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Number of Pairs in Array](https://leetcode.com/problems/maximum-number-of-pairs-in-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Node With Highest Edge Score](https://leetcode.com/problems/node-with-highest-edge-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count Pairs Of Similar Strings](https://leetcode.com/problems/count-pairs-of-similar-strings/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 451. Sort Characters By Frequency

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Arrays and Sorting | Java, Python |
| HashMap and Sort | Java, Python |
| Multiset and Bucket Sort | Java, Python |

## Approach 1: Arrays and Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public String frequencySort(String s) {
        
    if (s == null || s.isEmpty()) return s;
    
    // Create a sorted Array of chars.
    char[] chars = s.toCharArray();
    Arrays.sort(chars);
    
    // Convert identical chars into single Strings.
    List<String> charStrings = new ArrayList<String>();
    StringBuilder currentString = new StringBuilder();
    currentString.append(chars[0]);
    for (int i = 1; i < chars.length; i++) {
        if (chars[i] != chars[i - 1]) {
            charStrings.add(currentString.toString());
            currentString = new StringBuilder();
        }
        currentString.append(chars[i]);
    }
    charStrings.add(currentString.toString());
        
    // Our comparator is (a, b) -> b.length() - a.length().
    // If a is longer than b, then a negative number will be returned
    // telling the sort algorithm to place a first. Otherwise, a positive
    // number will be returned, telling it to place a second.
    // This results in a longest to shortest sorted list of the strings.
    Collections.sort(charStrings, (a, b) -> b.length() - a.length());
    
    // Use StringBuilder to build the String to return.
    StringBuilder sb = new StringBuilder();
    for (String str : charStrings) sb.append(str);
    return sb.toString();
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def frequencySort(self, s: str) -> str:
    if not s: return s
    
    # Convert s to a list.
    s = list(s)
    
    # Sort the characters in s.
    s.sort()
    
    # Make a list of strings, one for each unique char.
    all_strings = []
    cur_sb = [s[0]]
    for c in s[1:]:
        # If the last character on string builder is different...
        if cur_sb[-1] != c:
            all_strings.append("".join(cur_sb))
            cur_sb = []
        cur_sb.append(c)
    all_strings.append("".join(cur_sb))
    
    # Sort the strings by length from *longest* to shortest.
    all_strings.sort(key=lambda string : len(string), reverse=True)
    
    # Convert to a single string to return.
    # Converting a list of strings to a string is often done
    # using this rather strange looking python idiom.
    return "".join(all_strings)
```

</details>

<br>

## Approach 2: HashMap and Sort

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public String frequencySort(String s) {

    // Count up the occurances.
    Map<Character, Integer> counts = new HashMap<>();
    for (char c : s.toCharArray()) {
        counts.put(c, counts.getOrDefault(c, 0) + 1);
    }
            
    // Make a list of the keys, sorted by frequency.
    List<Character> characters = new ArrayList<>(counts.keySet());        
    Collections.sort(characters, (a, b) -> counts.get(b) - counts.get(a));

    // Convert the counts into a string with a sb.
    StringBuilder sb = new StringBuilder();
    for (char c : characters) {
        int copies = counts.get(c);
        for (int i = 0; i < copies; i++) {
            sb.append(c);
        }
    }
    return sb.toString();
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def frequencySort(self, s: str) -> str:

    # Count up the occurances.
    counts = collections.Counter(s)
    
    # Build up the string builder.
    string_builder = []
    for letter, freq in counts.most_common():
        # letter * freq makes freq copies of letter.
        # e.g. "a" * 4 -> "aaaa"
        string_builder.append(letter * freq)
    return "".join(string_builder)
```

</details>

<br>

## Approach 3: Multiset and Bucket Sort

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public String frequencySort(String s) {
        
    if (s == null || s.isEmpty()) return s;
    
    // Count up the occurances.
    Map<Character, Integer> counts = new HashMap<>();
    for (char c : s.toCharArray()) {
        counts.put(c, counts.getOrDefault(c, 0) + 1);
    }
    
    int maximumFrequency = Collections.max(counts.values());
    
    // Make the list of buckets and apply bucket sort.
    List<List<Character>> buckets = new ArrayList<>();
    for (int i = 0; i <= maximumFrequency; i++) {
        buckets.add(new ArrayList<Character>());
    }
    for (Character key : counts.keySet()) {
        int freq = counts.get(key);
        buckets.get(freq).add(key);
    }

    // Build up the string. 
    StringBuilder sb = new StringBuilder();
    for (int i = buckets.size() - 1; i >= 1; i--) {
        for (Character c : buckets.get(i)) {
            for (int j = 0; j < i; j++) {
                sb.append(c);
            }
        }
    }
    return sb.toString();
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def frequencySort(self, s: str) -> str:
    if not s: return s
    
    # Determine the frequency of each character.
    counts = collections.Counter(s)
    max_freq = max(counts.values())
    
    # Bucket sort the characters by frequency.
    buckets = [[] for _ in range(max_freq + 1)]
    for c, i in counts.items():
        buckets[i].append(c)
        
    # Build up the string.
    string_builder = []
    for i in range(len(buckets) - 1, 0, -1):
        for c in buckets[i]:
            string_builder.append(c * i)
            
    return "".join(string_builder)
```

</details>
