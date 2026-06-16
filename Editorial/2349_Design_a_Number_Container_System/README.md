# 2349. Design a Number Container System

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/design-a-number-container-system/)  
`Hash Table` `Design` `Heap (Priority Queue)` `Ordered Set`

**Problem Link:** [LeetCode 2349 - Design a Number Container System](https://leetcode.com/problems/design-a-number-container-system/)

## Problem

Design a number container system that can do the following:

- Insert or Replace a number at the given index in the system.
- Return the smallest index for the given number in the system.

Implement the NumberContainers class:

- NumberContainers() Initializes the number container system.
- void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
- int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.

### Example 1

```text
Input
["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
Output
[null, -1, null, null, null, null, 1, null, 2]

Explanation
NumberContainers nc = new NumberContainers();
nc.find(10); // There is no index that is filled with number 10. Therefore, we return -1.
nc.change(2, 10); // Your container at index 2 will be filled with number 10.
nc.change(1, 10); // Your container at index 1 will be filled with number 10.
nc.change(3, 10); // Your container at index 3 will be filled with number 10.
nc.change(5, 10); // Your container at index 5 will be filled with number 10.
nc.find(10); // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index that is filled with 10 is 1, we return 1.
nc.change(1, 20); // Your container at index 1 will be filled with number 20. Note that index 1 was filled with 10 and then replaced with 20.
nc.find(10); // Number 10 is at the indices 2, 3, and 5. The smallest index that is filled with 10 is 2. Therefore, we return 2.
```

## Constraints

- 1 <= index, number <= 109
- At most 105 calls will be made in total to change and find.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Seat Reservation Manager](https://leetcode.com/problems/seat-reservation-manager/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Design a Food Rating System](https://leetcode.com/problems/design-a-food-rating-system/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2349. Design a Number Container System

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Maps | C++, Java, Python3 |
| Using Min Heap with Lazy Update | C++, Java, Python3 |

## Approach 1: Two Maps

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class NumberContainers {
public:
    // Constructor
    // The data structures are already initialized as
    // part of the member variable declarations.
    NumberContainers() {}

    void change(int index, int number) {
        if (indexToNumbers.find(index) != indexToNumbers.end()) {
            int previousNumber = indexToNumbers[index];
            numberToIndices[previousNumber].erase(index);
            if (numberToIndices[previousNumber].empty()) {
                numberToIndices.erase(previousNumber);
            }
        }
        indexToNumbers[index] = number;
        numberToIndices[number].insert(index);
    }

    int find(int number) {
        if (numberToIndices.find(number) != numberToIndices.end()) {
            // Get the smallest index
            return *numberToIndices[number].begin();
        }
        return -1;
    }

private:
    // Map from number to set of indices
    unordered_map<int, set<int>> numberToIndices;
    // Map from index to number
    unordered_map<int, int> indexToNumbers;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class NumberContainers {

    // Maps from number to set of indices and from index to number
    private Map<Integer, TreeSet<Integer>> numberToIndices;
    private Map<Integer, Integer> indexToNumbers;

    // Constructor
    public NumberContainers() {
        // Initialize the data structures
        numberToIndices = new HashMap<>();
        indexToNumbers = new HashMap<>();
    }

    public void change(int index, int number) {
        // If index already has a number, remove it from the old number's index set
        if (indexToNumbers.containsKey(index)) {
            int previousNumber = indexToNumbers.get(index);
            numberToIndices.get(previousNumber).remove(index);
            if (numberToIndices.get(previousNumber).isEmpty()) {
                numberToIndices.remove(previousNumber);
            }
        }
        // Update the number and add the index to the new number's set
        indexToNumbers.put(index, number);
        numberToIndices.putIfAbsent(number, new TreeSet<>());
        numberToIndices.get(number).add(index);
    }

    public int find(int number) {
        // Return the smallest index for the given number, or -1 if not found
        if (numberToIndices.containsKey(number)) {
            return numberToIndices.get(number).first(); // Get the smallest index
        }
        return -1;
    }
}
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index, number);
 * int param_2 = obj.find(number);
 */
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class NumberContainers:

    def __init__(self):
        # Initializing the defaultdict with SortedSet and the regular dictionary
        # Map from number to set of indices
        self.number_to_indices = collections.defaultdict(SortedSet)
        # Map from index to number
        self.index_to_number = {}

    def change(self, index: int, number: int) -> None:
        # If index already has a number, remove it from the old number's index set
        if index in self.index_to_number:
            previous_number = self.index_to_number[index]
            self.number_to_indices[previous_number].remove(index)
            if not self.number_to_indices[previous_number]:
                del self.number_to_indices[previous_number]

        # Update the number and add the index to the new number's set
        self.index_to_number[index] = number
        self.number_to_indices[number].add(index)

    def find(self, number: int) -> int:
        # Return the smallest index for the given number, or -1 if not found
        if number in self.number_to_indices and self.number_to_indices[number]:
            return self.number_to_indices[number][0]
        return -1


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
```

</details>

<br>

## Approach 2: Using Min Heap with Lazy Update

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class NumberContainers {
public:
    NumberContainers() {}

    void change(int index, int number) {
        // Update index to number mapping
        indexToNumbers[index] = number;

        // Add index to the min heap for this number
        numberToIndices[number].push(index);
    }

    int find(int number) {
        // If number doesn't exist in our map
        if (numberToIndices.find(number) == numberToIndices.end()) {
            return -1;
        }

        // Get reference to min heap for this number
        auto& minHeap = numberToIndices[number];

        // Keep checking top element until we find valid index
        while (!minHeap.empty()) {
            int index = minHeap.top();

            // If index still maps to our target number, return it
            if (indexToNumbers[index] == number) {
                return index;
            }

            // Otherwise remove this stale index
            minHeap.pop();
        }

        return -1;
    }

private:
    // Map to store number -> min heap of indices
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>>
        numberToIndices;
    // Map to store index -> number
    unordered_map<int, int> indexToNumbers;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class NumberContainers {

    public NumberContainers() {
        numberToIndices = new HashMap<>();
        indexToNumbers = new HashMap<>();
    }

    public void change(int index, int number) {
        // Update index to number mapping
        indexToNumbers.put(index, number);

        // Add index to the min heap for this number
        numberToIndices
            .computeIfAbsent(number, k -> new PriorityQueue<>())
            .add(index);
    }

    public int find(int number) {
        // If number doesn't exist in our map
        if (!numberToIndices.containsKey(number)) {
            return -1;
        }

        // Get min heap for this number
        PriorityQueue<Integer> minHeap = numberToIndices.get(number);

        // Keep checking top element until we find valid index
        while (!minHeap.isEmpty()) {
            int index = minHeap.peek();

            // If index still maps to our target number, return it
            if (indexToNumbers.get(index) == number) {
                return index;
            }

            // Otherwise remove this stale index
            minHeap.poll();
        }

        return -1;
    }

    // Map to store number -> min heap of indices
    private Map<Integer, PriorityQueue<Integer>> numberToIndices;
    // Map to store index -> number
    private Map<Integer, Integer> indexToNumbers;
}
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class NumberContainers:
    def __init__(self):
        # Map to store number -> min heap of indices
        self.number_to_indices = defaultdict(list)
        # Map to store index -> number
        self.index_to_numbers = {}

    def change(self, index: int, number: int) -> None:
        # Update index to number mapping
        self.index_to_numbers[index] = number

        # Add index to the min heap for this number
        heapq.heappush(self.number_to_indices[number], index)

    def find(self, number: int) -> int:
        # If number doesn't exist in our map
        if not self.number_to_indices[number]:
            return -1

        # Keep checking top element until we find valid index
        while self.number_to_indices[number]:
            index = self.number_to_indices[number][0]

            # If index still maps to our target number, return it
            if self.index_to_numbers.get(index) == number:
                return index

            # Otherwise remove this stale index
            heapq.heappop(self.number_to_indices[number])
        return -1


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
```

</details>
