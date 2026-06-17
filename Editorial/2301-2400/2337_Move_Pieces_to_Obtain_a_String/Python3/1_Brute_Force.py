class Solution:
    def canChange(self, start: str, target: str) -> bool:
        # To keep track of visited states to avoid cycles
        visited_states = set()

        # Queue for current state
        state_queue = []
        # Start with the initial state
        state_queue.append(start)

        while state_queue:
            current_state = state_queue.pop(0)

            # If we reach the target state, return true
            if current_state == target:
                return True

            for position in range(1, len(current_state)):
                # Try moving 'L' to the left
                if (
                    current_state[position] == "L"
                    and current_state[position - 1] == "_"
                ):
                    current_state = list(current_state)
                    current_state[position], current_state[position - 1] = (
                        current_state[position - 1],
                        current_state[position],
                    )
                    current_state = "".join(current_state)
                    if current_state not in visited_states:
                        # Add the new state to the queue
                        state_queue.append(current_state)
                        # Mark the new state as visited
                        visited_states.add(current_state)
                    # Restore the state
                    current_state = list(current_state)
                    current_state[position], current_state[position - 1] = (
                        current_state[position - 1],
                        current_state[position],
                    )
                    current_state = "".join(current_state)

                # Try moving 'R' to the right
                if (
                    position < len(current_state) - 1
                    and current_state[position] == "R"
                    and current_state[position + 1] == "_"
                ):
                    current_state = list(current_state)
                    current_state[position], current_state[position + 1] = (
                        current_state[position + 1],
                        current_state[position],
                    )
                    current_state = "".join(current_state)
                    if current_state not in visited_states:
                        # Add the new state to the queue
                        state_queue.append(current_state)
                        # Mark the new state as visited
                        visited_states.add(current_state)
                    # Restore the state
                    current_state = list(current_state)
                    current_state[position], current_state[position + 1] = (
                        current_state[position + 1],
                        current_state[position],
                    )
                    current_state = "".join(current_state)

        # If no valid transformation sequence is found, return false
        return False
