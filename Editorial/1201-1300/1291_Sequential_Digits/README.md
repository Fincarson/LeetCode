# 1291. Sequential Digits

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sequential-digits/)  
`Enumeration`

**Problem Link:** [LeetCode 1291 - Sequential Digits](https://leetcode.com/problems/sequential-digits/)

## Problem

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

### Example 1

```text
Input: low = 100, high = 300
Output: [123,234]
```

### Example 2

```text
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
```

## Constraints

- 10 <= low <= high <= 10^9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1291. Sequential Digits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window | Java, Python |
| Precomputation | Java, Python |

## Approach 1: Sliding Window

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public List<Integer> sequentialDigits(int low, int high) {
    String sample = "123456789";
    int n = 10;
    List<Integer> nums = new ArrayList();

    int lowLen = String.valueOf(low).length();
    int highLen = String.valueOf(high).length();
    for (int length = lowLen; length < highLen + 1; ++length) {
      for (int start = 0; start < n - length; ++start) {
        int num = Integer.parseInt(sample.substring(start, start + length));
        if (num >= low && num <= high) nums.add(num);
      }
    }
    return nums;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        sample = "123456789"
        n = 10
        nums = []

        for length in range(len(str(low)), len(str(high)) + 1):
            for start in range(n - length):
                num = int(sample[start: start + length])
                if num >= low and num <= high:
                    nums.append(num)
        
        return nums
```

</details>

<br>

## Approach 2: Precomputation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Seq {
  public List<Integer> nums = new ArrayList();
  Seq() {
    String sample = "123456789";
    int n = 10;

    for (int length = 2; length < n; ++length) {
      for (int start = 0; start < n - length; ++start) {
        int num = Integer.parseInt(sample.substring(start, start + length));
        nums.add(num);
      }
    }
  }
}

class Solution {
  public static Seq s = new Seq();
  public List<Integer> sequentialDigits(int low, int high) {
    List<Integer> output = new ArrayList();
    for (int num : s.nums) {
      if (num >= low && num <= high) output.add(num);
    }
    return output;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Seqs:
    def __init__(self):
        sample = "123456789"
        n = 10
        self.nums = nums = []

        for length in range(2, n):
            for start in range(n - length):
                nums.append(int(sample[start: start + length]))
            
class Solution:
    s = Seqs()
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        return [x for x in self.s.nums if x >= low and x <= high]
```

</details>
