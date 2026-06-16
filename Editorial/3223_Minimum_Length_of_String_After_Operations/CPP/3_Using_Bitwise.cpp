class Solution {
public:
    int minimumLength(string s) {
        int present = 0;
        int parity = 0;
        int placevalue;

        // Iterate through the string and update the present and parity bitmasks
        for (int k = 0; k < s.size(); k++) {
            // Calculate the bit position for the character
            placevalue = 1 << (s[k] - 'a');
            // Set the corresponding bit in the present bitmask
            present |= placevalue;
            // Toggle the corresponding bit in the parity bitmask
            parity ^= placevalue;
        }

        int totalLength = 0;

        // Process the present bitmask and check the parity bitmask to calculate
        // the minimum length
        while (present) {
            // Clear the least significant bit in present
            placevalue = present & (present - 1);
            // If the corresponding parity bit is set, it indicates an odd
            // occurrence, so add 1
            totalLength += 2 - ((parity & (present - placevalue)) != 0);
            present = placevalue;
        }

        return totalLength;
    }
};
