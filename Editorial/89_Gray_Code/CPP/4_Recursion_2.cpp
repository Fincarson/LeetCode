class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        grayCodeHelper(result, n);
        return result;
    }

private:
    int nextNum = 0;

    void grayCodeHelper(vector<int> &result, int n) {
        if (n == 0) {
            result.push_back(nextNum);
            return;
        }
        grayCodeHelper(result, n - 1);
        // Flip the bit at (n - 1)th position from right
        nextNum = nextNum ^ (1 << (n - 1));
        grayCodeHelper(result, n - 1);
    }
};
