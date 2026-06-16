# 1908. Game of Nim

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/game-of-nim/)  
`Array` `Math` `Dynamic Programming` `Bit Manipulation` `Brainteaser` `Game Theory`

**Problem Link:** [LeetCode 1908 - Game of Nim](https://leetcode.com/problems/game-of-nim/)

## Problem

Alice and Bob take turns playing a game with Alice starting first.

In this game, there are n piles of stones. On each player's turn, the player should remove any positive number of stones from a non-empty pile of his or her choice. The first player who cannot make a move loses, and the other player wins.

Given an integer array piles, where piles[i] is the number of stones in the ith pile, return true if Alice wins, or false if Bob wins.

Both Alice and Bob play optimally.

### Example 1

```text
Input: piles = [1]
Output: true
Explanation: There is only one possible scenario:
- On the first turn, Alice removes one stone from the first pile. piles = [0].
- On the second turn, there are no stones left for Bob to remove. Alice wins.
```

### Example 2

```text
Input: piles = [1,1]
Output: false
Explanation: It can be proven that Bob will always win. One possible scenario is:
- On the first turn, Alice removes one stone from the first pile. piles = [0,1].
- On the second turn, Bob removes one stone from the second pile. piles = [0,0].
- On the third turn, there are no stones left for Alice to remove. Bob wins.
```

### Example 3

```text
Input: piles = [1,2,3]
Output: false
Explanation: It can be proven that Bob will always win. One possible scenario is:
- On the first turn, Alice removes three stones from the third pile. piles = [1,2,0].
- On the second turn, Bob removes one stone from the second pile. piles = [1,1,0].
- On the third turn, Alice removes one stone from the first pile. piles = [0,1,0].
- On the fourth turn, Bob removes one stone from the second pile. piles = [0,0,0].
- On the fifth turn, there are no stones left for Alice to remove. Bob wins.
```

## Constraints

- n == piles.length
- 1 <= n <= 7
- 1 <= piles[i] <= 7

Follow-up: Could you find a linear time solution? Although the linear time solution may be beyond the scope of an interview, it could be interesting to know.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subtree Removal Game with Fibonacci Tree](https://leetcode.com/problems/subtree-removal-game-with-fibonacci-tree/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1908. Game of Nim

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation - Dynamic Programming | Java, JavaScript, Python3 |
| Mathematical / Bit Manipulation | Java, JavaScript, Python3 |

## Approach 1: Simulation - Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean nimGame(int[] piles) {
        // The count of stones remaining, we recurse until
        // the count becomes zero.
        int remaining = Arrays.stream(piles).sum();

        // Hash map for memoization.
        Map<String, Boolean> memo = new HashMap<>();

        // Is the person to play next the winner?
        // The first person to play is Alice at the beginning.
        // So, if Alice wins, it is going to be true, otherwise
        // it is going to be false.
        return isNextPersonWinner(piles, remaining, memo);
    }
    
    private boolean isNextPersonWinner(int[] piles, int remaining, Map<String, Boolean> memo) {
        // Make a key by concatenating the count of stones
        // in each pile, so key for the state [1, 2, 3] => '1-2-3'.
        String key = getKey(piles);

        // Have we come across this state already?
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        // The current player has no more moves left, so they
        // lose the game.
        if (remaining == 0) {
            return false;
        }

        // Generate all possible next moves and check if
        // the opponent loses the game in any of them.
        for (int i = 0; i < piles.length; i++) {
            // piles[i] is greater than 0.
            for (int j = 1; j <= piles[i]; j++) {
                piles[i] -= j;

                // Next state is created by making a copy of the
                // current state array, and sorting it in ascending
                // order of pile heights.
                int[] nextState = piles.clone();
                Arrays.sort(nextState);

                // If the opponent loses, that means we win.
                if (!isNextPersonWinner(nextState, remaining - j, memo)) {
                    memo.put(key, true);
                    return true;
                }
                piles[i] += j;
            }
        }

        // If none returned false for the opponent, we must have
        // lost the game.
        memo.put(key, false);
        return false;
    }
    
    private String getKey(int[] piles) {
        StringBuilder key = new StringBuilder();
        for (int height: piles) {
            key.append(height).append("-");
        }
        return key.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function nimGame(piles) {
    // The count of stones remaining, we recurse until
    // the count becomes zero.
    let remaining = piles.reduce((a, b) => (a + b), 0);
    
    // Hash map for memoization
    let memo = new Map();

    // Is the person to play next the winner?
    // The first person to play is Alice at the beginning.
    // So, if Alice wins, it is going to be true, otherwise
    // it is going to be false.
    return isNextPersonWinner(piles, remaining, memo);
};

function isNextPersonWinner(piles, remaining, memo) {
    // Make a key by concatenating the count of stones
    // in each pile, so key for the state [1, 2, 3] => '1-2-3'.
    const key = piles.join("-");
    
    // Have we come across this state already?
    if (memo.has(key)) {
        return memo.get(key);
    }
    
    // The current player has no more moves left, so they
    // lose the game.
    if (remaining === 0) {
        return false;
    }
    
    // Generate all possible next moves and check if
    // the opponent loses the game in any of them.
    for (let i = 0; i < piles.length; i++) {
        // piles[i] is greater than 0.
        for (let j = 1; j <= piles[i]; j++) {
            piles[i] -= j;
            
            // Next state is created by making a copy of the
            // current state array, and sorting it in ascending
            // order of pile heights.
            let nextState = piles.slice().sort((a, b) => (a - b))
            
            // If the opponent loses, that means we win.
            if (!isNextPersonWinner(nextState, remaining - j, memo)) {
                memo.set(key, true);
                return true;
            }
            piles[i] += j;
        }
    }

    // If none returned false for the opponent, we must have
    // lost the game.
    memo.set(key, false);
    return false;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nimGame(self, piles: List[int]) -> bool:
        # The count of stones remaining, we recurse until
        # the count becomes zero.
        remaining = sum(piles)

        # Hash map for memoization.
        memo = {}

        # Is the person to play next the winner?
        # The first person to play is Alice at the beginning.
        # So, if Alice wins, it is going to be true, otherwise
        # it is going to be a false.
        return self.__is_next_person_winner(piles, remaining, memo)

    def __is_next_person_winner(self, piles, remaining, memo):
        # Make a key by concatenating the count of stones
        # in each pile, so key for the state [1, 2, 3] => '1-2-3'.
        key = "-".join(map(str, piles))

        # Have we come across this state already?
        if key in memo:
            return memo[key]

        # The current player has no more moves left, so they
        # lose the game.
        if remaining == 0:
            return False

        # Generate all possible next moves, and check if
        # the opponent loses the game in any of them.
        for i in range(len(piles)):
            # piles[i] is greater than 0.
            for j in range(1, piles[i] + 1):
                piles[i] -= j

                # Next state is created by making a copy of the
                # current state array, and sorting it in ascending
                # order of pile heights.
                next_state = sorted(piles)

                # If the opponent loses, that means we win.
                if not self.__is_next_person_winner(next_state, remaining - j, memo):
                    memo[key] = True
                    return True
                piles[i] += j

        # If none returned false for the opponent, we must have
        # lost the game.
        memo[key] = False
        return False
```

</details>

<br>

## Approach 2: Mathematical / Bit Manipulation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean nimGame(int[] piles) {
        int nimSum = 0;
        for (int p : piles) {
            nimSum ^= p;
        }
        return nimSum != 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function nimGame(piles) {
    let nimSum = 0;
    for (let p of piles) {
        nimSum ^= p;
    }
    return nimSum != 0;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nimGame(self, piles: List[int]) -> bool:
        nim_sum = 0
        for p in piles:
            nim_sum ^= p
        return nim_sum != 0
```

</details>
