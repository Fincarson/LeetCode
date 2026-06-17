# 2327. Number of People Aware of a Secret

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/number-of-people-aware-of-a-secret/)  
`Dynamic Programming` `Queue` `Simulation`

**Problem Link:** [LeetCode 2327 - Number of People Aware of a Secret](https://leetcode.com/problems/number-of-people-aware-of-a-secret/)

## Problem

On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.

### Example 1

```text
Input: n = 6, delay = 2, forget = 4
Output: 5
Explanation:
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
```

### Example 2

```text
Input: n = 4, delay = 1, forget = 3
Output: 6
Explanation:
Day 1: The first person is named A. (1 person)
Day 2: A shares the secret with B. (2 people)
Day 3: A and B share the secret with 2 new people, C and D. (4 people)
Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6 people)
```

## Constraints

- 2 <= n <= 1000
- 1 <= delay < forget <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2327. Number of People Aware of a Secret

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation + Deque | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation + Deque

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

typedef struct {
    int day;
    int count;
} Pair;

typedef struct {
    Pair* data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (Pair*)malloc(capacity * sizeof(Pair));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

int isEmpty(Queue* queue) { return queue->rear < queue->front; }

void enqueue(Queue* queue, Pair item) {
    if (queue->rear == queue->capacity - 1) {
        queue->capacity *= 2;
        queue->data =
            (Pair*)realloc(queue->data, queue->capacity * sizeof(Pair));
    }
    queue->data[++queue->rear] = item;
}

Pair dequeue(Queue* queue) { return queue->data[queue->front++]; }

Pair peek(Queue* queue) { return queue->data[queue->front]; }

void freeQueue(Queue* queue) {
    free(queue->data);
    free(queue);
}

int peopleAwareOfSecret(int n, int delay, int forget) {
    Queue* know = createQueue(n);
    Queue* share = createQueue(n);

    Pair initial = {1, 1};
    enqueue(know, initial);
    int knowCnt = 1, shareCnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!isEmpty(know) && peek(know).day == i - delay) {
            Pair first = dequeue(know);
            knowCnt = (knowCnt - first.count + MOD) % MOD;
            shareCnt = (shareCnt + first.count) % MOD;
            enqueue(share, first);
        }
        if (!isEmpty(share) && peek(share).day == i - forget) {
            Pair first = dequeue(share);
            shareCnt = (shareCnt - first.count + MOD) % MOD;
        }
        if (!isEmpty(share)) {
            knowCnt = (knowCnt + shareCnt) % MOD;
            Pair newPair = {i, shareCnt};
            enqueue(know, newPair);
        }
    }

    freeQueue(know);
    freeQueue(share);

    return (knowCnt + shareCnt) % MOD;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<pair<int, int>> know, share;
        know.emplace_back(1, 1);
        int know_cnt = 1, share_cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (!know.empty() && know[0].first == i - delay) {
                know_cnt = (know_cnt - know[0].second + mod) % mod;
                share_cnt = (share_cnt + know[0].second) % mod;
                share.push_back(know[0]);
                know.pop_front();
            }
            if (!share.empty() && share[0].first == i - forget) {
                share_cnt = (share_cnt - share[0].second + mod) % mod;
                share.pop_front();
            }
            if (!share.empty()) {
                know_cnt = (know_cnt + share_cnt) % mod;
                know.emplace_back(i, share_cnt);
            }
        }
        return (know_cnt + share_cnt) % mod;
    }

