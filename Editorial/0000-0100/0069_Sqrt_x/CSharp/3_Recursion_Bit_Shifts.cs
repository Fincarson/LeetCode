public class Solution {
    public int MySqrt(int x) {
        if (x < 2)
            return x;
        int left = MySqrt(x >> 2) << 1;
        int right = left + 1;
        return (long)right * right > x ? left : right;
    }
}
