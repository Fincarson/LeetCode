# 3433. Count Mentions Per User

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-mentions-per-user/)  
`Array` `Math` `Sorting` `Simulation`

**Problem Link:** [LeetCode 3433 - Count Mentions Per User](https://leetcode.com/problems/count-mentions-per-user/)

## Problem

You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.

Each events[i] can be either of the following two types:

Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.

All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.

Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= numberOfUsers <= 100
- 1 <= events.length <= 100
- events[i].length == 3
- events[i][0] will be one of MESSAGE or OFFLINE.
- 1 <= int(events[i][1]) <= 105
- The number of id<number> mentions in any "MESSAGE" event is between 1 and 100.
- 0 <= <number> <= numberOfUsers - 1
- It is guaranteed that the user id referenced in the OFFLINE event is online at the time the event occurs.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3433. Count Mentions Per User

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Playback After Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Playback After Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    char type[8];
    int timestamp;
    char target[512];
} Event;

int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    if (e1->timestamp != e2->timestamp) {
        return e1->timestamp - e2->timestamp;
    }

    return strcmp(e1->type, "OFFLINE") == 0 ? -1 : 1;
}

int* countMentions(int numberOfUsers, char*** events, int eventsSize,
                   int* eventsColSize, int* returnSize) {
    Event* eventArr = (Event*)calloc(eventsSize, sizeof(Event));
    for (int i = 0; i < eventsSize; i++) {
        strcpy(eventArr[i].type, events[i][0]);
        eventArr[i].timestamp = atoi(events[i][1]);
        strcpy(eventArr[i].target, events[i][2]);
    }

    qsort(eventArr, eventsSize, sizeof(Event), compareEvents);
    int* count = (int*)calloc(numberOfUsers, sizeof(int));
    int* nextOnlineTime = (int*)calloc(numberOfUsers, sizeof(int));

    for (int i = 0; i < eventsSize; i++) {
        int curTime = eventArr[i].timestamp;
        char* type = eventArr[i].type;
        char* target = eventArr[i].target;
        if (strcmp(type, "MESSAGE") == 0) {
            if (strcmp(target, "ALL") == 0) {
                for (int j = 0; j < numberOfUsers; j++) {
                    count[j]++;
                }
            } else if (strcmp(target, "HERE") == 0) {
                for (int j = 0; j < numberOfUsers; j++) {
                    if (nextOnlineTime[j] <= curTime) {
                        count[j]++;
                    }
                }
            } else {
                char* token = strtok(target, " ");
                while (token != NULL) {
                    int idx = atoi(token + 2);
                    count[idx]++;
                    token = strtok(NULL, " ");
                }
            }
        } else {
            int idx = atoi(target);
            nextOnlineTime[idx] = curTime + 60;
        }
    }

    free(eventArr);
    free(nextOnlineTime);
    *returnSize = numberOfUsers;
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        vector<int> count(numberOfUsers);
        vector<int> next_online_time(numberOfUsers);
        sort(events.begin(), events.end(),
             [&](const vector<string>& lth, const vector<string>& rth) {
                 int lth_timestamp = stoi(lth[1]);
                 int rth_timestamp = stoi(rth[1]);
                 if (lth_timestamp != rth_timestamp) {
                     return lth_timestamp < rth_timestamp;
                 }
                 if (rth[0] == "OFFLINE") {
                     return false;
                 }
                 return true;
             });

        for (auto&& event : events) {
            int cur_time = stoi(event[1]);
            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        count[i]++;
                    }
                } else if (event[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (next_online_time[i] <= cur_time) {
                            count[i]++;
                        }
                    }
                } else {
                    int idx = 0;
                    for (int i = 0; i < event[2].size(); i++) {
                        if (isdigit(event[2][i])) {
                            idx = idx * 10 + (event[2][i] - '0');
                        }
                        if (i + 1 == event[2].size() ||
                            event[2][i + 1] == ' ') {
                            count[idx]++;
                            idx = 0;
                        }
                    }
                }
            } else {
                int idx = stoi(event[2]);
                next_online_time[idx] = cur_time + 60;
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] CountMentions(int numberOfUsers, IList<IList<string>> events) {
        var sortedEvents = events.OrderBy(e => int.Parse(e[1]))
                               .ThenBy(e => e[0] == "MESSAGE" ? 1 : 0)
                               .ToList();

        int[] count = new int[numberOfUsers];
        int[] nextOnlineTime = new int[numberOfUsers];

        foreach (var eventItem in sortedEvents) {
            int curTime = int.Parse(eventItem[1]);
            string type = eventItem[0];

            if (type == "MESSAGE") {
                string target = eventItem[2];
                if (target == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        count[i]++;
                    }
                } else if (target == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (nextOnlineTime[i] <= curTime) {
                            count[i]++;
                        }
                    }
                } else {
                    string[] users = target.Split(' ');
                    foreach (string user in users) {
                        int idx = int.Parse(user.Substring(2));
                        count[idx]++;
                    }
                }
            } else {
                int idx = int.Parse(eventItem[2]);
                nextOnlineTime[idx] = curTime + 60;
            }
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countMentions(numberOfUsers int, events [][]string) []int {
	sort.Slice(events, func(i, j int) bool {
		timeA, _ := strconv.Atoi(events[i][1])
		timeB, _ := strconv.Atoi(events[j][1])
		if timeA != timeB {
			return timeA < timeB
		}
		return events[i][0] != "MESSAGE" && events[j][0] == "MESSAGE"
	})

	count := make([]int, numberOfUsers)
	nextOnlineTime := make([]int, numberOfUsers)

	for _, event := range events {
		curTime, _ := strconv.Atoi(event[1])
		eventType := event[0]

		if eventType == "MESSAGE" {
			target := event[2]
			switch target {
			case "ALL":
				for i := 0; i < numberOfUsers; i++ {
					count[i]++
				}
			case "HERE":
				for i := 0; i < numberOfUsers; i++ {
					if nextOnlineTime[i] <= curTime {
						count[i]++
					}
				}
			default:
				users := strings.Split(target, " ")
				for _, user := range users {
					idx, _ := strconv.Atoi(user[2:])
					count[idx]++
				}
			}
		} else {
			idx, _ := strconv.Atoi(event[2])
			nextOnlineTime[idx] = curTime + 60
		}
	}

	return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        events.sort((a, b) -> {
            int timeA = Integer.parseInt(a.get(1));
            int timeB = Integer.parseInt(b.get(1));
            if (timeA != timeB) {
                return Integer.compare(timeA, timeB);
            }
            boolean aIsMessage = a.get(0).equals("MESSAGE");
            boolean bIsMessage = b.get(0).equals("MESSAGE");
            return Boolean.compare(aIsMessage, bIsMessage);
        });

        int[] count = new int[numberOfUsers];
        int[] nextOnlineTime = new int[numberOfUsers];

        for (List<String> event : events) {
            int curTime = Integer.parseInt(event.get(1));
            String type = event.get(0);

            if (type.equals("MESSAGE")) {
                String target = event.get(2);
                if (target.equals("ALL")) {
                    for (int i = 0; i < numberOfUsers; i++) {
                        count[i]++;
                    }
                } else if (target.equals("HERE")) {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (nextOnlineTime[i] <= curTime) {
                            count[i]++;
                        }
                    }
                } else {
                    String[] users = target.split(" ");
                    for (String user : users) {
                        int idx = Integer.parseInt(user.substring(2));
                        count[idx]++;
                    }
                }
            } else {
                int idx = Integer.parseInt(event.get(2));
                nextOnlineTime[idx] = curTime + 60;
            }
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countMentions = function (numberOfUsers, events) {
    events.sort((a, b) => {
        const timeA = parseInt(a[1]);
        const timeB = parseInt(b[1]);
        if (timeA !== timeB) {
            return timeA - timeB;
        }
        return (b[0] === "MESSAGE" ? 0 : 1) - (a[0] === "MESSAGE" ? 0 : 1);
    });

    const count = new Array(numberOfUsers).fill(0);
    const nextOnlineTime = new Array(numberOfUsers).fill(0);

    for (const event of events) {
        const curTime = parseInt(event[1]);
        const type = event[0];

        if (type === "MESSAGE") {
            const target = event[2];
            if (target === "ALL") {
                for (let i = 0; i < numberOfUsers; i++) {
                    count[i]++;
                }
            } else if (target === "HERE") {
                for (let i = 0; i < numberOfUsers; i++) {
                    if (nextOnlineTime[i] <= curTime) {
                        count[i]++;
                    }
                }
            } else {
                const users = target.split(" ");
                for (const user of users) {
                    const idx = parseInt(user.substring(2));
                    count[idx]++;
                }
            }
        } else {
            const idx = parseInt(event[2]);
            nextOnlineTime[idx] = curTime + 60;
        }
    }

    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countMentions(
        self, numberOfUsers: int, events: List[List[str]]
    ) -> List[int]:
        events.sort(key=lambda e: (int(e[1]), e[0] == "MESSAGE"))
        count = [0] * numberOfUsers
        next_online_time = [0] * numberOfUsers
        for event in events:
            cur_time = int(event[1])
            if event[0] == "MESSAGE":
                if event[2] == "ALL":
                    for i in range(numberOfUsers):
                        count[i] += 1
                elif event[2] == "HERE":
                    for i, t in enumerate(next_online_time):
                        if t <= cur_time:
                            count[i] += 1
                else:
                    for idx in event[2].split():
                        count[int(idx[2:])] += 1
            else:
                next_online_time[int(event[2])] = cur_time + 60
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countMentions(numberOfUsers: number, events: string[][]): number[] {
    events.sort((a: string[], b: string[]): number => {
        const timeA: number = parseInt(a[1]);
        const timeB: number = parseInt(b[1]);
        if (timeA !== timeB) {
            return timeA - timeB;
        }
        return (b[0] === "MESSAGE" ? 0 : 1) - (a[0] === "MESSAGE" ? 0 : 1);
    });

    const count: number[] = new Array(numberOfUsers).fill(0);
    const nextOnlineTime: number[] = new Array(numberOfUsers).fill(0);

    for (const event of events) {
        const curTime: number = parseInt(event[1]);
        const type: string = event[0];

        if (type === "MESSAGE") {
            const target: string = event[2];
            if (target === "ALL") {
                for (let i = 0; i < numberOfUsers; i++) {
                    count[i]++;
                }
            } else if (target === "HERE") {
                for (let i = 0; i < numberOfUsers; i++) {
                    if (nextOnlineTime[i] <= curTime) {
                        count[i]++;
                    }
                }
            } else {
                const users: string[] = target.split(" ");
                for (const user of users) {
                    const idx: number = parseInt(user.substring(2));
                    count[idx]++;
                }
            }
        } else {
            const idx: number = parseInt(event[2]);
            nextOnlineTime[idx] = curTime + 60;
        }
    }

    return count;
}
```

</details>
