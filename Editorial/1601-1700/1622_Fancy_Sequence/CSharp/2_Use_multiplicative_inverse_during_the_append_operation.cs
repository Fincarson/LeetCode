public class Fancy {
    private const int MOD = 1000000007;
    private List<int> v;
    private int a;
    private int b;

    public Fancy() {
        v = new List<int>();
        a = 1;
        b = 0;
    }

    // fast exponentiation
    private int QuickMul(int x, int y) {
        long ret = 1;
        long cur = x;
        while (y != 0) {
            if ((y & 1) != 0) {
                ret = ret * cur % MOD;
            }
            cur = cur * cur % MOD;
            y >>= 1;
        }
        return (int)ret;
    }

    // multiplicative inverse
    private int Inv(int x) {
        return QuickMul(x, MOD - 2);
    }

    public void Append(int val) {
        long adjustedVal = ((long)(val - b + MOD) % MOD) * Inv(a) % MOD;
        v.Add((int)adjustedVal);
    }

    public void AddAll(int inc) {
        b = (b + inc) % MOD;
    }

    public void MultAll(int m) {
        a = (int)((long)a * m % MOD);
        b = (int)((long)b * m % MOD);
    }

    public int GetIndex(int idx) {
        if (idx >= v.Count) {
            return -1;
        }
        int ans = (int)(((long)a * v[idx] % MOD + b) % MOD);
        return ans;
    }
}
