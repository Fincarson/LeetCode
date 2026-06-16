class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringLen = ring.length();
        int keyLen = key.length();
        vector<vector<int>> bestSteps(ringLen, vector<int>(keyLen + 1, INT_MAX));
        // Initialize values of best_steps to largest integer
        for (auto& row : bestSteps) {
            fill(row.begin(), row.end(), INT_MAX);
        }
        // Initialize last column to zero to represent the word has been spelled
        for (int i = 0; i < ringLen; i++) {
            bestSteps[i][keyLen] = 0;
        }
        // For each occurrence of the character at key_index of key in ring
        // Stores minimum steps to the character from ringIndex of ring
        for (int keyIndex = keyLen - 1; keyIndex >= 0; keyIndex--) {
            for (int ringIndex = 0; ringIndex < ringLen; ringIndex++) {
                for (int charIndex = 0; charIndex < ringLen; charIndex++) {
                    if (ring[charIndex] == key[keyIndex]) {
                        bestSteps[ringIndex][keyIndex] = min(bestSteps[ringIndex][keyIndex],
                                1 + countSteps(ringIndex, charIndex, ringLen) 
                                + bestSteps[charIndex][keyIndex + 1]);
                    }
                }
            }
        }

        return bestSteps[0][0];
    }

private:
    // Find the minimum steps between two indexes of ring
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }
};
