# 3508. Implement Router

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/implement-router/)  
`Array` `Hash Table` `Binary Search` `Design` `Queue` `Ordered Set`

**Problem Link:** [LeetCode 3508 - Implement Router](https://leetcode.com/problems/implement-router/)

## Problem

Design a data structure that can efficiently manage data packets in a network router. Each data packet consists of the following attributes:

- source: A unique identifier for the machine that generated the packet.
- destination: A unique identifier for the target machine.
- timestamp: The time at which the packet arrived at the router.

Implement the Router class:

Router(int memoryLimit): Initializes the Router object with a fixed memory limit.

- memoryLimit is the maximum number of packets the router can store at any given time.
- If adding a new packet would exceed this limit, the oldest packet must be removed to free up space.

bool addPacket(int source, int destination, int timestamp): Adds a packet with the given attributes to the router.

- A packet is considered a duplicate if another packet with the same source, destination, and timestamp already exists in the router.
- Return true if the packet is successfully added (i.e., it is not a duplicate); otherwise return false.

int[] forwardPacket(): Forwards the next packet in FIFO (First In First Out) order.

- Remove the packet from storage.
- Return the packet as an array [source, destination, timestamp].
- If there are no packets to forward, return an empty array.

int getCount(int destination, int startTime, int endTime):

- Returns the number of packets currently stored in the router (i.e., not yet forwarded) that have the specified destination and have timestamps in the inclusive range [startTime, endTime].

Note that queries for addPacket will be made in non-decreasing order of timestamp.

### Example 1

### Example 2

## Constraints

- 2 <= memoryLimit <= 105
- 1 <= source, destination <= 2 * 105
- 1 <= timestamp <= 109
- 1 <= startTime <= endTime <= 109
- At most 105 calls will be made to addPacket, forwardPacket, and getCount methods altogether.
- queries for addPacket will be made in non-decreasing order of timestamp.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3508. Implement Router

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define PACKET_HASH_SIZE 4096
#define DEST_HASH_SIZE 4096

typedef struct {
    int source;
    int destination;
    int timestamp;
} Packet;

typedef struct PacketSetNode {
    Packet packet;
    struct PacketSetNode* next;
} PacketSetNode;

typedef struct {
    PacketSetNode** table;
    int size;
} PacketSet;

unsigned int hashPacket(Packet* p, int mod) {
    unsigned int h = 17;
    h = h * 31 + p->source;
    h = h * 31 + p->destination;
    h = h * 31 + p->timestamp;
    return h % mod;
}

PacketSet* packetSetCreate(int size) {
    PacketSet* set = malloc(sizeof(PacketSet));
    set->size = size;
    set->table = calloc(size, sizeof(PacketSetNode*));
    return set;
}

bool packetSetContains(PacketSet* set, Packet* p) {
    unsigned int idx = hashPacket(p, set->size);
    PacketSetNode* node = set->table[idx];
    while (node) {
        if (node->packet.source == p->source &&
            node->packet.destination == p->destination &&
            node->packet.timestamp == p->timestamp)
            return true;
        node = node->next;
    }
    return false;
}

void packetSetAdd(PacketSet* set, Packet* p) {
    unsigned int idx = hashPacket(p, set->size);
    PacketSetNode* node = malloc(sizeof(PacketSetNode));
    node->packet = *p;
    node->next = set->table[idx];
    set->table[idx] = node;
}

void packetSetRemove(PacketSet* set, Packet* p) {
    unsigned int idx = hashPacket(p, set->size);
    PacketSetNode* node = set->table[idx];
    PacketSetNode* prev = NULL;
    while (node) {
        if (node->packet.source == p->source &&
            node->packet.destination == p->destination &&
            node->packet.timestamp == p->timestamp) {
            if (prev)
                prev->next = node->next;
            else
                set->table[idx] = node->next;
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void packetSetFree(PacketSet* set) {
    for (int i = 0; i < set->size; i++) {
        PacketSetNode* node = set->table[i];
        while (node) {
            PacketSetNode* tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(set->table);
    free(set);
}

typedef struct Pair {
    int* timestamps;
    int size;
    int capacity;
    int head;
} Pair;

typedef struct DestNode {
    int destination;
    Pair pair;
    struct DestNode* next;
} DestNode;

typedef struct {
    int memoryLimit;
    int packetCount;
    Packet* queue;
    int head, tail;
    PacketSet* packetSet;
    DestNode** destTable;
} Router;

unsigned int hashDest(int destination) { return destination % DEST_HASH_SIZE; }

Pair* getPair(Router* obj, int destination) {
    unsigned int idx = hashDest(destination);
    DestNode* node = obj->destTable[idx];
    while (node) {
        if (node->destination == destination) return &node->pair;
        node = node->next;
    }
    node = malloc(sizeof(DestNode));
    node->destination = destination;
    node->pair.timestamps = NULL;
    node->pair.size = 0;
    node->pair.capacity = 0;
    node->pair.head = 0;
    node->next = obj->destTable[idx];
    obj->destTable[idx] = node;
    return &node->pair;
}

int lowerBound(int* nums, int size, int target, int left) {
    int right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}

Router* routerCreate(int memoryLimit) {
    Router* obj = malloc(sizeof(Router));
    obj->memoryLimit = memoryLimit;
    obj->packetCount = 0;
    obj->queue = malloc(sizeof(Packet) * memoryLimit);
    obj->head = obj->tail = 0;
    obj->packetSet = packetSetCreate(PACKET_HASH_SIZE);
    obj->destTable = calloc(DEST_HASH_SIZE, sizeof(DestNode*));
    return obj;
}

int* routerForwardPacket(Router* obj, int* retSize) {
    *retSize = 0;
    if (obj->packetCount == 0) return NULL;

    Packet packet = obj->queue[obj->head];
    obj->head = (obj->head + 1) % obj->memoryLimit;
    obj->packetCount--;

    packetSetRemove(obj->packetSet, &packet);

    Pair* pair = getPair(obj, packet.destination);
    pair->head++;

    int* res = malloc(sizeof(int) * 3);
    res[0] = packet.source;
    res[1] = packet.destination;
    res[2] = packet.timestamp;
    *retSize = 3;
    return res;
}

bool routerAddPacket(Router* obj, int source, int destination, int timestamp) {
    Packet p = {source, destination, timestamp};

    if (packetSetContains(obj->packetSet, &p)) return false;

    if (obj->packetCount == obj->memoryLimit) {
        int retSize;
        routerForwardPacket(obj, &retSize);
    }

    obj->queue[obj->tail] = p;
    obj->tail = (obj->tail + 1) % obj->memoryLimit;
    obj->packetCount++;

    packetSetAdd(obj->packetSet, &p);

    Pair* pair = getPair(obj, destination);
    if (pair->size == pair->capacity) {
        pair->capacity = pair->capacity == 0 ? 4 : pair->capacity * 2;
        pair->timestamps =
            realloc(pair->timestamps, sizeof(int) * pair->capacity);
    }
    pair->timestamps[pair->size++] = timestamp;

    return true;
}

int routerGetCount(Router* obj, int destination, int startTime, int endTime) {
    Pair* pair = getPair(obj, destination);
    if (!pair || pair->size == 0) return 0;
    int left = lowerBound(pair->timestamps, pair->size, startTime, pair->head);
    int right =
        lowerBound(pair->timestamps, pair->size, endTime + 1, pair->head);
    return right - left;
}

void routerFree(Router* obj) {
    free(obj->queue);
    packetSetFree(obj->packetSet);
    for (int i = 0; i < DEST_HASH_SIZE; i++) {
        DestNode* node = obj->destTable[i];
        while (node) {
            free(node->pair.timestamps);
            DestNode* tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(obj->destTable);
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Router {
public:
    int memLimit = 0;
    int length = 0;
    set<tuple<int, int, int>> isExist;
    unordered_map<int, deque<int>> sameDestQue;
    deque<tuple<int, int, int>> que;

    Router(int memoryLimit) { memLimit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> packet =
            make_tuple(source, destination, timestamp);
        if (isExist.contains(packet)) {
            return false;
        }
        if (length == memLimit) {
            forwardPacket();
        }
        length++;
        que.push_back(packet);
        sameDestQue[destination].push_back(timestamp);
        isExist.insert(packet);
        return true;
    }

    vector<int> forwardPacket() {
        vector<int> data;
        if (!que.empty()) {
            tuple<int, int, int> packet = que.front();
            que.pop_front();
            data = vector<int>{get<0>(packet), get<1>(packet), get<2>(packet)};
            isExist.erase(packet);
            sameDestQue[data[1]].pop_front();
            length--;
        }
        return data;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto pos1 = lower_bound(sameDestQue[destination].begin(),
                                sameDestQue[destination].end(), startTime);
        auto pos2 = upper_bound(sameDestQue[destination].begin(),
                                sameDestQue[destination].end(), endTime);
        return pos2 - pos1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Router {
    private record Packet(int Source, int Destination, int Timestamp);

    private class Pair {
        public List<int> Timestamps = new();
        public int Head = 0;
    }

    private readonly int memoryLimit;
    private readonly Queue<Packet> packetQ = new();
    private readonly HashSet<Packet> packetSet = new();
    private readonly Dictionary<int, Pair> destToTimestamps = new();

    public Router(int memoryLimit) {
        this.memoryLimit = memoryLimit;
    }

    public bool AddPacket(int source, int destination, int timestamp) {
        var packet = new Packet(source, destination, timestamp);
        if (!packetSet.Add(packet))
            return false;
        if (packetQ.Count == memoryLimit)
            ForwardPacket();
        packetQ.Enqueue(packet);
        if (!destToTimestamps.ContainsKey(destination))
            destToTimestamps[destination] = new Pair();
        destToTimestamps[destination].Timestamps.Add(timestamp);
        return true;
    }

    public int[] ForwardPacket() {
        if (packetQ.Count == 0)
            return Array.Empty<int>();
        var packet = packetQ.Dequeue();
        packetSet.Remove(packet);
        destToTimestamps[packet.Destination].Head++;
        return new int[] { packet.Source, packet.Destination,
                           packet.Timestamp };
    }

    public int GetCount(int destination, int startTime, int endTime) {
        if (!destToTimestamps.ContainsKey(destination))
            return 0;
        var p = destToTimestamps[destination];
        int left = LowerBound(p.Timestamps, startTime, p.Head);
        int right = LowerBound(p.Timestamps, endTime + 1, p.Head);
        return right - left;
    }

    private int LowerBound(List<int> nums, int target, int left) {
        int right = nums.Count;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Packet struct {
	Source, Destination, Timestamp int
}

type Pair struct {
	Timestamps []int
	Head       int
}

type Router struct {
	memoryLimit      int
	packetQ          []Packet
	packetSet        map[Packet]struct{}
	destToTimestamps map[int]*Pair
}

func Constructor(memoryLimit int) Router {
	return Router{
		memoryLimit:      memoryLimit,
		packetQ:          []Packet{},
		packetSet:        map[Packet]struct{}{},
		destToTimestamps: map[int]*Pair{},
	}
}

func (this *Router) AddPacket(source int, destination int, timestamp int) bool {
	p := Packet{source, destination, timestamp}
	if _, ok := this.packetSet[p]; ok {
		return false
	}
	if len(this.packetQ) == this.memoryLimit {
		this.ForwardPacket()
	}
	this.packetQ = append(this.packetQ, p)
	this.packetSet[p] = struct{}{}
	if _, ok := this.destToTimestamps[destination]; !ok {
		this.destToTimestamps[destination] = &Pair{}
	}
	this.destToTimestamps[destination].Timestamps = append(this.destToTimestamps[destination].Timestamps, timestamp)
	return true
}

func (this *Router) ForwardPacket() []int {
	if len(this.packetQ) == 0 {
		return []int{}
	}
	packet := this.packetQ[0]
	this.packetQ = this.packetQ[1:]
	delete(this.packetSet, packet)
	this.destToTimestamps[packet.Destination].Head++
	return []int{packet.Source, packet.Destination, packet.Timestamp}
}

func (this *Router) GetCount(destination int, startTime int, endTime int) int {
	p, ok := this.destToTimestamps[destination]
	if !ok {
		return 0
	}
	left := lowerBound(p.Timestamps, startTime, p.Head)
	right := lowerBound(p.Timestamps, endTime+1, p.Head)
	return right - left
}

func lowerBound(nums []int, target, left int) int {
	right := len(nums)
	for left < right {
		mid := (left + right) >> 1
		if nums[mid] >= target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return right
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Router {

    private record Packet(int source, int destination, int timestamp) {}

    private static class Pair {

        List<Integer> timestamps;
        int head;

        Pair() {
            this.timestamps = new ArrayList<>();
            this.head = 0;
        }
    }

    private final int memoryLimit;
    private final Queue<Packet> packetQ = new ArrayDeque<>();
    private final Set<Packet> packetSet = new HashSet<>();
    private final Map<Integer, Pair> destToTimestamps = new HashMap<>();

    public Router(int memoryLimit) {
        this.memoryLimit = memoryLimit;
    }

    public boolean addPacket(int source, int destination, int timestamp) {
        Packet packet = new Packet(source, destination, timestamp);
        if (!packetSet.add(packet)) return false;
        if (packetQ.size() == memoryLimit) forwardPacket();
        packetQ.add(packet);
        destToTimestamps
            .computeIfAbsent(destination, k -> new Pair())
            .timestamps.add(timestamp);
        return true;
    }

    public int[] forwardPacket() {
        if (packetQ.isEmpty()) return new int[] {};
        Packet packet = packetQ.poll();
        packetSet.remove(packet);
        Pair p = destToTimestamps.get(packet.destination);
        p.head++;
        return new int[] {
            packet.source,
            packet.destination,
            packet.timestamp,
        };
    }

    public int getCount(int destination, int startTime, int endTime) {
        Pair p = destToTimestamps.get(destination);
        if (p == null) return 0;
        int left = lowerBound(p.timestamps, startTime, p.head);
        int right = lowerBound(p.timestamps, endTime + 1, p.head);
        return right - left;
    }

    private int lowerBound(List<Integer> nums, int target, int left) {
        int right = nums.size();
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums.get(mid) >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class Router {
    constructor(memoryLimit) {
        this.memoryLimit = memoryLimit;
        this.packetQ = [];
        this.packetSet = new Set();
        this.destToTimestamps = new Map();
    }

    _key(p) {
        return `${p.source},${p.destination},${p.timestamp}`;
    }

    addPacket(source, destination, timestamp) {
        const packet = { source, destination, timestamp };
        const key = this._key(packet);
        if (this.packetSet.has(key)) return false;
        if (this.packetQ.length === this.memoryLimit) this.forwardPacket();
        this.packetQ.push(packet);
        this.packetSet.add(key);
        if (!this.destToTimestamps.has(destination))
            this.destToTimestamps.set(destination, { timestamps: [], head: 0 });
        this.destToTimestamps.get(destination).timestamps.push(timestamp);
        return true;
    }

    forwardPacket() {
        if (this.packetQ.length === 0) return [];
        const packet = this.packetQ.shift();
        this.packetSet.delete(this._key(packet));
        this.destToTimestamps.get(packet.destination).head++;
        return [packet.source, packet.destination, packet.timestamp];
    }

    getCount(destination, startTime, endTime) {
        const p = this.destToTimestamps.get(destination);
        if (!p) return 0;
        const left = this.lowerBound(p.timestamps, startTime, p.head);
        const right = this.lowerBound(p.timestamps, endTime + 1, p.head);
        return right - left;
    }

    lowerBound(nums, target, left) {
        let right = nums.length;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return right;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Router:
    def __init__(self, memoryLimit):
        self.memLimit = memoryLimit
        self.length = 0
        self.isExist = set()
        self.sameDestQue = {}
        self.que = []

    def addPacket(self, source, destination, timestamp):
        packet = (source, destination, timestamp)
        if packet in self.isExist:
            return False
        if self.length == self.memLimit:
            self.forwardPacket()
        self.length += 1
        self.que.append(packet)
        if destination not in self.sameDestQue:
            self.sameDestQue[destination] = SortedList()
        self.sameDestQue[destination].add(timestamp)
        self.isExist.add(packet)
        return True

    def forwardPacket(self):
        data = []
        if self.que:
            packet = self.que.pop(0)
            data = list(packet)
            self.isExist.remove(packet)
            self.sameDestQue[data[1]].remove(data[2])
            self.length -= 1
        return data

    def getCount(self, destination, startTime, endTime):
        if destination not in self.sameDestQue:
            return 0
        sl = self.sameDestQue[destination]
        l = sl.bisect_left(startTime)
        r = sl.bisect_right(endTime)
        return r - l
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class Router {
    private memoryLimit: number;
    private packetQ: {
        source: number;
        destination: number;
        timestamp: number;
    }[] = [];
    private packetSet: Set<string> = new Set();
    private destToTimestamps: Map<
        number,
        { timestamps: number[]; head: number }
    > = new Map();

    constructor(memoryLimit: number) {
        this.memoryLimit = memoryLimit;
    }

    private key(p: {
        source: number;
        destination: number;
        timestamp: number;
    }): string {
        return `${p.source},${p.destination},${p.timestamp}`;
    }

    addPacket(source: number, destination: number, timestamp: number): boolean {
        const packet = { source, destination, timestamp };
        const key = this.key(packet);
        if (this.packetSet.has(key)) return false;
        if (this.packetQ.length === this.memoryLimit) this.forwardPacket();
        this.packetQ.push(packet);
        this.packetSet.add(key);
        if (!this.destToTimestamps.has(destination))
            this.destToTimestamps.set(destination, { timestamps: [], head: 0 });
        this.destToTimestamps.get(destination)!.timestamps.push(timestamp);
        return true;
    }

    forwardPacket(): number[] {
        if (this.packetQ.length === 0) return [];
        const packet = this.packetQ.shift()!;
        this.packetSet.delete(this.key(packet));
        this.destToTimestamps.get(packet.destination)!.head++;
        return [packet.source, packet.destination, packet.timestamp];
    }

    getCount(destination: number, startTime: number, endTime: number): number {
        const p = this.destToTimestamps.get(destination);
        if (!p) return 0;
        const left = this.lowerBound(p.timestamps, startTime, p.head);
        const right = this.lowerBound(p.timestamps, endTime + 1, p.head);
        return right - left;
    }

    private lowerBound(nums: number[], target: number, left: number): number {
        let right = nums.length;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return right;
    }
}
```

</details>
