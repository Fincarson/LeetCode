# 514. Freedom Trail

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/freedom-trail/)  
`String` `Dynamic Programming` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 514 - Freedom Trail](https://leetcode.com/problems/freedom-trail/)

## Problem

In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.

Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at the "12:00" direction. You should spell all the characters in key one by one by rotating ring clockwise or anticlockwise to make each character of the string key aligned at the "12:00" direction and then by pressing the center button.

At the stage of rotating the ring to spell the key character key[i]:

### Example 1

```text
Input: ring = "godding", key = "gd"
Output: 4
Explanation:
For the first key character 'g', since it is already in place, we just need 1 step to spell this character.
For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
Also, we need 1 more step for spelling.
So the final output is 4.
```

### Example 2

```text
Input: ring = "godding", key = "godding"
Output: 13
```

## Constraints

- 1 <= ring.length, key.length <= 100
- ring and key consist of only lower case English letters.
- It is guaranteed that key could always be spelled by rotating ring.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 514. Freedom Trail

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Space-Optimized Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Shortest Path | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        return tryLock(0, 0, ring, key, INT_MAX);
    }

private:
    // Find the minimum steps between two indexes of ring
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }

    // Find the minimum number of steps to spell the keyword
    int tryLock(int ringIndex, int keyIndex, string ring, string key, int minSteps) {
        // If we reach the end of the key, it has been spelled
        if (keyIndex == key.length()) {
            return 0;
        }
        // For each occurrence of the character at index key_index of key in ring
        // Calculate the minimum steps to that character from the ringIndex of ring
        for (int i = 0; i < ring.length(); i++) {
            if (ring[i] == key[keyIndex]) {
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 +
                                            tryLock(i, keyIndex + 1, ring, key, INT_MAX);
                minSteps = min(minSteps, totalSteps);
            }
        }
        return minSteps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static final int MAX = Integer.MAX_VALUE;

    public int findRotateSteps(String ring, String key) {
        return tryLock(0, 0, ring, key, MAX);
    }

    // Find the minimum steps between two indexes of ring
    private int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = Math.abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return Math.min(stepsBetween, stepsAround);
    }

    // Find the minimum number of steps to spell the keyword
    public int tryLock(int ringIndex, int keyIndex, String ring, String key, int minSteps) {
        // If we reach the end of the key, it has been spelled
        if (keyIndex == key.length()) {
            return 0;
        }
        // For each occurrence of the character at key_index of key in ring
        // Calculate the minimum steps to that character from the ringIndex of ring
        for (int i = 0; i < ring.length(); i++) {
            if (ring.charAt(i) == key.charAt(keyIndex)) {
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 + 
                                            tryLock(i, keyIndex + 1, ring, key, MAX);
                minSteps = Math.min(minSteps, totalSteps);
            }
        }
        return minSteps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        ring_len = len(ring)
        key_len = len(key)

        # Find the minimum steps between two indexes of ring
        def count_steps(curr, next):
            steps_between = abs(curr - next)
            steps_around = ring_len - steps_between
            return min(steps_between, steps_around)

        # Find the minimum number of steps to spell the keyword
        def try_lock(ring_index, key_index, min_steps):
            # If we reach the end of the key, it has been spelled
            if key_index == len(key):
                return 0
            # For each occurrence of the character k[key_index] in ring
            # calculate the minimum steps from the ring_index of ring
            for i in range(len(ring)):
                if ring[i] == key[key_index]:
                    total_steps = count_steps(ring_index, i) + 1 + \
                                              try_lock(i, key_index + 1, inf)
                    min_steps = min(min_steps, total_steps)
            return min_steps
    
        return try_lock(0, 0, inf)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringLen = ring.length();
        int keyLen = key.length();
        vector<vector<int>> bestSteps(ringLen, vector<int>(keyLen + 1, INT_MAX));
        // Initialize values of best_steps to largest integer
        for (auto& row : bestSteps) {
            fill(row.begin(), row.end(), INT_MAX);
        }
        // Initialize last column to zero to represent the word has been spelled
        for (int i = 0; i < ringLen; i++) {
            bestSteps[i][keyLen] = 0;
        }
        // For each occurrence of the character at key_index of key in ring
        // Stores minimum steps to the character from ringIndex of ring
        for (int keyIndex = keyLen - 1; keyIndex >= 0; keyIndex--) {
            for (int ringIndex = 0; ringIndex < ringLen; ringIndex++) {
                for (int charIndex = 0; charIndex < ringLen; charIndex++) {
                    if (ring[charIndex] == key[keyIndex]) {
                        bestSteps[ringIndex][keyIndex] = min(bestSteps[ringIndex][keyIndex],
                                1 + countSteps(ringIndex, charIndex, ringLen) 
                                + bestSteps[charIndex][keyIndex + 1]);
                    }
                }
            }
        }

        return bestSteps[0][0];
    }

