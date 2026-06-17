# 379. Design Phone Directory

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/design-phone-directory/)  
`Array` `Hash Table` `Linked List` `Design` `Queue`

**Problem Link:** [LeetCode 379 - Design Phone Directory](https://leetcode.com/problems/design-phone-directory/)

## Problem

Design a phone directory that initially has maxNumbers empty slots that can store numbers. The directory should store numbers, check if a certain slot is empty or not, and empty a given slot.

Implement the PhoneDirectory class:

- PhoneDirectory(int maxNumbers) Initializes the phone directory with the number of available slots maxNumbers.
- int get() Provides a number that is not assigned to anyone. Returns -1 if no number is available.
- bool check(int number) Returns true if the slot number is available and false otherwise.
- void release(int number) Recycles or releases the slot number.

### Example 1

```text
Input
["PhoneDirectory", "get", "get", "check", "get", "check", "release", "check"]
[[3], [], [], [2], [], [2], [2], [2]]
Output
[null, 0, 1, true, 2, false, null, true]

Explanation
PhoneDirectory phoneDirectory = new PhoneDirectory(3);
phoneDirectory.get();      // It can return any available phone number. Here we assume it returns 0.
phoneDirectory.get();      // Assume it returns 1.
phoneDirectory.check(2);   // The number 2 is available, so return true.
phoneDirectory.get();      // It returns 2, the only number that is left.
phoneDirectory.check(2);   // The number 2 is no longer available, so return false.
phoneDirectory.release(2); // Release number 2 back to the pool.
phoneDirectory.check(2);   // Number 2 is available again, return true.
```

## Constraints

- 1 <= maxNumbers <= 104
- 0 <= number < maxNumbers
- At most 2 * 104 calls will be made to get, check, and release.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Seat Reservation Manager](https://leetcode.com/problems/seat-reservation-manager/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 379. Design Phone Directory

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Design using Arrays | C++, Java, JavaScript, Python3 |
| Design using Queue / LinkedList | C++, Java, JavaScript, Python3 |
| Design using Hash Table | C++, Java, JavaScript, Python3 |

## Approach 1: Design using Arrays

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class PhoneDirectory {
    // Array to mark if a slot is available.
    vector<bool> isSlotAvailable;

public:
    PhoneDirectory(int maxNumbers) {
        isSlotAvailable = vector<bool>(maxNumbers, true);
    }

    int get() {
        // Traverse the 'isSlotAvailable' array to find an empty slot.
        // If found then return the respective index.
        for (int i = 0; i < isSlotAvailable.size(); ++i) {
            if (isSlotAvailable[i]) {
                isSlotAvailable[i] = false;
                return i;
            }
        }

        // Otherwise, return -1 when all slots are occupied.
        return -1;
    }

    bool check(int number) {
        // Check if the slot at index 'number' is available.
        return isSlotAvailable[number];
    }

    void release(int number) {
        // Mark the slot at index 'number' as available.
        isSlotAvailable[number] = true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class PhoneDirectory {
    // Array to mark if a slot is available.
    private boolean[] isSlotAvailable;

    public PhoneDirectory(int maxNumbers) {
        isSlotAvailable = new boolean[maxNumbers];
        Arrays.fill(isSlotAvailable, true);
    }

    public int get() {
        // Traverse the 'isSlotAvailable' array to find an empty slot.
        // If found then return the respective index.
        for (int i = 0; i < isSlotAvailable.length; ++i) {
            if (isSlotAvailable[i]) {
                isSlotAvailable[i] = false;
                return i;
            }
        }
        
        // Otherwise, return -1 when all slots are occupied.
        return -1;
    }

    public boolean check(int number) {
        // Check if the slot at index 'number' is available.
        return isSlotAvailable[number];
    }

    public void release(int number) {
        // Mark the slot at index 'number' as available.
        isSlotAvailable[number] = true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var PhoneDirectory = function(maxNumbers) {
    // Array to mark if a slot is available.
    this.isSlotAvailable = new Array(maxNumbers).fill(true);
};

PhoneDirectory.prototype.get = function() {
    // Find an empty slot and return the respective index.
    const index = this.isSlotAvailable.findIndex((available) => available);
    if (index !== -1) {
      this.isSlotAvailable[index] = false;
    }
    return index;
};

PhoneDirectory.prototype.check = function(number) {
    // Check if the slot at index 'number' is available or not.
    return this.isSlotAvailable[number];
};

PhoneDirectory.prototype.release = function(number) {
    // Mark the slot at index 'number' as available.
    this.isSlotAvailable[number] = true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class PhoneDirectory:
    def __init__(self, maxNumbers):
        # List to mark if a slot is available.
        self.is_slot_available = [True] * maxNumbers

    def get(self):
        # Find an empty slot and return the respective index.
        index = next((i for i, available in enumerate(self.is_slot_available) if available), -1)
        if index != -1:
            self.is_slot_available[index] = False
        return index

    def check(self, number):
        # Check if the slot at index 'number' is available.
        return self.is_slot_available[number]

    def release(self, number):
        # Mark the slot at index 'number' as available.
        self.is_slot_available[number] = True
```

</details>

<br>

## Approach 2: Design using Queue / LinkedList

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class PhoneDirectory {
    // Queue to store all available slots.
    queue<int> slotsAvailableQueue;

    // Array to mark if a slot is available.
    vector<bool> isSlotAvailable;

public:
    PhoneDirectory(int maxNumbers) {
        // Initially, all slots are available.
        isSlotAvailable = vector<bool>(maxNumbers, true);
        for (int i = 0; i < maxNumbers; ++i) {
            slotsAvailableQueue.push(i);
        }
    }
    
    int get() {
        // If the queue is empty it means no slot is available.
        if (slotsAvailableQueue.size() == 0) {
            return -1;
        }

        // Otherwise, pop the first element from the queue, 
        // mark that slot as not available and return the slot.
        int slot = slotsAvailableQueue.front();
        slotsAvailableQueue.pop();
        isSlotAvailable[slot] = false;
        return slot;
    }
    
    bool check(int number) {
        // Check if the slot at index 'number' is available or not.
        return isSlotAvailable[number];
    }
    
    void release(int number) {
        // If the slot is already present in the queue, we don't do anything.
        if (isSlotAvailable[number]) {
            return;
        }

        // Otherwise, mark the slot 'number' as available.
        slotsAvailableQueue.push(number);
        isSlotAvailable[number] = true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class PhoneDirectory {
    // Queue to store all available slots.
    private Queue<Integer> slotsAvailableQueue;

    // Array to mark if a slot is available.
    private boolean[] isSlotAvailable;

    public PhoneDirectory(int maxNumbers) {
        // Initially, all slots are available.
        isSlotAvailable = new boolean[maxNumbers];
        for (int i = 0; i < maxNumbers; ++i) {
            isSlotAvailable[i] = true;
        }
        slotsAvailableQueue = new ArrayDeque<>(maxNumbers);
        for (int i = 0; i < maxNumbers; ++i) {
            slotsAvailableQueue.offer(i);
        }
    }

    public int get() {
        // If the queue is empty it means no slot is available.
        if (slotsAvailableQueue.isEmpty()) {
            return -1;
        }

        // Otherwise, poll the first element from the queue,
        // mark that slot as not available and return the slot.
        int slot = slotsAvailableQueue.poll();
        isSlotAvailable[slot] = false;
        return slot;
    }

    public boolean check(int number) {
        // Check if the slot at index 'number' is available or not.
        return isSlotAvailable[number];
    }

    public void release(int number) {
        // If the slot is already present in the queue, we don't do anything.
        if (isSlotAvailable[number]) {
            return;
        }

        // Otherwise, mark the slot 'number' as available.
        slotsAvailableQueue.offer(number);
        isSlotAvailable[number] = true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var PhoneDirectory = function(maxNumbers) {
    // Queue to store all available slots.
    this.slotsAvailableQueue = new Queue();

    // Array to mark if a slot is available.
    this.isSlotAvailable = new Array(maxNumbers).fill(true);

    for (let i = 0; i < maxNumbers; ++i) {
        this.slotsAvailableQueue.enqueue(i);
    }
};

PhoneDirectory.prototype.get = function() {
    // If the queue is empty, it means no slot is available.
    if (this.slotsAvailableQueue.isEmpty()) {
        return -1;
    }

    // Otherwise, remove the first element from the queue,
    // mark that slot as not available and return the slot.
    const slot = this.slotsAvailableQueue.dequeue();
    this.isSlotAvailable[slot] = false;
    return slot;
};

PhoneDirectory.prototype.check = function(number) {
    // Check if the slot at index 'number' is available or not.
    return this.isSlotAvailable[number];
};

PhoneDirectory.prototype.release = function(number) {
    // If the slot is already present in the queue, we don't do anything.
    if (this.isSlotAvailable[number]) {
      return;
    }

    // Otherwise, mark the slot 'number' as available and enqueue it back to the queue.
    this.slotsAvailableQueue.enqueue(number);
    this.isSlotAvailable[number] = true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class PhoneDirectory:
    def __init__(self, max_numbers):
        # Queue to store all available slots.
        self.slots_available_queue = deque(range(max_numbers))

        # List to mark if a slot is available.
        self.is_slot_available = [True] * max_numbers
    
    def get(self):
        # If the queue is empty, it means no slot is available.
        if not self.slots_available_queue:
            return -1

        # Otherwise, get the first available slot from the queue,
        # mark that slot as not available and return the slot.
        slot = self.slots_available_queue.popleft()
        self.is_slot_available[slot] = False
        return slot
    
    def check(self, number):
        # Check if the slot at index 'number' is available or not.
        return self.is_slot_available[number]
    
    def release(self, number):
        # If the slot is already present in the queue, we don't do anything.
        if self.is_slot_available[number]:
            return

        # Otherwise, mark the slot 'number' as available.
        self.slots_available_queue.append(number)
        self.is_slot_available[number] = True
```

</details>

<br>

## Approach 3: Design using Hash Table

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class PhoneDirectory {
    // Hash set to store all available slots.
    unordered_set<int> slotsAvailable;

public:
    PhoneDirectory(int maxNumbers) {
        // Initially, all slots are available.
        for (int i = 0; i < maxNumbers; ++i) {
            slotsAvailable.insert(i);
        }
    }
    
    int get() {
        // If the hash set is empty it means no slot is available.
        if (slotsAvailable.size() == 0) {
            return -1;
        }

        // Otherwise, pop the first element from the hash set and return the slot. 
        int slot = *(slotsAvailable.begin());
        slotsAvailable.erase(slot);
        return slot;
    }
    
    bool check(int number) {
        // Check if the slot at index 'number' is available or not.
        return slotsAvailable.find(number) != slotsAvailable.end();
    }
    
    void release(int number) {
        // Mark the slot 'number' as available.
        slotsAvailable.insert(number);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class PhoneDirectory {
    // Hash set to store all available slots.
    private Set<Integer> slotsAvailable;

    public PhoneDirectory(int maxNumbers) {
        // Initially, all slots are available.
        slotsAvailable = new HashSet<>();
        for (int i = 0; i < maxNumbers; ++i) {
            slotsAvailable.add(i);
        }
    }

    public int get() {
        // If the hash set is empty it means no slot is available.
        if (slotsAvailable.isEmpty()) {
            return -1;
        }

        // Otherwise, remove and return the first element from the hash set.
        int slot = slotsAvailable.iterator().next();
        slotsAvailable.remove(slot);
        return slot;
    }

    public boolean check(int number) {
        // Check if the slot at index 'number' is available or not.
        return slotsAvailable.contains(number);
    }

    public void release(int number) {
        // Mark the slot 'number' as available.
        slotsAvailable.add(number);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var PhoneDirectory = function(maxNumbers) {
    // Hash set to store all available slots.
    this.slotsAvailable = new Set(Array.from({ length: maxNumbers }, (_, i) => i));
};

PhoneDirectory.prototype.get = function() {
    // If the hash set is empty, it means no slot is available.
    if (this.slotsAvailable.size === 0) {
        return -1;
    }

    // Otherwise, remove and return the first element from the hash set.
    const slot = this.slotsAvailable.values().next().value;
    this.slotsAvailable.delete(slot);
    return slot;
};

PhoneDirectory.prototype.check = function(number) {
    // Check if the slot at index 'number' is available or not.
    return this.slotsAvailable.has(number);
};

PhoneDirectory.prototype.release = function(number) {
    // Mark the slot 'number' as available.
    this.slotsAvailable.add(number);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class PhoneDirectory:
    def __init__(self, max_numbers):
        # Hash set to store all available slots.
        self.slots_available = set(range(max_numbers))

    def get(self):
        # If the hash set is empty it means no slot is available.
        if not self.slots_available:
            return -1

        # Otherwise, pop and return the first element from the hash set.
        return self.slots_available.pop()

    def check(self, number):
        # Check if the slot at index 'number' is available or not.
        return number in self.slots_available

    def release(self, number):
        # Mark the slot 'number' as available.
        self.slots_available.add(number)
```

</details>
