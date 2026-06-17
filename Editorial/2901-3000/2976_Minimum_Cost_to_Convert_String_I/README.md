# 2976. Minimum Cost to Convert String I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-cost-to-convert-string-i/)  
`Array` `String` `Graph Theory` `Shortest Path`

**Problem Link:** [LeetCode 2976 - Minimum Cost to Convert String I](https://leetcode.com/problems/minimum-cost-to-convert-string-i/)

## Problem

You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

### Example 1

```text
Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
```

### Example 2

```text
Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
```

### Example 3

```text
Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.
```

## Constraints

- 1 <= source.length == target.length <= 105
- source, target consist of lowercase English letters.
- 1 <= cost.length == original.length == changed.length <= 2000
- original[i], changed[i] are lowercase English letters.
- 1 <= cost[i] <= 106
- original[i] != changed[i]

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Can Convert String in K Moves](https://leetcode.com/problems/can-convert-string-in-k-moves/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Moves to Convert String](https://leetcode.com/problems/minimum-moves-to-convert-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2976. Minimum Cost to Convert String I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dijkstra's Algorithm | C++, Java, Python3 |
| Floyd-Warshall Algorithm | C++, Java, Python3 |

## Approach 1: Dijkstra's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        // Create a graph representation of character conversions
        vector<vector<pair<int, int>>> adjacencyList(26);

        // Populate the adjacency list with character conversions
        int conversionCount = original.size();
        for (int i = 0; i < conversionCount; i++) {
            adjacencyList[original[i] - 'a'].push_back(
                {changed[i] - 'a', cost[i]});
        }

        // Calculate shortest paths for all possible character conversions
        vector<vector<long long>> minConversionCosts(26, vector<long long>(26));
        for (int i = 0; i < 26; i++) {
            minConversionCosts[i] = dijkstra(i, adjacencyList);
        }

        // Calculate the total cost of converting source to target
        long long totalCost = 0;
        int stringLength = source.length();
        for (int i = 0; i < stringLength; i++) {
            if (source[i] != target[i]) {
                long long charConversionCost =
                    minConversionCosts[source[i] - 'a'][target[i] - 'a'];
                if (charConversionCost == -1) {
                    return -1;  // Conversion not possible
                }
                totalCost += charConversionCost;
            }
        }
        return totalCost;
    }

