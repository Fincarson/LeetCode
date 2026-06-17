# 3408. Design Task Manager

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/design-task-manager/)  
`Hash Table` `Design` `Heap (Priority Queue)` `Ordered Set`

**Problem Link:** [LeetCode 3408 - Design Task Manager](https://leetcode.com/problems/design-task-manager/)

## Problem

There is a task management system that allows users to manage their tasks, each associated with a priority. The system should efficiently handle adding, modifying, executing, and removing tasks.

Implement the TaskManager class:

- TaskManager(vector<vector<int>>& tasks) initializes the task manager with a list of user-task-priority triples. Each element in the input list is of the form [userId, taskId, priority], which adds a task to the specified user with the given priority.
- void add(int userId, int taskId, int priority) adds a task with the specified taskId and priority to the user with userId. It is guaranteed that taskId does not exist in the system.
- void edit(int taskId, int newPriority) updates the priority of the existing taskId to newPriority. It is guaranteed that taskId exists in the system.
- void rmv(int taskId) removes the task identified by taskId from the system. It is guaranteed that taskId exists in the system.
- int execTop() executes the task with the highest priority across all users. If there are multiple tasks with the same highest priority, execute the one with the highest taskId. After executing, the taskId is removed from the system. Return the userId associated with the executed task. If no tasks are available, return -1.

Note that a user may be assigned multiple tasks.

### Example 1

## Constraints

- 1 <= tasks.length <= 105
- 0 <= userId <= 105
- 0 <= taskId <= 105
- 0 <= priority <= 109
- 0 <= newPriority <= 109
- At most 2 * 105 calls will be made in total to add, edit, rmv, and execTop methods.
- The input is generated such that taskId will be valid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3408. Design Task Manager

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Priority Queue + Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Priority Queue + Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MIN_QUEUE_SIZE 64

typedef struct Element {
    int priority;
    int taskId;
} Element;

typedef bool (*compare)(const void *, const void *);

typedef struct PriorityQueue {
    Element *arr;
    int capacity;
    int queueSize;
    compare lessFunc;
} PriorityQueue;

static bool less(const void *a, const void *b) {
    Element *e1 = (Element *)a;
    Element *e2 = (Element *)b;
    if (e1->priority == e2->priority) {
        return e1->taskId < e2->taskId;
    }
    return e1->priority < e2->priority;
}

static void memswap(void *m1, void *m2, size_t size) {
    unsigned char *a = (unsigned char *)m1;
    unsigned char *b = (unsigned char *)m2;
    while (size--) {
        *b ^= *a ^= *b ^= *a;
        a++;
        b++;
    }
}

static void swap(Element *arr, int i, int j) {
    memswap(&arr[i], &arr[j], sizeof(Element));
}

static void down(Element *arr, int size, int i, compare cmpFunc) {
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        if (k + 1 < size && cmpFunc(&arr[k], &arr[k + 1])) {
            k++;
        }
        if (cmpFunc(&arr[k], &arr[(k - 1) / 2])) {
            break;
        }
        swap(arr, k, (k - 1) / 2);
    }
}

PriorityQueue *createPriorityQueue(compare cmpFunc) {
    PriorityQueue *obj = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    obj->capacity = MIN_QUEUE_SIZE;
    obj->arr = (Element *)malloc(sizeof(Element) * obj->capacity);
    obj->queueSize = 0;
    obj->lessFunc = cmpFunc;
    return obj;
}

void heapfiy(PriorityQueue *obj) {
    for (int i = obj->queueSize / 2 - 1; i >= 0; i--) {
        down(obj->arr, obj->queueSize, i, obj->lessFunc);
    }
}

void enQueue(PriorityQueue *obj, Element *e) {
    if (obj->queueSize == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = realloc(obj->arr, sizeof(Element) * obj->capacity);
    }
    memcpy(&obj->arr[obj->queueSize], e, sizeof(Element));
    for (int i = obj->queueSize;
         i > 0 && obj->lessFunc(&obj->arr[(i - 1) / 2], &obj->arr[i]);
         i = (i - 1) / 2) {
        swap(obj->arr, i, (i - 1) / 2);
    }
    obj->queueSize++;
}

Element *deQueue(PriorityQueue *obj) {
    swap(obj->arr, 0, obj->queueSize - 1);
    down(obj->arr, obj->queueSize - 1, 0, obj->lessFunc);
    Element *e = &obj->arr[obj->queueSize - 1];
    obj->queueSize--;
    return e;
}

