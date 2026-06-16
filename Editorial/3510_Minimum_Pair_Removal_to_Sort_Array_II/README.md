# 3510. Minimum Pair Removal to Sort Array II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/)  
`Array` `Hash Table` `Linked List` `Heap (Priority Queue)` `Simulation` `Doubly-Linked List` `Ordered Set`

**Problem Link:** [LeetCode 3510 - Minimum Pair Removal to Sort Array II](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/)

## Problem

Given an array nums, you can perform the following operation any number of times:

- Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
- Replace the pair with their sum.

Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

### Example 1

### Example 2

## Constraints

- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3510. Minimum Pair Removal to Sort Array II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Priority Queue + Lazy Deletion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Priority Queue + Lazy Deletion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MIN_QUEUE_SIZE 4096

typedef struct Node {
    long long value;
    int left;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(long long value, int left) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

typedef struct QueueItem {
    Node* first;
    Node* second;
    long long cost;
    int firstLeft;
    int secondLeft;
} QueueItem;

typedef struct Element {
    QueueItem item;
} Element;

typedef bool (*CompareFunc)(const void*, const void*);

static bool itemLess(const void* a, const void* b) {
    const Element* e1 = (const Element*)a;
    const Element* e2 = (const Element*)b;
    const QueueItem* item1 = &e1->item;
    const QueueItem* item2 = &e2->item;
    if (item1->cost != item2->cost) {
        return item1->cost > item2->cost;
    }
    return item1->firstLeft > item2->firstLeft;
}

static void swap(Element* arr, int i, int j) {
    Element t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

typedef struct PriorityQueue {
    Element* arr;
    int capacity;
    int queueSize;
    CompareFunc lessFunc;
} PriorityQueue;

PriorityQueue* createPriorityQueue(CompareFunc cmpFunc) {
    PriorityQueue* obj = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    obj->capacity = MIN_QUEUE_SIZE;
    obj->arr = (Element*)malloc(sizeof(Element) * obj->capacity);
    obj->queueSize = 0;
    obj->lessFunc = cmpFunc;
    return obj;
}

static void down(Element* arr, int size, int i, CompareFunc cmpFunc) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < size && cmpFunc(&arr[smallest], &arr[left])) {
            smallest = left;
        }
        if (right < size && cmpFunc(&arr[smallest], &arr[right])) {
            smallest = right;
        }
        if (smallest == i) {
            break;
        }
        swap(arr, i, smallest);
        i = smallest;
    }
}

void enQueue(PriorityQueue* obj, const QueueItem* item) {
    if (obj->queueSize == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = (Element*)realloc(obj->arr, sizeof(Element) * obj->capacity);
    }

    obj->arr[obj->queueSize].item = *item;

    int i = obj->queueSize;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (!obj->lessFunc(&obj->arr[parent], &obj->arr[i])) {
            break;
        }
        swap(obj->arr, i, parent);
        i = parent;
    }

    obj->queueSize++;
}

QueueItem* deQueue(PriorityQueue* obj) {
    if (obj->queueSize == 0) {
        return NULL;
    }

    swap(obj->arr, 0, obj->queueSize - 1);
    QueueItem* result = &obj->arr[obj->queueSize - 1].item;
    obj->queueSize--;
    if (obj->queueSize > 0) {
        down(obj->arr, obj->queueSize, 0, obj->lessFunc);
    }

    return result;
}

QueueItem* front(const PriorityQueue* obj) {
    if (obj->queueSize == 0) {
        return NULL;
    }
    return &obj->arr[0].item;
}

bool isEmpty(const PriorityQueue* obj) { return obj->queueSize == 0; }

int size(const PriorityQueue* obj) { return obj->queueSize; }

void freeQueue(PriorityQueue* obj) {
    free(obj->arr);
    free(obj);
}

