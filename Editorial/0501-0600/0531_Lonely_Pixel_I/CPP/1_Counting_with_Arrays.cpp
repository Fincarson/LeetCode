class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = int(picture.size());
        int m = int(picture[0].size());
        
        // Arrays to store the count of black cells in rows and columns.
        vector<int> rowCount(n, 0);
        vector<int> columnCount(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == 'B') {
                    rowCount[i]++;
                    columnCount[j]++;
                }
            }
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Its a lonely cell, if the current cell is black and,
                // the count of black cells in its row and column is 1.
                if (picture[i][j] == 'B' && rowCount[i] == 1 && columnCount[j] == 1) {
                    answer++;
                }
            }
        }
        
        return answer;
    }
};
