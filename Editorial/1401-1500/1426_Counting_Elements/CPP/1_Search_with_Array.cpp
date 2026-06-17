class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0;
        for (auto x : arr) {
            if (integerInArray(arr, x + 1)) {
                count++;
            }
        }
        return count;
    }

    bool integerInArray(vector<int>& arr, int target) {
        for (auto x : arr) {
            if (x == target) {
                return true;
            }
        }
        return false;
    }
};
