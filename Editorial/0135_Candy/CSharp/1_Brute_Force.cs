public class Solution {
    public int Candy(int[] ratings) {
        int[] candies = new int[ratings.Length];
        for (int i = 0; i < candies.Length; i++) candies[i] = 1;
        bool hasChanged = true;
        while (hasChanged) {
            hasChanged = false;
            for (int i = 0; i < ratings.Length; i++) {
                if (i != ratings.Length - 1 && ratings[i] > ratings[i + 1] &&
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
        for (int i = 0; i < candies.Length; i++) {
            sum += candies[i];
        }

        return sum;
    }
}
