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
