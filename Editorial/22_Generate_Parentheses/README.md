# 22. Generate Parentheses

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/generate-parentheses/)  
`String` `Dynamic Programming` `Backtracking`

**Problem Link:** [LeetCode 22 - Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)

## Problem

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

### Example 1

```text
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

### Example 2

```text
Input: n = 1
Output: ["()"]
```

## Constraints

- 1 <= n <= 8

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 22. Generate Parentheses

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Backtracking, Keep Candidate Valid | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Divide and Conquer | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isValid(char* pString) {
    int leftCount = 0;
    for (int i = 0; i < strlen(pString); i++) {
        if (pString[i] == '(') {
            leftCount++;
        } else {
            leftCount--;
        }
        if (leftCount < 0) {
            return false;
        }
    }
    return leftCount == 0;
}
typedef struct queueNode {
    char* str;
    struct queueNode* next;
} QueueNode;
QueueNode* newNode(char* str) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->str = str;
    node->next = NULL;
    return node;
}
typedef struct queue {
    QueueNode *front, *rear;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enQueue(Queue* q, char* str) {
    QueueNode* node = newNode(str);
    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}
void deQueue(Queue* q) {
    if (q->front == NULL) return;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
}
bool isQueueEmpty(Queue* q) { return q->rear == NULL; }
char* front(Queue* q) { return q->front->str; }
char** generateParenthesis(int n, int* returnSize) {
    char** answer = (char**)malloc(sizeof(char*) * 10000);
    Queue* queue = createQueue();
    enQueue(queue, "");
    int index = 0;
    while (!isQueueEmpty(queue)) {
        char* curString = front(queue);
        deQueue(queue);
        if (strlen(curString) == 2 * n) {
            if (isValid(curString)) {
                answer[index] = curString;
                index++;
            }
            continue;
        }
        char* appendStringR = (char*)malloc(strlen(curString) + 2);
        strcpy(appendStringR, curString);
        strcat(appendStringR, ")");
        enQueue(queue, appendStringR);
        char* appendStringL = (char*)malloc(strlen(curString) + 2);
        strcpy(appendStringL, curString);
        strcat(appendStringL, "(");
        enQueue(queue, appendStringL);
    }
    *returnSize = index;
    return answer;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    bool isValid(std::string pString) {
        int leftCount = 0;
        for (char p : pString) {
            if (p == '(') {
                leftCount++;
            } else {
                leftCount--;
            }
            if (leftCount < 0) {
                return false;
            }
        }
        return leftCount == 0;
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> answer;
        std::queue<std::string> queue;
        queue.push("");
        while (!queue.empty()) {
            std::string curString = queue.front();
            queue.pop();
            if (curString.length() == 2 * n) {
                if (isValid(curString)) {
                    answer.push_back(curString);
                }
                continue;
            }
            queue.push(curString + ")");
            queue.push(curString + "(");
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private bool IsValid(string pString) {
        int leftCount = 0;
        foreach (char p in pString.ToCharArray()) {
            if (p == '(') {
                leftCount++;
            } else {
                leftCount--;
            }

            if (leftCount < 0) {
                return false;
            }
        }

        return leftCount == 0;
    }

    public IList<string> GenerateParenthesis(int n) {
        IList<string> answer = new List<string>();
        Queue<string> queue = new Queue<string>();
        queue.Enqueue("");
        while (queue.Count != 0) {
            string curString = queue.Dequeue();
            if (curString.Length == 2 * n) {
                if (IsValid(curString)) {
                    answer.Add(curString);
                }

                continue;
            }

            queue.Enqueue(curString + ")");
            queue.Enqueue(curString + "(");
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isValid(pString string) bool {
    leftCount := 0
    for _, p := range pString {
        if p == '(' {
            leftCount++
        } else {
            leftCount--
        }
        if leftCount < 0 {
            return false
        }
    }
    return leftCount == 0
}

func generateParenthesis(n int) []string {
    var answer []string
    queue := list.New()
    queue.PushBack("")
    for queue.Len() > 0 {
        curElement := queue.Front()
        queue.Remove(curElement)
        curString := curElement.Value.(string)
        if len(curString) == 2*n {
            if isValid(curString) {
                answer = append(answer, curString)
            }
            continue
        }
        queue.PushBack(curString + ")")
        queue.PushBack(curString + "(")
    }
    return answer
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean isValid(String pString) {
        int leftCount = 0;
        for (char p : pString.toCharArray()) {
            if (p == '(') {
                leftCount++;
            } else {
                leftCount--;
            }

            if (leftCount < 0) {
                return false;
            }
        }
        return leftCount == 0;
    }

    public List<String> generateParenthesis(int n) {
        List<String> answer = new ArrayList<>();
        Queue<String> queue = new LinkedList<>(Arrays.asList(""));

        while (!queue.isEmpty()) {
            String curString = queue.poll();

            // If the length of curString is 2 * n, add it to `answer` if
            // it is valid.
            if (curString.length() == 2 * n) {
                if (isValid(curString)) {
                    answer.add(curString);
                }
                continue;
            }
            queue.offer(curString + ")");
            queue.offer(curString + "(");
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function generateParenthesis(n) {
    let res = [];
    generate("", n, n, res);
    return res;
}
function generate(str, left, right, res) {
    if (!left && !right && str.length) {
        res.push(str);
        return;
    }
    if (left) generate(str + "(", left - 1, right, res);
    if (right > left) generate(str + ")", left, right - 1, res);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def isValid(p_string):
            left_count = 0
            for p in p_string:
                if p == "(":
                    left_count += 1
                else:
                    left_count -= 1

                if left_count < 0:
                    return False

            return left_count == 0

        answer = []
        queue = collections.deque([""])
        while queue:
            cur_string = queue.popleft()

            # If the length of cur_string is 2 * n, add it to `answer` if
            # it is valid.
            if len(cur_string) == 2 * n:
                if isValid(cur_string):
                    answer.append(cur_string)
                continue
            queue.append(cur_string + ")")
            queue.append(cur_string + "(")

        return answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function generateParenthesis(n: number): string[] {
    let res: string[] = [];
    generate("", n, n, res);
    return res;
}
function generate(
    str: string,
    left: number,
    right: number,
    res: string[],
): void {
    if (!left && !right && str.length) {
        res.push(str);
        return;
    }
    if (left) generate(str + "(", left - 1, right, res);
    if (right > left) generate(str + ")", left, right - 1, res);
}
```

