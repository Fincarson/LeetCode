class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 0);
        for (int position = 0; position < n; position++) {
            int positionsLeft = n - position - 1;
            if (k > positionsLeft * 26) {
                int add = k - (positionsLeft * 26);
                result[position] = ('a' + add - 1);
                k -= add;
            } else {
                result[position] = 'a';
                k--;
            }
        }
        return result;
    }
};