bool isEmpty(const PriorityQueue *obj) { return obj->queueSize == 0; }

Element *front(const PriorityQueue *obj) {
    if (obj->queueSize == 0) {
        return NULL;
    } else {
        return &obj->arr[0];
    }
}

void clear(PriorityQueue *obj) { obj->queueSize = 0; }

int size(const PriorityQueue *obj) { return obj->queueSize; }

void freeQueue(PriorityQueue *obj) {
    free(obj->arr);
    free(obj);
}

typedef struct Pair {
    int priority;
    int userId;
} Pair;

typedef struct {
    int key;
    Pair val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, Pair val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, int key, Pair val) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

Pair *hashGetItem(HashItem **obj, int key) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return NULL;
    }
    return &pEntry->val;
}

void hashEraseItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if (pEntry != NULL) {
        HASH_DEL(*obj, pEntry);
        free(pEntry);
    }
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

typedef struct {
    HashItem *taskInfo;
    PriorityQueue *heap;
} TaskManager;

TaskManager *taskManagerCreate(int **tasks, int tasksSize, int *tasksColSize) {
    TaskManager *obj = (TaskManager *)malloc(sizeof(TaskManager));
    obj->taskInfo = NULL;
    obj->heap = createPriorityQueue(less);
    for (int i = 0; i < tasksSize; i++) {
        int userId = tasks[i][0], taskId = tasks[i][1], priority = tasks[i][2];
        Pair val = {priority, userId};
        hashAddItem(&obj->taskInfo, taskId, val);
        Element e = {priority, taskId};
        enQueue(obj->heap, &e);
    }
    return obj;
}

void taskManagerAdd(TaskManager *obj, int userId, int taskId, int priority) {
    Pair val = {priority, userId};
    hashAddItem(&obj->taskInfo, taskId, val);
    Element e = {priority, taskId};
    enQueue(obj->heap, &e);
}

void taskManagerEdit(TaskManager *obj, int taskId, int newPriority) {
    if (hashFindItem(&obj->taskInfo, taskId)) {
        Pair *p = hashGetItem(&obj->taskInfo, taskId);
        Pair val = {newPriority, p->userId};
        hashSetItem(&obj->taskInfo, taskId, val);
        Element e = {newPriority, taskId};
        enQueue(obj->heap, &e);
    }
}

void taskManagerRmv(TaskManager *obj, int taskId) {
    hashEraseItem(&obj->taskInfo, taskId);
}

int taskManagerExecTop(TaskManager *obj) {
    while (!isEmpty(obj->heap)) {
        Element *p = front(obj->heap);
        int priority = p->priority;
        int taskId = p->taskId;
        deQueue(obj->heap);
        if (hashFindItem(&obj->taskInfo, taskId) &&
            hashGetItem(&obj->taskInfo, taskId)->priority == priority) {
            int userId = hashGetItem(&obj->taskInfo, taskId)->userId;
            hashEraseItem(&obj->taskInfo, taskId);
            return userId;
        }
    }
    return -1;
}

