class Solution {
public:
    int findRotateSteps(string ring, string key) {
        return tryLock(0, 0, ring, key, INT_MAX);
    }

private:
    // Find the minimum steps between two indexes of ring
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }

    // Find the minimum number of steps to spell the keyword
    int tryLock(int ringIndex, int keyIndex, string ring, string key, int minSteps) {
        // If we reach the end of the key, it has been spelled
        if (keyIndex == key.length()) {
            return 0;
        }
        // For each occurrence of the character at index key_index of key in ring
        // Calculate the minimum steps to that character from the ringIndex of ring
        for (int i = 0; i < ring.length(); i++) {
            if (ring[i] == key[keyIndex]) {
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 +
                                            tryLock(i, keyIndex + 1, ring, key, INT_MAX);
                minSteps = min(minSteps, totalSteps);
            }
        }
        return minSteps;
    }
};
