# 2379. Minimum Recolors to Get K Consecutive Black Blocks

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/)  
`String` `Sliding Window`

**Problem Link:** [LeetCode 2379 - Minimum Recolors to Get K Consecutive Black Blocks](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/)

## Problem

You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

### Example 1

```text
Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW".
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
```

### Example 2

```text
Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.
```

## Constraints

- n == blocks.length
- 1 <= n <= 100
- blocks[i] is either 'W' or 'B'.
- 1 <= k <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2379. Minimum Recolors to Get K Consecutive Black Blocks

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Queue | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |

## Approach 1: Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        queue<char> blockQueue;
        int numWhites = 0;

        // Initiate queue with first k values
        while (blockQueue.size() < k) {
            char currentChar = blocks[blockQueue.size()];
            if (currentChar == 'W') numWhites++;
            blockQueue.push(currentChar);
        }

        // Set initial minimum
        int numRecolors = numWhites;
        for (int i = k; i < blocks.size(); i++) {
            // Remove top element from queue and update current number of white
            // blocks
            if (blockQueue.front() == 'W') numWhites--;
            blockQueue.pop();

            // Add current element to queue and update current number of white
            // blocks
            if (blocks[i] == 'W') numWhites++;
            blockQueue.push(blocks[i]);

            // Update minimum
            numRecolors = min(numRecolors, numWhites);
        }
        return numRecolors;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumRecolors(String blocks, int k) {
        Queue<Character> blockQueue = new LinkedList<>();
        int numWhites = 0;

        // Initiate queue with first k values
        for (int i = 0; i < k; i++) {
            char currentChar = blocks.charAt(i);
            if (currentChar == 'W') numWhites++;
            blockQueue.add(currentChar);
        }

        // Set initial minimum
        int numRecolors = numWhites;

        for (int i = k; i < blocks.length(); i++) {
            // Remove front element from queue and update current number of white blocks
            if (blockQueue.poll() == 'W') numWhites--;

            // Add current element to queue and update current number of white blocks
            char currentChar = blocks.charAt(i);
            if (currentChar == 'W') numWhites++;
            blockQueue.add(currentChar);

            // Update minimum
            numRecolors = Math.min(numRecolors, numWhites);
        }
        return numRecolors;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        block_queue = deque()
        num_whites = 0

        # Initiate queue with first k values
        for i in range(k):
            current_char = blocks[i]
            if current_char == "W":
                num_whites += 1
            block_queue.append(current_char)

        # Set initial minimum
        num_recolors = num_whites

        for i in range(k, len(blocks)):

            # Remove front element from queue and update current number of white blocks
            if block_queue.popleft() == "W":
                num_whites -= 1

            # Add current element to queue and update current number of white blocks
            current_char = blocks[i]
            if current_char == "W":
                num_whites += 1
            block_queue.append(current_char)

            # Update minimum
            num_recolors = min(num_recolors, num_whites)

        return num_recolors
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
    int minimumRecolors(string blocks, int k) {
        int left = 0, numWhites = 0, numRecolors = INT_MAX;

        // Move right pointer
        for (int right = 0; right < blocks.size(); right++) {
            // Increment numWhites if block at right pointer is white
            if (blocks[right] == 'W') {
                numWhites++;
            }

            // k consecutive elements are found
            if (right - left + 1 == k) {
                // Update minimum
                numRecolors = min(numRecolors, numWhites);

                // Decrement numWhites if block at left pointer is white
                if (blocks[left] == 'W') numWhites--;

                // Move left pointer
                left++;
            }
        }
        return numRecolors;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumRecolors(String blocks, int k) {
        int left = 0, numWhites = 0, numRecolors = Integer.MAX_VALUE;

        // Move right pointer
        for (int right = 0; right < blocks.length(); right++) {
            // Increment numWhites if block at right pointer is white
            if (blocks.charAt(right) == 'W') {
                numWhites++;
            }

            // k consecutive elements are found
            if (right - left + 1 == k) {
                // Update minumum
                numRecolors = Math.min(numRecolors, numWhites);

                // Decrement numWhites if block at left pointer is white
                if (blocks.charAt(left) == 'W') numWhites--;

                // Move left pointer
                left++;
            }
        }
        return numRecolors;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        left = 0
        num_whites = 0
        num_recolors = float("inf")

        # Move right pointer
        for right in range(len(blocks)):

            # Increment num_whites if block at right pointer is white
            if blocks[right] == "W":
                num_whites += 1

            # k consecutive elements are found
            if right - left + 1 == k:

                # Update minimum
                num_recolors = min(num_recolors, num_whites)

                # Decrement num_whites if block at left pointer is white
                if blocks[left] == "W":
                    num_whites -= 1

                # Move left pointer
                left += 1

        return num_recolors
```

</details>
