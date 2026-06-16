class Solution {

    public String stringShift(String string, int[][] shift) {
        // Add up the left shifts and right shifts.
        int[] overallShifts = new int[2];
        for (int[] move : shift) {
            overallShifts[move[0]] += move[1];
        }
        int leftShifts = overallShifts[0];
        int rightShifts = overallShifts[1];

        // Determine which shift (if any) to perform.
        int len = string.length();
        if (leftShifts > rightShifts) {
            leftShifts = (leftShifts - rightShifts) % len;
            string =
                string.substring(leftShifts) + string.substring(0, leftShifts);
        } else if (rightShifts > leftShifts) {
            rightShifts = (rightShifts - leftShifts) % len;
            string =
                string.substring(len - rightShifts) +
                string.substring(0, len - rightShifts);
        }

        return string;
    }
}