int minimumPairRemoval(int* nums, int numsSize) {
    PriorityQueue* pq = createPriorityQueue(itemLess);
    bool* merged = (bool*)calloc(numsSize, sizeof(bool));
    int decreaseCount = 0;
    int count = 0;

    Node** nodes = (Node**)malloc(sizeof(Node*) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        nodes[i] = createNode(nums[i], i);
        if (i > 0) {
            nodes[i - 1]->next = nodes[i];
            nodes[i]->prev = nodes[i - 1];
        }
    }

    for (int i = 1; i < numsSize; i++) {
        QueueItem item;
        item.first = nodes[i - 1];
        item.second = nodes[i];
        item.cost = item.first->value + item.second->value;
        item.firstLeft = item.first->left;
        item.secondLeft = item.second->left;
        enQueue(pq, &item);
        if (nums[i - 1] > nums[i]) {
            decreaseCount++;
        }
    }

    while (decreaseCount > 0 && !isEmpty(pq)) {
        QueueItem* itemPtr = deQueue(pq);
        if (!itemPtr) {
            break;
        }
        QueueItem item = *itemPtr;

        if (merged[item.firstLeft] || merged[item.secondLeft]) {
            continue;
        }

        Node* first = item.first;
        Node* second = item.second;
        long long cost = item.cost;

        if (!first || !second) {
            continue;
        }
        if (first->next != second) {
            continue;
        }
        if (first->value + second->value != cost) {
            continue;
        }

        count++;

        if (first->value > second->value) {
            decreaseCount--;
        }

        Node* prevNode = first->prev;
        Node* nextNode = second->next;

        first->next = nextNode;
        if (nextNode) {
            nextNode->prev = first;
        }
        second->prev = NULL;
        second->next = NULL;

        if (prevNode) {
            if (prevNode->value > first->value && prevNode->value <= cost) {
                decreaseCount--;
            }
            if (prevNode->value <= first->value && prevNode->value > cost) {
                decreaseCount++;
            }
            QueueItem newItem;
            newItem.first = prevNode;
            newItem.second = first;
            newItem.cost = prevNode->value + cost;
            newItem.firstLeft = prevNode->left;
            newItem.secondLeft = first->left;
            enQueue(pq, &newItem);
        }

        if (nextNode) {
            if (second->value > nextNode->value && cost <= nextNode->value) {
                decreaseCount--;
            }
            if (second->value <= nextNode->value && cost > nextNode->value) {
                decreaseCount++;
            }
            QueueItem newItem;
            newItem.first = first;
            newItem.second = nextNode;
            newItem.cost = cost + nextNode->value;
            newItem.firstLeft = first->left;
            newItem.secondLeft = nextNode->left;
            enQueue(pq, &newItem);
        }

        first->value = cost;
        merged[second->left] = true;
    }

    for (int i = 0; i < numsSize; i++) {
        if (!merged[i]) {
            free(nodes[i]);
        }
    }
    free(nodes);
    free(merged);
    freeQueue(pq);

    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
typedef long long ll;

const int MAX_N = 100005;

struct Node {
    ll value;
    int left;
};

using ListIt = std::list<Node>::iterator;

struct Pair {
    ListIt first;
    ListIt second;
    ll cost;
    size_t firstLeft;
    size_t secondLeft;

    Pair() {}
    Pair(ListIt fi, ListIt se, ll cost)
        : first(fi),
          second(se),
          firstLeft(fi->left),
          secondLeft(se->left),
          cost(cost) {}
};

struct ComparePair {
    bool operator()(const Pair& a, const Pair& b) {
        if (a.cost != b.cost) {
            return a.cost > b.cost;
        }
        return a.firstLeft > b.firstLeft;
    }
};

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        std::list<Node> list;
        std::bitset<MAX_N> merged;
        std::priority_queue<Pair, std::vector<Pair>, ComparePair> pq;

        int decreaseCount = 0;
        int count = 0;

        list.push_back({nums[0], 0});

        for (size_t i = 1; i < nums.size(); ++i) {
            list.push_back({nums[i], (int)i});

            auto curr = std::prev(list.end());
            auto prev = std::prev(curr);

            pq.push({prev, curr, prev->value + curr->value});

            if (nums[i - 1] > nums[i]) {
                decreaseCount++;
            }
        }

        while (decreaseCount > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (merged[top.firstLeft] || merged[top.secondLeft]) {
                continue;
            }

            auto first = top.first;
            auto second = top.second;
            auto cost = top.cost;

            if (first->value + second->value != cost) {
                continue;
            }

            count++;

            if (first->value > second->value) {
                decreaseCount--;
            }

            ListIt prev =
                (first == list.begin()) ? list.end() : std::prev(first);
            ListIt next = std::next(second);

            if (prev != list.end()) {
                if (prev->value > first->value && prev->value <= cost) {
                    decreaseCount--;
                }
                if (prev->value <= first->value && prev->value > cost) {
                    decreaseCount++;
                }
                pq.push({prev, first, prev->value + cost});
            }

            if (next != list.end()) {
                if (second->value > next->value && cost <= next->value) {
                    decreaseCount--;
                }
                if (second->value <= next->value && cost > next->value) {
                    decreaseCount++;
                }
                pq.push({first, next, cost + next->value});
            }

            first->value = cost;
            merged[second->left] = 1;
            list.erase(second);
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Node {
    public long value;
    public int left;
    public Node prev;
    public Node next;

    public Node(long value, int left) {
        this.value = value;
        this.left = left;
    }
}

public class Item : IComparable<Item> {
    public Node first;
    public Node second;
    public long cost;

    public Item(Node first, Node second, long cost) {
        this.first = first;
        this.second = second;
        this.cost = cost;
    }

    public int CompareTo(Item other) {
        if (cost == other.cost) {
            return first.left.CompareTo(other.first.left);
        }
        return cost.CompareTo(other.cost);
    }
}

public class Solution {
    public int MinimumPairRemoval(int[] nums) {
        var pq = new PriorityQueue<Item, Item>();
        bool[] merged = new bool[nums.Length];
        int decreaseCount = 0;
        int count = 0;
        List<Node> nodes = new List<Node>();
        nodes.Add(new Node(nums[0], 0));

        for (int i = 1; i < nums.Length; i++) {
            nodes.Add(new Node(nums[i], i));
            nodes[i - 1].next = nodes[i];
            nodes[i].prev = nodes[i - 1];
            var item = new Item(nodes[i - 1], nodes[i],
                                nodes[i - 1].value + nodes[i].value);
            pq.Enqueue(item, item);

            if (nums[i - 1] > nums[i]) {
                decreaseCount++;
            }
        }

        while (decreaseCount > 0) {
            var item = pq.Dequeue();
            Node first = item.first;
            Node second = item.second;
            long cost = item.cost;

            if (merged[first.left] || merged[second.left] ||
                first.value + second.value != cost) {
                continue;
            }
            count++;
            if (first.value > second.value) {
                decreaseCount--;
            }

            Node prevNode = first.prev;
            Node nextNode = second.next;
            first.next = nextNode;
            if (nextNode != null) {
                nextNode.prev = first;
            }

            if (prevNode != null) {
                if (prevNode.value > first.value && prevNode.value <= cost) {
                    decreaseCount--;
                } else if (prevNode.value <= first.value &&
                           prevNode.value > cost) {
                    decreaseCount++;
                }
                var newItem = new Item(prevNode, first, prevNode.value + cost);
                pq.Enqueue(newItem, newItem);
            }

            if (nextNode != null) {
                if (second.value > nextNode.value && cost <= nextNode.value) {
                    decreaseCount--;
                } else if (second.value <= nextNode.value &&
                           cost > nextNode.value) {
                    decreaseCount++;
                }
                var newItem = new Item(first, nextNode, cost + nextNode.value);
                pq.Enqueue(newItem, newItem);
            }

            first.value = cost;
            merged[second.left] = true;
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumPairRemoval(nums []int) int {
	pq := &PriorityQueue{}
	heap.Init(pq)
	merged := make([]bool, len(nums))
	decreaseCount := 0
	count := 0
	head := &Node{value: int64(nums[0]), left: 0}
	current := head

	for i := 1; i < len(nums); i++ {
		newNode := &Node{value: int64(nums[i]), left: i}
		current.next = newNode
		newNode.prev = current

		heap.Push(pq, &Item{
			first:  current,
			second: newNode,
			cost:   current.value + newNode.value,
		})
		if nums[i-1] > nums[i] {
			decreaseCount++
		}

		current = newNode
	}

	for decreaseCount > 0 {
		item := heap.Pop(pq).(*Item)
		first := item.first
		second := item.second
		cost := item.cost

		if merged[first.left] || merged[second.left] || first.value+second.value != cost {
			continue
		}
		count++
		if first.value > second.value {
			decreaseCount--
		}

		prevNode := first.prev
		nextNode := second.next
		first.next = nextNode
		if nextNode != nil {
			nextNode.prev = first
		}

		if prevNode != nil {
			if prevNode.value > first.value && prevNode.value <= cost {
				decreaseCount--
			} else if prevNode.value <= first.value && prevNode.value > cost {
				decreaseCount++
			}
			heap.Push(pq, &Item{
				first:  prevNode,
				second: first,
				cost:   prevNode.value + cost,
			})
		}

		if nextNode != nil {
			if second.value > nextNode.value && cost <= nextNode.value {
				decreaseCount--
			} else if second.value <= nextNode.value && cost > nextNode.value {
				decreaseCount++
			}
			heap.Push(pq, &Item{
				first:  first,
				second: nextNode,
				cost:   cost + nextNode.value,
			})
		}

		first.value = cost
		merged[second.left] = true
	}

	return count
}

type Node struct {
	value int64
	left  int
	prev  *Node
	next  *Node
}

type Item struct {
	first  *Node
	second *Node
	cost   int64
	index  int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	if pq[i].cost == pq[j].cost {
		return pq[i].first.left < pq[j].first.left
	}
	return pq[i].cost < pq[j].cost
}
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}
func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1
	*pq = old[0 : n-1]
	return item
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Node {

    long value;
    int left;
    Node prev;
    Node next;

    Node(int value, int left) {
        this.value = value;
        this.left = left;
    }
}

class PQItem implements Comparable<PQItem> {

    Node first;
    Node second;
    long cost;

    PQItem(Node first, Node second, long cost) {
        this.first = first;
        this.second = second;
        this.cost = cost;
    }

    @Override
    public int compareTo(PQItem other) {
        if (this.cost == other.cost) {
            return this.first.left - other.first.left;
        }
        return this.cost < other.cost ? -1 : 1;
    }
}

public class Solution {

    public int minimumPairRemoval(int[] nums) {
        PriorityQueue<PQItem> pq = new PriorityQueue<>();
        boolean[] merged = new boolean[nums.length];

        int decreaseCount = 0;
        int count = 0;
        Node head = new Node(nums[0], 0);
        Node current = head;

        for (int i = 1; i < nums.length; i++) {
            Node newNode = new Node(nums[i], i);
            current.next = newNode;
            newNode.prev = current;
            pq.offer(
                new PQItem(current, newNode, current.value + newNode.value)
            );
            if (nums[i - 1] > nums[i]) {
                decreaseCount++;
            }
            current = newNode;
        }

        while (decreaseCount > 0) {
            PQItem item = pq.poll();
            Node first = item.first;
            Node second = item.second;
            long cost = item.cost;

            if (
                merged[first.left] ||
                merged[second.left] ||
                first.value + second.value != cost
            ) {
                continue;
            }
            count++;
            if (first.value > second.value) {
                decreaseCount--;
            }

            Node prevNode = first.prev;
            Node nextNode = second.next;
            first.next = nextNode;
            if (nextNode != null) {
                nextNode.prev = first;
            }

            if (prevNode != null) {
                if (prevNode.value > first.value && prevNode.value <= cost) {
                    decreaseCount--;
                } else if (
                    prevNode.value <= first.value && prevNode.value > cost
                ) {
                    decreaseCount++;
                }

                pq.offer(new PQItem(prevNode, first, prevNode.value + cost));
            }

            if (nextNode != null) {
                if (second.value > nextNode.value && cost <= nextNode.value) {
                    decreaseCount--;
                } else if (
                    second.value <= nextNode.value && cost > nextNode.value
                ) {
                    decreaseCount++;
                }

                pq.offer(new PQItem(first, nextNode, cost + nextNode.value));
            }

            first.value = cost;
            merged[second.left] = true;
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class Node extends DoublyLinkedListNode {
    value;
    left;
    constructor(value, left) {
        super(value);
        this.value = value;
        this.left = left;
    }
}

var minimumPairRemoval = function (nums) {
    const pq = new PriorityQueue((a, b) =>
        a.cost === b.cost ? a.first.left - b.first.left : a.cost - b.cost,
    );

    const list = new DoublyLinkedList();
    const merged = new Array(nums.length).fill(false);
    let decreaseCount = 0;
    let count = 0;
    list.insertLast(new Node(nums[0], 0));

    for (let i = 1; i < nums.length; i++) {
        list.insertLast(new Node(nums[i], i));
        const curr = list.tail();
        pq.enqueue({
            first: curr.getPrev(),
            second: curr,
            cost: nums[i] + nums[i - 1],
        });
        if (nums[i - 1] > nums[i]) {
            decreaseCount++;
        }
    }

    while (decreaseCount > 0) {
        const { first, second, cost } = pq.dequeue();
        if (
            merged[first.left] ||
            merged[second.left] ||
            first.value + second.value !== cost
        )
            continue;
        count++;

        if (first.value > second.value) {
            decreaseCount--;
        }

        const prev = first.getPrev();
        const next = second.getNext();

        if (prev) {
            if (prev.value > first.value && prev.value <= cost) {
                decreaseCount--;
            }
            if (prev.value <= first.value && prev.value > cost) {
                decreaseCount++;
            }

            pq.enqueue({
                first: prev,
                second: first,
                cost: prev.value + cost,
            });
        }

        if (next) {
            if (second.value > next.value && cost <= next.value) {
                decreaseCount--;
            }
            if (second.value <= next.value && cost > next.value) {
                decreaseCount++;
            }

            pq.enqueue({
                first: first,
                second: next,
                cost: cost + next.value,
            });
        }

        list.remove(second);
        first.value = cost;
        merged[second.left] = true;
    }

    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Node:
    def __init__(self, value, left):
        self.value = value
        self.left = left
        self.prev = None
        self.next = None


class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        class PQItem:
            def __init__(self, first, second, cost):
                self.first = first
                self.second = second
                self.cost = cost

            def __lt__(self, other):
                if self.cost == other.cost:
                    return self.first.left < other.first.left
                return self.cost < other.cost

        pq = []
        head = Node(nums[0], 0)
        current = head
        merged = [False] * len(nums)
        decrease_count = 0
        count = 0

        for i in range(1, len(nums)):
            new_node = Node(nums[i], i)
            current.next = new_node
            new_node.prev = current
            heapq.heappush(
                pq, PQItem(current, new_node, current.value + new_node.value)
            )

            if nums[i - 1] > nums[i]:
                decrease_count += 1

            current = new_node

        while decrease_count > 0:
            item = heapq.heappop(pq)
            first, second, cost = item.first, item.second, item.cost

            if (
                merged[first.left]
                or merged[second.left]
                or first.value + second.value != cost
            ):
                continue
            count += 1

            if first.value > second.value:
                decrease_count -= 1

            prev_node = first.prev
            next_node = second.next
            first.next = next_node
            if next_node:
                next_node.prev = first

            if prev_node:
                if prev_node.value > first.value and prev_node.value <= cost:
                    decrease_count -= 1
                elif prev_node.value <= first.value and prev_node.value > cost:
                    decrease_count += 1

                heapq.heappush(
                    pq, PQItem(prev_node, first, prev_node.value + cost)
                )

            if next_node:
                if second.value > next_node.value and cost <= next_node.value:
                    decrease_count -= 1
                elif second.value <= next_node.value and cost > next_node.value:
                    decrease_count += 1
                heapq.heappush(
                    pq, PQItem(first, next_node, cost + next_node.value)
                )

            first.value = cost
            merged[second.left] = True

        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class Node extends DoublyLinkedListNode {
    constructor(
        public value: number,
        public left: number,
    ) {
        super(value);
    }
}

interface Pair {
    first: Node;
    second: Node;
    cost: number;
}

function minimumPairRemoval(nums: number[]): number {
    const pq = new PriorityQueue<Pair>((a, b) =>
        a.cost === b.cost ? a.first.left - b.first.left : a.cost - b.cost,
    );
    const list = new DoublyLinkedList<Node>();
    const merged = new Array<boolean>(nums.length).fill(false);

    let decreaseCount = 0;
    let count = 0;
    list.insertLast(new Node(nums[0], 0));

    for (let i = 1; i < nums.length; i++) {
        list.insertLast(new Node(nums[i], i));

        const curr = list.tail();
        pq.enqueue({
            first: curr.getPrev() as Node,
            second: curr,
            cost: nums[i] + nums[i - 1],
        });

        if (nums[i - 1] > nums[i]) {
            decreaseCount++;
        }
    }

    while (decreaseCount > 0) {
        const { first, second, cost } = pq.dequeue()!;
        if (
            merged[first.left] ||
            merged[second.left] ||
            first.value + second.value !== cost
        )
            continue;
        count++;

        if (first.value > second.value) {
            decreaseCount--;
        }

        const prev = first.getPrev() as Node | null;
        const next = second.getNext() as Node | null;

        if (prev) {
            if (prev.value > first.value && prev.value <= cost) {
                decreaseCount--;
            }
            if (prev.value <= first.value && prev.value > cost) {
                decreaseCount++;
            }

            pq.enqueue({
                first: prev,
                second: first,
                cost: prev.value + cost,
            });
        }

        if (next) {
            if (second.value > next.value && cost <= next.value) {
                decreaseCount--;
            }
            if (second.value <= next.value && cost > next.value) {
                decreaseCount++;
            }

            pq.enqueue({
                first: first,
                second: next,
                cost: cost + next.value,
            });
        }

        list.remove(second);
        first.value = cost;
        merged[second.left] = true;
    }

    return count;
}
```

</details>
