class Solution {
    public int minOperations(int n) {
        int res = 0;
        // compute the sum:
        // (n - 1) + (n - 3) + (n - 5) + ... + 1 (or 0) 
        while (n > 0) {
            res += n - 1;
            n -= 2;    
        }
        return res;
    }
}