</details>

<br>

## Approach 2: Backtracking, Keep Candidate Valid

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void backtracking(char* cur_string, int left_count, int right_count, int n,
                  char** answer, int* returnSize) {
    if (strlen(cur_string) == 2 * n) {
        answer[*returnSize] = (char*)malloc(strlen(cur_string) + 1);
        strcpy(answer[*returnSize], cur_string);
        (*returnSize)++;
        return;
    }
    if (left_count < n) {
        strcat(cur_string, "(");
        backtracking(cur_string, left_count + 1, right_count, n, answer,
                     returnSize);
        cur_string[strlen(cur_string) - 1] = '\0';
    }
    if (right_count < left_count) {
        strcat(cur_string, ")");
        backtracking(cur_string, left_count, right_count + 1, n, answer,
                     returnSize);
        cur_string[strlen(cur_string) - 1] = '\0';
    }
}
char** generateParenthesis(int n, int* returnSize) {
    char** answer = (char**)malloc(16384 * sizeof(char*));
    char* cur_string = (char*)malloc((2 * n + 1) * sizeof(char));
    cur_string[0] = '\0';
    *returnSize = 0;
    backtracking(cur_string, 0, 0, n, answer, returnSize);
    free(cur_string);
    return answer;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        backtracking(answer, "", 0, 0, n);
        return answer;
    }

