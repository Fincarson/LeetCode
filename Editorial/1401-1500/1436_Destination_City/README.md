# 1436. Destination City

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/destination-city/)  
`Array` `Hash Table` `String`

**Problem Link:** [LeetCode 1436 - Destination City](https://leetcode.com/problems/destination-city/)

## Problem

You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

### Example 1

```text
Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo"
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
```

### Example 2

```text
Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are:
"D" -> "B" -> "C" -> "A".
"B" -> "C" -> "A".
"C" -> "A".
"A".
Clearly the destination city is "A".
```

### Example 3

```text
Input: paths = [["A","Z"]]
Output: "Z"
```

## Constraints

- 1 <= paths.length <= 100
- paths[i].length == 2
- 1 <= cityAi.length, cityBi.length <= 10
- cityAi != cityBi
- All strings consist of lowercase and uppercase English letters and the space character.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1436. Destination City

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Hash Set | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        for (int i = 0; i < paths.size(); i++) {
            string candidate = paths[i][1];
            bool good = true;
            
            for (int j = 0; j < paths.size(); j++) {
                if (paths[j][0] == candidate) {
                    good = false;
                    break;
                }
            }

            if (good) {
                return candidate;
            }
        }
        
        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String destCity(List<List<String>> paths) {
        for (int i = 0; i < paths.size(); i++) {
            String candidate = paths.get(i).get(1);
            boolean good = true;
            
            for (int j = 0; j < paths.size(); j++) {
                if (paths.get(j).get(0).equals(candidate)) {
                    good = false;
                    break;
                }
            }

            if (good) {
                return candidate;
            }
        }
        
        return "";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        for i in range(len(paths)):
            candidate = paths[i][1]
            good = True
            
            for j in range(len(paths)):
                if paths[j][0] == candidate:
                    good = False
                    break
                
            if good:
                return candidate
            
        return ""
```

</details>

<br>

## Approach 2: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> hasOutgoing;
        for (int i = 0; i < paths.size(); i++) {
            hasOutgoing.insert(paths[i][0]);
        }
        
        for (int i = 0; i < paths.size(); i++) {
            string candidate = paths[i][1];
            if (hasOutgoing.find(candidate) == hasOutgoing.end()) {
                return candidate;
            }
        }
        
        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> hasOutgoing = new HashSet();
        for (int i = 0; i < paths.size(); i++) {
            hasOutgoing.add(paths.get(i).get(0));
        }
        
        for (int i = 0; i < paths.size(); i++) {
            String candidate = paths.get(i).get(1);
            if (!hasOutgoing.contains(candidate)) {
                return candidate;
            }
        }
        
        return "";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        has_outgoing = set()
        for i in range(len(paths)):
            has_outgoing.add(paths[i][0])
        
        for i in range(len(paths)):
            candidate = paths[i][1]
            if candidate not in has_outgoing:
                return candidate
        
        return ""
```

</details>
