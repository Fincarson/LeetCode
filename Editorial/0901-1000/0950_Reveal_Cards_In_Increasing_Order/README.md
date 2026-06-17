# 950. Reveal Cards In Increasing Order

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/reveal-cards-in-increasing-order/)  
`Array` `Queue` `Sorting` `Simulation`

**Problem Link:** [LeetCode 950 - Reveal Cards In Increasing Order](https://leetcode.com/problems/reveal-cards-in-increasing-order/)

## Problem

You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.

### Example 1

```text
Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation:
We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.
```

### Example 2

```text
Input: deck = [1,1000]
Output: [1,1000]
```

## Constraints

- 1 <= deck.length <= 1000
- 1 <= deck[i] <= 106
- All the values of deck are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 950. Reveal Cards In Increasing Order

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers | C++, Java, Python3 |
| Simulation with Queue | C++, Java, Python3 |

## Approach 1: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        vector<int> result(N);
        bool skip = false;
        int indexInDeck = 0;
        int indexInResult = 0;

        sort(deck.begin(), deck.end());

        while (indexInDeck < N) {
            // There is an available gap in result
            if (result[indexInResult] == 0) {

                // Add a card to result
                if (!skip) {
                    result[indexInResult] = deck[indexInDeck];
                    indexInDeck++;
                }

                // Toggle skip to alternate between adding and skipping cards
                skip = !skip;
            }
            // Progress to the next index of result array
            indexInResult = (indexInResult + 1) % N;
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int N = deck.length;
        int[] result = new int[N];
        boolean skip = false;
        int indexInDeck = 0;
        int indexInResult = 0;

        Arrays.sort(deck);

        while (indexInDeck < N) {
            // There is an available gap in result
            if (result[indexInResult] == 0) {

                // Add a card to result
                if (!skip) {
                    result[indexInResult] = deck[indexInDeck];
                    indexInDeck++;
                }

                // Toggle skip to alternate between adding and skipping cards
                skip = !skip;
            }
            // Progress to next index of result array
            indexInResult = (indexInResult + 1) % N;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        N = len(deck)
        result = [0] * N
        skip = False
        index_in_deck = 0
        index_in_result = 0

        deck.sort()

        while index_in_deck < N:
            # There is an available gap in result
            if result[index_in_result] == 0:

                # Add a card to result
                if not skip:
                    result[index_in_result] = deck[index_in_deck]
                    index_in_deck += 1

                # Toggle skip to alternate between adding and skipping cards
                skip = not skip

            # Progress to the next index of result array
            index_in_result = (index_in_result + 1) % N

        return result
```

</details>

<br>

## Approach 2: Simulation with Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        queue<int> queue;

        // Create a queue of indexes
        for (int i = 0; i < N; i++) {
            queue.push(i);
        }
        
        sort(deck.begin(), deck.end());

        // Put cards at correct index in result
        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            // Reveal Card
            result[queue.front()] = deck[i];
            queue.pop();

            // Move next card to bottom
            if (!queue.empty()) {
                queue.push(queue.front());
                queue.pop();
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int N = deck.length;
        Queue<Integer> queue = new LinkedList<>();

        // Create a queue of indexes
        for (int i = 0; i < N; i++) {
            queue.add(i);
        }
        
        Arrays.sort(deck);

        // Put cards at correct index in result
        int[] result = new int[N];
        for (int i = 0; i < N; i++) {
            // Reveal Card and place in result
            result[queue.poll()] = deck[i];

            // Move next card to bottom
            queue.add(queue.poll());
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        N = len(deck)
        queue = deque()

        # Create a queue of indexes
        for i in range(N):
            queue.append(i)
        
        deck.sort()

        # Put cards at correct index in result
        result = [0] * N
        for card in deck:
            # Reveal Card
            result[queue.popleft()] = card

            # Move next card to bottom
            if queue:
                queue.append(queue.popleft())
                
        return result
```

</details>
