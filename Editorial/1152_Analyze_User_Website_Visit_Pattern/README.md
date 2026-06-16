# 1152. Analyze User Website Visit Pattern

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/analyze-user-website-visit-pattern/)  
`Array` `Hash Table` `String` `Sorting`

**Problem Link:** [LeetCode 1152 - Analyze User Website Visit Pattern](https://leetcode.com/problems/analyze-user-website-visit-pattern/)

## Problem

You are given two string arrays username and website and an integer array timestamp. All the given arrays are of the same length and the tuple [username[i], website[i], timestamp[i]] indicates that the user username[i] visited the website website[i] at time timestamp[i].

A pattern is a list of three websites (not necessarily distinct).

- For example, ["home", "away", "love"], ["leetcode", "love", "leetcode"], and ["luffy", "luffy", "luffy"] are all patterns.

The score of a pattern is the number of users that visited all the websites in the pattern in the same order they appeared in the pattern.

- For example, if the pattern is ["home", "away", "love"], the score is the number of users x such that x visited "home" then visited "away" and visited "love" after that.
- Similarly, if the pattern is ["leetcode", "love", "leetcode"], the score is the number of users x such that x visited "leetcode" then visited "love" and visited "leetcode" one more time after that.
- Also, if the pattern is ["luffy", "luffy", "luffy"], the score is the number of users x such that x visited "luffy" three different times at different timestamps.

Return the pattern with the largest score. If there is more than one pattern with the same largest score, return the lexicographically smallest such pattern.

Note that the websites in a pattern do not need to be visited contiguously, they only need to be visited in the order they appeared in the pattern.

### Example 1

```text
Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation: The tuples in this example are:
["joe","home",1],["joe","about",2],["joe","career",3],["james","home",4],["james","cart",5],["james","maps",6],["james","home",7],["mary","home",8],["mary","about",9], and ["mary","career",10].
The pattern ("home", "about", "career") has score 2 (joe and mary).
The pattern ("home", "cart", "maps") has score 1 (james).
The pattern ("home", "cart", "home") has score 1 (james).
The pattern ("home", "maps", "home") has score 1 (james).
The pattern ("cart", "maps", "home") has score 1 (james).
The pattern ("home", "home", "home") has score 0 (no user visited home 3 times).
```

### Example 2

```text
Input: username = ["ua","ua","ua","ub","ub","ub"], timestamp = [1,2,3,4,5,6], website = ["a","b","a","a","b","c"]
Output: ["a","b","a"]
```

## Constraints

- 3 <= username.length <= 50
- 1 <= username[i].length <= 10
- timestamp.length == username.length
- 1 <= timestamp[i] <= 109
- website.length == username.length
- 1 <= website[i].length <= 10
- username[i] and website[i] consist of lowercase English letters.
- It is guaranteed that there is at least one user who visited at least three websites.
- All the tuples [username[i], timestamp[i], website[i]] are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1152. Analyze User Website Visit Pattern

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Brute Force | C++, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
struct Node {
    string name;
    int timestamp;
    string website;
};

bool compareNodes(const Node& a, const Node& b) {
    return a.timestamp < b.timestamp;
}

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username,
                                      vector<int>& timestamp,
                                      vector<string>& website) {
        vector<Node> nodes;
        for (size_t i = 0; i < username.size(); ++i) {
            nodes.push_back({username[i], timestamp[i], website[i]});
        }
        sort(nodes.begin(), nodes.end(), compareNodes);
        unordered_map<string, vector<Node>> userVisits;
        for (const auto& node : nodes) {
            userVisits[node.name].push_back(node);
        }

        map<vector<string>, int> route;
        for (const auto& entry : userVisits) {
            set<vector<string>> tmp;
            for (size_t i = 0; i < entry.second.size(); ++i) {
                for (size_t j = i + 1; j < entry.second.size(); ++j) {
                    for (size_t k = j + 1; k < entry.second.size(); ++k) {
                        tmp.insert({entry.second[i].website,
                                    entry.second[j].website,
                                    entry.second[k].website});
                    }
                }
            }
            for (const auto& path : tmp) {
                route[path]++;
            }
        }

        vector<string> result;
        int max = -1;
        for (const auto& entry : route) {
            if (entry.second > max ||
                (entry.second == max && entry.first < result)) {
                max = entry.second;
                result = entry.first;
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Node struct {
    name string
    timestamp int
    website string
}

func mostVisitedPattern(username []string, timestamp []int, website []string) []string {
    n := make([]Node, len(username))
    for i := 0; i < len(username); i++ {
        n[i] = Node{username[i], timestamp[i], website[i]}
    }
    sort.Slice(n, func(i, j int) bool {
        return n[i].timestamp < n[j].timestamp // Ensure the user's access records are orderly
    })
    m := make(map[string][]Node)
    for i := 0; i < len(n); i++ {
        m[n[i].name] = append(m[n[i].name], n[i]) // Retrieve all access records for each user
    }
    route := make(map[[3]string]int)
    for _, v := range m {
        tmp := make(map[[3]string]int)
        for i := 0; i < len(v); i++ {
            for j := i + 1; j < len(v); j++ {
                for k := j + 1; k < len(v); k++ {
                    tmp[[3]string{v[i].website, v[j].website, v[k].website}] = 1 // Retrieve each access path
                }
            }
        }
        for k1, v1 := range tmp {
            route[k1] += v1
        }
    }
    max := -1
    ret := [3]string{}
    for k, v := range route {
        if v > max {
            ret = k
            max = v
        } else if v == max {
            if k[0] < ret[0] || (k[0] == ret[0] && k[1] < ret[1] || (k[0] == ret[0] && k[1] == ret[1] && k[2] < ret[2])) {
                ret = k
            }
        }
    }
    return []string{ret[0], ret[1], ret[2]}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Node {

    String name;
    int timestamp;
    String website;

    Node(String name, int timestamp, String website) {
        this.name = name;
        this.timestamp = timestamp;
        this.website = website;
    }
}

class Solution {

    public List<String> mostVisitedPattern(
        String[] username,
        int[] timestamp,
        String[] website
    ) {
        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < username.length; i++) {
            nodes.add(new Node(username[i], timestamp[i], website[i]));
        }
        nodes.sort((a, b) -> a.timestamp - b.timestamp);
        Map<String, List<Node>> userVisits = new HashMap<>();
        for (Node node : nodes) {
            userVisits
                .computeIfAbsent(node.name, k -> new ArrayList<>())
                .add(node);
        }
        Map<List<String>, Integer> route = new HashMap<>();
        for (List<Node> visits : userVisits.values()) {
            Set<List<String>> tmp = new HashSet<>();
            for (int i = 0; i < visits.size(); i++) {
                for (int j = i + 1; j < visits.size(); j++) {
                    for (int k = j + 1; k < visits.size(); k++) {
                        List<String> path = Arrays.asList(
                            visits.get(i).website,
                            visits.get(j).website,
                            visits.get(k).website
                        );
                        tmp.add(path);
                    }
                }
            }
            for (List<String> path : tmp) {
                route.put(path, route.getOrDefault(path, 0) + 1);
            }
        }

        List<String> result = null;
        int max = -1;
        for (Map.Entry<List<String>, Integer> entry : route.entrySet()) {
            if (
                entry.getValue() > max ||
                (entry.getValue() == max &&
                    entry.getKey().toString().compareTo(result.toString()) < 0)
            ) {
                max = entry.getValue();
                result = entry.getKey();
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class Node {
    constructor(name, timestamp, website) {
        this.name = name;
        this.timestamp = timestamp;
        this.website = website;
    }
}

var mostVisitedPattern = function (username, timestamp, website) {
    let nodes = username.map(
        (name, i) => new Node(name, timestamp[i], website[i]),
    );
    nodes.sort((a, b) => a.timestamp - b.timestamp);

    let userVisits = {};
    for (let node of nodes) {
        if (!userVisits[node.name]) {
            userVisits[node.name] = [];
        }
        userVisits[node.name].push(node);
    }

    let route = {};
    for (let visits of Object.values(userVisits)) {
        let tmp = new Set();
        for (let i = 0; i < visits.length; i++) {
            for (let j = i + 1; j < visits.length; j++) {
                for (let k = j + 1; k < visits.length; k++) {
                    let path = [
                        visits[i].website,
                        visits[j].website,
                        visits[k].website,
                    ].join(",");
                    tmp.add(path);
                }
            }
        }
        for (let path of tmp) {
            route[path] = (route[path] || 0) + 1;
        }
    }

    let max = -1;
    let result = "";
    for (let path in route) {
        if (route[path] > max || (route[path] === max && path < result)) {
            max = route[path];
            result = path;
        }
    }
    return result.split(",");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Node:
    def __init__(self, name, timestamp, website):
        self.name = name
        self.timestamp = timestamp
        self.website = website


class Solution:
    def mostVisitedPattern(
        self, username: List[str], timestamp: List[int], website: List[str]
    ) -> List[str]:
        nodes = [
            Node(name, ts, site)
            for name, ts, site in zip(username, timestamp, website)
        ]
        nodes.sort(key=lambda x: x.timestamp)
        user_visits = defaultdict(list)
        for node in nodes:
            user_visits[node.name].append(node)

        route = defaultdict(int)
        for visits in user_visits.values():
            tmp = set()
            for i, j, k in combinations(range(len(visits)), 3):
                path = (visits[i].website, visits[j].website, visits[k].website)
                tmp.add(path)
            for path in tmp:
                route[path] += 1

        max_count = -1
        result = ()
        for path, count in route.items():
            if count > max_count or (count == max_count and path < result):
                max_count = count
                result = path
        return list(result)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class Node {
    name: string;
    timestamp: number;
    website: string;

    constructor(name: string, timestamp: number, website: string) {
        this.name = name;
        this.timestamp = timestamp;
        this.website = website;
    }
}

function mostVisitedPattern(
    username: string[],
    timestamp: number[],
    website: string[],
): string[] {
    let nodes = username.map(
        (name, i) => new Node(name, timestamp[i], website[i]),
    );
    nodes.sort((a, b) => a.timestamp - b.timestamp);

    let userVisits: { [key: string]: Node[] } = {};
    for (let node of nodes) {
        if (!userVisits[node.name]) {
            userVisits[node.name] = [];
        }
        userVisits[node.name].push(node);
    }

    let route: { [key: string]: number } = {};
    for (let visits of Object.values(userVisits)) {
        let tmp = new Set<string>();
        for (let i = 0; i < visits.length; i++) {
            for (let j = i + 1; j < visits.length; j++) {
                for (let k = j + 1; k < visits.length; k++) {
                    let path = [
                        visits[i].website,
                        visits[j].website,
                        visits[k].website,
                    ].join(",");
                    tmp.add(path);
                }
            }
        }
        for (let path of tmp) {
            route[path] = (route[path] || 0) + 1;
        }
    }

    let max = -1;
    let result = "";
    for (let path in route) {
        if (route[path] > max || (route[path] === max && path < result)) {
            max = route[path];
            result = path;
        }
    }
    return result.split(",");
}
```

</details>
