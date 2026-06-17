# 241. Different Ways to Add Parentheses

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/different-ways-to-add-parentheses/)  
`Math` `String` `Dynamic Programming` `Recursion` `Memoization`

**Problem Link:** [LeetCode 241 - Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/)

## Problem

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

### Example 1

```text
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2
```

### Example 2

```text
Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
```

## Constraints

- 1 <= expression.length <= 20
- expression consists of digits and the operator '+', '-', and '*'.
- All the integer values in the input expression are in the range [0, 99].
- The integer values in the input expression do not have a leading '-' or '+' denoting the sign.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Basic Calculator](https://leetcode.com/problems/basic-calculator/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [The Score of Students Solving Math Expression](https://leetcode.com/problems/the-score-of-students-solving-math-expression/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimize Result by Adding Parentheses to Expression](https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 241. Different Ways to Add Parentheses

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C++, Java, Python3 |
| Memoization | C++, Java, Python3 |
| Tabulation | C++, Java, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;

        // Base case: if the string is empty, return an empty list
        if (expression.length() == 0) return results;

        // Base case: if the string is a single character, treat it as a number
        // and return it
        if (expression.length() == 1) {
            results.push_back(stoi(expression));
            return results;
        }

        // If the string has only two characters and the first character is a
        // digit, parse it as a number
        if (expression.length() == 2 && isdigit(expression[0])) {
            results.push_back(stoi(expression));
            return results;
        }

        // Recursive case: iterate through each character
        for (int i = 0; i < expression.length(); i++) {
            char currentChar = expression[i];

            // Skip if the current character is a digit
            if (isdigit(currentChar)) continue;

            // Split the expression into left and right parts
            vector<int> leftResults =
                diffWaysToCompute(expression.substr(0, i));
            vector<int> rightResults =
                diffWaysToCompute(expression.substr(i + 1));

            // Combine results from left and right parts
            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    int computedResult = 0;

                    // Perform the operation based on the current character
                    switch (currentChar) {
                        case '+':
                            computedResult = leftValue + rightValue;
                            break;
                        case '-':
                            computedResult = leftValue - rightValue;
                            break;
                        case '*':
                            computedResult = leftValue * rightValue;
                            break;
                    }

                    results.push_back(computedResult);
                }
            }
        }

        return results;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> results = new ArrayList<>();

        // Base case: if the string is empty, return an empty list
        if (expression.length() == 0) return results;

        // Base case: if the string is a single character, treat it as a number and return it
        if (expression.length() == 1) {
            results.add(Integer.parseInt(expression));
            return results;
        }

        // If the string has only two characters and the first character is a digit, parse it as a number
        if (
            expression.length() == 2 && Character.isDigit(expression.charAt(0))
        ) {
            results.add(Integer.parseInt(expression));
            return results;
        }

        // Recursive case: iterate through each character
        for (int i = 0; i < expression.length(); i++) {
            char currentChar = expression.charAt(i);

            // Skip if the current character is a digit
            if (Character.isDigit(currentChar)) continue;

            // Split the expression into left and right parts
            List<Integer> leftResults = diffWaysToCompute(
                expression.substring(0, i)
            );
            List<Integer> rightResults = diffWaysToCompute(
                expression.substring(i + 1)
            );

            // Combine results from left and right parts
            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    int computedResult = 0;

                    // Perform the operation based on the current character
                    switch (currentChar) {
                        case '+':
                            computedResult = leftValue + rightValue;
                            break;
                        case '-':
                            computedResult = leftValue - rightValue;
                            break;
                        case '*':
                            computedResult = leftValue * rightValue;
                            break;
                    }

                    results.add(computedResult);
                }
            }
        }

        return results;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        results = []

        # Base case: if the string is empty, return an empty list
        if len(expression) == 0:
            return results

        # Base case: if the string is a single character, treat it as a number and return it
        if len(expression) == 1:
            return [int(expression)]

        # If the string has only two characters and the first character is a digit, parse it as a number
        if len(expression) == 2 and expression[0].isdigit():
            return [int(expression)]

        # Recursive case: iterate through each character
        for i, current_char in enumerate(expression):

            # Skip if the current character is a digit
            if current_char.isdigit():
                continue

            # Split the expression into left and right parts
            left_results = self.diffWaysToCompute(expression[:i])
            right_results = self.diffWaysToCompute(expression[i + 1 :])

            # Combine results from left and right parts
            for left_value in left_results:
                for right_value in right_results:
                    # Perform the operation based on the current character
                    if current_char == "+":
                        results.append(left_value + right_value)
                    elif current_char == "-":
                        results.append(left_value - right_value)
                    elif current_char == "*":
                        results.append(left_value * right_value)

        return results
