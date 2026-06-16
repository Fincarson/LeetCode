# 17. Letter Combinations of a Phone Number

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)  
`Hash Table` `String` `Backtracking`

**Problem Link:** [LeetCode 17 - Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

## Problem

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

### Example 1

```text
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

### Example 2

```text
Input: digits = "2"
Output: ["a","b","c"]
```

## Constraints

- 1 <= digits.length <= 4
- digits[i] is a digit in the range ['2', '9'].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Combination Sum](https://leetcode.com/problems/combination-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Binary Watch](https://leetcode.com/problems/binary-watch/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count Number of Texts](https://leetcode.com/problems/count-number-of-texts/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Number of Pushes to Type Word I](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Number of Pushes to Type Word II](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 17. Letter Combinations of a Phone Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// include the utash.h
struct letters {
    char id; /* key */
    const char* value;
    UT_hash_handle hh; /* makes this structure hashable */
};
void backtrack(struct letters** lettersHash, const char* digits, int index,
               char* path, int pathLen, char** combinations, int* returnSize) {
    if (pathLen == strlen(digits)) {
        path[pathLen] = '\0';
        combinations[*returnSize] = (char*)calloc(pathLen + 1, sizeof(char));
        strncpy(combinations[*returnSize], path, pathLen + 1);
        (*returnSize)++;
        return;
    }
    struct letters* s;
    HASH_FIND(hh, *lettersHash, &digits[index], sizeof(char), s);
    const char* possibleLetters = s->value;
    while (*possibleLetters) {
        path[pathLen] = *possibleLetters;
        backtrack(lettersHash, digits, index + 1, path, pathLen + 1,
                  combinations, returnSize);
        possibleLetters++;
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }
    struct letters m1 = {'2', "abc"}, m2 = {'3', "def"}, m3 = {'4', "ghi"},
                   m4 = {'5', "jkl"}, m5 = {'6', "mno"}, m6 = {'7', "pqrs"},
                   m7 = {'8', "tuv"}, m8 = {'9', "wxyz"}, *s,
                   *lettersHash = NULL;
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m1);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m2);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m3);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m4);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m5);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m6);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m7);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m8);
    char** combinations = (char**)malloc(1024 * sizeof(char*));
    char* path = (char*)calloc(5, sizeof(char));
    *returnSize = 0;
    backtrack(&lettersHash, digits, 0, path, 0, combinations, returnSize);
    free(path);
    HASH_CLEAR(hh, lettersHash);
    return combinations;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    vector<string> combinations;
    unordered_map<char, string> letters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string phoneDigits;

public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return combinations;
        }
        phoneDigits = digits;
        backtrack(0, "");
        return combinations;
    }

private:
    void backtrack(int index, string path) {
        if (path.length() == phoneDigits.length()) {
            combinations.push_back(path);
            return;
        }
        string possibleLetters = letters[phoneDigits[index]];
        for (char letter : possibleLetters) {
            path.push_back(letter);
            backtrack(index + 1, path);
            path.pop_back();
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private List<string> combinations = new List<string>();

    private Dictionary<char, string> letters = new Dictionary<char, string> {
        { '2', "abc" }, { '3', "def" },  { '4', "ghi" }, { '5', "jkl" },
        { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" }
    };

    private string phoneDigits;

    public IList<string> LetterCombinations(string digits) {
        if (digits.Length == 0) {
            return combinations;
        }

        phoneDigits = digits;
        Backtrack(0, new StringBuilder());
        return combinations;
    }

    private void Backtrack(int index, StringBuilder path) {
        if (path.Length == phoneDigits.Length) {
            combinations.Add(path.ToString());
            return;
        }

        string possibleLetters = letters[phoneDigits[index]];
        foreach (char letter in possibleLetters) {
            path.Append(letter);
            Backtrack(index + 1, path);
            path.Remove(path.Length - 1, 1);
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return []string{}
    }
    combinations := []string{}
    letters := map[rune]string{
        '2': "abc", '3': "def", '4': "ghi", '5': "jkl",
        '6': "mno", '7': "pqrs", '8': "tuv", '9': "wxyz",
    }
    var backtrack func(index int, path []rune)
    backtrack = func(index int, path []rune) {
        if len(path) == len(digits) {
            combinations = append(combinations, string(path))
            return
        }
        possibleLetters := letters[rune(digits[index])]
        for _, letter := range possibleLetters {
            path = append(path, letter)
            backtrack(index+1, path)
            path = path[:len(path)-1]
        }
    }
    backtrack(0, []rune{})
    return combinations
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private List<String> combinations = new ArrayList<>();
    private Map<Character, String> letters = Map.of(
        '2',
        "abc",
        '3',
        "def",
        '4',
        "ghi",
        '5',
        "jkl",
        '6',
        "mno",
        '7',
        "pqrs",
        '8',
        "tuv",
        '9',
        "wxyz"
    );
    private String phoneDigits;

    public List<String> letterCombinations(String digits) {
        // If the input is empty, immediately return an empty answer array
        if (digits.length() == 0) {
            return combinations;
        }

        // Initiate backtracking with an empty path and starting index of 0
        phoneDigits = digits;
        backtrack(0, new StringBuilder());
        return combinations;
    }

    private void backtrack(int index, StringBuilder path) {
        // If the path is the same length as digits, we have a complete combination
        if (path.length() == phoneDigits.length()) {
            combinations.add(path.toString());
            return; // Backtrack
        }

        // Get the letters that the current digit maps to, and loop through them
        String possibleLetters = letters.get(phoneDigits.charAt(index));
        for (char letter : possibleLetters.toCharArray()) {
            // Add the letter to our current path
            path.append(letter);
            // Move on to the next digit
            backtrack(index + 1, path);
            // Backtrack by removing the letter before moving onto the next
            path.deleteCharAt(path.length() - 1);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var letterCombinations = function (digits) {
    if (digits.length === 0) {
        return [];
    }
    let combinations = [];
    let letters = {
        2: "abc",
        3: "def",
        4: "ghi",
        5: "jkl",
        6: "mno",
        7: "pqrs",
        8: "tuv",
        9: "wxyz",
    };
    let backtrack = function (index, path) {
        if (path.length === digits.length) {
            combinations.push(path.join(""));
            return;
        }
        let possibleLetters = letters[digits[index]];
        for (let letter of possibleLetters) {
            path.push(letter);
            backtrack(index + 1, path);
            path.pop();
        }
    };
    backtrack(0, []);
    return combinations;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        # If the input is empty, immediately return an empty answer array
        if len(digits) == 0:
            return []

        # Map all the digits to their corresponding letters
        letters = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(index, path):
            # If the path is the same length as digits, we have a complete combination
            if len(path) == len(digits):
                combinations.append("".join(path))
                return  # Backtrack

            # Get the letters that the current digit maps to, and loop through them
            possible_letters = letters[digits[index]]
            for letter in possible_letters:
                # Add the letter to our current path
                path.append(letter)
                # Move on to the next digit
                backtrack(index + 1, path)
                # Backtrack by removing the letter before moving onto the next
                path.pop()

        # Initiate backtracking with an empty path and starting index of 0
        combinations = []
        backtrack(0, [])
        return combinations
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function letterCombinations(digits: string): string[] {
    if (digits.length === 0) {
        return [];
    }
    let combinations: string[] = [];
    let letters: { [key: string]: string } = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    };
    let backtrack = function (index: number, path: string[]): void {
        if (path.length === digits.length) {
            combinations.push(path.join(""));
            return;
        }
        let possibleLetters: string = letters[digits[index]];
        for (let letter of possibleLetters) {
            path.push(letter);
            backtrack(index + 1, path);
            path.pop();
        }
    };
    backtrack(0, []);
    return combinations;
}
```

</details>
