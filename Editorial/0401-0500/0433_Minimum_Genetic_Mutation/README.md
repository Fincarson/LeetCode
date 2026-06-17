# 433. Minimum Genetic Mutation

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-genetic-mutation/)  
`Hash Table` `String` `Breadth-First Search`

**Problem Link:** [LeetCode 433 - Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation/)

## Problem

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

- For example, "AACCGGTT" --> "AACCGGTA" is one mutation.

There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

### Example 1

```text
Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
```

### Example 2

```text
Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
```

## Constraints

- 0 <= bank.length <= 10
- startGene.length == endGene.length == bank[i].length == 8
- startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Ladder](https://leetcode.com/problems/word-ladder/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 433. Minimum Genetic Mutation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: BFS (Breadth-First Search) | C++, Java, Python3 |

## Approach: BFS (Breadth-First Search)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> queue;
        unordered_set<string> seen;
        queue.push(start);
        seen.insert(start);
        
        int steps = 0;
        while (!queue.empty()) {
            int nodesInQueue = queue.size();
            
            for (int j = 0; j < nodesInQueue; j++) {
                string node = queue.front();
                queue.pop();

                if (node == end) {
                    return steps;
                }
                
                for (char c: "ACGT") {
                    for (int i = 0; i < node.size(); i++) {
                        string neighbor = node;
                        neighbor[i] = c;
                        if (!seen.count(neighbor) && find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            queue.push(neighbor);
                            seen.insert(neighbor);
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minMutation(String start, String end, String[] bank) {
        Queue<String> queue = new LinkedList<>();
        Set<String> seen = new HashSet<>();
        queue.add(start);
        seen.add(start);
        
        int steps = 0;
        
        while (!queue.isEmpty()) {
            int nodesInQueue = queue.size();
            for (int j = 0; j < nodesInQueue; j++) {
                String node = queue.remove();
                if (node.equals(end)) {
                    return steps;
                }

                for (char c: new char[] {'A', 'C', 'G', 'T'}) {
                    for (int i = 0; i < node.length(); i++) {
                        String neighbor = node.substring(0, i) + c + node.substring(i + 1);
                        if (!seen.contains(neighbor) && Arrays.asList(bank).contains(neighbor)) {
                            queue.add(neighbor);
                            seen.add(neighbor);
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        queue = deque([(start, 0)])
        seen = {start}
        
        while queue:
            node, steps = queue.popleft()
            if node == end:
                return steps

            for c in "ACGT":
                for i in range(len(node)):
                    neighbor = node[:i] + c + node[i + 1:]
                    if neighbor not in seen and neighbor in bank:
                        queue.append((neighbor, steps + 1))
                        seen.add(neighbor)

        return -1
```

</details>
