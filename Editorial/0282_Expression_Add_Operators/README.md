# 282. Expression Add Operators

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/expression-add-operators/)  
`Math` `String` `Backtracking`

**Problem Link:** [LeetCode 282 - Expression Add Operators](https://leetcode.com/problems/expression-add-operators/)

## Problem

Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.

Note that a number can contain multiple digits.

### Example 1

```text
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
```

### Example 2

```text
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
```

### Example 3

```text
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
```

## Constraints

- 1 <= num.length <= 10
- num consists of only digits.
- -231 <= target <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Basic Calculator](https://leetcode.com/problems/basic-calculator/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Target Sum](https://leetcode.com/problems/target-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 282. Expression Add Operators

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | Java, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

  public ArrayList<String> answer;
  public String digits;
  public long target;

  public void recurse(
      int index, long previousOperand, long currentOperand, long value, ArrayList<String> ops) {
    String nums = this.digits;

    // Done processing all the digits in num
    if (index == nums.length()) {

      // If the final value == target expected AND
      // no operand is left unprocessed
      if (value == this.target && currentOperand == 0) {
        StringBuilder sb = new StringBuilder();
        ops.subList(1, ops.size()).forEach(v -> sb.append(v));
        this.answer.add(sb.toString());
      }
      return;
    }

    // Extending the current operand by one digit
    currentOperand = currentOperand * 10 + Character.getNumericValue(nums.charAt(index));
    String current_val_rep = Long.toString(currentOperand);
    int length = nums.length();

    // To avoid cases where we have 1 + 05 or 1 * 05 since 05 won't be a
    // valid operand. Hence this check
    if (currentOperand > 0) {

      // NO OP recursion
      recurse(index + 1, previousOperand, currentOperand, value, ops);
    }

    // ADDITION
    ops.add("+");
    ops.add(current_val_rep);
    recurse(index + 1, currentOperand, 0, value + currentOperand, ops);
    ops.remove(ops.size() - 1);
    ops.remove(ops.size() - 1);

    if (ops.size() > 0) {

      // SUBTRACTION
      ops.add("-");
      ops.add(current_val_rep);
      recurse(index + 1, -currentOperand, 0, value - currentOperand, ops);
      ops.remove(ops.size() - 1);
      ops.remove(ops.size() - 1);

      // MULTIPLICATION
      ops.add("*");
      ops.add(current_val_rep);
      recurse(
          index + 1,
          currentOperand * previousOperand,
          0,
          value - previousOperand + (currentOperand * previousOperand),
          ops);
      ops.remove(ops.size() - 1);
      ops.remove(ops.size() - 1);
    }
  }

  public List<String> addOperators(String num, int target) {

    if (num.length() == 0) {
      return new ArrayList<String>();
    }

    this.target = target;
    this.digits = num;
    this.answer = new ArrayList<String>();
    this.recurse(0, 0, 0, 0, new ArrayList<String>());
    return this.answer;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addOperators(self, num: 'str', target: 'int') -> 'List[str]':

        N = len(num)
        answers = []
        def recurse(index, prev_operand, current_operand, value, string):

            # Done processing all the digits in num
            if index == N:

                # If the final value == target expected AND
                # no operand is left unprocessed
                if value == target and current_operand == 0:
                    answers.append("".join(string[1:]))
                return

            # Extending the current operand by one digit
            current_operand = current_operand*10 + int(num[index])
            str_op = str(current_operand)

            # To avoid cases where we have 1 + 05 or 1 * 05 since 05 won't be a
            # valid operand. Hence this check
            if current_operand > 0:

                # NO OP recursion
                recurse(index + 1, prev_operand, current_operand, value, string)

            # ADDITION
            string.append('+'); string.append(str_op)
            recurse(index + 1, current_operand, 0, value + current_operand, string)
            string.pop();string.pop()

            # Can subtract or multiply only if there are some previous operands
            if string:

                # SUBTRACTION
                string.append('-'); string.append(str_op)
                recurse(index + 1, -current_operand, 0, value - current_operand, string)
                string.pop();string.pop()

                # MULTIPLICATION
                string.append('*'); string.append(str_op)
                recurse(index + 1, current_operand * prev_operand, 0, value - prev_operand + (current_operand * prev_operand), string)
                string.pop();string.pop()
        recurse(0, 0, 0, 0, [])    
        return answers
```

</details>