private:
    // Find the minimum steps between two indexes of ring
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findRotateSteps(String ring, String key) {
        int ringLen = ring.length();
        int keyLen = key.length();
        int[][] bestSteps = new int[ringLen][keyLen + 1];
        // Initialize values of best_steps to largest integer
        for (int[] row : bestSteps) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        // Initialize last column to zero to represent the word has been spelled 
        for (int i = 0; i < ring.length(); i++) {
            bestSteps[i][keyLen] = 0;
        }
        // For each occurrence of the character at keyIndex of key in ring
        // Stores minimum steps to the character from ringIndex of ring
        for (int keyIndex = keyLen - 1; keyIndex >= 0; keyIndex--) {
            for (int ringIndex = 0; ringIndex < ringLen; ringIndex++) {
                for (int charIndex = 0; charIndex < ringLen; charIndex++) {
                    if (ring.charAt(charIndex) == key.charAt(keyIndex)) {
                        bestSteps[ringIndex][keyIndex] = Math.min(bestSteps[ringIndex][keyIndex],
                                1 + countSteps(ringIndex, charIndex, ringLen)
                                + bestSteps[charIndex][keyIndex + 1]);
                    }
                }
            }
        }
        return bestSteps[0][0];
    }

    // Find the minimum steps between two indexes of ring
    private int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = Math.abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return Math.min(stepsBetween, stepsAround);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        ring_len = len(ring)
        key_len = len(key)
        # Initialize values of best_steps to largest integer
        best_steps = [[inf] * (key_len + 1) for _ in range(ring_len)]

        # Find the minimum steps between two indexes of ring
        def count_steps(curr, next):
            steps_between = abs(curr - next)
            steps_around = ring_len - steps_between
            return min(steps_between, steps_around)

        # Initialize last column to 0 to represent the word has been spelled 
        for row in best_steps:
            row[key_len] = 0
        
        # For each occurrence of the character at key_index of key in ring
        # Stores minimum steps to the character from the ring_index of ring
        for key_index in range(key_len - 1, -1, -1):
            for ring_index in range(ring_len):
                for char_index in range(ring_len):
                    if ring[char_index] == key[key_index]:
                        best_steps[ring_index][key_index] = min(
                                best_steps[ring_index][key_index],
                                1 + count_steps(ring_index, char_index) 
                                + best_steps[char_index][key_index + 1])

        return best_steps[0][0]
