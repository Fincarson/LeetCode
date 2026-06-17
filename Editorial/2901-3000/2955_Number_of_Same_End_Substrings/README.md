# 2955. Number of Same-End Substrings

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/number-of-same-end-substrings/)  
`Array` `Hash Table` `String` `Counting` `Prefix Sum`

**Problem Link:** [LeetCode 2955 - Number of Same-End Substrings](https://leetcode.com/problems/number-of-same-end-substrings/)

## Problem

You are given a 0-indexed string s, and a 2D array of integers queries, where queries[i] = [li, ri] indicates a substring of s starting from the index li and ending at the index ri (both inclusive), i.e. s[li..ri].

Return an array ans where ans[i] is the number of same-end substrings of queries[i].

A 0-indexed string t of length n is called same-end if it has the same character at both of its ends, i.e., t[0] == t[n - 1].

A substring is a contiguous non-empty sequence of characters within a string.

### Example 1

```text
Input: s = "abcaab", queries = [[0,0],[1,4],[2,5],[0,5]]
Output: [1,5,5,10]
Explanation: Here is the same-end substrings of each query:
1st query: s[0..0] is "a" which has 1 same-end substring: "a".
2nd query: s[1..4] is "bcaa" which has 5 same-end substrings: "bcaa", "bcaa", "bcaa", "bcaa", "bcaa".
3rd query: s[2..5] is "caab" which has 5 same-end substrings: "caab", "caab", "caab", "caab", "caab".
4th query: s[0..5] is "abcaab" which has 10 same-end substrings: "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab".
```

### Example 2

```text
Input: s = "abcd", queries = [[0,3]]
Output: [4]
Explanation: The only query is s[0..3] which is "abcd". It has 4 same-end substrings: "abcd", "abcd", "abcd", "abcd".
```

## Constraints

- 2 <= s.length <= 3 * 104
- s consists only of lowercase English letters.
- 1 <= queries.length <= 3 * 104
- queries[i] = [li, ri]
- 0 <= li <= ri < s.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2955. Number of Same-End Substrings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Prefix Sum | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        // Map to store each character and its positions in the string 's'
        unordered_map<char, vector<int>> charPositionsMap;

        // Traverse the string and store the index of each character in the map
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            charPositionsMap[c].push_back(i);
        }

        int numQueries = queries.size();
        vector<int> result(
            numQueries);  // Array to store the result for each query

        // Process each query
        for (int i = 0; i < numQueries; i++) {
            int leftIndex = queries[i][0];
            int rightIndex = queries[i][1];
            int countSameEndSubstrings = 0;

            // For each unique character in the string, calculate the number of
            // same-end substrings
            for (auto& entry : charPositionsMap) {
                vector<int>& positions = entry.second;

                // Get the number of occurrences of the character within the
                // range [leftIndex, rightIndex]
                int leftBound = findFirstGE(positions, leftIndex);
                int rightBound = findFirstGT(positions, rightIndex);
                int numOccurrences = rightBound - leftBound;

                // Calculate the number of same-end substrings for this
                // character
                countSameEndSubstrings +=
                    numOccurrences * (numOccurrences + 1) / 2;
            }

            // Store the result for this query
            result[i] = countSameEndSubstrings;
        }

        return result;
    }

