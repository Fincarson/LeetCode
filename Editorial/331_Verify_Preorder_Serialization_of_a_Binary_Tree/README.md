# 331. Verify Preorder Serialization of a Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/)  
`String` `Stack` `Tree` `Binary Tree`

**Problem Link:** [LeetCode 331 - Verify Preorder Serialization of a Binary Tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/)

## Problem

One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid.

- For example, it could never contain two consecutive commas, such as "1,,3".

Note: You are not allowed to reconstruct the tree.

### Example 1

```text
Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
```

### Example 2

```text
Input: preorder = "1,#"
Output: false
```

### Example 3

```text
Input: preorder = "9,#,#,1"
Output: false
```

## Constraints

- 1 <= preorder.length <= 104
- preorder consist of integers in the range [0, 100] and '#' separated by commas ','.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 331. Verify Preorder Serialization of a Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iteration | Java, Python |
| One pass | Java, Python |

## Approach 1: Iteration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public boolean isValidSerialization(String preorder) {
    // number of available slots
    int slots = 1;

    for(String node : preorder.split(",")) {
      // one node takes one slot
      --slots;

      // no more slots available
      if (slots < 0) return false;

      // non-empty node creates two children slots
      if (!node.equals("#")) slots += 2;
    }

    // all slots should be used up
    return slots == 0;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        # number of available slots
        slots = 1

        for node in preorder.split(','):
            # one node takes one slot
            slots -= 1
            
            # no more slots available
            if slots < 0:
                return False
            
            # non-empty node creates two children slots
            if node != '#':
                slots += 2
        
        # all slots should be used up
        return slots == 0
```

</details>

<br>

## Approach 2: One pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public boolean isValidSerialization(String preorder) {
    // number of available slots
    int slots = 1;

    int n = preorder.length();
    for(int i = 0; i < n; ++i) {
      if (preorder.charAt(i) == ',') {
        // one node takes one slot
        --slots;

        // no more slots available
        if (slots < 0) return false;

        // non-empty node creates two children slots
        if (preorder.charAt(i - 1) != '#') slots += 2;
      }
    }

    // the last node
    slots = (preorder.charAt(n - 1) == '#') ? slots - 1 : slots + 1;
    // all slots should be used up
    return slots == 0;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        # number of available slots
        slots = 1
        
        prev = None  # previous character
        for ch in preorder:
            if ch == ',':
                # one node takes one slot
                slots -= 1

                # no more slots available
                if slots < 0:
                    return False

                # non-empty node creates two children slots
                if prev != '#':
                    slots += 2
            prev = ch
        
        # the last node
        slots = slots + 1 if ch != '#' else slots - 1 
        # all slots should be used up
        return slots == 0
```

</details>
