# 187. Repeated DNA Sequences

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/repeated-dna-sequences/)  
`Hash Table` `String` `Bit Manipulation` `Sliding Window` `Rolling Hash` `Hash Function`

**Problem Link:** [LeetCode 187 - Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/)

## Problem

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

- For example, "ACGAATTCCG" is a DNA sequence.

When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

### Example 1

```text
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
```

### Example 2

```text
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
```

## Constraints

- 1 <= s.length <= 105
- s[i] is either 'A', 'C', 'G', or 'T'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 187. Repeated DNA Sequences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear-time Slice Using Substring + HashSet | C++, Java, Python3 |
| Rabin-Karp: Constant-time Slice Using Rolling Hash | C++, Java, Python3 |
| Bit Manipulation: Constant-time Slice Using Bitmask | C++, Java, Python3 |

## Approach 1: Linear-time Slice Using Substring + HashSet

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int L = 10, n = s.length();
        unordered_set<string> seen, output;

        // iterate over all sequences of length L
        for (int start = 0; start < n - L + 1; ++start) {
            string tmp = s.substr(start, L);
            if (seen.find(tmp) != seen.end()) output.insert(tmp);
            seen.insert(tmp);
        }
        return vector<string>(output.begin(), output.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> findRepeatedDnaSequences(String s) {
        int L = 10, n = s.length();
        HashSet<String> seen = new HashSet(), output = new HashSet();

        // iterate over all sequences of length L
        for (int start = 0; start < n - L + 1; ++start) {
            String tmp = s.substring(start, start + L);
            if (seen.contains(tmp)) output.add(tmp);
            seen.add(tmp);
        }
        return new ArrayList<String>(output);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)
        seen, output = set(), set()

        # iterate over all sequences of length L
        for start in range(n - L + 1):
            tmp = s[start : start + L]
            if tmp in seen:
                output.add(tmp[:])
            seen.add(tmp)
        return list(output)
```

</details>

<br>

## Approach 2: Rabin-Karp: Constant-time Slice Using Rolling Hash

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int L = 10, n = s.size();
        if (n <= L) return vector<string>();

        // rolling hash parameters: base a
        int a = 4, aL = pow(a, L);

        // convert string to array of integers
        unordered_map<char, int> to_int = {
            {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = to_int[s[i]];

        int h = 0;
        unordered_set<int> seen;
        unordered_set<string> output;
        // iterate over all sequences of length L
        for (int start = 0; start < n - L + 1; ++start) {
            // compute hash of the current sequence in O(1) time
            if (start != 0)
                h = h * a - nums[start - 1] * aL + nums[start + L - 1];

            // compute hash of the first sequence in O(L) time
            else
                for (int i = 0; i < L; ++i) h = h * a + nums[i];

            // update output and hashset of seen sequences
            if (seen.find(h) != seen.end()) output.insert(s.substr(start, L));
            seen.insert(h);
        }
        return vector<string>(output.begin(), output.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> findRepeatedDnaSequences(String s) {
        int L = 10, n = s.length();
        if (n <= L) return new ArrayList();

        // rolling hash parameters: base a
        int a = 4, aL = (int) Math.pow(a, L);

        // convert string to array of integers
        Map<Character, Integer> toInt = new HashMap() {
            {
                put('A', 0);
                put('C', 1);
                put('G', 2);
                put('T', 3);
            }
        };
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) nums[i] = toInt.get(s.charAt(i));

        int h = 0;
        Set<Integer> seen = new HashSet();
        Set<String> output = new HashSet();
        // iterate over all sequences of length L
        for (int start = 0; start < n - L + 1; ++start) {
            // compute hash of the current sequence in O(1) time
            if (start != 0) h =
                h * a - nums[start - 1] * aL + nums[start + L - 1];
            // compute hash of the first sequence in O(L) time
            else for (int i = 0; i < L; ++i) h = h * a + nums[i];

            // update output and hashset of seen sequences
            if (seen.contains(h)) output.add(s.substring(start, start + L));
            seen.add(h);
        }
        return new ArrayList<String>(output);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)
        if n <= L:
            return []

        # rolling hash parameters: base a
        a = 4
        aL = pow(a, L)

        # convert string to array of integers
        to_int = {"A": 0, "C": 1, "G": 2, "T": 3}
        nums = [to_int.get(s[i]) for i in range(n)]

        h = 0
        seen, output = set(), set()
        # iterate over all sequences of length L
        for start in range(n - L + 1):
            # compute hash of the current sequence in O(1) time
            if start != 0:
                h = h * a - nums[start - 1] * aL + nums[start + L - 1]

            # compute hash of the first sequence in O(L) time
            else:
                for i in range(L):
                    h = h * a + nums[i]

            # update output and hashset of seen sequences
            if h in seen:
                output.add(s[start : start + L])
            seen.add(h)
        return list(output)
```

</details>

<br>

## Approach 3: Bit Manipulation: Constant-time Slice Using Bitmask

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int L = 10, n = s.size();
        if (n <= L) return {};

        // convert string to array of integers
        unordered_map<char, int> toInt = {
            {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = toInt[s[i]];

        int bitmask = 0;
        unordered_set<int> seen;
        unordered_set<string> output;
        // iterate over all sequences of length L
        for (int start = 0; start < n - L + 1; ++start) {
            // compute bitmask of the current sequence in O(1) time
            if (start != 0) {
                // left shift to free the last 2 bit
                bitmask <<= 2;
                // add a new 2-bits number in the last two bits
                bitmask |= nums[start + L - 1];
                // unset first two bits: 2L-bit and (2L + 1)-bit
                bitmask &= ~(3 << 2 * L);
            }
            // compute bitmask of the first sequence in O(L) time
            else {
                for (int i = 0; i < L; ++i) {
                    bitmask <<= 2;
                    bitmask |= nums[i];
                }
            }
            // update output and hashset of seen sequences
            if (seen.find(bitmask) != seen.end())
                output.insert(s.substr(start, L));
            seen.insert(bitmask);
        }
        return vector<string>(output.begin(), output.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> findRepeatedDnaSequences(String s) {
        int L = 10, n = s.length();
        if (n <= L) return new ArrayList();

        // rolling hash parameters: base a
        int a = 4, aL = (int) Math.pow(a, L);

        // convert string to array of integers
        Map<Character, Integer> toInt = new HashMap() {
            {
                put('A', 0);
                put('C', 1);
                put('G', 2);
                put('T', 3);
            }
        };
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) nums[i] = toInt.get(s.charAt(i));

        int bitmask = 0;
        Set<Integer> seen = new HashSet();
        Set<String> output = new HashSet();
        // iterate over all sequences of length L
        for (int start = 0; start < n - L + 1; ++start) {
            // compute bitmask of the current sequence in O(1) time
            if (start != 0) {
                // left shift to free the last 2 bit
                bitmask <<= 2;

                // add a new 2-bits number in the last two bits
                bitmask |= nums[start + L - 1];

                // unset first two bits: 2L-bit and (2L + 1)-bit
                bitmask &= ~(3 << (2 * L));
            }
            // compute hash of the first sequence in O(L) time
            else {
                for (int i = 0; i < L; ++i) {
                    bitmask <<= 2;
                    bitmask |= nums[i];
                }
            }

            // update output and hashset of seen sequences
            if (seen.contains(bitmask)) output.add(
                s.substring(start, start + L)
            );
            seen.add(bitmask);
        }
        return new ArrayList<String>(output);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)
        if n <= L:
            return []

        # convert string to the array of 2-bits integers:
        # 00_2, 01_2, 10_2 or 11_2
        to_int = {"A": 0, "C": 1, "G": 2, "T": 3}
        nums = [to_int.get(s[i]) for i in range(n)]

        bitmask = 0
        seen, output = set(), set()
        # iterate over all sequences of length L
        for start in range(n - L + 1):
            # compute bitmask of the sequence in O(1) time
            if start != 0:
                # left shift to free the last 2 bit
                bitmask <<= 2

                # add a new 2-bits number in the last two bits
                bitmask |= nums[start + L - 1]

                # unset first two bits: 2L-bit and (2L + 1)-bit
                bitmask &= ~(3 << 2 * L)

            # compute bitmask of the first sequence in O(L) time
            else:
                for i in range(L):
                    bitmask <<= 2
                    bitmask |= nums[i]
            if bitmask in seen:
                output.add(s[start : start + L])
            seen.add(bitmask)
        return list(output)
```

</details>
