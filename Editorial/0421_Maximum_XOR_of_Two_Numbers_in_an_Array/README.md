# 421. Maximum XOR of Two Numbers in an Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)  
`Array` `Hash Table` `Bit Manipulation` `Trie`

**Problem Link:** [LeetCode 421 - Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)

## Problem

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

### Example 1

```text
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
```

### Example 2

```text
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
```

## Constraints

- 1 <= nums.length <= 2 * 105
- 0 <= nums[i] <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum XOR With an Element From Array](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum XOR After Operations ](https://leetcode.com/problems/maximum-xor-after-operations/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sum of Prefix Scores of Strings](https://leetcode.com/problems/sum-of-prefix-scores-of-strings/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimize XOR](https://leetcode.com/problems/minimize-xor/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Strong Pair XOR I](https://leetcode.com/problems/maximum-strong-pair-xor-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Strong Pair XOR II](https://leetcode.com/problems/maximum-strong-pair-xor-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 421. Maximum XOR of Two Numbers in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bitwise Prefixes in HashSet | Java, Python |
| Bitwise Trie | Java, Python |

## Approach 1: Bitwise Prefixes in HashSet

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int findMaximumXOR(int[] nums) {
    int maxNum = nums[0];
    for(int num : nums) maxNum = Math.max(maxNum, num);
    // length of max number in a binary representation
    int L = (Integer.toBinaryString(maxNum)).length();

    int maxXor = 0, currXor;
    Set<Integer> prefixes = new HashSet<>();
    for(int i = L - 1; i > -1; --i) {
      //Go to the next bit by the left shift
      maxXor <<= 1;

      // Set 1 in the smallest bit
      currXor = maxXor | 1;
      prefixes.clear();

      // compute all possible prefixes 
      // of length (L - i) in binary representation
      for(int num: nums) prefixes.add(num >> i);

      // Update maxXor, if two of these prefixes could result in currXor.
      // Check if p1^p2 == currXor, i.e. p1 == currXor^p2.
      for(int p: prefixes) {
        if (prefixes.contains(currXor^p)) {
          maxXor = currXor;
          break;
        }
      }
    }
    return maxXor;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        # Length of the max number in a binary representation
        L = len(bin(max(nums))) - 2
        max_xor = 0
        for i in range(L)[::-1]:
            # Go to the next bit by the left shift
            max_xor <<= 1

            # Set 1 in the smallest bit
            curr_xor = max_xor | 1

            # Compute all existing prefixes 
            # of length (L - i) in binary representation
            prefixes = {num >> i for num in nums}

            # Update max_xor, if two of these prefixes could result in curr_xor.
            # Check if p1^p2 == curr_xor, i.e. p1 == curr_xor^p2
            max_xor |= any(curr_xor^p in prefixes for p in prefixes)
                    
        return max_xor
```

</details>

<br>

## Approach 2: Bitwise Trie

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
TrieNode root = new TrieNode();
    for (int num : nums) {
        TrieNode node = root, xorNode = root;
        int currXor = 0;
        
        for (int i = L - 1; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggledBit = bit ^ 1;
            
            if (node.children[bit] == null) {
                TrieNode newNode = new TrieNode();
                node.children[bit] = newNode;
            }
            node = node.children[bit];
            
            if (xorNode.children[toggledBit] != null) {
                currXor |= (1 << i);
                xorNode = xorNode.children[toggledBit];
            } else {
                xorNode = xorNode.children[bit];
            }
        }
        maxXor = Math.max(maxXor, currXor);
    }
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
trie = {}
for num in nums:
    node = trie
    for bit in num:
        if not bit in node:
            node[bit] = {}
        node = node[bit]
```

</details>
