# 359. Logger Rate Limiter

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/logger-rate-limiter/)  
`Hash Table` `Design` `Data Stream`

**Problem Link:** [LeetCode 359 - Logger Rate Limiter](https://leetcode.com/problems/logger-rate-limiter/)

## Problem

Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the Logger class:

- Logger() Initializes the logger object.
- bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.

### Example 1

```text
Input
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
Output
[null, true, true, false, false, false, true]

Explanation
Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
```

## Constraints

- 0 <= timestamp <= 109
- Every timestamp will be passed in non-decreasing order (chronological order).
- 1 <= message.length <= 30
- At most 104 calls will be made to shouldPrintMessage.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Design Hit Counter](https://leetcode.com/problems/design-hit-counter/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 359. Logger Rate Limiter

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Queue + Set | C++, Java, Python |
| Hashtable / Dictionary | C++, Java, Python |

## Approach 1: Queue + Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Logger {
private:
    queue<pair<string, int>> msg_queue;
    unordered_set<string> msg_set;

public:
    /** Initialize your data structure here. */
    Logger() {
        // Leave as it is.
    }

    /** Returns true if the message should be printed in the given timestamp,
     * otherwise returns false. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!msg_queue.empty()) {
            pair<string, int> head = msg_queue.front();
            if (timestamp - head.second >= 10) {
                msg_set.erase(head.first);
                msg_queue.pop();
            } else
                break;
        }

        if (msg_set.count(message) == 0) {
            msg_queue.push(make_pair(message, timestamp));
            msg_set.insert(message);
            return true;
        } else
            return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Pair<U, V> {

    public U first;
    public V second;

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }
}

class Logger {

    private LinkedList<Pair<String, Integer>> msgQueue;
    private HashSet<String> msgSet;

    /** Initialize your data structure here. */
    public Logger() {
        msgQueue = new LinkedList<Pair<String, Integer>>();
        msgSet = new HashSet<String>();
    }

    /**
     * Returns true if the message should be printed in the given timestamp, otherwise returns false.
     */
    public boolean shouldPrintMessage(int timestamp, String message) {
        // clean up.
        while (msgQueue.size() > 0) {
            Pair<String, Integer> head = msgQueue.getFirst();
            if (timestamp - head.second >= 10) {
                msgQueue.removeFirst();
                msgSet.remove(head.first);
            } else break;
        }

        if (!msgSet.contains(message)) {
            Pair<String, Integer> newEntry = new Pair<String, Integer>(
                message,
                timestamp
            );
            msgQueue.addLast(newEntry);
            msgSet.add(message);
            return true;
        } else return false;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from collections import deque

class Logger(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._msg_set = set()
        self._msg_queue = deque()
    
    def shouldPrintMessage(self, timestamp, message):
        """
        Returns true if the message should be printed in the given timestamp, otherwise returns false.
        """
        while self._msg_queue:
            msg, ts = self._msg_queue[0]
            if timestamp - ts >= 10:
                self._msg_queue.popleft()
                self._msg_set.remove(msg)
            else:
                break
        
        if message not in self._msg_set:
            self._msg_set.add(message)
            self._msg_queue.append((message, timestamp))
            return True
        else:
            return False
```

</details>

<br>

## Approach 2: Hashtable / Dictionary

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Logger {
private:
    unordered_map<string, int> msgDict;

public:
    /** Initialize your data structure here. */
    Logger() {}

    /**
     * Returns true if the message should be printed in the given timestamp,
     * otherwise returns false.
     */
    bool shouldPrintMessage(int timestamp, string message) {
        if (this->msgDict.find(message) == this->msgDict.end()) {
            this->msgDict[message] = timestamp;
            return true;
        }

        int oldTimestamp = this->msgDict[message];
        if (timestamp - oldTimestamp >= 10) {
            this->msgDict[message] = timestamp;
            return true;
        } else
            return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Logger {

    private HashMap<String, Integer> msgDict;

    /** Initialize your data structure here. */
    public Logger() {
        msgDict = new HashMap<String, Integer>();
    }

    /**
     * Returns true if the message should be printed in the given timestamp, otherwise returns false.
     */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if (!this.msgDict.containsKey(message)) {
            this.msgDict.put(message, timestamp);
            return true;
        }

        Integer oldTimestamp = this.msgDict.get(message);
        if (timestamp - oldTimestamp >= 10) {
            this.msgDict.put(message, timestamp);
            return true;
        } else return false;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Logger(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._msg_dict = {}
    
    def shouldPrintMessage(self, timestamp, message):
        """
        Returns true if the message should be printed in the given timestamp, otherwise returns false.
        """
        if message not in self._msg_dict:
            # case 1). add the message to print
            self._msg_dict[message] = timestamp
            return True

        if timestamp - self._msg_dict[message] >= 10:
            # case 2). update the timestamp of the message
            self._msg_dict[message] = timestamp
            return True
        else:
            return False
```

</details>
