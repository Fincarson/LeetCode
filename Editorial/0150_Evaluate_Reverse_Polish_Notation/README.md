# 150. Evaluate Reverse Polish Notation

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/evaluate-reverse-polish-notation/)  
`Array` `Math` `Stack`

**Problem Link:** [LeetCode 150 - Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

## Problem

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

- The valid operators are '+', '-', '*', and '/'.
- Each operand may be an integer or another expression.
- The division between two integers always truncates toward zero.
- There will not be any division by zero.
- The input represents a valid arithmetic expression in a reverse polish notation.
- The answer and all the intermediate calculations can be represented in a 32-bit integer.

### Example 1

```text
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

### Example 2

```text
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```

### Example 3

```text
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

## Constraints

- 1 <= tokens.length <= 104
- tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Basic Calculator](https://leetcode.com/problems/basic-calculator/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 150. Evaluate Reverse Polish Notation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Reducing the List In-place | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Evaluate with Stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Reducing the List In-place

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct hash_table {
    char key[2];
    int (*value)(int, int);
    UT_hash_handle hh;
};

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

struct hash_table *create_hash_table() {
    struct hash_table *s, *hash_table = NULL;
    int (*functions[4])(int, int) = {add, sub, mult, divide};
    char *keys[4] = {"+", "-", "*", "/"};

    for (int i = 0; i < 4; i++) {
        s = malloc(sizeof(struct hash_table));
        strncpy(s->key, keys[i], 2);
        s->value = functions[i];
        HASH_ADD_STR(hash_table, key, s);
    }

    return hash_table;
}

int evalRPN(char **tokens, int tokens_size) {
    struct hash_table *hash_table = create_hash_table();
    struct hash_table *s;
    int currentPosition = 0;
    int *stack = calloc(tokens_size, sizeof(int));
    int top = -1;

    while (currentPosition < tokens_size) {
        HASH_FIND_STR(hash_table, tokens[currentPosition], s);
        if (s == NULL) {
            stack[++top] = atoi(tokens[currentPosition++]);
        } else {
            int a = stack[top--];
            int b = stack[top--];
            stack[++top] = s->value(b, a);
            currentPosition++;
        }
    }

    int result = stack[top];
    free(stack);
    HASH_CLEAR(hh, hash_table);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    map<string, function<int(int, int)>> OPERATIONS = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }}};

