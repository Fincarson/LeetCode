class Solution {
public:
    string customSortString(string order, string s) {
        // Since strings are mutable in C++, we can sort s in-place
        sort(s.begin(), s.end(), [&order](char c1, char c2) {
            return order.find(c1) < order.find(c2);
        });
        return s;
    }
};
