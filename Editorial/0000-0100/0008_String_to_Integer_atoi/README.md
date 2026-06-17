# 8. String to Integer (atoi)

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/string-to-integer-atoi/)  
`String`

**Problem Link:** [LeetCode 8 - String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)

## Problem

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Return the integer as the final result.

### Example 1

### Example 2

### Example 3

### Example 4

### Example 5

## Constraints

- 0 <= s.length <= 200
- s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Valid Number](https://leetcode.com/problems/valid-number/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Check if Numbers Are Ascending in a Sentence](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 8. String to Integer (atoi)

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Follow the Rules | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Deterministic Finite Automaton (DFA) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Follow the Rules

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int myAtoi(char* s) {
    long sign = 1;
    long result = 0;
    int i = 0;

    while (s[i] == ' ') {
        i++;
    }

    if (s[i] == '+') {
        sign = 1;
        i++;
    } else if (s[i] == '-') {
        sign = -1;
        i++;
    }

    while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9') {
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (s[i++] - '0');
    }

    return sign * result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int myAtoi(string input) {
        int sign = 1;
        int result = 0;
        int index = 0;
        int n = input.size();

        // Discard all spaces from the beginning of the input string.
        while (index < n && input[index] == ' ') {
            index++;
        }

        // sign = +1, if it's positive number, otherwise sign = -1.
        if (index < n && input[index] == '+') {
            sign = 1;
            index++;
        } else if (index < n && input[index] == '-') {
            sign = -1;
            index++;
        }

        // Traverse next digits of input and stop if it is not a digit.
        // End of string is also non-digit character.
        while (index < n && isdigit(input[index])) {
            int digit = input[index] - '0';

            // Check overflow and underflow conditions.
            if ((result > INT_MAX / 10) ||
                (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                // If integer overflowed return 2^31-1, otherwise if underflowed
                // return -2^31.
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            // Append current digit to the result.
            result = 10 * result + digit;
            index++;
        }

        // We have formed a valid number without any overflow/underflow.
        // Return it after multiplying it with its sign.
        return sign * result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MyAtoi(string s) {
        int sign = 1;
        int result = 0;
        int i = 0;

        while (i < s.Length && s[i] == ' ') {
            i++;
        }

        if (i < s.Length && s[i] == '+') {
            sign = 1;
            i++;
        } else if (i < s.Length && s[i] == '-') {
            sign = -1;
            i++;
        }

        while (i < s.Length && char.IsDigit(s[i])) {
            if (result > int.MaxValue / 10 ||
                (result == int.MaxValue / 10 &&
                 s[i] - '0' > int.MaxValue % 10)) {
                return sign == 1 ? int.MaxValue : int.MinValue;
            }

            result = result * 10 + (s[i++] - '0');
        }

        return sign * result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func myAtoi(input string) int {
    sign := 1
    result := 0
    index := 0
    n := len(input)

    INT_MAX := int(math.Pow(2, 31) - 1)
    INT_MIN := -int(math.Pow(2, 31))

    for index < n && input[index] == ' ' {
        index++
    }

    if index < n && input[index] == '+' {
        sign = 1
        index++
    } else if index < n && input[index] == '-' {
        sign = -1
        index++
    }

    for index < n && input[index] >= '0' && input[index] <= '9' {
        digit := int(input[index] - '0')

        if result > INT_MAX/10 || (result == INT_MAX/10 && digit > INT_MAX%10) {
            if sign == 1 {
                return INT_MAX
            }
            return INT_MIN
        }

        result = 10*result + digit
        index++
    }

    return sign * result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int myAtoi(String input) {
        int sign = 1;
        int result = 0;
        int index = 0;
        int n = input.length();

        // Discard all spaces from the beginning of the input string.
        while (index < n && input.charAt(index) == ' ') {
            index++;
        }

        // sign = +1, if it's positive number, otherwise sign = -1.
        if (index < n && input.charAt(index) == '+') {
            sign = 1;
            index++;
        } else if (index < n && input.charAt(index) == '-') {
            sign = -1;
            index++;
        }

        // Traverse next digits of input and stop if it is not a digit
        while (index < n && Character.isDigit(input.charAt(index))) {
            int digit = input.charAt(index) - '0';

            // Check overflow and underflow conditions.
            if (
                (result > Integer.MAX_VALUE / 10) ||
                (result == Integer.MAX_VALUE / 10 &&
                    digit > Integer.MAX_VALUE % 10)
            ) {
                // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            // Append current digit to the result.
            result = 10 * result + digit;
            index++;
        }

        // We have formed a valid number without any overflow/underflow.
        // Return it after multiplying it with its sign.
        return sign * result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var myAtoi = function (input) {
    let sign = 1;
    let result = 0;
    let index = 0;
    let n = input.length;

    let INT_MAX = Math.pow(2, 31) - 1;
    let INT_MIN = -Math.pow(2, 31);

    // Discard all spaces from the beginning of the input string.
    while (index < n && input[index] == " ") {
        index++;
    }

    // sign = +1, if it's positive number, otherwise sign = -1.
    if (index < n && input[index] == "+") {
        sign = 1;
        index++;
    } else if (index < n && input[index] == "-") {
        sign = -1;
        index++;
    }

    // Traverse next digits of input and stop if it is not a digit.
    // End of string is also non-digit character.
    while (index < n && input[index] >= "0" && input[index] <= "9") {
        let digit = input[index] - "0";

        // Check overflow and underflow conditions.
        if (
            result > Math.floor(INT_MAX / 10) ||
            (result == Math.floor(INT_MAX / 10) && digit > INT_MAX % 10)
        ) {
            // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        // Append current digit to the result.
        result = 10 * result + digit;
        index++;
    }

    // We have formed a valid number without any overflow/underflow.
    // Return it after multiplying it with its sign.
    return sign * result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def myAtoi(self, input: str) -> int:
        sign = 1
        result = 0
        index = 0
        n = len(input)

        INT_MAX = pow(2, 31) - 1
        INT_MIN = -pow(2, 31)

        # Discard all spaces from the beginning of the input string.
        while index < n and input[index] == " ":
            index += 1

        # sign = +1, if it's positive number, otherwise sign = -1.
        if index < n and input[index] == "+":
            sign = 1
            index += 1
        elif index < n and input[index] == "-":
            sign = -1
            index += 1

        # Traverse next digits of input and stop if it is not a digit.
        # End of string is also non-digit character.
        while index < n and input[index].isdigit():
            digit = int(input[index])

            # Check overflow and underflow conditions.
            if (result > INT_MAX // 10) or (
                result == INT_MAX // 10 and digit > INT_MAX % 10
            ):
                # If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.
                return INT_MAX if sign == 1 else INT_MIN

            # Append current digit to the result.
            result = 10 * result + digit
            index += 1

        # We have formed a valid number without any overflow/underflow.
        # Return it after multiplying it with its sign.
        return sign * result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function myAtoi(s: string): number {
    let sign = 1;
    let result = 0;
    let index = 0;
    let n = s.length;

    let INT_MAX = Math.pow(2, 31) - 1;
    let INT_MIN = -Math.pow(2, 31);

    while (index < n && s[index] == " ") {
        index++;
    }

    if (index < n && s[index] == "+") {
        sign = 1;
        index++;
    } else if (index < n && s[index] == "-") {
        sign = -1;
        index++;
    }

    while (index < n && s[index] >= "0" && s[index] <= "9") {
        let digit = Number(s[index]);

        if (
            result > Math.floor(INT_MAX / 10) ||
            (result == Math.floor(INT_MAX / 10) && digit > INT_MAX % 10)
        ) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result = 10 * result + digit;
        index++;
    }

    return sign * result;
}
```

</details>

<br>

## Approach 2: Deterministic Finite Automaton (DFA)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Define the state enum in C style.
typedef enum { q0, q1, q2, qd } State;

// Create a struct to hold the state machine's data.
typedef struct {
    State currentState;
    int result;
    int sign;
} StateMachine;

// Initialize the state machine.
void initStateMachine(StateMachine *machine) {
    machine->currentState = q0;
    machine->result = 0;
    machine->sign = 1;
}

// Transition to state q1.
void toStateQ1(StateMachine *machine, char ch) {
    machine->sign = (ch == '-') ? -1 : 1;
    machine->currentState = q1;
}

// Transition to state q2.
void toStateQ2(StateMachine *machine, int digit) {
    machine->currentState = q2;
    // Append current digit to the result.
    if ((machine->result > INT_MAX / 10) ||
        (machine->result == INT_MAX / 10 && digit > INT_MAX % 10)) {
        if (machine->sign == 1) {
            // If sign is 1, clamp result to INT_MAX.
            machine->result = INT_MAX;
        } else {
            // If sign is -1, clamp result to INT_MIN.
            machine->result = INT_MIN;
            machine->sign = 1;
        }
        // When the 32-bit int range is exceeded, a dead state is reached.
        machine->currentState = qd;
    } else {
        machine->result = machine->result * 10 + digit;
    }
}

// Transition to dead state qd.
void toStateQd(StateMachine *machine) { machine->currentState = qd; }

// Change state based on current input character.
void transition(StateMachine *machine, char ch) {
    if (machine->currentState == q0) {
        if (ch == ' ') {
            return;
        } else if (ch == '-' || ch == '+') {
            toStateQ1(machine, ch);
        } else if (isdigit(ch)) {
            toStateQ2(machine, ch - '0');
        } else {
            toStateQd(machine);
        }
    } else if (machine->currentState == q1 || machine->currentState == q2) {
        if (isdigit(ch)) {
            toStateQ2(machine, ch - '0');
        } else {
            toStateQd(machine);
        }
    }
}

// Return the final result formed with its sign.
int getInteger(StateMachine *machine) {
    return machine->sign * machine->result;
}

// Get current state.
State getState(StateMachine *machine) { return machine->currentState; }

// Function to parse string to integer using the state machine.
int myAtoi(char *s) {
    StateMachine Q;
    initStateMachine(&Q);

    for (int i = 0; s[i] != '\0' && getState(&Q) != qd; ++i) {
        transition(&Q, s[i]);
    }

    return getInteger(&Q);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
enum State { q0, q1, q2, qd };

class StateMachine {
    // Store current state value.
    State currentState;
    // Store result formed and it's sign.
    int result, sign;
    
    // Transition to state q1.
    void toStateQ1(char& ch) {
        sign = (ch == '-') ? -1 : 1;
        currentState = q1;
    }
    
    // Transition to state q2.
    void toStateQ2(int digit) {
        currentState = q2;
        appendDigit(digit);
    }
    
    // Transition to dead state qd.
    void toStateQd() {
        currentState = qd;
    }
    
    // Append digit to result, if out of range return clamped value.
    void appendDigit(int& digit) {
        if ((result > INT_MAX / 10) || 
            (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            if (sign == 1) {
                // If sign is 1, clamp result to INT_MAX.
                result = INT_MAX;
            } else {
                // If sign is -1, clamp result to INT_MIN.
                result = INT_MIN;
                sign = 1;
            }
            
            // When the 32-bit int range is exceeded, a dead state is reached.
            toStateQd();
        } else {
            // Append current digit to the result. 
            result = result * 10 + digit;
        }
    }

public:
    StateMachine() {
        currentState = q0;
        result = 0;
        sign = 1;
    }

    // Change state based on current input character.
    void transition(char& ch) {
        if (currentState == q0) {
            // Beginning state of the string (or some whitespaces are skipped).
            if (ch == ' ') {
                // Current character is a whitespaces.
                // We stay in same state. 
                return;
            } else if (ch == '-' || ch == '+') {
                // Current character is a sign.
                toStateQ1(ch);
            } else if (isdigit(ch)) {
                // Current character is a digit.
                toStateQ2(ch - '0');
            } else {
                // Current character is not a space/sign/digit.
                // Reached a dead state.
                toStateQd();
            }
        } else if (currentState == q1 || currentState == q2) {
            // Previous character was a sign or digit.
            if (isdigit(ch)) {
                // Current character is a digit.
                toStateQ2(ch - '0');
            } else {
                // Current character is not a digit.
                // Reached a dead state.
                toStateQd();
            }
        }
    }
    
    // Return the final result formed with it's sign.
    int getInteger() {
        return sign * result;
    }
    
    // Get current state.
    State getState() {
        return currentState;
    }
};

class Solution {
public:
    int myAtoi(string s) {
        StateMachine Q;
        
        for (int i = 0; i < s.size() && Q.getState() != qd; ++i) {
            Q.transition(s[i]);
        }
        
        return Q.getInteger();
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public enum State { q0, q1, q2, qd }

public class StateMachine {
    private State currentState;
    private long result;
    private int sign;

    public StateMachine() {
        currentState = State.q0;
        result = 0;
        sign = 1;
    }

    private void toStateQ1(char ch) {
        sign = (ch == '-') ? -1 : 1;
        currentState = State.q1;
    }

    private void toStateQ2(int digit) {
        currentState = State.q2;
        appendDigit(digit);
    }

    private void toStateQd() {
        currentState = State.qd;
    }

    public void appendDigit(int digit) {
        if ((result > int.MaxValue / 10) ||
            (result == int.MaxValue / 10 && digit > int.MaxValue % 10)) {
            if (sign == 1) {
                result = int.MaxValue;
            } else {
                result = int.MinValue;
                sign = 1;
            }

            toStateQd();
        } else {
            result = result * 10 + digit;
        }
    }

    public void transition(char ch) {
        if (currentState == State.q0) {
            if (ch == ' ') {
                return;
            } else if (ch == '-' || ch == '+') {
                toStateQ1(ch);
            } else if (char.IsDigit(ch)) {
                toStateQ2(ch - '0');
            } else {
                toStateQd();
            }
        } else if (currentState == State.q1 || currentState == State.q2) {
            if (char.IsDigit(ch)) {
                toStateQ2(ch - '0');
            } else {
                toStateQd();
            }
        }
    }

    public int getInteger() {
        return (int)(sign * result);
    }

    public State getState() {
        return currentState;
    }
}

public class Solution {
    public int MyAtoi(string s) {
        StateMachine Q = new StateMachine();
        for (int i = 0; i < s.Length && Q.getState() != State.qd; ++i) {
            Q.transition(s[i]);
        }

        return Q.getInteger();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type State int

const (
    q0 State = iota
    q1
    q2
    qd
)

type StateMachine struct {
    currentState State
    result, sign int
}

func (sm *StateMachine) toStateQ1(ch byte) {
    if ch == '-' {
        sm.sign = -1
    } else {
        sm.sign = 1
    }
    sm.currentState = q1
}

func (sm *StateMachine) toStateQ2(digit int) {
    sm.currentState = q2
    sm.appendDigit(digit)
}

func (sm *StateMachine) toStateQd() {
    sm.currentState = qd
}

func (sm *StateMachine) appendDigit(digit int) {
    if (sm.result > math.MaxInt32/10) ||
        (sm.result == math.MaxInt32/10 && digit > math.MaxInt32%10) {
        if sm.sign == 1 {
            sm.result = math.MaxInt32
        } else {
            sm.result = math.MinInt32
            sm.sign = 1
        }
        sm.toStateQd()
    } else {
        sm.result = sm.result*10 + digit
    }
}

func (sm *StateMachine) Transition(ch byte) {
    switch sm.currentState {
    case q0:
        if ch == ' ' {
            return
        }
        if ch == '-' || ch == '+' {
            sm.toStateQ1(ch)
        } else if ch >= '0' && ch <= '9' {
            sm.toStateQ2(int(ch - '0'))
        } else {
            sm.toStateQd()
        }
    case q1, q2:
        if ch >= '0' && ch <= '9' {
            sm.toStateQ2(int(ch - '0'))
        } else {
            sm.toStateQd()
        }
    }
}

func (sm *StateMachine) GetInteger() int {
    return sm.sign * sm.result
}

func (sm *StateMachine) getState() State {
    return sm.currentState
}

func myAtoi(s string) int {
    Q := StateMachine{currentState: q0, result: 0, sign: 1}
    for i := 0; i < len(s) && Q.getState() != qd; i++ {
        Q.Transition(s[i])
    }
    return Q.GetInteger()
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
enum State {
    q0,
    q1,
    q2,
    qd,
}

class StateMachine {
    // Store current state value.
    private State currentState;
    // Store result formed and it's sign.
    private int result, sign;

    public StateMachine() {
        currentState = State.q0;
        result = 0;
        sign = 1;
    }

    // Transition to state q1.
    private void toStateQ1(char ch) {
        sign = (ch == '-') ? -1 : 1;
        currentState = State.q1;
    }

    // Transition to state q2.
    private void toStateQ2(int digit) {
        currentState = State.q2;
        appendDigit(digit);
    }

    // Transition to dead state qd.
    private void toStateQd() {
        currentState = State.qd;
    }

    // Append digit to result, if out of range return clamped value.
    private void appendDigit(int digit) {
        if (
            (result > Integer.MAX_VALUE / 10) ||
            (result == Integer.MAX_VALUE / 10 && digit > Integer.MAX_VALUE % 10)
        ) {
            if (sign == 1) {
                // If sign is 1, clamp result to Integer.MAX_VALUE.
                result = Integer.MAX_VALUE;
            } else {
                // If sign is -1, clamp result to Integer.MIN_VALUE.
                result = Integer.MIN_VALUE;
                sign = 1;
            }

            // When the 32-bit int range is exceeded, a dead state is reached.
            toStateQd();
        } else {
            // Append current digit to the result.
            result = result * 10 + digit;
        }
    }

    // Change state based on current input character.
    public void transition(char ch) {
        if (currentState == State.q0) {
            // Beginning state of the string (or some whitespaces are skipped).
            if (ch == ' ') {
                // Current character is a whitespaces.
                // We stay in same state.
                return;
            } else if (ch == '-' || ch == '+') {
                // Current character is a sign.
                toStateQ1(ch);
            } else if (Character.isDigit(ch)) {
                // Current character is a digit.
                toStateQ2(ch - '0');
            } else {
                // Current character is not a space/sign/digit.
                // Reached a dead state.
                toStateQd();
            }
        } else if (currentState == State.q1 || currentState == State.q2) {
            // Previous character was a sign or digit.
            if (Character.isDigit(ch)) {
                // Current character is a digit.
                toStateQ2(ch - '0');
            } else {
                // Current character is not a digit.
                // Reached a dead state.
                toStateQd();
            }
        }
    }

    // Return the final result formed with it's sign.
    public int getInteger() {
        return sign * result;
    }

    // Get current state.
    public State getState() {
        return currentState;
    }
}

class Solution {
    public int myAtoi(String s) {
        StateMachine Q = new StateMachine();

        for (int i = 0; i < s.length() && Q.getState() != State.qd; ++i) {
            Q.transition(s.charAt(i));
        }

        return Q.getInteger();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class StateMachine {
    // Store current state value.
    #currentState;
    // Store result formed and it's sign.
    #result;
    #sign;

    State;
    #INT_MAX;
    #INT_MIN;

    constructor() {
        this.State = { q0: 1, q1: 2, q2: 3, qd: 4 };
        this.#INT_MAX = Math.pow(2, 31) - 1;
        this.#INT_MIN = -Math.pow(2, 31);

        this.#currentState = this.State.q0;
        this.#result = 0;
        this.#sign = 1;
    }

    // Transition to state q1.
    toStateQ1(ch) {
        this.#sign = ch == "-" ? -1 : 1;
        this.#currentState = this.State.q1;
    }

    // Transition to state q2.
    toStateQ2(digit) {
        this.#currentState = this.State.q2;
        this.appendDigit(digit);
    }

    // Transition to dead state qd.
    toStateQd() {
        this.#currentState = this.State.qd;
    }

    // Append digit to result, if out of range return clamped value.
    appendDigit(digit) {
        if (
            this.#result > Math.floor(this.#INT_MAX / 10) ||
            (this.#result == Math.floor(this.#INT_MAX / 10) &&
                digit > this.#INT_MAX % 10)
        ) {
            if (this.#sign == 1) {
                // If sign is 1, clamp result to INT_MAX.
                this.#result = this.#INT_MAX;
            } else {
                // If sign is -1, clamp result to INT_MIN.
                this.#result = this.#INT_MIN;
                this.#sign = 1;
            }

            // When the 32-bit int range is exceeded, a dead state is reached.
            this.toStateQd();
        } else {
            // Append current digit to the result.
            this.#result = this.#result * 10 + digit;
        }
    }

    // Change state based on current input character.
    transition(ch) {
        if (this.#currentState == this.State.q0) {
            // Beginning state of the string (or some whitespaces are skipped).
            if (ch == " ") {
                // Current character is a whitespaces.
                // We stay in same state.
                return;
            } else if (ch == "-" || ch == "+") {
                // Current character is a sign.
                this.toStateQ1(ch);
            } else if (ch >= "0" && ch <= "9") {
                // Current character is a digit.
                this.toStateQ2(ch - "0");
            } else {
                // Current character is not a space/sign/digit.
                // Reached a dead state.
                this.toStateQd();
            }
        } else if (
            this.#currentState == this.State.q1 ||
            this.#currentState == this.State.q2
        ) {
            // Previous character was a sign or digit.
            if (ch >= "0" && ch <= "9") {
                // Current character is a digit.
                this.toStateQ2(ch - "0");
            } else {
                // Current character is not a digit.
                // Reached a dead state.
                this.toStateQd();
            }
        }
    }

    // Return the final result formed with it's sign.
    getInteger() {
        return this.#sign * this.#result;
    }

    // Get current state.
    getState() {
        return this.#currentState;
    }
}

var myAtoi = function (s) {
    let Q = new StateMachine();

    for (let i = 0; i < s.length && Q.getState() != Q.State.qd; ++i) {
        Q.transition(s[i]);
    }

    return Q.getInteger();
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class StateMachine:
    def __init__(self):
        self.State = {"q0": 1, "q1": 2, "q2": 3, "qd": 4}
        self.INT_MAX, self.INT_MIN = pow(2, 31) - 1, -pow(2, 31)

        # Store current state value.
        self.__current_state = self.State["q0"]
        # Store result formed and its sign.
        self.__result = 0
        self.__sign = 1

    def to_state_q1(self, ch: chr) -> None:
        """Transition to state q1."""
        self.__sign = -1 if (ch == "-") else 1
        self.__current_state = self.State["q1"]

    def to_state_q2(self, digit: int) -> None:
        """Transition to state q2."""
        self.__current_state = self.State["q2"]
        self.append_digit(digit)

    def to_state_qd(self) -> None:
        """Transition to dead state qd."""
        self.__current_state = self.State["qd"]

    def append_digit(self, digit: int) -> None:
        """Append digit to result, if out of range return clamped value."""
        if (self.__result > self.INT_MAX // 10) or (
            self.__result == self.INT_MAX // 10 and digit > self.INT_MAX % 10
        ):
            if self.__sign == 1:
                # If sign is 1, clamp result to INT_MAX.
                self.__result = self.INT_MAX
            else:
                # If sign is -1, clamp result to INT_MIN.
                self.__result = self.INT_MIN
                self.__sign = 1

            # When the 32-bit int range is exceeded, a dead state is reached.
            self.to_state_qd()
        else:
            # Append current digit to the result.
            self.__result = (self.__result * 10) + digit

    def transition(self, ch: chr) -> None:
        """Change state based on current input character."""
        if self.__current_state == self.State["q0"]:
            # Beginning state of the string (or some whitespaces are skipped).
            if ch == " ":
                # Current character is a whitespaces.
                # We stay in same state.
                return
            elif ch == "-" or ch == "+":
                # Current character is a sign.
                self.to_state_q1(ch)
            elif ch.isdigit():
                # Current character is a digit.
                self.to_state_q2(int(ch))
            else:
                # Current character is not a space/sign/digit.
                # Reached a dead state.
                self.to_state_qd()

        elif (
            self.__current_state == self.State["q1"]
            or self.__current_state == self.State["q2"]
        ):
            # Previous character was a sign or digit.
            if ch.isdigit():
                # Current character is a digit.
                self.to_state_q2(int(ch))
            else:
                # Current character is not a digit.
                # Reached a dead state.
                self.to_state_qd()

    def get_integer(self) -> int:
        """Return the final result formed with it's sign."""
        return self.__sign * self.__result

    def get_state(self) -> int:
        """Get current state."""
        return self.__current_state


class Solution:
    def myAtoi(self, input: str) -> int:
        q = StateMachine()

        for ch in input:
            q.transition(ch)
            if q.get_state() == q.State["qd"]:
                break

        return q.get_integer()
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type State = {
    q0: number;
    q1: number;
    q2: number;
    qd: number;
};

class StateMachine {
    // Store current state value.
    private currentState: number;
    // Store result formed and it's sign.
    private result: number;
    private sign: number;

    readonly State: State;
    private readonly INT_MAX: number;
    private readonly INT_MIN: number;

    constructor() {
        this.State = { q0: 1, q1: 2, q2: 3, qd: 4 };
        this.INT_MAX = Math.pow(2, 31) - 1;
        this.INT_MIN = -Math.pow(2, 31);

        this.currentState = this.State.q0;
        this.result = 0;
        this.sign = 1;
    }

    // Transition to state q1.
    private toStateQ1(ch: string): void {
        this.sign = ch === "-" ? -1 : 1;
        this.currentState = this.State.q1;
    }

    // Transition to state q2.
    private toStateQ2(digit: number): void {
        this.currentState = this.State.q2;
        this.appendDigit(digit);
    }

    // Transition to dead state qd.
    private toStateQd(): void {
        this.currentState = this.State.qd;
    }

    // Append digit to result, if out of range return clamped value.
    private appendDigit(digit: number): void {
        if (
            this.result > Math.floor(this.INT_MAX / 10) ||
            (this.result === Math.floor(this.INT_MAX / 10) &&
                digit > this.INT_MAX % 10)
        ) {
            if (this.sign === 1) {
                // If sign is 1, clamp result to INT_MAX.
                this.result = this.INT_MAX;
            } else {
                // If sign is -1, clamp result to INT_MIN.
                this.result = this.INT_MIN;
                this.sign = 1;
            }

            // When the 32-bit int range is exceeded, a dead state is reached.
            this.toStateQd();
        } else {
            // Append current digit to the result.
            this.result = this.result * 10 + digit;
        }
    }

    // Change state based on current input character.
    public transition(ch: string): void {
        if (this.currentState === this.State.q0) {
            // Beginning state of the string (or some whitespaces are skipped).
            if (ch === " ") {
                // Current character is a whitespace.
                // We stay in the same state.
                return;
            } else if (ch === "-" || ch === "+") {
                // Current character is a sign.
                this.toStateQ1(ch);
            } else if (ch >= "0" && ch <= "9") {
                // Current character is a digit.
                this.toStateQ2(parseInt(ch));
            } else {
                // Current character is not a space/sign/digit.
                // Reached a dead state.
                this.toStateQd();
            }
        } else if (
            this.currentState === this.State.q1 ||
            this.currentState === this.State.q2
        ) {
            // Previous character was a sign or digit.
            if (ch >= "0" && ch <= "9") {
                // Current character is a digit.
                this.toStateQ2(parseInt(ch));
            } else {
                // Current character is not a digit.
                // Reached a dead state.
                this.toStateQd();
            }
        }
    }

    // Return the final result formed with its sign.
    public getInteger(): number {
        return this.sign * this.result;
    }

    // Get current state.
    public getState(): number {
        return this.currentState;
    }
}

function myAtoi(s: string): number {
    let Q = new StateMachine();

    for (let i = 0; i < s.length && Q.getState() !== Q.State.qd; ++i) {
        Q.transition(s[i]);
    }

    return Q.getInteger();
}
```

</details>
