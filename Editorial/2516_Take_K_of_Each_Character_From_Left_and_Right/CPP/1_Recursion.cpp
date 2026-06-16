class Solution {
    int minMinutes = INT_MAX;

public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        vector<int> count(3, 0);
        solve(s, k, 0, s.length() - 1, count, 0);
        return minMinutes == INT_MAX ? -1 : minMinutes;
    }

private:
    void solve(string& s, int k, int left, int right, vector<int> count,
               int minutes) {
        // Base case: check if we have k of each character
        if (count[0] >= k && count[1] >= k && count[2] >= k) {
            minMinutes = min(minMinutes, minutes);
            return;
        }
        // If we can't take more characters
        if (left > right) return;

        // Take from left
        vector<int> leftCount = count;
        leftCount[s[left] - 'a']++;
        solve(s, k, left + 1, right, leftCount, minutes + 1);

        // Take from right
        vector<int> rightCount = count;
        rightCount[s[right] - 'a']++;
        solve(s, k, left, right - 1, rightCount, minutes + 1);
    }
};