private:
    // Custom binary search to find the first index in 'arr' where element >=
    // 'target'
    int findFirstGE(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    // Custom binary search to find the first index in 'arr' where element >
    // 'target'
    int findFirstGT(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] sameEndSubstringCount(String s, int[][] queries) {
        // Map to store each character and its positions in the string 's'
        Map<Character, List<Integer>> charPositionsMap = new HashMap<>();

        // Traverse the string and store the index of each character in the map
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            charPositionsMap.putIfAbsent(c, new ArrayList<>());
            charPositionsMap.get(c).add(i);
        }

        int numQueries = queries.length;
        int[] result = new int[numQueries]; // Array to store the result for each query

        // Process each query
        for (int i = 0; i < numQueries; i++) {
            int leftIndex = queries[i][0];
            int rightIndex = queries[i][1];
            int countSameEndSubstrings = 0;

            // For each unique character in the string, calculate the number of same-end substrings
            for (char c : charPositionsMap.keySet()) {
                List<Integer> positions = charPositionsMap.get(c);

                // Get the number of occurrences of the character within the range [leftIndex, rightIndex]
                int leftBound = findFirstGE(positions, leftIndex);
                int rightBound = findFirstGT(positions, rightIndex);
                int numOccurrences = rightBound - leftBound;

                // Calculate the number of same-end substrings for this character
                countSameEndSubstrings +=
                    (numOccurrences * (numOccurrences + 1)) / 2;
            }

            // Store the result for this query
            result[i] = countSameEndSubstrings;
        }

        return result;
    }

    // Custom binary search to find the first index in 'arr' where element >= 'target'
    private int findFirstGE(List<Integer> arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    // Custom binary search to find the first index in 'arr' where element > 'target'
    private int findFirstGT(List<Integer> arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr.get(mid) <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sameEndSubstringCount(
        self, s: str, queries: list[list[int]]
    ) -> list[int]:
        # Dictionary to store each character and its positions in the string 's'
        char_positions_map = {}

        # Traverse the string and store the index of each character in the dictionary
        for i, c in enumerate(s):
            if c not in char_positions_map:
                char_positions_map[c] = []
            char_positions_map[c].append(i)

        result = []

        # Process each query
        for left_index, right_index in queries:
            count_same_end_substrings = 0

            # For each unique character in the string, calculate the number of same-end substrings
            for positions in char_positions_map.values():
                # Get the number of occurrences of the character within the range [left_index, right_index]
                left_bound = bisect_left(positions, left_index)
                right_bound = bisect_right(positions, right_index)
                num_occurrences = right_bound - left_bound

                # Calculate the number of same-end substrings for this character
                count_same_end_substrings += (
                    num_occurrences * (num_occurrences + 1) // 2
                )

            # Store the result for this query
            result.append(count_same_end_substrings)

        return result
```

</details>

<br>

## Approach 2: Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.length();
        // 2D array to store prefix sum of character frequencies for each
        // character 'a' to 'z'
        vector<vector<int>> charFreqPrefixSum(26, vector<int>(n, 0));

        // Fill the frequency array
        for (int i = 0; i < n; i++) {
            charFreqPrefixSum[s[i] - 'a'][i]++;
        }

        // Convert the frequency array into a prefix sum array
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j < n; j++) {
                charFreqPrefixSum[i][j] += charFreqPrefixSum[i][j - 1];
            }
        }

        vector<int> results(queries.size());

        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int leftIndex = queries[i][0];
            int rightIndex = queries[i][1];
            int countSameEndSubstrings = 0;

            // For each character, calculate the frequency of occurrences within
            // the query range
            for (int charIndex = 0; charIndex < 26; charIndex++) {
                // Calculate frequency within the query range
                int leftFreq =
                    (leftIndex == 0)
                        ? 0
                        : charFreqPrefixSum[charIndex][leftIndex - 1];
                int rightFreq = charFreqPrefixSum[charIndex][rightIndex];
                int frequencyInRange = rightFreq - leftFreq;

                // Calculate the number of same-end substrings for this
                // character
                countSameEndSubstrings +=
                    frequencyInRange * (frequencyInRange + 1) / 2;
            }

            results[i] = countSameEndSubstrings;
        }

        return results;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] sameEndSubstringCount(String s, int[][] queries) {
        int n = s.length();
        // 2D array to store prefix sum of character frequencies for each character 'a' to 'z'
        int[][] charFreqPrefixSum = new int[26][n];

        // Fill the frequency array
        for (int i = 0; i < n; i++) {
            charFreqPrefixSum[s.charAt(i) - 'a'][i]++;
        }

        // Convert the frequency array into a prefix sum array
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j < n; j++) {
                charFreqPrefixSum[i][j] += charFreqPrefixSum[i][j - 1];
            }
        }

        int[] results = new int[queries.length];

        // Process each query
        for (int i = 0; i < queries.length; i++) {
            int leftIndex = queries[i][0];
            int rightIndex = queries[i][1];
            int countSameEndSubstrings = 0;

            // For each character, calculate the frequency of occurrences within the query range
            for (int charIndex = 0; charIndex < 26; charIndex++) {
                // Calculate frequency within the query range
                int leftFreq = (leftIndex == 0)
                    ? 0
                    : charFreqPrefixSum[charIndex][leftIndex - 1];
                int rightFreq = charFreqPrefixSum[charIndex][rightIndex];
                int frequencyInRange = rightFreq - leftFreq;

                // Calculate the number of same-end substrings for this character
                countSameEndSubstrings +=
                    (frequencyInRange * (frequencyInRange + 1)) / 2;
            }

            results[i] = countSameEndSubstrings;
        }

        return results;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sameEndSubstringCount(
        self, s: str, queries: List[List[int]]
    ) -> List[int]:
        n = len(s)
        # 2D list to store prefix sum of character frequencies for each character 'a' to 'z'
        char_freq_prefix_sum = [[0] * n for _ in range(26)]

        # Fill the frequency array
        for i, char in enumerate(s):
            char_freq_prefix_sum[ord(char) - ord("a")][i] += 1

        # Convert the frequency array into a prefix sum array
        for freq in char_freq_prefix_sum:
            for j in range(1, n):
                freq[j] += freq[j - 1]

        results = []

        # Process each query
        for left_index, right_index in queries:
            count_same_end_substrings = 0

            # For each character, calculate the frequency of occurrences within the query range
            for freq in char_freq_prefix_sum:
                left_freq = 0 if left_index == 0 else freq[left_index - 1]
                right_freq = freq[right_index]
                frequency_in_range = right_freq - left_freq

                # Calculate the number of same-end substrings for this character
                count_same_end_substrings += (
                    frequency_in_range * (frequency_in_range + 1) // 2
                )

            results.append(count_same_end_substrings)

        return results
```

</details>
