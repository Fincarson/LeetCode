# 846. Hand of Straights

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/hand-of-straights/)  
`Array` `Hash Table` `Greedy` `Sorting`

**Problem Link:** [LeetCode 846 - Hand of Straights](https://leetcode.com/problems/hand-of-straights/)

## Problem

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

### Example 1

```text
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
```

### Example 2

```text
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
```

## Constraints

- 1 <= hand.length <= 104
- 0 <= hand[i] <= 109
- 1 <= groupSize <= hand.length

Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 846. Hand of Straights

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Map | C++, Java, Python3 |
| Optimal | C++, Java, Python3 |
| Reverse Decrement (Most Optimal) | C++, Java, Python3 |

## Approach 1: Using Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int handSize = hand.size();

        if (handSize % groupSize != 0) {
            return false;
        }

        // Map to store the count of each card value
        map<int, int> cardCount;
        for (int i = 0; i < handSize; i++) {
            cardCount[hand[i]]++;
        }

        // Process the cards until the map is empty
        while (!cardCount.empty()) {
            // Get the smallest card value
            int currentCard = cardCount.begin()->first;
            // Check each consecutive sequence of groupSize cards
            for (int i = 0; i < groupSize; i++) {
                // If a card is missing or has exhausted its occurrences
                if (cardCount[currentCard + i] == 0) {
                    return false;
                }
                cardCount[currentCard + i]--;
                if (cardCount[currentCard + i] < 1) {
                    // Remove the card value if its occurrences are exhausted
                    cardCount.erase(currentCard + i);
                }
            }
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

    public boolean isNStraightHand(int[] hand, int groupSize) {
        int handSize = hand.length;
        if (handSize % groupSize != 0) {
            return false;
        }

        // TreeMap to store the count of each card value
        Map<Integer, Integer> cardCount = new TreeMap<>();
        for (int i = 0; i < handSize; i++) {
            cardCount.put(hand[i], cardCount.getOrDefault(hand[i], 0) + 1);
        }

        // Process the cards until the map is empty
        while (cardCount.size() > 0) {
            // Get the smallest card value
            int current_card = cardCount.entrySet().iterator().next().getKey();
            // Check each consecutive sequence of groupSize cards
            for (int i = 0; i < groupSize; i++) {
                // If a card is missing or has exhausted its occurrences
                if (!cardCount.containsKey(current_card + i)) return false;
                cardCount.put(
                    current_card + i,
                    cardCount.get(current_card + i) - 1
                );
                // Remove the card value if its occurrences are exhausted
                if (cardCount.get(current_card + i) == 0) cardCount.remove(
                    current_card + i
                );
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
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand_size = len(hand)

        if hand_size % groupSize != 0:
            return False

        # Counter to store the count of each card value
        card_count = Counter(hand)

        # Min-heap to process the cards in sorted order
        min_heap = list(card_count.keys())
        heapq.heapify(min_heap)

        # Process the cards until the heap is empty
        while min_heap:
            current_card = min_heap[0]  # Get the smallest card value
            # Check each consecutive sequence of groupSize cards
            for i in range(groupSize):
                if card_count[current_card + i] == 0:
                    return False
                card_count[current_card + i] -= 1
                if card_count[current_card + i] == 0:
                    if current_card + i != heapq.heappop(min_heap):
                        return False

        return True
```

</details>

<br>

## Approach 2: Optimal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Map to store the count of each card value
        map<int, int> cardCount;

        for (int card : hand) {
            cardCount[card]++;
        }

        // Queue to keep track of the number of new groups
        // starting with each card value
        queue<int> groupStartQueue;
        int lastCard = -1, currentOpenGroups = 0;

        for (auto& entry : cardCount) {
            int currentCard = entry.first;
            // Check if there are any discrepancies in the sequence
            // or more groups are required than available cards
            if ((currentOpenGroups > 0 && currentCard > lastCard + 1) ||
                currentOpenGroups > cardCount[currentCard]) {
                return false;
            }
            // Calculate the number of new groups starting
            // with the current card
            groupStartQueue.push(cardCount[currentCard] - currentOpenGroups);
            lastCard = currentCard;
            currentOpenGroups = cardCount[currentCard];
            // Maintain the queue size to be equal to groupSize
            if (groupStartQueue.size() == groupSize) {
                currentOpenGroups -= groupStartQueue.front();
                groupStartQueue.pop();
            }
        }

        // All groups should be completed by the end
        return currentOpenGroups == 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isNStraightHand(int[] hand, int groupSize) {
        // Map to store the count of each card value
        Map<Integer, Integer> cardCount = new TreeMap<>();

        for (int card : hand) {
            cardCount.put(card, cardCount.getOrDefault(card, 0) + 1);
        }

        // Queue to keep track of the number of new groups
        // starting with each card value
        Queue<Integer> groupStartQueue = new LinkedList<>();
        int lastCard = -1,
            currentOpenGroups = 0;
        for (Map.Entry<Integer, Integer> entry : cardCount.entrySet()) {
            int currentCard = entry.getKey();
            // Check if there are any discrepancies in the sequence
            // or more groups are required than available cards
            if (
                (currentOpenGroups > 0 && currentCard > lastCard + 1) ||
                currentOpenGroups > cardCount.get(currentCard)
            ) {
                return false;
            }
            // Calculate the number of new groups starting with the current card
            groupStartQueue.offer(
                cardCount.get(currentCard) - currentOpenGroups
            );
            lastCard = currentCard;
            currentOpenGroups = cardCount.get(currentCard);
            // Maintain the queue size to be equal to groupSize
            if (groupStartQueue.size() == groupSize) {
                currentOpenGroups -= groupStartQueue.poll();
            }
        }

        // All groups should be completed by the end
        return currentOpenGroups == 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        # Map to store the count of each card value
        cardCount = defaultdict(int)
        for card in hand:
            cardCount[card] += 1

        # Sorted list of card values
        sortedCards = sorted(cardCount.keys())
        # Queue to keep track of the number of new groups
        # starting with each card value
        groupStartQueue = deque()
        lastCard = -1
        currentOpenGroups = 0

        for currentCard in sortedCards:
            # Check if there are any discrepancies in the sequence
            # or more groups are required than available cards
            if (
                currentOpenGroups > 0 and currentCard > lastCard + 1
            ) or currentOpenGroups > cardCount[currentCard]:
                return False

            # Calculate the number of new groups starting
            # with the current card
            groupStartQueue.append(cardCount[currentCard] - currentOpenGroups)
            lastCard = currentCard
            currentOpenGroups = cardCount[currentCard]

            # Maintain the queue size to be equal to groupSize
            if len(groupStartQueue) == groupSize:
                currentOpenGroups -= groupStartQueue.popleft()

        # All groups should be completed by the end
        return currentOpenGroups == 0
```

</details>

<br>

## Approach 3: Reverse Decrement (Most Optimal)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // Map to store the count of each card value
        unordered_map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }

        for (int card : hand) {
            int startCard = card;
            // Find the start of the potential straight sequence
            while (cardCount[startCard - 1]) {
                startCard--;
            }

            // Process the sequence starting from startCard
            while (startCard <= card) {
                while (cardCount[startCard]) {
                    // Check if we can form a consecutive sequence of
                    // groupSize cards
                    for (int nextCard = startCard;
                         nextCard < startCard + groupSize; nextCard++) {
                        if (!cardCount[nextCard]) {
                            return false;
                        }
                        cardCount[nextCard]--;
                    }
                }
                startCard++;
            }
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

    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) {
            return false;
        }

        // HashMap to store the count of each card value
        HashMap<Integer, Integer> cardCount = new HashMap<>();
        for (int card : hand) {
            int count = cardCount.getOrDefault(card, 0);
            cardCount.put(card, count + 1);
        }

        for (int card : hand) {
            int startCard = card;
            // Find the start of the potential straight sequence
            while (cardCount.getOrDefault(startCard - 1, 0) > 0) {
                startCard--;
            }

            // Process the sequence starting from startCard
            while (startCard <= card) {
                while (cardCount.getOrDefault(startCard, 0) > 0) {
                    // Check if we can form a consecutive sequence
                    // of groupSize cards
                    for (
                        int nextCard = startCard;
                        nextCard < startCard + groupSize;
                        nextCard++
                    ) {
                        if (cardCount.getOrDefault(nextCard, 0) == 0) {
                            return false;
                        }
                        cardCount.put(nextCard, cardCount.get(nextCard) - 1);
                    }
                }
                startCard++;
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
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False

        # Counter to store the count of each card value
        card_count = Counter(hand)

        for card in hand:
            start_card = card
            # Find the start of the potential straight sequence
            while card_count[start_card - 1]:
                start_card -= 1

            # Process the sequence starting from start_card
            while start_card <= card:
                while card_count[start_card]:
                    # Check if we can form a consecutive sequence
                    # of groupSize cards
                    for next_card in range(start_card, start_card + groupSize):
                        if not card_count[next_card]:
                            return False
                        card_count[next_card] -= 1
                start_card += 1

        return True
```

</details>
