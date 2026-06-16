class Solution {
    private static final int MAX = Integer.MAX_VALUE;

    public int findRotateSteps(String ring, String key) {
        return tryLock(0, 0, ring, key, MAX);
    }

    // Find the minimum steps between two indexes of ring
    private int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = Math.abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return Math.min(stepsBetween, stepsAround);
    }

    // Find the minimum number of steps to spell the keyword
    public int tryLock(int ringIndex, int keyIndex, String ring, String key, int minSteps) {
        // If we reach the end of the key, it has been spelled
        if (keyIndex == key.length()) {
            return 0;
        }
        // For each occurrence of the character at key_index of key in ring
        // Calculate the minimum steps to that character from the ringIndex of ring
        for (int i = 0; i < ring.length(); i++) {
            if (ring.charAt(i) == key.charAt(keyIndex)) {
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 + 
                                            tryLock(i, keyIndex + 1, ring, key, MAX);
                minSteps = Math.min(minSteps, totalSteps);
            }
        }
        return minSteps;
    }
}