private:
    void backtracking(vector<string>& answer, string curString, int leftCount,
                      int rightCount, int n) {
        if (curString.size() == 2 * n) {
            answer.push_back(curString);
            return;
        }
        if (leftCount < n) {
            curString += '(';
            backtracking(answer, curString, leftCount + 1, rightCount, n);
            curString.pop_back();
        }
        if (leftCount > rightCount) {
            curString += ')';
            backtracking(answer, curString, leftCount, rightCount + 1, n);
            curString.pop_back();
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
class Solution {
    public IList<string> GenerateParenthesis(int n) {
        List<string> answer = new List<string>();
        Backtracking(answer, new StringBuilder(), 0, 0, n);
        return answer;
    }

    private void Backtracking(List<string> answer, StringBuilder curString,
                              int leftCount, int rightCount, int n) {
        if (curString.Length == 2 * n) {
            answer.Add(curString.ToString());
            return;
        }

        if (leftCount < n) {
            curString.Append("(");
            Backtracking(answer, curString, leftCount + 1, rightCount, n);
            curString.Remove(curString.Length - 1, 1);
        }

        if (leftCount > rightCount) {
            curString.Append(")");
            Backtracking(answer, curString, leftCount, rightCount + 1, n);
            curString.Remove(curString.Length - 1, 1);
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func generateParenthesis(n int) []string {
    var answer []string
    var backtracking func(currString string, leftCount, rightCount int)
    backtracking = func(currString string, leftCount, rightCount int) {
        if len(currString) == 2*n {
            answer = append(answer, currString)
            return
        }
        if leftCount < n {
            backtracking(currString+"(", leftCount+1, rightCount)
        }
        if rightCount < leftCount {
            backtracking(currString+")", leftCount, rightCount+1)
        }
    }
    backtracking("", 0, 0)
    return answer
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> answer = new ArrayList<>();
        backtracking(answer, new StringBuilder(), 0, 0, n);

        return answer;
    }

    private void backtracking(
        List<String> answer,
        StringBuilder curString,
        int leftCount,
        int rightCount,
        int n
    ) {
        if (curString.length() == 2 * n) {
            answer.add(curString.toString());
            return;
        }
        if (leftCount < n) {
            curString.append("(");
            backtracking(answer, curString, leftCount + 1, rightCount, n);
            curString.deleteCharAt(curString.length() - 1);
        }
        if (leftCount > rightCount) {
            curString.append(")");
            backtracking(answer, curString, leftCount, rightCount + 1, n);
            curString.deleteCharAt(curString.length() - 1);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function generateParenthesis(n) {
    const answer = [];
    backtracking(answer, "", 0, 0, n);
    return answer;
}
function backtracking(answer, curString, leftCount, rightCount, n) {
    if (curString.length === 2 * n) {
        answer.push(curString);
        return;
    }
    if (leftCount < n) {
        curString += "(";
        backtracking(answer, curString, leftCount + 1, rightCount, n);
        curString = curString.slice(0, -1);
    }
    if (leftCount > rightCount) {
        curString += ")";
        backtracking(answer, curString, leftCount, rightCount + 1, n);
        curString = curString.slice(0, -1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        answer = []

        def backtracking(cur_string, left_count, right_count):
            if len(cur_string) == 2 * n:
                answer.append("".join(cur_string))
                return
            if left_count < n:
                cur_string.append("(")
                backtracking(cur_string, left_count + 1, right_count)
                cur_string.pop()
            if right_count < left_count:
                cur_string.append(")")
                backtracking(cur_string, left_count, right_count + 1)
                cur_string.pop()

        backtracking([], 0, 0)
        return answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function generateParenthesis(n: number): string[] {
    const answer: string[] = [];
    backtracking(answer, "", 0, 0, n);
    return answer;
}
function backtracking(
    answer: string[],
    curString: string,
    leftCount: number,
    rightCount: number,
    n: number,
): void {
    if (curString.length === 2 * n) {
        answer.push(curString);
        return;
    }
    if (leftCount < n) {
        curString += "(";
        backtracking(answer, curString, leftCount + 1, rightCount, n);
        curString = curString.slice(0, -1);
    }
    if (leftCount > rightCount) {
        curString += ")";
        backtracking(answer, curString, leftCount, rightCount + 1, n);
        curString = curString.slice(0, -1);
    }
}
```

</details>

<br>

## Approach 3: Divide and Conquer

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize) {
    if (n == 0) {
        char **result = malloc(sizeof(char *));
        result[0] = malloc(sizeof(char));
        result[0][0] = '\0';
        *returnSize = 1;
        return result;
    }
    int length = 0, index = 0;
    char **result = NULL;
    for (int left_count = 0; left_count < n; ++left_count) {
        int left_size = 0;
        int right_size = 0;
        char **left_strings = generateParenthesis(left_count, &left_size);
        char **right_strings =
            generateParenthesis(n - 1 - left_count, &right_size);
        for (int i = 0; i < left_size; ++i) {
            for (int j = 0; j < right_size; ++j) {
                length +=
                    2 + strlen(left_strings[i]) + strlen(right_strings[j]);
                result = realloc(result, length * sizeof(char *));
                result[index] = malloc(2 + strlen(left_strings[i]) +
                                       strlen(right_strings[j]) + 1);
                sprintf(result[index], "(%s)%s", left_strings[i],
                        right_strings[j]);
                ++index;
            }
        }
        for (int i = 0; i < left_size; ++i) free(left_strings[i]);
        free(left_strings);
        for (int j = 0; j < right_size; ++j) free(right_strings[j]);
        free(right_strings);
    }
    *returnSize = index;
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        if (n == 0) {
            return std::vector<std::string>{""};
        }
        std::vector<std::string> answer;
        for (int leftCount = 0; leftCount < n; ++leftCount) {
            auto leftStrings = generateParenthesis(leftCount);
            auto rightStrings = generateParenthesis(n - 1 - leftCount);
            for (const auto& leftString : leftStrings) {
                for (const auto& rightString : rightStrings) {
                    answer.push_back("(" + leftString + ")" + rightString);
                }
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<string> GenerateParenthesis(int n) {
        if (n == 0) {
            return new List<string> { "" };
        }

        List<string> answer = new List<string>();
        for (int leftCount = 0; leftCount < n; ++leftCount) {
            IList<string> leftStrings = GenerateParenthesis(leftCount);
            IList<string> rightStrings = GenerateParenthesis(n - 1 - leftCount);
            foreach (string leftString in leftStrings) {
                foreach (string rightString in rightStrings) {
                    answer.Add("(" + leftString + ")" + rightString);
                }
            }
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func generateParenthesis(n int) []string {
    if n == 0 {
        return []string{""}
    }
    var result []string
    for leftCount := 0; leftCount < n; leftCount++ {
        leftStrings := generateParenthesis(leftCount)
        rightStrings := generateParenthesis(n - 1 - leftCount)
        for _, leftString := range leftStrings {
            for _, rightString := range rightStrings {
                result = append(result, "("+leftString+")"+rightString)
            }
        }
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        if (n == 0) {
            return new ArrayList(Arrays.asList(""));
        }

        List<String> answer = new ArrayList();
        for (int leftCount = 0; leftCount < n; ++leftCount) {
            List<String> leftStrings = generateParenthesis(leftCount);
            List<String> rightStrings = generateParenthesis(n - 1 - leftCount);
            for (String leftString : leftStrings)
                for (String rightString : rightStrings)
                    answer.add("(" + leftString + ")" + rightString);
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var generateParenthesis = function (n) {
    if (n === 0) {
        return [""];
    }
    let answer = [];
    for (let leftCount = 0; leftCount < n; ++leftCount) {
        let leftStrings = generateParenthesis(leftCount);
        let rightStrings = generateParenthesis(n - 1 - leftCount);
        for (let leftString of leftStrings) {
            for (let rightString of rightStrings) {
                answer.push("(" + leftString + ")" + rightString);
            }
        }
    }
    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return [""]

        answer = []
        for left_count in range(n):
            left_strings = self.generateParenthesis(left_count)
            right_strings = self.generateParenthesis(n - 1 - left_count)
            for left_string in left_strings:
                for right_string in right_strings:
                    answer.append("(" + left_string + ")" + right_string)

        return answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function generateParenthesis(n: number): string[] {
    if (n === 0) {
        return [""];
    }
    let answer: string[] = [];
    for (let leftCount = 0; leftCount < n; ++leftCount) {
        let leftStrings = generateParenthesis(leftCount);
        let rightStrings = generateParenthesis(n - 1 - leftCount);
        for (let leftString of leftStrings) {
            for (let rightString of rightStrings) {
                answer.push("(" + leftString + ")" + rightString);
            }
        }
    }
    return answer;
}
```

</details>
