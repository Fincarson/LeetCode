public class Solution {
    private (int, int) getNextChunk(string version, int n, int p) {
        if (p > n - 1) {
            return (0, p);
        }

        int pEnd = p;
        while (pEnd < n && version[pEnd] != '.') {
            ++pEnd;
        }

        int i = Int32.Parse(version.Substring(p,
            pEnd != n - 1 ? pEnd - p : n - p));
        p = pEnd + 1;
        return (i, p);
    }

    public int CompareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;
        int n1 = version1.Length, n2 = version2.Length;

        while (p1 < n1 || p2 < n2) {
            (int i1, int p1_) = getNextChunk(version1, n1, p1);
            p1 = p1_;
            (int i2, int p2_) = getNextChunk(version2, n2, p2);
            p2 = p2_;
            if (i1 != i2) {
                return i1 > i2 ? 1 : -1;
            }
        }

        return 0;
    }
}
