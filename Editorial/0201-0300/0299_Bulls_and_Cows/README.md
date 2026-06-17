# 299. Bulls and Cows

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/bulls-and-cows/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 299 - Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/)

## Problem

You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

- The number of "bulls", which are digits in the guess that are in the correct position.
- The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.

Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

### Example 1

```text
Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"
```

### Example 2

```text
Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.
```

## Constraints

- 1 <= secret.length, guess.length <= 1000
- secret.length == guess.length
- secret and guess consist of digits only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Make Number of Distinct Characters Equal](https://leetcode.com/problems/make-number-of-distinct-characters-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 299. Bulls and Cows

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| HashMap: Two Passes | Java, Python3 |
| One Pass | Java, Python3 |

## Approach 1: HashMap: Two Passes

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String getHint(String secret, String guess) {
        HashMap<Character, Integer> h = new HashMap();
        for (char s : secret.toCharArray()) {
            h.put(s, h.getOrDefault(s, 0) + 1);
        }
            
        int bulls = 0, cows = 0;
        int n = guess.length();
        for (int idx = 0; idx < n; ++idx) {
            char ch = guess.charAt(idx);
            if (h.containsKey(ch)) {
                // corresponding characters match
                if (ch == secret.charAt(idx)) {
                    // update the bulls
                    bulls++;
                    // update the cows 
                    // if all ch characters from secret 
                    // were used up
                    if (h.get(ch) <= 0)
                        cows--;    
                // corresponding characters don't match
                } else {
                    // update the cows
                    if (h.get(ch) > 0)
                        cows++;     
                }
                // ch character was used
                h.put(ch, h.get(ch) - 1); 
            }
        }
                
        return Integer.toString(bulls) + "A" + Integer.toString(cows) + "B";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        h = Counter(secret)
            
        bulls = cows = 0
        for idx, ch in enumerate(guess):
            if ch in h:
                # corresponding characters match
                if ch == secret[idx]:
                    # update the bulls
                    bulls += 1
                    # update the cows 
                    # if all ch characters from secret 
                    # were used up
                    cows -= int(h[ch] <= 0)
                # corresponding characters don't match
                else:
                    # update the cows
                    cows += int(h[ch] > 0)
                # ch character was used
                h[ch] -= 1
                
        return "{}A{}B".format(bulls, cows)
```

</details>

<br>

## Approach 2: One Pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String getHint(String secret, String guess) {
        HashMap<Character, Integer> h = new HashMap();
            
        int bulls = 0, cows = 0;
        int n = guess.length();
        for (int idx = 0; idx < n; ++idx) {
            char s = secret.charAt(idx);
            char g = guess.charAt(idx);
            if (s == g) {
                bulls++;    
            } else {
                if (h.getOrDefault(s, 0) < 0) 
                    cows++;
                if (h.getOrDefault(g, 0) > 0)
                    cows++;
                h.put(s, h.getOrDefault(s, 0) + 1);
                h.put(g, h.getOrDefault(g, 0) - 1);
            }
        } 
                
        return Integer.toString(bulls) + "A" + Integer.toString(cows) + "B";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        h = defaultdict(int)
        bulls = cows = 0

        for idx, s in enumerate(secret):
            g = guess[idx]
            if s == g: 
                bulls += 1
            else:
                cows += int(h[s] < 0) + int(h[g] > 0)
                h[s] += 1
                h[g] -= 1
                
        return "{}A{}B".format(bulls, cows)
```

</details>
