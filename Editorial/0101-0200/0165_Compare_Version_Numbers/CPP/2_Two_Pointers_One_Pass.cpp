class Solution {
public:
    pair<int, int> getNextChunk(string& version, int n, int p) {
        if (p > n - 1) {
            return make_pair(0, p);
        }

        int pEnd = p;
        while (pEnd < n && version[pEnd] != '.') {
            ++pEnd;
        }

        int i = stoi(version.substr(p, pEnd != n - 1 ? pEnd - p : n - p));
        p = pEnd + 1;

        return make_pair(i, p);
    }

    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;
        int n1 = version1.size(), n2 = version2.size();

        while (p1 < n1 || p2 < n2) {
            pair<int, int> pair1 = getNextChunk(version1, n1, p1);
            p1 = pair1.second;
            pair<int, int> pair2 = getNextChunk(version2, n2, p2);
            p2 = pair2.second;
            if (pair1.first != pair2.first) {
                return pair1.first > pair2.first ? 1 : -1;
            }
        }
        return 0;
    }
};
