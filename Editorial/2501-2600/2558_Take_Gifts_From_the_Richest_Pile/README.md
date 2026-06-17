# 2558. Take Gifts From the Richest Pile

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/take-gifts-from-the-richest-pile/)  
`Array` `Heap (Priority Queue)` `Simulation`

**Problem Link:** [LeetCode 2558 - Take Gifts From the Richest Pile](https://leetcode.com/problems/take-gifts-from-the-richest-pile/)

## Problem

You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

- Choose the pile with the maximum number of gifts.
- If there is more than one pile with the maximum number of gifts, choose any.
- Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.

Return the number of gifts remaining after k seconds.

### Example 1

```text
Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation:
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
```

### Example 2

```text
Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation:
In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile.
That is, you can't take any pile with you.
So, the total gifts remaining are 4.
```

## Constraints

- 1 <= gifts.length <= 103
- 1 <= gifts[i] <= 109
- 1 <= k <= 103

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Stones to Minimize the Total](https://leetcode.com/problems/remove-stones-to-minimize-the-total/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2558. Take Gifts From the Richest Pile

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Sorted Array | C++, Java, Python3 |
| Heap | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        // Perform the operation k times
        for (int i = 0; i < k; i++) {
            // Initialize the index of the richest pile (maximum element)
            int richestPileIndex = 0;

            // Iterate through the array to find the index of the maximum
            // element
            for (int currentPileIndex = 0; currentPileIndex < n;
                 currentPileIndex++) {
                // If we find a new maximum, update the index
                if (gifts[richestPileIndex] < gifts[currentPileIndex]) {
                    richestPileIndex = currentPileIndex;
                }
            }

            // Replace the richest pile with the floor of its square root
            gifts[richestPileIndex] = sqrt(gifts[richestPileIndex]);
        }

        // Calculate the sum of the remaining gifts in the array
        long long int numberOfRemainingGifts =
            accumulate(gifts.begin(), gifts.end(), 0LL);

        return numberOfRemainingGifts;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public long pickGifts(int[] gifts, int k) {
        int n = gifts.length;

        // Perform the operation k times
        for (int i = 0; i < k; i++) {
            // Initialize the index of the richest pile (maximum element)
            int richestPileIndex = 0;

            // Iterate through the array to find the index of the maximum element
            for (
                int currentPileIndex = 0;
                currentPileIndex < n;
                currentPileIndex++
            ) {
                // If we find a new maximum, update the index
                if (gifts[richestPileIndex] < gifts[currentPileIndex]) {
                    richestPileIndex = currentPileIndex;
                }
            }

            // Replace the richest pile with the floor of its square root
            gifts[richestPileIndex] = (int) Math.floor(
                Math.sqrt(gifts[richestPileIndex])
            );
        }

        // Calculate the sum of the remaining gifts in the array
        long numberOfRemainingGifts = Arrays.stream(gifts)
            .mapToLong(gift -> gift) // Map to long to avoid overflow
            .sum();

        return numberOfRemainingGifts;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        n = len(gifts)

        # Perform the operation k times
        for _ in range(k):
            # Initialize the index of the richest pile (maximum element)
            richest_pile_index = 0

            # Iterate through the array to find the index of the maximum element
            for current_pile_index in range(n):
                # If we find a new maximum, update the index
                if gifts[richest_pile_index] < gifts[current_pile_index]:
                    richest_pile_index = current_pile_index

            # Replace the richest pile with the floor of its square root
            gifts[richest_pile_index] = math.isqrt(gifts[richest_pile_index])

        # Calculate the sum of the remaining gifts in the array
        number_of_remaining_gifts = sum(gifts)

        return number_of_remaining_gifts
```

</details>

<br>

## Approach 2: Sorted Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        // Create a copy of the gifts array and sort it
        vector<int> sortedGifts = gifts;
        sort(sortedGifts.begin(), sortedGifts.end());

        // Perform the operation k times
        for (int i = 0; i < k; i++) {
            int maxElement = sortedGifts[n - 1];
            sortedGifts.pop_back();

            // upper_bound returns the first element greater than
            // sqrt(maxElement)
            auto spotOfSqrt = upper_bound(sortedGifts.begin(),
                                          sortedGifts.end(), sqrt(maxElement));

            // Insert the square root value at the found position
            sortedGifts.emplace(spotOfSqrt, sqrt(maxElement));
        }

        // Calculate the sum of the remaining gifts in the array
        long long int numberOfRemainingGifts =
            accumulate(sortedGifts.begin(), sortedGifts.end(), 0LL);

        return numberOfRemainingGifts;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public long pickGifts(int[] gifts, int k) {
        int n = gifts.length;

        // Create a list from the gifts array and sort it
        List<Integer> sortedGifts = new ArrayList<>();
        for (int gift : gifts) {
            sortedGifts.add(gift);
        }
        Collections.sort(sortedGifts);

        // Perform the operation k times
        for (int i = 0; i < k; i++) {
            // Get the largest element (last element in the sorted list)
            int maxElement = sortedGifts.get(n - 1);
            sortedGifts.remove(n - 1);

            // Calculate the square root of the max element
            int sqrtElement = (int) Math.floor(Math.sqrt(maxElement));

            // Find the index where the square root should be inserted
            int spotOfSqrt = Collections.binarySearch(sortedGifts, sqrtElement);

            // If the value isn't found, binarySearch returns a negative index
            if (spotOfSqrt < 0) {
                spotOfSqrt = -(spotOfSqrt + 1);
            }

            sortedGifts.add(spotOfSqrt, sqrtElement); // Insert the square root at the correct index
        }

        // Calculate the sum of the remaining gifts in the array
        long numberOfRemainingGifts = 0;
        for (int gift : sortedGifts) {
            numberOfRemainingGifts += gift;
        }

        return numberOfRemainingGifts;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        n = len(gifts)

        # Create a copy of the gifts array and sort it
        sorted_gifts = sorted(gifts)

        # Perform the operation k times
        for _ in range(k):
            max_element = sorted_gifts[-1]
            sorted_gifts.pop()

            # Find the index where the square root of max_element should be inserted
            sqrt_value = math.isqrt(max_element)
            spot_of_sqrt = bisect.bisect_right(sorted_gifts, sqrt_value)

            # Insert the square root value at the correct position
            sorted_gifts.insert(spot_of_sqrt, sqrt_value)

        # Calculate the sum of the remaining elements in the sorted array
        number_of_remaining_gifts = sum(sorted_gifts)

        return number_of_remaining_gifts
```

</details>

<br>

## Approach 3: Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Create a max-heap from the 'gifts' array (using a priority_queue)
        priority_queue<int> giftsHeap(gifts.begin(), gifts.end());

        // Perform the operation 'k' times
        for (int i = 0; i < k; i++) {
            // Get the maximum element from the heap (top element)
            int maxElement = giftsHeap.top();
            giftsHeap.pop();

            // Insert the floor of the square root of the maximum element back
            // into the heap
            giftsHeap.push(sqrt(maxElement));
        }

        // Accumulate the sum of the elements in the heap
        long long numberOfRemainingGifts = 0;
        while (!giftsHeap.empty()) {
            numberOfRemainingGifts += giftsHeap.top();
            giftsHeap.pop();
        }
        return numberOfRemainingGifts;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public long pickGifts(int[] gifts, int k) {
        // Convert int[] to List<Integer> manually for efficient initialization of the heap
        // Negate values to simulate max-heap
        List<Integer> giftsList = new ArrayList<>();
        for (int gift : gifts) {
            giftsList.add(-gift);
        }

        // Initialize giftsHeap from giftsList
        PriorityQueue<Integer> giftsHeap = new PriorityQueue<>(giftsList);
        // Perform the operation 'k' times
        for (int i = 0; i < k; i++) {
            // Get the maximum element from the heap (top element)
            int maxElement = -giftsHeap.poll();

            // Insert the floor of the square root of the maximum element back into the heap
            giftsHeap.offer(-(int) Math.sqrt(maxElement));
        }

        // Accumulate the sum of the elements in the heap
        long numberOfRemainingGifts = 0;
        while (!giftsHeap.isEmpty()) {
            numberOfRemainingGifts -= giftsHeap.poll();
        }

        return numberOfRemainingGifts;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        # Create a max-heap from the 'gifts' array (negating values to simulate max-heap)
        gifts_heap = [-gift for gift in gifts]
        heapq.heapify(gifts_heap)

        # Perform the operation 'k' times
        for _ in range(k):
            # Get the maximum element from the heap (top element)
            max_element = -heapq.heappop(gifts_heap)

            # Insert the floor of the square root of the maximum element back into the heap
            heapq.heappush(gifts_heap, -math.isqrt(max_element))

        # Accumulate the sum of the elements in the heap
        number_of_remaining_gifts = -sum(gifts_heap)

        return number_of_remaining_gifts
```

</details>
