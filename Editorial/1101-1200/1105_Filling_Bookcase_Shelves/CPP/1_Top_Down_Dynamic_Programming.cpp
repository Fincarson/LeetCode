class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> memo(books.size(), vector<int>(shelfWidth + 1, 0));
        return dpHelper(books, shelfWidth, memo, 0, shelfWidth, 0);
    }

private:
    int dpHelper(vector<vector<int>>& books, int shelfWidth,
                 vector<vector<int>>& memo, int i, int remainingShelfWidth,
                 int maxHeight) {
        // Return height of current shelf
        if (i == books.size()) return maxHeight;
        // Return answer if already computed
        if (memo[i][remainingShelfWidth] != 0) {
            return memo[i][remainingShelfWidth];
        } else {
            vector<int> currentBook = books[i];
            // Calculate the height of the bookcase if we put the
            // current book on the new shelf
            int option1Height =
                maxHeight + dpHelper(books, shelfWidth, memo, i + 1,
                                     shelfWidth - currentBook[0],
                                     currentBook[1]);
            int option2Height = INT_MAX;
            if (remainingShelfWidth >= currentBook[0]) {
                int maxHeightUpdated = max(maxHeight, currentBook[1]);
                option2Height = dpHelper(books, shelfWidth, memo, i + 1,
                                         remainingShelfWidth - currentBook[0],
                                         maxHeightUpdated);
            }
            // Store the smaller result in cache
            memo[i][remainingShelfWidth] = min(option1Height, option2Height);
            return memo[i][remainingShelfWidth];
        }
    }
};