```

</details>

<br>

## Approach 3: Space-Optimized Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringLen = ring.length();
        int keyLen = key.length();
        vector<int> curr(ringLen, 0);
        vector<int> prev(ringLen, 0);
        fill(prev.begin(), prev.end(), 0);
        // For each occurrence of the character at key_index of key in ring
        // Stores minimum steps to the character from ringIndex of ring
        for (int keyIndex = keyLen - 1; keyIndex >= 0; keyIndex--) {
            fill(curr.begin(), curr.end(), INT_MAX);
            for (int ringIndex = 0; ringIndex < ringLen; ringIndex++) {
                for (int charIndex = 0; charIndex < ringLen; charIndex++) {
                    if (ring[charIndex] == key[keyIndex]) {
                        curr[ringIndex] = min(curr[ringIndex],
                                1 + countSteps(ringIndex, charIndex, ringLen) + prev[charIndex]);
                    }
                }
            }
            prev = curr;
        }

        return prev[0];
    }

private:
    // Find the minimum steps between two indexes of ring
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findRotateSteps(String ring, String key) {
        int ringLen = ring.length();
        int keyLen = key.length();
        int[] curr = new int[ringLen];
        int[] prev = new int[ringLen];
        Arrays.fill(prev, 0);
        // For each occurrence of the character at key_index of key in ring
        // Stores minimum steps to the character from ringIndex of ring
        for (int keyIndex = keyLen - 1; keyIndex >= 0; keyIndex--) {
            Arrays.fill(curr, Integer.MAX_VALUE);
            for (int ringIndex = 0; ringIndex < ringLen; ringIndex++) {
                for (int charIndex = 0; charIndex < ringLen; charIndex++) {
                    if (ring.charAt(charIndex) == key.charAt(keyIndex)) {
                        curr[ringIndex] = Math.min(curr[ringIndex],
                                1 + countSteps(ringIndex, charIndex, ringLen) + prev[charIndex]);
                    }
                }
            }
            prev = curr.clone();
        }
        return prev[0];
    }

    // Find the minimum steps between two indexes of ring
    private int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = Math.abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return Math.min(stepsBetween, stepsAround);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        ring_len = len(ring)
        key_len = len(key)
        curr = [inf for _ in range(ring_len)]
        prev = [0 for _ in range(ring_len)]

        # Find the minimum steps between two indexes of ring
        def count_steps(curr, next):
            steps_between = abs(curr - next)
            steps_around = ring_len - steps_between
            return min(steps_between, steps_around)

        # For each occurrence of the character at keyIndex of key in ring
        # Stores minimum steps to the character from ring_index of ring
        for key_index in range(key_len - 1, -1, -1):
            curr = [inf for _ in range(ring_len)]
            for ring_index in range(ring_len):
                for character in range(ring_len):
                    if ring[character] == key[key_index]:
                        curr[ring_index] = min(curr[ring_index],
                                1 + count_steps(ring_index, character)
                                + prev[character])
            prev = curr.copy()

        return prev[0]
```

</details>

<br>

## Approach 4: Shortest Path

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringLen = ring.length();
        int keyLen = key.length();
        
        // HashMap to store the indices of occurrences of each character in the ring
        unordered_map<char, vector<int>> characterIndices;
        for (int i = 0; i < ring.length(); i++) {
            char ch = ring[i];
            characterIndices[ch].push_back(i);
        }

        // Initialize the heap (priority queue) with the starting point
        // Each element of the heap is a vector of integers representing:
        // totalSteps, ringIndex, keyIndex
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        heap.push({0, 0, 0});

        // HashSet to keep track of visited states
        unordered_set<string> seen;
        
        // Spell the keyword using the metal dial
        int totalSteps = 0;
        while (!heap.empty()) {
            // Pop the element with the smallest total steps from the heap
            vector<int> state = heap.top();
            heap.pop();
            totalSteps = state[0];
            int ringIndex = state[1];
            int keyIndex = state[2];
            
            // We have spelled the keyword
            if (keyIndex == keyLen) {
                break;
            }
            
            // Continue if we have visited this character from this position in ring before
            string currentState = to_string(ringIndex) + "-" + to_string(keyIndex);
            if (seen.count(currentState)) {
                continue;
            }

            // Otherwise, add this pair to the visited list
            seen.insert(currentState);
            
            // Add the rest of the occurrences of this character in ring to the heap
            for (int nextIndex : characterIndices[key[keyIndex]]) {
                heap.push({totalSteps + countSteps(ringIndex, nextIndex, ringLen), 
                            nextIndex, keyIndex + 1});
            }
        }
        
        // Return the total steps and add keyLen to account for 
        // pressing the center button for each character in the keyword
        return totalSteps + keyLen;
    }

