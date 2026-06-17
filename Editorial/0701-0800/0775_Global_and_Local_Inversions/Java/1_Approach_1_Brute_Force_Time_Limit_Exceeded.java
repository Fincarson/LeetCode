class Solution {
    public boolean isIdealPermutation(int[] A) {
        int N = A.length;
        for (int i = 0; i < N; ++i)
            for (int j = i+2; j < N; ++j)
                if (A[i] > A[j]) return false;
        return true;
    }
}
