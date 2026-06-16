class Solution:
    def stringShift(self, string: str, shift: List[List[int]]) -> str:

        # Add up the left shifts and right shifts.
        overall_shifts = [0, 0]
        for direction, amount in shift:
            overall_shifts[direction] += amount
        left_shifts, right_shifts = overall_shifts

        # Determine which shift (if any) to perform.
        if left_shifts > right_shifts:
            left_shifts = (left_shifts - right_shifts) % len(string)
            string = string[left_shifts:] + string[:left_shifts]
        else:
            right_shifts = (right_shifts - left_shifts) % len(string)
            string = string[-right_shifts:] + string[:-right_shifts]

        return string
