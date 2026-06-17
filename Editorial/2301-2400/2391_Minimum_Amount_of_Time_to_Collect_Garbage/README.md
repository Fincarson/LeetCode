# 2391. Minimum Amount of Time to Collect Garbage

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/)  
`Array` `String` `Prefix Sum`

**Problem Link:** [LeetCode 2391 - Minimum Amount of Time to Collect Garbage](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/)

## Problem

You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.

You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.

There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.

Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.

Return the minimum number of minutes needed to pick up all the garbage.

### Example 1

```text
Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21
Explanation:
The paper garbage truck:
1. Travels from house 0 to house 1
2. Collects the paper garbage at house 1
3. Travels from house 1 to house 2
4. Collects the paper garbage at house 2
Altogether, it takes 8 minutes to pick up all the paper garbage.
The glass garbage truck:
1. Collects the glass garbage at house 0
2. Travels from house 0 to house 1
3. Travels from house 1 to house 2
4. Collects the glass garbage at house 2
5. Travels from house 2 to house 3
6. Collects the glass garbage at house 3
Altogether, it takes 13 minutes to pick up all the glass garbage.
Since there is no metal garbage, we do not need to consider the metal garbage truck.
Therefore, it takes a total of 8 + 13 = 21 minutes to collect all the garbage.
```

### Example 2

```text
Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
Output: 37
Explanation:
The metal garbage truck takes 7 minutes to pick up all the metal garbage.
The paper garbage truck takes 15 minutes to pick up all the paper garbage.
The glass garbage truck takes 15 minutes to pick up all the glass garbage.
It takes a total of 7 + 15 + 15 = 37 minutes to collect all the garbage.
```

## Constraints

