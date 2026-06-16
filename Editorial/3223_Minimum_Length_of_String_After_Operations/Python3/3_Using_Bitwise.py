class Solution:
    def minimumLength(self, s: str) -> int:
        present = 0
        parity = 0
        place_value = 0

        # Iterate through the string and update the present and parity bitmasks
        for char in s:
            # Calculate the bit position for the character
            place_value = 1 << (ord(char) - ord("a"))

            # Set the corresponding bit in the present bitmask
            present |= place_value

            # Toggle the corresponding bit in the parity bitmask
            parity ^= place_value

        total_length = 0

        # Process the present bitmask and check the parity bitmask to calculate
        # the minimum length
        while present > 0:
            # Clear the least significant bit in present
            place_value = present & (present - 1)
            # If the corresponding parity bit is set, it indicates an odd
            # occurrence, so add 1
            total_length += 2 - ((parity & (present - place_value)) != 0)
            present = place_value

        return total_length
