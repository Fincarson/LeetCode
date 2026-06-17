# 1472. Design Browser History

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/design-browser-history/)  
`Array` `Linked List` `Stack` `Design` `Doubly-Linked List` `Data Stream`

**Problem Link:** [LeetCode 1472 - Design Browser History](https://leetcode.com/problems/design-browser-history/)

## Problem

You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

- BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
- void visit(string url) Visits url from the current page. It clears up all the forward history.
- string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
- string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

Example:

```text
Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
```

## Constraints

- 1 <= homepage.length <= 20
- 1 <= url.length <= 20
- 1 <= steps <= 100
- homepage and url consist of  '.' or lower case English letters.
- At most 5000 calls will be made to visit, back, and forward.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Design Video Sharing Platform](https://leetcode.com/problems/design-video-sharing-platform/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1472. Design Browser History

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Stacks | C++, Java, JavaScript, Python3 |
| Doubly Linked List | C++, Java, JavaScript, Python3 |
| Dynamic Array | C++, Java, JavaScript, Python3 |

## Approach 1: Two Stacks

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class BrowserHistory {
    stack<string> history, future;
    string current;
public:
    BrowserHistory(string homepage) {
        // 'homepage' is the first visited URL.
        current = homepage;
    }

    void visit(string url) {
        // Push 'current' in 'history' stack and mark 'url' as 'current'.
        history.push(current);
        current = url;
        // We need to delete all entries from 'future' stack.
        future = stack<string>();
    }
    
    string back(int steps) {
        // Pop elements from 'history' stack, and push elements in 'future' stack.
        while(steps > 0 && !history.empty()) {
            future.push(current);
            current = history.top();
            history.pop();
            steps--;
        }
        return current;
    }
    
    string forward(int steps) {
        // Pop elements from 'future' stack, and push elements in 'history' stack.
        while(steps > 0 && !future.empty()) {
            history.push(current);
            current = future.top();
            future.pop();
            steps--;
        }
        return current;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class BrowserHistory {
    private Stack<String> history, future;
    private String current;
    
    public BrowserHistory(String homepage) {
        history = new Stack<String>();
        future = new Stack<String>();
        // 'homepage' is the first visited URL.
        current = homepage;
    }
    
    public void visit(String url) {
        // Push 'current' in 'history' stack and mark 'url' as 'current'.
        history.push(current);
        current = url;
        // We need to delete all entries from 'future' stack.
        future = new Stack<String>();
    }
    
    public String back(int steps) {
        // Pop elements from 'history' stack, and push elements in 'future' stack.
        while(steps > 0 && !history.empty()) {
            future.push(current);
            current = history.pop();
            steps--;
        }
        return current;
    }
    
    public String forward(int steps) {
        // Pop elements from 'future' stack, and push elements in 'history' stack.
        while(steps > 0 && !future.empty()) {
            history.push(current);
            current = future.pop();
            steps--;
        }
        return current;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var BrowserHistory = function(homepage) {
    this.history = [], this.future = [];
    // 'homepage' is the first visited URL.
    this.current = homepage;
};

BrowserHistory.prototype.visit = function(url) {
    // Push 'current' in 'history' stack and mark 'url' as 'current'.
    this.history.push(this.current);
    this.current = url;
    // We need to delete all entries from 'future' stack.
    this.future = [];
};

BrowserHistory.prototype.back = function(steps) {
    // Pop elements from 'history' stack, and push elements in 'future' stack.
    while(steps > 0 && this.history.length != 0) {
        this.future.push(this.current);
        this.current = this.history.pop();
        steps--;
    }
    return this.current;
};

BrowserHistory.prototype.forward = function(steps) {
    // Pop elements from 'future' stack, and push elements in 'history' stack.
    while(steps > 0 && this.future.length != 0) {
        this.history.push(this.current);
        this.current = this.future.pop();
        steps--;
    }
    return this.current;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class BrowserHistory:
    def __init__(self, homepage: str):
        self._history, self._future = [], []
        # 'homepage' is the first visited URL.
        self._current = homepage

    def visit(self, url: str) -> None:
        # Push 'current' in 'history' stack and mark 'url' as 'current'.
        self._history.append(self._current)
        self._current = url
        # We need to delete all entries from 'future' stack.
        self._future = []

    def back(self, steps: int) -> str:
        # Pop elements from 'history' stack, and push elements in 'future' stack.
        while steps > 0 and self._history:
            self._future.append(self._current)
            self._current = self._history.pop()
            steps -= 1
        return self._current

    def forward(self, steps: int) -> str:
        # Pop elements from 'future' stack, and push elements in 'history' stack.
        while steps > 0 and self._future:
            self._history.append(self._current)
            self._current = self._future.pop()
            steps -= 1
        return self._current
```

</details>

<br>

## Approach 2: Doubly Linked List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class DLLNode {
public:
    string data;
    DLLNode *prev, *next;

    DLLNode(string url) {
        data = url;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:
    DLLNode* linkedListHead;
    DLLNode* current;

    BrowserHistory(string homepage) {
        // 'homepage' is the first visited URL.
        linkedListHead = new DLLNode(homepage);
        current = linkedListHead;
    }
    
    void visit(string url) {
        // Insert new node 'url' in the right of current node.
        DLLNode* newNode = new DLLNode(url);
        current->next = newNode;
        newNode->prev = current;
        // Make this new node as current node now.
        current = newNode;
    }
    
    string back(int steps) {
        // Move 'current' pointer in left direction.
        while (steps > 0 && current->prev != NULL) {
            current = current->prev;
            steps--;
        }
        return current->data;
    }
    
    string forward(int steps) {
        // Move 'current' pointer in right direction.
        while (steps > 0 && current->next != NULL) {
            current = current->next;
            steps--;
        }
        return current->data;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class DLLNode {
    public String data;
    public DLLNode prev, next;

    DLLNode(String url) {
        data = url;
        prev = null;
        next = null;
    }
};

class BrowserHistory {
    private DLLNode linkedListHead;
    private DLLNode current;

    public BrowserHistory(String homepage) {
        // 'homepage' is the first visited URL.
        linkedListHead = new DLLNode(homepage);
        current = linkedListHead;
    }
    
    public void visit(String url) {
        // Insert new node 'url' in the right of current node.
        DLLNode newNode = new DLLNode(url);
        current.next = newNode;
        newNode.prev = current;
        // Make this new node as current node now.
        current = newNode;
    }
    
    public String back(int steps) {
        // Move 'current' pointer in left direction.
        while (steps > 0 && current.prev != null) {
            current = current.prev;
            steps--;
        }
        return current.data;
    }
    
    public String forward(int steps) {
        // Move 'current' pointer in right direction.
        while (steps > 0 && current.next != null) {
            current = current.next;
            steps--;
        }
        return current.data;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class DLLNode {
    constructor(url) {
        this.data = url;
        this.prev = null;
        this.next = null;
    }
};

var BrowserHistory = function(homepage) {
    // 'homepage' is the first visited URL.
    this.linkedListHead = new DLLNode(homepage);
    this.current = this.linkedListHead;
};

BrowserHistory.prototype.visit = function(url) {
    // Insert new node 'url' in the right of current node.
    let newNode = new DLLNode(url);
    this.current.next = newNode;
    newNode.prev = this.current;
    // Make this new node as current node now.
    this.current = newNode;
};

BrowserHistory.prototype.back = function(steps) {
    // Move 'current' pointer in left direction.
    while (steps > 0 && this.current.prev != null) {
        this.current = this.current.prev;
        steps--;
    }
    return this.current.data;
};

BrowserHistory.prototype.forward = function(steps) {
    // Move 'current' pointer in right direction.
    while (steps > 0 && this.current.next != null) {
        this.current = this.current.next;
        steps--;
    }
    return this.current.data;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class DLLNode:
    def __init__(self, url: str):
        self.data = url
        self.prev, self.next = None, None

class BrowserHistory:
    def __init__(self, homepage: str):
        # 'homepage' is the first visited URL.
        self.linked_list_head = DLLNode(homepage)
        self.current = self.linked_list_head

    def visit(self, url: str) -> None:
        # Insert new node 'url' in the right of current node.
        new_node = DLLNode(url)
        self.current.next = new_node
        new_node.prev = self.current
        # Make this new node as current node now.
        self.current = new_node

    def back(self, steps: int) -> str:
        # Move 'current' pointer in left direction.
        while steps and self.current.prev:
            self.current = self.current.prev
            steps -= 1
        return self.current.data

    def forward(self, steps: int) -> str:
        # Move 'current' pointer in right direction.
        while steps and self.current.next:
            self.current = self.current.next
            steps -= 1
        return self.current.data
```

</details>

<br>

## Approach 3: Dynamic Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class BrowserHistory {
    vector<string> visitedURLs;
    int currURL, lastURL;
public:
    BrowserHistory(string homepage) {
        // 'homepage' is the first visited URL.
        visitedURLs.push_back(homepage);
        currURL = 0; 
        lastURL = 0;
    }
    
    void visit(string url) {
        currURL += 1;
        if (visitedURLs.size() > currURL) {
            // We have enough space in our array to overwrite an old 'url' entry with new one.
            visitedURLs[currURL] = url;
        } else {
            // We have to insert a new 'url' entry at the end.
            visitedURLs.push_back(url);
        }
        // This 'url' will be last URL if we try to go forward.
        lastURL = currURL;
    }
    
    string back(int steps) {
        // Move 'currURL' pointer in left direction.
        currURL = max(0, currURL - steps);
        return visitedURLs[currURL];
    }
    
    string forward(int steps) {
        // Move 'currURL' pointer in right direction.
        currURL = min(lastURL, currURL + steps);
        return visitedURLs[currURL];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class BrowserHistory {
    ArrayList<String> visitedURLs;
    int currURL, lastURL;

    public BrowserHistory(String homepage) {
        // 'homepage' is the first visited URL.
        visitedURLs = new ArrayList<String>(Arrays.asList(homepage));
        currURL = 0; 
        lastURL = 0;
    }
    
    public void visit(String url) {
        currURL += 1;
        if (visitedURLs.size() > currURL) {
            // We have enough space in our array to overwrite an old 'url' entry with new one.
            visitedURLs.set(currURL, url);
        } else {
            // We have to insert a new 'url' entry at the end.
            visitedURLs.add(url);
        }
        // This 'url' will be last URL if we try to go forward.
        lastURL = currURL;
    }
    
    public String back(int steps) {
        // Move 'currURL' pointer in left direction.
        currURL = Math.max(0, currURL - steps);
        return visitedURLs.get(currURL);
    }
    
    public String forward(int steps) {
        // Move 'currURL' pointer in right direction.
        currURL = Math.min(lastURL, currURL + steps);
        return visitedURLs.get(currURL);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var BrowserHistory = function(homepage) {
    // 'homepage' is the first visited URL.
    this.visitedURLs = [homepage]
    this.currURL = 0; 
    this.lastURL = 0;
};

BrowserHistory.prototype.visit = function(url) {
    this.currURL += 1;
    if (this.visitedURLs.length > this.currURL) {
        // We have enough space in our array to overwrite an old 'url' entry with new one.
        this.visitedURLs[this.currURL] = url;
    } else {
        // We have to insert a new 'url' entry at the end.
        this.visitedURLs.push(url);
    }
    // This 'url' will be last URL if we try to go forward.
    this.lastURL = this.currURL;
};

BrowserHistory.prototype.back = function(steps) {
    // Move 'currURL' pointer in left direction.
    this.currURL = Math.max(0, this.currURL - steps);
    return this.visitedURLs[this.currURL];
};

BrowserHistory.prototype.forward = function(steps) {
    // Move 'currURL' pointer in right direction.
    this.currURL = Math.min(this.lastURL, this.currURL + steps);
    return this.visitedURLs[this.currURL];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class BrowserHistory:
    def __init__(self, homepage: str):
        # 'homepage' is the first visited URL.
        self.visited_URLs = [homepage]
        self.curr_URL, self.last_URL = 0, 0

    def visit(self, url: str) -> None:
        self.curr_URL += 1
        if len(self.visited_URLs) > self.curr_URL:
            # We have enough space in our array to overwrite an old 'url' entry with new one.
            self.visited_URLs[self.curr_URL] = url
        else:
            # We have to insert a new 'url' entry at the end.
            self.visited_URLs.append(url)
        # This 'url' will be last URL if we try to go forward.
        self.last_URL = self.curr_URL

    def back(self, steps: int) -> str:
        # Move 'curr_URL' pointer in left direction.
        self.curr_URL = max(0, self.curr_URL - steps)
        return self.visited_URLs[self.curr_URL]

    def forward(self, steps: int) -> str:
        # Move 'curr_URL' pointer in right direction.
        self.curr_URL = min(self.last_URL, self.curr_URL + steps)
        return self.visited_URLs[self.curr_URL]
```

</details>
