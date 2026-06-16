class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        st = deque()

        # Traverse the entire expression
        for curr_char in expression:
            if curr_char == ")":
                values = []

                # Gather all values inside the parentheses
                while st[-1] != "(":
                    values.append(st.pop())
                st.pop()  # Remove '('
                op = st.pop()  # Remove the operator

                # Evaluate the subexpression and push the result back
                result = self._evaluate_sub_expr(op, values)
                st.append(result)
            elif curr_char != ",":
                st.append(curr_char)  # Push non-comma characters into the stack

        # Final result is on the top of the stack
        return st[-1] == "t"

    # Evaluates a subexpression based on the operator and list of values
    def _evaluate_sub_expr(self, op, values):
        if op == "!":
            return "f" if values[0] == "t" else "t"

        # AND: return 'f' if any value is 'f', otherwise return 't'
        if op == "&":
            for value in values:
                if value == "f":
                    return "f"
            return "t"

        # OR: return 't' if any value is 't', otherwise return 'f'
        if op == "|":
            for value in values:
                if value == "t":
                    return "t"
            return "f"

        return "f"  # This point should never be reached
