public class Solution {
    // Function to calculate sum of first n natural numbers
    public int count(int n) {
        return (n * (n + 1)) / 2;
    }

    public int Candy(int[] ratings) {
        if (ratings.Length <= 1) {
            return ratings.Length;
        }

        int candies = 0;
        int up = 0;
        int down = 0;
        int oldSlope = 0;
        for (int i = 1; i < ratings.Length; i++) {
            int newSlope = (ratings[i] > ratings[i - 1])
                               ? 1
                               : (ratings[i] < ratings[i - 1] ? -1 : 0);
            if ((oldSlope > 0 && newSlope == 0) ||
                (oldSlope < 0 && newSlope >= 0)) {
                candies += count(up) + count(down) + Math.Max(up, down);
                up = 0;
                down = 0;
            }

            if (newSlope > 0)
                up++;
            if (newSlope < 0)
                down++;
            if (newSlope == 0)
                candies++;
            oldSlope = newSlope;
        }

        candies += count(up) + count(down) + Math.Max(up, down) + 1;
        return candies;
    }
}
