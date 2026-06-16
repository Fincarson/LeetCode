# 895. Maximum Frequency Stack

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximum-frequency-stack/)  
`Hash Table` `Stack` `Design` `Ordered Set`

**Problem Link:** [LeetCode 895 - Maximum Frequency Stack](https://leetcode.com/problems/maximum-frequency-stack/)

## Problem

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

- FreqStack() constructs an empty frequency stack.
- void push(int val) pushes an integer val onto the top of the stack.
- int pop() removes and returns the most frequent element in the stack.

		If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

### Example 1

```text
Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
```

## Constraints

- 0 <= val <= 109
- At most 2 * 104 calls will be made to push and pop.
- It is guaranteed that there will be at least one element in the stack before calling pop.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 895. Maximum Frequency Stack

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack of Stacks | Java, Python |

## Approach 1: Stack of Stacks

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class FreqStack {
    Map<Integer, Integer> freq;
    Map<Integer, Stack<Integer>> group;
    int maxfreq;

    public FreqStack() {
        freq = new HashMap();
        group = new HashMap();
        maxfreq = 0;
    }

    public void push(int x) {
        int f = freq.getOrDefault(x, 0) + 1;
        freq.put(x, f);
        if (f > maxfreq)
            maxfreq = f;

        group.computeIfAbsent(f, z-> new Stack()).push(x);
    }

    public int pop() {
        int x = group.get(maxfreq).pop();
        freq.put(x, freq.get(x) - 1);
        if (group.get(maxfreq).size() == 0)
            maxfreq--;
        return x;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class FreqStack(object):

    def __init__(self):
        self.freq = collections.Counter()
        self.group = collections.defaultdict(list)
        self.maxfreq = 0

    def push(self, x):
        f = self.freq[x] + 1
        self.freq[x] = f
        if f > self.maxfreq:
            self.maxfreq = f
        self.group[f].append(x)

    def pop(self):
        x = self.group[self.maxfreq].pop()
        self.freq[x] -= 1
        if not self.group[self.maxfreq]:
            self.maxfreq -= 1

        return x
```

</details>
