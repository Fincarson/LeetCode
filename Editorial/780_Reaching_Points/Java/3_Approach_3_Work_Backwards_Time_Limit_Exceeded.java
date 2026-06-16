class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (sx == tx && sy == ty)
                return true;
            if (tx > ty) tx -= ty;
            else ty -= tx;
        }
        return false;
    }
}
