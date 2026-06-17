# 2024. Maximize the Confusion of an Exam

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)  
`String` `Binary Search` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 2024 - Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)

## Problem

A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

- Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').

Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

### Example 1

```text
Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.
```

### Example 2

```text
Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.
```

### Example 3

```text
Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT".
In both cases, there are five consecutive 'T's.
```

## Constraints

- n == answerKey.length
- 1 <= n <= 5 * 104
- answerKey[i] is either 'T' or 'F'
- 1 <= k <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2024. Maximize the Confusion of an Exam

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search + Fixed Size Sliding Window | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |
| Advanced Sliding Window | C++, Java, Python3 |

## Approach 1: Binary Search + Fixed Size Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int left = k, right = n;
        
        while (left < right) {
            int mid = (left + right + 1) / 2;
            
            if (isValid(answerKey, mid, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
    
    bool isValid(string answerKey, int size, int k) {
        int n = answerKey.length();
        unordered_map<char, int> counter;
        
        for (int i = 0; i < size; i++) {
            char c = answerKey[i];
            counter[c]++;
        }
        
        if (min(counter['T'], counter['F']) <= k) {
            return true;
        }
        
        for (int i = size; i < n; i++) {
            char c1 = answerKey[i];
            counter[c1]++;
            char c2 = answerKey[i - size];
            counter[c2]--;
            
            if (min(counter['T'], counter['F']) <= k) {
                return true;
            }
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
    public int maxConsecutiveAnswers(String answerKey, int k) {
        int n = answerKey.length();
        int left = k, right = n;
        
        while (left < right) {
            int mid = (left + right + 1) / 2;
            
            if (isValid(answerKey, mid, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
    
    private boolean isValid(String answerKey, int size, int k) {
        int n = answerKey.length();
        Map<Character, Integer> counter = new HashMap<>();
        
        for (int i = 0; i < size; i++) {
            char c = answerKey.charAt(i);
            counter.put(c, counter.getOrDefault(c, 0) + 1);
        }
        
        if (Math.min(counter.getOrDefault('T', 0), counter.getOrDefault('F', 0)) <= k) {
            return true;
        }
        
        for (int i = size; i < n; i++) {
            char c1 = answerKey.charAt(i);
            counter.put(c1, counter.getOrDefault(c1, 0) + 1);
            char c2 = answerKey.charAt(i - size);
            counter.put(c2, counter.getOrDefault(c2, 0) - 1);
            
            if (Math.min(counter.getOrDefault('T', 0), counter.getOrDefault('F', 0)) <= k) {
                return true;
            }
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
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        n = len(answerKey)
        left, right = k, n
        
        def isValid(size):
            counter = collections.Counter(answerKey[:size])
            if min(counter['T'], counter['F']) <= k:
                return True
            for i in range(size, n):
                counter[answerKey[i]] += 1
                counter[answerKey[i - size]] -= 1
                if min(counter['T'], counter['F']) <= k:
                    return True
            return False
        
        while left < right:
            mid = (left + right + 1) // 2
            
            if isValid(mid):
                left = mid
            else:
                right = mid - 1
        
        return left
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxSize = k;
        unordered_map<char, int> count;
        for (int i = 0; i < k; i++) {
            count[answerKey[i]]++;
        }
        
        int left = 0;
        for (int right = k; right < answerKey.length(); right++) {
            count[answerKey[right]]++;
            
            while (min(count['T'], count['F']) > k) {
                count[answerKey[left]]--;
                left++;
            }
            
            maxSize = max(maxSize, right - left + 1);
        }
                    
        return maxSize;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        int maxSize = k;
        Map<Character, Integer> count = new HashMap<>();
        for (int i = 0; i < k; i++) {
            count.put(answerKey.charAt(i), count.getOrDefault(answerKey.charAt(i), 0) + 1);
        }
        
        int left = 0;
        for (int right = k; right < answerKey.length(); right++) {
            count.put(answerKey.charAt(right), count.getOrDefault(answerKey.charAt(right), 0) + 1);
            
            while (Math.min(count.getOrDefault('T', 0), count.getOrDefault('F', 0)) > k) {
                count.put(answerKey.charAt(left), count.get(answerKey.charAt(left)) - 1);
                left++;
            }
            
            maxSize = Math.max(maxSize, right - left + 1);
        }
                    
        return maxSize;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        max_size = k
        count = collections.Counter(answerKey[:k])
        
        left = 0
        for right in range(k, len(answerKey)):
            count[answerKey[right]] += 1
            
            while min(count['T'], count['F']) > k: 
                count[answerKey[left]] -= 1
                left += 1
            
            max_size = max(max_size, right - left + 1)
                    
        return max_size
```

</details>

<br>

## Approach 3: Advanced Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxSize = 0;
        unordered_map<char, int> count;
        
        for (int right = 0; right < answerKey.length(); right++) {
            count[answerKey[right]]++;
            int minor = min(count['T'], count['F']);
            
            if (minor <= k) {
                maxSize++;
            } else {
                count[answerKey[right - maxSize]]--;
            }
        }

        return maxSize;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        int maxSize = 0;
        Map<Character, Integer> count = new HashMap<>();
        
        for (int right = 0; right < answerKey.length(); right++) {
            count.put(answerKey.charAt(right), count.getOrDefault(answerKey.charAt(right), 0) + 1);
            int minor = Math.min(count.getOrDefault('T', 0), count.getOrDefault('F', 0));
            
            if (minor <= k) {
                maxSize++;
            } else {
                count.put(answerKey.charAt(right - maxSize), count.get(answerKey.charAt(right - maxSize)) - 1);
            }
        }

        return maxSize;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        max_size = 0
        count = collections.Counter()
        
        for right in range(len(answerKey)):
            count[answerKey[right]] += 1
            minor = min(count['T'], count['F'])
            
            if minor <= k:
                max_size += 1
            else:
                count[answerKey[right - max_size]] -= 1

        return max_size
```

</details>
