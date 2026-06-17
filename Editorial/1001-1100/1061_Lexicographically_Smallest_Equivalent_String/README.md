# 1061. Lexicographically Smallest Equivalent String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/)  
`String` `Union-Find`

**Problem Link:** [LeetCode 1061 - Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/)

## Problem

You are given two strings of the same length s1 and s2 and a string baseStr.

We say s1[i] and s2[i] are equivalent characters.

- For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.

Equivalent characters follow the usual rules of any equivalence relation:

- Reflexivity: 'a' == 'a'.
- Symmetry: 'a' == 'b' implies 'b' == 'a'.
- Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.

For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

### Example 1

```text
Input: s1 = "parker", s2 = "morris", baseStr = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
The characters in each group are equivalent and sorted in lexicographical order.
So the answer is "makkek".
```

### Example 2

```text
Input: s1 = "hello", s2 = "world", baseStr = "hold"
Output: "hdld"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".
```

### Example 3

```text
Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
Output: "aauaaaaada"
Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".
```

## Constraints

- 1 <= s1.length, s2.length, baseStr <= 1000
- s1.length == s2.length
- s1, s2, and baseStr consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Lexicographically Smallest Generated String](https://leetcode.com/problems/lexicographically-smallest-generated-string/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1061. Lexicographically Smallest Equivalent String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C++, Java |
| Disjoint Set Union (DSU/Union Find) | C++, Java |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void DFS(int src, array<array<int, 26>, 26>& adjMatrix, array<int, 26>& visited, vector<int>& component, int& minChar) {
        // Mark the character as visited.
        visited[src] = 1;
        // Add it to the list.
        component.push_back(src);
        // Update the minimum character in the component.
        minChar = min(minChar, src);
        
        for (int i = 0; i < 26; i++) {
            // Perform DFS, if the edge exists and the node isn't visited yet.
            if (adjMatrix[src][i] && !visited[i]) {
                DFS(i, adjMatrix, visited, component, minChar);
            }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Adjacency matrix to store edges.
        array<array<int, 26>, 26> adjMatrix = {0};
        for (int i = 0; i < s1.size(); i++) {
            adjMatrix[s1[i] - 'a'][s2[i] - 'a'] = 1;
            adjMatrix[s2[i] - 'a'][s1[i] - 'a'] = 1;
        }
        
        // Array to store the final character mappings.
        array<int, 26> mappingChar = {0};
        for (int i = 0; i < 26; i++) {
            mappingChar[i] = i;
        }
        
        // Array to keep visited nodes during DFS.
        array<int, 26> visited = {0};
        for (int c = 0; c < 26; c++) {
            if (!visited[c]) {
                // Store the characters in the current component.
                vector<int> component;
                // Variable to store the minimum character in the component.
                int minChar = 27;

                DFS(c, adjMatrix, visited, component, minChar);
 
                // Map the characters in the component to the minimum character.
                for (int vertex : component) {
                    mappingChar[vertex] = minChar;
                }
            }
        }
        
        string ans;
        // Create the answer string.
        for (char c : baseStr) {
            ans += (char)(mappingChar[c - 'a'] + 'a');
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
    int minChar;

    void DFS(int src, Integer[][] adjMatrix, Integer visited[], List<Integer> component) {
        // Mark the character as visited.
        visited[src] = 1;
        // Add it to the list.
        component.add(src);
        // Update the minimum character in the component.
        minChar = Math.min(minChar, src);

        for (int i = 0; i < 26; i++) {
            // Perform DFS if the edge exists and the node isn't visited yet.
            if (adjMatrix[src][i] != null && visited[i] == null) {
                DFS(i, adjMatrix, visited, component);
            }
        }
    }

    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        // Adjacency matrix to store edges.
        Integer adjMatrix[][] = new Integer[26][26];
        for (int i = 0; i < s1.length(); i++) {
            adjMatrix[s1.charAt(i) - 'a'][s2.charAt(i) - 'a'] = 1;
            adjMatrix[s2.charAt(i) - 'a'][s1.charAt(i) - 'a'] = 1;
        }

        // Array to store the final character mappings.
        int mappingChar[] = new int[26];
        for (int i = 0; i < 26; i++) {
            mappingChar[i] = i;
        }

        // Array to keep visited nodes during DFS.
        Integer visited[] = new Integer[26];
        for (int c = 0; c < 26; c++) {
            if (visited[c] == null) {
                // Store the characters in the current component.
                List<Integer> component = new ArrayList<>();
                // Variable to store the minimum character in the component.
                minChar = 27;

                DFS(c, adjMatrix, visited, component);

                // Map the characters in the component to the minimum character.
                for (int vertex : component) {
                    mappingChar[vertex] = minChar;
                }
            }
        }

        String ans = "";
        // Create the answer string.
        for (char c : baseStr.toCharArray()) {
            ans += (char)(mappingChar[c - 'a'] + 'a');
        }

        return ans;
    }
}
```

</details>

<br>

## Approach 2: Disjoint Set Union (DSU/Union Find)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    array<int, 26> representative;
    
    // Returns the root representative of the component.
    int find(int x) {
        if (representative[x] == x) {
            return x;
        }
        
        return representative[x] = find(representative[x]);
    }
    
    // Perform union if x and y aren't in the same component.
    void performUnion(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) {
            return;
        }
        
        // Make the smaller character representative.
        if (x < y) {
            representative[y] = x;
        } else {
            representative[x] = y;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Make each character representative of itself.
        for (int i = 0; i < 26; i++) {
            representative[i] = i;
        }
        
        // Perform union merge for all the edges.
        for (int i = 0; i < s1.size(); i++) {
            performUnion(s1[i] - 'a', s2[i] - 'a');
        }
        
        string ans;
        // Create the answer string with final mappings.
        for (char c : baseStr) {
            ans += (char)(find(c - 'a') + 'a');
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
    int representative[] = new int[26];

    // Returns the root representative of the component.
    int find(int x) {
        if (representative[x] == x) {
            return x;
        }

        return representative[x] = find(representative[x]);
    }

    // Perform union if x and y aren't in the same component.
    void performUnion(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return;
        }

        // Make the smaller character representative.
        if (x < y) {
            representative[y] = x;
        } else {
            representative[x] = y;
        }
    }

    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        // Make each character representative of itself.
        for (int i = 0; i < 26; i++) {
            representative[i] = i;
        }

        // Perform union merge for all the edges.
        for (int i = 0; i < s1.length(); i++) {
            performUnion(s1.charAt(i) - 'a', s2.charAt(i) - 'a');
        }

        String ans = "";
        // Create the answer string with final mappings.
        for (char c : baseStr.toCharArray()) {
            ans += (char)(find(c - 'a') + 'a');
        }

        return ans;
    }
}
```

</details>
