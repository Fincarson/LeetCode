class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cycle_members = {4, 16, 37, 58, 89, 145, 42, 20};

        while (n != 1 && cycle_members.find(n) == cycle_members.end()) {
            n = getNext(n);
        }

        return n == 1;
    }

private:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
};