private:
    // Find minimum conversion costs from a starting character to all other
    // characters
    vector<long long> dijkstra(
        int startChar, const vector<vector<pair<int, int>>>& adjacencyList) {
        // Priority queue to store characters with their conversion cost, sorted
        // by cost
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            priorityQueue;

        // Initialize the starting character with cost 0
        priorityQueue.push({0, startChar});

        // Array to store the minimum conversion cost to each character
        vector<long long> minCosts(26, -1);

        while (!priorityQueue.empty()) {
            auto [currentCost, currentChar] = priorityQueue.top();
            priorityQueue.pop();

            if (minCosts[currentChar] != -1 &&
                minCosts[currentChar] < currentCost)
                continue;

            // Explore all possible conversions from the current character
            for (auto& [targetChar, conversionCost] :
                 adjacencyList[currentChar]) {
                long long newTotalCost = currentCost + conversionCost;

                // If we found a cheaper conversion, update its cost
                if (minCosts[targetChar] == -1 ||
                    newTotalCost < minCosts[targetChar]) {
                    minCosts[targetChar] = newTotalCost;
                    // Add the updated conversion to the queue for further
                    // exploration
                    priorityQueue.push({newTotalCost, targetChar});
                }
            }
        }
        // Return the array of minimum conversion costs from the starting
        // character to all others
        return minCosts;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minimumCost(
        String source,
        String target,
        char[] original,
        char[] changed,
        int[] cost
    ) {
        // Create a graph representation of character conversions
        List<int[]>[] adjacencyList = new List[26];
        for (int i = 0; i < 26; i++) {
            adjacencyList[i] = new ArrayList<>();
        }

        // Populate the adjacency list with character conversions
        int conversionCount = original.length;
        for (int i = 0; i < conversionCount; i++) {
            adjacencyList[original[i] - 'a'].add(
                    new int[] { changed[i] - 'a', cost[i] }
                );
        }

        // Calculate shortest paths for all possible character conversions
        long[][] minConversionCosts = new long[26][26];
        for (int i = 0; i < 26; i++) {
            minConversionCosts[i] = dijkstra(i, adjacencyList);
        }

        // Calculate the total cost of converting source to target
        long totalCost = 0;
        int stringLength = source.length();
        for (int i = 0; i < stringLength; i++) {
            if (source.charAt(i) != target.charAt(i)) {
                long charConversionCost =
                    minConversionCosts[source.charAt(i) - 'a'][target.charAt(
                            i
                        ) -
                        'a'];
                if (charConversionCost == -1) {
                    return -1; // Conversion not possible
                }
                totalCost += charConversionCost;
            }
        }
        return totalCost;
    }

    // Find minimum conversion costs from a starting character to all other characters
    private long[] dijkstra(int startChar, List<int[]>[] adjacencyList) {
        // Priority queue to store characters with their conversion cost, sorted by cost
        PriorityQueue<Pair<Long, Integer>> priorityQueue = new PriorityQueue<>(
            (e1, e2) -> Long.compare(e1.getKey(), e2.getKey())
        );

        // Initialize the starting character with cost 0
        priorityQueue.add(new Pair<>(0L, startChar));

        // Array to store the minimum conversion cost to each character
        long[] minCosts = new long[26];
        // Initialize all costs to -1 (unreachable)
        Arrays.fill(minCosts, -1L);

        while (!priorityQueue.isEmpty()) {
            Pair<Long, Integer> currentPair = priorityQueue.poll();
            long currentCost = currentPair.getKey();
            int currentChar = currentPair.getValue();

            if (
                minCosts[currentChar] != -1L &&
                minCosts[currentChar] < currentCost
            ) continue;

            // Explore all possible conversions from the current character
            for (int[] conversion : adjacencyList[currentChar]) {
                int targetChar = conversion[0];
                long conversionCost = conversion[1];
                long newTotalCost = currentCost + conversionCost;

                // If we found a cheaper conversion, update its cost
                if (
                    minCosts[targetChar] == -1L ||
                    newTotalCost < minCosts[targetChar]
                ) {
                    minCosts[targetChar] = newTotalCost;
                    // Add the updated conversion to the queue for further exploration
                    priorityQueue.add(new Pair<>(newTotalCost, targetChar));
                }
            }
        }
        // Return the array of minimum conversion costs from the starting character to all others
        return minCosts;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: List[str],
        changed: List[str],
        cost: List[int],
    ) -> int:
        # Create a graph representation of character conversions
        adjacency_list = [[] for _ in range(26)]

        # Populate the adjacency list with character conversions
        conversion_count = len(original)
        for i in range(conversion_count):
            adjacency_list[ord(original[i]) - ord("a")].append(
                (ord(changed[i]) - ord("a"), cost[i])
            )

        # Calculate shortest paths for all possible character conversions
        min_conversion_costs = [
            self._dijkstra(i, adjacency_list) for i in range(26)
        ]

        # Calculate the total cost of converting source to target
        total_cost = 0
        for s, t in zip(source, target):
            if s != t:
                char_conversion_cost = min_conversion_costs[ord(s) - ord("a")][
                    ord(t) - ord("a")
                ]
                if char_conversion_cost == float("inf"):
                    return -1  # Conversion not possible
                total_cost += char_conversion_cost

        return total_cost

    def _dijkstra(
        self, start_char: int, adjacency_list: List[List[tuple]]
    ) -> List[int]:
        # Priority queue to store characters with their conversion cost, sorted by cost
        priority_queue = [(0, start_char)]

        # List to store the minimum conversion cost to each character
        min_costs = [float("inf")] * 26

        while priority_queue:
            current_cost, current_char = heapq.heappop(priority_queue)

            if min_costs[current_char] != float("inf"):
                continue

            min_costs[current_char] = current_cost

            # Explore all possible conversions from the current character
            for target_char, conversion_cost in adjacency_list[current_char]:
                new_total_cost = current_cost + conversion_cost

                # If we found a cheaper conversion, update its cost
                if min_costs[target_char] == float("inf"):
                    heapq.heappush(
                        priority_queue, (new_total_cost, target_char)
                    )

        # Return the list of minimum conversion costs from the starting character to all others
        return min_costs
```

</details>

<br>

## Approach 2: Floyd-Warshall Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        // Initialize result to store the total minimum cost
        long long totalCost = 0;

        // Initialize a 2D vector to store the minimum transformation cost
        // between any two characters
        vector<vector<long long>> minCost(26, vector<long long>(26, INT_MAX));

        // Fill the initial transformation costs from the given original,
        // changed, and cost arrays
        for (int i = 0; i < original.size(); ++i) {
            int startChar = original[i] - 'a';
            int endChar = changed[i] - 'a';
            minCost[startChar][endChar] =
                min(minCost[startChar][endChar], (long long)cost[i]);
        }

        // Use Floyd-Warshall algorithm to find the shortest path between any
        // two characters
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    minCost[i][j] =
                        min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }

        // Calculate the total minimum cost to transform the source string to
        // the target string
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) {
                continue;
            }
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';

            // If the transformation is not possible, return -1
            if (minCost[sourceChar][targetChar] >= INT_MAX) {
                return -1;
            }
            totalCost += minCost[sourceChar][targetChar];
        }

        return totalCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minimumCost(
        String source,
        String target,
        char[] original,
        char[] changed,
        int[] cost
    ) {
        // Initialize result to store the total minimum cost
        long totalCost = 0;

        // Initialize a 2D array to store the minimum conversion cost
        // between any two characters
        long[][] minCost = new long[26][26];
        for (long[] row : minCost) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // Fill the initial conversion costs from the given original,
        // changed, and cost arrays
        for (int i = 0; i < original.length; ++i) {
            int startChar = original[i] - 'a';
            int endChar = changed[i] - 'a';
            minCost[startChar][endChar] = Math.min(
                minCost[startChar][endChar],
                (long) cost[i]
            );
        }

        // Use Floyd-Warshall algorithm to find the shortest path between any
        // two characters
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    minCost[i][j] = Math.min(
                        minCost[i][j],
                        minCost[i][k] + minCost[k][j]
                    );
                }
            }
        }

        // Calculate the total minimum cost to transform the source string to
        // the target string
        for (int i = 0; i < source.length(); ++i) {
            if (source.charAt(i) == target.charAt(i)) {
                continue;
            }
            int sourceChar = source.charAt(i) - 'a';
            int targetChar = target.charAt(i) - 'a';

            // If the transformation is not possible, return -1
            if (minCost[sourceChar][targetChar] >= Integer.MAX_VALUE) {
                return -1;
            }
            totalCost += minCost[sourceChar][targetChar];
        }

        return totalCost;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: List[str],
        changed: List[str],
        cost: List[int],
    ) -> int:
        # Initialize result to store the total minimum cost
        total_cost = 0

        # Initialize a 2D list to store the minimum transformation cost
        # between any two characters
        min_cost = [[float("inf")] * 26 for _ in range(26)]

        # Fill the initial transformation costs from the given original,
        # changed, and cost arrays
        for orig, chg, cst in zip(original, changed, cost):
            start_char = ord(orig) - ord("a")
            end_char = ord(chg) - ord("a")
            min_cost[start_char][end_char] = min(
                min_cost[start_char][end_char], cst
            )

        # Use Floyd-Warshall algorithm to find the shortest path between any
        # two characters
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    min_cost[i][j] = min(
                        min_cost[i][j], min_cost[i][k] + min_cost[k][j]
                    )

        # Calculate the total minimum cost to transform the source string to
        # the target string
        for src, tgt in zip(source, target):
            if src == tgt:
                continue
            source_char = ord(src) - ord("a")
            target_char = ord(tgt) - ord("a")

            # If the transformation is not possible, return -1
            if min_cost[source_char][target_char] == float("inf"):
                return -1
            total_cost += min_cost[source_char][target_char]

        return total_cost
```

</details>
