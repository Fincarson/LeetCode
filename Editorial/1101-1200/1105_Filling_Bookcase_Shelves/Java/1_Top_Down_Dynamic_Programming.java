class Solution {

    public int minHeightShelves(int[][] books, int shelfWidth) {
        // Cache to store previous computations
        int[][] memo = new int[books.length][shelfWidth + 1];
        return dpHelper(books, shelfWidth, memo, 0, shelfWidth, 0);
    }

    private int dpHelper(
        int[][] books,
        int shelfWidth,
        int[][] memo,
        int i,
        int remainingShelfWidth,
        int maxHeight
    ) {
        // Return height of current shelf
        if (i == books.length) return maxHeight;
        // Return answer if already computed
        if (memo[i][remainingShelfWidth] != 0) {
            return memo[i][remainingShelfWidth];
        } else {
            int[] currentBook = books[i];
            // Calculate the height of the bookcase if we put the current book on the new shelf
            int option1Height =
                maxHeight +
                dpHelper(
                    books,
                    shelfWidth,
                    memo,
                    i + 1,
                    shelfWidth - currentBook[0],
                    currentBook[1]
                );
            int option2Height = Integer.MAX_VALUE;
            if (remainingShelfWidth >= currentBook[0]) {
                int maxHeightUpdated = Math.max(maxHeight, currentBook[1]);
                // Calculate height of the bookcase if we put the current book on the current shelf
                option2Height = dpHelper(
                    books,
                    shelfWidth,
                    memo,
                    i + 1,
                    remainingShelfWidth - currentBook[0],
                    maxHeightUpdated
                );
            }
            // Store the smaller result in cache
            memo[i][remainingShelfWidth] = Math.min(
                option1Height,
                option2Height
            );
            return memo[i][remainingShelfWidth];
        }
    }
}
