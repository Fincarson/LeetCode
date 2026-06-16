# 1996. The Number of Weak Characters in the Game

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/)  
`Array` `Stack` `Greedy` `Sorting` `Monotonic Stack`

**Problem Link:** [LeetCode 1996 - The Number of Weak Characters in the Game](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/)

## Problem

You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters.

### Example 1

```text
Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
```

### Example 2

```text
Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack and defense.
```

### Example 3

```text
Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack and defense.
```

## Constraints

- 2 <= properties.length <= 105
- properties[i].length == 2
- 1 <= attacki, defensei <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Height by Stacking Cuboids ](https://leetcode.com/problems/maximum-height-by-stacking-cuboids/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1996. The Number of Weak Characters in the Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java |
| Greedy | C++, Java |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // Sort in ascending order of attack, 
        // If attack is same sort in descending order of defense
        sort(properties.begin(), properties.end(), 
             [](const vector<int>& a, vector<int>& b) -> bool { 
                 return (a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);});
             
        int weakCharacters = 0;
        int maxDefense = 0;
        for (int i = (int)properties.size() - 1; i >= 0; i--) {
            // Compare the current defense with the maximum achieved so far
            if (properties[i][1] < maxDefense) {
                weakCharacters++;
            }
            maxDefense = max(maxDefense, properties[i][1]);
        }
        
        return weakCharacters;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        // Sort in ascending order of attack, 
        // If attack is same sort in descending order of defense
        Arrays.sort(properties, (a, b) -> (a[0] == b[0]) ? (b[1] - a[1]) : a[0] - b[0]);
        
        int weakCharacters = 0;
        int maxDefense = 0;
        for (int i = properties.length - 1; i >= 0; i--) {
            // Compare the current defense with the maximum achieved so far
            if (properties[i][1] < maxDefense) {
                weakCharacters++;
            }
            maxDefense = Math.max(maxDefense, properties[i][1]);
        }
        
        return weakCharacters;
    }
}
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int maxAttack = 0;
        // Find the maximum atack value
        for (vector<int>& property : properties) {
            int attack = property[0];
            maxAttack = max(maxAttack, attack);
        }
        
        vector<int> maxDefense(maxAttack + 2, 0);
        // Store the maximum defense for an attack value
        for (vector<int>& property : properties) {
            int attack = property[0];
            int defense = property[1];
            
            maxDefense[attack] = max(maxDefense[attack], defense);
        }

        // Store the maximum defense for attack greater than or equal to a value
        for (int i = maxAttack - 1; i >= 0; i--) {
            maxDefense[i] = max(maxDefense[i], maxDefense[i + 1]);
        }
        
        int weakCharacters = 0;
        for (vector<int>& property : properties) {
            int attack = property[0];
            int defense = property[1];
            
            // If their is a greater defense for properties with greater attack
            if (defense < maxDefense[attack + 1]) {
                weakCharacters++;
            }
        }
        
        return weakCharacters;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        int maxAttack = 0;
        // Find the maximum atack value
        for (int[] property : properties) {
            int attack = property[0];
            maxAttack = Math.max(maxAttack, attack);
        }
        
        int maxDefense[] = new int[maxAttack + 2];
        // Store the maximum defense for an attack value
        for (int[] property : properties) {
            int attack = property[0];
            int defense = property[1];
            
            maxDefense[attack] = Math.max(maxDefense[attack], defense);
        }

        // Store the maximum defense for attack greater than or equal to a value
        for (int i = maxAttack - 1; i >= 0; i--) {
            maxDefense[i] = Math.max(maxDefense[i], maxDefense[i + 1]);
        }
        
        int weakCharacters = 0;
        for (int[] property : properties) {
            int attack = property[0];
            int defense = property[1];
            
            // If their is a greater defense for properties with greater attack
            if (defense < maxDefense[attack + 1]) {
                weakCharacters++;
            }
        }
        
        return weakCharacters;
    }
}
```

</details>
