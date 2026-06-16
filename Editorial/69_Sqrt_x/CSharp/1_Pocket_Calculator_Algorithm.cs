public class Solution {
    public int MySqrt(int x) {
        if (x < 2)
            return x;
        long left = (long)Math.Exp(0.5 * Math.Log(x));
        long right = left + 1;
        return right * right > x ? (int)left : (int)right;
    }
}
