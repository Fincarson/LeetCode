# 65. Valid Number

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/valid-number/)  
`String`

**Problem Link:** [LeetCode 65 - Valid Number](https://leetcode.com/problems/valid-number/)

## Problem

Given a string s, return whether s is a valid number.

For example, all the following are valid numbers: "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", while the following are not valid numbers: "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53".

Formally, a valid number is defined using one of the following definitions:

An integer number is defined with an optional sign '-' or '+' followed by digits.

A decimal number is defined with an optional sign '-' or '+' followed by one of the following definitions:

An exponent is defined with an exponent notation 'e' or 'E' followed by an integer number.

The digits are defined as one or more digits.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= s.length <= 20
- s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 65. Valid Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Follow The Rules! | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Deterministic Finite Automaton (DFA) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Follow The Rules!

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isNumber(char *s) {
    bool seenDigit = false;
    bool seenExponent = false;
    bool seenDot = false;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char curr = s[i];
        if ('0' <= curr && curr <= '9') {
            seenDigit = true;
        } else if (curr == '+' || curr == '-') {
            if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }
        } else if (curr == 'e' || curr == 'E') {
            if (seenExponent || !seenDigit) {
                return false;
            }
            seenExponent = true;
            seenDigit = false;
        } else if (curr == '.') {
            if (seenDot || seenExponent) {
                return false;
            }
            seenDot = true;
        } else {
            return false;
        }
    }
    return seenDigit;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            if (curr >= '0' && curr <= '9') {
                seenDigit = true;
            } else if (curr == '+' || curr == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (curr == 'e' || curr == 'E') {
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false;
            } else if (curr == '.') {
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else {
                return false;
            }
        }
        return seenDigit;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsNumber(string s) {
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;
        for (int i = 0; i < s.Length; i++) {
            char curr = s[i];
            if (Char.IsDigit(curr)) {
                seenDigit = true;
            } else if (curr == '+' || curr == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (curr == 'e' || curr == 'E') {
                if (seenExponent || !seenDigit) {
                    return false;
                }

                seenExponent = true;
                seenDigit = false;
            } else if (curr == '.') {
                if (seenDot || seenExponent) {
                    return false;
                }

                seenDot = true;
            } else {
                return false;
            }
        }

        return seenDigit;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isNumber(s string) bool {
    seenDigit := false
    seenExponent := false
    seenDot := false
    for i := 0; i < len(s); i++ {
        curr := s[i]
        if '0' <= curr && curr <= '9' {
            seenDigit = true
        } else if curr == '+' || curr == '-' {
            if i > 0 && s[i-1] != 'e' && s[i-1] != 'E' {
                return false
            }
        } else if curr == 'e' || curr == 'E' {
            if seenExponent || !seenDigit {
                return false
            }
            seenExponent = true
            seenDigit = false
        } else if curr == '.' {
            if seenDot || seenExponent {
                return false
            }
            seenDot = true
        } else {
            return false
        }
    }
    return seenDigit
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isNumber(String s) {
        boolean seenDigit = false;
        boolean seenExponent = false;
        boolean seenDot = false;

        for (int i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);
            if (Character.isDigit(curr)) {
                seenDigit = true;
            } else if (curr == '+' || curr == '-') {
                if (i > 0 && s.charAt(i - 1) != 'e' && s.charAt(i - 1) != 'E') {
                    return false;
                }
            } else if (curr == 'e' || curr == 'E') {
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false;
            } else if (curr == '.') {
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else {
                return false;
            }
        }

        return seenDigit;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isNumber = function (s) {
    var seenDigit = false;
    var seenExponent = false;
    var seenDot = false;
    for (var i = 0; i < s.length; i++) {
        var curr = s[i];
        if (!isNaN(curr)) {
            seenDigit = true;
        } else if (curr == "+" || curr == "-") {
            if (i > 0 && s[i - 1] != "e" && s[i - 1] != "E") {
                return false;
            }
        } else if (curr == "e" || curr == "E") {
            if (seenExponent || !seenDigit) {
                return false;
            }
            seenExponent = true;
            seenDigit = false;
        } else if (curr == ".") {
            if (seenDot || seenExponent) {
                return false;
            }
            seenDot = true;
        } else {
            return false;
        }
    }
    return seenDigit;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isNumber(self, s: str) -> bool:
        seen_digit = seen_exponent = seen_dot = False
        for i, c in enumerate(s):
            if c.isdigit():
                seen_digit = True
            elif c in ["+", "-"]:
                if i > 0 and s[i - 1] != "e" and s[i - 1] != "E":
                    return False
            elif c in ["e", "E"]:
                if seen_exponent or not seen_digit:
                    return False
                seen_exponent = True
                seen_digit = False
            elif c == ".":
                if seen_dot or seen_exponent:
                    return False
                seen_dot = True
            else:
                return False

        return seen_digit
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isNumber(s: string): boolean {
    let seenDigit: boolean = false;
    let seenExponent: boolean = false;
    let seenDot: boolean = false;
    for (let i = 0; i < s.length; i++) {
        let curr: string = s[i];
        if (!isNaN(parseInt(curr))) {
            seenDigit = true;
        } else if (curr == "+" || curr == "-") {
            if (i > 0 && s[i - 1] != "e" && s[i - 1] != "E") {
                return false;
            }
        } else if (curr == "e" || curr == "E") {
            if (seenExponent || !seenDigit) {
                return false;
            }
            seenExponent = true;
            seenDigit = false;
        } else if (curr == ".") {
            if (seenDot || seenExponent) {
                return false;
            }
            seenDot = true;
        } else {
            return false;
        }
    }
    return seenDigit;
}
```

</details>

<br>

## Approach 2: Deterministic Finite Automaton (DFA)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct hash_struct {
    int val;
    char id[20];
    UT_hash_handle hh;
};
bool isNumber(char *s) {
    struct hash_struct *hash_table[8];
    for (int i = 0; i < 8; i++) hash_table[i] = NULL;
    void add_item(struct hash_struct * *head, char *string, int number) {
        struct hash_struct *s = malloc(sizeof(struct hash_struct));
        strcpy(s->id, string);
        s->val = number;
        HASH_ADD_STR(*head, id, s);
    }
    add_item(&hash_table[0], "digit", 1);
    add_item(&hash_table[0], "sign", 2);
    add_item(&hash_table[0], "dot", 3);
    add_item(&hash_table[1], "digit", 1);
    add_item(&hash_table[1], "dot", 4);
    add_item(&hash_table[1], "exponent", 5);
    add_item(&hash_table[2], "digit", 1);
    add_item(&hash_table[2], "dot", 3);
    add_item(&hash_table[3], "digit", 4);
    add_item(&hash_table[4], "digit", 4);
    add_item(&hash_table[4], "exponent", 5);
    add_item(&hash_table[5], "sign", 6);
    add_item(&hash_table[5], "digit", 7);
    add_item(&hash_table[6], "digit", 7);
    add_item(&hash_table[7], "digit", 7);
    int current_state = 0;
    struct hash_struct *hash_item;
    for (int i = 0; s[i] != '\0'; i++) {
        char group[10];
        if (isdigit(s[i])) {
            strcpy(group, "digit");
        } else if (s[i] == '+' || s[i] == '-') {
            strcpy(group, "sign");
        } else if (s[i] == 'e' || s[i] == 'E') {
            strcpy(group, "exponent");
        } else if (s[i] == '.') {
            strcpy(group, "dot");
        } else {
            return false;
        }
        HASH_FIND_STR(hash_table[current_state], group, hash_item);
        if (hash_item == NULL) {
            return false;
        }
        current_state = hash_item->val;
    }
    return current_state == 1 || current_state == 4 || current_state == 7;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isNumber(string s) {
        // This is the DFA we have designed above
        map<string, int> dfa[8] = {{{"digit", 1}, {"sign", 2}, {"dot", 3}},
                                   {{"digit", 1}, {"dot", 4}, {"exponent", 5}},
                                   {{"digit", 1}, {"dot", 3}},
                                   {{"digit", 4}},
                                   {{"digit", 4}, {"exponent", 5}},
                                   {{"sign", 6}, {"digit", 7}},
                                   {{"digit", 7}},
                                   {{"digit", 7}}};
        int current_state = 0;
        string group;
        for (char c : s) {
            if (isdigit(c)) {
                group = "digit";
            } else if (c == '+' || c == '-') {
                group = "sign";
            } else if (c == 'e' || c == 'E') {
                group = "exponent";
            } else if (c == '.') {
                group = "dot";
            } else {
                return false;
            }
            if (dfa[current_state].find(group) == dfa[current_state].end()) {
                return false;
            }
            current_state = dfa[current_state][group];
        }
        return current_state == 1 || current_state == 4 || current_state == 7;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsNumber(string s) {
        // This is the DFA we have designed above
        var dfa = new Dictionary<string, int>[] {
            new Dictionary<string, int> {
                { "digit", 1 }, { "sign", 2 }, { "dot", 3 }
            },
            new Dictionary<string, int> {
                { "digit", 1 }, { "dot", 4 }, { "exponent", 5 }
            },
            new Dictionary<string, int> { { "digit", 1 }, { "dot", 3 } },
            new Dictionary<string, int> { { "digit", 4 } },
            new Dictionary<string, int> { { "digit", 4 }, { "exponent", 5 } },
            new Dictionary<string, int> { { "sign", 6 }, { "digit", 7 } },
            new Dictionary<string, int> { { "digit", 7 } },
            new Dictionary<string, int> { { "digit", 7 } }
        };
        int currentState = 0;
        string group;
        foreach (char curr in s) {
            if (Char.IsDigit(curr)) {
                group = "digit";
            } else if (curr == '+' || curr == '-') {
                group = "sign";
            } else if (curr == 'e' || curr == 'E') {
                group = "exponent";
            } else if (curr == '.') {
                group = "dot";
            } else {
                return false;
            }

            if (!dfa[currentState].ContainsKey(group)) {
                return false;
            }

            currentState = dfa[currentState][group];
        }

        return currentState == 1 || currentState == 4 || currentState == 7;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isNumber(s string) bool {
    // This is the DFA we have designed above
    dfa := []map[string]int{
        {"digit": 1, "sign": 2, "dot": 3},
        {"digit": 1, "dot": 4, "exponent": 5},
        {"digit": 1, "dot": 3},
        {"digit": 4},
        {"digit": 4, "exponent": 5},
        {"sign": 6, "digit": 7},
        {"digit": 7},
        {"digit": 7},
    }
    currentState := 0
    var group string
    for _, c := range s {
        if c >= '0' && c <= '9' {
            group = "digit"
        } else if c == '+' || c == '-' {
            group = "sign"
        } else if c == 'e' || c == 'E' {
            group = "exponent"
        } else if c == '.' {
            group = "dot"
        } else {
            return false
        }
        if _, ok := dfa[currentState][group]; !ok {
            return false
        }
        currentState = dfa[currentState][group]
    }
    return currentState == 1 || currentState == 4 || currentState == 7
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // This is the DFA we have designed above
    private static final List<Map<String, Integer>> dfa = List.of(
        Map.of("digit", 1, "sign", 2, "dot", 3),
        Map.of("digit", 1, "dot", 4, "exponent", 5),
        Map.of("digit", 1, "dot", 3),
        Map.of("digit", 4),
        Map.of("digit", 4, "exponent", 5),
        Map.of("sign", 6, "digit", 7),
        Map.of("digit", 7),
        Map.of("digit", 7)
    );

    // These are all of the valid finishing states for our DFA.
    private static final Set<Integer> validFinalStates = Set.of(1, 4, 7);

    public boolean isNumber(String s) {
        int currentState = 0;
        String group = "";

        for (int i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);
            if (Character.isDigit(curr)) {
                group = "digit";
            } else if (curr == '+' || curr == '-') {
                group = "sign";
            } else if (curr == 'e' || curr == 'E') {
                group = "exponent";
            } else if (curr == '.') {
                group = "dot";
            } else {
                return false;
            }

            if (!dfa.get(currentState).containsKey(group)) {
                return false;
            }

            currentState = dfa.get(currentState).get(group);
        }

        return validFinalStates.contains(currentState);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isNumber = function (s) {
    // This is the DFA we have designed above
    const dfa = [
        { digit: 1, sign: 2, dot: 3 },
        { digit: 1, dot: 4, exponent: 5 },
        { digit: 1, dot: 3 },
        { digit: 4 },
        { digit: 4, exponent: 5 },
        { sign: 6, digit: 7 },
        { digit: 7 },
        { digit: 7 },
    ];
    let current_state = 0;
    let group;
    for (const c of s) {
        if (c >= "0" && c <= "9") {
            group = "digit";
        } else if (c === "+" || c === "-") {
            group = "sign";
        } else if (c === "e" || c === "E") {
            group = "exponent";
        } else if (c === ".") {
            group = "dot";
        } else {
            return false;
        }
        if (!dfa[current_state][group]) {
            return false;
        }
        current_state = dfa[current_state][group];
    }
    return current_state === 1 || current_state === 4 || current_state === 7;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def isNumber(self, s):
        # This is the DFA we have designed above
        dfa = [
            {"digit": 1, "sign": 2, "dot": 3},
            {"digit": 1, "dot": 4, "exponent": 5},
            {"digit": 1, "dot": 3},
            {"digit": 4},
            {"digit": 4, "exponent": 5},
            {"sign": 6, "digit": 7},
            {"digit": 7},
            {"digit": 7},
        ]

        current_state = 0
        for c in s:
            if c.isdigit():
                group = "digit"
            elif c in ["+", "-"]:
                group = "sign"
            elif c in ["e", "E"]:
                group = "exponent"
            elif c == ".":
                group = "dot"
            else:
                return False

            if group not in dfa[current_state]:
                return False

            current_state = dfa[current_state][group]

        return current_state in [1, 4, 7]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isNumber(s: string): boolean {
    // This is the DFA we have designed above
    const dfa: { [key: string]: number }[] = [
        { digit: 1, sign: 2, dot: 3 },
        { digit: 1, dot: 4, exponent: 5 },
        { digit: 1, dot: 3 },
        { digit: 4 },
        { digit: 4, exponent: 5 },
        { sign: 6, digit: 7 },
        { digit: 7 },
        { digit: 7 },
    ];
    let current_state = 0;
    let group: string;
    for (const c of s) {
        if (c >= "0" && c <= "9") {
            group = "digit";
        } else if (c === "+" || c === "-") {
            group = "sign";
        } else if (c === "e" || c === "E") {
            group = "exponent";
        } else if (c === ".") {
            group = "dot";
        } else {
            return false;
        }
        if (!dfa[current_state][group]) {
            return false;
        }
        current_state = dfa[current_state][group];
    }
    return current_state === 1 || current_state === 4 || current_state === 7;
}
```

</details>