private:
    // Find the minimum steps between two indexes of ring
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findRotateSteps(String ring, String key) {
        int ringLen = ring.length();
        int keyLen = key.length();

        // HashMap to store the indices of occurrences of each character in the ring
        Map<Character, List<Integer>> characterIndices = new HashMap<>();
        for (int i = 0; i < ring.length(); i++) {
            char ch = ring.charAt(i);
            characterIndices.computeIfAbsent(ch, k -> new ArrayList<>()).add(i);
        }

        // Initialize the min heap (priority queue) with the starting point
        // Each element of the heap is an array of integers representing:
        // totalSteps, ringIndex, keyIndex
        PriorityQueue<int[]> heap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
                                                                                             
        heap.offer(new int[] { 0, 0, 0 });

        // HashSet to keep track of visited states
        Set<Pair<Integer, Integer>> seen = new HashSet<>();

        // Spell the keyword using the metal dial
        int totalSteps = 0;
        while (!heap.isEmpty()) {
            // Pop the element with the smallest total steps from the heap
            int[] state = heap.poll();
            totalSteps = state[0];
            int ringIndex = state[1];
            int keyIndex = state[2];

            // We have spelled the keyword
            if (keyIndex == keyLen) {
                break;
            }

            // Continue if we have visited this character from this position in ring before
            Pair<Integer, Integer> currentState = new Pair<>(ringIndex, keyIndex);
            if (seen.contains(currentState)) {
                continue;
            }

            // Otherwise, add this pair to the visited list
            seen.add(currentState);

            // Add the rest of the occurrences of this character in ring to the heap
            for (int nextIndex : characterIndices.get(key.charAt(keyIndex))) {
                heap.offer(
                        new int[] {totalSteps + countSteps(ringIndex, nextIndex, ringLen),
                                    nextIndex, keyIndex + 1});
            }
        }

        // Return the total steps and add keyLen to account for 
        // pressing the center button for each character in the keyword
        return totalSteps + keyLen;
    }

    // Find the minimum steps between two indexes of ring
    private int countSteps(int curr, int next, int ringLen) {
        int stepsBetween = Math.abs(curr - next);
        int stepsAround = ringLen - stepsBetween;
        return Math.min(stepsBetween, stepsAround);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        ring_len = len(ring)
        key_len = len(key)
        
        # Find the minimum steps between two indexes of ring
        def count_steps(curr, next):
            steps_between = abs(curr - next)
            steps_around = ring_len - steps_between
            return min(steps_between, steps_around)
        
        # HashMap to store the indices of occurrences 
        # of each character in the ring
        character_indicies = collections.defaultdict(list)
        for i, char in enumerate(ring):
            character_indicies[char].append(i)
        
        # Initialize the heap (priority queue) with the starting point
        # Each element of the heap is a tuple of integers representing:
        # totalSteps, ringIndex, keyIndex
        heap = [(0, 0, 0)]
        # tuple in seen: (ringIndex, keyIndex)
        seen = set()
        
        # Spell the keyword using the metal dial
        while heap:
            # Pop the element with the smallest total steps from the heap
            total_steps, ring_index, key_index = heapq.heappop(heap)

            # We have spelled the keyword
            if key_index == key_len:
                break

            # Continue if we have visited this character 
            # from this position in ring before
            if (ring_index, key_index) in seen:
                continue

            # Otherwise, add this pair to the visited list
            seen.add((ring_index, key_index))

            # Add the rest of the occurrences 
            # of this character in ring to the heap
            for next_index in character_indicies[key[key_index]]:
                heapq.heappush(
                        heap, 
                        (total_steps + count_steps(ring_index, next_index),
                        next_index, key_index + 1))

        # Return the total steps and add keyLen to account for 
        # pressing the center button for each character in the keyword
        return total_steps + key_len
```

</details>
