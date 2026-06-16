# 1079. Letter Tile Possibilities

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/letter-tile-possibilities/)  
`Hash Table` `String` `Backtracking` `Counting`

**Problem Link:** [LeetCode 1079 - Letter Tile Possibilities](https://leetcode.com/problems/letter-tile-possibilities/)

## Problem

You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

### Example 1

```text
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
```

### Example 2

```text
Input: tiles = "AAABBC"
Output: 188
```

### Example 3

```text
Input: tiles = "V"
Output: 1
```

## Constraints

- 1 <= tiles.length <= 7
- tiles consists of uppercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1079. Letter Tile Possibilities

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C++, Java, Python3 |
| Optimized Recursion | C++, Java, Python3 |
| Permutations and Combinations | C++, Java, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> sequences;
        vector<bool> used(tiles.length(), false);

        // Generate all possible sequences including empty string
        generateSequences(tiles, "", used, sequences);

        // Subtract 1 to exclude empty string from count
        return sequences.size() - 1;
    }

private:
    void generateSequences(string& tiles, string current, vector<bool>& used,
                           unordered_set<string>& sequences) {
        // Add current sequence to set
        sequences.insert(current);

        // Try adding each unused character to current sequence
        for (int pos = 0; pos < tiles.length(); ++pos) {
            if (!used[pos]) {
                used[pos] = true;
                generateSequences(tiles, current + tiles[pos], used, sequences);
                used[pos] = false;
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numTilePossibilities(String tiles) {
        Set<String> sequences = new HashSet<>();
        int len = tiles.length();
        boolean[] used = new boolean[len];

        // Generate all possible sequences including empty string
        generateSequences(tiles, "", used, sequences);

        // Subtract 1 to exclude empty string from count
        return sequences.size() - 1;
    }

    public void generateSequences(
        String tiles,
        String current,
        boolean[] used,
        Set<String> sequences
    ) {
        // Add current sequence to set
        sequences.add(current);

        // Try adding each unused character to current sequence
        for (int pos = 0; pos < tiles.length(); pos++) {
            if (!used[pos]) {
                used[pos] = true;
                generateSequences(
                    tiles,
                    current + tiles.charAt(pos),
                    used,
                    sequences
                );
                used[pos] = false;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        sequences = set()
        used = [False] * len(tiles)

        # Generate all possible sequences including empty string
        self._generate_sequences(tiles, "", used, sequences)

        # Subtract 1 to exclude empty string from count
        return len(sequences) - 1

    def _generate_sequences(
        self, tiles: str, current: str, used: list, sequences: set
    ) -> None:
        sequences.add(current)

        # Try adding each unused character to current sequence
        for pos, char in enumerate(tiles):
            if not used[pos]:
                used[pos] = True
                self._generate_sequences(tiles, current + char, used, sequences)
                used[pos] = False
```

</details>

<br>

## Approach 2: Optimized Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTilePossibilities(string tiles) {
        // Track frequency of each uppercase letter (A-Z)
        int charCount[26] = {0};
        for (char c : tiles) {
            charCount[c - 'A']++;
        }

        // Find all possible sequences using character frequencies
        return findSequences(charCount);
    }

private:
    int findSequences(int charCount[26]) {
        int totalCount = 0;

        // Try using each available character
        for (int pos = 0; pos < 26; pos++) {
            if (charCount[pos] == 0) {
                continue;
            }

            // Add current character and recurse
            totalCount++;
            charCount[pos]--;
            totalCount += findSequences(charCount);
            charCount[pos]++;
        }

        return totalCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numTilePossibilities(String tiles) {
        // Track frequency of each uppercase letter (A-Z)
        int[] charCount = new int[26];
        for (char c : tiles.toCharArray()) {
            charCount[c - 'A']++;
        }

        // Find all possible sequences using character frequencies
        return findSequences(charCount);
    }

    private int findSequences(int[] charCount) {
        int totalCount = 0;

        // Try using each available character
        for (int pos = 0; pos < 26; pos++) {
            if (charCount[pos] == 0) {
                continue;
            }

            // Add current character and recurse
            totalCount++;
            charCount[pos]--;
            totalCount += findSequences(charCount);
            charCount[pos]++;
        }

        return totalCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        # Track frequency of each uppercase letter (A-Z)
        char_count = [0] * 26
        for char in tiles:
            char_count[ord(char) - ord("A")] += 1

        # Find all possible sequences using character frequencies
        return self._find_sequences(char_count)

    def _find_sequences(self, char_count: list) -> int:
        total = 0

        # Try using each available character
        for pos in range(26):
            if char_count[pos] == 0:
                continue

            # Add current character and recurse
            total += 1
            char_count[pos] -= 1
            total += self._find_sequences(char_count)
            char_count[pos] += 1

        return total
```

</details>

<br>

## Approach 3: Permutations and Combinations

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> seen;

        // Sort characters to handle duplicates efficiently
        sort(tiles.begin(), tiles.end());

        // Find all unique sequences and their permutations
        return generateSequences(tiles, "", 0, seen) - 1;
    }

private:
    int factorial(int n) {
        if (n <= 1) {
            return 1;
        }

        int result = 1;
        for (int num = 2; num <= n; num++) {
            result *= num;
        }
        return result;
    }

    int countPermutations(string& seq) {
        // Count frequency of each character
        int charCount[26] = {0};
        for (char ch : seq) {
            charCount[ch - 'A']++;
        }

        // Calculate permutations using factorial formula
        int total = factorial(seq.length());
        for (int count : charCount) {
            if (count > 1) {
                total /= factorial(count);
            }
        }
        return total;
    }

    int generateSequences(string& tiles, string current, int pos,
                          unordered_set<string>& seen) {
        if (pos >= tiles.length()) {
            // If new sequence found, count its unique permutations
            if (seen.insert(current).second) {
                return countPermutations(current);
            }
            return 0;
        }

        // Try including and excluding current character
        return generateSequences(tiles, current, pos + 1, seen) +
               generateSequences(tiles, current + tiles[pos], pos + 1, seen);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numTilePossibilities(String tiles) {
        Set<String> seen = new HashSet<>();

        // Sort characters to handle duplicates efficiently
        char[] chars = tiles.toCharArray();
        Arrays.sort(chars);
        String sortedTiles = new String(chars);

        // Find all unique sequences and their permutations
        return generateSequences(sortedTiles, "", 0, seen) - 1;
    }

    private int factorial(int n) {
        if (n <= 1) {
            return 1;
        }

        int result = 1;
        for (int num = 2; num <= n; num++) {
            result *= num;
        }
        return result;
    }

    private int countPermutations(String seq) {
        // Count frequency of each character
        int[] charCount = new int[26];
        for (char ch : seq.toCharArray()) {
            charCount[ch - 'A']++;
        }

        // Calculate permutations using factorial formula
        int total = factorial(seq.length());
        for (int count : charCount) {
            total /= factorial(count);
        }
        return total;
    }

    private int generateSequences(
        String tiles,
        String current,
        int pos,
        Set<String> seen
    ) {
        if (pos >= tiles.length()) {
            // If new sequence found, count its unique permutations
            if (seen.add(current)) {
                return countPermutations(current);
            }
            return 0;
        }

        // Try including and excluding current character
        return (
            generateSequences(tiles, current, pos + 1, seen) +
            generateSequences(tiles, current + tiles.charAt(pos), pos + 1, seen)
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        seen = set()

        # Sort characters to handle duplicates efficiently
        sorted_tiles = "".join(sorted(tiles))

        # Find all unique sequences and their permutations
        return self._generate_sequences(sorted_tiles, "", 0, seen) - 1

    def _factorial(self, n: int) -> int:
        if n <= 1:
            return 1

        result = 1
        for num in range(2, n + 1):
            result *= num
        return result

    def _count_permutations(self, seq: str) -> int:
        # Calculate permutations using factorial formula
        total = self._factorial(len(seq))

        # Divide by factorial of each character's frequency
        for count in Counter(seq).values():
            total //= self._factorial(count)

        return total

    def _generate_sequences(
        self, tiles: str, current: str, pos: int, seen: set
    ) -> int:
        if pos >= len(tiles):
            # If new sequence found, count its unique permutations
            if current not in seen:
                seen.add(current)
                return self._count_permutations(current)
            return 0

        # Try including and excluding current character
        return self._generate_sequences(
            tiles, current, pos + 1, seen
        ) + self._generate_sequences(tiles, current + tiles[pos], pos + 1, seen)
```

</details>