public:
    int evalRPN(vector<string>& tokens) {
        int currentPosition = 0;
        while (tokens.size() > 1) {
            while (OPERATIONS.find(tokens[currentPosition]) ==
                   OPERATIONS.end()) {
                currentPosition++;
            }
            string operation = tokens[currentPosition];
            int number1 = stoi(tokens[currentPosition - 2]);
            int number2 = stoi(tokens[currentPosition - 1]);
            auto it = OPERATIONS.find(operation);
            int value = (it->second)(number1, number2);
            tokens[currentPosition] = to_string(value);
            tokens.erase(tokens.begin() + currentPosition - 2,
                         tokens.begin() + currentPosition);
            currentPosition--;
        }
        return stoi(tokens[0]);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private static Dictionary<string, Func<int, int, int>> OPERATIONS =
        new Dictionary<string, Func<int, int, int>>() {
            { "+", (int a, int b) => a + b },
            { "-", (int a, int b) => a - b },
            { "*", (int a, int b) => a * b },
            { "/", (int a, int b) => a / b }
        };

    public int EvalRPN(string[] tokens) {
        int currentPosition = 0;
        while (tokens.Length > 1) {
            while (!OPERATIONS.ContainsKey(tokens[currentPosition])) {
                currentPosition++;
            }

            string operation = tokens[currentPosition];
            int number1 = Int32.Parse(tokens[currentPosition - 2]);
            int number2 = Int32.Parse(tokens[currentPosition - 1]);
            Func<int, int, int> func = OPERATIONS[operation];
            int value = func(number1, number2);
            tokens[currentPosition] = value.ToString();
            List<string> tokenslist = tokens.ToList();
            tokenslist.RemoveRange(currentPosition - 2, 2);
            tokens = tokenslist.ToArray();
            currentPosition--;
        }

        return Int32.Parse(tokens[0]);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func evalRPN(tokens []string) int {
    OPERATIONS := map[string]func(int, int) int{
        "+": func(a, b int) int { return a + b },
        "-": func(a, b int) int { return a - b },
        "*": func(a, b int) int { return a * b },
        "/": func(a, b int) int { return a / b },
    }
    currentPosition := 0
    for len(tokens) > 1 {
        for _, exist := OPERATIONS[strings.TrimSpace(tokens[currentPosition])]; !exist; {
            currentPosition += 1
            _, exist = OPERATIONS[strings.TrimSpace(tokens[currentPosition])]
        }
        operator := strings.TrimSpace(tokens[currentPosition])
        operation, _ := OPERATIONS[operator]
        number1, _ := strconv.Atoi(tokens[currentPosition-2])
        number2, _ := strconv.Atoi(tokens[currentPosition-1])
        tokens[currentPosition] = fmt.Sprintf("%d", operation(number1, number2))
        tokens = append(tokens[:currentPosition-2], tokens[currentPosition:]...)
        currentPosition -= 1
    }
    result, _ := strconv.Atoi(tokens[0])
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static final Map<
        String,
        BiFunction<Integer, Integer, Integer>
    > OPERATIONS = new HashMap<>();

    // Ensure this only gets done once for ALL test cases.
    static {
        OPERATIONS.put("+", (a, b) -> a + b);
        OPERATIONS.put("-", (a, b) -> a - b);
        OPERATIONS.put("*", (a, b) -> a * b);
        OPERATIONS.put("/", (a, b) -> a / b);
    }

    public int evalRPN(String[] tokens) {
        int currentPosition = 0;
        int length = tokens.length; // We need to keep track of this ourselves.

        while (length > 1) {
            // Move the position pointer to the next operator token.
            while (!OPERATIONS.containsKey(tokens[currentPosition])) {
                currentPosition++;
            }

            // Extract the operation and numbers to apply operation too.
            String operation = tokens[currentPosition];
            int number1 = Integer.parseInt(tokens[currentPosition - 2]);
            int number2 = Integer.parseInt(tokens[currentPosition - 1]);

            // Calculate the result to overwrite the operator with.
            BiFunction<Integer, Integer, Integer> operator = OPERATIONS.get(
                operation
            );
            int value = operator.apply(number1, number2);
            tokens[currentPosition] = Integer.toString(value);

            // Delete numbers and point pointers correctly.
            delete2AtIndex(tokens, currentPosition - 2, length);
            currentPosition--;
            length -= 2;
        }

        return Integer.parseInt(tokens[0]);
    }

    private void delete2AtIndex(String[] tokens, int d, int length) {
        for (int i = d; i < length - 2; i++) {
            tokens[i] = tokens[i + 2];
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const OPERATORS = {
    "+": (a, b) => a + b,
    "-": (a, b) => a - b,
    "/": (a, b) => Math.trunc(a / b),
    "*": (a, b) => a * b,
};

var evalRPN = function (tokens) {
    let currentPosition = 0;

    while (tokens.length > 1) {
        // Move the current position pointer to the next operator.
        while (!(tokens[currentPosition] in OPERATORS)) {
            currentPosition += 1;
        }

        const operator = tokens[currentPosition];
        const operation = OPERATORS[operator];
        const number1 = Number(tokens[currentPosition - 2]);
        const number2 = Number(tokens[currentPosition - 1]);

        tokens[currentPosition] = operation(number1, number2);

        // Remove the numbers and move the pointer to the position
        // after the new number we just added.
        tokens.splice(currentPosition - 2, 2);
        currentPosition -= 1;
    }

    return tokens[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operations = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "/": lambda a, b: int(a / b),
            "*": lambda a, b: a * b,
        }

        current_position = 0

        while len(tokens) > 1:

            # Move the current position pointer to the next operator.
            while tokens[current_position] not in "+-*/":
                current_position += 1

            # Extract the operator and numbers from the list.
            operator = tokens[current_position]
            number_1 = int(tokens[current_position - 2])
            number_2 = int(tokens[current_position - 1])

            # Calculate the result to overwrite the operator with.
            operation = operations[operator]
            tokens[current_position] = operation(number_1, number_2)

            # Remove the numbers and move the pointer to the position
            # after the new number we just added.
            tokens.pop(current_position - 2)
            tokens.pop(current_position - 2)
            current_position -= 1

        return int(tokens[0])
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function evalRPN(tokens: string[]): number {
    const OPERATIONS = {
        "+": (a: number, b: number) => a + b,
        "-": (a: number, b: number) => a - b,
        "/": (a: number, b: number) => Math.trunc(a / b),
        "*": (a: number, b: number) => a * b,
    };
    let currentPosition = 0;
    while (tokens.length > 1) {
        while (!(tokens[currentPosition] in OPERATIONS)) {
            currentPosition += 1;
        }
        const operator = tokens[currentPosition];
        const operation = OPERATIONS[operator];
        const number1 = Number(tokens[currentPosition - 2]);
        const number2 = Number(tokens[currentPosition - 1]);
        tokens[currentPosition] = operation(number1, number2).toString();
        tokens.splice(currentPosition - 2, 2);
        currentPosition -= 1;
    }
    return Number(tokens[0]);
}
```

</details>

<br>

## Approach 2: Evaluate with Stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// enum for operations
typedef enum { ADD, SUBTRACT, DIVIDE, MULTIPLY, UNKNOWN } Operation;

struct my_struct {
    const char* id;
    Operation op_id;
    UT_hash_handle hh;
};

int perform_operation(Operation op_id, int a, int b) {
    switch (op_id) {
        case ADD:
            return a + b;
        case SUBTRACT:
            return a - b;
        case DIVIDE:
            return a / b;
        case MULTIPLY:
            return a * b;
        default:
            return 0;
    }
}

int evalRPN(char** tokens, int tokensSize) {
    struct my_struct *operations = NULL, *s;

    // Define the operations
    s = (struct my_struct*)malloc(sizeof *s);
    s->id = "+";
    s->op_id = ADD;
    HASH_ADD_KEYPTR(hh, operations, s->id, strlen(s->id), s);
    s = (struct my_struct*)malloc(sizeof *s);
    s->id = "-";
    s->op_id = SUBTRACT;
    HASH_ADD_KEYPTR(hh, operations, s->id, strlen(s->id), s);
    s = (struct my_struct*)malloc(sizeof *s);
    s->id = "/";
    s->op_id = DIVIDE;
    HASH_ADD_KEYPTR(hh, operations, s->id, strlen(s->id), s);
    s = (struct my_struct*)malloc(sizeof *s);
    s->id = "*";
    s->op_id = MULTIPLY;
    HASH_ADD_KEYPTR(hh, operations, s->id, strlen(s->id), s);

    // Iterate over the tokens
    int* stack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; ++i) {
        const char* key = tokens[i];
        HASH_FIND_STR(operations, key, s);
        if (s) {
            int op2 = stack[top--];
            int op1 = stack[top--];
            int result = perform_operation(s->op_id, op1, op2);
            stack[++top] = result;
        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    int result = stack[0];

    free(stack);
    // Cleanup
    struct my_struct *tmp, *tmp2;
    HASH_ITER(hh, operations, s, tmp) {
        HASH_DEL(operations, s);
        free(s);
    }

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> operations = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"/", [](int a, int b) { return a / b; }},
            {"*", [](int a, int b) { return a * b; }}};
        stack<int> stk;
        for (string& token : tokens) {
            if (!operations.count(token)) {
                stk.push(stoi(token));
            } else {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();
                function<int(int, int)> operation = operations[token];
                int result = operation(op1, op2);
                stk.push(result);
            }
        }
        return stk.top();
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private static Dictionary<string, Func<int, int, int>> OPERATIONS =
        new Dictionary<string, Func<int, int, int>>() {
            { "+", (int a, int b) => a + b },
            { "-", (int a, int b) => a - b },
            { "*", (int a, int b) => a * b },
            { "/", (int a, int b) => a / b }
        };

    public int EvalRPN(string[] tokens) {
        Stack<int> stack = new Stack<int>();
        foreach (string token in tokens) {
            if (!OPERATIONS.ContainsKey(token)) {
                stack.Push(Int32.Parse(token));
                continue;
            }

            int number2 = stack.Pop();
            int number1 = stack.Pop();
            Func<int, int, int> operation = OPERATIONS[token];
            int result = operation(number1, number2);
            stack.Push(result);
        }

        return stack.Pop();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func evalRPN(tokens []string) int {
    operations := map[string]func(int, int) int{
        "+": func(a, b int) int { return a + b },
        "-": func(a, b int) int { return a - b },
        "*": func(a, b int) int { return a * b },
        "/": func(a, b int) int { return a / b },
    }
    stack := []int{}
    for _, token := range tokens {
        if operation, exists := operations[token]; exists {
            num1 := stack[len(stack)-2]
            num2 := stack[len(stack)-1]
            stack = stack[:len(stack)-2]
            result := operation(num1, num2)
            stack = append(stack, result)
        } else {
            num, _ := strconv.Atoi(token)
            stack = append(stack, num)
        }
    }
    return stack[0]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static final Map<
        String,
        BiFunction<Integer, Integer, Integer>
    > OPERATIONS = new HashMap<>();

    // Ensure this only gets done once for ALL test cases.
    static {
        OPERATIONS.put("+", (a, b) -> a + b);
        OPERATIONS.put("-", (a, b) -> a - b);
        OPERATIONS.put("*", (a, b) -> a * b);
        OPERATIONS.put("/", (a, b) -> a / b);
    }

    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();

        for (String token : tokens) {
            if (!OPERATIONS.containsKey(token)) {
                stack.push(Integer.valueOf(token));
                continue;
            }

            int number2 = stack.pop();
            int number1 = stack.pop();
            BiFunction<Integer, Integer, Integer> operation;
            operation = OPERATIONS.get(token);
            int result = operation.apply(number1, number2);
            stack.push(result);
        }

        return stack.pop();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const OPERATORS = {
    "+": (a, b) => a + b,
    "-": (a, b) => a - b,
    "/": (a, b) => Math.trunc(a / b),
    "*": (a, b) => a * b,
};

var evalRPN = function (tokens) {
    const stack = [];

    for (const token of tokens) {
        if (token in OPERATORS) {
            const number2 = stack.pop();
            const number1 = stack.pop();
            const operation = OPERATORS[token];
            stack.push(operation(number1, number2));
        } else {
            stack.push(Number(token));
        }
    }

    return stack.pop();
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operations = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "/": lambda a, b: int(a / b),
            "*": lambda a, b: a * b,
        }

        stack = []
        for token in tokens:
            if token in operations:
                number_2 = stack.pop()
                number_1 = stack.pop()
                operation = operations[token]
                stack.append(operation(number_1, number_2))
            else:
                stack.append(int(token))
        return stack.pop()
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function evalRPN(tokens: string[]): number {
    const OPERATORS = {
        "+": (a: number, b: number) => a + b,
        "-": (a: number, b: number) => a - b,
        "/": (a: number, b: number) => Math.trunc(a / b),
        "*": (a: number, b: number) => a * b,
    };
    const stack: number[] = [];
    for (const token of tokens) {
        if (token in OPERATORS) {
            const number2 = stack.pop() || 0;
            const number1 = stack.pop() || 0;
            const operation = OPERATORS[token];
            stack.push(operation(number1, number2));
        } else {
            stack.push(Number(token));
        }
    }
    return stack.pop() || 0;
}
```

</details>