void taskManagerFree(TaskManager *obj) {
    freeQueue(obj->heap);
    hashFree(&obj->taskInfo);
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class TaskManager {
private:
    unordered_map<int, pair<int, int>> taskInfo;
    priority_queue<pair<int, int>> heap;

public:
    TaskManager(vector<vector<int>> tasks) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskInfo[taskId] = {priority, userId};
            heap.emplace(priority, taskId);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {priority, userId};
        heap.emplace(priority, taskId);
    }

    void edit(int taskId, int newPriority) {
        if (taskInfo.find(taskId) != taskInfo.end()) {
            taskInfo[taskId].first = newPriority;
            heap.emplace(newPriority, taskId);
        }
    }

    void rmv(int taskId) { taskInfo.erase(taskId); }

    int execTop() {
        while (!heap.empty()) {
            auto [priority, taskId] = heap.top();
            heap.pop();

            if (taskInfo.find(taskId) != taskInfo.end() &&
                taskInfo[taskId].first == priority) {
                int userId = taskInfo[taskId].second;
                taskInfo.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class TaskManager {
    private Dictionary<int, int[]> taskInfo;
    private PriorityQueue<int[], int[]> heap;

    public TaskManager(IList<IList<int>> tasks) {
        taskInfo = new Dictionary<int, int[]>();
        heap =
            new PriorityQueue<int[], int[]>(Comparer<int[]>.Create((a, b) => {
                if (a[0] == b[0]) {
                    return b[1].CompareTo(a[1]);
                }
                return b[0].CompareTo(a[0]);
            }));

        foreach (var task in tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskInfo[taskId] = new int[] { priority, userId };
            heap.Enqueue(new int[] { priority, taskId },
                         new int[] { priority, taskId });
        }
    }

    public void Add(int userId, int taskId, int priority) {
        taskInfo[taskId] = new int[] { priority, userId };
        heap.Enqueue(new int[] { priority, taskId },
                     new int[] { priority, taskId });
    }

    public void Edit(int taskId, int newPriority) {
        if (taskInfo.ContainsKey(taskId)) {
            taskInfo[taskId][0] = newPriority;
            heap.Enqueue(new int[] { newPriority, taskId },
                         new int[] { newPriority, taskId });
        }
    }

    public void Rmv(int taskId) {
        taskInfo.Remove(taskId);
    }

    public int ExecTop() {
        while (heap.Count > 0) {
            var task = heap.Dequeue();
            int priority = task[0], taskId = task[1];
            if (taskInfo.TryGetValue(taskId, out var info) &&
                info[0] == priority) {
                int userId = info[1];
                taskInfo.Remove(taskId);
                return userId;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type TaskManager struct {
    taskInfo map[int][2]int
    heap     *PriorityQueue
}

func Constructor(tasks [][]int) TaskManager {
    tm := TaskManager{
        taskInfo: make(map[int][2]int),
        heap:     &PriorityQueue{},
    }
    heap.Init(tm.heap)
    
    for _, task := range tasks {
        userId, taskId, priority := task[0], task[1], task[2]
        tm.taskInfo[taskId] = [2]int{priority, userId}
        heap.Push(tm.heap, Task{priority: priority, taskId: taskId})
    }
    return tm
}

func (this *TaskManager) Add(userId int, taskId int, priority int)  {
    this.taskInfo[taskId] = [2]int{priority, userId}
    heap.Push(this.heap, Task{priority: priority, taskId: taskId})
}

func (this *TaskManager) Edit(taskId int, newPriority int)  {
    if info, exists := this.taskInfo[taskId]; exists {
        info[0] = newPriority
        this.taskInfo[taskId] = info
        heap.Push(this.heap, Task{priority: newPriority, taskId: taskId})
    }
}

func (this *TaskManager) Rmv(taskId int)  {
    delete(this.taskInfo, taskId)
}

func (this *TaskManager) ExecTop() int {
    for this.heap.Len() > 0 {
        task := heap.Pop(this.heap).(Task)
        priority, taskId := task.priority, task.taskId
        if info, exists := this.taskInfo[taskId]; exists && info[0] == priority {
            userId := info[1]
            delete(this.taskInfo, taskId)
            return userId
        }
    }
    return -1
}

type Task struct {
    priority int
    taskId   int
}

type PriorityQueue []Task

func (pq PriorityQueue) Len() int { 
    return len(pq) 
}

func (pq PriorityQueue) Less(i, j int) bool {
    if pq[i].priority != pq[j].priority {
        return pq[i].priority > pq[j].priority
    }
    return pq[i].taskId > pq[j].taskId
}

func (pq PriorityQueue) Swap(i, j int) { 
    pq[i], pq[j] = pq[j], pq[i] 
}

func (pq *PriorityQueue) Push(x interface{}) { 
    *pq = append(*pq, x.(Task)) 
}

func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(old)
    item := old[n - 1]
    *pq = old[0 : n - 1]
    return item
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TaskManager {

    private Map<Integer, int[]> taskInfo;
    private PriorityQueue<int[]> heap;

    public TaskManager(List<List<Integer>> tasks) {
        taskInfo = new HashMap<>();
        heap = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) {
                return b[0] - a[0];
            }
            return b[1] - a[1];
        });

        for (List<Integer> task : tasks) {
            int userId = task.get(0);
            int taskId = task.get(1);
            int priority = task.get(2);
            taskInfo.put(taskId, new int[] { priority, userId });
            heap.offer(new int[] { priority, taskId });
        }
    }

    public void add(int userId, int taskId, int priority) {
        taskInfo.put(taskId, new int[] { priority, userId });
        heap.offer(new int[] { priority, taskId });
    }

    public void edit(int taskId, int newPriority) {
        if (taskInfo.containsKey(taskId)) {
            taskInfo.get(taskId)[0] = newPriority;
            heap.offer(new int[] { newPriority, taskId });
        }
    }

    public void rmv(int taskId) {
        taskInfo.remove(taskId);
    }

    public int execTop() {
        while (!heap.isEmpty()) {
            int[] task = heap.poll();
            int priority = task[0];
            int taskId = task[1];

            if (
                taskInfo.containsKey(taskId) &&
                taskInfo.get(taskId)[0] == priority
            ) {
                int userId = taskInfo.get(taskId)[1];
                taskInfo.remove(taskId);
                return userId;
            }
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var TaskManager = function (tasks) {
    this.taskInfo = new Map();
    this.heap = new PriorityQueue((a, b) => {
        if (a[0] === b[0]) {
            return a[1] > b[1] ? -1 : 1;
        }
        return a[0] > b[0] ? -1 : 1;
    });

    for (const [userId, taskId, priority] of tasks) {
        this.taskInfo.set(taskId, [priority, userId]);
        this.heap.enqueue([priority, taskId]);
    }
};

TaskManager.prototype.add = function (userId, taskId, priority) {
    this.taskInfo.set(taskId, [priority, userId]);
    this.heap.enqueue([priority, taskId]);
};

TaskManager.prototype.edit = function (taskId, newPriority) {
    if (this.taskInfo.has(taskId)) {
        const [priority, userId] = this.taskInfo.get(taskId);
        this.taskInfo.delete(taskId);
        this.taskInfo.set(taskId, [newPriority, userId]);
        this.heap.enqueue([newPriority, taskId]);
    }
};

TaskManager.prototype.rmv = function (taskId) {
    this.taskInfo.delete(taskId);
};

TaskManager.prototype.execTop = function () {
    while (!this.heap.isEmpty()) {
        const [priority, taskId] = this.heap.dequeue();
        if (
            this.taskInfo.has(taskId) &&
            this.taskInfo.get(taskId)[0] == priority
        ) {
            const userId = this.taskInfo.get(taskId)[1];
            this.taskInfo.delete(taskId);
            return userId;
        }
    }
    return -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.taskInfo = {}
        self.heap = []
        for userId, taskId, priority in tasks:
            self.taskInfo[taskId] = [priority, userId]
            heappush(self.heap, [-priority, -taskId])

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.taskInfo[taskId] = [priority, userId]
        heappush(self.heap, [-priority, -taskId])

    def edit(self, taskId: int, newPriority: int) -> None:
        self.taskInfo[taskId][0] = newPriority
        heappush(self.heap, [-newPriority, -taskId])

    def rmv(self, taskId: int) -> None:
        self.taskInfo.pop(taskId)

    def execTop(self) -> int:
        while self.heap:
            priority, taskId = heappop(self.heap)
            priority, taskId = -priority, -taskId
            if priority == self.taskInfo.get(taskId, [-1, -1])[0]:
                return self.taskInfo.pop(taskId)[1]
        return -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class TaskManager {
    private taskInfo: Map<number, [number, number]>;
    private heap: PriorityQueue<[number, number]>;

    constructor(tasks: number[][]) {
        this.taskInfo = new Map();
        this.heap = new PriorityQueue<[number, number]>(
            (a: [number, number], b: [number, number]) => {
                if (a[0] === b[0]) {
                    return a[1] > b[1] ? -1 : 1;
                }
                return a[0] > b[0] ? -1 : 1;
            },
        );
        for (const [userId, taskId, priority] of tasks) {
            this.taskInfo.set(taskId, [priority, userId]);
            this.heap.enqueue([priority, taskId]);
        }
    }

    add(userId: number, taskId: number, priority: number): void {
        this.taskInfo.set(taskId, [priority, userId]);
        this.heap.enqueue([priority, taskId]);
    }

    edit(taskId: number, newPriority: number): void {
        if (this.taskInfo.has(taskId)) {
            const [priority, userId] = this.taskInfo.get(taskId)!;
            this.taskInfo.delete(taskId);
            this.taskInfo.set(taskId, [newPriority, userId]);
            this.heap.enqueue([newPriority, taskId]);
        }
    }

    rmv(taskId: number): void {
        this.taskInfo.delete(taskId);
    }

    execTop(): number {
        while (!this.heap.isEmpty()) {
            const [priority, taskId] = this.heap.dequeue();
            if (
                this.taskInfo.has(taskId) &&
                this.taskInfo.get(taskId)![0] === priority
            ) {
                const userId = this.taskInfo.get(taskId)![1];
                this.taskInfo.delete(taskId);
                return userId;
            }
        }
        return -1;
    }
}
```

</details>
