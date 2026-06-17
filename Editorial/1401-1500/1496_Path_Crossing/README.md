# 1496. Path Crossing

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/path-crossing/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 1496 - Path Crossing](https://leetcode.com/problems/path-crossing/)

## Problem

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

### Example 1

```text
Input: path = "NES"
Output: false
Explanation: Notice that the path doesn't cross any point more than once.
```

### Example 2

```text
Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
```

## Constraints

- 1 <= path.length <= 104
- path[i] is either 'N', 'S', 'E', or 'W'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1496. Path Crossing

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Set | C++, Java, Python3 |

## Approach: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> moves;
        moves['N'] = {0, 1};
        moves['S'] = {0, -1};
        moves['W'] = {-1, 0};
        moves['E'] = {1, 0};
        
        unordered_set<string> visited;
        visited.insert("0,0");
        
        int x = 0;
        int y = 0;
        
        for (char c : path) {
            pair<int, int> curr = moves[c];
            int dx = curr.first;
            int dy = curr.second;
            x += dx;
            y += dy;
            
            string hash = to_string(x) + "," + to_string(y);
            if (visited.find(hash) != visited.end()) {
                return true;
            }
            
            visited.insert(hash);
        }
        
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isPathCrossing(String path) {
        Map<Character, Pair<Integer, Integer>> moves = new HashMap();
        moves.put('N', new Pair(0, 1));
        moves.put('S', new Pair(0, -1));
        moves.put('W', new Pair(-1, 0));
        moves.put('E', new Pair(1, 0));
        
        Set<Pair<Integer, Integer>> visited = new HashSet();
        visited.add(new Pair(0, 0));
        
        int x = 0;
        int y = 0;
        
        for (Character c : path.toCharArray()) {
            Pair<Integer, Integer> curr = moves.get(c);
            int dx = curr.getKey();
            int dy = curr.getValue();
            x += dx;
            y += dy;
            
            Pair<Integer, Integer> pair = new Pair(x, y);
            if (visited.contains(pair)) {
                return true;
            }
            
            visited.add(pair);
        }
        
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        moves = {
            "N": (0, 1),
            "S": (0, -1),
            "W": (-1, 0),
            "E": (1, 0)
        }
        
        visited = {(0, 0)}
        x = 0
        y = 0

        for c in path:
            dx, dy = moves[c]
            x += dx
            y += dy
            
            if (x, y) in visited:
                return True

            visited.add((x, y))
        
        return False
```

</details>
