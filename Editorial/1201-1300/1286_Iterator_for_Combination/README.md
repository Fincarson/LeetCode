# 1286. Iterator for Combination

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/iterator-for-combination/)  
`String` `Backtracking` `Design` `Iterator`

**Problem Link:** [LeetCode 1286 - Iterator for Combination](https://leetcode.com/problems/iterator-for-combination/)

## Problem

Design the CombinationIterator class:

- CombinationIterator(string characters, int combinationLength) Initializes the object with a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
- next() Returns the next combination of length combinationLength in lexicographical order.
- hasNext() Returns true if and only if there exists a next combination.

### Example 1

```text
Input
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
Output
[null, "ab", true, "ac", true, "bc", false]

Explanation
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False
```

## Constraints

- 1 <= combinationLength <= characters.length <= 15
- All the characters of characters are unique.
- At most 104 calls will be made to next and hasNext.
- It is guaranteed that all calls of the function next are valid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1286. Iterator for Combination

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bitmasking: Precomputation | Java, Python3 |
| Bitmasking: Next Combination | Java, Python3 |
| Algorithm L by D. E. Knuth: Lexicographic Combinations: Precomputation | Java, Python3 |
| Algorithm L by D. E. Knuth: Lexicographic Combinations: Next Combination | Java, Python3 |

## Approach 1: Bitmasking: Precomputation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class CombinationIterator {
    public Deque < String > combinations = new ArrayDeque < String > ();

    public CombinationIterator(String characters, int combinationLength) {
        int n = characters.length();
        int k = combinationLength;

        // generate bitmasks from 0..00 to 1..11  
        for (int bitmask = 0; bitmask < 1 << n; bitmask++) {
            // use bitmasks with k 1-bits
            if (Integer.bitCount(bitmask) == k) {
                // convert bitmask into combination
                // 111 --> "abc", 000 --> ""
                // 110 --> "ab", 101 --> "ac", 011 --> "bc"
                StringBuilder curr = new StringBuilder();
                for (int j = 0; j < n; j++) {
                    if ((bitmask & (1 << n - j - 1)) != 0) {
                        curr.append(characters.charAt(j));
                    }
                }
                combinations.push(curr.toString());
            }
        }
    }

    public String next() {
        return combinations.pop();
    }

    public boolean hasNext() {
        return (!combinations.isEmpty());
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        self.combinations = []
        n, k = len(characters), combinationLength
        
        # generate bitmasks from 0..00 to 1..11  
        for bitmask in range(1 << n):
            # use bitmasks with k 1-bits
            if bin(bitmask).count('1') == k:
                # convert bitmask into combination
                # 111 --> "abc", 000 --> ""
                # 110 --> "ab", 101 --> "ac", 011 --> "bc"
                curr = [characters[j] for j in range(n) if bitmask & (1 << n - j - 1)]
                self.combinations.append(''.join(curr))

    def next(self) -> str:
        return self.combinations.pop()

    def hasNext(self) -> bool:
        return self.combinations
```

</details>

<br>

## Approach 2: Bitmasking: Next Combination

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class CombinationIterator {
    int bitmask, n, k;
    String chars;

    public CombinationIterator(String characters, int combinationLength) {
        n = characters.length();
        k = combinationLength;
        chars = characters;

        // generate first bitmask 1(k)0(n - k)
        bitmask = (1 << n) - (1 << n - k);
    }

    public String next() {
        // convert bitmask into combination
        // 111 --> "abc", 000 --> ""
        // 110 --> "ab", 101 --> "ac", 011 --> "bc"
        StringBuilder curr = new StringBuilder();
        for (int j = 0; j < n; j++) {
            if ((bitmask & (1 << n - j - 1)) != 0) {
                curr.append(chars.charAt(j));
            }
        }

        // generate next bitmask
        bitmask--;
        while (bitmask > 0 && Integer.bitCount(bitmask) != k) {
            bitmask--;
        }

        return curr.toString();
    }

    public boolean hasNext() {
        return bitmask > 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        self.n = n = len(characters)
        self.k = k = combinationLength
        self.chars = characters

        # generate first bitmask 1(k)0(n - k)
        self.b = (1 << n) - (1 << n - k)

    def next(self) -> str:
        # convert bitmasks into combinations
        # 111 --> "abc", 000 --> ""
        # 110 --> "ab", 101 --> "ac", 011 --> "bc"
        curr = [self.chars[j] for j in range(self.n) if self.b & (1 << self.n - j - 1)]
        
        # generate next bitmask
        self.b -= 1
        while self.b > 0 and bin(self.b).count('1') != self.k:
            self.b -= 1
        
        return ''.join(curr)

    def hasNext(self) -> bool:
        return self.b > 0
```

</details>

<br>

## Approach 3: Algorithm L by D. E. Knuth: Lexicographic Combinations: Precomputation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class CombinationIterator {
    public Deque < String > combinations = new ArrayDeque < String > ();

    public CombinationIterator(String characters, int combinationLength) {
        int n = characters.length(), k = combinationLength;

        // init the first combination
        int[] nums = new int[k + 1];
        for (int i = 0; i < k; ++i) {
            nums[i] = i;
        }
        nums[k] = n;

        int j = 0;
        while (j < k) {
            // add current combination
            StringBuilder sb = new StringBuilder();
            for (int i = k - 1; i > -1; i--) {
                sb.append(characters.charAt(n - 1 - nums[i]));
            }
            combinations.push(sb.toString());
            // Generate next combination.
            // Find the first j such that nums[j] + 1 != nums[j + 1].
            // Increase nums[j] by one.
            j = 0;
            while ((j < k) && (nums[j + 1] == nums[j] + 1)) {
                nums[j] = j;
                j++;
            }
            nums[j]++;
        }
    }

    public String next() {
        return combinations.pop();
    }

    public boolean hasNext() {
        return (!combinations.isEmpty());
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        self.combinations = []
        n, k = len(characters), combinationLength
        
        # init the first combination
        nums = list(range(k)) + [n]
        
        j = 0
        while j < k:
            # add current combination
            curr = [characters[n - 1 - nums[i]] for i in range(k - 1, -1, -1)]
            self.combinations.append(''.join(curr))
            
            # Generate next combination.
            # Find the first j such that nums[j] + 1 != nums[j + 1].
            # Increase nums[j] by one.
            j = 0
            while j < k and nums[j + 1] == nums[j] + 1:
                nums[j] = j
                j += 1
            nums[j] += 1

    def next(self) -> str:
        return self.combinations.pop()

    def hasNext(self) -> bool:
        return self.combinations
```

</details>

<br>

## Approach 4: Algorithm L by D. E. Knuth: Lexicographic Combinations: Next Combination

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class CombinationIterator {
    int[] nums;
    boolean has_next;
    int n, k;
    String chars;

    public CombinationIterator(String characters, int combinationLength) {
        n = characters.length();
        k = combinationLength;
        chars = characters;

        // init the first combination
        has_next = true;
        nums = new int[k];
        for (int i = 0; i < k; ++i) {
            nums[i] = i;
        }
    }

    public String next() {
        StringBuilder curr = new StringBuilder();
        for (int j: nums) {
            curr.append(chars.charAt(j));
        }

        // Generate next combination.
        // Find the first j such that nums[j] != n - k + j.
        // Increase nums[j] by one.
        int j = k - 1;
        while (j >= 0 && nums[j] == n - k + j) {
            j--;
        }

        if (j >= 0) {
            nums[j]++;
            for (int i = j + 1; i < k; i++) {
                nums[i] = nums[j] + i - j;
            }
        } else {
            has_next = false;
        }

        return curr.toString();
    }

    public boolean hasNext() {
        return has_next;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        self.n = len(characters)
        self.k = k = combinationLength
        self.chars = characters
        
        # init the first combination
        self.nums = list(range(k))
        self.has_next = True
        
    def next(self) -> str:
        nums = self.nums
        n, k = self.n, self.k
        curr = [self.chars[j] for j in nums]
        
        # Generate next combination.
        # Find the first j such that nums[j] != n - k + j.
        # Increase nums[j] by one.
        j = k - 1
        while j >= 0 and nums[j] == n - k + j:
            j -= 1 
        nums[j] += 1
        
        if j >= 0:
            for i in range(j + 1, k):
                nums[i] = nums[j] + i - j
        else:
            self.has_next = False
        
        return ''.join(curr)
        
    def hasNext(self) -> bool:
        return self.has_next
```

</details>
