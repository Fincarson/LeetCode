# 2306. Naming a Company

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/naming-a-company/)  
`Array` `Hash Table` `String` `Bit Manipulation` `Enumeration`

**Problem Link:** [LeetCode 2306 - Naming a Company](https://leetcode.com/problems/naming-a-company/)

## Problem

You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

Return the number of distinct valid names for the company.

### Example 1

```text
Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.
```

### Example 2

```text
Input: ideas = ["lack","back"]
Output: 0
Explanation: There are no valid selections. Therefore, 0 is returned.
```

## Constraints

- 2 <= ideas.length <= 5 * 104
- 1 <= ideas[i].length <= 10
- ideas[i] consists of lowercase English letters.
- All the strings in ideas are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2306. Naming a Company

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Group words by their initials | C++, Java, Python3 |

## Approach 1: Group words by their initials

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // Group idea by their initials.
        unordered_set<string> initialGroup[26];
        for (auto& idea : ideas)
            initialGroup[idea[0] - 'a'].insert(idea.substr(1));
        
        // Calculate number of valid names from every pair of groups.
        long long answer = 0;
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                // Get the number of mutual suffixes.
                int numOfMutual = 0;
                for (auto& ideaA : initialGroup[i]) {
                    if (initialGroup[j].count(ideaA)) {
                        numOfMutual++;
                    }
                }

                // Valid names are only from distinct suffixes in both groups.
                // Since we can swap a with b and swap b with a to create two valid names, multiple answer by 2.
                answer += 2LL * (initialGroup[i].size() - numOfMutual) * (initialGroup[j].size() - numOfMutual);
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long distinctNames(String[] ideas) {
        // Group idea by their initials.
        HashSet<String>[] initialGroup = new HashSet[26];
        for (int i = 0; i < 26; ++i) {
            initialGroup[i] = new HashSet<>();
        }
        for (String idea : ideas) {
            initialGroup[idea.charAt(0) - 'a'].add(idea.substring(1));
        }
        
        // Calculate number of valid names from every pair of groups.
        long answer = 0;
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                // Get the number of mutual suffixes.
                long numOfMutual = 0;
                for (String ideaA : initialGroup[i]) {
                    if (initialGroup[j].contains(ideaA)) {
                        numOfMutual++;
                    }
                }

                // Valid names are only from distinct suffixes in both groups.
                // Since we can swap a with b and swap b with a to create two valid names, multiple answer by 2.
                answer += 2 * (initialGroup[i].size() - numOfMutual) * (initialGroup[j].size() - numOfMutual);
            }
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        # Group idea by their initials.
        initial_groups = [set() for _ in range(26)]
        for idea in ideas:
            initial_groups[ord(idea[0]) - ord('a')].add(idea[1:])
        
        answer = 0
        # Calculate number of valid names from every pair of groups.
        for i in range(25):
            for j in range(i + 1, 26):
                # Get the number of mutual suffixes.
                num_of_mutual = len(initial_groups[i] & initial_groups[j]) 
                
                # Valid names are only from distinct suffixes in both groups.
                # Since we can swap a with b and swap b with a to create two valid names, multiple answer by 2.
                answer += 2 * (len(initial_groups[i]) - num_of_mutual) * (len(initial_groups[j]) - num_of_mutual)
                
        return answer
```

</details>
