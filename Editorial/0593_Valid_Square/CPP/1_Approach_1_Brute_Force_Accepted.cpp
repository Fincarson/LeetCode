class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2) {
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) +
               (p2[0] - p1[0]) * (p2[0] - p1[0]);
    }

    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3,
               vector<int>& p4) {
        return dist(p1, p2) > 0 && dist(p1, p2) == dist(p2, p3) &&
               dist(p2, p3) == dist(p3, p4) && dist(p3, p4) == dist(p1, p4) &&
               dist(p1, p3) == dist(p2, p4);
    }

    void swap(vector<vector<int>>& p, int x, int y) {
        vector<int> temp = p[x];
        p[x] = p[y];
        p[y] = temp;
    }

    bool checkAllPermutations(vector<vector<int>>& p, int l) {
        if (l == 4) {
            if (p[0] == p[1] || p[1] == p[2] || p[2] == p[3] || p[3] == p[0] ||
                p[0] == p[2] || p[1] == p[3])
                return false;
            return check(p[0], p[1], p[2], p[3]);
        } else {
            bool res = false;
            for (int i = l; i < 4; i++) {
                swap(p, l, i);
                res |= checkAllPermutations(p, l + 1);
                swap(p, l, i);
                if (res) return true;
            }
            return res;
        }
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                     vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        return checkAllPermutations(p, 0);
    }
};
