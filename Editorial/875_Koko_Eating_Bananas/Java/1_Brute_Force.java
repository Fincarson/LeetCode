class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        // Start at an eating speed of 1.
        int speed = 1;

        while (true) {
            // hourSpent stands for the total hour Koko spends with 
            // the given eating speed.
            int hourSpent = 0;

            // Iterate over the piles and calculate hourSpent.
            // We increase the hourSpent by ceil(pile / speed)
            for (int pile : piles) {
                hourSpent += Math.ceil((double) pile / speed);
                if (hourSpent > h) {
                    break;
                }
            }

            // Check if Koko can finish all the piles within h hours,
            // If so, return speed. Otherwise, let speed increment by
            // 1 and repeat the previous iteration.
            if (hourSpent <= h) {
                return speed;
            } else {
                speed += 1;
            }            
        }
    }
}
