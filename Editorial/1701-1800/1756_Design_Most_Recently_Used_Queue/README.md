# 1756. Design Most Recently Used Queue

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/design-most-recently-used-queue/)  
`Array` `Linked List` `Divide and Conquer` `Design` `Simulation` `Doubly-Linked List`

**Problem Link:** [LeetCode 1756 - Design Most Recently Used Queue](https://leetcode.com/problems/design-most-recently-used-queue/)

## Problem

Design a queue-like data structure that moves the most recently used element to the end of the queue.

Implement the MRUQueue class:

- MRUQueue(int n) constructs the MRUQueue with n elements: [1,2,3,...,n].
- int fetch(int k) moves the kth element (1-indexed) to the end of the queue and returns it.

### Example 1

```text
Input:
["MRUQueue", "fetch", "fetch", "fetch", "fetch"]
[[8], [3], [5], [2], [8]]
Output:
[null, 3, 6, 2, 2]

Explanation:
MRUQueue mRUQueue = new MRUQueue(8); // Initializes the queue to [1,2,3,4,5,6,7,8].
mRUQueue.fetch(3); // Moves the 3rd element (3) to the end of the queue to become [1,2,4,5,6,7,8,3] and returns it.
mRUQueue.fetch(5); // Moves the 5th element (6) to the end of the queue to become [1,2,4,5,7,8,3,6] and returns it.
mRUQueue.fetch(2); // Moves the 2nd element (2) to the end of the queue to become [1,4,5,7,8,3,6,2] and returns it.
mRUQueue.fetch(8); // The 8th element (2) is already at the end of the queue so just return it.
```

## Constraints

- 1 <= n <= 2000
- 1 <= k <= n
- At most 2000 calls will be made to fetch.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [LRU Cache](https://leetcode.com/problems/lru-cache/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1756. Design Most Recently Used Queue

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force with Array Queue | C++, Java, Python3 |
| Brute Force with Linked List | C++, Java, Python3 |
| Square Root Decomposition | C++, Java, Python3 |
| Fenwick Tree | C++, Java, Python3 |

## Approach 1: Brute Force with Array Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MRUQueue {
private:
    vector<int> queue;

public:
    MRUQueue(int n) {
        // Initialize the queue with numbers from 1 to n
        for (int number = 1; number <= n; ++number) {
            queue.push_back(number);
        }
    }

    int fetch(int k) {
        // Get the k-th element (1-indexed)
        int value = queue[k - 1];
        // Remove the element from its current position in the queue
        queue.erase(queue.begin() + k - 1);
        // Append the element to the end of the queue
        queue.push_back(value);
        return value;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MRUQueue {

    private List<Integer> queue = new ArrayList<>();

    public MRUQueue(int n) {
        // Initialize the queue with numbers from 1 to n
        for (int number = 1; number <= n; ++number) {
            queue.add(number);
        }
    }

    public int fetch(int k) {
        // Get the k-th element (1-indexed)
        int value = queue.get(k - 1);
        // Remove the element from its current position in the queue
        queue.remove(k - 1);
        // Append the element to the end of the queue
        queue.add(value);
        return value;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MRUQueue:

    def __init__(self, n: int):
        # Initialize the queue with numbers from 1 to n
        self.queue = [i for i in range(1, n + 1)]

    def fetch(self, k: int) -> int:
        # Get the k-th element (1-indexed)
        value = self.queue.pop(k - 1)
        # Append the element to the end of the queue
        self.queue.append(value)
        return value
```

</details>

<br>

## Approach 2: Brute Force with Linked List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
struct MRUQueueListNode {
    int value;
    MRUQueueListNode* next;

    MRUQueueListNode() : value(0), next(nullptr) {}
    MRUQueueListNode(int val) : value(val), next(nullptr) {}
};

class MRUQueue {
private:
    MRUQueueListNode* head;
    MRUQueueListNode* tail;

public:
    MRUQueue(int n) {
        head = new MRUQueueListNode();
        MRUQueueListNode* current = head;

        // Initialize the linked list with values from 1 to n
        for (int number = 1; number <= n; ++number) {
            current->next = new MRUQueueListNode(number);
            current = current->next;
        }

        tail = current;
    }

    int fetch(int k) {
        MRUQueueListNode* current = head;

        // Traverse to the node before the k-th node
        for (int index = 1; index < k; ++index) {
            current = current->next;
        }

        // Get the value of the k-th node
        int value = current->next->value;

        // Move the k-th node to the end of the list
        tail->next = current->next;
        tail = tail->next;
        current->next = tail->next;
        tail->next = nullptr;

        return value;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class ListNode {

    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class MRUQueue {

    private ListNode head;
    private ListNode tail;

    public MRUQueue(int n) {
        this.head = new ListNode(0, null);
        ListNode current = head;

        // Initialize the linked list with values from 1 to n
        for (int number = 1; number <= n; ++number) {
            current.next = new ListNode(number, null);
            current = current.next;
        }

        tail = current;
    }

    public int fetch(int k) {
        ListNode current = head;

        // Traverse to the node before the k-th node
        for (int index = 1; index < k; ++index) {
            current = current.next;
        }

        // Get the value of the k-th node
        int value = current.next.val;

        // Move the k-th node to the end of the list
        tail.next = current.next;
        tail = tail.next;
        current.next = tail.next;
        tail.next = null;

        return value;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class MRUQueue:

    def __init__(self, n: int):
        self.head = ListNode()
        self.tail = self.head
        current = self.head
        for i in range(1, n + 1):
            current.next = ListNode(i)
            current = current.next

        self.tail = current

    def fetch(self, k: int) -> int:
        current = self.head
        for _ in range(1, k):
            current = current.next

        # Fetch node value
        val = current.next.val

        # Move fetched node to tail
        self.tail.next = current.next
        current.next = current.next.next
        self.tail = self.tail.next
        self.tail.next = None

        return val
```

</details>

<br>

## Approach 3: Square Root Decomposition

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MRUQueue {
private:
    int totalElements;
    const int BUCKET_SIZE;
    // Stores elements in different buckets
    vector<vector<int>> data;
    // Tracks the starting index of each bucket
    vector<int> index;

public:
    MRUQueue(int n) : totalElements(n), BUCKET_SIZE(sqrt(n)) {
        // Initialize data with the given number of elements
        for (int number = 1; number <= n; ++number) {
            int bucketIndex = (number - 1) / BUCKET_SIZE;
            // Create a new bucket if it's not already present
            if (bucketIndex == data.size()) {
                data.push_back({});
                index.push_back(number);
            }
            // Add the number to the corresponding bucket
            data.back().push_back(number);
        }
    }

    int fetch(int k) {
        // Find the bucket that contains the kth element using binary search
        int bucketIndex =
            upper_bound(index.begin(), index.end(), k) - index.begin() - 1;

        // Get the element from the selected bucket
        int element = data[bucketIndex][k - index[bucketIndex]];
        // Remove the element from its current bucket
        data[bucketIndex].erase(data[bucketIndex].begin() +
                                (k - index[bucketIndex]));

        // Shift the starting indices of the subsequent buckets
        for (int i = bucketIndex + 1; i < index.size(); ++i) {
            index[i]--;
        }

        // Append the element to the last bucket
        if (data.back().size() >= BUCKET_SIZE) {
            data.push_back({});
            // Update the last bucket's index
            index.push_back(totalElements);
        }
        // Add the element to the last bucket
        data.back().push_back(element);

        // Remove any empty buckets after the operation
        if (data[bucketIndex].empty()) {
            data.erase(data.begin() + bucketIndex);
            index.erase(index.begin() + bucketIndex);
        }

        return element;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MRUQueue {

    private int totalElements;
    private int BUCKET_SIZE;
    List<List<Integer>> data = new ArrayList<>();
    List<Integer> index = new ArrayList<>();

    public MRUQueue(int n) {
        this.totalElements = n;
        this.BUCKET_SIZE = (int) Math.sqrt(n);
        for (int number = 1; number <= n; ++number) {
            int bucketIndex = (number - 1) / BUCKET_SIZE;
            if (bucketIndex == data.size()) {
                data.add(new ArrayList<>());
                index.add(number);
            }
            data.get(data.size() - 1).add(number);
        }
    }

    public int fetch(int k) {
        int bucketIndex = upperBound(index, k) - 1;
        int element = data.get(bucketIndex).get(k - index.get(bucketIndex));
        data.get(bucketIndex).remove(k - index.get(bucketIndex));

        for (int i = bucketIndex + 1; i < index.size(); ++i) {
            index.set(i, index.get(i) - 1);
        }

        if (data.get(data.size() - 1).size() >= BUCKET_SIZE) {
            data.add(new ArrayList<>());
            index.add(totalElements);
        }
        data.get(data.size() - 1).add(element);

        if (data.get(bucketIndex).isEmpty()) {
            data.remove(bucketIndex);
            index.remove(bucketIndex);
        }
        return element;
    }

    public int upperBound(List<Integer> nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums.get(mid) > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MRUQueue:

    def __init__(self, n: int):
        self.total_elements = n
        self.BUCKET_SIZE = int(n**0.5)
        self.data = []
        self.index = []
        for number in range(1, n + 1):
            bucket_index = (number - 1) // self.BUCKET_SIZE
            if bucket_index == len(self.data):
                self.data.append([])
                self.index.append(number)
            self.data[-1].append(number)

    def fetch(self, k: int) -> int:
        bucket_index = self.upper_bound(self.index, k) - 1
        element = self.data[bucket_index][k - self.index[bucket_index]]
        del self.data[bucket_index][k - self.index[bucket_index]]
        for i in range(bucket_index + 1, len(self.index)):
            self.index[i] -= 1

        if len(self.data[-1]) >= self.BUCKET_SIZE:
            self.data.append([])
            self.index.append(self.total_elements)
        self.data[-1].append(element)

        if len(self.data[bucket_index]) == 0:
            del self.data[bucket_index]
            del self.index[bucket_index]

        return element

    def upper_bound(self, nums, target):
        left, right = 0, len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > target:
                right = mid
            else:
                left = mid + 1
        return left
```

</details>

<br>

## Approach 4: Fenwick Tree

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    // Calculates the sum up to the given index
    int sum(int index) {
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index &= index - 1;
        }
        return result;
    }

    // Updates the tree by adding value at the given index
    void insert(int index, int value) {
        // Adjust for 1-based indexing
        index += 1;
        while (index < tree.size()) {
            tree[index] += value;
            index += index & -index;
        }
    }
};

class MRUQueue {
private:
    int size;
    FenwickTree tree;
    vector<int> values;

public:
    MRUQueue(int n) : size(n), tree(n + 2000), values(n + 2000, 0) {
        for (int i = 0; i < n; ++i) {
            // Mark positions in the Fenwick Tree
            tree.insert(i, 1);
            // Set the initial values
            values[i] = i + 1;
        }
    }

    // Fetches the kth value from the queue
    int fetch(int k) {
        int low = 0, high = size;

        // Binary search to find the kth value
        while (low < high) {
            int mid = (low + high) >> 1;
            if (tree.sum(mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        // Move the found value to the end
        tree.insert(low - 1, -1);
        tree.insert(size, 1);
        values[size] = values[low - 1];
        size += 1;

        // Return the fetched value
        return values[low - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class FenwickTree {

    private int[] tree;

    public FenwickTree(int size) {
        this.tree = new int[size + 1];
    }

    public int sum(int index) {
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index = index & (index - 1);
        }
        return result;
    }

    public void insert(int index, int value) {
        index += 1;
        while (index < tree.length) {
            tree[index] += value;
            index += index & -index;
        }
    }
}

class MRUQueue {

    private int size;
    private FenwickTree tree;
    private int[] values;

    public MRUQueue(int n) {
        this.size = n;
        this.tree = new FenwickTree(n + 2000);
        this.values = new int[n + 2000];
        for (int i = 0; i < n; ++i) {
            this.tree.insert(i, 1);
            this.values[i] = i + 1;
        }
    }

    public int fetch(int k) {
        int low = 0, high = size;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (this.tree.sum(mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        this.tree.insert(low - 1, -1);
        this.tree.insert(size, 1);
        this.values[size] = this.values[low - 1];
        this.size++;

        return this.values[low - 1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class FenwickTree:
    def __init__(self, size):
        self.tree = [0] * (size + 1)

    def sum(self, index):
        result = 0
        while index > 0:
            result += self.tree[index]
            index = index & (index - 1)

        return result

    def insert(self, index, value):
        index += 1
        while index < len(self.tree):
            self.tree[index] += value
            index += index & -index


class MRUQueue:
    def __init__(self, n):
        self.size = n
        self.tree = FenwickTree(n + 2000)
        self.values = [0] * (n + 2000)
        for i in range(n):
            self.tree.insert(i, 1)
            self.values[i] = i + 1

    def fetch(self, k):
        low = 0
        high = self.size
        while low < high:
            mid = (low + high) >> 1
            if self.tree.sum(mid) < k:
                low = mid + 1
            else:
                high = mid

        self.tree.insert(low - 1, -1)
        self.tree.insert(self.size, 1)
        self.values[self.size] = self.values[low - 1]
        self.size += 1

        return self.values[low - 1]
```

</details>