private:
    static constexpr int mod = 1000000007;
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const int MOD = 1000000007;

    public int PeopleAwareOfSecret(int n, int delay, int forget) {
        LinkedList<int[]> know = new LinkedList<int[]>();
        LinkedList<int[]> share = new LinkedList<int[]>();
        know.AddLast(new int[] { 1, 1 });
        int knowCnt = 1, shareCnt = 0;

        for (int i = 2; i <= n; i++) {
            if (know.First != null && know.First.Value[0] == i - delay) {
                int[] first = know.First.Value;
                know.RemoveFirst();
                knowCnt = (knowCnt - first[1] + MOD) % MOD;
                shareCnt = (shareCnt + first[1]) % MOD;
                share.AddLast(first);
            }
            if (share.First != null && share.First.Value[0] == i - forget) {
                int[] first = share.First.Value;
                share.RemoveFirst();
                shareCnt = (shareCnt - first[1] + MOD) % MOD;
            }
            if (share.First != null) {
                knowCnt = (knowCnt + shareCnt) % MOD;
                know.AddLast(new int[] { i, shareCnt });
            }
        }
        return (knowCnt + shareCnt) % MOD;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const MOD = 1000000007

type Pair struct {
	day   int
	count int
}

func peopleAwareOfSecret(n int, delay int, forget int) int {
	know := make([]Pair, 0)
	share := make([]Pair, 0)
	know = append(know, Pair{1, 1})
	knowCnt, shareCnt := 1, 0

	for i := 2; i <= n; i++ {
		if len(know) > 0 && know[0].day == i-delay {
			first := know[0]
			know = know[1:]
			knowCnt = (knowCnt - first.count + MOD) % MOD
			shareCnt = (shareCnt + first.count) % MOD
			share = append(share, first)
		}
		if len(share) > 0 && share[0].day == i-forget {
			first := share[0]
			share = share[1:]
			shareCnt = (shareCnt - first.count + MOD) % MOD
		}
		if len(share) > 0 {
			knowCnt = (knowCnt + shareCnt) % MOD
			know = append(know, Pair{i, shareCnt})
		}
	}
	return (knowCnt + shareCnt) % MOD
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = 1000000007;

    public int peopleAwareOfSecret(int n, int delay, int forget) {
        Deque<int[]> know = new LinkedList<>();
        Deque<int[]> share = new LinkedList<>();
        know.add(new int[] { 1, 1 });
        int knowCnt = 1;
        int shareCnt = 0;

        for (int i = 2; i <= n; i++) {
            if (!know.isEmpty() && know.peekFirst()[0] == i - delay) {
                int[] first = know.pollFirst();
                knowCnt = (knowCnt - first[1] + MOD) % MOD;
                shareCnt = (shareCnt + first[1]) % MOD;
                share.add(first);
            }
            if (!share.isEmpty() && share.peekFirst()[0] == i - forget) {
                int[] first = share.pollFirst();
                shareCnt = (shareCnt - first[1] + MOD) % MOD;
            }
            if (!share.isEmpty()) {
                knowCnt = (knowCnt + shareCnt) % MOD;
                know.add(new int[] { i, shareCnt });
            }
        }
        return (knowCnt + shareCnt) % MOD;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var peopleAwareOfSecret = function (n, delay, forget) {
    const MOD = 1000000007;
    const know = new Deque();
    const share = new Deque();
    know.pushBack({ day: 1, count: 1 });
    let knowCnt = 1,
        shareCnt = 0;

    for (let i = 2; i <= n; i++) {
        if (!know.isEmpty() && know.front().day === i - delay) {
            const first = know.popFront();
            knowCnt = (knowCnt - first.count + MOD) % MOD;
            shareCnt = (shareCnt + first.count) % MOD;
            share.pushBack(first);
        }
        if (!share.isEmpty() && share.front().day === i - forget) {
            const first = share.popFront();
            shareCnt = (shareCnt - first.count + MOD) % MOD;
        }
        if (!share.isEmpty()) {
            knowCnt = (knowCnt + shareCnt) % MOD;
            know.pushBack({ day: i, count: shareCnt });
        }
    }
    return (knowCnt + shareCnt) % MOD;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        know, share = deque([(1, 1)]), deque([])
        know_cnt, share_cnt = 1, 0
        for i in range(2, n + 1):
            if know and know[0][0] == i - delay:
                know_cnt -= know[0][1]
                share_cnt += know[0][1]
                share.append(know[0])
                know.popleft()
            if share and share[0][0] == i - forget:
                share_cnt -= share[0][1]
                share.popleft()
            if share:
                know_cnt += share_cnt
                know.append((i, share_cnt))
        return (know_cnt + share_cnt) % (10**9 + 7)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function peopleAwareOfSecret(n: number, delay: number, forget: number): number {
    const MOD = 1000000007;
    const know = new Deque<number[]>();
    const share = new Deque<number[]>();
    know.pushBack([1, 1]);
    let knowCnt = 1,
        shareCnt = 0;

    for (let i = 2; i <= n; i++) {
        if (!know.isEmpty() && know.front()[0] === i - delay) {
            const first = know.popFront();
            knowCnt = (knowCnt - first[1] + MOD) % MOD;
            shareCnt = (shareCnt + first[1]) % MOD;
            share.pushBack(first);
        }
        if (!share.isEmpty() && share.front()[0] === i - forget) {
            const first = share.popFront();
            shareCnt = (shareCnt - first[1] + MOD) % MOD;
        }
        if (!share.isEmpty()) {
            knowCnt = (knowCnt + shareCnt) % MOD;
            know.pushBack([i, shareCnt]);
        }
    }
    return (knowCnt + shareCnt) % MOD;
}
```

</details>
