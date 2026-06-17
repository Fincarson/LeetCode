class Solution {
public:
    string stringShift(string string, vector<vector<int>>& shift) {
        int len = string.length();
        for (auto move : shift) {
            int direction = move[0];
            int amount = move[1] % len;
            if (direction == 0) {
                // Move necessary amount of characters from start to end
                string = string.substr(amount) + string.substr(0, amount);
            } else {
                // Move necessary amount of characters from end to start
                string = string.substr(len - amount) +
                         string.substr(0, len - amount);
            }
        }
        return string;
    }
};