```

</details>

<br>

## Approach 2: Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // Initialize memoization vector to store results of subproblems
        vector<vector<vector<int>>> memo(
            expression.length(), vector<vector<int>>(expression.length()));
        // Solve for the entire expression
        return computeResults(expression, memo, 0, expression.length() - 1);
    }

private:
    vector<int> computeResults(string& expression,
                               vector<vector<vector<int>>>& memo, int start,
                               int end) {
        // If result is already memoized, return it
        if (!memo[start][end].empty()) {
            return memo[start][end];
        }

        vector<int> results;

        // Base case: single digit
        if (start == end) {
            results.push_back(expression[start] - '0');
            return results;
        }

        // Base case: two-digit number
        if (end - start == 1 && isdigit(expression[start])) {
            int tens = expression[start] - '0';
            int ones = expression[end] - '0';
            results.push_back(10 * tens + ones);
            return results;
        }

        // Recursive case: split the expression at each operator
        for (int i = start; i <= end; i++) {
            char currentChar = expression[i];
            if (isdigit(currentChar)) {
                continue;
            }

            vector<int> leftResults =
                computeResults(expression, memo, start, i - 1);
            vector<int> rightResults =
                computeResults(expression, memo, i + 1, end);

            // Combine results from left and right subexpressions
            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    switch (currentChar) {
                        case '+':
                            results.push_back(leftValue + rightValue);
                            break;
                        case '-':
                            results.push_back(leftValue - rightValue);
                            break;
                        case '*':
                            results.push_back(leftValue * rightValue);
                            break;
                    }
                }
            }
        }

        // Memoize the result for this subproblem
        memo[start][end] = results;

        return results;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> diffWaysToCompute(String expression) {
        // Initialize memoization array to store results of subproblems
        List<Integer>[][] memo =
            new ArrayList[expression.length()][expression.length()];
        // Solve for the entire expression
        return computeResults(expression, memo, 0, expression.length() - 1);
    }

    private List<Integer> computeResults(
        String expression,
        List<Integer>[][] memo,
        int start,
        int end
    ) {
        // If result is already memoized, return it
        if (memo[start][end] != null) {
            return memo[start][end];
        }

        List<Integer> results = new ArrayList<>();

        // Base case: single digit
        if (start == end) {
            results.add(expression.charAt(start) - '0');
            return results;
        }

        // Base case: two-digit number
        if (end - start == 1 && Character.isDigit(expression.charAt(start))) {
            int tens = expression.charAt(start) - '0';
            int ones = expression.charAt(end) - '0';
            results.add(10 * tens + ones);
            return results;
        }

        // Recursive case: split the expression at each operator
        for (int i = start; i <= end; i++) {
            char currentChar = expression.charAt(i);
            if (Character.isDigit(currentChar)) {
                continue;
            }

            List<Integer> leftResults = computeResults(
                expression,
                memo,
                start,
                i - 1
            );
            List<Integer> rightResults = computeResults(
                expression,
                memo,
                i + 1,
                end
            );

            // Combine results from left and right subexpressions
            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    switch (currentChar) {
                        case '+':
                            results.add(leftValue + rightValue);
                            break;
                        case '-':
                            results.add(leftValue - rightValue);
                            break;
                        case '*':
                            results.add(leftValue * rightValue);
                            break;
                    }
                }
            }
        }

        // Memoize the result for this subproblem
        memo[start][end] = results;

        return results;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        # Initialize memoization dictionary to store results of subproblems
        memo = {}
        # Solve for the entire expression
        return self._compute_results(expression, memo, 0, len(expression) - 1)

    def _compute_results(
        self, expression: str, memo: dict, start: int, end: int
    ) -> List[int]:
        # If result is already memoized, return it
        if (start, end) in memo:
            return memo[(start, end)]

        results = []

        # Base case: single digit
        if start == end:
            results.append(int(expression[start]))
            return results

        # Base case: two-digit number
        if end - start == 1 and expression[start].isdigit():
            results.append(int(expression[start : end + 1]))
            return results

        # Recursive case: split the expression at each operator
        for i in range(start, end + 1):
            if expression[i].isdigit():
                continue

            left_results = self._compute_results(expression, memo, start, i - 1)
            right_results = self._compute_results(expression, memo, i + 1, end)

            # Combine results from left and right subexpressions
            for left_value in left_results:
                for right_value in right_results:
                    if expression[i] == "+":
                        results.append(left_value + right_value)
                    elif expression[i] == "-":
                        results.append(left_value - right_value)
                    elif expression[i] == "*":
                        results.append(left_value * right_value)

        # Memoize the result for this subproblem
        memo[(start, end)] = results

        return results
```

