class Solution {
public:
    int numTilings(int n) {
        int MOD = 1'000'000'007; 
        if (n <= 2) {
            return n;
        }
        long fPrevious = 1L; 
        long fCurrent = 2L; 
        long pCurrent = 1L;
        for (int k = 3; k < n + 1; ++k) {
            long tmp = fCurrent;
            fCurrent = (fCurrent + fPrevious + 2 * pCurrent) % MOD;
            pCurrent = (pCurrent + fPrevious) % MOD;
            fPrevious = tmp;
        }
        return static_cast<int>(fCurrent);
    }
};
