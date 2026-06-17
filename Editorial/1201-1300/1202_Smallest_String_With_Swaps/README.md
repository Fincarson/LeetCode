# 1202. Smallest String With Swaps

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/smallest-string-with-swaps/)  
`Array` `Hash Table` `String` `Depth-First Search` `Breadth-First Search` `Union-Find` `Sorting`

**Problem Link:** [LeetCode 1202 - Smallest String With Swaps](https://leetcode.com/problems/smallest-string-with-swaps/)

## Problem

You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

### Example 1

```text
Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
```

### Example 2

```text
Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
```

### Example 3

```text
Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination:
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
```

## Constraints

- 1 <= s.length <= 10^5
- 0 <= pairs.length <= 10^5
- 0 <= pairs[i][0], pairs[i][1] < s.length
- s only contains lower case English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimize Hamming Distance After Swap Operations](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Process Restricted Friend Requests](https://leetcode.com/problems/process-restricted-friend-requests/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Lexicographically Smallest Beautiful String](https://leetcode.com/problems/lexicographically-smallest-beautiful-string/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Make Lexicographically Smallest Array by Swapping Elements](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1202. Smallest String With Swaps

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C++, Java |
| Disjoint Set Union (DSU) | C++, Java |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Maximum number of vertices
    static const int N = 100001;
    vector<int> adj[N];
    bool visited[N];
    
    void DFS(string& s, int vertex, vector<char>& characters, vector<int>& indices) {
        // Add the character and index to the list
        characters.push_back(s[vertex]);
        indices.push_back(vertex);
        
        visited[vertex] = true;
        
        // Traverse the adjacents
        for (int adjacent : adj[vertex]) {
            if (!visited[adjacent]) {
                DFS(s, adjacent, characters, indices);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // Build the adjacency list
        for (vector<int> edge : pairs) {
            int source = edge[0];
            int destination = edge[1];
            
            // Undirected edge
            adj[source].push_back(destination);
            adj[destination].push_back(source);
        }
        
        for (int vertex = 0; vertex < s.size(); vertex++) {
            // If not covered in the DFS yet
            if (!visited[vertex]) {
                vector<char> characters;
                vector<int> indices;
                
                DFS(s, vertex, characters, indices);
                // Sort the list of characters and indices
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());

                // Store the sorted characters corresponding to the index
                for (int index = 0; index < characters.size(); index++) {
                    s[indices[index]] = characters[index];
                }
            }
        }
        
        return s;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Maximum number of vertices
    final static int N = 100001;
    boolean[] visited = new boolean[N];
    List<Integer>[] adj = new ArrayList[N]; 
    
    private void DFS(String s, int vertex, List<Character> characters, List<Integer> indices) {
        // Add the character and index to the list
        characters.add(s.charAt(vertex));
        indices.add(vertex);
        
        visited[vertex] = true;
        
        // Traverse the adjacents
        for (int adjacent : adj[vertex]) {
            if (!visited[adjacent]) {
                DFS(s, adjacent, characters, indices);
            }
        }
    }
    
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
         for (int i = 0; i < s.length(); i++) {
            adj[i] = new ArrayList<Integer>();
        }
        
        // Build the adjacency list
        for (List<Integer> edge : pairs) {
            int source = edge.get(0);
            int destination = edge.get(1);
            
            // Undirected edge
            adj[source].add(destination);
            adj[destination].add(source);
        }
        
        char[] answer = new char[s.length()];
        for (int vertex = 0; vertex < s.length(); vertex++) {
            // If not covered in the DFS yet
            if (!visited[vertex]) {
                List<Character> characters = new ArrayList<>();
                List<Integer> indices = new ArrayList<>();
                
                DFS(s, vertex, characters, indices);
                // Sort the list of characters and indices
                Collections.sort(characters);
                Collections.sort(indices);

                // Store the sorted characters corresponding to the index
                for (int index = 0; index < characters.size(); index++) {
                    answer[indices.get(index)] = characters.get(index);
                }
            }
        }
        return new String(answer);
    }
}
```

</details>

<br>

## Approach 2: Disjoint Set Union (DSU)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
public:
    // Initialize the array root and rank
    // Each vertex is representative of itself with rank 1
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    // Get the root of a vertex
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    // Perform the union of two components
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] >= rank[rootY]) {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            } else {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        
        // Iterate over the edges
        for (vector<int> edge : pairs) {
            int source = edge[0];
            int destination = edge[1];
            
            // Perform the union of end points
            uf.unionSet(source, destination);
        }
        
        
        unordered_map<int, vector<int>> rootToComponent;
        // Group the vertices that are in the same component
        for (int vertex = 0; vertex < s.size(); vertex++) {
            int root = uf.find(vertex);
            // Add the vertices corresponding to the component root
            rootToComponent[root].push_back(vertex);
        }
        
        // String to store the answer
        string smallestString(s.length(), ' ');
        // Iterate over each component
        for (auto component : rootToComponent) {
            vector<int> indices = component.second;
            
            // Sort the characters in the group
            vector<char> characters;
            for (int index : indices) {
                characters.push_back(s[index]);
            }
            sort(characters.begin(), characters.end());
            
            // Store the sorted characters
            for (int index = 0; index < indices.size(); index++) {
                smallestString[indices[index]] = characters[index];
            }
        }
        
        return smallestString;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        UnionFind uf = new UnionFind(s.length());

        // Iterate over the edges
        for (List<Integer> edge : pairs) {
            int source = edge.get(0);
            int destination = edge.get(1);
            
            // Perform the union of end points
            uf.union(source, destination);
        }
        
        Map<Integer, List<Integer>> rootToComponent = new HashMap<>();
        // Group the vertices that are in the same component
        for (int vertex = 0; vertex < s.length(); vertex++) {
            int root = uf.find(vertex);
            // Add the vertices corresponding to the component root
            rootToComponent.putIfAbsent(root, new ArrayList<>());
            rootToComponent.get(root).add(vertex);
        }
        
        // String to store the answer
        char[] smallestString = new char[s.length()];
        // Iterate over each component
        for (List<Integer> indices : rootToComponent.values()) {
            // Sort the characters in the group
            List<Character> characters = new ArrayList<>();
            for (int index : indices) {
                characters.add(s.charAt(index));
            }
            Collections.sort(characters);
            
            // Store the sorted characters
            for (int index = 0; index < indices.size(); index++) {
                smallestString[indices.get(index)] = characters.get(index);
            }
        }
        
        return new String(smallestString);
    }
}

class UnionFind {
    private int[] root;
    private int[] rank;

    // Initialize the array root and rank
    // Each vertex is representative of itself with rank 1
    public UnionFind(int size) {
        root = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    // Get the root of a vertex
    public int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    // Perform the union of two components
    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] >= rank[rootY]) {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            } else {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
        }
    }
}
```

</details>
