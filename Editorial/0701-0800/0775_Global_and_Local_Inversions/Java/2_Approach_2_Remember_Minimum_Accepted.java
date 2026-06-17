class Solution {
    public boolean isIdealPermutation(int[] A) {
        int N = A.length;
        int floor = N;
        for (int i=N-1; i>=2; --i) {
            floor = Math.min(floor, A[i]);
            if (A[i-2] > floor) return false;
        }
        return true;
    }
}