- 2 <= garbage.length <= 105
- garbage[i] consists of only the letters 'M', 'P', and 'G'.
- 1 <= garbage[i].length <= 10
- travel.length == garbage.length - 1
- 1 <= travel[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2391. Minimum Amount of Time to Collect Garbage

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| HashMap | C++, Java, Python3 |
| HashMap and In-place Modification | C++, Java, Python3 |
| Iterate in Reverse | C++, Java, Python3 |

## Approach 1: HashMap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // Vector to store the prefix sum in travel.
        vector<int> prefixSum(travel.size() + 1, 0);
        prefixSum[1] = travel[0];
        for (int i = 1; i < travel.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + travel[i];
        }

        // Map to store garbage type to the last house index.
        unordered_map<char, int> garbageLastPos;

        // Map to store the total count of each type of garbage in all houses.
        unordered_map<char, int> garbageCount;
        for (int i = 0; i < garbage.size(); i++) {
            for (char c : garbage[i]) {
                garbageLastPos[c] = i;
                garbageCount[c]++;
            }
        }

        char garbageTypes[3] = {'M', 'P', 'G'};
        int ans = 0;
        for (char c : garbageTypes) {
            // Add only if there is at least one unit of this garbage.
            if (garbageCount[c]) {
                ans += prefixSum[garbageLastPos[c]] + garbageCount[c];
            }
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

    public int garbageCollection(String[] garbage, int[] travel) {
        // Array to store the prefix sum in travel.
        int[] prefixSum = new int[travel.length + 1];
        prefixSum[1] = travel[0];
        for (int i = 1; i < travel.length; i++) {
            prefixSum[i + 1] = prefixSum[i] + travel[i];
        }

        // Map to store garbage type to the last house index.
        Map<Character, Integer> garbageLastPos = new HashMap<
            Character,
            Integer
        >();

        // Map to store the total count of each type of garbage in all houses.
        Map<Character, Integer> garbageCount = new HashMap<
            Character,
            Integer
        >();
        for (int i = 0; i < garbage.length; i++) {
            for (char c : garbage[i].toCharArray()) {
                garbageLastPos.put(c, i);
                garbageCount.put(c, garbageCount.getOrDefault(c, 0) + 1);
            }
        }

        String garbageTypes = "MPG";
        int ans = 0;
        for (char c : garbageTypes.toCharArray()) {
            // Add only if there is at least one unit of this garbage.
            if (garbageCount.containsKey(c)) {
                ans += prefixSum[garbageLastPos.get(c)] + garbageCount.get(c);
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        # List to store the prefix sum in travel.
        prefix_sum = [0] * (len(travel) + 1)
        prefix_sum[1] = travel[0]
        for i in range(1, len(travel)):
            prefix_sum[i + 1] = prefix_sum[i] + travel[i]

        # Dictionary to store garbage type to the last house index.
        garbage_last_pos = {}

        # Dictionary to store the total count of each type of garbage in all houses.
        garbage_count = {}
        for i in range(len(garbage)):
            for c in garbage[i]:
                garbage_last_pos[c] = i
                garbage_count[c] = garbage_count.get(c, 0) + 1

        garbage_types = "MPG"
        ans = 0
        for c in garbage_types:
            # Add only if there is at least one unit of this garbage.
            if c in garbage_count:
                ans += prefix_sum[garbage_last_pos[c]] + garbage_count[c]

        return ans
```

</details>

<br>

## Approach 2: HashMap and In-place Modification

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // Store the prefix sum in travel itself.
        for (int i = 1; i < travel.size(); i++) {
            travel[i] = travel[i - 1] + travel[i];
        }

        // Map to store garbage type to the last house index.
        unordered_map<char, int> garbageLastPos;
        int ans = 0;
        for (int i = 0; i < garbage.size(); i++) {
            for (char c : garbage[i]) {
                garbageLastPos[c] = i;
            }
            ans += garbage[i].size();
        }

        string garbageTypes = "MPG";
        for (char c : garbageTypes) {
            // No travel time is required if the last house is at index 0.
            ans += (garbageLastPos[c] == 0 ? 0 : travel[garbageLastPos[c] - 1]);
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

    public int garbageCollection(String[] garbage, int[] travel) {
        // Store the prefix sum in travel itself.
        for (int i = 1; i < travel.length; i++) {
            travel[i] = travel[i - 1] + travel[i];
        }

        // Map to store garbage type to the last house index.
        Map<Character, Integer> garbageLastPos = new HashMap<
            Character,
            Integer
        >();
        int ans = 0;
        for (int i = 0; i < garbage.length; i++) {
            for (char c : garbage[i].toCharArray()) {
                garbageLastPos.put(c, i);
            }
            ans += garbage[i].length();
        }

        String garbageTypes = "MPG";
        for (char c : garbageTypes.toCharArray()) {
            // No travel time is required if the last house is at index 0.
            ans +=
            (garbageLastPos.getOrDefault(c, 0) == 0
                    ? 0
                    : travel[garbageLastPos.get(c) - 1]);
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def garbageCollection(self, garbage, travel):
        # Store the prefix sum in travel itself.
        for i in range(1, len(travel)):
            travel[i] = travel[i - 1] + travel[i]

        # Dictionary to store garbage type to the last house index.
        garbageLastPos = {}
        ans = 0
        for i in range(len(garbage)):
            for c in garbage[i]:
                garbageLastPos[c] = i
            ans += len(garbage[i])

        garbageTypes = "MPG"
        for c in garbageTypes:
            # No travel time is required if the last house is at index 0.
            ans += (
                0
                if garbageLastPos.get(c, 0) == 0
                else travel[garbageLastPos.get(c) - 1]
            )

        return ans
```

</details>

<br>

## Approach 3: Iterate in Reverse

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int M = 0, P = 0, G = 0;
        int ans = garbage[0].size();

        for (int i = garbage.size() - 1; i > 0; i--) {
            for (char ch : garbage[i]) {
                if (ch == 'M') {
                    M = 1;
                } else if (ch == 'P') {
                    P = 1;
                } else {
                    G = 1;
                }
            }

            ans += travel[i - 1] * (M + P + G) + garbage[i].size();
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

    public int garbageCollection(String[] garbage, int[] travel) {
        Boolean M = false, P = false, G = false;
        int ans = garbage[0].length();

        for (int i = garbage.length - 1; i > 0; i--) {
            M |= garbage[i].contains("M");
            P |= garbage[i].contains("P");
            G |= garbage[i].contains("G");
            ans +=
            travel[i - 1] * ((M ? 1 : 0) + (P ? 1 : 0) + (G ? 1 : 0)) +
            garbage[i].length();
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def garbageCollection(self, garbage, travel):
        M, P, G = False, False, False
        ans = len(garbage[0])

        for i in range(len(garbage) - 1, 0, -1):
            M |= "M" in garbage[i]
            P |= "P" in garbage[i]
            G |= "G" in garbage[i]
            ans += travel[i - 1] * (int(M) + int(P) + int(G)) + len(garbage[i])

        return ans
```

</details>
