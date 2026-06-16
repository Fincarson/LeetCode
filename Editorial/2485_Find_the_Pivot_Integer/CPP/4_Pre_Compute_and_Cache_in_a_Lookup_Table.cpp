const int maxValue = 1000;
// Array to store precomputed pivot values
int precompute[maxValue + 1] = {0}; // Initializing to 0

class Solution {
public:
    int pivotInteger(int n) {
        // Check if precompute array is not initialized
        if (precompute[1] == 0) {
            for (int i = 1, j = 1; i <= maxValue; ++i) {
                int sum = i * (i + 1) / 2;

                // Find the first square greater than or equal to sum
                while (j * j < sum) {
                    ++j;
                }

                // Check if j * j is equal to sum (pivot found), otherwise set to -1
                precompute[i] = j * j == sum ? j : -1;
            }
        }

        return precompute[n];
    }
};
