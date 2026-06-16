class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> hashSet(arr.begin(), arr.end());
        int count = 0;
        for (int x : arr) {
            if (hashSet.find(x + 1) != hashSet.end()) {
                count++;
            }
        }
        return count;
    }
};
