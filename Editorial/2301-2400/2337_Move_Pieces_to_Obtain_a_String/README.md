# 2337. Move Pieces to Obtain a String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/move-pieces-to-obtain-a-string/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 2337 - Move Pieces to Obtain a String](https://leetcode.com/problems/move-pieces-to-obtain-a-string/)

## Problem

You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

- The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
- The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.

Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.

### Example 1

```text
Input: start = "_L__R__R_", target = "L______RR"
Output: true
Explanation: We can obtain the string target from start by doing the following moves:
- Move the first piece one step to the left, start becomes equal to "L___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___R".
- Move the second piece three steps to the right, start becomes equal to "L______RR".
Since it is possible to get the string target from start, we return true.
```

### Example 2

```text
Input: start = "R_L_", target = "__LR"
Output: false
Explanation: The 'R' piece in the string start can move one step to the right to obtain "_RL_".
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
```

### Example 3

```text
Input: start = "_R", target = "R_"
Output: false
Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.
```

## Constraints

- n == start.length == target.length
- 1 <= n <= 105
- start and target consist of the characters 'L', 'R', and '_'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Swap Adjacent in LR String](https://leetcode.com/problems/swap-adjacent-in-lr-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2337. Move Pieces to Obtain a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (Memory Limit Exceeded) | C++, Java, Python3 |
| Using Queue | C++, Java, Python3 |
| Two pointer | C++, Java, Python3 |

## Approach 1: Brute Force (Memory Limit Exceeded)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canChange(string start, string target) {
        // To keep track of visited states to avoid cycles
        unordered_set<string> visitedStates;
        // Queue for current state
        queue<string> stateQueue;
        // Start with the initial state
        stateQueue.push(start);

        while (!stateQueue.empty()) {
            string currentState = stateQueue.front();
            stateQueue.pop();

            // If we reach the target state, return true
            if (currentState == target) return true;

            for (int position = 1; position < currentState.size(); position++) {
                // Try moving 'L' to the left
                if (currentState[position] == 'L' &&
                    currentState[position - 1] == '_') {
                    swap(currentState[position], currentState[position - 1]);
                    if (visitedStates.find(currentState) ==
                        visitedStates.end()) {
                        // Add the new state to the queue
                        stateQueue.push(currentState);
                        // Mark the new state as visited
                        visitedStates.insert(currentState);
                    }
                    // Restore the state
                    swap(currentState[position], currentState[position - 1]);
                }
                // Try moving 'R' to the right
                if (currentState[position - 1] == 'R' &&
                    currentState[position] == '_') {
                    swap(currentState[position], currentState[position - 1]);
                    if (visitedStates.find(currentState) ==
                        visitedStates.end()) {
                        // Add the new state to the queue
                        stateQueue.push(currentState);
                        // Mark the new state as visited
                        visitedStates.insert(currentState);
                    }
                    // Restore the state
                    swap(currentState[position], currentState[position - 1]);
                }
            }
        }

        // If no valid transformation sequence is found, return false
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canChange(String start, String target) {
        // To keep track of visited states to avoid cycles
        Set<String> visitedStates = new HashSet<>();
        // Queue for current state
        Queue<String> stateQueue = new LinkedList<>();
        // Start with the initial state
        stateQueue.add(start);

        while (!stateQueue.isEmpty()) {
            String currentState = stateQueue.poll();

            // If we reach the target state, return true
            if (currentState.equals(target)) return true;

            for (
                int position = 1;
                position < currentState.length();
                position++
            ) {
                // Try moving 'L' to the left
                if (
                    currentState.charAt(position) == 'L' &&
                    currentState.charAt(position - 1) == '_'
                ) {
                    char[] stateArray = currentState.toCharArray();
                    swap(stateArray, position, position - 1);
                    String newState = new String(stateArray);
                    if (!visitedStates.contains(newState)) {
                        // Add the new state to the queue
                        stateQueue.add(newState);
                        // Mark the new state as visited
                        visitedStates.add(newState);
                    }
                    // Restore the state
                    swap(stateArray, position, position - 1);
                }
                // Try moving 'R' to the right
                if (
                    currentState.charAt(position - 1) == 'R' &&
                    currentState.charAt(position) == '_'
                ) {
                    char[] stateArray = currentState.toCharArray();
                    swap(stateArray, position, position - 1);
                    String newState = new String(stateArray);
                    if (!visitedStates.contains(newState)) {
                        // Add the new state to the queue
                        stateQueue.add(newState);
                        // Mark the new state as visited
                        visitedStates.add(newState);
                    }
                    // Restore the state
                    swap(stateArray, position, position - 1);
                }
            }
        }

        // If no valid transformation sequence is found, return false
        return false;
    }

    private void swap(char[] array, int i, int j) {
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        # To keep track of visited states to avoid cycles
        visited_states = set()

        # Queue for current state
        state_queue = []
        # Start with the initial state
        state_queue.append(start)

        while state_queue:
            current_state = state_queue.pop(0)

            # If we reach the target state, return true
            if current_state == target:
                return True

            for position in range(1, len(current_state)):
                # Try moving 'L' to the left
                if (
                    current_state[position] == "L"
                    and current_state[position - 1] == "_"
                ):
                    current_state = list(current_state)
                    current_state[position], current_state[position - 1] = (
                        current_state[position - 1],
                        current_state[position],
                    )
                    current_state = "".join(current_state)
                    if current_state not in visited_states:
                        # Add the new state to the queue
                        state_queue.append(current_state)
                        # Mark the new state as visited
                        visited_states.add(current_state)
                    # Restore the state
                    current_state = list(current_state)
                    current_state[position], current_state[position - 1] = (
                        current_state[position - 1],
                        current_state[position],
                    )
                    current_state = "".join(current_state)

                # Try moving 'R' to the right
                if (
                    position < len(current_state) - 1
                    and current_state[position] == "R"
                    and current_state[position + 1] == "_"
                ):
                    current_state = list(current_state)
                    current_state[position], current_state[position + 1] = (
                        current_state[position + 1],
                        current_state[position],
                    )
                    current_state = "".join(current_state)
                    if current_state not in visited_states:
                        # Add the new state to the queue
                        state_queue.append(current_state)
                        # Mark the new state as visited
                        visited_states.add(current_state)
                    # Restore the state
                    current_state = list(current_state)
                    current_state[position], current_state[position + 1] = (
                        current_state[position + 1],
                        current_state[position],
                    )
                    current_state = "".join(current_state)

        # If no valid transformation sequence is found, return false
        return False
```

</details>

<br>

## Approach 2: Using Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canChange(string start, string target) {
        // Queue to store characters and indices from both strings
        queue<pair<char, int>> startQueue, targetQueue;

        // Record non-underscore characters and their indices
        for (int i = 0; i < start.size(); i++) {
            if (start[i] != '_') {
                startQueue.push({start[i], i});
            }
            if (target[i] != '_') {
                targetQueue.push({target[i], i});
            }
        }

        // If number of pieces don't match, return false
        if (startQueue.size() != targetQueue.size()) return false;

        // Compare each piece's type and position
        while (!startQueue.empty()) {
            auto [startChar, startIndex] = startQueue.front();
            startQueue.pop();
            auto [targetChar, targetIndex] = targetQueue.front();
            targetQueue.pop();

            // Check character match and movement rules
            if (startChar != targetChar ||
                (startChar == 'L' && startIndex < targetIndex) ||
                (startChar == 'R' && startIndex > targetIndex))
                return false;
        }

        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canChange(String start, String target) {
        // Queue to store characters and indices from both strings
        Queue<Pair<Character, Integer>> startQueue =
            new LinkedList<>(), targetQueue = new LinkedList<>();

        // Record non-underscore characters and their indices
        for (int i = 0; i < start.length(); i++) {
            if (start.charAt(i) != '_') {
                startQueue.add(new Pair<>(start.charAt(i), i));
            }
            if (target.charAt(i) != '_') {
                targetQueue.add(new Pair<>(target.charAt(i), i));
            }
        }

        // If number of pieces don't match, return false
        if (startQueue.size() != targetQueue.size()) return false;

        // Compare each piece's type and position
        while (!startQueue.isEmpty()) {
            Pair<Character, Integer> startPair = startQueue.poll();
            Pair<Character, Integer> targetPair = targetQueue.poll();

            char startChar = startPair.getKey();
            int startIndex = startPair.getValue();
            char targetChar = targetPair.getKey();
            int targetIndex = targetPair.getValue();

            // Check character match and movement rules
            if (
                startChar != targetChar ||
                (startChar == 'L' && startIndex < targetIndex) ||
                (startChar == 'R' && startIndex > targetIndex)
            ) {
                return false;
            }
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        # Queue to store characters and indices from both strings
        start_queue = []
        target_queue = []

        # Record non-underscore characters and their indices
        for i in range(len(start)):
            if start[i] != "_":
                start_queue.append((start[i], i))
            if target[i] != "_":
                target_queue.append((target[i], i))

        # If number of pieces don't match, return false
        if len(start_queue) != len(target_queue):
            return False

        # Compare each piece's type and position
        while not len(start_queue) == 0:
            start_char, start_index = start_queue.pop(0)
            target_char, target_index = target_queue.pop(0)

            # Check character match and movement rules
            if (
                start_char != target_char
                or (start_char == "L" and start_index < target_index)
                or (start_char == "R" and start_index > target_index)
            ):
                return False

        return True
```

</details>

<br>

## Approach 3: Two pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canChange(string start, string target) {
        int startLength = start.size();
        // Pointer for start string and target string
        int startIndex = 0, targetIndex = 0;

        while (startIndex < startLength || targetIndex < startLength) {
            // Skip underscores in start
            while (startIndex < startLength && start[startIndex] == '_') {
                startIndex++;
            }
            // Skip underscores in target
            while (targetIndex < startLength && target[targetIndex] == '_') {
                targetIndex++;
            }
            // If one string is exhausted, both should be exhausted
            if (startIndex == startLength || targetIndex == startLength) {
                return startIndex == startLength && targetIndex == startLength;
            }

            // Check if the pieces match and follow movement rules
            if (start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex))
                return false;

            startIndex++;
            targetIndex++;
        }

        // If all conditions are satisfied, return true
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean canChange(String start, String target) {
        int startLength = start.length();
        // Pointers for start string and target string
        int startIndex = 0, targetIndex = 0;

        while (startIndex < startLength || targetIndex < startLength) {
            // Skip underscores in start
            while (
                startIndex < startLength && start.charAt(startIndex) == '_'
            ) {
                startIndex++;
            }
            // Skip underscores in target
            while (
                targetIndex < startLength && target.charAt(targetIndex) == '_'
            ) {
                targetIndex++;
            }
            // If one string is exhausted, both should be exhausted
            if (startIndex == startLength || targetIndex == startLength) {
                return startIndex == startLength && targetIndex == startLength;
            }

            // Check if the pieces match and follow movement rules
            if (
                start.charAt(startIndex) != target.charAt(targetIndex) ||
                (start.charAt(startIndex) == 'L' && startIndex < targetIndex) ||
                (start.charAt(startIndex) == 'R' && startIndex > targetIndex)
            ) return false;

            startIndex++;
            targetIndex++;
        }

        // If all conditions are satisfied, return true
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        start_length = len(start)
        # pointers for start string and target string
        start_index, target_index = (0, 0)

        while start_index < start_length or target_index < start_length:
            # skip underscores in start
            while start_index < start_length and start[start_index] == "_":
                start_index += 1

            # skip underscores in target
            while target_index < start_length and target[target_index] == "_":
                target_index += 1

            # if one string exhausted, both strings should be exhausted
            if start_index == start_length or target_index == start_length:
                return (
                    start_index == start_length and target_index == start_length
                )

            # check if the pieces match and follow movement rules
            if (
                start[start_index] != target[target_index]
                or (start[start_index] == "L" and start_index < target_index)
                or (start[start_index] == "R" and start_index > target_index)
            ):
                return False

            start_index += 1
            target_index += 1

        # if all conditions satisfied, return true
        return True
```

</details>
