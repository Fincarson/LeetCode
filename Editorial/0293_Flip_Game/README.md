# 293. Flip Game

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/flip-game/)  
`String`

**Problem Link:** [LeetCode 293 - Flip Game](https://leetcode.com/problems/flip-game/)

## Problem

You are playing a Flip Game with your friend.

You are given a string currentState that contains only '+' and '-'. You and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move, and therefore the other person will be the winner.

Return all possible states of the string currentState after one valid move. You may return the answer in any order. If there is no valid move, return an empty list [].

### Example 1

```text
Input: currentState = "++++"
Output: ["--++","+--+","++--"]
```

### Example 2

```text
Input: currentState = "+"
Output: []
```

## Constraints

- 1 <= currentState.length <= 500
- currentState[i] is either '+' or '-'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Flip Game II](https://leetcode.com/problems/flip-game-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 293. Flip Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Linear Iteration | C, C++, Go, Java, JavaScript, Python3 |

## Approach: Linear Iteration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char** generatePossibleNextMoves(char* currentState, int* returnSize) {
    // Initialize the return size.
    *returnSize = 0;
    // Allocate memory for the array of strings.
    char** nextPossibleStates = NULL;

    // Iterate through the 'currentState' string characters from left to right.
    for (size_t index = 0; index < strlen(currentState) - 1; ++index) {
        // If two adjacent characters of the 'currentState' string are '+', 
        // replace them with '-' and store the new state string.
        if (currentState[index] == '+' && currentState[index + 1] == '+') {
            // Allocate memory for the next state string.
            char* nextState = malloc((strlen(currentState) + 1) * sizeof(char));
            strcpy(nextState, currentState);
            nextState[index] = '-';
            nextState[index + 1] = '-';

            // Resize the array to store the new state.
            nextPossibleStates = realloc(nextPossibleStates, (*returnSize + 1) * sizeof(char*));
            nextPossibleStates[*returnSize] = nextState;
            ++(*returnSize);
        }
    }

    return nextPossibleStates;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        // Array to store all possible next states after making one move.
        vector<string> nextPossibleStates;

        // Iterate through the 'currentState' string characters from left to right.
        for (int index = 0; index < currentState.size() - 1; ++index) {
            // If two adjacent characters of the 'currentState' string are '+', 
            // replace them with '-' and store the new state string.
            if (currentState[index] == '+' and currentState[index + 1] == '+') {
                string nextState = (
                    currentState.substr(0, index) + 
                    "--" + 
                    currentState.substr(index + 2)
                );
                nextPossibleStates.push_back(nextState);
            }
        }
        // Return the 'nextPossibleStates' array.
        return nextPossibleStates;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func generatePossibleNextMoves(currentState string) []string {
    // Slice to store all possible next states after making one move.
	var nextPossibleStates []string

	// Iterate through the 'currentState' string characters from left to right.
	for index := 0; index < len(currentState)-1; index++ {
		// If two adjacent characters of the 'currentState' string are '+', 
		// replace them with '-' and store the new state string.
		if currentState[index] == '+' && currentState[index+1] == '+' {
			nextState := currentState[:index] + "--" + currentState[index+2:]
			nextPossibleStates = append(nextPossibleStates, nextState)
		}
	}

	// Return 'nextPossibleStates' slice.
	return nextPossibleStates
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> generatePossibleNextMoves(String currentState) {
        // List to store all possible next states after making one move.
        List<String> nextPossibleStates = new ArrayList<>();

        // Iterate through the 'currentState' string characters from left to right.
        for (int index = 0; index < currentState.length() - 1; ++index) {
            // If two adjacent characters of the 'currentState' string are '+', 
            // replace them with '-' and store the new state string.
            if (currentState.charAt(index) == '+' && currentState.charAt(index + 1) == '+') {
                String nextState = (
                    currentState.substring(0, index) + 
                    "--" + 
                    currentState.substring(index + 2)
                );
                nextPossibleStates.add(nextState);
            }
        }

        // Return 'nextPossibleStates' list.
        return nextPossibleStates;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var generatePossibleNextMoves = function(currentState) {
    // Array to store all possible next states after making one move.
    const nextPossibleStates = [];

    // Iterate through the 'currentState' string characters from left to right.
    for (let index = 0; index < currentState.length - 1; ++index) {
        // If two adjacent characters of the 'currentState' string are '+', 
        // replace them with '-' and store the new state string.
        if (currentState[index] === '+' && currentState[index + 1] === '+') {
            const nextState = (
                  currentState.substring(0, index) + 
                  "--" + 
                  currentState.substring(index + 2)
            );
            nextPossibleStates.push(nextState);
        }
    }

    // Return 'nextPossibleStates' array.
    return nextPossibleStates;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        # List to store all possible next states after making one move.
        next_possible_states = []

        # Iterate through the 'currentState' string characters from left to right.
        for index in range(len(currentState) - 1):
            # If two adjacent characters of the 'currentState' string are '+', 
            # replace them with '-' and store the new state string.
            if currentState[index] == '+' and currentState[index + 1] == '+':
                next_state = currentState[:index] + "--" + currentState[index + 2:]
                next_possible_states.append(next_state)

        # Return 'next_possible_states' list.
        return next_possible_states
```

</details>
