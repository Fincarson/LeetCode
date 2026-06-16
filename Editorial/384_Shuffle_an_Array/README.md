# 384. Shuffle an Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/shuffle-an-array/)  
`Array` `Math` `Design` `Randomized`

**Problem Link:** [LeetCode 384 - Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/)

## Problem

Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:

- Solution(int[] nums) Initializes the object with the integer array nums.
- int[] reset() Resets the array to its original configuration and returns it.
- int[] shuffle() Returns a random shuffling of the array.

### Example 1

```text
Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]
```

## Constraints

- 1 <= nums.length <= 50
- -106 <= nums[i] <= 106
- All the elements of nums are unique.
- At most 104 calls in total will be made to reset and shuffle.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 384. Shuffle an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Accepted] | Java, Python |
| Approach #2 Fisher-Yates Algorithm [Accepted] | Java, Python |

## Approach #1 Brute Force [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int[] array;
    private int[] original;

    private Random rand = new Random();

    private List<Integer> getArrayCopy() {
        List<Integer> asList = new ArrayList<Integer>();
        for (int i = 0; i < array.length; i++) {
            asList.add(array[i]);
        }
        return asList;
    }

    public Solution(int[] nums) {
        array = nums;
        original = nums.clone();
    }
    
    public int[] reset() {
        array = original;
        original = original.clone();
        return array;
    }
    
    public int[] shuffle() {
        List<Integer> aux = getArrayCopy();

        for (int i = 0; i < array.length; i++) {
            int removeIdx = rand.nextInt(aux.size());
            array[i] = aux.get(removeIdx);
            aux.remove(removeIdx);
        }

        return array;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def __init__(self, nums):
        self.array = nums
        self.original = list(nums)

    def reset(self):
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        aux = list(self.array)

        for idx in range(len(self.array)):
            remove_idx = random.randrange(len(aux))
            self.array[idx] = aux.pop(remove_idx)

        return self.array
```

</details>

<br>

## Approach #2 Fisher-Yates Algorithm [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int[] array;
    private int[] original;

    Random rand = new Random();

    private int randRange(int min, int max) {
        return rand.nextInt(max - min) + min;
    }

    private void swapAt(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public Solution(int[] nums) {
        array = nums;
        original = nums.clone();
    }
    
    public int[] reset() {
        array = original;
        original = original.clone();
        return original;
    }
    
    public int[] shuffle() {
        for (int i = 0; i < array.length; i++) {
            swapAt(i, randRange(i, array.length));
        }
        return array;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def __init__(self, nums):
        self.array = nums
        self.original = list(nums)

    def reset(self):
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        for i in range(len(self.array)):
            swap_idx = random.randrange(i, len(self.array))
            self.array[i], self.array[swap_idx] = self.array[swap_idx], self.array[i]
        return self.array
```

</details>
