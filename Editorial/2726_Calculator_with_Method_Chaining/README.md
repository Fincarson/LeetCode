# 2726. Calculator with Method Chaining

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/calculator-with-method-chaining/)  

**Problem Link:** [LeetCode 2726 - Calculator with Method Chaining](https://leetcode.com/problems/calculator-with-method-chaining/)

## Problem

Design a Calculator class. The class should provide the mathematical operations of addition, subtraction, multiplication, division, and exponentiation. It should also allow consecutive operations to be performed using method chaining. The Calculator class constructor should accept a number which serves as the initial value of result.

Your Calculator class should have the following methods:

- add - This method adds the given number value to the result and returns the updated Calculator.
- subtract - This method subtracts the given number value from the result and returns the updated Calculator.
- multiply - This method multiplies the result  by the given number value and returns the updated Calculator.
- divide - This method divides the result by the given number value and returns the updated Calculator. If the passed value is 0, an error "Division by zero is not allowed" should be thrown.
- power - This method raises the result to the power of the given number value and returns the updated Calculator.
- getResult - This method returns the result.

Solutions within 10-5 of the actual result are considered correct.

### Example 1

```text
Input:
actions = ["Calculator", "add", "subtract", "getResult"],
values = [10, 5, 7]
Output: 8
Explanation:
new Calculator(10).add(5).subtract(7).getResult() // 10 + 5 - 7 = 8
```

### Example 2

```text
Input:
actions = ["Calculator", "multiply", "power", "getResult"],
values = [2, 5, 2]
Output: 100
Explanation:
new Calculator(2).multiply(5).power(2).getResult() // (2 * 5) ^ 2 = 100
```

### Example 3

```text
Input:
actions = ["Calculator", "divide", "getResult"],
values = [20, 0]
Output: "Division by zero is not allowed"
Explanation:
new Calculator(20).divide(0).getResult() // 20 / 0

The error should be thrown because we cannot divide by zero.
```

## Constraints

- actions is a valid JSON array of strings
- values is a valid JSON array of numbers
- 2 <= actions.length <= 2 * 104
- 1 <= values.length <= 2 * 104 - 1
- actions[i] is one of "Calculator", "add", "subtract", "multiply", "divide", "power", and "getResult"
- First action is always "Calculator"
- Last action is always "getResult"

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2726. Calculator with Method Chaining

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Method Chaining | JavaScript, TypeScript |

## Approach 1: Method Chaining

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class Calculator {
  constructor(value) {
    this.result = value;
  }
  add(value){
    this.result += value;
    return this;
  }
  subtract(value){
    this.result -= value;
    return this;
  }
  multiply(value) {
    this.result *= value;
    return this;
  }
  divide(value) {
    if(value === 0) throw "Division by zero is not allowed";
    this.result /= value;
    return this;
  }
  power(value) {
    this.result **= value;
    return this;
  }
  getResult() {
    return this.result;
  }
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class Calculator {
  private result: number;

  constructor(value: number) {
    this.result = value;
  }

  add(value: number): Calculator {
    this.result += value;
    return this;
  }

  subtract(value: number): Calculator {
    this.result -= value;
    return this;
  }

  multiply(value: number): Calculator {
    this.result *= value;
    return this;
  }

  divide(value: number): Calculator {
    if(value === 0) throw "Division by zero is not allowed";
    this.result /= value;
    return this;
  }

  power(value: number): Calculator {
    this.result **= value;
    return this;
  }

  getResult(): number {
    return this.result;
  }
}
```

</details>
