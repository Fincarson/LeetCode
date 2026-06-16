class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        bool hasChanged = true;
        while (hasChanged) {
            hasChanged = false;
            for (int i = 0; i < ratings.size(); i++) {
                if (i != ratings.size() - 1 && ratings[i] > ratings[i + 1] &&
                    candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    hasChanged = true;
                }
                if (i > 0 && ratings[i] > ratings[i - 1] &&
                    candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    hasChanged = true;
                }
            }
        }
        int sum = 0;
        for (int candy : candies) {
            sum += candy;
        }
        return sum;
    }
};
