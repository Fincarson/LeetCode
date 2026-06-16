class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int N) {
        for (int i = 0; i <= N; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;
        if (size[fx] > size[fy]) swap(fx, fy);
        parent[fx] = fy;
        size[fy] += size[fx];
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int MAX = 100000;
        int N = nums.size();
        vector<bool> has(MAX + 1, false);
        for (int x : nums) {
            has[x] = true;
        }

        if (N == 1) return true;
        if (has[1]) return false;

        vector<int> sieve(MAX + 1, 0);
        for (int d = 2; d <= MAX; d++) {
            if (sieve[d] == 0) {
                for (int v = d; v <= MAX; v += d) {
                    sieve[v] = d;
                }
            }
        }

        DSU unionfind(2 * MAX + 1);
        for (int x : nums) {
            int val = x;
            while (val > 1) {
                int prime = sieve[val];
                int root = prime + MAX;
                if (unionfind.find(root) != unionfind.find(x)) {
                    unionfind.merge(root, x);
                }
                while (val % prime == 0) {
                    val /= prime;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i <= MAX; i++) {
            if (has[i] && unionfind.find(i) == i) {
                cnt++;
            }
        }
        return cnt == 1;
    }
};
