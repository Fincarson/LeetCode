# 1647. Minimum Deletions to Make Character Frequencies Unique

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)  
`Hash Table` `String` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1647 - Minimum Deletions to Make Character Frequencies Unique](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)

## Problem

A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

### Example 1

```text
Input: s = "aab"
Output: 0
Explanation: s is already good.
```

### Example 2

```text
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
```

### Example 3

```text
Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
```

## Constraints

- 1 <= s.length <= 105
- s contains only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Deletions to Make Array Beautiful](https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Removing Minimum and Maximum From Array](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Remove Letter To Equalize Frequency](https://leetcode.com/problems/remove-letter-to-equalize-frequency/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Deletions to Make String K-Special](https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1647. Minimum Deletions to Make Character Frequencies Unique

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Decrement Each Duplicate Until it is Unique | C++, Java, Python3 |
| Priority Queue | C++, Java, Python3 |
| Sorting | C++, Java, Python3 |

## Approach 1: Decrement Each Duplicate Until it is Unique

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minDeletions(string s) {
        // Store the frequency of each character
        vector<int> frequency(26, 0);
        for (char c : s) {
            frequency[c - 'a']++;
        }
        
        int deleteCount = 0;
        // Use a set to store the frequencies we have already seen
        unordered_set<int> seenFrequencies;
        for (int i = 0; i < 26; i++) {
            // Keep decrementing the frequency until it is unique
            while (frequency[i] && seenFrequencies.find(frequency[i]) != seenFrequencies.end()) {
                frequency[i]--;
                deleteCount++;
            }
            // Add the newly occupied frequency to the set
            seenFrequencies.insert(frequency[i]);
        }
        
        return deleteCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDeletions(String s) {
        // Store the frequency of each character
        int[] frequency = new int[26];
        for (int i = 0; i < s.length(); i++) {
            frequency[s.charAt(i) - 'a']++;
        }
        
        int deleteCount = 0;
        // Use a set to store the frequencies we have already seen
        HashSet<Integer> seenFrequencies = new HashSet<>();
        for (int i = 0; i < 26; i++) {
            // Keep decrementing the frequency until it is unique
            while (frequency[i] > 0 && seenFrequencies.contains(frequency[i])) {
                frequency[i]--;
                deleteCount++;
            }
            // Add the newly occupied frequency to the set
            seenFrequencies.add(frequency[i]);
        }
        
        return deleteCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDeletions(self, s: str) -> int:
        
        # Store the frequency of each character
        frequency = [0] * 26
        for char in s:
            frequency[ord(char) - ord('a')] += 1
        
        delete_count = 0
        # Use a set to store the frequencies we have already seen
        seen_frequencies = set()
        for i in range(26):
            # Keep decrementing the frequency until it is unique
            while frequency[i] and frequency[i] in seen_frequencies:
                frequency[i] -= 1
                delete_count += 1
                
            # Add the newly occupied frequency to the set
            seen_frequencies.add(frequency[i])
        
        return delete_count
```

</details>

<br>

## Approach 2: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minDeletions(string s) {
        // Store the frequency of each character
        vector<int> frequency(26, 0);
        for (char c : s) {
            frequency[c - 'a']++;
        }
        
        // Add the frequencies to priority queue
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (frequency[i] > 0) {
                pq.push(frequency[i]);
            }
        }
        
        int deleteCount = 0;
        while (pq.size() > 1) {
            int topElement  = pq.top();
            pq.pop();
            
            // If the top two elements in the priority queue are the same
            if (topElement == pq.top()) {
                // Decrement the popped value and push it back into the queue
                if (topElement - 1 > 0) {
                    pq.push(topElement - 1);
                }
                deleteCount++;
            }
        }
        
        return deleteCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDeletions(String s) {
        // Store the frequency of each character
        int[] frequency = new int[26];
        for (int i = 0; i < s.length(); i++) {
            frequency[s.charAt(i) - 'a']++;
        }
        
        // Add the frequencies to the priority queue
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < 26; i++) {
            if (frequency[i] > 0) {
                pq.add(frequency[i]);
            }
        }
        
        int deleteCount = 0;
        while (pq.size() > 1) {
            int topElement  = pq.remove();
            
            // If the top two elements in the priority queue are the same
            if (topElement == pq.peek()) {
                // Decrement the popped value and push it back into the queue
                if (topElement - 1 > 0) {
                    pq.add(topElement - 1);
                }
                deleteCount++;
            }
        }
        
        return deleteCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDeletions(self, s: str) -> int:
        
        # Store the frequency of each character
        frequency = [0] * 26
        for char in s:
            frequency[ord(char) - ord('a')] += 1
            
        # Add all non-zero frequencies to max priority queue
        # Create a max priority queue by flipping the sign of each element
        pq = [-freq for freq in frequency if freq != 0]
        heapq.heapify(pq)
        
        delete_count = 0
        while len(pq) > 1:
            # Flip the sign back to positive when removing from the max priority queue
            top_element = -heapq.heappop(pq)
            
            # If the top two elements in the priority queue are the same
            if top_element == -pq[0]:
                # Decrement the popped value and push it back into the queue
                if top_element - 1 > 0: 
                    top_element -= 1
                    heapq.heappush(pq, -top_element)

                delete_count += 1
        
        return delete_count
```

</details>

<br>

## Approach 3: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minDeletions(string s) {
        // Store the frequency of each character
        vector<int> frequency(26, 0);
        for (char c : s) {
            frequency[c - 'a']++;
        }
        
        sort(frequency.begin(), frequency.end(), greater<int>());
        
        int deleteCount = 0;
        // Maximum frequency the current character can have
        int maxFreqAllowed = s.size();
        
        // Iterate over the frequencies in descending order
        for (int i = 0; i < 26 && frequency[i] > 0; i++) {
            // Delete characters to make the frequency equal the maximum frequency allowed
            if (frequency[i] > maxFreqAllowed) {
                deleteCount += frequency[i] - maxFreqAllowed;
                frequency[i] = maxFreqAllowed;
            }
            // Update the maximum allowed frequency
            maxFreqAllowed = max(0, frequency[i] - 1);
        }
        
        return deleteCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDeletions(String s) {
        // Store the frequency of each character
        int[] frequency = new int[26];
        for (int i = 0; i < s.length(); i++) {
            frequency[s.charAt(i) - 'a']++;
        }
        
        Arrays.sort(frequency);
        
        int deleteCount = 0;
        // Maximum frequency the current character can have
        int maxFreqAllowed = s.length();
        
        // Iterate over the frequencies in descending order
        for (int i = 25; i >= 0 && frequency[i] > 0; i--) {
            // Delete characters to make the frequency equal the maximum frequency allowed
            if (frequency[i] > maxFreqAllowed) {
                deleteCount += frequency[i] - maxFreqAllowed;
                frequency[i] = maxFreqAllowed;
            }
            // Update the maximum allowed frequency
            maxFreqAllowed = Math.max(0, frequency[i] - 1);
        }
        
        return deleteCount;
    }     
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDeletions(self, s: str) -> int:
        
        # Store the frequency of each character
        frequency = [0] * 26
        for char in s:
            frequency[ord(char) - ord('a')] += 1
        frequency.sort(reverse=True)
        
        delete_count = 0
        # Maximum frequency the current character can have
        max_freq_allowed = len(s)
        
        # Iterate over the frequencies in descending order
        for freq in frequency:
            # Delete characters to make the frequency equal the maximum frequency allowed
            if freq > max_freq_allowed:
                delete_count += freq - max_freq_allowed
                freq = max_freq_allowed

            # Update the maximum allowed frequency
            max_freq_allowed = max(0, freq - 1)
            
        return delete_count
```

</details>
