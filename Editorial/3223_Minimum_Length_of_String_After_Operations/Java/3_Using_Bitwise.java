class Solution {

    public int minimumLength(String s) {
        int present = 0;
        int parity = 0;
        int placeValue;

        // Iterate through the string and update the present and parity bitmasks
        for (int k = 0; k < s.length(); k++) {
            // Calculate the bit position for the character
            placeValue = 1 << (s.charAt(k) - 'a');
            // Set the corresponding bit in the present bitmask
            present |= placeValue;
            // Toggle the corresponding bit in the parity bitmask
            parity ^= placeValue;
        }

        int totalLength = 0;

        // Process the present bitmask and check the parity bitmask to calculate
        // the minimum length
        while (present > 0) {
            // Clear the least significant bit in present
            placeValue = present & (present - 1);
            // If the corresponding parity bit is set, it indicates an odd
            // occurrence, so add 1
            totalLength += 2 - ((parity & (present - placeValue)) != 0 ? 1 : 0);
            present = placeValue;
        }

        return totalLength;
    }
}