</details>

<br>

## Approach 3: Tabulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length();
        // Create a 2D array of lists to store results of subproblems
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

        initializeBaseCases(expression, dp);

        // Fill the dp table for all possible subexpressions
        for (int length = 3; length <= n; length++) {
            for (int start = 0; start + length - 1 < n; start++) {
                int end = start + length - 1;
                processSubexpression(expression, dp, start, end);
            }
        }

        // Return the results for the entire expression
        return dp[0][n - 1];
    }

private:
    void initializeBaseCases(string& expression,
                             vector<vector<vector<int>>>& dp) {
        int n = expression.length();
        // Handle base cases: single digits and two-digit numbers
        for (int i = 0; i < n; i++) {
            if (isdigit(expression[i])) {
                // Check if it's a two-digit number
                int dig1 = expression[i] - '0';
                if (i + 1 < n && isdigit(expression[i + 1])) {
                    int dig2 = expression[i + 1] - '0';
                    int number = dig1 * 10 + dig2;
                    dp[i][i + 1].push_back(number);
                }
                // Single digit case
                dp[i][i].push_back(dig1);
            }
        }
    }

    void processSubexpression(string& expression,
                              vector<vector<vector<int>>>& dp, int start,
                              int end) {
        // Try all possible positions to split the expression
        for (int split = start; split <= end; split++) {
            if (isdigit(expression[split])) continue;

            vector<int> leftResults = dp[start][split - 1];
            vector<int> rightResults = dp[split + 1][end];

            computeResults(expression[split], leftResults, rightResults,
                           dp[start][end]);
        }
    }

    void computeResults(char op, vector<int>& leftResults,
                        vector<int>& rightResults, vector<int>& results) {
        // Compute results based on the operator at position 'split'
        for (int leftValue : leftResults) {
            for (int rightValue : rightResults) {
                switch (op) {
                    case '+':
                        results.push_back(leftValue + rightValue);
                        break;
                    case '-':
                        results.push_back(leftValue - rightValue);
                        break;
                    case '*':
                        results.push_back(leftValue * rightValue);
                        break;
                }
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> diffWaysToCompute(String expression) {
        int n = expression.length();
        // Create a 2D array of lists to store results of subproblems
        List<Integer>[][] dp = new ArrayList[n][n];

        initializeBaseCases(expression, dp);

        // Fill the dp table for all possible subexpressions
        for (int length = 3; length <= n; length++) {
            for (int start = 0; start + length - 1 < n; start++) {
                int end = start + length - 1;
                processSubexpression(expression, dp, start, end);
            }
        }

        // Return the results for the entire expression
        return dp[0][n - 1];
    }

    private void initializeBaseCases(String expression, List<Integer>[][] dp) {
        int n = expression.length();
        // Initialize the dp array with empty lists
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = new ArrayList<>();
            }
        }

        // Handle base cases: single digits and two-digit numbers
        for (int i = 0; i < n; i++) {
            if (Character.isDigit(expression.charAt(i))) {
                // Check if it's a two-digit number
                int dig1 = expression.charAt(i) - '0';
                if (i + 1 < n && Character.isDigit(expression.charAt(i + 1))) {
                    int dig2 = expression.charAt(i + 1) - '0';
                    int number = dig1 * 10 + dig2;
                    dp[i][i + 1].add(number);
                }
                // Single digit case
                dp[i][i].add(dig1);
            }
        }
    }

    private void processSubexpression(
        String expression,
        List<Integer>[][] dp,
        int start,
        int end
    ) {
        // Try all possible positions to split the expression
        for (int split = start; split <= end; split++) {
            if (Character.isDigit(expression.charAt(split))) continue;

            List<Integer> leftResults = dp[start][split - 1];
            List<Integer> rightResults = dp[split + 1][end];

            computeResults(
                expression.charAt(split),
                leftResults,
                rightResults,
                dp[start][end]
            );
        }
    }

    private void computeResults(
        char op,
        List<Integer> leftResults,
        List<Integer> rightResults,
        List<Integer> results
    ) {
        // Compute results based on the operator at position 'split'
        for (int leftValue : leftResults) {
            for (int rightValue : rightResults) {
                switch (op) {
                    case '+':
                        results.add(leftValue + rightValue);
                        break;
                    case '-':
                        results.add(leftValue - rightValue);
                        break;
                    case '*':
                        results.add(leftValue * rightValue);
                        break;
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        n = len(expression)
        # Create a 2D array of lists to store results of subproblems
        dp = [[[] for _ in range(n)] for _ in range(n)]

        self._initialize_base_cases(expression, dp)

        # Fill the dp table for all possible subexpressions
        for length in range(3, n + 1):
            for start in range(n - length + 1):
                end = start + length - 1
                self._process_subexpression(expression, dp, start, end)

        # Return the results for the entire expression
        return dp[0][n - 1]

    def _initialize_base_cases(
        self, expression: str, dp: List[List[List[int]]]
    ):
        # Handle base cases: single digits and two-digit numbers
        for i, char in enumerate(expression):
            if char.isdigit():
                # Check if it's a two-digit number
                dig1 = ord(char) - ord("0")
                if i + 1 < len(expression) and expression[i + 1].isdigit():
                    dig2 = ord(expression[i + 1]) - ord("0")
                    number = dig1 * 10 + dig2
                    dp[i][i + 1].append(number)
                # Single digit case
                dp[i][i].append(dig1)

    def _process_subexpression(
        self, expression: str, dp: List[List[List[int]]], start: int, end: int
    ):
        # Try all possible positions to split the expression
        for split in range(start, end + 1):
            if expression[split].isdigit():
                continue

            left_results = dp[start][split - 1]
            right_results = dp[split + 1][end]

            self._compute_results(
                expression[split], left_results, right_results, dp[start][end]
            )

    def _compute_results(
        self,
        op: str,
        left_results: List[int],
        right_results: List[int],
        results: List[int],
    ):
        # Compute results based on the operator at position 'split'
        for left_value in left_results:
            for right_value in right_results:
                if op == "+":
                    results.append(left_value + right_value)
                elif op == "-":
                    results.append(left_value - right_value)
                elif op == "*":
                    results.append(left_value * right_value)
```

</details>
