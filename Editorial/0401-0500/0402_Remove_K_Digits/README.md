# 402. Remove K Digits

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/remove-k-digits/)  
`String` `Stack` `Greedy` `Monotonic Stack`

**Problem Link:** [LeetCode 402 - Remove K Digits](https://leetcode.com/problems/remove-k-digits/)

## Problem

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

### Example 1

```text
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

### Example 2

```text
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
```

### Example 3

```text
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

## Constraints

- 1 <= k <= num.length <= 105
- num consists of only digits.
- num does not have any leading zeros except for the zero itself.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Create Maximum Number](https://leetcode.com/problems/create-maximum-number/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Monotone Increasing Digits](https://leetcode.com/problems/monotone-increasing-digits/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Most Competitive Subsequence](https://leetcode.com/problems/find-the-most-competitive-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Append K Integers With Minimal Sum](https://leetcode.com/problems/append-k-integers-with-minimal-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Remove Digit From Number to Maximize Result](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Operations to Make a Special Number](https://leetcode.com/problems/minimum-operations-to-make-a-special-number/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 402. Remove K Digits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy with Stack | Java, Python |

## Approach 2: Greedy with Stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public String removeKdigits(String num, int k) {
    LinkedList<Character> stack = new LinkedList<Character>();
        
    for(char digit : num.toCharArray()) {
      while(stack.size() > 0 && k > 0 && stack.peekLast() > digit) {
        stack.removeLast();
        k -= 1;
      }
      stack.addLast(digit);
    }
        
    /* remove the remaining digits from the tail. */
    for(int i=0; i<k; ++i) {
      stack.removeLast();
    }
        
    // build the final string, while removing the leading zeros.
    StringBuilder ret = new StringBuilder();
    boolean leadingZero = true;
    for(char digit: stack) {
      if(leadingZero && digit == '0') continue;
      leadingZero = false;
      ret.append(digit);
    }
        
    /* return the final string  */
    if (ret.length() == 0) return "0";
    return ret.toString();
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        numStack = []
        
        # Construct a monotone increasing sequence of digits
        for digit in num:
            while k and numStack and numStack[-1] > digit:
                numStack.pop()
                k -= 1
        
            numStack.append(digit)
        
        # - Trunk the remaining K digits at the end
        # - in the case k==0: return the entire list
        finalStack = numStack[:-k] if k else numStack
        
        # trip the leading zeros
        return "".join(finalStack).lstrip('0') or "0"
```

</details>
