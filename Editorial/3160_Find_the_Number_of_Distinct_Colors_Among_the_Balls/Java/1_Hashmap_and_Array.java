class Solution {

    public int[] queryResults(int limit, int[][] queries) {
        int n = queries.length;
        int[] result = new int[n];
        Map<Integer, Integer> colorMap = new HashMap<>();
        int[] ballArray = new int[limit + 1];

        // Iterate through queries
        for (int i = 0; i < n; i++) {
            // Extract ball label and color from query
            int ball = queries[i][0];
            int color = queries[i][1];

            // Check if ball is already colored
            if (ballArray[ball] != 0) {
                // Decrement count of the previous color on the ball
                int prevColor = ballArray[ball];
                colorMap.put(prevColor, colorMap.get(prevColor) - 1);

                // If there are no balls with previous color left, remove color from color map
                if (colorMap.get(prevColor) == 0) {
                    colorMap.remove(prevColor);
                }
            }
            // Set color of ball to the new color
            ballArray[ball] = color;

            // Increment the count of the new color
            colorMap.put(color, colorMap.getOrDefault(color, 0) + 1);

            result[i] = colorMap.size();
        }
        return result;
    }
}
