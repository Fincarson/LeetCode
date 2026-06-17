class Solution {
public:
    string stringShift(string string, vector<vector<int>>& shift) {
        // Add up the left shifts and right shifts.
        vector<int> overallShifts(2, 0);
        for (auto& move : shift) {
            overallShifts[move[0]] += move[1];
        }
        int leftShifts = overallShifts[0];
        int rightShifts = overallShifts[1];

        // Determine which shift (if any) to perform.
        int len = string.length();
        if (leftShifts > rightShifts) {
            leftShifts = (leftShifts - rightShifts) % len;
            string = string.substr(leftShifts) + string.substr(0, leftShifts);
        } else if (rightShifts > leftShifts) {
            rightShifts = (rightShifts - leftShifts) % len;
            string = string.substr(len - rightShifts) +
                     string.substr(0, len - rightShifts);
        }

        return string;
    }
};
